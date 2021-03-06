// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Quaternion.h"
#include "Math/Vector3/Function.h"

#include <cassert>
#include <cmath>
#include <stdexcept>

namespace simple {
namespace math {

template <typename T>
T squared_length(Quaternion<T> const& value) {
	return value.x * value.x + value.y * value.y + value.z * value.z + value.w * value.w;
}

template <typename T>
T length(Quaternion<T> const& value) {
	return std::sqrt(squared_length(value));
}

template <typename T>
Quaternion<T> normalize(Quaternion<T> const& value) {
	T l = length(value);
	if (l == 0) {
		std::runtime_error("length == 0!");
	}
	return Quaternion<T>(value.x / l, value.y / l, value.z / l, value.w / l);
}

template <typename T>
Quaternion<T> conjugate(Quaternion<T> const& value) {
	return Quaternion<T>(-value.x, -value.y, -value.z, value.w);
}

template <typename T>
Quaternion<T> concatenate(Quaternion<T> const& left, Quaternion<T> const& right) {
	Quaternion<T> output;

	Vector3<T> qv(left [0], left [1], left [2]);
	Vector3<T> pv(right[0], right[1], right[2]);

	Vector3<T> vec = left.w * pv + right.w * qv + cross(pv, qv);

	output.x = vec.x;
	output.y = vec.y;
	output.z = vec.z;
	output.w = left.w * right.w - pv * qv;

	return output;
}

} // namespace math
} // namespace simple
