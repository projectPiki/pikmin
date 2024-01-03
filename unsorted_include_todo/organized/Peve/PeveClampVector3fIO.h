#ifndef _PEVECLAMPVECTOR3FIO_H
#define _PEVECLAMPVECTOR3FIO_H

/**
 * .obj __vt__19PeveClampVector3fIO, global
 * .4byte __RTTI__19PeveClampVector3fIO
 * .4byte 0
 * .4byte input__19PeveClampVector3fIOFR9NVector3f
 * .4byte output__16NVector3fIOClassFR9NVector3f
*/

struct NVector3fIOClass {
	virtual void input(NVector3f &);  // _08
	virtual void output(NVector3f &); // _0C
};

/**
 * @brief TODO
 */
struct PeveClampVector3fIO : public NVector3fIOClass {
	virtual void input(NVector3f &);  // _08

};

#endif
