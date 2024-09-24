#ifndef _ZEN_MATH_H
#define _ZEN_MATH_H

#include "types.h"

struct Vector3f;
struct Matrix3f;
struct Matrix4f;
struct Quat;

namespace zen {

// global utility functions:
void getDistPointAndLine(Vector3f, Vector3f, Vector3f, f32&);
void makeRotMatrix(Vector3f&, Matrix3f&);

namespace ZenQuat {

// unused globals
void GetMatrix(const Quat&, Matrix3f&);
void GetMatrix(const Quat&, Matrix4f&);
void GetRotate(const Quat&, Vector3f&);

} // namespace ZenQuat

} // namespace zen

#endif
