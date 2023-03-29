#include <iostream>
#include <cstdlib>
#include <queue>

//error handling must be implemented by the developer.
int main()
{
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();

    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << "empty: " << q.empty() << std::endl;
    q.pop();
    q.pop();
    std::cout << "empty after pops: " << q.empty() << std::endl;

    return EXIT_SUCCESS;

}
