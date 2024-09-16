#ifndef _ZEN_OGSUB_H
#define _ZEN_OGSUB_H

#include "types.h"

struct Matrix3f;
struct P2DPicture;
struct P2DScreen;
struct P2DTextBox;
struct Vector3f;

namespace zen {

// global utility functions
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
