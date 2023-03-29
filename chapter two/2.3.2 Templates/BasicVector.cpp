#include <iostream>
#include <cstdlib>

using namespace std;

// We indicate with template<typename T> that we are going to use a template
template <typename T>
class BasicVector
{
public:
    BasicVector(int capacity = 10);
    T &operator[](int index) { return data[index]; }
    ~BasicVector() { delete[] data; }

private:
    T *data;
    int capacity;
};

// The constructor can allocate any type of data because it is a template
template <typename T>
BasicVector<T>::BasicVector(int capacity)
{
    this->capacity = capacity;
    data = new T[capacity];
}

int main()
{
    BasicVector<int> vectorOne(1);
    vectorOne[0] = 10;
    cout << vectorOne[0] << endl;

    BasicVector<string> vectorTwo(1);
    vectorTwo[0] = "Hello";
    cout << vectorTwo[0] << endl;

    BasicVector<double> vectorThree(10);
    vectorThree[0] = 10.5;
    cout << vectorThree[0] << endl;

    // we can pass a basic vector as a parameter to another basic vector with the same class
    BasicVector<BasicVector<int>> vectorFour(10);
    vectorFour[2][8] = 10;
    cout << vectorFour[2][8] << endl;
    return 0;
}
