// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector3.h"

#include <cstdint>

namespace simple {

template <typename T>
class Matrix3x3 {
public:
	Matrix3x3();
	Matrix3x3(Vector3<T> const& x, Vector3<T> const& y, Vector3<T> const& z);

	Vector3<T>& operator[](uint32_t column);
	Vector3<T> const& operator[](uint32_t column) const;
private:
	Vector3<T> mColumns[3];
};

using Mat3  = Matrix3x3<float>;
using Mat3f = Matrix3x3<float>;
using Mat3i = Matrix3x3<int32_t>;

template <typename T>
Matrix3x3<T>::Matrix3x3() {
	mColumns[0] = Vector3<T>(1, 0, 0);
	mColumns[1] = Vector3<T>(0, 1, 0);
	mColumns[2] = Vector3<T>(0, 0, 1);
}

template <typename T>
Matrix3x3<T>::Matrix3x3(Vector3<T> const& x, Vector3<T> const& y, Vector3<T> const& z) {
	mColumns[0] = x;
	mColumns[1] = y;
	mColumns[2] = z;
}

template <typename T>
Vector3<T>& Matrix3x3<T>::operator[](uint32_t column) {
	return mColumns[column];
}

template <typename T>
Vector3<T> const& Matrix3x3<T>::operator[](uint32_t column) const {
	return mColumns[column];
}

} // namespace simple
