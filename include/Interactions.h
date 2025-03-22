#ifndef _INTERACTIONS_H
#define _INTERACTIONS_H

#include "types.h"
#include "Vector.h"

// passing this as the flick angle = flick directly away from enemy
#define FLICK_BACKWARDS_ANGLE (-1000.0f)

// any angle below this will flick directly away from enemy
#define FLICK_BACKWARDS_THRESHOLD (-10.0f)

struct Boss;
struct Bridge;
struct Creature;
struct CollPart;
struct HinderRock;
struct ItemCreature;
struct Navi;
struct Pellet;
struct Piki;
struct Teki;

namespace zen {
struct particleGenerator;
}

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
	InteractAttack(Creature* owner, CollPart* collPart, f32 damage, bool p4)
	    : Interaction(owner)
	    , mDamage(damage)
	    , mCollPart(collPart)
	    , _10(p4)
	{
	}

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actBoss(Boss*);         // _18
	virtual bool actItem(ItemCreature*); // _28

	int getDamagePortion();

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 mDamage;         // _08
	CollPart* mCollPart; // _0C
	bool _10;            // _10
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
	inline InteractBomb(Creature* owner, f32 damage, CollPart* part)
	    : Interaction(owner)
	    , mDamage(damage)
	    , mCollPart(part)
	{
	}

	// need this to not be in order, otherwise vtable generates in interactBattle
	virtual bool actTeki(Teki*);         // _10
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actNavi(Navi*);         // _14
	virtual bool actBoss(Boss*);         // _18
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 mDamage;         // _08
	CollPart* mCollPart; // _0C
};

/**
 * @brief TODO
 */
struct InteractBreak : public Interaction {
	InteractBreak(Creature* owner, int stage, f32 p3)
	    : Interaction(owner)
	{
		mStageIndex = stage;
		_0C         = p3;
	}

	virtual bool actBridge(Bridge*); // _24

	// _00     = VTBL
	// _00-_08 = Interaction
	int mStageIndex; // _08
	f32 _0C;         // _0C
};

/**
 * @brief TODO
 */
struct InteractBubble : public Interaction {
	inline InteractBubble(Creature* owner, f32 damage)
	    : Interaction(owner)
	{
		mDamage = damage;
	}

	virtual bool actPiki(Piki*); // _0C
	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 mDamage; // _08
};

/**
 * @brief TODO
 */
struct InteractBuild : public Interaction {
	InteractBuild(Creature* owner, int stage, f32 rate)
	    : Interaction(owner)
	{
		mCurrentStage = stage;
		mProgressRate = rate;
	}

	virtual bool actBridge(Bridge*);     // _24
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	int mCurrentStage; // _0C
	f32 mProgressRate; // _10
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
	bool mMakeFlower; // _08, causes piki to be flowered
	f32 _0C;          // _0C
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
	f32 mDamage; // _08
};

/**
 * @brief TODO
 */
struct InteractFlick : public Interaction {
	inline InteractFlick(Creature* owner, f32 knockback, f32 damage, f32 angle)
	    : Interaction(owner)
	{
		mIntensity = knockback;
		mDamage    = damage;
		mAngle     = angle;
	}

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actBoss(Boss*);         // _18
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 mIntensity; // _08
	f32 mDamage;    // _0C
	f32 mAngle;     // _10
};

/**
 * @brief TODO
 */
struct InteractFlute : public Interaction {
	InteractFlute(Creature* owner)
	    : Interaction(owner)
	{
	}

	virtual bool actTeki(Teki*); // _10

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractGeyzer : public Interaction {
	inline InteractGeyzer(Creature* owner, Vector3f& p2)
	    : Interaction(owner)
	    , _08(p2)
	{
	}

	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	Vector3f _08; // _08
};

/**
 * @brief TODO
 */
struct InteractGrab : public Interaction {
	InteractGrab(Creature* owner)
	    : Interaction(owner)
	{
	}

