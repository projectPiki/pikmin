#include "ItemAI.h"
#include "BaseInf.h"
#include "BombItem.h"
#include "Boss.h"
#include "BuildingItem.h"
#include "Collision.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GameStat.h"
#include "GemItem.h"
#include "GoalItem.h"
#include "Interface.h"
#include "MapCode.h"
#include "MapMgr.h"
#include "MoviePlayer.h"
#include "NaviMgr.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "gameflow.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(33)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("itemAI")

/**
 * @todo: Documentation
 */
SluiceAI::SluiceAI()
{
	SAIUserEvent* evt1 = new SAIUserEvent(0);
	SAIUserEvent* evt2 = new SAIUserEvent(1);
	create(Sluice_COUNT);
	addState(Sluice_Init, PANI_NO_MOTION, new SluiceAI::Init);
	addState(Sluice_WaitInit, PANI_NO_MOTION, new SluiceAI::WaitInit);
	addState(Sluice_AddCount, PANI_NO_MOTION, new SluiceAI::AddCount);
	addState(Sluice_ChangeInit, PANI_NO_MOTION, new SluiceAI::ChangeInit);
	addState(Sluice_MotionDone, PANI_NO_MOTION, new SluiceAI::MotionDone);
	addState(Sluice_DamageInit, PANI_NO_MOTION, new SluiceAI::DamageInit);

	addArrow(Sluice_ChangeInit, saiMotionDoneEvent, Sluice_MotionDone);
	addArrow(Sluice_ChangeInit, evt1, Sluice_AddCount);

	addArrow(Sluice_AddCount, evt1, Sluice_AddCount);
	addArrow(Sluice_AddCount, saiMotionDoneEvent, Sluice_MotionDone);

	addArrow(Sluice_WaitInit, evt1, Sluice_ChangeInit);
	addArrow(Sluice_WaitInit, evt2, Sluice_DamageInit);

	addArrow(Sluice_DamageInit, evt1, Sluice_ChangeInit);
	addArrow(Sluice_DamageInit, saiMotionDoneEvent, Sluice_WaitInit);
}

/**
 * @todo: Documentation
 */
void SluiceAI::Init::act(AICreature* item)
{
	item->mCounter = 0;
	item->mStateMachine->transit(item, Sluice_WaitInit);
}

/**
 * @todo: Documentation
 */
void SluiceAI::MotionDone::act(AICreature* item)
{
	PRINT("GATE ** MOTION DONE ** %d\n", item->mCounter);

	if (item->mCounter <= 0) {
		item->mCounter = 0;
		item->mStateMachine->transit(item, Sluice_WaitInit);
	} else {
		item->mCounter--;
		item->mStateMachine->transit(item, Sluice_ChangeInit);
	}
}

/**
 * @todo: Documentation
 */
void SluiceAI::AddCount::act(AICreature* item)
{
	PRINT("GATE ** COUNTER became %d\n", item->mCounter);
	item->mCounter++;
}

/**
 * @todo: Documentation
 */
void SluiceAI::WaitInit::act(AICreature* item)
{
	BuildingItem* obj = (BuildingItem*)item;
	if (obj->isCompleted()) {
		obj->mWayPoint->setFlag(true);
		if (obj->mSeContext) {
			obj->mSeContext->releaseEvent();
		}
	} else {
		obj->mWayPoint->setFlag(false);
	}

	obj->stopMotion();
	obj->stopBreakEffect();
}

/**
 * @todo: Documentation
 */
void SluiceAI::ChangeInit::act(AICreature* item)
{
	BuildingItem* obj = (BuildingItem*)item;
	PRINT("******* CHANGE INIT ******** aiContext.int=%d curr=%d\n", obj->mCurrStage, obj->mCurrAnimId);

	item->setMotionSpeed(30.0f);
	item->startMotion(obj->mCurrAnimId);
	obj->startBreakEffect();
	if (obj->mCurrAnimId == obj->mNumStages - 1) {
		obj->mWayPoint->setFlag(true);
	}
	obj->mCurrAnimId++;
}

/**
 * @todo: Documentation
 */
void SluiceAI::DamageInit::act(AICreature* item)
{
	BuildingItem* obj = (BuildingItem*)item;

	if (obj->mCurrStage < obj->mNumStages) {
		item->setMotionSpeed(30.0f);
		item->startMotion(obj->mCurrAnimId + 3);
	}
}

/**
 * @todo: Documentation
 */
