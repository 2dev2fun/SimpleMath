// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#include "Math/Quaternion/Function.h"
#include "Math/Quaternion/Operator.h"

#include <catch2/catch.hpp>

#include <cmath>

namespace simple {

TEST_CASE("Math Quaternion Function", "[Quaternion Function]") {
	Quaternion<float> a(1, 2, 3, 4);
	Quaternion<float> b(5, 6, 7, 8);

	SECTION("T lengthSquared(Quaternion<T> const& value)") {
		auto res = math::squared_length(a);
		auto ref = 30;

		REQUIRE(res == ref);
	}

	SECTION("T length(Quaternion<T> const& value)") {
		auto res = math::length(a);
		auto ref = std::sqrt(math::squared_length(a));

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;
		ref = std::round(ref * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Quaternion<T> normalize(Quaternion<T> const& value)") {
		auto res = math::length(math::normalize(a));
		auto ref = 1.0f;

		res = std::round(res * 1000.0f + 0.5f) / 1000.0f;

		REQUIRE(res == ref);
	}

	SECTION("Quaternion<T> conjugate(Quaternion<T> const& value)") {
		auto res = math::conjugate(a);
		auto ref = Quaternion<float>(-a.x, -a.y, -a.z, a.w);

		REQUIRE(res == ref);
	}
}

} // namespace simple
