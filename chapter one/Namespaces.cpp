#include <iostream>
#include <cstdlib>

using namespace std;

/*
we can define a namespace to group constants and types
to acces global constants and types we use the scope resolution operator ::
for example myGlobals::SIZE it refers to a copy of the constant SIZE in the namespace myGlobals
*/
namespace myGlobals
{
    const int SIZE = 10;
    int array[SIZE];
    const float PI = 3.14159265;
}
/*
    we can use using namespace myGlobals
    and then we dont have to write myGlobals::SIZE just SIZE
*/
/*
Namespaces may generally contain definitios
of more complex types, such as classes, functions, and templates.
*/

int main()
{
    // accessing global constants and types
    cout << myGlobals::SIZE << endl;
    cout << myGlobals::PI << endl;
    cout << myGlobals::array[0] << endl;
}