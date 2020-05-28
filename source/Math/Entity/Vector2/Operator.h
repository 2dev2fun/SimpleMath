// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Vector2.h"

#include <ostream>

namespace simple {

template <typename T, typename U>
Vector2<T>& operator+=(Vector2<T>& left, U right) {
	left.x += right;
	left.y += right;
	return left;
}

template <typename T, typename U>
Vector2<T>& operator-=(Vector2<T>& left, U right) {
	left.x -= right;
	left.y -= right;
	return left;
}

template <typename T, typename U>
Vector2<T>& operator*=(Vector2<T>& left, U right) {
	left.x *= right;
	left.y *= right;
	return left;
}

template <typename T>
Vector2<T>& operator+=(Vector2<T>& left, Vector2<T> const& right) {
	left.x += right.x;
	left.y += right.y;
	return left;
}

template <typename T>
Vector2<T>& operator-=(Vector2<T>& left, Vector2<T> const& right) {
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

template <typename T>
bool operator==(Vector2<T> const& left, Vector2<T> const& right) {
	return left.x == right.x && left.y == right.y;
}

template <typename T>
bool operator!=(Vector2<T> const& left, Vector2<T> const& right) {
	return !(left == right);
}

template <typename T>
Vector2<T> operator+(Vector2<T> const& left, Vector2<T> const& right) {
	return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
Vector2<T> operator-(Vector2<T> const& left, Vector2<T> const& right) {
	return Vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T>
T operator*(Vector2<T> const& left, Vector2<T> const& right) {
	return left.x * right.x + left.y * right.y;
}

template <typename T, typename U>
Vector2<T> operator+(Vector2<T> const& left, U right) {
	return Vector2<T>(left.x + right, left.y + right);
}

template <typename T, typename U>
Vector2<T> operator-(Vector2<T> const& left, U right) {
	return Vector2<T>(left.x - right, left.y - right);
}

template <typename T, typename U>
Vector2<T> operator*(Vector2<T> const& left, U right) {
	return Vector2<T>(left.x * right, left.y * right);
}

template <typename T, typename U>
Vector2<T> operator+(U left, Vector2<T> const& right) {
	return Vector2<T>(left + right.x, left + right.y);
}

template <typename T, typename U>
Vector2<T> operator*(U left, Vector2<T> const& right) {
	return Vector2<T>(left * right.x, left * right.y);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector2<T> const& /*value*/) {
	return os << "Vector2<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Vector2<float> const& /*value*/) {
	return os << "Vector2<float>";
}

} // namespace simple
