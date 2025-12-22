#include "DebugLog.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TekiConditions.h"
#include "WorkObject.h"
#include "gameflow.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(21)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIAattack")

/**
 * @TODO: Documentation
 */
void TAIAattackWorkObject::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setStatus(0);
	teki.setFrameCounter(0.0f);
}

/**
 * @TODO: Documentation
 */
bool TAIAattackWorkObject::act(Teki& teki)
{
	bool res = false;
	switch (teki.getStatus()) {
	case 0:
		if (teki.startNewMotion(_0C)) {
			if (setTargetPosition(teki)) {
				teki.setStatus(1);
				teki.setFrameCounter(0.0f);
			} else {
				res = true;
			}
		}
		break;
	case 1:
		if (teki.startNewMotion(_0C)) {
			if (teki.mTargetPosition.distance(teki.getPosition()) < getAttackPointRadius(teki)) {
				teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
				teki.mVelocity = teki.mTargetVelocity;
				teki.setStatus(2);
			} else {
				teki.addFrameCounter(gsys->getFrameTime());
				if (teki.getFrameCounter() < 15.0f) {
					teki.moveTowardPriorityFaceDir(teki.mTargetPosition, teki.getParameterF(TPF_WalkVelocity));
				} else if (teki.getCollidePlatformCreature() == teki.getWorkObjectPointer()) {
					teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
					teki.mVelocity = teki.mTargetVelocity;
					teki.setStatus(2);
				}
			}
		}
		break;
	case 2:
		if (teki.startNewMotion(_10)) {
			res = attackWorkObject(teki);
		}
		break;
	default:
		ERROR("Unknown status %d \n", teki.getStatus());
		break;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
bool TAIAattackWorkObject::attackWorkObject(Teki& teki)
{
	bool res        = false;
	WorkObject* obj = teki.getWorkObjectPointer();
	if (obj && obj->isBridge()) {
		Bridge* bridge = (Bridge*)obj;
		if (teki.getTableIndex() < 0) {
			res = true;
		} else {
			if (getLastFinishedStageBridge(bridge) == teki.getTableIndex()) {
				InteractBreak intBreak(&teki, teki.getTableIndex(),
				                       gsys->getFrameTime() / gameflow.mWorldClock.mTimeScale * getDamage(teki));
				bridge->stimulate(intBreak);
				attackEffect(teki);
			} else {
				teki.setStatus(0);
			}
		}
	}

	return res;
}

/**
 * @TODO: Documentation
 */
bool TAIAattackWorkObject::setTargetPosition(Teki& teki)
{
	bool res        = false;
	WorkObject* obj = teki.getWorkObjectPointer();
	teki.mTargetPosition.set(teki.getPosition());
	if (obj && obj->isBridge()) {
		Bridge* bridge = (Bridge*)obj;
		int stage      = getLastFinishedStageBridge(bridge);
		if (stage >= 0) {
			Vector3f offset;
			teki.mTargetPosition.set(bridge->getStagePos(stage));
			offset = bridge->getBridgeZVec();
			offset.multiply(-bridge->getStageDepth());
			teki.mTargetPosition.add(offset);
			teki.mTargetPosition.y = mapMgr->getMinY(teki.mTargetPosition.x, teki.mTargetPosition.z, true);
			offset                 = bridge->getBridgeXVec();
			offset.multiply(bridge->getStageWidth() * (zen::Rand(1.0f) - 0.5f) * 0.8f);
			teki.mTargetPosition.add(offset);
			res = true;
		}
		teki.setTableIndex(stage);
	}

	return res;
}

/**
 * @TODO: Documentation
 */
int TAIAattackWorkObject::getLastFinishedStageBridge(Bridge* bridge)
{
	for (int i = bridge->getStage() - 1; i >= 0; i--) {
		if (bridge->isStageFinished(i)) {
			return i;
		}
	}
	return -1;
}

/**
 * @TODO: Documentation
 */
void TAIAflickingAfterMotionLoop::start(Teki& teki)
{
	TAIAmotionLoop::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @TODO: Documentation
 */
bool TAIAflickingAfterMotionLoop::permitFlick(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
bool TAIAflickingAfterMotionLoop::act(Teki& teki)
{
	bool res = false;
	if (permitFlick(teki)) {
		teki.flick();
	}
	if (TAIAmotionLoop::act(teki) && teki.mCurrentAnimEvent == KEY_Finished) {
		teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
		res = true;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
bool TAIAtargetNavi::act(Teki& teki)
{
	Navi* navi = naviMgr->getNavi();
	if (teki.attackableCreature(*navi)) {
		teki.setCreaturePointer(0, navi);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TAIAtargetPiki::act(Teki& teki)
{
	bool res = false;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (teki.attackableCreature(*piki)) {
			teki.setCreaturePointer(0, piki);
			res = true;
			break;
		}
	}

	return res;
}

/**
 * @TODO: Documentation
 */
void TAIAfireBreath::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setAnimSpeed(getPreviousAnimSpeed(teki));
}

/**
 * @TODO: Documentation
 */
bool TAIAfireBreath::act(Teki& teki)
{
	if (TAIAreserveMotion::act(teki)) {
		teki.setAnimSpeed(getAttackAnimSpeed(teki));
		if (mCallBack) {
			mCallBack->invoke(teki);
		}

		if (teki.mCurrentAnimEvent == KEY_Finished) {
			teki.setManualAnimation(false);
			return true;
		}
		return false;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
bool TAIAflickCheck::act(Teki& teki)
{
	bool res = false;
	if (getDamageCountLimit(teki) < 0) {
		f32 damageCount = teki.getFlickDamageCount(teki.countPikis(TekiLowerRangeCondition(&teki)));
		res             = teki.mDamageCount >= damageCount;
	} else if (teki.mDamageCount >= getDamageCountLimit(teki)) {
		res = true;
	}

	if (res) {
		teki.mDamageCount = 0.0f;
	}

	return res;
	TekiLowerCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
void TAIAflicking::start(Teki& teki)
{
	TAIAmotion::start(teki);
	teki.stopMove();
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @TODO: Documentation
 */
bool TAIAflicking::act(Teki& teki)
{
	bool res = false;
	if (teki.mCurrentAnimEvent == KEY_Finished) {
		teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
		teki.mDamageCount = 0.0f;
		res               = true;
	} else {
		flick(teki);
	}
	return res;
}

/**
 * @TODO: Documentation
 */
void TAIAflicking::flick(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		InteractFlick NRef flick = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
		                                         getFlickDirection(teki));
		teki.flick(flick, flick);
	}
}

/**
 * @TODO: Documentation
 */
void TAIAflickingReserveMotion::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.stopMove();
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @TODO: Documentation
 */
bool TAIAflickingReserveMotion::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mCurrentAnimEvent == KEY_Finished) {
			teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
			teki.mDamageCount = 0.0f;
			res               = true;
		} else {
			flick(teki);
		}
	}
	return res;
}

/**
 * @TODO: Documentation
 */
void TAIAflickingReserveMotion::flick(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Action0) {
		InteractFlick NRef flick = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
		                                         getFlickDirection(teki));
		teki.flick(flick, flick);
	}
}

/**
 * @TODO: Documentation
 */
void TAIAbiteForKabekui::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setBiteSwitch(false);
	teki.setCreaturePointer(2, nullptr);
}

/**
 * @TODO: Documentation
 */
bool TAIAbiteForKabekui::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		if (teki.mCurrentAnimEvent == KEY_Finished) {
			if (teki.getCreaturePointer(2)) {
				mNextState = _0C;
			} else {
				mNextState = _10;
			}
			res = true;
		} else {
			if (teki.mCurrentAnimEvent == KEY_Action0) {
				teki.setBiteSwitch(true);
			} else if (teki.mCurrentAnimEvent == KEY_Action1) {
				teki.setBiteSwitch(false);
			}
			if (teki.getBiteSwitch()) {
				hitCheck(teki);
			}
		}
	}

	return res;
}

