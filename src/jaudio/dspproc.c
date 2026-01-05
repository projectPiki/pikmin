#include "jaudio/dspproc.h"
#include "Dolphin/dsp.h"
#include "Dolphin/os.h"
#include <stddef.h>

static u16 DSP_MIXERLEVEL = 0x4000;
#if defined(VERSION_GPIP01_00)
volatile static int flag;
#endif

/**
 * @TODO: Documentation
 */
s32 DSPSendCommands(u32* commands, u32 count)
{
	if (DSPCheckMailToDSP() != 0) {
#if defined(VERSION_PIKIDEMO)
#else
		OSReport("DSP Err:not received mail (to DSP) is remained \n");
#endif
		return -1;
	}

	if (DSPCheckMailFromDSP() != 0) {
#if defined(VERSION_PIKIDEMO)
#else
		OSReport("DSP Err:not received mail (from DSP) is remained \n");
#endif
		return -1;
	}

	int i;

	for (i = 0; i < count; i++) {
		DSPSendMailToDSP(commands[i]);

		while (DSPCheckMailToDSP() != 0)
			;
	}

	return 0;
}

/**
 * @TODO: Documentation
 */
u32 DSPReleaseHalt()
{
#if defined(VERSION_GPIP01_00)
	u32 bit[4];
	u64 map = DSP_CreateMap();
	bit[0]  = map >> 32;
	bit[1]  = map & 0xFFFFFFFF;
	DSPSendCommands2(bit, 0, NULL);
#else
	while (DSPCheckMailToDSP() != 0)
		;
	DSPSendMailToDSP(0);
	if (DSPCheckMailFromDSP() != 0) {
		DSPReadMailFromDSP();
	}

	return 0x88881357;
#endif
}

#if defined(VERSION_GPIP01_00)
static void setup_callback(u16 a)
{
	flag = 0;
}
#endif

/**
 * @TODO: Documentation
 */
void DSPWaitFinish()
{
	u32 mail;
	while (TRUE) {
		while (DSPCheckMailFromDSP() == 0)
			;

		mail = DSPReadMailFromDSP() + 0x77780000;
		if (mail != 0x1357) {
			return;
		}
#if defined(VERSION_PIKIDEMO)
#else
		OSReport("Error: DSP now in framework\n");
#endif
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void Dswap(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000048
 */
void Dmix(u32, u32, u32, s16)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void Dcopy(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void DloadBuffer1(u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void DloadBuffer(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void DsaveBuffer(u16, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
void DsetLoopState(u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void DadpcmDec(u32, u32, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void DloadFilter(u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void DcopyfromARAM(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void DoscStart(u8, u16, u16)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void DoscStop(u8)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
void DoscStore(u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void Dmixer(u32, u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void Dresampletest()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000038
 */
void Dadpcmtest(u32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void DsetupTable(u32 cmd1, u32 cmd2, u32 cmd3, u32 cmd4, u32 cmd5)
{
	u32 commands[5];

	commands[0] = (cmd1 & 0xFFFF) | 0x81000000;
	commands[1] = cmd2;
	commands[2] = cmd3;
	commands[3] = cmd4;
	commands[4] = cmd5;

#if defined(VERSION_GPIP01_00)
	flag = 1;
	DSPSendCommands2(commands, ARRAY_SIZE(commands), setup_callback);
	while (flag != 0) { }
#else
	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
#endif
}

/**
 * @TODO: Documentation
 */
void DsetMixerLevel(f32 level)
{
	DSP_MIXERLEVEL = 4096.0f * level;
}

/**
 * @TODO: Documentation
 */
void DsyncFrame(u32 subframes, u32 dspbufStart, u32 dspbufEnd)
{
	u32 commands[3];

	u32 val = (subframes << 16 & 0xFF0000);
	val |= 0x82000000;
	commands[0] = val | DSP_MIXERLEVEL;
	commands[1] = dspbufStart;
	commands[2] = dspbufEnd;

#if defined(VERSION_GPIP01_00)
	u32 stack;
	DSPSendCommands2(commands, ARRAY_SIZE(commands), NULL);
#else
	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
#endif
}

/**
 * @TODO: Documentation
 */
void DwaitFrame()
{
	u32 commands[1];

	commands[0] = 0x80000000;
	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
}

/**
 * @TODO: Documentation
 */
void DiplSec(u32 cmd)
{
	u32 commands[2];
	STACK_PAD_VAR(1);

	commands[0] = 0x8B000008;
	commands[1] = cmd;
	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
}

/**
 * @TODO: Documentation
 */
void DagbSec(u32 cmd)
{
	u32 commands[2];
	STACK_PAD_VAR(3);

	commands[0] = 0x8C000008;
	commands[1] = cmd;
	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
}
