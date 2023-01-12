#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    //data types examples
    //bool
    bool b = true;
    //char
    char c = 'a';
    //int octal number
    int i = 012;
    //int hexadecimal number
    int j = 0x12;
    //you can put an L at the end of a number to make it a long
    //long big number
    long l = 314159265L;
    //float
    float f = 1.0;
    //double
    double d = 1.0;
    //Enum days
    enum Days {monday, tuesday, wednesday, thursday, friday, saturday, sunday};
    //Enum mood with values
    enum Mood {happy = 3, sad = 2, angry = 4};

    Days day = wednesday;
    Mood mood = angry;


    cout << "int in octal number is " << i << endl;
    cout << "int in hexadecimal number is " << j << endl;
    cout << "long big number is " << l << endl;
    cout << "Enum days wednesday is " << day << endl;
    cout << "Enum mood angry is " << mood << endl;
}
