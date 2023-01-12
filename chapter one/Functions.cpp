#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// you have to declare the function before implementing it
int isEvenOrOdd(int number);
void keepSum(int &sum, int number);
int sumArray(int array[], int size);

// function overloading is when you have functions
// with the same name but different parameters
void print(int array[], int size);
void print(int number);

/*
Operator overloading is a compile-time polymorphism. It is an idea of giving 
special meaning to an existing operator in C++ without changing its original meaning.

For example this function is used to concatenate two strings
*/
//TODO: implement the operator overloading for the + operator

int main()
{
    int total = 0;
    keepSum(total, 10);
    keepSum(total, 20);
    keepSum(total, 30);
    cout << "keepSum" << endl;
    cout << "The total is: " << endl;
    print(total);

    cout << "SumArray" << endl;
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "The array before the sumArray is: " << endl;
    print(array, size);

    sumArray(array, size);

    cout << "The array after the sumArray is: " << endl;
    print(array, size);

    return EXIT_SUCCESS;
}

/*
 FUNCTIONS
 A function is a block of code that is executed when it is called

 A functions counts with 4 parts:
 - return type : the type of the value that the function returns
 - name : the name of the function
 - parameters : the values that the function receives
 - body : the block of code that the function executes

 The function syntax is the following:
 return_type name(parameter1, parameter2, ...){
     //body
 }

 For example:
 */

// this function find if a number is even or odd
int isEvenOrOdd(int number)
{
    if (number % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// you can send referenced parameters to a function
void keepSum(int &sum, int number)
{
    sum += number;
}

// when you send an array to a function you send a reference to the array
int sumArray(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
        // for the sake of the example we are going to put a
        // 0 in the number added to the sum
        array[i] = 0;
    }
    return sum;
}

//this function is used to print an array
void print(int number)
{
    cout << number << endl;
}


void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}
