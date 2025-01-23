#include "TAI/Shell.h"
#include "TAI/BasicActions.h"
#include "TAI/TimerActions.h"
#include "TAI/ReactionActions.h"
#include "RumbleMgr.h"
#include "MapMgr.h"
#include "nlib/Geometry.h"
#include "teki.h"
#include "Pellet.h"
#include "TekiConditions.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "Graphics.h"
#include "sysNew.h"
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
DEFINE_PRINT("taishell");

/*
 * --INFO--
 * Address:	80141FD0
 * Size:	000084
 */
TaiShellSoundTable::TaiShellSoundTable()
    : PaniSoundTable(5)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(SE_SHELL_CLOSE + i);
	}
}

/*
 * --INFO--
 * Address:	80142054
 * Size:	00018C
 */
TaiShellParameters::TaiShellParameters()
    : TekiParameters(SHELLPI_COUNT, SHELLPF_COUNT)
{
	int i = SHELLPI_ClosingLoopCount;
	mParameters->mIntParams->mParaInfo[i++].init("CLOSING_LOOP_COUNT", 0, 30);

	int j = SHELLPF_OpeningPeriod;
	mParameters->mFloatParams->mParaInfo[j++].init("OPENING_PERIOD", 0.0f, 30.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_ShadowType, 1);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_CullingType, 0);
	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, -1.0f);
	multiP->setF(TPF_AttackableRange, 42.0f);
	multiP->setF(TPF_ShadowSize, 10.0f);
	multiP->setF(TPF_SpawnDistance, 3.0f);
	multiP->setF(TPF_SpawnHeight, 10.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 24.0f);

	multiP->setI(SHELLPI_ClosingLoopCount, 5);
	multiP->setF(SHELLPF_OpeningPeriod, 4.0f);

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	801421E0
 * Size:	0004F4
 */
TaiShellStrategy::TaiShellStrategy(TekiParameters* params)
    : TaiStrategy(SHELLSTATE_COUNT, SHELLSTATE_Normal)
{
	TaiTypeNaviWatchResultOnAction* naviWatchAction   = new TaiTypeNaviWatchResultOnAction();
	TaiShellSetPositionAction* setPosAction           = new TaiShellSetPositionAction();
	TaiShellSaveItemPositionAction* saveItemPosAction = new TaiShellSaveItemPositionAction();
	TaiContinuousMotionAction* motionAction           = new TaiContinuousMotionAction(TAI_NO_TRANSIT, 2);
	TaiShellNaviPikiInsideAction* insideAction        = new TaiShellNaviPikiInsideAction(SHELLSTATE_Open);

	// NORMAL STATE (just chilling)
	TaiState* state0 = new TaiState(4);
	int j            = 0;
	state0->setAction(j++, setPosAction);
	state0->setAction(j++, saveItemPosAction);
	state0->setAction(j++, motionAction);
	state0->setAction(j++, insideAction); // if pikis or navis inside, transit to Open
	setState(SHELLSTATE_Normal, state0);

	motionAction                    = new TaiContinuousMotionAction(TAI_NO_TRANSIT, 10);
	TaiTimerAction* openTimerAction = new TaiTimerAction(SHELLSTATE_Warn, 0, params->getF(SHELLPF_OpeningPeriod), 0.0f);

	// OPEN STATE (opening wide)
	TaiState* state1 = new TaiState(3);
	j                = 0;
	state1->setAction(j++, setPosAction);
	state1->setAction(j++, motionAction);
	state1->setAction(j++, openTimerAction); // when open timer is done, transit to Warn
	setState(SHELLSTATE_Open, state1);

	motionAction                        = new TaiContinuousMotionAction(TAI_NO_TRANSIT, 11);
	TaiCountLoopAction* closeLoopAction = new TaiCountLoopAction(SHELLSTATE_Close, params->getI(SHELLPI_ClosingLoopCount));

	// WARN STATE (warning loops at max open before snapping shut)
	TaiState* state2 = new TaiState(3);
	j                = 0;
	state2->setAction(j++, setPosAction);
	state2->setAction(j++, closeLoopAction); // when warn loops are done, transit to Close
	state2->setAction(j++, motionAction);
	setState(SHELLSTATE_Warn, state2);

	TaiShellEatAction* eatAction = new TaiShellEatAction(SHELLSTATE_Eat);
	TaiOnceAction* onceAction    = new TaiOnceAction(SHELLSTATE_Normal);

	// CLOSE STATE (snapping shut)
	TaiState* state3 = new TaiState(3);
	j                = 0;
	state3->setAction(j++, setPosAction);
	state3->setAction(j++, eatAction);  // if things to eat, transit to Eat
	state3->setAction(j++, onceAction); // nothing to eat, transit to Normal
	setState(SHELLSTATE_Close, state3);

	motionAction = new TaiContinuousMotionAction(SHELLSTATE_Normal, 13);

	// EAT STATE (chewing pikis or navis state)
	TaiState* state4 = new TaiState(3);
	j                = 0;
	state4->setAction(j++, setPosAction);
	state4->setAction(j++, motionAction); // eat anim done, transit to Normal
	state4->setAction(j++, naviWatchAction);
	setState(SHELLSTATE_Eat, state4);
}

