#include "BombItem.h"
#include "Collision.h"
#include "Condition.h"
#include "DebugLog.h"
#include "Interactions.h"
#include "MapCode.h"
#include "Navi.h"
#include "Piki.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "Stickers.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(19)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("interactBattle");

/**
 * @TODO: Documentation
 */
bool InteractBomb::actPiki(Piki* piki) immut
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

	if (piki->aiCullable() && !playerState->mDemoFlags.isFlag(DEMOFLAG_FirstBombDeath)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_FirstBombDeath);
	}

	playerState->mResultFlags.setOn(RESFLAG_PikminBombDeath);

	piki->playEventSound(mOwner, SE_PIKI_DAMAGED);

	piki->mHealth -= mDamage;

	// update this when PikiProp is filled out
	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiMaxHealth());

	Vector3f diff = mOwner->mSRT.t - piki->mSRT.t;
	diff.normalise();
	piki->mRotationAngle  = atan2f(diff.x, diff.z);
	piki->mFlickIntensity = 180.0f;

	piki->mFSM->transit(piki, PIKISTATE_Flick);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractBury::actPiki(Piki* piki) immut
{
	if (!piki->isAlive()) {
		return false;
	}

	if (!piki->isSafeMePos(piki->mSRT.t) || MapCode::isBald(piki->mGroundTriangle)) {
		return false;
	}

	if (mMakeFlower && piki->mHappa < Flower) {
		piki->mHappa = Flower;
		PRINT_GLOBAL("miurin %d\n", piki->mHappa);
	}

	piki->mFSM->transit(piki, PIKISTATE_Bury);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractThrowAway::actPiki(Piki* piki) immut
{
	if (!piki->isAlive()) {
		return false;
	}

	piki->mFSM->transit(piki, PIKISTATE_FallMeck);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractChangeColor::actPiki(Piki* piki) immut
{
	if (!piki->isAlive()) {
		return false;
	}

	piki->changeShape(mColor);
	piki->setColor(mColor);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractChangeHappa::actPiki(Piki* piki) immut
{
	if (!piki->isAlive()) {
		return false;
	}

	piki->setFlower(mHappa);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractSpore::actPiki(Piki* piki) immut
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
		piki->mActiveAction->mCurrActionIdx = PikiAction::Kinoko;
		piki->mActiveAction->mChildActions[piki->mActiveAction->mCurrActionIdx].initialise(kinoko);
		piki->mFSM->transit(piki, PIKISTATE_KinokoChange);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool InteractBubble::actPiki(Piki* piki) immut
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

/**
 * @TODO: Documentation
 */
bool InteractFire::actPiki(Piki* piki) immut
{
	if (!piki->isAlive()) {
		return false;
	}

	// red pikmin are immune to fire
	if (piki->mColor != Red) {
		piki->startFire();
		return true;
	}

	playerState->mResultFlags.setOn(RESFLAG_PikminOnFire);
	return false;
}

/**
 * @TODO: Documentation
 */
bool InteractWind::actCommon(Creature*) immut
{
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractWind::actPiki(Piki* piki) immut
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

/**
 * @TODO: Documentation
 */
bool InteractFlick::actCommon(Creature* creature) immut
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

/**
 * @TODO: Documentation
 */
bool InteractFlick::actPiki(Piki* piki) immut
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

	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiMaxHealth());

	if (mAngle < FLICK_BACKWARDS_THRESHOLD) {
		piki->mRotationAngle = piki->mFaceDirection;
	} else {
		piki->mRotationAngle = mAngle;
	}

	piki->mFlickIntensity = mIntensity;
	piki->mFSM->transit(piki, PIKISTATE_Flick);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractSlimeAttack::actCommon(Creature*) immut
{
	return true;
}

/**
 * @TODO: Documentation
 */
int InteractAttack::getDamagePortion() immut
{
	if (mCollPart) {
		immut ID32& id = mCollPart->getCode();
		if (id.match('***0')) {
			return 0;
		}

		if (id.match('***1')) {
			return 1;
		}

		if (id.match('***2')) {
			return 2;
		}

		if (id.match('***3')) {
			return 3;
		}

		if (id.match('***4')) {
			return 4;
		}

		if (id.match('***5')) {
			return 5;
		}

		if (id.match('***6')) {
			return 6;
		}

		if (id.match('***7')) {
			return 7;
		}

		if (id.match('***8')) {
			return 8;
		}

		if (id.match('***9')) {
			return 9;
		}
	}

	return -1;
}

/**
 * @TODO: Documentation
 */
bool InteractAttack::actCommon(Creature* creature) immut
{
	if (!creature->isVisible()) {
		return false;
	}
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractAttack::actPiki(Piki* piki) immut
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

	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiMaxHealth());

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

/**
 * @TODO: Documentation
 */
bool InteractSwallow::actCommon(Creature*) immut
{
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractSwallow::actPiki(Piki* piki) immut
{
	if (!piki->isAlive()) {
		ERROR("try to swallow dead piki!\n");
	}

	piki->mActiveAction->abandon(nullptr);
	piki->mActiveAction->mCurrActionIdx = PikiAction::Free;
	piki->mActiveAction->mChildActions[piki->mActiveAction->mCurrActionIdx].initialise(nullptr);
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
		PRINT("ちゃんとスティックしてません 口に\n"); // "It's not sticking properly in my mouth"
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

	if (piki->mInWaterTimer) {
		piki->mInWaterTimer = 0;
		piki->mRippleEffect->kill();
		piki->mIsPanicked = false;
	}

	piki->mInWaterTimer = 0;
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractKill::actPiki(Piki* piki) immut
{
	if (_08 == 1) {
		piki->kill(true);
	} else {
		piki->kill(false);
	}
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractKill::actNavi(Navi* navi) immut
{
	navi->kill(false);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractPress::actPiki(Piki* piki) immut
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
			BombItem* bombItem    = static_cast<BombItem*>(bomb);
			bombItem->mCurrAnimId = 0;
			static_cast<SimpleAI*>(bombItem->mStateMachine)->procMsg(bombItem, &msg);
			PRINT("bomb immediately\n");
		}
	}

	piki->changeMode(0, piki->mNavi);
	piki->mFSM->transit(piki, PIKISTATE_Pressed);

	piki->mDeathTimer = C_PIKI_PROP(piki).mPressDeathFactor();
	piki->mHealth -= mDamage;
	PRINT(">>> piki pressed : life is %.1f (damage %.1f)\n", piki->mHealth, mDamage);
	piki->mLifeGauge.updValue(piki->mHealth, C_PIKI_PROP(piki).mPikiMaxHealth());
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	return true;
}

/**
 * @TODO: Documentation
 */
bool InteractFlute::actTeki(Teki*) immut
{
	return true;
}
