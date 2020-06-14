// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Matrix4x4.h"
#include "Math/Entity/Vector4/Hash.h"

#include <functional>

namespace std {

template <typename T>
struct hash<simple::Matrix4x4<T>> {
	size_t operator()(simple::Matrix4x4<T> const& value) const {
		size_t output = 17;

		output = output * 31 + hash<simple::Vector4<T>>()(value[0]);
		output = output * 31 + hash<simple::Vector4<T>>()(value[1]);
		output = output * 31 + hash<simple::Vector4<T>>()(value[2]);
		output = output * 31 + hash<simple::Vector4<T>>()(value[3]);

		return output;
	}
};

} // namespace std
