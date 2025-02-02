#include "ItemAI.h"
#include "PikiHeadItem.h"
#include "BombItem.h"
#include "GoalItem.h"
#include "GemItem.h"
#include "Collision.h"
#include "MapMgr.h"
#include "MapCode.h"
#include "BuildingItem.h"
#include "PikiMgr.h"
#include "Interface.h"
#include "BaseInf.h"
#include "teki.h"
#include "gameflow.h"
#include "NaviMgr.h"
#include "FlowController.h"
#include "RumbleMgr.h"
#include "Boss.h"
#include "GameStat.h"
#include "PlayerState.h"
#include "MoviePlayer.h"
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
	create(6);
	addState(Sluice_Init, -1, new SluiceAI::Init, nullptr, nullptr);
	addState(Sluice_WaitInit, -1, new SluiceAI::WaitInit, nullptr, nullptr);
	addState(Sluice_AddCount, -1, new SluiceAI::AddCount, nullptr, nullptr);
	addState(Sluice_ChangeInit, -1, new SluiceAI::ChangeInit, nullptr, nullptr);
	addState(Sluice_MotionDone, -1, new SluiceAI::MotionDone, nullptr, nullptr);
	addState(Sluice_DamageInit, -1, new SluiceAI::DamageInit, nullptr, nullptr);

	addArrow(2, saiMotionDoneEvent, 4);
	addArrow(2, evt1, 3);
	addArrow(3, evt1, 3);
	addArrow(3, saiMotionDoneEvent, 4);
	addArrow(1, evt1, 2);
	addArrow(1, evt2, 5);
	addArrow(5, evt1, 2);
	addArrow(5, saiMotionDoneEvent, 1);
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
	PRINT("******* CHANGE INIT ******** aiContext.int=%d curr=%d\n", obj->mStartAnimId, obj->_2D0);

	item->setMotionSpeed(30.0f);
	item->startMotion(obj->_2D0);
	obj->startBreakEffect();
	if (obj->_2D0 == obj->mEndAnimId - 1) {
		obj->mWayPoint->setFlag(true);
	}
	obj->_2D0++;
}

/*
 * --INFO--
 * Address:	800EF1F4
 * Size:	00006C
 */
void SluiceAI::DamageInit::act(AICreature* item)
{
	BuildingItem* obj = (BuildingItem*)item;

	if (obj->mStartAnimId < obj->mEndAnimId) {
		item->setMotionSpeed(30.0f);
		item->startMotion(obj->_2D0 + 3);
	}
}

/*
 * --INFO--
 * Address:	800EF260
 * Size:	00050C
 */
