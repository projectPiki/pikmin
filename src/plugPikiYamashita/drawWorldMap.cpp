#include "types.h"

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
 * Address:	........
 * Size:	000040
 */
zen::DrawWorldMap::~DrawWorldMap()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801DB14C
 * Size:	00246C
 */
zen::DrawWorldMap::DrawWorldMap()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x4B0(r1)
	  stmw      r17, 0x474(r1)
	  addi      r26, r3, 0
	  lis       r3, 0x802E
	  addi      r17, r3, 0x57B0
	  addi      r3, r26, 0x64
	  bl        0xEB8C
	  addi      r3, r26, 0x74
	  bl        -0x4B058
	  li        r3, 0x4C4
	  bl        -0x194178
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x50
	  li        r4, 0x60
	  li        r5, 0x1F4
	  li        r6, 0x28A
	  bl        0xE728

	.loc_0x50:
	  stw       r18, 0x50(r26)
	  li        r3, 0x100
	  lwz       r0, 0x50(r26)
	  stw       r0, 0x31C0(r13)
	  bl        -0x1941A8
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x84
	  addi      r4, r17, 0x24
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BC58

	.loc_0x84:
	  stw       r18, 0x10(r26)
	  li        r3, 0x100
	  bl        -0x1941D4
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0xB0
	  addi      r4, r17, 0x3C
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BC84

	.loc_0xB0:
	  stw       r18, 0x14(r26)
	  li        r3, 0x100
	  bl        -0x194200
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0xDC
	  addi      r4, r17, 0x54
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BCB0

	.loc_0xDC:
	  stw       r18, 0x18(r26)
	  li        r3, 0x100
	  bl        -0x19422C
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x108
	  addi      r4, r17, 0x6C
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BCDC

	.loc_0x108:
	  stw       r18, 0x1C(r26)
	  li        r3, 0x100
	  bl        -0x194258
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x134
	  addi      r4, r17, 0x84
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD08

	.loc_0x134:
	  stw       r18, 0x20(r26)
	  li        r3, 0x100
	  bl        -0x194284
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x160
	  addi      r4, r17, 0x9C
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD34

	.loc_0x160:
	  stw       r18, 0x24(r26)
	  li        r3, 0x100
	  bl        -0x1942B0
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x18C
	  addi      r4, r17, 0xB4
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD60

	.loc_0x18C:
	  stw       r18, 0x28(r26)
	  li        r3, 0x100
	  bl        -0x1942DC
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x1B8
	  addi      r4, r17, 0xCC
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BD8C

	.loc_0x1B8:
	  stw       r18, 0x2C(r26)
	  li        r3, 0x100
	  bl        -0x194308
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x1E4
	  addi      r4, r17, 0xE4
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1BDB8

	.loc_0x1E4:
	  stw       r18, 0x30(r26)
	  li        r0, -0x1
	  li        r3, 0x138
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r26)
	  stw       r0, 0x4(r26)
	  stw       r0, 0x8(r26)
	  bl        -0x194348
	  addi      r18, r3, 0
	  mr.       r5, r18
	  beq-      .loc_0x23C
	  lis       r3, 0x801E
	  subi      r4, r3, 0x1924
	  addi      r3, r5, 0x8
	  li        r5, 0
	  li        r6, 0x3C
	  li        r7, 0x5
	  bl        0x396FC
	  li        r0, 0
	  stw       r0, 0x4(r18)
	  stw       r0, 0x134(r18)
	  stw       r0, 0x0(r18)

	.loc_0x23C:
	  stw       r18, 0x38(r26)
	  li        r23, 0
	  lwz       r4, 0x2C(r26)
	  lwz       r3, 0x28(r26)
	  lwz       r27, 0x38(r26)
	  addi      r28, r4, 0x4
	  addi      r25, r3, 0x4
	  stw       r23, 0x134(r27)
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  addi      r24, r27, 0x8
	  lis       r22, 0x78
	  lis       r21, 0x785F
	  lis       r20, 0x706F
	  lis       r19, 0x736C
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r22, 0x5F31
	  addi      r6, r21, 0x3173
	  addi      r7, r20, 0x3031
	  addi      r9, r19, 0x6931
	  bl        0x3170
	  addi      r0, r27, 0xF8
	  stw       r0, 0x2C(r24)
	  addi      r29, r27, 0x44
	  addi      r18, r27, 0xBC
	  stw       r29, 0x30(r24)
	  li        r4, 0x3
	  stw       r23, 0x34(r24)
	  stw       r18, 0x38(r24)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15B8C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x304
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r22, 0x5F32
	  addi      r6, r21, 0x3273
	  addi      r7, r20, 0x3032
	  addi      r9, r19, 0x6932
	  bl        0x3120
	  stw       r24, 0x2C(r29)
	  addi      r0, r27, 0x80
	  stw       r23, 0x30(r29)
	  stw       r23, 0x34(r29)
	  stw       r0, 0x38(r29)
	  b         .loc_0x338

	.loc_0x304:
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r22, 0x5F32
	  addi      r6, r21, 0x3273
	  addi      r7, r20, 0x3032
	  addi      r9, r19, 0x6932
	  bl        0x30E8
	  stw       r18, 0x2C(r29)
	  addi      r0, r27, 0x80
	  stw       r23, 0x30(r29)
	  stw       r23, 0x34(r29)
	  stw       r0, 0x38(r29)

	.loc_0x338:
	  addi      r19, r27, 0x80
	  lis       r29, 0x78
	  lis       r24, 0x785F
	  lis       r23, 0x706F
	  lis       r22, 0x736C
	  addi      r3, r19, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r29, 0x5F33
	  addi      r6, r24, 0x3373
	  addi      r7, r23, 0x3033
	  addi      r9, r22, 0x6933
	  bl        0x30A0
	  addi      r18, r27, 0xBC
	  stw       r18, 0x2C(r19)
	  li        r21, 0
	  addi      r20, r27, 0x44
	  stw       r21, 0x30(r19)
	  li        r4, 0x3
	  stw       r20, 0x34(r19)
	  stw       r21, 0x38(r19)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15B998
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3D8
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r29, 0x5F34
	  addi      r6, r24, 0x3473
	  addi      r7, r23, 0x3034
	  addi      r9, r22, 0x6934
	  bl        0x3050
	  addi      r0, r27, 0xF8
	  stw       r0, 0x2C(r18)
	  addi      r0, r27, 0x8
	  stw       r19, 0x30(r18)
	  stw       r0, 0x34(r18)
	  stw       r21, 0x38(r18)
	  b         .loc_0x40C

	.loc_0x3D8:
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r29, 0x5F34
	  addi      r6, r24, 0x3473
	  addi      r7, r23, 0x3034
	  addi      r9, r22, 0x6934
	  bl        0x3014
	  addi      r0, r27, 0xF8
	  stw       r0, 0x2C(r18)
	  stw       r19, 0x30(r18)
	  stw       r20, 0x34(r18)
	  stw       r21, 0x38(r18)

	.loc_0x40C:
	  addi      r18, r27, 0xF8
	  lis       r5, 0x78
	  lis       r6, 0x785F
	  lis       r7, 0x706F
	  lis       r9, 0x736C
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r5, 0x5F35
	  addi      r6, r6, 0x3573
	  addi      r7, r7, 0x3035
	  addi      r9, r9, 0x6935
	  bl        0x2FCC
	  li        r4, 0
	  stw       r4, 0x2C(r18)
	  addi      r3, r27, 0xBC
	  addi      r0, r27, 0x8
	  stw       r3, 0x30(r18)
	  stw       r0, 0x34(r18)
	  stw       r4, 0x38(r18)
	  b         .loc_0x574

	.loc_0x460:
	  addi      r29, r27, 0x8
	  lis       r24, 0x78
	  lis       r31, 0x785F
	  lis       r30, 0x706F
	  lis       r18, 0x736C
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F31
	  addi      r6, r31, 0x3173
	  addi      r7, r30, 0x3031
	  addi      r9, r18, 0x6931
	  bl        0x2F78
	  addi      r22, r27, 0xF8
	  stw       r22, 0x2C(r29)
	  addi      r19, r27, 0x44
	  addi      r21, r27, 0xBC
	  stw       r19, 0x30(r29)
	  addi      r3, r19, 0
	  addi      r4, r25, 0
	  stw       r23, 0x34(r29)
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F32
	  stw       r21, 0x38(r29)
	  addi      r6, r31, 0x3273
	  addi      r7, r30, 0x3032
	  addi      r9, r18, 0x6932
	  bl        0x2F3C
	  stw       r29, 0x2C(r19)
	  addi      r20, r27, 0x80
	  addi      r3, r20, 0
	  stw       r23, 0x30(r19)
	  addi      r4, r25, 0
	  addi      r8, r28, 0
	  stw       r23, 0x34(r19)
	  addi      r5, r24, 0x5F33
	  addi      r6, r31, 0x3373
	  stw       r20, 0x38(r19)
	  addi      r7, r30, 0x3033
	  addi      r9, r18, 0x6933
	  bl        0x2F08
	  stw       r21, 0x2C(r20)
	  mr        r3, r21
	  addi      r4, r25, 0
	  stw       r23, 0x30(r20)
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F34
	  stw       r19, 0x34(r20)
	  addi      r6, r31, 0x3473
	  addi      r7, r30, 0x3034
	  stw       r23, 0x38(r20)
	  addi      r9, r18, 0x6934
	  bl        0x2ED8
	  stw       r22, 0x2C(r21)
	  mr        r3, r22
	  addi      r4, r25, 0
	  stw       r20, 0x30(r21)
	  addi      r8, r28, 0
	  addi      r5, r24, 0x5F35
	  stw       r29, 0x34(r21)
	  addi      r6, r31, 0x3573
	  addi      r7, r30, 0x3035
	  stw       r23, 0x38(r21)
	  addi      r9, r18, 0x6935
	  bl        0x2EA8
	  stw       r23, 0x2C(r22)
	  stw       r21, 0x30(r22)
	  stw       r29, 0x34(r22)
	  stw       r23, 0x38(r22)

	.loc_0x574:
	  addi      r28, r13, 0x2470
	  addi      r18, r28, 0
	  addi      r19, r27, 0
	  li        r22, 0

	.loc_0x584:
	  lbz       r21, 0x0(r18)
	  addi      r3, r1, 0x45C
	  addi      r5, r22, 0x1
	  crclr     6, 0x6
	  addi      r4, r13, 0x2610
	  bl        0x3AEB4
	  addi      r3, r1, 0x464
	  crclr     6, 0x6
	  addi      r5, r22, 0x1
	  addi      r4, r13, 0x2618
	  bl        0x3AEA0
	  lwz       r12, 0x0(r25)
	  mr        r3, r25
	  lbz       r6, 0x465(r1)
	  addi      r20, r19, 0x8
	  lbz       r0, 0x45D(r1)
	  lwz       r12, 0x34(r12)
	  rlwinm    r7,r6,16,0,15
	  lbz       r8, 0x464(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r4, 0x45C(r1)
	  lbz       r5, 0x45E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r9, 0x466(r1)
	  rlwimi    r0,r5,8,16,23
	  lbz       r6, 0x45F(r1)
	  rlwimi    r7,r8,24,0,7
	  lbz       r10, 0x467(r1)
	  rlwimi    r7,r9,8,16,23
	  or        r4, r6, r0
	  or        r23, r10, r7
	  li        r5, 0x1
	  blrl
	  stw       r3, 0x24(r20)
	  addi      r3, r25, 0
	  addi      r4, r23, 0
	  lwz       r12, 0x0(r25)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r20)
	  stw       r21, 0x18(r19)
	  lbz       r0, 0x14(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x678
	  lwz       r3, 0x14(r20)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r20)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r20)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x678:
	  addi      r23, r19, 0x8
	  li        r4, 0x1
	  stb       r4, 0x14(r19)
	  li        r20, 0
	  lwz       r3, 0x1C(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x24(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r19)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x728
	  mr        r4, r21
	  bl        -0x15BCE0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x728
	  stb       r20, 0xC(r23)
	  lwz       r3, 0x14(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x1C(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r23)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r20,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x728:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x5
	  addi      r18, r18, 0x1
	  addi      r19, r19, 0x3C
	  blt+      .loc_0x584
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r27, r0
	  stw       r0, 0x4(r27)
	  lwz       r6, 0x4(r27)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x798
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x798:
	  li        r3, 0xB0
	  bl        -0x1948E4
	  addi      r18, r3, 0
	  mr.       r5, r18
	  beq-      .loc_0x7E0
	  lis       r3, 0x801E
	  subi      r4, r3, 0x1AE0
	  addi      r3, r5, 0xC
	  li        r5, 0
	  li        r6, 0x28
	  li        r7, 0x4
	  bl        0x39160
	  lfs       f0, -0x4188(r2)
	  li        r0, 0
	  stfs      f0, 0x4(r18)
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0x8(r18)
	  stb       r0, 0xAC(r18)

	.loc_0x7E0:
	  stw       r18, 0x58(r26)
	  lis       r18, 0x7770
	  addi      r5, r18, 0x3030
	  lwz       r3, 0x10(r26)
	  lwz       r19, 0x58(r26)
	  addi      r20, r3, 0x4
	  addi      r4, r20, 0
	  addi      r3, r19, 0xC
	  bl        0x2A70
	  addi      r4, r20, 0
	  addi      r3, r19, 0x34
	  addi      r5, r18, 0x3031
	  bl        0x2A60
	  addi      r4, r20, 0
	  addi      r3, r19, 0x5C
	  addi      r5, r18, 0x3032
	  bl        0x2A50
	  addi      r4, r20, 0
	  addi      r3, r19, 0x84
	  addi      r5, r18, 0x3033
	  bl        0x2A40
	  lfs       f0, -0x4188(r2)
	  li        r18, 0
	  li        r3, 0x24
	  stfs      f0, 0x4(r19)
	  lfs       f0, -0x4180(r2)
	  stfs      f0, 0x8(r19)
	  stb       r18, 0xAC(r19)
	  bl        -0x194998
	  cmplwi    r3, 0
	  beq-      .loc_0x88C
	  li        r0, 0x2
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  stw       r0, 0x8(r3)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x0(r3)
	  stb       r18, 0x20(r3)
	  stw       r18, 0xC(r3)
	  stw       r18, 0x10(r3)
	  stw       r18, 0x14(r3)
	  stw       r18, 0x18(r3)
	  stw       r18, 0x1C(r3)

	.loc_0x88C:
	  stw       r3, 0x54(r26)
	  lis       r3, 0x6D69
	  addi      r4, r3, 0x5F31
	  lwz       r3, 0x1C(r26)
	  li        r5, 0x1
	  lwz       r18, 0x54(r26)
	  addi      r19, r3, 0x4
	  addi      r3, r19, 0
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x8CC
	  stw       r3, 0xC(r18)

	.loc_0x8CC:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F32
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x8FC
	  stw       r3, 0x10(r18)

	.loc_0x8FC:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F33
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x92C
	  stw       r3, 0x14(r18)

	.loc_0x92C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F34
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x95C
	  stw       r3, 0x18(r18)

	.loc_0x95C:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6D69
	  addi      r4, r4, 0x5F35
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x98C
	  stw       r3, 0x1C(r18)

	.loc_0x98C:
	  mr        r3, r18
	  bl        0x2828
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x9E8
	  bl        -0x15AE84
	  stw       r3, 0x3C(r26)
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15AE88
	  stw       r3, 0x40(r26)
	  li        r4, 0
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15BEE0
	  stw       r3, 0x44(r26)
	  li        r4, 0x1
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15BEF0
	  stw       r3, 0x48(r26)
	  li        r4, 0x2
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15BF00
	  stw       r3, 0x4C(r26)
	  b         .loc_0xA08

	.loc_0x9E8:
	  li        r0, 0x1E
	  stw       r0, 0x3C(r26)
	  li        r3, 0x1D
	  li        r0, 0x3E7
	  stw       r3, 0x40(r26)
	  stw       r0, 0x44(r26)
	  stw       r0, 0x48(r26)
	  stw       r0, 0x4C(r26)

	.loc_0xA08:
	  lwz       r3, 0x20(r26)
	  lis       r19, 0x6463
	  lwzu      r12, 0x4(r3)
	  addi      r4, r19, 0x5F63
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x20(r26)
	  addi      r18, r3, 0
	  li        r5, 0x1
	  lwz       r12, 0x4(r4)
	  addi      r3, r4, 0x4
	  addi      r4, r19, 0x5F6C
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x20(r26)
	  addi      r20, r3, 0
	  li        r5, 0x1
	  lwz       r12, 0x4(r4)
	  addi      r3, r4, 0x4
	  addi      r4, r19, 0x5F72
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r21, r3, 0
	  li        r3, 0x10
	  bl        -0x194BC0
	  mr.       r19, r3
	  beq-      .loc_0xB04
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  li        r4, 0
	  li        r5, 0x10
	  bl        -0x2B4E8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C50C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5A08
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B4E8
	  addi      r4, r20, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B4F8
	  addi      r4, r21, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B508
	  stw       r18, 0x4(r19)
	  mr        r3, r19
	  stw       r20, 0x8(r19)
	  stw       r21, 0xC(r19)
	  bl        0x2554

	.loc_0xB04:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B5BC
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x726F
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x194C84
	  mr.       r19, r3
	  beq-      .loc_0xC4C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B5AC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C5D0
	  addi      r0, r26, 0x40
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xBF0
	  addi      r3, r19, 0x4
	  bl        -0x5D2B8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xC1C
	  stw       r0, 0xEC(r18)
	  b         .loc_0xC1C

	.loc_0xBF0:
	  addi      r3, r19, 0x4
	  bl        -0x5D2E8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xC1C
	  stw       r0, 0xEC(r18)

	.loc_0xC1C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0xC4C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B704
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x726F
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x194DCC
	  mr.       r19, r3
	  beq-      .loc_0xD94
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B6F4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C718
	  addi      r0, r26, 0x40
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xD38
	  addi      r3, r19, 0x4
	  bl        -0x5D400
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xD64
	  stw       r0, 0xEC(r18)
	  b         .loc_0xD64

	.loc_0xD38:
	  addi      r3, r19, 0x4
	  bl        -0x5D430
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xD64
	  stw       r0, 0xEC(r18)

	.loc_0xD64:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0xD94:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B84C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7274
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x194F14
	  mr.       r19, r3
	  beq-      .loc_0xEDC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B83C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C860
	  addi      r0, r26, 0x3C
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xE80
	  addi      r3, r19, 0x4
	  bl        -0x5D548
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xEAC
	  stw       r0, 0xEC(r18)
	  b         .loc_0xEAC

	.loc_0xE80:
	  addi      r3, r19, 0x4
	  bl        -0x5D578
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xEAC
	  stw       r0, 0xEC(r18)

	.loc_0xEAC:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0xEDC:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2B994
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7274
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x19505C
	  mr.       r19, r3
	  beq-      .loc_0x1024
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2B984
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1C9A8
	  addi      r0, r26, 0x3C
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC8
	  addi      r3, r19, 0x4
	  bl        -0x5D690
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xFF4
	  stw       r0, 0xEC(r18)
	  b         .loc_0xFF4

	.loc_0xFC8:
	  addi      r3, r19, 0x4
	  bl        -0x5D6C0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0xFF4
	  stw       r0, 0xEC(r18)

	.loc_0xFF4:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1024:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BADC
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x6270
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x1951A4
	  mr.       r19, r3
	  beq-      .loc_0x116C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BACC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CAF0
	  addi      r0, r26, 0x44
	  stw       r0, 0x4(r19)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1110
	  addi      r3, r19, 0x4
	  bl        -0x5D7D8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x113C
	  stw       r0, 0xEC(r18)
	  b         .loc_0x113C

	.loc_0x1110:
	  addi      r3, r19, 0x4
	  bl        -0x5D808
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x113C
	  stw       r0, 0xEC(r18)

	.loc_0x113C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x116C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BC24
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x6270
	  addi      r4, r3, 0x5F63
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x1952EC
	  mr.       r19, r3
	  beq-      .loc_0x12B4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BC14
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CC38
	  addi      r0, r26, 0x44
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1258
	  addi      r3, r19, 0x4
	  bl        -0x5D920
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1284
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1284

	.loc_0x1258:
	  addi      r3, r19, 0x4
	  bl        -0x5D950
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1284
	  stw       r0, 0xEC(r18)

	.loc_0x1284:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x12B4:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BD6C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x6270
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195434
	  mr.       r19, r3
	  beq-      .loc_0x13FC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BD5C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CD80
	  addi      r0, r26, 0x44
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x13A0
	  addi      r3, r19, 0x4
	  bl        -0x5DA68
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x13CC
	  stw       r0, 0xEC(r18)
	  b         .loc_0x13CC

	.loc_0x13A0:
	  addi      r3, r19, 0x4
	  bl        -0x5DA98
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x13CC
	  stw       r0, 0xEC(r18)

	.loc_0x13CC:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x13FC:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BEB4
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7270
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x19557C
	  mr.       r19, r3
	  beq-      .loc_0x1544
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BEA4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1CEC8
	  addi      r0, r26, 0x48
	  stw       r0, 0x4(r19)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x14E8
	  addi      r3, r19, 0x4
	  bl        -0x5DBB0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1514
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1514

	.loc_0x14E8:
	  addi      r3, r19, 0x4
	  bl        -0x5DBE0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1514
	  stw       r0, 0xEC(r18)

	.loc_0x1514:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1544:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2BFFC
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7270
	  addi      r4, r3, 0x5F63
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x1956C4
	  mr.       r19, r3
	  beq-      .loc_0x168C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2BFEC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D010
	  addi      r0, r26, 0x48
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1630
	  addi      r3, r19, 0x4
	  bl        -0x5DCF8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x165C
	  stw       r0, 0xEC(r18)
	  b         .loc_0x165C

	.loc_0x1630:
	  addi      r3, r19, 0x4
	  bl        -0x5DD28
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x165C
	  stw       r0, 0xEC(r18)

	.loc_0x165C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x168C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C144
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7270
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x19580C
	  mr.       r19, r3
	  beq-      .loc_0x17D4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C134
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D158
	  addi      r0, r26, 0x48
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1778
	  addi      r3, r19, 0x4
	  bl        -0x5DE40
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x17A4
	  stw       r0, 0xEC(r18)
	  b         .loc_0x17A4

	.loc_0x1778:
	  addi      r3, r19, 0x4
	  bl        -0x5DE70
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x17A4
	  stw       r0, 0xEC(r18)

	.loc_0x17A4:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x17D4:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C28C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7970
	  addi      r4, r3, 0x5F6C
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195954
	  mr.       r19, r3
	  beq-      .loc_0x191C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C27C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D2A0
	  addi      r0, r26, 0x4C
	  stw       r0, 0x4(r19)
	  li        r0, 0x64
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x18C0
	  addi      r3, r19, 0x4
	  bl        -0x5DF88
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x18EC
	  stw       r0, 0xEC(r18)
	  b         .loc_0x18EC

	.loc_0x18C0:
	  addi      r3, r19, 0x4
	  bl        -0x5DFB8
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x18EC
	  stw       r0, 0xEC(r18)

	.loc_0x18EC:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x191C:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C3D4
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7970
	  addi      r4, r3, 0x5F63
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195A9C
	  mr.       r19, r3
	  beq-      .loc_0x1A64
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C3C4
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D3E8
	  addi      r0, r26, 0x4C
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A08
	  addi      r3, r19, 0x4
	  bl        -0x5E0D0
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1A34
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1A34

	.loc_0x1A08:
	  addi      r3, r19, 0x4
	  bl        -0x5E100
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1A34
	  stw       r0, 0xEC(r18)

	.loc_0x1A34:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1A64:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C51C
	  lwz       r5, 0x20(r26)
	  lis       r3, 0x7970
	  addi      r4, r3, 0x5F72
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r18, r3, 0
	  li        r3, 0x1C
	  bl        -0x195BE4
	  mr.       r19, r3
	  beq-      .loc_0x1BAC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r19)
	  addi      r4, r18, 0
	  addi      r3, r19, 0x4
	  li        r5, 0x12
	  bl        -0x2C50C
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r19)
	  addi      r3, r19, 0x4
	  bl        -0x1D530
	  addi      r0, r26, 0x4C
	  stw       r0, 0x4(r19)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x8(r19)
	  addi      r0, r3, 0x2FE4
	  li        r4, 0
	  stw       r0, 0x0(r19)
	  stb       r4, 0x18(r19)
	  lwz       r3, 0x4(r19)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r19)
	  stw       r4, 0x14(r19)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r19)
	  lbz       r0, 0x18(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B50
	  addi      r3, r19, 0x4
	  bl        -0x5E218
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1B7C
	  stw       r0, 0xEC(r18)
	  b         .loc_0x1B7C

	.loc_0x1B50:
	  addi      r3, r19, 0x4
	  bl        -0x5E248
	  lbz       r0, 0xF1(r18)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x1B7C
	  stw       r0, 0xEC(r18)

	.loc_0x1B7C:
	  lha       r5, 0x1A(r18)
	  lha       r4, 0x1E(r18)
	  lha       r3, 0x18(r18)
	  lha       r0, 0x1C(r18)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r18)
	  extsh     r0, r4
	  sth       r0, 0xBA(r18)

	.loc_0x1BAC:
	  addi      r3, r18, 0
	  addi      r4, r19, 0
	  bl        -0x2C664
	  li        r3, 0x12C
	  bl        -0x195D04
	  mr.       r18, r3
	  beq-      .loc_0x1C54
	  lfs       f2, -0x4188(r2)
	  lis       r3, 0x801E
	  subi      r4, r3, 0x1F4C
	  stfs      f2, 0x14(r18)
	  fmr       f1, f2
	  fmr       f0, f2
	  addi      r3, r18, 0x44
	  stfs      f2, 0x10(r18)
	  li        r5, 0
	  stfs      f2, 0xC(r18)
	  li        r6, 0x3C
	  stfs      f2, 0x20(r18)
	  li        r7, 0x3
	  stfs      f2, 0x1C(r18)
	  stfs      f2, 0x18(r18)
	  stfs      f1, 0x2C(r18)
	  stfs      f1, 0x28(r18)
	  stfs      f1, 0x24(r18)
	  stfs      f0, 0x40(r18)
	  stfs      f0, 0x3C(r18)
	  stfs      f0, 0x38(r18)
	  bl        0x37D08
	  lfs       f0, -0x4188(r2)
	  li        r0, 0
	  addi      r3, r18, 0
	  stfs      f0, 0x100(r18)
	  stfs      f0, 0xFC(r18)
	  stfs      f0, 0xF8(r18)
	  stfs      f0, 0x10C(r18)
	  stfs      f0, 0x108(r18)
	  stfs      f0, 0x104(r18)
	  stw       r0, 0x8(r18)
	  stw       r0, 0x110(r18)
	  stw       r0, 0x114(r18)
	  bl        0x1214

	.loc_0x1C54:
	  stw       r18, 0x34(r26)
	  li        r4, 0x7269
	  li        r5, 0x1
	  lwz       r3, 0x14(r26)
	  lwz       r18, 0x34(r26)
	  addi      r19, r3, 0x4
	  addi      r3, r19, 0
	  lwz       r12, 0x0(r19)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1C90
	  stw       r3, 0x8(r18)

	.loc_0x1C90:
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6369
	  addi      r4, r4, 0x5F62
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1CC0
	  stw       r3, 0x44(r18)

	.loc_0x1CC0:
	  addi      r3, r18, 0x44
	  bl        0x1084
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6369
	  addi      r4, r4, 0x5F72
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1CF8
	  stw       r3, 0x80(r18)

	.loc_0x1CF8:
	  addi      r3, r18, 0x80
	  bl        0x104C
	  mr        r3, r19
	  lwz       r12, 0x0(r19)
	  lis       r4, 0x6369
	  addi      r4, r4, 0x5F79
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x1D30
	  stw       r3, 0xBC(r18)

	.loc_0x1D30:
	  addi      r3, r18, 0xBC
	  bl        0x1014
	  mr        r3, r18
	  bl        0x8E4
	  li        r3, 0x8
	  bl        -0x195E8C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1D88
	  lwz       r18, 0x249C(r13)
	  mulli     r3, r18, 0x28
	  addi      r3, r3, 0x8
	  bl        -0x195EA8
	  lis       r4, 0x801E
	  subi      r4, r4, 0x28C0
	  addi      r7, r18, 0
	  li        r5, 0
	  li        r6, 0x28
	  bl        0x37D64
	  stw       r3, 0x0(r19)
	  li        r0, -0x1
	  stw       r0, 0x4(r19)

	.loc_0x1D88:
	  stw       r19, 0x5C(r26)
	  li        r18, 0
	  mr        r21, r18
	  lwz       r3, 0x18(r26)
	  lwz       r19, 0x5C(r26)
	  lwz       r22, 0x249C(r13)
	  addi      r20, r3, 0x4
	  b         .loc_0x1E50

	.loc_0x1DA8:
	  lbz       r5, 0x0(r28)
	  addi      r3, r1, 0x40C
	  crclr     6, 0x6
	  addi      r4, r13, 0x2620
	  addi      r5, r5, 0x1
	  bl        0x39690
	  lwz       r12, 0x0(r20)
	  mr        r3, r20
	  lbz       r0, 0x40D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x40C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x40E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x40F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lwz       r0, 0x0(r19)
	  add       r24, r0, r21
	  stw       r3, 0x4(r24)
	  lwz       r3, 0x4(r24)
	  addi      r3, r3, 0x18
	  bl        -0x24A24
	  lwz       r4, 0x4(r24)
	  addi      r23, r3, 0
	  addi      r3, r4, 0x18
	  bl        -0x24A44
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x4(r24)
	  extsh     r3, r0
	  srawi     r0, r23, 0x1
	  sth       r3, 0xB8(r4)
	  extsh     r0, r0
	  sth       r0, 0xBA(r4)
	  li        r0, 0
	  addi      r21, r21, 0x28
	  stw       r0, 0x0(r24)
	  addi      r18, r18, 0x1
	  addi      r28, r28, 0x1

	.loc_0x1E50:
	  cmpw      r18, r22
	  blt+      .loc_0x1DA8
	  li        r21, 0
	  lwz       r18, 0x249C(r13)
	  addi      r23, r21, 0
	  addi      r20, r21, 0
	  b         .loc_0x1EA4

	.loc_0x1E6C:
	  lwz       r0, 0x0(r19)
	  li        r4, 0x280
	  li        r5, 0x1E0
	  add       r22, r0, r23
	  lwz       r3, 0x4(r22)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stw       r20, 0x0(r22)
	  lwz       r3, 0x4(r22)
	  bl        0x748
	  addi      r23, r23, 0x28
	  addi      r21, r21, 0x1

	.loc_0x1EA4:
	  cmpw      r21, r18
	  blt+      .loc_0x1E6C
	  li        r0, -0x1
	  stw       r0, 0x4(r19)
	  li        r3, 0xC
	  bl        -0x196000
	  cmplwi    r3, 0
	  beq-      .loc_0x1ED0
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)

	.loc_0x1ED0:
	  stw       r3, 0x60(r26)
	  addi      r3, r1, 0x404
	  crclr     6, 0x6
	  li        r18, 0
	  lwz       r5, 0x24(r26)
	  lwz       r29, 0x60(r26)
	  addi      r4, r13, 0x2628
	  addi      r30, r5, 0x4
	  li        r5, 0
	  bl        0x39558
	  b         .loc_0x1F14

	.loc_0x1EFC:
	  addi      r18, r18, 0x1
	  crclr     6, 0x6
	  addi      r5, r18, 0
	  addi      r3, r1, 0x404
	  addi      r4, r13, 0x2628
	  bl        0x3953C

	.loc_0x1F14:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x405(r1)
	  li        r5, 0
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x404(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x406(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x407(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x1EFC
	  stw       r18, 0x0(r29)
	  lwz       r0, 0x0(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1960A8
	  stw       r3, 0x4(r29)
	  lwz       r0, 0x0(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1960B8
	  li        r18, 0
	  stw       r3, 0x8(r29)
	  mr        r19, r18
	  b         .loc_0x20B4

	.loc_0x1F84:
	  addi      r5, r18, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x404
	  addi      r4, r13, 0x2630
	  bl        0x394B8
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x405(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x404(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x406(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x407(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x2018
	  lwz       r5, 0x4(r29)
	  li        r4, 0x1
	  stwx      r3, r5, r19
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r19
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r19
	  bl        -0x1D63C
	  lwz       r5, 0x4(r29)
	  mr        r4, r3
	  lwzx      r3, r5, r19
	  bl        -0x1D5C0

	.loc_0x2018:
	  addi      r5, r18, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x404
	  addi      r4, r13, 0x2628
	  bl        0x39424
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x405(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x404(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x406(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x407(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x20AC
	  lwz       r5, 0x8(r29)
	  li        r4, 0x1
	  stwx      r3, r5, r19
	  lwz       r3, 0x8(r29)
	  lwzx      r3, r3, r19
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r29)
	  lwzx      r3, r3, r19
	  bl        -0x1D6D0
	  lwz       r5, 0x8(r29)
	  mr        r4, r3
	  lwzx      r3, r5, r19
	  bl        -0x1D654

	.loc_0x20AC:
	  addi      r19, r19, 0x4
	  addi      r18, r18, 0x1

	.loc_0x20B4:
	  lwz       r0, 0x0(r29)
	  cmpw      r18, r0
	  blt+      .loc_0x1F84
	  li        r3, 0x88
	  bl        -0x19620C
	  addi      r31, r3, 0
	  mr.       r18, r31
	  beq-      .loc_0x242C
	  li        r0, 0
	  stw       r0, 0x4(r31)
	  li        r3, 0x100
	  stw       r0, 0x8(r31)
	  lfs       f6, -0x4184(r2)
	  stfs      f6, 0x10(r31)
	  fmr       f4, f6
	  fmr       f3, f6
	  stfs      f6, 0xC(r31)
	  fmr       f2, f6
	  fmr       f1, f6
	  lfs       f5, -0x4188(r2)
	  stfs      f5, 0x20(r31)
	  fmr       f0, f5
	  stfs      f5, 0x1C(r31)
	  stfs      f5, 0x18(r31)
	  stfs      f5, 0x14(r31)
	  stfs      f6, 0x28(r31)
	  stfs      f6, 0x24(r31)
	  stfs      f4, 0x30(r31)
	  stfs      f4, 0x2C(r31)
	  stw       r0, 0x34(r31)
	  stw       r0, 0x38(r31)
	  stfs      f3, 0x40(r31)
	  stfs      f3, 0x3C(r31)
	  stfs      f5, 0x50(r31)
	  stfs      f5, 0x4C(r31)
	  stfs      f5, 0x48(r31)
	  stfs      f5, 0x44(r31)
	  stfs      f2, 0x58(r31)
	  stfs      f2, 0x54(r31)
	  stfs      f1, 0x60(r31)
	  stfs      f1, 0x5C(r31)
	  stfs      f0, 0x84(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x7C(r31)
	  bl        -0x1962AC
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x2188
	  addi      r4, r17, 0xFC
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x1DD5C

	.loc_0x2188:
	  stw       r19, 0x0(r31)
	  lis       r3, 0x7061
	  addi      r4, r3, 0x6C6C
	  lwz       r3, 0x0(r31)
	  li        r5, 0x1
	  addi      r7, r3, 0x4
	  lha       r3, 0x1C(r3)
	  lha       r0, 0x1C(r7)
	  mr        r30, r7
	  lha       r6, 0x1A(r7)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r7)
	  srawi     r0, r0, 0x1
	  sub       r6, r3, r6
	  extsh     r3, r0
	  srawi     r0, r6, 0x1
	  sth       r3, 0xB8(r7)
	  extsh     r0, r0
	  sth       r0, 0xBA(r7)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x7365
	  addi      r29, r3, 0
	  lwz       r12, 0x34(r12)
	  addi      r3, r30, 0
	  addi      r4, r4, 0x5F63
	  mtlr      r12
	  li        r5, 0x1
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x13
	  bne-      .loc_0x2228
	  lwz       r0, 0xF4(r3)
	  stw       r0, 0x68(r31)
	  lwz       r0, 0xF8(r3)
	  stw       r0, 0x6C(r31)

	.loc_0x2228:
	  li        r3, 0x20
	  bl        -0x196374
	  lis       r4, 0x801C
	  lis       r5, 0x801C
	  addi      r4, r4, 0x3C4C
	  addi      r5, r5, 0x3BF8
	  li        r6, 0xC
	  li        r7, 0x2
	  bl        0x37894
	  li        r28, 0
	  stw       r3, 0x64(r31)
	  addi      r27, r28, 0
	  addi      r25, r29, 0

	.loc_0x225C:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x3FC
	  addi      r4, r13, 0x2638
	  bl        0x391E0
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x3FD(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x3FC(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x3FE(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x3FF(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r17, r3, 0
	  addi      r4, r29, 0
	  bl        -0x1D85C
	  lwz       r0, 0x64(r31)
	  addi      r4, r17, 0
	  li        r5, 0
	  add       r3, r0, r27
	  lwz       r3, 0x0(r3)
	  bl        -0x1ABEC
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x3FC
	  addi      r4, r13, 0x2640
	  bl        0x39170
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x3FD(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x3FC(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x3FE(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x3FF(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  lwz       r4, 0x64(r31)
	  cmplwi    r0, 0x12
	  add       r6, r4, r27
	  bne-      .loc_0x2350
	  stw       r3, 0x4(r6)
	  li        r5, 0
	  addi      r4, r29, 0
	  lwz       r3, 0x4(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4(r6)
	  bl        -0x1D8F8

	.loc_0x2350:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x3FC
	  addi      r4, r13, 0x2648
	  bl        0x390EC
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x3FD(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x3FC(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x3FE(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x3FF(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  lwz       r4, 0x64(r31)
	  cmplwi    r0, 0x12
	  add       r6, r4, r27
	  bne-      .loc_0x23D4
	  stw       r3, 0x8(r6)
	  li        r5, 0
	  addi      r4, r25, 0
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r6)
	  bl        -0x1D97C

	.loc_0x23D4:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x2
	  addi      r27, r27, 0xC
	  blt+      .loc_0x225C
	  lis       r17, 0x7A2A
	  lfs       f1, -0x417C(r2)
	  lfs       f2, -0x4178(r2)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  addi      r3, r18, 0x4
	  addi      r6, r17, 0x2A6C
	  bl        -0x2910
	  lfs       f1, -0x4174(r2)
	  mr        r4, r30
	  lfs       f2, -0x4178(r2)
	  addi      r5, r29, 0
	  addi      r3, r18, 0x34
	  addi      r6, r17, 0x2A72
	  bl        -0x292C
	  addi      r3, r18, 0
	  li        r4, 0
	  bl        .loc_0x246C

	.loc_0x242C:
	  stw       r31, 0x70(r26)
	  li        r3, 0x8
	  bl        -0x19657C
	  cmplwi    r3, 0
	  beq-      .loc_0x2450
	  lfs       f0, -0x4170(r2)
	  li        r0, 0
	  stfs      f0, 0x0(r3)
	  stb       r0, 0x4(r3)

	.loc_0x2450:
	  stw       r3, 0x364(r26)
	  mr        r3, r26
	  lmw       r17, 0x474(r1)
	  lwz       r0, 0x4B4(r1)
	  addi      r1, r1, 0x4B0
	  mtlr      r0
	  blr

	.loc_0x246C:
	*/
}

/*
 * --INFO--
 * Address:	801DD5B8
 * Size:	000174
 */
void zen::WorldMapConfirmMgr::init(zen::WorldMapConfirmMgr::statusFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stw       r31, 0xAC(r1)
	  stw       r30, 0xA8(r1)
	  mr        r30, r3
	  stw       r29, 0xA4(r1)
	  stw       r4, 0x74(r3)
	  li        r4, 0x280
	  lwz       r3, 0x0(r3)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  li        r5, 0x1
	  lfs       f0, -0x4184(r2)
	  li        r31, 0
	  addi      r4, r3, 0x4
	  stfs      f0, 0xC4(r3)
	  lis       r29, 0x4330
	  addi      r3, r30, 0x4
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  lwz       r4, 0x0(r30)
	  lbz       r0, 0x10(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0x10(r4)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x70(r30)
	  stw       r31, 0x78(r30)
	  lwz       r0, 0x78(r30)
	  lwz       r5, 0x64(r30)
	  mulli     r4, r0, 0xC
	  lfd       f2, -0x4168(r2)
	  addi      r0, r4, 0x4
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x94(r1)
	  stw       r4, 0x9C(r1)
	  stw       r29, 0x98(r1)
	  stw       r29, 0x90(r1)
	  lfd       f1, 0x98(r1)
	  lfd       f0, 0x90(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0x26D0
	  lwz       r0, 0x78(r30)
	  addi      r3, r30, 0x34
	  lwz       r5, 0x64(r30)
	  mulli     r4, r0, 0xC
	  lfd       f2, -0x4168(r2)
	  addi      r0, r4, 0x8
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x84(r1)
	  stw       r4, 0x8C(r1)
	  stw       r29, 0x88(r1)
	  stw       r29, 0x80(r1)
	  lfd       f1, 0x88(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0x2720
	  li        r29, 0

	.loc_0x120:
	  lwz       r3, 0x78(r30)
	  addi      r5, r30, 0x68
	  lwz       r0, 0x64(r30)
	  addi      r6, r30, 0x6C
	  sub       r3, r3, r29
	  cntlzw    r3, r3
	  add       r7, r0, r31
	  rlwinm    r4,r3,27,5,31
	  lwz       r3, 0x0(r7)
	  bl        -0x1AF80
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x2
	  addi      r31, r31, 0xC
	  blt+      .loc_0x120
	  lwz       r0, 0xB4(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DD72C
 * Size:	000014
 */
void P2DPane::hide()
{
	/*
	.loc_0x0:
	  lbz       r0, 0xC(r3)
	  li        r4, 0
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DD740
 * Size:	00002C
 */
@unnamed @ ::WorldMapTitleObj::WorldMapTitleObj()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4188(r2)
	  li        r0, 0
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DD76C
 * Size:	00067C
 */
void zen::WorldMapCursorMgr::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B0(r1)
	  stfd      f31, 0x1A8(r1)
	  stw       r31, 0x1A4(r1)
	  mr        r31, r3
	  stw       r30, 0x1A0(r1)
	  stw       r29, 0x19C(r1)
	  lwz       r4, 0x8(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xBC
	  lha       r0, 0x18(r4)
	  lis       r3, 0x4330
	  lha       r4, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x194(r1)
	  xoris     r0, r4, 0x8000
	  stw       r3, 0x190(r1)
	  stw       r0, 0x18C(r1)
	  lfd       f0, 0x190(r1)
	  stw       r3, 0x188(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x188(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x18(r31)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x2578(r13)
	  stfs      f0, 0x20(r31)
	  lwz       r5, 0x8(r31)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x8(r31)
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)

	.loc_0xBC:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        .loc_0x67C
	  li        r0, 0
	  stb       r0, 0x35(r31)
	  lfs       f0, 0x2594(r13)
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x2598(r13)
	  stfs      f0, 0x3C(r31)
	  lfs       f0, 0x259C(r13)
	  stfs      f0, 0x40(r31)
	  lfs       f1, -0x4188(r2)
	  stfs      f1, 0x0(r31)
	  lfs       f0, 0x25A0(r13)
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0x25A4(r13)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x25A8(r13)
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x25AC(r13)
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x25B0(r13)
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x25B4(r13)
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x25B8(r13)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x25BC(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x25C0(r13)
	  stfs      f0, 0x20(r31)
	  stfs      f1, 0x30(r31)
	  lfs       f0, 0x25C4(r13)
	  stfs      f0, 0xF8(r31)
	  lfs       f0, 0x25C8(r13)
	  stfs      f0, 0xFC(r31)
	  lfs       f0, 0x25CC(r13)
	  stfs      f0, 0x100(r31)
	  lfs       f0, 0x25D0(r13)
	  stfs      f0, 0x104(r31)
	  lfs       f0, 0x25D4(r13)
	  stfs      f0, 0x108(r31)
	  lfs       f0, 0x25D8(r13)
	  stfs      f0, 0x10C(r31)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x190
	  bge-      .loc_0x190
	  cmpwi     r0, 0
	  bge-      .loc_0x18C
	  b         .loc_0x190

	.loc_0x18C:
	  stfs      f1, 0x30(r31)

	.loc_0x190:
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0x128(r31)
	  lwz       r5, 0x44(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x1D4
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x2
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)

	.loc_0x1D4:
	  lfs       f31, 0x251C(r13)
	  bl        0x3A72C
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x18C(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x4160(r2)
	  addi      r5, r1, 0x14C
	  stw       r0, 0x188(r1)
	  li        r4, 0x32
	  lfd       f1, 0x188(r1)
	  li        r6, 0
	  li        r7, 0
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f31, f0
	  stfs      f0, 0x78(r31)
	  lfs       f0, 0x24C4(r13)
	  stfs      f0, 0x48(r31)
	  lfs       f0, 0x24C8(r13)
	  stfs      f0, 0x4C(r31)
	  lfs       f0, 0x24CC(r13)
	  stfs      f0, 0x50(r31)
	  lfs       f0, 0x24D0(r13)
	  stfs      f0, 0x60(r31)
	  lfs       f0, 0x24D4(r13)
	  stfs      f0, 0x64(r31)
	  lfs       f0, 0x24D8(r13)
	  stfs      f0, 0x68(r31)
	  lfs       f0, 0x24DC(r13)
	  stfs      f0, 0x6C(r31)
	  lfs       f0, 0x2514(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x24E0(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, 0x24E4(r13)
	  lfs       f1, 0x24E8(r13)
	  stfs      f0, 0x14C(r1)
	  lfs       f0, 0x24EC(r13)
	  stfs      f1, 0x150(r1)
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x154(r1)
	  bl        0xC154
	  stw       r3, 0x7C(r31)
	  lwz       r5, 0x80(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x2C0
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x2
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)

	.loc_0x2C0:
	  lfs       f31, 0x251C(r13)
	  bl        0x3A640
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x18C(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x4160(r2)
	  addi      r5, r1, 0x140
	  stw       r0, 0x188(r1)
	  li        r4, 0x32
	  lfd       f1, 0x188(r1)
	  li        r6, 0
	  li        r7, 0
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f31, f0
	  stfs      f0, 0xB4(r31)
	  lfs       f0, 0x24C4(r13)
	  stfs      f0, 0x84(r31)
	  lfs       f0, 0x24C8(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0x24CC(r13)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x24D0(r13)
	  stfs      f0, 0x9C(r31)
	  lfs       f0, 0x24D4(r13)
	  stfs      f0, 0xA0(r31)
	  lfs       f0, 0x24D8(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x24DC(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x2514(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, 0x24E0(r13)
	  stfs      f0, 0xB0(r31)
	  lfs       f0, 0x24E4(r13)
	  lfs       f1, 0x24E8(r13)
	  stfs      f0, 0x140(r1)
	  lfs       f0, 0x24EC(r13)
	  stfs      f1, 0x144(r1)
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x148(r1)
	  bl        0xC068
	  stw       r3, 0xB8(r31)
	  lwz       r5, 0xBC(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x3AC
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x2
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)

	.loc_0x3AC:
	  lfs       f31, 0x251C(r13)
	  bl        0x3A554
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x18C(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x4160(r2)
	  addi      r5, r1, 0x134
	  stw       r0, 0x188(r1)
	  li        r4, 0x32
	  lfd       f1, 0x188(r1)
	  li        r6, 0
	  li        r7, 0
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f31, f0
	  stfs      f0, 0xF0(r31)
	  lfs       f0, 0x24C4(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, 0x24C8(r13)
	  stfs      f0, 0xC4(r31)
	  lfs       f0, 0x24CC(r13)
	  stfs      f0, 0xC8(r31)
	  lfs       f0, 0x24D0(r13)
	  stfs      f0, 0xD8(r31)
	  lfs       f0, 0x24D4(r13)
	  stfs      f0, 0xDC(r31)
	  lfs       f0, 0x24D8(r13)
	  stfs      f0, 0xE0(r31)
	  lfs       f0, 0x24DC(r13)
	  stfs      f0, 0xE4(r31)
	  lfs       f0, 0x2514(r13)
	  stfs      f0, 0xE8(r31)
	  lfs       f0, 0x24E0(r13)
	  stfs      f0, 0xEC(r31)
	  lfs       f0, 0x24E4(r13)
	  lfs       f1, 0x24E8(r13)
	  stfs      f0, 0x134(r1)
	  lfs       f0, 0x24EC(r13)
	  stfs      f1, 0x138(r1)
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x13C(r1)
	  bl        0xBF7C
	  stw       r3, 0xF4(r31)
	  addi      r30, r31, 0
	  li        r29, 0

	.loc_0x464:
	  lwz       r0, 0x110(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x478
	  lwz       r3, 0x110(r31)
	  bl        -0x3CFE4

	.loc_0x478:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x2
	  addi      r30, r30, 0x4
	  blt+      .loc_0x464
	  lfs       f0, 0x257C(r13)
	  addi      r5, r1, 0x174
	  lfs       f1, 0x2580(r13)
	  li        r4, 0x30
	  stfs      f0, 0x174(r1)
	  lfs       f0, 0x2584(r13)
	  li        r6, 0
	  stfs      f1, 0x178(r1)
	  li        r7, 0
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x17C(r1)
	  bl        0xBF1C
	  stw       r3, 0x110(r31)
	  addi      r5, r1, 0x168
	  li        r4, 0x31
	  lwz       r3, 0x110(r31)
	  li        r6, 0
	  li        r7, 0
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  lwz       r3, 0x110(r31)
	  lfs       f0, 0xB8(r3)
	  stfs      f0, 0x118(r31)
	  lwz       r3, 0x110(r31)
	  lfs       f0, 0xCC(r3)
	  stfs      f0, 0x120(r31)
	  lfs       f0, 0x2588(r13)
	  lfs       f1, 0x258C(r13)
	  stfs      f0, 0x168(r1)
	  lfs       f0, 0x2590(r13)
	  stfs      f1, 0x16C(r1)
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x170(r1)
	  bl        0xBEC0
	  stw       r3, 0x114(r31)
	  lwz       r3, 0x114(r31)
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  lwz       r3, 0x114(r31)
	  lfs       f0, 0xB8(r3)
	  stfs      f0, 0x11C(r31)
	  lwz       r3, 0x110(r31)
	  lfs       f0, 0xCC(r3)
	  stfs      f0, 0x124(r31)
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x5D8
	  li        r29, 0
	  addi      r30, r31, 0

	.loc_0x554:
	  lwz       r3, 0x2F6C(r13)
	  mr        r4, r29
	  bl        -0x15D6FC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x598
	  lwz       r3, 0x44(r30)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C4
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)
	  b         .loc_0x5C4

	.loc_0x598:
	  lwz       r3, 0x44(r30)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C4
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x5C4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r30, r30, 0x3C
	  blt+      .loc_0x554
	  b         .loc_0x65C

	.loc_0x5D8:
	  lwz       r3, 0x44(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x604
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x604:
	  lwz       r3, 0x80(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xB8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x630
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x630:
	  lwz       r3, 0xBC(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xF4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x65C
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x65C:
	  lwz       r0, 0x1B4(r1)
	  lfd       f31, 0x1A8(r1)
	  lwz       r31, 0x1A4(r1)
	  lwz       r30, 0x1A0(r1)
	  lwz       r29, 0x19C(r1)
	  addi      r1, r1, 0x1B0
	  mtlr      r0
	  blr

	.loc_0x67C:
	*/
}

/*
 * --INFO--
 * Address:	801DDDE8
 * Size:	0000AC
 */
void zen::WorldMapCursorMgr::setLandingFlag(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x68
	  li        r0, 0x1
	  stb       r0, 0x34(r31)
	  li        r3, 0x124
	  bl        -0x138A9C
	  lwz       r3, 0x110(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  lfs       f1, -0x415C(r2)
	  lfs       f0, 0x118(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB8(r3)

	.loc_0x48:
	  lwz       r3, 0x114(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  lfs       f1, -0x4158(r2)
	  lfs       f0, 0x11C(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB8(r3)
	  b         .loc_0x98

	.loc_0x68:
	  li        r0, 0
	  stb       r0, 0x34(r31)
	  lwz       r3, 0x110(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  lfs       f0, 0x118(r31)
	  stfs      f0, 0xB8(r3)

	.loc_0x84:
	  lwz       r3, 0x114(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  lfs       f0, 0x11C(r31)
	  stfs      f0, 0xB8(r3)

	.loc_0x98:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DDE94
 * Size:	00011C
 */
void zen::WorldMapCursorOnyon::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r5, 0x0(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x54
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x2
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)

	.loc_0x54:
	  lfs       f31, 0x251C(r13)
	  bl        0x3A184
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x54(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x4160(r2)
	  addi      r5, r1, 0x40
	  stw       r0, 0x50(r1)
	  li        r4, 0x32
	  lfd       f1, 0x50(r1)
	  li        r6, 0
	  li        r7, 0
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f31, f0
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x24C4(r13)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x24C8(r13)
	  stfs      f0, 0x8(r31)
	  lfs       f0, 0x24CC(r13)
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0x24D0(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x24D4(r13)
	  stfs      f0, 0x20(r31)
	  lfs       f0, 0x24D8(r13)
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x24DC(r13)
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x2514(r13)
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x24E0(r13)
	  stfs      f0, 0x30(r31)
	  lfs       f0, 0x24E4(r13)
	  lfs       f1, 0x24E8(r13)
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x24EC(r13)
	  stfs      f1, 0x44(r1)
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x48(r1)
	  bl        0xBBAC
	  stw       r3, 0x38(r31)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DDFB0
 * Size:	000104
 */
void zen::WorldMapCursorMgr::initParams()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stb       r0, 0x34(r3)
	  lwz       r4, 0x110(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x1C
	  lfs       f0, 0x118(r3)
	  stfs      f0, 0xB8(r4)

	.loc_0x1C:
	  lwz       r4, 0x114(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lfs       f0, 0x11C(r3)
	  stfs      f0, 0xB8(r4)

	.loc_0x30:
	  li        r0, 0
	  stb       r0, 0x35(r3)
	  lfs       f0, 0x2594(r13)
	  stfs      f0, 0x38(r3)
	  lfs       f0, 0x2598(r13)
	  stfs      f0, 0x3C(r3)
	  lfs       f0, 0x259C(r13)
	  stfs      f0, 0x40(r3)
	  lfs       f1, -0x4188(r2)
	  stfs      f1, 0x0(r3)
	  lfs       f0, 0x25A0(r13)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0x25A4(r13)
	  stfs      f0, 0x10(r3)
	  lfs       f0, 0x25A8(r13)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x25AC(r13)
	  stfs      f0, 0x24(r3)
	  lfs       f0, 0x25B0(r13)
	  stfs      f0, 0x28(r3)
	  lfs       f0, 0x25B4(r13)
	  stfs      f0, 0x2C(r3)
	  lfs       f0, 0x25B8(r13)
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x25BC(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x25C0(r13)
	  stfs      f0, 0x20(r3)
	  stfs      f1, 0x30(r3)
	  lfs       f0, 0x25C4(r13)
	  stfs      f0, 0xF8(r3)
	  lfs       f0, 0x25C8(r13)
	  stfs      f0, 0xFC(r3)
	  lfs       f0, 0x25CC(r13)
	  stfs      f0, 0x100(r3)
	  lfs       f0, 0x25D0(r13)
	  stfs      f0, 0x104(r3)
	  lfs       f0, 0x25D4(r13)
	  stfs      f0, 0x108(r3)
	  lfs       f0, 0x25D8(r13)
	  stfs      f0, 0x10C(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0xF4
	  b         .loc_0xF8

	.loc_0xF4:
	  stfs      f1, 0x30(r3)

	.loc_0xF8:
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0x128(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE0B4
 * Size:	0000EC
 */
zen::WorldMapCursorOnyon::WorldMapCursorOnyon()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x30(r3)
	  stfs      f0, 0x2C(r3)
	  stfs      f0, 0x28(r3)
	  stw       r0, 0x0(r3)
	  lfs       f0, 0x24F0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x24F4(r13)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x24F8(r13)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0x24FC(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x2500(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, 0x2504(r13)
	  stfs      f0, 0x24(r3)
	  lfs       f31, 0x251C(r13)
	  bl        0x39F34
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x4160(r2)
	  mr        r3, r31
	  stw       r0, 0x18(r1)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f31, f0
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x2508(r13)
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x2514(r13)
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x250C(r13)
	  stfs      f0, 0x30(r31)
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE1A0
 * Size:	000164
 */
void @unnamed @ ::DrawWorldMapDateCallBack::setTex()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x15D608
	  addi      r0, r3, 0x1
	  cmpwi     r0, 0x9
	  ble-      .loc_0xF0
	  lwz       r5, 0x4(r31)
	  lis       r3, 0x6666
	  addi      r3, r3, 0x6667
	  lbz       r4, 0xC(r5)
	  li        r6, 0
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  mulhw     r3, r3, r0
	  lwz       r5, 0x8(r31)
	  lbz       r4, 0xC(r5)
	  li        r6, 0x1
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  srawi     r3, r3, 0x2
	  rlwinm    r4,r3,1,31,31
	  lwz       r6, 0x8(r31)
	  add       r5, r3, r4
	  lis       r4, 0x803D
	  lbz       r3, 0xF1(r6)
	  rlwinm    r5,r5,2,0,29
	  addi      r4, r4, 0x2360
	  add       r4, r4, r5
	  cmplwi    r3, 0
	  lwz       r3, 0x0(r4)
	  ble-      .loc_0x90
	  stw       r3, 0xEC(r6)

	.loc_0x90:
	  lis       r3, 0x6666
	  lwz       r6, 0xC(r31)
	  addi      r3, r3, 0x6667
	  mulhw     r3, r3, r0
	  lbz       r5, 0xC(r6)
	  srawi     r3, r3, 0x2
	  li        r4, 0x1
	  rlwimi    r5,r4,7,24,24
	  rlwinm    r4,r3,1,31,31
	  stb       r5, 0xC(r6)
	  add       r3, r3, r4
	  mulli     r4, r3, 0xA
	  lwz       r6, 0xC(r31)
	  lbz       r3, 0xF1(r6)
	  sub       r0, r0, r4
	  lis       r4, 0x803D
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r4, 0x2360
	  add       r4, r0, r5
	  cmplwi    r3, 0
	  lwz       r0, 0x0(r4)
	  ble-      .loc_0x150
	  stw       r0, 0xEC(r6)
	  b         .loc_0x150

	.loc_0xF0:
	  lwz       r6, 0x4(r31)
	  lis       r3, 0x803D
	  li        r4, 0x1
	  lbz       r5, 0xC(r6)
	  rlwimi    r5,r4,7,24,24
	  rlwinm    r4,r0,2,0,29
	  stb       r5, 0xC(r6)
	  addi      r0, r3, 0x2360
	  add       r3, r0, r4
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x0(r3)
	  lbz       r0, 0xF1(r4)
	  cmplwi    r0, 0
	  ble-      .loc_0x12C
	  stw       r3, 0xEC(r4)

	.loc_0x12C:
	  lwz       r3, 0x8(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x150:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE304
 * Size:	0000B8
 */
void zen::WorldMapMapImageMgr::init()
{
	/*
	.loc_0x0:
	  li        r6, 0
	  li        r0, 0x5
	  stw       r6, 0x4(r3)
	  mtctr     r0
	  addi      r7, r3, 0

	.loc_0x14:
	  lwz       r4, 0xC(r7)
	  cmplwi    r4, 0
	  beq-      .loc_0x60
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r8, 0xC(r7)
	  lha       r4, 0x18(r8)
	  lha       r0, 0x1C(r8)
	  lha       r5, 0x1A(r8)
	  sub       r0, r0, r4
	  lha       r4, 0x1E(r8)
	  srawi     r0, r0, 0x1
	  sub       r5, r4, r5
	  extsh     r4, r0
	  srawi     r0, r5, 0x1
	  sth       r4, 0xB8(r8)
	  extsh     r0, r0
	  sth       r0, 0xBA(r8)

	.loc_0x60:
	  addi      r7, r7, 0x4
	  bdnz+     .loc_0x14
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beqlr-
	  bge-      .loc_0x8C
	  cmpwi     r0, 0
	  bge-      .loc_0x98
	  blr

	.loc_0x8C:
	  cmpwi     r0, 0x3
	  bgelr-
	  b         .loc_0xAC

	.loc_0x98:
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x1
	  stfs      f0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  blr

	.loc_0xAC:
	  li        r0, 0x1
	  stb       r0, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE3BC
 * Size:	000164
 */
void zen::WorldMapWipe::init(P2DScreen*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x150
	  stw       r3, 0x24(r31)
	  lis       r6, 0x4330
	  lwz       r5, 0x24(r31)
	  lfd       f3, -0x4168(r2)
	  lha       r7, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r7
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  lha       r5, 0x1A(r5)
	  sub       r4, r3, r4
	  add       r0, r7, r0
	  xoris     r3, r0, 0x8000
	  srawi     r0, r4, 0x1
	  stw       r3, 0xD4(r1)
	  add       r0, r5, r0
	  xoris     r0, r0, 0x8000
	  stw       r6, 0xD0(r1)
	  stw       r0, 0xCC(r1)
	  lfd       f0, 0xD0(r1)
	  stw       r6, 0xC8(r1)
	  fsubs     f1, f0, f3
	  lfd       f0, 0xC8(r1)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x0(r31)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x25FC(r13)
	  stfs      f0, 0x8(r31)
	  lwz       r7, 0x24(r31)
	  lha       r9, 0x18(r7)
	  lha       r8, 0x1A(r7)
	  xoris     r0, r9, 0x8000
	  lha       r3, 0x1C(r7)
	  stw       r0, 0xC4(r1)
	  xoris     r0, r8, 0x8000
	  sub       r5, r3, r9
	  lha       r4, 0x1A(r7)
	  stw       r6, 0xC0(r1)
	  lha       r3, 0x1E(r7)
	  srawi     r5, r5, 0x1
	  stw       r0, 0xBC(r1)
	  sub       r5, r9, r5
	  lfd       f0, 0xC0(r1)
	  stw       r6, 0xB8(r1)
	  sub       r0, r3, r4
	  fsubs     f2, f0, f3
	  srawi     r3, r0, 0x1
	  lfd       f0, 0xB8(r1)
	  xoris     r0, r5, 0x8000
	  stw       r0, 0xB4(r1)
	  sub       r0, r8, r3
	  fsubs     f1, f0, f3
	  stfs      f2, 0xC(r31)
	  xoris     r0, r0, 0x8000
	  stw       r6, 0xB0(r1)
	  stw       r0, 0xAC(r1)
	  lfd       f0, 0xB0(r1)
	  stfs      f1, 0x10(r31)
	  fsubs     f1, f0, f3
	  stw       r6, 0xA8(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0xA8(r1)
	  stfs      f2, 0x14(r31)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x18(r31)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x20(r31)

	.loc_0x150:
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE520
 * Size:	000034
 */
zen::WorldMapWipe::WorldMapWipe()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4188(r2)
	  li        r0, 0
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x18(r3)
	  stw       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE554
 * Size:	000188
 */
void @unnamed @ ::WorldMapCoursePoint::setPane(P2DScreen*, u32, u32, u32, P2DScreen*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stmw      r26, 0xA0(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  addi      r4, r5, 0
	  addi      r3, r28, 0
	  mr        r26, r6
	  addi      r29, r7, 0
	  addi      r30, r8, 0
	  addi      r31, r9, 0
	  lwz       r12, 0x0(r28)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x84
	  stw       r3, 0x14(r27)
	  lwz       r5, 0x14(r27)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sub       r3, r3, r4
	  sth       r0, 0xB8(r5)
	  extsh     r0, r3
	  sth       r0, 0xBA(r5)

	.loc_0x84:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r4, r26, 0
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0xE0
	  stw       r3, 0x18(r27)
	  lwz       r5, 0x18(r27)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sub       r3, r3, r4
	  sth       r0, 0xB8(r5)
	  extsh     r0, r3
	  sth       r0, 0xBA(r5)

	.loc_0xE0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r4, r29, 0
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x154
	  stw       r3, 0x1C(r27)
	  li        r4, 0
	  lwz       r7, 0x18(r27)
	  lwz       r6, 0x1C(r27)
	  lha       r3, 0x18(r7)
	  lha       r0, 0x1C(r7)
	  lha       r5, 0x1A(r7)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r7)
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sub       r3, r3, r5
	  sth       r0, 0xB8(r6)
	  extsh     r0, r3
	  sth       r0, 0xBA(r6)
	  lwz       r3, 0x1C(r27)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x154:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r27)
	  lmw       r26, 0xA0(r1)
	  lwz       r0, 0xBC(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE6DC
 * Size:	000038
 */
@unnamed @ ::WorldMapCoursePoint::WorldMapCoursePoint()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x8(r3)
	  stb       r0, 0xC(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x18(r3)
	  stw       r0, 0x24(r3)
	  stw       r0, 0x28(r3)
	  stw       r0, 0x2C(r3)
	  stw       r0, 0x30(r3)
	  stw       r0, 0x34(r3)
	  stw       r0, 0x38(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DE714
 * Size:	000C14
 */
void zen::DrawWorldMap::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1D0(r1)
	  stfd      f31, 0x1C8(r1)
	  stfd      f30, 0x1C0(r1)
	  stfd      f29, 0x1B8(r1)
	  stfd      f28, 0x1B0(r1)
	  stmw      r19, 0x17C(r1)
	  mr        r30, r3
	  li        r31, 0
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xBEC
	  cmpwi     r0, 0x3
	  bne-      .loc_0x78
	  addi      r3, r30, 0x64
	  bl        0xB6AC
	  cmpwi     r3, 0
	  beq-      .loc_0xBEC
	  cmpwi     r3, 0x2
	  bne-      .loc_0x6C
	  li        r0, -0x1
	  stw       r0, 0x4(r30)
	  li        r0, 0x6
	  li        r31, 0x1
	  stw       r0, 0x8(r30)
	  b         .loc_0xBEC

	.loc_0x6C:
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0xBEC

	.loc_0x78:
	  cmpwi     r0, 0x6
	  bne-      .loc_0x2E4
	  addi      r3, r30, 0x74
	  bl        -0x4DE74
	  cmpwi     r3, -0x1
	  bne-      .loc_0xBEC
	  li        r0, 0x7
	  stw       r0, 0x4(r30)
	  li        r29, 0
	  lis       r20, 0x4330
	  lwz       r21, 0x58(r30)
	  lfd       f29, -0x4168(r2)
	  mr        r22, r21

	.loc_0xAC:
	  lwz       r3, 0x30(r22)
	  addi      r28, r22, 0xC
	  lha       r4, 0x18(r3)
	  lha       r0, 0x1C(r3)
	  lwz       r12, 0x0(r3)
	  sub       r5, r0, r4
	  lha       r4, 0x1A(r3)
	  lha       r0, 0x1E(r3)
	  srawi     r5, r5, 0x1
	  lwz       r12, 0x14(r12)
	  subfic    r23, r5, 0x140
	  sub       r0, r0, r4
	  srawi     r0, r0, 0x1
	  mtlr      r12
	  subfic    r24, r0, 0xF0
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  blrl
	  xoris     r3, r23, 0x8000
	  stw       r3, 0x174(r1)
	  xoris     r0, r24, 0x8000
	  addi      r29, r29, 0x1
	  stw       r20, 0x170(r1)
	  cmpwi     r29, 0x4
	  addi      r22, r22, 0x28
	  stw       r0, 0x16C(r1)
	  lfd       f0, 0x170(r1)
	  stw       r20, 0x168(r1)
	  fsubs     f2, f0, f29
	  lfd       f0, 0x168(r1)
	  stw       r3, 0x164(r1)
	  fsubs     f1, f0, f29
	  stfs      f2, 0xC(r28)
	  stw       r20, 0x160(r1)
	  stw       r0, 0x15C(r1)
	  lfd       f0, 0x160(r1)
	  stfs      f1, 0x10(r28)
	  fsubs     f1, f0, f29
	  stw       r20, 0x158(r1)
	  lfs       f2, 0x25EC(r13)
	  lfd       f0, 0x158(r1)
	  stfs      f2, 0x14(r28)
	  fsubs     f0, f0, f29
	  stfs      f1, 0x18(r28)
	  stfs      f0, 0x1C(r28)
	  lfs       f0, 0x25F0(r13)
	  stfs      f0, 0x20(r28)
	  blt+      .loc_0xAC
	  li        r29, 0
	  stw       r29, 0x0(r21)
	  addi      r25, r1, 0xF8
	  addi      r24, r1, 0xF4
	  lwz       r30, 0x58(r30)
	  addi      r23, r1, 0x100
	  lfs       f31, -0x4188(r2)
	  addi      r22, r1, 0xFC
	  addi      r21, r30, 0
	  stfs      f31, 0x4(r30)
	  lis       r20, 0x4330
	  lfs       f30, -0x4154(r2)
	  stfs      f30, 0x8(r30)
	  lfd       f29, -0x4168(r2)

	.loc_0x1A4:
	  lfs       f0, 0x10(r21)
	  addi      r28, r21, 0xC
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C0
	  fadds     f0, f30, f0
	  b         .loc_0x1C4

	.loc_0x1C0:
	  fsubs     f0, f0, f30

	.loc_0x1C4:
	  lfs       f1, 0x0(r28)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f31
	  stfd      f0, 0x158(r1)
	  lwz       r26, 0x15C(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1E8
	  fadds     f0, f30, f1
	  b         .loc_0x1EC

	.loc_0x1E8:
	  fsubs     f0, f1, f30

	.loc_0x1EC:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r28)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x158(r1)
	  lwz       r27, 0x15C(r1)
	  bl        -0x263F0
	  lwz       r4, 0x24(r28)
	  srawi     r0, r3, 0x1
	  sub       r27, r27, r0
	  addi      r3, r4, 0x18
	  bl        -0x263F4
	  lwz       r5, 0x24(r28)
	  srawi     r3, r3, 0x1
	  addi      r4, r24, 0
	  lha       r0, 0x1A(r5)
	  addi      r5, r25, 0
	  sub       r26, r26, r3
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  addi      r3, r28, 0xC
	  addi      r6, r13, 0x25F4
	  stw       r20, 0x160(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f0, f0, f29
	  stfs      f0, 0xF8(r1)
	  lwz       r7, 0x24(r28)
	  lha       r0, 0x18(r7)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x16C(r1)
	  stw       r20, 0x168(r1)
	  lfd       f0, 0x168(r1)
	  fsubs     f0, f0, f29
	  stfs      f0, 0xF4(r1)
	  bl        -0x1812F8
	  xoris     r3, r26, 0x8000
	  xoris     r0, r27, 0x8000
	  stw       r3, 0x174(r1)
	  mr        r4, r22
	  stw       r0, 0x154(r1)
	  addi      r5, r23, 0
	  addi      r3, r28, 0x18
	  stw       r20, 0x170(r1)
	  addi      r6, r13, 0x25F8
	  stw       r20, 0x150(r1)
	  lfd       f1, 0x170(r1)
	  lfd       f0, 0x150(r1)
	  fsubs     f1, f1, f29
	  fsubs     f0, f0, f29
	  stfs      f1, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  bl        -0x18133C
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r21, r21, 0x28
	  blt+      .loc_0x1A4
	  li        r0, 0x2
	  stw       r0, 0x0(r30)
	  li        r0, 0x1
	  li        r3, 0x134
	  stb       r0, 0xAC(r30)
	  bl        -0x13967C
	  b         .loc_0xBEC

	.loc_0x2E4:
	  cmplwi    r0, 0x8
	  bgt-      .loc_0x930
	  lis       r3, 0x802E
	  addi      r3, r3, 0x58C0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x58(r30)
	  lbz       r0, 0xAC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x324
	  li        r0, 0x6
	  stw       r0, 0x4(r30)
	  addi      r3, r30, 0x74
	  bl        -0x4E4E8

	.loc_0x324:
	  lwz       r21, 0x34(r30)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x354
	  bge-      .loc_0x3E4
	  cmpwi     r0, 0
	  bge-      .loc_0x348
	  b         .loc_0x3E4
	  b         .loc_0x3E4

	.loc_0x348:
	  mr        r3, r21
	  bl        0x1F24
	  b         .loc_0x3E4

	.loc_0x354:
	  mr        r3, r21
	  bl        0x1A84
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3E4
	  lbz       r0, 0x35(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x37C
	  mr        r3, r21
	  bl        0x1998
	  b         .loc_0x3E4

	.loc_0x37C:
	  lbz       r0, 0x34(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x3B8
	  li        r0, 0x2
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3E4
	  bge-      .loc_0x3E4
	  cmpwi     r0, 0
	  bge-      .loc_0x3AC
	  b         .loc_0x3E4

	.loc_0x3AC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)
	  b         .loc_0x3E4

	.loc_0x3B8:
	  li        r0, 0
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3E4
	  bge-      .loc_0x3E4
	  cmpwi     r0, 0
	  bge-      .loc_0x3DC
	  b         .loc_0x3E4

	.loc_0x3DC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)

	.loc_0x3E4:
	  mr        r3, r21
	  bl        0x15D4
	  li        r20, 0
	  mulli     r0, r20, 0x3C
	  add       r19, r21, r0

	.loc_0x3F8:
	  lwz       r4, 0x8(r21)
	  addi      r3, r19, 0x44
	  addi      r4, r4, 0xC0
	  bl        0xF90
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x3
	  addi      r19, r19, 0x3C
	  blt+      .loc_0x3F8
	  mr        r3, r21
	  bl        0xC20
	  mr        r3, r30
	  bl        0x87E4
	  b         .loc_0x930
	  lwz       r3, 0x58(r30)
	  lbz       r0, 0xAC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x444
	  li        r0, 0x2
	  stw       r0, 0x4(r30)

	.loc_0x444:
	  lwz       r21, 0x34(r30)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x474
	  bge-      .loc_0x504
	  cmpwi     r0, 0
	  bge-      .loc_0x468
	  b         .loc_0x504
	  b         .loc_0x504

	.loc_0x468:
	  mr        r3, r21
	  bl        0x1E04
	  b         .loc_0x504

	.loc_0x474:
	  mr        r3, r21
	  bl        0x1964
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x504
	  lbz       r0, 0x35(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x49C
	  mr        r3, r21
	  bl        0x1878
	  b         .loc_0x504

	.loc_0x49C:
	  lbz       r0, 0x34(r21)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D8
	  li        r0, 0x2
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x504
	  bge-      .loc_0x504
	  cmpwi     r0, 0
	  bge-      .loc_0x4CC
	  b         .loc_0x504

	.loc_0x4CC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)
	  b         .loc_0x504

	.loc_0x4D8:
	  li        r0, 0
	  stw       r0, 0x4(r21)
	  lwz       r0, 0x4(r21)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x504
	  bge-      .loc_0x504
	  cmpwi     r0, 0
	  bge-      .loc_0x4FC
	  b         .loc_0x504

	.loc_0x4FC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r21)

	.loc_0x504:
	  mr        r3, r21
	  bl        0x14B4
	  li        r20, 0
	  mulli     r0, r20, 0x3C
	  add       r19, r21, r0

	.loc_0x518:
	  lwz       r4, 0x8(r21)
	  addi      r3, r19, 0x44
	  addi      r4, r4, 0xC0
	  bl        0xE70
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x3
	  addi      r19, r19, 0x3C
	  blt+      .loc_0x518
	  mr        r3, r21
	  bl        0xB00
	  mr        r3, r30
	  bl        0x86C4
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x41A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x574
	  li        r0, 0x1
	  stw       r0, 0x4(r30)
	  b         .loc_0x930

	.loc_0x574:
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x45F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x7D38
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, 0x2
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  lwz       r3, 0x28(r4)
	  rlwinm.   r0,r3,0,7,7
	  beq-      .loc_0x5D8
	  addi      r3, r30, 0x64
	  bl        0xB0C4
	  li        r0, 0x3
	  stw       r0, 0x4(r30)
	  b         .loc_0x930

	.loc_0x5D8:
	  rlwinm.   r0,r3,0,16,16
	  beq-      .loc_0x8F8
	  lwz       r4, 0x34(r30)
	  li        r3, 0
	  lbz       r0, 0x35(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x604
	  lbz       r0, 0x34(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x604
	  li        r3, 0x1

	.loc_0x604:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  lwz       r26, 0x58(r30)
	  addi      r22, r1, 0xE0
	  lfs       f31, -0x4188(r2)
	  addi      r23, r1, 0xDC
	  lfs       f30, -0x4154(r2)
	  lfd       f29, -0x4168(r2)
	  addi      r21, r26, 0
	  addi      r24, r1, 0xE8
	  addi      r25, r1, 0xE4
	  li        r20, 0
	  lis       r28, 0x4330

	.loc_0x638:
	  lfs       f0, 0x10(r21)
	  addi      r19, r21, 0xC
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x654
	  fadds     f0, f30, f0
	  b         .loc_0x658

	.loc_0x654:
	  fsubs     f0, f0, f30

	.loc_0x658:
	  lfs       f1, 0x0(r19)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f31
	  stfd      f0, 0x150(r1)
	  lwz       r29, 0x154(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x67C
	  fadds     f0, f30, f1
	  b         .loc_0x680

	.loc_0x67C:
	  fsubs     f0, f1, f30

	.loc_0x680:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r19)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x150(r1)
	  lwz       r27, 0x154(r1)
	  bl        -0x26884
	  lwz       r4, 0x24(r19)
	  srawi     r0, r3, 0x1
	  sub       r27, r27, r0
	  addi      r3, r4, 0x18
	  bl        -0x26888
	  srawi     r0, r3, 0x1
	  lwz       r3, 0x24(r19)
	  sub       r29, r29, r0
	  lwz       r12, 0x0(r3)
	  addi      r4, r27, 0
	  addi      r5, r29, 0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  xoris     r29, r29, 0x8000
	  xoris     r27, r27, 0x8000
	  stw       r29, 0x15C(r1)
	  mr        r4, r23
	  stw       r27, 0x164(r1)
	  addi      r5, r22, 0
	  addi      r3, r19, 0xC
	  stw       r28, 0x158(r1)
	  addi      r6, r13, 0x25EC
	  stw       r28, 0x160(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f29
	  fsubs     f0, f0, f29
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        -0x181798
	  stw       r29, 0x16C(r1)
	  addi      r4, r25, 0
	  addi      r5, r24, 0
	  stw       r27, 0x174(r1)
	  addi      r3, r19, 0x18
	  addi      r6, r13, 0x25F0
	  stw       r28, 0x168(r1)
	  stw       r28, 0x170(r1)
	  lfd       f1, 0x168(r1)
	  lfd       f0, 0x170(r1)
	  fsubs     f1, f1, f29
	  fsubs     f0, f0, f29
	  stfs      f1, 0xE8(r1)
	  stfs      f0, 0xE4(r1)
	  bl        -0x1817D4
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x4
	  addi      r21, r21, 0x28
	  blt+      .loc_0x638
	  li        r0, 0
	  stw       r0, 0x0(r26)
	  li        r0, 0x2
	  mtctr     r0
	  lis       r3, 0x4330
	  lwz       r7, 0x58(r30)
	  lfs       f0, -0x4188(r2)
	  mr        r9, r7
	  stfs      f0, 0x4(r7)
	  lfs       f0, -0x4154(r2)
	  stfs      f0, 0x8(r7)
	  lfd       f3, -0x4168(r2)

	.loc_0x790:
	  lwz       r5, 0x30(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x154(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x150(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x15C(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x150(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x158(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x158(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x18(r9)
	  stw       r3, 0x160(r1)
	  stw       r0, 0x16C(r1)
	  lfd       f0, 0x160(r1)
	  stfs      f1, 0x1C(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x168(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x168(r1)
	  stfs      f2, 0x20(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x24(r9)
	  stfs      f0, 0x28(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x2C(r9)
	  lwz       r5, 0x58(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x154(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x150(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x15C(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x150(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x158(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x158(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x40(r9)
	  stw       r3, 0x160(r1)
	  stw       r0, 0x16C(r1)
	  lfd       f0, 0x160(r1)
	  stfs      f1, 0x44(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x168(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x168(r1)
	  stfs      f2, 0x48(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x4C(r9)
	  stfs      f0, 0x50(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x54(r9)
	  addi      r9, r9, 0x50
	  bdnz+     .loc_0x790
	  li        r4, 0x1
	  stw       r4, 0x0(r7)
	  li        r0, 0x5
	  li        r3, 0x134
	  stb       r4, 0xAC(r7)
	  stw       r0, 0x4(r30)
	  bl        -0x139C90
	  b         .loc_0x930

	.loc_0x8F8:
	  mr        r3, r30
	  bl        0x7174
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, 0x8
	  stw       r0, 0x4(r30)
	  b         .loc_0x930
	  mr        r3, r30
	  bl        0x819C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x930
	  li        r0, -0x1
	  stw       r0, 0x4(r30)
	  li        r31, 0x1

	.loc_0x930:
	  lwz       r3, 0x34(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x94C
	  lbz       r0, 0x34(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x954

	.loc_0x94C:
	  mr        r3, r30
	  bl        0x86C4

	.loc_0x954:
	  lwz       r3, 0x50(r30)
	  bl        0xAB1C
	  lwz       r3, 0x54(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x9D4
	  bge-      .loc_0x97C
	  cmpwi     r0, 0
	  bge-      .loc_0x988
	  b         .loc_0x9E0

	.loc_0x97C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x9E0
	  b         .loc_0x9DC

	.loc_0x988:
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x9E0
	  rlwinm    r0,r0,2,0,29
	  add       r4, r3, r0
	  lwz       r4, 0xC(r4)
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r0, 0x8(r3)
	  lfs       f0, -0x4184(r2)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0xC(r3)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x9E0

	.loc_0x9D4:
	  bl        0x588
	  b         .loc_0x9E0

	.loc_0x9DC:
	  bl        0x494

	.loc_0x9E0:
	  lwz       r23, 0x58(r30)
	  li        r0, 0
	  stb       r0, 0xAC(r23)
	  lwz       r20, 0x0(r23)
	  cmpwi     r20, 0
	  beq-      .loc_0xBBC
	  blt-      .loc_0xBBC
	  cmpwi     r20, 0x3
	  bge-      .loc_0xBBC
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r23)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r23)
	  lfs       f0, 0x4(r23)
	  lfs       f1, 0x8(r23)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0xA30
	  stfs      f1, 0x4(r23)
	  mr        r20, r0

	.loc_0xA30:
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xAA0
	  lfs       f1, 0x4(r23)
	  lfs       f0, 0x8(r23)
	  lfs       f2, -0x4150(r2)
	  fdivs     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0x3C9F0
	  lfs       f3, -0x4184(r2)
	  lfs       f4, -0x4154(r2)
	  fsubs     f1, f3, f1
	  lfs       f2, -0x414C(r2)
	  lfs       f0, -0x4188(r2)
	  fmuls     f31, f4, f1
	  fsubs     f1, f3, f31
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xA88
	  fadds     f0, f4, f1
	  b         .loc_0xA8C

	.loc_0xA88:
	  fsubs     f0, f1, f4

	.loc_0xA8C:
	  fctiwz    f0, f0
	  stfd      f0, 0x150(r1)
	  lwz       r0, 0x154(r1)
	  rlwinm    r21,r0,0,24,31
	  b         .loc_0xAF8

	.loc_0xAA0:
	  lfs       f1, 0x4(r23)
	  lfs       f0, 0x8(r23)
	  lfs       f2, -0x4148(r2)
	  fdivs     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0x3CB20
	  lfs       f2, -0x414C(r2)
	  fmr       f31, f1
	  lfs       f0, -0x4188(r2)
	  fmuls     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xAE0
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0xAE8

	.loc_0xAE0:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0xAE8:
	  fctiwz    f0, f0
	  stfd      f0, 0x150(r1)
	  lwz       r0, 0x154(r1)
	  rlwinm    r21,r0,0,24,31

	.loc_0xAF8:
	  lfs       f0, -0x4184(r2)
	  mr        r24, r23
	  lfs       f29, -0x4188(r2)
	  li        r22, 0
	  fsubs     f28, f0, f31
	  lfs       f30, -0x4154(r2)

	.loc_0xB10:
	  addi      r19, r24, 0xC
	  lfs       f1, 0x1C(r24)
	  lfs       f0, 0x28(r24)
	  fmuls     f1, f1, f28
	  fmuls     f0, f0, f31
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB3C
	  fadds     f0, f30, f0
	  b         .loc_0xB40

	.loc_0xB3C:
	  fsubs     f0, f0, f30

	.loc_0xB40:
	  lfs       f1, 0xC(r19)
	  fctiwz    f2, f0
	  lfs       f0, 0x18(r19)
	  fmuls     f1, f1, f28
	  fmuls     f0, f0, f31
	  stfd      f2, 0x150(r1)
	  lwz       r5, 0x154(r1)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB74
	  fadds     f0, f30, f0
	  b         .loc_0xB78

	.loc_0xB74:
	  fsubs     f0, f0, f30

	.loc_0xB78:
	  lwz       r3, 0x24(r19)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x150(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x154(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r19)
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  stb       r21, 0xF0(r3)
	  addi      r24, r24, 0x28
	  blt+      .loc_0xB10
	  stw       r20, 0x0(r23)
	  li        r0, 0x1
	  stb       r0, 0xAC(r23)

	.loc_0xBBC:
	  li        r20, 0
	  lwz       r22, 0x5C(r30)
	  mulli     r19, r20, 0x28
	  lwz       r21, 0x249C(r13)
	  b         .loc_0xBE4

	.loc_0xBD0:
	  lwz       r0, 0x0(r22)
	  add       r3, r0, r19
	  bl        .loc_0xC14
	  addi      r19, r19, 0x28
	  addi      r20, r20, 0x1

	.loc_0xBE4:
	  cmpw      r20, r21
	  blt+      .loc_0xBD0

	.loc_0xBEC:
	  mr        r3, r31
	  lmw       r19, 0x17C(r1)
	  lwz       r0, 0x1D4(r1)
	  lfd       f31, 0x1C8(r1)
	  lfd       f30, 0x1C0(r1)
	  lfd       f29, 0x1B8(r1)
	  lfd       f28, 0x1B0(r1)
	  addi      r1, r1, 0x1D0
	  mtlr      r0
	  blr

	.loc_0xC14:
	*/
}

/*
 * --INFO--
 * Address:	801DF328
 * Size:	00025C
 */
void @unnamed @ ::WorldMapTitleObj::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  mr        r30, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x38
	  bge-      .loc_0x2C
	  b         .loc_0x244

	.loc_0x2C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x244
	  b         .loc_0x138

	.loc_0x38:
	  lwz       r3, 0x2DEC(r13)
	  li        r31, 0
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r30)
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x68
	  stfs      f0, 0x8(r30)
	  li        r31, 0x1

	.loc_0x68:
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x4144(r2)
	  lfs       f2, -0x4148(r2)
	  fdivs     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0x3C944
	  lfs       f2, -0x4184(r2)
	  lfs       f0, 0x20(r30)
	  fsubs     f5, f2, f1
	  lfs       f3, 0x14(r30)
	  fmuls     f2, f0, f1
	  lfs       f0, -0x4188(r2)
	  fmuls     f3, f3, f5
	  fadds     f2, f3, f2
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB8
	  lfs       f0, -0x4154(r2)
	  fadds     f2, f0, f2
	  b         .loc_0xC0

	.loc_0xB8:
	  lfs       f0, -0x4154(r2)
	  fsubs     f2, f2, f0

	.loc_0xC0:
	  lfs       f0, 0x10(r30)
	  fctiwz    f4, f2
	  lfs       f2, 0x1C(r30)
	  fmuls     f3, f0, f5
	  lfs       f0, -0x4188(r2)
	  fmuls     f1, f2, f1
	  stfd      f4, 0x40(r1)
	  fadds     f1, f3, f1
	  lwz       r5, 0x44(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xFC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x104

	.loc_0xFC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x104:
	  lwz       r3, 0x4(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x40(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x44(r1)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x244
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  b         .loc_0x244

	.loc_0x138:
	  lwz       r3, 0x2DEC(r13)
	  li        r31, 0
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r30)
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x4154(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  stfs      f0, 0x8(r30)
	  li        r31, 0x1

	.loc_0x168:
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x4154(r2)
	  lfs       f2, -0x4148(r2)
	  fdivs     f0, f1, f0
	  fmuls     f1, f2, f0
	  bl        0x3C844
	  lfs       f2, -0x4184(r2)
	  lfs       f0, 0x20(r30)
	  fsubs     f5, f2, f1
	  lfs       f3, 0x14(r30)
	  fmuls     f2, f0, f1
	  lfs       f0, -0x4188(r2)
	  fmuls     f3, f3, f5
	  fadds     f2, f3, f2
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1B8
	  lfs       f0, -0x4154(r2)
	  fadds     f2, f0, f2
	  b         .loc_0x1C0

	.loc_0x1B8:
	  lfs       f0, -0x4154(r2)
	  fsubs     f2, f2, f0

	.loc_0x1C0:
	  lfs       f0, 0x10(r30)
	  fctiwz    f4, f2
	  lfs       f2, 0x1C(r30)
	  fmuls     f3, f0, f5
	  lfs       f0, -0x4188(r2)
	  fmuls     f1, f2, f1
	  stfd      f4, 0x40(r1)
	  fadds     f1, f3, f1
	  lwz       r5, 0x44(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1FC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x204

	.loc_0x1FC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x204:
	  lwz       r3, 0x4(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x40(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x44(r1)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x244
	  li        r4, 0
	  stw       r4, 0x0(r30)
	  lwz       r3, 0x4(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x244:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DF584
 * Size:	0000EC
 */
void zen::WorldMapMapImageMgr::modeOpen()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f1, 0x0(r3)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x5C
	  lfs       f3, -0x4184(r2)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x0(r3)
	  lbz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x50
	  li        r0, 0x1
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  stb       r0, 0x20(r3)
	  b         .loc_0x60

	.loc_0x50:
	  li        r0, 0
	  stw       r0, 0x4(r3)
	  b         .loc_0x60

	.loc_0x5C:
	  fdivs     f3, f1, f0

	.loc_0x60:
	  lfs       f1, -0x4154(r2)
	  lfs       f0, -0x4184(r2)
	  fdivs     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  fmr       f4, f1
	  ble-      .loc_0x7C
	  fmr       f4, f0

	.loc_0x7C:
	  lfs       f2, -0x4154(r2)
	  lfs       f0, -0x4140(r2)
	  fsubs     f1, f3, f2
	  fdivs     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x98
	  fmr       f1, f0

	.loc_0x98:
	  lfs       f0, -0x4184(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA8
	  fmr       f1, f0

	.loc_0xA8:
	  lwz       r0, 0x8(r3)
	  li        r4, 0x1
	  rlwinm    r0,r0,2,0,29
	  add       r5, r3, r0
	  lwz       r5, 0xC(r5)
	  stfs      f4, 0xC0(r5)
	  stfs      f1, 0xC4(r5)
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0xC8(r5)
	  lwz       r0, 0x8(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DF670
 * Size:	0000E0
 */
void zen::WorldMapMapImageMgr::modeClose()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f1, 0x0(r3)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4C
	  stfs      f0, 0x0(r3)
	  li        r4, 0
	  lwz       r0, 0x8(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr

	.loc_0x4C:
	  fdivs     f1, f1, f0
	  lfs       f2, -0x4184(r2)
	  lfs       f0, -0x4154(r2)
	  fsubs     f1, f2, f1
	  fdivs     f0, f1, f0
	  fcmpo     cr0, f0, f2
	  fmr       f3, f0
	  ble-      .loc_0x70
	  fmr       f3, f2

	.loc_0x70:
	  lfs       f2, -0x4154(r2)
	  lfs       f0, -0x4140(r2)
	  fsubs     f1, f1, f2
	  fdivs     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x8C
	  fmr       f1, f0

	.loc_0x8C:
	  lfs       f0, -0x4184(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x9C
	  fmr       f1, f0

	.loc_0x9C:
	  lwz       r0, 0x8(r3)
	  li        r4, 0x1
	  rlwinm    r0,r0,2,0,29
	  add       r5, r3, r0
	  lwz       r5, 0xC(r5)
	  stfs      f3, 0xC0(r5)
	  stfs      f1, 0xC4(r5)
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0xC8(r5)
	  lwz       r0, 0x8(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0xC(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DF750
 * Size:	000358
 */
void zen::WorldMapCursorMgr::effect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1A8(r1)
	  stfd      f31, 0x1A0(r1)
	  stfd      f30, 0x198(r1)
	  stw       r31, 0x194(r1)
	  stw       r30, 0x190(r1)
	  mr        r30, r3
	  stw       r29, 0x18C(r1)
	  lis       r29, 0x4330
	  stw       r28, 0x188(r1)
	  lwz       r31, 0x8(r3)
	  lfs       f1, -0x4148(r2)
	  lfs       f2, 0xBC(r31)
	  lfs       f0, -0x4188(r2)
	  fsubs     f31, f2, f1
	  stfs      f0, 0x160(r1)
	  stfs      f0, 0x15C(r1)
	  fmr       f1, f31
	  stfs      f0, 0x158(r1)
	  lfd       f3, -0x4168(r2)
	  lha       r6, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  lha       r5, 0x1A(r31)
	  sub       r0, r0, r6
	  lha       r3, 0x1E(r31)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r5
	  add       r0, r6, r0
	  xoris     r3, r0, 0x8000
	  srawi     r0, r4, 0x1
	  stw       r3, 0x184(r1)
	  add       r0, r5, r0
	  xoris     r0, r0, 0x8000
	  stw       r29, 0x180(r1)
	  stw       r0, 0x17C(r1)
	  lfd       f0, 0x180(r1)
	  stw       r29, 0x178(r1)
	  fsubs     f2, f0, f3
	  lfd       f0, 0x178(r1)
	  fsubs     f0, f0, f3
	  stfs      f2, 0x158(r1)
	  stfs      f0, 0x15C(r1)
	  lfs       f0, 0x2550(r13)
	  stfs      f0, 0x160(r1)
	  lha       r3, 0x1A(r31)
	  lha       r0, 0x1E(r31)
	  sub       r28, r0, r3
	  bl        0x3C4D8
	  srawi     r0, r28, 0x1
	  lwz       r4, 0x8(r30)
	  xoris     r0, r0, 0x8000
	  lfd       f3, -0x4168(r2)
	  stw       r0, 0x174(r1)
	  addi      r28, r4, 0xC0
	  lfs       f0, 0xC4(r31)
	  stw       r29, 0x170(r1)
	  lha       r3, 0x18(r4)
	  lfd       f2, 0x170(r1)
	  lha       r0, 0x1C(r4)
	  fsubs     f2, f2, f3
	  sub       r31, r0, r3
	  fneg      f2, f2
	  fmuls     f0, f2, f0
	  fmuls     f30, f1, f0
	  fmr       f1, f31
	  bl        0x3C2FC
	  srawi     r0, r31, 0x1
	  lfd       f3, -0x4168(r2)
	  xoris     r0, r0, 0x8000
	  lfs       f0, 0x0(r28)
	  stw       r0, 0x16C(r1)
	  lfs       f4, 0x158(r1)
	  stw       r29, 0x168(r1)
	  lfd       f2, 0x168(r1)
	  fsubs     f2, f2, f3
	  fneg      f2, f2
	  fmuls     f0, f2, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x158(r1)
	  lfs       f0, 0x15C(r1)
	  fadds     f0, f0, f30
	  stfs      f0, 0x15C(r1)
	  lfs       f1, 0x160(r1)
	  lfs       f0, 0x2554(r13)
	  fadds     f0, f1, f0
	  stfs      f0, 0x160(r1)
	  lfs       f1, -0x413C(r2)
	  lfs       f0, 0x15C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x15C(r1)
	  lwz       r3, 0x110(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x250
	  lwz       r0, 0x80(r3)
	  fmr       f1, f31
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  lwz       r4, 0x110(r30)
	  lwz       r3, 0x158(r1)
	  lwz       r0, 0x15C(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x160(r1)
	  stw       r0, 0x14(r4)
	  bl        0x3C3F0
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x3C250
	  fneg      f1, f1
	  lfs       f0, 0x2558(r13)
	  stfs      f1, 0x134(r1)
	  stfs      f30, 0x138(r1)
	  stfs      f0, 0x13C(r1)
	  lwz       r4, 0x110(r30)
	  lwz       r3, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x13C(r1)
	  stw       r0, 0xA8(r4)
	  lwz       r3, 0x8(r30)
	  lfs       f1, -0x4154(r2)
	  lfs       f0, 0xC0(r3)
	  lwz       r3, 0x110(r30)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xF0(r3)
	  lwz       r3, 0x8(r30)
	  lfs       f0, 0x120(r30)
	  addi      r4, r3, 0xC0
	  lwz       r3, 0x110(r30)
	  lfs       f1, 0x0(r4)
	  fmuls     f0, f0, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xCC(r3)
	  lwz       r0, 0x4(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x23C
	  lfs       f0, 0x118(r30)
	  lwz       r3, 0x110(r30)
	  stfs      f0, 0xB8(r3)
	  b         .loc_0x250

	.loc_0x23C:
	  lfs       f1, -0x4138(r2)
	  lfs       f0, 0x118(r30)
	  lwz       r3, 0x110(r30)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB8(r3)

	.loc_0x250:
	  lwz       r3, 0x114(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x330
	  lwz       r0, 0x80(r3)
	  fmr       f1, f31
	  ori       r0, r0, 0x10
	  stw       r0, 0x80(r3)
	  lwz       r4, 0x114(r30)
	  lwz       r3, 0x158(r1)
	  lwz       r0, 0x15C(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x160(r1)
	  stw       r0, 0x14(r4)
	  bl        0x3C310
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x3C170
	  fneg      f1, f1
	  lfs       f0, 0x255C(r13)
	  stfs      f1, 0x120(r1)
	  stfs      f30, 0x124(r1)
	  stfs      f0, 0x128(r1)
	  lwz       r4, 0x114(r30)
	  lwz       r3, 0x120(r1)
	  lwz       r0, 0x124(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x128(r1)
	  stw       r0, 0xA8(r4)
	  lwz       r3, 0x8(r30)
	  lfs       f1, -0x4134(r2)
	  lfs       f0, 0xC0(r3)
	  lwz       r3, 0x114(r30)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xF0(r3)
	  lwz       r3, 0x8(r30)
	  lfs       f0, 0x124(r30)
	  addi      r4, r3, 0xC0
	  lwz       r3, 0x114(r30)
	  lfs       f1, 0x0(r4)
	  fmuls     f0, f0, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xCC(r3)
	  lwz       r0, 0x4(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x324
	  lfs       f1, -0x4144(r2)
	  lfs       f0, 0x11C(r30)
	  lwz       r3, 0x114(r30)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB8(r3)
	  b         .loc_0x330

	.loc_0x324:
	  lfs       f0, 0x11C(r30)
	  lwz       r3, 0x114(r30)
	  stfs      f0, 0xB8(r3)

	.loc_0x330:
	  lwz       r0, 0x1AC(r1)
	  lfd       f31, 0x1A0(r1)
	  lfd       f30, 0x198(r1)
	  lwz       r31, 0x194(r1)
	  lwz       r30, 0x190(r1)
	  lwz       r29, 0x18C(r1)
	  lwz       r28, 0x188(r1)
	  addi      r1, r1, 0x1A8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DFAA8
 * Size:	000628
 */
void zen::WorldMapCursorOnyon::update(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1A0(r1)
	  stfd      f31, 0x198(r1)
	  stfd      f30, 0x190(r1)
	  stfd      f29, 0x188(r1)
	  stfd      f28, 0x180(r1)
	  stw       r31, 0x17C(r1)
	  mr        r31, r3
	  stw       r30, 0x178(r1)
	  mr        r30, r4
	  lfs       f3, 0x14(r31)
	  lfs       f1, 0x8(r31)
	  lfs       f2, 0x10(r31)
	  fsubs     f1, f3, f1
	  lfs       f0, 0x4(r31)
	  lfs       f3, 0x18(r31)
	  fsubs     f2, f2, f0
	  lfs       f0, 0xC(r31)
	  fsubs     f0, f3, f0
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f4, f1, f1
	  fmuls     f5, f2, f2
	  lfs       f8, -0x4130(r2)
	  lfs       f7, 0x28C(r3)
	  fmuls     f6, f0, f0
	  fadds     f4, f5, f4
	  fmuls     f28, f8, f7
	  lfs       f3, -0x4188(r2)
	  fadds     f7, f6, f4
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0xD8
	  fsqrte    f4, f7
	  lfd       f6, -0x4128(r2)
	  lfd       f5, -0x4120(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f7, f3
	  frsp      f3, f3
	  stfs      f3, 0xB0(r1)
	  lfs       f7, 0xB0(r1)

	.loc_0xD8:
	  lfs       f3, -0x4118(r2)
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0x1BC
	  lfs       f3, -0x4114(r2)
	  fdivs     f5, f2, f7
	  lfs       f4, -0x417C(r2)
	  lfs       f2, -0x4110(r2)
	  fdivs     f3, f7, f3
	  fmuls     f3, f4, f3
	  fdivs     f1, f1, f7
	  fdivs     f0, f0, f7
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0x110
	  fmr       f3, f2

	.loc_0x110:
	  fmuls     f2, f0, f3
	  addi      r6, r1, 0x68
	  fmuls     f1, f1, f3
	  addi      r5, r1, 0x64
	  fmuls     f0, f5, f3
	  stfs      f2, 0x68(r1)
	  addi      r4, r1, 0x60
	  addi      r3, r1, 0x118
	  stfs      f1, 0x64(r1)
	  stfs      f0, 0x60(r1)
	  bl        -0x1A8AC4
	  lfs       f2, 0x120(r1)
	  addi      r6, r1, 0xA0
	  lfs       f1, 0x11C(r1)
	  addi      r5, r1, 0x9C
	  lfs       f0, 0x118(r1)
	  fmuls     f2, f2, f28
	  addi      r4, r1, 0x98
	  fmuls     f1, f1, f28
	  addi      r3, r1, 0x124
	  fmuls     f0, f0, f28
	  stfs      f2, 0xA0(r1)
	  stfs      f1, 0x9C(r1)
	  stfs      f0, 0x98(r1)
	  bl        -0x1A8AFC
	  lfs       f1, 0x128(r1)
	  lfs       f2, 0x12C(r1)
	  lfs       f0, 0x124(r1)
	  stfs      f0, 0x1C(r31)
	  stfs      f1, 0x20(r31)
	  stfs      f2, 0x24(r31)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x1C(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x20(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r31)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x24(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)

	.loc_0x1BC:
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  lwz       r3, 0x0(r31)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x170(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x168(r1)
	  mtlr      r12
	  lwz       r4, 0x174(r1)
	  lwz       r5, 0x16C(r1)
	  blrl
	  lfs       f0, -0x4188(r2)
	  addi      r6, r1, 0x90
	  addi      r5, r1, 0x8C
	  stfs      f0, 0xC8(r1)
	  addi      r4, r1, 0x88
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f3, -0x410C(r2)
	  lfs       f2, 0x28C(r3)
	  addi      r3, r1, 0xD8
	  lfs       f1, 0x30(r31)
	  lfs       f0, 0xC(r31)
	  fmuls     f2, f3, f2
	  lfs       f3, -0x4130(r2)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x2C(r31)
	  fmuls     f1, f3, f2
	  lfs       f2, 0x28(r31)
	  stfs      f0, 0x90(r1)
	  fadds     f1, f4, f1
	  lfs       f0, 0x8(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x4(r31)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x88(r1)
	  bl        -0x1A8BE8
	  lfs       f1, 0xD8(r1)
	  lfs       f0, 0xDC(r1)
	  stfs      f1, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xE0(r1)
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1D2100
	  lfs       f0, -0x4118(r2)
	  fmr       f29, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x354
	  lfs       f1, 0x30(r31)
	  addi      r6, r1, 0x84
	  lfs       f0, 0xC(r31)
	  addi      r5, r1, 0x80
	  addi      r4, r1, 0x7C
	  fsubs     f0, f1, f0
	  addi      r3, r1, 0xE4
	  stfs      f0, 0x84(r1)
	  lfs       f1, 0x2C(r31)
	  lfs       f0, 0x8(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x80(r1)
	  lfs       f1, 0x28(r31)
	  lfs       f0, 0x4(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  bl        -0x1A8C78
	  lfs       f1, 0xE4(r1)
	  lfs       f0, 0xE8(r1)
	  stfs      f1, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xEC(r1)
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1D2190
	  lfs       f0, -0x4118(r2)
	  fmr       f29, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x354
	  lfs       f0, 0x24A0(r13)
	  lfs       f29, 0x2514(r13)
	  stfs      f0, 0xC0(r1)
	  stfs      f29, 0xC4(r1)
	  lfs       f0, 0x24A4(r13)
	  stfs      f0, 0xC8(r1)

	.loc_0x354:
	  lfs       f0, 0x2510(r13)
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x38C
	  fdivs     f1, f0, f29
	  lfs       f0, 0xC0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  b         .loc_0x3C0

	.loc_0x38C:
	  lfs       f0, 0x2518(r13)
	  fcmpo     cr0, f29, f0
	  ble-      .loc_0x3C0
	  fdivs     f1, f0, f29
	  lfs       f0, 0xC0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC8(r1)

	.loc_0x3C0:
	  lfs       f1, 0xC(r31)
	  addi      r6, r1, 0x78
	  lfs       f0, 0xC8(r1)
	  addi      r5, r1, 0x74
	  addi      r4, r1, 0x70
	  fadds     f1, f1, f0
	  lfs       f0, 0xC0(r1)
	  addi      r3, r1, 0xF0
	  stfs      f1, 0x78(r1)
	  lfs       f2, 0x8(r31)
	  lfs       f1, 0xC4(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x74(r1)
	  lfs       f1, 0x4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  bl        -0x1A8D8C
	  lfs       f28, 0xF0(r1)
	  lfs       f30, 0xF4(r1)
	  lfs       f31, 0xF8(r1)
	  lfs       f1, 0xC4(r1)
	  lfs       f2, 0xC0(r1)
	  bl        -0xC20B8
	  lfs       f0, -0x4148(r2)
	  li        r4, 0x7A
	  lwz       r3, 0x0(r31)
	  fsubs     f1, f1, f0
	  bl        -0x596C8
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1D22B8
	  lfs       f0, -0x4188(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x468
	  addi      r3, r1, 0xC0
	  bl        -0x1569C0

	.loc_0x468:
	  lfs       f0, 0x2514(r13)
	  lwz       r3, 0x2DEC(r13)
	  fsubs     f2, f0, f29
	  lfs       f3, -0x417C(r2)
	  lfs       f1, 0x28C(r3)
	  lfs       f0, 0xC0(r1)
	  fmuls     f1, f2, f1
	  fmuls     f1, f3, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  stfs      f28, 0x28(r31)
	  stfs      f30, 0x2C(r31)
	  stfs      f31, 0x30(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x34(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x34(r31)
	  lfs       f1, 0x251C(r13)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x4E0
	  fsubs     f0, f0, f1
	  stfs      f0, 0x34(r31)

	.loc_0x4E0:
	  lfs       f2, 0x34(r31)
	  lfs       f1, 0x251C(r13)
	  lfs       f0, -0x4108(r2)
	  fdivs     f1, f2, f1
	  fmuls     f28, f0, f1
	  fmr       f1, f28
	  bl        0x3BD48
	  lfs       f0, -0x4100(r2)
	  lfs       f3, -0x4104(r2)
	  lfs       f2, 0x4(r30)
	  fmuls     f0, f0, f1
	  fmr       f1, f28
	  fmuls     f2, f3, f2
	  fsubs     f28, f2, f0
	  bl        0x3BD28
	  lfs       f0, -0x4100(r2)
	  lfs       f3, -0x4104(r2)
	  lfs       f2, 0x0(r30)
	  fmuls     f1, f0, f1
	  lfs       f0, 0x24A8(r13)
	  fmuls     f2, f3, f2
	  fadds     f1, f2, f1
	  stfs      f1, 0x10C(r1)
	  stfs      f28, 0x110(r1)
	  stfs      f0, 0x114(r1)
	  lwz       r4, 0x0(r31)
	  lwz       r3, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x114(r1)
	  stw       r0, 0xC8(r4)
	  lwz       r5, 0x38(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x600
	  lfs       f0, -0x4188(r2)
	  lis       r3, 0x4330
	  stfs      f0, 0x150(r1)
	  stfs      f0, 0x14C(r1)
	  stfs      f0, 0x148(r1)
	  lfd       f2, -0x4168(r2)
	  lwz       r4, 0x0(r31)
	  lha       r6, 0x18(r4)
	  lha       r0, 0x1C(r4)
	  lha       r4, 0x1A(r4)
	  sub       r0, r0, r6
	  srawi     r0, r0, 0x1
	  add       r0, r6, r0
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x16C(r1)
	  xoris     r0, r4, 0x8000
	  stw       r3, 0x168(r1)
	  stw       r0, 0x174(r1)
	  lfd       f0, 0x168(r1)
	  stw       r3, 0x170(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x170(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x148(r1)
	  stfs      f0, 0x14C(r1)
	  lfs       f0, 0x24AC(r13)
	  stfs      f0, 0x150(r1)
	  lfs       f1, -0x413C(r2)
	  lfs       f0, 0x14C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14C(r1)
	  lwz       r3, 0x148(r1)
	  lwz       r0, 0x14C(r1)
	  stw       r3, 0xC(r5)
	  stw       r0, 0x10(r5)
	  lwz       r0, 0x150(r1)
	  stw       r0, 0x14(r5)

	.loc_0x600:
	  lwz       r0, 0x1A4(r1)
	  lfd       f31, 0x198(r1)
	  lfd       f30, 0x190(r1)
	  lfd       f29, 0x188(r1)
	  lfd       f28, 0x180(r1)
	  lwz       r31, 0x17C(r1)
	  lwz       r30, 0x178(r1)
	  addi      r1, r1, 0x1A0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E00D0
 * Size:	000350
 */
void zen::WorldMapCursorMgr::moveOnyon()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stfd      f31, 0x158(r1)
	  addi      r6, r1, 0x4C
	  addi      r5, r1, 0x48
	  stfd      f30, 0x150(r1)
	  addi      r4, r1, 0x44
	  stfd      f29, 0x148(r1)
	  stfd      f28, 0x140(r1)
	  stfd      f27, 0x138(r1)
	  stfd      f26, 0x130(r1)
	  stfd      f25, 0x128(r1)
	  stw       r31, 0x124(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0xB0
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x104(r1)
	  stfs      f0, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  lwz       r7, 0x2DEC(r13)
	  stfs      f0, 0x110(r1)
	  lfs       f2, -0x4130(r2)
	  stfs      f0, 0x10C(r1)
	  lfs       f5, 0x25E8(r13)
	  stfs      f0, 0x108(r1)
	  lfs       f3, 0x25E4(r13)
	  stfs      f0, 0x11C(r1)
	  lfs       f1, 0x25E0(r13)
	  stfs      f0, 0x118(r1)
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x28C(r7)
	  lwz       r7, 0x8(r31)
	  fmuls     f7, f2, f0
	  lfs       f0, 0x10C(r31)
	  lfs       f6, 0x20(r31)
	  lfs       f4, 0x1C(r31)
	  fmuls     f0, f0, f7
	  lfs       f2, 0x18(r31)
	  fadds     f31, f6, f5
	  lfs       f28, 0xC0(r7)
	  fadds     f30, f4, f3
	  stfs      f0, 0x4C(r1)
	  fadds     f29, f2, f1
	  lfs       f0, 0x108(r31)
	  fmuls     f0, f0, f7
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x104(r31)
	  fmuls     f0, f0, f7
	  stfs      f0, 0x44(r1)
	  bl        -0x1A907C
	  lfs       f1, 0xF8(r31)
	  addi      r6, r1, 0x64
	  lfs       f0, 0xB0(r1)
	  addi      r5, r1, 0x60
	  lfs       f2, 0xB8(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0xB4(r1)
	  addi      r4, r1, 0x5C
	  addi      r3, r1, 0xBC
	  stfs      f0, 0xF8(r31)
	  lfs       f0, 0xFC(r31)
	  fadds     f0, f0, f1
	  stfs      f0, 0xFC(r31)
	  lfs       f0, 0x100(r31)
	  fadds     f0, f0, f2
	  stfs      f0, 0x100(r31)
	  lfs       f0, 0x100(r31)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0xFC(r31)
	  fsubs     f0, f0, f30
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0xF8(r31)
	  fsubs     f0, f0, f29
	  stfs      f0, 0x5C(r1)
	  bl        -0x1A90E4
	  lfs       f26, 0xBC(r1)
	  lfs       f27, 0xC0(r1)
	  fmuls     f1, f26, f26
	  lfs       f25, 0xC4(r1)
	  fmuls     f0, f27, f27
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1D25E4
	  lfs       f0, -0x4118(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x174
	  lfs       f26, 0x2520(r13)
	  lfs       f27, 0x2524(r13)
	  lfs       f25, 0x2528(r13)
	  b         .loc_0x18C

	.loc_0x174:
	  lfs       f0, 0x25DC(r13)
	  fmuls     f0, f0, f28
	  fdivs     f0, f0, f1
	  fmuls     f26, f26, f0
	  fmuls     f27, f27, f0
	  fmuls     f25, f25, f0

	.loc_0x18C:
	  fadds     f2, f31, f25
	  addi      r6, r1, 0x58
	  fadds     f1, f30, f27
	  addi      r5, r1, 0x54
	  fadds     f0, f29, f26
	  stfs      f2, 0x58(r1)
	  addi      r4, r1, 0x50
	  addi      r3, r1, 0xC8
	  stfs      f1, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  bl        -0x1A9168
	  lfs       f28, 0xD0(r1)
	  addi      r6, r1, 0x40
	  lfs       f0, 0x100(r31)
	  addi      r5, r1, 0x3C
	  lfs       f31, 0xCC(r1)
	  fsubs     f0, f28, f0
	  lfs       f25, 0xC8(r1)
	  addi      r4, r1, 0x38
	  addi      r3, r1, 0xE0
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0xFC(r31)
	  fsubs     f0, f31, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0xF8(r31)
	  fsubs     f0, f25, f0
	  stfs      f0, 0x38(r1)
	  bl        -0x1A91AC
	  lfs       f1, 0x104(r31)
	  lfs       f0, 0xE0(r1)
	  lfs       f2, 0xE4(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0xE8(r1)
	  stfs      f0, 0x104(r31)
	  lfs       f0, 0x108(r31)
	  fadds     f0, f0, f2
	  stfs      f0, 0x108(r31)
	  lfs       f0, 0x10C(r31)
	  fadds     f0, f0, f1
	  stfs      f0, 0x10C(r31)
	  stfs      f25, 0xF8(r31)
	  stfs      f31, 0xFC(r31)
	  stfs      f28, 0x100(r31)
	  lfs       f0, 0xF8(r31)
	  stfs      f0, 0xFC(r1)
	  lfs       f0, 0xFC(r31)
	  stfs      f0, 0x100(r1)
	  lfs       f0, 0x252C(r13)
	  stfs      f0, 0x104(r1)
	  lfs       f1, -0x40FC(r2)
	  bl        0x3B830
	  fmr       f25, f1
	  lfs       f1, -0x40FC(r2)
	  bl        0x3B9B8
	  fmuls     f3, f26, f25
	  fmuls     f0, f26, f1
	  fmuls     f2, f27, f1
	  fadds     f3, f29, f3
	  fadds     f1, f30, f0
	  fmuls     f0, f27, f25
	  fsubs     f2, f3, f2
	  fadds     f0, f1, f0
	  stfs      f2, 0x108(r1)
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x2530(r13)
	  lfs       f1, -0x40F8(r2)
	  stfs      f0, 0x110(r1)
	  bl        0x3B7EC
	  fmr       f25, f1
	  lfs       f1, -0x40F8(r2)
	  bl        0x3B974
	  fmuls     f3, f26, f25
	  fmuls     f0, f26, f1
	  fmuls     f2, f27, f1
	  fadds     f3, f29, f3
	  fadds     f1, f30, f0
	  fmuls     f0, f27, f25
	  fsubs     f2, f3, f2
	  fadds     f0, f1, f0
	  stfs      f2, 0x114(r1)
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x2534(r13)
	  stfs      f0, 0x11C(r1)
	  lfs       f1, 0x100(r1)
	  lfs       f0, 0xFC(r1)
	  stfs      f0, 0x54(r31)
	  stfs      f1, 0x58(r31)
	  lfs       f0, 0x24B0(r13)
	  stfs      f0, 0x5C(r31)
	  lfs       f1, 0x10C(r1)
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0x90(r31)
	  stfs      f1, 0x94(r31)
	  lfs       f0, 0x24B0(r13)
	  stfs      f0, 0x98(r31)
	  lfs       f1, 0x118(r1)
	  lfs       f0, 0x114(r1)
	  stfs      f0, 0xCC(r31)
	  stfs      f1, 0xD0(r31)
	  lfs       f0, 0x24B0(r13)
	  stfs      f0, 0xD4(r31)
	  lwz       r0, 0x164(r1)
	  lfd       f31, 0x158(r1)
	  lfd       f30, 0x150(r1)
	  lfd       f29, 0x148(r1)
	  lfd       f28, 0x140(r1)
	  lfd       f27, 0x138(r1)
	  lfd       f26, 0x130(r1)
	  lfd       f25, 0x128(r1)
	  lwz       r31, 0x124(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E0420
 * Size:	0000D0
 */
void zen::WorldMapCursorMgr::forceMove()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lbz       r0, 0x35(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xBC
	  li        r0, 0x1
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x4C
	  bge-      .loc_0x4C
	  cmpwi     r0, 0
	  bge-      .loc_0x44
	  b         .loc_0x4C

	.loc_0x44:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r31)

	.loc_0x4C:
	  lfs       f0, -0x4188(r2)
	  li        r4, 0
	  li        r0, 0x1
	  stfs      f0, 0x0(r31)
	  li        r3, 0x124
	  lfs       f0, 0x38(r31)
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0x3C(r31)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x40(r31)
	  stfs      f0, 0x14(r31)
	  stb       r4, 0x35(r31)
	  stb       r0, 0x34(r31)
	  bl        -0x13B12C
	  lwz       r3, 0x110(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lfs       f1, -0x415C(r2)
	  lfs       f0, 0x118(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB8(r3)

	.loc_0xA0:
	  lwz       r3, 0x114(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xBC
	  lfs       f1, -0x4158(r2)
	  lfs       f0, 0x11C(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xB8(r3)

	.loc_0xBC:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E04F0
 * Size:	000494
 */
void zen::WorldMapCursorMgr::moveUfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stfd      f26, 0xC8(r1)
	  stw       r31, 0xC4(r1)
	  li        r31, 0
	  stw       r30, 0xC0(r1)
	  mr        r30, r3
	  lfs       f2, 0x2538(r13)
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0x1C(r3)
	  fmuls     f5, f2, f2
	  lfs       f2, 0xC(r3)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x18(r3)
	  lwz       r3, 0x8(r3)
	  fsubs     f2, f2, f0
	  lwz       r4, 0x2DEC(r13)
	  fmuls     f3, f1, f1
	  lfs       f0, -0x4188(r2)
	  fmuls     f4, f2, f2
	  lfs       f6, -0x4130(r2)
	  lfs       f27, 0xC0(r3)
	  fadds     f3, f4, f3
	  lfs       f4, 0x28C(r4)
	  lfs       f26, -0x4184(r2)
	  fmuls     f28, f6, f4
	  fadds     f30, f5, f3
	  fcmpo     cr0, f30, f0
	  ble-      .loc_0xE4
	  fsqrte    f3, f30
	  lfd       f5, -0x4128(r2)
	  lfd       f4, -0x4120(r2)
	  fmul      f0, f3, f3
	  fmul      f3, f5, f3
	  fmul      f0, f30, f0
	  fsub      f0, f4, f0
	  fmul      f3, f3, f0
	  fmul      f0, f3, f3
	  fmul      f3, f5, f3
	  fmul      f0, f30, f0
	  fsub      f0, f4, f0
	  fmul      f3, f3, f0
	  fmul      f0, f3, f3
	  fmul      f3, f5, f3
	  fmul      f0, f30, f0
	  fsub      f0, f4, f0
	  fmul      f0, f3, f0
	  fmul      f0, f30, f0
	  frsp      f0, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f30, 0x7C(r1)

	.loc_0xE4:
	  lwz       r3, 0x8(r30)
	  lfs       f3, -0x4148(r2)
	  lfs       f4, 0xBC(r3)
	  lfs       f0, -0x4188(r2)
	  fsubs     f3, f4, f3
	  fcmpo     cr0, f3, f0
	  fmr       f31, f3
	  bge-      .loc_0x110
	  lfs       f0, -0x4108(r2)
	  fadds     f31, f31, f0
	  b         .loc_0x120

	.loc_0x110:
	  lfs       f0, -0x4108(r2)
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x120
	  fsubs     f31, f31, f0

	.loc_0x120:
	  bl        -0xC2808
	  lfs       f0, -0x4114(r2)
	  lbz       r0, 0x34(r30)
	  fdivs     f3, f30, f0
	  lfs       f0, -0x4110(r2)
	  cmplwi    r0, 0
	  fmuls     f29, f0, f3
	  beq-      .loc_0x1B4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x0(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r30)
	  lfs       f0, -0x417C(r2)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x174
	  lfs       f26, -0x4188(r2)
	  fcmpu     cr0, f26, f27
	  bne-      .loc_0x188
	  li        r31, 0x1
	  b         .loc_0x188

	.loc_0x174:
	  lfs       f0, -0x4184(r2)
	  fmr       f26, f3
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x188
	  fmr       f26, f0

	.loc_0x188:
	  lfs       f2, -0x40F0(r2)
	  lfs       f0, 0x0(r30)
	  lfs       f3, -0x40F4(r2)
	  fmuls     f2, f2, f0
	  lfs       f0, -0x40EC(r2)
	  fmuls     f29, f29, f3
	  fcmpo     cr0, f2, f0
	  fmr       f3, f2
	  ble-      .loc_0x1D4
	  lfs       f3, -0x4188(r2)
	  b         .loc_0x1D4

	.loc_0x1B4:
	  lfs       f0, -0x40F0(r2)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x1D0
	  lfs       f0, -0x4184(r2)
	  fcmpu     cr0, f0, f27
	  bne-      .loc_0x1D0
	  li        r31, 0x1

	.loc_0x1D0:
	  lfs       f3, -0x417C(r2)

	.loc_0x1D4:
	  fsubs     f4, f1, f31
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x1EC
	  fneg      f2, f4
	  b         .loc_0x1F0

	.loc_0x1EC:
	  fmr       f2, f4

	.loc_0x1F0:
	  lfs       f1, -0x4150(r2)
	  lfs       f0, -0x40EC(r2)
	  fmuls     f1, f1, f3
	  fdivs     f3, f1, f0
	  fcmpo     cr0, f2, f3
	  ble-      .loc_0x25C
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x21C
	  fneg      f1, f4
	  b         .loc_0x220

	.loc_0x21C:
	  fmr       f1, f4

	.loc_0x220:
	  lfs       f0, -0x4150(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x244
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x258
	  lfs       f0, -0x40E8(r2)
	  fmuls     f3, f3, f0
	  b         .loc_0x258

	.loc_0x244:
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x258
	  lfs       f0, -0x40E8(r2)
	  fmuls     f3, f3, f0

	.loc_0x258:
	  fmuls     f4, f3, f28

	.loc_0x25C:
	  fadds     f31, f31, f4
	  lfs       f1, -0x4148(r2)
	  lfs       f0, -0x4188(r2)
	  fadds     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x280
	  lfs       f0, -0x4108(r2)
	  fadds     f1, f1, f0
	  b         .loc_0x290

	.loc_0x280:
	  lfs       f0, -0x4108(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x290
	  fsubs     f1, f1, f0

	.loc_0x290:
	  lwz       r3, 0x8(r30)
	  li        r4, 0x7A
	  lha       r5, 0x18(r3)
	  lha       r0, 0x1C(r3)
	  lha       r6, 0x1A(r3)
	  sub       r0, r0, r5
	  lha       r5, 0x1E(r3)
	  srawi     r0, r0, 0x1
	  sub       r6, r5, r6
	  extsh     r5, r0
	  srawi     r0, r6, 0x1
	  sth       r5, 0xB8(r3)
	  extsh     r0, r0
	  sth       r0, 0xBA(r3)
	  bl        -0x59FAC
	  lfs       f0, -0x4110(r2)
	  fcmpo     cr0, f29, f0
	  ble-      .loc_0x2DC
	  fmr       f29, f0

	.loc_0x2DC:
	  fmr       f1, f31
	  bl        0x3B518
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x3B378
	  fmuls     f1, f29, f1
	  fmuls     f0, f29, f30
	  fmuls     f1, f28, f1
	  fmuls     f0, f28, f0
	  stfs      f1, 0x24(r30)
	  stfs      f0, 0x28(r30)
	  lfs       f0, 0x253C(r13)
	  stfs      f0, 0x2C(r30)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x24(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r30)
	  lfs       f1, 0x1C(r30)
	  lfs       f0, 0x28(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r30)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x2C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  lfs       f1, 0x18(r30)
	  lfs       f0, -0x40E4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x354
	  stfs      f0, 0x18(r30)

	.loc_0x354:
	  lfs       f1, 0x18(r30)
	  lfs       f0, -0x40E0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x368
	  stfs      f0, 0x18(r30)

	.loc_0x368:
	  lfs       f1, 0x1C(r30)
	  lfs       f0, -0x40E4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x37C
	  stfs      f0, 0x1C(r30)

	.loc_0x37C:
	  lfs       f1, 0x1C(r30)
	  lfs       f0, -0x40DC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x390
	  stfs      f0, 0x1C(r30)

	.loc_0x390:
	  lfs       f1, 0x1C(r30)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3B0
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x3B8

	.loc_0x3B0:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x3B8:
	  lfs       f2, 0x18(r30)
	  fctiwz    f1, f0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0xB8(r1)
	  lwz       r5, 0xBC(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3E4
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x3EC

	.loc_0x3E4:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0x3EC:
	  lwz       r3, 0x8(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0xB8(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0xBC(r1)
	  mtlr      r12
	  blrl
	  fsubs     f1, f27, f26
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x420
	  fneg      f1, f1

	.loc_0x420:
	  lfs       f0, -0x40D8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x434
	  fmr       f27, f26
	  b         .loc_0x450

	.loc_0x434:
	  fcmpo     cr0, f27, f26
	  bge-      .loc_0x448
	  fmuls     f0, f0, f28
	  fadds     f27, f27, f0
	  b         .loc_0x450

	.loc_0x448:
	  fmuls     f0, f0, f28
	  fsubs     f27, f27, f0

	.loc_0x450:
	  lwz       r4, 0x8(r30)
	  mr        r3, r31
	  stfs      f27, 0xC0(r4)
	  stfs      f27, 0xC4(r4)
	  stfs      f27, 0xC8(r4)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lfd       f26, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E0984
 * Size:	0003B4
 */
void zen::WorldMapCursorMgr::stayUfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f2, 0xC(r3)
	  lfs       f1, 0x18(r3)
	  lfs       f6, 0x28C(r4)
	  fsubs     f5, f2, f1
	  lfs       f0, -0x4180(r2)
	  lfs       f1, -0x4130(r2)
	  fmuls     f3, f0, f6
	  lfs       f4, 0x2540(r13)
	  lfs       f0, 0x24(r3)
	  fmuls     f31, f1, f6
	  fmuls     f5, f5, f3
	  lfs       f2, 0x10(r3)
	  fmuls     f4, f4, f3
	  lfs       f1, 0x1C(r3)
	  fadds     f0, f0, f5
	  fsubs     f1, f2, f1
	  stfs      f0, 0x24(r3)
	  fmuls     f1, f1, f3
	  lfs       f0, 0x28(r3)
	  fadds     f0, f0, f1
	  stfs      f0, 0x28(r3)
	  lfs       f0, 0x2C(r3)
	  fadds     f0, f0, f4
	  stfs      f0, 0x2C(r3)
	  lfs       f0, 0x24(r3)
	  lfs       f1, -0x40D4(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r3)
	  lfs       f0, 0x28(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x28(r3)
	  lfs       f0, 0x2C(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r3)
	  lfs       f1, 0x24(r3)
	  lfs       f3, 0x2C(r3)
	  lfs       f0, 0x28(r3)
	  fmuls     f2, f1, f1
	  fmuls     f3, f3, f3
	  fmuls     f1, f0, f0
	  lfs       f0, -0x4188(r2)
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x128
	  fsqrte    f1, f4
	  lfd       f3, -0x4128(r2)
	  lfd       f2, -0x4120(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x74(r1)
	  lfs       f4, 0x74(r1)

	.loc_0x128:
	  lfs       f0, -0x4118(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x150
	  lfs       f0, 0x2544(r13)
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x2548(r13)
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x254C(r13)
	  stfs      f0, 0x2C(r31)
	  b         .loc_0x1B8

	.loc_0x150:
	  lfs       f0, -0x4184(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x184
	  fdivs     f1, f0, f4
	  lfs       f0, 0x24(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x2C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r31)

	.loc_0x184:
	  lfs       f0, -0x4154(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x1B8
	  fdivs     f1, f0, f4
	  lfs       f0, 0x24(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x2C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r31)

	.loc_0x1B8:
	  lfs       f1, 0x18(r31)
	  lfs       f0, 0x24(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r31)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x28(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x2C(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x208
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x210

	.loc_0x208:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x210:
	  lfs       f2, 0x18(r31)
	  fctiwz    f1, f0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0xA8(r1)
	  lwz       r5, 0xAC(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x23C
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x244

	.loc_0x23C:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0x244:
	  lwz       r3, 0x8(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0xA8(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0xAC(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8(r31)
	  lfs       f1, -0x4188(r2)
	  lfs       f0, 0xBC(r3)
	  fsubs     f3, f1, f0
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x284
	  fneg      f0, f3
	  b         .loc_0x288

	.loc_0x284:
	  fmr       f0, f3

	.loc_0x288:
	  lfs       f1, -0x40D0(r2)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x2E8
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x2A8
	  fneg      f2, f3
	  b         .loc_0x2AC

	.loc_0x2A8:
	  fmr       f2, f3

	.loc_0x2AC:
	  lfs       f0, -0x4150(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x2D0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x2E4
	  lfs       f0, -0x40E8(r2)
	  fmuls     f1, f1, f0
	  b         .loc_0x2E4

	.loc_0x2D0:
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x2E4
	  lfs       f0, -0x40E8(r2)
	  fmuls     f1, f1, f0

	.loc_0x2E4:
	  fmuls     f3, f1, f31

	.loc_0x2E8:
	  lfs       f0, 0x30(r31)
	  fadds     f0, f0, f3
	  stfs      f0, 0x30(r31)
	  lfs       f1, 0x30(r31)
	  lfs       f0, -0x40CC(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x30(r31)
	  lfs       f1, 0x30(r31)
	  lfs       f0, -0x40C8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x318
	  stfs      f0, 0x30(r31)

	.loc_0x318:
	  lfs       f1, 0x30(r31)
	  lfs       f0, -0x40C4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x32C
	  stfs      f0, 0x30(r31)

	.loc_0x32C:
	  lwz       r3, 0x8(r31)
	  lfs       f1, 0x30(r31)
	  lfs       f2, 0xBC(r3)
	  lfs       f0, -0x4188(r2)
	  fadds     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x354
	  lfs       f0, -0x4108(r2)
	  fadds     f1, f1, f0
	  b         .loc_0x364

	.loc_0x354:
	  lfs       f0, -0x4108(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x364
	  fsubs     f1, f1, f0

	.loc_0x364:
	  lha       r4, 0x18(r3)
	  lha       r0, 0x1C(r3)
	  lha       r6, 0x1A(r3)
	  sub       r0, r0, r4
	  lha       r5, 0x1E(r3)
	  srawi     r0, r0, 0x1
	  extsh     r4, r0
	  sub       r0, r5, r6
	  sth       r4, 0xB8(r3)
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xBA(r3)
	  li        r4, 0x7A
	  bl        -0x5A510
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E0D38
 * Size:	000134
 */
void zen::DrawWorldMap::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x104
	  lwz       r3, 0x30(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x28(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1C(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x14(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x50(r30)
	  mr        r4, r31
	  bl        0x8DA4
	  lwz       r3, 0x70(r30)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x110

	.loc_0x104:
	  addi      r3, r30, 0x74
	  addi      r4, r31, 0
	  bl        -0x4FCA0

	.loc_0x110:
	  addi      r3, r30, 0x64
	  addi      r4, r31, 0
	  bl        0x912C
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
 * Size:	000AA4
 */
void zen::DrawWorldMap::setCoursePoint(zen::DrawWorldMap::startPlaceFlag)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801E0E6C
 * Size:	001B78
 */
void zen::DrawWorldMap::start(zen::DrawWorldMap::startModeFlag, zen::DrawWorldMap::startPlaceFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x470(r1)
	  stfd      f31, 0x468(r1)
	  stfd      f30, 0x460(r1)
	  stfd      f29, 0x458(r1)
	  stmw      r21, 0x42C(r1)
	  mr        r31, r3
	  addi      r24, r5, 0
	  stw       r4, 0x0(r3)
	  li        r4, 0x1
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x50(r3)
	  bl        0x8E28
	  li        r0, 0x5
	  stw       r0, 0x8(r31)
	  lwz       r3, 0x10(r31)
	  addi      r3, r3, 0x4
	  bl        -0x2171C
	  lwz       r3, 0x1C(r31)
	  addi      r3, r3, 0x4
	  bl        -0x21728
	  lwz       r3, 0x14(r31)
	  addi      r3, r3, 0x4
	  bl        -0x21734
	  lwz       r3, 0x18(r31)
	  addi      r3, r3, 0x4
	  bl        -0x21740
	  lwz       r3, 0x20(r31)
	  addi      r3, r3, 0x4
	  bl        -0x2174C
	  lwz       r3, 0x24(r31)
	  addi      r3, r3, 0x4
	  bl        -0x21758
	  lwz       r3, 0x28(r31)
	  addi      r3, r3, 0x4
	  bl        -0x21764
	  lwz       r3, 0x2C(r31)
	  addi      r3, r3, 0x4
	  bl        -0x21770
	  lwz       r3, 0x30(r31)
	  addi      r3, r3, 0x4
	  bl        -0x2177C
	  lwz       r22, 0x34(r31)
	  lwz       r4, 0x8(r22)
	  cmplwi    r4, 0
	  beq-      .loc_0x158
	  lha       r0, 0x18(r4)
	  lis       r3, 0x4330
	  lha       r4, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x424(r1)
	  xoris     r0, r4, 0x8000
	  stw       r3, 0x420(r1)
	  stw       r0, 0x41C(r1)
	  lfd       f0, 0x420(r1)
	  stw       r3, 0x418(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x418(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x18(r22)
	  stfs      f0, 0x1C(r22)
	  lfs       f0, 0x2578(r13)
	  stfs      f0, 0x20(r22)
	  lwz       r5, 0x8(r22)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x8(r22)
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)

	.loc_0x158:
	  mr        r3, r22
	  bl        -0x3018
	  addi      r3, r22, 0x44
	  bl        -0x313C
	  addi      r3, r22, 0x80
	  bl        -0x3144
	  addi      r3, r22, 0xBC
	  bl        -0x314C
	  li        r21, 0
	  addi      r23, r22, 0

	.loc_0x180:
	  lwz       r0, 0x110(r23)
	  cmplwi    r0, 0
	  beq-      .loc_0x194
	  lwz       r3, 0x110(r22)
	  bl        -0x40400

	.loc_0x194:
	  addi      r21, r21, 0x1
	  cmpwi     r21, 0x2
	  addi      r23, r23, 0x4
	  blt+      .loc_0x180
	  lfs       f0, 0x257C(r13)
	  addi      r5, r1, 0x394
	  lfs       f1, 0x2580(r13)
	  li        r4, 0x30
	  stfs      f0, 0x394(r1)
	  lfs       f0, 0x2584(r13)
	  li        r6, 0
	  stfs      f1, 0x398(r1)
	  li        r7, 0
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x39C(r1)
	  bl        0x8B00
	  stw       r3, 0x110(r22)
	  addi      r5, r1, 0x3A0
	  li        r4, 0x31
	  lwz       r3, 0x110(r22)
	  li        r6, 0
	  li        r7, 0
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  lwz       r3, 0x110(r22)
	  lfs       f0, 0xB8(r3)
	  stfs      f0, 0x118(r22)
	  lwz       r3, 0x110(r22)
	  lfs       f0, 0xCC(r3)
	  stfs      f0, 0x120(r22)
	  lfs       f0, 0x2588(r13)
	  lfs       f1, 0x258C(r13)
	  stfs      f0, 0x3A0(r1)
	  lfs       f0, 0x2590(r13)
	  stfs      f1, 0x3A4(r1)
	  lwz       r3, 0x31C0(r13)
	  stfs      f0, 0x3A8(r1)
	  bl        0x8AA4
	  stw       r3, 0x114(r22)
	  lwz       r3, 0x114(r22)
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,28,26
	  stw       r0, 0x80(r3)
	  lwz       r3, 0x114(r22)
	  lfs       f0, 0xB8(r3)
	  stfs      f0, 0x11C(r22)
	  lwz       r3, 0x110(r22)
	  lfs       f0, 0xCC(r3)
	  stfs      f0, 0x124(r22)
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x2F0
	  li        r23, 0

	.loc_0x26C:
	  lwz       r3, 0x2F6C(r13)
	  mr        r4, r23
	  bl        -0x160B14
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B0
	  lwz       r3, 0x44(r22)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x2DC
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)
	  b         .loc_0x2DC

	.loc_0x2B0:
	  lwz       r3, 0x44(r22)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x2DC
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x2DC:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x3
	  addi      r22, r22, 0x3C
	  blt+      .loc_0x26C
	  b         .loc_0x374

	.loc_0x2F0:
	  lwz       r3, 0x44(r22)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x31C
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x31C:
	  lwz       r3, 0x80(r22)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xB8(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x348
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x348:
	  lwz       r3, 0xBC(r22)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xF4(r22)
	  cmplwi    r3, 0
	  beq-      .loc_0x374
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x374:
	  cmpwi     r24, 0x2
	  beq-      .loc_0x69C
	  bge-      .loc_0x390
	  cmpwi     r24, 0
	  beq-      .loc_0x3A0
	  bge-      .loc_0x51C
	  b         .loc_0xB1C

	.loc_0x390:
	  cmpwi     r24, 0x4
	  beq-      .loc_0x99C
	  bge-      .loc_0xB1C
	  b         .loc_0x81C

	.loc_0x3A0:
	  lwz       r8, 0x38(r31)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x3F0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x3F0:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x434
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x434:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x478
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x478:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x4BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x4BC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x4FC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x4FC:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        0x1A44
	  b         .loc_0xC94

	.loc_0x51C:
	  lwz       r8, 0x38(r31)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x56C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x56C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x5B0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x5B0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x5F4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x5F4:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x638
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x638:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x678
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x678:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        0x18C4
	  b         .loc_0xC94

	.loc_0x69C:
	  lwz       r8, 0x38(r31)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x6EC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x6EC:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x730
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x730:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x774
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x774:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x7B8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x7B8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x7F8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x7F8:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        0x1744
	  b         .loc_0xC94

	.loc_0x81C:
	  lwz       r8, 0x38(r31)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x86C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x86C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x8B0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x8B0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x8F4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x8F4:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x938
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x938:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x978
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x978:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        0x15C4
	  b         .loc_0xC94

	.loc_0x99C:
	  lwz       r8, 0x38(r31)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x9EC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x9EC:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xA30
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xA30:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xA74
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xA74:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xAB8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xAB8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xAF8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xAF8:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        0x1444
	  b         .loc_0xC94

	.loc_0xB1C:
	  lwz       r8, 0x38(r31)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xB6C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xB6C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xBB0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xBB0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xBF4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xBF4:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xC38
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC38:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xC78
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC78:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        0x12C8

	.loc_0xC94:
	  lwz       r4, 0x38(r31)
	  lis       r3, 0x4330
	  lfd       f3, -0x4168(r2)
	  lwz       r4, 0x4(r4)
	  lwz       r30, 0x34(r31)
	  lwz       r5, 0x28(r4)
	  lha       r4, 0x18(r5)
	  lha       r5, 0x1A(r5)
	  xoris     r6, r4, 0x8000
	  stw       r6, 0x41C(r1)
	  xoris     r0, r5, 0x8000
	  stw       r3, 0x418(r1)
	  stw       r0, 0x424(r1)
	  lfd       f0, 0x418(r1)
	  stw       r3, 0x420(r1)
	  fsubs     f2, f0, f3
	  lfd       f0, 0x420(r1)
	  stw       r6, 0x414(r1)
	  fsubs     f1, f0, f3
	  stfs      f2, 0x18(r30)
	  stw       r3, 0x410(r1)
	  stw       r0, 0x40C(r1)
	  lfd       f0, 0x410(r1)
	  stfs      f1, 0x1C(r30)
	  fsubs     f1, f0, f3
	  stw       r3, 0x408(r1)
	  lfs       f2, 0x256C(r13)
	  lfd       f0, 0x408(r1)
	  stfs      f2, 0x20(r30)
	  fsubs     f0, f0, f3
	  stfs      f1, 0xC(r30)
	  stfs      f0, 0x10(r30)
	  lfs       f0, 0x2570(r13)
	  stfs      f0, 0x14(r30)
	  lwz       r3, 0x8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x4188(r2)
	  addi      r5, r1, 0x2E8
	  lfs       f0, 0x2574(r13)
	  addi      r6, r1, 0x2F4
	  stfs      f1, 0x378(r1)
	  mr        r3, r30
	  stfs      f1, 0x37C(r1)
	  addi      r4, r1, 0x2DC
	  stfs      f0, 0x380(r1)
	  lwz       r8, 0x8(r30)
	  lwz       r7, 0x378(r1)
	  lwz       r0, 0x37C(r1)
	  stw       r7, 0xC0(r8)
	  stw       r0, 0xC4(r8)
	  lwz       r0, 0x380(r1)
	  stw       r0, 0xC8(r8)
	  stfs      f1, 0x2E4(r1)
	  stfs      f1, 0x2E0(r1)
	  stfs      f1, 0x2DC(r1)
	  stfs      f1, 0x2F0(r1)
	  stfs      f1, 0x2EC(r1)
	  stfs      f1, 0x2E8(r1)
	  stfs      f1, 0x2FC(r1)
	  stfs      f1, 0x2F8(r1)
	  stfs      f1, 0x2F4(r1)
	  bl        0xEAC
	  lfs       f1, -0x4188(r2)
	  addi      r3, r30, 0x48
	  lfs       f0, 0x2DC(r1)
	  addi      r4, r1, 0x260
	  stfs      f1, 0x258(r1)
	  addi      r5, r1, 0x25C
	  lfs       f1, 0x2E0(r1)
	  addi      r6, r13, 0x24B4
	  stfs      f1, 0x25C(r1)
	  stfs      f0, 0x260(r1)
	  bl        -0x1845A0
	  addi      r3, r30, 0x54
	  addi      r4, r1, 0x260
	  addi      r5, r1, 0x25C
	  addi      r6, r13, 0x24B8
	  bl        -0x1845B4
	  lfs       f1, 0x25C(r1)
	  addi      r5, r1, 0x264
	  lfs       f0, 0x2514(r13)
	  addi      r3, r30, 0x6C
	  addi      r4, r1, 0x260
	  fadds     f0, f1, f0
	  addi      r6, r13, 0x24BC
	  stfs      f0, 0x264(r1)
	  bl        -0x1845D8
	  lfs       f1, 0x48(r30)
	  lfs       f0, 0x4C(r30)
	  lwz       r3, 0x44(r30)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x400(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x3F8(r1)
	  mtlr      r12
	  lwz       r4, 0x404(r1)
	  lwz       r5, 0x3FC(r1)
	  blrl
	  addi      r4, r1, 0x258
	  addi      r5, r4, 0
	  addi      r3, r1, 0x268
	  addi      r6, r13, 0x24C0
	  bl        -0x1AAB90
	  lwz       r7, 0x44(r30)
	  addi      r3, r30, 0x84
	  lwz       r6, 0x268(r1)
	  addi      r4, r1, 0x244
	  lwz       r0, 0x26C(r1)
	  addi      r5, r1, 0x240
	  stw       r6, 0xC0(r7)
	  addi      r6, r13, 0x24B4
	  stw       r0, 0xC4(r7)
	  lwz       r0, 0x270(r1)
	  stw       r0, 0xC8(r7)
	  lfs       f1, -0x4188(r2)
	  lfs       f0, 0x2EC(r1)
	  stfs      f1, 0x23C(r1)
	  stfs      f0, 0x240(r1)
	  lfs       f0, 0x2E8(r1)
	  stfs      f0, 0x244(r1)
	  bl        -0x184668
	  addi      r3, r30, 0x90
	  addi      r4, r1, 0x244
	  addi      r5, r1, 0x240
	  addi      r6, r13, 0x24B8
	  bl        -0x18467C
	  lfs       f1, 0x240(r1)
	  addi      r5, r1, 0x248
	  lfs       f0, 0x2514(r13)
	  addi      r3, r30, 0xA8
	  addi      r4, r1, 0x244
	  fadds     f0, f1, f0
	  addi      r6, r13, 0x24BC
	  stfs      f0, 0x248(r1)
	  bl        -0x1846A0
	  lfs       f1, 0x84(r30)
	  lfs       f0, 0x88(r30)
	  lwz       r3, 0x80(r30)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x3F0(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x3E8(r1)
	  mtlr      r12
	  lwz       r4, 0x3F4(r1)
	  lwz       r5, 0x3EC(r1)
	  blrl
	  addi      r4, r1, 0x23C
	  addi      r5, r4, 0
	  addi      r3, r1, 0x24C
	  addi      r6, r13, 0x24C0
	  bl        -0x1AAC58
	  lwz       r7, 0x80(r30)
	  addi      r3, r30, 0xC0
	  lwz       r6, 0x24C(r1)
	  addi      r4, r1, 0x228
	  lwz       r0, 0x250(r1)
	  addi      r5, r1, 0x224
	  stw       r6, 0xC0(r7)
	  addi      r6, r13, 0x24B4
	  stw       r0, 0xC4(r7)
	  lwz       r0, 0x254(r1)
	  stw       r0, 0xC8(r7)
	  lfs       f1, -0x4188(r2)
	  lfs       f0, 0x2F8(r1)
	  stfs      f1, 0x220(r1)
	  stfs      f0, 0x224(r1)
	  lfs       f0, 0x2F4(r1)
	  stfs      f0, 0x228(r1)
	  bl        -0x184730
	  addi      r3, r30, 0xCC
	  addi      r4, r1, 0x228
	  addi      r5, r1, 0x224
	  addi      r6, r13, 0x24B8
	  bl        -0x184744
	  lfs       f1, 0x224(r1)
	  addi      r5, r1, 0x22C
	  lfs       f0, 0x2514(r13)
	  addi      r3, r30, 0xE4
	  addi      r4, r1, 0x228
	  fadds     f0, f1, f0
	  addi      r6, r13, 0x24BC
	  stfs      f0, 0x22C(r1)
	  bl        -0x184768
	  lfs       f1, 0xC0(r30)
	  lfs       f0, 0xC4(r30)
	  lwz       r3, 0xBC(r30)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x3E0(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x3D8(r1)
	  mtlr      r12
	  lwz       r4, 0x3E4(r1)
	  lwz       r5, 0x3DC(r1)
	  blrl
	  addi      r4, r1, 0x220
	  addi      r5, r4, 0
	  addi      r3, r1, 0x230
	  addi      r6, r13, 0x24C0
	  bl        -0x1AAD20
	  lwz       r4, 0xBC(r30)
	  li        r5, 0
	  lwz       r3, 0x230(r1)
	  lwz       r0, 0x234(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x238(r1)
	  stw       r0, 0xC8(r4)
	  lwz       r3, 0x38(r31)
	  lwz       r23, 0x34(r31)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r23)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r21, 0x18(r3)
	  lha       r22, 0x1A(r3)
	  bne-      .loc_0x10B8
	  lbz       r3, 0x34(r23)
	  cmplwi    r3, 0
	  bne-      .loc_0x1028
	  li        r5, 0x1

	.loc_0x1028:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x10B8
	  cmplwi    r3, 0
	  bne-      .loc_0x104C
	  lbz       r0, 0x35(r23)
	  cmplwi    r0, 0
	  bne-      .loc_0x104C
	  li        r3, 0x123
	  bl        -0x13CB40

	.loc_0x104C:
	  li        r0, 0x1
	  stw       r0, 0x4(r23)
	  lwz       r0, 0x4(r23)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1078
	  bge-      .loc_0x1078
	  cmpwi     r0, 0
	  bge-      .loc_0x1070
	  b         .loc_0x1078

	.loc_0x1070:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r23)

	.loc_0x1078:
	  xoris     r0, r21, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x3DC(r1)
	  xoris     r0, r22, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0x3D8(r1)
	  stw       r0, 0x3E4(r1)
	  lfd       f0, 0x3D8(r1)
	  stw       r3, 0x3E0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x3E0(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r23)
	  stfs      f0, 0x10(r23)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r23)

	.loc_0x10B8:
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x1598
	  cmpwi     r0, 0x3
	  beq-      .loc_0x133C
	  bge-      .loc_0x10E0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x10EC
	  bge-      .loc_0x1214
	  b         .loc_0x1598

	.loc_0x10E0:
	  cmpwi     r0, 0x5
	  bge-      .loc_0x1598
	  b         .loc_0x1464

	.loc_0x10EC:
	  lwz       r3, 0x38(r31)
	  li        r4, 0x1
	  li        r0, 0x5
	  stw       r4, 0x0(r3)
	  mtctr     r0
	  addi      r8, r3, 0

	.loc_0x1104:
	  lwz       r0, 0x4(r3)
	  addi      r7, r8, 0x8
	  cmplw     r0, r7
	  beq-      .loc_0x115C
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x11A0
	  lwz       r4, 0x14(r7)
	  li        r6, 0x1
	  li        r5, 0
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  b         .loc_0x11A0

	.loc_0x115C:
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x11A0
	  lwz       r4, 0x14(r7)
	  li        r6, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x11A0:
	  addi      r8, r8, 0x3C
	  bdnz+     .loc_0x1104
	  addi      r4, r13, 0x2478
	  lfs       f0, -0x4188(r2)
	  lbz       r5, 0x1(r4)
	  li        r0, 0x1
	  li        r4, 0
	  mulli     r5, r5, 0x3C
	  addi      r5, r5, 0x8
	  add       r5, r3, r5
	  stfs      f0, 0x8(r5)
	  stw       r0, 0x4(r5)
	  lwz       r3, 0x14(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x1C(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1598

	.loc_0x1214:
	  lwz       r3, 0x38(r31)
	  li        r4, 0x1
	  li        r0, 0x5
	  stw       r4, 0x0(r3)
	  mtctr     r0
	  addi      r8, r3, 0

	.loc_0x122C:
	  lwz       r0, 0x4(r3)
	  addi      r7, r8, 0x8
	  cmplw     r0, r7
	  beq-      .loc_0x1284
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C8
	  lwz       r4, 0x14(r7)
	  li        r6, 0x1
	  li        r5, 0
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  b         .loc_0x12C8

	.loc_0x1284:
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C8
	  lwz       r4, 0x14(r7)
	  li        r6, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x12C8:
	  addi      r8, r8, 0x3C
	  bdnz+     .loc_0x122C
	  addi      r4, r13, 0x2478
	  lfs       f0, -0x4188(r2)
	  lbz       r5, 0x2(r4)
	  li        r0, 0x1
	  li        r4, 0
	  mulli     r5, r5, 0x3C
	  addi      r5, r5, 0x8
	  add       r5, r3, r5
	  stfs      f0, 0x8(r5)
	  stw       r0, 0x4(r5)
	  lwz       r3, 0x14(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x1C(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1598

	.loc_0x133C:
	  lwz       r3, 0x38(r31)
	  li        r4, 0x1
	  li        r0, 0x5
	  stw       r4, 0x0(r3)
	  mtctr     r0
	  addi      r8, r3, 0

	.loc_0x1354:
	  lwz       r0, 0x4(r3)
	  addi      r7, r8, 0x8
	  cmplw     r0, r7
	  beq-      .loc_0x13AC
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x13F0
	  lwz       r4, 0x14(r7)
	  li        r6, 0x1
	  li        r5, 0
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  b         .loc_0x13F0

	.loc_0x13AC:
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x13F0
	  lwz       r4, 0x14(r7)
	  li        r6, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x13F0:
	  addi      r8, r8, 0x3C
	  bdnz+     .loc_0x1354
	  addi      r4, r13, 0x2478
	  lfs       f0, -0x4188(r2)
	  lbz       r5, 0x3(r4)
	  li        r0, 0x1
	  li        r4, 0
	  mulli     r5, r5, 0x3C
	  addi      r5, r5, 0x8
	  add       r5, r3, r5
	  stfs      f0, 0x8(r5)
	  stw       r0, 0x4(r5)
	  lwz       r3, 0x14(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x1C(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1598

	.loc_0x1464:
	  lwz       r3, 0x38(r31)
	  li        r4, 0x1
	  li        r0, 0x5
	  stw       r4, 0x0(r3)
	  mtctr     r0
	  addi      r8, r3, 0

	.loc_0x147C:
	  lwz       r0, 0x4(r3)
	  addi      r7, r8, 0x8
	  cmplw     r0, r7
	  beq-      .loc_0x14D4
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1518
	  lwz       r4, 0x14(r7)
	  li        r6, 0x1
	  li        r5, 0
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  b         .loc_0x1518

	.loc_0x14D4:
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1518
	  lwz       r4, 0x14(r7)
	  li        r6, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x20(r7)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x1518:
	  addi      r8, r8, 0x3C
	  bdnz+     .loc_0x147C
	  addi      r4, r13, 0x2478
	  lfs       f0, -0x4188(r2)
	  lbz       r0, 0x4(r4)
	  li        r5, 0x1
	  li        r4, 0
	  mulli     r6, r0, 0x3C
	  addi      r6, r6, 0x8
	  add       r6, r3, r6
	  stfs      f0, 0x8(r6)
	  stw       r5, 0x4(r6)
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x1C(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x364(r31)
	  stb       r5, 0x4(r3)
	  lfs       f0, -0x40C0(r2)
	  stfs      f0, 0x0(r3)

	.loc_0x1598:
	  lwz       r7, 0x54(r31)
	  li        r5, 0
	  li        r0, 0x5
	  stw       r5, 0x4(r7)
	  mtctr     r0
	  addi      r6, r7, 0

	.loc_0x15B0:
	  lwz       r3, 0xC(r6)
	  cmplwi    r3, 0
	  beq-      .loc_0x15FC
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r8, 0xC(r6)
	  lha       r3, 0x18(r8)
	  lha       r0, 0x1C(r8)
	  lha       r4, 0x1A(r8)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r8)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r8)
	  extsh     r0, r0
	  sth       r0, 0xBA(r8)

	.loc_0x15FC:
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0x15B0
	  li        r0, 0
	  stw       r0, 0x8(r7)
	  lwz       r0, 0x4(r7)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1650
	  bge-      .loc_0x1628
	  cmpwi     r0, 0
	  bge-      .loc_0x1634
	  b         .loc_0x1650

	.loc_0x1628:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x1650
	  b         .loc_0x1648

	.loc_0x1634:
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x1
	  stfs      f0, 0x0(r7)
	  stw       r0, 0x4(r7)
	  b         .loc_0x1650

	.loc_0x1648:
	  li        r0, 0x1
	  stb       r0, 0x20(r7)

	.loc_0x1650:
	  lwz       r0, 0x2F6C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x1740
	  lwz       r5, 0x20(r31)
	  lis       r3, 0x705F
	  addi      r4, r3, 0x6263
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0
	  bl        -0x161F2C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x16A8
	  lbz       r0, 0xC(r21)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r21)

	.loc_0x16A8:
	  lwz       r5, 0x20(r31)
	  lis       r3, 0x705F
	  addi      r4, r3, 0x7263
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1
	  bl        -0x161F78
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x16F4
	  lbz       r0, 0xC(r21)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r21)

	.loc_0x16F4:
	  lwz       r5, 0x20(r31)
	  lis       r3, 0x705F
	  addi      r4, r3, 0x7963
	  lwz       r12, 0x4(r5)
	  addi      r3, r5, 0x4
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r21, r3
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x2
	  bl        -0x161FC4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1740
	  lbz       r0, 0xC(r21)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r21)

	.loc_0x1740:
	  li        r24, 0
	  lwz       r25, 0x5C(r31)
	  lwz       r21, 0x249C(r13)
	  addi      r27, r24, 0
	  addi      r23, r24, 0
	  addi      r22, r24, 0
	  b         .loc_0x179C

	.loc_0x175C:
	  lwz       r0, 0x0(r25)
	  li        r4, 0x280
	  li        r5, 0x1E0
	  add       r26, r0, r27
	  lwz       r3, 0x4(r26)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stw       r23, 0x0(r26)
	  addi      r27, r27, 0x28
	  addi      r24, r24, 0x1
	  lwz       r3, 0x4(r26)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r22,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x179C:
	  cmpw      r24, r21
	  blt+      .loc_0x175C
	  li        r0, -0x1
	  stw       r0, 0x4(r25)
	  lwz       r3, 0x38(r31)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C0
	  lwz       r0, 0x10(r3)

	.loc_0x17C0:
	  cmpwi     r0, -0x1
	  lwz       r22, 0x60(r31)
	  bne-      .loc_0x17D8
	  li        r5, 0
	  li        r21, 0
	  b         .loc_0x18F0

	.loc_0x17D8:
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1880
	  cmpwi     r0, 0x2
	  beq-      .loc_0x1838
	  bge-      .loc_0x1800
	  cmpwi     r0, 0
	  beq-      .loc_0x1810
	  bge-      .loc_0x1824
	  b         .loc_0x1874

	.loc_0x1800:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x1860
	  bge-      .loc_0x1874
	  b         .loc_0x184C

	.loc_0x1810:
	  li        r21, 0x2
	  li        r4, 0
	  bl        -0x162A70
	  mr        r5, r3
	  b         .loc_0x18F0

	.loc_0x1824:
	  li        r21, 0x8
	  li        r4, 0x1
	  bl        -0x162A84
	  mr        r5, r3
	  b         .loc_0x18F0

	.loc_0x1838:
	  li        r21, 0x9
	  li        r4, 0x2
	  bl        -0x162A98
	  mr        r5, r3
	  b         .loc_0x18F0

	.loc_0x184C:
	  li        r21, 0xA
	  li        r4, 0x3
	  bl        -0x162AAC
	  mr        r5, r3
	  b         .loc_0x18F0

	.loc_0x1860:
	  li        r21, 0x1
	  li        r4, 0x4
	  bl        -0x162AC0
	  mr        r5, r3
	  b         .loc_0x18F0

	.loc_0x1874:
	  li        r21, 0
	  addi      r5, r21, 0
	  b         .loc_0x18F0

	.loc_0x1880:
	  cmpwi     r0, 0x2
	  beq-      .loc_0x18C4
	  bge-      .loc_0x189C
	  cmpwi     r0, 0
	  beq-      .loc_0x18AC
	  bge-      .loc_0x18B8
	  b         .loc_0x18E8

	.loc_0x189C:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x18DC
	  bge-      .loc_0x18E8
	  b         .loc_0x18D0

	.loc_0x18AC:
	  li        r21, 0x2
	  li        r5, 0x1
	  b         .loc_0x18F0

	.loc_0x18B8:
	  li        r21, 0x8
	  li        r5, 0x2
	  b         .loc_0x18F0

	.loc_0x18C4:
	  li        r21, 0x9
	  li        r5, 0x3
	  b         .loc_0x18F0

	.loc_0x18D0:
	  li        r21, 0xA
	  li        r5, 0x4
	  b         .loc_0x18F0

	.loc_0x18DC:
	  li        r21, 0x1
	  li        r5, 0
	  b         .loc_0x18F0

	.loc_0x18E8:
	  li        r21, 0
	  addi      r5, r21, 0

	.loc_0x18F0:
	  addi      r3, r22, 0
	  addi      r4, r21, 0
	  bl        .loc_0x1B78
	  lwz       r3, 0x58(r31)
	  li        r24, 0
	  lfs       f0, -0x4188(r2)
	  lis       r21, 0x4330
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4180(r2)
	  stfs      f0, 0x8(r3)
	  stb       r24, 0xAC(r3)
	  lwz       r22, 0x58(r31)
	  lfd       f29, -0x4168(r2)
	  mr        r23, r22

	.loc_0x1928:
	  lwz       r3, 0x30(r23)
	  addi      r25, r23, 0xC
	  lha       r4, 0x18(r3)
	  lha       r0, 0x1C(r3)
	  lwz       r12, 0x0(r3)
	  sub       r5, r0, r4
	  lha       r4, 0x1A(r3)
	  lha       r0, 0x1E(r3)
	  srawi     r5, r5, 0x1
	  lwz       r12, 0x14(r12)
	  subfic    r26, r5, 0x140
	  sub       r0, r0, r4
	  srawi     r0, r0, 0x1
	  mtlr      r12
	  subfic    r27, r0, 0xF0
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  blrl
	  xoris     r3, r26, 0x8000
	  stw       r3, 0x3DC(r1)
	  xoris     r0, r27, 0x8000
	  addi      r24, r24, 0x1
	  stw       r21, 0x3D8(r1)
	  cmpwi     r24, 0x4
	  addi      r23, r23, 0x28
	  stw       r0, 0x3E4(r1)
	  lfd       f0, 0x3D8(r1)
	  stw       r21, 0x3E0(r1)
	  fsubs     f2, f0, f29
	  lfd       f0, 0x3E0(r1)
	  stw       r3, 0x3EC(r1)
	  fsubs     f1, f0, f29
	  stfs      f2, 0xC(r25)
	  stw       r21, 0x3E8(r1)
	  stw       r0, 0x3F4(r1)
	  lfd       f0, 0x3E8(r1)
	  stfs      f1, 0x10(r25)
	  fsubs     f1, f0, f29
	  stw       r21, 0x3F0(r1)
	  lfs       f2, 0x25EC(r13)
	  lfd       f0, 0x3F0(r1)
	  stfs      f2, 0x14(r25)
	  fsubs     f0, f0, f29
	  stfs      f1, 0x18(r25)
	  stfs      f0, 0x1C(r25)
	  lfs       f0, 0x25F0(r13)
	  stfs      f0, 0x20(r25)
	  blt+      .loc_0x1928
	  li        r30, 0
	  stw       r30, 0x0(r22)
	  addi      r26, r1, 0x168
	  addi      r25, r1, 0x164
	  lwz       r31, 0x58(r31)
	  addi      r24, r1, 0x170
	  lfs       f29, -0x4188(r2)
	  addi      r23, r1, 0x16C
	  addi      r22, r31, 0
	  stfs      f29, 0x4(r31)
	  lis       r21, 0x4330
	  lfs       f0, -0x4184(r2)
	  stfs      f0, 0x8(r31)
	  lfs       f30, -0x4154(r2)
	  lfd       f31, -0x4168(r2)

	.loc_0x1A24:
	  lfs       f0, 0x10(r22)
	  addi      r29, r22, 0xC
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1A40
	  fadds     f0, f30, f0
	  b         .loc_0x1A44

	.loc_0x1A40:
	  fsubs     f0, f0, f30

	.loc_0x1A44:
	  lfs       f1, 0x0(r29)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f29
	  stfd      f0, 0x3D8(r1)
	  lwz       r27, 0x3DC(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1A68
	  fadds     f0, f30, f1
	  b         .loc_0x1A6C

	.loc_0x1A68:
	  fsubs     f0, f1, f30

	.loc_0x1A6C:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r29)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x3D8(r1)
	  lwz       r28, 0x3DC(r1)
	  bl        -0x2A3C8
	  lwz       r4, 0x24(r29)
	  srawi     r0, r3, 0x1
	  sub       r28, r28, r0
	  addi      r3, r4, 0x18
	  bl        -0x2A3CC
	  lwz       r5, 0x24(r29)
	  srawi     r3, r3, 0x1
	  addi      r4, r25, 0
	  lha       r0, 0x1A(r5)
	  addi      r5, r26, 0
	  sub       r27, r27, r3
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3E4(r1)
	  addi      r3, r29, 0xC
	  addi      r6, r13, 0x25F4
	  stw       r21, 0x3E0(r1)
	  lfd       f0, 0x3E0(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x168(r1)
	  lwz       r7, 0x24(r29)
	  lha       r0, 0x18(r7)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3EC(r1)
	  stw       r21, 0x3E8(r1)
	  lfd       f0, 0x3E8(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x164(r1)
	  bl        -0x1852D0
	  xoris     r3, r27, 0x8000
	  xoris     r0, r28, 0x8000
	  stw       r3, 0x3F4(r1)
	  mr        r4, r23
	  stw       r0, 0x3FC(r1)
	  addi      r5, r24, 0
	  addi      r3, r29, 0x18
	  stw       r21, 0x3F0(r1)
	  addi      r6, r13, 0x25F8
	  stw       r21, 0x3F8(r1)
	  lfd       f1, 0x3F0(r1)
	  lfd       f0, 0x3F8(r1)
	  fsubs     f1, f1, f31
	  fsubs     f0, f0, f31
	  stfs      f1, 0x170(r1)
	  stfs      f0, 0x16C(r1)
	  bl        -0x185314
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r22, r22, 0x28
	  blt+      .loc_0x1A24
	  li        r0, 0x2
	  stw       r0, 0x0(r31)
	  li        r0, 0x1
	  stb       r0, 0xAC(r31)
	  lwz       r0, 0x474(r1)
	  lfd       f31, 0x468(r1)
	  lfd       f30, 0x460(r1)
	  lfd       f29, 0x458(r1)
	  lmw       r21, 0x42C(r1)
	  addi      r1, r1, 0x470
	  mtlr      r0
	  blr

	.loc_0x1B78:
	*/
}

/*
 * --INFO--
 * Address:	801E29E4
 * Size:	0000C8
 */
void zen::WorldMapPartsInfoMgr::setDisplayParts(int, int)
{
	/*
	.loc_0x0:
	  li        r7, 0
	  li        r6, 0
	  b         .loc_0xB8

	.loc_0xC:
	  cmpw      r7, r4
	  bge-      .loc_0x84
	  cmpw      r7, r5
	  bge-      .loc_0x50
	  lwz       r8, 0x8(r3)
	  li        r10, 0x1
	  li        r9, 0
	  lwzx      r8, r8, r6
	  lbz       r0, 0xC(r8)
	  rlwimi    r0,r10,7,24,24
	  stb       r0, 0xC(r8)
	  lwz       r8, 0x4(r3)
	  lwzx      r8, r8, r6
	  lbz       r0, 0xC(r8)
	  rlwimi    r0,r9,7,24,24
	  stb       r0, 0xC(r8)
	  b         .loc_0xB0

	.loc_0x50:
	  lwz       r8, 0x8(r3)
	  li        r10, 0
	  li        r9, 0x1
	  lwzx      r8, r8, r6
	  lbz       r0, 0xC(r8)
	  rlwimi    r0,r10,7,24,24
	  stb       r0, 0xC(r8)
	  lwz       r8, 0x4(r3)
	  lwzx      r8, r8, r6
	  lbz       r0, 0xC(r8)
	  rlwimi    r0,r9,7,24,24
	  stb       r0, 0xC(r8)
	  b         .loc_0xB0

	.loc_0x84:
	  lwz       r8, 0x8(r3)
	  li        r9, 0
	  lwzx      r8, r8, r6
	  lbz       r0, 0xC(r8)
	  rlwimi    r0,r9,7,24,24
	  stb       r0, 0xC(r8)
	  lwz       r8, 0x4(r3)
	  lwzx      r8, r8, r6
	  lbz       r0, 0xC(r8)
	  rlwimi    r0,r9,7,24,24
	  stb       r0, 0xC(r8)

	.loc_0xB0:
	  addi      r6, r6, 0x4
	  addi      r7, r7, 0x1

	.loc_0xB8:
	  lwz       r0, 0x0(r3)
	  cmpw      r7, r0
	  blt+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E2AAC
 * Size:	000318
 */
void zen::WorldMapCursorMgr::updateOnyonPos(Vector3f*, Vector3f*, Vector3f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x150(r1)
	  stfd      f31, 0x148(r1)
	  addi      r0, r1, 0x78
	  stfd      f30, 0x140(r1)
	  stfd      f29, 0x138(r1)
	  stfd      f28, 0x130(r1)
	  stfd      f27, 0x128(r1)
	  stfd      f26, 0x120(r1)
	  stfd      f25, 0x118(r1)
	  stw       r31, 0x114(r1)
	  mr        r31, r6
	  addi      r6, r1, 0x74
	  stw       r30, 0x110(r1)
	  mr        r30, r5
	  mr        r5, r6
	  stw       r29, 0x10C(r1)
	  mr        r29, r4
	  mr        r6, r0
	  stw       r28, 0x108(r1)
	  mr        r28, r3
	  lwz       r7, 0x2DEC(r13)
	  lwz       r3, 0x8(r3)
	  lfs       f2, -0x4130(r2)
	  lfs       f1, 0x28C(r7)
	  lfs       f25, 0xC0(r3)
	  addi      r3, r1, 0x70
	  fmuls     f5, f2, f1
	  lfs       f0, 0x10C(r28)
	  mr        r4, r3
	  lfs       f3, 0x20(r28)
	  addi      r3, r1, 0xC8
	  fmuls     f0, f0, f5
	  lfs       f4, 0x1C(r28)
	  lfs       f2, 0x18(r28)
	  lfs       f1, 0x25E8(r13)
	  stfs      f0, 0x78(r1)
	  fadds     f29, f3, f1
	  lfs       f3, 0x25E4(r13)
	  lfs       f0, 0x108(r28)
	  lfs       f1, 0x25E0(r13)
	  fadds     f30, f4, f3
	  fmuls     f0, f0, f5
	  fadds     f31, f2, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x104(r28)
	  fmuls     f0, f0, f5
	  stfs      f0, 0x70(r1)
	  bl        -0x1ABA54
	  lfs       f1, 0xF8(r28)
	  lfs       f0, 0xC8(r1)
	  lfs       f2, 0xCC(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0xD0(r1)
	  stfs      f0, 0xF8(r28)
	  lfs       f0, 0xFC(r28)
	  fadds     f0, f0, f2
	  stfs      f0, 0xFC(r28)
	  lfs       f0, 0x100(r28)
	  fadds     f0, f0, f1
	  stfs      f0, 0x100(r28)
	  lfs       f1, 0xFC(r28)
	  lfs       f0, 0xF8(r28)
	  fsubs     f1, f1, f30
	  lfs       f4, 0x100(r28)
	  fsubs     f2, f0, f31
	  lfs       f3, -0x4188(r2)
	  fsubs     f0, f4, f29
	  fmuls     f5, f2, f2
	  fmuls     f4, f1, f1
	  fmuls     f6, f0, f0
	  fadds     f4, f5, f4
	  fadds     f7, f6, f4
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0x188
	  fsqrte    f4, f7
	  lfd       f6, -0x4128(r2)
	  lfd       f5, -0x4120(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f7, f3
	  frsp      f3, f3
	  stfs      f3, 0x7C(r1)
	  lfs       f7, 0x7C(r1)

	.loc_0x188:
	  lfs       f3, -0x4118(r2)
	  fcmpo     cr0, f7, f3
	  bge-      .loc_0x1A4
	  lfs       f25, 0x2520(r13)
	  lfs       f26, 0x2524(r13)
	  lfs       f0, 0x2528(r13)
	  b         .loc_0x1BC

	.loc_0x1A4:
	  lfs       f3, 0x25DC(r13)
	  fmuls     f3, f3, f25
	  fdivs     f3, f3, f7
	  fmuls     f25, f2, f3
	  fmuls     f26, f1, f3
	  fmuls     f0, f0, f3

	.loc_0x1BC:
	  fadds     f29, f29, f0
	  lfs       f0, 0x100(r28)
	  fadds     f28, f30, f26
	  addi      r6, r1, 0x6C
	  fadds     f27, f31, f25
	  fsubs     f0, f29, f0
	  addi      r5, r1, 0x68
	  addi      r4, r1, 0x64
	  addi      r3, r1, 0x98
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0xFC(r28)
	  fsubs     f0, f28, f0
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0xF8(r28)
	  fsubs     f0, f27, f0
	  stfs      f0, 0x64(r1)
	  bl        -0x1ABB8C
	  lfs       f1, 0x104(r28)
	  lfs       f0, 0x98(r1)
	  lfs       f2, 0x9C(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0xA0(r1)
	  stfs      f0, 0x104(r28)
	  lfs       f0, 0x108(r28)
	  fadds     f0, f0, f2
	  stfs      f0, 0x108(r28)
	  lfs       f0, 0x10C(r28)
	  fadds     f0, f0, f1
	  stfs      f0, 0x10C(r28)
	  stfs      f27, 0xF8(r28)
	  stfs      f28, 0xFC(r28)
	  stfs      f29, 0x100(r28)
	  lfs       f0, 0xF8(r28)
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0xFC(r28)
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x252C(r13)
	  stfs      f0, 0x8(r29)
	  lfs       f1, -0x40FC(r2)
	  bl        0x38E50
	  fmr       f27, f1
	  lfs       f1, -0x40FC(r2)
	  bl        0x38FD8
	  fmuls     f3, f25, f27
	  fmuls     f2, f25, f1
	  fmuls     f0, f26, f27
	  fadds     f4, f31, f3
	  fmuls     f3, f26, f1
	  fadds     f1, f30, f2
	  fsubs     f2, f4, f3
	  fadds     f0, f1, f0
	  stfs      f2, 0x0(r30)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x2530(r13)
	  stfs      f0, 0x8(r30)
	  lfs       f1, -0x40F8(r2)
	  bl        0x38E0C
	  fmr       f27, f1
	  lfs       f1, -0x40F8(r2)
	  bl        0x38F94
	  fmuls     f3, f25, f27
	  fmuls     f2, f25, f1
	  fmuls     f0, f26, f27
	  fadds     f4, f31, f3
	  fmuls     f3, f26, f1
	  fadds     f1, f30, f2
	  fsubs     f2, f4, f3
	  fadds     f0, f1, f0
	  stfs      f2, 0x0(r31)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x2534(r13)
	  stfs      f0, 0x8(r31)
	  lwz       r0, 0x154(r1)
	  lfd       f31, 0x148(r1)
	  lfd       f30, 0x140(r1)
	  lfd       f29, 0x138(r1)
	  lfd       f28, 0x130(r1)
	  lfd       f27, 0x128(r1)
	  lfd       f26, 0x120(r1)
	  lfd       f25, 0x118(r1)
	  lwz       r31, 0x114(r1)
	  lwz       r30, 0x110(r1)
	  lwz       r29, 0x10C(r1)
	  lwz       r28, 0x108(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E2DC4
 * Size:	000048
 */
void @unnamed @ ::WorldMapCoursePoint::select()
{
	/*
	.loc_0x0:
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beqlr-
	  lwz       r4, 0x14(r3)
	  li        r6, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x18(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r3, 0x20(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E2E0C
 * Size:	00047C
 */
void zen::DrawWorldMap::modeStart(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  li        r31, 0
	  stw       r30, 0xD0(r1)
	  mr        r30, r3
	  stw       r29, 0xCC(r1)
	  stw       r28, 0xC8(r1)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f1, f1, f0
	  stfs      f1, 0xC(r3)
	  lfs       f0, -0x4184(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x50
	  stfs      f0, 0xC(r30)

	.loc_0x50:
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x4184(r2)
	  lwz       r3, 0x28(r30)
	  fdivs     f30, f1, f0
	  lfs       f0, -0x4148(r2)
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  fmuls     f31, f0, f30
	  fmr       f1, f31
	  bl        0x38E68
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD0
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xD8

	.loc_0xD0:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0xD8:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xC0(r1)
	  mtlr      r12
	  lwz       r4, 0xC4(r1)
	  blrl
	  lwz       r3, 0x2C(r30)
	  fmr       f1, f31
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  bl        0x38DD0
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xBC(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xB8(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x168
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x170

	.loc_0x168:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x170:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  lwz       r3, 0x18(r30)
	  fmr       f1, f31
	  addi      r29, r3, 0x4
	  bl        0x38D3C
	  lha       r4, 0x1A(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1E(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1FC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x204

	.loc_0x1FC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x204:
	  fctiwz    f0, f0
	  fmr       f1, f31
	  stfd      f0, 0xB8(r1)
	  lwz       r28, 0xBC(r1)
	  bl        0x38CC8
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x270
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x278

	.loc_0x270:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x278:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  lwz       r3, 0x1C(r30)
	  fmr       f1, f31
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  bl        0x38C30
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x40BC(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x308
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x310

	.loc_0x308:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x310:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  fmr       f1, f31
	  bl        0x38BA4
	  lwz       r3, 0x20(r30)
	  lfs       f3, -0x4184(r2)
	  addi      r6, r3, 0x4
	  lha       r5, 0x1E(r3)
	  lha       r4, 0x22(r3)
	  fsubs     f0, f3, f1
	  lfs       f2, -0x417C(r2)
	  fmr       f1, f31
	  sub       r4, r4, r5
	  fmuls     f0, f2, f0
	  lha       r3, 0x1C(r3)
	  srawi     r4, r4, 0x1
	  lha       r0, 0x1C(r6)
	  fadds     f0, f3, f0
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r6)
	  extsh     r0, r4
	  sth       r0, 0xBA(r6)
	  stfs      f0, 0xC0(r6)
	  stfs      f0, 0xC4(r6)
	  stfs      f0, 0xC8(r6)
	  lwz       r3, 0x24(r30)
	  lha       r28, 0x1E(r3)
	  addi      r29, r3, 0x4
	  bl        0x38B38
	  lha       r4, 0x18(r29)
	  lis       r0, 0x4330
	  lha       r3, 0x1C(r29)
	  lfs       f0, -0x4184(r2)
	  sub       r3, r3, r4
	  lfd       f3, -0x4168(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f4, -0x4138(r2)
	  stw       r3, 0xC4(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4188(r2)
	  stw       r0, 0xC0(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x400
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x408

	.loc_0x400:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x408:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0x14(r12)
	  mr        r5, r28
	  stfd      f0, 0xB8(r1)
	  mtlr      r12
	  lwz       r4, 0xBC(r1)
	  blrl
	  lwz       r3, 0x70(r30)
	  li        r4, 0
	  bl        -0x5C88
	  lfs       f0, -0x4184(r2)
	  fcmpu     cr0, f0, f30
	  bne-      .loc_0x448
	  li        r31, 0x1

	.loc_0x448:
	  mr        r3, r30
	  bl        0x40C4
	  mr        r3, r31
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  lwz       r28, 0xC8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E3288
 * Size:	002744
 */
void zen::DrawWorldMap::modeAppear(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C0(r1)
	  stmw      r27, 0x1AC(r1)
	  li        r29, 0
	  mr        r30, r3
	  li        r31, 0
	  lwz       r28, 0x38(r3)
	  stw       r29, 0x134(r28)
	  lwz       r0, 0x0(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x50
	  bge-      .loc_0x70
	  cmpwi     r0, 0
	  bge-      .loc_0x40
	  b         .loc_0x70

	.loc_0x40:
	  addi      r3, r28, 0
	  li        r5, 0
	  bl        0x2910
	  b         .loc_0x70

	.loc_0x50:
	  mr        r3, r28
	  bl        .loc_0x2744
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x70
	  stw       r29, 0x0(r28)
	  li        r0, 0x40
	  stw       r0, 0x134(r28)

	.loc_0x70:
	  lwz       r3, 0x38(r30)
	  lwz       r0, 0x134(r3)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0x2628
	  lwz       r4, 0x4(r3)
	  li        r3, -0x1
	  cmplwi    r4, 0
	  beq-      .loc_0x94
	  lwz       r3, 0x10(r4)

	.loc_0x94:
	  lwz       r0, 0x0(r30)
	  cmpw      r0, r3
	  beq-      .loc_0xA8
	  mr        r3, r30
	  bl        0x40CC

	.loc_0xA8:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x1310
	  bge-      .loc_0xC8
	  cmpwi     r0, 0x1
	  beq-      .loc_0xD4
	  bge-      .loc_0x9E8
	  b         .loc_0x255C

	.loc_0xC8:
	  cmpwi     r0, 0x5
	  bge-      .loc_0x255C
	  b         .loc_0x1C38

	.loc_0xD4:
	  li        r0, 0x1
	  cmpwi     r0, 0x2
	  beq-      .loc_0x3F8
	  bge-      .loc_0xF4
	  cmpwi     r0, 0
	  beq-      .loc_0x104
	  bge-      .loc_0x27C
	  b         .loc_0x86C

	.loc_0xF4:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x6F0
	  bge-      .loc_0x86C
	  b         .loc_0x574

	.loc_0x104:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x150:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x194
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x194:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x1D8
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x1D8:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x21C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x21C:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x25C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x25C:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x738
	  b         .loc_0x255C

	.loc_0x27C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C8
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x2C8:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x30C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x30C:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x350
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x350:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x394
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x394:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x3D4
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x3D4:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x8B4
	  b         .loc_0x255C

	.loc_0x3F8:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x444
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x444:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x488
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x488:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x4CC
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x4CC:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x510
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x510:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x550
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x550:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xA30
	  b         .loc_0x255C

	.loc_0x574:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C0
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x5C0:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x604
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x604:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x648
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x648:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x68C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x68C:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x6CC
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x6CC:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xBAC
	  b         .loc_0x255C

	.loc_0x6F0:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r3, 0x14(r8)
	  cmplwi    r3, 0
	  beq-      .loc_0x73C
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x73C:
	  addi      r7, r8, 0x3C
	  lbz       r3, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r3, 0
	  beq-      .loc_0x780
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x780:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x7C4
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x7C4:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r3, 0
	  beq-      .loc_0x808
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x808:
	  lbz       r3, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r3, 0
	  beq-      .loc_0x848
	  lwz       r4, 0x14(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r0,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x18(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)
	  lwz       r4, 0x20(r6)
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r5,7,24,24
	  stb       r3, 0xC(r4)

	.loc_0x848:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xD28
	  b         .loc_0x255C

	.loc_0x86C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x8BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x8BC:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x900
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x900:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x944
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x944:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x988
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x988:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x9C8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x9C8:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0xEA4
	  b         .loc_0x255C

	.loc_0x9E8:
	  li        r0, 0x2
	  cmpwi     r0, 0x2
	  b         .loc_0xD14
	  bge-      .loc_0xA08
	  cmpwi     r0, 0
	  beq-      .loc_0xA18
	  bge-      .loc_0xB94
	  b         .loc_0x1194

	.loc_0xA08:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x1014
	  bge-      .loc_0x1194
	  b         .loc_0xE94

	.loc_0xA18:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xA68
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xA68:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xAAC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xAAC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xAF0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xAF0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xB34
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xB34:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xB74
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xB74:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1050
	  b         .loc_0x255C

	.loc_0xB94:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xBE4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xBE4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xC28
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC28:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xC6C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC6C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xCB0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xCB0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xCF0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xCF0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x11D0
	  b         .loc_0x255C

	.loc_0xD14:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xD64
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xD64:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xDA8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xDA8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xDEC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xDEC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xE30
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xE30:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xE70
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xE70:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1350
	  b         .loc_0x255C

	.loc_0xE94:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0xEE4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xEE4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0xF28
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xF28:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xF6C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xF6C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0xFB0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xFB0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0xFF0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xFF0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x14D0
	  b         .loc_0x255C

	.loc_0x1014:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1064
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1064:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x10A8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x10A8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x10EC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x10EC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1130
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1130:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1170
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1170:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1650
	  b         .loc_0x255C

	.loc_0x1194:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x11E4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x11E4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1228
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1228:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x126C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x126C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x12B0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x12B0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x12F0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x12F0:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x17CC
	  b         .loc_0x255C

	.loc_0x1310:
	  li        r0, 0x3
	  cmpwi     r0, 0x2
	  beq-      .loc_0x163C
	  bge-      .loc_0x1330
	  cmpwi     r0, 0
	  beq-      .loc_0x1340
	  bge-      .loc_0x14BC
	  b         .loc_0x1ABC

	.loc_0x1330:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x193C
	  bge-      .loc_0x1ABC
	  b         .loc_0x17BC

	.loc_0x1340:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1390
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1390:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x13D4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x13D4:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1418
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1418:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x145C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x145C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x149C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x149C:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1978
	  b         .loc_0x255C

	.loc_0x14BC:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x150C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x150C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1550
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1550:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1594
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1594:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x15D8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x15D8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1618
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1618:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1AF8
	  b         .loc_0x255C

	.loc_0x163C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x168C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x168C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x16D0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x16D0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1714
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1714:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1758
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1758:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1798
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1798:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1C78
	  b         .loc_0x255C

	.loc_0x17BC:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x180C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x180C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1850
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1850:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1894
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1894:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x18D8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x18D8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1918
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1918:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1DF8
	  b         .loc_0x255C

	.loc_0x193C:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x198C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x198C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x19D0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x19D0:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1A14
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1A14:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1A58
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1A58:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1A98
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1A98:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x1F78
	  b         .loc_0x255C

	.loc_0x1ABC:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B0C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1B0C:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1B50
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1B50:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1B94
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1B94:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1BD8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1BD8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1C18
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1C18:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x20F4
	  b         .loc_0x255C

	.loc_0x1C38:
	  li        r0, 0x4
	  cmpwi     r0, 0x2
	  beq-      .loc_0x1F64
	  bge-      .loc_0x1C58
	  cmpwi     r0, 0
	  beq-      .loc_0x1C68
	  bge-      .loc_0x1DE4
	  b         .loc_0x23E4

	.loc_0x1C58:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x2264
	  bge-      .loc_0x23E4
	  b         .loc_0x20E4

	.loc_0x1C68:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1CB8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1CB8:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1CFC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1CFC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1D40
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1D40:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1D84
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1D84:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1DC4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1DC4:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x22A0
	  b         .loc_0x255C

	.loc_0x1DE4:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E34
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1E34:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1E78
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1E78:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1EBC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1EBC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x1F00
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1F00:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x1F40
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1F40:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x1(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x2420
	  b         .loc_0x255C

	.loc_0x1F64:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x1FB4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1FB4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x1FF8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x1FF8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x203C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x203C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2080
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2080:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x20C0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x20C0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x2(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x25A0
	  b         .loc_0x255C

	.loc_0x20E4:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x2134
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2134:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x2178
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2178:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x21BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x21BC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2200
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2200:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x2240
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2240:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x3(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x2720
	  b         .loc_0x255C

	.loc_0x2264:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x22B4
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x22B4:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x22F8
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x22F8:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x233C
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x233C:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2380
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2380:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x23C0
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x23C0:
	  addi      r3, r13, 0x2478
	  lbz       r0, 0x4(r3)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x28A0
	  b         .loc_0x255C

	.loc_0x23E4:
	  lwz       r8, 0x38(r30)
	  li        r5, 0
	  li        r4, 0x1
	  stw       r5, 0x0(r8)
	  addi      r6, r8, 0x8
	  lbz       r0, 0x14(r8)
	  cmplwi    r0, 0
	  beq-      .loc_0x2434
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2434:
	  addi      r7, r8, 0x3C
	  lbz       r0, 0x50(r8)
	  addi      r6, r7, 0x8
	  cmplwi    r0, 0
	  beq-      .loc_0x2478
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2478:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x24BC
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x24BC:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  addi      r7, r7, 0x3C
	  cmplwi    r0, 0
	  beq-      .loc_0x2500
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2500:
	  lbz       r0, 0x50(r7)
	  addi      r6, r7, 0x44
	  cmplwi    r0, 0
	  beq-      .loc_0x2540
	  lwz       r3, 0x14(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2540:
	  lbz       r0, 0x2478(r13)
	  mulli     r3, r0, 0x3C
	  addi      r0, r3, 0x8
	  add       r0, r8, r0
	  stw       r0, 0x4(r8)
	  lwz       r3, 0x4(r8)
	  bl        -0x2A1C

	.loc_0x255C:
	  lwz       r3, 0x38(r30)
	  li        r4, 0
	  lwz       r31, 0x34(r30)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r31)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r28, 0x18(r3)
	  lha       r29, 0x1A(r3)
	  bne-      .loc_0x2624
	  lbz       r3, 0x34(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x2594
	  li        r4, 0x1

	.loc_0x2594:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x2624
	  cmplwi    r3, 0
	  bne-      .loc_0x25B8
	  lbz       r0, 0x35(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x25B8
	  li        r3, 0x123
	  bl        -0x1404C8

	.loc_0x25B8:
	  li        r0, 0x1
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x25E4
	  bge-      .loc_0x25E4
	  cmpwi     r0, 0
	  bge-      .loc_0x25DC
	  b         .loc_0x25E4

	.loc_0x25DC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r31)

	.loc_0x25E4:
	  xoris     r0, r28, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1A4(r1)
	  xoris     r0, r29, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0x1A0(r1)
	  stw       r0, 0x19C(r1)
	  lfd       f0, 0x1A0(r1)
	  stw       r3, 0x198(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x198(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r31)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r31)

	.loc_0x2624:
	  li        r31, 0x1

	.loc_0x2628:
	  lwz       r27, 0x34(r30)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2658
	  bge-      .loc_0x26E8
	  cmpwi     r0, 0
	  bge-      .loc_0x264C
	  b         .loc_0x26E8
	  b         .loc_0x26E8

	.loc_0x264C:
	  mr        r3, r27
	  bl        -0x4F54
	  b         .loc_0x26E8

	.loc_0x2658:
	  mr        r3, r27
	  bl        -0x53F4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x26E8
	  lbz       r0, 0x35(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x2680
	  mr        r3, r27
	  bl        -0x54E0
	  b         .loc_0x26E8

	.loc_0x2680:
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x26BC
	  li        r0, 0x2
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x26E8
	  bge-      .loc_0x26E8
	  cmpwi     r0, 0
	  bge-      .loc_0x26B0
	  b         .loc_0x26E8

	.loc_0x26B0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)
	  b         .loc_0x26E8

	.loc_0x26BC:
	  li        r0, 0
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x26E8
	  bge-      .loc_0x26E8
	  cmpwi     r0, 0
	  bge-      .loc_0x26E0
	  b         .loc_0x26E8

	.loc_0x26E0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)

	.loc_0x26E8:
	  mr        r3, r27
	  bl        -0x58A4
	  li        r28, 0
	  mulli     r0, r28, 0x3C
	  add       r29, r27, r0

	.loc_0x26FC:
	  lwz       r4, 0x8(r27)
	  addi      r3, r29, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x5EE8
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  addi      r29, r29, 0x3C
	  blt+      .loc_0x26FC
	  mr        r3, r27
	  bl        -0x6258
	  mr        r3, r30
	  bl        0x196C
	  mr        r3, r31
	  lmw       r27, 0x1AC(r1)
	  lwz       r0, 0x1C4(r1)
	  addi      r1, r1, 0x1C0
	  mtlr      r0
	  blr

	.loc_0x2744:
	*/
}

/*
 * --INFO--
 * Address:	801E59CC
 * Size:	000214
 */
void zen::WorldMapCoursePointMgr::modeAppear()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stfd      f29, 0xB8(r1)
	  stfd      f28, 0xB0(r1)
	  stmw      r25, 0x94(r1)
	  mr        r26, r3
	  addi      r28, r26, 0x8
	  li        r29, 0
	  li        r27, 0
	  lis       r31, 0x4330
	  lfs       f29, -0x4188(r2)
	  lfd       f30, -0x4168(r2)
	  lwz       r30, 0x2608(r13)
	  lfs       f28, -0x4154(r2)
	  lfs       f31, -0x4184(r2)
	  lwz       r25, 0x260C(r13)

	.loc_0x4C:
	  stw       r30, 0x0(r28)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x158
	  bge-      .loc_0x70
	  cmpwi     r0, 0
	  beq-      .loc_0x1CC
	  bge-      .loc_0x7C
	  b         .loc_0x1CC

	.loc_0x70:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x1CC
	  b         .loc_0x198

	.loc_0x7C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f28
	  stfs      f0, 0x8(r28)
	  ble-      .loc_0x1CC
	  stfs      f29, 0x70(r1)
	  addi      r5, r1, 0x68
	  li        r4, 0x2E
	  stfs      f29, 0x6C(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f29, 0x68(r1)
	  lwz       r9, 0x14(r28)
	  lha       r10, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  lha       r8, 0x1A(r9)
	  lha       r3, 0x1E(r9)
	  sub       r0, r0, r10
	  srawi     r0, r0, 0x1
	  lha       r9, 0x1A(r9)
	  sub       r8, r3, r8
	  add       r3, r10, r0
	  srawi     r0, r8, 0x1
	  xoris     r3, r3, 0x8000
	  add       r0, r9, r0
	  stw       r3, 0x8C(r1)
	  subfic    r0, r0, 0x1E0
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x88(r1)
	  stw       r0, 0x84(r1)
	  lfd       f0, 0x88(r1)
	  stw       r31, 0x80(r1)
	  fsubs     f1, f0, f30
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f30
	  stfs      f1, 0x68(r1)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x2604(r13)
	  stfs      f0, 0x70(r1)
	  lwz       r3, 0x31C0(r13)
	  bl        0x404C
	  lwz       r3, 0x31C0(r13)
	  addi      r5, r1, 0x68
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        0x4034
	  li        r3, 0x126
	  bl        -0x14079C
	  li        r0, 0x2
	  stw       r0, 0x4(r28)
	  stfs      f29, 0x8(r28)
	  b         .loc_0x1CC

	.loc_0x158:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r28)
	  ble-      .loc_0x1CC
	  stfs      f29, 0x8(r28)
	  li        r0, 0x3
	  li        r4, 0x1
	  stw       r0, 0x4(r28)
	  lwz       r3, 0x1C(r28)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1CC

	.loc_0x198:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r28)
	  ble-      .loc_0x1CC
	  stfs      f29, 0x8(r28)
	  li        r0, 0
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x0(r28)
	  or        r0, r0, r25
	  stw       r0, 0x0(r28)

	.loc_0x1CC:
	  lwz       r0, 0x0(r28)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x1DC
	  li        r29, 0x1

	.loc_0x1DC:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x5
	  addi      r28, r28, 0x3C
	  blt+      .loc_0x4C
	  mr        r3, r29
	  lmw       r25, 0x94(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E5BE0
 * Size:	0005A4
 */
void zen::WorldMapCoursePointMgr::modeOperation(Controller*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x178(r1)
	  stfd      f31, 0x170(r1)
	  stfd      f30, 0x168(r1)
	  stfd      f29, 0x160(r1)
	  stfd      f28, 0x158(r1)
	  stmw      r24, 0x138(r1)
	  mr        r25, r3
	  mr        r26, r4
	  mr        r27, r5
	  addi      r29, r25, 0x8
	  li        r28, 0
	  lis       r31, 0x4330
	  lfs       f29, -0x4188(r2)
	  lfd       f30, -0x4168(r2)
	  lwz       r30, 0x2608(r13)
	  lfs       f28, -0x4154(r2)
	  lfs       f31, -0x4184(r2)
	  lwz       r24, 0x260C(r13)

	.loc_0x50:
	  stw       r30, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x15C
	  bge-      .loc_0x74
	  cmpwi     r0, 0
	  beq-      .loc_0x1D0
	  bge-      .loc_0x80
	  b         .loc_0x1D0

	.loc_0x74:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x1D0
	  b         .loc_0x19C

	.loc_0x80:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f28
	  stfs      f0, 0x8(r29)
	  ble-      .loc_0x1D0
	  stfs      f29, 0x114(r1)
	  addi      r5, r1, 0x10C
	  li        r4, 0x2E
	  stfs      f29, 0x110(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f29, 0x10C(r1)
	  lwz       r9, 0x14(r29)
	  lha       r10, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  lha       r8, 0x1A(r9)
	  lha       r3, 0x1E(r9)
	  sub       r0, r0, r10
	  srawi     r0, r0, 0x1
	  lha       r9, 0x1A(r9)
	  sub       r8, r3, r8
	  add       r3, r10, r0
	  srawi     r0, r8, 0x1
	  xoris     r3, r3, 0x8000
	  add       r0, r9, r0
	  stw       r3, 0x134(r1)
	  subfic    r0, r0, 0x1E0
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x130(r1)
	  stw       r0, 0x12C(r1)
	  lfd       f0, 0x130(r1)
	  stw       r31, 0x128(r1)
	  fsubs     f1, f0, f30
	  lfd       f0, 0x128(r1)
	  fsubs     f0, f0, f30
	  stfs      f1, 0x10C(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x2604(r13)
	  stfs      f0, 0x114(r1)
	  lwz       r3, 0x31C0(r13)
	  bl        0x3E34
	  lwz       r3, 0x31C0(r13)
	  addi      r5, r1, 0x10C
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        0x3E1C
	  li        r3, 0x126
	  bl        -0x1409B4
	  li        r0, 0x2
	  stw       r0, 0x4(r29)
	  stfs      f29, 0x8(r29)
	  b         .loc_0x1D0

	.loc_0x15C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r29)
	  ble-      .loc_0x1D0
	  stfs      f29, 0x8(r29)
	  li        r0, 0x3
	  li        r4, 0x1
	  stw       r0, 0x4(r29)
	  lwz       r3, 0x1C(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1D0

	.loc_0x19C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f31
	  stfs      f0, 0x8(r29)
	  ble-      .loc_0x1D0
	  stfs      f29, 0x8(r29)
	  li        r0, 0
	  stw       r0, 0x4(r29)
	  lwz       r0, 0x0(r29)
	  or        r0, r0, r24
	  stw       r0, 0x0(r29)

	.loc_0x1D0:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x5
	  addi      r29, r29, 0x3C
	  blt+      .loc_0x50
	  cmplwi    r26, 0
	  beq-      .loc_0x57C
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0x55C
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x2C0
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x2C(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x2C0
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C0
	  li        r3, 0x112
	  bl        -0x140A88
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x268
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x268:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B4
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x2B4:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x2C0:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x390
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x30(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x390
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x390
	  li        r3, 0x112
	  bl        -0x140B58
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x338
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x338:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x384
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x384:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x390:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x460
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x34(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x460
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  li        r3, 0x112
	  bl        -0x140C28
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x408
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x408:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x454
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x454:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x460:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x530
	  lwz       r3, 0x4(r25)
	  lwz       r24, 0x38(r3)
	  cmplwi    r24, 0
	  beq-      .loc_0x530
	  lbz       r0, 0xC(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x530
	  li        r3, 0x112
	  bl        -0x140CF8
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D8
	  lwz       r3, 0x14(r6)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x4D8:
	  stw       r24, 0x4(r25)
	  lwz       r6, 0x4(r25)
	  lbz       r0, 0xC(r6)
	  cmplwi    r0, 0
	  beq-      .loc_0x524
	  lwz       r3, 0x14(r6)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x524:
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x1
	  stw       r0, 0x134(r25)

	.loc_0x530:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r26)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x57C
	  li        r3, 0x111
	  bl        -0x140DB4
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x10
	  stw       r0, 0x134(r25)
	  b         .loc_0x57C

	.loc_0x55C:
	  lwz       r0, 0x28(r26)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x57C
	  li        r3, 0x11D
	  bl        -0x140DD8
	  lwz       r0, 0x134(r25)
	  ori       r0, r0, 0x20
	  stw       r0, 0x134(r25)

	.loc_0x57C:
	  lmw       r24, 0x138(r1)
	  li        r3, 0
	  lwz       r0, 0x17C(r1)
	  lfd       f31, 0x170(r1)
	  lfd       f30, 0x168(r1)
	  lfd       f29, 0x160(r1)
	  lfd       f28, 0x158(r1)
	  addi      r1, r1, 0x178
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E6184
 * Size:	000868
 */
void zen::DrawWorldMap::modeOperation(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x208(r1)
	  stfd      f31, 0x200(r1)
	  stfd      f30, 0x1F8(r1)
	  stfd      f29, 0x1F0(r1)
	  stmw      r20, 0x1C0(r1)
	  mr        r31, r3
	  addi      r26, r4, 0
	  li        r25, 0
	  lwz       r23, 0x364(r3)
	  bl        0x31EC0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4168(r2)
	  stw       r0, 0x1BC(r1)
	  lis       r22, 0x4330
	  lfs       f2, -0x4160(r2)
	  stw       r22, 0x1B8(r1)
	  lfs       f1, -0x4178(r2)
	  lfd       f3, 0x1B8(r1)
	  lfs       f0, 0x0(r23)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x11C
	  bl        0x31E84
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4168(r2)
	  stw       r0, 0x1BC(r1)
	  lfs       f1, -0x4160(r2)
	  stw       r22, 0x1B8(r1)
	  lfs       f0, -0x40B8(r2)
	  lfd       f2, 0x1B8(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f29, f0, f1
	  bl        0x31E58
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4168(r2)
	  stw       r0, 0x1B4(r1)
	  lfs       f1, -0x4160(r2)
	  stw       r22, 0x1B0(r1)
	  lfs       f0, -0x4174(r2)
	  lfd       f2, 0x1B0(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f30, f0, f1
	  bl        0x31E2C
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x40B0(r2)
	  stw       r0, 0x1AC(r1)
	  addi      r5, r1, 0x170
	  fsubs     f1, f0, f30
	  lfd       f5, -0x4168(r2)
	  stw       r22, 0x1A8(r1)
	  lfs       f3, -0x4160(r2)
	  fneg      f0, f29
	  lfd       f4, 0x1A8(r1)
	  li        r4, 0x33
	  lfs       f2, -0x40B4(r2)
	  li        r6, 0
	  fsubs     f4, f4, f5
	  lwz       r3, 0x31C0(r13)
	  li        r7, 0
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  stfs      f2, 0x170(r1)
	  stfs      f1, 0x174(r1)
	  stfs      f0, 0x178(r1)
	  bl        0x38A0

	.loc_0x11C:
	  lbz       r0, 0x4(r23)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  lfs       f1, 0x0(r23)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x14C
	  li        r0, 0
	  stb       r0, 0x4(r23)
	  lfs       f0, -0x4170(r2)
	  stfs      f0, 0x0(r23)
	  b         .loc_0x158

	.loc_0x14C:
	  lfs       f0, -0x4144(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r23)

	.loc_0x158:
	  lwz       r3, 0x34(r31)
	  li        r5, 0
	  lbz       r0, 0x35(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x17C
	  lbz       r0, 0x34(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x17C
	  li        r5, 0x1

	.loc_0x17C:
	  lwz       r23, 0x38(r31)
	  li        r22, 0
	  stw       r22, 0x134(r23)
	  lwz       r0, 0x0(r23)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1B4
	  bge-      .loc_0x1D4
	  cmpwi     r0, 0
	  bge-      .loc_0x1A4
	  b         .loc_0x1D4

	.loc_0x1A4:
	  addi      r3, r23, 0
	  addi      r4, r26, 0
	  bl        -0x750
	  b         .loc_0x1D4

	.loc_0x1B4:
	  mr        r3, r23
	  bl        -0x970
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1D4
	  stw       r22, 0x0(r23)
	  li        r0, 0x40
	  stw       r0, 0x134(r23)

	.loc_0x1D4:
	  lwz       r3, 0x38(r31)
	  lwz       r30, 0x134(r3)
	  rlwinm.   r0,r30,0,31,31
	  beq-      .loc_0x2B0
	  lwz       r26, 0x34(r31)
	  li        r4, 0
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r26)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r20, 0x18(r3)
	  lha       r21, 0x1A(r3)
	  bne-      .loc_0x2A8
	  lbz       r3, 0x34(r26)
	  cmplwi    r3, 0
	  bne-      .loc_0x218
	  li        r4, 0x1

	.loc_0x218:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x2A8
	  cmplwi    r3, 0
	  bne-      .loc_0x23C
	  lbz       r0, 0x35(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x23C
	  li        r3, 0x123
	  bl        -0x141048

	.loc_0x23C:
	  li        r0, 0x1
	  stw       r0, 0x4(r26)
	  lwz       r0, 0x4(r26)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x268
	  bge-      .loc_0x268
	  cmpwi     r0, 0
	  bge-      .loc_0x260
	  b         .loc_0x268

	.loc_0x260:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r26)

	.loc_0x268:
	  xoris     r0, r20, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1AC(r1)
	  xoris     r0, r21, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0x1A8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stw       r3, 0x1B0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1B0(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r26)
	  stfs      f0, 0x10(r26)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r26)

	.loc_0x2A8:
	  mr        r3, r31
	  bl        0xFC8

	.loc_0x2B0:
	  rlwinm.   r0,r30,0,27,27
	  beq-      .loc_0x2CC
	  lwz       r3, 0x70(r31)
	  li        r4, 0x1
	  bl        -0x8E8C
	  li        r0, 0x4
	  stw       r0, 0x4(r31)

	.loc_0x2CC:
	  rlwinm.   r0,r30,0,26,26
	  beq-      .loc_0x38C
	  lwz       r3, 0x38(r31)
	  lwz       r22, 0x34(r31)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r22)
	  lwz       r3, 0x24(r3)
	  cmplwi    r0, 0
	  lha       r20, 0x18(r3)
	  lha       r21, 0x1A(r3)
	  bne-      .loc_0x304
	  lbz       r0, 0x34(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x38C

	.loc_0x304:
	  li        r0, 0
	  stb       r0, 0x35(r22)
	  addi      r3, r22, 0
	  li        r4, 0
	  bl        -0x86B0
	  li        r0, 0x1
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x344
	  bge-      .loc_0x344
	  cmpwi     r0, 0
	  bge-      .loc_0x33C
	  b         .loc_0x344

	.loc_0x33C:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r22)

	.loc_0x344:
	  xoris     r0, r20, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0x1AC(r1)
	  xoris     r0, r21, 0x8000
	  lis       r4, 0x4330
	  stw       r4, 0x1A8(r1)
	  li        r3, 0x11D
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stw       r4, 0x1B0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1B0(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r22)
	  stfs      f0, 0x10(r22)
	  lfs       f0, 0x2568(r13)
	  stfs      f0, 0x14(r22)
	  bl        -0x141198

	.loc_0x38C:
	  lwz       r3, 0x34(r31)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x740
	  lwz       r3, 0x38(r31)
	  li        r0, -0x1
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3B4
	  lwz       r0, 0x10(r3)

	.loc_0x3B4:
	  stw       r0, 0x8(r31)
	  li        r4, 0
	  lwz       r3, 0x50(r31)
	  bl        0x3790
	  lwz       r3, 0x38(r31)
	  lfs       f0, -0x4188(r2)
	  lwz       r3, 0x4(r3)
	  lwz       r21, 0x14(r3)
	  stfs      f0, 0x100(r1)
	  addi      r3, r21, 0x18
	  stfs      f0, 0xFC(r1)
	  stfs      f0, 0xF8(r1)
	  bl        -0x2E034
	  lha       r20, 0x1A(r21)
	  addi      r22, r3, 0
	  addi      r3, r21, 0x18
	  bl        -0x2E054
	  lha       r4, 0x18(r21)
	  srawi     r3, r3, 0x1
	  srawi     r0, r22, 0x1
	  lfd       f2, -0x4168(r2)
	  add       r3, r4, r3
	  xoris     r3, r3, 0x8000
	  add       r0, r20, r0
	  stw       r3, 0x1AC(r1)
	  subfic    r0, r0, 0x1E0
	  xoris     r0, r0, 0x8000
	  lis       r22, 0x4330
	  stw       r0, 0x1B4(r1)
	  addi      r5, r1, 0xF8
	  stw       r22, 0x1A8(r1)
	  li        r4, 0x2D
	  li        r6, 0
	  stw       r22, 0x1B0(r1)
	  li        r7, 0
	  lfd       f1, 0x1A8(r1)
	  lfd       f0, 0x1B0(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  stfs      f1, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f0, 0x2600(r13)
	  stfs      f0, 0x100(r1)
	  lwz       r3, 0x31C0(r13)
	  bl        0x3554
	  lwz       r25, 0x58(r31)
	  addi      r30, r1, 0xD8
	  lfs       f29, -0x4188(r2)
	  addi      r29, r1, 0xD4
	  lfs       f30, -0x4154(r2)
	  lfd       f31, -0x4168(r2)
	  addi      r26, r25, 0
	  addi      r28, r1, 0xE0
	  addi      r27, r1, 0xDC
	  li        r21, 0

	.loc_0x490:
	  lfs       f0, 0x10(r26)
	  addi      r20, r26, 0xC
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4AC
	  fadds     f0, f30, f0
	  b         .loc_0x4B0

	.loc_0x4AC:
	  fsubs     f0, f0, f30

	.loc_0x4B0:
	  lfs       f1, 0x0(r20)
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f29
	  stfd      f0, 0x1A8(r1)
	  lwz       r23, 0x1AC(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4D4
	  fadds     f0, f30, f1
	  b         .loc_0x4D8

	.loc_0x4D4:
	  fsubs     f0, f1, f30

	.loc_0x4D8:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r20)
	  addi      r3, r3, 0x18
	  stfd      f0, 0x1A8(r1)
	  lwz       r24, 0x1AC(r1)
	  bl        -0x2E14C
	  lwz       r4, 0x24(r20)
	  srawi     r0, r3, 0x1
	  sub       r24, r24, r0
	  addi      r3, r4, 0x18
	  bl        -0x2E150
	  srawi     r0, r3, 0x1
	  lwz       r3, 0x24(r20)
	  sub       r23, r23, r0
	  lwz       r12, 0x0(r3)
	  addi      r4, r24, 0
	  addi      r5, r23, 0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  xoris     r23, r23, 0x8000
	  xoris     r24, r24, 0x8000
	  stw       r23, 0x1B4(r1)
	  mr        r4, r29
	  stw       r24, 0x1BC(r1)
	  addi      r5, r30, 0
	  addi      r3, r20, 0xC
	  stw       r22, 0x1B0(r1)
	  addi      r6, r13, 0x25EC
	  stw       r22, 0x1B8(r1)
	  lfd       f1, 0x1B0(r1)
	  lfd       f0, 0x1B8(r1)
	  fsubs     f1, f1, f31
	  fsubs     f0, f0, f31
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xD4(r1)
	  bl        -0x189060
	  stw       r23, 0x1A4(r1)
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  stw       r24, 0x19C(r1)
	  addi      r3, r20, 0x18
	  addi      r6, r13, 0x25F0
	  stw       r22, 0x1A0(r1)
	  stw       r22, 0x198(r1)
	  lfd       f1, 0x1A0(r1)
	  lfd       f0, 0x198(r1)
	  fsubs     f1, f1, f31
	  fsubs     f0, f0, f31
	  stfs      f1, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  bl        -0x18909C
	  addi      r21, r21, 0x1
	  cmpwi     r21, 0x4
	  addi      r26, r26, 0x28
	  blt+      .loc_0x490
	  li        r0, 0
	  stw       r0, 0x0(r25)
	  li        r0, 0x2
	  mtctr     r0
	  lis       r3, 0x4330
	  lwz       r7, 0x58(r31)
	  lfs       f0, -0x4188(r2)
	  mr        r9, r7
	  stfs      f0, 0x4(r7)
	  lfs       f0, -0x4154(r2)
	  stfs      f0, 0x8(r7)
	  lfd       f3, -0x4168(r2)

	.loc_0x5E8:
	  lwz       r5, 0x30(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x19C(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x198(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x1A4(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x198(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x1A0(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x1A0(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1AC(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x18(r9)
	  stw       r3, 0x1A8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stfs      f1, 0x1C(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x1B0(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x1B0(r1)
	  stfs      f2, 0x20(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x24(r9)
	  stfs      f0, 0x28(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x2C(r9)
	  lwz       r5, 0x58(r9)
	  lha       r0, 0x18(r5)
	  lha       r10, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  lha       r4, 0x1E(r5)
	  stw       r0, 0x19C(r1)
	  xoris     r0, r10, 0x8000
	  lha       r6, 0x18(r5)
	  sub       r4, r4, r10
	  stw       r3, 0x198(r1)
	  lha       r5, 0x1C(r5)
	  stw       r0, 0x1A4(r1)
	  sub       r0, r5, r6
	  lfd       f0, 0x198(r1)
	  srawi     r0, r0, 0x1
	  stw       r3, 0x1A0(r1)
	  subfic    r0, r0, 0x140
	  fsubs     f2, f0, f3
	  lfd       f0, 0x1A0(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1AC(r1)
	  srawi     r4, r4, 0x1
	  subfic    r0, r4, 0xF0
	  fsubs     f1, f0, f3
	  xoris     r0, r0, 0x8000
	  stfs      f2, 0x40(r9)
	  stw       r3, 0x1A8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1A8(r1)
	  stfs      f1, 0x44(r9)
	  fsubs     f1, f0, f3
	  stw       r3, 0x1B0(r1)
	  lfs       f2, 0x25F4(r13)
	  lfd       f0, 0x1B0(r1)
	  stfs      f2, 0x48(r9)
	  fsubs     f0, f0, f3
	  stfs      f1, 0x4C(r9)
	  stfs      f0, 0x50(r9)
	  lfs       f0, 0x25F8(r13)
	  stfs      f0, 0x54(r9)
	  addi      r9, r9, 0x50
	  bdnz+     .loc_0x5E8
	  li        r0, 0x1
	  stw       r0, 0x0(r7)
	  li        r25, 0x1
	  stb       r0, 0xAC(r7)

	.loc_0x740:
	  lwz       r22, 0x34(r31)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x770
	  bge-      .loc_0x800
	  cmpwi     r0, 0
	  bge-      .loc_0x764
	  b         .loc_0x800
	  b         .loc_0x800

	.loc_0x764:
	  mr        r3, r22
	  bl        -0x5F68
	  b         .loc_0x800

	.loc_0x770:
	  mr        r3, r22
	  bl        -0x6408
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x800
	  lbz       r0, 0x35(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x798
	  mr        r3, r22
	  bl        -0x64F4
	  b         .loc_0x800

	.loc_0x798:
	  lbz       r0, 0x34(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x7D4
	  li        r0, 0x2
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x800
	  bge-      .loc_0x800
	  cmpwi     r0, 0
	  bge-      .loc_0x7C8
	  b         .loc_0x800

	.loc_0x7C8:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r22)
	  b         .loc_0x800

	.loc_0x7D4:
	  li        r0, 0
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x800
	  bge-      .loc_0x800
	  cmpwi     r0, 0
	  bge-      .loc_0x7F8
	  b         .loc_0x800

	.loc_0x7F8:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r22)

	.loc_0x800:
	  mr        r3, r22
	  bl        -0x68B8
	  li        r20, 0
	  mulli     r0, r20, 0x3C
	  add       r21, r22, r0

	.loc_0x814:
	  lwz       r4, 0x8(r22)
	  addi      r3, r21, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x6EFC
	  addi      r20, r20, 0x1
	  cmpwi     r20, 0x3
	  addi      r21, r21, 0x3C
	  blt+      .loc_0x814
	  mr        r3, r22
	  bl        -0x726C
	  mr        r3, r31
	  bl        0x958
	  mr        r3, r25
	  lmw       r20, 0x1C0(r1)
	  lwz       r0, 0x20C(r1)
	  lfd       f31, 0x200(r1)
	  lfd       f30, 0x1F8(r1)
	  lfd       f29, 0x1F0(r1)
	  addi      r1, r1, 0x208
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E69EC
 * Size:	000614
 */
void zen::DrawWorldMap::modeConfirm(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stmw      r26, 0x108(r1)
	  mr        r31, r3
	  lwz       r28, 0x70(r3)
	  lwz       r0, 0x74(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x184
	  bge-      .loc_0x38
	  cmpwi     r0, 0x1
	  bge-      .loc_0x44
	  b         .loc_0x360

	.loc_0x38:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x360
	  b         .loc_0x1A8

	.loc_0x44:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r28)
	  lfs       f1, 0x70(r28)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x80
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x2
	  stfs      f0, 0x70(r28)
	  lfs       f1, -0x4184(r2)
	  stw       r0, 0x74(r28)
	  b         .loc_0x90

	.loc_0x80:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4148(r2)
	  fmuls     f1, f1, f0
	  bl        0x35270

	.loc_0x90:
	  lfs       f0, -0x4148(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f31
	  bl        0x350CC
	  lfs       f0, -0x4178(r2)
	  fmuls     f0, f0, f1
	  fmr       f1, f31
	  stfs      f0, 0x7C(r28)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x80(r28)
	  bl        0x35244
	  lfs       f2, -0x4178(r2)
	  fmuls     f0, f2, f1
	  fsubs     f0, f0, f2
	  stfs      f0, 0x84(r28)
	  lfs       f1, 0x80(r28)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xEC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xF4

	.loc_0xEC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0xF4:
	  lfs       f2, 0x7C(r28)
	  fctiwz    f1, f0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x100(r1)
	  lwz       r5, 0x104(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x120
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x128

	.loc_0x120:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0x128:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  stfd      f0, 0x100(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x104(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  lfs       f1, 0x84(r28)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x4148(r2)
	  li        r4, 0x1
	  lwz       r3, 0x0(r28)
	  fsubs     f0, f31, f0
	  lfs       f1, -0x4108(r2)
	  addi      r3, r3, 0x4
	  fsubs     f1, f1, f0
	  bl        -0x6035C
	  b         .loc_0x360

	.loc_0x184:
	  mr        r3, r28
	  bl        .loc_0x614
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x360
	  li        r0, 0x3
	  stw       r0, 0x74(r28)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x70(r28)
	  b         .loc_0x360

	.loc_0x1A8:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r28)
	  lfs       f1, 0x70(r28)
	  lfs       f0, -0x4144(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1F4
	  lfs       f0, -0x4188(r2)
	  li        r4, 0
	  stfs      f0, 0x70(r28)
	  lfs       f2, -0x4184(r2)
	  stw       r4, 0x74(r28)
	  lwz       r3, 0x0(r28)
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  b         .loc_0x20C

	.loc_0x1F4:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x4148(r2)
	  fmuls     f1, f1, f0
	  bl        0x34F68
	  lfs       f0, -0x4184(r2)
	  fsubs     f2, f0, f1

	.loc_0x20C:
	  lwz       r0, 0x78(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x26C
	  lfs       f1, -0x40AC(r2)
	  lfs       f0, -0x4188(r2)
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x23C
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x244

	.loc_0x23C:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x244:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  li        r4, 0
	  stfd      f0, 0x100(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r5, 0x104(r1)
	  mtlr      r12
	  blrl
	  b         .loc_0x360

	.loc_0x26C:
	  lfs       f1, -0x4148(r2)
	  fmuls     f0, f1, f2
	  fadds     f31, f1, f0
	  fmr       f1, f31
	  bl        0x34EEC
	  lfs       f0, -0x4178(r2)
	  fmuls     f0, f0, f1
	  fmr       f1, f31
	  stfs      f0, 0x7C(r28)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x80(r28)
	  bl        0x35064
	  lfs       f2, -0x4178(r2)
	  fmuls     f0, f2, f1
	  fsubs     f0, f0, f2
	  stfs      f0, 0x84(r28)
	  lfs       f1, 0x80(r28)
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2CC
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x2D4

	.loc_0x2CC:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f1, f0

	.loc_0x2D4:
	  lfs       f2, 0x7C(r28)
	  fctiwz    f1, f0
	  lfs       f0, -0x4188(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x100(r1)
	  lwz       r5, 0x104(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x300
	  lfs       f0, -0x4154(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x308

	.loc_0x300:
	  lfs       f0, -0x4154(r2)
	  fsubs     f0, f2, f0

	.loc_0x308:
	  fctiwz    f0, f0
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  stfd      f0, 0x100(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x104(r1)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r28)
	  lwzu      r12, 0x4(r3)
	  lfs       f1, 0x84(r28)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x4148(r2)
	  li        r4, 0x1
	  lwz       r3, 0x0(r28)
	  fsubs     f0, f31, f0
	  lfs       f1, -0x4108(r2)
	  addi      r3, r3, 0x4
	  fsubs     f1, f1, f0
	  bl        -0x6053C

	.loc_0x360:
	  lwz       r3, 0x0(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r28, 0x4
	  bl        -0xC550
	  addi      r3, r28, 0x34
	  bl        -0xC558
	  lwz       r3, 0x74(r28)
	  neg       r0, r3
	  cntlzw    r0, r0
	  cmpwi     r3, 0
	  rlwinm    r30,r0,27,5,31
	  bne-      .loc_0x4F4
	  lwz       r3, 0x70(r31)
	  lwz       r0, 0x78(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x4F4
	  lwz       r3, 0x38(r31)
	  li        r26, 0
	  lwz       r27, 0x34(r31)
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x35(r27)
	  lwz       r3, 0x28(r3)
	  cmplwi    r0, 0
	  lha       r29, 0x18(r3)
	  lha       r28, 0x1A(r3)
	  bne-      .loc_0x4F4
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x40C
	  bge-      .loc_0x460
	  cmpwi     r0, 0
	  bge-      .loc_0x3F0
	  b         .loc_0x460

	.loc_0x3F0:
	  lfs       f0, -0x4188(r2)
	  addi      r3, r27, 0
	  li        r26, 0x1
	  stfs      f0, 0x0(r27)
	  li        r4, 0x1
	  bl        -0x9008
	  b         .loc_0x460

	.loc_0x40C:
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x460
	  xoris     r0, r29, 0x8000
	  stw       r0, 0x104(r1)
	  xoris     r0, r28, 0x8000
	  li        r4, 0x1
	  lis       r3, 0x4330
	  stb       r4, 0x35(r27)
	  stw       r3, 0x100(r1)
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0xFC(r1)
	  lfd       f0, 0x100(r1)
	  stw       r3, 0xF8(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x38(r27)
	  stfs      f0, 0x3C(r27)
	  lfs       f0, 0x2560(r13)
	  stfs      f0, 0x40(r27)

	.loc_0x460:
	  rlwinm.   r0,r26,0,24,31
	  beq-      .loc_0x4F4
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x488
	  lbz       r0, 0x35(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x488
	  li        r3, 0x123
	  bl        -0x141AFC

	.loc_0x488:
	  li        r0, 0x1
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x4B4
	  bge-      .loc_0x4B4
	  cmpwi     r0, 0
	  bge-      .loc_0x4AC
	  b         .loc_0x4B4

	.loc_0x4AC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)

	.loc_0x4B4:
	  xoris     r0, r29, 0x8000
	  lfd       f2, -0x4168(r2)
	  stw       r0, 0xFC(r1)
	  xoris     r0, r28, 0x8000
	  lis       r3, 0x4330
	  stw       r3, 0xF8(r1)
	  stw       r0, 0x104(r1)
	  lfd       f0, 0xF8(r1)
	  stw       r3, 0x100(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x100(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r27)
	  stfs      f0, 0x10(r27)
	  lfs       f0, 0x2564(r13)
	  stfs      f0, 0x14(r27)

	.loc_0x4F4:
	  lwz       r28, 0x34(r31)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x524
	  bge-      .loc_0x5B4
	  cmpwi     r0, 0
	  bge-      .loc_0x518
	  b         .loc_0x5B4
	  b         .loc_0x5B4

	.loc_0x518:
	  mr        r3, r28
	  bl        -0x6584
	  b         .loc_0x5B4

	.loc_0x524:
	  mr        r3, r28
	  bl        -0x6A24
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5B4
	  lbz       r0, 0x35(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x54C
	  mr        r3, r28
	  bl        -0x6B10
	  b         .loc_0x5B4

	.loc_0x54C:
	  lbz       r0, 0x34(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x588
	  li        r0, 0x2
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5B4
	  bge-      .loc_0x5B4
	  cmpwi     r0, 0
	  bge-      .loc_0x57C
	  b         .loc_0x5B4

	.loc_0x57C:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r28)
	  b         .loc_0x5B4

	.loc_0x588:
	  li        r0, 0
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x4(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5B4
	  bge-      .loc_0x5B4
	  cmpwi     r0, 0
	  bge-      .loc_0x5AC
	  b         .loc_0x5B4

	.loc_0x5AC:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r28)

	.loc_0x5B4:
	  mr        r3, r28
	  bl        -0x6ED4
	  li        r26, 0
	  mulli     r0, r26, 0x3C
	  add       r27, r28, r0

	.loc_0x5C8:
	  lwz       r4, 0x8(r28)
	  addi      r3, r27, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x7518
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r27, r27, 0x3C
	  blt+      .loc_0x5C8
	  mr        r3, r28
	  bl        -0x7888
	  mr        r3, r31
	  bl        0x33C
	  mr        r3, r30
	  lmw       r26, 0x108(r1)
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr

	.loc_0x614:
	*/
}

/*
 * --INFO--
 * Address:	801E7000
 * Size:	0001C8
 */
void zen::WorldMapConfirmMgr::modeOperation(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stmw      r25, 0x64(r1)
	  mr        r28, r4
	  mr        r27, r3
	  li        r30, 0
	  lwz       r5, 0x28(r4)
	  lwz       r29, 0x78(r3)
	  rlwinm    r0,r5,0,12,12
	  neg       r4, r0
	  subic     r3, r4, 0x1
	  rlwinm    r0,r5,0,10,10
	  subfe     r4, r3, r4
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r4,0,24,31
	  rlwinm    r0,r0,0,24,31
	  sub       r0, r0, r3
	  add       r0, r29, r0
	  stw       r0, 0x78(r27)
	  lwz       r0, 0x78(r27)
	  cmpwi     r0, 0
	  bge-      .loc_0x6C
	  li        r0, 0x1
	  stw       r0, 0x78(r27)

	.loc_0x6C:
	  lwz       r0, 0x78(r27)
	  cmpwi     r0, 0x1
	  ble-      .loc_0x80
	  li        r0, 0
	  stw       r0, 0x78(r27)

	.loc_0x80:
	  lwz       r0, 0x78(r27)
	  li        r25, 0
	  lwz       r3, 0x64(r27)
	  li        r26, 0
	  mulli     r0, r0, 0xC
	  add       r31, r3, r0

	.loc_0x98:
	  lwz       r3, 0x78(r27)
	  addi      r5, r27, 0x68
	  lwz       r0, 0x64(r27)
	  addi      r6, r27, 0x6C
	  sub       r3, r3, r25
	  cntlzw    r3, r3
	  add       r7, r0, r26
	  rlwinm    r4,r3,27,5,31
	  lwz       r3, 0x0(r7)
	  bl        -0x247A0
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x2
	  addi      r26, r26, 0xC
	  blt+      .loc_0x98
	  lwz       r0, 0x78(r27)
	  cmpw      r29, r0
	  beq-      .loc_0x170
	  li        r3, 0x112
	  bl        -0x141D6C
	  lwz       r4, 0x4(r31)
	  lis       r29, 0x4330
	  lfd       f2, -0x4168(r2)
	  addi      r3, r27, 0x4
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  lfs       f3, -0x4154(r2)
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r4, 0x5C(r1)
	  stw       r29, 0x58(r1)
	  stw       r29, 0x50(r1)
	  lfd       f1, 0x58(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0xC580
	  lwz       r4, 0x8(r31)
	  addi      r3, r27, 0x34
	  lfd       f2, -0x4168(r2)
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  lfs       f3, -0x4154(r2)
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x44(r1)
	  stw       r4, 0x4C(r1)
	  stw       r29, 0x48(r1)
	  stw       r29, 0x40(r1)
	  lfd       f1, 0x48(r1)
	  lfd       f0, 0x40(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        -0xC5C4

	.loc_0x170:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x190
	  li        r3, 0x111
	  bl        -0x141E14
	  li        r30, 0x1

	.loc_0x190:
	  lwz       r0, 0x28(r28)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x1B0
	  li        r3, 0x11D
	  bl        -0x141E2C
	  li        r0, 0x1
	  stw       r0, 0x78(r27)
	  li        r30, 0x1

	.loc_0x1B0:
	  mr        r3, r30
	  lmw       r25, 0x64(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E71C8
 * Size:	000154
 */
void zen::DrawWorldMap::modeEnd(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r30, r3
	  li        r31, 0
	  lwz       r3, 0x58(r3)
	  lbz       r0, 0xAC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  lwz       r3, 0x50(r30)
	  li        r4, 0x1
	  bl        0x2ADC
	  li        r31, 0x1

	.loc_0x38:
	  lwz       r27, 0x34(r30)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x68
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0x5C
	  b         .loc_0xF8
	  b         .loc_0xF8

	.loc_0x5C:
	  mr        r3, r27
	  bl        -0x68A4
	  b         .loc_0xF8

	.loc_0x68:
	  mr        r3, r27
	  bl        -0x6D44
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF8
	  lbz       r0, 0x35(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x90
	  mr        r3, r27
	  bl        -0x6E30
	  b         .loc_0xF8

	.loc_0x90:
	  lbz       r0, 0x34(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  li        r0, 0x2
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0xC0
	  b         .loc_0xF8

	.loc_0xC0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)
	  b         .loc_0xF8

	.loc_0xCC:
	  li        r0, 0
	  stw       r0, 0x4(r27)
	  lwz       r0, 0x4(r27)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0xF8
	  cmpwi     r0, 0
	  bge-      .loc_0xF0
	  b         .loc_0xF8

	.loc_0xF0:
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x30(r27)

	.loc_0xF8:
	  mr        r3, r27
	  bl        -0x71F4
	  li        r29, 0
	  mulli     r0, r29, 0x3C
	  add       r28, r27, r0

	.loc_0x10C:
	  lwz       r4, 0x8(r27)
	  addi      r3, r28, 0x44
	  addi      r4, r4, 0xC0
	  bl        -0x7838
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r28, r28, 0x3C
	  blt+      .loc_0x10C
	  mr        r3, r27
	  bl        -0x7BA8
	  mr        r3, r30
	  bl        .loc_0x154
	  mr        r3, r31
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x154:
	*/
}

/*
 * --INFO--
 * Address:	801E731C
 * Size:	0000DC
 */
void zen::DrawWorldMap::updateScreens()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x10(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x14(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x18(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x28(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	801E73F8
 * Size:	000124
 */
void zen::DrawWorldMap::closeMapInfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  lwz       r4, 0x54(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x54
	  bge-      .loc_0x2C
	  cmpwi     r0, 0
	  bge-      .loc_0x38
	  b         .loc_0x54

	.loc_0x2C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x54
	  b         .loc_0x4C

	.loc_0x38:
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x1
	  stfs      f0, 0x0(r4)
	  stw       r0, 0x4(r4)
	  b         .loc_0x54

	.loc_0x4C:
	  li        r0, 0x1
	  stb       r0, 0x20(r4)

	.loc_0x54:
	  lwz       r10, 0x5C(r3)
	  lwz       r0, 0x4(r10)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x108
	  mulli     r0, r0, 0x28
	  lwz       r4, 0x0(r10)
	  lfd       f2, -0x4168(r2)
	  add       r8, r4, r0
	  lwz       r9, 0x4(r8)
	  lis       r7, 0x4330
	  li        r4, 0x2
	  lha       r5, 0x18(r9)
	  li        r6, 0x1
	  lha       r9, 0x1A(r9)
	  li        r0, -0x1
	  xoris     r5, r5, 0x8000
	  stw       r5, 0x3C(r1)
	  xoris     r5, r9, 0x8000
	  stw       r7, 0x38(r1)
	  stw       r5, 0x34(r1)
	  lfd       f0, 0x38(r1)
	  stw       r7, 0x30(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x10(r8)
	  stfs      f0, 0x14(r8)
	  lfs       f0, 0x2480(r13)
	  stfs      f0, 0x18(r8)
	  lfs       f2, 0x14(r8)
	  lfs       f1, -0x40A8(r2)
	  lfs       f0, 0x10(r8)
	  fsubs     f1, f2, f1
	  stfs      f0, 0x1C(r8)
	  stfs      f1, 0x20(r8)
	  lfs       f0, 0x18(r8)
	  stfs      f0, 0x24(r8)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x8(r8)
	  stw       r4, 0x0(r8)
	  lwz       r5, 0x4(r8)
	  lbz       r4, 0xC(r5)
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  stw       r0, 0x4(r10)

	.loc_0x108:
	  lwz       r3, 0x60(r3)
	  li        r4, -0x1
	  bl        .loc_0x124
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x124:
	*/
}

/*
 * --INFO--
 * Address:	801E751C
 * Size:	00020C
 */
void zen::WorldMapPartsInfoMgr::setActiveMapNo(@unnamed @ ::WorldMapName)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  bne-      .loc_0x2C
	  li        r3, 0
	  li        r31, 0
	  b         .loc_0x130

	.loc_0x2C:
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  cmpwi     r4, 0x2
	  beq-      .loc_0x84
	  bge-      .loc_0x54
	  cmpwi     r4, 0
	  beq-      .loc_0x64
	  bge-      .loc_0x74
	  b         .loc_0xB4

	.loc_0x54:
	  cmpwi     r4, 0x4
	  beq-      .loc_0xA4
	  bge-      .loc_0xB4
	  b         .loc_0x94

	.loc_0x64:
	  li        r31, 0x2
	  li        r4, 0
	  bl        -0x167974
	  b         .loc_0x130

	.loc_0x74:
	  li        r31, 0x8
	  li        r4, 0x1
	  bl        -0x167984
	  b         .loc_0x130

	.loc_0x84:
	  li        r31, 0x9
	  li        r4, 0x2
	  bl        -0x167994
	  b         .loc_0x130

	.loc_0x94:
	  li        r31, 0xA
	  li        r4, 0x3
	  bl        -0x1679A4
	  b         .loc_0x130

	.loc_0xA4:
	  li        r31, 0x1
	  li        r4, 0x4
	  bl        -0x1679B4
	  b         .loc_0x130

	.loc_0xB4:
	  li        r31, 0
	  li        r3, 0
	  b         .loc_0x130

	.loc_0xC0:
	  cmpwi     r4, 0x2
	  beq-      .loc_0x104
	  bge-      .loc_0xDC
	  cmpwi     r4, 0
	  beq-      .loc_0xEC
	  bge-      .loc_0xF8
	  b         .loc_0x128

	.loc_0xDC:
	  cmpwi     r4, 0x4
	  beq-      .loc_0x11C
	  bge-      .loc_0x128
	  b         .loc_0x110

	.loc_0xEC:
	  li        r31, 0x2
	  li        r3, 0x1
	  b         .loc_0x130

	.loc_0xF8:
	  li        r31, 0x8
	  li        r3, 0x2
	  b         .loc_0x130

	.loc_0x104:
	  li        r31, 0x9
	  li        r3, 0x3
	  b         .loc_0x130

	.loc_0x110:
	  li        r31, 0xA
	  li        r3, 0x4
	  b         .loc_0x130

	.loc_0x11C:
	  li        r31, 0x1
	  li        r3, 0
	  b         .loc_0x130

	.loc_0x128:
	  li        r31, 0
	  li        r3, 0

	.loc_0x130:
	  li        r4, 0
	  addi      r5, r4, 0
	  b         .loc_0x1E8

	.loc_0x13C:
	  cmpw      r4, r31
	  bge-      .loc_0x1B4
	  cmpw      r4, r3
	  bge-      .loc_0x180
	  lwz       r6, 0x8(r30)
	  li        r8, 0x1
	  li        r7, 0
	  lwzx      r6, r6, r5
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r8,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r6, 0x4(r30)
	  lwzx      r6, r6, r5
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)
	  b         .loc_0x1E0

	.loc_0x180:
	  lwz       r6, 0x8(r30)
	  li        r8, 0
	  li        r7, 0x1
	  lwzx      r6, r6, r5
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r8,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r6, 0x4(r30)
	  lwzx      r6, r6, r5
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)
	  b         .loc_0x1E0

	.loc_0x1B4:
	  lwz       r6, 0x8(r30)
	  li        r7, 0
	  lwzx      r6, r6, r5
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r6, 0x4(r30)
	  lwzx      r6, r6, r5
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)

	.loc_0x1E0:
	  addi      r5, r5, 0x4
	  addi      r4, r4, 0x1

	.loc_0x1E8:
	  lwz       r0, 0x0(r30)
	  cmpw      r4, r0
	  blt+      .loc_0x13C
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
 * Address:	801E7728
 * Size:	000220
 */
void zen::DrawWorldMap::openMapInfo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  lwz       r4, 0x38(r3)
	  lwz       r4, 0x4(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x2C
	  lwz       r6, 0x10(r4)

	.loc_0x2C:
	  lwz       r4, 0x54(r3)
	  lwz       r0, 0x4(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x50
	  lfs       f0, -0x4188(r2)
	  li        r0, 0x2
	  stfs      f0, 0x0(r4)
	  stw       r6, 0x8(r4)
	  stw       r0, 0x4(r4)

	.loc_0x50:
	  lwz       r7, 0x5C(r3)
	  addi      r4, r13, 0x2470
	  lbzx      r4, r4, r6
	  lwz       r0, 0x4(r7)
	  cmpw      r0, r4
	  beq-      .loc_0xCC
	  stw       r4, 0x4(r7)
	  li        r5, 0x1
	  lwz       r0, 0x4(r7)
	  lwz       r4, 0x0(r7)
	  mulli     r0, r0, 0x28
	  lfs       f0, 0x2484(r13)
	  add       r4, r4, r0
	  stfs      f0, 0x10(r4)
	  lfs       f0, 0x2488(r13)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x248C(r13)
	  stfs      f0, 0x18(r4)
	  lfs       f0, 0x2490(r13)
	  stfs      f0, 0x1C(r4)
	  lfs       f0, 0x2494(r13)
	  stfs      f0, 0x20(r4)
	  lfs       f0, 0x2498(r13)
	  stfs      f0, 0x24(r4)
	  lfs       f0, -0x4188(r2)
	  stfs      f0, 0x8(r4)
	  stw       r5, 0x0(r4)
	  lwz       r4, 0x4(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0xCC:
	  cmpwi     r6, -0x1
	  lwz       r30, 0x60(r3)
	  bne-      .loc_0xE4
	  li        r5, 0
	  li        r31, 0
	  b         .loc_0x1FC

	.loc_0xE4:
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x18C
	  cmpwi     r6, 0x2
	  beq-      .loc_0x144
	  bge-      .loc_0x10C
	  cmpwi     r6, 0
	  beq-      .loc_0x11C
	  bge-      .loc_0x130
	  b         .loc_0x180

	.loc_0x10C:
	  cmpwi     r6, 0x4
	  beq-      .loc_0x16C
	  bge-      .loc_0x180
	  b         .loc_0x158

	.loc_0x11C:
	  li        r31, 0x2
	  li        r4, 0
	  bl        -0x167C38
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x130:
	  li        r31, 0x8
	  li        r4, 0x1
	  bl        -0x167C4C
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x144:
	  li        r31, 0x9
	  li        r4, 0x2
	  bl        -0x167C60
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x158:
	  li        r31, 0xA
	  li        r4, 0x3
	  bl        -0x167C74
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x16C:
	  li        r31, 0x1
	  li        r4, 0x4
	  bl        -0x167C88
	  mr        r5, r3
	  b         .loc_0x1FC

	.loc_0x180:
	  li        r31, 0
	  addi      r5, r31, 0
	  b         .loc_0x1FC

	.loc_0x18C:
	  cmpwi     r6, 0x2
	  beq-      .loc_0x1D0
	  bge-      .loc_0x1A8
	  cmpwi     r6, 0
	  beq-      .loc_0x1B8
	  bge-      .loc_0x1C4
	  b         .loc_0x1F4

	.loc_0x1A8:
	  cmpwi     r6, 0x4
	  beq-      .loc_0x1E8
	  bge-      .loc_0x1F4
	  b         .loc_0x1DC

	.loc_0x1B8:
	  li        r31, 0x2
	  li        r5, 0x1
	  b         .loc_0x1FC

	.loc_0x1C4:
	  li        r31, 0x8
	  li        r5, 0x2
	  b         .loc_0x1FC

	.loc_0x1D0:
	  li        r31, 0x9
	  li        r5, 0x3
	  b         .loc_0x1FC

	.loc_0x1DC:
	  li        r31, 0xA
	  li        r5, 0x4
	  b         .loc_0x1FC

	.loc_0x1E8:
	  li        r31, 0x1
	  li        r5, 0
	  b         .loc_0x1FC

	.loc_0x1F4:
	  li        r31, 0
	  addi      r5, r31, 0

	.loc_0x1FC:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x4F48
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E7948
 * Size:	000168
 */
void @unnamed @ ::DrawWorldMapDateCallBack::invoke(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x166DB0
	  addi      r0, r3, 0x1
	  cmpwi     r0, 0x9
	  ble-      .loc_0xF0
	  lwz       r5, 0x4(r31)
	  lis       r3, 0x6666
	  addi      r3, r3, 0x6667
	  lbz       r4, 0xC(r5)
	  li        r6, 0
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  mulhw     r3, r3, r0
	  lwz       r5, 0x8(r31)
	  lbz       r4, 0xC(r5)
	  li        r6, 0x1
	  rlwimi    r4,r6,7,24,24
	  stb       r4, 0xC(r5)
	  srawi     r3, r3, 0x2
	  rlwinm    r4,r3,1,31,31
	  lwz       r6, 0x8(r31)
	  add       r5, r3, r4
	  lis       r4, 0x803D
	  lbz       r3, 0xF1(r6)
	  rlwinm    r5,r5,2,0,29
	  addi      r4, r4, 0x2360
	  add       r4, r4, r5
	  cmplwi    r3, 0
	  lwz       r3, 0x0(r4)
	  ble-      .loc_0x90
	  stw       r3, 0xEC(r6)

	.loc_0x90:
	  lis       r3, 0x6666
	  lwz       r6, 0xC(r31)
	  addi      r3, r3, 0x6667
	  mulhw     r3, r3, r0
	  lbz       r5, 0xC(r6)
	  srawi     r3, r3, 0x2
	  li        r4, 0x1
	  rlwimi    r5,r4,7,24,24
	  rlwinm    r4,r3,1,31,31
	  stb       r5, 0xC(r6)
	  add       r3, r3, r4
	  mulli     r4, r3, 0xA
	  lwz       r6, 0xC(r31)
	  lbz       r3, 0xF1(r6)
	  sub       r0, r0, r4
	  lis       r4, 0x803D
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r4, 0x2360
	  add       r4, r0, r5
	  cmplwi    r3, 0
	  lwz       r0, 0x0(r4)
	  ble-      .loc_0x150
	  stw       r0, 0xEC(r6)
	  b         .loc_0x150

	.loc_0xF0:
	  lwz       r6, 0x4(r31)
	  lis       r3, 0x803D
	  li        r4, 0x1
	  lbz       r5, 0xC(r6)
	  rlwimi    r5,r4,7,24,24
	  rlwinm    r4,r0,2,0,29
	  stb       r5, 0xC(r6)
	  addi      r0, r3, 0x2360
	  add       r3, r0, r4
	  lwz       r4, 0x4(r31)
	  lwz       r3, 0x0(r3)
	  lbz       r0, 0xF1(r4)
	  cmplwi    r0, 0
	  ble-      .loc_0x12C
	  stw       r3, 0xEC(r4)

	.loc_0x12C:
	  lwz       r3, 0x8(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x150:
	  lwz       r0, 0x34(r1)
	  li        r3, 0x1
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
