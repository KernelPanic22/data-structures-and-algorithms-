#ifndef EULER_TOUR_H
#define EULER_TOUR_H
#include <iostream>
#include <cstdlib>
#include <list>
#include "LinkedBinaryTree.h"

template <class T, class E>
class IntEuler;
template <class T, class E>
class EulerTour
{
public:
    void initialize(const LinkedBinaryTree &T) { tree = &T; }
    friend class IntEuler<T, E>;

protected:
    struct Result
    {
        E leftResult;
        E rightResult;
        E finalResult;
    };
    typedef LinkedBinaryTree<T> BinaryTree;
    typedef typename LinkedBinaryTree<T>::Position Position;
    const LinkedBinaryTree<T> *tree;
    virtual E eulerTour(const Position<T> &p) const;

protected:
    virtual void visitExternal(const Position<T> &p, Result &r) const;
    virtual void visitLeft(const Position<T> &p, Result &r) const;
    virtual void visitRight(const Position<T> &p, Result &r) const;
    Result initResult() const { return Result(); }
    int result(const Result<E> &r) const { return r.finalResult; }

};

template <class T, class E>
class IntEuler : EulerTour<T,E>
{
public:
    E eulerTour(const Position<T> &p) const;
protected:
    void visitExternal(const Position &p, Result &r) const;
    void visitLeft(const Position &p, Result &r) const;
    void visitRight(const Position &p, Result &r) const;

};

template<class T, class E>
E IntEuler<T,E>::eulerTour(const Position<E>& p) const{

}
