#include <iostream>
#include <cstdlib>

int binarySum(int a[], int i, int n)
{
    if (n == 1)
        return a[i];
    else
        return binarySum(a, i, n / 2) + binarySum(a, i + n / 2, n / 2);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << binarySum(a, 0, 8) << std::endl;
    // We iterate 3 times to get the sum of the array with a tree 3 layers deep

    return EXIT_SUCCESS;
}