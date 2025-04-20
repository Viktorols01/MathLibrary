#include <iostream>
#include "Matrix.h"

using namespace MathLibrary;

template<std::size_t rowCount, std::size_t colCount>
void printMatrix(const Matrix<rowCount, colCount>& matrix) {
    std::cout << "\n";
    for (std::size_t i = 0; i < rowCount; i++) {
        std::cout << "|";
        for (std::size_t j = 0; j < colCount; j++) {
            if (j != 0) {
                std::cout << " ";
            }
            std::cout << matrix.get(i, j); 
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

int main() {
    printf("Hello world! \n");
    printf("Size of float: %d \n", sizeof(float));

    Matrix<2, 3> m1;
    m1.set(0, 0, 7.0);
    printMatrix(m1);
    return 0;
}