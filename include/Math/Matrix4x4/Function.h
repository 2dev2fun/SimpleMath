// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Matrix4x4.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"
#include "Math/Vector3/Function.h"
#include "Math/Vector3/Operator.h"

namespace simple {
namespace math {

template <typename T>
Matrix4x4<T> transpose(Matrix4x4<T> const& value) {
	return Matrix4x4<T>(
			Vector4<T>(value[0][0], value[1][0], value[2][0], value[3][0]),
			Vector4<T>(value[0][1], value[1][1], value[2][1], value[3][1]),
			Vector4<T>(value[0][2], value[1][2], value[2][2], value[3][2]),
			Vector4<T>(value[0][3], value[1][3], value[2][3], value[3][3]));
}

template <typename T>
T const* getPointer(Matrix4x4<T> const& value) {
	return &value[0][0];
}

template <typename T>
Matrix4x4<T> lookAt(Vector3<T> const& eye, Vector3<T> const& target, Vector3<T> const& up) {
	Vector3<T> forward = normalize(eye - target);
	Vector3<T> left    = normalize(cross(up, forward));
	Vector3<T> newUp   = cross(forward, left);

	Vector3<T> translation = invert(Vector3<T>(left * eye, newUp * eye, forward * eye));

	return Matrix4x4<T>(
			Vector4<T>(left.x,        newUp.x,       forward.x,     0),
			Vector4<T>(left.y,        newUp.y,       forward.y,     0),
			Vector4<T>(left.z,        newUp.z,       forward.z,     0),
			Vector4<T>(translation.x, translation.y, translation.z, 1));
}

template <typename T>
Matrix4x4<T> perspective(T fov, T width, T height, T near, T far) {
	const T aspect      = width / height;
	const T tanfov      = std::tan(fov / 2.0f);
	const T invertRange = 1.0f / (far - near);

	const T a = 1.0f / (aspect * tanfov);
	const T b = 1.0f / tanfov;
	const T c = -(far + near) * invertRange;
	const T d = -1;
	const T e = -2 * far * near * invertRange;

	return Matrix4x4<T>(
			Vector4<T>(a, 0, 0, 0),
			Vector4<T>(0, b, 0, 0),
			Vector4<T>(0, 0, c, d),
			Vector4<T>(0, 0, e, 0));
}

template <typename T>
Matrix4x4<T> translate(Vector3<T> const& translation) {
	return Matrix4x4<T>(
		Vector4<T>(1,             0,             0,             0),
		Vector4<T>(0,             1,             0,             0),
		Vector4<T>(0,             0,             1,             0),
		Vector4<T>(translation.x, translation.y, translation.z, 1));
}

template <typename T>
Matrix4x4<T> rotate(Quaternion<T> const& rotation) {
	Mat4 output;

	output[0][0] = 1.0f - 2.0f * rotation.y * rotation.y - 2.0f * rotation.z * rotation.z;
	output[0][1] = 2.0f        * rotation.x * rotation.y + 2.0f * rotation.w * rotation.z;
	output[0][2] = 2.0f        * rotation.x * rotation.z - 2.0f * rotation.w * rotation.y;
	output[0][3] = 0.0f;

	output[1][0] = 2.0f        * rotation.x * rotation.y - 2.0f * rotation.w * rotation.z;
	output[1][1] = 1.0f - 2.0f * rotation.x * rotation.x - 2.0f * rotation.z * rotation.z;
	output[1][2] = 2.0f        * rotation.y * rotation.z + 2.0f * rotation.w * rotation.x;
	output[1][3] = 0.0f;

	output[2][0] = 2.0f        * rotation.x * rotation.z + 2.0f * rotation.w * rotation.y;
	output[2][1] = 2.0f        * rotation.y * rotation.z - 2.0f * rotation.w * rotation.x;
	output[2][2] = 1.0f - 2.0f * rotation.x * rotation.x - 2.0f * rotation.y * rotation.y;
	output[2][3] = 0.0f;

	output[3][0] = 0.0f;
	output[3][1] = 0.0f;
	output[3][2] = 0.0f;
	output[3][3] = 1.0f;

	return output;
}

template <typename T>
Matrix4x4<T> rotateX(T theta) {
	return Matrix4x4<T>(
			Vector4<T>(1.0f,  0.0f,            0.0f,            0.0f),
			Vector4<T>(0.0f,  std::cos(theta), std::sin(theta), 0.0f),
			Vector4<T>(0.0f, -std::sin(theta), std::cos(theta), 0.0f),
			Vector4<T>(0.0f,  0.0f,            0.0f,            1.0f));
}

template <typename T>
Matrix4x4<T> rotateY(T theta) {
	return Matrix4x4<T>(
			Vector4<T>( std::cos(theta), 0.0f, std::sin(theta), 0.0f),
			Vector4<T>( 0.0f,            1.0f, 0.0f,            0.0f),
			Vector4<T>(-std::sin(theta), 0.0f, std::cos(theta), 0.0f),
			Vector4<T>( 0.0f,            0.0f, 0.0f,            1.0f));
}

template <typename T>
Matrix4x4<T> rotateZ(T theta) {
	return Matrix4x4<T>(
			Vector4<T>( std::cos(theta), std::sin(theta), 0.0f, 0.0f),
			Vector4<T>(-std::sin(theta), std::cos(theta), 0.0f, 0.0f),
			Vector4<T>( 0.0f,            0.0f,            1.0f, 0.0f),
			Vector4<T>( 0.0f,            0.0f,            0.0f, 1.0f));
}

template <typename T>
Matrix4x4<T> scale(T scale) {
	return Matrix4x4<T>(
		Vector4<T>(scale, 0,     0,     0    ),
		Vector4<T>(0,     scale, 0,     0    ),
		Vector4<T>(0,     0,     scale, 0    ),
		Vector4<T>(0,     0,     0,     scale));
}

} // namespace math
} // namespace simple
