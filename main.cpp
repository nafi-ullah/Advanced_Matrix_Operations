// main.cpp

#include <iostream>
#include "matrix_operations.h"
#include <vector>

// Function to create and return a 2D vector (matrix) with user input
std::vector<std::vector<int>> createMatrixWithInput(int rows, int cols) {
    // Create a vector of vectors
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    // Take input for matrix elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}


int main() {
    int rows = 3;
    int cols = 3;


    std::vector<std::vector<int>> myMatrix = createMatrixWithInput(rows, cols);


    std::cout << "Matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << myMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
