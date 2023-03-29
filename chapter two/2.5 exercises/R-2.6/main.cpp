#include <iostream>
#include <cstdlib>
#include "Goat.cpp"
#include "Pig.cpp"
#include "Horse.h"
#include "Racer.cpp"

int main()
{
    Goat messi("Messi", 5);
    messi.print();
    messi.jump(2.5);
    messi.milk();
    messi.winWorldCup();

    cout << "\n"
         << endl;

    Pig pig("Pig", 5);
    pig.print();
    pig.jump(2.5);
    pig.eat();
    pig.wallow();

    cout << "\n"
         << endl;

    Horse horse("Horse", 5, 1.5, "Brown");
    horse.print();
    horse.jump(2.5);
    horse.eat();
    horse.gallop();

    cout << "\n"
         << endl;

    Racer racer(horse);
    racer.race();
 

    return 0;
}