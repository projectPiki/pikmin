#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80199414
 * Size:	000060
 */
void GameCourseClearScreen::menuQuitGame(Menu &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  addi      r3, r4, 0
  lwz       r12, 0x0(r4)
  lwz       r12, 0x4C(r12)
  mtlr      r12
  blrl      
  li        r0, 0x1
  stw       r0, 0x1F0(r31)
  li        r0, 0xB
  stw       r0, 0x1F4(r31)
  lwz       r3, 0x2DEC(r13)
  lfs       f0, -0x4CD8(r2)
  stfs      f0, 0x8(r3)
  lfs       f0, -0x4CD4(r2)
  stfs      f0, 0xC(r3)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80199474
 * Size:	000D38
 */
GameCourseClearSection::GameCourseClearSection()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  stwu      r1, -0xE8(r1)
  stmw      r23, 0xC4(r1)
  addi      r31, r4, 0x6320
  addi      r30, r3, 0
  addi      r4, r13, 0xE84
  bl        -0x1644DC
  lis       r3, 0x8023
  subi      r25, r3, 0x71E0
  stw       r25, 0x0(r30)
  addi      r3, r30, 0
  addi      r4, r13, 0xE84
  bl        -0x158D70
  lis       r3, 0x802A
  addi      r0, r3, 0x642C
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x69F0
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  addi      r4, r31, 0x44
  bl        -0x158D94
  lwz       r4, 0x2DEC(r13)
  li        r26, 0x1
  lis       r3, 0x803A
  stw       r26, 0x14(r4)
  subi      r4, r3, 0x24E0
  li        r27, 0
  stw       r27, 0x24C(r4)
  li        r3, 0x554
  stw       r27, 0x250(r4)
  bl        -0x1524F4
  addi      r29, r3, 0
  mr.       r0, r29
  beq-      .loc_0xC6C
  stw       r29, 0x94(r1)
  addi      r4, r13, 0xE84
  lwz       r3, 0x94(r1)
  bl        -0x16455C
  lwz       r28, 0x94(r1)
  addi      r4, r13, 0xE84
  stw       r25, 0x0(r28)
  mr        r3, r28
  bl        -0x158DEC
  lis       r3, 0x802D
  addi      r0, r3, 0x6980
  stw       r0, 0x0(r28)
  addi      r3, r1, 0x88
  addi      r4, r13, 0xE8C
  stw       r27, 0x20(r28)
  bl        -0x148A6C
  lwz       r0, 0x88(r1)
  addi      r5, r1, 0x20
  addi      r3, r28, 0x24
  stw       r0, 0x20(r1)
  addi      r4, r28, 0x20
  bl        -0x13AADC
  lis       r3, 0x802A
  addi      r0, r3, 0x6098
  stw       r0, 0x2C(r28)
  addi      r3, r1, 0x90
  addi      r4, r13, 0xE90
  lfs       f0, -0x4CD0(r2)
  stfs      f0, 0x30(r28)
  bl        -0x148AA4
  lwz       r0, 0x90(r1)
  addi      r5, r1, 0x1C
  addi      r3, r28, 0x34
  stw       r0, 0x1C(r1)
  addi      r4, r28, 0x20
  bl        -0x13AB14
  lis       r3, 0x802A
  addi      r0, r3, 0x60C4
  stw       r0, 0x3C(r28)
  lis       r3, 0x802D
  addi      r8, r3, 0x68DC
  stw       r26, 0x40(r28)
  addi      r3, r28, 0x48
  addi      r0, r28, 0x54
  stw       r8, 0x48(r28)
  stw       r3, 0x50(r28)
  stw       r3, 0x4C(r28)
  stw       r3, 0x44(r28)
  lwz       r5, 0x44(r28)
  stw       r5, 0x8(r5)
  lwz       r3, 0x44(r28)
  stw       r5, 0x4(r3)
  stw       r0, 0x80(r1)
  lwz       r24, 0x80(r1)
  stw       r8, 0x4(r24)
  addi      r0, r24, 0x4
  addi      r6, r24, 0x14
  stw       r0, 0xC(r24)
  addi      r5, r24, 0x14
  addi      r4, r24, 0x24
  stw       r0, 0x8(r24)
  addi      r3, r24, 0x24
  stw       r0, 0x0(r24)
  addi      r0, r24, 0x34
  lwz       r9, 0x0(r24)
  stw       r9, 0x8(r9)
  lwz       r7, 0x0(r24)
  stw       r9, 0x4(r7)
  stw       r8, 0x14(r24)
  stw       r6, 0x1C(r24)
  stw       r6, 0x18(r24)
  stw       r5, 0x10(r24)
  lwz       r6, 0x10(r24)
  stw       r6, 0x8(r6)
  lwz       r5, 0x10(r24)
  stw       r6, 0x4(r5)
  stw       r8, 0x24(r24)
  stw       r4, 0x2C(r24)
  stw       r4, 0x28(r24)
  stw       r3, 0x20(r24)
  lwz       r4, 0x20(r24)
  stw       r4, 0x8(r4)
  lwz       r3, 0x20(r24)
  stw       r4, 0x4(r3)
  stw       r0, 0x18(r1)
  lwz       r3, 0x18(r1)
  bl        0xDF8
  lwz       r26, 0x18(r1)
  addi      r3, r26, 0x10
  bl        0xDEC
  stw       r27, 0x20(r26)
  addi      r23, r24, 0x60
  addi      r3, r23, 0
  stw       r27, 0x24(r26)
  bl        0xDD8
  stw       r27, 0x10(r23)
  addi      r23, r28, 0xF4
  addi      r3, r1, 0x78
  stw       r27, 0x30(r24)
  li        r4, 0
  li        r5, 0
  stw       r27, 0x5C(r24)
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x19F80
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x78
  addi      r3, r23, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x17304
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r23)
  addi      r3, r28, 0x208
  stb       r27, 0xEC(r23)
  stw       r27, 0xF0(r23)
  stw       r27, 0xF4(r23)
  bl        -0x156524
  addi      r0, r31, 0x60
  stw       r0, 0x4(r28)
  li        r3, 0x50
  bl        -0x1526F4
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x2C8
  addi      r3, r24, 0
  addi      r4, r31, 0x78
  bl        -0x164758
  stw       r25, 0x0(r24)
  addi      r3, r24, 0
  addi      r4, r31, 0x78
  bl        -0x158FE4
  lis       r3, 0x8023
  subi      r0, r3, 0x714C
  stw       r0, 0x0(r24)
  addi      r3, r24, 0
  li        r4, 0x1
  bl        -0x158D88