PikiHeadAI::PikiHeadAI()
{
	create(PIKIHEAD_COUNT);
	addState(PIKIHEAD_Unk13, PikiHeadMotion::TaneFall);
	addState(PIKIHEAD_Bounce, PikiHeadMotion::TaneDown, new BounceSound);
	addState(PIKIHEAD_Bury2, PANI_NO_MOTION, new BuryInit2, new BuryExec2);
	addState(PIKIHEAD_Flying, PikiHeadMotion::TaneFall, new FlyingEffect, new FlyingExec, new FlyingCleanup);
	addState(PIKIHEAD_Bury, PANI_NO_MOTION, new BuryInit, new BuryExec);
	addState(PIKIHEAD_Tane, PANI_NO_MOTION, new TaneInit, new TaneExec);
	addState(PIKIHEAD_Unk5, PikiHeadMotion::Hatuga);
	addState(PIKIHEAD_Wait, PikiHeadMotion::UgWait, new WaitInit, new WaitExec);
	addState(PIKIHEAD_Unk7, PikiHeadMotion::UgGrow);
	addState(PIKIHEAD_Growuped, PANI_NO_MOTION, new GrowupedExec);
	addState(PIKIHEAD_Grow, PANI_NO_MOTION, new GrowEffect);
	addState(PIKIHEAD_Unk10, PikiHeadMotion::Sioreru);
	addState(PIKIHEAD_Kareta, PANI_NO_MOTION, new KaretaInit, new KaretaExec);
	addState(PIKIHEAD_Dead, PANI_NO_MOTION, new Dead);

	addArrow(PIKIHEAD_Flying, saiBounceEvent, PIKIHEAD_Bounce);
	addArrow(PIKIHEAD_Bounce, saiMotionDoneEvent, PIKIHEAD_Bury);
	addArrow(PIKIHEAD_Unk5, saiMotionDoneEvent, PIKIHEAD_Wait);
	addArrow(PIKIHEAD_Unk7, saiMotionAction0Event, PIKIHEAD_Growuped);
	addArrow(PIKIHEAD_Growuped, saiMotionDoneEvent, PIKIHEAD_Wait);
	addArrow(PIKIHEAD_Unk10, saiMotionDoneEvent, PIKIHEAD_Kareta);
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::BounceSound::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	CollTriInfo* tri = mapMgr->getCurrTri(item->mSRT.t.x, item->mSRT.t.z, true);
	if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
		item->startWaterEffect();
		effectMgr->create(EffectMgr::EFF_P_Bubbles, item->mSRT.t, nullptr, nullptr);
		if (obj->_3E0) {
			item->playEventSound(obj->_3E0, SE_PIKI_GROW0_WATER);
		} else {
			seSystem->playPikiSound(SEF_PIKI_GROW0_WATER, obj->mSRT.t);
		}
		return;
	}

	effectMgr->create(EffectMgr::EFF_SD_DirtCloud, item->mSRT.t, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_SD_DirtSpray, item->mSRT.t, nullptr, nullptr);
	if (obj->_3E0) {
		item->playEventSound(obj->_3E0, SE_PIKI_GROW0);
	} else {
		PRINT("******** SEF_PIKI_GROW0 !!!! %d !!!!!\n", seSystem->getJacID(SEF_PIKI_GROW0));
		seSystem->playPikiSound(SEF_PIKI_GROW0, obj->mSRT.t);
	}
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::FlyingEffect::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->_3E4.init(obj->mSRT.t, EffectMgr::EFF_SD_Sparkle);
	obj->finishFix();
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::FlyingExec::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->_3E4.updatePos(obj->mSRT.t);
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::FlyingCleanup::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->_3E4.kill();
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::BuryInit2::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->mFlowerStage = Leaf;
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::BuryExec2::act(AICreature* item)
{
	PRINT("to save or not to save ....\n"); // Alright mr shakespeare over here

	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->mStateMachine->transit(item, PIKIHEAD_Dead);
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::BuryInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->startFix();
	obj->mFlowerStage       = Leaf;
	obj->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms.mSeedUpTime() + gsys->getRand(1.0f) * 2.0f;

	STACK_PAD_VAR(2);
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::BuryExec::act(AICreature* item)
{
	// stupid but fixes a regswap
	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		item->startMotion(PikiHeadMotion::TaneUp);
		item->mStateMachine->transit(item, PIKIHEAD_Tane);
	}
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::TaneInit::act(AICreature* item)
{
	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms.mPluckWaitTime() + gsys->getRand(1.0f) * 2.0f;
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::TaneExec::act(AICreature* item)
{
	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		item->mStateMachine->transit(item, PIKIHEAD_Unk5);
	}
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::WaitInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	if (obj->mFlowerStage == Flower) {
		item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms.mWiltTime() + gsys->getRand(1.0f) * 2.0f;
	} else {
		item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms.mGrowUpTime() + gsys->getRand(1.0f) * 2.0f;
	}
	item->mCounter = 0;
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::WaitExec::act(AICreature* item)
{
	f32 badocmpiler[2];

	PikiHeadItem* obj = (PikiHeadItem*)item;

	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		if (obj->mFlowerStage == Flower) {
			item->mStateMachine->transit(item, PIKIHEAD_Unk10);
		} else {
			item->mStateMachine->transit(item, PIKIHEAD_Unk7);
		}
	} else if (health < 2.0f && obj->mCounter == 0 && obj->mFlowerStage != Flower) {
		Vector3f pos = obj->mSRT.t;
		pos.y += 13.0f;
		EffectParm parm(pos);
		utEffectMgr->cast(KandoEffect::PikiGrowup1, parm);
		obj->mCounter = 1;
	}
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::GrowupedExec::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->mFlowerStage = (obj->mFlowerStage + 1) % 3;

	int soundsA[3] = { SE_PIKI_GROW3, SE_PIKI_GROW2, SE_PIKI_GROW4 };
	int soundsB[3] = { SEF_PIKI_GROW3, SEF_PIKI_GROW2, SEF_PIKI_GROW4 };

	if (obj->_3E0) {
		obj->playEventSound(obj->_3E0, soundsA[obj->mFlowerStage]);
	} else {
		seSystem->playPikiSound(soundsB[obj->mFlowerStage], obj->mSRT.t);
	}

	Vector3f pos = item->mSRT.t;
	pos.y += 13.0f;
	EffectParm parm(pos);
	utEffectMgr->cast(KandoEffect::PikiGrowup2, parm);
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::GrowEffect::act(AICreature* item)
{
	item->mStateMachine->transit(item, PIKIHEAD_Wait);
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::KaretaInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms.mRebirthSeedTime() + 2.0f * gsys->getRand(1.0f);
	obj->mFlowerStage        = Leaf;
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::KaretaExec::act(AICreature* item)
{
	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		item->mStateMachine->transit(item, PIKIHEAD_Bury);
	}
}

/**
 * @todo: Documentation
 */
void PikiHeadAI::Dead::act(AICreature* item)
{
	item->kill(false);
}

/**
 * @todo: Documentation
 */
BombAI::BombAI()
{
	SAIUserEvent* evt1 = new SAIUserEvent(0);
	SAIUserEvent* evt2 = new SAIUserEvent(1);
	SAIUserEvent* evt3 = new SAIUserEvent(2);

	create(BOMB_COUNT);
	addState(BOMB_Unk0, PANI_NO_MOTION);
	addState(BOMB_Unk1, PANI_NO_MOTION);
	addState(BOMB_Set, PANI_NO_MOTION, new SetInit, new SetExec);
	addState(BOMB_Bomb, 0, new BombInit, new BombExec);
	addState(BOMB_Mizu, PANI_NO_MOTION, new MizuInit, new MizuExec);
	addState(BOMB_Die, PANI_NO_MOTION, new DieInit, new DieExec);

	addArrow(BOMB_Unk0, evt1, BOMB_Set);
	addArrow(BOMB_Set, evt2, BOMB_Bomb);
	addArrow(BOMB_Unk0, evt2, BOMB_Bomb);
	addArrow(BOMB_Unk1, saiBounceEvent, BOMB_Bomb);
}

/**
 * @todo: Documentation
 */
void BombAI::SetInit::act(AICreature* item)
{
	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms.mBombSetFuseTime() * (gsys->getRand(1.0f) * 0.05f + 1.0f);
	item->mMaxItemHealth     = item->mCurrentItemHealth;
	PRINT("BOMB * %f/%f\n", item->mCurrentItemHealth, item->mMaxItemHealth);

	if (item->mObjType != OBJTYPE_Bomb) {
		ERROR("this is not bomb %s\n", "setInit");
	}
}

/**
 * @todo: Documentation
 */
void BombAI::SetExec::act(AICreature* item)
{
	item->mCurrentItemHealth -= gsys->getFrameTime();
	PRINT("BOMB TIMER = %.1f\n", item->mCurrentItemHealth);
	if (item->mCurrentItemHealth < 0.0f) {
		PRINT("send bomb event ... %x\n", item);
		MsgUser msg(1);
		item->mCurrAnimId = 0;
		C_SAI(item)->procMsg(item, &msg);
	}

	if (item->mObjType != OBJTYPE_Bomb) {
		ERROR("this is not bomb %s\n", "setExec");
	}
}

/**
 * @todo: Documentation
 */
void BombAI::BombInit::act(AICreature* item)
{
	if (!tekiMgr) {
		return;
	}

	if (item->mObjType != OBJTYPE_Bomb) {
		ERROR("this is not bomb %s\n", "bombinit");
	}
	CndBombable cnd;
	f32 maxRange = pikiMgr->mPikiParms->mPikiParms.mBombExplodeRadius();
	f32 unused   = pikiMgr->mPikiParms->mPikiParms.mBombDamageBomb();
	item->setMotionSpeed(30.0f);
	playerState->mResultFlags.setOn(RESFLAG_YellowWithBomb);
	rumbleMgr->start(RUMBLE_Unk8, 0, item->mSRT.t);
	EffectParm parm(item->mSRT.t);
	if (item->mCurrAnimId == 1) {
		utEffectMgr->cast(KandoEffect::BombLight, parm);
		PRINT("USE LIGHTWEIGHT BOMB EFFECT\n");
	} else {
		utEffectMgr->cast(KandoEffect::Bomb, parm);
		PRINT("USE BOMB EFFECT\n");
	}

	if (!playerState->mDemoFlags.isFlag(DEMOFLAG_FirstBombExplode)) {
		playerState->mDemoFlags.setTimer(1.5f, DEMOFLAG_FirstBombExplode, nullptr);
	}
	item->playEventSound(item, SE_BOMB);
	item->mCurrentItemHealth = 0.0f;

	Iterator naviIt(naviMgr);
	CI_LOOP(naviIt)
	{
		Creature* obj = *naviIt;
		f32 dist      = circleDist(item, obj) + obj->getCentreSize();
		if (obj->isAlive() && obj->isVisible() && dist <= maxRange) {
			InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageNavi(), nullptr);
			obj->stimulate(act);
		}
	}

	Iterator pikiIt(pikiMgr);
	CI_LOOP(pikiIt)
	{
		Piki* obj = (Piki*)*pikiIt;
		f32 dist  = circleDist(item, obj) + obj->getCentreSize();
		if (obj->isAlive() && (obj->isVisible() || obj->getState() == PIKISTATE_Flying) && dist <= maxRange
		    && obj->getState() != PIKISTATE_Pressed) {
			PRINT("piki %x got bomb interaction!\n", obj);
			InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms.mBombDamagePiki(), nullptr);
			obj->stimulate(act);
		}
	}

	Iterator tekiIt(tekiMgr);
	CI_LOOP(tekiIt)
	{
		Creature* obj = *tekiIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist = qdist2(item->mSRT.t.x, item->mSRT.t.z, obj->mSRT.t.x, obj->mSRT.t.z);
			if (dist - maxRange - obj->getBoundingSphereRadius() > 0.0f) {
				continue;
			}
			PRINT("checkCollisionSpecial start <\n");
			CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mSRT.t, maxRange, &cnd);
			PRINT("checkCollisionSpecial done >\n");
			if (part) {
				PRINT("part found \n");
				obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageEnemy(), part));
			} else {
				if (centreDist(item, obj) - maxRange - obj->getCentreSize() < 0.0f) {
					obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageEnemy(), nullptr));
				}
			}
		}
	}

	Iterator bossIt(bossMgr);
	CI_LOOP(bossIt)
	{
		Creature* obj = *bossIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist = qdist2(item->mSRT.t.x, item->mSRT.t.z, obj->mSRT.t.x, obj->mSRT.t.z);
			if (dist - maxRange - obj->getBoundingSphereRadius() > 0.0f) {
				continue;
			}
			PRINT("checkCollisionSpecial start <\n");
			CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mSRT.t, maxRange, &cnd);
			PRINT("checkCollisionSpecial done >\n");
			InteractBomb bomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageEnemy(), part);
			if (part) {
				PRINT("part found \n");
				obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageEnemy(), part));
			} else {
				if (centreDist(item, obj) - maxRange - obj->getCentreSize() < 0.0f) {
					obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageEnemy(), nullptr));
				}
			}
		}
	}

	Iterator meltingIt(itemMgr->getMeltingPotMgr());
	CI_LOOP(meltingIt)
	{
		Creature* obj = *meltingIt;
		f32 minDist   = 128000.0f;
		if (obj->isSluice()) {
			CollPart* flagPart = obj->mCollInfo->getSphere('flag');
			for (int i = 0; i < flagPart->getChildCount(); i++) {
				CollPart* child = flagPart->getChildAt(i);
				Vector3f dir    = child->mCentre - item->mSRT.t;
				f32 dist        = dir.length() - child->mRadius - item->getCentreSize();
				if (dist < minDist) {
					minDist = dist;
				}
			}
		} else {
			minDist = circleDist(item, obj) - obj->getCentreSize();
		}
		InteractBomb bomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageNavi(), nullptr);
		if (obj->isAlive() && obj->isVisible() && minDist <= maxRange) {
			obj->stimulate(bomb);
		}
	}

	Iterator itemIt(itemMgr);
	CI_LOOP(itemIt)
	{
		Creature* c = *itemIt;
		f32 dist    = circleDist(item, c) - c->getCentreSize();
		if (c == item) {
			continue;
		}

		bool check = false;
		if (c->mObjType == OBJTYPE_Bomb && dist <= maxRange) {
			BombItem* otherBomb = (BombItem*)c;
			int state           = otherBomb->getCurrState()->getID();
			if (state != BombAI::BOMB_Die && state != BombAI::BOMB_Mizu && state != BombAI::BOMB_Bomb) {
				check = true;
			}
		} else if (c->isAlive() && c->isVisible() && dist <= maxRange) {
			check = true;
		}

		if (check) {
			InteractBomb bomb(item, pikiMgr->mPikiParms->mPikiParms.mBombDamageBomb(), nullptr);
			c->stimulate(bomb);
		}
	}

	PRINT("all done\n");
}

