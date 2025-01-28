#include "PikiAI.h"
#include "zen/Math.h"
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
 * Address:	800BAF68
 * Size:	00004C
 */
ActGoto::ActGoto(Piki* piki)
    : Action(piki, true)
{
	_1C.clear();
}

/*
 * --INFO--
 * Address:	800BAFB4
 * Size:	00007C
 */
void ActGoto::Initialiser::initialise(Action* action)
{
	ActGoto* ai = static_cast<ActGoto*>(action);
	ai->_14     = _08;
	ai->_18     = _0C;
	if (_04) {
		ai->_1C.set(_04);
	}
}

/*
 * --INFO--
 * Address:	800BB030
 * Size:	0000D4
 */
void ActGoto::init(Creature* target)
{
	_20 = randFloat(2.0f) + 4.0f;
	_1C.set(target);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

/*
 * --INFO--
 * Address:	800BB104
 * Size:	000040
 */
void ActGoto::cleanup()
{
	Creature* target = _1C.getPtr();
	_1C.reset();
}

/*
 * --INFO--
 * Address:	800BB144
 * Size:	000378
 */
int ActGoto::exec()
{
	Creature* target = _1C.getPtr();
	if (!target || !target->isVisible()) {
		return ACTOUT_Fail;
	}

	_20 -= gsys->getFrameTime();

	f32 dist       = qdist2(target, mPiki);
	f32 heightDiff = zen::Abs(target->mPosition.y - mPiki->mPosition.y);
	if (dist >= _18 && dist <= _14 + mPiki->getCentreSize() + target->getCentreSize()) {
		if (heightDiff > 20.0f) {
			return ACTOUT_Fail;
		}
		return ACTOUT_Success;
	}

	if (_20 < 0.0f) {
		PRINT("time out\n");
		return ACTOUT_Fail;
	}

	Vector3f targetPos(target->mPosition);
	Vector3f dir = mPiki->mPosition - targetPos;
	dir.normalise();
	dir       = dir * _18;
	targetPos = targetPos + dir;
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	Vector3f dir2 = targetPos - mPiki->mPosition;
	dir2.y        = 0.0f;
	f32 dist2     = dir2.length();
	if (dist2 > 0.0f) {
		dir2 = (1.0f / dist2) * dir2;
	} else {
		f32 angle = 2.0f * randFloat(PI);
		dir2.set(cosf(angle), 0.0f, sinf(angle));
	}

	Vector3f vec1(0.0f, 0.0f, 0.0f);
	Vector3f vec2 = targetPos - mPiki->mPosition;
	vec2.normalise();
	Vector3f vec3(-vec2.z, 0.0f, vec2.x);
	bool unused = false;
	mPiki->setSpeed(1.0f, dir2);
	f32 factor = 1.0f;
	if (unused) {
		mPiki->mTargetVelocity = (1.0f - factor) * mPiki->mTargetVelocity + factor * vec1;
	}

	return ACTOUT_Continue;
}
