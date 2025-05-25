#ifndef _JAUDIO_FILTER3D_H
#define _JAUDIO_FILTER3D_H

#include "types.h"

typedef struct Vector3D_ Vector3D_;
typedef struct TVector3D_ TVector3D_;
typedef struct Object3D_ Object3D_;
typedef struct Filter_ Filter_;

struct Vector3D_ {
	f32 x, y, z;
};

f32 V3D_GetAngle(Vector3D_* input_vec);
f64 V3D_Abs(Vector3D_* input_vec);

#endif
