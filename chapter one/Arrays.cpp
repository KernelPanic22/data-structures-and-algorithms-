#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    /*
    An array is a collection of objects of the same type.
    given any type T and a constant integer N,
    the type T[N] is an array of N objects of type T.

    Each element of an array is accessed by an index,
    a nonnegative integer that is less than the size of the array
    being the size of the array N-1 (zero based index).
    */

    // array that holds 3 doubles
    double a[3];
    // array that holds 10 doubles
    double b[10];

    /*is important to remember that each element of an array
    is a pointer to memory location that holds the value of the element
    */

    /*when we assign a value to an array element we are actually changing the value
     of the memory location that the index points to*/

    // assigning values to array elements
    a[4] = 5.0;
    b[2] = 4.0;

    // a two dimensional array is implemented as an array of arrays
    // a two dimensional array of 3 rows and 4 columns
    int c[3][4];

    //declaring and initializing an array
    int d[3] = {1, 2, 3};

    //declaring an array of pointers to integers
    int *e[3];
    //setting the values of the array of pointers
    e[0] = &d[0];
    e[1] = &d[1];
    e[2] = &d[2];

    //accessing the values of the array of pointers
    cout <<"accessing the values of the array of pointers" << endl;
    cout << "e[0] = " << *e[0] << endl;
    cout << "e[1] = " << *e[1] << endl;
    cout << "e[2] = " << *e[2] << endl;

//The name of an array is a pointer to the first element of the array
// Example:
char f[] = {'a', 'b', 'c', 'd', 'e'};
char* p = f;
// we can acces the first element with the operator address-of
char *p = &f[0];


}