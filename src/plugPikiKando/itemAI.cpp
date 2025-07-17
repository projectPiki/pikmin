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

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(33)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("itemAI")

/*
 * --INFO--
 * Address:	800EECE8
 * Size:	00033C
 */
SluiceAI::SluiceAI()
{
	SAIUserEvent* evt1 = new SAIUserEvent(0);
	SAIUserEvent* evt2 = new SAIUserEvent(1);
	create(Sluice_COUNT);
	addState(Sluice_Init, -1, new SluiceAI::Init, nullptr, nullptr);
	addState(Sluice_WaitInit, -1, new SluiceAI::WaitInit, nullptr, nullptr);
	addState(Sluice_AddCount, -1, new SluiceAI::AddCount, nullptr, nullptr);
	addState(Sluice_ChangeInit, -1, new SluiceAI::ChangeInit, nullptr, nullptr);
	addState(Sluice_MotionDone, -1, new SluiceAI::MotionDone, nullptr, nullptr);
	addState(Sluice_DamageInit, -1, new SluiceAI::DamageInit, nullptr, nullptr);

	addArrow(Sluice_ChangeInit, saiMotionDoneEvent, Sluice_MotionDone);
	addArrow(Sluice_ChangeInit, evt1, Sluice_AddCount);

	addArrow(Sluice_AddCount, evt1, Sluice_AddCount);
	addArrow(Sluice_AddCount, saiMotionDoneEvent, Sluice_MotionDone);

	addArrow(Sluice_WaitInit, evt1, Sluice_ChangeInit);
	addArrow(Sluice_WaitInit, evt2, Sluice_DamageInit);

	addArrow(Sluice_DamageInit, evt1, Sluice_ChangeInit);
	addArrow(Sluice_DamageInit, saiMotionDoneEvent, Sluice_WaitInit);
}

/*
 * --INFO--
 * Address:	800EF024
 * Size:	00003C
 */
void SluiceAI::Init::act(AICreature* item)
{
	item->mCounter = 0;
	item->mStateMachine->transit(item, Sluice_WaitInit);
}

/*
 * --INFO--
 * Address:	800EF060
 * Size:	00006C
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

/*
 * --INFO--
 * Address:	800EF0CC
 * Size:	000010
 */
void SluiceAI::AddCount::act(AICreature* item)
{
	PRINT("GATE ** COUNTER became %d\n", item->mCounter);
	item->mCounter++;
}

/*
 * --INFO--
 * Address:	800EF0DC
 * Size:	00008C
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

/*
 * --INFO--
 * Address:	800EF168
 * Size:	00008C
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

/*
 * --INFO--
 * Address:	800EF1F4
 * Size:	00006C
 */
void SluiceAI::DamageInit::act(AICreature* item)
{
	BuildingItem* obj = (BuildingItem*)item;

	if (obj->mCurrStage < obj->mNumStages) {
		item->setMotionSpeed(30.0f);
		item->startMotion(obj->mCurrAnimId + 3);
	}
}

/*
 * --INFO--
 * Address:	800EF260
 * Size:	00050C
 */
PikiHeadAI::PikiHeadAI()
{
	create(PIKIHEAD_COUNT);
	addState(PIKIHEAD_Unk13, 0, nullptr, nullptr, nullptr);
	addState(PIKIHEAD_Bounce, 6, new BounceSound, nullptr, nullptr);
	addState(PIKIHEAD_Bury2, -1, new BuryInit2, new BuryExec2, nullptr);
	addState(PIKIHEAD_Flying, 0, new FlyingEffect, new FlyingExec, new FlyingCleanup);
	addState(PIKIHEAD_Bury, -1, new BuryInit, new BuryExec, nullptr);
	addState(PIKIHEAD_Tane, -1, new TaneInit, new TaneExec, nullptr);
	addState(PIKIHEAD_Unk5, 2, nullptr, nullptr, nullptr);
	addState(PIKIHEAD_Wait, 3, new WaitInit, new WaitExec, nullptr);
	addState(PIKIHEAD_Unk7, 4, nullptr, nullptr, nullptr);
	addState(PIKIHEAD_Growuped, -1, new GrowupedExec, nullptr, nullptr);
	addState(PIKIHEAD_Grow, -1, new GrowEffect, nullptr, nullptr);
	addState(PIKIHEAD_Unk10, 5, nullptr, nullptr, nullptr);
	addState(PIKIHEAD_Kareta, -1, new KaretaInit, new KaretaExec, nullptr);
	addState(PIKIHEAD_Dead, -1, new Dead, nullptr, nullptr);

	addArrow(PIKIHEAD_Flying, saiBounceEvent, PIKIHEAD_Bounce);
	addArrow(PIKIHEAD_Bounce, saiMotionDoneEvent, PIKIHEAD_Bury);
	addArrow(PIKIHEAD_Unk5, saiMotionDoneEvent, PIKIHEAD_Wait);
	addArrow(PIKIHEAD_Unk7, saiMotionAction0Event, PIKIHEAD_Growuped);
	addArrow(PIKIHEAD_Growuped, saiMotionDoneEvent, PIKIHEAD_Wait);
	addArrow(PIKIHEAD_Unk10, saiMotionDoneEvent, PIKIHEAD_Kareta);
}