/**
 * @TODO: Documentation
 */
bool TAIAbiteForKabekui::hitCheck(Teki& teki)
{
	bool res = false;
	if (!teki.getCreaturePointer(2)) {
		CollPart* mouth = teki.mCollInfo->getSphere('slot');
		for (int i = 0; i < mouth->getChildCount(); i++) {
			Iterator iter(pikiMgr);
			CI_LOOP(iter)
			{
				Creature* piki = *iter;
				if (piki->isAlive()) {
					if (mouth->getChildAt(i)->mCentre.distance(piki->getPosition()) < getPikiAttackSize(teki)) {

						teki.setCreaturePointer(2, piki);
						InteractSwallow swallow(&teki, mouth->getChildAt(i), 1);
						piki->stimulate(swallow);
						res = true;
						break;
					}
				}
			}
		}

		if (!res) {
			Iterator iter(naviMgr);
			CI_LOOP(iter)
			{
				Creature* navi = *iter;
				if (mouth->mCentre.distance(navi->getPosition()) < getNaviAttackSize(teki)) {
					teki.attackTarget(*navi, teki.getAttackRange(), teki.getParameterF(TPF_AttackPower), TekiRecognitionCondition(&teki));
				}
			}
		}
	}

	STACK_PAD_TERNARY(res, 2);
	return res;
}

/**
 * @TODO: Documentation
 */
void TAIAeatPiki::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
}

/**
 * @TODO: Documentation
 */
bool TAIAeatPiki::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki) && teki.mCurrentAnimEvent == KEY_Action0) {
		eatEffect(teki);
		teki.killStickToMouthPiki();
		res = true;
	}

	return res;
}

/**
 * @TODO: Documentation
 */
void TAIAeatPiki::eatEffect(Teki& teki)
{
	teki.playEventSound(&teki, SE_WALLEAT_NIP);
}
