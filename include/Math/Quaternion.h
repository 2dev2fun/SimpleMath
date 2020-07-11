// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector3.h"

#include <cmath>
#include <cstdint>

namespace simple {

template<typename T>
class Quaternion {
public:
	Quaternion();
	Quaternion(T x, T y, T z, T w = 1);
	Quaternion(Vector3<T> const& axis, T angle);

	T& operator[](uint32_t index);
	T const& operator[](uint32_t index) const;

	T x;
	T y;
	T z;
	T w;
};

using Quat = Quaternion<float>;

template <typename T>
Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(1) {}

template <typename T>
Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

template <typename T>
Quaternion<T>::Quaternion(Vector3<T> const& axis, T angle) {
	T scalar = std::sin(angle / 2.0f);
	x = axis.x * scalar;
	y = axis.y * scalar;
	z = axis.z * scalar;
	w = std::cos(angle / 2.0f);
}

template <typename T>
T& Quaternion<T>::operator[](uint32_t index) {
	return *(&x + index);
}

template <typename T>
T const& Quaternion<T>::operator[](uint32_t index) const {
	return *(&x + index);
}

} // namespace simple
