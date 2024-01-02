#ifndef _INTERACTBUBBLE_H
#define _INTERACTBUBBLE_H

/**
 * .obj __vt__14InteractBubble, global
 * .4byte __RTTI__14InteractBubble
 * .4byte 0
 * .4byte actCommon__11InteractionFP8Creature
 * .4byte actPiki__14InteractBubbleFP4Piki
 * .4byte actTeki__11InteractionFP4Teki
 * .4byte actNavi__14InteractBubbleFP4Navi
 * .4byte actBoss__11InteractionFP4Boss
 * .4byte actPellet__11InteractionFP6Pellet
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
struct InteractBubble : public Interaction {
	virtual void actPiki(Piki *);  // _0C
	virtual void actNavi(Navi *);  // _14

};

#endif