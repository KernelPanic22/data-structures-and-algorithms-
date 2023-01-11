#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    /*
    If statement are used to execute a block of code if a condition is true
    */
    
    // enter two numbers
    
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if(a > b){
        cout << "a is greater than b" << endl;
    }else{
        cout << "b is greater than a" << endl;
    }
    
    /*
    Switch statement are used to execute a block of code depending on the 
    value of a variable
    */

    // enter a number between 1 and 3
    int c;
    cout << "Enter a number between 1 and 3: ";
    cin >> c;
    switch(c){
        case 1:
            cout << "You entered 1" << endl;
            break;
        case 2:
            cout << "You entered 2" << endl;
            break;
        case 3:
            cout << "You entered 3" << endl;
            break;
        default:
            cout << "You entered a number that is not between 1 and 3" << endl;
            break;
    }

}