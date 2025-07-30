#include <iostream>
#include "Matrix.h"

using namespace MathLibrary;

template<typename T>
void printMatrix(const Matrix<T>& matrix) {
    std::cout << "\n";
    for (std::size_t i = 0; i < matrix.getRowCount(); i++) {
        std::cout << "|";
        for (std::size_t j = 0; j < matrix.getColCount(); j++) {
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
    printf("Size of float: %lu \n", sizeof(float));

    Matrix<float> m(2, 3);
    m.set(0, 0, 7.0);
    Matrix<float> v(3, 1);
    v.set(0, 0, 1.0);
    v.set(0, 0, 1.0);
    printMatrix(m);
    printMatrix(v);
    printMatrix(m*v);
    printMatrix(m.transpose());
    printMatrix(m * m.transpose());
    return 0;
}