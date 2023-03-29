#include <iostream>
#include <cstdlib>
#include "Object.h"

class Pig : public Object
{
public:
    Pig(std::string name, int age);
    virtual void print();
    void jump(double height);
    void eat();
    void wallow();
    int getAge() { return age; }
    std::string getName() { return name; }
    ~Pig();
private:
    std::string name;
    int age;
};

Pig::Pig(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

void Pig::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}

void Pig::jump(double height)
{
    std::cout << "The pig jumped " << height << " meters" << std::endl;
}

void Pig::eat()
{
    std::cout << "The pig was fed" << std::endl;
}

void Pig::wallow()
{
    std::cout << "The pig was wallowed" << std::endl;
}

Pig::~Pig()
{
}






