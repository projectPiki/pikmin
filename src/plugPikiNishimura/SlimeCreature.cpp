#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Slime.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("SlimeCreature");

/**
 * @TODO: Documentation
 */
SlimeCreature::SlimeCreature(CreatureProp* props)
    : Creature(props)
{
	mSearchBuffer.init(mSearchData, 3);
}

/**
 * @TODO: Documentation
 */
void SlimeCreature::init(immut Vector3f& pos, Slime* slime)
{
	mSlime           = slime;
	mCollisionRadius = 20.0f;
	mSRT.t           = pos;
	mTargetPosition  = pos;
	Creature::init();
	startFlying();
}

/**
 * @TODO: Documentation
 */
f32 SlimeCreature::getSize()
{
	return 20.0f;
}

/**
 * @TODO: Documentation
 */
f32 SlimeCreature::getiMass()
{
	return 0.01f;
}

/**
 * @TODO: Documentation
 */
Vector3f SlimeCreature::getCentre()
{
	return mSRT.t;
}

/**
 * @TODO: Documentation
 */
void SlimeCreature::doKill()
{
	kill(false);
}

/**
 * @TODO: Documentation
 */
bool SlimeCreature::isAlive()
{
	return mSlime->isAlive();
}

/**
 * @TODO: Documentation
 */
bool SlimeCreature::isAtari()
{
	return mSlime->isAtari();
}

/**
 * @TODO: Documentation
 */
bool SlimeCreature::ignoreAtari(Creature* creature)
{
	if (creature->mObjType == mObjType) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void SlimeCreature::doAI()
{
}

/**
 * @TODO: Documentation
 */
void SlimeCreature::doAnimation()
{
}

/**
 * @TODO: Documentation
 */
void SlimeCreature::update()
{
	mSRT.t.y -= 0.5f;
	moveVelocity();
	moveNew(gsys->getFrameTime());
}

/**
 * @TODO: Documentation
 */
void SlimeCreature::refresh(Graphics&)
{
}
