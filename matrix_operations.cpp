
// matrix_operations.cpp

#include "matrix_operations.h"
#include <iostream>
#include <vector>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}


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

// Function to create and return a 2D vector (matrix) for rowReductionwith user input
std::vector<std::vector<double>> createRowReductionMatrix(int var) {

    int rows =  var;
    int cols = var + 1;
    // Create a vector of vectors
    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols, 0));

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
    std::cout<<"Row Reduction Matrix created successfully\n\n";

    return matrix;
}

std::vector<std::vector<double>> createMatrixForInverse(int var) {

    int rows =  var;
    int cols = var;
    // Create a vector of vectors
    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols, 0));

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


void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void displayRowReductionSolve(const std::vector<double>& solution) {
    std::cout << "Solution with Row Reduction method:\n";
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
    }
}

std::vector<double> rowReductionSolve(std::vector<std::vector<double>>& augmentedMatrix) {
    int n = augmentedMatrix.size();

    std::cout << "Initial Augmented Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            std::cout << augmentedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Forward elimination
    for (int i = 0; i < n; ++i) {
        // Find the pivot row
        int pivotRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(augmentedMatrix[j][i]) > std::abs(augmentedMatrix[pivotRow][i])) {
                pivotRow = j;
            }
        }

        // Swap the current row with the pivot row
        std::swap(augmentedMatrix[i], augmentedMatrix[pivotRow]);

        std::cout << "After swapping (Pivot at row " << i + 1 << "):\n";
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j <= n; ++j) {
                std::cout << augmentedMatrix[k][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        // Make the diagonal element 1
        double pivot = augmentedMatrix[i][i];
        for (int j = i; j <= n; ++j) {
            augmentedMatrix[i][j] /= pivot;
        }

        std::cout << "After making diagonal element 1:\n";
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j <= n; ++j) {
                std::cout << augmentedMatrix[k][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        // Eliminate other rows
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];
                for (int k = i; k <= n; ++k) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }

        std::cout << "After eliminating other rows:\n";
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j <= n; ++j) {
                std::cout << augmentedMatrix[k][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Extract the solution vector
    std::vector<double> solution(n);
    for (int i = 0; i < n; ++i) {
        solution[i] = augmentedMatrix[i][n];
    }

    std::cout << "Final Augmented Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            std::cout << augmentedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return solution;
}

std::vector<std::vector<double>> findMatrixInverse(std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();

    // Augment the matrix with the identity matrix
    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i) {
        augmentedMatrix[i][i + n] = 1.0;
        for (int j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = matrix[i][j];
        }
    }

    std::cout << "Augmented Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            std::cout << augmentedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Perform Gaussian Elimination
    for (int i = 0; i < n; ++i) {
        // Find the pivot row
        int pivotRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(augmentedMatrix[j][i]) > std::abs(augmentedMatrix[pivotRow][i])) {
                pivotRow = j;
            }
        }

        // Swap the current row with the pivot row
        std::swap(augmentedMatrix[i], augmentedMatrix[pivotRow]);

        // Make the diagonal element 1
        double pivot = augmentedMatrix[i][i];
        for (int j = i; j < 2 * n; ++j) {
            augmentedMatrix[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];
                for (int k = i; k < 2 * n; ++k) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }

        // Display intermediate steps
        std::cout << "Intermediate Augmented Matrix (Step " << i + 1 << "):\n";
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 2 * n; ++k) {
                std::cout << augmentedMatrix[j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Extract the inverse matrix from the augmented matrix
    std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverseMatrix[i][j] = augmentedMatrix[i][j + n];
        }
    }

    std::cout << "Inverse Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << inverseMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return inverseMatrix;
}



