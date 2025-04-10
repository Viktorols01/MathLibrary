#include "Matrix.h"
#include <cmath>
#include <stdexcept>

namespace MathLibrary
{

    Matrix::Matrix(float **components, std::size_t row, std::size_t col) : rowCount(row), colCount(col)
    {
        this->components = new float*[row];
        for (std::size_t i = 0; i < row; i++)
        {
            this->components[i] = new float[col]; 
            for (std::size_t j = 0; j < col; j++)
            {
                this->components[i][j] = components[i][j];
            }
        }
    }

    Matrix::Matrix(std::size_t row, std::size_t col) : rowCount(row), colCount(col)
    {
        this->components = new float*[row];
        for (std::size_t i = 0; i < row; i++)
        {
            this->components[i] = new float[col]; 
            for (std::size_t j = 0; j < col; j++)
            {
                this->components[i][j] = 0;
            }
        }
    }

    Matrix::~Matrix() {
        components = new float*[rowCount];
        for (std::size_t i = 0; i < rowCount; i++)
        {
            delete[] components[i];
        }
        delete[] components;
    }

    std::size_t Matrix::getRowCount() const {
        return rowCount;
    }

    std::size_t Matrix::getColCount() const {
        return colCount;
    }

    float Matrix::get(int row, int col) const {
        return components[row][col];
    }

    void Matrix::set(int row, int col, float value) {
        components[row][col] = value;
    }

    Matrix Matrix::operator+(const Matrix &other) const
     {
        if (rowCount != other.rowCount || colCount != other.colCount) {
            throw std::invalid_argument("Matrix dimensions not valid for addition.");
        }

        Matrix result (rowCount, colCount);

        for (std::size_t i = 0; i < rowCount; i++)
        {
            for (std::size_t j = 0; j < colCount; j++)
            {
                result.components[i][j] = components[i][j] + other.components[i][j];
            }
        }
        return result;
    }
}