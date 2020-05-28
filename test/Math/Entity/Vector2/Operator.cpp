// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Entity/Vector2/Operator.h"

#include <catch2/catch.hpp>

namespace simple {

TEST_CASE("Math Vector2 Operator", "[Vector2 Operator]") {
	Vector2<float> a(1, 2);
	Vector2<float> b(3, 4);

	SECTION("Vector2<T>& operator+=(Vector2<T>& left, U right)") {
		auto res = a;
		res += 2;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T>& operator-=(Vector2<T>& left, U right)") {
		auto res = b;
		res -= 2;
		auto ref = a;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T>& operator*=(Vector2<T>& left, U right)") {
		auto res = a;
		res *= 2;
		auto ref = Vector2<float>(2, 4);

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T>& operator+=(Vector2<T>& left, Vector2<T> const& right)") {
		auto res = a;
		res += b;
		auto ref = Vector2<float>(4, 6);

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T>& operator-=(Vector2<T>& left, Vector2<T> const& right)") {
		auto res = a;
		res -= b;
		auto ref = Vector2<float>(-2, -2);

		REQUIRE(res == ref);
	}

	SECTION("bool operator==(Vector2<T> const& left, Vector2<T> const& right)") {
		REQUIRE(a == a);
		REQUIRE(b == b);
	}

	SECTION("bool operator!=(Vector2<T> const& left, Vector2<T> const& right)") {
		REQUIRE(a != b);
		REQUIRE(b != a);
	}

	SECTION("Vector2<T> operator+(Vector2<T> const& left, Vector2<T> const& right)") {
		auto res = a + b;
		auto ref = Vector2<float>(4, 6);

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator-(Vector2<T> const& left, Vector2<T> const& right)") {
		auto res = a - b;
		auto ref = Vector2<float>(-2, -2);

		REQUIRE(res == ref);
	}

	SECTION("T operator*(Vector2<T> const& left, Vector2<T> const& right)") {
		auto res = a * b;
		auto ref = 11;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator+(Vector2<T> const& left, U right)") {
		auto res = a + 2;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator-(Vector2<T> const& left, U right)") {
		auto res = b - 2;
		auto ref = a;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator*(Vector2<T> const& left, U right)") {
		auto res = a * 2;
		auto ref = Vector2<float>(2, 4);

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator+(U left, Vector2<T> const& right)") {
		auto res = 2 + a;
		auto ref = b;

		REQUIRE(res == ref);
	}

	SECTION("Vector2<T> operator*(U left, Vector2<T> const& right)") {
		auto res = 2 * a;
		auto ref = Vector2<float>(2, 4);

		REQUIRE(res == ref);
	}
}

} // namespace simple
