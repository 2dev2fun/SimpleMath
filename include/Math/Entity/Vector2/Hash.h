// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Vector2.h"

#include <functional>

namespace std {

template <typename T>
struct hash<simple::Vector2<T>> {
	size_t operator()(simple::Vector2<T> const& value) const {
		size_t output = 17;

		output = output * 31 + hash<T>()(value.x);
		output = output * 31 + hash<T>()(value.y);

		return output;
	}
};

} // namespace std
