#include<iostream>
#include<cstdlib>

int binaryFib(int k){
    if(k <= 1)
        return k;
    else
        return binaryFib(k - 1) + binaryFib(k - 2);
}

int main(){
    std::cout << binaryFib(5) << std::endl;
    // We iterate 5 times to get the 5th fibonacci number with a tree 5 layers deep

    return EXIT_SUCCESS;
}