/*
 * --INFO--
 * Address:	800EF76C
 * Size:	000114
 */
void PikiHeadAI::BounceSound::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	CollTriInfo* tri = mapMgr->getCurrTri(item->mPosition.x, item->mPosition.z, true);
	if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
		item->startWaterEffect();
		effectMgr->create(EffectMgr::EFF_P_Bubbles, item->mPosition, nullptr, nullptr);
		if (obj->_3E0) {
			item->playEventSound(obj->_3E0, SE_PIKI_GROW0_WATER);
		} else {
			seSystem->playPikiSound(SEF_PIKI_GROW0_WATER, obj->mPosition);
		}
		return;
	}

	effectMgr->create(EffectMgr::EFF_SD_DirtCloud, item->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_SD_DirtSpray, item->mPosition, nullptr, nullptr);
	if (obj->_3E0) {
		item->playEventSound(obj->_3E0, SE_PIKI_GROW0);
	} else {
		PRINT("******** SEF_PIKI_GROW0 !!!! %d !!!!!\n", seSystem->getJacID(SEF_PIKI_GROW0));
		seSystem->playPikiSound(SEF_PIKI_GROW0, obj->mPosition);
	}
}

/*
 * --INFO--
 * Address:	800EF880
 * Size:	000044
 */
void PikiHeadAI::FlyingEffect::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->_3E4.init(obj->mPosition, EffectMgr::EFF_SD_Sparkle);
	obj->finishFix();
}

/*
 * --INFO--
 * Address:	800EF8C4
 * Size:	000028
 */
void PikiHeadAI::FlyingExec::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->_3E4.updatePos(obj->mPosition);
}

/*
 * --INFO--
 * Address:	800EF8EC
 * Size:	000024
 */
void PikiHeadAI::FlyingCleanup::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->_3E4.kill();
}

/*
 * --INFO--
 * Address:	800EF910
 * Size:	00000C
 */
void PikiHeadAI::BuryInit2::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->mFlowerStage = Leaf;
}

/*
 * --INFO--
 * Address:	800EF91C
 * Size:	000034
 */
void PikiHeadAI::BuryExec2::act(AICreature* item)
{
	PRINT("to save or not to save ....\n"); // Alright mr shakespeare over here

	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->mStateMachine->transit(item, PIKIHEAD_Dead);
}

/*
 * --INFO--
 * Address:	800EF950
 * Size:	000088
 */
void PikiHeadAI::BuryInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;
	obj->startFix();
	obj->mFlowerStage       = Leaf;
	obj->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._38C() + gsys->getRand(1.0f) * 2.0f;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800EF9D8
 * Size:	000080
 */
void PikiHeadAI::BuryExec::act(AICreature* item)
{
	// stupid but fixes a regswap
	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		item->startMotion(1);
		item->mStateMachine->transit(item, PIKIHEAD_Tane);
	}
}

/*
 * --INFO--
 * Address:	800EFA58
 * Size:	000074
 */
void PikiHeadAI::TaneInit::act(AICreature* item)
{
	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._39C() + gsys->getRand(1.0f) * 2.0f;
}

/*
 * --INFO--
 * Address:	800EFACC
 * Size:	000058
 */
