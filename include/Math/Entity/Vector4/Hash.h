// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Vector4.h"

#include <functional>

namespace std {

template <typename T>
struct hash<simple::Vector4<T>> {
	size_t operator()(simple::Vector4<T> const& value) const {
		size_t output = 17;

		output = output * 31 + hash<T>()(value.x);
		output = output * 31 + hash<T>()(value.y);
		output = output * 31 + hash<T>()(value.z);
		output = output * 31 + hash<T>()(value.w);

		return output;
	}
};

} // namespace std
