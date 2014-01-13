/*
 * Vector3.hpp
 *
 *  Created on: Sep 19, 2012
 *      Author: zrbecker
 */

#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

#include <iostream>

namespace z3d {

template <typename T>
class Vector3 {
public:
    Vector3();
    Vector3(T x, T y, T z);

    T x, y, z;
};

template <typename T>
Vector3<T> operator+(const Vector3<T> &v1, const Vector3<T> &v2);

template <typename T>
Vector3<T> operator-(const Vector3<T> &v1, const Vector3<T> &v2);

template <typename T>
Vector3<T> operator+(const Vector3<T> &v);

template <typename T>
Vector3<T> operator-(const Vector3<T> &v);

template <typename T>
Vector3<T> operator*(const T &c, const Vector3<T> &v);

template <typename T>
Vector3<T> operator*(const Vector3<T> &v, const T &c);

template <typename T>
Vector3<T> operator/(const Vector3<T> &v, const T& c);

template <typename T>
bool operator==(const Vector3<T> &v1, const Vector3<T> &v2);

template <typename T>
bool operator!=(const Vector3<T> &v1, const Vector3<T> &v2);

template <typename T>
T dot(const Vector3<T> &v1, const Vector3<T> &v2);

template <typename T>
Vector3<T> cross(const Vector3<T> &v1, const Vector3<T> &v2);

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector3<T> &v);

#include "Vector3.inl"

typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;

}

#endif /* VECTOR3_HPP_ */
