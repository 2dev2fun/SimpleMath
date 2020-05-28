// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Entity/Matrix2x2/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Matrix2x2 Operator", "[Matrix2x2 Operator]") {
	Vector2<float> a(1, 2);
	Vector2<float> b(3, 4);

	Matrix2x2<float> A(a, a);
	Matrix2x2<float> B(b, b);

	SECTION("bool operator==(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		REQUIRE(A == A);
		REQUIRE(B == B);
	}

	SECTION("bool operator!=(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		REQUIRE(A != B);
		REQUIRE(B != A);
	}

	SECTION("Matrix2x2<T> operator+(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		auto res = A + B;
		auto ref = Matrix2x2<float>(
				Vector2<float>(4, 6),
				Vector2<float>(4, 6));

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator-(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		auto res = A - B;
		auto ref = Matrix2x2<float>(
				Vector2<float>(-2, -2),
				Vector2<float>(-2, -2));

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator*(Matrix2x2<T> const& left, Vector2<T> const& right)") {
		auto res = A * b;
		auto ref = Vector2<float>(7, 14);

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator*(Matrix2x2<T> const& left, Matrix2x2<T> const& right)") {
		auto res = A * B;
		auto ref = Matrix2x2<float>(
				Vector2<float>(7, 14),
				Vector2<float>(7, 14));

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator*(Matrix2x2<T> const& left, U right)") {
		auto res = A * 2;
		auto ref = Matrix2x2<float>(
				Vector2<float>(2, 4),
				Vector2<float>(2, 4));

		REQUIRE(res == ref);
	}

	SECTION("Matrix2x2<T> operator*(U left, Matrix2x2<T> const& right)") {
		auto res = 2 * A;
		auto ref = Matrix2x2<float>(
				Vector2<float>(2, 4),
				Vector2<float>(2, 4));

		REQUIRE(res == ref);
	}
}

} // namespace simple
