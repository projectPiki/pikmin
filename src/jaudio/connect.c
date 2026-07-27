#include "jaudio/connect.h"
#include "jaudio/aramcall.h"
#include "jaudio/bx.h"
#include "jaudio/debug.h"
#include "jaudio/heapctrl.h"
#include <stddef.h>

static s16 WS_V2P_TABLE[0x100];
static s16 BNK_V2P_TABLE[0x100];

/**
 * @TODO: Documentation
 */
static int UpdateWave(WaveArchive_* arc, Ctrl_* ctrl, u32 base)
{
	u32 i = 0;
	for (; i < ctrl->count; i++) {
		WaveID_* wave = ctrl->waveIDs[i];
		wave->data    = arc->waves[i + base];
		if (arc->heap.startAddress) {
			Jac_SelfAllocHeap(&wave->heap, &arc->heap, wave->data->length + 0x1f & 0xffffffe0,
			                  arc->heap.startAddress + wave->data->srcAddress);
		}
	}
	return i + base;
}

/**
 * @TODO: Documentation
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
		while (index < cdf->count) {
			if ((cdf->waveIDs[index]->id & 0xffff) == b) {
				break;
			}
			index++;
		}

		if (index != cdf->count) {
			JAUDIO_PRINT("UpdateWave_Extern: scene=%d index=%d\n", a, index);
			WaveID_** wave2 = &cdf->waveIDs[index];
			if ((*wave2)->heap.startAddress) {
				wave->data = (*wave2)->data;
				Jac_SelfInitHeap(&wave->heap, (*wave2)->heap.startAddress, 0, (*wave2)->heap.memoryType);
				Jac_SetGroupHeap(&wave->heap, &(*wave2)->heap);
			} else {
				WaveArchive_* wave3        = bank->waveGroups[a];
				wave->data                 = wave3->waves[index];
				wave->loadStatus           = 0;
				wave->data->fileLoadStatus = &wave->loadStatus;
				LoadAram_One(wave3->filePath, wave->data->srcAddress, wave->data->length, &wave->loadStatus, &wave->heap);
				Jac_SetGroupHeap(&wave->heap, &wave3->heap);
			}
		}
	}
	return TRUE;
}

/**
 * @TODO: Documentation
 */
void Jac_SceneClose(WaveArchiveBank_* bank, CtrlGroup_* group, u32 id, BOOL set)
{
	WaveArchive_* arc;
	SCNE_* scene;

	scene = group->scenes[id];
	arc   = bank->waveGroups[id];
	Jac_DeleteHeap(&arc->heap);
	arc->fileLoadStatus = 0;

	if (set && scene->dependencyCount) {
		for (u32 i = 0; i < scene->dependencyCount; i++) {
			Jac_SceneClose(bank, group, scene->dependencyIds[i], TRUE);
		}
	}

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
BOOL Jac_SceneSet(WaveArchiveBank_* bank, CtrlGroup_* group, u32 id, BOOL set)
{
	WaveArchive_* arc;
	int stat = 0;
	SCNE_* scene;
	Ctrl_* cdf;
	u32 i;

	JAUDIO_PRINT("Jac_SceneSet: id=%d\n", id);
	arc = bank->waveGroups[id];
	!arc;

	if (arc->heap.startAddress && arc->fileLoadStatus) {
		for (i = 0; i < arc->waveCount; i++) {
			arc->waves[i]->fileLoadStatus = &arc->fileLoadStatus;
		}
	} else {
		arc->fileLoadStatus = 0;
		for (i = 0; i < arc->waveCount; i++) {
			arc->waves[i]->fileLoadStatus = &arc->fileLoadStatus;
		}

		if (LoadAram_All(arc->filePath, &arc->fileLoadStatus, &arc->heap) == 0) {
			return FALSE;
		}
	}

	JAUDIO_PRINT("Jac_SceneSet: bank=%x\n", bank);
	scene = group->scenes[id];
	cdf   = scene->cdf;
	if (cdf) {
		stat = UpdateWave(arc, cdf, 0);
	}
	if (scene->cex) {
		if (scene->externalMode == 0) {
			UpdateWave(arc, scene->cex, stat);
		} else {
			UpdateWave_Extern(bank, group, scene->cex);
		}
	}

	if (set) {
		group->mCurrentSceneIndex = id;
	}
	return TRUE;

	STACK_PAD_VAR(6);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
WaveID_* __GetSoundHandle(CtrlGroup_* group, u32 id, u32 id2)
{
	u16 wId      = id;
	SCNE_* scene = group->scenes[id2];
	Ctrl_* ctrl;

	ctrl = scene->cdf;
	if (ctrl) {
		WaveID_* wave = SearchWave(ctrl, wId);
		if (wave && wave->data && (int)wave->data != 0xffffffff) {
			return wave;
		}
	}

	ctrl = scene->cex;
	if (ctrl) {
		WaveID_* wave = SearchWave(ctrl, wId);
		if (wave && wave->data && (int)wave->data != 0xffffffff) {
			return wave;
		}
	}

	for (u32 i = 0; i < scene->dependencyCount; i++) {
		WaveID_* wave = __GetSoundHandle(group, id, scene->dependencyIds[i]);
		if (wave && wave->data && (int)wave->data != 0xffffffff) {
			return wave;
		}
	}
	return NULL;
}

/**
 * @TODO: Documentation
 */
WaveID_* GetSoundHandle(CtrlGroup_* group, u32 flag)
{
	WaveID_* wave = __GetSoundHandle(group, flag, group->mCurrentSceneIndex);
	if (wave == NULL) {
		return NULL;
	}
	if (wave->data == NULL) {
		return NULL;
	}

	JAUDIO_PRINT("GetSoundHandle: flag=%x\n", flag);
	u32* ptr = wave->data->fileLoadStatus;
	if (ptr == NULL) {
		return NULL;
	}

	if (*ptr == 0) {
		JAUDIO_PRINT("GetSoundHandle: unavailable flag=%x scene=%d data=%p status=%d\n", flag,
		             group->mCurrentSceneIndex, wave->data, *ptr);
		return NULL;
	}

	return wave;
}

/**
 * @TODO: Documentation
 */
u16 Jac_WsVirtualToPhysical(u16 vID)
{
	return WS_V2P_TABLE[vID];
}

/**
 * @TODO: Documentation
 */
u16 Jac_BnkVirtualToPhysical(u16 vID)
{
	return BNK_V2P_TABLE[vID];
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
u16 Jac_BnkPhysicalToVirtual(u16 bnk)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
u16 Jac_WsPhysicalToVirtual(u16 ws)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
void Jac_WsConnectTableSet(u32 id, u32 val)
{
	if (id != 0xffff && id < 0x100 && WS_V2P_TABLE[id] == -1) {
		WS_V2P_TABLE[id] = val;
		JAUDIO_PRINT("Jac_WsConnectTableSet: id=%d (0x%x) value=%d\n", id, id, val);
	}
}

/**
 * @TODO: Documentation
 */
void Jac_BnkConnectTableSet(u32 id, u32 val)
{
	if (id != 0xffff && id < 0x100 && BNK_V2P_TABLE[id] == -1) {
		BNK_V2P_TABLE[id] = val;
		JAUDIO_PRINT("Jac_BnkConnectTableSet: id=%d (0x%x) value=%d\n", id, id, val);
	}
}

/**
 * @TODO: Documentation
 */
void Jac_ConnectTableInit()
{
	for (int i = 0; i < 0x100; i++) {
		WS_V2P_TABLE[i]  = -1;
		BNK_V2P_TABLE[i] = -1;
	}
}
