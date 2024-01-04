#ifndef _CULLFRUSTUM_H
#define _CULLFRUSTUM_H

/*
 * @brief TODO
 */
struct CullFrustum {
	void isPointVisible(Vector3f&, float);
	void draw(Graphics&);
	void updateViewPlanes(float, float, float, float);
	void createViewPlanes();
	void update(float, float, float, float);
	void calcVectors(Vector3f&, Vector3f&);
	void calcLookAt(Vector3f&, Vector3f&, Vector3f*);
};

#endif
