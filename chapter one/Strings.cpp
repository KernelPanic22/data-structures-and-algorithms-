#include <iostream>
#include <cstdlib>
#include <string>
using std::string;
using namespace std;

int main()
{
    /*
    A string literal such as "Hello World" is
    represented as a fixed-length array of characters
    that ends with a null character '\0'
    Remember that '\0' is the literal constant for the null character
    */
    string s = "to be";
    string t = "not" + s;
    string u = s + "or" + t;

    /*as we said before string are arrays of characters
    we can access the characters using an index
    */
    cout << "accesing the first character of the string s" << endl;
    cout << s[0] << endl;

    /*we can also know the size of the string by doing*/
    cout << "size of the string s" << endl;
    cout << s.size() << endl;

    /*we can append more characters to an string using +=*/
    string name = "John";
    name += " Doe";
    cout << "Appending more characters to an string using +=" << endl;
    cout << "name = " << name << endl;

    
}