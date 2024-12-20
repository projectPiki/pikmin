#include "P2D/Stream.h"
#include "sysNew.h"

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
 * Address:	801B3274
 * Size:	0000C4
 */
void* P2DStream::getResource(int)
{
	u8 resType = mStream->readByte();
	u8 resSize = mStream->readByte();
	u8 size    = resSize;
	void* res  = nullptr;
	if (resSize) {
		res = new u8[resSize + 1];
		switch (resType) {
		case 0:
		case 2:
			mStream->read(res, resSize);
			((u8*)res)[size & 0xFF] = 0;
			break;
		case 1:
			break;
		}
	}

	return res;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  mr        r27, r3
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  lwz       r3, 0x0(r27)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r29,r3,0,24,31
	  addi      r31, r3, 0
	  li        r28, 0
	  beq-      .loc_0xAC
	  addi      r3, r29, 0x1
	  bl        -0x16C2C4
	  rlwinm    r0,r30,0,24,31
	  cmpwi     r0, 0x1
	  addi      r30, r3, 0
	  addi      r28, r30, 0
	  beq-      .loc_0xAC
	  bge-      .loc_0x7C
	  cmpwi     r0, 0
	  bge-      .loc_0x84
	  b         .loc_0xAC

	.loc_0x7C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xAC

	.loc_0x84:
	  lwz       r3, 0x0(r27)
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r31,0,24,31
	  li        r3, 0
	  stbx      r3, r30, r0

	.loc_0xAC:
	  mr        r3, r28
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B3338
 * Size:	000090
 */
void P2DStream::align(int alignment)
{
	int pos     = mStream->getPosition();
	int newPos  = alignment + pos;
	u32 realign = ~(alignment - 1 | alignment - 1);
	int diff    = (realign & (newPos - 1)) - pos;
	for (int i = 0; i < diff; i++) {
		mStream->readByte();
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r4
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  subi      r0, r30, 0x1
	  add       r4, r30, r3
	  not       r5, r0
	  subi      r0, r4, 0x1
	  and       r0, r5, r0
	  sub       r31, r0, r3
	  li        r30, 0
	  b         .loc_0x6C

	.loc_0x54:
	  lwz       r3, 0x0(r29)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1

	.loc_0x6C:
	  cmpw      r30, r31
	  blt+      .loc_0x54
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
