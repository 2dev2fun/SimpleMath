// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Matrix2x2.h"
#include "Math/Entity/Vector2/Hash.h"

#include <functional>

namespace std {

template <typename T>
struct hash<simple::Matrix2x2<T>> {
	size_t operator()(simple::Matrix2x2<T> const& value) const {
		size_t output = 17;

		output = output * 31 + hash<simple::Vector2<T>>()(value[0]);
		output = output * 31 + hash<simple::Vector2<T>>()(value[1]);

		return output;
	}
};

} // namespace std
