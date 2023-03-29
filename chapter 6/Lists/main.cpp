#include "List.h"
#include <iostream>
#include "Iterator.h"
#include "Node.h"

int main(){
List<int> list = List<int>();
list.push_front(1);
list.push_back(3);
list.push_front(2);

Iterator<int>* begin = list.begin();
Iterator<int>* end = list.end();

while (begin != end)
{
    std::cout << begin << std::endl;
    begin++;
}

}