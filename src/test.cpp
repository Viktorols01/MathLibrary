#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace MathLibrary;

void printVector(const Vector& vector) {
    std::cout << "(";
    for (std::size_t i = 0; i < vector.getDimension(); i++) {
        if (i != 0) {
            std::cout << ",";
        }
        std::cout << vector.get(i);
    }
    std::cout << ")";
}

void printMatrix(const Matrix& matrix) {
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
    printf("Size of float: %d \n", sizeof(float));

    Vector u(3);
    float components[]{1, 2, 3};
    Vector v = Vector(components, 3);
    Vector w = u + 2*v;
    printVector(u);
    printVector(v);
    printVector(w);
    printf("Magnitude of v: %f", v.magnitude());

    Matrix m1 = Matrix(2, 3);
    m1.set(0, 0, 7.0);
    printMatrix(m1);
    return 0;
}