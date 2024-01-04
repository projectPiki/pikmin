#ifndef _CIRCLEARRANGER_H
#define _CIRCLEARRANGER_H

/**
 * .obj __vt__14CircleArranger, global
 * .4byte __RTTI__14CircleArranger
 * .4byte 0
 * .4byte arrange__14CircleArrangerFP12FormationMgr
 * .4byte getLength__12FormArrangerFP12FormationMgr
 */

struct FormArranger {
	virtual void arrange(FormationMgr*);   // _08
	virtual void getLength(FormationMgr*); // _0C
};

/**
 * @brief TODO
 */
struct CircleArranger : public FormArranger {
	virtual void arrange(FormationMgr*); // _08
};

#endif
