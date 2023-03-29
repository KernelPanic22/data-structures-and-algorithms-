#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include <cstdlib>
#include <list>

class ExceptionBase
{
public:
    ExceptionBase(const std::string &err) : error(err) {}
    std::string getMessage() const { return error; }

private:
    std::string error;
};

class StackFull : public ExceptionBase
{
public:
    StackFull(const std::string &err) : ExceptionBase(err) {}
};

class StackEmpty : public ExceptionBase
{
public:
    StackEmpty(const std::string &err) : ExceptionBase(err) {}
};

template <typename E>
class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();
    int size() const;
    bool empty() const;
    const E &top() const;
    void push(const E &e);
    void pop();
    void reverse();
    std::list<E>* getData(){return data;}
    void setData(std::list<E> setData){data=setData;}

private:
    std::list<E> data;
    int numberOfElements;
};

template <typename E>
LinkedStack<E>::LinkedStack()
{
    numberOfElements = 0;
}

template <typename E>
LinkedStack<E>::~LinkedStack()
{
}

template <typename E>
int LinkedStack<E>::size() const
{
    return numberOfElements;
}

template <typename E>
bool LinkedStack<E>::empty() const
{
    return numberOfElements == 0;
}

template <typename E>
const E &LinkedStack<E>::top() const
{
    if (empty())
        throw StackEmpty("Stack is empty");
    return data.front();
}

template <typename E>
void LinkedStack<E>::push(const E &e)
{
    data.push_front(e);
    numberOfElements++;
}

template <typename E>
void LinkedStack<E>::pop()
{
    if (empty())
        throw StackEmpty("Stack is empty");
    data.pop_front();
    numberOfElements--;
}

template <typename E>
void LinkedStack<E>::reverse()
{
    std::list<E> dataToReverse= data;
    std::list<E> dataList;
    while (!empty())
    {
        dataList.emplace_back(dataToReverse.back());
        dataToReverse.pop_back();
        numberOfElements--;
    }
    data.assign(dataList.begin(),dataList.end());
    numberOfElements= dataList.size();
}

#endif