.loc_0x2C8:
  lwz       r25, 0x94(r1)
  li        r0, 0
  addi      r4, r31, 0x88
  stw       r24, 0x200(r25)
  li        r5, 0x1
  stw       r0, 0x1F0(r25)
  lwz       r3, 0x2DEC(r13)
  bl        -0x15A650
  addi      r24, r3, 0
  li        r3, 0x10
  bl        -0x152760
  stw       r3, 0x204(r25)
  addi      r4, r24, 0
  li        r5, 0x15
  lwz       r3, 0x204(r25)
  li        r6, 0x2A
  bl        -0x171AC4
  li        r3, 0xB4
  bl        -0x152780
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x334
  lwz       r5, 0x2DEC(r13)
  li        r6, 0
  lwz       r4, 0x200(r25)
  lwz       r5, 0x10(r5)
  bl        -0x13C0AC

.loc_0x334:
  lwz       r28, 0x94(r1)
  li        r3, 0x14
  stw       r24, 0x1F8(r28)
  lwz       r0, -0x7848(r13)
  lwz       r4, 0x1F8(r28)
  srawi     r0, r0, 0x1
  addze     r0, r0
  stw       r0, 0x48(r4)
  lwz       r0, -0x7844(r13)
  lwz       r4, 0x1F8(r28)
  srawi     r0, r0, 0x1
  addze     r0, r0
  stw       r0, 0x4C(r4)
  bl        -0x1527D8
  cmplwi    r3, 0
  beq-      .loc_0x3C4
  lwz       r0, 0x2C(r31)
  lis       r5, 0x802A
  lwz       r6, 0x30(r31)
  lis       r4, 0x802A
  addi      r5, r5, 0x65F0
  stw       r0, 0x98(r1)
  addi      r0, r4, 0x7A80
  stw       r6, 0x9C(r1)
  lwz       r4, 0x34(r31)
  stw       r4, 0xA0(r1)
  lwz       r4, 0x1F8(r28)
  stw       r5, 0x0(r3)
  stw       r0, 0x0(r3)
  stw       r4, 0x4(r3)
  lwz       r4, 0x98(r1)
  lwz       r0, 0x9C(r1)
  stw       r4, 0x8(r3)
  stw       r0, 0xC(r3)
  lwz       r0, 0xA0(r1)
  stw       r0, 0x10(r3)

.loc_0x3C4:
  lwz       r25, 0x94(r1)
  addi      r6, r3, 0
  li        r4, 0x20
  lwz       r3, 0x1F8(r25)
  li        r5, 0x2000
  bl        -0x13BEF8
  li        r3, 0x14
  bl        -0x152850
  cmplwi    r3, 0
  beq-      .loc_0x438
  lwz       r0, 0x38(r31)
  lis       r5, 0x802A
  lwz       r6, 0x3C(r31)
  lis       r4, 0x802D
  addi      r5, r5, 0x65F0
  stw       r0, 0xA4(r1)
  addi      r0, r4, 0x6894
  stw       r6, 0xA8(r1)
  lwz       r4, 0x40(r31)
  stw       r4, 0xAC(r1)
  stw       r5, 0x0(r3)
  stw       r0, 0x0(r3)
  stw       r25, 0x4(r3)
  lwz       r4, 0xA4(r1)
  lwz       r0, 0xA8(r1)
  stw       r4, 0x8(r3)
  stw       r0, 0xC(r3)
  lwz       r0, 0xAC(r1)
  stw       r0, 0x10(r3)

.loc_0x438:
  lwz       r26, 0x94(r1)
  addi      r6, r3, 0
  li        r4, 0
  lwz       r3, 0x1F8(r26)
  addi      r5, r13, 0xE94
  li        r7, 0x1
  bl        -0x13BDA8
  li        r25, 0
  stw       r25, 0x1FC(r26)
  lis       r0, 0xB
  li        r3, 0x8
  lwz       r4, 0x2DEC(r13)
  lfs       f0, -0x4CCC(r2)
  stfs      f0, 0x8(r4)
  lfs       f0, -0x4CD4(r2)
  stfs      f0, 0xC(r4)
  stw       r0, 0x1F4(r26)
  bl        -0x1528EC
  addi      r26, r3, 0
  mr.       r23, r26
  beq-      .loc_0x4CC
  li        r0, 0x3
  stw       r0, 0x0(r26)
  lwz       r0, 0x0(r26)
  rlwinm    r3,r0,2,0,29
  bl        -0x15290C
  stw       r3, 0x4(r26)
  addi      r4, r25, 0
  addi      r5, r25, 0
  b         .loc_0x4C0

.loc_0x4B0:
  lwz       r3, 0x4(r23)
  addi      r4, r4, 0x1
  stwx      r25, r3, r5
  addi      r5, r5, 0x4

.loc_0x4C0:
  lwz       r0, 0x0(r23)
  cmplw     r4, r0
  blt+      .loc_0x4B0

.loc_0x4CC:
  lwz       r3, 0x94(r1)
  li        r24, 0
  stw       r26, 0x1EC(r3)

.loc_0x4D8:
  li        r3, 0x200
  bl        -0x15294C
  addi      r26, r3, 0
  mr.       r3, r26
  beq-      .loc_0x4F0
  bl        0x970

.loc_0x4F0:
  lwz       r25, 0x94(r1)
  mr        r4, r24
  mr        r5, r26
  lwz       r3, 0x1EC(r25)
  bl        0x40714
  addi      r24, r24, 0x1
  cmpwi     r24, 0x3
  blt+      .loc_0x4D8
  lwz       r3, 0x1EC(r25)
  bl        0x40750
  li        r3, 0x10
  bl        -0x15298C
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x534
  li        r4, 0xF
  bl        0x8B4

.loc_0x534:
  lwz       r4, 0x94(r1)
  li        r3, 0x10
  stw       r24, 0x550(r4)
  bl        -0x1529B0
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x5AC
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0x94
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r4, 0x1
  addi      r0, r3, 0x6828
  stw       r4, 0x4(r24)
  li        r3, 0x1B4
  stw       r0, 0x0(r24)
  bl        -0x1529EC
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x598
  addi      r3, r25, 0
  li        r4, 0
  bl        0x5B6C0

.loc_0x598:
  stw       r25, 0xC(r24)
  lwz       r3, 0xC(r24)
  bl        0x5BA00
  lis       r0, 0x1
  stw       r0, 0x4(r24)

.loc_0x5AC:
  lwz       r3, 0x94(r1)
  li        r0, 0
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x5D0
  stwx      r24, r3, r4

.loc_0x5D0:
  li        r3, 0x168
  bl        -0x152A44
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x620
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0xA8
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x67FC
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x5BA7C
  addi      r3, r24, 0xC
  bl        0x5BD70
  stw       r25, 0x4(r24)

.loc_0x620:
  lwz       r3, 0x94(r1)
  li        r0, 0x1
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x644
  stwx      r24, r3, r4

