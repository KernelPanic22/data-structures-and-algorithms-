#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H
#include <iostream>
#include <cstdlib>
#include <list>

template <class E> class LinkedBinaryTree;
template <class E> class Position;
template <class E> struct Node;

template <class E>
struct Node
{
    E element;
    Node<E> *parent;
    Node<E> *left;
    Node<E> *right;
    Node() : element(), parent(nullptr), left(nullptr), right(nullptr) {}
    void operator=(const E &e) { element = e; }
    void operator=(const Node<E> &n)
    {
        element = n.element;
        parent = n.parent;
        left = n.left;
        right = n.right;
    }
};



template <class E>
class Position
{
public:
    Position(Node<E> *_v = nullptr) : v(_v) {}
    E &operator*() { return v->element; }
    Position<E> left() const { return Position(v->left); }
    Position<E> right() const { return Position(v->right); }
    Position<E> parent() const { return Positon(v->parent); }
    bool isRoot() const { return v->parent == nullptr; }
    bool isExternal() const { return (v->left == nullptr && v->right == nullptr); }
    friend class LinkedBinaryTree<E>;

private:
    Node<E> *v;
};

template <class E>
using PositionList = std::list<Position<E>>;


template <class E>
class LinkedBinaryTree
{
public:
    LinkedBinaryTree();                                    // constructor
    ~LinkedBinaryTree();                                   // destructor
    int size() const;                                      // size of tree
    bool empty() const;                                    // is tree empty?
    Position<E> root() const;                              // get the root
    PositionList<E> positions() const;                     // list of all positions
    void addRoot();                                        // add root to empty tree
    void populateFromList(const std::list<E> &pl);      // recurse the tree and populate tree with data from list
    void expandExternal(const Position<E> &p);             // expand external node
    Position<E> removeAboveExternal(const Position<E> &p); // remove p and parent
    void printTree() const;                                // print tree structure

protected:
    void preorder(Node<E> *v, PositionList<E> &pl) const; // preorder utility

private:
    Node<E> *root_; // pointer to the root
    int n;       // number of nodes
};

template <class E>
LinkedBinaryTree<E>::LinkedBinaryTree() : root_(nullptr), n(0) {}

template <class E>
LinkedBinaryTree<E>::~LinkedBinaryTree()
{
    delete root_;
}

// recurse the tree and populate tree with data from list
template <class E>
void LinkedBinaryTree<E>::populateFromList(const std::list<E> &pl)
{
    if (pl.empty())
    {
        return;
    }
    auto p = root();
    for (auto e : pl)
    {
        if (p.isExternal())
        {
            expandExternal(p);
        }
        p = p.left();
        p = *e;
    }
}

template <class E>
void LinkedBinaryTree<E>::printTree() const
{
    PositionList<E> pl = positions();
    for (auto p : pl)
    {
        std::cout << *p << std::endl;
    }
}

template <class E>
int LinkedBinaryTree<E>::size() const
{
    return n;
}

template <class E>
bool LinkedBinaryTree<E>::empty() const
{
    return size() == 0;
}

template <class E>
Position<E> LinkedBinaryTree<E>::root() const
{
    return Position<E>(root_);
}

template <class E>
PositionList<E> LinkedBinaryTree<E>::positions() const
{
    PositionList<E> pl;
    preorder(root_, pl);
    return PositionList<E>(pl);
}

template <class E>
void LinkedBinaryTree<E>::addRoot()
{
    if (empty())
    {
        root_ = new Node<E>;
        n = 1;
    }
    else
    {
        std::cout << "Tree is not empty" << std::endl;
    }
}

template <class E>
void LinkedBinaryTree<E>::expandExternal(const Position<E> &p)
{
    Node<E> *v = p.v;
    v->left = new Node<E>;
    v->left->parent = v;
    v->right = new Node<E>;
    v->right->parent = v;
    n += 2;
}

template <class E>
Position<E> LinkedBinaryTree<E>::removeAboveExternal(const Position<E> &p)
{
    Node<E> *w = p.v;
    Node<E> *v = w->parent;
    Node<E> *sib = (w == v->left ? v->right : v->left);
    if (v == root_)
    {
        root_ = sib;
        sib->parent = nullptr;
    }
    else
    {
        Node<E> *gpar = v->parent;
        if (v == gpar->left)
            gpar->left = sib;
        else
            gpar->right = sib;
        sib->parent = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position<E>(sib);
}

template <class E>
void LinkedBinaryTree<E>::printTree() const
{
    PositionList<E> pl = positions();
    for (auto p : pl)
    {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}

template <class E>
void LinkedBinaryTree<E>::preorder(Node<E> *v, PositionList<E> &pl) const
{
    pl.push_back(Position<E>(v));
    if (v->left != nullptr)
        preorder(v->left, pl);
    if (v->right != nullptr)
        preorder(v->right, pl);
}

#endif

