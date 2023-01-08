#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    Loops are used to execute a block of code multiple times
    */

    // while loop
    int a = 0;
    while (a < 10)
    { // the condition is checked before the loop is executed
        cout << a << endl;
        a++;
    }

    // do while loop
    int b = 0;
    do
    {
        cout << b << endl;
        b++;
    } while (b < 10); // the condition is checked after the loop is executed

    // for loop
    for (int c = 0; c < 10; c++) // the for loop encapsulates and simplifies the while loop
    {                            // contains an initialization, a condition and an increment all in one
        cout << c << endl;
    }

    // for each loop
    int arr[] = {1, 2, 3, 4, 5};
    for (int d : arr) // the for each loop is used to iterate over a collection
    {
        cout << d << endl;
    }

    // infinite loop
    // for(;;){
    //     cout << "infinite loop" << endl;
    // }

    /*
    The break condition
    */
    for (int e = 0; e < 10; e++)
    {
        if (e == 5)
        {
            break; // the break statement is used to exit a loop
        }
        cout << e << endl;
    }

    return 0;
}