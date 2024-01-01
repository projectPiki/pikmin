#ifndef _CORENUCLEUSPROP_H
#define _CORENUCLEUSPROP_H

/**
 * .obj __vt__15CoreNucleusProp, weak
 * .4byte __RTTI__15CoreNucleusProp
 * .4byte 0
 * .4byte read__15CoreNucleusPropFR18RandomAccessStream
 * .4byte __RTTI__15CoreNucleusProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__15CoreNucleusPropFR18RandomAccessStream"
*/

struct ANode {
	virtual void read(RandomAccessStream &);  // _08 (weak)
	virtual void _0C() = 0;                   // _0C
	virtual void _10() = 0;                   // _10
	virtual void getAgeNodeType();            // _14 (weak)
};

/**
 * @brief TODO
 */
struct CoreNucleusProp : public ANode {
	virtual void read(RandomAccessStream &);  // _08 (weak)

};

#endif
