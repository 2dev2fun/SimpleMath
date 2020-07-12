// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Quaternion.h"
#include "Math/Vector3.h"

#include <cassert>
#include <cmath>
#include <random>

namespace simple {
namespace math {

template <typename T>
Vector3<T> cross(Vector3<T> const& left, Vector3<T> const& right) {
	return Vector3<T>(
		left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
}

template <typename T>
T lengthSquared(Vector3<T> const& value) {
	return value.x * value.x + value.y * value.y + value.z * value.z;
}

template <typename T>
T length(Vector3<T> const& value) {
	return std::sqrt(lengthSquared(value));
}

template <typename T>
Vector3<T> normalize(Vector3<T> const& value) {
	T length = math::length(value);
	assert(length);
	return Vector3<T>(value.x / length, value.y / length, value.z / length);
}

template <typename T>
T const* getPointer(Vector3<T> const& value) {
	return &value[0];
}

template <typename T>
Vector3<T> invert(Vector3<T> const& value) {
	return Vector3<T>(-value.x, -value.y, -value.z);
}

template <typename T>
Vector3<T> transform(Vector3<T> const& vector, Quaternion<T> const& rotation) {
	Vec3 qv(rotation.x, rotation.y, rotation.z);
	return vector + 2.0f * cross(qv, cross(qv, vector) + rotation.w * vector);
}

template <typename T>
Vector3<T> linearRandom(Vector3<T> const& min, Vector3<T> const& max) {
	return Vector3<T> {
		min.x + (max.x - min.x) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX),
		min.y + (max.y - min.y) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX),
		min.z + (max.z - min.z) * static_cast<T>(std::rand()) / static_cast<T>(RAND_MAX)
	};
}

} // namespace math
} // namespace simple
