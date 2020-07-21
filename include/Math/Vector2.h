// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include <cstdint>

namespace simple {

template<typename T>
class Vector2 {
public:
	Vector2();
	Vector2(T x, T y);
	explicit Vector2(T value);

	T& operator[](uint32_t index);
	T const& operator[](uint32_t index) const;

	T x;
	T y;
};

using Vec2  = Vector2<float>;
using Vec2f = Vector2<float>;
using Vec2i = Vector2<int32_t>;

template <typename T>
Vector2<T>::Vector2() : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <typename T>
Vector2<T>::Vector2(T value) : x(value), y(value) {}

template <typename T>
T& Vector2<T>::operator[](uint32_t index) {
	return *(&x + index);
}

template <typename T>
T const& Vector2<T>::operator[](uint32_t index) const {
	return *(&x + index);
}

} // namespace simple
