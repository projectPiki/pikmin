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
 * Address:	........
 * Size:	000128
 */
void ObjCollInfo::getCentreSize(Vector3f &, float &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void ObjCollInfo::showInfo(Graphics &, Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001AC
 */
void ObjCollInfo::saveini(char *, RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80036124
 * Size:	000350
 */
void ObjCollInfo::loadini(CmdStream *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8022
  stw       r0, 0x4(r1)
  lis       r6, 0x8022
  lis       r5, 0x8023
  stwu      r1, -0x50(r1)
  lis       r8, 0x8023
  stfd      f31, 0x48(r1)
  stfd      f30, 0x40(r1)
  stmw      r23, 0x1C(r1)
  addi      r25, r3, 0
  addi      r26, r4, 0
  addi      r28, r7, 0x738C
  addi      r29, r6, 0x737C
  subi      r30, r5, 0x7804
  subi      r27, r8, 0x7610
  lis       r31, 0x6E6F
  lfs       f30, -0x7C90(r2)
  lfs       f31, -0x7C8C(r2)
  b         .loc_0x2F8

.loc_0x50:
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAF34
  addi      r3, r26, 0
  subi      r4, r13, 0x7AF4
  bl        0xB24C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x98
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAF14
  addi      r3, r25, 0x18
  addi      r4, r26, 0x8
  li        r5, 0x4
  bl        0x1E3168
  addi      r3, r25, 0x14
  bl        0xDDDC
  b         .loc_0x2F8

.loc_0x98:
  addi      r3, r26, 0
  subi      r4, r13, 0x7AF0
  bl        0xB210
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD4
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAED8
  addi      r3, r25, 0x24
  addi      r4, r26, 0x8
  li        r5, 0x4
  bl        0x1E312C
  addi      r3, r25, 0x20
  bl        0xDDA0
  b         .loc_0x2F8

.loc_0xD4:
  addi      r3, r26, 0
  subi      r4, r13, 0x7AE8
  bl        0xB1D4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1D0
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAE9C
  crclr     6, 0x6
  addi      r5, r25, 0x2C
  subi      r4, r13, 0x7AE0
  bl        0x1E1E70
  lwz       r0, 0x2C(r25)
  cmpwi     r0, 0x2
  beq-      .loc_0x1AC
  bge-      .loc_0x2F8
  cmpwi     r0, 0x1
  bge-      .loc_0x120
  b         .loc_0x2F8

.loc_0x120:
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAE64
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAE58
  crclr     6, 0x6
  addi      r5, r25, 0x40
  subi      r4, r13, 0x7ADC
  bl        0x1E1E2C
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAE3C
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAE30
  crclr     6, 0x6
  addi      r5, r25, 0x34
  subi      r4, r13, 0x7ADC
  bl        0x1E1E04
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAE14
  crclr     6, 0x6
  addi      r5, r25, 0x38
  subi      r4, r13, 0x7ADC
  bl        0x1E1DE8
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xADF8
  crclr     6, 0x6
  addi      r5, r25, 0x3C
  subi      r4, r13, 0x7ADC
  bl        0x1E1DCC
  b         .loc_0x2F8

.loc_0x1AC:
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xADD8
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xADCC
  bl        0xA058
  stw       r3, 0x4C(r25)
  b         .loc_0x2F8

.loc_0x1D0:
  addi      r3, r26, 0
  subi      r4, r13, 0x7AD8
  bl        0xB0D8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1F0
  li        r0, 0x1
  stw       r0, 0x50(r25)
  b         .loc_0x2F8

.loc_0x1F0:
  addi      r3, r26, 0
  addi      r4, r27, 0
  bl        0xB0B8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2F8
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAD80
  crclr     6, 0x6
  addi      r5, r1, 0x10
  subi      r4, r13, 0x7AE0
  bl        0x1E1D54
  li        r3, 0x54
  bl        0x10CBC
  mr.       r23, r3
  beq-      .loc_0x2C4
  stw       r28, 0x0(r23)
  li        r24, 0
  subi      r0, r13, 0x7AD0
  stw       r29, 0x0(r23)
  addi      r3, r23, 0x14
  stw       r24, 0x10(r23)
  stw       r24, 0xC(r23)
  stw       r24, 0x8(r23)
  stw       r0, 0x4(r23)
  stw       r30, 0x0(r23)
  bl        0xDAE0
  addi      r3, r23, 0x20
  bl        0xDAD8
  stfs      f30, 0x3C(r23)
  addi      r3, r23, 0x14
  addi      r4, r31, 0x6E65
  stfs      f30, 0x38(r23)
  stfs      f30, 0x34(r23)
  bl        0xDB28
  addi      r3, r23, 0x20
  addi      r4, r31, 0x6E65
  bl        0xDB1C
  li        r0, -0x1
  stw       r0, 0x30(r23)
  li        r0, 0x1
  stw       r0, 0x2C(r23)
  stfs      f31, 0x40(r23)
  lfs       f0, -0x7B00(r13)
  stfs      f0, 0x34(r23)
  lfs       f0, -0x7AFC(r13)
  stfs      f0, 0x38(r23)
  lfs       f0, -0x7AF8(r13)
  stfs      f0, 0x3C(r23)
  stw       r24, 0x44(r23)
  stw       r24, 0x4C(r23)
  stw       r24, 0x48(r23)
  stw       r24, 0x50(r23)

.loc_0x2C4:
  lwz       r0, 0x10(r1)
  mr        r3, r25
  mr        r4, r23
  stw       r0, 0x30(r23)
  lwz       r0, 0x44(r25)
  stw       r0, 0x44(r23)
  bl        0xA1D8
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xACA4
  addi      r3, r23, 0
  addi      r4, r26, 0
  bl        .loc_0x0

.loc_0x2F8:
  mr        r3, r26
  bl        0xA938
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x318
  mr        r3, r26
  bl        0xB058
  rlwinm.   r0,r3,0,24,31
  beq+      .loc_0x50

.loc_0x318:
  mr        r3, r26
  bl        0xA918
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x334
  addi      r3, r26, 0
  li        r4, 0x1
  bl        0xAC5C

.loc_0x334:
  lmw       r23, 0x1C(r1)
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  lfd       f30, 0x40(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}
