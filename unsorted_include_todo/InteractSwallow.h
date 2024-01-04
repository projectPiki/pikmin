#ifndef _INTERACTSWALLOW_H
#define _INTERACTSWALLOW_H

/**
 * .obj __vt__15InteractSwallow, global
 * .4byte __RTTI__15InteractSwallow
 * .4byte 0
 * .4byte actCommon__15InteractSwallowFP8Creature
 * .4byte actPiki__15InteractSwallowFP4Piki
 * .4byte actTeki__15InteractSwallowFP4Teki
 * .4byte actNavi__15InteractSwallowFP4Navi
 * .4byte actBoss__11InteractionFP4Boss
 * .4byte actPellet__15InteractSwallowFP6Pellet
 * .4byte actHinderRock__11InteractionFP10HinderRock
 * .4byte actBridge__11InteractionFP6Bridge
 * .4byte actItem__15InteractSwallowFP12ItemCreature
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
};

/**
 * @brief TODO
 */
struct InteractSwallow : public Interaction {
	virtual void actCommon(Creature*);   // _08
	virtual void actPiki(Piki*);         // _0C
	virtual void actTeki(Teki*);         // _10
	virtual void actNavi(Navi*);         // _14
	virtual void actPellet(Pellet*);     // _1C
	virtual void actItem(ItemCreature*); // _28
};

#endif
