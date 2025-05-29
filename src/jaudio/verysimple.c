#include "jaudio/verysimple.h"

#include "Dolphin/os.h"
#include "jaudio/dvdthread.h"
#include "jaudio/audiothread.h"
#include "jaudio/driverinterface.h"
#include "jaudio/oneshot.h"
#include "jaudio/jammain_2.h"
#include "jaudio/cmdqueue.h"
#include "jaudio/syncstream.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/piki_player.h"
#include "jaudio/pikidemo.h"
#include "jaudio/piki_scene.h"
#include "jaudio/waveread.h"
#include "jaudio/aictrl.h"
#include "jaudio/cmdstack.h"
#include "jaudio/fat.h"
#include "jaudio/pikiinter.h"
#include "jaudio/fxinterface.h"
#include "jaudio/bankloader.h"
#include "jaudio/seqsetup.h"
#include "jaudio/connect.h"
#include "jaudio/file_seq.h"
#include "jaudio/pikiseq.h"

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

/*
 * --INFO--
 * Address:	80016A60
 * Size:	00006C
 */
static BOOL InitQueue()
{
	u32 badCompiler[4];
	seqp_* handle;

	handle = Jam_GetTrackHandle(0x10009);
	if (!handle)
		return FALSE;
	Jal_AddCmdQueue(&system_se, handle, FALSE);
	Jal_AddCmdQueue(&system_se_stop, handle, TRUE);
	return TRUE;
}

/*
 * --INFO--
 * Address:	80016AE0
 * Size:	00000C
 */
void Jac_StopSe(s32)
{
	if (cmdqueue_reset) {
		(cmdqueue_reset != 0);
	}
}

/*
 * --INFO--
 * Address:	80016B00
 * Size:	000010
 */
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

/*
 * --INFO--
 * Address:	80016B20
 * Size:	000068
 */
void Jac_SysSEDemoFadeCheck()
{
	if (sys_voldown_flag == 0) {
		return;
	}

	if (sys_voldown_flag == 1) {
		if (!StreamSyncCheckBusy(0, 5)) {
			Jac_DemoFade(1.0f, 0, 100);
			sys_voldown_flag = 0;
		}
	} else {
		--sys_voldown_flag;
	}
}

/*
 * --INFO--
 * Address:	80016BA0
 * Size:	0003A0
 */
void Jac_PlaySystemSe(s32 id)
{
	if (!cmdqueue_reset) {
		cmdqueue_reset = InitQueue();
		if (!cmdqueue_reset) {
			return;
		}
	}

	switch (id) {
	case 16:
		Jac_PlayOrimaSe(14);
		return;
	case 10:
	case 12:
		if (Jac_DemoCheck() == TRUE || Jac_PauseCheck() == TRUE || Jac_GetCurrentScene() != 5) {
			return;
		}

		break;
	case 5:
		++countdown_count;
		if (countdown_count == 10) {
			Jac_FadeOutBgm(0, 60);
			Jac_FadeOutBgm(1, 60);
		}
		break;

	case 4:
		Jac_SetBgmModeFlag(0, 2, 1);
		break;

	case 6:
		Jac_SetBgmModeFlag(0, 4, 1);
		Jac_SetBgmModeFlag(1, 4, 1);
		container = TRUE;
		Jac_Orima_Formation(0, 0);
		Jac_PauseOrimaSe();
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		break;

	case 7:
		if (container == TRUE) {
			Jac_SetBgmModeFlag(0, 4, 0);
			Jac_SetBgmModeFlag(1, 4, 0);
			container = FALSE;
			Jam_UnPauseTrack(Jam_GetTrackHandle(0x20000), 1);
			Jac_UnPauseOrimaSe();
			Jac_StopSystemSe(0x23);
			Jac_StopSystemSe(0x21);
			break;
		}
		return;

	case 3:
		if (container == FALSE) {
			Jac_SetBgmModeFlag(0, 4, 1);
			Jac_SetBgmModeFlag(1, 4, 1);
			Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
			Jac_PauseOrimaSe();
			Jac_Orima_Formation(0, 0);
		}
		pausemode = TRUE;
		break;

	case 15:
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

	case 18:
		WaveScene_Set(0xd, 6);
		Jac_PlayDemoSequenceDirect(8);
		return;

	case 32:
		if (sys_voldown_flag == FALSE) {
			Jac_DemoFade(0.15f, 1, 5);
		}
		Jac_StartDemoSound(5);
		sys_voldown_flag = 0x14;
		return;

	case 38:
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		Jam_PauseTrack(Jam_GetTrackHandle(0x1000f), 1);
		Jac_PauseOrimaSe();
		Jac_Orima_Formation(0, 0);
		Jac_SetBgmModeFlag(0, 4, 1);
		Jac_SetBgmModeFlag(1, 4, 1);
		StreamSetDVDPause(0, 1);
		id = 0x1c;
		break;

	case 39:
		Jam_UnPauseTrack(Jam_GetTrackHandle(0x20000), 1);
		Jam_UnPauseTrack(Jam_GetTrackHandle(0x1000f), 1);
		Jac_UnPauseOrimaSe();
		StreamSetDVDPause(0, 0);
		Jac_SetBgmModeFlag(0, 4, 0);
		Jac_SetBgmModeFlag(1, 4, 0);
		return;

	case 40:
		Jam_PauseTrack(Jam_GetTrackHandle(0x20000), 1);
		Jac_Orima_Formation(0, 0);
		pausemode = TRUE;
		return;
	}

	if (cmdqueue_reset == TRUE) {
		Jal_SendCmdQueue_Noblock(&system_se, id);
	}
}

