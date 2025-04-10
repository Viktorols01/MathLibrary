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
}