.loc_0x644:
  li        r3, 0x58
  bl        -0x152AB8
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x694
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0xBC
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x67D0
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x58B64
  addi      r3, r24, 0xC
  bl        0x58EC8
  stw       r25, 0x4(r24)

.loc_0x694:
  lwz       r3, 0x94(r1)
  li        r0, 0x2
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x6B8
  stwx      r24, r3, r4

.loc_0x6B8:
  li        r3, 0x5C
  bl        -0x152B2C
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x708
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0xD0
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x67A8
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x581F4
  addi      r3, r24, 0xC
  bl        0x585F0
  stw       r25, 0x4(r24)

.loc_0x708:
  lwz       r3, 0x94(r1)
  li        r0, 0x3
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x72C
  stwx      r24, r3, r4

.loc_0x72C:
  li        r3, 0x60
  bl        -0x152BA0
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x77C
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0xE0
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x677C
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x56EA0
  addi      r3, r24, 0xC
  bl        0x5754C
  stw       r25, 0x4(r24)

.loc_0x77C:
  lwz       r3, 0x94(r1)
  li        r0, 0x4
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x7A0
  stwx      r24, r3, r4

.loc_0x7A0:
  li        r3, 0xA0
  bl        -0x152C14
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x7E8
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0xEC
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x6754
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x52C84
  stw       r25, 0x4(r24)

.loc_0x7E8:
  lwz       r3, 0x94(r1)
  li        r0, 0x5
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x80C
  stwx      r24, r3, r4

.loc_0x80C:
  li        r3, 0xCC
  bl        -0x152C80
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x824
  bl        .loc_0xD38

.loc_0x824:
  lwz       r3, 0x94(r1)
  li        r0, 0x6
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x848
  stwx      r24, r3, r4

.loc_0x848:
  li        r3, 0x374
  bl        -0x152CBC
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x8A8
  lis       r3, 0x802D
  stw       r24, 0x4C(r1)
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  lis       r3, 0x802D
  addi      r4, r31, 0x110
  lwz       r26, 0x4C(r1)
  lis       r25, 0x1
  addi      r0, r3, 0x6724
  stw       r4, 0x8(r26)
  addi      r3, r26, 0xC
  stw       r25, 0x4(r26)
  stw       r0, 0x0(r26)
  bl        0x41448
  addi      r3, r26, 0xC
  li        r4, 0
  li        r5, 0
  bl        0x47158
  stw       r25, 0x4(r26)

.loc_0x8A8:
  lwz       r3, 0x94(r1)
  li        r0, 0x7
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x8CC
  stwx      r24, r3, r4

.loc_0x8CC:
  li        r3, 0x18
  bl        -0x152D40
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x91C
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0x120
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x66F8
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x4FF78
  addi      r3, r24, 0xC
  bl        0x50018
  stw       r25, 0x4(r24)

.loc_0x91C:
  lwz       r3, 0x94(r1)
  li        r0, 0x8
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x940
  stwx      r24, r3, r4

.loc_0x940:
  li        r3, 0x1F0
  bl        -0x152DB4
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0x9BC
  lis       r3, 0x802D
  stw       r24, 0x40(r1)
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  lis       r3, 0x802D
  addi      r4, r31, 0x140
  lwz       r26, 0x40(r1)
  lis       r25, 0x1
  addi      r0, r3, 0x66D0
  stw       r4, 0x8(r26)
  addi      r3, r26, 0x10
  stw       r25, 0x4(r26)
  stw       r0, 0x0(r26)
  bl        0x20804
  li        r0, 0
  stw       r0, 0xC(r26)
  addi      r3, r26, 0x10
  li        r4, 0
  li        r5, 0
  li        r6, 0
  li        r7, 0
  li        r8, 0
  li        r9, 0
  li        r10, 0
  bl        0x237AC
  stw       r25, 0x4(r26)

.loc_0x9BC:
  lwz       r3, 0x94(r1)
  li        r0, 0x9
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0x9E0
  stwx      r24, r3, r4

.loc_0x9E0:
  li        r3, 0x2C
  bl        -0x152E54
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0xA40
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0x154
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x66A4
  stw       r25, 0x4(r24)
  addi      r3, r24, 0x10
  stw       r0, 0x0(r24)
  bl        0x4EA6C
  li        r0, 0
  stw       r0, 0xC(r24)
  addi      r3, r24, 0x10
  li        r4, 0x1
  lfs       f1, -0x4CC8(r2)
  bl        0x4EF20
  stw       r25, 0x4(r24)

.loc_0xA40:
  lwz       r3, 0x94(r1)
  li        r0, 0xA
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0xA64
  stwx      r24, r3, r4

.loc_0xA64:
  li        r3, 0x48
  bl        -0x152ED8
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0xAC4
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0x164
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x6678
  stw       r25, 0x4(r24)
  addi      r3, r24, 0x10
  stw       r0, 0x0(r24)
  bl        0x4DB98
  lfs       f1, -0x4CD8(r2)
  addi      r3, r24, 0x10
  addi      r4, r24, 0xC
  stfs      f1, 0xC(r24)
  lfs       f2, -0x4CCC(r2)
  bl        0x4DD88
  stw       r25, 0x4(r24)

.loc_0xAC4:
  lwz       r3, 0x94(r1)
  li        r0, 0xB
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0xAE8
  stwx      r24, r3, r4

.loc_0xAE8:
  li        r3, 0x1C
  bl        -0x152F5C
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0xB38
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0x174
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x664C
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  stw       r0, 0x0(r24)
  bl        0x402B4
  addi      r3, r24, 0xC
  bl        0x40538
  stw       r25, 0x4(r24)

.loc_0xB38:
  lwz       r3, 0x94(r1)
  li        r0, 0xC
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0xB5C
  stwx      r24, r3, r4

.loc_0xB5C:
  li        r3, 0x28
  bl        -0x152FD0
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0xBC8
  lis       r3, 0x802D
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  addi      r0, r31, 0x18C
  lis       r3, 0x802D
  stw       r0, 0x8(r24)
  lis       r25, 0x1
  addi      r0, r3, 0x6620
  stw       r25, 0x4(r24)
  addi      r3, r24, 0xC
  li        r4, 0
  stw       r0, 0x0(r24)
  bl        0x1C324
  lfs       f1, -0x4CC4(r2)
  addi      r3, r24, 0xC
  li        r4, 0x1
  bl        0x1EAA0
  lfs       f1, -0x4CC4(r2)
  addi      r3, r24, 0xC
  li        r4, 0x1
  bl        0x1EB8C
  stw       r25, 0x4(r24)

.loc_0xBC8:
  lwz       r3, 0x94(r1)
  li        r0, 0xD
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0xBEC
  stwx      r24, r3, r4

