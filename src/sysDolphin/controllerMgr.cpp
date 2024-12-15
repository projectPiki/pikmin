#include "types.h"
#include "Controller.h"
#include "Dolphin/pad.h"

static char file[] = __FILE__;
static char name[] = "ControllerMgr";

static PADStatus sControllerPad[4];
static u32 padChannels[4] = { PAD_CHAN0_BIT, PAD_CHAN1_BIT, PAD_CHAN2_BIT, PAD_CHAN3_BIT };

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
 * Address:	800471B4
 * Size:	0000C4
 */
void ControllerMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  subi      r31, r3, 0x2C00
	  addi      r3, r31, 0
	  bl        0x1BE134
	  mr        r3, r31
	  bl        0x1BCB24
	  lbz       r0, 0xA(r31)
	  lis       r3, 0x802A
	  addi      r4, r3, 0x56CC
	  extsb     r0, r0
	  cmpwi     r0, -0x1
	  li        r3, 0
	  bne-      .loc_0x48
	  lwz       r3, 0x0(r4)

	.loc_0x48:
	  addi      r5, r31, 0xC
	  lbz       r0, 0x16(r31)
	  addi      r4, r4, 0x4
	  extsb     r0, r0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x68
	  lwz       r0, 0x0(r4)
	  or        r3, r3, r0

	.loc_0x68:
	  lbz       r0, 0x16(r5)
	  addi      r5, r5, 0xC
	  addi      r4, r4, 0x4
	  extsb     r0, r0
	  cmpwi     r0, -0x1
	  bne-      .loc_0x88
	  lwz       r0, 0x0(r4)
	  or        r3, r3, r0

	.loc_0x88:
	  lbz       r0, 0x16(r5)
	  addi      r4, r4, 0x4
	  extsb     r0, r0
	  cmpwi     r0, -0x1
	  bne-      .loc_0xA4
	  lwz       r0, 0x0(r4)
	  or        r3, r3, r0

	.loc_0xA4:
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  bl        0x1BDAC4

	.loc_0xB0:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80047278
 * Size:	000020
 */