/**
 * @todo: Documentation
 */
void BombAI::BombExec::act(AICreature* item)
{
	item->mStateMachine->transit(item, BOMB_Die);
}

/**
 * @todo: Documentation
 */
void BombAI::MizuInit::act(AICreature* item)
{
	item->mCurrentItemHealth = 1.0f;
}

/**
 * @todo: Documentation
 */
void BombAI::MizuExec::act(AICreature* item)
{
	item->mCurrentItemHealth -= gsys->getFrameTime();
	PRINT("bomb in water ! %f\n", item->mCurrentItemHealth);
	f32 health = item->mCurrentItemHealth;
	if (health <= 0.0f) {
		item->mStateMachine->transit(item, BOMB_Die);
	}
	item->mSRT.s.set(health, health, health);
}

/**
 * @todo: Documentation
 */
void BombAI::DieInit::act(AICreature* item)
{
	item->mCurrentItemHealth = 5.0f;
	item->mSRT.s.set(0.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 */
void BombAI::DieExec::act(AICreature* item)
{
	f32 time = gsys->getFrameTime();
	item->setMotionSpeed(0.0f);
	item->mCurrentItemHealth -= time;
	if (item->mCurrentItemHealth <= 0.0f) {
		item->kill(false);
	}
}

/**
 * @todo: Documentation
 */
GoalAI::GoalAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);
	NotFinished* nf   = new NotFinished;

	create(GOAL_COUNT);
	addState(GOAL_Wait, PANI_NO_MOTION, new WaitInit);
	addState(GOAL_Effect, 2, new Effect);
	addState(GOAL_Unk2, 0);
	addState(GOAL_EmitPiki, PANI_NO_MOTION, new EmitPiki);
	addState(GOAL_EmitWait, PANI_NO_MOTION, nullptr, new EmitWait);
	addState(GOAL_BootInit, PANI_NO_MOTION, new BootInit);
	addState(GOAL_BootEmit, PANI_NO_MOTION, new BootEmit, nullptr, new BootDone);

	addArrow(GOAL_Wait, evt, GOAL_Effect);
	addArrow(GOAL_Effect, saiMotionDoneEvent, GOAL_Unk2);
	addArrow(GOAL_Unk2, evt, GOAL_Effect);
	addArrow(GOAL_Unk2, saiMotionLoopEndEvent, GOAL_EmitPiki);
	addArrow(GOAL_EmitPiki, evt, GOAL_Effect);
	addArrow(GOAL_EmitPiki, saiMotionLoopStartEvent, GOAL_EmitWait)->mCondition.add(nf);
	addArrow(GOAL_EmitPiki, saiMotionDoneEvent, GOAL_Wait);
	addArrow(GOAL_EmitWait, evt, GOAL_Effect);
	addArrow(GOAL_EmitWait, saiMotionDoneEvent, GOAL_Wait);
	addArrow(GOAL_EmitWait, saiMotionLoopEndEvent, GOAL_EmitPiki)->mCondition.add(nf);
	addArrow(GOAL_BootInit, saiMotionAction0Event, GOAL_BootEmit);
	addArrow(GOAL_BootEmit, saiMotionDoneEvent, GOAL_Wait);
}

