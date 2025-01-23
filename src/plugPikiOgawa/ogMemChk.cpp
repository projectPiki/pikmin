#include "zen/ogMemChk.h"
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
 * Address:	8018D04C
 * Size:	0009D0
 */
zen::ogScrMemChkMgr::ogScrMemChkMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stmw      r26, 0x88(r1)
	  li        r28, 0
	  addi      r31, r3, 0
	  stb       r28, 0x0(r3)
	  li        r3, 0xF8
	  bl        -0x146068
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x84
	  addi      r26, r29, 0
	  addi      r3, r1, 0x80
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x26594
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x80
	  addi      r3, r26, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x23918
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r29)
	  stb       r28, 0xEC(r29)
	  stw       r28, 0xF0(r29)
	  stw       r28, 0xF4(r29)

	.loc_0x84:
	  stw       r29, 0x24(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x5CC8
	  lwz       r3, 0x24(r31)
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x25B14
	  lwz       r3, 0x24(r31)
	  lis       r4, 0x626C
	  addi      r4, r4, 0x636B
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r31)
	  li        r0, 0xFF
	  li        r3, 0x4C4
	  lwz       r4, 0x28(r31)
	  stb       r0, 0xF0(r4)
	  bl        -0x146120
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xF8
	  li        r4, 0x20
	  li        r5, 0x80
	  li        r6, 0x80
	  bl        0x5C780

	.loc_0xF8:
	  stw       r28, 0xC(r31)
	  li        r28, 0
	  li        r3, 0xF8
	  stw       r28, 0x10(r31)
	  stw       r28, 0x14(r31)
	  bl        -0x146154
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x170
	  addi      r26, r29, 0
	  addi      r3, r1, 0x74
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x264A8
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x74
	  addi      r3, r26, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2382C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r29)
	  stb       r28, 0xEC(r29)
	  stw       r28, 0xF0(r29)
	  stw       r28, 0xF4(r29)

	.loc_0x170:
	  stw       r29, 0x2C(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x5CE0
	  lwz       r3, 0x2C(r31)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x25A28
	  lwz       r27, 0x2C(r31)
	  lis       r28, 0x7368
	  addi      r4, r28, 0x6F6D
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6F74
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x78(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6368
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x80(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6F69
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x84(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6F6B
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x88(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6F73
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x68
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6169
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xAC(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x69
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6965
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB0(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6861
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6963
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB4(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6969
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6563
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB8(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x7566
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8C(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x7369
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x90(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x7878
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x94(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x7361
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x7269
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xEC(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6D65
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6D6F
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xF0(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6272
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6F6D
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xF4(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6B61
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x696D
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xF8(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x696A
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6F6D
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xFC(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6E61
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x696D
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x100(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6669
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x6C65
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x104(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x796E
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x5F77
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x98(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6370
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x736C
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x9C(r31)
	  lis       r3, 0x6162
	  addi      r4, r3, 0x746E
	  lwz       r3, 0x2C(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA4(r31)
	  li        r3, 0x12C
	  bl        -0x1464FC
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x4D0
	  lwz       r4, 0xA4(r31)
	  lfs       f1, -0x4F00(r2)
	  bl        -0xE2F4

	.loc_0x4D0:
	  stw       r28, 0xA0(r31)
	  lis       r3, 0x6D61
	  li        r30, 0
	  lwz       r6, 0xA4(r31)
	  addi      r4, r3, 0x696E
	  li        r5, 0x1
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA8(r31)
	  lis       r3, 0x6375
	  addi      r4, r3, 0x7273
	  lwz       r3, 0x74(r31)
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x78(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x80(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x7C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x84(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x88(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x90(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x94(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xEC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xF0(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xF4(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xF8(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xFC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xFC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x104(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC0(r31)
	  li        r3, 0x12C
	  bl        -0x14667C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x650
	  lwz       r4, 0xC0(r31)
	  lfs       f1, -0x4EFC(r2)
	  bl        -0xE474

	.loc_0x650:
	  stw       r28, 0xBC(r31)
	  li        r3, 0x418
	  bl        -0x1466A0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x670
	  lwz       r4, 0x74(r31)
	  bl        -0xD328

	.loc_0x670:
	  stw       r28, 0x34(r31)
	  li        r3, 0x418
	  bl        -0x1466C0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x690
	  lwz       r4, 0x80(r31)
	  bl        -0xD348

	.loc_0x690:
	  stw       r28, 0x40(r31)
	  li        r3, 0x418
	  bl        -0x1466E0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x6B0
	  lwz       r4, 0x78(r31)
	  bl        -0xD368

	.loc_0x6B0:
	  stw       r28, 0x38(r31)
	  li        r3, 0x418
	  bl        -0x146700
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x6D0
	  lwz       r4, 0x7C(r31)
	  bl        -0xD388

	.loc_0x6D0:
	  stw       r28, 0x3C(r31)
	  li        r3, 0x418
	  bl        -0x146720
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x6F0
	  lwz       r4, 0x84(r31)
	  bl        -0xD3A8

	.loc_0x6F0:
	  stw       r28, 0x44(r31)
	  li        r3, 0x418
	  bl        -0x146740
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x710
	  lwz       r4, 0x88(r31)
	  bl        -0xD3C8

	.loc_0x710:
	  stw       r28, 0x48(r31)
	  li        r3, 0x418
	  bl        -0x146760
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x730
	  lwz       r4, 0x8C(r31)
	  bl        -0xD3E8

	.loc_0x730:
	  stw       r28, 0x4C(r31)
	  li        r3, 0x418
	  bl        -0x146780
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x750
	  lwz       r4, 0x90(r31)
	  bl        -0xD408

	.loc_0x750:
	  stw       r28, 0x50(r31)
	  li        r3, 0x418
	  bl        -0x1467A0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x770
	  lwz       r4, 0x94(r31)
	  bl        -0xD428

	.loc_0x770:
	  stw       r28, 0x54(r31)
	  li        r3, 0x418
	  bl        -0x1467C0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x790
	  lwz       r4, 0xEC(r31)
	  bl        -0xD448

	.loc_0x790:
	  stw       r28, 0x58(r31)
	  li        r3, 0x418
	  bl        -0x1467E0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x7B0
	  lwz       r4, 0xF0(r31)
	  bl        -0xD468

	.loc_0x7B0:
	  stw       r28, 0x5C(r31)
	  li        r3, 0x418
	  bl        -0x146800
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x7D0
	  lwz       r4, 0xF4(r31)
	  bl        -0xD488

	.loc_0x7D0:
	  stw       r28, 0x60(r31)
	  li        r3, 0x418
	  bl        -0x146820
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x7F0
	  lwz       r4, 0xF8(r31)
	  bl        -0xD4A8

	.loc_0x7F0:
	  stw       r28, 0x64(r31)
	  li        r3, 0x418
	  bl        -0x146840
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x810
	  lwz       r4, 0xFC(r31)
	  bl        -0xD4C8

	.loc_0x810:
	  stw       r28, 0x68(r31)
	  li        r3, 0x418
	  bl        -0x146860
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x830
	  lwz       r4, 0x100(r31)
	  bl        -0xD4E8

	.loc_0x830:
	  stw       r28, 0x6C(r31)
	  li        r3, 0x418
	  bl        -0x146880
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x850
	  lwz       r4, 0x104(r31)
	  bl        -0xD508

	.loc_0x850:
	  stw       r28, 0x70(r31)
	  lis       r3, 0x666F
	  li        r0, -0x1
	  lwz       r6, 0x58(r31)
	  addi      r4, r3, 0x6D74
	  li        r5, 0x1
	  stw       r6, 0x30(r31)
	  stw       r0, 0x1C(r31)
	  stw       r0, 0x20(r31)
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  lwz       r3, 0x2C(r31)
	  lis       r4, 0x63
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x7773
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  lwz       r3, 0x2C(r31)
	  lis       r4, 0x7274
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x7279
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  lwz       r3, 0x2C(r31)
	  lis       r4, 0x7365
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x5F63
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r26, r3, 0
	  li        r3, 0xC4
	  bl        -0x146944
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x928
	  lwz       r4, 0x2C(r31)
	  mr        r7, r26
	  lwz       r5, 0xB4(r31)
	  li        r8, 0
	  lwz       r6, 0xB8(r31)
	  li        r9, 0
	  bl        0x8EF4

	.loc_0x928:
	  stw       r27, 0xD4(r31)
	  li        r4, 0
	  li        r3, 0x54
	  lbz       r0, 0xC(r28)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r28)
	  lbz       r0, 0xC(r29)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r29)
	  lbz       r0, 0xC(r30)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r30)
	  lwz       r4, 0xAC(r31)
	  lwz       r0, 0x10C(r4)
	  stw       r0, 0xD8(r31)
	  lwz       r4, 0xB0(r31)
	  lwz       r0, 0x10C(r4)
	  stw       r0, 0xDC(r31)
	  lwz       r0, 0x10C(r28)
	  stw       r0, 0xE0(r31)
	  lwz       r0, 0x10C(r29)
	  stw       r0, 0xE4(r31)
	  lwz       r0, 0x10C(r30)
	  stw       r0, 0xE8(r31)
	  bl        -0x1469D0
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x99C
	  bl        0x5FB8

	.loc_0x99C:
	  stw       r27, 0x18(r31)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        0x2C4
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x2F0
	  mr        r3, r31
	  lmw       r26, 0x88(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_Y_N()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_W_R()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_F_N()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void zen::ogScrMemChkMgr::StartSub()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018DA1C
 * Size:	000258
 */
void zen::ogScrMemChkMgr::StatusCheck()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  lwz       r0, 0xD8(r3)
	  lwz       r3, 0xAC(r3)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0xB
	  beq-      .loc_0xB0
	  bge-      .loc_0xFC
	  cmpwi     r0, 0xA
	  bge-      .loc_0x60
	  b         .loc_0xFC

	.loc_0x60:
	  li        r0, 0xA
	  stw       r0, 0x20(r31)
	  li        r0, 0x1
	  addi      r3, r31, 0
	  stw       r0, 0x1C(r31)
	  lwz       r4, 0x48(r31)
	  bl        .loc_0x258
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  b         .loc_0xFC

	.loc_0xB0:
	  li        r0, 0xB
	  stw       r0, 0x20(r31)
	  li        r0, 0x1
	  addi      r3, r31, 0
	  stw       r0, 0x1C(r31)
	  lwz       r4, 0x44(r31)
	  bl        .loc_0x258
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)

	.loc_0xFC:
	  lwz       r0, 0x1C(r31)
	  cmplwi    r0, 0x12
	  bgt-      .loc_0x220
	  lis       r3, 0x802D
	  addi      r3, r3, 0x5CF8
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  mr        r3, r31
	  lwz       r4, 0x58(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x6C(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x64(r31)
	  bl        .loc_0x258
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x68(r31)
	  bl        .loc_0x258
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x5C(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x60(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x70(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x4C(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x50(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C
	  mr        r3, r31
	  lwz       r4, 0x54(r31)
	  bl        .loc_0x258
	  b         .loc_0x23C

	.loc_0x220:
	  lwz       r5, 0x30(r31)
	  li        r4, 0
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r5)

	.loc_0x23C:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r0, 0xBC(r1)
	  lwz       r31, 0xB4(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr

	.loc_0x258:
	*/
}

/*
 * --INFO--
 * Address:	8018DC74
 * Size:	000044
 */
void zen::ogScrMemChkMgr::setPCtex(zen::TypingTextMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r7, 0x30(r3)
	  lwz       r5, 0x8(r7)
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r5)
	  stw       r6, 0x0(r7)
	  stw       r4, 0x30(r3)
	  lwz       r3, 0x30(r3)
	  bl        -0xD884
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018DCB8
 * Size:	000038
 */
void zen::ogScrMemChkMgr::DispYesNo(bool)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x20
	  lwz       r3, 0x98(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr

	.loc_0x20:
	  lwz       r3, 0x98(r3)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018DCF0
 * Size:	000038
 */
void zen::ogScrMemChkMgr::DispAcup(bool)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x20
	  lwz       r3, 0x9C(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr

	.loc_0x20:
	  lwz       r3, 0x9C(r3)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::ogScrMemChkMgr::MakeDefFileStart()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void zen::ogScrMemChkMgr::RepairFileStart()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018DD28
 * Size:	000224
 */
void zen::ogScrMemChkMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  li        r29, 0
	  stw       r28, 0x60(r1)
	  stb       r29, 0x0(r3)
	  stw       r29, 0x1C(r3)
	  bl        -0xF504
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x44
	  li        r0, 0x8
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0x44:
	  lis       r3, 0x803A
	  subi      r30, r3, 0x2848
	  addi      r28, r30, 0x24
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0x119E90
	  cmpwi     r3, -0x2
	  bne-      .loc_0x70
	  li        r0, 0x9
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0x70:
	  cmpwi     r3, -0x5
	  bne-      .loc_0x84
	  li        r0, 0xA
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0x84:
	  cmpwi     r3, -0x4
	  bne-      .loc_0x98
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0x98:
	  cmpwi     r3, -0x3
	  bne-      .loc_0xAC
	  li        r0, 0xC
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0xAC:
	  cmpwi     r3, -0x6
	  bne-      .loc_0xC0
	  li        r0, 0xD
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0xC0:
	  cmpwi     r3, -0x8
	  bne-      .loc_0xD4
	  li        r0, 0xE
	  stw       r0, 0x1C(r31)
	  b         .loc_0x15C

	.loc_0xD4:
	  lwz       r0, 0x5C(r30)
	  cmpwi     r0, 0
	  bge-      .loc_0xFC
	  lwz       r3, 0x18(r31)
	  bl        0x5EF0
	  li        r0, 0xF
	  stw       r0, 0x1C(r31)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0x15C

	.loc_0xFC:
	  mr        r3, r28
	  bl        -0x1179CC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15C
	  mr        r3, r28
	  bl        -0x11793C
	  li        r0, 0x10
	  stw       r0, 0x1C(r31)
	  lwz       r5, 0x30(r31)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r29, 0x0(r5)
	  stw       r4, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xDA48
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r3, 0x98(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x15C:
	  lwz       r4, 0x30(r31)
	  li        r30, 0
	  lwz       r3, 0x8(r4)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r30, 0x0(r4)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xC0(r31)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r3, 0xBC(r31)
	  bl        -0xE860
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x98(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x8D30
	  li        r0, 0x3
	  sth       r0, 0x8(r31)
	  mr        r3, r31
	  bl        -0x50C
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018DF4C
 * Size:	000190
 */
void zen::ogScrMemChkMgr::DebugStart(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x68(r1)
	  stb       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  blt-      .loc_0x170
	  cmpwi     r4, 0x9
	  bgt-      .loc_0x170
	  addi      r0, r4, 0x7
	  cmpwi     r4, 0x8
	  stw       r0, 0x1C(r31)
	  bne-      .loc_0x60
	  lwz       r3, 0x18(r31)
	  bl        0x5D68
	  li        r0, 0xF
	  stw       r0, 0x1C(r31)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xC4

	.loc_0x60:
	  cmpwi     r4, 0x9
	  bne-      .loc_0xC4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x24
	  bl        -0x117AC4
	  li        r0, 0x10
	  stw       r0, 0x1C(r31)
	  li        r30, 0
	  lwz       r5, 0x30(r31)
	  lwz       r4, 0x4C(r31)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r30, 0x0(r5)
	  stw       r4, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xDBD4
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r3, 0x98(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0xC4:
	  lwz       r4, 0x30(r31)
	  li        r30, 0
	  lwz       r3, 0x8(r4)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r30, 0x0(r4)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xC0(r31)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r3, 0xBC(r31)
	  bl        -0xE9EC
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x98(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x8BA4
	  li        r0, 0x3
	  sth       r0, 0x8(r31)
	  mr        r3, r31
	  bl        -0x698
	  b         .loc_0x178

	.loc_0x170:
	  mr        r3, r31
	  bl        -0x398

	.loc_0x178:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void zen::ogScrMemChkMgr::FormatEffectStart()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool zen::ogScrMemChkMgr::checkTypingAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::ogScrMemChkMgr::checkErrNitaku(zen::ogNitakuMgr*, Controller*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::ogScrMemChkMgr::setNoCard()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8018E0DC
 * Size:	000EC4
 */
zen::ogScrMemChkMgr::MemChkStatus zen::ogScrMemChkMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x378(r1)
	  stw       r31, 0x374(r1)
	  mr        r31, r3
	  stw       r30, 0x370(r1)
	  stw       r29, 0x36C(r1)
	  stw       r28, 0x368(r1)
	  addi      r28, r4, 0
	  lwz       r3, 0x1C(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x34
	  b         .loc_0xEA4

	.loc_0x34:
	  cmpwi     r3, 0
	  bne-      .loc_0x4C
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0x1C(r31)
	  b         .loc_0xEA4

	.loc_0x4C:
	  cmpwi     r3, 0x13
	  blt-      .loc_0x64
	  li        r0, -0x1
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0x1C(r31)
	  b         .loc_0xEA4

	.loc_0x64:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xC8(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC8(r31)
	  bl        -0xF904
	  rlwinm.   r0,r3,0,24,31
	  addi      r29, r3, 0
	  bne-      .loc_0x168
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x168
	  li        r0, 0x8
	  stw       r0, 0x1C(r31)
	  mr        r3, r31
	  bl        0xF34
	  lwz       r3, 0x98(r31)
	  li        r30, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA4(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x8A60
	  lwz       r5, 0x30(r31)
	  lwz       r4, 0x58(r31)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r30, 0x0(r5)
	  stw       r4, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xDDF0
	  lwz       r3, 0x10(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x150:
	  lwz       r3, 0x14(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x168
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x168:
	  lwz       r0, 0x1C(r31)
	  cmplwi    r0, 0x12
	  bgt-      .loc_0xE28
	  lis       r3, 0x802D
	  addi      r3, r3, 0x5D44
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  rlwinm.   r0,r29,0,24,31
	  beq-      .loc_0x1A4
	  mr        r3, r31
	  bl        -0x54C
	  lwz       r3, 0x1C(r31)
	  b         .loc_0xEA4

	.loc_0x1A4:
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x1C0
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x1C0:
	  li        r0, 0

	.loc_0x1C4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x210
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x8B98
	  cmpwi     r3, 0x6
	  bne-      .loc_0x1FC
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x1FC:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x210:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x274
	  li        r0, 0x1
	  b         .loc_0x278

	.loc_0x274:
	  li        r0, 0

	.loc_0x278:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2C4
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x8AE4
	  cmpwi     r3, 0x6
	  bne-      .loc_0x2B0
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x2B0:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x2C4:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x328
	  li        r0, 0x1
	  b         .loc_0x32C

	.loc_0x328:
	  li        r0, 0

	.loc_0x32C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x378
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x8A30
	  cmpwi     r3, 0x6
	  bne-      .loc_0x364
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x364:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x378:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x3DC
	  li        r0, 0x1
	  b         .loc_0x3E0

	.loc_0x3DC:
	  li        r0, 0

	.loc_0x3E0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x42C
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x897C
	  cmpwi     r3, 0x6
	  bne-      .loc_0x418
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x418:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x42C:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xD4(r31)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x460
	  li        r0, 0x1
	  b         .loc_0x464

	.loc_0x460:
	  li        r0, 0

	.loc_0x464:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x4B0
	  lwz       r5, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r4,7,24,24
	  addi      r4, r28, 0
	  stb       r0, 0xC(r5)
	  bl        0x88F8
	  cmpwi     r3, 0x6
	  bne-      .loc_0x49C
	  li        r0, 0x13
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x49C:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  li        r0, 0x14
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x4B0:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x4E0
	  li        r0, 0x1
	  b         .loc_0x4E4

	.loc_0x4E0:
	  li        r0, 0

	.loc_0x4E4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x544
	  li        r0, 0x2
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE0(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x8644
	  lwz       r3, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28

	.loc_0x544:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r3, 0xD4(r31)
	  mr        r4, r28
	  bl        0x8818
	  cmpwi     r3, 0x4
	  blt-      .loc_0xE28
	  cmpwi     r3, 0x5
	  bne-      .loc_0x5B8
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x34(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE25C
	  li        r0, 0x3
	  stw       r0, 0x1C(r31)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28

	.loc_0x5B8:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC4(r31)
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0xA
	  bne-      .loc_0x60C
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x64(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE2B0
	  li        r0, 0xA
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0xD4(r31)
	  bl        0x8568
	  b         .loc_0x65C

	.loc_0x60C:
	  cmpwi     r0, 0xB
	  bne-      .loc_0x654
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x68(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE2F8
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0xD4(r31)
	  bl        0x8520
	  b         .loc_0x65C

	.loc_0x654:
	  li        r0, 0x1
	  stw       r0, 0x1C(r31)

	.loc_0x65C:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x680
	  li        r0, 0x1
	  b         .loc_0x684

	.loc_0x680:
	  li        r0, 0

	.loc_0x684:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x6E4
	  li        r0, 0x4
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x84A4
	  lwz       r3, 0x98(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28

	.loc_0x6E4:
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xE28
	  lwz       r3, 0xD4(r31)
	  mr        r4, r28
	  bl        0x8678
	  cmpwi     r3, 0x4
	  blt-      .loc_0xE28
	  cmpwi     r3, 0x5
	  bne-      .loc_0x86C
	  lwz       r5, 0x30(r31)
	  li        r28, 0
	  lwz       r4, 0x40(r31)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r28, 0x0(r5)
	  stw       r4, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE3FC
	  li        r0, 0x5
	  stw       r0, 0x1C(r31)
	  lis       r8, 0x4330
	  addi      r5, r1, 0x334
	  lwz       r3, 0x98(r31)
	  li        r4, 0x27
	  li        r6, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  li        r7, 0
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r9, 0xA8(r31)
	  stfs      f0, 0x33C(r1)
	  stfs      f0, 0x338(r1)
	  stfs      f0, 0x334(r1)
	  lfs       f1, 0xD78(r13)
	  lfs       f0, 0xD7C(r13)
	  stfs      f1, 0x334(r1)
	  stfs      f0, 0x338(r1)
	  lfs       f0, 0xD80(r13)
	  stfs      f0, 0x33C(r1)
	  lha       r10, 0x18(r9)
	  lha       r3, 0x1C(r9)
	  xoris     r0, r10, 0x8000
	  lfd       f4, -0x4EF0(r2)
	  stw       r0, 0x364(r1)
	  sub       r3, r3, r10
	  xoris     r0, r3, 0x8000
	  lfs       f3, -0x4EFC(r2)
	  stw       r0, 0x35C(r1)
	  lfs       f2, -0x4EF4(r2)
	  stw       r8, 0x358(r1)
	  lfd       f0, 0x358(r1)
	  stw       r8, 0x360(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0x360(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0x334(r1)
	  lha       r10, 0x1A(r9)
	  lha       r3, 0x1E(r9)
	  xoris     r0, r10, 0x8000
	  stw       r0, 0x354(r1)
	  sub       r3, r3, r10
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x34C(r1)
	  stw       r8, 0x348(r1)
	  lfd       f0, 0x348(r1)
	  stw       r8, 0x350(r1)
	  fsubs     f0, f0, f4
	  lfd       f1, 0x350(r1)
	  fsubs     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x338(r1)
	  lwz       r3, 0xC(r31)
	  bl        0x5B21C
	  stw       r3, 0x10(r31)
	  addi      r5, r1, 0x334
	  li        r4, 0x28
	  lwz       r3, 0xC(r31)
	  li        r6, 0
	  li        r7, 0
	  bl        0x5B200
	  stw       r3, 0x14(r31)
	  b         .loc_0xE28

	.loc_0x86C:
	  lwz       r0, 0x20(r31)
	  cmpwi     r0, 0xA
	  bne-      .loc_0x8A8
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x48(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE55C
	  b         .loc_0x8DC

	.loc_0x8A8:
	  cmpwi     r0, 0xB
	  bne-      .loc_0x8DC
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x44(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE594

	.loc_0x8DC:
	  lfs       f0, -0x4EF8(r2)
	  li        r0, 0x1
	  stfs      f0, 0xC8(r31)
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x92C
	  b         .loc_0x930

	.loc_0x92C:
	  mr        r5, r4

	.loc_0x930:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lfs       f1, 0xC8(r31)
	  lfs       f0, -0x4EE8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE28
	  lwz       r4, 0x10(r31)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x80(r4)
	  addi      r3, r3, 0x24
	  li        r28, 0x1
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)
	  lwz       r4, 0x14(r31)
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)
	  bl        -0x118E38
	  cmpwi     r3, 0
	  beq-      .loc_0x988
	  li        r28, 0

	.loc_0x988:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x9E4
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x38(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE674
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF434
	  li        r0, 0x6
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0x9E4:
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x3C(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE6C8
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF488
	  li        r0, 0x7
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r5, 0
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF3F8
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE97E8
	  lfs       f0, -0x4EF8(r2)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stfs      f0, 0xC4(r31)
	  lwz       r0, 0x5C(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xABC
	  lwz       r3, 0x18(r31)
	  bl        0x517C
	  li        r0, 0xF
	  stw       r0, 0x1C(r31)
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28

	.loc_0xABC:
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0xA0(r31)
	  bl        -0xF460
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE9850
	  lfs       f0, -0x4EF8(r2)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  stfs      f0, 0xC4(r31)
	  stw       r0, 0x1C(r31)
	  bl        -0xEB4
	  b         .loc_0xE28
	  lwz       r3, 0x18(r31)
	  mr        r4, r28
	  bl        0x51FC
	  cmpwi     r3, 0x4
	  bne-      .loc_0xB28
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28

	.loc_0xB28:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xE28
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x68(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE814
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xD8(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xDC(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x7FD4
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xBE8
	  b         .loc_0xBEC

	.loc_0xBE8:
	  mr        r5, r4

	.loc_0xBEC:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lfs       f1, 0xC8(r31)
	  lfs       f0, -0x4EE4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE28
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r3, r3, 0x24
	  bl        -0x1182C4
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0xC5C
	  li        r0, 0x11
	  stw       r0, 0x1C(r31)
	  li        r4, 0
	  lwz       r6, 0x30(r31)
	  lwz       r5, 0x50(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE910
	  b         .loc_0xC90

	.loc_0xC5C:
	  li        r0, 0x12
	  stw       r0, 0x1C(r31)
	  li        r4, 0
	  lwz       r6, 0x30(r31)
	  lwz       r5, 0x54(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xE948

	.loc_0xC90:
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC8(r31)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF6FC
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xCE0
	  b         .loc_0xCE4

	.loc_0xCE0:
	  mr        r5, r4

	.loc_0xCE4:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF698
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE9A88
	  li        r0, 0x15
	  stw       r0, 0x1C(r31)
	  b         .loc_0xE28
	  lwz       r3, 0x98(r31)
	  li        r4, 0
	  li        r5, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xD6C
	  b         .loc_0xD70

	.loc_0xD6C:
	  mr        r5, r4

	.loc_0xD70:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0xE28
	  lwz       r3, 0xA4(r31)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r31)
	  bl        -0xF724
	  lis       r3, 0x100
	  lwz       r4, 0x28(r28)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xE28
	  li        r3, 0x111
	  bl        -0xE9B14
	  lwz       r6, 0x30(r31)
	  li        r4, 0
	  lwz       r5, 0x68(r31)
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  stw       r4, 0x0(r6)
	  stw       r5, 0x30(r31)
	  lwz       r3, 0x30(r31)
	  bl        -0xEA94
	  li        r0, 0xB
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xAC(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB0(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE4(r31)
	  lwz       r3, 0xB4(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r0, 0xE8(r31)
	  lwz       r3, 0xB8(r31)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0xD4(r31)
	  bl        0x7D54
	  lfs       f0, -0x4EF8(r2)
	  stfs      f0, 0xC4(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0xE28:
	  mr        r3, r31
	  bl        0x1A8
	  lwz       r3, 0x1C(r31)
	  cmpwi     r3, 0x13
	  blt-      .loc_0xE40
	  b         .loc_0xEA4

	.loc_0xE40:
	  lwz       r3, 0xC(r31)
	  bl        0x5AC68
	  lwz       r3, 0x2C(r31)
	  bl        0x23C28
	  lwz       r3, 0xBC(r31)
	  bl        -0xF7E8
	  lwz       r3, 0x30(r31)
	  bl        -0xE59C
	  lwz       r4, 0x30(r31)
	  lwz       r3, 0xC0(r31)
	  lwz       r7, 0x8(r4)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x116(r7)
	  lwz       r12, 0x14(r12)
	  subi      r5, r4, 0x18
	  lha       r0, 0x1A(r7)
	  lha       r6, 0x114(r7)
	  mtlr      r12
	  lha       r4, 0x18(r7)
	  add       r5, r0, r5
	  add       r4, r4, r6
	  blrl
	  lwz       r3, 0x24(r31)
	  bl        0x23BD8
	  lwz       r3, 0x1C(r31)

	.loc_0xEA4:
	  lwz       r0, 0x37C(r1)
	  lwz       r31, 0x374(r1)
	  lwz       r30, 0x370(r1)
	  lwz       r29, 0x36C(r1)
	  lwz       r28, 0x368(r1)
	  addi      r1, r1, 0x378
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018EFA0
 * Size:	000110
 */
void zen::ogScrMemChkMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xF8(r1)
	  mr        r30, r3
	  lwz       r0, 0x1C(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF8
	  cmpwi     r0, 0x13
	  bge-      .loc_0xF8
	  lha       r3, 0x8(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x48
	  subi      r0, r3, 0x1
	  sth       r0, 0x8(r30)
	  b         .loc_0xF8

	.loc_0x48:
	  lfs       f1, -0x4EE0(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x4F00(r2)
	  li        r4, 0
	  lfs       f3, -0x4EDC(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x21188
	  addi      r3, r1, 0x10
	  bl        0x21290
	  lwz       r3, 0x24(r30)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x23EB0
	  lwz       r3, 0x1C(r30)
	  subi      r0, r3, 0x8
	  cmplwi    r0, 0xD
	  bgt-      .loc_0xC0
	  lis       r3, 0x802D
	  addi      r3, r3, 0x5D90
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x18(r30)
	  mr        r4, r31
	  bl        0x50E4
	  b         .loc_0xE0

	.loc_0xC0:
	  lwz       r3, 0x2C(r30)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x23E64
	  lwz       r3, 0xC(r30)
	  mr        r4, r31
	  bl        0x5AB30

	.loc_0xE0:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0xF8:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018F0B0
 * Size:	000144
 */
void zen::ogScrMemChkMgr::setErrorMessage()
{
	/*
	.loc_0x0:
	  lwz       r4, 0xEC(r3)
	  li        r5, 0
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x100(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0xF8(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0xFC(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0xF0(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0xF4(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x104(r3)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x1C(r3)
	  subi      r0, r4, 0x8
	  cmplwi    r0, 0x6
	  bgtlr-
	  lis       r4, 0x802D
	  addi      r4, r4, 0x5DC8
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0xEC(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	  lwz       r3, 0x100(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	  lwz       r3, 0xF8(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	  lwz       r3, 0xFC(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	  lwz       r3, 0xF0(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	  lwz       r3, 0xF4(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	  lwz       r3, 0x104(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  blr
	*/
}
