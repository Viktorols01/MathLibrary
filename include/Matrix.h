#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <type_traits>

namespace MathLibrary {
    class Matrix {
        private:
        float** components; 
        std::size_t rowCount;
        std::size_t colCount;
        public:  
        Matrix(float** components, std::size_t row, std::size_t col);
        Matrix(std::size_t row, std::size_t col);
        ~Matrix();

        std::size_t getRowCount() const;
        std::size_t getColCount() const;
        float get(int row, int col) const;
        void set(int row, int col, float value);

        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(float scalar) const;
        friend Matrix operator*(float scalar, const Matrix matrix);
        float* operator[](int index) const;

    };
}

#endif