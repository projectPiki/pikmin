#include "jaudio/verysimple.h"

#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/audiothread.h"
#include "jaudio/bankloader.h"
#include "jaudio/cmdqueue.h"
#include "jaudio/cmdstack.h"
#include "jaudio/connect.h"
#include "jaudio/driverinterface.h"
#include "jaudio/dvdthread.h"
#include "jaudio/fat.h"
#include "jaudio/file_seq.h"
#include "jaudio/fxinterface.h"
#include "jaudio/jammain_2.h"
#include "jaudio/oneshot.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/piki_player.h"
#include "jaudio/piki_scene.h"
#include "jaudio/pikidemo.h"
#include "jaudio/pikiinter.h"
#include "jaudio/pikiseq.h"
#include "jaudio/seqsetup.h"
#include "jaudio/syncstream.h"
#include "jaudio/waveread.h"

static CmdQueue system_se;      // TODO: type uncertain
static CmdQueue system_se_stop; // TODO: type undertain

CmdQueue* queue_list;
static BOOL cmdqueue_reset;
static u32 countdown_count;  // TODO: type uncertain
static BOOL pausemode;       // TODO: type uncertain
static BOOL container;       // TODO: type uncertain
static u32 sys_voldown_flag; // TODO: type uncertain
static BOOL boot_ok;
static u32 count; // TODO: type uncertain
static u8* lend_buffer;

// forward declared statics
static void __ResetCounter();

static BOOL InitQueue()
{
	STACK_PAD_VAR(4);
	seqp_* handle;

	handle = Jam_GetTrackHandle(0x10009);
	if (!handle)
		return FALSE;
	Jal_AddCmdQueue(&system_se, handle, FALSE);
	Jal_AddCmdQueue(&system_se_stop, handle, TRUE);
	return TRUE;
}

void Jac_StopSe(s32)
{
	if (cmdqueue_reset) {
		(cmdqueue_reset != 0);
	}
}

