#include<iostream>
#include<cstdlib>   
#include "Goat.cpp"

int main()
{
    Goat messi("Messi", 5);
    messi.print();
    messi.jump(2.5);
    messi.milk();
    messi.winWorldCup();
    return 0;
}