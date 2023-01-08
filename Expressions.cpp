#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    Arithmetic operators
    */
    int a = 10;
    int b = 3;
    int c = a + b; // addition
    int d = a - b; // subtraction
    int e = a * b; // multiplication
    int f = a / b; // division
    int g = a % b; // modulus
    int h = a++;   // postfix increment
    int i = ++a;   // prefix increment
    int j = a--;   // postfix decrement
    int k = --a;   // prefix decrement

    /*
    relational operators
    */
    bool l = a == b; // equal to
    bool m = a != b; // not equal to
    bool n = a > b;  // greater than
    bool o = a < b;  // less than
    bool p = a >= b; // greater than or equal to
    bool q = a <= b; // less than or equal to

    // Comparison can be made between numbers, characters, strings, and pointers
    // Comparison between pointers is made by comparing the addresses of the pointers

    /*
    Logical operators
    */
    bool r = a && b; // logical AND
    bool s = a || b; // logical OR
    bool t = !a;     // logical NOT

    /*
    The operators && and || are short-circuit operators
     this means that if the first operand is enough to determine
     the result of the expression the second operand is not evaluated
    */

    /*
    Bitwise operators
    */
    int u = a & b;  // bitwise AND
    int v = a | b;  // bitwise OR
    int w = a ^ b;  // bitwise XOR
    int x = ~a;     // bitwise NOT
    int y = a << 1; // left shift a left shift by 1 bit
    int z = a >> 1; // right shift a right shift by 1 bit

    /*
    In c++ integer variables are signed by default but they may be declared as unsigned
    as in in unsigned int x if the left operand of a right shift is unsigned
    the shift fills the vacated bits with 0s instead of 1s otherwise the right shift fills with the numbers sign bit
    0 for positive numbers and 1 for negative numbers
    */
}