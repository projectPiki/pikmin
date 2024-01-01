#ifndef _V3D_H
#define _V3D_H

#include "types.h"
typedef struct Vector3D_ Vector3D_;
typedef struct TVector3D_ TVector3D_;
typedef struct Object3D_ Object3D_;
typedef struct Filter_ Filter_;

struct Vector3D_ {
	f32 x, y, z;
};

double atanf2(float, float);
double sqrtf2(float);

#endif