/**
 * @todo: Documentation
 */
bool GoalAI::NotFinished::satisfy(AICreature* item)
{
	if (item->mCurrAnimId > 0 || item->mCounter > 0) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
void GoalAI::WaitInit::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;
	int anim      = ((ItemCreature*)item)->mItemAnimator.getCurrentMotionIndex();
	if (anim >= 6 && anim <= 8) {
		ERROR("wait and takeoff\n");
		return;
	}
	if (obj->getTotalStorePikis() > 0) {
		((ItemCreature*)item)->startMotion(12);
		((ItemCreature*)item)->setMotionSpeed(30.0f);
	} else {
		((ItemCreature*)item)->startMotion(1);
		((ItemCreature*)item)->setMotionSpeed(30.0f);
	}
}

/**
 * @todo: Documentation
 */
void GoalAI::BootInit::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;
	item->startMotion(obj->mOnionColour + 3);
}

/**
 * @todo: Documentation
 */
void GoalAI::BootEmit::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;

	PikiHeadItem* seed = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
	if (seed) {
		GameStat::bornPikis.inc(obj->mOnionColour);
		Vector3f pos = item->mSRT.t;
		pos.y += 110.0f;
		seed->init(pos);
		seed->setColor(obj->mOnionColour);
		rand();
		f32 dir = obj->mFaceDirection;
		seed->mVelocity.set(sinf(dir) * 290.0f, 800.0f, cosf(dir) * 290.0f);
		item->playEventSound(item, SE_CONTAINER_PIKIBORN);
		seed->startAI(0);
		seed->_3E0 = obj;
		C_SAI(seed)->start(seed, PikiHeadAI::PIKIHEAD_Flying);
		return;
	}

	PRINT("BOOT EMIT PIKI FAILED !\n");
	PikiHeadItem* oldSeed = nullptr;
	f32 seeddist          = 0.0f;

	Iterator it(itemMgr->getPikiHeadMgr());
	CI_LOOP(it)
	{
		PikiHeadItem* item = (PikiHeadItem*)*it;
		f32 dist           = qdist2(item->mSRT.t.x, item->mSRT.t.z, obj->mSRT.t.x, obj->mSRT.t.z);
		if (dist > seeddist) {
			seeddist = dist;
			oldSeed  = item;
		}
	}
	PRINT("*** GOT HERE\n");

	if (oldSeed) {
		pikiInfMgr.incPiki(oldSeed->mSeedColor, Leaf);
		itemMgr->getContainer(oldSeed->mSeedColor)->mHeldPikis[Leaf]++;
		GameStat::containerPikis.inc(oldSeed->mSeedColor);
		GameStat::update();
		oldSeed->kill(false);
		GameStat::workPikis.dec(oldSeed->mSeedColor);
		PRINT("far mePiki was killed\n");
	} else {

		Piki* oldPiki = nullptr;
		f32 pikidist  = 0.0f;

		Iterator pikiIt(pikiMgr);
		CI_LOOP(pikiIt)
		{
			Piki* item = (Piki*)*pikiIt;
			f32 dist   = qdist2(item->mSRT.t.x, item->mSRT.t.z, obj->mSRT.t.x, obj->mSRT.t.z);
			if (dist > pikidist) {
				pikidist = dist;
				oldPiki  = item;
			}
		}

		if (oldPiki) {
			pikiInfMgr.incPiki(oldPiki);
			GoalItem* onyon = itemMgr->getContainer(oldPiki->mColor);
			onyon->mHeldPikis[oldPiki->mHappa]++;
			GameStat::containerPikis.inc(oldPiki->mColor);
			GameStat::update();
			PRINT("far Piki was killed ** color%d\n", oldPiki->mColor);
			oldPiki->setEraseKill();
			oldPiki->kill(false);
		} else {
			ERROR("the end\n");
		}
	}

	PRINT("try again\n");
	act(item);
	STACK_PAD_VAR(3);
}

