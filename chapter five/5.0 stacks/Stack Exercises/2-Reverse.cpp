#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
/*
Write a program that reads in a sequence of characters and prints them
    in reverse order.  Use a stack.
*/
template <typename E>
void insert_at_bottom(std::stack<E>& st, E x)
{
 
    if (st.size() == 0) {
        st.push(x);
    }
    else {
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
        st.push(a);
    }
}


template <typename E>
void reverse(std::stack<E>& stack)
{

    if (stack.size() > 0)
    {
        E elem = stack.top();
        stack.pop();
        reverse(stack);

        insert_at_bottom(stack,elem);
    }
}

int main()
{
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    reverse(stack);

    while (!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
};