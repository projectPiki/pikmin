#ifndef _LINEARRANGER_H
#define _LINEARRANGER_H

/**
 * .obj __vt__12LineArranger, global
 * .4byte __RTTI__12LineArranger
 * .4byte 0
 * .4byte arrange__12LineArrangerFP12FormationMgr
 * .4byte getLength__12FormArrangerFP12FormationMgr
*/

struct FormArranger {
	virtual void arrange(FormationMgr *);    // _08
	virtual void getLength(FormationMgr *);  // _0C
};

/**
 * @brief TODO
 */
struct LineArranger : public FormArranger {
	virtual void arrange(FormationMgr *);  // _08

};

#endif
