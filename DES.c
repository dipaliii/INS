
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* STRING;
void vernam_encrypt_decrypt(STRING *text, STRING key)
{
	int txt_len = strlen(*text);
	int key_len = strlen(key);
	int txt_counter, key_counter;
	for (txt_counter = 0, key_counter = 0; txt_counter < txt_len ; ++txt_counter, key_counter=(key_counter+1)%key_len)
		(*text)[txt_counter] ^= key[key_counter];
}

void flush_stdin()
{
	while(fgetc(stdin) != '\n');
}

void print_binary_for_ascii(STRING text)
{
	int txt_length = strlen(text);
	int txt_counter, byte_counter;
	char temp_char;
	for(txt_counter = 0 ; txt_counter < txt_length ; ++txt_counter)
	{
		for (byte_counter = 0,  temp_char = text[txt_counter]; byte_counter < 8 ; ++byte_counter, temp_char<<=1)
			if(temp_char&128)
				printf("1");
			else
				printf("0");
		printf(" ");
	}
}

void print_binary_for_ascii_repeat(STRING text, int txt_max)
{
	int txt_length = strlen(text);
	int txt_counter, byte_counter, txt_index;
	char temp_char;
	for(txt_counter = 0, txt_index = 0 ; txt_counter < txt_max ; ++txt_counter, txt_index=(txt_index+1)%txt_length)
	{
		for (byte_counter = 0,  temp_char = text[txt_counter]; byte_counter < 8 ; ++byte_counter, temp_char<<=1)
			if(temp_char&128)
				printf("1");
			else
				printf("0");
		printf(" ");
	}
}

int main(int argv,char** argc)
{
	int key_length;
	int txt_length;
	char *key;
	char *str;

	printf("Enter the length of the key: ");
	scanf("%d",&key_length);

	printf("Enter the key to be used for encryption: ");
	key = (char*)malloc((key_length+1)*sizeof(char));
	flush_stdin();
	fgets(key,key_length+1,stdin);

	printf("Enter the length of the text: ");
	scanf("%d",&txt_length);

	printf("Input the string you want to encrypt: ");
	flush_stdin();
	str = (char*)malloc((txt_length+1)*sizeof(char));
	fgets(str,txt_length+1,stdin);

	printf("\nPlaintext:");
	printf("\nBinary: ");
	print_binary_for_ascii(str);
	printf("\n");

	printf("\nKey:");
	printf("\nBinary: ");
	print_binary_for_ascii_repeat(str,txt_length);
	printf("\n");

	vernam_encrypt_decrypt(&str,key); //encrypt
	printf("\nAfter Encryption:");
	printf("\nBinary: ");
	print_binary_for_ascii(str);

	vernam_encrypt_decrypt(&str,key); //decrypt
	printf("\nAfter decrypting:");
	printf("\nBinary: ");
	print_binary_for_ascii(str);
	printf("\n");

	free(str);
	free(key);
	return 0;
}
