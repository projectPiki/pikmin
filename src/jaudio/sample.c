#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Limit16(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Jac_mixcopy(s16*, s16*, s16*, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005F00
 * Size:	000030
 */
void Jac_imixcopy(s16*, s16*, s16*, s32)
{
	/*
	.loc_0x0:
	  mtctr     r6
	  cmpwi     r6, 0
	  blelr-

	.loc_0xC:
	  lha       r0, 0x0(r3)
	  addi      r3, r3, 0x2
	  sth       r0, 0x0(r5)
	  lha       r0, 0x0(r4)
	  addi      r4, r4, 0x2
	  sth       r0, 0x2(r5)
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Jac_bcopyW(s16*, s16*, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80005F40
 * Size:	00003C
 */
void Jac_bcopyfast(u32*, u32*, u32)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r5,28,4,31
	  mtctr     r0
	  beqlr-

	.loc_0xC:
	  lwz       r0, 0x0(r3)
	  lwz       r5, 0x4(r3)
	  lwz       r6, 0x8(r3)
	  lwz       r7, 0xC(r3)
	  addi      r3, r3, 0x10
	  stw       r0, 0x0(r4)
	  stw       r5, 0x4(r4)
	  stw       r6, 0x8(r4)
	  stw       r7, 0xC(r4)
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80005F80
 * Size:	0000FC
 */
void Jac_bcopy(void*, void*, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r6,r3,0,30,31
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,30,31
	  cmplw     r6, r0
	  rlwinm    r8,r3,0,30,31
	  stwu      r1, -0x8(r1)
	  rlwinm    r7,r4,0,30,31
	  bne-      .loc_0x34
	  rlwinm.   r0,r5,0,28,31
	  bne-      .loc_0x34
	  bl        -0x6C
	  b         .loc_0xEC

	.loc_0x34:
	  rlwinm    r6,r8,0,24,31
	  rlwinm    r0,r7,0,24,31
	  cmplw     r6, r0
	  bne-      .loc_0xCC
	  cmpwi     r5, 0x10
	  blt-      .loc_0xCC
	  cmplwi    r6, 0
	  beq-      .loc_0x7C
	  subfic    r6, r8, 0x4
	  b         .loc_0x74

	.loc_0x5C:
	  lbz       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  subi      r5, r5, 0x1
	  subi      r6, r6, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1

	.loc_0x74:
	  rlwinm.   r0,r6,0,24,31
	  bne+      .loc_0x5C

	.loc_0x7C:
	  rlwinm    r0,r5,30,2,31
	  mtctr     r0
	  cmpwi     r5, 0x4
	  blt-      .loc_0xA4

	.loc_0x8C:
	  lwz       r0, 0x0(r3)
	  addi      r3, r3, 0x4
	  subi      r5, r5, 0x4
	  stw       r0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x8C

	.loc_0xA4:
	  cmpwi     r5, 0
	  beq-      .loc_0xEC
	  mtctr     r5
	  ble-      .loc_0xEC

	.loc_0xB4:
	  lbz       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0xB4
	  b         .loc_0xEC

	.loc_0xCC:
	  mtctr     r5
	  cmpwi     r5, 0
	  ble-      .loc_0xEC

	.loc_0xD8:
	  lbz       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0xD8

	.loc_0xEC:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80006080
 * Size:	00002C
 */
void Jac_bzerofast(u32*, u32)
{
	/*
	.loc_0x0:
	  rlwinm.   r4,r4,28,4,31
	  li        r0, 0
	  mtctr     r4
	  beqlr-

	.loc_0x10:
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)
	  addi      r3, r3, 0x10
	  bdnz+     .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800060C0
 * Size:	0000E0
 */
void Jac_bzero(void*, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r5,r3,0,30,31
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r3,0,30,31
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x38
	  rlwinm.   r0,r4,0,27,31
	  bne-      .loc_0x28
	  bl        0x1F0BD0
	  b         .loc_0xD0

	.loc_0x28:
	  rlwinm.   r0,r4,0,28,31
	  bne-      .loc_0x38
	  bl        -0x70
	  b         .loc_0xD0

	.loc_0x38:
	  cmpwi     r4, 0x10
	  blt-      .loc_0xB4
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x6C
	  subfic    r6, r5, 0x4
	  li        r5, 0
	  b         .loc_0x64

	.loc_0x54:
	  stb       r5, 0x0(r3)
	  addi      r3, r3, 0x1
	  subi      r4, r4, 0x1
	  subi      r6, r6, 0x1

	.loc_0x64:
	  rlwinm.   r0,r6,0,24,31
	  bne+      .loc_0x54

	.loc_0x6C:
	  rlwinm    r0,r4,30,2,31
	  li        r5, 0
	  mtctr     r0
	  cmpwi     r4, 0x4
	  blt-      .loc_0x90

	.loc_0x80:
	  stw       r5, 0x0(r3)
	  addi      r3, r3, 0x4
	  subi      r4, r4, 0x4
	  bdnz+     .loc_0x80

	.loc_0x90:
	  cmpwi     r4, 0
	  beq-      .loc_0xD0
	  li        r0, 0
	  mtctr     r4
	  ble-      .loc_0xD0

	.loc_0xA4:
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0xA4
	  b         .loc_0xD0

	.loc_0xB4:
	  li        r0, 0
	  mtctr     r4
	  cmpwi     r4, 0
	  ble-      .loc_0xD0

	.loc_0xC4:
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0xC4

	.loc_0xD0:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void SampleDecoder_Alloc(u8*, s32, DECODER_FORMAT, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void SampleDecoder_Init(SD_*, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001FC
 */
void SampleGet(SD_*, s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void SampleDecoder(SD_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void DecodeADPCM(u8*, s16*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void DecodeADPCM2(u8*, s16*)
{
	// UNUSED FUNCTION
}
