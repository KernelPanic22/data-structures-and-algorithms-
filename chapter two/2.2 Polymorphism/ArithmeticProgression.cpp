#include <iostream>
#include <cstdlib>
#include "Progression.h"

using namespace std;

class ArithmeticProgression : public Progression
{
public:
    ArithmeticProgression(long i = 1);
    ArithmeticProgression &operator=(const ArithmeticProgression &p);
    ~ArithmeticProgression();

protected:
    long nextValue();

protected:
    long inc;
};

ArithmeticProgression::ArithmeticProgression(long i) : Progression(), inc(i)
{
}

ArithmeticProgression &ArithmeticProgression::operator=(const ArithmeticProgression &p)
{
    this->inc = p.inc;
    return *this;
}

/*
we override the nextValue() inherited from Progression thats why
we used the virtual keyword in the Progression class
*/
long ArithmeticProgression::nextValue()
{
    cur += inc;
    return cur;
}

ArithmeticProgression::~ArithmeticProgression()
{
}