// Copyright (C) 2020 Maxim, 2dev2fun@gmail.com. All rights reserved.

#pragma once

#include "Math/Entity/Matrix4x4.h"
#include "Math/Entity/Quaternion.h"
#include "Math/Entity/Vector3.h"

namespace simple {
namespace math {

Mat4 lookAt(Vec3 const& eye, Vec3 const& target, Vec3 const& up);
Mat4 perspective(float fov, float widht, float height, float near, float far);
Vec3 transform(Vec3 const& vector, Quat const& rotation);
Mat4 createTranslation(Vec3 const& translation);
Mat4 createRotation(Quat const& rotation);
Mat4 createScale(float scale);

} // namespace math
} // namespace simple