PikiHeadAI::PikiHeadAI()
{
	create(15);
	addState(13, 0, nullptr, nullptr, nullptr);
	addState(2, 6, new BounceSound, nullptr, nullptr);
	addState(14, -1, new BuryInit2, new BuryExec2, nullptr);
	addState(0, 0, new FlyingEffect, new FlyingExec, new FlyingCleanup);
	addState(3, -1, new BuryInit, new BuryExec, nullptr);
	addState(4, -1, new TaneInit, new TaneExec, nullptr);
	addState(5, 2, nullptr, nullptr, nullptr);
	addState(6, 3, new WaitInit, new WaitExec, nullptr);
	addState(7, 4, nullptr, nullptr, nullptr);
	addState(8, -1, new GrowupedExec, nullptr, nullptr);
	addState(9, -1, new GrowEffect, nullptr, nullptr);
	addState(10, 5, nullptr, nullptr, nullptr);
	addState(11, -1, new KaretaInit, new KaretaExec, nullptr);
	addState(12, -1, new Dead, nullptr, nullptr);

	addArrow(0, saiBounceEvent, 2);
	addArrow(2, saiMotionDoneEvent, 3);
	addArrow(5, saiMotionDoneEvent, 6);
	addArrow(7, saiMotionAction0Event, 8);
	addArrow(8, saiMotionDoneEvent, 6);
	addArrow(10, saiMotionDoneEvent, 11);
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
	obj->mFlowerStage = 0;
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
	obj->mStateMachine->transit(item, 12);
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
	obj->mFlowerStage       = 0;
	obj->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._38C() + gsys->getRand(1.0f) * 2.0f;

	f32 badcompiler[2];
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
		item->mStateMachine->transit(item, 4);
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
		item->mStateMachine->transit(item, 5);
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

	if (obj->mFlowerStage == 2) {
		item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3BC() + gsys->getRand(1.0f) * 2.0f;
	} else {
		item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3AC() + gsys->getRand(1.0f) * 2.0f;
	}
	item->mCounter = 0;

	f32 badcompiler[2];
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
		if (obj->mFlowerStage == 2) {
			item->mStateMachine->transit(item, 10);
		} else {
			item->mStateMachine->transit(item, 7);
		}
	} else if (health < 2.0f && obj->mCounter == 0 && obj->mFlowerStage != 2) {
		Vector3f pos = obj->mPosition;
		pos.y += 13.0f;
		EffectParm parm(pos);
		utEffectMgr->cast(9, parm);
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

	Vector3f pos = obj->mPosition;
	pos.y += 13.0f;
	EffectParm parm(pos);
	utEffectMgr->cast(10, parm);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r6, r3, 0x2668
	  lis       r3, 0x8022
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  lis       r4, 0x5555
	  lwz       r5, 0x3D0(r31)
	  addi      r0, r4, 0x5556
	  addi      r7, r31, 0
	  addi      r5, r5, 0x1
	  mulhw     r4, r0, r5
	  rlwinm    r0,r4,1,31,31
	  add       r0, r4, r0
	  mulli     r0, r0, 0x3
	  sub       r0, r5, r0
	  stw       r0, 0x3D0(r31)
	  addi      r4, r3, 0x2674
	  lwz       r5, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x54(r1)
	  stw       r0, 0x58(r1)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x5C(r1)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x48(r1)
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x50(r1)
	  lwz       r4, 0x3E0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xA8
	  lwz       r0, 0x3D0(r7)
	  addi      r5, r1, 0x54
	  addi      r3, r7, 0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r5, r0
	  bl        -0x65818
	  b         .loc_0xC4

	.loc_0xA8:
	  lwz       r0, 0x3D0(r7)
	  addi      r4, r1, 0x48
	  lwz       r3, 0x3038(r13)
	  addi      r5, r7, 0x94
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        -0x4B9E4

	.loc_0xC4:
	  lfs       f0, 0x94(r31)
	  addi      r4, r1, 0x10
	  li        r3, 0xA
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x643C(r2)
	  stfs      f1, 0x44(r1)
	  lfs       f1, 0x40(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  lfs       f1, -0x6440(r2)
	  lwz       r6, 0x3C(r1)
	  stfs      f1, 0x18(r1)
	  lwz       r5, 0x40(r1)
	  stfs      f1, 0x14(r1)
	  lwz       r0, 0x44(r1)
	  stfs      f1, 0x10(r1)
	  lfs       f0, -0x6454(r2)
	  stfs      f1, 0x24(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f1, 0x1C(r1)
	  stw       r6, 0x10(r1)
	  stw       r5, 0x14(r1)
	  stw       r0, 0x18(r1)
	  stfs      f0, 0x34(r1)
	  bl        0x24484
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFE74
 * Size:	000034
 */
void PikiHeadAI::GrowEffect::act(AICreature* item)
{
	item->mStateMachine->transit(item, 6);
}

/*
 * --INFO--
 * Address:	800EFEA8
 * Size:	00007C
 */
void PikiHeadAI::KaretaInit::act(AICreature* item)
{
	PikiHeadItem* obj = (PikiHeadItem*)item;

	item->mCurrentItemHealth = pikiMgr->mPikiParms->mPikiParms._3CC() + gsys->getRand(1.0f) * 2.0f;
	obj->mFlowerStage        = 0;

	f32 badcompiler[2];
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
		item->mStateMachine->transit(item, 3);
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

	create(6);
	addState(0, -1, nullptr, nullptr, nullptr);
	addState(1, -1, nullptr, nullptr, nullptr);
	addState(2, -1, new SetInit, new SetExec, nullptr);
	addState(3, 0, new BombInit, new BombExec, nullptr);
	addState(4, -1, new MizuInit, new MizuExec, nullptr);
	addState(5, -1, new DieInit, new DieExec, nullptr);

	addArrow(0, evt1, 2);
	addArrow(2, evt2, 3);
	addArrow(0, evt2, 3);
	addArrow(1, saiBounceEvent, 3);
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
		item->_2D0 = 0;
		item->mStateMachine->procMsg(item, &msg);
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
	item->setMotionSpeed(30.0f);
	playerState->mResultFlags.setOn(RESFLAG_YellowWithBomb);
	rumbleMgr->start(8, 0, item->mPosition);
	EffectParm parm(item->mPosition);
	if (item->mCounter == 1) {
		utEffectMgr->cast(20, parm);
		PRINT("USE LIGHTWEIGHT BOMB EFFECT\n");
	} else {
		utEffectMgr->cast(19, parm);
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
		if ((obj->isAlive() && (obj->isVisible() || obj->getState() == 14) && dist <= maxRange) || obj->getState() != 33) {
			PRINT("piki %x got bomb interaction!\n", obj);
			InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._42C(), nullptr);
			obj->stimulate(act);
		}
	}

	Iterator tekiIt(tekiMgr);
	CI_LOOP(tekiIt)
	{
		Teki* obj = (Teki*)*tekiIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist   = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z) - maxRange;
			f32 radius = obj->getBoundingSphereRadius();
			if (dist - radius < 0.0f) {
				PRINT("checkCollisionSpecial start <\n");
				CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mPosition, maxRange, &cnd);
				PRINT("checkCollisionSpecial done >\n");
				if (part) {
					PRINT("part found \n");
					InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._43C(), part);
					obj->stimulate(act);
				} else {
					f32 dist = centreDist(item, obj) - obj->getBoundingSphereRadius();
					if (dist - maxRange < 0.0f) {
						InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._43C(), nullptr);
						obj->stimulate(act);
					}
				}
			}
		}
	}

	Iterator itemIt(itemMgr->mMeltingPotMgr);
	CI_LOOP(itemIt)
	{
		Teki* obj = (Teki*)*itemIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist   = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z) - maxRange;
			f32 radius = obj->getBoundingSphereRadius();
			if (dist - radius < 0.0f) {
				PRINT("checkCollisionSpecial start <\n");
				CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mPosition, maxRange, &cnd);
				PRINT("checkCollisionSpecial done >\n");
				if (part) {
					PRINT("part found \n");
					InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._43C(), part);
					obj->stimulate(act);
				} else {
					f32 dist = centreDist(item, obj) - obj->getBoundingSphereRadius();
					if (dist - maxRange < 0.0f) {
						InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._43C(), nullptr);
						obj->stimulate(act);
					}
				}
			}
		}
	}

	Iterator bossIt(bossMgr);
	CI_LOOP(bossIt)
	{
		Teki* obj = (Teki*)*bossIt;
		if (obj->isAlive() && obj->isVisible() && obj->mCollInfo && obj->mCollInfo->hasInfo()) {
			f32 dist   = qdist2(item->mPosition.x, item->mPosition.z, obj->mPosition.x, obj->mPosition.z) - maxRange;
			f32 radius = obj->getBoundingSphereRadius();
			if (dist - radius < 0.0f) {
				PRINT("checkCollisionSpecial start <\n");
				CollPart* part = obj->mCollInfo->checkCollisionSpecial(item->mPosition, maxRange, &cnd);
				PRINT("checkCollisionSpecial done >\n");
				if (part) {
					PRINT("part found \n");
					InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._43C(), part);
					obj->stimulate(act);
				} else {
					f32 dist = centreDist(item, obj) - obj->getBoundingSphereRadius();
					if (dist - maxRange < 0.0f) {
						InteractBomb act(item, pikiMgr->mPikiParms->mPikiParms._43C(), nullptr);
						obj->stimulate(act);
					}
				}
			}
		}
	}

	Iterator it(bossMgr);
	CI_LOOP(it)
	{
	}

	Iterator it2(bossMgr);
	CI_LOOP(it2)
	{
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2C0(r1)
	  stfd      f31, 0x2B8(r1)
	  stfd      f30, 0x2B0(r1)
	  stfd      f29, 0x2A8(r1)
	  stfd      f28, 0x2A0(r1)
	  stfd      f27, 0x298(r1)
	  stfd      f26, 0x290(r1)
	  stmw      r22, 0x268(r1)
	  addi      r31, r4, 0
	  lwz       r0, 0x3160(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xE10
	  lis       r3, 0x802C
	  lwz       r4, 0x3068(r13)
	  subi      r0, r3, 0x2150
	  lfs       f1, -0x6458(r2)
	  lis       r3, 0x802C
	  stw       r0, 0x264(r1)
	  subi      r0, r3, 0x215C
	  stw       r0, 0x264(r1)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x14C(r12)
	  lfs       f27, 0x418(r4)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x11
	  addi      r3, r3, 0x70
	  bl        -0x6CAA4
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x8
	  li        r5, 0
	  bl        0x8C91C
	  lfs       f1, -0x6440(r2)
	  lfs       f0, -0x6454(r2)
	  stfs      f1, 0x23C(r1)
	  stfs      f1, 0x238(r1)
	  stfs      f1, 0x234(r1)
	  stfs      f1, 0x248(r1)
	  stfs      f1, 0x244(r1)
	  stfs      f1, 0x240(r1)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x234(r1)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x23C(r1)
	  stfs      f0, 0x258(r1)
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xF0
	  li        r3, 0x14
	  addi      r4, r1, 0x234
	  bl        0x23DD4
	  b         .loc_0xFC

	.loc_0xF0:
	  li        r3, 0x13
	  addi      r4, r1, 0x234
	  bl        0x23DC4

	.loc_0xFC:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x14
	  addi      r3, r3, 0x54
	  bl        -0x6E068
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x12C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x14
	  lfs       f1, -0x6434(r2)
	  li        r5, 0
	  addi      r3, r3, 0x54
	  bl        -0x6DDCC

	.loc_0x12C:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x1F
	  bl        -0x65FA8
	  lfs       f0, -0x6440(r2)
	  stfs      f0, 0x2D8(r31)
	  lwz       r29, 0x3120(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802D
	  addi      r30, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  b         .loc_0x274

	.loc_0x174:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x198
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1B0

	.loc_0x198:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1B0:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x636E4
	  mr        r3, r26
	  fadds     f26, f1, f26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0x258
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  addi      r4, r1, 0x218
	  lfs       f0, 0x438(r5)
	  stw       r25, 0x218(r1)
	  stw       r31, 0x21C(r1)
	  stw       r24, 0x218(r1)
	  stfs      f0, 0x220(r1)
	  stw       r0, 0x224(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x258:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x274:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x29C
	  li        r0, 0x1
	  b         .loc_0x2C8

	.loc_0x29C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2C4
	  li        r0, 0x1
	  b         .loc_0x2C8

	.loc_0x2C4:
	  li        r0, 0

	.loc_0x2C8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x174
	  lwz       r29, 0x3068(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802D
	  addi      r30, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  b         .loc_0x420

	.loc_0x300:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x324
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x33C

	.loc_0x324:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x33C:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x63870
	  mr        r3, r26
	  fadds     f26, f1, f26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x404
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3AC
	  mr        r3, r26
	  bl        -0x28270
	  cmpwi     r3, 0xE
	  bne-      .loc_0x404

	.loc_0x3AC:
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0x404
	  mr        r3, r26
	  bl        -0x2828C
	  cmpwi     r3, 0x21
	  beq-      .loc_0x404
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  addi      r4, r1, 0x1FC
	  lfs       f0, 0x458(r5)
	  stw       r25, 0x1FC(r1)
	  stw       r31, 0x200(r1)
	  stw       r24, 0x1FC(r1)
	  stfs      f0, 0x204(r1)
	  stw       r0, 0x208(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x404:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x420:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x448
	  li        r0, 0x1
	  b         .loc_0x474

	.loc_0x448:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x470
	  li        r0, 0x1
	  b         .loc_0x474

	.loc_0x470:
	  li        r0, 0

	.loc_0x474:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x300
	  lwz       r28, 0x3160(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f28, -0x6440(r2)
	  lis       r4, 0x802D
	  addi      r27, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  addi      r30, r1, 0x16C
	  addi      r29, r1, 0x17C
	  b         .loc_0x66C

	.loc_0x4B8:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x4E0
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x4FC

	.loc_0x4E0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x4FC:
	  lwz       r12, 0x0(r26)
	  mr        r3, r26
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x650
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x650
	  lwz       r3, 0x220(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x650
	  bl        -0x66E14
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x650
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  lfs       f3, 0x94(r26)
	  lfs       f4, 0x9C(r26)
	  bl        -0xB8358
	  mr        r3, r26
	  fmr       f26, f1
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fsubs     f0, f26, f27
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f28
	  bgt-      .loc_0x650
	  fmr       f1, f27
	  lwz       r3, 0x220(r26)
	  addi      r4, r31, 0x94
	  addi      r5, r1, 0x264
	  bl        -0x67C84
	  cmplwi    r3, 0
	  beq-      .loc_0x5E0
	  lwz       r5, 0x3068(r13)
	  mr        r4, r29
	  lwz       r5, 0x68(r5)
	  lfs       f0, 0x448(r5)
	  stw       r25, 0x17C(r1)
	  stw       r31, 0x180(r1)
	  stw       r24, 0x17C(r1)
	  stfs      f0, 0x184(r1)
	  stw       r3, 0x188(r1)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x650

	.loc_0x5E0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x64FF4
	  fsubs     f0, f1, f27
	  fsubs     f0, f0, f26
	  fcmpo     cr0, f0, f28
	  bge-      .loc_0x650
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  mr        r4, r30
	  lfs       f0, 0x448(r5)
	  stw       r25, 0x16C(r1)
	  stw       r31, 0x170(r1)
	  stw       r24, 0x16C(r1)
	  stfs      f0, 0x174(r1)
	  stw       r0, 0x178(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x650:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x66C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x694
	  li        r0, 0x1
	  b         .loc_0x6C0

	.loc_0x694:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6BC
	  li        r0, 0x1
	  b         .loc_0x6C0

	.loc_0x6BC:
	  li        r0, 0

	.loc_0x6C0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4B8
	  lwz       r27, 0x3168(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f28, -0x6440(r2)
	  lis       r4, 0x802D
	  addi      r28, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  addi      r30, r1, 0x14C
	  addi      r29, r1, 0x15C
	  b         .loc_0x8BC

	.loc_0x704:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x72C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x748

	.loc_0x72C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x748:
	  lwz       r12, 0x0(r26)
	  mr        r3, r26
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A0
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A0
	  lwz       r3, 0x220(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x8A0
	  bl        -0x67060
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A0
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  lfs       f3, 0x94(r26)
	  lfs       f4, 0x9C(r26)
	  bl        -0xB85A4
	  mr        r3, r26
	  fmr       f26, f1
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fsubs     f0, f26, f27
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f28
	  bgt-      .loc_0x8A0
	  fmr       f1, f27
	  lwz       r3, 0x220(r26)
	  addi      r4, r31, 0x94
	  addi      r5, r1, 0x264
	  bl        -0x67ED0
	  lwz       r4, 0x3068(r13)
	  cmplwi    r3, 0
	  lwz       r4, 0x68(r4)
	  addi      r4, r4, 0x448
	  beq-      .loc_0x830
	  lfs       f0, 0x0(r4)
	  mr        r4, r29
	  stw       r25, 0x15C(r1)
	  stw       r31, 0x160(r1)
	  stw       r24, 0x15C(r1)
	  stfs      f0, 0x164(r1)
	  stw       r3, 0x168(r1)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x8A0

	.loc_0x830:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x65244
	  fsubs     f0, f1, f27
	  fsubs     f0, f0, f26
	  fcmpo     cr0, f0, f28
	  bge-      .loc_0x8A0
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  mr        r4, r30
	  lfs       f0, 0x448(r5)
	  stw       r25, 0x14C(r1)
	  stw       r31, 0x150(r1)
	  stw       r24, 0x14C(r1)
	  stfs      f0, 0x154(r1)
	  stw       r0, 0x158(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x8A0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x8BC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8E4
	  li        r0, 0x1
	  b         .loc_0x910

	.loc_0x8E4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x90C
	  li        r0, 0x1
	  b         .loc_0x910

	.loc_0x90C:
	  li        r0, 0

	.loc_0x910:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x704
	  lwz       r3, 0x30AC(r13)
	  lwz       r27, 0x68(r3)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f29, -0x6440(r2)
	  lis       r4, 0x802D
	  lfd       f30, -0x6428(r2)
	  lfd       f31, -0x6420(r2)
	  addi      r28, r3, 0
	  subi      r30, r5, 0x3064
	  subi      r25, r4, 0x2614
	  lis       r29, 0x666C
	  b         .loc_0xBB4

	.loc_0x95C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x980
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x998

	.loc_0x980:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x998:
	  lwz       r5, 0x6C(r3)
	  li        r4, 0x1
	  lfs       f26, -0x6430(r2)
	  addi      r26, r3, 0
	  cmpwi     r5, 0x16
	  addi      r3, r4, 0
	  addi      r0, r4, 0
	  beq-      .loc_0x9C4
	  cmpwi     r5, 0x17
	  beq-      .loc_0x9C4
	  li        r0, 0

	.loc_0x9C4:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x9D8
	  cmpwi     r5, 0x18
	  beq-      .loc_0x9D8
	  li        r3, 0

	.loc_0x9D8:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x9EC
	  cmpwi     r5, 0x19
	  beq-      .loc_0x9EC
	  li        r4, 0

	.loc_0x9EC:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xAF0
	  lwz       r3, 0x220(r26)
	  addi      r4, r29, 0x6167
	  bl        -0x67710
	  addi      r23, r3, 0
	  li        r22, 0
	  b         .loc_0xADC

	.loc_0xA0C:
	  addi      r3, r23, 0
	  addi      r4, r22, 0
	  bl        -0x6904C
	  lfs       f2, 0x98(r31)
	  mr        r24, r3
	  lfs       f3, 0x8(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f28, f2, f0
	  fcmpo     cr0, f28, f29
	  ble-      .loc_0xAAC
	  fsqrte    f1, f28
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f28, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f28, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f28, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0xE4(r1)
	  lfs       f28, 0xE4(r1)

	.loc_0xAAC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r24)
	  fsubs     f0, f28, f0
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f26
	  bge-      .loc_0xAD8
	  fmr       f26, f0

	.loc_0xAD8:
	  addi      r22, r22, 0x1

	.loc_0xADC:
	  mr        r3, r23
	  bl        -0x69174
	  cmpw      r22, r3
	  blt+      .loc_0xA0C
	  b         .loc_0xB18

	.loc_0xAF0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x64024
	  fsubs     f26, f1, f26

	.loc_0xB18:
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r4, 0x68(r4)
	  lfs       f0, 0x438(r4)
	  stw       r30, 0x1AC(r1)
	  stw       r31, 0x1B0(r1)
	  stw       r25, 0x1AC(r1)
	  stfs      f0, 0x1B4(r1)
	  stw       r0, 0x1B8(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB98
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB98
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0xB98
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  addi      r4, r1, 0x1AC
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xB98:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xBB4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBDC
	  li        r0, 0x1
	  b         .loc_0xC08

	.loc_0xBDC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xC04
	  li        r0, 0x1
	  b         .loc_0xC08

	.loc_0xC04:
	  li        r0, 0

	.loc_0xC08:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x95C
	  lwz       r27, 0x30AC(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802D
	  addi      r28, r3, 0
	  subi      r29, r5, 0x3064
	  subi      r26, r4, 0x2614
	  b         .loc_0xDB4

	.loc_0xC40:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xC68
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0xC84

	.loc_0xC68:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0xC84:
	  addi      r22, r24, 0
	  addi      r3, r22, 0
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r22, 0
	  bl        -0x641BC
	  cmplw     r24, r31
	  fsubs     f26, f1, f26
	  beq-      .loc_0xD98
	  lwz       r0, 0x6C(r24)
	  li        r23, 0
	  cmpwi     r0, 0xE
	  bne-      .loc_0xD0C
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0xD0C
	  lwz       r12, 0x0(r24)
	  mr        r3, r24
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x5
	  beq-      .loc_0xD54
	  cmpwi     r0, 0x4
	  beq-      .loc_0xD54
	  cmpwi     r0, 0x3
	  beq-      .loc_0xD54
	  li        r23, 0x1
	  b         .loc_0xD54

	.loc_0xD0C:
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD54
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD54
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0xD54
	  li        r23, 0x1

	.loc_0xD54:
	  rlwinm.   r0,r23,0,24,31
	  beq-      .loc_0xD98
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r22, 0
	  lwz       r5, 0x68(r4)
	  addi      r4, r1, 0x18C
	  lfs       f0, 0x428(r5)
	  stw       r29, 0x18C(r1)
	  stw       r31, 0x190(r1)
	  stw       r26, 0x18C(r1)
	  stfs      f0, 0x194(r1)
	  stw       r0, 0x198(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xD98:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xDB4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDDC
	  li        r0, 0x1
	  b         .loc_0xE08

	.loc_0xDDC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xE04
	  li        r0, 0x1
	  b         .loc_0xE08

	.loc_0xE04:
	  li        r0, 0

	.loc_0xE08:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xC40

	.loc_0xE10:
	  lmw       r22, 0x268(r1)
	  lwz       r0, 0x2C4(r1)
	  lfd       f31, 0x2B8(r1)
	  lfd       f30, 0x2B0(r1)
	  lfd       f29, 0x2A8(r1)
	  lfd       f28, 0x2A0(r1)
	  lfd       f27, 0x298(r1)
	  lfd       f26, 0x290(r1)
	  addi      r1, r1, 0x2C0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F1260
 * Size:	000034
 */
void BombAI::BombExec::act(AICreature* item)
{
	item->mStateMachine->transit(item, 5);
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
		item->mStateMachine->transit(item, 5);
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

	create(7);
	addState(0, -1, new WaitInit, nullptr, nullptr);
	addState(1, 2, new Effect, nullptr, nullptr);
	addState(2, 0, nullptr, nullptr, nullptr);
	addState(3, -1, new EmitPiki, nullptr, nullptr);
	addState(4, -1, nullptr, new EmitWait, nullptr);
	addState(5, -1, new BootInit, nullptr, nullptr);
	addState(6, -1, new BootEmit, nullptr, new BootDone);

	addArrow(0, evt, 1);
	addArrow(1, saiMotionDoneEvent, 2);
	addArrow(2, evt, 1);
	addArrow(2, saiMotionLoopEndEvent, 3);
	addArrow(3, evt, 1);
	addArrow(3, saiMotionLoopStartEvent, 4)->mCondition.add(nf);
	addArrow(3, saiMotionDoneEvent, 0);
	addArrow(4, evt, 1);
	addArrow(4, saiMotionDoneEvent, 0);
	addArrow(4, saiMotionLoopEndEvent, 3)->mCondition.add(nf);
	addArrow(5, saiMotionAction0Event, 6);
	addArrow(6, saiMotionDoneEvent, 0);
}

/*
 * --INFO--
 * Address:	800F17A0
 * Size:	000028
 */
bool GoalAI::NotFinished::satisfy(AICreature* item)
{
	if (item->_2D0 > 0 || item->mCounter > 0) {
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
	int anim      = obj->mItemAnimator.getCurrentMotionIndex();
	if (anim >= 6 && anim <= 8) {
		ERROR("wait and takeoff\n");
		return;
	}
	if (obj->getTotalStorePikis() > 0) {
		obj->startMotion(12);
		obj->setMotionSpeed(30.0f);
	} else {
		obj->startMotion(1);
		obj->setMotionSpeed(30.0f);
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r0, 0x3B0(r4)
	  cmpwi     r0, 0x6
	  blt-      .loc_0x28
	  cmpwi     r0, 0x8
	  ble-      .loc_0xA4

	.loc_0x28:
	  lwz       r4, 0x434(r31)
	  lwz       r0, 0x430(r31)
	  lwz       r3, 0x42C(r31)
	  add       r0, r0, r4
	  add.      r0, r3, r0
	  ble-      .loc_0x74
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0xC
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, -0x6458(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA4

	.loc_0x74:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0x1
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, -0x6458(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl

	.loc_0xA4:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
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
		static_cast<SimpleAI*>(seed->mStateMachine)->start(seed, 0);
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
		pikiInfMgr.incPiki(oldSeed->mSeedColor, 0);
		itemMgr->getContainer(oldSeed->mSeedColor)->mHeldPikis[0]++;
		GameStat::containerPikis.inc(oldSeed->mSeedColor);
		GameStat::update();
		oldSeed->kill(false);
		GameStat::workPikis.dec(oldSeed->mSeedColor);
		return;
	}

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
		itemMgr->getContainer(oldPiki->mColor)->mHeldPikis[oldPiki->mHappa]++;
		GameStat::containerPikis.inc(oldPiki->mColor);
		GameStat::update();
		PRINT("far Piki was killed ** color%d\n", oldPiki->mColor);
		oldPiki->setEraseKill();
		oldPiki->kill(false);
	}

	act(item);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stmw      r26, 0x70(r1)
	  mr        r29, r3
	  mr        r30, r4
	  li        r4, 0xF
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r27, r3
	  beq-      .loc_0x124
	  lhz       r4, 0x428(r30)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1EAC
	  rlwinm    r3,r4,2,0,29
	  add       r5, r0, r3
	  lwz       r4, 0x0(r5)
	  addi      r3, r27, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r5)
	  addi      r4, r1, 0x64
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x9C(r30)
	  lfs       f0, -0x6414(r2)
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x68(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lhz       r4, 0x428(r30)
	  bl        -0x4EC0
	  bl        0x12670C
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0x12A1E4
	  lfs       f0, -0x6410(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x12A368
	  lfs       f0, -0x6410(r2)
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  fmuls     f0, f0, f1
	  li        r5, 0xCC
	  stfs      f0, 0x70(r27)
	  lfs       f0, -0x3274(r13)
	  stfs      f0, 0x74(r27)
	  stfs      f31, 0x78(r27)
	  bl        -0x673F4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r30, 0x3E0(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r3, 0x2E8(r27)
	  bl        -0x7427C
	  b         .loc_0x444

	.loc_0x124:
	  lwz       r3, 0x30AC(r13)
	  li        r31, 0
	  lfs       f30, -0x6440(r2)
	  lwz       r28, 0x64(r3)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x1D0

	.loc_0x150:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x174
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x18C

	.loc_0x174:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x18C:
	  mr        r26, r3
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f4, 0x9C(r30)
	  bl        -0xB9430
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x1B4
	  fmr       f30, f1
	  mr        r31, r26

	.loc_0x1B4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1D0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x1F8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x220
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x220:
	  li        r0, 0

	.loc_0x224:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x150
	  cmplwi    r31, 0
	  beq-      .loc_0x2B4
	  lis       r3, 0x803D
	  lwz       r4, 0x3CC(r31)
	  addi      r3, r3, 0x1DF0
	  li        r5, 0
	  bl        -0x2C2E4
	  lwz       r3, 0x30AC(r13)
	  lwz       r4, 0x3CC(r31)
	  bl        0xEB0
	  lwz       r5, 0x42C(r3)
	  lis       r4, 0x803D
	  addi      r0, r4, 0x1EA0
	  addi      r4, r5, 0x1
	  stw       r4, 0x42C(r3)
	  lwz       r3, 0x3CC(r31)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x20A28
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x66E64
	  lwz       r4, 0x3CC(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E88
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  b         .loc_0x42C

	.loc_0x2B4:
	  lwz       r27, 0x3068(r13)
	  li        r31, 0
	  lfs       f30, -0x6440(r2)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x35C

	.loc_0x2DC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x300
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x318

	.loc_0x300:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x318:
	  mr        r26, r3
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f4, 0x9C(r30)
	  bl        -0xB95BC
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x340
	  fmr       f30, f1
	  mr        r31, r26

	.loc_0x340:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x35C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x384
	  li        r0, 0x1
	  b         .loc_0x3B0

	.loc_0x384:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3AC
	  li        r0, 0x1
	  b         .loc_0x3B0

	.loc_0x3AC:
	  li        r0, 0

	.loc_0x3B0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2DC
	  cmplwi    r31, 0
	  beq-      .loc_0x42C
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  addi      r4, r31, 0
	  bl        -0x2C4A0
	  lwz       r3, 0x30AC(r13)
	  lhz       r4, 0x510(r31)
	  bl        0xD28
	  lwz       r5, 0x520(r31)
	  lis       r4, 0x803D
	  addi      r0, r4, 0x1EA0
	  rlwinm    r4,r5,2,0,29
	  add       r4, r3, r4
	  lwz       r3, 0x42C(r4)
	  addi      r3, r3, 0x1
	  stw       r3, 0x42C(r4)
	  lhz       r3, 0x510(r31)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x20894
	  li        r0, 0x1
	  stb       r0, 0x584(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x67000

	.loc_0x42C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x444:
	  lmw       r26, 0x70(r1)
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
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

	if (item->_2D0 > 0) {
		if (item->mObjType != OBJTYPE_Goal) {
			char buf[256];
			sprintf(buf, "%d : not goal", item->mObjType);
			ERROR(buf);
		}
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
		static_cast<SimpleAI*>(seed->mStateMachine)->start(seed, 0);
	} else {
		pikiInfMgr.incPiki(obj->mOnionColour, 0);
		obj->mHeldPikis[0]++;
		GameStat::containerPikis.inc(obj->mOnionColour);
		GameStat::update();
		if (!gameflow.mMoviePlayer->mIsActive && !playerState->_1B6
		    && !playerState->mDemoFlags.isFlag(flowCont.mCurrentStage->mStageID + DEMOFLAG_PikminLimitOffset)) {
			playerState->mDemoFlags.setFlagOnly(flowCont.mCurrentStage->mStageID + DEMOFLAG_PikminLimitOffset);
			gameflow.mGameInterface->message(0, 21);
		}
	}

	obj->_2D0--;
	if (obj->_2D0 == 0 && obj->mCounter == 0) {
		obj->finishMotion();
	}

	f32 badcompiler[8];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stw       r31, 0x174(r1)
	  mr        r31, r4
	  stw       r30, 0x170(r1)
	  stw       r29, 0x16C(r1)
	  lwz       r0, 0x2D4(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0xA0
	  bl        0x126324
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x9E
	  li        r6, 0
	  li        r7, 0
	  bl        0xAADD4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x9F
	  li        r6, 0
	  li        r7, 0
	  bl        0xAADBC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xA0
	  li        r6, 0
	  li        r7, 0
	  bl        0xAADA4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xA1
	  li        r6, 0
	  li        r7, 0
	  bl        0xAAD8C
	  lwz       r3, 0x2D4(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2D4(r31)

	.loc_0xA0:
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x2DC
	  lwz       r5, 0x6C(r31)
	  cmpwi     r5, 0x10
	  beq-      .loc_0xCC
	  lis       r3, 0x802C
	  crclr     6, 0x6
	  subi      r4, r3, 0x26E8
	  addi      r3, r1, 0x44
	  bl        0x1247B4

	.loc_0xCC:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0xF
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x428(r31)
	  lis       r4, 0x803D
	  mr.       r29, r3
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r4, 0x1EAC
	  add       r5, r0, r5
	  lwz       r4, 0x0(r5)
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r5)
	  beq-      .loc_0x208
	  lfs       f0, 0x94(r31)
	  mr        r3, r29
	  addi      r4, r1, 0x38
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x6414(r2)
	  stfs      f1, 0x40(r1)
	  lfs       f1, 0x3C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C(r1)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lhz       r4, 0x428(r31)
	  bl        -0x53D0
	  bl        0x1261FC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6448(r2)
	  stw       r0, 0x164(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6450(r2)
	  stw       r0, 0x160(r1)
	  lfs       f2, -0x6454(r2)
	  lfd       f1, 0x160(r1)
	  lfs       f0, -0x640C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x644C(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x129C9C
	  lfs       f0, -0x6410(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x129E20
	  lfs       f0, -0x6410(r2)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  fmuls     f0, f0, f1
	  li        r5, 0xCC
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x3270(r13)
	  stfs      f0, 0x74(r29)
	  stfs      f31, 0x78(r29)
	  bl        -0x6793C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r31, 0x3E0(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r3, 0x2E8(r29)
	  bl        -0x747C4
	  b         .loc_0x2D0

	.loc_0x208:
	  lis       r3, 0x803D
	  lhz       r4, 0x428(r31)
	  addi      r3, r3, 0x1DF0
	  li        r5, 0
	  bl        -0x2C71C
	  lwz       r4, 0x42C(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1EA0
	  addi      r3, r4, 0x1
	  stw       r3, 0x42C(r31)
	  lhz       r3, 0x428(r31)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x205FC
	  lis       r3, 0x803A
	  subi      r30, r3, 0x2848
	  lwz       r3, 0x1DC(r30)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2D0
	  lwz       r5, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x2D0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r29, r3, 0xA8
	  lwz       r4, 0xA8(r3)
	  addi      r3, r5, 0x54
	  lhz       r4, 0x26(r4)
	  addi      r4, r4, 0x15
	  bl        -0x6FAE8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2D0
	  lwz       r3, 0x0(r29)
	  lwz       r5, 0x2F6C(r13)
	  lhz       r4, 0x26(r3)
	  addi      r3, r5, 0x54
	  addi      r4, r4, 0x15
	  bl        -0x6F87C
	  lwz       r3, 0x1E8(r30)
	  li        r4, 0
	  li        r5, 0x15
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D0:
	  lwz       r3, 0x2D0(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2D0(r31)

	.loc_0x2DC:
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x308
	  lwz       r0, 0x2D4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x308
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x134(r12)
	  mtlr      r12
	  blrl

	.loc_0x308:
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
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

	create(3);
	addState(0, -1, nullptr, nullptr, nullptr);
	addState(1, -1, new RiseInit, new RiseExec, nullptr);
	addState(2, -1, new Die, nullptr, nullptr);

	addArrow(0, evt, 1);
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
	utEffectMgr->cast(0, parm);
	item->playEventSound(item->mTargetCreature, SE_CONTAINER_PELLETIN);
	item->mVelocity.y = 0.0f;
	item->_2D0        = 0;
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

	if (item->_2D0 == 0) {
		item->_2D0 = 1;
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
		item->mStateMachine->transit(item, 2);
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
	goal->_2D0 += seeds;

	if (obj->mStateMachine) {
		obj->mStateMachine->procMsg(obj, &msg);
	}
	obj->_3E4 = 0;
	obj->kill(false);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r4, 0x2C0(r4)
	  lwz       r0, 0x3E0(r31)
	  lhz       r3, 0x428(r4)
	  cmpw      r3, r0
	  bne-      .loc_0x30
	  lwz       r3, 0x3F8(r31)
	  b         .loc_0x34

	.loc_0x30:
	  lwz       r3, 0x3FC(r31)

	.loc_0x34:
	  li        r0, 0xA
	  stw       r0, 0x14(r1)
	  li        r0, 0
	  stw       r0, 0x18(r1)
	  lwz       r0, 0x2D0(r4)
	  add       r0, r0, r3
	  stw       r0, 0x2D0(r4)
	  lwz       r3, 0x2E8(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lwz       r12, 0x0(r3)
	  addi      r5, r1, 0x14
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  li        r0, 0
	  stb       r0, 0x3E4(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x6769C
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2394
 * Size:	000254
 */
WaterAI::WaterAI()
{
	SAIUserEvent* evt = new SAIUserEvent(0);

	create(5);
	addState(0, 0, nullptr, nullptr, nullptr);
	addState(1, 1, nullptr, nullptr, nullptr);
	addState(2, 3, nullptr, nullptr, nullptr);
	addState(3, 2, nullptr, nullptr, nullptr);
	addState(4, -1, new Die, nullptr, nullptr);

	addArrow(3, saiMotionDoneEvent, 0);
	addArrow(0, saiCollideEvent, 1)->mCondition.add(new CollideChar);
	addArrow(0, saiMotionDoneEvent, 0);
	addArrow(0, evt, 2);
	addArrow(1, saiMotionDoneEvent, 0);
	addArrow(1, evt, 2);
	addArrow(2, saiMotionDoneEvent, 4);
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
	create(5);
	addState(0, 1, nullptr, nullptr, nullptr);
	addState(1, 0, nullptr, nullptr, nullptr);
	addState(2, -1, new CollideInit, nullptr, nullptr);
	addState(3, -1, new EmitInit, nullptr, nullptr);
	addState(4, -1, new DisappearInit, nullptr, nullptr);

	addArrow(0, saiMotionDoneEvent, 1);
	addArrow(1, saiBounceEvent, 2);
	addArrow(1, saiGroundEvent, 2);
	addArrow(2, saiMotionAction0Event, 3);
	addArrow(3, saiMotionDoneEvent, 4);
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

/*
 * --INFO--
 * Address:	800F2924
 * Size:	000054
 */
bool CndBombable::satisfy(CollPart* part)
{
	if (part && part->getCode().match('**b*', '*')) {
		return true;
	}
	return false;
}
