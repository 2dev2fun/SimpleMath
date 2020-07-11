// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Vector2.h"
#include "Math/Vector2/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Vector2", "[Vector2]") {
	Vector2<float> a(1, 2);
	Vector2<float> b(3, 4);

	SECTION("Vector2()") {
		Vector2<float> res;
		Vector2<float> ref = Vector2<float>(0, 0);

		REQUIRE(res == ref);
	}

	SECTION("Vector2(T x, T y)") {
		auto res = a;

		REQUIRE(res.x == 1);
		REQUIRE(res.y == 2);
	}

	SECTION("Vector2(T value)") {
		auto res = Vector2<float>(3);

		REQUIRE(res.x == 3);
		REQUIRE(res.y == 3);
	}
}

} // namespace simple
