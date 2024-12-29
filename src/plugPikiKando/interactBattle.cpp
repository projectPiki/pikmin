#include "Condition.h"
#include "Interactions.h"
#include "Piki.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "PikiMgr.h"
#include "MapCode.h"
#include "PikiAI.h"
#include "Collision.h"
#include "Stickers.h"
#include "Navi.h"
#include "BombItem.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "interactBattle"); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007B7C8
 * Size:	0001A0
 */
bool InteractBomb::actPiki(Piki* piki)
{
	// maybe the vector distance angle calc is a bigger inline? seems to work as-is though
	u32 badCompiler;
	u32 badCompiler2;
	u32 badCompiler3;

	if (!piki->isAlive()) {
		return false;
	}

	int state = piki->getState();
	if (state == PIKISTATE_Drown || state == PIKISTATE_Dead || state == PIKISTATE_Dying) {
		return false;
	}

	if (state == PIKISTATE_Flick) {
		return false;
	}

	if (!piki->isCreatureFlag(CF_Unk19) && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk27)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk27);
	}

	playerState->mResultFlags.setOn(RESFLAG_Unk24);

	piki->playEventSound(mOwner, 26);

	piki->mHealth -= mDamage;

	// update this when PikiProp is filled out
	piki->mLifeGauge.updValue(piki->mHealth, static_cast<PikiProp*>(piki->mProps)->mCreatureProps.mAcceleration());

	Vector3f diff = mOwner->mPosition - piki->mPosition;
	diff.normalise();
	piki->mRotationAngle = atan2f(diff.x, diff.z);
	piki->_498           = 180.0f;

	piki->mFSM->transit(piki, PIKISTATE_Flick);
	return true;
}

/*
 * --INFO--
 * Address:	8007B968
 * Size:	0000C0
 */
bool InteractBury::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	if (!piki->isSafeMePos(piki->mPosition) || MapCode::isBald(piki->mFloorTri)) {
		return false;
	}

	if (mMakeFlower && piki->mHappa < Flower) {
		piki->mHappa = Flower;
	}

	piki->mFSM->transit(piki, PIKISTATE_Bury);
	return true;
}

/*
 * --INFO--
 * Address:	8007BA28
 * Size:	00006C
 */
bool InteractThrowAway::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	piki->mFSM->transit(piki, PIKISTATE_FallMeck);
	return true;
}

/*
 * --INFO--
 * Address:	8007BA94
 * Size:	000080
 */
bool InteractChangeColor::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	piki->changeShape(mColor);
	piki->setColor(mColor);
	return true;
}

/*
 * --INFO--
 * Address:	8007BB18
 * Size:	000074
 */
bool InteractChangeHappa::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	piki->setFlower(mHappa);
	return true;
}

/*
 * --INFO--
 * Address:	8007BB90
 * Size:	000120
 */
