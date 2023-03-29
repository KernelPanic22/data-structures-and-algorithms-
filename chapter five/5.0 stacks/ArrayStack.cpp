#include<iostream>
#include<cstdlib>

class ExceptionBase{
    public:
        ExceptionBase(const std::string& err): error(err){}
        std::string getMessage() const { return error; }
    private:
        std::string error;
};

class StackFull : public ExceptionBase{
    public:
        StackFull(const std::string& err): ExceptionBase(err){}
};

class StackEmpty : public ExceptionBase{
    public:
        StackEmpty(const std::string& err): ExceptionBase(err){}
};

template<typename E>
class ArrayStack{
    enum { DEF_CAPACITY = 10 };
    public:
        ArrayStack(int cap = DEF_CAPACITY);
        ~ArrayStack();
        int size() const;
        bool empty() const;
        const E& top() const;
        void push(const E& e);
        void pop();
    private:
        E* data;
        int capacity;
        int indexLast;
};

template<typename E>
ArrayStack<E>::ArrayStack(int cap){
    data = new E[cap];
    capacity = cap;
    indexLast = -1;
}

template<typename E>
ArrayStack<E>::~ArrayStack(){
    delete [] data;
}

template<typename E>
int ArrayStack<E>::size() const{
    return indexLast + 1;
}

template<typename E>
bool ArrayStack<E>::empty() const{
    return indexLast < 0;
}

template<typename E>
const E& ArrayStack<E>::top() const{
    if(empty()) throw StackEmpty("Stack is empty");
    return data[indexLast];
}

template<typename E>
void ArrayStack<E>::push(const E& e){
    if(size() == capacity) throw StackFull("Stack is full");
    data[++indexLast] = e;
}

template<typename E>
void ArrayStack<E>::pop(){
    --indexLast;
}

int main(){
    ArrayStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);

    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << stack.top() << std::endl;
    stack.push(11);
    stack.push(12);
    stack.push(13);

};