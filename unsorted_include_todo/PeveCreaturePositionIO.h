#ifndef _PEVECREATUREPOSITIONIO_H
#define _PEVECREATUREPOSITIONIO_H

/**
 * .obj __vt__22PeveCreaturePositionIO, weak
 * .4byte __RTTI__22PeveCreaturePositionIO
 * .4byte 0
 * .4byte input__22PeveCreaturePositionIOFR9NVector3f
 * .4byte output__22PeveCreaturePositionIOFR9NVector3f
*/

/**
 * @brief TODO
 */
struct PeveCreaturePositionIO {
	virtual void input(NVector3f &);  // _08
	virtual void output(NVector3f &); // _0C

};

#endif
