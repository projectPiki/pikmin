#ifndef _JAUDIO_VERYSIMPLE_H
#define _JAUDIO_VERYSIMPLE_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef enum JacSystemSoundID {
	JACSYS_AllStop          = 0,
	JACSYS_Decide1          = 1,
	JACSYS_Move1            = 2,
	JACSYS_Pause            = 3,
	JACSYS_EveningAlert     = 4,
	JACSYS_Countdown        = 5,
	JACSYS_MenuOn           = 6,
	JACSYS_MenuOff          = 7,
	JACSYS_MenuSelect       = 8,
	JACSYS_MenuError        = 9,
	JACSYS_OrimaLifeDim     = 10,
	JACSYS_WorkFinish       = 11,
	JACSYS_ViewChange       = 12,
	JACSYS_Cancel           = 13,
	JACSYS_Typewriter       = 14,
	JACSYS_Unpause          = 15,
	JACSYS_ContainerOK      = 16,
	JACSYS_Jungle           = 17,
	JACSYS_PartsAppear      = 18,
	JACSYS_SelectMove       = 19,
	JACSYS_SelectDecide     = 20,
	JACSYS_TimeSignal       = 21,
	JACSYS_SelectCourseOpen = 22,
	JACSYS_MessageClose     = 23,
	JACSYS_Unk24            = 24,
	JACSYS_Unk25            = 25,
	JACSYS_CardAccess       = 26,
	JACSYS_CardOK           = 27,
	JACSYS_CardError        = 28,
	JACSYS_TimeSmallSignal  = 29,
	JACSYS_Unk30            = 30,
	JACSYS_Unk31            = 31,
	JACSYS_ChgHiScore       = 32,
	JACSYS_MenuZoomIn       = 33,
	JACSYS_MenuZoomOut      = 34,
	JACSYS_MenuScroll       = 35,
	JACSYS_Unk36            = 36,
	JACSYS_SoundConfig      = 37,
	JACSYS_DVDPause         = 38,
	JACSYS_DVDUnpause       = 39,
	JACSYS_Unk40            = 40,
} JacSystemSoundID;

//////////// JAUDIO "VERY SIMPLE" FUNCTIONS ////////////
void Jac_StopSe(s32);
BOOL Jac_PauseCheck();
void Jac_SysSEDemoFadeCheck();
void Jac_PlaySystemSe(s32);
void Jac_StopSystemSe(s32);
BOOL Jac_CheckBootOk();
void Jac_Start(void* heap, u32 heapSize, u32 aramSize, immut char* rootPath);
void Jac_Freeze_Precall();
void Jac_Freeze();
void Jac_AddDVDBuffer(u8* buf, u32);
void Jac_BackDVDBuffer();

///////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
