#ifndef SCORES_H
#define SCORES_H
#include<iostream>
#include<cstdlib>
#include "GameEntry.h"

class Scores
{
    public :
        Scores(int maxEnteries);
        ~Scores();
        void add(const GameEntry& e);
        GameEntry remove(int i);
    private :
        int maxEnteries;
        int numEnteries;
        GameEntry* entries;
};

Scores::Scores(int maxEnteries)
{
    this->maxEnteries = maxEnteries;
    this->numEnteries = 0;
    this->entries = new GameEntry[maxEnteries];
}

Scores::~Scores()
{
    delete[] entries;
}

void Scores::add(const GameEntry& e)
{
    int newScore = e.getScore();
    if (numEnteries == maxEnteries)
    {
        if (newScore <= entries[maxEnteries - 1].getScore())
            return;
    }
    else
        numEnteries++;
    int i = numEnteries - 2;
    while (i >= 0 && newScore > entries[i].getScore())
    {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry Scores::remove(int i)
{
    if (i < 0 || i >= numEnteries)
        std::cout << "Invalid index" << std::endl;
    GameEntry temp = entries[i];
    for (int j = i; j < numEnteries - 1; j++)
        entries[j] = entries[j + 1];
    entries[numEnteries - 1] = GameEntry("", 0);
    numEnteries--;
    return temp;
}

#endif

