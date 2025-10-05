#pragma once
#include "Tiny/Types.h"

#include <array>

namespace Tiny
{

template<typename T, size_t N, size_t M>
struct Matrix {
    T data[N][M];

    constexpr Matrix() : data{} {};
};

template<typename T, size_t N, size_t M>
constexpr bool operator==(const Matrix<T, N, M> &left, const Matrix<T, N, M> &right) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (left.data[i][j] != right.data[i][j]) {
                return false;
            }
        }
    }
    return true;
};

template<typename T, size_t N, size_t M>
constexpr bool operator!=(const Matrix<T, N, M> &left, const Matrix<T, N, M> &right) {
    return !(left == right);
};

template<typename T, size_t N, size_t M>
Matrix<T, N, M> Identity() {
    Matrix<T, N, M> result;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (i == j) {
                result.data[i][j] = static_cast<T>(1.0f);
            }
        }
    }
    return result;
};

/* Declare Matrix */
using Mat2f = Matrix<f32, 2, 2>;
using Mat3f = Matrix<f32, 3, 3>;
using Mat4f = Matrix<f32, 4, 4>;

using Mat2i = Matrix<i32, 2, 2>;
using Mat3i = Matrix<i32, 3, 3>;
using Mat4i = Matrix<i32, 4, 4>;

}