#ifndef _JAUDIO_CONNECT_H
#define _JAUDIO_CONNECT_H

#include "types.h"

typedef struct WaveArchive_ WaveArchive_;
typedef struct WaveArchiveBank_ WaveArchiveBank_;
typedef struct Ctrl_ Ctrl_;
typedef struct CtrlGroup_ CtrlGroup_;

void Jac_SceneClose(WaveArchiveBank_*, CtrlGroup_*, u32, int);
void Jac_SceneSet(WaveArchiveBank_*, CtrlGroup_*, u32, int);
void GetSoundHandle(CtrlGroup_*, u32);
void Jac_WsVirtualToPhysical(u16);
void Jac_BnkVirtualToPhysical(u16);
void Jac_BnkPhysicalToVirtual(u16);
void Jac_WsPhysicalToVirtual(u16);
void Jac_WsConnectTableSet(u32, u32);
void Jac_BnkConnectTableSet(u32, u32);
void Jac_ConnectTableInit();

#endif
