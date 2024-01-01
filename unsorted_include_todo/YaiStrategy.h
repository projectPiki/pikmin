#ifndef _YAISTRATEGY_H
#define _YAISTRATEGY_H

/**
 * .obj __vt__11YaiStrategy, global
 * .4byte __RTTI__11YaiStrategy
 * .4byte 0
 * .4byte start__11YaiStrategyFR4Teki
 * .4byte act__11YaiStrategyFR4Teki
 * .4byte eventPerformed__11YaiStrategyFR9TekiEvent
 * .4byte createEffect__12TekiStrategyFR4Tekii
 * .4byte draw__11YaiStrategyFR4TekiR8Graphics
 * .4byte drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
 * .4byte interact__12TekiStrategyFR4TekiR18TekiInteractionKey
 * .4byte spawnCorpseParts__12TekiStrategyFR4Teki
*/

struct TekiStrategy {
	virtual void start(Teki &);                           // _08
	virtual void act(Teki &);                             // _0C
	virtual void eventPerformed(TekiEvent &);             // _10
	virtual void createEffect(Teki &, int);               // _14
	virtual void draw(Teki &, Graphics &);                // _18
	virtual void drawDebugInfo(Teki &, Graphics &);       // _1C
	virtual void interact(Teki &, TekiInteractionKey &);  // _20
	virtual void spawnCorpseParts(Teki &);                // _24
};

/**
 * @brief TODO
 */
struct YaiStrategy : public TekiStrategy {
	virtual void start(Teki &);                // _08
	virtual void act(Teki &);                  // _0C
	virtual void eventPerformed(TekiEvent &);  // _10
	virtual void draw(Teki &, Graphics &);     // _18

};

#endif
