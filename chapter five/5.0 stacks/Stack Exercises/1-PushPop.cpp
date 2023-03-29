#include <iostream>
#include <cstdlib>
#include "/home/kernelpanic/Documents/arrays-c++/chapter five/5.0 stacks/LinkedStack.h"
/*
Problem:
 1. (Sedgewick, Exercise 4.6).  A letter means push and an asterisk means pop in the
    following sequence.  Give the sequence of values returned by the pop operations
    when this sequence of operations is performed on an initially empty LIFO stack.
Input:
    E A S * Y * Q U E * * * S T * * * I O * N * * *
*/

class PushPop
{
public:
    PushPop();
    ~PushPop();
    void push(const std::string &e);
    void pop();
    void decodeMessage();

private:
    LinkedStack<char> data;
};

PushPop::PushPop()
{
}

PushPop::~PushPop()
{
}

void PushPop::push(const std::string &e)
{
    for (int i = 0; i < e.length(); i++)
    {
        if (isalpha(e[i]))
            data.push(e[i]);
    }
}

void PushPop::decodeMessage(){
    data.reverse();
    while (!data.empty())
    {   
        std::cout<< data.top() <<std::ends;
        data.pop();
    }
    
}

int main(){
    PushPop p = PushPop();
    p.push("E A S * Y * Q U E * * * S T * * * I O * N * * *");
    p.decodeMessage();
}
