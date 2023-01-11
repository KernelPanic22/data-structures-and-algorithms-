#include<iostream>
#include<cstdlib>
#include "FibonacciProgression.cpp"
#include "ArithmeticProgression.cpp"
#include "GeometricProgression.cpp"

using namespace std;

int main(){
    Progression* p;

    cout << "Arithmetic progression with default increment:\n" << endl;
    p = new ArithmeticProgression();
    p->printProgression(10);
    cout << "Arithmetic progression with increment 5:\n" << endl;
    p = new ArithmeticProgression(5);
    p->printProgression(10);


    cout << "Geometric progression with default base:\n" << endl;
    p = new GeometryProgression();
    p->printProgression(10);
    cout << "Geometric progression with base 3:\n" << endl;
    p = new GeometryProgression(3);
    p->printProgression(10);

    cout << "Fibonacci progression with default start values:\n" << endl;
    p = new FibonacciProgression();
    p->printProgression(10);
    cout << "Fibonacci progression with start values 4 and 6:\n" << endl;
    p = new FibonacciProgression(4, 6);
    p->printProgression(10);
    return EXIT_SUCCESS;
}