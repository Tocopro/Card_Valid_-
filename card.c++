#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;
class Card_validation
{
public:
    // initialize the constructors
    string card_number;
    string num;
    int number = 0;
    int total = 0;
    string bunch1 = " ", bunch2 = " ", bunch3 = " ", bunch4 = " ";
    int num3 = 0;
    // get the card number input from the user
    void iterating_string()
    {
        cout << " User, Please Enter the Card Number for Validation Check with no spaces: ";
        cin >> card_number;
        cout << " THE CARD NUMBER ENTERED IS : " << card_number << endl;
        // crating the four digit space display on cards
        for ( int d = 0; d < 4; d++)
        {
            bunch1 += card_number[d];
        }
        for ( int d = 4; d < 8; d++)
        {
            bunch2 += card_number[d];
        }
        for ( int d = 8; d < 12; d++)
        {
            bunch3 += card_number[d];
        }
        for ( int d = 12; d < 16; d++)
        {
            bunch4 += card_number[d];
        }

    }

    void string_reverse()
    {
        // reversing the card number for the iteration calculation using luhn algorithm
        num = card_number;
        reverse(num.begin(), num.end());
        int count = 0;
        for(int x = 0; x < num.length(); x++)
        {
            if ( x % 2 != 0 )
            {
                char a = num[x];
                int check1 = a - 48;
                int num1 = (check1 * 2);
                if ( num1 > 9)
                {
                    string check2 = to_string(num1);
                    for (int f = 0; f < check2.length(); f++)
                    {
                        stringstream  ss;
                        ss << check2[f];
                        ss >>  num3;
                        total = total + num3;
                    }
                }
                else if (num1 < 9)
                {

                    total = total + num1;
                }
            }
            else if ( x % 2 == 0)
            {
                char a = num[x];
                number = a - 48;
                total = total + number;
            }
        }
    }
    void check() const
    {
        // displaying the result of the card number check
        if ( total % 10 == 0)
        {
            cout << bunch1 << " " << bunch2 << " " << bunch3 << " " << bunch4 << " - IS A VALID CARD" << endl;
        }
        else if ( total % 10 != 0)
        {
            cout <<  bunch1 << " " << bunch2 << " " << bunch3 << " " << bunch4 << " - IS NOT A VALID NUMBER" << endl;
        }
    }
};

int main() {
    // run the program
    Card_validation start;
    start.iterating_string();
    start.string_reverse();
    start.check();
    return 0;
}

