#pragma once
#include "Tiny/Types.h"

#include <array>
#include <cmath>
#include <ostream>
#include <typeinfo>
#include <format>

namespace Tiny {

template<typename T, size_t N>
struct Vector {
    std::array<T, N> data{};

    constexpr Vector() : data{} {};

    template<typename... Args, typename = std::enable_if_t<sizeof...(Args) == N>>
    constexpr Vector(Args... args) : data{{static_cast<T>(args)...}} {};
};

template<typename T, size_t N>
constexpr bool operator==(const Vector<T, N> &left, const Vector<T, N> &right) {
    for (size_t i = 0; i < N; i++) {
        if (left.data[i] != right.data[i]) {
            return false;
        }
    }
    return true;
};

template<typename T, size_t N>
constexpr bool operator!=(const Vector<T, N> &left, const Vector<T, N> &right) {
    return !(left == right);
};

/* For DocTests Outputting Strings */
template<typename T, size_t N>
std::ostream& operator<<(std::ostream &os, const Vector<T, N> &thisVector) {
    std::ostringstream stream;
    stream << std::format("Vector<{}, {}>", typeid(T).name(), N) << " {";
    for (size_t i = 0; i < N; i++) {
        if (i == N - 1) {
            stream << thisVector.data[i];
        } else {
            stream << thisVector.data[i] << ", ";
        };
    };
    stream << "}";
    return os << stream.str();
};

template<typename T, size_t N>
constexpr Vector<T, N> operator*(const Vector<T, N> &left, const Vector<T, N> &right) {
    Vector<T, N> result; 
    for (size_t i = 0; i < N; i++) {
        result.data[i] = left.data[i] * right.data[i];
    }
    return result;
};

template<typename T, size_t N>
Vector<T, N> operator*(const Vector<T, N> &a, T scalar) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] * scalar;
    }
    return result;
};

template<typename T, size_t N>
Vector<T, N> operator+(const Vector<T, N> &left, const Vector<T, N> &right) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result.data[i] = left.data[i] + right.data[i];
    }
    return result;
};

template<typename T, size_t N>
Vector<T, N> operator-(const Vector<T, N> &left, const Vector<T, N> &right) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result.data[i] = left.data[i] - right.data[i];
    }
    return result;
};

template<typename T, size_t N>
Vector<T, N> operator/(const Vector<T, N> &a, T scalar) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] / scalar;
    }
    return result;
};

template<typename T, size_t N>
T dotProduct(const Vector<T, N> &a, const Vector<T, N> &b) {
    T result = static_cast<T>(0);
    for (size_t i = 0; i < N; i++) {
        result += a.data[i] * b.data[i];
    };
    return result;
};

template<typename T>
Vector<T, 3> crossProduct(const Vector<T, 3> &a, const Vector<T, 3> &b) {
    Vector<T, 3> result;
    result.data[0] = (a.data[1] * b.data[2]) - (a.data[2] * b.data[1]);
    result.data[1] = (a.data[2] * b.data[0]) - (a.data[0] * b.data[2]);
    result.data[2] = (a.data[0] * b.data[1]) - (a.data[1] * b.data[0]);
    return result;
};

template<typename T, size_t N>
T length(const Vector<T, N> &a) {
    T result = static_cast<T>(0);
    for (size_t i = 0; i < N; i++) {
        result += a.data[i] * a.data[i];
    };
    return sqrt(result);
};

template<typename T, size_t N>
Vector<T, N> normalize(const Vector<T, N> &a) {
    T len = length(a);
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] / len;
    };
    return result;
};

template<typename T, size_t N>
Vector<T, N> project(const Vector<T, N> &from, const Vector<T, N> &to) {
    return multiply(to, dotProduct(from, to) / pow(length(to), static_cast<T>(2.0f)));
};

/* Note: This reflect function is based of the formula used in physics, where the
vector being reflected is based on a incoming vector and is "bounced" into an outgoing vector. 
Instead of reflecting an outgoing vector to an "flipped" outgoing vector. Hence why the
direction vector is inverted in this function.*/
template<typename T, size_t N>
Vector<T, N> reflect(const Vector<T, N> &direction, const Vector<T, N> &normal) {
    Vector<T, N> negDirection = multiply(direction, static_cast<T>(-1.0f));
    Vector<T, N> c = subtract(negDirection, project(negDirection, normal));
    return subtract(project(negDirection, normal), c);
};

/* Declare Vectors */
using Vec2f = Vector<f32, 2>;
using Vec3f = Vector<f32, 3>;
using Vec4f = Vector<f32, 4>;

using Vec2i = Vector<i32, 2>;
using Vec3i = Vector<i32, 3>;
using Vec4i = Vector<i32, 4>;

}