// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Quaternion/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Quaternion Operator", "[Quaternion Operator]") {
	Quaternion<float> a(1, 2, 3, 4);
	Quaternion<float> b(5, 6, 7, 8);

	SECTION("bool operator==(Quaternion<T> const& left, Quaternion<T> const& right)") {
		REQUIRE(a == a);
		REQUIRE(b == b);
	}

	SECTION("bool operator!=(Quaternion<T> const& left, Quaternion<T> const& right)") {
		REQUIRE(a != b);
		REQUIRE(b != a);
	}
}

} // namespace simple
