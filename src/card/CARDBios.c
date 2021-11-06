#include "types.h"



/*
 * --INFO--
 * Address:	80207E60
 * Size:	000004
 */
void __CARDDefaultApiCallback(void)
{
}

/*
 * --INFO--
 * Address:	80207E64
 * Size:	000034
 */
void __CARDSyncCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  mulli     r4, r3, 0x108
  stw       r0, 0x4(r1)
  lis       r3, 0x803D
  stwu      r1, -0x8(r1)
  addi      r0, r3, 0x3420
  add       r3, r0, r4
  addi      r3, r3, 0x8C
  bl        -0xB3DC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80207E98
 * Size:	0000CC
 */
void __CARDExtHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  mulli     r4, r29, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r30, r0, r4
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  beq-      .loc_0xB0
  li        r31, 0
  stw       r31, 0x0(r30)
  li        r0, -0x3
  addi      r3, r29, 0
  stw       r0, 0x4(r30)
  li        r4, 0
  bl        -0xFBF0
  addi      r3, r30, 0xE0
  bl        -0x11ABC
  lwz       r0, 0xCC(r30)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0x80
  stw       r31, 0xCC(r30)
  mtlr      r12
  addi      r3, r29, 0
  li        r4, -0x3
  blrl      

.loc_0x80:
  lwz       r12, 0xC4(r30)
  cmplwi    r12, 0
  beq-      .loc_0xB0
  lwz       r0, 0x24(r30)
  cmpwi     r0, 0x7
  blt-      .loc_0xB0
  li        r0, 0
  mtlr      r12
  stw       r0, 0xC4(r30)
  addi      r3, r29, 0
  li        r4, -0x3
  blrl      

.loc_0xB0:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	80207F64
 * Size:	000118
 */
void __CARDExiHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r3, 0
  mulli     r4, r31, 0x108
  stw       r30, 0x20(r1)
  lis       r3, 0x803D
  stw       r29, 0x1C(r1)
  addi      r0, r3, 0x3420
  add       r30, r0, r4
  addi      r3, r30, 0xE0
  bl        -0x11B60
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  beq-      .loc_0xFC
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  bl        -0xF274
  cmpwi     r3, 0
  bne-      .loc_0x60
  li        r29, -0x80
  b         .loc_0xD4

.loc_0x60:
  addi      r3, r31, 0
  addi      r4, r1, 0x10
  bl        0x3A8
  mr.       r29, r3
  blt-      .loc_0xCC
  mr        r3, r31
  bl        0x488
  mr.       r29, r3
  blt-      .loc_0xCC
  lbz       r0, 0x10(r1)
  rlwinm.   r0,r0,0,27,28
  beq-      .loc_0x98
  li        r0, -0x5
  b         .loc_0x9C

.loc_0x98:
  li        r0, 0

.loc_0x9C:
  mr        r29, r0
  cmpwi     r29, -0x5
  bne-      .loc_0xCC
  lwz       r3, 0xA8(r30)
  subic.    r0, r3, 0x1
  stw       r0, 0xA8(r30)
  ble-      .loc_0xCC
  mr        r3, r31
  bl        0x594
  mr.       r29, r3
  blt-      .loc_0xD4
  b         .loc_0xFC

.loc_0xCC:
  mr        r3, r31
  bl        -0xF204

.loc_0xD4:
  lwz       r0, 0xCC(r30)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0xFC
  li        r0, 0
  mtlr      r12
  stw       r0, 0xCC(r30)
  addi      r3, r31, 0
  addi      r4, r29, 0
  blrl      

.loc_0xFC:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	8020807C
 * Size:	0000A8
 */
void __CARDTxHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r27, r3, 0
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  mulli     r4, r27, 0x108
  addi      r3, r27, 0
  add       r29, r0, r4
  bl        -0xF89C
  cntlzw    r0, r3
  addi      r3, r27, 0
  rlwinm    r31,r0,27,5,31
  bl        -0xF284
  lwz       r0, 0xC8(r29)
  cmplwi    r0, 0
  mr        r28, r0
  beq-      .loc_0x94
  li        r30, 0
  cmpwi     r31, 0
  stw       r30, 0xC8(r29)
  bne-      .loc_0x70
  mr        r3, r27
  bl        -0xFD68
  cmpwi     r3, 0
  beq-      .loc_0x70
  li        r30, 0x1

