#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // Two essentials operators are use to manipulate pointers
    /* The first  returns the address of an object in memory
        address-of operator (&) for example:
        int x = 5;
        &x; //returns the address in memory of x
    */

    /*The second operator is the dereference operator (*)
       if p is a pointer to x that is int* then set p=&x
       then we could access the value of x by using *p
       changing the value of p would change the value of x
       and vice versa
    */

    char ch = 'Q';
    char *p = &ch;
    cout << "dereference char* p = &ch ch='Q'" << *p << endl;
    ch = 'A';
    cout << "dereference char* p = &ch='A'" << *p << endl;
    *p = 'Z';
    cout << "Changing the value of p changes the value of ch *p='Z' " << ch << endl;

    /*pointers not only point to fundamental types but also to complex types
    they may also point to complex types and even functions*/

    /*we can declare a pointer to be type void* is used to indicate
    no type information at all
    we can delcare a pointer to be type void*.
    Since the compiler is unable to check the correctness of such references,
    the use of void* pointers is strongly discouraged, except in unusual cases where
    direct access to the computer’s memory is needed.
    */
}