	virtual bool actCommon(Creature*); // _08

	// _00     = VTBL
	// _00-_08 = Interaction
	// TODO: members
};

/**
 * @brief TODO
 */
struct InteractHitEffect : public Interaction {
	InteractHitEffect(Creature* owner, Vector3f& effPos, Vector3f& effDir, CollPart* part)
	    : Interaction(owner)
	    , mEffectPos(effPos)
	    , mEffectDir(effDir)
	    , mCollPart(part)
	{
	}

	virtual bool actTeki(Teki*); // _10
	virtual bool actBoss(Boss*); // _18

	// _00     = VTBL
	// _00-_08 = Interaction
	Vector3f mEffectPos; // _08
	Vector3f mEffectDir; // _14
	CollPart* mCollPart; // _20
};

/**
 * @brief TODO
 */
struct InteractKill : public Interaction {
	inline InteractKill(Creature* owner, int p2)
	    : Interaction(owner)
	{
		_08 = p2;
	}

	virtual bool actPiki(Piki*);     // _0C
	virtual bool actNavi(Navi*);     // _14
	virtual bool actPellet(Pellet*); // _1C

	// _00     = VTBL
	// _00-_08 = Interaction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct InteractPress : public Interaction {
	inline InteractPress(Creature* owner, f32 damage)
	    : Interaction(owner)
	{
		mDamage = damage;
	}

	virtual bool actPiki(Piki*); // _0C
	virtual bool actTeki(Teki*); // _10
	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 mDamage; // _08
};

/**
 * @brief TODO
 */
struct InteractPullout : public Interaction {
	InteractPullout(Creature* owner)
	    : Interaction(owner)
	{
	}

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
};

/**
 * @brief TODO
 */
struct InteractPush : public Interaction {
	InteractPush(Creature* owner, int p2)
	    : Interaction(owner)
	    , mStrength(p2)
	{
	}

	virtual bool actHinderRock(HinderRock*); // _20

	// _00     = VTBL
	// _00-_08 = Interaction
	int mStrength; // _08
};

/**
 * @brief TODO
 */
struct InteractRelease : public Interaction {
	InteractRelease(Creature* owner, f32 p2)
	    : Interaction(owner)
	{
		_08 = p2;
	}

	virtual bool actCommon(Creature*); // _08

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 _08; // _08
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
	InteractSuck(Creature* owner, f32 damage)
	    : Interaction(owner)
	    , mDamage(damage)
	{
	}

	virtual bool actNavi(Navi*); // _14

	// _00     = VTBL
	// _00-_08 = Interaction
	f32 mDamage; // _08
};

/**
 * @brief TODO
 */
struct InteractSwallow : public Interaction {
	inline InteractSwallow(Creature* owner, CollPart* mouthPart, int p3)
	    : Interaction(owner)
	{
		_08        = p3;
		mMouthPart = mouthPart;
	}

	virtual bool actCommon(Creature*);   // _08
	virtual bool actPiki(Piki*);         // _0C
	virtual bool actTeki(Teki*);         // _10
	virtual bool actNavi(Navi*);         // _14
	virtual bool actPellet(Pellet*);     // _1C
	virtual bool actItem(ItemCreature*); // _28

	// _00     = VTBL
	// _00-_08 = Interaction
	int _08;              // _08
	CollPart* mMouthPart; // _0C
};

/**
 * @brief TODO
 */
struct InteractTalk : public Interaction {
	inline InteractTalk(Creature* owner)
	    : Interaction(owner)
	{
	}

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
	InteractWarn(Creature* owner)
	    : Interaction(owner)
	{
	}

	virtual bool actPiki(Piki*); // _0C

	// _00     = VTBL
	// _00-_08 = Interaction
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
	u8 _08[0x4];                            // _08, unknown
	Vector3f mVelocity;                     // _0C
	zen::particleGenerator* mWindParticles; // _18
};

#endif
