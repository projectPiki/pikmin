#ifndef _ZEN_H
#define _ZEN_H

/*
 * @brief TODO
 */
struct zen {
	void ogCheckInsCard();
	void calcPuruPuruScale(float);
	void setNumberTag(P2DScreen*, unsigned long, int*, int);
	void setTextColor(P2DTextBox*, P2DPicture*);
	void getStringCVS(char*, char*, short);
	void getSpecialNumber(int);
	void setSpecialNumber(int, int);
	void cnvSpecialNumber(char*);
	void cnvSpecialNumberHyphen(char*);
	void getDistPointAndLine(Vector3f, Vector3f, Vector3f, float&);
	void makeRotMatrix(Vector3f&, Matrix3f&);
	void makePathName(const char*, const char*, char*);
	void loadTexExp(const char*, bool, bool);
};

#endif
