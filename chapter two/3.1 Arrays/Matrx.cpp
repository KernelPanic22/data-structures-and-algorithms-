#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    // 2D array
    // we use an two parameter vector constructor that receives the number 
    // of rows and for the columns we use a single parameter vector constructor with the number of columns
    std::vector<std::vector<int>> matrix(3, std::vector<int>(6));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = i + j;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}