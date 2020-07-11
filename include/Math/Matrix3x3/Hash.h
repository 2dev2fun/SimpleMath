// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix3x3.h"
#include "Math/Vector3/Hash.h"

#include <functional>

namespace std {

template <typename T>
struct hash<simple::Matrix3x3<T>> {
	size_t operator()(simple::Matrix3x3<T> const& value) const {
		size_t output = 17;

		output = output * 31 + hash<simple::Vector3<T>>()(value[0]);
		output = output * 31 + hash<simple::Vector3<T>>()(value[1]);
		output = output * 31 + hash<simple::Vector3<T>>()(value[2]);

		return output;
	}
};

} // namespace std
