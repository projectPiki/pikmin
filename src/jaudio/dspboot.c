#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void WRITEIO(unsigned long, unsigned short)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void READIO(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void CHKCDCR(unsigned char)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void DSPCall()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80008300
 * Size:	000280
 */
void __DSPCheckMXICBoot2(STRUCT_DSP_TASK2*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3

	.loc_0x14:
	  bl        0x1FFB10
	  cmplwi    r3, 0
	  beq+      .loc_0x14
	  bl        0x1FFB14
	  addis     r0, r3, 0x7F8F
	  cmplwi    r0, 0xFEED
	  bne-      .loc_0x114
	  lis       r3, 0x80F4
	  subi      r3, r3, 0x5FFF
	  bl        0x1FFB14

	.loc_0x3C:
	  bl        0x1FFAD8
	  cmplwi    r3, 0
	  bne+      .loc_0x3C
	  lwz       r3, 0x0(r31)
	  bl        0x1FFB00

	.loc_0x50:
	  bl        0x1FFAC4
	  cmplwi    r3, 0
	  bne+      .loc_0x50
	  lis       r3, 0x80F4
	  subi      r3, r3, 0x5FFE
	  bl        0x1FFAE8

	.loc_0x68:
	  bl        0x1FFAAC
	  cmplwi    r3, 0
	  bne+      .loc_0x68
	  lwz       r3, 0x4(r31)
	  bl        0x1FFAD4

	.loc_0x7C:
	  bl        0x1FFA98
	  cmplwi    r3, 0
	  bne+      .loc_0x7C
	  lis       r3, 0x80F4
	  subi      r3, r3, 0x3FFE
	  bl        0x1FFABC

	.loc_0x94:
	  bl        0x1FFA80
	  cmplwi    r3, 0
	  bne+      .loc_0x94
	  lhz       r3, 0x8(r31)
	  bl        0x1FFAA8

	.loc_0xA8:
	  bl        0x1FFA6C
	  cmplwi    r3, 0
	  bne+      .loc_0xA8
	  lis       r3, 0x80F4
	  subi      r3, r3, 0x4FFE
	  bl        0x1FFA90

	.loc_0xC0:
	  bl        0x1FFA54
	  cmplwi    r3, 0
	  bne+      .loc_0xC0
	  li        r3, 0
	  bl        0x1FFA7C

	.loc_0xD4:
	  bl        0x1FFA40
	  cmplwi    r3, 0
	  bne+      .loc_0xD4
	  lis       r3, 0x80F4
	  subi      r3, r3, 0x2FFF
	  bl        0x1FFA64

	.loc_0xEC:
	  bl        0x1FFA28
	  cmplwi    r3, 0
	  bne+      .loc_0xEC
	  lhz       r3, 0x16(r31)
	  bl        0x1FFA50

	.loc_0x100:
	  bl        0x1FFA14
	  cmplwi    r3, 0
	  bne+      .loc_0x100
	  li        r3, 0x1
	  b         .loc_0x26C

	.loc_0x114:
	  addis     r0, r3, 0x3F01
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x268
	  lis       r3, 0xC003
	  subi      r3, r3, 0x7F8D
	  bl        0x1FFA24

	.loc_0x12C:
	  bl        0x1FF9E8
	  cmplwi    r3, 0
	  bne+      .loc_0x12C
	  lis       r3, 0xC001
	  subi      r3, r3, 0x32
	  bl        0x1FFA0C

	.loc_0x144:
	  bl        0x1FF9D0
	  cmplwi    r3, 0
	  bne+      .loc_0x144
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,16,16,31
	  oris      r3, r0, 0xC001
	  bl        0x1FF9F0

	.loc_0x160:
	  bl        0x1FF9B4
	  cmplwi    r3, 0
	  bne+      .loc_0x160
	  lis       r3, 0xC001
	  subi      r3, r3, 0x31
	  bl        0x1FF9D8

	.loc_0x178:
	  bl        0x1FF99C
	  cmplwi    r3, 0
	  bne+      .loc_0x178
	  lwz       r0, 0x0(r31)
	  rlwinm    r0,r0,0,16,31
	  oris      r3, r0, 0xC001
	  bl        0x1FF9BC

	.loc_0x194:
	  bl        0x1FF980
	  cmplwi    r3, 0
	  bne+      .loc_0x194
	  lis       r3, 0xC001
	  subi      r3, r3, 0x33
	  bl        0x1FF9A4

	.loc_0x1AC:
	  bl        0x1FF968
	  cmplwi    r3, 0
	  bne+      .loc_0x1AC
	  lhz       r0, 0x8(r31)
	  oris      r3, r0, 0xC001
	  bl        0x1FF98C

	.loc_0x1C4:
	  bl        0x1FF950
	  cmplwi    r3, 0
	  bne+      .loc_0x1C4
	  lis       r3, 0xC001
	  subi      r3, r3, 0x37
	  bl        0x1FF974

	.loc_0x1DC:
	  bl        0x1FF938
	  cmplwi    r3, 0
	  bne+      .loc_0x1DC
	  lis       r3, 0xC001
	  addi      r3, r3, 0x2
	  bl        0x1FF95C

	.loc_0x1F4:
	  bl        0x1FF920
	  cmplwi    r3, 0
	  bne+      .loc_0x1F4
	  lis       r3, 0xC001
	  subi      r3, r3, 0x35
	  bl        0x1FF944

	.loc_0x20C:
	  bl        0x1FF908
	  cmplwi    r3, 0
	  bne+      .loc_0x20C
	  lwz       r0, 0x4(r31)
	  oris      r3, r0, 0xC001
	  bl        0x1FF92C

	.loc_0x224:
	  bl        0x1FF8F0
	  cmplwi    r3, 0
	  bne+      .loc_0x224
	  lis       r3, 0xC003
	  subi      r3, r3, 0x7F8D
	  bl        0x1FF914

	.loc_0x23C:
	  bl        0x1FF8D8
	  cmplwi    r3, 0
	  bne+      .loc_0x23C
	  lhz       r0, 0x16(r31)
	  oris      r3, r0, 0xC002
	  bl        0x1FF8FC

	.loc_0x254:
	  bl        0x1FF8C0
	  cmplwi    r3, 0
	  bne+      .loc_0x254
	  li        r3, 0x1
	  b         .loc_0x26C

	.loc_0x268:
	  li        r3, 0

	.loc_0x26C:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008580
 * Size:	000004
 */
void DSPInit(void) { }

/*
 * --INFO--
 * Address:	800085A0
 * Size:	000098
 */
void DSPInit2(STRUCT_DSP_TASK2*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  mr        r30, r3
	  bl        0x1F09C8
	  addi      r0, r3, 0
	  lis       r3, 0x100
	  mr        r31, r0
	  bl        0x1F0DE0
	  lis       r3, 0xCC00
	  li        r4, -0xA9
	  addi      r5, r3, 0x5000
	  li        r0, -0xAD
	  lhz       r6, 0xA(r5)
	  addi      r3, r31, 0
	  and       r4, r6, r4
	  ori       r4, r4, 0x800
	  sth       r4, 0xA(r5)
	  lhz       r4, 0xA(r5)
	  and       r0, r4, r0
	  sth       r0, 0xA(r5)
	  bl        0x1F09AC
	  mr        r3, r30
	  bl        -0x300
	  cmpwi     r3, 0x1
	  beq-      .loc_0x84
	  lis       r4, 0x8022
	  subi      r3, r2, 0x7FD8
	  addi      r5, r4, 0x2020
	  li        r4, 0x165
	  crclr     6, 0x6
	  bl        0x1EF2F0

	.loc_0x84:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008640
 * Size:	000074
 */
void DspBoot()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r6, r3, 0x2EE0
	  li        r5, 0x1A00
	  li        r4, 0
	  stwu      r1, -0x40(r1)
	  li        r0, 0x100
	  stw       r6, 0x20(r1)
	  addi      r3, r1, 0x20
	  stw       r5, 0x24(r1)
	  sth       r4, 0x28(r1)
	  stw       r6, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  sth       r4, 0x34(r1)
	  sth       r4, 0x36(r1)
	  bl        -0xE0

	.loc_0x44:
	  bl        0x1FF7A0
	  stw       r3, 0x14(r1)
	  lwz       r0, 0x14(r1)
	  cmplwi    r0, 0
	  beq+      .loc_0x44
	  bl        0x1FF79C
	  bl        0x1FF788
	  bl        0x2A0
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}
