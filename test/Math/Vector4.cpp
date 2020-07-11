// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector4.h"
#include "Math/Vector4/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Vector4", "[Vector4]") {
	Vector4<float> a(1, 2, 3, 4);
	Vector4<float> b(5, 6, 7, 8);

	SECTION("Vector4()") {
		Vector4<float> res;
		Vector4<float> ref = Vector4<float>(0, 0, 0, 0);

		REQUIRE(res == ref);
	}

	SECTION("Vector4(T x, T y, T z, T w)") {
		auto res = a;

		REQUIRE(res.x == 1);
		REQUIRE(res.y == 2);
		REQUIRE(res.z == 3);
		REQUIRE(res.w == 4);
	}

	SECTION("Vector4(T value)") {
		auto res = Vector4<float>(3);

		REQUIRE(res.x == 3);
		REQUIRE(res.y == 3);
		REQUIRE(res.z == 3);
		REQUIRE(res.w == 3);
	}
}

} // namespace simple
