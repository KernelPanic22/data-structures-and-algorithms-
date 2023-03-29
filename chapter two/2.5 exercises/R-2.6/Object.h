#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
#include<cstdlib>

using namespace std;

class Object
{
public:
    Object();
    virtual void print() = 0;
    virtual ~Object() {}
};

Object::Object()
{
}
#endif