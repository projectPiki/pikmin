#ifndef _JAUDIO_PIKIBGM_H
#define _JAUDIO_PIKIBGM_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef struct BgmControl_ BgmControl_;

///////////// JAUDIO PIKMIN BGM MAPPING /////////////
typedef enum JacBgmID {
	BGM_PikiSE   = 0, ///< 0, pikise.jam
	BGM_SysEvent = 1, ///< 1, sysevent.jam
	BGM_Dummy2   = 2, ///< 2, dummy
	// 3 = dummy
	BGM_Tutorial    = 4,  ///< 4, tutorial.jam
	BGM_Play3       = 5,  ///< 5, play3.jam
	BGM_DEnd2       = 6,  ///< 6, d_end2.jam
	BGM_Jungle      = 7,  ///< 7, jungle.jam
	BGM_Dummy8      = 8,  ///< 8, dummy
	BGM_Yakushima   = 9,  ///< 9, yaku.jam
	BGM_Cave        = 10, ///< 10, cave.jam
	BGM_Boss2       = 11, ///< 11, boss2.jam
	BGM_Map         = 12, ///< 12, map.jam
	BGM_DemoBgm     = 13, ///< 13, demobgm.jam
	BGM_Dummy14     = 14, ///< 14, dummy
	BGM_Dummy15     = 15, ///< 15, dummy
	BGM_Boss3       = 16, ///< 16, boss3.jam
	BGM_Flow        = 17, ///< 17, flow.jam
	BGM_Select      = 18, ///< 18, select.jam
	BGM_Char        = 19, ///< 19, char.jam
	BGM_ChalResult  = 20, ///< 20, cresult.jam
	BGM_FinalResult = 21, ///< 21, fresult.jam
} JacBgmID;

/////////////////////////////////////////////////////
//////////// JAUDIO PIKMIN BGM FUNCTIONS ////////////
void Jac_InitBgm(void);
void Jac_FadeOutBgm(u32 trackIndex, u32 fadeFrames);
void Jac_StopBgm(u32 trackIndex);
void Jac_ReadyBgm(u32 bgmID);
void Jac_PlayBgm(u32 trackIndex, u32 bgmID);
BOOL Jac_ChangeBgmMode(u32 trackIndex, u8 modeFlags);
void Jac_SetBgmModeFlag(u32 trackIndex, u8 flagMask, u8 enabled);
void Jac_BgmFrameWork(void);
void Jac_MoveBgmTrackVol(BgmControl_* bgmControl);
void Jac_ChangeBgmTrackVol(BgmControl_* bgmControl);
void Jac_GameVolume(u8 bgmLevel, u8 seLevel);
void Jac_EasyCrossFade(u8 crossfadeMode, u32 fadeFrames);
void Jac_DemoFade(u8 fadeType, u32 fadeFrames, f32 volumeScale);
void Jac_EnterBossMode(void);
void Jac_ExitBossMode(void);

/////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
