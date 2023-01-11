#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    Casting a variable is the process of changing the type of the variable itself
    for example:
    */
    int a = 10;
    double b = (double)a; // casting a to double

    /*
    Division between two integers return a integer value if we want to
    get the decimal part of the division we need to cast the operands
    */
    int c = 10;
    int d = 3;
    double e = double(c) / double(d); // casting c and d to double
    double f = double(c / d);         // casting c and d to double

    /*
    static_cast his most common use is between numeric types, it truncates the value
    not rounding it
    */
    int g = 10;
    double h = static_cast<double>(g); // casting g to double

    /*
    reinterpret_cast reference : https://en.cppreference.com/w/cpp/language/reinterpret_cast
    */

    struct S1
    {
        int a;
    } s1;
    struct S2
    {
        int a;

    private:
        int b;
    } s2; // not standard-layout
    union U
    {
        int a;
        double b;
    } u = {0};
    int arr[2];
    int *p1 = reinterpret_cast<int *>(&s1);      // value of p1 is "pointer to s1.a" because
                                                 // s1.a and s1 are pointer-interconvertible
    int *p2 = reinterpret_cast<int *>(&s2);      // value of p2 is unchanged by reinterpret_cast
                                                 // and is "pointer to s2".
    int *p3 = reinterpret_cast<int *>(&u);       // value of p3 is "pointer to u.a":
                                                 // u.a and u are pointer-interconvertible
    double *p4 = reinterpret_cast<double *>(p3); // value of p4 is "pointer to u.b": u.a and
                                                 // u.b are pointer-interconvertible because
                                                 // both are pointer-interconvertible with u
    int *p5 = reinterpret_cast<int *>(&arr);     // value of p5 is unchanged by reinterpret_cast
                                                 // and is "pointer to arr"


}