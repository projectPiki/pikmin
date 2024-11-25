#include "TAI/KabekuiA.h"
#include "sysNew.h"

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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801CA2A8
 * Size:	000084
 */
TAIkabekuiASoundTable::TAIkabekuiASoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + 124);
	}
}

/*
 * --INFO--
 * Address:	801CA32C
 * Size:	00036C
 */
TAIkabekuiAParameters::TAIkabekuiAParameters()
    : TekiParameters(20, 54) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x36
	  stwu      r1, -0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xC8(r1)
	  addi      r30, r4, 0x20C8
	  li        r4, 0x14
	  bl        -0x7E60C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x26E0
	  stw       r0, 0x0(r31)
	  li        r6, 0x32
	  li        r5, 0x33
	  lwz       r4, 0x84(r31)
	  li        r3, 0x34
	  li        r0, 0x35
	  lwz       r7, 0x4(r4)
	  mulli     r6, r6, 0xC
	  lwz       r8, 0x8(r7)
	  mulli     r5, r5, 0xC
	  add       r7, r8, r6
	  addi      r6, r30, 0x1C
	  stw       r6, 0x0(r7)
	  mulli     r3, r3, 0xC
	  lfs       f1, -0x4508(r2)
	  mulli     r0, r0, 0xC
	  stfs      f1, 0x4(r7)
	  lfs       f0, -0x4504(r2)
	  add       r6, r8, r5
	  addi      r5, r30, 0x34
	  stfs      f0, 0x8(r7)
	  add       r11, r8, r3
	  addi      r10, r30, 0x44
	  stw       r5, 0x0(r6)
	  add       r12, r8, r0
	  addi      r3, r30, 0x5C
	  stfs      f1, 0x4(r6)
	  li        r0, 0x1
	  li        r9, -0x1
	  lfs       f4, -0x4500(r2)
	  li        r8, 0x5
	  li        r7, 0x2
	  stfs      f4, 0x8(r6)
	  li        r6, 0xA
	  li        r5, 0x3
	  stw       r10, 0x0(r11)
	  stfs      f1, 0x4(r11)
	  stfs      f4, 0x8(r11)
	  stw       r3, 0x0(r12)
	  stfs      f1, 0x4(r12)
	  stfs      f4, 0x8(r12)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44FC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44F8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44F4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD4(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r9, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x40(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x44F0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44EC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x44E8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x44E4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44E0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44DC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44D8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44D4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44D0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44CC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x44C8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44C4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x44C0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x80(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x84(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x88(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x44BC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x8C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x44B8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x90(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r31
	  lfs       f0, -0x44B4(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x54(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x44B0(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f3, 0x4C(r4)
	  lwz       r0, 0xD4(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CA698
 * Size:	000A84
 */
TAIkabekuiAStrategy::TAIkabekuiAStrategy()
    : YaiStrategy(11, 1) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xB
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0xE0(r1)
	  stmw      r14, 0x98(r1)
	  addi      r31, r3, 0
	  bl        0x1EFA0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2624
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x1836C4
	  stw       r3, 0x94(r1)
	  lwz       r0, 0x94(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x94(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xCB4
	  lwz       r3, 0x94(r1)
	  stw       r0, 0x4(r3)

	.loc_0x70:
	  li        r3, 0x10
	  bl        -0x183708
	  stw       r3, 0x90(r1)
	  lwz       r3, 0x90(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x1DAD4
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0x90(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0xD30
	  lwz       r3, 0x90(r1)
	  stw       r0, 0x4(r3)
	  li        r0, 0x44
	  lwz       r3, 0x90(r1)
	  stw       r0, 0xC(r3)

	.loc_0xC0:
	  li        r3, 0xC
	  bl        -0x183758
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0xE10
	  li        r0, 0x1
	  stw       r3, 0x4(r28)
	  stb       r0, 0x8(r28)

	.loc_0xFC:
	  li        r3, 0x8
	  bl        -0x183794
	  stw       r3, 0x8C(r1)
	  lwz       r0, 0x8C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x140
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x8C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x8C(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6EC
	  lwz       r3, 0x8C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x140:
	  li        r3, 0xC
	  bl        -0x1837D8
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x16C
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x1DB14
	  lis       r3, 0x802E
	  subi      r0, r3, 0x720
	  stw       r0, 0x4(r23)

	.loc_0x16C:
	  li        r3, 0x10
	  bl        -0x183804
	  stw       r3, 0x88(r1)
	  lwz       r3, 0x88(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x1AC
	  li        r4, -0x1
	  li        r5, 0x4
	  bl        -0x1DBD0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  lwz       r3, 0x88(r1)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x88(r1)
	  lfs       f0, -0x4508(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x1AC:
	  li        r3, 0x8
	  bl        -0x183844
	  stw       r3, 0x84(r1)
	  lwz       r0, 0x84(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x84(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0x84(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0xEC
	  lwz       r3, 0x84(r1)
	  stw       r0, 0x4(r3)

	.loc_0x1F0:
	  li        r3, 0x8
	  bl        -0x183888
	  cmplwi    r3, 0
	  beq-      .loc_0x220
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lis       r4, 0x802E
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x124
	  stw       r0, 0x4(r3)

	.loc_0x220:
	  li        r3, 0x14
	  bl        -0x1838B8
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x268
	  li        r4, 0x3
	  li        r5, 0x4
	  bl        -0x1DC80
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  stw       r0, 0x4(r26)
	  lis       r3, 0x802E
	  subi      r3, r3, 0x3EC
	  lfs       f0, -0x44D4(r2)
	  li        r0, 0x1
	  stfs      f0, 0xC(r26)
	  stw       r3, 0x4(r26)
	  stb       r0, 0x10(r26)

	.loc_0x268:
	  li        r3, 0x8
	  bl        -0x183900
	  stw       r3, 0x80(r1)
	  lwz       r0, 0x80(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2AC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x80(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x4
	  lwz       r3, 0x80(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x510
	  lwz       r3, 0x80(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2AC:
	  li        r3, 0xC
	  bl        -0x183944
	  stw       r3, 0x7C(r1)
	  lwz       r3, 0x7C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x2E0
	  li        r4, 0x3
	  li        r5, 0x6
	  bl        -0x1DC84
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2E0:
	  li        r3, 0x8
	  bl        -0x183978
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x314
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0xC74
	  stw       r0, 0x4(r25)

	.loc_0x314:
	  li        r3, 0x10
	  bl        -0x1839AC
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0x360
	  li        r4, -0x1
	  li        r5, 0x1
	  bl        -0x1DD74
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lis       r3, 0x802E
	  stw       r0, 0x4(r20)
	  subi      r0, r3, 0xD30
	  stw       r0, 0x4(r20)
	  li        r0, 0x44
	  lis       r3, 0x802E
	  stw       r0, 0xC(r20)
	  subi      r0, r3, 0xD4C
	  stw       r0, 0x4(r20)

	.loc_0x360:
	  li        r3, 0x8
	  bl        -0x1839F8
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x394
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0x0(r18)
	  addi      r0, r3, 0x1CC
	  stw       r0, 0x4(r18)

	.loc_0x394:
	  li        r3, 0x8
	  bl        -0x183A2C
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x3C8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r14)
	  addi      r0, r3, 0x2540
	  stw       r0, 0x4(r14)

	.loc_0x3C8:
	  li        r3, 0x8
	  bl        -0x183A60
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x3FC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r22)
	  addi      r0, r3, 0x1B60
	  stw       r0, 0x4(r22)

	.loc_0x3FC:
	  li        r3, 0x8
	  bl        -0x183A94
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x430
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x7
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x478
	  stw       r0, 0x4(r16)

	.loc_0x430:
	  li        r3, 0xC
	  bl        -0x183AC8
	  stw       r3, 0x78(r1)
	  lwz       r3, 0x78(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x464
	  li        r4, 0x8
	  li        r5, 0x6
	  bl        -0x1DE08
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0x78(r1)
	  stw       r0, 0x4(r3)

	.loc_0x464:
	  li        r3, 0x14
	  bl        -0x183AFC
	  addi      r15, r3, 0
	  mr.       r3, r15
	  beq-      .loc_0x4AC
	  li        r4, 0x4
	  li        r5, 0x6
	  bl        -0x1DE38
	  lis       r3, 0x802E
	  addi      r0, r3, 0x588
	  stw       r0, 0x4(r15)
	  li        r0, 0x6
	  lis       r3, 0x802E
	  stw       r0, 0xC(r15)
	  li        r0, 0x8
	  addi      r3, r3, 0x24BC
	  stw       r0, 0x10(r15)
	  stw       r3, 0x4(r15)

	.loc_0x4AC:
	  li        r3, 0x8
	  bl        -0x183B44
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x4E0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r23)
	  addi      r0, r3, 0x1CC
	  stw       r0, 0x4(r23)

	.loc_0x4E0:
	  li        r3, 0xC
	  bl        -0x183B78
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x528
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x9
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r27)
	  addi      r0, r3, 0x23F4
	  lfs       f0, -0x44F4(r2)
	  stfs      f0, 0x8(r27)
	  stw       r0, 0x4(r27)

	.loc_0x528:
	  li        r3, 0x14
	  bl        -0x183BC0
	  addi      r17, r3, 0
	  mr.       r3, r17
	  beq-      .loc_0x570
	  li        r4, 0xA
	  li        r5, 0x5
	  bl        -0x1DF88
	  lis       r3, 0x802E
	  addi      r0, r3, 0x259C
	  stw       r0, 0x4(r17)
	  lis       r3, 0x802E
	  subi      r3, r3, 0x3EC
	  lfs       f0, -0x44D4(r2)
	  li        r0, 0
	  stfs      f0, 0xC(r17)
	  stw       r3, 0x4(r17)
	  stb       r0, 0x10(r17)

	.loc_0x570:
	  li        r3, 0xC
	  bl        -0x183C08
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x5B8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x149C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r21)
	  addi      r0, r3, 0x23AC
	  lfs       f0, -0x44F4(r2)
	  stfs      f0, 0x8(r21)
	  stw       r0, 0x4(r21)

	.loc_0x5B8:
	  li        r3, 0x8
	  bl        -0x183C50
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x5EC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r24)
	  addi      r0, r3, 0x2348
	  stw       r0, 0x4(r24)

	.loc_0x5EC:
	  li        r3, 0x8
	  bl        -0x183C84
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x620
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  addi      r0, r3, 0x2310
	  stw       r0, 0x4(r19)

	.loc_0x620:
	  li        r3, 0x10
	  bl        -0x183CB8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x670
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0xE44
	  lis       r3, 0x802E
	  stw       r0, 0x4(r30)
	  subi      r3, r3, 0xE60
	  li        r0, 0x1
	  stw       r3, 0x4(r30)
	  lfs       f0, -0x44BC(r2)
	  stfs      f0, 0x8(r30)
	  stb       r0, 0xC(r30)

	.loc_0x670:
	  li        r3, 0xC
	  bl        -0x183D08
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x68C
	  li        r4, 0x2
	  bl        -0xA3C88

	.loc_0x68C:
	  li        r0, 0
	  lwz       r4, 0x8(r29)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x90(r1)
	  stwx      r0, r4, r3
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x8C(r1)
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x0(r4)
	  bl        -0x183D54
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x6D8
	  li        r4, 0x5
	  bl        -0xA3CD4

	.loc_0x6D8:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r14, r4, r0
	  li        r0, 0x4
	  rlwinm    r6,r0,2,0,29
	  lwz       r0, 0x88(r1)
	  lwz       r4, 0x8(r29)
	  rlwinm    r3,r3,2,0,29
	  stwx      r0, r4, r3
	  rlwinm    r5,r5,2,0,29
	  lwz       r0, 0x84(r1)
	  li        r3, 0xC
	  lwz       r4, 0x8(r29)
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r23, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x4(r4)
	  bl        -0x183DD0
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x754
	  li        r4, 0x2
	  bl        -0xA3D50

	.loc_0x754:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r23)
	  li        r3, 0xC
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x8(r4)
	  bl        -0x183E14
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x798
	  li        r4, 0x2
	  bl        -0xA3D94

	.loc_0x798:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x80(r1)
	  lwz       r4, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r24, 0xC(r4)
	  bl        -0x183E5C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x7E0
	  li        r4, 0x7
	  bl        -0xA3DDC

	.loc_0x7E0:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r0, 0x2
	  li        r7, 0x5
	  stwx      r25, r4, r5
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x3
	  lwz       r6, 0x8(r29)
	  li        r4, 0x4
	  li        r5, 0x6
	  stwx      r28, r6, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r4,r5,2,0,29
	  lwz       r3, 0x8(r29)
	  lwz       r5, 0x94(r1)
	  rlwinm    r7,r7,2,0,29
	  stwx      r5, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x7C(r1)
	  lwz       r5, 0x8(r29)
	  stwx      r0, r5, r6
	  lwz       r5, 0x8(r29)
	  stwx      r18, r5, r7
	  lwz       r5, 0x8(r29)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x10(r4)
	  bl        -0x183EF8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x87C
	  li        r4, 0x2
	  bl        -0xA3E78

	.loc_0x87C:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x8C(r1)
	  lwz       r4, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x14(r4)
	  bl        -0x183F40
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x8C4
	  li        r4, 0x1
	  bl        -0xA3EC0

	.loc_0x8C4:
	  li        r0, 0
	  lwz       r3, 0x8(r23)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r23, 0x18(r4)
	  bl        -0x183F74
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x8F8
	  li        r4, 0x5
	  bl        -0xA3EF4

	.loc_0x8F8:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r28, r3, r0
	  rlwinm    r6,r5,2,0,29
	  li        r0, 0x4
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x94(r1)
	  stwx      r0, r3, r6
	  li        r3, 0xC
	  lwz       r0, 0x78(r1)
	  lwz       r6, 0x8(r29)
	  stwx      r25, r6, r5
	  lwz       r5, 0x8(r29)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x1C(r4)
	  bl        -0x183FF0
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x974
	  li        r4, 0x5
	  bl        -0xA3F70

	.loc_0x974:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x94(r1)
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r0, 0x3
	  li        r4, 0x2
	  stwx      r28, r3, r5
	  rlwinm    r3,r4,2,0,29
	  li        r5, 0x4
	  lwz       r4, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r6, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r29)
	  stwx      r25, r4, r0
	  lwz       r4, 0x8(r29)
	  stwx      r15, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r29, 0x20(r4)
	  bl        -0x184068
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x9EC
	  li        r4, 0x3
	  bl        -0xA3FE8

	.loc_0x9EC:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r14, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r17, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x8C(r1)
	  lwz       r5, 0x8(r27)
	  stwx      r0, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x24(r4)
	  bl        -0x1840C0
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xA44
	  li        r4, 0x2
	  bl        -0xA4040

	.loc_0xA44:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r26)
	  mr        r3, r31
	  stwx      r21, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x28(r4)
	  lwz       r0, 0xE4(r1)
	  lmw       r14, 0x98(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB11C
 * Size:	0006FC
 */
void TAIkabekuiAAnimation::makeDefaultAnimations()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r3
	  stw       r30, 0xD0(r1)
	  lwz       r0, 0x4(r3)
	  lis       r3, 0x802E
	  addi      r30, r3, 0x20C8
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0x70
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x27BD0
	  addi      r3, r31, 0
	  addi      r4, r30, 0x90
	  bl        -0x27BDC
	  addi      r3, r31, 0
	  addi      r4, r30, 0xB4
	  bl        -0x27BE8
	  li        r3, 0x10
	  bl        -0x184180
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x8C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x8C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1841C8
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0xD8
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0xD8:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0xD4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x27C88
	  li        r3, 0x10
	  bl        -0x184220
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x12C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x12C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x184268
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x178
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x178:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0xF4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x27D28
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17AF04
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AABC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AAD4
	  li        r3, 0x10
	  bl        -0x1842FC
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x20C
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x20C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x184348
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x25C
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x25C:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x118
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x27E0C
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17AFE8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17ABA0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17ABB8
	  li        r3, 0x10
	  bl        -0x1843E0
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x2F0
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x2F0:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18442C
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x340
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x340:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x13C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x27EF0
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17B0CC
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AC84
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AC9C
	  li        r3, 0x10
	  bl        -0x1844C4
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x3D4
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x3D4:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x184510
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x424
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x424:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x15C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x27FD4
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x17B1B0
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AD68
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AD80
	  li        r3, 0x10
	  bl        -0x1845A8
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x4B8
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x4B8:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x1845F4
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x508
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x508:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x17C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x280B8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AE40
	  li        r3, 0x10
	  bl        -0x184668
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x57C
	  li        r0, 0x1
	  stw       r0, 0x0(r7)
	  li        r3, 0x2
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x57C:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x1A0
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2812C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AEB4
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AECC
	  li        r3, 0x10
	  bl        -0x1846F4
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x604
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x604:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x184740
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x654
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x654:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x1C0
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x28204
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x17AF8C
	  li        r3, 0x10
	  bl        -0x1847B4
	  cmplwi    r3, 0
	  beq-      .loc_0x6C4
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  li        r4, 0x2
	  li        r0, 0
	  stb       r4, 0x6(r3)
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)

	.loc_0x6C4:
	  lwz       r4, 0x8(r31)
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r3)
	  stw       r5, 0x8(r3)
	  lwz       r4, 0xC(r5)
	  stw       r3, 0x8(r4)
	  stw       r3, 0xC(r5)

	.loc_0x6E4:
	  lwz       r0, 0xDC(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB818
 * Size:	000058
 */
void TAIAshadowOff::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
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
 * Address:	801CB870
 * Size:	000058
 */
void TAIAshadowOn::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9D0(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
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
 * Address:	801CB8C8
 * Size:	000018
 */
f32 TAIAsleepKabekuiA::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB8E0
 * Size:	000018
 */
f32 TAIAdiveKabekuiA::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB8F8
 * Size:	000020
 */
void TAIAattackWorkObjectKabekuiA::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1D768
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB918
 * Size:	000020
 */
bool TAIAattackWorkObjectKabekuiA::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1D74C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB938
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiA::getDamage(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xCC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB950
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiA::getAttackPointRadius(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CB968
 * Size:	00016C
 */
void TAIAattackWorkObjectKabekuiA::attackEffect(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  lis       r4, 0x736C
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6F74
	  bl        -0x14227C
	  mr.       r31, r3
	  beq-      .loc_0x154
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD4
	  mr        r3, r31
	  bl        -0x143C18
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  subi      r4, r4, 0x1
	  bl        -0x143BCC
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x4F
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2EE9C
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  lfs       f0, 0x1D88(r13)
	  lfs       f1, 0x1D8C(r13)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x1D90(r13)
	  stfs      f1, 0x24(r1)
	  stfs      f0, 0x28(r1)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0xA8:
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x7E
	  bl        -0x141468
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0xD4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x34
	  addi      r3, r3, 0x70
	  bl        -0x148038

	.loc_0xD4:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x154
	  cmpwi     r0, 0x3
	  bne-      .loc_0x154
	  mr        r3, r31
	  bl        -0x143CC4
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  subi      r4, r4, 0x1
	  bl        -0x143C78
	  mr        r4, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0x50
	  li        r6, 0
	  li        r7, 0
	  bl        -0x2EF48
	  cmplwi    r3, 0
	  beq-      .loc_0x154
	  lfs       f0, 0x1D94(r13)
	  lfs       f1, 0x1D98(r13)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x1D9C(r13)
	  stfs      f1, 0x18(r1)
	  stfs      f0, 0x1C(r1)
	  lwz       r4, 0x14(r1)
	  lwz       r0, 0x18(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x154:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801CBAD4
 * Size:	000034
 */
void TAIAinvincibleOn::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9B4(r13)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
