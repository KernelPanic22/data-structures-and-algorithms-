#include <iostream>
#include <cstdlib>

using namespace std;

//Example of interface for person
/*
    A class to be concidered a interface his methods must be pure virtual
    and the implementation of the methods must be in the derived classes

    The virtual destructor is needed to avoid memory leaks
    the virtual methods should return a 0 value in case of a call to the base class
*/
class PersonInterfaceExample
{
public:
    virtual void print() = 0;
    virtual ~PersonInterfaceExample() {}
    virtual string getName() = 0;
    virtual int getAge() = 0;
};
