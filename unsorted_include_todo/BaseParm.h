#ifndef _BASEPARM_H
#define _BASEPARM_H

/**
 * .obj __vt__8BaseParm, weak
 * .4byte __RTTI__8BaseParm
 * .4byte 0
 * .4byte 0
 * .4byte write__8BaseParmFR18RandomAccessStream
 * .4byte read__8BaseParmFR18RandomAccessStream
*/

/**
 * @brief TODO
 */
struct BaseParm {
	virtual void _08() = 0;                    // _08
	virtual void write(RandomAccessStream &);  // _0C
	virtual void read(RandomAccessStream &);   // _10

};

#endif
