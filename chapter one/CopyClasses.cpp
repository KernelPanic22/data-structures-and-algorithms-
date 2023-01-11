#include <iostream>
#include <cstdlib>

using namespace std;

class Vector
{
public:
    Vector(int s);
    int &operator[](int i);
    int size();
    ~Vector();
    Vector(const Vector &v);
    Vector &operator=(const Vector &v);

private:
    int *data;
    int sz;
};

Vector::Vector(int s)
{
    data = new int[s];
    sz = s;
}

int &Vector::operator[](int i)
{
    return data[i];
}

int Vector::size()
{
    return sz;
}

Vector::~Vector()
{
    delete[] data;
}

Vector::Vector(const Vector &v)
{
    data = new int[v.sz];
    sz = v.sz;
    for (int i = 0; i < sz; i++)
    {
        data[i] = v.data[i];
    }
}

// we change the operator= to return a reference to the object
Vector &Vector::operator=(const Vector &v)
{
    // we check if the object is not in the same memory space
    if (this != &v)
    {
        // we delete the old data
        delete[] data;
        // we allocate new space
        data = new int[v.sz];
        // we set the size
        sz = v.sz;
        // we copy the data
        for (int i = 0; i < sz; i++)
        {
            data[i] = v.data[i];
        }
    }
    // we return a reference to the new object
    return *this;
}

int main()
{
    Vector v(3);
    v[0] = 1;
    Vector v2 = v;
    Vector v3(v);

    // we can check that the 3 vectors are in
    // different memory spaces meaning that they are different objects
    cout << "v space of memory" << &v << endl;
    cout << "v2 space of memory" << &v2 << endl;
    cout << "v3 space of memory" << &v3 << endl;

    return EXIT_SUCCESS;
}
