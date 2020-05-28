// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Entity/Matrix4x4.h"
#include "Math/Entity/Matrix4x4/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Matrix4x4", "[Matrix4x4]") {
	Vector4<float> a( 1,  2,  3,  4);
	Vector4<float> b( 5,  6,  7,  8);
	Vector4<float> c( 9, 10, 11, 12);
	Vector4<float> d(13, 14, 15, 16);

	SECTION("Matrix4x4()") {
		auto a = Vector4<float>(1, 0, 0, 0);
		auto b = Vector4<float>(0, 1, 0, 0);
		auto c = Vector4<float>(0, 0, 1, 0);
		auto d = Vector4<float>(0, 0, 0, 1);

		Matrix4x4<float> res;

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
		REQUIRE(res[2] == c);
		REQUIRE(res[3] == d);
	}

	SECTION("Matrix4x4(Vector4<T> const& x, Vector4<T> const& y, Vector4<T> const& z, Vector4<T> const& w)") {
		Matrix4x4<float> res(a, b, c, d);

		REQUIRE(res[0] == a);
		REQUIRE(res[1] == b);
		REQUIRE(res[2] == c);
		REQUIRE(res[3] == d);
	}
}

} // namespace simple