/**
 * @todo: Documentation
 */
void GoalAI::BootDone::act(AICreature* item)
{
}

/**
 * @todo: Documentation
 */
void GoalAI::EmitPiki::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;

	if (item->mCounter > 0) {
		Vector3f pos = item->mSRT.t;
		pos.y += 110.0f; // some dll exclusive unused stuff here
		rand();

		effectMgr->create(EffectMgr::EFF_Onyon_FireworkTrail, item->mSRT.t, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Onyon_FireworkMain, item->mSRT.t, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Onyon_FireworkKisek, item->mSRT.t, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Onyon_FireworkSmall, item->mSRT.t, nullptr, nullptr);
		item->mCounter--;
	}

	STACK_PAD_VAR(3);

	if (item->mCurrAnimId > 0) {
		if (item->mObjType != OBJTYPE_Goal) {
			char buf[256];
			sprintf(buf, "%d : not goal", item->mObjType);
			ERROR(buf);
		}

		PikiHeadItem* seed = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
		GameStat::bornPikis.inc(obj->mOnionColour);
		if (seed) {
			Vector3f pos = obj->mSRT.t;
			pos.y += 110.0f;
			seed->init(pos);
			seed->setColor(obj->mOnionColour);
			f32 dir = gsys->getRand(1.0f) * PI * 2.0f;
			seed->mVelocity.set(sinf(dir) * 290.0f, 800.0f, cosf(dir) * 290.0f);
			item->playEventSound(item, SE_CONTAINER_PIKIBORN);
			seed->startAI(0);
			seed->_3E0 = obj;
			C_SAI(seed)->start(seed, PikiHeadAI::PIKIHEAD_Flying);
		} else {
			pikiInfMgr.incPiki(obj->mOnionColour, Leaf);
			obj->mHeldPikis[Leaf]++;
			GameStat::containerPikis.inc(obj->mOnionColour);
			GameStat::update();
			if (!gameflow.mMoviePlayer->mIsActive && !playerState->mIsChallengeMode
			    && !playerState->mDemoFlags.isFlag(flowCont.mCurrentStage->mStageID + DEMOFLAG_PikminLimitOffset)) {
				playerState->mDemoFlags.setFlagOnly(flowCont.mCurrentStage->mStageID + DEMOFLAG_PikminLimitOffset);
				gameflow.mGameInterface->message(MOVIECMD_TextDemo, 21);
			}
			PRINT("COUNTER UP!\n");
		}

		obj->mCurrAnimId--;
	}
	if (obj->mCurrAnimId == 0 && obj->mCounter == 0) {
		obj->finishMotion();
	}

	STACK_PAD_VAR(4);
}

