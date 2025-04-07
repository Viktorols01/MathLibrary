#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <type_traits>

namespace MathLibrary {
    template<typename T, typename = std::enable_if<std::is_arithmetic_v<T>>>
    class Vector {
        private:
        T* components; 
        std::size_t dimensions;
        public:  
        // Constructor
        Vector(T* components, std::size_t dimensions) : components(components), dimensions(dimensions) {};

        // Member functions
        double magnitude() const;
        Vector normalize() const;
        double dot(const Vector &other) const;
        Vector cross(const Vector &other) const;

        // Operator overloads
        Vector operator+(const Vector &other) const;
        Vector operator-(const Vector &other) const;
        Vector operator*(double scalar) const;
        Vector operator*(Vector vector) const;
        bool operator==(const Vector &other) const;
    };
}

#endif