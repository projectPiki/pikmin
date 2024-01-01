#ifndef _INTERACTKILL_H
#define _INTERACTKILL_H

/**
 * .obj __vt__12InteractKill, global
 * .4byte __RTTI__12InteractKill
 * .4byte 0
 * .4byte actCommon__11InteractionFP8Creature
 * .4byte actPiki__12InteractKillFP4Piki
 * .4byte actTeki__11InteractionFP4Teki
 * .4byte actNavi__12InteractKillFP4Navi
 * .4byte actBoss__11InteractionFP4Boss
 * .4byte actPellet__12InteractKillFP6Pellet
 * .4byte actHinderRock__11InteractionFP10HinderRock
 * .4byte actBridge__11InteractionFP6Bridge
 * .4byte actItem__11InteractionFP12ItemCreature
*/

struct Interaction {
	virtual void actCommon(Creature *);        // _08
	virtual void actPiki(Piki *);              // _0C
	virtual void actTeki(Teki *);              // _10
	virtual void actNavi(Navi *);              // _14
	virtual void actBoss(Boss *);              // _18
	virtual void actPellet(Pellet *);          // _1C
	virtual void actHinderRock(HinderRock *);  // _20
	virtual void actBridge(Bridge *);          // _24
	virtual void actItem(ItemCreature *);      // _28
};

/**
 * @brief TODO
 */
struct InteractKill : public Interaction {
	virtual void actPiki(Piki *);      // _0C
	virtual void actNavi(Navi *);      // _14
	virtual void actPellet(Pellet *);  // _1C

};

#endif
