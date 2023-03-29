#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val = 0) : data(val), next(nullptr) {}

    Node(int val, Node *tempNext) : data(val), next(tempNext) {}
};

class SingleLinkedList
{
private:
    Node *head;

public:
    SingleLinkedList()
    {
        head = NULL;
    };
    void insert(int data);
    void remove(int data);
    void removeFront();
    void display();
    bool empty() const;
    ~SingleLinkedList()
    {
        while (!empty())
        {
            removeFront();
        }
    }
};

bool SingleLinkedList::empty() const
{
    return head == nullptr;
}

void SingleLinkedList::insert(int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void SingleLinkedList::removeFront()
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        Node *old = head;
        head = old->next;
        delete old;
    }
}

void SingleLinkedList::remove(int val)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            return;
        }
        else
        {
            if (prev == nullptr)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
        }
    }
}

void SingleLinkedList::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    
    SingleLinkedList list;
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.display();
    list.remove(3);
    list.removeFront();
    list.display();
    return 0;
}