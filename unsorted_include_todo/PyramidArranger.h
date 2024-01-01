#ifndef _PYRAMIDARRANGER_H
#define _PYRAMIDARRANGER_H

/**
 * .obj __vt__15PyramidArranger, global
 * .4byte __RTTI__15PyramidArranger
 * .4byte 0
 * .4byte arrange__15PyramidArrangerFP12FormationMgr
 * .4byte getLength__15PyramidArrangerFP12FormationMgr
*/

/**
 * @brief TODO
 */
struct PyramidArranger {
	virtual void arrange(FormationMgr *);    // _08
	virtual void getLength(FormationMgr *);  // _0C

};

#endif
