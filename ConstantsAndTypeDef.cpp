#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
    /*
    Constants are values that cannot be changed
    For example using constants we can define the size of an array
    */
    const int SIZE = 10;
    int array[SIZE];
    //you can also define constants using the #define preprocessor directive
    #define PI 3.14159265

    //typedef is used to define a new type
    //you can define a type char* as a new type called BufferPtr for example

    typedef char* BufferPtr;
    BufferPtr buffer; //this is the same as char* buffer is a pointer to a char

    typedef double Coordinate;
    Coordinate x, y, z; //this is the same as double x, y, z;

    /*
    By using typedef we can provide a more descriptive name for various types
    */
}