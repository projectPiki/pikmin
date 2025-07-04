#include "Dolphin/OS/OSThread.h"
#include "jaudio/audiothread.h"
#include "jaudio/dummyprobe.h"
#include "jaudio/dspproc.h"
#include "jaudio/rate.h"
#include "jaudio/audiocommon.h"
#include "jaudio/aictrl.h"
#include "jaudio/playercall.h"
#include "jaudio/dspbuf.h"
#include "jaudio/cpubuf.h"
#include "jaudio/dspboot.h"
#include "jaudio/dummyrom.h"
#include "jaudio/dspinterface.h"
#include "jaudio/dvdthread.h"
#include "jaudio/stackchecker.h"
#include "jaudio/ja_calc.h"
#include "Dolphin/os.h"
#include "Dolphin/ai.h"

// this is purely for comm bullshit to match. pretty sure it's not the comm bug, just wacky.
typedef struct Jac_AudioThread {
	OSThread thread; // _00
	u8 pad[0x10];    // _310
} Jac_AudioThread;

Jac_AudioThread jac_audioThread ATTRIBUTE_ALIGN(32);
u8 jac_audioStack[AUDIO_STACK_SIZE];
OSThread jac_neosThread;
OSThread jac_dvdThread;
u8 jac_dvdStack[AUDIO_STACK_SIZE] ATTRIBUTE_ALIGN(32);

static OSMessageQueue audioproc_mq;
static OSMessage msgbuf[AUDIOPROC_MQ_BUF_COUNT];

static u32 audioproc_mq_init;
static volatile int intcount;

/*
 * --INFO--
 * Address:	800062C0
 * Size:	000008
 */
void DspSyncCountClear(int count)
{
	intcount = count;
}

/*
 * --INFO--
 * Address:	800062E0
 * Size:	000008
 */
