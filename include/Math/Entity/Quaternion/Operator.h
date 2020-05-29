// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Quaternion.h"

#include <ostream>

namespace simple {

template <typename T>
bool operator==(Quaternion<T> const& left, Quaternion<T> const& right) {
	return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
}

template <typename T>
bool operator!=(Quaternion<T> const& left, Quaternion<T> const& right) {
	return !(left == right);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Quaternion<T> const& /*value*/) {
	return os << "Quaternion<T>";
}

template <>
inline std::ostream& operator<<(std::ostream& os, Quaternion<float> const& /*value*/) {
	return os << "Quaternion<float>";
}

} // namespace simple
