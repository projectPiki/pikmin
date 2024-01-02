#include "types.h"

/*
 * --INFO--
 * Address:	800062C0
 * Size:	000008
 */
void DspSyncCountClear(void)
{
	/*
	.loc_0x0:
	  stw       r3, 0x2B44(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800062E0
 * Size:	000008
 */
void DspSyncCountCheck(void)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2B44(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_GetDacRate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80006300
 * Size:	000044
 */
void DspSync()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2B40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  lis       r3, 0x802F
	  li        r4, 0x1
	  subi      r3, r3, 0x69A0
	  li        r5, 0
	  bl        0x1F34EC
	  b         .loc_0x34

	.loc_0x30:
	  bl        0x2450

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80006360
 * Size:	000050
 */
void StopAudioThread(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2B40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  lis       r3, 0x802F
	  li        r4, 0x3
	  subi      r3, r3, 0x69A0
	  li        r5, 0
	  bl        0x1F348C
	  cmpwi     r3, 0
	  bne-      .loc_0x40
	  lis       r3, 0x803D
	  addi      r3, r3, 0x62C0
	  bl        0x1F5F2C

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800063C0
 * Size:	000080
 */
void AudioSync()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2B4C(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x24
	  li        r0, 0x1
	  stw       r0, 0x2B48(r13)
	  stb       r0, 0x2B4C(r13)

	.loc_0x24:
	  lwz       r0, 0x2B48(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x38
	  li        r3, 0x4
	  bl        -0xDD4

	.loc_0x38:
	  li        r0, 0
	  lis       r3, 0x8022
	  stw       r0, 0x2B48(r13)
	  addi      r4, r3, 0x1FF8
	  li        r3, 0x4
	  bl        -0xE0C
	  lwz       r0, 0x2B40(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lis       r3, 0x802F
	  li        r4, 0
	  subi      r3, r3, 0x69A0
	  li        r5, 0
	  bl        0x1F33E8

	.loc_0x70:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NeosSync()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80006440
 * Size:	000068
 */
void __DspSync(s16, OSContext*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0xCC00
	  stw       r0, 0x4(r1)
	  addi      r5, r3, 0x5000
	  li        r0, -0x29
	  stwu      r1, -0x2E0(r1)
	  stw       r31, 0x2DC(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x10
	  lhz       r4, 0xA(r5)
	  and       r0, r4, r0
	  ori       r0, r0, 0x80
	  sth       r0, 0xA(r5)
	  bl        0x1F0FC8
	  addi      r3, r1, 0x10
	  bl        0x1F0DF8
	  bl        -0x180
	  addi      r3, r1, 0x10
	  bl        0x1F0FB4
	  mr        r3, r31
	  bl        0x1F0DE4
	  lwz       r0, 0x2E4(r1)
	  lwz       r31, 0x2DC(r1)
	  addi      r1, r1, 0x2E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800064C0
 * Size:	000044
 */
void __DspReg()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        0x1F2AAC
	  lis       r4, 0x8000
	  addi      r31, r3, 0
	  addi      r4, r4, 0x6440
	  li        r3, 0x7
	  bl        0x1F2AE4
	  mr        r3, r31
	  bl        0x1F2AB8
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80006520
 * Size:	000130
 */
void audioproc(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  subi      r31, r3, 0x69A0
	  bl        0x128
	  addi      r3, r31, 0
	  addi      r4, r31, 0x20
	  li        r5, 0x10
	  bl        0x1F326C
	  li        r0, 0x1
	  stw       r0, 0x2B40(r13)
	  bl        -0xD54
	  bl        0x77A8
	  bl        0xBC4
	  li        r3, 0
	  bl        0x63C
	  li        r3, 0
	  bl        0x974
	  bl        0x20D0
	  bl        0x56EC
	  bl        -0xB8
	  lwz       r3, 0x2BC0(r13)
	  bl        0x1FFC88
	  lis       r3, 0x8000
	  addi      r3, r3, 0x63C0
	  bl        0x1FFA78
	  bl        0x1FFB40

	.loc_0x74:
	  addi      r3, r31, 0
	  addi      r4, r1, 0x18
	  li        r5, 0x1
	  bl        0x1F333C
	  lwz       r0, 0x18(r1)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x108
	  bge-      .loc_0xA4
	  cmpwi     r0, 0
	  beq-      .loc_0xB0
	  bge-      .loc_0xB8
	  b         .loc_0x74

	.loc_0xA4:
	  cmpwi     r0, 0x4
	  bge+      .loc_0x74
	  b         .loc_0x110

	.loc_0xB0:
	  bl        -0x810
	  b         .loc_0x74

	.loc_0xB8:
	  lwz       r0, 0x2B44(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x11C
	  lwz       r3, 0x2B44(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2B44(r13)
	  lwz       r0, 0x2B44(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0xEC
	  li        r3, 0x7
	  bl        -0xFE0
	  bl        0x89C
	  b         .loc_0x74

	.loc_0xEC:
	  li        r3, 0x2
	  subi      r4, r2, 0x7FF0
	  bl        -0x1014
	  bl        0x7E8
	  li        r3, 0x2
	  bl        -0x1000
	  b         .loc_0x74

	.loc_0x108:
	  bl        0xAB8
	  b         .loc_0x74

	.loc_0x110:
	  li        r3, 0
	  bl        0x1F5BB0
	  b         .loc_0x74

	.loc_0x11C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80006660
 * Size:	000034
 */
void OSInitFastCast(void)
{
	/*
	.loc_0x0:
	  li        r3, 0x4
	  oris      r3, r3, 0x4
	  mtspr     914, r3
	  li        r3, 0x5
	  oris      r3, r3, 0x5
	  mtspr     915, r3
	  li        r3, 0x6
	  oris      r3, r3, 0x6
	  mtspr     916, r3
	  li        r3, 0x7
	  oris      r3, r3, 0x7
	  mtspr     917, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SetAudioThreadPriority(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800066A0
 * Size:	000124
 */
void StartAudioThread(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r31, r4, 0
	  addi      r30, r5, 0
	  addi      r29, r6, 0
	  lwz       r0, 0x2B50(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x50
	  bl        0x1F5418
	  bl        0x1F64DC
	  subi      r0, r3, 0x3
	  stw       r0, 0x2B54(r13)
	  lwz       r4, 0x2B54(r13)
	  addi      r3, r4, 0x1
	  addi      r0, r4, 0x2
	  stw       r3, 0x2B5C(r13)
	  stw       r0, 0x2B58(r13)

	.loc_0x50:
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0xFD8
	  mr        r3, r30
	  bl        -0x560
	  rlwinm    r3,r29,0,29,29
	  bl        -0x4E8
	  lis       r3, 0x803E
	  li        r4, 0x200
	  subi      r31, r3, 0x7400
	  addi      r3, r31, 0
	  bl        0x1BA4
	  rlwinm.   r0,r29,0,30,30
	  beq-      .loc_0xBC
	  lis       r4, 0x803D
	  lis       r3, 0x8000
	  addi      r30, r4, 0x62C0
	  lwz       r8, 0x2B54(r13)
	  addi      r4, r3, 0x6520
	  addi      r3, r30, 0
	  addi      r6, r31, 0x1000
	  li        r5, 0
	  li        r7, 0x1000
	  li        r9, 0x1
	  bl        0x1F5974
	  mr        r3, r30
	  bl        0x1F5E6C

	.loc_0xBC:
	  lis       r3, 0x803E
	  li        r4, 0x200
	  subi      r30, r3, 0x60E0
	  addi      r3, r30, 0
	  bl        0x1B54
	  rlwinm.   r0,r29,0,31,31
	  beq-      .loc_0x110
	  bl        0xEC8
	  lis       r4, 0x803E
	  lis       r3, 0x8000
	  subi      r31, r4, 0x6400
	  lwz       r8, 0x2B5C(r13)
	  addi      r4, r3, 0x7680
	  addi      r3, r31, 0
	  addi      r6, r30, 0x1000
	  li        r5, 0
	  li        r7, 0x1000
	  li        r9, 0x1
	  bl        0x1F5920
	  mr        r3, r31
	  bl        0x1F5E18

	.loc_0x110:
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
