#ifndef _INTERACTGEYZER_H
#define _INTERACTGEYZER_H

/**
 * .obj __vt__14InteractGeyzer, global
 * .4byte __RTTI__14InteractGeyzer
 * .4byte 0
 * .4byte actCommon__11InteractionFP8Creature
 * .4byte actPiki__11InteractionFP4Piki
 * .4byte actTeki__11InteractionFP4Teki
 * .4byte actNavi__14InteractGeyzerFP4Navi
 * .4byte actBoss__11InteractionFP4Boss
 * .4byte actPellet__11InteractionFP6Pellet
 * .4byte actHinderRock__11InteractionFP10HinderRock
 * .4byte actBridge__11InteractionFP6Bridge
 * .4byte actItem__11InteractionFP12ItemCreature
 */

struct Interaction {
	virtual void actCommon(Creature*);       // _08
	virtual void actPiki(Piki*);             // _0C
	virtual void actTeki(Teki*);             // _10
	virtual void actNavi(Navi*);             // _14
	virtual void actBoss(Boss*);             // _18
	virtual void actPellet(Pellet*);         // _1C
	virtual void actHinderRock(HinderRock*); // _20
	virtual void actBridge(Bridge*);         // _24
	virtual void actItem(ItemCreature*);     // _28
};

/**
 * @brief TODO
 */
struct InteractGeyzer : public Interaction {
	virtual void actNavi(Navi*); // _14
};

#endif
