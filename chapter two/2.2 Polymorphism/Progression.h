#ifndef PROGRESSION_H
#define PROGRESSION_H
#include <iostream>


class Progression
{
public:
    Progression(long f = 0) : first(f), cur(f){};
    virtual ~Progression();
    void printProgression(int n);
    Progression(const Progression& p) : first(p.first), cur(p.cur){};
protected:
    virtual long firstValue();
    virtual long nextValue();
protected:
    long first;
    long cur;
};

void Progression::printProgression(int n)
{
    std::cout << firstValue();
    for (int i = 2; i <= n; i++)
        std::cout << ' ' << nextValue();
    std::cout << std::endl;
}

long Progression::firstValue()
{
    cur = first;
    return cur;
}

long Progression::nextValue()
{
    return ++cur;
}

Progression::~Progression()
{
}

#endif