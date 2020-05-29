// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Vector4.h"

#include <ostream>

namespace simple {

template <typename T, typename U>
Vector4<T>& operator+=(Vector4<T>& left, U right) {
	left.x += right;
	left.y += right;
	left.z += right;
	left.w += right;
	return left;
}

template <typename T, typename U>
Vector4<T>& operator-=(Vector4<T>& left, U right) {
	left.x -= right;
	left.y -= right;
	left.z -= right;
	left.w -= right;
	return left;
}

template <typename T, typename U>
Vector4<T>& operator*=(Vector4<T>& left, U right) {
	left.x *= right;
	left.y *= right;
	left.z *= right;
	left.w *= right;
	return left;
}

template <typename T>
Vector4<T>& operator+=(Vector4<T>& left, Vector4<T> const& right) {
	left.x += right.x;
	left.y += right.y;
	left.z += right.z;
	left.w += right.w;
	return left;
}

template <typename T>
Vector4<T>& operator-=(Vector4<T>& left, Vector4<T> const& right) {
	left.x -= right.x;
	left.y -= right.y;
	left.z -= right.z;
	left.w -= right.w;
	return left;
}

template <typename T>
bool operator==(Vector4<T> const& left, Vector4<T> const& right) {
	return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
}

template <typename T>
bool operator!=(Vector4<T> const& left, Vector4<T> const& right) {
	return !(left == right);
}

template <typename T>
Vector4<T> operator+(Vector4<T> const& left, Vector4<T> const& right) {
	return Vector4<T>(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

template <typename T>
Vector4<T> operator-(Vector4<T> const& left, Vector4<T> const& right) {
	return Vector4<T>(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}

template <typename T>
T operator*(Vector4<T> const& left, Vector4<T> const& right) {
	return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
}

template <typename T, typename U>
Vector4<T> operator+(Vector4<T> const& left, U right) {
	return Vector4<T>(left.x + right, left.y + right, left.z + right, left.w + right);
}

template <typename T, typename U>
Vector4<T> operator-(Vector4<T> const& left, U right) {
	return Vector4<T>(left.x - right, left.y - right, left.z - right, left.w - right);
}

template <typename T, typename U>
Vector4<T> operator*(Vector4<T> const& left, U right) {
	return Vector4<T>(left.x * right, left.y * right, left.z * right, left.w * right);
}

template <typename T, typename U>
Vector4<T> operator+(U left, Vector4<T> const& right) {
	return Vector4<T>(left + right.x, left + right.y, left + right.z, left + right.w);
}

template <typename T, typename U>
Vector4<T> operator*(U left, Vector4<T> const& right) {
	return Vector4<T>(left * right.x, left * right.y, left * right.z, left * right.w);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector4<T> const& /*value*/) {
	return os << "Vector4<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Vector4<float> const& /*value*/) {
	return os << "Vector4<float>";
}

} // namespace simple
