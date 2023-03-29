#ifndef NODE_H
#define NODE_H

template <class T>
struct Node
{
    T element;
    Node<T>* prev;
    Node<T>* next;
};
#endif