bool ControllerMgr::keyDown(int)
{
	/*
	.loc_0x0:
	  lis       r3, 0x803A
	  lhz       r0, -0x2C00(r3)
	  and       r0, r0, r4
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r0,0,24,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80047298
 * Size:	000028
 */
void ControllerMgr::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x1BE500
	  bl        0x1BDD38
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800472C0
 * Size:	0001F8
 */
void ControllerMgr::updateController(Controller* controller)
{
	u32 keyStatus = 0;

#ifdef _WIN32
	if (keyDown('V'))
		keyStatus |= 0x4000;
	if (keyDown('N'))
		keyStatus |= 0x8000;
	if (keyDown('\r'))
		keyStatus |= 0x1000000;
	if (keyDown('\t'))
		keyStatus |= 0x10000;
	if (keyDown('g'))
		keyStatus |= 0x20000;
	if (keyDown('i'))
		keyStatus |= 0x40000;
	if (keyDown('d'))
		keyStatus |= 0x400000;
	if (keyDown('f'))
		keyStatus |= 0x100000;
	if (keyDown('h'))
		keyStatus |= 0x80000;
	if (keyDown('b'))
		keyStatus |= 0x200000;
	if (keyDown(' '))
		keyStatus |= 0x10;
	if (keyDown('B'))
		keyStatus |= 0x20;
	if (keyDown('%'))
		keyStatus |= 1;
	if (keyDown('\''))
		keyStatus |= 2;
	if (keyDown('&'))
		keyStatus |= 4;
	if (keyDown('('))
		keyStatus |= 8;
	if (keyDown('S'))
		keyStatus |= 0x100;
	if (keyDown('D'))
		keyStatus |= 0x200;
	if (keyDown('A'))
		keyStatus |= 0x400;
	if (keyDown('Z'))
		keyStatus |= 0x800;
#else
	// TODO: decomp

#endif

	controller->mMainStickX = (keyStatus & 0x400000) ? -74 : (keyStatus & 0x100000) ? 74 : 0;
	controller->mMainStickY = (keyStatus & 0x200000) ? -74 : (keyStatus & 0x80000) ? 74 : 0;
	controller->mSubStickX  = (keyStatus & 1) ? -74 : (keyStatus & 2) ? 74 : 0;
	controller->mSubStickY  = (keyStatus & 8) ? -74 : (keyStatus & 4) ? 74 : 0;

	controller->_49 = (keyStatus & 0x1000) ? 0xF : 0;
	controller->_4A = (keyStatus & 0x2000) ? 0xF : 0;
	controller->_4B = (keyStatus & 0x20000) ? 0xAA : 0;
	controller->_4C = (keyStatus & 0x40000) ? 0xAA : 0;

	controller->updateCont(keyStatus);
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x38(r4)
	  lis       r4, 0x803A
	  subi      r5, r4, 0x2C00
	  mulli     r0, r0, 0xC
	  subi      r7, r5, 0xA
	  lbzx      r0, r7, r0
	  subi      r8, r5, 0x9
	  subi      r9, r5, 0x8
	  stb       r0, 0x45(r3)
	  subi      r10, r5, 0x7
	  li        r4, 0
	  lwz       r0, 0x38(r3)
	  mulli     r0, r0, 0xC
	  lbzx      r0, r8, r0
	  stb       r0, 0x46(r3)
	  lwz       r0, 0x38(r3)
	  mulli     r0, r0, 0xC
	  lbzx      r0, r9, r0
	  stb       r0, 0x47(r3)
	  lwz       r0, 0x38(r3)
	  mulli     r0, r0, 0xC
	  lbzx      r0, r10, r0
	  stb       r0, 0x48(r3)
	  lwz       r0, 0x38(r3)
	  mulli     r6, r0, 0xC
	  add       r11, r5, r6
	  lhz       r0, -0xC(r11)
	  rlwinm.   r11,r0,0,23,23
	  beq-      .loc_0x88
	  ori       r4, r4, 0x1000

	.loc_0x88:
	  rlwinm.   r11,r0,0,22,22
	  beq-      .loc_0x94
	  ori       r4, r4, 0x2000

	.loc_0x94:
	  rlwinm.   r11,r0,0,21,21
	  beq-      .loc_0xA0
	  ori       r4, r4, 0x4000

	.loc_0xA0:
	  rlwinm.   r11,r0,0,20,20
	  beq-      .loc_0xAC
	  ori       r4, r4, 0x8000

	.loc_0xAC:
	  rlwinm.   r11,r0,0,27,27
	  beq-      .loc_0xB8
	  oris      r4, r4, 0x1

	.loc_0xB8:
	  rlwinm.   r11,r0,0,26,26
	  beq-      .loc_0xC4
	  oris      r4, r4, 0x4

	.loc_0xC4:
	  rlwinm.   r11,r0,0,25,25
	  beq-      .loc_0xD0
	  oris      r4, r4, 0x2

	.loc_0xD0:
	  lbzx      r11, r7, r6
	  extsb     r7, r11
	  cmpwi     r7, -0x20
	  bge-      .loc_0xE4
	  oris      r4, r4, 0x40

	.loc_0xE4:
	  extsb     r7, r11
	  cmpwi     r7, 0x20
	  ble-      .loc_0xF4
	  oris      r4, r4, 0x10

	.loc_0xF4:
	  lbzx      r8, r8, r6
	  extsb     r7, r8
	  cmpwi     r7, -0x20
	  bge-      .loc_0x108
	  oris      r4, r4, 0x20

	.loc_0x108:
	  extsb     r7, r8
	  cmpwi     r7, 0x20
	  ble-      .loc_0x118
	  oris      r4, r4, 0x8

	.loc_0x118:
	  lbzx      r8, r9, r6
	  extsb     r7, r8
	  cmpwi     r7, -0x20
	  bge-      .loc_0x12C
	  ori       r4, r4, 0x1

	.loc_0x12C:
	  extsb     r7, r8
	  cmpwi     r7, 0x20
	  ble-      .loc_0x13C
	  ori       r4, r4, 0x2

	.loc_0x13C:
	  lbzx      r8, r10, r6
	  extsb     r7, r8
	  cmpwi     r7, -0x20
	  bge-      .loc_0x150
	  ori       r4, r4, 0x8

	.loc_0x150:
	  extsb     r7, r8
	  cmpwi     r7, 0x20
	  ble-      .loc_0x160
	  ori       r4, r4, 0x4

	.loc_0x160:
	  rlwinm.   r7,r0,0,31,31
	  beq-      .loc_0x16C
	  ori       r4, r4, 0x100

	.loc_0x16C:
	  rlwinm.   r7,r0,0,30,30
	  beq-      .loc_0x178
	  ori       r4, r4, 0x200

	.loc_0x178:
	  rlwinm.   r7,r0,0,28,28
	  beq-      .loc_0x184
	  ori       r4, r4, 0x400

	.loc_0x184:
	  rlwinm.   r7,r0,0,29,29
	  beq-      .loc_0x190
	  ori       r4, r4, 0x800

	.loc_0x190:
	  rlwinm.   r0,r0,0,19,19
	  beq-      .loc_0x19C
	  oris      r4, r4, 0x100

	.loc_0x19C:
	  add       r6, r5, r6
	  lbz       r0, -0x4(r6)
	  stb       r0, 0x49(r3)
	  lwz       r0, 0x38(r3)
	  mulli     r0, r0, 0xC
	  add       r6, r5, r0
	  lbz       r0, -0x3(r6)
	  stb       r0, 0x4A(r3)
	  lwz       r0, 0x38(r3)
	  mulli     r0, r0, 0xC
	  add       r6, r5, r0
	  lbz       r0, -0x6(r6)
	  stb       r0, 0x4B(r3)
	  lwz       r0, 0x38(r3)
	  mulli     r0, r0, 0xC
	  add       r5, r5, r0
	  lbz       r0, -0x5(r5)
	  stb       r0, 0x4C(r3)
	  bl        -0x6AD0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
