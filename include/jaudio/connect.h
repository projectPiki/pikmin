#ifndef _JAUDIO_CONNECT_H
#define _JAUDIO_CONNECT_H

#include "types.h"

typedef struct WaveArchive_ WaveArchive_;
typedef struct WaveArchiveBank_ WaveArchiveBank_;
typedef struct Ctrl_ Ctrl_;
typedef struct CtrlGroup_ CtrlGroup_;

struct WaveArchive_ {
	WaveArchiveBank_* _00; // _00
	                       // TODO
};

struct WaveArchiveBank_ {
	u8 _00[0x40];        // _00
	struct jaheap_* _40; // _40
	int _44;             // _44
	int _48;             // _48
	u8 _4C[0x24];        // _4C
	u32 _70;             // _70
	void** _74;          // _74
	                     // TODO
};

struct Ctrl_ {
	// TODO
};

struct CtrlGroup_ {
	u32 _00;                   // _00
	u32 _04;                   // _04
	u32 _08;                   // _08
	struct WaveArchive_** _0C; // _0C
};

void Jac_SceneClose(WaveArchiveBank_*, CtrlGroup_*, u32, BOOL);
BOOL Jac_SceneSet(WaveArchiveBank_*, CtrlGroup_*, u32, BOOL);
int* GetSoundHandle(CtrlGroup_*, u32);
u16 Jac_WsVirtualToPhysical(u16);
u16 Jac_BnkVirtualToPhysical(u16);
u16 Jac_BnkPhysicalToVirtual(u16);
u16 Jac_WsPhysicalToVirtual(u16);
void Jac_WsConnectTableSet(u32, u32);
void Jac_BnkConnectTableSet(u32, u32);
void Jac_ConnectTableInit();
int* __GetSoundHandle(CtrlGroup_*, u32, u32);

#endif
