// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Entity/Matrix2x2/Function.h"
#include "Math/Entity/Matrix2x2/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Matrix2x2 Function", "[Matrix2x2 Function]") {
	Vector2<float> a(1, 2);
	Vector2<float> b(3, 4);

	Matrix2x2<float> A(a, a);
	Matrix2x2<float> B(b, b);

	SECTION("Matrix2x2<T> transpose(Matrix2x2<T> const& value)") {
		auto res = math::transpose(A);
		auto ref = Matrix2x2<float>(
				Vector2<float>(1, 1),
				Vector2<float>(2, 2));

		REQUIRE(res == ref);
	}

	SECTION("T const* getPointer(Matrix2x2<T> const& value)") {
		auto* res = math::getPointer(A);

		REQUIRE(res[0] == 1);
		REQUIRE(res[1] == 2);
		REQUIRE(res[2] == 1);
		REQUIRE(res[3] == 2);
	}
}

} // namespace simple
