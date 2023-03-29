#ifndef LIST_H
#define LIST_H
#include "Iterator.h"
#include "Node.h"
#include <iostream>

template <class T>
class List
{
public:
    List();
    ~List();
    void push_front(const T &element);
    void push_back(const T &element);
    void insert(Iterator<T> pointer, const T &insert);
    void pop_front();
    void pop_back();
    int getSize();
    bool empty();
    Iterator<T>* begin();
    Iterator<T>* end();

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

template <class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <class T>
List<T>::~List()
{
    while (head != NULL)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void List<T>::push_front(const T &element)
{
    insert(begin(), element);
}

template <class T>
void List<T>::push_back(const T &element)
{
    insert(end(), element);
}

template <class T>
void List<T>::insert(Iterator<T> pointer, const T &insert)
{
    Node<T> *w = pointer.current;
    Node<T> *u = w->prev;
    Node<T> *v = new Node<T>;
    v->element = insert;
    v->next = w;
    w->prev = v;
    if (u == NULL)
    {
        head = v;
    }
    else
    {
        u->next = v;
        v->prev = u;
    }
    size++;
}

template <class T>
void List<T>::pop_front()
{
    if (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        head->prev = nullptr;

        delete temp;
        size--;
    }
}

template <class T>
void List<T>::pop_back()
{
    if (back != nullptr)
    {
        Node<T> *temp = back;
        back = back->prev;
        back->next = nullptr;

        delete temp;
        size--;
    }
}

template <class T>
Iterator<T>* List<T>::begin()
{
    return Iterator(head->next);
}

template <class T>
Iterator<T>* List<T>::end()
{
    return Iterator(tail);
}

template <class T>
int List<T>::getSize()
{
 return size;
}

template<class T>
bool List<T>::empty(){
    return (size == 0);
}

#endif