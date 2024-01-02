#ifndef _INTERACTATTACK_H
#define _INTERACTATTACK_H

/**
 * .obj __vt__14InteractAttack, global
 * .4byte __RTTI__14InteractAttack
 * .4byte 0
 * .4byte actCommon__14InteractAttackFP8Creature
 * .4byte actPiki__14InteractAttackFP4Piki
 * .4byte actTeki__14InteractAttackFP4Teki
 * .4byte actNavi__14InteractAttackFP4Navi
 * .4byte actBoss__14InteractAttackFP4Boss
 * .4byte actPellet__11InteractionFP6Pellet
 * .4byte actHinderRock__11InteractionFP10HinderRock
 * .4byte actBridge__11InteractionFP6Bridge
 * .4byte actItem__14InteractAttackFP12ItemCreature
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
struct InteractAttack : public Interaction {
	virtual void actCommon(Creature *);    // _08
	virtual void actPiki(Piki *);          // _0C
	virtual void actTeki(Teki *);          // _10
	virtual void actNavi(Navi *);          // _14
	virtual void actBoss(Boss *);          // _18
	virtual void actItem(ItemCreature *);  // _28

};

#endif
