#ifndef _JAUDIO_PIKIPLAYER_H
#define _JAUDIO_PIKIPLAYER_H

#include "types.h"

typedef enum JacOrimaSoundID {
	JACORIMA_Unk0             = 0,
	JACORIMA_Unk1             = 1,
	JACORIMA_OrimaTouchPlants = 2,
	JACORIMA_PikiPulling      = 3,
	JACORIMA_PikiPulled2      = 4,
	JACORIMA_PlayerPunch      = 5,
	JACORIMA_Throw            = 6,
	JACORIMA_Breakup          = 7,
	JACORIMA_Gather           = 8,
	JACORIMA_MoveObj          = 9,
	JACORIMA_Damaged          = 10,
	JACORIMA_Fired            = 11,
	JACORIMA_PlayerDown       = 12,
	JACORIMA_PlayerTouchHoney = 13,
	JACORIMA_Unk14            = 14,

	JACORIMA_PIKISOUND        = 0x8000, // these all have special checks in piki_player
	JACORIMA_ThrowHit         = 0x8001,
	JACORIMA_PikiFly          = 0x8002,
	JACORIMA_BreakupPikiVoice = 0x8003,
	JACORIMA_PikiFlyReady     = 0x8004,
	JACORIMA_PikiCalled       = 0x8005,
	JACORIMA_PikiFind         = 0x8006,
	JACORIMA_PikiPulled       = 0x8007,
	JACORIMA_PikiWaterDrop    = 0x8008,
	JACORIMA_PikiAttachEnemy  = 0x8009,
	JACORIMA_KinokoPikiAttack = 0x800A,
	// ...
	JACORIMA_Unk800C = 0x800C,
	// ...
	JACORIMA_Unk8015 = 0x8015,
	JACORIMA_Unk8016 = 0x8016,
	JACORIMA_Unk8017 = 0x8017,
} JacOrimaSoundID;

//////////// JAUDIO PIKMIN DEMO FUNCTIONS (C++) ////////////
void Jac_PauseOrimaSe();
void Jac_UnPauseOrimaSe();
void Jac_UpdatePikiGaya();

////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN DEMO FUNCTIONS (C) ////////////
void Jac_Orima_Walk(s32 groundSoundID, u32 p2); // args uncertain
void Jac_Orima_Formation(s32, s32);             // args
void Jac_PlayOrimaSe(u32 orimaSoundID);         // args
void Jac_StopOrimaSe(s32 orimaSoundID);         // args
void Jac_Piki_Number(u32);                      // args

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
