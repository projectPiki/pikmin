#include "jaudio/connect.h"
#include "jaudio/heapctrl.h"

static s16 WS_V2P_TABLE[0x100];
static s16 BNK_V2P_TABLE[0x100];

/*
 * --INFO--
 * Address:	8000C860
 * Size:	0000A0
 */
static void UpdateWave(WaveArchive_*, Ctrl_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x7C

	.loc_0x28:
	  add       r0, r30, r29
	  addi      r4, r31, 0x8
	  rlwinm    r3,r0,2,0,29
	  lwzx      r4, r28, r4
	  addi      r0, r3, 0x74
	  lwzx      r0, r27, r0
	  stw       r0, 0x34(r4)
	  lwz       r6, 0x48(r27)
	  cmplwi    r6, 0
	  beq-      .loc_0x74
	  lwz       r7, 0x34(r4)
	  addi      r3, r4, 0x4
	  addi      r4, r27, 0x40
	  lwz       r5, 0xC(r7)
	  lwz       r0, 0x8(r7)
	  addi      r5, r5, 0x1F
	  rlwinm    r5,r5,0,0,26
	  add       r6, r6, r0
	  bl        0x23D0

	.loc_0x74:
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x4

	.loc_0x7C:
	  lwz       r0, 0x4(r28)
	  cmplw     r30, r0
	  blt+      .loc_0x28
	  add       r3, r30, r29
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000C900
 * Size:	000174
 */
static void UpdateWave_Extern(WaveArchiveBank_*, CtrlGroup_*, Ctrl_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  li        r30, 0
	  li        r26, 0
	  b         .loc_0x150

	.loc_0x28:
	  addi      r0, r26, 0x8
	  lwzx      r31, r29, r0
	  lwz       r3, 0x0(r31)
	  rlwinm    r0,r3,16,16,31
	  rlwinm    r7,r3,0,16,31
	  stw       r0, 0x20(r1)
	  lwz       r0, 0xC(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x148
	  lwz       r3, 0x20(r1)
	  li        r0, 0
	  rlwinm    r6,r3,2,0,29
	  addi      r3, r6, 0xC
	  lwzx      r3, r28, r3
	  lwz       r8, 0xC(r3)
	  stw       r0, 0x1C(r1)
	  lwz       r5, 0x4(r8)
	  b         .loc_0x98

	.loc_0x70:
	  rlwinm    r3,r4,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r3, r8, r0
	  lwz       r0, 0x0(r3)
	  rlwinm    r0,r0,0,16,31
	  cmplw     r0, r7
	  beq-      .loc_0xA4
	  lwz       r3, 0x1C(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x1C(r1)

	.loc_0x98:
	  lwz       r4, 0x1C(r1)
	  cmplw     r4, r5
	  blt+      .loc_0x70

	.loc_0xA4:
	  cmplw     r4, r5
	  beq-      .loc_0x148
	  rlwinm    r4,r4,2,0,29
	  addi      r25, r4, 0x8
	  add       r25, r8, r25
	  lwz       r3, 0x0(r25)
	  lwz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  lwz       r0, 0x34(r3)
	  addi      r3, r31, 0x4
	  li        r5, 0
	  stw       r0, 0x34(r31)
	  lwz       r6, 0x0(r25)
	  lwz       r4, 0xC(r6)
	  lbz       r6, 0x5(r6)
	  bl        0x227C
	  lwz       r4, 0x0(r25)
	  addi      r3, r31, 0x4
	  addi      r4, r4, 0x4
	  bl        0x23AC
	  b         .loc_0x148

	.loc_0xFC:
	  addi      r0, r6, 0x8
	  addi      r3, r4, 0x74
	  lwzx      r25, r27, r0
	  li        r0, 0
	  addi      r6, r31, 0x30
	  addi      r7, r31, 0x4
	  lwzx      r4, r25, r3
	  addi      r3, r25, 0
	  stw       r4, 0x34(r31)
	  stw       r0, 0x30(r31)
	  lwz       r4, 0x34(r31)
	  stw       r6, 0x24(r4)
	  lwz       r5, 0x34(r31)
	  lwz       r4, 0x8(r5)
	  lwz       r5, 0xC(r5)
	  bl        0x11A8
	  addi      r3, r31, 0x4
	  addi      r4, r25, 0x40
	  bl        0x235C

	.loc_0x148:
	  addi      r30, r30, 0x1
	  addi      r26, r26, 0x4

	.loc_0x150:
	  lwz       r0, 0x4(r29)
	  cmplw     r30, r0
	  blt+      .loc_0x28
	  lmw       r25, 0x2C(r1)
	  li        r3, 0x1
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000CA80
 * Size:	00009C
 */
void Jac_SceneClose(WaveArchiveBank_* bank, CtrlGroup_* group, u32 flag, BOOL set)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  add       r3, r26, r0
	  add       r4, r27, r0
	  addi      r28, r6, 0
	  lwz       r30, 0x8(r3)
	  lwz       r29, 0xC(r4)
	  addi      r3, r30, 0x40
	  bl        0x254C
	  li        r31, 0
	  cmpwi     r28, 0
	  stw       r31, 0x6C(r30)
	  beq-      .loc_0x88
	  lwz       r0, 0x8(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  li        r30, 0
	  b         .loc_0x7C

	.loc_0x5C:
	  addi      r0, r31, 0x18
	  addi      r3, r26, 0
	  lwzx      r5, r29, r0
	  addi      r4, r27, 0
	  li        r6, 0x1
	  bl        .loc_0x0
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x4

	.loc_0x7C:
	  lwz       r0, 0x8(r29)
	  cmplw     r30, r0
	  blt+      .loc_0x5C

	.loc_0x88:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000CB20
 * Size:	00015C
 */
BOOL Jac_SceneSet(WaveArchiveBank_* bank, CtrlGroup_* group, u32 flag, BOOL set)
{
	if (set) {
		group->_04 = flag;
	}
	return TRUE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stmw      r25, 0x3C(r1)
	  addi      r25, r4, 0
	  addi      r26, r6, 0
	  li        r27, 0
	  stw       r5, 0x10(r1)
	  stw       r3, 0x8(r1)
	  lwz       r29, 0x10(r1)
	  lwz       r30, 0x8(r1)
	  rlwinm    r31,r29,2,0,29
	  add       r3, r30, r31
	  lwz       r28, 0x8(r3)
	  lwz       r0, 0x48(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r0, 0x6C(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  addi      r5, r28, 0x6C
	  li        r6, 0
	  li        r3, 0
	  b         .loc_0x74

	.loc_0x60:
	  addi      r0, r3, 0x74
	  addi      r6, r6, 0x1
	  lwzx      r4, r28, r0
	  addi      r3, r3, 0x4
	  stw       r5, 0x24(r4)

	.loc_0x74:
	  lwz       r0, 0x70(r28)
	  cmplw     r6, r0
	  blt+      .loc_0x60
	  b         .loc_0xD8

	.loc_0x84:
	  li        r6, 0
	  addi      r5, r28, 0x6C
	  stw       r6, 0x6C(r28)
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x98:
	  addi      r0, r3, 0x74
	  addi      r6, r6, 0x1
	  lwzx      r4, r28, r0
	  addi      r3, r3, 0x4
	  stw       r5, 0x24(r4)

	.loc_0xAC:
	  lwz       r0, 0x70(r28)
	  cmplw     r6, r0
	  blt+      .loc_0x98
	  addi      r3, r28, 0
	  addi      r4, r28, 0x6C
	  addi      r5, r28, 0x40
	  bl        0xFBC
	  cmplwi    r3, 0
	  bne-      .loc_0xD8
	  li        r3, 0
	  b         .loc_0x148

	.loc_0xD8:
	  add       r3, r25, r31
	  lwz       r31, 0xC(r3)
	  lwz       r0, 0xC(r31)
	  cmplwi    r0, 0
	  mr        r4, r0
	  beq-      .loc_0x100
	  addi      r3, r28, 0
	  li        r5, 0
	  bl        -0x3B8
	  mr        r27, r3

	.loc_0x100:
	  lwz       r5, 0x10(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x138
	  lwz       r0, 0x4(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x12C
	  addi      r3, r28, 0
	  addi      r4, r5, 0
	  addi      r5, r27, 0
	  bl        -0x3E4
	  b         .loc_0x138

	.loc_0x12C:
	  addi      r3, r30, 0
	  addi      r4, r25, 0
	  bl        -0x354

	.loc_0x138:
	  cmpwi     r26, 0
	  beq-      .loc_0x144
	  stw       r29, 0x4(r25)

	.loc_0x144:
	  li        r3, 0x1

	.loc_0x148:
	  lmw       r25, 0x3C(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000CC80
 * Size:	000044
 */
static void SearchWave(Ctrl_* ctrl, u32 flag)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r3)
	  li        r5, 0
	  mtctr     r0
	  cmplwi    r0, 0
	  ble-      .loc_0x3C

	.loc_0x14:
	  addi      r0, r5, 0x8
	  lwzx      r6, r3, r0
	  lwz       r0, 0x0(r6)
	  rlwinm    r0,r0,0,16,31
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  mr        r3, r6
	  blr

	.loc_0x34:
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x14

	.loc_0x3C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000CCE0
 * Size:	00010C
 */
int* __GetSoundHandle(CtrlGroup_*, u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r30, r3, 0
	  add       r3, r30, r0
	  addi      r31, r4, 0
	  rlwinm    r29,r4,0,16,31
	  lwz       r28, 0xC(r3)
	  lwz       r0, 0xC(r28)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0x64
	  mr        r4, r29
	  bl        -0x9C
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  lwz       r4, 0x34(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x64
	  addis     r0, r4, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0x64
	  b         .loc_0xF8

	.loc_0x64:
	  lwz       r3, 0x10(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  mr        r4, r29
	  bl        -0xD4
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  lwz       r4, 0x34(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x9C
	  addis     r0, r4, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0x9C
	  b         .loc_0xF8

	.loc_0x9C:
	  li        r27, 0
	  li        r29, 0
	  b         .loc_0xE8

	.loc_0xA8:
	  addi      r0, r29, 0x18
	  addi      r3, r30, 0
	  lwzx      r5, r28, r0
	  mr        r4, r31
	  bl        .loc_0x0
	  cmplwi    r3, 0
	  beq-      .loc_0xE0
	  lwz       r4, 0x34(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xE0
	  addis     r0, r4, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0xE0
	  b         .loc_0xF8

	.loc_0xE0:
	  addi      r27, r27, 0x1
	  addi      r29, r29, 0x4

	.loc_0xE8:
	  lwz       r0, 0x8(r28)
	  cmplw     r27, r0
	  blt+      .loc_0xA8
	  li        r3, 0

	.loc_0xF8:
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000CE00
 * Size:	000074
 */
int* GetSoundHandle(CtrlGroup_* group, u32 flag)
{
	// need to figure out this type
	int* a = __GetSoundHandle(group, flag, group->_04);
	if (a == NULL) {
		return NULL;
	}
	if (a[13] == NULL) {
		return NULL;
	}
	return a;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r4, 0xC(r1)
	  lwz       r4, 0xC(r1)
	  lwz       r5, 0x4(r3)
	  bl        -0x138
	  cmplwi    r3, 0
	  bne-      .loc_0x2C
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x2C:
	  lwz       r4, 0x34(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x40:
	  lwz       r4, 0x24(r4)
	  cmplwi    r4, 0
	  bne-      .loc_0x54
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x54:
	  lwz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x64
	  li        r3, 0

	.loc_0x64:
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000CE80
 * Size:	000018
 */
u16 Jac_WsVirtualToPhysical(u16 vID)
{
	return WS_V2P_TABLE[vID];
}

/*
 * --INFO--
 * Address:	8000CEA0
 * Size:	000018
 */
u16 Jac_BnkVirtualToPhysical(u16 vID)
{
	return BNK_V2P_TABLE[vID];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
u16 Jac_BnkPhysicalToVirtual(u16 bnk)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
u16 Jac_WsPhysicalToVirtual(u16 ws)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000CEC0
 * Size:	000050
 */
void Jac_WsConnectTableSet(u32 id, u32 val)
{
	u32* id2 = &id;
	u32* bnk = &val;

	if (id != 0xffff && id < 0x100 && BNK_V2P_TABLE[id] == -1) {
		BNK_V2P_TABLE[id] = *bnk;
	}

	u32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	8000CF20
 * Size:	000050
 */
void Jac_BnkConnectTableSet(u32 id, u32 val)
{
	u32* id2 = &id;
	u32* bnk = &val;

	if (id != 0xffff && id < 0x100 && BNK_V2P_TABLE[id] == -1) {
		BNK_V2P_TABLE[id] = *bnk;
	}

	u32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	8000CF80
 * Size:	00003C
 */
void Jac_ConnectTableInit()
{
	for (int i = 0; i < 0x100; i++) {
		WS_V2P_TABLE[i]  = -1;
		BNK_V2P_TABLE[i] = -1;
	}
}
