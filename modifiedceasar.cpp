#include <iostream>
#include <string>

#include <cstdlib>
#include<macros.h>

using namespace std;

char restart;

int nCode;

 

int main()

{

    do

    {

        if (restart == 'Y'| restart == 'y')

            system("clear");    //CLS for a windows machine

        cout << "Please enter the code: ";

        cin >> nCode;

        srand(nCode);

        int gap = ((rand() % 4) + 1);

        cout << "Please enter your message(Gap=" << gap <<"):\n";

        Clear(); // in macros.h

        string sString;

        getline(cin, sString);

        bool bChose;

        cout << "\nEnter 0 to decrypt.\nEnter 1 to encrypt.\n";

        cin >> bChose;

        cout << "\n";

        if (bChose == 1)
        {

            for ( int i=0; sString[i] != '\0'; ++i )

            {

                sString[i] -= gap;
                ++i;

                if (!(i=='\0')) //Because the for loop doesnt check if its the null terninator

                    sString[i] += gap;

            }

        }

        else

        {

            for ( int i=0; sString[i] != '\0'; ++i )

            {

                sString[i] += gap;

                ++i;

                if(!(i=='\0'))

                    sString[i] -= gap;

            }

        }

        for (int i=0; sString[i] != '\0'; ++i )

        {

            cout << sString[i];

        }

        cout << "\n";

        cout << "\nWould you like to do it again? (y/n): ";

        cin >> restart;

    }

    while (restart == 'y' || restart == 'Y');

    Pause(); //all you need to know is that it is in macros.h and waits for the users input(it works)

    return 0;

}

