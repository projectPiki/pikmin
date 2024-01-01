#ifndef _TAIIWAGENSTRATEGY_H
#define _TAIIWAGENSTRATEGY_H

/**
 * .obj __vt__17TaiIwagenStrategy, global
 * .4byte __RTTI__17TaiIwagenStrategy
 * .4byte 0
 * .4byte start__17TaiIwagenStrategyFR4Teki
 * .4byte act__11TaiStrategyFR4Teki
 * .4byte eventPerformed__11TaiStrategyFR9TekiEvent
 * .4byte createEffect__12TekiStrategyFR4Tekii
 * .4byte draw__17TaiIwagenStrategyFR4TekiR8Graphics
 * .4byte drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
 * .4byte interact__12TekiStrategyFR4TekiR18TekiInteractionKey
 * .4byte spawnCorpseParts__12TekiStrategyFR4Teki
*/

struct TaiStrategy {
	virtual void start(Teki &);                // _08
	virtual void act(Teki &);                  // _0C
	virtual void eventPerformed(TekiEvent &);  // _10
};

struct TekiStrategy {
	virtual void start(Teki &);                           // _08
	virtual void _0C() = 0;                               // _0C
	virtual void _10() = 0;                               // _10
	virtual void createEffect(Teki &, int);               // _14
	virtual void draw(Teki &, Graphics &);                // _18
	virtual void drawDebugInfo(Teki &, Graphics &);       // _1C
	virtual void interact(Teki &, TekiInteractionKey &);  // _20
	virtual void spawnCorpseParts(Teki &);                // _24
};

/**
 * @brief TODO
 */
struct TaiIwagenStrategy : public TaiStrategy, public TekiStrategy {
	virtual void start(Teki &);             // _08
	virtual void draw(Teki &, Graphics &);  // _18

};

#endif
