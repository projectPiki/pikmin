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
		if (arc->heap.startAddress) {
			Jac_SelfAllocHeap(&wave->heap, &arc->heap, wave->wave->_0C + 0x1f & 0xffffffe0, arc->heap.startAddress + wave->wave->_08);
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
	WaveID_* wave;
	for (u32 i = 0; i < ctrl->count; i++) {
		wave  = ctrl->waveIDs[i];
		u32 a = wave->id >> 16;
		u32 b = wave->id & 0xffff;
		if (wave->heap.startAddress) {
			continue;
		}
		Ctrl_* cdf = group->scenes[a]->cdf;
		u32 index  = 0;
		u32* ptr   = &a;
		u32* ptr2  = &index;
		while (index < cdf->count) {
			if ((cdf->waveIDs[index]->id & 0xffff) == b) {
				break;
			}
			index++;
		}

		if (index != cdf->count) {
			WaveID_** wave2 = &cdf->waveIDs[index];
			if ((*wave2)->heap.startAddress) {
				wave->wave = (*wave2)->wave;
				Jac_SelfInitHeap(&wave->heap, (*wave2)->heap.startAddress, 0, (*wave2)->heap.memoryType);
				Jac_SetGroupHeap(&wave->heap, &(*wave2)->heap);
			} else {
				WaveArchive_* wave3 = bank->waveGroups[a];
				wave->wave          = wave3->waves[index];
				wave->_30           = 0;
				wave->wave->_24     = &wave->_30;
				LoadAram_One(wave3->arcName, wave->wave->_08, wave->wave->_0C, &wave->_30, &wave->heap);
				Jac_SetGroupHeap(&wave->heap, &wave3->heap);
			}
		}
	}
	return TRUE;
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
	WaveArchiveBank_** bankp = &bank;
	u32* idp                 = &id;
	WaveArchive_* arc;
	int stat = 0;
	SCNE_* scene;
	Ctrl_* cdf;
	u32 i;

	arc = bank->waveGroups[id];
	!arc;

	if (arc->heap.startAddress && arc->_6C) {
		for (i = 0; i < arc->waveCount; i++) {
			arc->waves[i]->_24 = &arc->_6C;
		}
	} else {
		arc->_6C = 0;
		for (i = 0; i < arc->waveCount; i++) {
			arc->waves[i]->_24 = &arc->_6C;
		}

		if (LoadAram_All(arc->arcName, &arc->_6C, &arc->heap) == 0) {
			return FALSE;
		}
	}

	scene = group->scenes[id];
	cdf   = scene->cdf;
	if (cdf) {
		stat = UpdateWave(arc, cdf, 0);
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

	if (id != 0xffff && id < 0x100 && WS_V2P_TABLE[id] == -1) {
		WS_V2P_TABLE[id] = *bnk;
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