.loc_0x70:
  cmpwi     r30, 0
  beq-      .loc_0x80
  li        r4, 0
  b         .loc_0x84

.loc_0x80:
  li        r4, -0x3

.loc_0x84:
  addi      r12, r28, 0
  mtlr      r12
  addi      r3, r27, 0
  blrl      

.loc_0x94:
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80208124
 * Size:	000084
 */
void __CARDUnlockedHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  mulli     r4, r30, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r3, r0, r4
  lwz       r0, 0xDC(r3)
  cmplwi    r0, 0
  mr        r31, r0
  beq-      .loc_0x6C
  li        r0, 0
  stw       r0, 0xDC(r3)
  mr        r3, r30
  bl        -0xFDF4
  cmpwi     r3, 0
  beq-      .loc_0x58
  li        r4, 0x1
  b         .loc_0x5C

.loc_0x58:
  li        r4, -0x3

.loc_0x5C:
  addi      r12, r31, 0
  mtlr      r12
  addi      r3, r30, 0
  blrl      

.loc_0x6C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	802081A8
 * Size:	00010C
 */
void __CARDReadNintendoID(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  li        r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  bl        -0xFAF4
  cmpwi     r3, 0
  bne-      .loc_0x3C
  li        r3, -0x3
  b         .loc_0xF0

.loc_0x3C:
  li        r0, 0
  stw       r0, 0x10(r1)
  addi      r3, r29, 0
  addi      r4, r1, 0x10
  li        r5, 0x2
  li        r6, 0x1
  li        r7, 0
  bl        -0x10540
  cntlzw    r0, r3
  addi      r3, r29, 0
  rlwinm    r31,r0,27,5,31
  bl        -0x10168
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r29, 0
  addi      r4, r30, 0
  or        r31, r31, r0
  li        r5, 0x4
  li        r6, 0
  li        r7, 0
  bl        -0x10574
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r29, 0
  or        r31, r31, r0
  bl        -0x101A0
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r29, 0
  or        r31, r31, r0
  bl        -0xFA54
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or.       r31, r31, r0
  beq-      .loc_0xD0
  li        r3, -0x3
  b         .loc_0xF0

.loc_0xD0:
  lwz       r3, 0x0(r30)
  rlwinm.   r0,r3,0,0,15
  bne-      .loc_0xE4
  rlwinm.   r0,r3,0,30,31
  beq-      .loc_0xEC

.loc_0xE4:
  li        r3, -0x2
  b         .loc_0xF0

.loc_0xEC:
  li        r3, 0

.loc_0xF0:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	802082B4
 * Size:	0000C0
 */
void __CARDEnableInterrupt(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  li        r4, 0
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  bl        -0xFBFC
  cmpwi     r3, 0
  bne-      .loc_0x38
  li        r3, -0x3
  b         .loc_0xA8

.loc_0x38:
  cmpwi     r31, 0
  beq-      .loc_0x48
  lis       r0, 0x8101
  b         .loc_0x4C

.loc_0x48:
  lis       r0, 0x8100

.loc_0x4C:
  stw       r0, 0x10(r1)
  addi      r3, r30, 0
  addi      r4, r1, 0x10
  li        r5, 0x2
  li        r6, 0x1
  li        r7, 0
  bl        -0x10658
  cntlzw    r0, r3
  addi      r3, r30, 0
  rlwinm    r31,r0,27,5,31
  bl        -0x10280
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r30, 0
  or        r31, r31, r0
  bl        -0xFB34
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or.       r31, r31, r0
  beq-      .loc_0xA4
  li        r3, -0x3
  b         .loc_0xA8

.loc_0xA4:
  li        r3, 0

.loc_0xA8:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	80208374
 * Size:	0000F0
 */
void __CARDReadStatus(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  li        r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  bl        -0xFCC0
  cmpwi     r3, 0
  bne-      .loc_0x3C
  li        r3, -0x3
  b         .loc_0xD4

.loc_0x3C:
  lis       r0, 0x8300
  stw       r0, 0x10(r1)
  addi      r3, r29, 0
  addi      r4, r1, 0x10
  li        r5, 0x2
  li        r6, 0x1
  li        r7, 0
  bl        -0x1070C
  cntlzw    r0, r3
  addi      r3, r29, 0
  rlwinm    r31,r0,27,5,31
  bl        -0x10334
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r29, 0
  addi      r4, r30, 0
  or        r31, r31, r0
  li        r5, 0x1
  li        r6, 0
  li        r7, 0
  bl        -0x10740
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r29, 0
  or        r31, r31, r0
  bl        -0x1036C
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r29, 0
  or        r31, r31, r0
  bl        -0xFC20
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or.       r31, r31, r0
  beq-      .loc_0xD0
  li        r3, -0x3
  b         .loc_0xD4

.loc_0xD0:
  li        r3, 0

.loc_0xD4:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80208464
 * Size:	0000AC
 */
void __CARDClearStatus(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  li        r5, 0x4
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  bl        -0xFDA8
  cmpwi     r3, 0
  bne-      .loc_0x34
  li        r3, -0x3
  b         .loc_0x94

.loc_0x34:
  lis       r0, 0x8900
  stw       r0, 0xC(r1)
  addi      r3, r30, 0
  addi      r4, r1, 0xC
  li        r5, 0x1
  li        r6, 0x1
  li        r7, 0
  bl        -0x107F4
  cntlzw    r0, r3
  addi      r3, r30, 0
  rlwinm    r31,r0,27,5,31
  bl        -0x1041C
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r30, 0
  or        r31, r31, r0
  bl        -0xFCD0
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or.       r31, r31, r0
  beq-      .loc_0x90
  li        r3, -0x3
  b         .loc_0x94

.loc_0x90:
  li        r3, 0

.loc_0x94:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void __CARDSleep(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void __CARDWakeup(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80208510
 * Size:	0000A4
 */
void TimeoutHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x3420
  addi      r0, r4, 0xE0
  stwu      r1, -0x18(r1)
  cmplw     r3, r0
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r4, 0
  beq-      .loc_0x4C
  addi      r0, r4, 0x1E8
  cmplw     r3, r0
  addi      r4, r4, 0x108
  addi      r30, r4, 0
  li        r31, 0x1
  beq-      .loc_0x4C
  li        r31, 0x2

.loc_0x4C:
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  beq-      .loc_0x8C
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x10278
  lwz       r0, 0xCC(r30)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0x8C
  li        r0, 0
  mtlr      r12
  stw       r0, 0xCC(r30)
  addi      r3, r31, 0
  li        r4, -0x5
  blrl      

.loc_0x8C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void SetupTimeoutAlarm(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802085B4
 * Size:	00022C
 */
void Retry(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  mulli     r4, r30, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r4
  addi      r3, r30, 0
  li        r4, 0
  bl        -0xFF0C
  cmpwi     r3, 0
  bne-      .loc_0x50
  mr        r3, r30
  bl        -0xF7C8
  li        r3, -0x3
  b         .loc_0x214

.loc_0x50:
  addi      r3, r31, 0xE0
  bl        -0x121D4
  lbz       r0, 0x94(r31)
  cmpwi     r0, 0xF3
  beq-      .loc_0x120
  bge-      .loc_0x78
  cmpwi     r0, 0xF1
  beq-      .loc_0xBC
  bge-      .loc_0x84
  b         .loc_0x120

.loc_0x78:
  cmpwi     r0, 0xF5
  bge-      .loc_0x120
  b         .loc_0xBC

.loc_0x84:
  lis       r3, 0x8000
  lwz       r0, 0xF8(r3)
  lis       r4, 0x1062
  lis       r3, 0x8021
  rlwinm    r0,r0,30,2,31
  addi      r4, r4, 0x4DD3
  mulhwu    r0, r4, r0
  rlwinm    r0,r0,26,6,31
  mulli     r6, r0, 0x64
  subi      r7, r3, 0x7AF0
  addi      r3, r31, 0xE0
  li        r5, 0
  bl        -0x12300
  b         .loc_0x120

.loc_0xBC:
  lis       r3, 0x8000
  lwz       r4, 0xC(r31)
  lwz       r0, 0xF8(r3)
  lis       r3, 0x8021
  srawi     r9, r4, 0xD
  rlwinm    r7,r0,30,2,31
  li        r0, 0x2
  li        r4, 0
  mullw     r8, r4, r0
  mulhwu    r6, r7, r0
  add       r8, r8, r6
  mullw     r5, r7, r0
  addze     r9, r9
  mullw     r6, r7, r4
  srawi     r0, r9, 0x1F
  mullw     r4, r0, r5
  mulhwu    r0, r9, r5
  subi      r7, r3, 0x7AF0
  add       r3, r8, r6
  add       r4, r4, r0
  mullw     r0, r9, r3
  mullw     r6, r9, r5
  addi      r3, r31, 0xE0
  add       r5, r4, r0
  bl        -0x12368

.loc_0x120:
  lwz       r5, 0xA0(r31)
  addi      r3, r30, 0
  addi      r4, r31, 0x94
  li        r6, 0x1
  bl        -0x107C8
  cmpwi     r3, 0
  bne-      .loc_0x154
  mr        r3, r30
  bl        -0xFEEC
  mr        r3, r30
  bl        -0xF8CC
  li        r3, -0x3
  b         .loc_0x214

.loc_0x154:
  lbz       r0, 0x94(r31)
  cmplwi    r0, 0x52
  bne-      .loc_0x198
  lwz       r4, 0x80(r31)
  mr        r3, r30
  lwz       r5, 0x14(r31)
  li        r6, 0x1
  addi      r4, r4, 0x200
  bl        -0x1080C
  cmpwi     r3, 0
  bne-      .loc_0x198
  mr        r3, r30
  bl        -0xFF30
  mr        r3, r30
  bl        -0xF910
  li        r3, -0x3
  b         .loc_0x214

.loc_0x198:
  lwz       r3, 0xA4(r31)
  addis     r0, r3, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x1C0
  mr        r3, r30
  bl        -0xFF58
  mr        r3, r30
  bl        -0xF938
  li        r3, 0
  b         .loc_0x214

.loc_0x1C0:
  lbz       r0, 0x94(r31)
  cmplwi    r0, 0x52
  bne-      .loc_0x1D4
  li        r5, 0x200
  b         .loc_0x1D8

.loc_0x1D4:
  li        r5, 0x80

.loc_0x1D8:
  lis       r3, 0x8021
  lwz       r4, 0xB4(r31)
  subi      r7, r3, 0x7F84
  lwz       r6, 0xA4(r31)
  mr        r3, r30
  bl        -0x107E4
  cmpwi     r3, 0
  bne-      .loc_0x210
  mr        r3, r30
  bl        -0xFFA8
  mr        r3, r30
  bl        -0xF988
  li        r3, -0x3
  b         .loc_0x214

.loc_0x210:
  li        r3, 0

.loc_0x214:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	802087E0
 * Size:	000110
 */
void UnlockedCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  mulli     r5, r31, 0x108
  stw       r30, 0x10(r1)
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r30, r0, r5
  blt-      .loc_0x74
  lis       r3, 0x8021
  subi      r0, r3, 0x7820
  lis       r3, 0x8021
  stw       r0, 0xDC(r30)
  subi      r5, r3, 0x7EDC
  addi      r3, r31, 0
  li        r4, 0
  bl        -0xFAF0
  cmpwi     r3, 0
  bne-      .loc_0x60
  li        r4, 0
  b         .loc_0x74

.loc_0x60:
  li        r0, 0
  stw       r0, 0xDC(r30)
  mr        r3, r31
  bl        -0x298
  mr        r4, r3

.loc_0x74:
  cmpwi     r4, 0
  bge-      .loc_0xF8
  lbz       r0, 0x94(r30)
  cmpwi     r0, 0xF3
  beq-      .loc_0xF8
  bge-      .loc_0xA4
  cmpwi     r0, 0x52
  beq-      .loc_0xB0
  blt-      .loc_0xF8
  cmpwi     r0, 0xF1
  bge-      .loc_0xD8
  b         .loc_0xF8

.loc_0xA4:
  cmpwi     r0, 0xF5
  bge-      .loc_0xF8
  b         .loc_0xD8

.loc_0xB0:
  lwz       r0, 0xC8(r30)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0xF8
  li        r0, 0
  mtlr      r12
  stw       r0, 0xC8(r30)
  mr        r3, r31
  blrl      
  b         .loc_0xF8

.loc_0xD8:
  lwz       r12, 0xCC(r30)
  cmplwi    r12, 0
  beq-      .loc_0xF8
  li        r0, 0
  mtlr      r12
  stw       r0, 0xCC(r30)
  mr        r3, r31
  blrl      

.loc_0xF8:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	802088F0
 * Size:	0001A0
 */
void __CARDStart(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  mulli     r6, r30, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r6
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0
  bne-      .loc_0x3C
  li        r3, -0x3
  b         .loc_0x188

.loc_0x3C:
  cmplwi    r4, 0
  beq-      .loc_0x48
  stw       r4, 0xC8(r31)

.loc_0x48:
  cmplwi    r5, 0
  beq-      .loc_0x54
  stw       r5, 0xCC(r31)

.loc_0x54:
  lis       r3, 0x8021
  subi      r0, r3, 0x7820
  lis       r3, 0x8021
  stw       r0, 0xDC(r31)
  subi      r5, r3, 0x7EDC
  addi      r3, r30, 0
  li        r4, 0
  bl        -0xFC24
  cmpwi     r3, 0
  bne-      .loc_0x84
  li        r3, -0x1
  b         .loc_0x188

.loc_0x84:
  li        r0, 0
  stw       r0, 0xDC(r31)
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0x4
  bl        -0x102AC
  cmpwi     r3, 0
  bne-      .loc_0xB4
  mr        r3, r30
  bl        -0xFB68
  li        r3, -0x3
  b         .loc_0x188

.loc_0xB4:
  addi      r3, r31, 0xE0
  bl        -0x12574
  lbz       r0, 0x94(r31)
  cmpwi     r0, 0xF3
  beq-      .loc_0x184
  bge-      .loc_0xDC
  cmpwi     r0, 0xF1
  beq-      .loc_0x120
  bge-      .loc_0xE8
  b         .loc_0x184

.loc_0xDC:
  cmpwi     r0, 0xF5
  bge-      .loc_0x184
  b         .loc_0x120

.loc_0xE8:
  lis       r3, 0x8000
  lwz       r0, 0xF8(r3)
  lis       r4, 0x1062
  lis       r3, 0x8021
  rlwinm    r0,r0,30,2,31
  addi      r4, r4, 0x4DD3
  mulhwu    r0, r4, r0
  rlwinm    r0,r0,26,6,31
  mulli     r6, r0, 0x64
  subi      r7, r3, 0x7AF0
  addi      r3, r31, 0xE0
  li        r5, 0
  bl        -0x126A0
  b         .loc_0x184

.loc_0x120:
  lis       r3, 0x8000
  lwz       r4, 0xC(r31)
  lwz       r0, 0xF8(r3)
  lis       r3, 0x8021
  srawi     r9, r4, 0xD
  rlwinm    r7,r0,30,2,31
  li        r0, 0x2
  li        r4, 0
  mullw     r8, r4, r0
  mulhwu    r6, r7, r0
  add       r8, r8, r6
  mullw     r5, r7, r0
  addze     r9, r9
  mullw     r6, r7, r4
  srawi     r0, r9, 0x1F
  mullw     r4, r0, r5
  mulhwu    r0, r9, r5
  subi      r7, r3, 0x7AF0
  add       r3, r8, r6
  add       r4, r4, r0
  mullw     r0, r9, r3
  mullw     r6, r9, r5
  addi      r3, r31, 0xE0
  add       r5, r4, r0
  bl        -0x12708

.loc_0x184:
  li        r3, 0

.loc_0x188:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	80208A90
 * Size:	000138
 */
void __CARDReadSegment(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0x5
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  mulli     r5, r30, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r5
  li        r0, 0x52
  stb       r0, 0x94(r31)
  li        r0, 0
  addi      r3, r30, 0
  lwz       r5, 0xB0(r31)
  rlwinm    r5,r5,15,25,31
  stb       r5, 0x95(r31)
  li        r5, 0
  lwz       r7, 0xB0(r31)
  rlwinm    r7,r7,23,24,31
  stb       r7, 0x96(r31)
  lwz       r7, 0xB0(r31)
  rlwinm    r7,r7,25,30,31
  stb       r7, 0x97(r31)
  lwz       r7, 0xB0(r31)
  rlwinm    r7,r7,0,25,31
  stb       r7, 0x98(r31)
  stw       r6, 0xA0(r31)
  stw       r0, 0xA4(r31)
  stw       r0, 0xA8(r31)
  bl        -0x21C
  cmpwi     r3, -0x1
  bne-      .loc_0x90
  li        r3, 0
  b         .loc_0x120

.loc_0x90:
  cmpwi     r3, 0
  bge-      .loc_0x9C
  b         .loc_0x120

.loc_0x9C:
  lwz       r5, 0xA0(r31)
  addi      r3, r30, 0
  addi      r4, r31, 0x94
  li        r6, 0x1
  bl        -0x10C20
  cmpwi     r3, 0
  beq-      .loc_0xFC
  lwz       r4, 0x80(r31)
  mr        r3, r30
  lwz       r5, 0x14(r31)
  li        r6, 0x1
  addi      r4, r4, 0x200
  bl        -0x10C40
  cmpwi     r3, 0
  beq-      .loc_0xFC
  lis       r3, 0x8021
  lwz       r4, 0xB4(r31)
  subi      r7, r3, 0x7F84
  lwz       r6, 0xA4(r31)
  addi      r3, r30, 0
  li        r5, 0x200
  bl        -0x10BC4
  cmpwi     r3, 0
  bne-      .loc_0x11C

.loc_0xFC:
  li        r0, 0
  stw       r0, 0xC8(r31)
  mr        r3, r30
  bl        -0x10390
  mr        r3, r30
  bl        -0xFD70
  li        r3, -0x3
  b         .loc_0x120

.loc_0x11C:
  li        r3, 0

.loc_0x120:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80208BC8
 * Size:	000120
 */
void __CARDWritePage(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r7, 0x5
  stw       r0, 0x4(r1)
  li        r6, 0x1
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  mulli     r5, r30, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r5
  li        r0, 0xF2
  stb       r0, 0x94(r31)
  addi      r5, r4, 0
  li        r0, 0x3
  lwz       r3, 0xB0(r31)
  li        r4, 0
  rlwinm    r3,r3,15,25,31
  stb       r3, 0x95(r31)
  addi      r3, r30, 0
  lwz       r8, 0xB0(r31)
  rlwinm    r8,r8,23,24,31
  stb       r8, 0x96(r31)
  lwz       r8, 0xB0(r31)
  rlwinm    r8,r8,25,30,31
  stb       r8, 0x97(r31)
  lwz       r8, 0xB0(r31)
  rlwinm    r8,r8,0,25,31
  stb       r8, 0x98(r31)
  stw       r7, 0xA0(r31)
  stw       r6, 0xA4(r31)
  stw       r0, 0xA8(r31)
  bl        -0x35C
  cmpwi     r3, -0x1
  bne-      .loc_0x98
  li        r3, 0
  b         .loc_0x108

.loc_0x98:
  cmpwi     r3, 0
  bge-      .loc_0xA4
  b         .loc_0x108

.loc_0xA4:
  lwz       r5, 0xA0(r31)
  addi      r3, r30, 0
  addi      r4, r31, 0x94
  li        r6, 0x1
  bl        -0x10D60
  cmpwi     r3, 0
  beq-      .loc_0xE4
  lis       r3, 0x8021
  lwz       r4, 0xB4(r31)
  subi      r7, r3, 0x7F84
  lwz       r6, 0xA4(r31)
  addi      r3, r30, 0
  li        r5, 0x80
  bl        -0x10CE4
  cmpwi     r3, 0
  bne-      .loc_0x104

.loc_0xE4:
  li        r0, 0
  stw       r0, 0xCC(r31)
  mr        r3, r30
  bl        -0x104B0
  mr        r3, r30
  bl        -0xFE90
  li        r3, -0x3
  b         .loc_0x108

.loc_0x104:
  li        r3, 0

.loc_0x108:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void __CARDErase(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80208CE8
 * Size:	0000DC
 */
void __CARDEraseSector(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  mulli     r6, r29, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r30, r0, r6
  li        r0, 0xF1
  stb       r0, 0x94(r30)
  rlwinm    r3,r4,15,25,31
  rlwinm    r0,r4,23,24,31
  stb       r3, 0x95(r30)
  li        r6, 0x3
  addi      r3, r29, 0
  stb       r0, 0x96(r30)
  li        r0, -0x1
  li        r4, 0
  stw       r6, 0xA0(r30)
  stw       r0, 0xA4(r30)
  stw       r6, 0xA8(r30)
  bl        -0x458
  cmpwi     r3, -0x1
  bne-      .loc_0x74
  li        r3, 0
  b         .loc_0xC0

.loc_0x74:
  cmpwi     r3, 0
  bge-      .loc_0x80
  b         .loc_0xC0

.loc_0x80:
  lwz       r5, 0xA0(r30)
  addi      r3, r29, 0
  addi      r4, r30, 0x94
  li        r31, 0
  li        r6, 0x1
  bl        -0x10E60
  cmpwi     r3, 0
  bne-      .loc_0xAC
  li        r0, 0
  stw       r0, 0xCC(r30)
  li        r31, -0x3

.loc_0xAC:
  mr        r3, r29
  bl        -0x10590
  mr        r3, r29
  bl        -0xFF70
  mr        r3, r31

.loc_0xC0:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80208DC4
 * Size:	000090
 */
void CARDInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r29, 0xC(r1)
  lwz       r0, 0x3408(r13)
  cmplwi    r0, 0
  bne-      .loc_0x74
  bl        -0x200868
  bl        -0x12D2C
  lis       r3, 0x803D
  addi      r30, r3, 0x3420
  li        r29, 0
  li        r31, -0x3

.loc_0x3C:
  stw       r31, 0x4(r30)
  addi      r3, r30, 0x8C
  bl        -0xD334
  addi      r3, r30, 0xE0
  bl        -0x12D04
  addi      r29, r29, 0x1
  cmpwi     r29, 0x2
  addi      r30, r30, 0x108
  blt+      .loc_0x3C
  lis       r3, 0x8000
  bl        .loc_0x90
  lis       r3, 0x802F
  subi      r3, r3, 0x7450
  bl        -0xED74

.loc_0x74:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  lwz       r29, 0xC(r1)
  addi      r1, r1, 0x18
  blr       

.loc_0x90:
*/
}

/*
 * --INFO--
 * Address:	80208E54
 * Size:	00001C
 */
void __CARDSetDiskID(void)
{
/*
.loc_0x0:
  cmplwi    r3, 0
  beq-      .loc_0xC
  b         .loc_0x14

.loc_0xC:
  lis       r3, 0x803D
  addi      r3, r3, 0x3630

.loc_0x14:
  stw       r3, 0x3408(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	80208E70
 * Size:	0000B0
 */
void __CARDGetControlBlock(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  stw       r30, 0x10(r1)
  addi      r30, r4, 0
  blt-      .loc_0x34
  cmpwi     r31, 0x2
  bge-      .loc_0x34
  lwz       r0, 0x3408(r13)
  cmplwi    r0, 0
  bne-      .loc_0x3C

.loc_0x34:
  li        r3, -0x80
  b         .loc_0x98

.loc_0x3C:
  bl        -0xFF30
  mulli     r5, r31, 0x108
  lis       r4, 0x803D
  addi      r0, r4, 0x3420
  add       r4, r0, r5
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0
  bne-      .loc_0x64
  li        r31, -0x3
  b         .loc_0x90

.loc_0x64:
  lwz       r0, 0x4(r4)
  cmpwi     r0, -0x1
  bne-      .loc_0x78
  li        r31, -0x1
  b         .loc_0x90

.loc_0x78:
  li        r0, -0x1
  stw       r0, 0x4(r4)
  li        r0, 0
  li        r31, 0
  stw       r0, 0xD0(r4)
  stw       r4, 0x0(r30)

.loc_0x90:
  bl        -0xFF5C
  mr        r3, r31

.loc_0x98:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80208F20
 * Size:	000050
 */
void __CARDPutControlBlock(void)
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
  bl        -0xFFC0
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  beq-      .loc_0x30
  stw       r31, 0x4(r30)

.loc_0x30:
  bl        -0xFFAC
  lwz       r0, 0x1C(r1)
  mr        r3, r31
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80208F70
 * Size:	000030
 */
void CARDGetResultCode(void)
{
/*
.loc_0x0:
  cmpwi     r3, 0
  blt-      .loc_0x10
  cmpwi     r3, 0x2
  blt-      .loc_0x18

.loc_0x10:
  li        r3, -0x80
  blr       

.loc_0x18:
  mulli     r4, r3, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r3, r0, r4
  lwz       r3, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80208FA0
 * Size:	000120
 */
void CARDFreeBlocks(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r5, 0
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  addi      r4, r1, 0x18
  bl        -0x154
  cmpwi     r3, 0
  bge-      .loc_0x34
  b         .loc_0x104

.loc_0x34:
  lwz       r3, 0x18(r1)
  bl        0x4D4
  mr        r30, r3
  lwz       r3, 0x18(r1)
  bl        0x8CC
  cmplwi    r30, 0
  beq-      .loc_0x58
  cmplwi    r3, 0
  bne-      .loc_0x80

.loc_0x58:
  lwz       r30, 0x18(r1)
  bl        -0x10080
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  beq-      .loc_0x74
  li        r0, -0x6
  stw       r0, 0x4(r30)

.loc_0x74:
  bl        -0x10070
  li        r3, -0x6
  b         .loc_0x104

.loc_0x80:
  cmplwi    r29, 0
  beq-      .loc_0x9C
  lwz       r4, 0x18(r1)
  lhz       r0, 0x6(r30)
  lwz       r4, 0xC(r4)
  mullw     r0, r4, r0
  stw       r0, 0x0(r29)

.loc_0x9C:
  cmplwi    r31, 0
  beq-      .loc_0xE0
  li        r0, 0
  stw       r0, 0x0(r31)
  li        r5, 0
  b         .loc_0xD4

.loc_0xB4:
  lbz       r0, 0x8(r3)
  cmplwi    r0, 0xFF
  bne-      .loc_0xCC
  lwz       r4, 0x0(r31)
  addi      r0, r4, 0x1
  stw       r0, 0x0(r31)

.loc_0xCC:
  addi      r3, r3, 0x40
  addi      r5, r5, 0x1

.loc_0xD4:
  rlwinm    r0,r5,0,16,31
  cmplwi    r0, 0x7F
  blt+      .loc_0xB4

.loc_0xE0:
  lwz       r30, 0x18(r1)
  bl        -0x10108
  lwz       r0, 0x0(r30)
  cmpwi     r0, 0
  beq-      .loc_0xFC
  li        r0, 0
  stw       r0, 0x4(r30)

.loc_0xFC:
  bl        -0x100F8
  li        r3, 0

.loc_0x104:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void CARDGetEncoding(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void CARDGetMemSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802090C0
 * Size:	00006C
 */
void CARDGetSectorSize(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  addi      r4, r1, 0x10
  bl        -0x268
  cmpwi     r3, 0
  bge-      .loc_0x28
  b         .loc_0x58

.loc_0x28:
  lwz       r3, 0x10(r1)
  lwz       r0, 0xC(r3)
  stw       r0, 0x0(r31)
  lwz       r31, 0x10(r1)
  bl        -0x1017C
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0
  beq-      .loc_0x50
  li        r0, 0
  stw       r0, 0x4(r31)

.loc_0x50:
  bl        -0x1016C
  li        r3, 0

.loc_0x58:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020912C
 * Size:	000098
 */
void __CARDSync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  mulli     r4, r28, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r4
  bl        -0x101E0
  mr        r29, r3
  b         .loc_0x44

.loc_0x3C:
  addi      r3, r31, 0x8C
  bl        -0xC7B0

.loc_0x44:
  cmpwi     r28, 0
  blt-      .loc_0x54
  cmpwi     r28, 0x2
  blt-      .loc_0x5C

.loc_0x54:
  li        r0, -0x80
  b         .loc_0x60

.loc_0x5C:
  lwz       r0, 0x4(r31)

.loc_0x60:
  mr        r30, r0
  cmpwi     r30, -0x1
  beq+      .loc_0x3C
  mr        r3, r29
  bl        -0x101F8
  lwz       r0, 0x24(r1)
  mr        r3, r30
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	802091C4
 * Size:	000050
 */
void OnReset(void)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bne-      .loc_0x3C
  li        r3, 0
  bl        0x2014
  cmpwi     r3, -0x1
  beq-      .loc_0x34
  li        r3, 0x1
  bl        0x2004
  cmpwi     r3, -0x1
  bne-      .loc_0x3C

.loc_0x34:
  li        r3, 0
  b         .loc_0x40

.loc_0x3C:
  li        r3, 0x1

.loc_0x40:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
