#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <stdexcept>

namespace MathLibrary
{

    // It appears I must implement the functions
    // here for the template to work?
    // Will have to study this in more detail later
    template <std::size_t rowCount, std::size_t colCount>
    class Matrix
    {
    private:
        float *components;

    public:
        Matrix()
        {
            components = new float[rowCount * colCount]();
        }
        ~Matrix()
        {
            delete[] components;
        }

        // No checking if operation valid --> better performance?
        float get(int row, int col) const
        {
            return components[row + rowCount * col];
        }
        void set(int row, int col, float value)
        {
            components[row + rowCount * col] = value;
        }

        Matrix operator+(const Matrix &other) const
        {
            Matrix result;
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    result.set(i, j, get(i, j) + other.get(i, j));
                }
            }
            return result;
        }
        Matrix operator-(const Matrix &other) const
        {
            Matrix result;
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    result.set(i, j, get(i, j) - other.get(i, j));
                }
            }
            return result;
        }
        float *operator[](int index) const
        {
            Matrix result;
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    result.set(i, j, get(i, j) * index);
                }
            }
            return result;
        }
        template <std::size_t colCountOther>
        Matrix<rowCount, colCountOther> operator*(const Matrix<colCount, colCountOther> &other)
        {
            Matrix<rowCount, colCountOther> result;
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCountOther; j++)
                {
                    float sum = 0;
                    for (int k = 0; k < colCount; k++)
                    {
                        sum += get(i, k) * other.get(k, j);
                    }
                    result.set(i, j) = sum;
                }
            }
            return result;
        }
    };
}

#endif