/*
 * --INFO--
 * Address:	80016F40
 * Size:	000070
 */
void Jac_StopSystemSe(s32 id)
{
	if (cmdqueue_reset == FALSE) {
		cmdqueue_reset = InitQueue();
	}

	switch (id) {
	case 16:
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

/*
 * --INFO--
 * Address:	80016FC0
 * Size:	000050
 */
static void Jac_PlayInit()
{
	Jaq_Reset();
	Init_StreamAudio();
	Jac_ConnectTableInit();
	Jaf_InitSeqArchive2("/Seqs/pikiseq.hed", HEAD_pikiseq, 0);
	Jac_InitBgm();
	Bank_Setup("Banks/pikibank.bx");
}

/*
 * --INFO--
 * Address:	80017020
 * Size:	000004
 */
static void Jac_Archiver_Init()
{
}

/*
 * --INFO--
 * Address:	80017040
 * Size:	0000AC
 */
static u32 TrackReceive(seqp_* track, u16 param_2)
{
	u32 badCompiler;
	u8 stupid1;  // Do it inside the if statement, idiots.
	u8 stupid2;  // Do it inside the if statement, idiots.
	u16 stupid3; // Do it inside the if statement, idiots.

	u16 portReadOut;

	if (param_2 == 0x1000) {
		WaveScene_Close(13, 6);
	}
	if ((param_2 & 0x8000) == 0x8000) {
		stupid1 = (track->_88 & 0x00f0) >> 4;
		stupid2 = (track->_88 & 0x000f) >> 0;
		stupid3 = (param_2 & 0x0fff);
		if ((track->_88 & 0x0f00) >> 8 == 1) {
			MML_StopEventAction(stupid1, stupid2, stupid3);
		}
	}
	if ((param_2 & 0x9000) == 0x9000) {
		Jam_ReadPortAppDirect(track, 2, &portReadOut);
		MML_StopEventAll(track->_88 & 0xf, portReadOut);
	}
	return 0;
}

/*
 * --INFO--
 * Address:	80017100
 * Size:	00007C
 */
static void AuxBusInit()
{
	u32* REF_alloc2Size;
	u32 alloc2Size;

	u32 badCompiler2[2];

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

/*
 * --INFO--
 * Address:	80017180
 * Size:	00000C
 */
static void __BootSoundOK(u32)
{
	boot_ok = TRUE;
}

/*
 * --INFO--
 * Address:	800171A0
 * Size:	000008
 */
BOOL Jac_CheckBootOk()
{
	return boot_ok;
}

/*
 * --INFO--
 * Address:	800171C0
 * Size:	000144
 */
void Jac_Start(void* heap, u32 heapSize, u32 aramSize, char* rootPath)
{
	u32 badCompiler;

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

/*
 * --INFO--
 * Address:	80017320
 * Size:	00004C
 */
void Jac_Freeze_Precall()
{
	BOOL level   = OSDisableInterrupts();
	jcs_* handle = Get_GlobalHandle();
	AllStop_1Shot(handle);
	FlushRelease_1Shot(handle);
	OSRestoreInterrupts(level);
	__ResetCounter();
}

/*
 * --INFO--
 * Address:	80017380
 * Size:	000038
 */
void Jac_Freeze()
{
	BOOL level = OSDisableInterrupts();
	StopAudioThread();
	OSRestoreInterrupts(level);
}

/*
 * --INFO--
 * Address:	800173C0
 * Size:	00000C
 */
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

/*
 * --INFO--
 * Address:	800173E0
 * Size:	000038
 */
void Jac_AddDVDBuffer(u8* buf, u32 p2)
{
	DVDT_SetBuffer(buf, 1, p2);
	lend_buffer = buf;
}

/*
 * --INFO--
 * Address:	80017420
 * Size:	000034
 */
void Jac_BackDVDBuffer()
{
	if (lend_buffer) {
		DVDT_CloseBuffer(lend_buffer);
	}
	lend_buffer = NULL;
}