bool InteractSpore::actPiki(Piki* piki)
{

	if (!piki->isAlive()) {
		return false;
	}

	// if not a puffmin, make a puffmin
	if (!piki->isKinoko()) {
		Creature* kinoko = mOwner;
		if (piki->_2AC) {
			InteractRelease release(piki, 1.0f);
			piki->_2AC->stimulate(release);
		}

		piki->_4A8 = kinoko;
		piki->_4F8->abandon(nullptr);
		piki->_4F8->mChildActionIdx = 22;
		piki->_4F8->initialiseChildAction(kinoko);
		piki->mFSM->transit(piki, PIKISTATE_KinokoChange);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8007BCB0
 * Size:	0000B4
 */
bool InteractBubble::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	int state = piki->getState();

	if (state == PIKISTATE_Dying || state == PIKISTATE_Dead || state == PIKISTATE_Bubble) {
		return false;
	}

	// blue pikmin are immune to bubble
	if (piki->mColor != Blue) {
		piki->changeMode(0, piki->mNavi);
		piki->mFSM->transit(piki, PIKISTATE_Bubble);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8007BD64
 * Size:	00007C
 */
bool InteractFire::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	// red pikmin are immune to fire
	if (piki->mColor != Red) {
		piki->startFire();
		return true;
	}

	playerState->mResultFlags.setOn(RESFLAG_Unk39);
	return false;
}

/*
 * --INFO--
 * Address:	8007BDE0
 * Size:	000008
 */
bool InteractWind::actCommon(Creature*) { return true; }

/*
 * --INFO--
 * Address:	8007BDE8
 * Size:	000108
 */
bool InteractWind::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	int state = piki->getState();
	if (state == PIKISTATE_Dying || state == PIKISTATE_Drown || state == PIKISTATE_Flown) {
		return false;
	}

	// can't get blown away if stuck to a creature
	if (piki->mStickTarget) {
		return false;
	}

	if ((int)piki->mMode == 11 || (int)piki->mMode == 12) {
		return false;
	}

	piki->_4F8->abandon(mWindParticles);
	piki->mFSM->transit(piki, PIKISTATE_Flown);

	piki->mVelocity       = _0C;
	piki->mTargetVelocity = _0C;

	return true;
}

/*
 * --INFO--
 * Address:	8007BEF0
 * Size:	00005C
 */
bool InteractFlick::actCommon(Creature* creature)
{
	u32 badCompiler;
	if (creature->isCreatureFlag(CF_StuckToMouth)) {
		creature->endStickMouth();
	}

	// if stuck to something, end stick
	if (creature->mStickTarget) {
		creature->endStickObject();
		creature->endStick();
	}

	return true;
}

/*
 * --INFO--
 * Address:	8007BF4C
 * Size:	0000EC
 */
bool InteractFlick::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	if (piki->getState() == PIKISTATE_Flick) {
		return false;
	}

	piki->playEventSound(mOwner, 26);

	piki->mHealth -= mDamage;

	// update this when PikiProp is filled out
	piki->mLifeGauge.updValue(piki->mHealth, static_cast<PikiProp*>(piki->mProps)->mCreatureProps.mAcceleration());

	if (mAngle < -10.0f) {
		piki->mRotationAngle = piki->mDirection;
	} else {
		piki->mRotationAngle = mAngle;
	}

	piki->_498 = mKnockback;
	piki->mFSM->transit(piki, PIKISTATE_Flick);
	return true;
}

/*
 * --INFO--
 * Address:	8007C038
 * Size:	000008
 */
bool InteractSlimeAttack::actCommon(Creature*) { return true; }

/*
 * --INFO--
 * Address:	8007C040
 * Size:	00018C
 */
int InteractAttack::getDamagePortion()
{
	if (mCollPart) {
		ID32& id = mCollPart->getCode();
		if (id.match('***0', '*')) {
			return 0;
		}

		if (id.match('***1', '*')) {
			return 1;
		}

		if (id.match('***2', '*')) {
			return 2;
		}

		if (id.match('***3', '*')) {
			return 3;
		}

		if (id.match('***4', '*')) {
			return 4;
		}

		if (id.match('***5', '*')) {
			return 5;
		}

		if (id.match('***6', '*')) {
			return 6;
		}

		if (id.match('***7', '*')) {
			return 7;
		}

		if (id.match('***8', '*')) {
			return 8;
		}

		if (id.match('***9', '*')) {
			return 9;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address:	8007C1CC
 * Size:	000044
 */
bool InteractAttack::actCommon(Creature* creature)
{
	if (!creature->isVisible()) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	8007C218
 * Size:	000188
 */
bool InteractAttack::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		return false;
	}

	int state = piki->getState();
	if (state == PIKISTATE_Dying || state == PIKISTATE_Dead) {
		return false;
	}

	if (state == PIKISTATE_Flick) {
		return false;
	}

	piki->playEventSound(mOwner, 26);
	piki->startDamage();
	piki->mHealth -= mDamage;

	// update this when PikiProp is filled out
	piki->mLifeGauge.updValue(piki->mHealth, static_cast<PikiProp*>(piki->mProps)->mCreatureProps.mAcceleration());

	if (state == PIKISTATE_Unk34) {
		piki->mFSM->transit(piki, PIKISTATE_Normal);
	}

	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (piki->mHealth <= 0.0f) {
		piki->finishDamage();
		piki->mFSM->transit(piki, PIKISTATE_Dying);
	} else {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Damage, piki), PaniMotionInfo(PIKIANIM_Damage));
	}
	return true;
}

/*
 * --INFO--
 * Address:	8007C3A0
 * Size:	000008
 */
bool InteractSwallow::actCommon(Creature*) { return true; }

/*
 * --INFO--
 * Address:	8007C3A8
 * Size:	0002F0
 */
