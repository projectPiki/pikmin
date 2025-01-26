#include "NaviState.h"
#include "NaviMgr.h"
#include "system.h"
#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"
#include "GameStat.h"
#include "ItemMgr.h"
#include "CPlate.h"
#include "GoalItem.h"
#include "teki.h"
#include "Boss.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "Kontroller.h"
#include "zen/DrawAccount.h"
#include "FlowController.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("naviDemo")

/*
 * --INFO--
 * Address:	8010B0E0
 * Size:	000478
 */
void NaviDemoSunsetState::DemoStateMachine::init(NaviDemoSunsetState*)
{
	create(36); // NOT 5 as it should be
	registerState(new GoState);
	registerState(new LookState);
	registerState(new WhistleState);
	registerState(new WaitState);
	registerState(new SitState);
}

/*
 * --INFO--
 * Address:	8010B558
 * Size:	000090
 */
void NaviDemoSunsetState::GoState::init(NaviDemoSunsetState* state)
{
	state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(0, state->mNavi), PaniMotionInfo(0));
	_14 = false;
}

/*
 * --INFO--
 * Address:	8010B5E8
 * Size:	00034C
 */
void NaviDemoSunsetState::GoState::exec(NaviDemoSunsetState* state)
{
	if (_14) {
		state->mNavi->mVelocity.multiply(0.9f);
		state->mNavi->mTargetVelocity = state->mNavi->mVelocity;
		return;
	}

	Vector3f diff = (state->mGoalPos - state->mNavi->mPosition);
	f32 dist      = std::sqrtf(diff.x * diff.x + diff.z * diff.z);
	f32 nrm       = diff.normalise() / state->_2C;

	if (nrm > 0.7f && nrm < 0.71f && gsys->getRand(1.0f) >= 0.999f) {
		_14 = true;
		state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(20, state->mNavi), PaniMotionInfo(20));
		_10 = (int)(gsys->getRand(1.0f) * 4.0f) + 2;
		return;
	}

	if (dist <= 5.0f) {
		state->mNavi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		transit(state, 1);
	} else {
		f32 test                = nrm * 0.6f + 0.4f;
		f32 speed               = C_NAVI_PROP(state->mNavi)._CC();
		state->mNavi->mPosition = diff * speed * test;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stw       r31, 0xBC(r1)
	  mr        r31, r3
	  stw       r30, 0xB8(r1)
	  stw       r29, 0xB4(r1)
	  stw       r28, 0xB0(r1)
	  addi      r28, r4, 0
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r3, 0x10(r28)
	  lfs       f1, -0x6188(r2)
	  lfsu      f0, 0x70(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0x10(r28)
	  lwz       r3, 0x70(r4)
	  lwz       r0, 0x74(r4)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x78(r4)
	  stw       r0, 0xAC(r4)
	  b         .loc_0x324

	.loc_0x84:
	  lwz       r3, 0x10(r28)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x20(r28)
	  lfs       f3, 0x24(r28)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x28(r28)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x90(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x90(r1)
	  lfs       f1, 0x98(r1)
	  fmuls     f4, f0, f0
	  lfs       f0, -0x6184(r2)
	  fmuls     f5, f1, f1
	  fadds     f31, f4, f5
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x130
	  fsqrte    f1, f31
	  lfd       f3, -0x6180(r2)
	  lfd       f2, -0x6178(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x5C(r1)
	  lfs       f31, 0x5C(r1)

	.loc_0x130:
	  lfs       f0, 0x94(r1)
	  fmuls     f0, f0, f0
	  fadds     f0, f4, f0
	  fadds     f1, f5, f0
	  bl        -0xFDAE8
	  lfs       f0, -0x6184(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x174
	  lfs       f0, 0x90(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x98(r1)

	.loc_0x174:
	  lfs       f2, 0x2C(r28)
	  lfs       f0, -0x6170(r2)
	  fdivs     f30, f1, f2
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0x270
	  lfs       f0, -0x616C(r2)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x270
	  bl        0x10C8F4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6148(r2)
	  stw       r0, 0xAC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6164(r2)
	  stw       r0, 0xA8(r1)
	  lfs       f1, -0x6168(r2)
	  lfd       f3, 0xA8(r1)
	  lfs       f0, -0x6160(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x270
	  li        r0, 0x1
	  stb       r0, 0x14(r31)
	  lwz       r29, 0x10(r28)
	  cmplwi    r29, 0
	  beq-      .loc_0x1EC
	  addi      r29, r29, 0x2B8

	.loc_0x1EC:
	  addi      r3, r1, 0x6C
	  li        r4, 0x14
	  bl        0x1377C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x74
	  li        r4, 0x14
	  bl        0x1379C
	  lwz       r6, 0x10(r28)
	  addi      r4, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r6, 0x834
	  bl        0x14264
	  bl        0x10C868
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6148(r2)
	  stw       r0, 0xAC(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6164(r2)
	  stw       r0, 0xA8(r1)
	  lfs       f1, -0x6168(r2)
	  lfd       f3, 0xA8(r1)
	  lfs       f0, -0x615C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0xA0(r1)
	  lwz       r3, 0xA4(r1)
	  addi      r0, r3, 0x2
	  stw       r0, 0x10(r31)
	  b         .loc_0x324

	.loc_0x270:
	  lfs       f0, -0x6158(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x2C0
	  lwz       r5, 0x10(r28)
	  mr        r3, r31
	  lfs       f0, -0x2688(r13)
	  addi      r4, r28, 0
	  addi      r6, r5, 0xA4
	  stfs      f0, 0xA4(r5)
	  li        r5, 0x1
	  lfs       f0, -0x2684(r13)
	  stfs      f0, 0x4(r6)
	  lfs       f0, -0x2680(r13)
	  stfs      f0, 0x8(r6)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x324

	.loc_0x2C0:
	  lwz       r4, 0x10(r28)
	  lfs       f0, -0x6150(r2)
	  lwz       r3, 0x224(r4)
	  fmuls     f2, f0, f30
	  lfs       f3, -0x6154(r2)
	  lfs       f0, 0x90(r1)
	  lfs       f4, 0xD8(r3)
	  lfs       f1, 0x94(r1)
	  fadds     f3, f3, f2
	  lfs       f2, 0x98(r1)
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f4
	  fmuls     f4, f2, f4
	  fmuls     f1, f1, f3
	  fmuls     f2, f0, f3
	  fmuls     f0, f4, f3
	  stfs      f2, 0x90(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0xAC(r4)

	.loc_0x324:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  lwz       r28, 0xB0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010BA1C
 * Size:	00012C
 */
void NaviDemoSunsetState::GoState::procAnimMsg(NaviDemoSunsetState* state, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 6:
		if (_14) {
			_10--;
			state->mNavi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			state->mNavi->mVelocity.set(0.0f, 0.0f, 0.0f);
			if (_10 <= 0) {
				state->mNavi->mNaviAnimMgr.finishMotion(state->mNavi);
			}
		}
		break;
	case 0:
		state->mNavi->mNaviAnimMgr.startMotion(PaniMotionInfo(2, state->mNavi), PaniMotionInfo(2));
		_14 = false;
		break;
	}
}

/*
 * --INFO--
 * Address:	8010BB48
 * Size:	000004
 */
void NaviDemoSunsetState::GoState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BB4C
 * Size:	000084
 */
void NaviDemoSunsetState::LookState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(65, state->mNavi), PaniMotionInfo(65));
	cameraMgr->mCamera->finishMotion();
}

/*
 * --INFO--
 * Address:	8010BBD0
 * Size:	000004
 */
void NaviDemoSunsetState::LookState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BBD4
 * Size:	000004
 */
void NaviDemoSunsetState::LookState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BBD8
 * Size:	00007C
 */
void NaviDemoSunsetState::LookState::procAnimMsg(NaviDemoSunsetState* state, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 0:
		if (GameStat::allPikis == 0) {
			transit(state, DEMOSTATE_Sit);
		} else {
			transit(state, DEMOSTATE_Whistle);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	8010BC54
 * Size:	00009C
 */
void NaviDemoSunsetState::WhistleState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(49, state->mNavi), PaniMotionInfo(49));
	_10           = 0;
	flowCont._23C = 1;
}

/*
 * --INFO--
 * Address:	8010BCF0
 * Size:	000004
 */
void NaviDemoSunsetState::WhistleState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010BCF4
 * Size:	0000C0
 */
void NaviDemoSunsetState::WhistleState::procAnimMsg(NaviDemoSunsetState* state, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case 6:
		_10++;
		if (_10 == 8) {
			enterAllPikis(state);
		}
		if (_10 == 16) {
			state->mNavi->mNaviAnimMgr.finishMotion(state->mNavi);
		}
		break;
	case 0:
		transit(state, 3);
		break;
	}
}

/*
 * --INFO--
 * Address:	8010BDB4
 * Size:	0002C8
 */
void NaviDemoSunsetState::WhistleState::enterAllPikis(NaviDemoSunsetState* state)
{
	GoalItem* goals[3];

	Navi* navi = state->mNavi;
	Iterator it(itemMgr);
	CI_LOOP(it)
	{
		GoalItem* goal = (GoalItem*)*it;
		if (goal->mObjType == OBJTYPE_Goal) {
			goals[goal->mOnionColour] = goal;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (!goals[i]) {
			char buf[256];
			sprintf(buf, "no goal (%d)", i);
			PRINT("no goal %d\n", i);
		}
	}

	Piki* pikiList[200];
	int pikis = 0;
	Iterator it2(navi->mPlateMgr);
	CI_LOOP(it2)
	{
		Piki* piki = (Piki*)*it2;
		if (piki->isAlive()) {
			pikiList[pikis++] = piki;
		}
	}

	for (int i = 0; i < pikis; i++) {
		if (pikiList[i]->mColor >= 3) {
			PRINT("COLOR ID = %d\n", pikiList[i]->mColor);
			char buf[256];
			sprintf(buf, "COLOR %d !!", pikiList[i]->mColor);
			ERROR(buf);
		}

		navi->mGoalItem = goals[pikiList[i]->mColor];
		pikiList[i]->changeMode(11, nullptr);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x590(r1)
	  stmw      r26, 0x578(r1)
	  lwz       r29, 0x30AC(r13)
	  lwz       r31, 0x10(r4)
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  addi      r28, r1, 0x23C
	  b         .loc_0xA8

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x8C
	  lhz       r0, 0x428(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r28, r0

	.loc_0x8C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xA8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD0
	  li        r0, 0x1
	  b         .loc_0xFC

	.loc_0xD0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF8
	  li        r0, 0x1
	  b         .loc_0xFC

	.loc_0xF8:
	  li        r0, 0

	.loc_0xFC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lis       r3, 0x802C
	  addi      r27, r1, 0x23C
	  addi      r28, r3, 0x1AC8
	  li        r26, 0

	.loc_0x114:
	  lwz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x134
	  addi      r4, r28, 0
	  crclr     6, 0x6
	  addi      r5, r26, 0
	  addi      r3, r1, 0x130
	  bl        0x10A6B4

	.loc_0x134:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r27, r27, 0x4
	  blt+      .loc_0x114
	  lwz       r29, 0x710(r31)
	  li        r30, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r3, 0
	  addi      r28, r1, 0x254
	  b         .loc_0x1EC

	.loc_0x16C:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x190
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1A8

	.loc_0x190:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1A8:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D0
	  rlwinm    r0,r30,2,0,29
	  stwx      r26, r28, r0
	  addi      r30, r30, 0x1

	.loc_0x1D0:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1EC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x214
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x214:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x23C
	  li        r0, 0x1
	  b         .loc_0x240

	.loc_0x23C:
	  li        r0, 0

	.loc_0x240:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x16C
	  lis       r3, 0x802C
	  addi      r27, r1, 0x254
	  addi      r28, r3, 0x1AD8
	  addi      r29, r1, 0x23C
	  li        r26, 0
	  b         .loc_0x2AC

	.loc_0x260:
	  lwz       r3, 0x0(r27)
	  lhz       r5, 0x510(r3)
	  cmplwi    r5, 0x3
	  blt-      .loc_0x280
	  addi      r4, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x24
	  bl        0x10A568

	.loc_0x280:
	  lwz       r3, 0x0(r27)
	  li        r4, 0xB
	  li        r5, 0
	  lhz       r0, 0x510(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r29, r0
	  stw       r0, 0x708(r31)
	  lwz       r3, 0x0(r27)
	  bl        -0x3EE88
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x1

	.loc_0x2AC:
	  cmpw      r26, r30
	  blt+      .loc_0x260
	  lmw       r26, 0x578(r1)
	  lwz       r0, 0x594(r1)
	  addi      r1, r1, 0x590
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010C07C
 * Size:	000004
 */
void NaviDemoSunsetState::WhistleState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C080
 * Size:	000078
 */
void NaviDemoSunsetState::WaitState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(3, state->mNavi), PaniMotionInfo(3));
}

/*
 * --INFO--
 * Address:	8010C0F8
 * Size:	000004
 */
void NaviDemoSunsetState::WaitState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C0FC
 * Size:	000004
 */
void NaviDemoSunsetState::WaitState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C100
 * Size:	000078
 */
void NaviDemoSunsetState::SitState::init(NaviDemoSunsetState* state)
{
	state->mNavi->startMotion(PaniMotionInfo(50, state->mNavi), PaniMotionInfo(50));
}

/*
 * --INFO--
 * Address:	8010C178
 * Size:	000004
 */
void NaviDemoSunsetState::SitState::exec(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C17C
 * Size:	000004
 */
void NaviDemoSunsetState::SitState::cleanup(NaviDemoSunsetState*)
{
}

/*
 * --INFO--
 * Address:	8010C180
 * Size:	0000D4
 */
NaviDemoSunsetState::NaviDemoSunsetState()
    : NaviState(NAVISTATE_DemoSunset)
{
	mStateMachine = new DemoStateMachine;
	mStateMachine->init(this);
}

/*
 * --INFO--
 * Address:	8010C254
 * Size:	000200
 */
void NaviDemoSunsetState::init(Navi* navi)
{
	seMgr->setPikiNum(0);
	seMgr->playNaviSound(0, 0);
	mNavi         = navi;
	mCurrentState = nullptr;
	mStateMachine->transit(this, DEMOSTATE_Go);
	mStartPos.set(0.0f, 0.0f, 0.0f);
	mGoalPos.set(400.0f, 0.0f, 0.0f);

	Iterator it(itemMgr);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (obj->mObjType == OBJTYPE_SunsetStart) {
			mStartPos = obj->mPosition;
		} else if (obj->mObjType == OBJTYPE_SunsetGoal) {
			mGoalPos = obj->mPosition;
		}
	}

	setActors(navi);
	_30 = 30.0f;
	cameraMgr->mCamera->startMotion(*(PcamMotionInfo*)((int)cameraMgr->mCamera + 0x38)); // I really dont want to figure out this struct yet
	mOpenedAccount = false;
}

/*
 * --INFO--
 * Address:	8010C454
 * Size:	0004A0
 */
void NaviDemoSunsetState::setActors(Navi* navi)
{
	navi->mPosition = mStartPos;

	Vector3f dist    = mGoalPos - mStartPos;
	_2C              = dist.normalise();
	navi->mDirection = atan2f(dist.x, dist.z);
	navi->makeCStick(false);

	Iterator it(navi->mPlateMgr);
	CI_LOOP(it)
	{
		Piki* piki        = (Piki*)*it;
		ActCrowd* act     = (ActCrowd*)piki->mActiveAction->getCurrAction();
		Vector3f newpos   = navi->mPlateMgr->mSlotList[act->mCPlateSlotID].mPosition + navi->mPlateMgr->mPlateCenter;
		piki->mPosition   = newpos;
		piki->mPosition.y = mapMgr->getMinY(piki->mPosition.x, piki->mPosition.z, true);
	}

	Iterator it3(pikiMgr);
	CI_LOOP(it3)
	{
		Piki* piki = (Piki*)*it3;
		if (piki->mMode != 1 || piki->getState() == 14) {
			piki->mEraseKill = true;
			piki->kill(false);
			it3.dec();
		}
	}

	tekiMgr->store();
	itemMgr->store();
	tekiMgr->killAll();
	bossMgr->killAll();

	Iterator it2(itemMgr);
	CI_LOOP(it2)
	{
		Creature* item = *it3;
		if (item->mObjType != OBJTYPE_Pikihead && item->mObjType != OBJTYPE_Goal && item->mObjType != OBJTYPE_Fulcrum
		    && item->mObjType != OBJTYPE_Rope) {
			item->kill(false);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stw       r31, 0xDC(r1)
	  stw       r30, 0xD8(r1)
	  stw       r29, 0xD4(r1)
	  mr        r29, r4
	  stw       r28, 0xD0(r1)
	  mr        r28, r3
	  lwz       r3, 0x14(r3)
	  lwz       r0, 0x18(r28)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x1C(r28)
	  stw       r0, 0x9C(r4)
	  lfs       f3, 0x20(r28)
	  lfs       f2, 0x14(r28)
	  lfs       f1, 0x24(r28)
	  fsubs     f31, f3, f2
	  lfs       f0, 0x18(r28)
	  lfs       f2, 0x28(r28)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x1C(r28)
	  fsubs     f30, f2, f0
	  fmuls     f1, f31, f31
	  fmuls     f0, f3, f3
	  fmuls     f2, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xFE890
	  lfs       f0, -0x6184(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x94
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1

	.loc_0x94:
	  stfs      f1, 0x2C(r28)
	  fmr       f1, f31
	  fmr       f2, f30
	  bl        0x10F504
	  stfs      f1, 0xA0(r29)
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0xE118
	  lwz       r31, 0x710(r29)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x1D0

	.loc_0xD4:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xFC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x118

	.loc_0xFC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x118:
	  lwz       r3, 0x4F8(r28)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x130
	  li        r3, 0
	  b         .loc_0x13C

	.loc_0x130:
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x13C:
	  lwz       r6, 0x710(r29)
	  li        r4, 0x1
	  lwz       r0, 0x58(r3)
	  lwz       r5, 0x80(r6)
	  rlwinm    r3,r0,5,0,26
	  lfsu      f0, 0x94(r6)
	  addi      r3, r3, 0xC
	  add       r3, r5, r3
	  lfs       f1, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x4(r6)
	  fadds     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x8(r6)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lwz       r3, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r3, 0x94(r28)
	  stw       r0, 0x98(r28)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x9C(r28)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r28)
	  lfs       f2, 0x9C(r28)
	  bl        -0xA46FC
	  stfs      f1, 0x98(r28)
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1D0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x1F8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
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
	  beq+      .loc_0xD4
	  lwz       r28, 0x3068(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x2E4

	.loc_0x24C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x270
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x288

	.loc_0x270:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x288:
	  lhz       r0, 0x4FC(r3)
	  addi      r30, r3, 0
	  cmplwi    r0, 0x1
	  bne-      .loc_0x2A8
	  mr        r3, r30
	  bl        -0x4419C
	  cmpwi     r3, 0xE
	  bne-      .loc_0x2C8

	.loc_0x2A8:
	  li        r0, 0x1
	  stb       r0, 0x584(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x81A2C
	  cmpwi     r29, 0
	  blt-      .loc_0x2C8
	  subi      r29, r29, 0x1

	.loc_0x2C8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x2E4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x30C
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x30C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x24C
	  lwz       r3, 0x3160(r13)
	  bl        -0x2C234
	  lwz       r3, 0x30AC(r13)
	  bl        -0x2C23C
	  lwz       r3, 0x3160(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0x30AC(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x41C

	.loc_0x398:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x3BC
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3D4

	.loc_0x3BC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3D4:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xF
	  beq-      .loc_0x400
	  cmpwi     r0, 0x10
	  beq-      .loc_0x400
	  cmpwi     r0, 0x11
	  beq-      .loc_0x400
	  cmpwi     r0, 0x12
	  beq-      .loc_0x400
	  li        r4, 0
	  bl        -0x81B70

	.loc_0x400:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x41C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x444
	  li        r0, 0x1
	  b         .loc_0x470

	.loc_0x444:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x46C
	  li        r0, 0x1
	  b         .loc_0x470

	.loc_0x46C:
	  li        r0, 0

	.loc_0x470:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x398
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  lwz       r29, 0xD4(r1)
	  lwz       r28, 0xD0(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010C8F4
 * Size:	000160
 */
void NaviDemoSunsetState::exec(Navi* navi)
{
	navi->findNextThrowPiki();
	navi->makeCStick(true);
	navi->_738 = 0.0f;
	mStateMachine->exec(this);
	_30 -= gsys->getFrameTime();

	if (_30 < 0.0f || (_30 <= 15.0f && navi->mKontroller->keyClick(0x107f000))) {
		flowCont._240 = 1;
		cleanup(navi);
		return;
	}

	if (mOpenedAccount) {
		return;
	}

	if (!(_30 <= 20.0f)) {
		return;
	}

	zen::AccountData data(GameStat::minPikis, GameStat::maxPikis, GameStat::deadPikis, GameStat::killTekis, GameStat::getPellets);
	accountWindow->start(data);
	mOpenedAccount = true;
}

/*
 * --INFO--
 * Address:	8010CA94
 * Size:	000218
 */
void NaviDemoSunsetState::cleanup(Navi* navi)
{
	Iterator it(pikiMgr);
	CI_LOOP(it)
	{
		Piki* piki = (Piki*)*it;
		if (piki && piki->isAlive()) {
			Iterator it2(itemMgr);
			CI_LOOP(it2)
			{
				GoalItem* item = (GoalItem*)*it2;
				if (item->mObjType == OBJTYPE_Goal && item->mOnionColour == piki->mColor) {
					item->enterGoal(piki);
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8010CCAC
 * Size:	000034
 */
void NaviDemoSunsetState::procAnimMsg(Navi* navi, MsgAnim* msg)
{
	mStateMachine->procMsg(this, msg);
}
