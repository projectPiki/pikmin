#ifndef _TAIACHECKINSIDERANGEPIKI_H
#define _TAIACHECKINSIDERANGEPIKI_H

/**
 * .obj __vt__24TAIAcheckInsideRangePiki, global
 * .4byte __RTTI__24TAIAcheckInsideRangePiki
 * .4byte 0
 * .4byte start__9TaiActionFR4Teki
 * .4byte finish__9TaiActionFR4Teki
 * .4byte act__24TAIAcheckInsideRangePikiFR4Teki
 * .4byte actByEvent__9TaiActionFR9TekiEvent
 * .4byte hasNextState__9TaiActionFv
 * .4byte getPikiMax__24TAIAcheckInsideRangePikiFR4Teki
 * .4byte getRange__24TAIAcheckInsideRangePikiFR4Teki
*/

struct TaiAction {
	virtual void start(Teki &);            // _08
	virtual void finish(Teki &);           // _0C
	virtual void act(Teki &);              // _10
	virtual void actByEvent(TekiEvent &);  // _14
	virtual void hasNextState();           // _18
};

/**
 * @brief TODO
 */
struct TAIAcheckInsideRangePiki : public TaiAction {
	virtual void act(Teki &);         // _10
	virtual void getPikiMax(Teki &);  // _1C
	virtual void getRange(Teki &);    // _20

};

#endif
