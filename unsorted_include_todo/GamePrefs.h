#ifndef _GAMEPREFS_H
#define _GAMEPREFS_H

/**
 * .obj __vt__9GamePrefs, global
 * .4byte __RTTI__9GamePrefs
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__9GamePrefsFR18RandomAccessStream
 * .4byte write__9GamePrefsFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

/**
 * @brief TODO
 */
struct GamePrefs : public ANode {
	virtual void read(RandomAccessStream &);  // _0C
	virtual void write(RandomAccessStream &); // _10

};

#endif
