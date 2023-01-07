#include <iostream>
#include <cstdlib>
/* with use namespace std
 we don't need to use std::cout or std::endl*/
using namespace std;

int main()
{
    int x, y;
    cout << "Please enter two numbers: ";

    cout << "\n x=";
    cin >> x;
    cout << "\n y=";
    cin >> y;
    cout << "The sum of " << x << " and "
         << y << " is " << x + y << std::endl;
    return EXIT_SUCCESS;
}

// basic types in C++ are bool,char,short,int,long,float,double

// integral types are bool,char,int

// discrete values enum

// void indicates absence of any type information

// literal constants are values that are written directly into the program
/*literal constants are enclosed in single quotes
a number of escape sequences are available for special characters
'\t' tab, '\n' newline, '\r' carriage return,
'\v' vertical tab, '\b' backspace,
'\f' form feed, '\a' alert,
 '\?' question mark,
  '\'' single quote,
   '\"' double quote,
    '\\' backslash,
    '\ooo' octal value,
     '\xhh' hexadecimal value
     '\0' null*/

     