void PikiHeadAI::TaneExec::act(AICreature* item)
{
	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		item->mStateMachine->transit(item, PIKIHEAD_Unk5);
	}
}

/*
 * --INFO--
 * Address:	800EFB24
 * Size:	0000D8
 */
void PikiHeadAI::WaitInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	if (obj->mFlowerStage == Flower) {
		item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3BC() + gsys->getRand(1.0f) * 2.0f;
	} else {
		item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3AC() + gsys->getRand(1.0f) * 2.0f;
	}
	item->mCounter = 0;
}

/*
 * --INFO--
 * Address:	800EFBFC
 * Size:	000130
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
		Vector3f pos = obj->mPosition;
		pos.y += 13.0f;
		EffectParm parm(pos);
		utEffectMgr->cast(KandoEffect::PikiGrowup1, parm);
		obj->mCounter = 1;
	}
}

/*
 * --INFO--
 * Address:	800EFD2C
 * Size:	000148
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
		seSystem->playPikiSound(soundsB[obj->mFlowerStage], obj->mPosition);
	}

	Vector3f pos = item->mPosition;
	pos.y += 13.0f;
	EffectParm parm(pos);
	utEffectMgr->cast(KandoEffect::PikiGrowup2, parm);
}

/*
 * --INFO--
 * Address:	800EFE74
 * Size:	000034
 */
void PikiHeadAI::GrowEffect::act(AICreature* item)
{
	item->mStateMachine->transit(item, PIKIHEAD_Wait);
}

/*
 * --INFO--
 * Address:	800EFEA8
 * Size:	00007C
 */
void PikiHeadAI::KaretaInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3CC() + 2.0f * gsys->getRand(1.0f);
	obj->mFlowerStage        = Leaf;
}

/*
 * --INFO--
 * Address:	800EFF24
 * Size:	000058
 */
void PikiHeadAI::KaretaExec::act(AICreature* item)
{
	f32& health = item->mCurrentItemHealth;
	health -= gsys->getFrameTime();
	if (health < 0.0f) {
		item->mStateMachine->transit(item, PIKIHEAD_Bury);
	}
}

/*
 * --INFO--
 * Address:	800EFF7C
 * Size:	000028
 */
void PikiHeadAI::Dead::act(AICreature* item)
{
	item->kill(false);
}

/*
 * --INFO--
 * Address:	800EFFA4
 * Size:	000390
 */
BombAI::BombAI()
{
	SAIUserEvent* evt1 = new SAIUserEvent(0);
	SAIUserEvent* evt2 = new SAIUserEvent(1);
	SAIUserEvent* evt3 = new SAIUserEvent(2);

	create(BOMB_COUNT);
	addState(BOMB_Unk0, -1, nullptr, nullptr, nullptr);
	addState(BOMB_Unk1, -1, nullptr, nullptr, nullptr);
	addState(BOMB_Set, -1, new SetInit, new SetExec, nullptr);
	addState(BOMB_Bomb, 0, new BombInit, new BombExec, nullptr);
	addState(BOMB_Mizu, -1, new MizuInit, new MizuExec, nullptr);
	addState(BOMB_Die, -1, new DieInit, new DieExec, nullptr);

	addArrow(BOMB_Unk0, evt1, BOMB_Set);
	addArrow(BOMB_Set, evt2, BOMB_Bomb);
	addArrow(BOMB_Unk0, evt2, BOMB_Bomb);
	addArrow(BOMB_Unk1, saiBounceEvent, BOMB_Bomb);
}

/*
 * --INFO--
 * Address:	800F0334
 * Size:	000080
 */
void BombAI::SetInit::act(AICreature* item)
{
	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3FC() * (gsys->getRand(1.0f) * 0.05f + 1.0f);
	item->mMaxItemHealth     = item->mCurrentItemHealth;
	PRINT("BOMB * %f/%f\n", item->mCurrentItemHealth, item->mMaxItemHealth);

	if (item->mObjType != OBJTYPE_Bomb) {
		ERROR("this is not bomb %s\n", "setInit");
	}
}