/*
 * --INFO--
 * Address:	801426D4
 * Size:	00008C
 */
void TaiShellStrategy::createEffect(Teki& teki, int p2)
{
	TekiStrategy::createEffect(teki, p2);
	if (effectMgr && p2 == 0) {
		NVector3f spawnPos;
		teki.outputSpawnPosition(spawnPos);
		effectMgr->create(EffectMgr::EFF_BigDustRing, spawnPos, nullptr, nullptr);
		rumbleMgr->start(4, 0, spawnPos);
	}
}

/*
 * --INFO--
 * Address:	80142760
 * Size:	0001F4
 */
void TaiShellStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Shell_Twinkle, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
	teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
	BOOL hasPart = teki.getPersonalityI(TekiPersonality::INT_Parameter0);
	int type     = TEKI_Pearl;
	if (hasPart == TRUE) {
		ID32& id = teki.mPersonality->mID;
		if (playerState->existUfoParts(id.mId)) {
			PRINT("!!!TaiShellStrategy::start:%08x:%s already exists\n", teki, id.mStringID);
			teki.mPersonality->mID.setID('none');
		} else {
			type = TEKI_Rocpe;
		}
	}

	Teki* pearl = teki.generateTeki(type);

	if (!pearl) {
		PRINT("!TaiShellStrategy::start:teki==null:%08x\n", teki);
		return;
	}

	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	ID32& id = teki.mPersonality->mID;
	PRINT("TaiShellStrategy:%08x:%d,%s\n", this, type, id.mStringID);
	pearl->mPersonality->mID.setID(id.mId);
	pearl->startAI(0); // unused, will go to default state (PEARLSTATE_Normal)

	pearl->inputPosition(spawnPos);
	pearl->setDirection(teki.getDirection());
	teki.setCreaturePointer(2, pearl);
	pearl->setCreaturePointer(0, &teki);
	teki.mPersonality->mID.setID('none');
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x50
	  stw       r30, 0x70(r1)
	  addi      r30, r3, 0
	  li        r4, 0x5C
	  lfs       f0, -0xB80(r13)
	  lfs       f1, -0xB7C(r13)
	  stfs      f0, 0x50(r1)
	  lfs       f0, -0xB78(r13)
	  stfs      f1, 0x54(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x58(r1)
	  bl        0x5A390
	  lwz       r5, 0x3D8(r31)
	  mr        r4, r31
	  stw       r3, 0x0(r5)
	  mr        r3, r30
	  bl        -0x1B328
	  mr        r3, r31
	  lwz       r4, -0x9C0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C8(r31)
	  li        r30, 0xD
	  lwz       r3, 0x34(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x10(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xE4
	  addi      r4, r4, 0x28
	  lwz       r3, 0x2F6C(r13)
	  lwz       r4, 0x0(r4)
	  bl        -0xC340C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE0
	  lwz       r5, 0x2C8(r31)
	  lis       r3, 0x6E6F
	  addi      r4, r3, 0x6E65
	  addi      r3, r5, 0x28
	  bl        -0xFE974
	  b         .loc_0xE4

	.loc_0xE0:
	  li        r30, 0xE

	.loc_0xE4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x194(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x1DC
	  addi      r3, r1, 0x5C
	  bl        -0x25A14
	  addi      r3, r31, 0
	  addi      r4, r1, 0x5C
	  bl        0x3D3C
	  lwz       r4, 0x2C8(r31)
	  lwz       r3, 0x2C8(r30)
	  addi      r4, r4, 0x28
	  lwz       r4, 0x0(r4)
	  addi      r3, r3, 0x28
	  bl        -0xFE9C8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x5C(r1)
	  lwz       r0, 0x60(r1)
	  stw       r3, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x9C(r30)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0xA0(r30)
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x184
	  beq-      .loc_0x184
	  bl        -0x5E56C
	  li        r0, 0
	  stw       r0, 0x420(r31)

	.loc_0x184:
	  stw       r30, 0x420(r31)
	  lwz       r3, 0x420(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x198
	  bl        -0x5E598

	.loc_0x198:
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x1B4
	  beq-      .loc_0x1B4
	  bl        -0x5E59C
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x1B4:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C8
	  bl        -0x5E5C8

	.loc_0x1C8:
	  lwz       r5, 0x2C8(r31)
	  lis       r3, 0x6E6F
	  addi      r4, r3, 0x6E65
	  addi      r3, r5, 0x28
	  bl        -0xFEA74

	.loc_0x1DC:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80142954
 * Size:	0000D0
 */
void TaiShellStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.moveNestPosition();
	TekiStrategy::draw(teki, gfx);
	if (teki.mParticleGenerators[0]) {
		if (!teki.getTekiOption(BTeki::TEKI_OPTION_DRAWED)) {
			teki.stopParticleGenerator(0);
		} else {
			teki.startParticleGenerator(0);
			Matrix4f invLookMtx;
			gfx.mCamera->mLookAtMtx.inverse(&invLookMtx);
			NVector3f animPos;
			teki.outputWorldAnimationPosition(animPos, 6, invLookMtx);
			teki.setParticleGeneratorPosition(0, animPos);
		}
	}
}

/*
 * --INFO--
 * Address:	80142A24
 * Size:	000038
 */
bool TaiShellSetPositionAction::act(Teki& teki)
{
	BTeki* pearl = static_cast<BTeki*>(teki.getCreaturePointer(2));
	if (pearl->getTekiOption(BTeki::TEKI_OPTION_ALIVE)) {
		setPosition(teki, pearl);
	}
	return false;
}

/*
 * --INFO--
 * Address:	80142A5C
 * Size:	000078
 */
void TaiShellSetPositionAction::setPosition(Teki& teki, Creature* pearl)
{
	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	spawnPos.y = mapMgr->getMinY(spawnPos.x, spawnPos.z, true);
	pearl->inputPosition(spawnPos);
}

/*
 * --INFO--
 * Address:	80142AD4
 * Size:	0001A8
 */
bool TaiShellSaveItemPositionAction::act(Teki& teki)
{
	if (teki.mTekiAnimator->getCounter() > teki.mTekiAnimator->getKeyValueByKeyType(2)) {
		return false;
	}

	Pellet* item = static_cast<Teki*>(teki.getCreaturePointer(2))->mPellet;

	if (!item) {
		PRINT("TaiShellSaveItemPositionAction::act:item==null:%08x\n", teki);
		return false;
	}

	NVector3f savePos;
	teki.outputSpawnPosition(savePos);
	f32 dist = savePos.distanceXZ(item->getPosition());
	if (dist >= teki.getAttackableRange()) {
		PRINT("TaiShellResetPearlAction::resetPearl:%08x:outside:%f,%f\n", teki, dist, teki.getAttackableRange());
		return false;
	}

	PRINT("TaiShellResetPearlAction::resetPearl:%08x:inside:%f,%f\n", teki, dist, teki.getAttackableRange());
	setPosition(teki, item);
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stw       r31, 0xEC(r1)
	  stw       r30, 0xE8(r1)
	  mr        r30, r4
	  stw       r29, 0xE4(r1)
	  addi      r29, r3, 0
	  lwz       r5, 0x2CC(r4)
	  li        r4, 0x2
	  lfs       f29, 0x2C(r5)
	  mr        r3, r5
	  bl        -0x2331C
	  fcmpo     cr0, f29, f1
	  ble-      .loc_0x50
	  li        r3, 0
	  b         .loc_0x180

	.loc_0x50:
	  lwz       r3, 0x420(r30)
	  lwz       r0, 0x2BC(r3)
	  cmplwi    r0, 0
	  mr        r31, r0
	  bne-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0x180

	.loc_0x6C:
	  addi      r3, r1, 0xC4
	  bl        -0x25CF0
	  addi      r3, r30, 0
	  addi      r4, r1, 0xC4
	  bl        0x3A60
	  lfs       f3, 0xCC(r1)
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0xC4(r1)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x134F38
	  lwz       r3, 0x2C8(r30)
	  fmr       f29, f1
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x1F97C
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x1F990
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x206E4
	  fmuls     f0, f30, f31
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f29, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x138
	  lwz       r3, 0x2C8(r30)
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x1F9CC
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x1F9DC
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x2072C
	  li        r3, 0
	  b         .loc_0x180

	.loc_0x138:
	  lwz       r3, 0x2C8(r30)
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x1FA08
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x1FA18
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x20768
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        .loc_0x1A8
	  li        r3, 0

	.loc_0x180:
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  lwz       r29, 0xE4(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr

	.loc_0x1A8:
	*/
}

/*
 * --INFO--
 * Address:	80142C7C
 * Size:	000078
 */
void TaiShellSaveItemPositionAction::setPosition(Teki& teki, Creature* item)
{
	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	spawnPos.y = mapMgr->getMinY(spawnPos.x, spawnPos.z, true);
	item->inputPosition(spawnPos);
}

/*
 * --INFO--
 * Address:	80142CF4
 * Size:	000104
 */
bool TaiShellNaviPikiInsideAction::act(Teki& teki)
{
	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);

	return teki.checkNaviPiki(TekiPositionDistanceCondition(spawnPos, teki.getAttackableRange()));
}

/*
 * --INFO--
 * Address:	80142DF8
 * Size:	0001D0
 */
bool TaiShellEatAction::act(Teki& teki)
{
	u32 badCompiler[6];
	// some ungodly combination of these things will fix the stack, but i cannot work out *what*

	TekiAndCondition recogAndNotStick(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickerCondition(&teki)));

	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	TekiAndCondition posDistAndAnd(&recogAndNotStick, &TekiPositionDistanceCondition(spawnPos, teki.getAttackableRange()));
	return teki.interactNaviPiki(InteractSwallow(&teki, nullptr, 0), posDistAndAnd);

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802D
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802C
	  lis       r3, 0x802B
	  stwu      r1, -0x110(r1)
	  addi      r7, r5, 0x6890
	  subi      r8, r6, 0x2A4C
	  stfd      f31, 0x108(r1)
	  addi      r5, r1, 0xB8
	  addi      r0, r1, 0xB0
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stw       r31, 0xF4(r1)
	  stw       r30, 0xF0(r1)
	  stw       r29, 0xEC(r1)
	  subi      r29, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r28, 0xE8(r1)
	  addi      r30, r3, 0x6964
	  lis       r3, 0x802C
	  stw       r29, 0xD8(r1)
	  addi      r31, r3, 0x685C
	  lis       r3, 0x802D
	  stw       r29, 0xA8(r1)
	  subi      r6, r3, 0x295C
	  addi      r28, r4, 0
	  stw       r29, 0xB0(r1)
	  addi      r4, r1, 0xA8
	  addi      r3, r1, 0xCC
	  stw       r29, 0xB8(r1)
	  stw       r30, 0xD8(r1)
	  stw       r30, 0xA8(r1)
	  stw       r30, 0xB0(r1)
	  stw       r30, 0xB8(r1)
	  stw       r31, 0xD8(r1)
	  stw       r8, 0xA8(r1)
	  stw       r7, 0xB0(r1)
	  stw       r6, 0xB8(r1)
	  stw       r5, 0xDC(r1)
	  stw       r28, 0xAC(r1)
	  stw       r4, 0xB4(r1)
	  stw       r28, 0xBC(r1)
	  stw       r0, 0xE0(r1)
	  bl        -0x26054
	  addi      r3, r28, 0
	  addi      r4, r1, 0xCC
	  bl        0x36FC
	  lwz       r3, 0x2C8(r28)
	  li        r4, 0
	  bl        -0x1B00C
	  fmr       f29, f1
	  lwz       r3, 0x2C4(r28)
	  li        r4, 0x1
	  bl        -0x1B004
	  lwz       r3, 0x2C4(r28)
	  fmr       f30, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  bl        -0x1FCD4
	  lfs       f2, 0xCC(r1)
	  lis       r4, 0x802D
	  subi      r0, r4, 0x285C
	  lfs       f0, 0xD0(r1)
	  stfs      f2, 0x88(r1)
	  fmr       f31, f1
	  addi      r5, r1, 0x8C
	  stfs      f0, 0x8C(r1)
	  addi      r6, r1, 0x90
	  addi      r3, r1, 0x98
	  lfs       f0, 0xD4(r1)
	  addi      r4, r1, 0x88
	  stfs      f0, 0x90(r1)
	  stw       r29, 0x94(r1)
	  lfs       f0, -0x5940(r2)
	  stw       r30, 0x94(r1)
	  stw       r0, 0x94(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f0, 0x9C(r1)
	  stfs      f0, 0x98(r1)
	  bl        -0xE58AC
	  lis       r3, 0x802B
	  stw       r29, 0xC0(r1)
	  subi      r0, r3, 0x3064
	  fmuls     f0, f30, f29
	  stw       r0, 0x78(r1)
	  lis       r3, 0x802B
	  subi      r3, r3, 0x3244
	  stw       r30, 0xC0(r1)
	  fmuls     f0, f31, f0
	  addi      r5, r1, 0xD8
	  stw       r28, 0x7C(r1)
	  li        r0, 0
	  addi      r6, r1, 0x94
	  stw       r3, 0x78(r1)
	  addi      r4, r1, 0x78
	  mr        r3, r28
	  stw       r31, 0xC0(r1)
	  stw       r5, 0xC4(r1)
	  addi      r5, r1, 0xC0
	  stw       r0, 0x80(r1)
	  stfs      f0, 0xA4(r1)
	  stw       r6, 0xC8(r1)
	  stw       r0, 0x84(r1)
	  bl        0x4B80
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lwz       r31, 0xF4(r1)
	  lwz       r30, 0xF0(r1)
	  lwz       r29, 0xEC(r1)
	  lwz       r28, 0xE8(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80142FC8
 * Size:	000084
 */
TaiPearlSoundTable::TaiPearlSoundTable()
    : PaniSoundTable(5)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(SE_SHELL_CLOSE + i);
	}
}

/*
 * --INFO--
 * Address:	8014304C
 * Size:	000148
 */
TaiPearlParameters::TaiPearlParameters()
    : TekiParameters(20, 50)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, 1);
	multiP->setI(TPI_CarcassSize, 3);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SpawnPelletForward, 1);

	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_CorpseSize, 5.0f);
	multiP->setF(TPF_CorpseHeight, 5.0f);
	multiP->setF(TPF_CorpseVelocityHoriz, 400.0f);
	multiP->setF(TPF_CorpseVelocityVert, 300.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	u32 badCompiler[4];
}

/*
 * --INFO--
 * Address:	80143194
 * Size:	00014C
 */
TaiRocpearlParameters::TaiRocpearlParameters()
    : TekiParameters(20, 50)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, 0);
	multiP->setI(TPI_CarcassSize, 3);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SpawnPelletForward, 1);

	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 400.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 300.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	u32 badCompiler[4];
}

