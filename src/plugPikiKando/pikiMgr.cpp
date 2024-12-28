#include "PikiMgr.h"
#include "sysNew.h"
#include "gameflow.h"
#include "MemStat.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CDCD0
 * Size:	0000BC
 */
Creature* PikiMgr::birth()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0x1EC4
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r6, 0x30AC(r13)
	  lwz       r4, 0x8(r5)
	  lwz       r0, 0x4(r5)
	  cmplwi    r6, 0
	  lwz       r3, 0x0(r5)
	  add       r31, r0, r4
	  add       r31, r3, r31
	  beq-      .loc_0x4C
	  mr        r3, r6
	  bl        0x29954
	  add       r31, r31, r3

	.loc_0x4C:
	  lbz       r0, 0x306F(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  subi      r31, r31, 0x1

	.loc_0x5C:
	  lbz       r0, 0x306D(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r3, 0x2F80(r13)
	  lwz       r3, 0x120(r3)
	  addi      r0, r3, 0x1
	  cmpw      r31, r0
	  blt-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x84:
	  lwz       r3, 0x2F80(r13)
	  lwz       r0, 0x120(r3)
	  cmpw      r31, r0
	  blt-      .loc_0x9C
	  li        r3, 0
	  b         .loc_0xA4

	.loc_0x9C:
	  mr        r3, r30
	  bl        0x13704

	.loc_0xA4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void PikiMgr::getFormationPikis()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CDD8C
 * Size:	000258
 */
PikiMgr::PikiMgr(Navi* navi)
{
	mNavi  = navi;
	mPikiParms = new PikiProp();

	

	mLeafModel = gameflow.loadShape("pikis/happas/leaf.mod", true);
	mBudModel = gameflow.loadShape("pikis/happas/bud.mod", true);
	mFlowerModel = gameflow.loadShape("pikis/happas/flower.mod", true);
	load("parms/", "pikiMgr.bin", 1);
	memStat->start("piki mtable");
	mMotionTable = PaniPikiAnimator::createMotionTable();
	memStat->end("piki mtable");

	_5C = _54 = _58 = 0;
	_72 = _70 = 7;
	


	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  subi      r31, r5, 0x75B0
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  stw       r28, 0x50(r1)
	  addi      r28, r4, 0
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        0x13290
	  lis       r3, 0x802C
	  lwz       r4, 0x8(r1)
	  subi      r3, r3, 0x746C
	  stw       r3, 0x0(r4)
	  addi      r0, r3, 0x18
	  li        r3, 0x52C
	  stw       r0, 0x8(r4)
	  stw       r28, 0x6C(r4)
	  bl        -0x86DDC
	  addi      r30, r3, 0
	  mr.       r28, r30
	  beq-      .loc_0x198
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r30)
	  li        r0, 0
	  addi      r3, r1, 0x28
	  stw       r0, 0x0(r30)
	  subi      r4, r13, 0x41A0
	  bl        -0x7D334
	  lwz       r0, 0x28(r1)
	  addi      r5, r1, 0x24
	  lfs       f1, -0x6990(r2)
	  mr        r4, r28
	  stw       r0, 0x24(r1)
	  lfs       f2, -0x698C(r2)
	  addi      r3, r28, 0x4
	  lfs       f3, -0x6988(r2)
	  li        r6, 0
	  bl        -0x353F4
	  addi      r3, r1, 0x30
	  subi      r4, r13, 0x419C
	  bl        -0x7D368
	  lwz       r0, 0x30(r1)
	  addi      r5, r1, 0x2C
	  lfs       f1, -0x6990(r2)
	  mr        r4, r28
	  stw       r0, 0x2C(r1)
	  lfs       f2, -0x698C(r2)
	  addi      r3, r28, 0x14
	  lfs       f3, -0x6988(r2)
	  li        r6, 0
	  bl        -0x35428
	  addi      r3, r1, 0x38
	  subi      r4, r13, 0x4198
	  bl        -0x7D39C
	  lwz       r0, 0x38(r1)
	  addi      r5, r1, 0x34
	  lfs       f1, -0x6984(r2)
	  mr        r4, r28
	  stw       r0, 0x34(r1)
	  lfs       f2, -0x698C(r2)
	  addi      r3, r28, 0x24
	  lfs       f3, -0x6988(r2)
	  li        r6, 0
	  bl        -0x3545C
	  addi      r3, r1, 0x40
	  subi      r4, r13, 0x4194
	  bl        -0x7D3D0
	  lwz       r0, 0x40(r1)
	  addi      r5, r1, 0x3C
	  lfs       f1, -0x6980(r2)
	  mr        r4, r28
	  stw       r0, 0x3C(r1)
	  lfs       f2, -0x697C(r2)
	  addi      r3, r28, 0x34
	  lfs       f3, -0x6978(r2)
	  li        r6, 0
	  bl        -0x35490
	  addi      r3, r1, 0x48
	  subi      r4, r13, 0x4190
	  bl        -0x7D404
	  lwz       r0, 0x48(r1)
	  addi      r5, r1, 0x44
	  lfs       f1, -0x6974(r2)
	  mr        r4, r28
	  stw       r0, 0x44(r1)
	  lfs       f2, -0x697C(r2)
	  addi      r3, r28, 0x44
	  lfs       f3, -0x6978(r2)
	  li        r6, 0
	  bl        -0x354C4
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7358
	  stw       r0, 0x54(r30)
	  addi      r3, r28, 0x58
	  bl        .loc_0x258
	  lfs       f0, -0x6980(r2)
	  stfs      f0, 0x10(r30)

	.loc_0x198:
	  lwz       r28, 0x8(r1)
	  lis       r3, 0x803A
	  subi      r29, r3, 0x2848
	  stw       r30, 0x68(r28)
	  addi      r3, r29, 0
	  addi      r4, r31, 0xC
	  li        r5, 0x1
	  bl        -0x7B230
	  stw       r3, 0x3C(r28)
	  addi      r3, r29, 0
	  addi      r4, r31, 0x24
	  li        r5, 0x1
	  bl        -0x7B244
	  stw       r3, 0x40(r28)
	  addi      r3, r29, 0
	  addi      r4, r31, 0x3C
	  li        r5, 0x1
	  bl        -0x7B258
	  stw       r3, 0x44(r28)
	  addi      r3, r28, 0x8
	  addi      r5, r31, 0x54
	  subi      r4, r13, 0x418C
	  li        r6, 0x1
	  bl        -0x8D8E0
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r31, 0x60
	  bl        -0x47854
	  bl        0x4AD74
	  stw       r3, 0x64(r28)
	  addi      r4, r31, 0x60
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x47758
	  li        r4, 0
	  stw       r4, 0x58(r28)
	  li        r0, 0x7
	  addi      r3, r28, 0
	  stw       r4, 0x54(r28)
	  stw       r4, 0x5C(r28)
	  sth       r0, 0x70(r28)
	  sth       r0, 0x72(r28)
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr

	.loc_0x258:
	*/
}

/*
 * --INFO--
 * Address:	800CDFE4
 * Size:	000D90
 */
PikiProp::Parms::Parms()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x4F0(r1)
	  stw       r31, 0x4EC(r1)
	  addi      r31, r3, 0
	  addi      r5, r1, 0x270
	  stw       r30, 0x4E8(r1)
	  addi      r4, r31, 0
	  stw       r29, 0x4E4(r1)
	  stw       r0, 0x0(r3)
	  addi      r3, r31, 0x4
	  lwz       r0, -0x4184(r13)
	  stw       r0, 0x4D4(r1)
	  lwz       r0, 0x4D4(r1)
	  stw       r0, 0x270(r1)
	  bl        -0x6F5A4
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6098
	  stw       r30, 0xC(r31)
	  addi      r5, r1, 0x26C
	  addi      r4, r31, 0
	  lfs       f0, -0x6970(r2)
	  addi      r3, r31, 0x14
	  stfs      f0, 0x10(r31)
	  lwz       r0, -0x4180(r13)
	  stw       r0, 0x4CC(r1)
	  lwz       r0, 0x4CC(r1)
	  stw       r0, 0x26C(r1)
	  bl        -0x6F5D8
	  stw       r30, 0x1C(r31)
	  addi      r5, r1, 0x268
	  addi      r4, r31, 0
	  lfs       f0, -0x696C(r2)
	  addi      r3, r31, 0x24
	  stfs      f0, 0x20(r31)
	  lwz       r0, -0x417C(r13)
	  stw       r0, 0x4C4(r1)
	  lwz       r0, 0x4C4(r1)
	  stw       r0, 0x268(r1)
	  bl        -0x6F604
	  stw       r30, 0x2C(r31)
	  addi      r5, r1, 0x264
	  addi      r4, r31, 0
	  lfs       f0, -0x6968(r2)
	  addi      r3, r31, 0x34
	  stfs      f0, 0x30(r31)
	  lwz       r0, -0x4178(r13)
	  stw       r0, 0x4BC(r1)
	  lwz       r0, 0x4BC(r1)
	  stw       r0, 0x264(r1)
	  bl        -0x6F630
	  stw       r30, 0x3C(r31)
	  addi      r5, r1, 0x260
	  addi      r4, r31, 0
	  lfs       f0, -0x6964(r2)
	  addi      r3, r31, 0x44
	  stfs      f0, 0x40(r31)
	  lwz       r0, -0x4174(r13)
	  stw       r0, 0x4B4(r1)
	  lwz       r0, 0x4B4(r1)
	  stw       r0, 0x260(r1)
	  bl        -0x6F65C
	  stw       r30, 0x4C(r31)
	  addi      r5, r1, 0x25C
	  addi      r4, r31, 0
	  lfs       f0, -0x6988(r2)
	  addi      r3, r31, 0x54
	  stfs      f0, 0x50(r31)
	  lwz       r0, -0x4170(r13)
	  stw       r0, 0x4AC(r1)
	  lwz       r0, 0x4AC(r1)
	  stw       r0, 0x25C(r1)
	  bl        -0x6F688
	  stw       r30, 0x5C(r31)
	  addi      r5, r1, 0x258
	  addi      r4, r31, 0
	  lfs       f0, -0x6960(r2)
	  addi      r3, r31, 0x64
	  stfs      f0, 0x60(r31)
	  lwz       r0, -0x416C(r13)
	  stw       r0, 0x4A4(r1)
	  lwz       r0, 0x4A4(r1)
	  stw       r0, 0x258(r1)
	  bl        -0x6F6B4
	  stw       r30, 0x6C(r31)
	  addi      r5, r1, 0x254
	  addi      r4, r31, 0
	  lfs       f0, -0x695C(r2)
	  addi      r3, r31, 0x74
	  stfs      f0, 0x70(r31)
	  lwz       r0, -0x4168(r13)
	  stw       r0, 0x49C(r1)
	  lwz       r0, 0x49C(r1)
	  stw       r0, 0x254(r1)
	  bl        -0x6F6E0
	  stw       r30, 0x7C(r31)
	  addi      r5, r1, 0x250
	  addi      r4, r31, 0
	  lfs       f0, -0x6958(r2)
	  addi      r3, r31, 0x84
	  stfs      f0, 0x80(r31)
	  lwz       r0, -0x4164(r13)
	  stw       r0, 0x494(r1)
	  lwz       r0, 0x494(r1)
	  stw       r0, 0x250(r1)
	  bl        -0x6F70C
	  stw       r30, 0x8C(r31)
	  addi      r5, r1, 0x24C
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x94
	  stfs      f0, 0x90(r31)
	  lwz       r0, -0x4160(r13)
	  stw       r0, 0x48C(r1)
	  lwz       r0, 0x48C(r1)
	  stw       r0, 0x24C(r1)
	  bl        -0x6F738
	  stw       r30, 0x9C(r31)
	  addi      r5, r1, 0x248
	  addi      r4, r31, 0
	  lfs       f0, -0x6950(r2)
	  addi      r3, r31, 0xA4
	  stfs      f0, 0xA0(r31)
	  lwz       r0, -0x415C(r13)
	  stw       r0, 0x484(r1)
	  lwz       r0, 0x484(r1)
	  stw       r0, 0x248(r1)
	  bl        -0x6F764
	  stw       r30, 0xAC(r31)
	  addi      r5, r1, 0x244
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0xB4
	  stfs      f0, 0xB0(r31)
	  lwz       r0, -0x4158(r13)
	  stw       r0, 0x47C(r1)
	  lwz       r0, 0x47C(r1)
	  stw       r0, 0x244(r1)
	  bl        -0x6F790
	  lis       r3, 0x802A
	  addi      r29, r3, 0x60C4
	  stw       r29, 0xBC(r31)
	  li        r0, 0x1
	  addi      r5, r1, 0x240
	  stw       r0, 0xC0(r31)
	  mr        r4, r31
	  addi      r3, r31, 0xC4
	  lwz       r0, -0x4154(r13)
	  stw       r0, 0x474(r1)
	  lwz       r0, 0x474(r1)
	  stw       r0, 0x240(r1)
	  bl        -0x6F7C4
	  stw       r29, 0xCC(r31)
	  li        r0, 0x2
	  addi      r5, r1, 0x23C
	  stw       r0, 0xD0(r31)
	  mr        r4, r31
	  addi      r3, r31, 0xD4
	  lwz       r0, -0x4150(r13)
	  stw       r0, 0x46C(r1)
	  lwz       r0, 0x46C(r1)
	  stw       r0, 0x23C(r1)
	  bl        -0x6F7F0
	  stw       r30, 0xDC(r31)
	  addi      r5, r1, 0x238
	  addi      r4, r31, 0
	  lfs       f0, -0x694C(r2)
	  addi      r3, r31, 0xE4
	  stfs      f0, 0xE0(r31)
	  lwz       r0, -0x414C(r13)
	  stw       r0, 0x464(r1)
	  lwz       r0, 0x464(r1)
	  stw       r0, 0x238(r1)
	  bl        -0x6F81C
	  stw       r30, 0xEC(r31)
	  addi      r5, r1, 0x234
	  addi      r4, r31, 0
	  lfs       f0, -0x6948(r2)
	  addi      r3, r31, 0xF4
	  stfs      f0, 0xF0(r31)
	  lwz       r0, -0x4148(r13)
	  stw       r0, 0x45C(r1)
	  lwz       r0, 0x45C(r1)
	  stw       r0, 0x234(r1)
	  bl        -0x6F848
	  stw       r30, 0xFC(r31)
	  addi      r5, r1, 0x230
	  addi      r4, r31, 0
	  lfs       f0, -0x6944(r2)
	  addi      r3, r31, 0x104
	  stfs      f0, 0x100(r31)
	  lwz       r0, -0x4144(r13)
	  stw       r0, 0x454(r1)
	  lwz       r0, 0x454(r1)
	  stw       r0, 0x230(r1)
	  bl        -0x6F874
	  stw       r30, 0x10C(r31)
	  addi      r5, r1, 0x22C
	  addi      r4, r31, 0
	  lfs       f0, -0x6940(r2)
	  addi      r3, r31, 0x114
	  stfs      f0, 0x110(r31)
	  lwz       r0, -0x4140(r13)
	  stw       r0, 0x44C(r1)
	  lwz       r0, 0x44C(r1)
	  stw       r0, 0x22C(r1)
	  bl        -0x6F8A0
	  stw       r30, 0x11C(r31)
	  addi      r5, r1, 0x228
	  addi      r4, r31, 0
	  lfs       f0, -0x693C(r2)
	  addi      r3, r31, 0x124
	  stfs      f0, 0x120(r31)
	  lwz       r0, -0x413C(r13)
	  stw       r0, 0x444(r1)
	  lwz       r0, 0x444(r1)
	  stw       r0, 0x228(r1)
	  bl        -0x6F8CC
	  stw       r30, 0x12C(r31)
	  addi      r5, r1, 0x224
	  addi      r4, r31, 0
	  lfs       f0, -0x6988(r2)
	  addi      r3, r31, 0x134
	  stfs      f0, 0x130(r31)
	  lwz       r0, -0x4138(r13)
	  stw       r0, 0x43C(r1)
	  lwz       r0, 0x43C(r1)
	  stw       r0, 0x224(r1)
	  bl        -0x6F8F8
	  stw       r30, 0x13C(r31)
	  addi      r5, r1, 0x220
	  addi      r4, r31, 0
	  lfs       f0, -0x6938(r2)
	  addi      r3, r31, 0x144
	  stfs      f0, 0x140(r31)
	  lwz       r0, -0x4134(r13)
	  stw       r0, 0x434(r1)
	  lwz       r0, 0x434(r1)
	  stw       r0, 0x220(r1)
	  bl        -0x6F924
	  stw       r30, 0x14C(r31)
	  addi      r5, r1, 0x21C
	  addi      r4, r31, 0
	  lfs       f0, -0x6940(r2)
	  addi      r3, r31, 0x154
	  stfs      f0, 0x150(r31)
	  lwz       r0, -0x4130(r13)
	  stw       r0, 0x42C(r1)
	  lwz       r0, 0x42C(r1)
	  stw       r0, 0x21C(r1)
	  bl        -0x6F950
	  stw       r30, 0x15C(r31)
	  addi      r5, r1, 0x218
	  addi      r4, r31, 0
	  lfs       f0, -0x6934(r2)
	  addi      r3, r31, 0x164
	  stfs      f0, 0x160(r31)
	  lwz       r0, -0x412C(r13)
	  stw       r0, 0x424(r1)
	  lwz       r0, 0x424(r1)
	  stw       r0, 0x218(r1)
	  bl        -0x6F97C
	  stw       r30, 0x16C(r31)
	  addi      r5, r1, 0x214
	  addi      r4, r31, 0
	  lfs       f0, -0x6930(r2)
	  addi      r3, r31, 0x174
	  stfs      f0, 0x170(r31)
	  lwz       r0, -0x4128(r13)
	  stw       r0, 0x41C(r1)
	  lwz       r0, 0x41C(r1)
	  stw       r0, 0x214(r1)
	  bl        -0x6F9A8
	  stw       r30, 0x17C(r31)
	  addi      r5, r1, 0x210
	  addi      r4, r31, 0
	  lfs       f0, -0x6964(r2)
	  addi      r3, r31, 0x184
	  stfs      f0, 0x180(r31)
	  lwz       r0, -0x4124(r13)
	  stw       r0, 0x414(r1)
	  lwz       r0, 0x414(r1)
	  stw       r0, 0x210(r1)
	  bl        -0x6F9D4
	  stw       r30, 0x18C(r31)
	  addi      r5, r1, 0x20C
	  addi      r4, r31, 0
	  lfs       f0, -0x692C(r2)
	  addi      r3, r31, 0x194
	  stfs      f0, 0x190(r31)
	  lwz       r0, -0x4120(r13)
	  stw       r0, 0x40C(r1)
	  lwz       r0, 0x40C(r1)
	  stw       r0, 0x20C(r1)
	  bl        -0x6FA00
	  stw       r30, 0x19C(r31)
	  addi      r5, r1, 0x208
	  addi      r4, r31, 0
	  lfs       f0, -0x6928(r2)
	  addi      r3, r31, 0x1A4
	  stfs      f0, 0x1A0(r31)
	  lwz       r0, -0x411C(r13)
	  stw       r0, 0x404(r1)
	  lwz       r0, 0x404(r1)
	  stw       r0, 0x208(r1)
	  bl        -0x6FA2C
	  stw       r30, 0x1AC(r31)
	  addi      r5, r1, 0x204
	  addi      r4, r31, 0
	  lfs       f0, -0x692C(r2)
	  addi      r3, r31, 0x1B4
	  stfs      f0, 0x1B0(r31)
	  lwz       r0, -0x4118(r13)
	  stw       r0, 0x3FC(r1)
	  lwz       r0, 0x3FC(r1)
	  stw       r0, 0x204(r1)
	  bl        -0x6FA58
	  stw       r30, 0x1BC(r31)
	  addi      r5, r1, 0x200
	  addi      r4, r31, 0
	  lfs       f0, -0x6928(r2)
	  addi      r3, r31, 0x1C4
	  stfs      f0, 0x1C0(r31)
	  lwz       r0, -0x4114(r13)
	  stw       r0, 0x3F4(r1)
	  lwz       r0, 0x3F4(r1)
	  stw       r0, 0x200(r1)
	  bl        -0x6FA84
	  stw       r30, 0x1CC(r31)
	  addi      r5, r1, 0x1FC
	  addi      r4, r31, 0
	  lfs       f0, -0x692C(r2)
	  addi      r3, r31, 0x1D4
	  stfs      f0, 0x1D0(r31)
	  lwz       r0, -0x4110(r13)
	  stw       r0, 0x3EC(r1)
	  lwz       r0, 0x3EC(r1)
	  stw       r0, 0x1FC(r1)
	  bl        -0x6FAB0
	  stw       r30, 0x1DC(r31)
	  addi      r5, r1, 0x1F8
	  addi      r4, r31, 0
	  lfs       f0, -0x6928(r2)
	  addi      r3, r31, 0x1E4
	  stfs      f0, 0x1E0(r31)
	  lwz       r0, -0x410C(r13)
	  stw       r0, 0x3E4(r1)
	  lwz       r0, 0x3E4(r1)
	  stw       r0, 0x1F8(r1)
	  bl        -0x6FADC
	  stw       r30, 0x1EC(r31)
	  addi      r5, r1, 0x1F4
	  addi      r4, r31, 0
	  lfs       f0, -0x6924(r2)
	  addi      r3, r31, 0x1F4
	  stfs      f0, 0x1F0(r31)
	  lwz       r0, -0x4108(r13)
	  stw       r0, 0x3DC(r1)
	  lwz       r0, 0x3DC(r1)
	  stw       r0, 0x1F4(r1)
	  bl        -0x6FB08
	  stw       r30, 0x1FC(r31)
	  addi      r5, r1, 0x1F0
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x204
	  stfs      f0, 0x200(r31)
	  lwz       r0, -0x4104(r13)
	  stw       r0, 0x3D4(r1)
	  lwz       r0, 0x3D4(r1)
	  stw       r0, 0x1F0(r1)
	  bl        -0x6FB34
	  stw       r30, 0x20C(r31)
	  addi      r5, r1, 0x1EC
	  addi      r4, r31, 0
	  lfs       f0, -0x6960(r2)
	  addi      r3, r31, 0x214
	  stfs      f0, 0x210(r31)
	  lwz       r0, -0x4100(r13)
	  stw       r0, 0x3CC(r1)
	  lwz       r0, 0x3CC(r1)
	  stw       r0, 0x1EC(r1)
	  bl        -0x6FB60
	  stw       r30, 0x21C(r31)
	  addi      r5, r1, 0x1E8
	  addi      r4, r31, 0
	  lfs       f0, -0x6920(r2)
	  addi      r3, r31, 0x224
	  stfs      f0, 0x220(r31)
	  lwz       r0, -0x40FC(r13)
	  stw       r0, 0x3C4(r1)
	  lwz       r0, 0x3C4(r1)
	  stw       r0, 0x1E8(r1)
	  bl        -0x6FB8C
	  stw       r30, 0x22C(r31)
	  addi      r5, r1, 0x1E4
	  addi      r4, r31, 0
	  lfs       f0, -0x691C(r2)
	  addi      r3, r31, 0x234
	  stfs      f0, 0x230(r31)
	  lwz       r0, -0x40F8(r13)
	  stw       r0, 0x3BC(r1)
	  lwz       r0, 0x3BC(r1)
	  stw       r0, 0x1E4(r1)
	  bl        -0x6FBB8
	  stw       r30, 0x23C(r31)
	  addi      r5, r1, 0x1E0
	  addi      r4, r31, 0
	  lfs       f0, -0x6918(r2)
	  addi      r3, r31, 0x244
	  stfs      f0, 0x240(r31)
	  lwz       r0, -0x40F4(r13)
	  stw       r0, 0x3B4(r1)
	  lwz       r0, 0x3B4(r1)
	  stw       r0, 0x1E0(r1)
	  bl        -0x6FBE4
	  stw       r30, 0x24C(r31)
	  addi      r5, r1, 0x1DC
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x254
	  stfs      f0, 0x250(r31)
	  lwz       r0, -0x40F0(r13)
	  stw       r0, 0x3AC(r1)
	  lwz       r0, 0x3AC(r1)
	  stw       r0, 0x1DC(r1)
	  bl        -0x6FC10
	  stw       r30, 0x25C(r31)
	  addi      r5, r1, 0x1D8
	  addi      r4, r31, 0
	  lfs       f0, -0x6958(r2)
	  addi      r3, r31, 0x264
	  stfs      f0, 0x260(r31)
	  lwz       r0, -0x40EC(r13)
	  stw       r0, 0x3A4(r1)
	  lwz       r0, 0x3A4(r1)
	  stw       r0, 0x1D8(r1)
	  bl        -0x6FC3C
	  stw       r30, 0x26C(r31)
	  addi      r5, r1, 0x1D4
	  addi      r4, r31, 0
	  lfs       f0, -0x6914(r2)
	  addi      r3, r31, 0x274
	  stfs      f0, 0x270(r31)
	  lwz       r0, -0x40E8(r13)
	  stw       r0, 0x39C(r1)
	  lwz       r0, 0x39C(r1)
	  stw       r0, 0x1D4(r1)
	  bl        -0x6FC68
	  stw       r30, 0x27C(r31)
	  addi      r5, r1, 0x1D0
	  addi      r4, r31, 0
	  lfs       f0, -0x6910(r2)
	  addi      r3, r31, 0x284
	  stfs      f0, 0x280(r31)
	  lwz       r0, -0x40E4(r13)
	  stw       r0, 0x394(r1)
	  lwz       r0, 0x394(r1)
	  stw       r0, 0x1D0(r1)
	  bl        -0x6FC94
	  stw       r30, 0x28C(r31)
	  addi      r5, r1, 0x1CC
	  addi      r4, r31, 0
	  lfs       f0, -0x6910(r2)
	  addi      r3, r31, 0x294
	  stfs      f0, 0x290(r31)
	  lwz       r0, -0x40E0(r13)
	  stw       r0, 0x38C(r1)
	  lwz       r0, 0x38C(r1)
	  stw       r0, 0x1CC(r1)
	  bl        -0x6FCC0
	  stw       r30, 0x29C(r31)
	  addi      r5, r1, 0x1C8
	  addi      r4, r31, 0
	  lfs       f0, -0x6950(r2)
	  addi      r3, r31, 0x2A4
	  stfs      f0, 0x2A0(r31)
	  lwz       r0, -0x40DC(r13)
	  stw       r0, 0x384(r1)
	  lwz       r0, 0x384(r1)
	  stw       r0, 0x1C8(r1)
	  bl        -0x6FCEC
	  stw       r30, 0x2AC(r31)
	  addi      r5, r1, 0x1C4
	  addi      r4, r31, 0
	  lfs       f0, -0x6960(r2)
	  addi      r3, r31, 0x2B4
	  stfs      f0, 0x2B0(r31)
	  lwz       r0, -0x40D8(r13)
	  stw       r0, 0x37C(r1)
	  lwz       r0, 0x37C(r1)
	  stw       r0, 0x1C4(r1)
	  bl        -0x6FD18
	  stw       r30, 0x2BC(r31)
	  addi      r5, r1, 0x1C0
	  addi      r4, r31, 0
	  lfs       f0, -0x6960(r2)
	  addi      r3, r31, 0x2C4
	  stfs      f0, 0x2C0(r31)
	  lwz       r0, -0x40D4(r13)
	  stw       r0, 0x374(r1)
	  lwz       r0, 0x374(r1)
	  stw       r0, 0x1C0(r1)
	  bl        -0x6FD44
	  stw       r30, 0x2CC(r31)
	  addi      r5, r1, 0x1BC
	  addi      r4, r31, 0
	  lfs       f0, -0x690C(r2)
	  addi      r3, r31, 0x2D4
	  stfs      f0, 0x2D0(r31)
	  lwz       r0, -0x40D0(r13)
	  stw       r0, 0x36C(r1)
	  lwz       r0, 0x36C(r1)
	  stw       r0, 0x1BC(r1)
	  bl        -0x6FD70
	  stw       r30, 0x2DC(r31)
	  addi      r5, r1, 0x1B8
	  addi      r4, r31, 0
	  lfs       f0, -0x690C(r2)
	  addi      r3, r31, 0x2E4
	  stfs      f0, 0x2E0(r31)
	  lwz       r0, -0x40CC(r13)
	  stw       r0, 0x364(r1)
	  lwz       r0, 0x364(r1)
	  stw       r0, 0x1B8(r1)
	  bl        -0x6FD9C
	  stw       r30, 0x2EC(r31)
	  addi      r5, r1, 0x1B4
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x2F4
	  stfs      f0, 0x2F0(r31)
	  lwz       r0, -0x40C8(r13)
	  stw       r0, 0x35C(r1)
	  lwz       r0, 0x35C(r1)
	  stw       r0, 0x1B4(r1)
	  bl        -0x6FDC8
	  stw       r30, 0x2FC(r31)
	  addi      r5, r1, 0x1B0
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x304
	  stfs      f0, 0x300(r31)
	  lwz       r0, -0x40C4(r13)
	  stw       r0, 0x354(r1)
	  lwz       r0, 0x354(r1)
	  stw       r0, 0x1B0(r1)
	  bl        -0x6FDF4
	  stw       r30, 0x30C(r31)
	  addi      r5, r1, 0x1AC
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x314
	  stfs      f0, 0x310(r31)
	  lwz       r0, -0x40C0(r13)
	  stw       r0, 0x34C(r1)
	  lwz       r0, 0x34C(r1)
	  stw       r0, 0x1AC(r1)
	  bl        -0x6FE20
	  stw       r30, 0x31C(r31)
	  addi      r5, r1, 0x1A8
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x324
	  stfs      f0, 0x320(r31)
	  lwz       r0, -0x40BC(r13)
	  stw       r0, 0x344(r1)
	  lwz       r0, 0x344(r1)
	  stw       r0, 0x1A8(r1)
	  bl        -0x6FE4C
	  stw       r30, 0x32C(r31)
	  addi      r5, r1, 0x1A4
	  addi      r4, r31, 0
	  lfs       f0, -0x697C(r2)
	  addi      r3, r31, 0x334
	  stfs      f0, 0x330(r31)
	  lwz       r0, -0x40B8(r13)
	  stw       r0, 0x33C(r1)
	  lwz       r0, 0x33C(r1)
	  stw       r0, 0x1A4(r1)
	  bl        -0x6FE78
	  stw       r30, 0x33C(r31)
	  addi      r5, r1, 0x1A0
	  addi      r4, r31, 0
	  lfs       f0, -0x6988(r2)
	  addi      r3, r31, 0x344
	  stfs      f0, 0x340(r31)
	  lwz       r0, -0x40B4(r13)
	  stw       r0, 0x334(r1)
	  lwz       r0, 0x334(r1)
	  stw       r0, 0x1A0(r1)
	  bl        -0x6FEA4
	  stw       r30, 0x34C(r31)
	  addi      r5, r1, 0x19C
	  addi      r4, r31, 0
	  lfs       f0, -0x6988(r2)
	  addi      r3, r31, 0x354
	  stfs      f0, 0x350(r31)
	  lwz       r0, -0x40B0(r13)
	  stw       r0, 0x32C(r1)
	  lwz       r0, 0x32C(r1)
	  stw       r0, 0x19C(r1)
	  bl        -0x6FED0
	  stw       r30, 0x35C(r31)
	  addi      r5, r1, 0x198
	  addi      r4, r31, 0
	  lfs       f0, -0x6908(r2)
	  addi      r3, r31, 0x364
	  stfs      f0, 0x360(r31)
	  lwz       r0, -0x40AC(r13)
	  stw       r0, 0x324(r1)
	  lwz       r0, 0x324(r1)
	  stw       r0, 0x198(r1)
	  bl        -0x6FEFC
	  stw       r30, 0x36C(r31)
	  addi      r5, r1, 0x194
	  addi      r4, r31, 0
	  lfs       f0, -0x6908(r2)
	  addi      r3, r31, 0x374
	  stfs      f0, 0x370(r31)
	  lwz       r0, -0x40A8(r13)
	  stw       r0, 0x31C(r1)
	  lwz       r0, 0x31C(r1)
	  stw       r0, 0x194(r1)
	  bl        -0x6FF28
	  stw       r30, 0x37C(r31)
	  addi      r5, r1, 0x190
	  addi      r4, r31, 0
	  lfs       f0, -0x6988(r2)
	  addi      r3, r31, 0x384
	  stfs      f0, 0x380(r31)
	  lwz       r0, -0x40A4(r13)
	  stw       r0, 0x314(r1)
	  lwz       r0, 0x314(r1)
	  stw       r0, 0x190(r1)
	  bl        -0x6FF54
	  stw       r30, 0x38C(r31)
	  addi      r5, r1, 0x18C
	  addi      r4, r31, 0
	  lfs       f0, -0x693C(r2)
	  addi      r3, r31, 0x394
	  stfs      f0, 0x390(r31)
	  lwz       r0, -0x40A0(r13)
	  stw       r0, 0x30C(r1)
	  lwz       r0, 0x30C(r1)
	  stw       r0, 0x18C(r1)
	  bl        -0x6FF80
	  stw       r30, 0x39C(r31)
	  addi      r5, r1, 0x188
	  addi      r4, r31, 0
	  lfs       f0, -0x694C(r2)
	  addi      r3, r31, 0x3A4
	  stfs      f0, 0x3A0(r31)
	  lwz       r0, -0x409C(r13)
	  stw       r0, 0x304(r1)
	  lwz       r0, 0x304(r1)
	  stw       r0, 0x188(r1)
	  bl        -0x6FFAC
	  stw       r30, 0x3AC(r31)
	  addi      r5, r1, 0x184
	  addi      r4, r31, 0
	  lfs       f0, -0x6978(r2)
	  addi      r3, r31, 0x3B4
	  stfs      f0, 0x3B0(r31)
	  lwz       r0, -0x4098(r13)
	  stw       r0, 0x2FC(r1)
	  lwz       r0, 0x2FC(r1)
	  stw       r0, 0x184(r1)
	  bl        -0x6FFD8
	  stw       r30, 0x3BC(r31)
	  addi      r5, r1, 0x180
	  addi      r4, r31, 0
	  lfs       f0, -0x6904(r2)
	  addi      r3, r31, 0x3C4
	  stfs      f0, 0x3C0(r31)
	  lwz       r0, -0x4094(r13)
	  stw       r0, 0x2F4(r1)
	  lwz       r0, 0x2F4(r1)
	  stw       r0, 0x180(r1)
	  bl        -0x70004
	  stw       r30, 0x3CC(r31)
	  addi      r5, r1, 0x17C
	  addi      r4, r31, 0
	  lfs       f0, -0x6958(r2)
	  addi      r3, r31, 0x3D4
	  stfs      f0, 0x3D0(r31)
	  lwz       r0, -0x4090(r13)
	  stw       r0, 0x2EC(r1)
	  lwz       r0, 0x2EC(r1)
	  stw       r0, 0x17C(r1)
	  bl        -0x70030
	  stw       r30, 0x3DC(r31)
	  addi      r5, r1, 0x178
	  addi      r4, r31, 0
	  lfs       f0, -0x6954(r2)
	  addi      r3, r31, 0x3E4
	  stfs      f0, 0x3E0(r31)
	  lwz       r0, -0x408C(r13)
	  stw       r0, 0x2E4(r1)
	  lwz       r0, 0x2E4(r1)
	  stw       r0, 0x178(r1)
	  bl        -0x7005C
	  stw       r30, 0x3EC(r31)
	  addi      r5, r1, 0x174
	  addi      r4, r31, 0
	  lfs       f0, -0x6900(r2)
	  addi      r3, r31, 0x3F4
	  stfs      f0, 0x3F0(r31)
	  lwz       r0, -0x4088(r13)
	  stw       r0, 0x2DC(r1)
	  lwz       r0, 0x2DC(r1)
	  stw       r0, 0x174(r1)
	  bl        -0x70088
	  stw       r30, 0x3FC(r31)
	  addi      r5, r1, 0x170
	  addi      r4, r31, 0
	  lfs       f0, -0x68FC(r2)
	  addi      r3, r31, 0x404
	  stfs      f0, 0x400(r31)
	  lwz       r0, -0x4084(r13)
	  stw       r0, 0x2D4(r1)
	  lwz       r0, 0x2D4(r1)
	  stw       r0, 0x170(r1)
	  bl        -0x700B4
	  stw       r30, 0x40C(r31)
	  addi      r5, r1, 0x16C
	  addi      r4, r31, 0
	  lfs       f0, -0x6958(r2)
	  addi      r3, r31, 0x414
	  stfs      f0, 0x410(r31)
	  lwz       r0, -0x4080(r13)
	  stw       r0, 0x2CC(r1)
	  lwz       r0, 0x2CC(r1)
	  stw       r0, 0x16C(r1)
	  bl        -0x700E0
	  stw       r30, 0x41C(r31)
	  addi      r5, r1, 0x168
	  addi      r4, r31, 0
	  lfs       f0, -0x68F8(r2)
	  addi      r3, r31, 0x424
	  stfs      f0, 0x420(r31)
	  lwz       r0, -0x407C(r13)
	  stw       r0, 0x2C4(r1)
	  lwz       r0, 0x2C4(r1)
	  stw       r0, 0x168(r1)
	  bl        -0x7010C
	  stw       r29, 0x42C(r31)
	  li        r0, 0x1E
	  addi      r5, r1, 0x164
	  stw       r0, 0x430(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x434
	  lwz       r0, -0x4078(r13)
	  stw       r0, 0x2BC(r1)
	  lwz       r0, 0x2BC(r1)
	  stw       r0, 0x164(r1)
	  bl        -0x70138
	  stw       r29, 0x43C(r31)
	  li        r0, 0xA
	  addi      r5, r1, 0x160
	  stw       r0, 0x440(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x444
	  lwz       r0, -0x4074(r13)
	  stw       r0, 0x2B4(r1)
	  lwz       r0, 0x2B4(r1)
	  stw       r0, 0x160(r1)
	  bl        -0x70164
	  stw       r30, 0x44C(r31)
	  addi      r5, r1, 0x15C
	  addi      r4, r31, 0
	  lfs       f0, -0x6940(r2)
	  addi      r3, r31, 0x454
	  stfs      f0, 0x450(r31)
	  lwz       r0, -0x4070(r13)
	  stw       r0, 0x2AC(r1)
	  lwz       r0, 0x2AC(r1)
	  stw       r0, 0x15C(r1)
	  bl        -0x70190
	  stw       r30, 0x45C(r31)
	  addi      r5, r1, 0x158
	  addi      r4, r31, 0
	  lfs       f0, -0x68F4(r2)
	  addi      r3, r31, 0x464
	  stfs      f0, 0x460(r31)
	  lwz       r0, -0x406C(r13)
	  stw       r0, 0x2A4(r1)
	  lwz       r0, 0x2A4(r1)
	  stw       r0, 0x158(r1)
	  bl        -0x701BC
	  stw       r30, 0x46C(r31)
	  addi      r5, r1, 0x154
	  addi      r4, r31, 0
	  lfs       f0, -0x68F0(r2)
	  addi      r3, r31, 0x474
	  stfs      f0, 0x470(r31)
	  lwz       r0, -0x4068(r13)
	  stw       r0, 0x29C(r1)
	  lwz       r0, 0x29C(r1)
	  stw       r0, 0x154(r1)
	  bl        -0x701E8
	  stw       r30, 0x47C(r31)
	  addi      r5, r1, 0x150
	  addi      r4, r31, 0
	  lfs       f0, -0x6964(r2)
	  addi      r3, r31, 0x484
	  stfs      f0, 0x480(r31)
	  lwz       r0, -0x4064(r13)
	  stw       r0, 0x294(r1)
	  lwz       r0, 0x294(r1)
	  stw       r0, 0x150(r1)
	  bl        -0x70214
	  stw       r30, 0x48C(r31)
	  addi      r5, r1, 0x14C
	  addi      r4, r31, 0
	  lfs       f0, -0x6948(r2)
	  addi      r3, r31, 0x494
	  stfs      f0, 0x490(r31)
	  lwz       r0, -0x4060(r13)
	  stw       r0, 0x28C(r1)
	  lwz       r0, 0x28C(r1)
	  stw       r0, 0x14C(r1)
	  bl        -0x70240
	  stw       r30, 0x49C(r31)
	  addi      r5, r1, 0x148
	  addi      r4, r31, 0
	  lfs       f0, -0x695C(r2)
	  addi      r3, r31, 0x4A4
	  stfs      f0, 0x4A0(r31)
	  lwz       r0, -0x405C(r13)
	  stw       r0, 0x284(r1)
	  lwz       r0, 0x284(r1)
	  stw       r0, 0x148(r1)
	  bl        -0x7026C
	  stw       r30, 0x4AC(r31)
	  addi      r5, r1, 0x144
	  addi      r4, r31, 0
	  lfs       f0, -0x68F4(r2)
	  addi      r3, r31, 0x4B4
	  stfs      f0, 0x4B0(r31)
	  lwz       r0, -0x4058(r13)
	  stw       r0, 0x27C(r1)
	  lwz       r0, 0x27C(r1)
	  stw       r0, 0x144(r1)
	  bl        -0x70298
	  stw       r30, 0x4BC(r31)
	  addi      r5, r1, 0x140
	  addi      r4, r31, 0
	  lfs       f0, -0x68EC(r2)
	  addi      r3, r31, 0x4C4
	  stfs      f0, 0x4C0(r31)
	  lwz       r0, -0x4054(r13)
	  stw       r0, 0x274(r1)
	  lwz       r0, 0x274(r1)
	  stw       r0, 0x140(r1)
	  bl        -0x702C4
	  stw       r30, 0x4CC(r31)
	  mr        r3, r31
	  lfs       f0, -0x6904(r2)
	  stfs      f0, 0x4D0(r31)
	  lwz       r0, 0x4F4(r1)
	  lwz       r31, 0x4EC(r1)
	  lwz       r30, 0x4E8(r1)
	  lwz       r29, 0x4E4(r1)
	  addi      r1, r1, 0x4F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CED74
 * Size:	000018
 */
void PikiMgr::init()
{

	_60 = 0;
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x3058(r13)
	  stw       r0, 0x60(r3)
	  stb       r0, 0x306E(r13)
	  stb       r0, 0x306D(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CED8C
 * Size:	00007C
 */
ViewPiki* PikiMgr::createObject()
{
	memStat->start("pikiNew");
	ViewPiki* piki = new ViewPiki(mPikiParms);
	memStat->end("pikiNew");
	return piki;
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r4, r13, 0x4050
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x48674
	  li        r3, 0x59C
	  bl        -0x87DB0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x40
	  lwz       r4, 0x68(r30)
	  bl        0x9EF0

	.loc_0x40:
	  lwz       r4, 0x48(r30)
	  mr        r3, r31
	  lwz       r5, 0x4C(r30)
	  lwz       r6, 0x6C(r30)
	  bl        0x9FF0
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x4050
	  bl        -0x485A0
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void PikiMgr::lostAllPikis()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CEE08
 * Size:	000020
 */
void PikiMgr::update() {MonoObjectMgr::update();}

/*
 * --INFO--
 * Address:	800CEE28
 * Size:	000020
 */
void PikiMgr::refresh(Graphics& graphics) {MonoObjectMgr::refresh(graphics);}


/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void PikiMgr::refresh2d(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800CEE48
 * Size:	000030
 */
void PikiMgr::read(RandomAccessStream& input) {mPikiParms->read(input);}

/*
 * --INFO--
 * Address:	800CEE78
 * Size:	000044
 */
void PikiProp::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x702FC
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x70308
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800CEEBC
 * Size:	000198
 */
void PikiMgr::dumpAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  stw       r30, 0x70(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x124

	.loc_0x30:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  b         .loc_0x74

	.loc_0x58:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3

	.loc_0x74:
	  lwz       r4, 0x228(r5)
	  mr        r3, r5
	  lwz       r0, 0x22C(r5)
	  stw       r4, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r4, 0x230(r5)
	  lwz       r0, 0x234(r5)
	  stw       r4, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r4, 0x238(r5)
	  lwz       r0, 0x23C(r5)
	  stw       r4, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r4, 0x240(r5)
	  lwz       r0, 0x244(r5)
	  stw       r4, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r4, 0x248(r5)
	  lwz       r0, 0x24C(r5)
	  stw       r4, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r4, 0x250(r5)
	  lwz       r0, 0x254(r5)
	  stw       r4, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  lwz       r4, 0x258(r5)
	  lwz       r0, 0x25C(r5)
	  stw       r4, 0x54(r1)
	  stw       r0, 0x58(r1)
	  lwz       r4, 0x260(r5)
	  lwz       r0, 0x264(r5)
	  stw       r4, 0x5C(r1)
	  stw       r0, 0x60(r1)
	  lwz       r12, 0x0(r5)
	  lwz       r12, 0xC8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x124:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x14C
	  li        r0, 0x1
	  b         .loc_0x178

	.loc_0x14C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x174
	  li        r0, 0x1
	  b         .loc_0x178

	.loc_0x174:
	  li        r0, 0

	.loc_0x178:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x30
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
 * Address:	800CF054
 * Size:	000084
 */
PikiMgr::~PikiMgr() { }
