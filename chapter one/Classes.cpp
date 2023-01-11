#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*
    A class is a user defined data type
*/
class Person
{

    // the public section is used to define the interface that is available to the outside world
public:
    Person(string name, int age);
    void print();
    int getAge();
    void setAge(int age);
    void setName(string name);
    string getName();
    ~Person();

    // the private section is used for entities that are not available to the outside world
private:
    string name;
    int age;
};

int main()
{
    Person person("John", 20);
    person.print();
    cout << "The person's name is: " << person.getName() << endl;
    cout << "The person's age is: " << person.getAge() << endl;
    return EXIT_SUCCESS;
}

// the constructor is a special function that is called when an object is created
Person::Person(string name, int age)
{
    this->name = name;
    this->age = age;
}

string Person::getName()
{
    return this->name;
}

void Person::setName(string name)
{
    this->name = name;
}

int Person::getAge()
{
    return this->age;
}

/*
    Book example page 35
*/

enum MealType
{
    REGULAR,
    DIET,
    VEGETARIAN
};

class Passenger
{
public:
    Passenger(string name, MealType mealType, bool isFreqFlyer, string freqFlyerNo);
    void print();
    string getName();
    MealType getMealType();
    // the word const means that the function will not modify the object
    bool getIsFreqFlyer() const;
    string getFreqFlyerNo();
    void makeFreqFlyer(const string &freqFlyerNo);
    void setMealType(MealType mealType);
    void setName(string name);

private:
    string name;
    MealType mealType;
    bool isFreqFlyer;
    string freqFlyerNo;
};

Passenger::Passenger(string name, MealType mealType, bool isFreqFlyer, string freqFlyerNo)
{
    this->name = name;
    this->mealType = mealType;
    this->isFreqFlyer = isFreqFlyer;
    this->freqFlyerNo = freqFlyerNo;
}

string Passenger::getName()
{
    return this->name;
}

MealType Passenger::getMealType()
{
    return this->mealType;
}

bool Passenger::getIsFreqFlyer() const
{
    return this->isFreqFlyer;
}

string Passenger::getFreqFlyerNo()
{
    return this->freqFlyerNo;
}

void Passenger::makeFreqFlyer(const string &freqFlyerNo)
{
    this->isFreqFlyer = true;
    this->freqFlyerNo = freqFlyerNo;
}

void Passenger::setMealType(MealType mealType)
{
    this->mealType = mealType;
}

void Passenger::setName(string name)
{
    this->name = name;
}

Person::~Person()
{
  operator delete(this);
}
