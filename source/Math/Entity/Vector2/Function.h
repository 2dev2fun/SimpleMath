// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Vector2.h"

#include <cassert>
#include <cmath>

namespace simple {
namespace math {

template <typename T>
T lengthSquared(Vector2<T> const& value) {
	return value.x * value.x + value.y * value.y;
}

template <typename T>
T length(Vector2<T> const& value) {
	return std::sqrt(lengthSquared(value));
}

template <typename T>
Vector2<T> normalize(Vector2<T> const& value) {
	T length = math::length(value);
	assert(length);
	return Vector2<T>(value.x / length, value.y / length);
}

template <typename T>
T const* getPointer(Vector2<T> const& value) {
	return &value[0];
}

template <typename T>
Vector2<T> invert(Vector2<T> const& value) {
	return Vector2<T>(-value.x, -value.y);
}

} // namespace math
} // namespace simple
