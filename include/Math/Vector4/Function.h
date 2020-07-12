// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Vector4.h"

#include <cassert>
#include <cmath>
#include <random>

namespace simple {
namespace math {

template <typename T>
T lengthSquared(Vector4<T> const& value) {
	return value.x * value.x + value.y * value.y + value.z * value.z + value.w * value.w;
}

template <typename T>
T length(Vector4<T> const& value) {
	return std::sqrt(lengthSquared(value));
}

template <typename T>
Vector4<T> normalize(Vector4<T> const& value) {
	T length = math::length(value);
	assert(length);
	return Vector4<T>(value.x / length, value.y / length, value.z / length, value.w / length);
}

template <typename T>
T const* getPointer(Vector4<T> const& value) {
	return &value[0];
}

template <typename T>
Vector4<T> invert(Vector4<T> const& value) {
	return Vector4<T>(-value.x, -value.y, -value.z, -value.w);
}

template <typename T>
Vector4<T> linearRandom(Vector4<T> const& min, Vector4<T> const& max) {
	return Vector4<T> {
		min.x + (max.x - min.x) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX),
		min.y + (max.y - min.y) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX),
		min.z + (max.z - min.z) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX),
		min.w + (max.w - min.w) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX)
	};
}

} // namespace math
} // namespace simple
