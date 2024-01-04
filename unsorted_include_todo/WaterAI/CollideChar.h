#ifndef _WATERAI_COLLIDECHAR_H
#define _WATERAI_COLLIDECHAR_H

/**
 * .obj __vt__Q27WaterAI11CollideChar, global
 * .4byte __RTTI__Q27WaterAI11CollideChar
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte satisfy__Q27WaterAI11CollideCharFP10AICreature
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

namespace WaterAI {
/**
 * @brief TODO
 */
struct CollideChar : public ANode, public CoreNode {
	virtual void satisfy(AICreature*); // _10
};
} // namespace WaterAI

#endif
