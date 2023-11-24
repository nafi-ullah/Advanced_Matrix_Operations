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
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<"Matrix created successfully\n\n";

    return matrix;
}

std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    // Check if matrices have the same dimensions
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        std::cerr << "Error: Matrices have different dimensions. Addition is not possible.\n";
        return {};  // Return an empty matrix to indicate an error
    }

    // Create a matrix to store the result
    std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1[0].size(), 0));

    // Perform matrix addition
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[0].size(); ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<int>> subtractMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    // Check if matrices have the same dimensions
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        std::cerr << "Error: Matrices have different dimensions. Addition is not possible.\n";
        return {};  // Return an empty matrix to indicate an error
    }

    // Create a matrix to store the result
    std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix1[0].size(), 0));

    // Perform matrix addition
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[0].size(); ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    // Check if matrices can be multiplied
    if (matrix1[0].size() != matrix2.size()) {
        std::cerr << "Error: Matrices cannot be multiplied. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n";
        return {};  // Return an empty matrix to indicate an error
    }

    // Create a matrix to store the result
    std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));

    // Perform matrix multiplication
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix2[0].size(); ++j) {
            for (size_t k = 0; k < matrix1[0].size(); ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}


int main() {
    int rows = 2;
    int cols = 2;

    std::cout<<"Enter your first matrix element\n";
    std::vector<std::vector<int>> matrix1 = createMatrixWithInput(rows, cols);
    std::cout<<"Enter your second matrix element\n";
    std::vector<std::vector<int>> matrix2 = createMatrixWithInput(rows, cols);


    std::vector<std::vector<int>> result = addMatrices(matrix1, matrix2);
    std::vector<std::vector<int>> subresult = subtractMatrices(matrix1, matrix2);
    std::vector<std::vector<int>> multiplyresult = multiplyMatrices(matrix1, matrix2);

    // Display the result if addition was successful
    if (!result.empty()) {
        std::cout << "Resultant Matrix:\n";
        for (size_t i = 0; i < result.size(); ++i) {
            for (size_t j = 0; j < result[0].size(); ++j) {
                std::cout << multiplyresult[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


    return 0;
}
