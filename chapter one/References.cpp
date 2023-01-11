#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
    /*
    references are a way to give an alternative name to an object
    */
    string author = "William Shakespeare";
    string& ref = author;
    ref = "Edgar Allan Poe";
    //now author is "Edgar Allan Poe"
    cout << "author = " << author << endl;
}