/*
 * --INFO--
 * Address:	801432E0
 * Size:	00036C
 */
TaiPearlStrategy::TaiPearlStrategy(TekiParameters*)
    : TaiStrategy(PEARLSTATE_COUNT, PEARLSTATE_Normal)
{
	TaiDeadAction* deadAct               = new TaiDeadAction(PEARLSTATE_Die);
	TaiDamageAction* damageAct           = new TaiDamageAction(PEARLSTATE_Damage);
	TaiDyingAction* dyingAct             = new TaiDyingAction(0);
	TaiSpawnItemsAction* spawnItemsAct   = new TaiSpawnItemsAction();
	TaiEffectAction* effectAct           = new TaiEffectAction(EffectMgr::EFF_Shell_Boom);
	TaiPearlTresureSoundAction* soundAct = new TaiPearlTresureSoundAction();
	TaiSetOptionAction* setOptAct        = new TaiSetOptionAction(BTeki::TEKI_OPTION_SHADOW_VISIBLE, false);

	// DIE STATE (dying, time to yeet out of the clam)
	TaiState* state = new TaiState(5);
	int j           = 0;
	state->setAction(j++, soundAct);
	state->setAction(j++, spawnItemsAct);
	state->setAction(j++, dyingAct);
	state->setAction(j++, setOptAct);
	state->setAction(j++, effectAct);
	setState(PEARLSTATE_Die, state);

	TaiMotionAction* motionAct = new TaiMotionAction(TAI_NO_TRANSIT, 2);

	// NORMAL STATE (just chilling)
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, deadAct);   // if dead, transit to Die
	state->setAction(j++, damageAct); // if being damaged, transit to Damage
	state->setAction(j++, motionAct);
	setState(PEARLSTATE_Normal, state);

	TaiDamagingAction* damagingAct = new TaiDamagingAction(PEARLSTATE_Normal, 1);

	// DAMAGE STATE (being attacked)
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, deadAct);     // if dead, transit to Die
	state->setAction(j++, damagingAct); // if no longer being damaged, transit to Normal
	setState(PEARLSTATE_Damage, state);
}

/*
 * --INFO--
 * Address:	8014364C
 * Size:	000020
 */
void TaiPearlStrategy::start(Teki& teki)
{
	TaiStrategy::start(teki);
}

/*
 * --INFO--
 * Address:	8014366C
 * Size:	000064
 */
void TaiPearlTresureSoundAction::start(Teki& teki)
{
	Creature* maybeClam = teki.getCreaturePointer(0);
	if (maybeClam) {
		Teki* clam = static_cast<Teki*>(maybeClam);
		clam->playSound(SE_SHELL_TRESURE);
		clam->playSound(SE_KURIONE_HIT);
	} else {
		PRINT("TaiPearlTresureSoundAction::start:creature==null:%08x\n", teki);
	}

	u32 badCompiler[2];
}
