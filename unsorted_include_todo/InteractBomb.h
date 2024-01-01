#ifndef _INTERACTBOMB_H
#define _INTERACTBOMB_H

/**
 * .obj __vt__12InteractBomb, global
 * .4byte __RTTI__12InteractBomb
 * .4byte 0
 * .4byte actCommon__11InteractionFP8Creature
 * .4byte actPiki__12InteractBombFP4Piki
 * .4byte actTeki__12InteractBombFP4Teki
 * .4byte actNavi__12InteractBombFP4Navi
 * .4byte actBoss__12InteractBombFP4Boss
 * .4byte actPellet__11InteractionFP6Pellet
 * .4byte actHinderRock__11InteractionFP10HinderRock
 * .4byte actBridge__11InteractionFP6Bridge
 * .4byte actItem__12InteractBombFP12ItemCreature
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
};

/**
 * @brief TODO
 */
struct InteractBomb : public Interaction {
	virtual void actPiki(Piki *);          // _0C
	virtual void actTeki(Teki *);          // _10
	virtual void actNavi(Navi *);          // _14
	virtual void actBoss(Boss *);          // _18
	virtual void actItem(ItemCreature *);  // _28

};

#endif
