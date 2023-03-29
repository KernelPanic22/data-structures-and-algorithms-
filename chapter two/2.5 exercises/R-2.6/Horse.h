#ifndef HORSE_H
#define HORSE_H
#include<iostream>
#include<cstdlib>
#include "Object.h"

class Horse : public Object
{
public:
    Horse(std::string name, int age, double height, string color);
    Horse(const Horse &horse) : Object(horse)
    {
        this->name = horse.name;
        this->age = horse.age;
        this->height = horse.height;
        this->color = horse.color;
    }
    virtual void print();
    void jump(double height);
    void eat();
    void gallop();
    int getAge() { return age; }
    std::string getName() { return name; }
    double getHeight() { return height; }
    string getColor() { return color; }
    ~Horse();
private:
    std::string name;
    int age;
    double height;
    string color;
};

Horse::Horse(std::string name, int age, double height, string color)
{
    this->name = name;
    this->age = age;
    this->height = height;
    this->color = color;
}

void Horse::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Height: " << this->height << std::endl;
    std::cout << "Color: " << this->color << std::endl;
}

void Horse::jump(double height)
{
    std::cout << "The horse jumped " << height << " meters" << std::endl;
}

void Horse::eat()
{
    std::cout << "The horse was fed" << std::endl;
}

void Horse::gallop()
{
    std::cout << "The horse galloped" << std::endl;
}

Horse::~Horse()
{
}
#endif