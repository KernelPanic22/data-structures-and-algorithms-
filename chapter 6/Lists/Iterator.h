#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"
#include "List.h"


template <class T>
class Iterator
{
    public:
        T& operator*();
        Iterator<T>& operator++();
        Iterator<T>& operator--();
        bool operator==(const Iterator<T>& rhs);
        bool operator!=(const Iterator<T>& rhs);
        friend class List<T>;
    private:
        Node<T>* current;
        Iterator(Node<T>* p);
};

template <class T>
Iterator<T>::Iterator(Node<T>* p)
{
    current = p;
}

template <class T>
T& Iterator<T>::operator*()
{
    return current->element;
}

template <class T>
Iterator<T>& Iterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template <class T>
Iterator<T>& Iterator<T>::operator--()
{
    current = current->prev;
    return *this;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& rhs)
{
    return current == rhs.current;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs)
{
    return current != rhs.current;
}

#endif