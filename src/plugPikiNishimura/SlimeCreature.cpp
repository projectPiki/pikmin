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

SlimeCreature::SlimeCreature(CreatureProp* props)
    : Creature(props)
{
	mSearchBuffer.init(mSearchData, 3);
}

void SlimeCreature::init(immut Vector3f& pos, Slime* slime)
{
	mSlime           = slime;
	mCollisionRadius = 20.0f;
	mSRT.t           = pos;
	mTargetPosition  = pos;
	Creature::init();
	startFlying();
}

f32 SlimeCreature::getSize()
{
	return 20.0f;
}

f32 SlimeCreature::getiMass()
{
	return 0.01f;
}

Vector3f SlimeCreature::getCentre()
{
	return mSRT.t;
}

void SlimeCreature::doKill()
{
	kill(false);
}

bool SlimeCreature::isAlive()
{
	return mSlime->isAlive();
}

bool SlimeCreature::isAtari()
{
	return mSlime->isAtari();
}

bool SlimeCreature::ignoreAtari(Creature* creature)
{
	if (creature->mObjType == mObjType) {
		return true;
	}

	return false;
}

void SlimeCreature::doAI()
{
}

void SlimeCreature::doAnimation()
{
}

void SlimeCreature::update()
{
	mSRT.t.y -= 0.5f;
	moveVelocity();
	moveNew(gsys->getFrameTime());
}

void SlimeCreature::refresh(Graphics&)
{
}
