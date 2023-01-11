#include <iostream>
#include <cstdlib>
#include "Progression.h"

using namespace std;

class GeometryProgression : public Progression
{
public:
    GeometryProgression(long b = 2);
    GeometryProgression &operator=(const GeometryProgression &p);
    ~GeometryProgression();

protected:
    long nextValue();

protected:
    long base;
};

GeometryProgression::GeometryProgression(long b) : Progression(), base(b)
{
}

GeometryProgression &GeometryProgression::operator=(const GeometryProgression& p)
{
    this->base = p.base;
    return *this;
}

/*
we override the nextValue() inherited from Progression thats why
we used the virtual keyword in the Progression class
*/
long GeometryProgression::nextValue()
{
    cur *= base;
    return cur;
}

GeometryProgression::~GeometryProgression()
{
}