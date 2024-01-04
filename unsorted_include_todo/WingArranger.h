#ifndef _WINGARRANGER_H
#define _WINGARRANGER_H

/**
 * .obj __vt__12WingArranger, global
 * .4byte __RTTI__12WingArranger
 * .4byte 0
 * .4byte arrange__12WingArrangerFP12FormationMgr
 * .4byte getLength__12FormArrangerFP12FormationMgr
 */

struct FormArranger {
	virtual void arrange(FormationMgr*);   // _08
	virtual void getLength(FormationMgr*); // _0C
};

/**
 * @brief TODO
 */
struct WingArranger : public FormArranger {
	virtual void arrange(FormationMgr*); // _08
};

#endif
