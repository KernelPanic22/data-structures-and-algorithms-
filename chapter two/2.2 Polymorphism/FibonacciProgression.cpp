#include <iostream>
#include <cstdlib>
#include "Progression.h"

using namespace std;

class FibonacciProgression : public Progression
{
public:
    FibonacciProgression(long f = 0, long s = 1);
    FibonacciProgression &operator=(const FibonacciProgression &p);
    ~FibonacciProgression();

protected:
    long firstValue();
    long nextValue();

protected:
    long second;
    long prev;
};

// constructor
FibonacciProgression::FibonacciProgression(long f, long s)
    : Progression(f), second(s), prev(second - first)
{
    this->first = f;
    this->second = s;
    this->prev = second - first;
}

// operator overloading
FibonacciProgression &FibonacciProgression::operator=(const FibonacciProgression &p)
{
    this->second = p.second;
    this->prev = p.prev;
    return *this;
}

// new method needed in fibonacci progression
long FibonacciProgression::firstValue()
{
    cur = first;
    prev = second - first;
    return cur;
}

// override from Progression
long FibonacciProgression::nextValue()
{
    long temp = prev;
    prev = cur;
    cur += temp;
    return cur;
}
