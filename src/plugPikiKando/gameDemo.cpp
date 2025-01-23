#include "Demo.h"
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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
DemoParms::DemoParms()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
DemoParms::Parms::Parms()
    : mOnionBootTriggerRadius(this, 150.0f, 0.0f, 1000.0f, "p00", "コンテナ接近距離")
    , mSeedDemoTriggerRadius(this, 100.0f, 0.0f, 1000.0f, "p01", "芽ピキ接近距離")
    , mSeedDemoWaitTime(this, 6.0f, 0.0f, 500.0f, "p02", "芽ピキ抜かずタイムアウト")
    , _30(this, 30.0f, 0.0f, 500.0f, "p03", "ペレット草バトルタイムアウト")
    , mDemoTriggerRadius(this, 150.0f, 0.0f, 1000.0f, "p04", "エンジン接近距離")
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80081C10
 * Size:	0005F4
 */
DemoFlags::DemoFlags()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  subi      r31, r4, 0x21E0
	  stw       r30, 0x70(r1)
	  stw       r29, 0x6C(r1)
	  addi      r29, r3, 0
	  li        r3, 0x74
	  stw       r28, 0x68(r1)
	  bl        -0x3AC38
	  mr.       r30, r3
	  beq-      .loc_0x17C
	  addi      r3, r30, 0
	  subi      r4, r13, 0x60C0
	  bl        -0x4CC98
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  subi      r4, r13, 0x60C0
	  bl        -0x4152C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x1EB0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  addi      r3, r1, 0x40
	  stw       r0, 0x20(r30)
	  subi      r4, r13, 0x60B0
	  bl        -0x311B0
	  lwz       r0, 0x40(r1)
	  addi      r5, r1, 0x38
	  addi      r3, r30, 0x24
	  stw       r0, 0x38(r1)
	  addi      r4, r30, 0x20
	  bl        -0x23220
	  lis       r3, 0x802A
	  addi      r28, r3, 0x6098
	  stw       r28, 0x2C(r30)
	  addi      r3, r1, 0x48
	  subi      r4, r13, 0x60AC
	  lfs       f0, -0x7618(r2)
	  stfs      f0, 0x30(r30)
	  bl        -0x311E8
	  lwz       r0, 0x48(r1)
	  addi      r5, r1, 0x34
	  addi      r3, r30, 0x34
	  stw       r0, 0x34(r1)
	  addi      r4, r30, 0x20
	  bl        -0x23258
	  stw       r28, 0x3C(r30)
	  addi      r3, r1, 0x50
	  subi      r4, r13, 0x60A8
	  lfs       f0, -0x7614(r2)
	  stfs      f0, 0x40(r30)
	  bl        -0x31218
	  lwz       r0, 0x50(r1)
	  addi      r5, r1, 0x30
	  addi      r3, r30, 0x44
	  stw       r0, 0x30(r1)
	  addi      r4, r30, 0x20
	  bl        -0x23288
	  stw       r28, 0x4C(r30)
	  addi      r3, r1, 0x58
	  subi      r4, r13, 0x60A4
	  lfs       f0, -0x7610(r2)
	  stfs      f0, 0x50(r30)
	  bl        -0x31248
	  lwz       r0, 0x58(r1)
	  addi      r5, r1, 0x2C
	  addi      r3, r30, 0x54
	  stw       r0, 0x2C(r1)
	  addi      r4, r30, 0x20
	  bl        -0x232B8
	  stw       r28, 0x5C(r30)
	  addi      r3, r1, 0x60
	  subi      r4, r13, 0x60A0
	  lfs       f0, -0x760C(r2)
	  stfs      f0, 0x60(r30)
	  bl        -0x31278
	  lwz       r0, 0x60(r1)
	  addi      r5, r1, 0x28
	  addi      r3, r30, 0x64
	  stw       r0, 0x28(r1)
	  addi      r4, r30, 0x20
	  bl        -0x232E8
	  stw       r28, 0x6C(r30)
	  addi      r3, r30, 0
	  addi      r5, r31, 0x1C
	  lfs       f0, -0x7618(r2)
	  subi      r4, r13, 0x60B8
	  li        r6, 0x1
	  stfs      f0, 0x70(r30)
	  bl        -0x416E8

	.loc_0x17C:
	  stw       r30, 0x2F70(r13)
	  li        r0, 0x20
	  li        r30, 0
	  sth       r0, 0x0(r29)
	  lhz       r0, 0x0(r29)
	  rlwinm    r0,r0,3,16,28
	  sth       r0, 0x4(r29)
	  sth       r30, 0x2(r29)
	  lhz       r3, 0x0(r29)
	  bl        -0x3ADAC
	  stw       r3, 0x8(r29)
	  lhz       r0, 0x4(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x3ADBC
	  stw       r3, 0xC(r29)
	  li        r4, 0
	  b         .loc_0x1CC

	.loc_0x1C0:
	  lwz       r3, 0x8(r29)
	  stbx      r30, r3, r4
	  addi      r4, r4, 0x1

	.loc_0x1CC:
	  lhz       r0, 0x0(r29)
	  cmpw      r4, r0
	  blt+      .loc_0x1C0
	  li        r6, 0
	  addi      r5, r6, 0
	  addi      r4, r6, 0
	  b         .loc_0x1F8

	.loc_0x1E8:
	  lwz       r3, 0xC(r29)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x1F8:
	  lhz       r0, 0x4(r29)
	  cmpw      r6, r0
	  blt+      .loc_0x1E8
	  li        r0, -0x1
	  sth       r0, 0x18(r29)
	  addi      r3, r29, 0
	  addi      r5, r31, 0x28
	  lfs       f0, -0x7608(r2)
	  li        r4, 0
	  li        r6, 0x4
	  stfs      f0, 0x14(r29)
	  li        r7, 0
	  li        r8, 0
	  bl        0x60C
	  addi      r3, r29, 0
	  addi      r5, r31, 0x40
	  li        r4, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  li        r8, 0
	  bl        0x5F0
	  addi      r3, r29, 0
	  addi      r5, r31, 0x58
	  li        r4, 0x2
	  li        r6, 0x6
	  li        r7, 0
	  li        r8, 0
	  bl        0x5D4
	  addi      r3, r29, 0
	  addi      r5, r31, 0x70
	  li        r4, 0x3
	  li        r6, 0x7
	  li        r7, 0
	  li        r8, 0
	  bl        0x5B8
	  addi      r3, r29, 0
	  addi      r5, r31, 0x84
	  li        r4, 0x4
	  li        r6, 0x9
	  li        r7, 0
	  li        r8, 0
	  bl        0x59C
	  addi      r3, r29, 0
	  addi      r5, r31, 0x94
	  li        r4, 0x5
	  li        r6, 0xA
	  li        r7, 0
	  li        r8, 0
	  bl        0x580
	  addi      r3, r29, 0
	  addi      r5, r31, 0xA4
	  li        r4, 0x6
	  li        r6, 0xB
	  li        r7, 0
	  li        r8, 0
	  bl        0x564
	  addi      r3, r29, 0
	  addi      r5, r31, 0xB4
	  li        r4, 0x7
	  li        r6, 0x8
	  li        r7, 0
	  li        r8, 0
	  bl        0x548
	  addi      r3, r29, 0
	  addi      r5, r31, 0xCC
	  li        r4, 0x8
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x52C
	  addi      r3, r29, 0
	  addi      r5, r31, 0xD8
	  li        r4, 0x9
	  li        r6, 0xD
	  li        r7, 0
	  li        r8, 0
	  bl        0x510
	  addi      r3, r29, 0
	  addi      r5, r31, 0xF8
	  li        r4, 0xA
	  li        r6, 0xE
	  li        r7, 0
	  li        r8, 0
	  bl        0x4F4
	  addi      r3, r29, 0
	  addi      r5, r31, 0x10C
	  li        r4, 0xB
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x4D8
	  addi      r3, r29, 0
	  addi      r5, r31, 0x120
	  li        r4, 0xC
	  li        r6, 0x10
	  li        r7, 0
	  li        r8, 0
	  bl        0x4BC
	  addi      r3, r29, 0
	  addi      r5, r31, 0x138
	  li        r4, 0xD
	  li        r6, 0x14
	  li        r7, 0
	  li        r8, 0
	  bl        0x4A0
	  addi      r3, r29, 0
	  addi      r5, r31, 0x14C
	  li        r4, 0xE
	  li        r6, 0xF
	  li        r7, 0
	  li        r8, 0
	  bl        0x484
	  lis       r4, 0x1
	  addi      r3, r29, 0
	  addi      r5, r31, 0x15C
	  subi      r6, r4, 0x1
	  li        r4, 0xF
	  li        r7, 0
	  li        r8, 0
	  bl        0x464
	  addi      r3, r29, 0
	  addi      r5, r31, 0x16C
	  li        r4, 0x10
	  li        r6, 0x2C
	  li        r7, 0
	  li        r8, 0x1
	  bl        0x448
	  addi      r3, r29, 0
	  addi      r5, r31, 0x184
	  li        r4, 0x11
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x1
	  bl        0x42C
	  addi      r3, r29, 0
	  addi      r5, r31, 0x19C
	  li        r4, 0x12
	  li        r6, 0x44
	  li        r7, 0
	  li        r8, 0
	  bl        0x410
	  addi      r3, r29, 0
	  addi      r5, r31, 0x1AC
	  li        r4, 0x13
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x3F4
	  addi      r3, r29, 0
	  addi      r5, r31, 0x1BC
	  li        r4, 0x14
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x3D8
	  addi      r3, r29, 0
	  addi      r5, r31, 0x1D0
	  li        r4, 0x15
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x3BC
	  addi      r3, r29, 0
	  addi      r5, r31, 0x1EC
	  li        r4, 0x16
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x3A0
	  addi      r3, r29, 0
	  addi      r5, r31, 0x204
	  li        r4, 0x17
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x384
	  addi      r3, r29, 0
	  addi      r5, r31, 0x21C
	  li        r4, 0x18
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x368
	  addi      r3, r29, 0
	  addi      r5, r31, 0x238
	  li        r4, 0x19
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x34C
	  addi      r3, r29, 0
	  addi      r5, r31, 0x250
	  li        r4, 0x1A
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x330
	  addi      r3, r29, 0
	  addi      r5, r31, 0x260
	  li        r4, 0x1B
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x314
	  addi      r3, r29, 0
	  addi      r5, r31, 0x270
	  li        r4, 0x1C
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x2F8
	  addi      r3, r29, 0
	  addi      r5, r31, 0x27C
	  li        r4, 0x1D
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x2DC
	  addi      r3, r29, 0
	  li        r4, 0x1E
	  subi      r5, r13, 0x609C
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x2C0
	  addi      r3, r29, 0
	  addi      r5, r31, 0x28C
	  li        r4, 0x1F
	  li        r6, 0xC
	  li        r7, 0
	  li        r8, 0
	  bl        0x2A4
	  li        r28, 0

	.loc_0x59C:
	  addi      r3, r29, 0
	  addi      r4, r28, 0x20
	  addi      r5, r31, 0x298
	  rlwinm    r7,r28,0,16,31
	  li        r6, 0xC
	  li        r8, 0
	  bl        0x284
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x1E
	  blt+      .loc_0x59C
	  addi      r3, r29, 0
	  li        r4, 0x24
	  bl        0x574
	  mr        r3, r29
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  lwz       r28, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80082204
 * Size:	000058
 */
void DemoFlags::initGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x8(r1)
	  b         .loc_0x24

	.loc_0x18:
	  lwz       r4, 0x8(r3)
	  stbx      r5, r4, r6
	  addi      r6, r6, 0x1

	.loc_0x24:
	  lhz       r0, 0x0(r3)
	  cmpw      r6, r0
	  blt+      .loc_0x18
	  li        r0, -0x1
	  sth       r0, 0x18(r3)
	  li        r4, 0x24
	  lfs       f0, -0x7608(r2)
	  stfs      f0, 0x14(r3)
	  bl        0x508
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008225C
 * Size:	000014
 */
void DemoFlags::initCourse()
{
	/*
	.loc_0x0:
	  li        r0, -0x1
	  sth       r0, 0x18(r3)
	  lfs       f0, -0x7608(r2)
	  stfs      f0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80082270
 * Size:	0000F8
 */
void DemoFlags::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  subi      r31, r4, 0x2848
	  stw       r30, 0x20(r1)
	  addi      r30, r31, 0x1DC
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r4, 0x1DC(r31)
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0xDC
	  lha       r4, 0x18(r29)
	  cmpwi     r4, -0x1
	  beq-      .loc_0xDC
	  mr        r3, r29
	  bl        0x20C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  mr        r3, r29
	  bl        0x500
	  b         .loc_0xDC

	.loc_0x60:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r29)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r29)
	  lwz       r3, 0x0(r30)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xDC
	  lfs       f1, 0x14(r29)
	  lfs       f0, -0x7608(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xDC
	  lha       r4, 0x18(r29)
	  cmpwi     r4, 0x14
	  bne-      .loc_0xD0
	  lwz       r3, 0x1E8(r31)
	  li        r4, 0
	  li        r5, 0x14
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lha       r4, 0x18(r29)
	  bl        0x418
	  b         .loc_0xDC

	.loc_0xD0:
	  lwz       r5, 0x10(r29)
	  mr        r3, r29
	  bl        0x1D4

	.loc_0xDC:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80082368
 * Size:	000070
 */
void DemoFlags::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r30
	  lwz       r4, 0x8(r29)
	  lwz       r12, 0x4(r30)
	  lbzx      r4, r4, r31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1

	.loc_0x48:
	  lhz       r0, 0x0(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x28
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
 * Address:	800823D8
 * Size:	000070
 */
void DemoFlags::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x8(r29)
	  stbx      r3, r4, r31
	  addi      r31, r31, 0x1

	.loc_0x48:
	  lhz       r0, 0x0(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x28
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
 * Address:	80082448
 * Size:	00007C
 */
void DemoFlags::registerDemoFlag(int, char*, u16, u16, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r27, r4, 0
	  mr        r26, r3
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  addi      r30, r7, 0
	  addi      r31, r8, 0
	  lhz       r0, 0x2(r3)
	  cmpw      r0, r27
	  li        r3, 0xC
	  bl        -0x3B478
	  stw       r28, 0x0(r3)
	  sth       r29, 0x6(r3)
	  sth       r30, 0x8(r3)
	  sth       r27, 0x4(r3)
	  stb       r31, 0xA(r3)
	  lhz       r0, 0x2(r26)
	  lwz       r4, 0xC(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r3, r4, r0
	  lhz       r3, 0x2(r26)
	  addi      r0, r3, 0x1
	  sth       r0, 0x2(r26)
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800824C4
 * Size:	000030
 */
bool DemoFlags::isFlag(int)
{
	/*
	.loc_0x0:
	  srawi     r5, r4, 0x3
	  lwz       r3, 0x8(r3)
	  rlwinm    r0,r5,3,0,28
	  sub       r4, r4, r0
	  lbzx      r0, r3, r5
	  li        r3, 0x1
	  slw       r3, r3, r4
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800824F4
 * Size:	000028
 */
void DemoFlags::resetFlag(int)
{
	/*
	.loc_0x0:
	  srawi     r6, r4, 0x3
	  lwz       r5, 0x8(r3)
	  rlwinm    r0,r6,3,0,28
	  sub       r0, r4, r0
	  lbzx      r4, r5, r6
	  li        r3, 0x1
	  slw       r0, r3, r0
	  andc      r0, r4, r0
	  stbx      r0, r5, r6
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008251C
 * Size:	000234
 */
void DemoFlags::setFlag(int, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stmw      r27, 0x6C(r1)
	  addi      r30, r4, 0
	  addi      r29, r3, 0
	  srawi     r27, r30, 0x3
	  rlwinm    r4,r27,3,0,28
	  addi      r31, r5, 0
	  lwz       r3, 0x8(r3)
	  lbzx      r0, r3, r27
	  sub       r3, r30, r4
	  li        r4, 0x1
	  slw       r28, r4, r3
	  and.      r0, r28, r0
	  bne-      .loc_0x220
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x280
	  lwz       r5, 0x8(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  lbzx      r0, r5, r27
	  or        r0, r0, r28
	  stbx      r0, r5, r27
	  bl        0x264
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x258
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x24C
	  lha       r0, 0x6(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x220
	  cmpwi     r30, 0x4
	  bne-      .loc_0x108
	  lfs       f0, -0x6094(r13)
	  cmplwi    r31, 0
	  lfs       f1, -0x7604(r2)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, -0x6090(r13)
	  stfs      f1, 0x40(r1)
	  stfs      f0, 0x44(r1)
	  beq-      .loc_0xBC
	  addi      r28, r31, 0x94
	  b         .loc_0xC0

	.loc_0xBC:
	  li        r28, 0

	.loc_0xC0:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x200
	  lis       r5, 0x803A
	  lha       r4, 0x6(r3)
	  subi      r3, r5, 0x2848
	  lwz       r3, 0x1E8(r3)
	  mr        r6, r31
	  addi      r7, r28, 0
	  lwz       r12, 0x0(r3)
	  addi      r8, r1, 0x3C
	  li        r5, 0
	  lwz       r12, 0xC(r12)
	  li        r9, -0x1
	  li        r10, 0x1
	  mtlr      r12
	  blrl
	  b         .loc_0x220

	.loc_0x108:
	  cmplwi    r31, 0
	  beq-      .loc_0x1B4
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x10
	  beq-      .loc_0x1B4
	  lfs       f0, 0x94(r31)
	  addi      r3, r1, 0x30
	  lfs       f1, -0x7600(r2)
	  stfs      f0, 0x30(r1)
	  lfs       f2, -0x75FC(r2)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x38(r1)
	  bl        0x908B4
	  lfs       f2, -0x608C(r13)
	  cmplwi    r31, 0
	  lfs       f0, -0x6088(r13)
	  stfs      f2, 0x24(r1)
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  beq-      .loc_0x168
	  addi      r28, r31, 0x94
	  b         .loc_0x16C

	.loc_0x168:
	  li        r28, 0

	.loc_0x16C:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x154
	  lis       r5, 0x803A
	  lha       r4, 0x6(r3)
	  subi      r3, r5, 0x2848
	  lwz       r3, 0x1E8(r3)
	  mr        r6, r31
	  addi      r7, r28, 0
	  lwz       r12, 0x0(r3)
	  addi      r8, r1, 0x24
	  li        r5, 0
	  lwz       r12, 0xC(r12)
	  li        r9, -0x1
	  li        r10, 0x1
	  mtlr      r12
	  blrl
	  b         .loc_0x220

	.loc_0x1B4:
	  cmplwi    r31, 0
	  beq-      .loc_0x1C4
	  addi      r28, r31, 0x88
	  b         .loc_0x1C8

	.loc_0x1C4:
	  li        r28, 0

	.loc_0x1C8:
	  cmplwi    r31, 0
	  beq-      .loc_0x1D8
	  addi      r27, r31, 0x94
	  b         .loc_0x1DC

	.loc_0x1D8:
	  li        r27, 0

	.loc_0x1DC:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0xE4
	  lis       r5, 0x803A
	  lha       r4, 0x6(r3)
	  subi      r3, r5, 0x2848
	  lwz       r3, 0x1E8(r3)
	  mr        r6, r31
	  addi      r7, r27, 0
	  lwz       r12, 0x0(r3)
	  addi      r8, r28, 0
	  li        r5, 0
	  lwz       r12, 0xC(r12)
	  li        r9, -0x1
	  li        r10, 0x1
	  mtlr      r12
	  blrl

	.loc_0x220:
	  lmw       r27, 0x6C(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80082750
 * Size:	000030
 */
void DemoFlags::setFlagOnly(int)
{
	/*
	.loc_0x0:
	  srawi     r5, r4, 0x3
	  lwz       r6, 0x8(r3)
	  rlwinm    r0,r5,3,0,28
	  sub       r0, r4, r0
	  lbzx      r3, r6, r5
	  li        r4, 0x1
	  slw       r4, r4, r0
	  and.      r0, r4, r3
	  bnelr-
	  or        r0, r3, r4
	  stbx      r0, r6, r5
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80082780
 * Size:	000048
 */
void DemoFlags::setTimer(f32, int, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh     r0, r4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r5
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  stfs      f1, 0x14(r3)
	  sth       r0, 0x18(r3)
	  bl        0x3C
	  stw       r31, 0x10(r30)
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
 * Address:	800827C8
 * Size:	00001C
 */
void DemoFlags::resetTimer()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x10(r3)
	  li        r0, -0x1
	  lfs       f0, -0x7608(r2)
	  stfs      f0, 0x14(r3)
	  sth       r0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800827E4
 * Size:	000010
 */
DemoFlag* DemoFlags::getDemoFlag(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800827F4
 * Size:	000024
 */
void DemoParms::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x20
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x23C6C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
