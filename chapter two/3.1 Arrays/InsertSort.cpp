#include <iostream>
#include <cstdlib>

class TSort
{
public:
    template <typename T>
    void insert_sort(int *array, int size)
    {
        for (int i = 1; i < size; i++)
        {
            int current = array[i];
            int j = i - 1;
            while ((j >= 0) && (array[j] > current))
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = current;
        }
    }
};

int main()
{
    TSort sort;
    //unsorted array
    int array[] = { 5, 2, 4, 6, 1, 3 };
    int size = sizeof(array) / sizeof(array[0]);
    sort.insert_sort<int>(array, size);
    return 0;
}