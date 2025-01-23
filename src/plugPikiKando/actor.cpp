#include "Actor.h"
#include "Piki.h"
#include "SimpleAI.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
Actor::Actor()
    : AICreature(nullptr)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119A10
 * Size:	0000A4
 */
void Actor::setType(int, PikiShapeObject* shape, CreatureProp* props, SimpleAI* ai)
{
	mProps               = props;
	mPikiShape           = shape;
	mPikiShape->mAnimMgr = PikiShapeObject::getAnimMgr();
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, actorMgr->mMotionTable);

	mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Wait, nullptr), PaniMotionInfo(PIKIANIM_Wait));

	mStateMachine = ai;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Actor::startAI(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void Actor::refresh(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Actor::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Actor::doAnimation()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Actor::doAI()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Actor::doKill()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void Actor::startMotion(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Actor::startMotion(int, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Actor::finishMotion()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void Actor::finishMotion(f32)
{
	// UNUSED FUNCTION
}
