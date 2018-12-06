//8FE7EEB9915EBC2B80FA5691E74E51DFAE0A6EF59366DF8CE54AFAFFE12F2B87

#include <iostream>

using namespace std;


int main()
{
    int n; bool foo = true; bool bar = true; int numk; int numk2;
    cout << "Enter an integer: "; cin >> n;//The program starts with printing a string
    while (foo == true){
        if (n <= 0)  {cout << "Invalid. Try again!" << endl << "Enter an integer: ";
            cin >> n;
        }//Invalid case, print string
        else {foo = false;
            int placedigit = n;
                while (bar == true)
                    {while (placedigit >= 1){
                    if (n != placedigit + placedigit % 10 + (placedigit / 10) % 10 + (placedigit / 100) % 10 + (placedigit / 1000) % 10 +(placedigit / 10000) % 10 +  (placedigit / 100000) % 10 + (placedigit / 1000000) % 10 + (placedigit / 10000000) % 10 + (placedigit / 100000000) % 10 + (placedigit / 1000000000) % 10 + (placedigit / 10000000000) % 10)
                    placedigit--;//If placedigit hit 1 the loop ends
                    else {{numk = n; numk2 = placedigit; cout << numk << " = " << numk2; while (numk2 != 0) {cout << " + " << numk2 % 10;
                        amaconstant2 = numk2 / 10;
                        }//Printing the equation
                    cout << endl; placedigit = n++; if (n == -2147483648) {n = 0; break;}}//handling a special case input n >= 2147483648 to match with sample-selfnum
                }
            }
    {cout << n << " is a self number." << endl; break;}//next statement for NOT(placedigit >= 1), quit loop and the output
            }
        }
    }
    return 0;
}
