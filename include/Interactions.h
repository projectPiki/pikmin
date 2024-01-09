#ifndef _INTERACTION_H
#define _INTERACTION_H

#include "types.h"

struct Boss;
struct Bridge;
struct Creature;
struct HinderRock;
struct ItemCreature;
struct Navi;
struct Pellet;
struct Piki;
struct Teki;

/**
 * @brief TODO
 */
struct Interaction {
	inline Interaction(Creature* owner)
	    : mOwner(owner)
	{
	}

	virtual bool actCommon(Creature*) { return true; }       // _08
	virtual bool actPiki(Piki*) { return true; }             // _0C
	virtual bool actTeki(Teki*) { return true; }             // _10
	virtual bool actNavi(Navi*) { return true; }             // _14
	virtual bool actBoss(Boss*) { return true; }             // _18
	virtual bool actPellet(Pellet*) { return true; }         // _1C
	virtual bool actHinderRock(HinderRock*) { return true; } // _20
	virtual bool actBridge(Bridge*) { return true; }         // _24
	virtual bool actItem(ItemCreature*) { return true; }     // _28

	// _00 = VTBL
	Creature* mOwner; // _04, creature causing the interaction
};

/**
 * @brief TODO
 */
struct InteractAttack : public Interaction {
	inline InteractAttack(); // TODO: probably

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actBoss(Boss*);         // _18
	virtual bool actItem(ItemCreature*); // _28

	void getDamagePortion();

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractBikkuri : public Interaction {
	inline InteractBikkuri(); // TODO: probably

	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractBomb : public Interaction {
	inline InteractBomb(); // TODO: probably

	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actBoss(Boss*);         // _18
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractBreak : public Interaction {
	inline InteractBreak(); // TODO: probably

	virtual bool actBridge(Bridge*); // _24

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractBubble : public Interaction {
	inline InteractBubble(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C
	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractBuild : public Interaction {
	inline InteractBuild(); // TODO: probably

	virtual bool actBridge(Bridge*);     // _24
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractBury : public Interaction {
	inline InteractBury(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C
	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractChangeColor : public Interaction {
	inline InteractChangeColor(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
	int mColor; // _08, color to change to
};

/**
 * @brief TODO
 */
struct InteractChangeHappa : public Interaction {
	inline InteractChangeHappa(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
	int mHappa; // _08, flower stage to change to
};

/**
 * @brief TODO
 */
struct InteractFire : public Interaction {
	inline InteractFire(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C
	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractFlick : public Interaction {
	inline InteractFlick(); // TODO: probably

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actBoss(Boss*);         // _18
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractFlute : public Interaction {
	inline InteractFlute(); // TODO: probably

	virtual bool actTeki(Teki*); // _10

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractGeyzer : public Interaction {
	inline InteractGeyzer(); // TODO: probably

	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractGrab : public Interaction {
	inline InteractGrab(); // TODO: probably

	virtual bool actCommon(Creature*); // _08

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractHitEffect : public Interaction {
	inline InteractHitEffect(); // TODO: probably

	virtual bool actTeki(Teki*); // _10
	virtual bool actBoss(Boss*); // _18

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractKill : public Interaction {
	inline InteractKill(); // TODO: probably

	virtual bool actPiki(Piki*);     // _0C
	virtual bool actNavi(Navi*);     // _14
	virtual bool actPellet(Pellet*); // _1C

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractPress : public Interaction {
	inline InteractPress(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C
	virtual bool actTeki(Teki*); // _10
	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractPullout : public Interaction {
	inline InteractPullout(); // TODO: probably

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractPush : public Interaction {
	inline InteractPush(); // TODO: probably

	virtual bool actHinderRock(HinderRock*); // _20

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractRelease : public Interaction {
	inline InteractRelease(); // TODO: probably

	virtual bool actCommon(Creature*); // _08

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractSlimeAttack : public Interaction {
	inline InteractSlimeAttack(); // TODO: probably

	virtual bool actCommon(Creature*); // _08

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractSpore : public Interaction {
	inline InteractSpore(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractSuck : public Interaction {
	inline InteractSuck(); // TODO: probably

	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractSwallow : public Interaction {
	inline InteractSwallow(); // TODO: probably

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actPellet(Pellet*);     // _1C
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractTalk : public Interaction {
	inline InteractTalk(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractThrowAway : public Interaction {
	inline InteractThrowAway(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractWarn : public Interaction {
	inline InteractWarn(); // TODO: probably

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractWind : public Interaction {
	inline InteractWind(); // TODO: probably

	virtual bool actCommon(Creature*); // _08
	virtual bool actPiki(Piki*);       // _0C
	virtual bool actNavi(Navi*);       // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

#endif
