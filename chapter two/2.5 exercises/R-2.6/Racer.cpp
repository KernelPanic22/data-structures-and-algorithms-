#include<iostream>
#include<cstdlib>
#include "Horse.h"

class Racer : public Horse
{
    public:
        Racer(Horse &horse);
        ~Racer();
        void race();
    private:
};

Racer::Racer(Horse &horse) : Horse(horse)
{
}

void race()
{
    std::cout << "The horse is racing" << std::endl;
}

Racer::~Racer()
{
}