/*
 * --INFO--
 * Address:	800F03B4
 * Size:	000070
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

/*
 * --INFO--
 * Address:	800F0424
 * Size:	000E3C
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
	f32 maxRange = pikiMgr->mPikiParms->mPikiParms._40C();
	f32 unused   = pikiMgr->mPikiParms->mPikiParms._41C();
	item->setMotionSpeed(30.0f);
	playerState->mResultFlags.setOn(RESFLAG_YellowWithBomb);
	rumbleMgr->start(RUMBLE_Unk8, 0, item->mPosition);
	EffectParm parm(item->mPosition);
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
			InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._42C(), nullptr);
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
			InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._44C(), nullptr);
			obj->stimulate(act);
		}
	}

	Iterator tekiIt(tekiMgr);
	CI_LOOP(tekiIt)
	{
		Creature* obj = *tekiIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z);
			if (dist - maxRange - obj->getBoundingSphereRadius() > 0.0f) {
				continue;
			}
			PRINT("checkCollisionSpecial start <\n");
			CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mPosition, maxRange, &cnd);
			PRINT("checkCollisionSpecial done >\n");
			if (part) {
				PRINT("part found \n");
				obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms._43C(), part));
			} else {
				if (centreDist(item, obj) - maxRange - obj->getCentreSize() < 0.0f) {
					obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms._43C(), nullptr));
				}
			}
		}
	}

	Iterator bossIt(bossMgr);
	CI_LOOP(bossIt)
	{
		Creature* obj = *bossIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z);
			if (dist - maxRange - obj->getBoundingSphereRadius() > 0.0f) {
				continue;
			}
			PRINT("checkCollisionSpecial start <\n");
			CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mPosition, maxRange, &cnd);
			PRINT("checkCollisionSpecial done >\n");
			InteractBomb bomb(item, pikiMgr->mPikiParms->mPikiParms._43C(), part);
			if (part) {
				PRINT("part found \n");
				obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms._43C(), part));
			} else {
				if (centreDist(item, obj) - maxRange - obj->getCentreSize() < 0.0f) {
					obj->stimulate(InteractBomb(item, pikiMgr->mPikiParms->mPikiParms._43C(), nullptr));
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
				Vector3f dir    = child->mCentre - item->mPosition;
				f32 dist        = dir.length() - child->mRadius - item->getCentreSize();
				if (dist < minDist) {
					minDist = dist;
				}
			}
		} else {
			minDist = circleDist(item, obj) - obj->getCentreSize();
		}
		InteractBomb bomb(item, pikiMgr->mPikiParms->mPikiParms._42C(), nullptr);
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
			InteractBomb bomb(item, pikiMgr->mPikiParms->mPikiParms._41C(), nullptr);
			c->stimulate(bomb);
		}
	}

	PRINT("all done\n");
}

/*
 * --INFO--
 * Address:	800F1260
 * Size:	000034
 */
void BombAI::BombExec::act(AICreature* item)
{
	item->mStateMachine->transit(item, BOMB_Die);
}

/*
 * --INFO--
 * Address:	800F1294
 * Size:	00000C
 */
void BombAI::MizuInit::act(AICreature* item)
{
	item->mCurrentItemHealth = 1.0f;
}

/*
 * --INFO--
 * Address:	800F12A0
 * Size:	000080
 */
void BombAI::MizuExec::act(AICreature* item)
{
	item->mCurrentItemHealth -= gsys->getFrameTime();
	PRINT("bomb in water ! %f\n", item->mCurrentItemHealth);
	f32 health = item->mCurrentItemHealth;
	if (health <= 0.0f) {
		item->mStateMachine->transit(item, BOMB_Die);
	}
	item->mScale.set(health, health, health);
}

/*
 * --INFO--
 * Address:	800F1320
 * Size:	000024
 */
void BombAI::DieInit::act(AICreature* item)
{
	item->mCurrentItemHealth = 5.0f;
	item->mScale.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	800F1344
 * Size:	00007C
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

/*
 * --INFO--
 * Address:	800F13C0
 * Size:	0003E0
 */
GoalAI::GoalAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);
	NotFinished* nf   = new NotFinished;

	create(GOAL_COUNT);
	addState(GOAL_Wait, -1, new WaitInit, nullptr, nullptr);
	addState(GOAL_Effect, 2, new Effect, nullptr, nullptr);
	addState(GOAL_Unk2, 0, nullptr, nullptr, nullptr);
	addState(GOAL_EmitPiki, -1, new EmitPiki, nullptr, nullptr);
	addState(GOAL_EmitWait, -1, nullptr, new EmitWait, nullptr);
	addState(GOAL_BootInit, -1, new BootInit, nullptr, nullptr);
	addState(GOAL_BootEmit, -1, new BootEmit, nullptr, new BootDone);

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

