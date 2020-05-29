// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Matrix4x4.h"
#include "Math/Entity/Quaternion.h"
#include "Math/Entity/Vector3.h"
#include "Math/Entity/Vector3/Function.h"
#include "Math/Entity/Vector3/Operator.h"

#include <cmath>

namespace simple {
namespace math {

Mat4 lookAt(Vec3 const& eye, Vec3 const& target, Vec3 const& up);
Mat4 perspective(float fov, float widht, float height, float near, float far);
Vec3 transform(Vec3 const& vector, Quat const& rotation);
Mat4 createTranslation(Vec3 const& translation);
Mat4 createRotation(Quat const& rotation);
Mat4 createScale(float scale);

inline Mat4 lookAt(Vec3 const& eye, Vec3 const& target, Vec3 const& up) {
	Vec3 forward = math::normalize(eye - target);
	Vec3 left    = math::normalize(math::cross(up, forward));
	Vec3 newUp   = math::cross(forward, left);

	Vec3 translation = math::invert(Vec3(left * eye, newUp * eye, forward * eye));

	return Mat4(
			Vec4(left.x,        newUp.x,       forward.x,     0),
			Vec4(left.y,        newUp.y,       forward.y,     0),
			Vec4(left.z,        newUp.z,       forward.z,     0),
			Vec4(translation.x, translation.y, translation.z, 1));
}

inline Mat4 perspective(float fov, float widht, float height, float near, float far) {
	float const aspect      = widht / height;
	float const tanfov      = std::tan(fov / 2.0f);
	float const invertRange = 1.0f / (far - near);

	float const a = 1.0f / (aspect * tanfov);
	float const b = 1.0f / tanfov;
	float const c = -(far + near) * invertRange;
	float const d = -1;
	float const e = -2 * far * near * invertRange;

	return Mat4(Vec4(a, 0, 0, 0), Vec4(0, b, 0, 0), Vec4(0, 0, c, d), Vec4(0, 0, e, 0));
}

inline Vec3 transform(Vec3 const& vector, Quat const& rotation) {
	Vec3 qv(rotation.x, rotation.y, rotation.z);
	return vector + 2.0f * math::cross(qv, math::cross(qv, vector) + rotation.w * vector);
}

inline Mat4 createTranslation(Vec3 const& translation) {
	return Mat4(
		Vec4(1,             0,             0,             0),
		Vec4(0,             1,             0,             0),
		Vec4(0,             0,             1,             0),
		Vec4(translation.x, translation.y, translation.z, 1));
}

inline Mat4 createRotation(Quat const& rotation) {
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

inline Mat4 createScale(float scale) {
	return Mat4(
		Vec4(scale, 0,     0,     0),
		Vec4(0,     scale, 0,     0),
		Vec4(0,     0,     scale, 0),
		Vec4(0,     0,     0,     scale));
}

} // namespace math
} // namespace simple
