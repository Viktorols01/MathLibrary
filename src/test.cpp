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

    Vector u(3);
    float components[]{1, 2, 3};
    Vector v = Vector(components, 3);
    Vector w = u + 2*v;
    printVector(u);
    printVector(v);
    printVector(w);
    return 0;
}