.loc_0xBEC:
  li        r3, 0x160
  bl        -0x153060
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0xC48
  lis       r3, 0x802D
  stw       r24, 0x28(r1)
  addi      r0, r3, 0x6838
  stw       r0, 0x0(r24)
  lis       r3, 0x802D
  addi      r4, r31, 0x198
  lwz       r26, 0x28(r1)
  lis       r25, 0x1
  addi      r0, r3, 0x65F4
  stw       r4, 0x8(r26)
  addi      r3, r26, 0xC
  stw       r25, 0x4(r26)
  stw       r0, 0x0(r26)
  bl        0x263F4
  addi      r3, r26, 0xC
  li        r4, 0x1
  bl        0x26800
  stw       r25, 0x4(r26)

.loc_0xC48:
  lwz       r3, 0x94(r1)
  li        r0, 0xE
  rlwinm    r4,r0,2,0,29
  lwz       r3, 0x550(r3)
  lwz       r3, 0xC(r3)
  lwzx      r0, r3, r4
  cmplwi    r0, 0
  bne-      .loc_0xC6C
  stwx      r24, r3, r4

.loc_0xC6C:
  mr        r27, r29
  lfs       f1, -0x4CC0(r2)
  addi      r3, r27, 0x54
  li        r4, 0xA
  li        r5, 0xFF1
  li        r6, 0xFF1
  bl        0x7008
  lfs       f0, 0xE78(r13)
  addi      r24, r1, 0xB4
  lfs       f1, 0xE7C(r13)
  addi      r4, r31, 0x1BC
  stfs      f0, 0xB4(r1)
  lfs       f0, 0xE80(r13)
  li        r5, 0x1
  stfs      f1, 0xB8(r1)
  lwz       r3, 0x2DEC(r13)
  stfs      f0, 0xBC(r1)
  bl        -0x15B01C
  mr        r26, r3
  lwz       r3, 0x2DEC(r13)
  addi      r4, r31, 0x1BC
  li        r5, 0x1
  bl        -0x15B030
  addi      r25, r3, 0
  addi      r3, r27, 0x44
  addi      r4, r31, 0x1A4
  li        r5, 0x1
  bl        0x6DD8
  addi      r4, r3, 0
  addi      r5, r25, 0
  addi      r6, r26, 0
  addi      r7, r24, 0
  addi      r3, r27, 0x54
  li        r8, 0
  li        r9, 0
  bl        0x711C
  addi      r3, r27, 0xF4
  addi      r4, r31, 0x1D4
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0x1
  bl        0x18A7C
  addi      r3, r30, 0
  addi      r4, r27, 0
  bl        -0x159BB8
  mr        r3, r30
  lmw       r23, 0xC4(r1)
  lwz       r0, 0xEC(r1)
  addi      r1, r1, 0xE8
  mtlr      r0
  blr       

.loc_0xD38:
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
zen::DrawHurryUp::~DrawHurryUp()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
zen::DrawContainer::~DrawContainer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019A1AC
 * Size:	0000AC
 */
CMresultMode::CMresultMode()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x6838
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lis       r31, 0x1
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x650C
  lis       r3, 0x802D
  stw       r0, 0x8(r30)
  addi      r0, r3, 0x65CC
  addi      r3, r30, 0xC
  stw       r31, 0x4(r30)
  stw       r0, 0x0(r30)
  bl        0x54974
  stw       r31, 0x4(r30)
  li        r0, 0x3
  li        r4, 0
  stw       r0, 0xAC(r30)
  li        r0, 0x2
  li        r3, 0x3D6
  stw       r4, 0xB0(r30)
  li        r6, 0x1B0
  li        r5, 0x161
  stw       r0, 0xB4(r30)
  li        r4, 0xDD
  li        r0, 0x7B
  stw       r3, 0xB8(r30)
  mr        r3, r30
  stw       r6, 0xBC(r30)
  stw       r5, 0xC0(r30)
  stw       r4, 0xC4(r30)
  stw       r0, 0xC8(r30)
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
 * Address:	8019A258
 * Size:	000078
 */
