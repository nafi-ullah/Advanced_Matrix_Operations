// main.cpp

#include <iostream>
#include "matrix_operations.h"





int main() {
   /* int rows = 2;
    int cols = 2;

    std::cout<<"Enter your first matrix element\n";
    std::vector<std::vector<int>> matrix1 = createMatrixWithInput(rows, cols);
    std::cout<<"Enter your second matrix element\n";
    std::vector<std::vector<int>> matrix2 = createMatrixWithInput(rows, cols);


    std::vector<std::vector<int>> result = addMatrices(matrix1, matrix2);
    std::vector<std::vector<int>> subresult = subtractMatrices(matrix1, matrix2);
    std::vector<std::vector<int>> multiplyresult = multiplyMatrices(matrix1, matrix2);

    displayMatrix(multiplyresult);
    */

    /*
   std::vector<std::vector<double>> matrix1 = createRowReductionMatrix(3);

    // Find the solution vector
    std::vector<double> solution = rowReductionSolve(matrix1);

    // Display the solution
    displayRowReductionSolve(solution);
    */

   std::vector<std::vector<double>> matrix1 = createMatrixForInverse(3);

    // Find the inverse matrix
    std::vector<std::vector<double>> inverseMatrix = findMatrixInverse(matrix1);



    return 0;
}
