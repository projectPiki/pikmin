#ifndef _ODOMETER_H
#define _ODOMETER_H

/*
 * @brief TODO
 */
struct OdoMeter {
	OdoMeter();
	void start(float, float);
	void moving(Vector3f&, Vector3f&);
};

#endif
