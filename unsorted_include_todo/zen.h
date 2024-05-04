#ifndef _ZEN_H
#define _ZEN_H

#include "types.h"
#include "Vector3f.h"
#include "Matrix3f.h"

/*
 * @brief TODO
 */
namespace zen {
	void ogCheckInsCard();
	void calcPuruPuruScale(f32);
	void setNumberTag(P2DScreen*, u32, int*, int);
	void setTextColor(P2DTextBox*, P2DPicture*);
	void getStringCVS(char*, char*, s16);
	void getSpecialNumber(int);
	void setSpecialNumber(int, int);
	void cnvSpecialNumber(char*);
	void cnvSpecialNumberHyphen(char*);
	void getDistPointAndLine(Vector3f, Vector3f, Vector3f, f32&);
	void makeRotMatrix(Vector3f&, Matrix3f&);
	void makePathName(const char*, const char*, char*);
	void loadTexExp(const char*, bool, bool);
} // namespace zen

#endif
