#include "types.h"

/*
 * --INFO--
 * Address:	80019760
 * Size:	000038
 */
void Jac_Delete_CurrentBgmWave(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xBF0
	  li        r3, 0x1
	  bl        -0xBF8
	  lwz       r3, 0x2D08(r13)
	  li        r4, 0
	  bl        -0xCFA4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800197A0
 * Size:	000094
 */
void __Loaded(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  lis       r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  rlwinm    r4,r3,0,0,15
	  rlwinm    r3,r3,0,16,31
	  cmpw      r4, r0
	  stw       r3, 0x8(r1)
	  beq-      .loc_0x64
	  bge-      .loc_0x3C
	  cmpwi     r4, 0
	  beq-      .loc_0x58
	  b         .loc_0x84

	.loc_0x3C:
	  lis       r0, 0x2
	  cmpw      r4, r0
	  beq-      .loc_0x4C
	  b         .loc_0x84

	.loc_0x4C:
	  li        r0, 0x1
	  stw       r0, 0x2D14(r13)
	  b         .loc_0x84

	.loc_0x58:
	  li        r0, 0
	  stw       r0, 0x2D10(r13)
	  b         .loc_0x84

	.loc_0x64:
	  lwz       r3, 0x2D08(r13)
	  lwz       r0, 0x8(r1)
	  cmplw     r3, r0
	  bne-      .loc_0x84
	  bl        -0xBE34
	  li        r3, 0
	  lwz       r4, 0x2D08(r13)
	  bl        -0xBA0

	.loc_0x84:
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019840
 * Size:	000008
 */
void Jac_GetCurrentScene(void)
{
	/*
	.loc_0x0:
	  lwz       r3, -0x7F20(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019860
 * Size:	000008
 */
void Jac_TellChgMode(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2D18(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019880
 * Size:	00045C
 */
void Jac_SceneSetup(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  addi      r31, r5, 0x6248
	  lbz       r0, 0x2D20(r13)
	  stw       r3, 0x8(r1)
	  extsb.    r0, r0
	  stw       r4, 0xC(r1)
	  bne-      .loc_0x38
	  li        r0, 0x1
	  stw       r0, 0x2D1C(r13)
	  stb       r0, 0x2D20(r13)

	.loc_0x38:
	  li        r27, 0
	  li        r3, 0
	  bl        -0x2F00
	  lwz       r0, 0x2D14(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x74
	  lwz       r3, 0x8(r1)
	  b         .loc_0x68

	.loc_0x58:
	  cmplwi    r3, 0x1
	  beq-      .loc_0x74
	  cmplwi    r3, 0
	  beq-      .loc_0x74

	.loc_0x68:
	  lwz       r0, 0x2D14(r13)
	  cmpwi     r0, 0
	  beq+      .loc_0x58

	.loc_0x74:
	  lwz       r30, 0x8(r1)
	  cmplwi    r30, 0xA
	  bne-      .loc_0x88
	  li        r0, 0x1
	  stw       r0, 0x2D18(r13)

	.loc_0x88:
	  cmplwi    r30, 0x3
	  bne-      .loc_0xA8
	  li        r3, 0xD
	  li        r4, 0
	  bl        -0xD138
	  bl        0x7C4
	  li        r0, 0
	  stw       r0, 0x2D18(r13)

	.loc_0xA8:
	  cmplwi    r30, 0x1
	  bne-      .loc_0xB8
	  li        r0, 0
	  stw       r0, 0x2D18(r13)

	.loc_0xB8:
	  lwz       r0, -0x7F20(r13)
	  cmplwi    r0, 0x5
	  beq-      .loc_0xCC
	  cmplwi    r30, 0x5
	  bne-      .loc_0xEC

	.loc_0xCC:
	  bl        -0x190C
	  li        r3, 0
	  bl        -0x1214
	  bl        -0x1198
	  li        r3, 0x8
	  bl        -0x12E0
	  bl        0x189C
	  bl        0x1438

	.loc_0xEC:
	  li        r3, 0xF
	  bl        -0x2DD0
	  li        r3, 0x7
	  bl        -0x2DD8
	  li        r3, 0x10
	  bl        -0x2A40
	  li        r3, 0x21
	  bl        -0x2A48
	  li        r3, 0x23
	  bl        -0x2A50
	  bl        -0x1354
	  lwz       r0, -0x7F20(r13)
	  cmplwi    r0, 0x6
	  bne-      .loc_0x128
	  bl        0x11FC

	.loc_0x128:
	  lwz       r3, -0x7F20(r13)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x140
	  li        r3, 0
	  b         .loc_0x148

	.loc_0x140:
	  rlwinm    r0,r3,2,0,29
	  lwzx      r3, r31, r0

	.loc_0x148:
	  lwz       r29, 0xC(r1)
	  cmplwi    r30, 0x6
	  stw       r30, -0x7F20(r13)
	  rlwinm    r0,r30,2,0,29
	  stw       r29, -0x7F1C(r13)
	  lwzx      r28, r31, r0
	  bne-      .loc_0x180
	  lwz       r0, 0x2D18(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x174
	  li        r28, 0x14

	.loc_0x174:
	  cmplwi    r29, 0x1
	  bne-      .loc_0x180
	  li        r28, 0x15

	.loc_0x180:
	  lwz       r0, 0x2D08(r13)
	  cmplw     r0, r28
	  beq-      .loc_0x1F8
	  li        r26, 0x1
	  li        r3, 0
	  bl        -0xE94
	  li        r3, 0x1
	  bl        -0xE9C
	  cmplwi    r28, 0x1
	  li        r25, 0
	  bne-      .loc_0x1C8
	  rlwinm    r0,r29,2,0,29
	  lwz       r4, 0x2D08(r13)
	  add       r3, r31, r0
	  lwz       r0, 0x70(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x1C8
	  li        r26, 0

	.loc_0x1C8:
	  lwz       r3, 0x2D08(r13)
	  cmplwi    r3, 0
	  bne-      .loc_0x1D8
	  li        r26, 0

	.loc_0x1D8:
	  cmplwi    r28, 0
	  bne-      .loc_0x1E4
	  li        r26, 0

	.loc_0x1E4:
	  cmpwi     r26, 0
	  beq-      .loc_0x20C
	  li        r4, 0
	  bl        -0xD290
	  b         .loc_0x20C

	.loc_0x1F8:
	  cmplw     r28, r3
	  bne-      .loc_0x208
	  li        r25, 0x1
	  b         .loc_0x20C

	.loc_0x208:
	  li        r25, 0

	.loc_0x20C:
	  cmpwi     r28, 0x1
	  li        r26, 0
	  beq-      .loc_0x228
	  bge-      .loc_0x250
	  cmpwi     r28, 0
	  bge-      .loc_0x2C4
	  b         .loc_0x250

	.loc_0x228:
	  rlwinm    r0,r29,2,0,29
	  cmplwi    r29, 0
	  add       r3, r31, r0
	  lwz       r28, 0x70(r3)
	  beq-      .loc_0x240
	  li        r26, 0x1

	.loc_0x240:
	  lis       r3, 0x2
	  bl        -0x9464
	  li        r4, 0x1
	  bl        -0x85EC

	.loc_0x250:
	  cmpwi     r25, 0x1
	  beq-      .loc_0x2C4
	  lwz       r0, 0x2D0C(r13)
	  cmplw     r0, r28
	  beq-      .loc_0x2A8
	  mr        r3, r28
	  bl        -0xF08
	  bl        -0xC10C
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0xD418
	  cmpwi     r26, 0
	  stw       r28, 0x2D0C(r13)
	  bne-      .loc_0x2A0
	  lis       r4, 0x8002
	  addis     r3, r28, 0x1
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11B98
	  b         .loc_0x2C4

	.loc_0x2A0:
	  li        r27, 0x1
	  b         .loc_0x2C4

	.loc_0x2A8:
	  lwz       r0, 0x2D10(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x2A8
	  bl        -0xC154
	  li        r3, 0
	  addi      r4, r28, 0
	  bl        -0xEC0

	.loc_0x2C4:
	  cmplwi    r28, 0
	  beq-      .loc_0x2D0
	  stw       r28, 0x2D08(r13)

	.loc_0x2D0:
	  cmpwi     r26, 0
	  beq-      .loc_0x348
	  cmplwi    r29, 0x4
	  bne-      .loc_0x308
	  li        r3, 0xB
	  li        r4, 0
	  bl        -0xD388
	  li        r3, 0x10
	  li        r4, 0
	  bl        -0xD494
	  li        r3, 0x1
	  li        r4, 0x10
	  bl        -0xF00
	  b         .loc_0x32C

	.loc_0x308:
	  li        r3, 0x10
	  li        r4, 0
	  bl        -0xD3B0
	  li        r3, 0xB
	  li        r4, 0
	  bl        -0xD4BC
	  li        r3, 0x1
	  li        r4, 0xB
	  bl        -0xF28

	.loc_0x32C:
	  cmpwi     r27, 0
	  beq-      .loc_0x348
	  lis       r4, 0x8002
	  addis     r3, r28, 0x1
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11C44

	.loc_0x348:
	  lwz       r0, -0x7F20(r13)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x3C4
	  lwz       r0, 0x2D1C(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3C4
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x2D1C(r13)
	  li        r4, 0x1
	  bl        -0xD4D0
	  li        r3, 0
	  li        r4, 0x2
	  bl        -0xD4DC
	  li        r3, 0
	  li        r4, 0x3
	  bl        -0xD4E8
	  li        r3, 0xE
	  li        r4, 0
	  bl        -0xD534
	  li        r3, 0xF
	  li        r4, 0
	  bl        -0xD540
	  li        r3, 0x2
	  li        r4, 0
	  bl        -0xD54C
	  lis       r4, 0x8002
	  lis       r3, 0x2
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11CC0

	.loc_0x3C4:
	  cmplwi    r30, 0
	  bne-      .loc_0x440

	.loc_0x3CC:
	  bl        -0x2AAC
	  cmpwi     r3, 0
	  beq+      .loc_0x3CC
	  bl        0x1E3760
	  rlwinm    r4,r3,30,2,31
	  rlwinm    r0,r3,30,27,31
	  cmplwi    r0, 0x1F
	  bne-      .loc_0x418
	  rlwinm    r0,r4,0,26,31
	  cmplwi    r0, 0x3F
	  bne-      .loc_0x408
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FEB
	  bl        -0x18E0
	  b         .loc_0x440

	.loc_0x408:
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FEA
	  bl        -0x18F0
	  b         .loc_0x440

	.loc_0x418:
	  rlwinm    r0,r4,0,25,31
	  cmplwi    r0, 0x7E
	  bne-      .loc_0x434
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FE9
	  bl        -0x190C
	  b         .loc_0x440

	.loc_0x434:
	  lis       r3, 0x1
	  subi      r3, r3, 0x7FF4
	  bl        -0x191C

	.loc_0x440:
	  li        r3, 0x1
	  bl        -0x3304
	  lmw       r25, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019CE0
 * Size:	0000FC
 */
void Jac_SceneExit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  addi      r28, r3, 0
	  lis       r3, 0x8022
	  addi      r29, r4, 0
	  addi      r31, r3, 0x6248
	  lwz       r0, -0x7F20(r13)
	  cmplw     r0, r28
	  beq-      .loc_0xE8
	  li        r3, 0x2
	  bl        -0x3350
	  lwz       r0, -0x7F20(r13)
	  li        r3, 0
	  rlwinm    r0,r0,2,0,29
	  add       r4, r31, r0
	  lwz       r0, 0x38(r4)
	  stw       r0, 0x18(r1)
	  lwz       r30, 0x18(r1)
	  mr        r4, r30
	  bl        -0x11F4
	  li        r3, 0x1
	  addi      r4, r30, 0
	  bl        -0x1200
	  rlwinm    r0,r28,2,0,29
	  lwzx      r0, r31, r0
	  cmpwi     r0, 0x1
	  mr        r30, r0
	  beq-      .loc_0x88
	  bge-      .loc_0x94
	  cmpwi     r0, 0
	  bge-      .loc_0xE0
	  b         .loc_0x94

	.loc_0x88:
	  rlwinm    r0,r29,2,0,29
	  add       r3, r31, r0
	  lwz       r30, 0x70(r3)

	.loc_0x94:
	  lwz       r0, 0x2D10(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC

	.loc_0xA0:
	  lwz       r0, 0x2D10(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0xA0

	.loc_0xAC:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0xD6B4
	  mr        r3, r30
	  bl        -0x11BC
	  lis       r4, 0x8002
	  addi      r3, r30, 0
	  subi      r5, r4, 0x6860
	  li        r4, 0
	  bl        -0x11E30
	  li        r0, 0x1
	  stw       r30, 0x2D0C(r13)
	  stw       r0, 0x2D10(r13)

	.loc_0xE0:
	  li        r3, 0x3
	  bl        -0x3404

	.loc_0xE8:
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019DE0
 * Size:	00000C
 */
void Jac_SetStreamLevel(void)
{
	/*
	.loc_0x0:
	  sth       r3, -0x7F14(r13)
	  sth       r4, -0x7F12(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019E00
 * Size:	000064
 */
void Jac_UpdateStreamLevel(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x3B50
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x5
	  bne-      .loc_0x44
	  li        r3, 0
	  li        r4, 0x7FFF
	  li        r5, 0x7FFF
	  bl        0x38D4
	  lhz       r4, -0x7F14(r13)
	  li        r3, 0
	  lhz       r5, -0x7F12(r13)
	  bl        0x3904
	  b         .loc_0x54

	.loc_0x44:
	  lhz       r4, -0x7F14(r13)
	  li        r3, 0
	  addi      r5, r4, 0
	  bl        0x38B0

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019E80
 * Size:	00007C
 */
void MovieSync(u32, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x94
	  cmpwi     r31, -0x1
	  bne-      .loc_0x38
	  li        r3, 0x1
	  li        r0, 0
	  stw       r3, 0x2D28(r13)
	  li        r3, 0
	  stw       r0, 0x2D24(r13)
	  b         .loc_0x68

	.loc_0x38:
	  lwz       r0, 0x2D24(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x54
	  li        r0, 0
	  li        r3, -0x1
	  stw       r0, 0x2D24(r13)
	  b         .loc_0x68

	.loc_0x54:
	  cmpwi     r31, 0
	  bne-      .loc_0x64
	  li        r0, 0x1
	  stw       r0, 0x2D28(r13)

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019F00
 * Size:	000028
 */
void Jac_InitStreamSystem(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8002
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x6180
	  stwu      r1, -0x8(r1)
	  bl        0x2E0C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019F40
 * Size:	000038
 */
void Jac_StopDemoSound(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  li        r3, 0
	  stwu      r1, -0x8(r1)
	  bl        0x348C
	  cmpwi     r3, 0x1
	  bne-      .loc_0x28
	  li        r0, 0x1
	  stw       r0, 0x2D24(r13)

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80019F80
 * Size:	000098
 */
void Jac_PrepareDemoSound(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r3, 0x8(r1)
	  li        r3, 0
	  lwz       r31, 0x8(r1)
	  mr        r4, r31
	  bl        0x3440
	  cmpwi     r3, 0x1
	  bne-      .loc_0x48
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x2D28(r13)
	  bl        -0x78

	.loc_0x3C:
	  lwz       r0, 0x2D28(r13)
	  cmplwi    r0, 0
	  beq+      .loc_0x3C

	.loc_0x48:
	  lis       r3, 0x8022
	  rlwinm    r4,r31,5,0,26
	  addi      r0, r3, 0x62CC
	  addi      r3, r1, 0x1C
	  add       r4, r0, r4
	  bl        -0x12A9C
	  addi      r4, r31, 0
	  addi      r5, r1, 0x1C
	  li        r3, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  bl        0x2148
	  bl        -0x1FC
	  stw       r31, -0x7F18(r13)
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001A020
 * Size:	0000A4
 */
void Jac_StartDemoSound(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lwz       r0, -0x7F18(r13)
	  cmplw     r0, r31
	  beq-      .loc_0x50
	  li        r3, 0
	  addi      r4, r31, 0
	  bl        0x3398
	  cmpwi     r3, 0x1
	  bne-      .loc_0x50
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x2D28(r13)
	  bl        -0x120

	.loc_0x44:
	  lwz       r0, 0x2D28(r13)
	  cmplwi    r0, 0
	  beq+      .loc_0x44

	.loc_0x50:
	  li        r0, -0x1
	  addi      r4, r31, 0
	  stw       r0, -0x7F18(r13)
	  li        r3, 0
	  bl        0x3300
	  cmpwi     r3, 0
	  bne-      .loc_0x74
	  mr        r3, r31
	  bl        -0x110

	.loc_0x74:
	  lhz       r4, -0x7F14(r13)
	  li        r3, 0
	  lfs       f1, -0x7E20(r2)
	  mr        r5, r4
	  bl        0x339C
	  cmpwi     r3, 0x1
	  bne+      .loc_0x74
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Jac_CheckReadyDemoSound(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Jac_StreamSetup(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Jac_StreamUpdate(void)
{
	// UNUSED FUNCTION
}
