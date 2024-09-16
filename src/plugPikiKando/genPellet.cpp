#include "Generator.h"
#include "sysNew.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "genPellet"); }

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
 * Address:	........
 * Size:	000070
 */
GenObjectPellet::GenObjectPellet()
    : GenObject('pelt', "ペレットをうむ")
{
	_18 = 0;
}

/*
 * --INFO--
 * Address:	80099D1C
 * Size:	000080
 */
static GenObjectPellet* makeObjectPellet()
{
	return new GenObjectPellet();
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x28
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        -0x52D2C
	  mr.       r31, r3
	  beq-      .loc_0x68
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  addi      r5, r4, 0x904
	  lis       r4, 0x7065
	  addi      r6, r3, 0x910
	  addi      r3, r31, 0
	  addi      r4, r4, 0x6C74
	  bl        0x40F5C
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802B
	  stw       r0, 0x4(r31)
	  addi      r0, r3, 0x984
	  stw       r0, 0x4(r31)
	  addi      r3, r31, 0x1C
	  bl        -0x55F1C
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x68:
	  mr        r3, r31
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80099D9C
 * Size:	00008C
 */
void GenObjectPellet::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x7065
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x6C74
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x800A
	  lis       r4, 0x802B
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  subi      r6, r6, 0x62E4
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  addi      r5, r4, 0x910
	  addi      r4, r3, 0x2E30
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
 * Address:	80099E28
 * Size:	000054
 */
void GenObjectPellet::doRead(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x1C
	  bl        -0x55DA4
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x1C(r31)
	  bl        -0x1204
	  stw       r3, 0x18(r31)
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x40
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x40:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80099E7C
 * Size:	000070
 */
void GenObjectPellet::doWrite(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x18(r30)
	  bl        -0x1218
	  addi      r4, r3, 0x2C
	  lwz       r0, 0x2C(r3)
	  addi      r3, r30, 0x20
	  addi      r4, r4, 0x4
	  stw       r0, 0x1C(r30)
	  li        r5, 0x5
	  bl        0x17AB08
	  addi      r3, r30, 0x1C
	  addi      r4, r31, 0
	  bl        -0x55EC0
	  addi      r3, r30, 0x1C
	  bl        -0x55D78
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
 * Address:	80099EEC
 * Size:	000040
 */
void GenObjectPellet::updateUseList(Generator*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x1C(r4)
	  bl        -0x11E0
	  mr.       r4, r3
	  beq-      .loc_0x30
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x44(r4)
	  bl        -0x1414

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80099F2C
 * Size:	000100
 */
void* GenObjectPellet::birth(BirthInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x1C
	  stw       r30, 0x30(r1)
	  addi      r30, r4, 0
	  bl        -0x55DF4
	  lwz       r3, 0x301C(r13)
	  li        r5, 0
	  lwz       r4, 0x1C(r31)
	  bl        -0x19AC
	  mr.       r31, r3
	  beq-      .loc_0xE4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0xC(r30)
	  mr        r3, r31
	  lwz       r0, 0x10(r30)
	  li        r4, 0
	  stw       r5, 0x88(r31)
	  stw       r0, 0x8C(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x90(r31)
	  lfs       f0, 0x8C(r31)
	  stfs      f0, 0xA0(r31)
	  lwz       r0, 0x24(r30)
	  stw       r0, 0x64(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r30)
	  lwz       r3, 0x28(r3)
	  lwz       r0, 0x34(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xB4
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r31)

	.loc_0xB4:
	  lwz       r3, 0x55C(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  lfs       f0, 0xFC(r3)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  lwz       r3, 0x470(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0xE4:
	  mr        r3, r31
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}
