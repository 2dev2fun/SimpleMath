// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix2x2.h"
#include "Math/Matrix2x2/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Matrix2x2", "[Matrix2x2]") {
	Vector2<float> a(1, 2);
	Vector2<float> b(3, 4);

	SECTION("Matrix2x2()") {
		auto a = Vector2<float>(1, 0);
		auto b = Vector2<float>(0, 1);

		Matrix2x2<float> res;

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
	}

	SECTION("Matrix2x2(Vector2<T> const& x, Vector2<T> const& y, Vector2<T> const& z)") {
		Matrix2x2<float> res(a, b);

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
	}
}

} // namespace simple