/*
 * --INFO--
 * Address:	800F17A0
 * Size:	000028
 */
bool GoalAI::NotFinished::satisfy(AICreature* item)
{
	if (item->mCurrAnimId > 0 || item->mCounter > 0) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800F17C8
 * Size:	0000B8
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

/*
 * --INFO--
 * Address:	800F1880
 * Size:	000038
 */
void GoalAI::BootInit::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;
	item->startMotion(obj->mOnionColour + 3);
}

/*
 * --INFO--
 * Address:	800F18B8
 * Size:	000460
 */
void GoalAI::BootEmit::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;

	PikiHeadItem* seed = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
	if (seed) {
		GameStat::bornPikis.inc(obj->mOnionColour);
		Vector3f pos = item->mPosition;
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
		f32 dist           = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z);
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
			f32 dist   = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z);
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
		}
	}

	PRINT("try again\n");
	act(item);
	STACK_PAD_VAR(3);
}

/*
 * --INFO--
 * Address:	800F1D18
 * Size:	000004
 */
void GoalAI::BootDone::act(AICreature* item)
{
}

/*
 * --INFO--
 * Address:	800F1D1C
 * Size:	00032C
 */
void GoalAI::EmitPiki::act(AICreature* item)
{
	GoalItem* obj = (GoalItem*)item;

	if (item->mCounter > 0) {
		Vector3f pos = item->mPosition;
		pos.y += 110.0f; // some dll exclusive unused stuff here
		rand();

		effectMgr->create(EffectMgr::EFF_Onyon_FireworkTrail, item->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Onyon_FireworkMain, item->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Onyon_FireworkKisek, item->mPosition, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Onyon_FireworkSmall, item->mPosition, nullptr, nullptr);
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
			Vector3f pos = obj->mPosition;
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
				gameflow.mGameInterface->message(0, 21);
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

/*
 * --INFO--
 * Address:	800F2048
 * Size:	000004
 */
void GoalAI::EmitWait::act(AICreature*)
{
}

/*
 * --INFO--
 * Address:	800F204C
 * Size:	000078
 */
void GoalAI::Effect::act(AICreature* item)
{
	Vector3f pos = item->mPosition;
	pos.y += 90.0f;
	effectMgr->create(EffectMgr::EFF_Onyon_ActEffect, pos, nullptr, nullptr);
	item->playEventSound(item, SE_CONTAINER_PELLETIN2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001AC
 */
GemAI::GemAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);

	create(GEM_COUNT);
	addState(GEM_Unk0, -1, nullptr, nullptr, nullptr);
	addState(GEM_Rise, -1, new RiseInit, new RiseExec, nullptr);
	addState(GEM_Die, -1, new Die, nullptr, nullptr);

	addArrow(GEM_Unk0, evt, GEM_Rise);
}

/*
 * --INFO--
 * Address:	800F20C4
 * Size:	0000C0
 */
void GemAI::RiseInit::act(AICreature* item)
{
	item->mCurrentItemHealth = 0.0f;
	item->mMaxItemHealth     = 1.5f;
	item->setFlag80();

	Vector3f pos = item->mPosition;
	EffectParm parm(pos);
	utEffectMgr->cast(KandoEffect::Goal, parm);
	item->playEventSound(item->mTargetCreature, SE_CONTAINER_PELLETIN);
	item->mVelocity.y = 0.0f;
	item->mCurrAnimId = 0;
}

/*
 * --INFO--
 * Address:	800F2184
 * Size:	000178
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

	Vector3f diff = item->mTargetCreature->mPosition - item->mPosition;
	diff.y        = 0.0f;
	diff.normalise();
	diff              = diff * 60.0f;
	item->mVelocity.x = diff.x;
	item->mVelocity.z = diff.z;
	item->mCurrentItemHealth += gsys->getFrameTime() * item->mVelocity.y;
	item->mVelocity.y += gsys->getFrameTime() * 720.0f;

	f32 div = item->mCurrentItemHealth / 74.0f;
	f32 b   = 1.0f - div * 1.0f;
	item->mScale.set(b, b, b);
	if (div >= 1.0f) {
		item->mStateMachine->transit(item, GEM_Die);
		GameStat::getPellets.inc();
	}
}

/*
 * --INFO--
 * Address:	800F22FC
 * Size:	000098
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

/*
 * --INFO--
 * Address:	800F2394
 * Size:	000254
 */
WaterAI::WaterAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);

	create(WATER_COUNT);
	addState(WATER_Unk0, 0, nullptr, nullptr, nullptr);
	addState(WATER_Unk1, 1, nullptr, nullptr, nullptr);
	addState(WATER_Unk2, 3, nullptr, nullptr, nullptr);
	addState(WATER_Unk3, 2, nullptr, nullptr, nullptr);
	addState(WATER_Die, -1, new Die, nullptr, nullptr);

	addArrow(WATER_Unk3, saiMotionDoneEvent, WATER_Unk0);
	addArrow(WATER_Unk0, saiCollideEvent, WATER_Unk1)->mCondition.add(new CollideChar);
	addArrow(WATER_Unk0, saiMotionDoneEvent, WATER_Unk0);
	addArrow(WATER_Unk0, evt, WATER_Unk2);
	addArrow(WATER_Unk1, saiMotionDoneEvent, WATER_Unk0);
	addArrow(WATER_Unk1, evt, WATER_Unk2);
	addArrow(WATER_Unk2, saiMotionDoneEvent, WATER_Die);
}

