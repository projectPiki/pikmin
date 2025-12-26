#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Slime.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("SlimeCreature");

/**
 * @todo: Documentation
 */
SlimeCreature::SlimeCreature(CreatureProp* props)
    : Creature(props)
{
	mSearchBuffer.init(mSearchData, 3);
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
f32 SlimeCreature::getSize()
{
	return 20.0f;
}

/**
 * @todo: Documentation
 */
f32 SlimeCreature::getiMass()
{
	return 0.01f;
}

/**
 * @todo: Documentation
 */
Vector3f SlimeCreature::getCentre()
{
	return mSRT.t;
}

/**
 * @todo: Documentation
 */
void SlimeCreature::doKill()
{
	kill(false);
}

/**
 * @todo: Documentation
 */
bool SlimeCreature::isAlive()
{
	return mSlime->isAlive();
}

/**
 * @todo: Documentation
 */
bool SlimeCreature::isAtari()
{
	return mSlime->isAtari();
}

/**
 * @todo: Documentation
 */
bool SlimeCreature::ignoreAtari(Creature* creature)
{
	if (creature->mObjType == mObjType) {
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void SlimeCreature::doAI()
{
}

/**
 * @todo: Documentation
 */
void SlimeCreature::doAnimation()
{
}

/**
 * @todo: Documentation
 */
void SlimeCreature::update()
{
	mSRT.t.y -= 0.5f;
	moveVelocity();
	moveNew(gsys->getFrameTime());
}

/**
 * @todo: Documentation
 */
void SlimeCreature::refresh(Graphics&)
{
}
