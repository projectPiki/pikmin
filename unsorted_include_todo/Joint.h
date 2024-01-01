#ifndef _JOINT_H
#define _JOINT_H

/**
 * .obj __vt__5Joint, global
 * .4byte __RTTI__5Joint
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__5JointFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

/**
 * @brief TODO
 */
struct Joint : public ANode {
	virtual void read(RandomAccessStream &);  // _0C

};

#endif