bool InteractSwallow::actPiki(Piki* piki)
{
	piki->isAlive();
	piki->_4F8->abandon(nullptr);
	piki->_4F8->mChildActionIdx = 15;
	piki->_4F8->initialiseChildAction(nullptr);
	piki->mMode = 0;
	if (!mMouthPart) {
		piki->playEventSound(mOwner, 22);
		piki->kill(false);
		return true;
	}

	piki->mSwallowMouthPart = mMouthPart;

	piki->getState();

	if (_08 == 0) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Esa), PaniMotionInfo(PIKIANIM_Esa));
	} else {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Fall), PaniMotionInfo(PIKIANIM_Fall));
	}

	piki->mFSM->transit(piki, PIKISTATE_Swallowed);

	if (piki->mStickTarget && !piki->isCreatureFlag(CF_StuckToMouth)) {
		piki->endStickObject();
		piki->endStick();
	}

	piki->startStickMouth(mOwner, mMouthPart);

	if (!piki->isCreatureFlag(CF_StuckToMouth)) {
		piki->mSwallowMouthPart = nullptr;
		return false;
	}

	bool isPiki = false;
	Stickers stickers(mOwner);
	Stickers* stickPtr = &stickers;
	for (int i = stickPtr->getFirst(); !stickPtr->isEnd(i); i = stickPtr->getNext(i)) {
		Creature* stuck;

		// On invalid index, get the first creature
		if (i == -1) {
			stuck = stickPtr->getCreature(0);
		} else {
			stuck = stickPtr->getCreature(i);
		}

		if (stuck == piki) {
			isPiki = true;
		}

		if (stuck->isCreatureFlag(CF_StuckToMouth)) {
			stuck->isCreatureFlag(CF_StuckToMouth);
		}
	}

	if (!isPiki) {
		Creature* target = mOwner->_180;
		while (target) {
			target = target->_18C;
		}
	}

	piki->playEventSound(mOwner, 22);

	if (piki->_426) {
		piki->_426 = 0;
		// piki->_430->_30();
		piki->_424 = 0;
	}

	piki->_426 = 0;
	return true;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stmw      r27, 0x64(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4F8(r31)
	  li        r4, 0
	  bl        0x48F68
	  lwz       r3, 0x4F8(r31)
	  li        r0, 0xF
	  li        r4, 0
	  sth       r0, 0x8(r3)
	  lwz       r3, 0x4F8(r31)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        0x47920
	  li        r0, 0
	  sth       r0, 0x4FC(r31)
	  lwz       r0, 0xC(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lwz       r4, 0x4(r30)
	  addi      r3, r31, 0
	  li        r5, 0x16
	  bl        0xE18C
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0xE8AC
	  li        r3, 0x1
	  b         .loc_0x2DC

	.loc_0x98:
	  mr        r3, r31
	  stw       r0, 0x4A4(r31)
	  bl        0x4C10C
	  lwz       r0, 0x8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xE0
	  addi      r3, r1, 0x30
	  li        r4, 0x46
	  bl        0xA2AF8
	  addi      r29, r3, 0
	  addi      r3, r1, 0x38
	  li        r4, 0x46
	  bl        0xA2AE8
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        0x4E558
	  b         .loc_0x10C

	.loc_0xE0:
	  addi      r3, r1, 0x20
	  li        r4, 0x1D
	  bl        0xA2AC8
	  addi      r29, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x1D
	  bl        0xA2AB8
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  bl        0x4E528

	.loc_0x10C:
	  lwz       r3, 0x490(r31)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x150
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0x150
	  mr        r3, r31
	  bl        0x1438C
	  mr        r3, r31
	  bl        0x144E8

	.loc_0x150:
	  lwz       r4, 0x4(r30)
	  mr        r3, r31
	  lwz       r5, 0xC(r30)
	  bl        0x13A94
	  lwz       r0, 0xC8(r31)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0x17C
	  li        r0, 0
	  stw       r0, 0x4A4(r31)
	  li        r3, 0
	  b         .loc_0x2DC

	.loc_0x17C:
	  addi      r3, r1, 0x50
	  lwz       r4, 0x4(r30)
	  bl        0x14758
	  addi      r29, r1, 0x50
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x218

	.loc_0x1AC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x1D0
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1E8

	.loc_0x1D0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1E8:
	  cmplw     r3, r31
	  bne-      .loc_0x1F4
	  li        r27, 0x1

	.loc_0x1F4:
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,16,16
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x218:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x240
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x240:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x268:
	  li        r0, 0

	.loc_0x26C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1AC
	  rlwinm.   r0,r27,0,24,31
	  bne-      .loc_0x294
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x180(r3)
	  b         .loc_0x28C

	.loc_0x288:
	  lwz       r3, 0x18C(r3)

	.loc_0x28C:
	  cmplwi    r3, 0
	  bne+      .loc_0x288

	.loc_0x294:
	  lwz       r4, 0x4(r30)
	  addi      r3, r31, 0
	  li        r5, 0x16
	  bl        0xDF6C
	  lhz       r0, 0x426(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x2D0
	  li        r30, 0
	  sth       r30, 0x426(r31)
	  lwz       r3, 0x430(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x424(r31)

	.loc_0x2D0:
	  li        r0, 0
	  sth       r0, 0x426(r31)
	  li        r3, 0x1

	.loc_0x2DC:
	  lmw       r27, 0x64(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007C698
 * Size:	000008
 */
bool Condition::satisfy(Creature*) { return true; }

/*
 * --INFO--
 * Address:	8007C6A0
 * Size:	000048
 */
bool InteractKill::actPiki(Piki* piki)
{
	if (_08 == 1) {
		piki->kill(true);
	} else {
		piki->kill(false);
	}
	return true;
}

/*
 * --INFO--
 * Address:	8007C6E8
 * Size:	00002C
 */
bool InteractKill::actNavi(Navi* navi)
{
	navi->kill(false);
	return true;
}

/*
 * --INFO--
 * Address:	8007C714
 * Size:	000138
 */
bool InteractPress::actPiki(Piki* piki)
{
	if (piki->getState() == PIKISTATE_Pressed) {
		return false;
	}
	piki->playEventSound(mOwner, 27);
	if (piki->hasBomb()) {
		Creature* bomb = piki->_2AC;
		bomb->resetStateGrabbed();
		if (bomb->mObjType == OBJTYPE_Bomb) {
			MsgUser msg(1);
			static_cast<BombItem*>(bomb)->_2D0 = 0;
			static_cast<BombItem*>(bomb)->mStateMachine->procMsg(static_cast<BombItem*>(bomb), &msg);
		}
	}

	piki->changeMode(0, piki->mNavi);
	piki->mFSM->transit(piki, PIKISTATE_Pressed);
	// update when PikiProps is filled out
	piki->_48C = static_cast<PikiProp*>(piki->mProps)->mCreatureProps.mAcceleration();
	piki->mHealth -= mDamage;
	// update when PikiProps is filled out
	piki->mLifeGauge.updValue(piki->mHealth, static_cast<PikiProp*>(piki->mProps)->mCreatureProps.mAcceleration());
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return true;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x34(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  bl        0x4BE1C
	  cmpwi     r3, 0x21
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x38:
	  lwz       r4, 0x4(r29)
	  addi      r3, r30, 0
	  li        r5, 0x1B
	  bl        0xDE5C
	  mr        r3, r30
	  bl        0x4B710
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  lwz       r31, 0x2AC(r30)
	  mr        r3, r31
	  bl        0xE260
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xE
	  bne-      .loc_0xA4
	  li        r0, 0xA
	  stw       r0, 0x24(r1)
	  li        r0, 0x1
	  addi      r4, r31, 0
	  stw       r0, 0x28(r1)
	  li        r0, 0
	  addi      r5, r1, 0x24
	  stw       r0, 0x2D0(r31)
	  lwz       r3, 0x2E8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0xA4:
	  lwz       r5, 0x504(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x50A08
	  lwz       r3, 0x490(r30)
	  addi      r4, r30, 0
	  li        r5, 0x21
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x224(r30)
	  addi      r3, r30, 0x1E0
	  lfs       f0, 0x168(r4)
	  stfs      f0, 0x48C(r30)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r30)
	  lwz       r4, 0x224(r30)
	  lfs       f1, 0x58(r30)
	  lfs       f2, 0xB8(r4)
	  bl        -0x2079C
	  lfs       f0, -0x63E4(r13)
	  li        r3, 0x1
	  stfs      f0, 0xA4(r30)
	  lfs       f0, -0x63E0(r13)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, -0x63DC(r13)
	  stfs      f0, 0xAC(r30)

	.loc_0x11C:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007C84C
 * Size:	000008
 */
bool InteractFlute::actTeki(Teki*) { return 0x1; }