GameModeMgr::GameModeMgr(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  stw       r4, 0x8(r3)
  lwz       r0, 0x8(r3)
  rlwinm    r3,r0,2,0,29
  bl        -0x153274
  li        r5, 0
  stw       r3, 0xC(r31)
  addi      r4, r5, 0
  li        r6, 0
  b         .loc_0x48

.loc_0x38:
  lwz       r3, 0xC(r31)
  addi      r6, r6, 0x1
  stwx      r4, r3, r5
  addi      r5, r5, 0x4

.loc_0x48:
  lwz       r0, 0x8(r31)
  cmpw      r6, r0
  blt+      .loc_0x38
  li        r0, 0
  stw       r0, 0x0(r31)
  mr        r3, r31
  stw       r0, 0x4(r31)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A2D0
 * Size:	000188
 */
zen::particleGenerator::particleGenerator()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802D
  stw       r0, 0x4(r1)
  addi      r9, r4, 0x68DC
  li        r4, 0
  stwu      r1, -0x18(r1)
  li        r5, 0
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  stw       r3, 0x8(r1)
  lis       r3, 0x802D
  addi      r0, r3, 0x6590
  lwz       r30, 0x8(r1)
  stw       r9, 0x0(r30)
  addi      r8, r30, 0x2C
  addi      r7, r30, 0x2C
  stw       r30, 0x8(r30)
  addi      r6, r30, 0x3C
  addi      r3, r30, 0
  stw       r30, 0x4(r30)
  stw       r0, 0x0(r30)
  addi      r0, r30, 0x3C
  lfs       f0, -0x4CD8(r2)
  stfs      f0, 0x14(r30)
  stfs      f0, 0x10(r30)
  stfs      f0, 0xC(r30)
  stfs      f0, 0x24(r30)
  stfs      f0, 0x20(r30)
  stfs      f0, 0x1C(r30)
  stw       r9, 0x2C(r30)
  stw       r8, 0x34(r30)
  stw       r8, 0x30(r30)
  stw       r7, 0x28(r30)
  lwz       r8, 0x28(r30)
  stw       r8, 0x8(r8)
  lwz       r7, 0x28(r30)
  stw       r8, 0x4(r7)
  stw       r9, 0x3C(r30)
  stw       r6, 0x44(r30)
  stw       r6, 0x40(r30)
  stw       r0, 0x38(r30)
  lwz       r7, 0x38(r30)
  stw       r7, 0x8(r7)
  lwz       r6, 0x38(r30)
  stw       r7, 0x4(r6)
  stb       r31, 0x48(r30)
  stb       r31, 0x49(r30)
  stb       r31, 0x4A(r30)
  stb       r31, 0x4B(r30)
  stw       r31, 0x4C(r30)
  stw       r31, 0x50(r30)
  stw       r31, 0x54(r30)
  stfs      f0, 0x9C(r30)
  stfs      f0, 0x98(r30)
  stfs      f0, 0x94(r30)
  stfs      f0, 0xA8(r30)
  stfs      f0, 0xA4(r30)
  stfs      f0, 0xA0(r30)
  stfs      f0, 0xB4(r30)
  stfs      f0, 0xB0(r30)
  stfs      f0, 0xAC(r30)
  stfs      f0, 0x134(r30)
  stfs      f0, 0x130(r30)
  stfs      f0, 0x12C(r30)
  stfs      f0, 0x140(r30)
  stfs      f0, 0x13C(r30)
  stfs      f0, 0x138(r30)
  stfs      f0, 0x14C(r30)
  stfs      f0, 0x148(r30)
  stfs      f0, 0x144(r30)
  stfs      f0, 0x168(r30)
  stfs      f0, 0x164(r30)
  stfs      f0, 0x160(r30)
  stfs      f0, 0x178(r30)
  stfs      f0, 0x174(r30)
  stfs      f0, 0x170(r30)
  stfs      f0, 0x188(r30)
  stfs      f0, 0x184(r30)
  stfs      f0, 0x180(r30)
  stfs      f0, 0x19C(r30)
  stfs      f0, 0x198(r30)
  stfs      f0, 0x194(r30)
  stfs      f0, 0x1E4(r30)
  stfs      f0, 0x1E0(r30)
  stfs      f0, 0x1DC(r30)
  bl        0x58E8
  stw       r31, 0x1D4(r30)
  mr        r3, r30
  stw       r31, 0x1D8(r30)
  stw       r31, 0x84(r30)
  stw       r31, 0x80(r30)
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
 * Size:	000040
 */
zen::bBoardColourAnimData::~bBoardColourAnimData()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
zen::particleManager::~particleManager()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
zen::simplePtclManager::~simplePtclManager()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
zen::particleMdlManager::~particleMdlManager()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019A458
 * Size:	000030
 */
zen::zenListManager::zenListManager()
{
/*
.loc_0x0:
  lis       r4, 0x802D
  addi      r0, r4, 0x68DC
  stw       r0, 0x4(r3)
  addi      r0, r3, 0x4
  stw       r0, 0xC(r3)
  stw       r0, 0x8(r3)
  stw       r0, 0x0(r3)
  lwz       r5, 0x0(r3)
  stw       r5, 0x8(r5)
  lwz       r4, 0x0(r3)
  stw       r5, 0x4(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
zen::particleLoader::~particleLoader()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
zen::zenListManager::~zenListManager()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019A488
 * Size:	000040
 */
void zen::particleGenerator::remove()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r0, 0x4(r3)
  lwz       r6, 0x8(r3)
  stw       r0, 0x4(r6)
  lwz       r0, 0x8(r3)
  lwz       r6, 0x4(r3)
  stw       r0, 0x8(r6)
  bl        0x585C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A4C8
 * Size:	000084
 */
void CMresultMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF518C
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x58
  addi      r3, r29, 0xC
  addi      r4, r29, 0xAC
  bl        0x55254

.loc_0x58:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x55094
  mr        r3, r31
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
 * Address:	8019A54C
 * Size:	000024
 */
void CMresultMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x5517C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A570
 * Size:	000080
 */
void HurryUpMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5234
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x58
  addi      r3, r29, 0xC
  li        r4, 0x1
  bl        0x262F0

.loc_0x58:
  addi      r3, r29, 0xC
  bl        0x267B8
  mr        r3, r31
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
 * Address:	8019A5F0
 * Size:	000024
 */
void HurryUpMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x26A44
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A614
 * Size:	0000C0
 */
void GameInfoMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF52D8
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x6C
  lfs       f1, -0x4CC4(r2)
  addi      r3, r29, 0xC
  li        r4, 0x1
  bl        0x1E458
  lfs       f1, -0x4CC4(r2)
  addi      r3, r29, 0xC
  li        r4, 0x1
  bl        0x1E544

.loc_0x6C:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,17,17
  beq-      .loc_0x98
  lfs       f1, -0x4CC4(r2)
  addi      r3, r29, 0xC
  li        r4, 0x1
  bl        0x1E4A8
  lfs       f1, -0x4CC4(r2)
  addi      r3, r29, 0xC
  li        r4, 0x1
  bl        0x1E5C8

.loc_0x98:
  addi      r3, r29, 0xC
  bl        0x1DED0
  mr        r3, r31
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
 * Address:	8019A6D4
 * Size:	000024
 */
void GameInfoMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x1E2F0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A6F8
 * Size:	000080
 */
void ProgressiveMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF53BC
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  addi      r3, r29, 0xC
  bl        0x3FD94

.loc_0x54:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x3FDD8
  mr        r3, r31
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
 * Address:	8019A778
 * Size:	000024
 */
void ProgressiveMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x40044
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A79C
 * Size:	0000E4
 */
void CountDownMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5460
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,19,19
  beq-      .loc_0x54
  lfs       f0, -0x4CD8(r2)
  stfs      f0, 0xC(r29)

.loc_0x54:
  lwz       r0, 0x20(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x70
  lfs       f1, 0xC(r29)
  lfs       f0, -0x4CBC(r2)
  fadds     f0, f1, f0
  stfs      f0, 0xC(r29)

.loc_0x70:
  lwz       r0, 0x20(r30)
  rlwinm.   r0,r0,0,17,17
  beq-      .loc_0x8C
  lfs       f1, 0xC(r29)
  lfs       f0, -0x4CBC(r2)
  fsubs     f0, f1, f0
  stfs      f0, 0xC(r29)

.loc_0x8C:
  lfs       f1, 0xC(r29)
  lfs       f0, -0x4CD8(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xA4
  lfs       f0, -0x4CCC(r2)
  stfs      f0, 0xC(r29)

.loc_0xA4:
  lfs       f1, 0xC(r29)
  lfs       f0, -0x4CCC(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xBC
  lfs       f0, -0x4CD8(r2)
  stfs      f0, 0xC(r29)

.loc_0xBC:
  addi      r3, r29, 0x10
  bl        0x4D604
  mr        r3, r31
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
 * Address:	8019A880
 * Size:	000024
 */
void CountDownMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x10
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x4E040
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A8A4
 * Size:	0000D4
 */
void GameOverMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5568
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0xA8
  lwz       r3, 0xC(r29)
  addi      r0, r3, 0x1
  cmpwi     r0, 0x1
  stw       r0, 0xC(r29)
  ble-      .loc_0x68
  li        r0, 0
  stw       r0, 0xC(r29)

.loc_0x68:
  lwz       r0, 0xC(r29)
  cmpwi     r0, 0x1
  beq-      .loc_0x98
  bge-      .loc_0xA8
  cmpwi     r0, 0
  bge-      .loc_0x84
  b         .loc_0xA8

.loc_0x84:
  lfs       f1, -0x4CC8(r2)
  addi      r3, r29, 0x10
  li        r4, 0x1
  bl        0x4E498
  b         .loc_0xA8

.loc_0x98:
  lfs       f1, -0x4CC8(r2)
  addi      r3, r29, 0x10
  li        r4, 0
  bl        0x4E484

.loc_0xA8:
  addi      r3, r29, 0x10
  addi      r4, r30, 0
  bl        0x4E694
  mr        r3, r31
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
 * Address:	8019A978
 * Size:	000024
 */
void GameOverMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x10
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x4EC8C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019A99C
 * Size:	000130
 */
void ContainerMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  li        r31, 0
  stw       r30, 0x28(r1)
  addi      r30, r4, 0
  stw       r29, 0x24(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5660
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x104
  lwz       r3, 0xC(r29)
  addi      r0, r3, 0x1
  cmplwi    r0, 0x2
  stw       r0, 0xC(r29)
  ble-      .loc_0x68
  li        r0, 0
  stw       r0, 0xC(r29)

.loc_0x68:
  lwz       r0, 0xC(r29)
  cmpwi     r0, 0x1
  beq-      .loc_0xB8
  bge-      .loc_0x84
  cmpwi     r0, 0
  bge-      .loc_0x90
  b         .loc_0x104

.loc_0x84:
  cmpwi     r0, 0x3
  bge-      .loc_0x104
  b         .loc_0xE0

.loc_0x90:
  addi      r3, r29, 0x10
  li        r4, 0
  li        r5, 0
  li        r6, 0
  li        r7, 0
  li        r8, 0
  li        r9, 0
  li        r10, 0
  bl        0x22B88
  b         .loc_0x104

.loc_0xB8:
  addi      r3, r29, 0x10
  li        r4, 0x1
  li        r5, 0
  li        r6, 0
  li        r7, 0
  li        r8, 0
  li        r9, 0
  li        r10, 0
  bl        0x22B60
  b         .loc_0x104

.loc_0xE0:
  addi      r3, r29, 0x10
  li        r4, 0x2
  li        r5, 0
  li        r6, 0
  li        r7, 0
  li        r8, 0
  li        r9, 0
  li        r10, 0
  bl        0x22B38

.loc_0x104:
  addi      r3, r29, 0x10
  addi      r4, r1, 0x18
  bl        0x23DA0
  mr        r3, r31
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AACC
 * Size:	000024
 */
void ContainerMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x10
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x2465C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AAF0
 * Size:	000080
 */
void WMPauseMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF57B4
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  addi      r3, r29, 0xC
  bl        0x4F260

.loc_0x54:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x4F2B4
  mr        r3, r31
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
 * Address:	8019AB70
 * Size:	000024
 */
void WMPauseMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x4F3FC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AB94
 * Size:	000088
 */
void WorldMapMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5858
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,17,17
  beq-      .loc_0x5C
  addi      r3, r29, 0xC
  li        r4, 0x4
  li        r5, 0x2
  bl        0x46280

.loc_0x5C:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x43B1C
  mr        r3, r31
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
 * Address:	8019AC1C
 * Size:	000024
 */
void WorldMapMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x4610C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AC40
 * Size:	000090
 */
void CMcourseSelectMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5904
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  addi      r3, r29, 0xC
  bl        0x52074

.loc_0x54:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x5237C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x70
  addi      r3, r29, 0xC
  bl        0x5255C

.loc_0x70:
  mr        r3, r31
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
 * Address:	8019ACD0
 * Size:	000024
 */
void CMcourseSelectMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x52498
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019ACF4
 * Size:	000080
 */
void HiScoreMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF59B8
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  addi      r3, r29, 0xC
  bl        0x563F0

.loc_0x54:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x56108
  mr        r3, r31
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
 * Address:	8019AD74
 * Size:	000024
 */
void HiScoreMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x56200
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AD98
 * Size:	000080
 */
void UfoPartsMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5A5C
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  addi      r3, r29, 0xC
  bl        0x5737C

.loc_0x54:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x57058
  mr        r3, r31
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
 * Address:	8019AE18
 * Size:	000024
 */
void UfoPartsMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x57154
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AE3C
 * Size:	0000B0
 */
void SaveMesMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5B00
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x70
  lwz       r0, 0xC(r29)
  cmpwi     r0, 0x3
  beq-      .loc_0x5C
  b         .loc_0x68

.loc_0x5C:
  addi      r3, r29, 0xC
  bl        0x57B7C
  b         .loc_0x70

.loc_0x68:
  addi      r3, r29, 0xC
  bl        0x57B20

.loc_0x70:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,17,17
  beq-      .loc_0x84
  addi      r3, r29, 0xC
  bl        0x57BA4

.loc_0x84:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x57BBC
  mr        r3, r31
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
 * Address:	8019AEEC
 * Size:	000024
 */
void SaveMesMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x5842C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AF10
 * Size:	000080
 */
void SaveFailureMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5BD4
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  addi      r3, r29, 0xC
  bl        0x5A89C

.loc_0x54:
  addi      r3, r29, 0xC
  addi      r4, r30, 0
  bl        0x5A5E0
  mr        r3, r31
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
 * Address:	8019AF90
 * Size:	000024
 */
void SaveFailureMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x5A734
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019AFB4
 * Size:	000080
 */
void FinalResultMode::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  lwz       r0, 0x4(r3)
  lwz       r3, 0x2C(r4)
  and.      r0, r3, r0
  beq-      .loc_0x40
  li        r3, 0x11D
  bl        -0xF5C78
  li        r31, 0x1

.loc_0x40:
  lwz       r0, 0x2C(r30)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x54
  lwz       r3, 0xC(r29)
  bl        0x5A410

.loc_0x54:
  lwz       r3, 0xC(r29)
  mr        r4, r30
  bl        0x5A128
  mr        r3, r31
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
 * Address:	8019B034
 * Size:	000024
 */
void FinalResultMode::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0xC(r3)
  bl        0x5A298
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019B058
 * Size:	000040
 */
void GameModeBase::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r4, 0x2C(r4)
  lwz       r0, 0x4(r3)
  and.      r0, r4, r0
  beq-      .loc_0x2C
  li        r3, 0x11D
  bl        -0xF5D08
  li        r5, 0x1

.loc_0x2C:
  mr        r3, r5
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019B098
 * Size:	000004
 */
void GameModeBase::draw(Graphics &)
{
}

/*
 * --INFO--
 * Address:	8019B09C
 * Size:	000154
 */
void GameCourseClearScreen::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  mr        r30, r3
  lwz       r3, 0x200(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  addi      r3, r30, 0xF4
  bl        0x17A84
  lwz       r3, 0x1FC(r30)
  cmplwi    r3, 0
  beq-      .loc_0x5C
  lwz       r12, 0x0(r3)
  li        r4, 0
  lwz       r12, 0x50(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x1FC(r30)
  b         .loc_0xCC

.loc_0x5C:
  lwz       r0, 0x1F0(r30)
  cmplwi    r0, 0
  bne-      .loc_0x84
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  li        r0, 0
  stw       r0, 0x33C(r3)
  mr        r3, r30
  bl        -0x15A9B4
  b         .loc_0xCC

.loc_0x84:
  cmplwi    r0, 0x1
  bne-      .loc_0xCC
  cmplwi    r3, 0
  bne-      .loc_0xCC
  lwz       r3, 0x2DEC(r13)
  lfs       f1, -0x4CD8(r2)
  lfs       f0, 0x4(r3)
  fcmpu     cr0, f1, f0
  bne-      .loc_0xCC
  li        r0, -0x1
  lis       r3, 0x803A
  stw       r0, 0x1F0(r30)
  subi      r4, r3, 0x2848
  lwz       r3, 0x1FC(r4)
  li        r0, 0x1
  stw       r3, 0x1F4(r4)
  lwz       r3, 0x2DEC(r13)
  stb       r0, 0x0(r3)

.loc_0xCC:
  lwz       r31, 0x550(r30)
  lwz       r4, 0x200(r30)
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0x1
  beq-      .loc_0x10C
  bge-      .loc_0x13C
  cmpwi     r0, 0
  bge-      .loc_0xF0
  b         .loc_0x13C

.loc_0xF0:
  mr        r3, r31
  bl        .loc_0x154
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x13C
  li        r0, 0x1
  stw       r0, 0x0(r31)
  b         .loc_0x13C

.loc_0x10C:
  lwz       r0, 0x4(r31)
  lwz       r3, 0xC(r31)
  rlwinm    r0,r0,2,0,29
  lwzx      r3, r3, r0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x13C
  li        r0, 0
  stw       r0, 0x0(r31)

.loc_0x13C:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr       

.loc_0x154:
*/
}

/*
 * --INFO--
 * Address:	8019B1F0
 * Size:	0000A8
 */
void GameModeMgr::updateSelect(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  li        r9, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r8, 0x2C(r4)
  lwz       r7, 0x4(r3)
  rlwinm    r0,r8,0,12,12
  neg       r6, r0
  subic     r5, r6, 0x1
  rlwinm    r0,r8,0,10,10
  subfe     r6, r5, r6
  neg       r5, r0
  subic     r0, r5, 0x1
  subfe     r0, r0, r5
  rlwinm    r5,r6,0,24,31
  rlwinm    r0,r0,0,24,31
  sub       r0, r0, r5
  add       r0, r7, r0
  stw       r0, 0x4(r3)
  lwz       r5, 0x4(r3)
  cmpwi     r5, 0
  bge-      .loc_0x64
  lwz       r0, 0x8(r3)
  add       r0, r5, r0
  stw       r0, 0x4(r3)

.loc_0x64:
  lwz       r0, 0x4(r3)
  lwz       r5, 0x8(r3)
  cmpw      r0, r5
  blt-      .loc_0x7C
  sub       r0, r0, r5
  stw       r0, 0x4(r3)

.loc_0x7C:
  lwz       r0, 0x2C(r4)
  rlwinm.   r0,r0,0,19,19
  beq-      .loc_0x94
  li        r3, 0x111
  bl        -0xF5F08
  li        r9, 0x1

.loc_0x94:
  mr        r3, r9
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019B298
 * Size:	000358
 */
void GameCourseClearScreen::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x468(r1)
  stmw      r26, 0x450(r1)
  li        r26, 0
  mr        r31, r4
  mr        r30, r3
  mr        r3, r31
  lwz       r5, 0x310(r4)
  lwz       r0, 0x30C(r4)
  addi      r4, r1, 0x4C
  stw       r26, 0x4C(r1)
  stw       r26, 0x50(r1)
  stw       r0, 0x54(r1)
  stw       r5, 0x58(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x48(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x310(r31)
  addi      r4, r1, 0x3C
  lwz       r0, 0x30C(r31)
  mr        r3, r31
  stw       r26, 0x3C(r1)
  stw       r26, 0x40(r1)
  stw       r0, 0x44(r1)
  stw       r5, 0x48(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x50(r12)
  mtlr      r12
  blrl      
  stb       r26, 0x38(r1)
  li        r27, 0xFF
  addi      r4, r1, 0x38
  stb       r26, 0x39(r1)
  mr        r3, r31
  stb       r26, 0x3A(r1)
  stb       r27, 0x3B(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xB4(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0x3
  li        r5, 0
  lwz       r12, 0x38(r12)
  mtlr      r12
  blrl      
  lwz       r6, 0x310(r31)
  addi      r5, r1, 0x28
  lwz       r0, 0x30C(r31)
  mr        r3, r31
  addi      r4, r1, 0x3FC
  stw       r26, 0x28(r1)
  stw       r26, 0x2C(r1)
  stw       r0, 0x30(r1)
  stw       r6, 0x34(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  li        r28, 0x40
  stb       r28, 0x24(r1)
  li        r29, 0xC0
  addi      r4, r1, 0x24
  stb       r28, 0x25(r1)
  mr        r3, r31
  li        r5, 0x1
  stb       r29, 0x26(r1)
  stb       r27, 0x27(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  stb       r29, 0x20(r1)
  addi      r4, r1, 0x20
  addi      r3, r31, 0
  stb       r28, 0x21(r1)
  stb       r27, 0x22(r1)
  stb       r27, 0x23(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x310(r31)
  addi      r4, r1, 0x10
  lwz       r0, 0x30C(r31)
  mr        r3, r31
  stw       r26, 0x10(r1)
  stw       r26, 0x14(r1)
  stw       r0, 0x18(r1)
  stw       r5, 0x1C(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xD4(r12)
  mtlr      r12
  blrl      
  addi      r3, r1, 0xB4
  bl        -0x15825C
  lfs       f1, 0xE60(r13)
  addi      r3, r1, 0xB4
  lfs       f0, 0xE6C(r13)
  addi      r4, r1, 0x68
  stfs      f1, 0x68(r1)
  lfs       f1, 0xE64(r13)
  addi      r5, r1, 0x5C
  stfs      f0, 0x5C(r1)
  lfs       f0, 0xE70(r13)
  stfs      f1, 0x6C(r1)
  lfs       f1, 0xE68(r13)
  stfs      f0, 0x60(r1)
  lfs       f0, 0xE74(r13)
  stfs      f1, 0x70(r1)
  stfs      f0, 0x64(r1)
  bl        -0x1586BC
  lwz       r5, 0x30C(r31)
  lis       r4, 0x4330
  lwz       r0, 0x310(r31)
  addi      r3, r1, 0xB4
  xoris     r5, r5, 0x8000
  xoris     r0, r0, 0x8000
  stw       r5, 0x44C(r1)
  lfd       f5, -0x4CB0(r2)
  stw       r0, 0x444(r1)
  lfs       f2, -0x4CC0(r2)
  stw       r4, 0x448(r1)
  lfs       f3, -0x4CCC(r2)
  stw       r4, 0x440(r1)
  lfd       f1, 0x448(r1)
  lfd       f0, 0x440(r1)
  fsubs     f1, f1, f5
  lfs       f4, -0x4CB8(r2)
  fsubs     f0, f0, f5
  fdivs     f1, f1, f0
  bl        -0x15885C
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0xB4
  lwz       r12, 0x6C(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x3B4(r31)
  lis       r4, 0x803A
  mr        r3, r31
  lwz       r12, 0x70(r12)
  subi      r4, r4, 0x77C0
  addi      r5, r1, 0x74
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0x280(r1)
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x314
  lfs       f2, 0x278(r1)
  lwz       r12, 0x3C(r12)
  lfs       f3, 0x284(r1)
  mtlr      r12
  lfs       f4, 0x288(r1)
  lfs       f5, -0x4CCC(r2)
  blrl      
  mr        r3, r31
  lwz       r4, 0x2E4(r31)
  lwz       r12, 0x3B4(r31)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0xCC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x550(r30)
  lwz       r5, 0x204(r30)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0x308
  bge-      .loc_0x32C
  cmpwi     r0, 0
  bge-      .loc_0x2FC
  b         .loc_0x32C

.loc_0x2FC:
  mr        r4, r31
  bl        .loc_0x358
  b         .loc_0x32C

.loc_0x308:
  lwz       r0, 0x4(r3)
  mr        r4, r31
  lwz       r3, 0xC(r3)
  rlwinm    r0,r0,2,0,29
  lwzx      r3, r3, r0
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      

.loc_0x32C:
  lwz       r3, 0x1FC(r30)
  cmplwi    r3, 0
  beq-      .loc_0x344
  lfs       f1, -0x4CCC(r2)
  mr        r4, r31
  bl        -0x13D1C8

.loc_0x344:
  lmw       r26, 0x450(r1)
  lwz       r0, 0x46C(r1)
  addi      r1, r1, 0x468
  mtlr      r0
  blr       

.loc_0x358:
*/
}

/*
 * --INFO--
 * Address:	8019B5F0
 * Size:	0001BC
 */
void GameModeMgr::drawSelect(Graphics &, Font *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stmw      r20, 0x80(r1)
  li        r27, 0
  mr        r24, r4
  mr        r23, r3
  addi      r3, r24, 0
  addi      r25, r5, 0
  lwz       r6, 0x310(r4)
  lwz       r0, 0x30C(r4)
  addi      r4, r1, 0x30
  addi      r5, r4, 0
  stw       r27, 0x30(r1)
  addi      r4, r1, 0x40
  stw       r27, 0x34(r1)
  stw       r0, 0x38(r1)
  stw       r6, 0x3C(r1)
  lwz       r12, 0x3B4(r24)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  addi      r29, r1, 0x24
  addi      r28, r1, 0x20
  addi      r31, r1, 0x2C
  addi      r30, r1, 0x28
  li        r26, 0
  b         .loc_0x19C

.loc_0x70:
  lwz       r0, 0x4(r23)
  cmpw      r0, r26
  bne-      .loc_0xE0
  li        r20, 0xC0
  stb       r20, 0x2C(r1)
  li        r22, 0x40
  li        r21, 0xFF
  stb       r22, 0x2D(r1)
  addi      r3, r24, 0
  addi      r4, r31, 0
  stb       r21, 0x2E(r1)
  li        r5, 0x1
  stb       r21, 0x2F(r1)
  lwz       r12, 0x3B4(r24)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  stb       r22, 0x28(r1)
  addi      r3, r24, 0
  addi      r4, r30, 0
  stb       r22, 0x29(r1)
  stb       r20, 0x2A(r1)
  stb       r21, 0x2B(r1)
  lwz       r12, 0x3B4(r24)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  b         .loc_0x144

.loc_0xE0:
  li        r21, 0xC0
  stb       r21, 0x24(r1)
  li        r22, 0xFF
  addi      r3, r24, 0
  stb       r22, 0x25(r1)
  addi      r4, r29, 0
  li        r5, 0x1
  stb       r22, 0x26(r1)
  stb       r22, 0x27(r1)
  lwz       r12, 0x3B4(r24)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  li        r0, 0xC8
  stb       r0, 0x20(r1)
  li        r0, 0xD7
  addi      r3, r24, 0
  stb       r0, 0x21(r1)
  mr        r4, r28
  stb       r21, 0x22(r1)
  stb       r22, 0x23(r1)
  lwz       r12, 0x3B4(r24)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      

.loc_0x144:
  lwz       r4, 0xC(r23)
  mr        r3, r25
  lwz       r20, 0x8(r25)
  lwzx      r4, r4, r27
  lwz       r21, 0x8(r4)
  mr        r4, r21
  bl        -0x173618
  mullw     r6, r26, r20
  lwz       r12, 0x3B4(r24)
  crclr     6, 0x6
  lwz       r12, 0xEC(r12)
  mtlr      r12
  srawi     r0, r3, 0x1
  addze     r0, r0
  addi      r3, r24, 0
  subfic    r5, r0, 0x140
  addi      r4, r25, 0
  addi      r7, r21, 0
  addi      r6, r6, 0x46
  blrl      
  addi      r27, r27, 0x4
  addi      r26, r26, 0x1

.loc_0x19C:
  lwz       r0, 0x8(r23)
  cmpw      r26, r0
  blt+      .loc_0x70
  lmw       r20, 0x80(r1)
  lwz       r0, 0xB4(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019B7AC
 * Size:	000024
 */
void GameCourseClearScreen::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x20
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x13CC24
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019B7D0
 * Size:	000004
 */
void GameCourseClearSection::init()
{
}

/*
 * --INFO--
 * Address:	8019B7D4
 * Size:	000030
 */
void Delegate1<GameCourseClearScreen, Menu &>::invoke(Menu &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r5, r3
  stw       r0, 0x4(r1)
  addi      r12, r5, 0x8
  stwu      r1, -0x8(r1)
  lwz       r3, 0x4(r3)
  bl        0x79544
  nop       
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
