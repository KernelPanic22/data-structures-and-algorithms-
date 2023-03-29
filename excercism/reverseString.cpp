#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include<algorithm>


std::string reverse_string(std::string s){
     std::reverse(s.begin(),s.end());
    return s;
}

int main(){
    std::string s="robot";
    std::cout<<reverse_string(s);
}