// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector2.h"

#include <cassert>
#include <cmath>
#include <random>

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

template <typename T>
Vector2<T> linearRandom(Vector2<T> const& min, Vector2<T> const& max) {
	return Vector2<T> {
		min.x + (max.x - min.x) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX),
		min.y + (max.y - min.y) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX)
	};
}

} // namespace math
} // namespace simple
