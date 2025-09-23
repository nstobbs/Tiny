#pragma once
#include "TinyMaths/types.h"

namespace Tiny
{

template<typename T, size_t N>
struct Vector
{
    std::array<T, N> data;
};

template<typename T, size_t N>
Vector<T, N> add(Vector<T, N> &a, Vector<T, N> &b) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result[i] = a.data[i] + b.data[i];
    }
    return result;
};

template<typename T, size_t N>
Vector<T, N> subtract(Vector<T, N> &a, Vector<T, N> &b) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result[i] = a.data[i] - b.data[i];
    }
    return result;
};

template<typename T, size_t N>
Vector<T, N> multiply(Vector<T, N> &a, T &scalar) {
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++) {
        result[i] = a.data[i] * scalar;
    }
    return result;
};

/* Define Vec */
using Vec2f = Vector<f32, 2>;
using Vec3f = Vector<f32, 3>;
using Vec4f = Vector<f32, 4>;

using Vec2i = Vector<i32, 2>;
using Vec3i = Vector<i32, 3>;
using Vec4i = Vector<i32, 4>;

using Vec2u = Vector<u32, 2>;
using Vec3u = Vector<u32, 3>;
using Vec4u = Vector<u32, 4>;
}