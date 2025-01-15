#include "Condition.h"
#include "Interactions.h"
#include "Piki.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "PikiMgr.h"
#include "MapCode.h"
#include "PikiAI.h"
#include "SoundMgr.h"
#include "Collision.h"
#include "Stickers.h"
#include "Navi.h"
#include "BombItem.h"
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
DEFINE_PRINT("interactBattle");

/*
 * --INFO--
 * Address:	8007B7C8
 * Size:	0001A0
 */
bool InteractBomb::actPiki(Piki* piki)
{
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

	if (piki->aiCullable() && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk27)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk27);
	}

	playerState->mResultFlags.setOn(RESFLAG_Unk24);

	piki->playEventSound(mOwner, SE_PIKI_DAMAGED);

	piki->mHealth -= mDamage;

	// update this when PikiProp is filled out
	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiHealth());

	Vector3f diff = mOwner->mPosition - piki->mPosition;
	diff.normalise();
	piki->mRotationAngle  = atan2f(diff.x, diff.z);
	piki->mFlickIntensity = 180.0f;

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
		PRINT("miurin %d\n", piki->mHappa);
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

		// if we're holding a bomb, drop it
		if (piki->isHolding()) {
			InteractRelease release(piki, 1.0f);
			Creature* bomb = piki->getHoldCreature();
			bomb->stimulate(release);
		}

		piki->mLeaderCreature = kinoko;
		piki->mActiveAction->abandon(nullptr);
		piki->mActiveAction->mChildActionIdx = 22;
		piki->mActiveAction->mChildActions[piki->mActiveAction->mChildActionIdx].initialise(kinoko);
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
bool InteractWind::actCommon(Creature*)
{
	return true;
}

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
	if (piki->isStickTo()) {
		return false;
	}

	int pikiMode = piki->mMode;
	if (pikiMode == PikiMode::EnterMode || pikiMode == PikiMode::ExitMode) {
		return false;
	}

	piki->mActiveAction->abandon(mWindParticles);
	piki->mFSM->transit(piki, PIKISTATE_Flown);

	piki->mVelocity       = mVelocity;
	piki->mTargetVelocity = mVelocity;

	return true;
}

/*
 * --INFO--
 * Address:	8007BEF0
 * Size:	00005C
 */
bool InteractFlick::actCommon(Creature* creature)
{
	if (creature->isStickToMouth()) {
		creature->endStickMouth();
	}

	// if stuck to something, end stick
	if (creature->isStickTo()) {
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
		PRINT("already flicked\n");
		return false;
	}

	piki->playEventSound(mOwner, SE_PIKI_DAMAGED);

	piki->mHealth -= mDamage;

	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiHealth());

	if (mAngle < FLICK_BACKWARDS_THRESHOLD) {
		piki->mRotationAngle = piki->mDirection;
	} else {
		piki->mRotationAngle = mAngle;
	}

	piki->mFlickIntensity = mIntensity;
	piki->mFSM->transit(piki, PIKISTATE_Flick);
	return true;
}

/*
 * --INFO--
 * Address:	8007C038
 * Size:	000008
 */
bool InteractSlimeAttack::actCommon(Creature*)
{
	return true;
}

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
		PRINT("DYING or DEAD \n");
		return false;
	}

	if (state == PIKISTATE_Flick) {
		return false;
	}

	piki->playEventSound(mOwner, SE_PIKI_DAMAGED);
	piki->startDamage();
	piki->mHealth -= mDamage;

	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiHealth());

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
bool InteractSwallow::actCommon(Creature*)
{
	return true;
}

/*
 * --INFO--
 * Address:	8007C3A8
 * Size:	0002F0
 */
bool InteractSwallow::actPiki(Piki* piki)
{
	if (!piki->isAlive()) {
		ERROR("try to swallow dead piki!\n");
	}

	piki->mActiveAction->abandon(nullptr);
	piki->mActiveAction->mChildActionIdx = 15;
	piki->mActiveAction->mChildActions[piki->mActiveAction->mChildActionIdx].initialise(nullptr);
	piki->mMode = 0;
	if (!mMouthPart) {
		piki->playEventSound(mOwner, SE_PIKI_EATEN);
		piki->kill(false);
		return true;
	}

	PRINT("piki swallowed (CollPart=%x:%s)\n", mMouthPart, mMouthPart->mCollInfo->mId.mStringID);

	piki->mSwallowMouthPart = mMouthPart;

	piki->getState();

	if (_08 == 0) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Esa), PaniMotionInfo(PIKIANIM_Esa));
	} else {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Fall), PaniMotionInfo(PIKIANIM_Fall));
	}

	piki->mFSM->transit(piki, PIKISTATE_Swallowed);

	if (piki->isStickTo() && !piki->isStickToMouth()) {
		PRINT("*** Before stickMouth : stick off\n");
		piki->endStickObject();
		piki->endStick();
	}

	piki->startStickMouth(mOwner, mMouthPart);

	if (!piki->isStickToMouth()) {
		PRINT("**** STICK MOUTH FAILED *****************\n");
		piki->mSwallowMouthPart = nullptr;
		return false;
	}

	PRINT("nakata check +++++++++++++++++++++\n");

	Stickers stuckList(mOwner);
	Iterator iter(&stuckList);
	bool isPiki = false;
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;

		if (stuck == piki) {
			isPiki = true;
		}

		if (stuck->isStickToMouth()) {
			PRINT("object %x (type %d) is stick to my mouth\n", stuck, stuck->mObjType);
		}
	}

	PRINT("--------------------------\n");

	if (!isPiki) {
		PRINT("WHY=============??\n");
		PRINT("p->_stickObject = %x sender = %x\n", piki->mStickTarget, mOwner);
		PRINT("CHAPPY no stickers ==\n");
		for (Creature* stuck = mOwner->mStickListHead; stuck; stuck = stuck->mNextSticker) {
			PRINT(" %x : flags=%x\n", stuck, stuck->mCreatureFlags);
		}

		ERROR("sorry\n");
	}

	if (!piki->isCreatureFlag(CF_StuckToMouth)) {
		ERROR("FL_STICK_MOUTH is false\n"); // OOOOH THIS IS HOW THEY NAMED THE FLAGS
	}

	PRINT("play dead sound!\n");
	piki->playEventSound(mOwner, SE_PIKI_EATEN);

	if (piki->_426) {
		piki->_426 = 0;
		piki->mRippleEffect->kill();
		piki->_424 = 0;
	}

	piki->_426 = 0;
	return true;
}

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
	piki->playEventSound(mOwner, SE_PIKI_PRESSED);
	if (piki->hasBomb()) {
		Creature* bomb = piki->getHoldCreature();
		bomb->resetStateGrabbed();
		if (bomb->mObjType == OBJTYPE_Bomb) {
			MsgUser msg(1);
			BombItem* bombItem = static_cast<BombItem*>(bomb);
			bombItem->_2D0     = 0;
			static_cast<SimpleAI*>(bombItem->mStateMachine)->procMsg(bombItem, &msg);
			PRINT("bomb immediately\n");
		}
	}

	piki->changeMode(0, piki->mNavi);
	piki->mFSM->transit(piki, PIKISTATE_Pressed);

	piki->_48C = C_PIKI_PROP(piki)._15C();
	piki->mHealth -= mDamage;
	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiHealth());
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return true;
}

/*
 * --INFO--
 * Address:	8007C84C
 * Size:	000008
 */
bool InteractFlute::actTeki(Teki*)
{
	return true;
}
