#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    A structure is useful for storing related data of different types
    each member or field is reffered to by a given name
    */

    // enum is a type that can be used to define a set of named constants
    enum MealType
    {
        NO_PREF,
        REGULAR,
        LOW_FAT,
        VEGETARIAN
    };

    // structure definition
    struct Passenger
    {
        string firstName;
        string lastName;
        MealType mealPref;
        bool isFreqFlyer;
        string freqFlyerNo;
    };

    // constructing a structure
    Passenger pass = {"John", "Doe", REGULAR, true, "123456789"};

    // accessing the structure members
    cout << "First Name: " << pass.firstName << endl;
    cout << "Last Name: " << pass.lastName << endl;
    cout << "Meal Preference: " << pass.mealPref << endl;
    cout << "Is Frequent Flyer: " << pass.isFreqFlyer << endl;
    cout << "Frequent Flyer Number: " << pass.freqFlyerNo << endl;

    // changing the structure members
    pass.firstName = "Jane";
    pass.lastName = "Doe";
    pass.mealPref = VEGETARIAN;
    pass.isFreqFlyer = false;
    pass.freqFlyerNo = "";

    // viweing the structure members after the change
    cout << "First Name: " << pass.firstName << endl;
    cout << "Last Name: " << pass.lastName << endl;
    cout << "Meal Preference: " << pass.mealPref << endl;
    cout << "Is Frequent Flyer: " << pass.isFreqFlyer << endl;
    cout << "Frequent Flyer Number: " << pass.freqFlyerNo << endl;

    // the new operator
    /*
    The new operator is used to allocate memory for a structure,
    dinaamically allocating memory for a structure is useful
    when the size of the structure is not known at compile time

    The new operator returns a pointer to the newly allocated memory
    */

    // Suppose we want to dynamically create a new instance of the Passenger structure
    // we can do it like this
    Passenger *passPtr = new Passenger;

    /*
    we can access the members of the structure using the pointer "->" operator
    passPtr->firstName is equivalent to (*passPtr).firstName
    */
    passPtr->firstName = "John";

    // we can also use the dereference operator to access the members of the structure
    (*passPtr).lastName = "Doe";

    passPtr->mealPref = REGULAR;
    passPtr->isFreqFlyer = true;
    passPtr->freqFlyerNo = "123456789";

    // C++ doesnt have a garbage collector so we need to free the memory
    // we can do it like this
    delete passPtr;
    // delete destroys the object pointed to by passPtr and frees the memory
    // the delete operator should be used only for objects created with new

    // arrays can be allocated dynamically using the new operator
    // we can do it like this
    int *intArray = new int[10];
    intArray[0] = 1;

    // to delete an array allocated with new we use the delete[] operator
    delete[] intArray;

    /*the golden rule of an object allocated with new is that it should
    eventually be deleted with his proper delete*/

    
}