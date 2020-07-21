// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include <cstdint>

namespace simple {

template<typename T>
class Vector4 {
public:
	Vector4();
	Vector4(T x, T y, T z, T w);
	explicit Vector4(T value);

	T& operator[](uint32_t index);
	T const& operator[](uint32_t index) const;

	T x;
	T y;
	T z;
	T w;
};

using Vec4  = Vector4<float>;
using Vec4f = Vector4<float>;
using Vec4i = Vector4<int32_t>;

template <typename T>
Vector4<T>::Vector4() : x(0), y(0), z(0), w(0) {}

template <typename T>
Vector4<T>::Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

template <typename T>
Vector4<T>::Vector4(T value) : x(value), y(value), z(value), w(value) {}

template <typename T>
T& Vector4<T>::operator[](uint32_t index) {
	return *(&x + index);
}

template <typename T>
T const& Vector4<T>::operator[](uint32_t index) const {
	return *(&x + index);
}

} // namespace simple
