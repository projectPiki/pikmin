#include "Generator.h"
#include "sysNew.h"
#include "TekiPersonality.h"
#include "Dolphin/os.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "敵を発生"); // 'spawn enemies'
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
 * Address:	8011B2CC
 * Size:	000040
 */
static GenObjectTeki* makeObjectTeki() { return new GenObjectTeki(); }

/*
 * --INFO--
 * Address:	8011B30C
 * Size:	000088
 */
void GenObjectTeki::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x7465
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x6B69
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r4, 0x8012
	  lis       r3, 0x802C
	  lwz       r0, 0x0(r7)
	  subi      r6, r4, 0x4D34
	  lwz       r4, 0x8(r7)
	  addi      r5, r3, 0x4094
	  rlwinm    r0,r0,4,0,27
	  add       r3, r4, r0
	  stw       r6, 0x4(r3)
	  li        r4, 0xA
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B394
 * Size:	00008C
 */
GenObjectTeki::GenObjectTeki()
    : GenObject('teki', "敵を生む") // 'create enemies'
{
	mTekiType    = TEKI_Frog;
	mPersonality = new TekiPersonality();
}

/*
 * --INFO--
 * Address:	8011B420
 * Size:	000094
 */
void GenObjectTeki::doRead(RandomAccessStream& input)
{
	if (mVersion <= 8) {
		mTekiType = input.readInt();
	} else {
		mTekiType = (u8)input.readByte();
	}

	mPersonality->read(input, mVersion);
}

/*
 * --INFO--
 * Address:	8011B4B4
 * Size:	000068
 */
void GenObjectTeki::doWrite(RandomAccessStream& output)
{
	output.writeByte((char)mTekiType);
	mPersonality->write(output);
}

/*
 * --INFO--
 * Address:	8011B51C
 * Size:	000070
 */
void GenObjectTeki::updateUseList(Generator*, int)
{
	if (mTekiType < TEKI_START || mTekiType >= TEKI_TypeCount) {
		return;
	}

	tekiMgr->mUsingType[mTekiType] = true;

	if (!tekiMgr->mTekiParams[mTekiType]) {
		return;
	}
	/*
	.loc_0x0:
	  lwz       r4, 0x1C(r3)
	  cmpwi     r4, 0
	  bltlr-
	  cmpwi     r4, 0x23
	  blt-      .loc_0x18
	  blr

	.loc_0x18:
	  lwz       r0, 0x3160(r13)
	  li        r5, 0x1
	  add       r4, r0, r4
	  stb       r5, 0x164(r4)
	  lwz       r0, 0x1C(r3)
	  lwz       r4, 0x3160(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r4, r0
	  lwz       r3, 0x4C(r3)
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0xC(r3)
	  cmpwi     r0, 0
	  bltlr-
	  cmpwi     r0, 0x23
	  bgelr-
	  add       r3, r4, r0
	  stb       r5, 0x164(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011B58C
 * Size:	000120
 */
void* GenObjectTeki::birth(BirthInfo& info)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r4
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x1C(r29)
	  bl        0x2F598
	  mr.       r31, r3
	  bne-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x104

	.loc_0x3C:
	  lwz       r3, 0x18(r29)
	  lfs       f0, 0x0(r30)
	  stfsu     f0, 0x4(r3)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x18(r29)
	  lfs       f0, 0x18(r30)
	  stfsu     f0, 0x10(r3)
	  lfs       f0, 0x1C(r30)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x20(r30)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x10(r30)
	  lwz       r3, 0x18(r29)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x2C8(r31)
	  lwz       r4, 0x18(r29)
	  bl        0x31770
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x170(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0x10(r30)
	  stw       r3, 0x88(r31)
	  stw       r0, 0x8C(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x90(r31)
	  lwz       r3, 0x24(r30)
	  lwz       r3, 0x28(r3)
	  lwz       r0, 0x34(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xF0
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r31)

	.loc_0xF0:
	  lwz       r4, 0x24(r30)
	  mr        r3, r31
	  lwz       r4, 0x28(r4)
	  lwz       r0, 0x24(r4)
	  stw       r0, 0x34(r31)

	.loc_0x104:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}
