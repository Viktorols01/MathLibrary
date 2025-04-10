#include "Vector.h"
#include <cmath>
#include <stdexcept>

namespace MathLibrary
{

    Vector::Vector(float *components, std::size_t dimension)
        : dimension(dimension)
    {
        this->components = new float[dimension];
        for (std::size_t i = 0; i < dimension; ++i)
        {
            this->components[i] = components[i];
        }
    }

    Vector::Vector(std::size_t dimensions)
        : dimension(dimensions)
    {
        this->components = new float[dimensions]{};
    }

    Vector::~Vector()
    {
        delete[] this->components;
    }

    float Vector::magnitude() const
    {
        float sum = 0.0;
        for (std::size_t i = 0; i < dimension; i++)
        {
            sum += components[i] * components[i];
        }
        return std::sqrt(sum);
    }

    Vector Vector::normalize() const
    {
        float mag = magnitude();
        if (mag == 0)
        {
            throw std::runtime_error("Cannot normalize a zero vector");
        }
        Vector normalized(dimension);
        for (std::size_t i = 0; i < dimension; ++i)
        {
            normalized.components[i] = components[i] / mag;
        }
        return normalized;
    }

    float Vector::dot(const Vector &other) const
    {
        if (dimension != other.dimension)
        {
            throw std::invalid_argument("Vectors must have the same dimensions for dot product");
        }
        float product = 0.0;
        for (std::size_t i = 0; i < dimension; ++i)
        {
            product += components[i] * other.components[i];
        }
        return product;
    }

    Vector Vector::cross(const Vector& other) const {
    if (dimension != 3 || other.dimension != 3) {
        throw std::invalid_argument("Cross product is only defined for 3D vectors.");
    }

    Vector result(3); 

    result.components[0] = components[1] * other.components[2] - components[2] * other.components[1];
    result.components[1] = components[2] * other.components[0] - components[0] * other.components[2];
    result.components[2] = components[0] * other.components[1] - components[1] * other.components[0];

    return result;
    }

    std::size_t Vector::getDimension() const {
        return dimension;
    }

    float Vector::get(int index) const {
        return components[index];
    }

    void Vector::set(int index, float value) {
        components[index] = value; 
    }
    
    Vector Vector::operator+(const Vector &other) const {
        if (dimension != other.dimension)
        {
            throw std::invalid_argument("Vectors must have the same dimensions for dot product");
        }
        Vector result(dimension); 
        for (std::size_t i = 0; i < dimension; i++) {
            result.components[i] = components[i] + other.components[i];
        }
        return result;
    }

    Vector Vector::operator-(const Vector &other) const {
        if (dimension != other.dimension)
        {
            throw std::invalid_argument("Vectors must have the same dimensions for dot product");
        }
        Vector result(dimension); 
        for (std::size_t i = 0; i < dimension; i++) {
            result.components[i] = components[i] - other.components[i];
        }
        return result;
    }

    Vector Vector::operator*(float scalar) const {
        Vector result(dimension); 
        for (std::size_t i = 0; i < dimension; i++) {
            result.components[i] = components[i] * scalar; 
        }
        return result;
    }

    Vector operator*(float scalar, const Vector& vector) {
        Vector result(vector.dimension); 
        for (std::size_t i = 0; i < vector.dimension; i++) {
            result.components[i] = vector.components[i] * scalar; 
        }
        return result;
    }
} 