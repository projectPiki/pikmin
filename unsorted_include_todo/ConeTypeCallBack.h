#ifndef _CONETYPECALLBACK_H
#define _CONETYPECALLBACK_H

/**
 * .obj __vt__16ConeTypeCallBack, global
 * .4byte __RTTI__16ConeTypeCallBack
 * .4byte 0
 * .4byte invoke__16ConeTypeCallBackFPQ23zen17particleGenerator
 */

/**
 * @brief TODO
 */
struct ConeTypeCallBack {
	virtual void invoke(zen::particleGenerator*); // _08

	void init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, float, float, float, float, TAIeffectAttackEventCallBack*);
	void hitCheckCommon(zen::particleGenerator*, Creature*);
};

#endif