/**
 * @todo: Documentation
 */
void GoalAI::EmitWait::act(AICreature*)
{
}

/**
 * @todo: Documentation
 */
void GoalAI::Effect::act(AICreature* item)
{
	Vector3f pos = item->mSRT.t;
	pos.y += 90.0f;
	effectMgr->create(EffectMgr::EFF_Onyon_ActEffect, pos, nullptr, nullptr);
	item->playEventSound(item, SE_CONTAINER_PELLETIN2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001AC
 */
GemAI::GemAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);

	create(GEM_COUNT);
	addState(GEM_Unk0, PANI_NO_MOTION);
	addState(GEM_Rise, PANI_NO_MOTION, new RiseInit, new RiseExec);
	addState(GEM_Die, PANI_NO_MOTION, new Die);

	addArrow(GEM_Unk0, evt, GEM_Rise);
}

/**
 * @todo: Documentation
 */
void GemAI::RiseInit::act(AICreature* item)
{
	item->mCurrentItemHealth = 0.0f;
	item->mMaxItemHealth     = 1.5f;
	item->setFlag80();

	Vector3f pos = item->mSRT.t;
	EffectParm parm(pos);
	utEffectMgr->cast(KandoEffect::Goal, parm);
	item->playEventSound(item->mTargetCreature, SE_CONTAINER_PELLETIN);
	item->mVelocity.y = 0.0f;
	item->mCurrAnimId = 0;
}