/*
 * --INFO--
 * Address:	800F25E8
 * Size:	000040
 */
bool WaterAI::CollideChar::satisfy(AICreature* item)
{
	if (item->mCollidingCreature->mObjType == OBJTYPE_Navi) {
		seSystem->playPlayerSe(SE_PLAYER_TOUCHHONEY);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800F2628
 * Size:	000028
 */
void WaterAI::Die::act(AICreature* item)
{
	item->kill(false);
}

/*
 * --INFO--
 * Address:	800F2650
 * Size:	0001D8
 */
FallWaterAI::FallWaterAI()
{
	create(FALLWATER_COUNT);
	addState(FALLWATER_Unk0, 1, nullptr, nullptr, nullptr);
	addState(FALLWATER_Unk1, 0, nullptr, nullptr, nullptr);
	addState(FALLWATER_Collide, -1, new CollideInit, nullptr, nullptr);
	addState(FALLWATER_Emit, -1, new EmitInit, nullptr, nullptr);
	addState(FALLWATER_Disappear, -1, new DisappearInit, nullptr, nullptr);

	addArrow(FALLWATER_Unk0, saiMotionDoneEvent, FALLWATER_Unk1);
	addArrow(FALLWATER_Unk1, saiBounceEvent, FALLWATER_Collide);
	addArrow(FALLWATER_Unk1, saiGroundEvent, FALLWATER_Collide);
	addArrow(FALLWATER_Collide, saiMotionAction0Event, FALLWATER_Emit);
	addArrow(FALLWATER_Emit, saiMotionDoneEvent, FALLWATER_Disappear);
}

/*
 * --INFO--
 * Address:	800F2828
 * Size:	000054
 */
void FallWaterAI::CollideInit::act(AICreature* item)
{
	item->finishMotion(29.0f);
	seSystem->playSoundDirect(1, SE_KURIONE_WATER, item->mPosition);
}

/*
 * --INFO--
 * Address:	800F287C
 * Size:	000080
 */
void FallWaterAI::EmitInit::act(AICreature* item)
{
	PRINT("emit init !\n");
	Creature* obj = itemMgr->birth(OBJTYPE_Water);
	if (obj) {
		PRINT("water born\n");
		obj->init(item->mPosition);
		obj->startAI(0);
	}
}

/*
 * --INFO--
 * Address:	800F28FC
 * Size:	000028
 */
void FallWaterAI::DisappearInit::act(AICreature* item)
{
	item->kill(false);
}
