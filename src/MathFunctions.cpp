#include "MathFunctions.h"
#include "Matrix.h"

namespace MathLibrary {

void verifyInput(Matrix<float> A, Matrix<float> b) {
  if (A.getRowCount() != A.getColCount()) {
    throw std::invalid_argument("Matrix not quadratic for gmres.");
  }
  if (A.getRowCount() != b.getRowCount()) {
    throw std::invalid_argument("Matrices not matching for gmres.");
  }
}

Matrix<float> gmres(Matrix<float> A, Matrix<float> b) {
  verifyInput(A, b);
  Matrix<float> x{b.getRowCount(), 1};
  return x;
}

Matrix<float> arnoldiIteration(Matrix<float> A, Matrix<float> b, int n) {
  verifyInput(A, b);
  if (n == 0) {
    return b;
  } else {
    return A * b;
  }
}

} // namespace MathLibrary