/**
 * @todo: Documentation
 */
void GemAI::RiseExec::act(AICreature* item)
{
	if (item->mTargetCreature->mObjType != OBJTYPE_Goal) {
		ERROR("mail to good monkey!\n");
	}

	if (item->mMaxItemHealth > 0.0f) {
		item->mVelocity.set(0.0f, 0.0f, 0.0f);
		item->mMaxItemHealth -= gsys->getFrameTime();
		return;
	}

	if (item->mCurrAnimId == 0) {
		item->mCurrAnimId = 1;
	}

	Vector3f diff = item->mTargetCreature->mSRT.t - item->mSRT.t;
	diff.y        = 0.0f;
	diff.normalise();
	diff              = diff * 60.0f;
	item->mVelocity.x = diff.x;
	item->mVelocity.z = diff.z;
	item->mCurrentItemHealth += gsys->getFrameTime() * item->mVelocity.y;
	item->mVelocity.y += gsys->getFrameTime() * 720.0f;

	f32 div = item->mCurrentItemHealth / 74.0f;
	f32 b   = 1.0f - div * 1.0f;
	item->mSRT.s.set(b, b, b);
	if (div >= 1.0f) {
		item->mStateMachine->transit(item, GEM_Die);
		GameStat::getPellets.inc();
	}
}

