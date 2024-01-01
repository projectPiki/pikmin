#ifndef _CNDBOMBABLE_H
#define _CNDBOMBABLE_H

/**
 * .obj __vt__11CndBombable, weak
 * .4byte __RTTI__11CndBombable
 * .4byte 0
 * .4byte satisfy__11CndBombableFP8CollPart
*/

/**
 * @brief TODO
 */
struct CndBombable {
	virtual void satisfy(CollPart *);  // _08 (weak)

};

#endif
