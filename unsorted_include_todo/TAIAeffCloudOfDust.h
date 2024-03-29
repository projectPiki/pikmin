#ifndef _TAIAEFFCLOUDOFDUST_H
#define _TAIAEFFCLOUDOFDUST_H

/**
 * .obj __vt__18TAIAeffCloudOfDust, global
 * .4byte __RTTI__18TAIAeffCloudOfDust
 * .4byte 0
 * .4byte start__18TAIAeffCloudOfDustFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__18TAIAeffCloudOfDustFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte setType__18TAIAeffCloudOfDustFR8Vector3fii
 */

struct TaiAction {
	virtual void start(Teki&);           // _08
	virtual void finish(Teki&);          // _0C
	virtual void act(Teki&);             // _10
	virtual void actByEvent(TekiEvent&); // _14
	virtual void hasNextState();         // _18
};

/**
 * @brief TODO
 */
struct TAIAeffCloudOfDust : public TaiAction {
	virtual void start(Teki&);                 // _08
	virtual void act(Teki&);                   // _10
	virtual void setType(Vector3f&, int, int); // _1C

	void init(EffectMgr::effTypeTable, bool, int, int, float, int, int, int, int, int);
	void createCloudOfDust(Teki&, int);
	void getCollPart(Teki&, int);
};

#endif
