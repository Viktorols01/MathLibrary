#include <iostream>
#include "Vector.h"

using namespace MathLibrary;

void printVector(const Vector& vector) {
    std::cout << "(";
    for (std::size_t i = 0; i < vector.getDimension(); i++) {
        if (i != 0) {
            std::cout << ",";
        }
        std::cout << vector[i];
    }
    std::cout << ")";
}

int main() {
    printf("Hello world! \n");
    printf("Size of float: %d \n", sizeof(float));

    Vector v(3);
    printVector(v);
    return 0;
}