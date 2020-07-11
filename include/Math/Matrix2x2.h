// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector2.h"

#include <cstdint>

namespace simple {

template <typename T>
class Matrix2x2 {
public:
	Matrix2x2();
	Matrix2x2(Vector2<T> const& x, Vector2<T> const& y);

	Vector2<T>& operator[](uint32_t column);
	Vector2<T> const& operator[](uint32_t column) const;
private:
	Vector2<T> mColumns[2];
};

using Mat2 = Matrix2x2<float>;

template <typename T>
Matrix2x2<T>::Matrix2x2() {
	mColumns[0] = Vector2<T>(1, 0);
	mColumns[1] = Vector2<T>(0, 1);
}

template <typename T>
Matrix2x2<T>::Matrix2x2(Vector2<T> const& x, Vector2<T> const& y) {
	mColumns[0] = x;
	mColumns[1] = y;
}

template <typename T>
Vector2<T>& Matrix2x2<T>::operator[](uint32_t column) {
	return mColumns[column];
}

template <typename T>
Vector2<T> const& Matrix2x2<T>::operator[](uint32_t column) const {
	return mColumns[column];
}

} // namespace simple