BOOL Jac_PauseCheck()
{
	return pausemode | container;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void Jac_UpdateRocketParam(void)
{
	// UNUSED FUNCTION
}

void Jac_SysSEDemoFadeCheck()
{
	if (sys_voldown_flag == 0) {
		return;
	}

	if (sys_voldown_flag == 1) {
		if (!StreamSyncCheckBusy(0, 5)) {
			Jac_DemoFade(0, 100, 1.0f);
			sys_voldown_flag = 0;
		}
	} else {
		--sys_voldown_flag;
	}
}

void Jac_PlaySystemSe(s32 id)
{
	if (!cmdqueue_reset) {
		cmdqueue_reset = InitQueue();
		if (!cmdqueue_reset) {
			return;
		}
	}

	switch (id) {
	case JACSYS_ContainerOK:
		Jac_PlayOrimaSe(JACORIMA_Unk14);
		return;

	case JACSYS_OrimaLifeDim:
	case JACSYS_ViewChange:
		if (Jac_DemoCheck() == TRUE || Jac_PauseCheck() == TRUE || Jac_GetCurrentScene() != SCENE_Unk5) {
			return;
		}

		break;
	case JACSYS_Countdown:
		++countdown_count;
		if (countdown_count == 10) {
			Jac_FadeOutBgm(0, 60);
			Jac_FadeOutBgm(1, 60);
		}
		break;

	case JACSYS_EveningAlert:
		Jac_SetBgmModeFlag(0, 2, 1);
		break;

	case JACSYS_MenuOn:
		Jac_SetBgmModeFlag(0, 4, 1);
		Jac_SetBgmModeFlag(1, 4, 1);
		container = TRUE;
		Jac_Orima_Formation(0, 0);
		Jac_PauseOrimaSe();
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		break;

	case JACSYS_MenuOff:
		if (container == TRUE) {
			Jac_SetBgmModeFlag(0, 4, 0);
			Jac_SetBgmModeFlag(1, 4, 0);
			container = FALSE;
			Jam_UnPauseTrack(Jam_GetTrackHandle(0x20000), 1);
			Jac_UnPauseOrimaSe();
			Jac_StopSystemSe(JACSYS_MenuScroll);
			Jac_StopSystemSe(JACSYS_MenuZoomIn);
			break;
		}
		return;

	case JACSYS_Pause:
		if (container == FALSE) {
			Jac_SetBgmModeFlag(0, 4, 1);
			Jac_SetBgmModeFlag(1, 4, 1);
			Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
			Jac_PauseOrimaSe();
			Jac_Orima_Formation(0, 0);
		}
		pausemode = TRUE;
		break;

	case JACSYS_Unpause:
		if (pausemode != FALSE) {
			if (container == FALSE) {
				Jac_SetBgmModeFlag(0, 4, 0);
				Jac_SetBgmModeFlag(1, 4, 0);
				Jam_UnPauseTrack(Jam_GetTrackHandle(0x20000), 1);
				Jac_UnPauseOrimaSe();
			}
			pausemode = FALSE;
		} else {
			countdown_count  = 0;
			sys_voldown_flag = 0;
			return;
		}
		break;

	case JACSYS_PartsAppear:
		WaveScene_Set(0xd, 6);
		Jac_PlayDemoSequenceDirect(8);
		return;

	case JACSYS_ChgHiScore:
		if (sys_voldown_flag == FALSE) {
			Jac_DemoFade(1, 5, 0.15f);
		}
		Jac_StartDemoSound(5);
		sys_voldown_flag = 0x14;
		return;

	case JACSYS_DVDPause:
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		Jam_PauseTrack(Jam_GetTrackHandle(0x1000f), 1);
		Jac_PauseOrimaSe();
		Jac_Orima_Formation(0, 0);
		Jac_SetBgmModeFlag(0, 4, 1);
		Jac_SetBgmModeFlag(1, 4, 1);
		StreamSetDVDPause(0, 1);
		id = JACSYS_CardError;
		break;

	case JACSYS_DVDUnpause:
		Jam_UnPauseTrack(Jam_GetTrackHandle(0x20000), 1);
		Jam_UnPauseTrack(Jam_GetTrackHandle(0x1000f), 1);
		Jac_UnPauseOrimaSe();
		StreamSetDVDPause(0, 0);
		Jac_SetBgmModeFlag(0, 4, 0);
		Jac_SetBgmModeFlag(1, 4, 0);
		return;

	case JACSYS_Unk40:
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		Jac_Orima_Formation(0, 0);
		pausemode = TRUE;
		return;
	}

	if (cmdqueue_reset == TRUE) {
		Jal_SendCmdQueue_Noblock(&system_se, id);
	}
}

void Jac_StopSystemSe(s32 id)
{
	if (cmdqueue_reset == FALSE) {
		cmdqueue_reset = InitQueue();
	}

	switch (id) {
	case JACSYS_ContainerOK:
		Jac_StopOrimaSe(14);
		break;

	default:
		if (cmdqueue_reset == TRUE) {
			Jal_SendCmdQueue_Noblock(&system_se_stop, id);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Jac_PlaySe(u32)
{
	// UNUSED FUNCTION
}

static void Jac_PlayInit()
{
	Jaq_Reset();
	Init_StreamAudio();
	Jac_ConnectTableInit();
	Jaf_InitSeqArchive2("/Seqs/pikiseq.hed", HEAD_pikiseq, 0);
	Jac_InitBgm();
	Bank_Setup("Banks/pikibank.bx");
}

static void Jac_Archiver_Init()
{
}

static u16 TrackReceive(seqp_* track, u16 param_2)
{
	STACK_PAD_VAR(1);
	u8 childTrackIndex;
	u8 childSlotIndex;
	u16 eventActionId;

	u16 portReadOut;

	if (param_2 == 0x1000) {
		WaveScene_Close(13, 6);
	}
	if ((param_2 & 0x8000) == 0x8000) {
		childTrackIndex = (track->trackId & 0x00f0) >> 4;
		childSlotIndex  = (track->trackId & 0x000f) >> 0;
		eventActionId   = (param_2 & 0x0fff);
		if ((track->trackId & 0x0f00) >> 8 == 1) {
			MML_StopEventAction(childTrackIndex, childSlotIndex, eventActionId);
		}
	}
	if ((param_2 & 0x9000) == 0x9000) {
		Jam_ReadPortAppDirect(track, 2, &portReadOut);
		MML_StopEventAll(track->trackId & 0xf, portReadOut);
	}
	return 0;
}

static void AuxBusInit()
{
	u32* REF_alloc2Size;
	u32 alloc2Size;

	STACK_PAD_VAR(2);

	u32 i;
	s16* circularBufferBase;

	static FxlineConfig fx_config[] = {
		{ 1, 0x000A, 0x6000, 0x000B, 0x0000, 0x00000032, { 0x0000, 0x0000, 0x0000, 0x01F4, 0x03E8, 0x0FA0, 0x1B58, 0x1F40 } },
		{ 0, 0x0000, 0x0000, 0x0001, 0x6000, 0x00000000, { 0x0000, 0x0000, 0x0000, 0x01F4, 0x03E8, 0x0FA0, 0x1B58, 0x1F40 } },
		{ 2, 0x000A, 0x3FFF, 0x000B, 0x3FFF, 0x00000028, { 0x0000, 0x0078, 0x00FA, 0x01F4, 0x03E8, 0x0FA0, 0x0FA0, 0x0FA0 } },
		{ 0, 0x0000, 0x1000, 0x0001, 0x1000, 0x00000000, { 0x0000, 0x0000, 0x0000, 0x01F4, 0x03E8, 0x0FA0, 0x1B58, 0x1F40 } },
	};

	for (i = 0; i < 4; ++i) {
		if (i < 3) {
			alloc2Size         = fx_config[i].circularBufferSize * 0xa0; // TODO: What is 160 bytes large?
			REF_alloc2Size     = &alloc2Size;
			circularBufferBase = (s16*)OSAlloc2(alloc2Size);
		} else {
			circularBufferBase = NULL;
		}
		DFX_SetFxLine(i, circularBufferBase, &fx_config[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Jac_SetThreadPriority(void)
{
	// UNUSED FUNCTION
}

static void __BootSoundOK(u32)
{
	boot_ok = TRUE;
}

BOOL Jac_CheckBootOk()
{
	return boot_ok;
}

void Jac_Start(void* heap, u32 heapSize, u32 aramSize, immut char* rootPath)
{
	STACK_PAD_VAR(1);

	if (rootPath) {
		DVDT_SetRootPath(rootPath);
	}
	StartAudioThread(heap, heapSize, aramSize, 3);
	AuxBusInit();
	Jac_RegisterExtFastOpen("/Seqs/pikiseq.arc");
	Jac_RegisterExtFastOpen("/Banks/demose_0.aw");
	Jac_RegisterExtFastOpen("/Banks/demose_1.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_0.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_1.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_2.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_3.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_4.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_5.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_6.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_7.aw");
	Jac_RegisterExtFastOpen("/Banks/demo_8.aw");
	Jac_RegisterExtFastOpen("/d_end1.stx");
	Jac_RegisterExtFastOpen("/d_end3.stx");
	Jac_RegisterExtFastOpen("/fanf5.stx");
	Jac_RegisterExtFastOpen("/badend0.stx");
	Jac_RegisterExtFastOpen("/badend1.stx");
	Jac_FatMemory_Init(0x10000);
	Jac_Archiver_Init();
	Jac_PlayInit();
	WaveScene_Set(0, 0);
	DVDT_CheckPass(0, 0, __BootSoundOK);
	Jac_Portcmd_Init();
	Jal_CmdQueue_Init();
	Jac_SetMixerLevel(1.1f, 2.0f);
	Jam_RegisterTrackCallback(TrackReceive);
	Jac_InitEventSystem();
	Jac_InitDemoSystem();
	Jac_InitStreamSystem();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Jac_StopSoundAll(void)
{
	// UNUSED FUNCTION
}

void Jac_Freeze_Precall()
{
	BOOL level   = OSDisableInterrupts();
	jcs_* handle = Get_GlobalHandle();
	AllStop_1Shot(handle);
	FlushRelease_1Shot(handle);
	OSRestoreInterrupts(level);
	__ResetCounter();
}

void Jac_Freeze()
{
	BOOL level = OSDisableInterrupts();
	StopAudioThread();
	OSRestoreInterrupts(level);
}

static void __ResetCounter()
{
	count = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Jac_Silence_Check(void)
{
	// UNUSED FUNCTION
}

void Jac_AddDVDBuffer(u8* buf, u32 p2)
{
	DVDT_SetBuffer(buf, 1, p2);
	lend_buffer = buf;
}

void Jac_BackDVDBuffer()
{
	if (lend_buffer) {
		DVDT_CloseBuffer(lend_buffer);
	}
	lend_buffer = NULL;
}
