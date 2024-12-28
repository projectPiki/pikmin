#include "Slime.h"
#include "Dolphin/os.h"
#include "system.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("SlimeCreature");

/*
 * --INFO--
 * Address:	8016B278
 * Size:	000078
 */
SlimeCreature::SlimeCreature(CreatureProp* props)
    : Creature(props)
{
	mSearchBuffer.init(mSearchData, 3);
}

/*
 * --INFO--
 * Address:	8016B2F0
 * Size:	000080
 */
void SlimeCreature::init(Vector3f& pos, Slime* slime)
{
	mSlime           = slime;
	mCollisionRadius = 20.0f;
	mPosition        = pos;
	_2BC             = pos;
	Creature::init();
	setFlag40UnsetFlag2();
}

/*
 * --INFO--
 * Address:	8016B370
 * Size:	000008
 */
f32 SlimeCreature::getSize() { return 20.0f; }

/*
 * --INFO--
 * Address:	8016B378
 * Size:	000008
 */
f32 SlimeCreature::getiMass() { return 0.01f; }

/*
 * --INFO--
 * Address:	8016B380
 * Size:	00001C
 */
Vector3f SlimeCreature::getCentre() { return mPosition; }

/*
 * --INFO--
 * Address:	8016B39C
 * Size:	000024
 */
void SlimeCreature::doKill() { kill(false); }

/*
 * --INFO--
 * Address:	8016B3C0
 * Size:	000030
 */
bool SlimeCreature::isAlive() { return mSlime->isAlive(); }

/*
 * --INFO--
 * Address:	8016B3F0
 * Size:	000030
 */
bool SlimeCreature::isAtari() { return mSlime->isAtari(); }

/*
 * --INFO--
 * Address:	8016B420
 * Size:	000020
 */
bool SlimeCreature::ignoreAtari(Creature* creature)
{
	if (creature->mObjType == mObjType) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8016B440
 * Size:	000004
 */
void SlimeCreature::doAI() { }

/*
 * --INFO--
 * Address:	8016B444
 * Size:	000004
 */
void SlimeCreature::doAnimation() { }

/*
 * --INFO--
 * Address:	8016B448
 * Size:	00004C
 */
void SlimeCreature::update()
{
	mPosition.y -= 0.5f;
	moveVelocity();
	moveNew(gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	8016B494
 * Size:	000004
 */
void SlimeCreature::refresh(Graphics&) { }
