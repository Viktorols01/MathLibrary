#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

namespace MathLibrary {

/*
Assumes T is numeric
*/

template <typename T> class Matrix {
private:
  int rowCount;
  int colCount;
  T *components;

public:
  Matrix(int rowCount, int colCount) : rowCount(rowCount), colCount(colCount) {
    components = new T[rowCount * colCount]();
  }
  ~Matrix() { delete[] components; }
  Matrix(const Matrix &matrix) = default;

  T get(int row, int col) const { return components[row + rowCount * col]; }

  void set(int row, int col, T value) {
    components[row + rowCount * col] = value;
  }

  int getRowCount() const { return rowCount; }

  int getColCount() const { return colCount; }

  Matrix transpose() const {
    Matrix result(colCount, rowCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < colCount; j++) {
        result.set(j, i, get(i, j));
      }
    }
    return result;
  }

  Matrix operator+(const Matrix &other) const {
    if (rowCount != other.rowCount || colCount != other.colCount) {
      throw std::invalid_argument(
          "Matrix<T> dimensions do not match for addition.");
    }
    Matrix result(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < colCount; j++) {
        result.set(i, j, get(i, j) + other.get(i, j));
      }
    }
    return result;
  }

  Matrix operator-(const Matrix &other) const {
    if (rowCount != other.rowCount || colCount != other.colCount) {
      throw std::invalid_argument(
          "Matrix<T> dimensions do not match for subtraction.");
    }
    Matrix result(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < colCount; j++) {
        result.set(i, j, get(i, j) - other.get(i, j));
      }
    }
    return result;
  }

  Matrix operator*(int value) const {
    Matrix result(rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < colCount; j++) {
        result.set(i, j, get(i, j) * value);
      }
    }
    return result;
  }

  Matrix operator*(const Matrix &other) {
    if (colCount != other.rowCount) {
      throw std::invalid_argument(
          "Matrix dimensions do not match for multiplication.");
    }
    Matrix result(rowCount, other.colCount);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < other.colCount; j++) {
        T sum = 0;
        for (int k = 0; k < colCount; k++) {
          sum += get(i, k) * other.get(k, j);
        }
        result.set(i, j, sum);
      }
    }
    return result;
  }
  void operator*=(T value) {
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < colCount; j++) {
        this->set(i, j, get(i, j) * value);
      }
    }
  }
};
} // namespace MathLibrary

#endif