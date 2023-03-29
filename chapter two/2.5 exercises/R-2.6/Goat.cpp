#include<iostream>
#include<cstdlib>
#include "Object.h"

class Goat : public Object
{
public:
    Goat(std::string name, int age);
    std::string getName() { return name; }
    int getAge() { return age; }
    virtual void print();
    ~Goat();
    void jump(double height);
    void milk();
    void winWorldCup();
private:
    std::string name;
    int age;
};

Goat::Goat(std::string name, int age)
{
    this->name = name;
    this->age = age;
}

void Goat::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}

Goat::~Goat()
{
}

void Goat::jump(double height)
{
    std::cout << "The goat jumped " << height << " meters" << std::endl;
}

void Goat::milk()
{
    std::cout << "The goat was milked" << std::endl;
}

void Goat::winWorldCup()
{
    string winWorldCup= "The goat " + this->name + " won the world cup";
    std::cout << winWorldCup << std::endl;
}