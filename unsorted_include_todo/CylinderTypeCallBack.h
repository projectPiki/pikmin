#ifndef _CYLINDERTYPECALLBACK_H
#define _CYLINDERTYPECALLBACK_H

/**
 * .obj __vt__20CylinderTypeCallBack, global
 * .4byte __RTTI__20CylinderTypeCallBack
 * .4byte 0
 * .4byte invoke__20CylinderTypeCallBackFPQ23zen17particleGenerator
 */

/**
 * @brief TODO
 */
struct CylinderTypeCallBack {
	virtual void invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, float, float, float, float, TAIeffectAttackEventCallBack*);
	void hitCheckCommon(zen::particleGenerator*, Creature*);
};

#endif
