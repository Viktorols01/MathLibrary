#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include "Matrix.h"

namespace MathLibrary {
    Matrix<float> gmres(Matrix<float> A, Matrix<float> b);
    Matrix<float> arnoldiIteration(Matrix<float> A, Matrix<float> b, int n);
}

#endif