// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Matrix3x3/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Matrix3x3 Operator", "[Matrix3x3 Operator]") {
	Vector3<float> a(1, 2, 3);
	Vector3<float> b(4, 5, 6);

	Matrix3x3<float> A(a, a, a);
	Matrix3x3<float> B(b, b, b);

	SECTION("bool operator==(Matrix3x3<T> const& left, Matrix3x3<T> const& right)") {
		REQUIRE(A == A);
		REQUIRE(B == B);
	}

	SECTION("bool operator!=(Matrix3x3<T> const& left, Matrix3x3<T> const& right)") {
		REQUIRE(A != B);
		REQUIRE(B != A);
	}

	SECTION("Matrix3x3<T> operator+(Matrix3x3<T> const& left, Matrix3x3<T> const& right)") {
		auto res = A + B;
		auto ref = Matrix3x3<float>(
				Vector3<float>(5, 7, 9),
				Vector3<float>(5, 7, 9),
				Vector3<float>(5, 7, 9));

		REQUIRE(res == ref);
	}

	SECTION("Matrix3x3<T> operator-(Matrix3x3<T> const& left, Matrix3x3<T> const& right)") {
		auto res = A - B;
		auto ref = Matrix3x3<float>(
				Vector3<float>(-3, -3, -3),
				Vector3<float>(-3, -3, -3),
				Vector3<float>(-3, -3, -3));

		REQUIRE(res == ref);
	}

	SECTION("Vector3<T> operator*(Matrix3x3<T> const& left, Vector3<T> const& right)") {
		auto res = A * b;
		auto ref = Vector3<float>(15, 30, 45);

		REQUIRE(res == ref);
	}

	SECTION("Matrix3x3<T> operator*(Matrix3x3<T> const& left, Matrix3x3<T> const& right)") {
		auto res = A * B;
		auto ref = Matrix3x3<float>(
				Vector3<float>(15, 30, 45),
				Vector3<float>(15, 30, 45),
				Vector3<float>(15, 30, 45));

		REQUIRE(res == ref);
	}

	SECTION("Matrix3x3<T> operator*(Matrix3x3<T> const& left, U right)") {
		auto res = A * 2;
		auto ref = Matrix3x3<float>(
				Vector3<float>(2, 4, 6),
				Vector3<float>(2, 4, 6),
				Vector3<float>(2, 4, 6));

		REQUIRE(res == ref);
	}

	SECTION("Matrix3x3<T> operator*(U left, Matrix3x3<T> const& right)") {
		auto res = 2 * A;
		auto ref = Matrix3x3<float>(
				Vector3<float>(2, 4, 6),
				Vector3<float>(2, 4, 6),
				Vector3<float>(2, 4, 6));

		REQUIRE(res == ref);
	}
}

} // namespace simple