/**
 * @todo: Documentation
 */
void GemAI::Die::act(AICreature* item)
{
	GemItem* obj   = (GemItem*)item;
	GoalItem* goal = (GoalItem*)item->mTargetCreature;
	int seeds;
	if (goal->mOnionColour == obj->mColor) {
		seeds = obj->_3F8;
	} else {
		seeds = obj->_3FC;
	}
	MsgUser msg(0);
	PRINT("gem item : ### add %d pikis\n", seeds);
	goal->mCurrAnimId += seeds;

	if (goal->mStateMachine) {
		C_SAI(goal)->procMsg(goal, &msg);
	}
	obj->_3E4 = 0;
	item->kill(false);
	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
WaterAI::WaterAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);

	create(WATER_COUNT);
	addState(WATER_Unk0, 0);
	addState(WATER_Unk1, 1);
	addState(WATER_Unk2, 3);
	addState(WATER_Unk3, 2);
	addState(WATER_Die, PANI_NO_MOTION, new Die);

	addArrow(WATER_Unk3, saiMotionDoneEvent, WATER_Unk0);
	addArrow(WATER_Unk0, saiCollideEvent, WATER_Unk1)->mCondition.add(new CollideChar);
	addArrow(WATER_Unk0, saiMotionDoneEvent, WATER_Unk0);
	addArrow(WATER_Unk0, evt, WATER_Unk2);
	addArrow(WATER_Unk1, saiMotionDoneEvent, WATER_Unk0);
	addArrow(WATER_Unk1, evt, WATER_Unk2);
	addArrow(WATER_Unk2, saiMotionDoneEvent, WATER_Die);
}

/**
 * @todo: Documentation
 */
bool WaterAI::CollideChar::satisfy(AICreature* item)
{
	if (item->mCollidingCreature->mObjType == OBJTYPE_Navi) {
		seSystem->playPlayerSe(SE_PLAYER_TOUCHHONEY);
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
void WaterAI::Die::act(AICreature* item)
{
	item->kill(false);
}

/**
 * @todo: Documentation
 */
FallWaterAI::FallWaterAI()
{
	create(FALLWATER_COUNT);
	addState(FALLWATER_Unk0, 1);
	addState(FALLWATER_Unk1, 0);
	addState(FALLWATER_Collide, PANI_NO_MOTION, new CollideInit);
	addState(FALLWATER_Emit, PANI_NO_MOTION, new EmitInit);
	addState(FALLWATER_Disappear, PANI_NO_MOTION, new DisappearInit);

	addArrow(FALLWATER_Unk0, saiMotionDoneEvent, FALLWATER_Unk1);
	addArrow(FALLWATER_Unk1, saiBounceEvent, FALLWATER_Collide);
	addArrow(FALLWATER_Unk1, saiGroundEvent, FALLWATER_Collide);
	addArrow(FALLWATER_Collide, saiMotionAction0Event, FALLWATER_Emit);
	addArrow(FALLWATER_Emit, saiMotionDoneEvent, FALLWATER_Disappear);
}

/**
 * @todo: Documentation
 */
void FallWaterAI::CollideInit::act(AICreature* item)
{
	item->finishMotion(29.0f);
	seSystem->playSoundDirect(1, SE_KURIONE_WATER, item->mSRT.t);
}

/**
 * @todo: Documentation
 */
void FallWaterAI::EmitInit::act(AICreature* item)
{
	PRINT("emit init !\n");
	Creature* obj = itemMgr->birth(OBJTYPE_Water);
	if (obj) {
		PRINT("water born\n");
		obj->init(item->mSRT.t);
		obj->startAI(0);
	}
}

/**
 * @todo: Documentation
 */
void FallWaterAI::DisappearInit::act(AICreature* item)
{
	item->kill(false);
}
