#ifndef _MATRIX4F_H
#define _MATRIX4F_H

#include "types.h"

struct Matrix4f {
	void makeIdentity();

	float m_matrix[4][4];
};

#endif
