#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <type_traits>

namespace MathLibrary {
    class Vector {
        private:
        float* components; 
        std::size_t dimension;
        public:  
        // Constructor
        Vector(float* components, std::size_t dimension);
        Vector(std::size_t dimension);
        ~Vector();

        // Member functions
        float magnitude() const;
        Vector normalize() const;
        float dot(const Vector &other) const;
        Vector cross(const Vector &other) const;
        std::size_t getDimension() const;

        // Operator overloads
        Vector operator+(const Vector &other) const;
        Vector operator-(const Vector &other) const;
        Vector operator*(float scalar) const;
        friend Vector operator*(float scalar, const Vector &vector);
        float operator[](int index) const;

    };
}

#endif