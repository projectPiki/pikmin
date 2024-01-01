#ifndef _NVECTOR3FIOCLASS_H
#define _NVECTOR3FIOCLASS_H

/**
 * .obj __vt__16NVector3fIOClass, weak
 * .4byte __RTTI__16NVector3fIOClass
 * .4byte 0
 * .4byte input__16NVector3fIOClassFR9NVector3f
 * .4byte output__16NVector3fIOClassFR9NVector3f
*/

/**
 * @brief TODO
 */
struct NVector3fIOClass {
	virtual void input(NVector3f &);  // _08
	virtual void output(NVector3f &); // _0C

};

#endif
