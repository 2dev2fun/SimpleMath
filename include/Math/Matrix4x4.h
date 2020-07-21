// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector4.h"

#include <cstdint>

namespace simple {

template <typename T>
class Matrix4x4 {
public:
	Matrix4x4();
	Matrix4x4(Vector4<T> const& x, Vector4<T> const& y, Vector4<T> const& z, Vector4<T> const& w);

	Vector4<T>& operator[](uint32_t column);
	Vector4<T> const& operator[](uint32_t column) const;
private:
	Vector4<T> mColumns[4];
};

using Mat4  = Matrix4x4<float>;
using Mat4f = Matrix4x4<float>;
using Mat4i = Matrix4x4<int32_t>;

template <typename T>
Matrix4x4<T>::Matrix4x4() {
	mColumns[0] = Vector4<T>(1, 0, 0, 0);
	mColumns[1] = Vector4<T>(0, 1, 0, 0);
	mColumns[2] = Vector4<T>(0, 0, 1, 0);
	mColumns[3] = Vector4<T>(0, 0, 0, 1);
}

template <typename T>
Matrix4x4<T>::Matrix4x4(Vector4<T> const& x, Vector4<T> const& y, Vector4<T> const& z, Vector4<T> const& w) {
	mColumns[0] = x;
	mColumns[1] = y;
	mColumns[2] = z;
	mColumns[3] = w;
}

template <typename T>
Vector4<T>& Matrix4x4<T>::operator[](uint32_t column) {
	return mColumns[column];
}

template <typename T>
Vector4<T> const& Matrix4x4<T>::operator[](uint32_t column) const {
	return mColumns[column];
}

} // namespace simple
