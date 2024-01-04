#ifndef _CAMERA_H
#define _CAMERA_H

/*
 * @brief TODO
 */
struct Camera {
	void projectWorldPoint(Graphics&, Vector3f&);
	Camera();
};

#endif
