#include "jaudio/connect.h"
#include "jaudio/heapctrl.h"
#include "jaudio/bx.h"
#include "jaudio/aramcall.h"

static s16 WS_V2P_TABLE[0x100];
static s16 BNK_V2P_TABLE[0x100];

/*
 * --INFO--
 * Address:	8000C860
 * Size:	0000A0
 */
static int UpdateWave(WaveArchive_* arc, Ctrl_* ctrl, u32 base)
{
	u32 i = 0;
	for (; i < ctrl->count; i++) {
		WaveID_* wave = ctrl->waveIDs[i];
		wave->wave    = arc->waves[i + base];
		if (arc->heap._08) {
			Jac_SelfAllocHeap(&wave->heap, &arc->heap, wave->wave->_0C + 0x1f & 0xffffffe0, arc->heap._08 + wave->wave->_08);
		}
	}
	return i + base;
}

/*
 * --INFO--
 * Address:	8000C900
 * Size:	000174
 */
static BOOL UpdateWave_Extern(WaveArchiveBank_* bank, CtrlGroup_* group, Ctrl_* ctrl)
{
	u32 i = 0;
	for (; i < ctrl->count; i++) {
		WaveID_* wave = ctrl->waveIDs[i];
		u32 a         = wave->id >> 0x10;
		u32* ptr      = &a;
		if (wave->heap._08) {
			continue;
		}
		Ctrl_* cdf = group->scenes[a]->cdf;
		u16 index  = 0;
		u16* ptr2  = &index;
		while (index < cdf->count && (u16)cdf->waveIDs[index]->heap._04 < wave->id) {
			index++;
		}

		if (index != cdf->count) {
			WaveID_** wave2 = &cdf->waveIDs[index];
			if ((*wave2)->heap._08) {
				wave->wave = (*wave2)->wave;
				Jac_SelfInitHeap(&wave->heap, wave->heap._08, 0, (*wave2)->heap._01);
				Jac_SetGroupHeap(&wave->heap, &(*wave2)->heap);
			} else {
				WaveArchive_* wave3 = bank->waveGroups[a];
				wave->wave          = wave3->waves[index];
				wave->_30           = 0;
				wave->wave->_24     = &wave->heap._08;
				LoadAram_One(wave3->arcName, wave->wave->_08, wave->wave->_0C, &wave->heap._08, &wave->heap);
				Jac_SetGroupHeap(&wave->heap, &wave3->heap);
			}
		}
	}
	return TRUE;
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
void Jac_SceneClose(WaveArchiveBank_* bank, CtrlGroup_* group, u32 id, BOOL set)
{
	WaveArchive_* arc;
	SCNE_* scene;

	scene = group->scenes[id];
	arc   = bank->waveGroups[id];
	Jac_DeleteHeap(&arc->heap);
	arc->_6C = 0;

	if (set && scene->_08) {
		for (u32 i = 0; i < scene->_08; i++) {
			Jac_SceneClose(bank, group, scene->_18[i], TRUE);
		}
	}

	u32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	8000CB20
 * Size:	00015C
 */
BOOL Jac_SceneSet(WaveArchiveBank_* bank, CtrlGroup_* group, u32 id, BOOL set)
{
	u32* idp = &id;
	int stat = 0;
	WaveArchive_* arc;
	SCNE_* scene;

	arc = bank->waveGroups[id];
	if (arc->heap._08 && arc->_6C) {
		for (u32 i = 0; i < arc->waveCount; i++) {
			arc->waves[i]->_24 = &arc->_6C;
		}
	} else {
		arc->_6C = 0;
		for (u32 i = 0; i < arc->waveCount; i++) {
			arc->waves[i]->_24 = &arc->_6C;
		}

		if (LoadAram_All(arc->arcName, &arc->_6C, &arc->heap) == 0) {
			return FALSE;
		}
	}

	scene = group->scenes[id];
	if (scene->cdf) {
		stat = UpdateWave(arc, scene->cdf, 0);
	}
	if (scene->cex) {
		if (scene->_04 == 0) {
			UpdateWave(arc, scene->cex, stat);
		} else {
			UpdateWave_Extern(bank, group, scene->cex);
		}
	}

	if (set) {
		group->_04 = id;
	}
	return TRUE;

	u32 badcompiler[6];
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
static WaveID_* SearchWave(Ctrl_* ctrl, u32 flag)
{
	for (u32 i = 0; i < ctrl->count; i++) {
		WaveID_* wave = ctrl->waveIDs[i];
		if ((u16)wave->id == flag) {
			return wave;
		}
	}
	return NULL;
}

/*
 * --INFO--
 * Address:	8000CCE0
 * Size:	00010C
 */
WaveID_* __GetSoundHandle(CtrlGroup_* group, u32 id, u32 id2)
{
	u16 wId      = id;
	SCNE_* scene = group->scenes[id2];
	Ctrl_* ctrl;

	ctrl = scene->cdf;
	if (ctrl) {
		WaveID_* wave = SearchWave(ctrl, wId);
		if (wave && wave->wave && (int)wave->wave != 0xffffffff) {
			return wave;
		}
	}

	ctrl = scene->cex;
	if (ctrl) {
		WaveID_* wave = SearchWave(ctrl, wId);
		if (wave && wave->wave && (int)wave->wave != 0xffffffff) {
			return wave;
		}
	}

	for (u32 i = 0; i < scene->_08; i++) {
		WaveID_* wave = __GetSoundHandle(group, id, scene->_18[i]);
		if (wave && wave->wave && (int)wave->wave != 0xffffffff) {
			return wave;
		}
	}
	return NULL;
}

/*
 * --INFO--
 * Address:	8000CE00
 * Size:	000074
 */
WaveID_* GetSoundHandle(CtrlGroup_* group, u32 flag)
{
	u32* flagptr  = &flag;
	WaveID_* wave = __GetSoundHandle(group, flag, group->_04);
	if (wave == NULL) {
		return NULL;
	}
	if (wave->wave == NULL) {
		return NULL;
	}
	u32* ptr = wave->wave->_24;
	if (ptr == NULL) {
		return NULL;
	}
	if (*ptr == 0) {
		return NULL;
	}
	return wave;

	u32 badcompiler[4];
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
