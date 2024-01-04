#ifndef _TEKIPERSONALITY_H
#define _TEKIPERSONALITY_H

/**
 * .obj __vt__15TekiPersonality, global
 * .4byte __RTTI__15TekiPersonality
 * .4byte 0
 * .4byte read__15TekiPersonalityFR18RandomAccessStreami
 * .4byte write__15TekiPersonalityFR18RandomAccessStream
 */

/**
 * @brief TODO
 */
struct TekiPersonality {
	virtual void read(RandomAccessStream&, int); // _08
	virtual void write(RandomAccessStream&);     // _0C

	TekiPersonality();
	void reset();
	void input(TekiPersonality&);
};

#endif
