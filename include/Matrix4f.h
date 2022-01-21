#include "types.h"

struct Matrix4f {
	void makeIdentity();

	float m_matrix[4][4];
};
