#include<iostream>
#include<cstdlib>
#include <utility>

std::pair<long,long> linearFib(long k){
    if(k <= 1) return std::make_pair(k,0);
    
        auto p = linearFib(k - 1);
        return std::make_pair(p.first + p.second, p.first);
}

int main(){
    std::cout << linearFib(5).first << std::endl;

    return EXIT_SUCCESS;
}