int DspSyncCountCheck()
{
	return intcount;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_GetDacRate(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80006300
 * Size:	000044
 */
static void DspSync()
{
	if (audioproc_mq_init) {
		OSSendMessage(&audioproc_mq, AUDIOPROC_MESSAGE_DSP_SYNC, OS_MESSAGE_NOBLOCK);
	} else {
		DSPReleaseHalt();
	}
}

/*
 * --INFO--
 * Address:	80006360
 * Size:	000050
 */
void StopAudioThread()
{
	if (audioproc_mq_init) {
		if (OSSendMessage(&audioproc_mq, AUDIOPROC_MESSAGE_3, OS_MESSAGE_NOBLOCK) == FALSE) {
			OSCancelThread(&jac_audioThread.thread);
		}
	}
}

/*
 * --INFO--
 * Address:	800063C0
 * Size:	000080
 */
static void AudioSync()
{
	static BOOL first = TRUE;

	if (first == FALSE) {
		Probe_Finish(4);
	}

	first = FALSE;
	Probe_Start(4, "UPDATE-DAC");
	if (audioproc_mq_init) {
		OSSendMessage(&audioproc_mq, AUDIOPROC_MESSAGE_UPDATE_DAC, OS_MESSAGE_NOBLOCK);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NeosSync()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80006440
 * Size:	000068
 */
static void __DspSync(__OSInterrupt interrupt, OSContext* context)
{
	u16 reg                       = __DSPRegs[DSP_CONTROL_STATUS];
	reg                           = (1 << 7) | reg & -0x29; /* clear AR + AI interrupt, set DSP interrupt */
	__DSPRegs[DSP_CONTROL_STATUS] = reg;

	OSContext tmp_context;
	OSClearContext(&tmp_context);
	OSSetCurrentContext(&tmp_context);
	DspSync();
	OSClearContext(&tmp_context);
	OSSetCurrentContext(context);
}

/*
 * --INFO--
 * Address:	800064C0
 * Size:	000044
 */
static void __DspReg()
{
	BOOL enable = OSDisableInterrupts();
	__OSSetInterruptHandler(__OS_INTERRUPT_DSP_DSP, &__DspSync);
	OSRestoreInterrupts(enable);
}

/*
 * --INFO--
 * Address:	80006520
 * Size:	000130
 */
static void* audioproc(void*)
{
	OSInitFastCast();
	OSInitMessageQueue(&audioproc_mq, msgbuf, AUDIOPROC_MQ_BUF_COUNT);
	audioproc_mq_init = TRUE;
	Jac_Init();
	Jac_InitSinTable();
	ResetPlayerCallback();
	DspbufProcess(DSPBUF_EVENT_INIT);
	CpubufProcess(DSPBUF_EVENT_INIT);
	DspBoot();
	DSP_InitBuffer();
	__DspReg();
	AISetDSPSampleRate(JAC_AI_SETTING);
	AIRegisterDMACallback(&AudioSync);
	AIStartDMA();

	while (TRUE) {
		OSMessage msg;

		OSReceiveMessage(&audioproc_mq, &msg, OS_MESSAGE_BLOCK);
		switch ((int)msg) {
		case (int)AUDIOPROC_MESSAGE_UPDATE_DAC:
			Jac_UpdateDAC();
			break;
		case (int)AUDIOPROC_MESSAGE_DSP_SYNC:
			if (intcount == 0) {
				return;
			}

			intcount--;
			if (intcount == 0) {
				Probe_Finish(7);
				DspFrameEnd();
			} else {
				Probe_Start(2, "SFR_DSP");
				UpdateDSP();
				Probe_Finish(2);
			}

			break;
		case (int)AUDIOPROC_MESSAGE_NEOS_SYNC:
			CpuFrameEnd();
			break;
		case (int)AUDIOPROC_MESSAGE_3:
			OSExitThread(NULL);
			break;
		}
	}

	STACK_PAD_VAR(3);
}

// GQR formats.
#define OS_GQR_U8  (0x0004) // GQR 1
#define OS_GQR_U16 (0x0005) // GQR 2
#define OS_GQR_S8  (0x0006) // GQR 3
#define OS_GQR_S16 (0x0007) // GQR 4

// GQRs for fast casting.
#define OS_FASTCAST_U8  (2)
#define OS_FASTCAST_U16 (3)
#define OS_FASTCAST_S8  (4)
#define OS_FASTCAST_S16 (5)

/*
 * --INFO--
 * Address:	80006660
 * Size:	000034
 */
static void OSInitFastCast(void)
{
#ifdef __MWERKS__
	asm {
		li        r3,     OS_GQR_U8
		oris      r3, r3, OS_GQR_U8
		mtspr     GQR2, r3
		li        r3,     OS_GQR_U16
		oris      r3, r3, OS_GQR_U16
		mtspr     GQR3, r3
		li        r3,     OS_GQR_S8
		oris      r3, r3, OS_GQR_S8
		mtspr     GQR4, r3
		li        r3,     OS_GQR_S16
		oris      r3, r3, OS_GQR_S16
		mtspr     GQR5, r3
	}
#endif
}

static BOOL priority_set        = FALSE;
static volatile OSPriority pri  = 0;
static volatile OSPriority pri2 = 0;
static volatile OSPriority pri3 = 0;

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SetAudioThreadPriority(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800066A0
 * Size:	000124
 */
void StartAudioThread(void* heap, s32 heapSize, u32 aramSize, u32 flags)
{
	if (priority_set == FALSE) {
		OSPriority base_prio = OSGetThreadPriority(OSGetCurrentThread()) - 3;

		pri = base_prio;

		OSPriority p = pri;
		pri3         = p + 1;
		pri2         = p + 2;
	}

	u32 neos_flag;

	Jac_HeapSetup(heap, heapSize);
	Jac_SetAudioARAMSize(aramSize);

	neos_flag = flags & AUDIO_THREAD_FLAG_NEOS;
	Jac_InitARAM(neos_flag);

	Jac_StackInit(jac_audioStack, 0x200);
	if ((flags & AUDIO_THREAD_FLAG_AUDIO)) {
		// point to top of audioStack
		u8* stack_p = jac_audioStack;
		OSCreateThread(&jac_audioThread.thread, &audioproc, NULL, stack_p + AUDIO_STACK_SIZE, AUDIO_STACK_SIZE, pri, OS_THREAD_ATTR_DETACH);
		OSResumeThread(&jac_audioThread.thread);
	}

	Jac_StackInit(jac_dvdStack, 0x200);
	if ((flags & AUDIO_THREAD_FLAG_DVD)) {
		jac_dvdproc_init();
		// point to top of dvdStack
		u8* stack_p = jac_dvdStack;
		OSCreateThread(&jac_dvdThread, &jac_dvdproc, NULL, stack_p + AUDIO_STACK_SIZE, AUDIO_STACK_SIZE, pri3, OS_THREAD_ATTR_DETACH);
		OSResumeThread(&jac_dvdThread);
	}

	STACK_PAD_VAR(2);
}
