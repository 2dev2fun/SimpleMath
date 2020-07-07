// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Vector3.h"

#include <cmath>

namespace simple {
namespace math {

inline extern float const PI     = 3.141592f;
inline extern float const TWO_PI = PI / 2.0f;

inline extern Vec3 const RIGHT   { 1.0f, 0.0f,  0.0f };
inline extern Vec3 const UP      { 0.0f, 1.0f,  0.0f };
inline extern Vec3 const FORWARD { 0.0f, 0.0f, -1.0f };

template <typename T>
T max(T const& a, T const& b) {
	return a < b ? b : a;
}

template <typename T>
T min(T const& a, T const& b) {
	return a < b ? a : b;
}

template <typename T>
T power(T base, T exponent) {
	return std::pow(base, exponent);
}

inline float abs(float value) {
	return std::fabs(value);
}

inline float cos(float value) {
	return std::cos(value);
}

inline float sin(float value) {
	return std::sin(value);
}

inline float tan(float value) {
	return std::tan(value);
}

inline float cot(float value) {
	return 1.0f / tan(value);
}

inline float acos(float value) {
	return std::acos(value);
}

inline float asin(float value) {
	return std::asin(value);
}

inline float sqrt(float value) {
	return std::sqrt(value);
}

inline float fmod(float numer, float denom) {
	return std::fmod(numer, denom);
}

inline float atan2(float y, float x) {
	return std::atan2(y, x);
}

inline float clamp(float value, float lower, float upper) {
	return min(upper, max(lower, value));
}

inline float lerp(float previous, float next, float fraction) {
	return previous + fraction * (next - previous);
}

inline bool nearZero(float value, float epsilon = 0.001f) {
	return abs(value) <= epsilon ? true : false;
}

inline float radians(float degrees) {
	return degrees * PI / 180.0f;
}

inline float degrees(float radians) {
	return radians * 180.0f / PI;
}

} // namespace math
} // namespace simple
