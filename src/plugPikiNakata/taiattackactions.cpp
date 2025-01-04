#include "Tai/AttackActions.h"
#include "teki.h"
#include "TekiPersonality.h"
#include "TekiParameters.h"
#include "TekiConditions.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "taiattackactions");
	// UNUSED FUNCTION
}

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
 * Address:	80127604
 * Size:	0000AC
 */
bool TaiAttackableNaviPikiAction::act(Teki& teki)
{
	TekiAttackableCondition cond(&teki);
	Creature* naviPiki = teki.getClosestNaviPiki(cond, nullptr);
	if (!naviPiki) {
		return false;
	}

	// this needs? more inlines? somehow?
	u32 badCompiler;
	u32 badCompiler2;
	if (teki.mTargetCreatures[0].mPtr) {
		resetCreature(teki.mTargetCreatures[0].mPtr);
	}
	teki.mTargetCreatures[0].mPtr = naviPiki;
	postSetCreature(teki.mTargetCreatures[0].mPtr);

	return true;
}

/*
 * --INFO--
 * Address:	801276B0
 * Size:	00008C
 */
bool TaiAttackableNaviAction::act(Teki& teki)
{
	Navi* navi = naviMgr->getNavi();
	if (teki.attackableCreature(*navi)) {
		if (teki.mTargetCreatures[0].mPtr) {
			resetCreature(teki.mTargetCreatures[0].mPtr);
		}
		teki.mTargetCreatures[0].mPtr = navi;
		postSetCreature(teki.mTargetCreatures[0].mPtr);
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8012773C
 * Size:	0000B8
 */
bool TaiAttackablePikiAction::act(Teki& teki)
{
	TekiAttackableCondition cond(&teki);
	Creature* nearest = pikiMgr->findClosest(teki.mPosition, &cond);
	if (!nearest) {
		return false;
	}

	if (teki.mTargetCreatures[0].mPtr) {
		resetCreature(teki.mTargetCreatures[0].mPtr);
	}
	teki.mTargetCreatures[0].mPtr = nearest;
	postSetCreature(teki.mTargetCreatures[0].mPtr);
	// sigh
	u32 badCompiler;
	u32 badCompiler2;
	return true;
}

/*
 * --INFO--
 * Address:	801277F4
 * Size:	000040
 */
void TaiAnimationSwallowingAction::start(Teki& teki)
{
	if (teki.mTargetCreatures) {
		teki.setTekiOption(BTeki::TEKI_OPTION_INVINCIBLE);
	}
}

/*
 * --INFO--
 * Address:	80127844
 * Size:	000660
 */
bool TaiAnimationSwallowingAction::act(Teki& teki)
{
	if (teki.isAnimKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		teki.flickUpper();
		Vector3f center;
		teki.outputHitCenter(center);
		TekiPikiStateCondition cond;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x280(r1)
	  stfd      f31, 0x278(r1)
	  stfd      f30, 0x270(r1)
	  stfd      f29, 0x268(r1)
	  stmw      r15, 0x224(r1)
	  mr        r31, r4
	  lwz       r0, -0x99C(r13)
	  lwz       r3, 0x414(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0x4F4
	  mr        r3, r31
	  bl        0x20574
	  lfs       f0, -0x5DF0(r2)
	  mr        r3, r31
	  addi      r4, r1, 0x210
	  stfs      f0, 0x218(r1)
	  stfs      f0, 0x214(r1)
	  stfs      f0, 0x210(r1)
	  bl        0x2017C
	  lis       r3, 0x802B
	  subi      r19, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r19, 0x204(r1)
	  addi      r18, r3, 0x6964
	  stw       r19, 0x1F8(r1)
	  lis       r3, 0x802C
	  addi      r10, r3, 0x685C
	  stw       r19, 0x1AC(r1)
	  lis       r6, 0x802D
	  lis       r5, 0x802C
	  stw       r19, 0x1B4(r1)
	  lis       r4, 0x802D
	  lis       r3, 0x802D
	  stw       r19, 0x1BC(r1)
	  subi      r16, r6, 0x2A4C
	  addi      r15, r5, 0x6890
	  stw       r18, 0x204(r1)
	  subi      r11, r4, 0x295C
	  addi      r9, r1, 0x1BC
	  stw       r19, 0x19C(r1)
	  subi      r7, r3, 0x26E8
	  addi      r3, r1, 0x204
	  stw       r19, 0x1A4(r1)
	  addi      r12, r1, 0x1AC
	  addi      r8, r1, 0x1B4
	  stw       r18, 0x1F8(r1)
	  addi      r5, r1, 0x19C
	  addi      r0, r1, 0x1A4
	  stw       r18, 0x1AC(r1)
	  li        r6, 0x16
	  li        r4, 0
	  stw       r18, 0x1B4(r1)
	  stw       r18, 0x1BC(r1)
	  stw       r10, 0x204(r1)
	  stw       r18, 0x19C(r1)
	  stw       r18, 0x1A4(r1)
	  stw       r10, 0x1F8(r1)
	  stw       r16, 0x1AC(r1)
	  stw       r15, 0x1B4(r1)
	  stw       r11, 0x1BC(r1)
	  stw       r9, 0x208(r1)
	  stw       r7, 0x19C(r1)
	  stw       r15, 0x1A4(r1)
	  stw       r3, 0x1FC(r1)
	  stw       r31, 0x1B0(r1)
	  stw       r12, 0x1B8(r1)
	  stw       r31, 0x1C0(r1)
	  stw       r8, 0x20C(r1)
	  stw       r6, 0x1A0(r1)
	  stw       r5, 0x1A8(r1)
	  stw       r0, 0x200(r1)
	  lwz       r3, 0x2C8(r31)
	  bl        0x548
	  fmr       f29, f1
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x1
	  bl        0x550
	  lwz       r3, 0x2C4(r31)
	  fmr       f30, f1
	  li        r4, 0xB
	  lwz       r3, 0x84(r3)
	  bl        -0x4780
	  lfs       f0, 0x210(r1)
	  lis       r4, 0x802D
	  subi      r0, r4, 0x28E0
	  fmr       f31, f1
	  stfs      f0, 0x17C(r1)
	  addi      r5, r1, 0x180
	  lfs       f0, 0x214(r1)
	  addi      r6, r1, 0x184
	  addi      r3, r1, 0x18C
	  stfs      f0, 0x180(r1)
	  addi      r4, r1, 0x17C
	  lfs       f0, 0x218(r1)
	  stfs      f0, 0x184(r1)
	  stw       r19, 0x188(r1)
	  lfs       f0, -0x5DF0(r2)
	  stw       r18, 0x188(r1)
	  stw       r0, 0x188(r1)
	  stfs      f0, 0x194(r1)
	  stfs      f0, 0x190(r1)
	  stfs      f0, 0x18C(r1)
	  bl        -0xCA358
	  fmuls     f0, f30, f29
	  lis       r3, 0x736C
	  addi      r30, r1, 0x1F8
	  addi      r29, r1, 0x188
	  fmuls     f0, f31, f0
	  addi      r4, r3, 0x6F74
	  li        r27, 0
	  stfs      f0, 0x198(r1)
	  li        r26, 0
	  lwz       r3, 0x220(r31)
	  bl        -0x9E300
	  mr.       r25, r3
	  beq-      .loc_0x1E4
	  mr        r3, r25
	  bl        -0x9FC90
	  mr        r26, r3

	.loc_0x1E4:
	  lis       r4, 0x802B
	  lwz       r3, 0x3120(r13)
	  subi      r0, r4, 0x3064
	  stw       r0, 0x170(r1)
	  lis       r4, 0x802B
	  subi      r0, r4, 0x328C
	  stw       r31, 0x174(r1)
	  li        r15, 0
	  addi      r24, r1, 0x170
	  stw       r0, 0x170(r1)
	  li        r23, 0
	  stw       r15, 0x178(r1)
	  bl        -0x10694
	  lwz       r12, 0x0(r30)
	  addi      r0, r3, 0
	  mr        r16, r0
	  lwz       r12, 0x8(r12)
	  addi      r3, r30, 0
	  addi      r4, r16, 0
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x264
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r16
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x264
	  li        r15, 0x1

	.loc_0x264:
	  rlwinm.   r0,r15,0,24,31
	  beq-      .loc_0x2B0
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x160(r1)
	  lis       r3, 0x802B
	  subi      r3, r3, 0x3244
	  stw       r31, 0x164(r1)
	  li        r0, 0
	  addi      r4, r1, 0x160
	  stw       r3, 0x160(r1)
	  mr        r3, r16
	  stw       r0, 0x168(r1)
	  stw       r0, 0x16C(r1)
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r23, 0x1

	.loc_0x2B0:
	  lwz       r28, 0x3068(r13)
	  li        r22, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r18, r3, 0
	  subi      r20, r5, 0x3064
	  subi      r21, r4, 0x3244
	  addi      r19, r1, 0x150
	  b         .loc_0x434

	.loc_0x2E8:
	  cmpwi     r18, -0x1
	  bne-      .loc_0x310
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r17, r3
	  b         .loc_0x32C

	.loc_0x310:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r18
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r17, r3

	.loc_0x32C:
	  cmplwi    r17, 0
	  addi      r15, r17, 0
	  beq-      .loc_0x490
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  mr        r4, r17
	  lwz       r12, 0x8(r12)
	  li        r16, 0
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x380
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r17
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x380
	  li        r16, 0x1

	.loc_0x380:
	  rlwinm.   r0,r16,0,24,31
	  beq-      .loc_0x418
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x24(r3)
	  cmpw      r27, r0
	  bge-      .loc_0x418
	  cmplwi    r25, 0
	  beq-      .loc_0x3F8
	  cmpw      r27, r26
	  bge-      .loc_0x3F8
	  addi      r4, r27, 0
	  addi      r3, r25, 0
	  addi      r27, r27, 0x1
	  bl        -0x9FE18
	  stw       r20, 0x150(r1)
	  li        r0, 0
	  addi      r4, r19, 0
	  stw       r31, 0x154(r1)
	  stw       r21, 0x150(r1)
	  stw       r0, 0x158(r1)
	  stw       r3, 0x15C(r1)
	  mr        r3, r15
	  lwz       r12, 0x0(r15)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x414

	.loc_0x3F8:
	  mr        r3, r15
	  lwz       r12, 0x0(r15)
	  mr        r4, r24
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r27, 0x1

	.loc_0x414:
	  li        r22, 0x1

	.loc_0x418:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r18
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0x434:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r18
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x45C
	  li        r0, 0x1
	  b         .loc_0x488

	.loc_0x45C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r18
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x484
	  li        r0, 0x1
	  b         .loc_0x488

	.loc_0x484:
	  li        r0, 0

	.loc_0x488:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2E8

	.loc_0x490:
	  mr        r3, r31
	  lwz       r4, -0x9B4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r23,0,24,31
	  beq-      .loc_0x4D0
	  rlwinm.   r0,r22,0,24,31
	  beq-      .loc_0x4C4
	  li        r0, 0x3
	  stw       r0, 0x338(r31)
	  b         .loc_0x63C

	.loc_0x4C4:
	  li        r0, 0x1
	  stw       r0, 0x338(r31)
	  b         .loc_0x63C

	.loc_0x4D0:
	  rlwinm.   r0,r22,0,24,31
	  beq-      .loc_0x4E4
	  li        r0, 0x2
	  stw       r0, 0x338(r31)
	  b         .loc_0x63C

	.loc_0x4E4:
	  li        r0, 0
	  stw       r0, 0x338(r31)
	  li        r3, 0x1
	  b         .loc_0x640

	.loc_0x4F4:
	  lwz       r0, -0x998(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x63C
	  addi      r3, r1, 0x1D0
	  addi      r4, r31, 0
	  bl        -0x970C8
	  addi      r16, r1, 0x1D0
	  addi      r3, r16, 0
	  lwz       r12, 0x0(r16)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r17, r3, 0
	  subi      r18, r5, 0x3064
	  subi      r15, r4, 0x328C
	  addi      r19, r1, 0x144
	  b         .loc_0x5E0

	.loc_0x540:
	  cmpwi     r17, -0x1
	  bne-      .loc_0x564
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x57C

	.loc_0x564:
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  mr        r4, r17
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x57C:
	  cmplwi    r3, 0
	  beq-      .loc_0x63C
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x5C4
	  stw       r18, 0x144(r1)
	  li        r0, 0
	  mr        r4, r19
	  stw       r31, 0x148(r1)
	  stw       r15, 0x144(r1)
	  stw       r0, 0x14C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r17, 0
	  blt-      .loc_0x5C4
	  subi      r17, r17, 0x1

	.loc_0x5C4:
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  mr        r4, r17
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r17, r3

	.loc_0x5E0:
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  mr        r4, r17
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x608
	  li        r0, 0x1
	  b         .loc_0x634

	.loc_0x608:
	  mr        r3, r16
	  lwz       r12, 0x0(r16)
	  mr        r4, r17
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x630
	  li        r0, 0x1
	  b         .loc_0x634

	.loc_0x630:
	  li        r0, 0

	.loc_0x634:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x540

	.loc_0x63C:
	  li        r3, 0

	.loc_0x640:
	  lmw       r15, 0x224(r1)
	  lwz       r0, 0x284(r1)
	  lfd       f31, 0x278(r1)
	  lfd       f30, 0x270(r1)
	  lfd       f29, 0x268(r1)
	  addi      r1, r1, 0x280
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80127EA4
 * Size:	000010
 */
void BTeki::clearTekiOption(int opt) { mTekiOptions &= ~opt; }

/*
 * --INFO--
 * Address:	80127EE4
 * Size:	00012C
 */
void TaiAnimationSwallowingAction::finish(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r3, r1, 0x28
	  stw       r30, 0x38(r1)
	  bl        -0x97278
	  addi      r31, r1, 0x28
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xB8

	.loc_0x3C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x60
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x78

	.loc_0x60:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x9C
	  bl        -0x97F54
	  cmpwi     r30, 0
	  blt-      .loc_0x9C
	  subi      r30, r30, 0x1

	.loc_0x9C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xB8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE0
	  li        r0, 0x1
	  b         .loc_0x10C

	.loc_0xE0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x108
	  li        r0, 0x1
	  b         .loc_0x10C

	.loc_0x108:
	  li        r0, 0

	.loc_0x10C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x3C

	.loc_0x114:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80128010
 * Size:	000088
 */
bool TaiBangingAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x74
	  lwz       r7, 0x4(r4)
	  lis       r5, 0x802B
	  lis       r3, 0x802B
	  lwz       r6, 0x2C4(r7)
	  subi      r5, r5, 0x3064
	  subi      r0, r3, 0x32D4
	  lwz       r3, 0x84(r6)
	  addi      r6, r1, 0x4C
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x30(r3)
	  stw       r5, 0x4C(r1)
	  stw       r7, 0x50(r1)
	  stw       r0, 0x4C(r1)
	  stfs      f0, 0x54(r1)
	  lwz       r3, 0x8(r4)
	  mr        r4, r6
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x74:
	  li        r3, 0

	.loc_0x78:
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80128098
 * Size:	0000D4
 */
bool TaiFlickAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r5, r3, 0xF68
	  lis       r3, 0x802C
	  stwu      r1, -0x68(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802C
	  stw       r31, 0x64(r1)
	  lis       r6, 0x802D
	  addi      r31, r4, 0
	  stw       r5, 0x4C(r1)
	  addi      r3, r3, 0x685C
	  subi      r7, r6, 0x2A84
	  stw       r5, 0x3C(r1)
	  addi      r4, r1, 0x4C
	  stw       r5, 0x44(r1)
	  lis       r5, 0x802D
	  subi      r6, r5, 0x295C
	  stw       r0, 0x4C(r1)
	  addi      r5, r1, 0x44
	  stw       r3, 0x4C(r1)
	  mr        r3, r31
	  stw       r0, 0x3C(r1)
	  stw       r0, 0x44(r1)
	  addi      r0, r1, 0x3C
	  stw       r7, 0x3C(r1)
	  stw       r6, 0x44(r1)
	  stw       r5, 0x50(r1)
	  stw       r31, 0x40(r1)
	  stw       r31, 0x48(r1)
	  stw       r0, 0x54(r1)
	  bl        0x20348
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x20484
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x5DE8(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x340(r31)
	  stw       r0, 0x58(r1)
	  lfd       f1, 0x58(r1)
	  fsubs     f1, f1, f2
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012816C
 * Size:	000028
 */
bool TaiTargetStickAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x418(r4)
	  cmplwi    r3, 0
	  bne-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lwz       r0, 0x184(r3)
	  sub       r0, r4, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80128194
 * Size:	000044
 */
void TaiFlickingAction::start(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0xBE70
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801281D8
 * Size:	000034
 */
void TaiFlickingAction::finish(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012820C
 * Size:	00007C
 */
bool TaiFlickingAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x44
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x68

	.loc_0x44:
	  lwz       r3, 0x414(r31)
	  lwz       r0, -0x99C(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x64
	  mr        r3, r31
	  bl        0x1FB10
	  lfs       f0, -0x5DF0(r2)
	  stfs      f0, 0x340(r31)

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80128288
 * Size:	000058
 */
bool TaiFlickingUpperAction::act(Teki& teki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r0, -0x99C(r13)
	  lwz       r4, 0x414(r4)
	  and.      r0, r4, r0
	  beq-      .loc_0x34
	  mr        r3, r31
	  bl        0x1FB34

	.loc_0x34:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0xBD8C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801282E0
 * Size:	000084
 */
bool TekiAndCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r3, 0x4(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64
	  lwz       r3, 0x8(r29)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64
	  li        r31, 0x1

	.loc_0x64:
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80128364
 * Size:	00003C
 */
bool TekiNotCondition::satisfy(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801283A0
 * Size:	000008
 */
bool TekiCondition::satisfy(Creature*) { return true; }
