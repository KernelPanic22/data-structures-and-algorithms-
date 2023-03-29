#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<cstdlib>

class Array
{
    public :
        Array(int size);
        ~Array();
        int getSize() const;
        int& operator[](int index);
        int operator[](int index) const;
    private :
        int size;
        
};



