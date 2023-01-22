#ifndef GAME_ENTRY_H
#define GAME_ENTRY_H
#include<iostream>
#include<cstdlib>

class GameEntry
{
    public :
        GameEntry(std::string& name, int score);
        std::string getName() const;
        int getScore() const;
    private :
        std::string name;
        int score;
};

GameEntry::GameEntry(std::string& name, int score)
{
    this->name = name;
    this->score = score;
}

std::string GameEntry::getName() const
{
    return this->name;
}

int GameEntry::getScore() const
{
    return this->score;
}


#endif