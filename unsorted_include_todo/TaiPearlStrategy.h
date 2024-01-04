#ifndef _TAIPEARLSTRATEGY_H
#define _TAIPEARLSTRATEGY_H

/**
 * .obj __vt__16TaiPearlStrategy, global
 * .4byte __RTTI__16TaiPearlStrategy
 * .4byte 0
 * .4byte start__16TaiPearlStrategyFR4Teki
 * .4byte act__11TaiStrategyFR4Teki
 * .4byte eventPerformed__11TaiStrategyFR9TekiEvent
 * .4byte createEffect__12TekiStrategyFR4Tekii
 * .4byte draw__12TekiStrategyFR4TekiR8Graphics
 * .4byte drawDebugInfo__12TekiStrategyFR4TekiR8Graphics
 * .4byte interact__12TekiStrategyFR4TekiR18TekiInteractionKey
 * .4byte spawnCorpseParts__12TekiStrategyFR4Teki
 */

struct TaiStrategy {
	virtual void start(Teki&);               // _08
	virtual void act(Teki&);                 // _0C
	virtual void eventPerformed(TekiEvent&); // _10
};

struct TekiStrategy {
	virtual void start(Teki&);                         // _08
	virtual void _0C() = 0;                            // _0C
	virtual void _10() = 0;                            // _10
	virtual void createEffect(Teki&, int);             // _14
	virtual void draw(Teki&, Graphics&);               // _18
	virtual void drawDebugInfo(Teki&, Graphics&);      // _1C
	virtual void interact(Teki&, TekiInteractionKey&); // _20
	virtual void spawnCorpseParts(Teki&);              // _24
};

/**
 * @brief TODO
 */
struct TaiPearlStrategy : public TaiStrategy, public TekiStrategy {
	virtual void start(Teki&); // _08
};

#endif
