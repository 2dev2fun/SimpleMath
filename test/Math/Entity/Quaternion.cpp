// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Entity/Quaternion.h"
#include "Math/Entity/Quaternion/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Quaternion", "[Quaternion]") {

	SECTION("Quaternion()") {
		Quaternion<float> res;

		REQUIRE(res.x == 0);
		REQUIRE(res.y == 0);
		REQUIRE(res.z == 0);
		REQUIRE(res.w == 1);
	}

	SECTION("Quaternion(T x, T y, T z)") {
		Quaternion<float> res(2, 2, 2);

		REQUIRE(res.x == 2);
		REQUIRE(res.y == 2);
		REQUIRE(res.z == 2);
		REQUIRE(res.w == 1);
	}

	SECTION("Quaternion(T x, T y, T z, T w)") {
		Quaternion<float> res(1, 2, 3, 4);

		REQUIRE(res.x == 1);
		REQUIRE(res.y == 2);
		REQUIRE(res.z == 3);
		REQUIRE(res.w == 4);
	}
}

} // namespace simple
