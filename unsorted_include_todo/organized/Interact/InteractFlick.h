#ifndef _INTERACTFLICK_H
#define _INTERACTFLICK_H

/**
 * .obj __vt__13InteractFlick, global
 * .4byte __RTTI__13InteractFlick
 * .4byte 0
 * .4byte actCommon__13InteractFlickFP8Creature
 * .4byte actPiki__13InteractFlickFP4Piki
 * .4byte actTeki__13InteractFlickFP4Teki
 * .4byte actNavi__13InteractFlickFP4Navi
 * .4byte actBoss__13InteractFlickFP4Boss
 * .4byte actPellet__11InteractionFP6Pellet
 * .4byte actHinderRock__11InteractionFP10HinderRock
 * .4byte actBridge__11InteractionFP6Bridge
 * .4byte actItem__13InteractFlickFP12ItemCreature
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
struct InteractFlick : public Interaction {
	virtual void actCommon(Creature *);    // _08
	virtual void actPiki(Piki *);          // _0C
	virtual void actTeki(Teki *);          // _10
	virtual void actNavi(Navi *);          // _14
	virtual void actBoss(Boss *);          // _18
	virtual void actItem(ItemCreature *);  // _28

};

#endif
