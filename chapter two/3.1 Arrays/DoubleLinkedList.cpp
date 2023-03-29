#include<iostream>
#include<cstdlib>

typedef std::string Elem;
class Node{
    private :
        Elem elem;
        Node* next;
        Node* prev;
        friend class DLinkedList;
};

class DLinkedList{
    public :
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const Elem& front() const;
        const Elem& back() const;
        void addFront(const Elem& e);
        void addBack(const Elem& e);
        void removeFront();
        void removeBack();
    private :
        Node* header;
        Node* trailer;
    protected :
        void add(Node* v, const Elem& e);
        void remove(Node* v);
};

DLinkedList::DLinkedList(){
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList(){
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const{
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const{
    return header->next->elem;
}

const Elem& DLinkedList::back() const{
    return trailer->prev->elem;
}

void DLinkedList::add(Node* v, const Elem& e){
    Node* u = new Node;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e){
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e){
    add(trailer, e);
}

void DLinkedList::remove(Node* v){
    Node* u = v->prev;
    Node* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront(){
    remove(header->next);
}

