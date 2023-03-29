#include <iostream>
#include <cstdlib>
#include <list>
//exception QueueEmpty
class QueueEmpty
{
public:
    QueueEmpty(const std::string &err) : error(err) {}
    std::string getMessage() const { return error; }

private:
    std::string error;
};


template <typename E>
class Queue
{
public:
    Queue(): numberOfElements(0) {};
    ~Queue();
    void enqueue(const E &elem);
    void dequeue();
    const E front();
    int size() const { return numberOfElements; }
private:
    std::list<E> data;
    int numberOfElements;
};

template <typename E>
Queue<E>::~Queue()
{
}

template <typename E>
const E Queue<E>::front()
{
    if (numberOfElements == 0)
        throw QueueEmpty("Queue is empty");
    return data.front();
}

template <typename E>
void Queue<E>::enqueue(const E &elem)
{
    data.emplace_back(elem);
    numberOfElements++;
}

template <typename E>
void Queue<E>::dequeue()
{
    if (numberOfElements == 0)
        throw QueueEmpty("Queue is empty");
    data.pop_front();
    numberOfElements--;
}


int main()
{
    Queue<int> p = Queue<int>();
    p.enqueue(1);
    p.enqueue(2);
    p.dequeue();
    p.enqueue(3);

    while (p.size() > 0)
    {
        std::cout << p.front() << std::endl;
        p.dequeue();
    }

    return EXIT_SUCCESS;
};
