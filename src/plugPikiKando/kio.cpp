#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80084340
 * Size:	000010
 */
void hioEnumCallback(s32)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2F88(r13)
	  stw       r3, 0x0(r4)
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80084350
 * Size:	000024
 */
void hioCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2F88(r13)
	  bl        0xE4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80084374
 * Size:	00005C
 */
KIO::KIO()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x20
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stb       r31, 0x10(r3)
	  li        r3, 0x100
	  stw       r30, 0x2F88(r13)
	  bl        -0x3D238
	  stw       r3, 0xC(r30)
	  mr        r3, r30
	  stb       r31, 0x2F8C(r13)
	  stb       r31, 0x11(r30)
	  stw       r31, 0x2F90(r13)
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
 * Address:	800843D0
 * Size:	000074
 */
void KIO::initialise()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8008
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x4340
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  mr        r3, r0
	  bl        0x189010
	  lis       r4, 0x8008
	  lwz       r3, 0x0(r31)
	  addi      r4, r4, 0x4350
	  bl        0x1891C4
	  cmpwi     r3, 0
	  bne-      .loc_0x48
	  li        r0, 0
	  stb       r0, 0x10(r31)
	  b         .loc_0x60

	.loc_0x48:
	  li        r0, 0x1
	  stb       r0, 0x10(r31)
	  mr        r3, r31
	  bl        .loc_0x74
	  li        r0, 0x2
	  stw       r0, -0x5F88(r13)

	.loc_0x60:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x74:
	*/
}

/*
 * --INFO--
 * Address:	80084444
 * Size:	0000DC
 */
void KIO::readMailbox()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0xC
	  stw       r31, 0xC(r1)
	  bl        0x189390
	  cmpwi     r3, 0
	  beq-      .loc_0xC4
	  lis       r3, 0x10
	  lwz       r4, 0xC(r1)
	  addi      r0, r3, 0x3
	  cmpw      r4, r0
	  beq-      .loc_0xAC
	  bge-      .loc_0x64
	  addi      r0, r3, 0x1
	  cmpw      r4, r0
	  beq-      .loc_0x90
	  bge-      .loc_0x80
	  cmpw      r4, r3
	  bge-      .loc_0x74
	  b         .loc_0xBC

	.loc_0x64:
	  addi      r0, r3, 0x6
	  cmpw      r4, r0
	  beq-      .loc_0xA0
	  b         .loc_0xBC

	.loc_0x74:
	  stw       r31, -0x5F88(r13)
	  stb       r31, 0x11(r30)
	  b         .loc_0xC4

	.loc_0x80:
	  li        r0, 0x1
	  stw       r0, -0x5F88(r13)
	  stb       r31, 0x11(r30)
	  b         .loc_0xC4

	.loc_0x90:
	  li        r0, 0x2
	  stw       r0, -0x5F88(r13)
	  stb       r31, 0x11(r30)
	  b         .loc_0xC4

	.loc_0xA0:
	  addi      r3, r30, 0x4
	  bl        0xF0
	  b         .loc_0xC4

	.loc_0xAC:
	  li        r0, 0x1
	  stb       r0, 0x2F8C(r13)
	  stb       r0, 0x11(r30)
	  b         .loc_0xC4

	.loc_0xBC:
	  li        r0, 0x2
	  stw       r0, -0x5F88(r13)

	.loc_0xC4:
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
 * Address:	80084520
 * Size:	000038
 */
void KIO::startWrite(int, u8*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x4
	  bl        0x84
	  mr        r3, r31
	  bl        .loc_0x38
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x38:
	*/
}

/*
 * --INFO--
 * Address:	80084558
 * Size:	000064
 */
void KIO::writeHeader()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lbz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x50
	  lwz       r3, 0xC(r31)
	  li        r4, 0x100
	  bl        0x172668
	  lwz       r4, 0xC(r31)
	  li        r3, 0x500
	  li        r5, 0x100
	  bl        0x18948C
	  cmpwi     r3, 0
	  beq-      .loc_0x50
	  lis       r3, 0x10
	  addi      r3, r3, 0x3
	  bl        0x189384

	.loc_0x50:
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
 * Size:	0000E4
 */
void KIO::copyEfb(u8*, u16, u16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800845BC
 * Size:	00001C
 */
void KIOContext::set(int, u8*, int)
{
	/*
	.loc_0x0:
	  stw       r6, 0x0(r3)
	  lwz       r7, 0x2F88(r13)
	  lwz       r7, 0xC(r7)
	  stw       r6, 0x4(r7)
	  stw       r4, 0x0(r7)
	  stw       r5, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800845D8
 * Size:	0000E8
 */
void KIOContext::write()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r4, 0x0(r3)
	  cmpwi     r4, 0
	  bgt-      .loc_0x48
	  lwz       r5, 0x2F90(r13)
	  cmplwi    r5, 0
	  beq-      .loc_0xCC
	  crclr     6, 0x6
	  subi      r3, r13, 0x5F90
	  li        r4, 0xA6
	  bl        0x1732F8
	  b         .loc_0xCC

	.loc_0x48:
	  lis       r3, 0x2
	  subi      r0, r3, 0x600
	  cmpw      r4, r0
	  addi      r31, r4, 0
	  ble-      .loc_0x60
	  mr        r31, r0

	.loc_0x60:
	  srawi     r0, r31, 0x5
	  addze     r0, r0
	  rlwinm    r0,r0,5,0,26
	  subc.     r0, r31, r0
	  addi      r30, r31, 0
	  beq-      .loc_0x84
	  srawi     r0, r31, 0x5
	  rlwinm    r3,r0,5,0,26
	  addi      r30, r3, 0x20

	.loc_0x84:
	  lwz       r3, 0x4(r29)
	  mr        r4, r30
	  bl        0x172584
	  lwz       r4, 0x4(r29)
	  addi      r5, r30, 0
	  li        r3, 0x600
	  bl        0x1893A8
	  cmpwi     r3, 0
	  beq-      .loc_0xCC
	  lis       r3, 0x10
	  addi      r3, r3, 0x4
	  bl        0x1892A0
	  lwz       r0, 0x4(r29)
	  add       r0, r0, r31
	  stw       r0, 0x4(r29)
	  lwz       r0, 0x0(r29)
	  sub       r0, r0, r31
	  stw       r0, 0x0(r29)

	.loc_0xCC:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
