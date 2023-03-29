#include <iostream>
#include <cstdlib>

template<typename E>
class CircularyLinkedList;

template <typename E>
class Node
{
private:
    E elem;
    Node* next;
    friend class CircularyLinkedList<E>;
};

template <typename E>
class CircularyLinkedList
{
public:
    CircularyLinkedList();
    ~CircularyLinkedList();
    bool empty() const;
    const E &front() const;
    const E &back() const;
    void advance();
    void add(const E &e);
    void remove();

private:
    Node<E>* cursor;

protected:
    void add(Node<E> *v, const E &e);
    void remove(Node<E> *v);
};

template <typename E>
CircularyLinkedList<E>::CircularyLinkedList()
    : cursor(NULL) {}

template <typename E>
CircularyLinkedList<E>::~CircularyLinkedList()
{
    while (!empty())
        remove();
}

template <typename E>
bool CircularyLinkedList<E>::empty() const
{
    return (cursor == NULL);
}

template <typename E>
const E &CircularyLinkedList<E>::front() const
{
    return cursor->next->elem;
}

template <typename E>
const E &CircularyLinkedList<E>::back() const
{
    return cursor->elem;
}

template <typename E>
void CircularyLinkedList<E>::advance()
{
    std::cout << cursor->next->elem << std::endl;
    cursor = cursor->next;
}

template <typename E>
void CircularyLinkedList<E>::add(const E &e)
{
    Node<E> *newNode = new Node<E>;
    newNode->elem = e;
    if (cursor == nullptr)
    {
        newNode->next = newNode;
        cursor = newNode;
    }
    else
    {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

template <typename E>
void CircularyLinkedList<E>::remove()
{
    Node<E> *nodeToRemove = cursor->next;
    if (nodeToRemove == cursor)
    {
        cursor == nullptr;
    }
    else
    {
        cursor->next = nodeToRemove->next;
    }
    delete nodeToRemove;
}


int main()
{
    CircularyLinkedList<std::string> playlist;
    playlist.add("Stayin Alive");
    playlist.add("Le Freak");
    playlist.add("Jive Talkin");

    playlist.advance();
    playlist.advance();
    playlist.remove();
    playlist.add("Disco Inferno");
    playlist.advance();
    
    return EXIT_SUCCESS;
}
