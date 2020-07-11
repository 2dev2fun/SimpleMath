// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix3x3.h"
#include "Math/Matrix3x3/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Matrix3x3", "[Matrix3x3]") {
	Vector3<float> a(1, 2, 3);
	Vector3<float> b(4, 5, 6);
	Vector3<float> c(7, 8, 9);

	SECTION("Matrix3x3()") {
		auto a = Vector3<float>(1, 0, 0);
		auto b = Vector3<float>(0, 1, 0);
		auto c = Vector3<float>(0, 0, 1);

		Matrix3x3<float> res;

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
		REQUIRE(res[2] == c);
	}

	SECTION("Matrix3x3(Vector3<T> const& x, Vector3<T> const& y, Vector3<T> const& z)") {
		Matrix3x3<float> res(a, b, c);

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
		REQUIRE(res[2] == c);
	}
}

} // namespace simple
