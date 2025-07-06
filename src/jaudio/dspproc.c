#include "jaudio/dspproc.h"
#include "Dolphin/dsp.h"
#include "Dolphin/os.h"
#include "VersionGroups.h"

static u16 DSP_MIXERLEVEL = 0x4000;

/*
 * --INFO--
 * Address:	800086C0
 * Size:	0000A8
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

/*
 * --INFO--
 * Address:	80008780
 * Size:	000048
 */
u32 DSPReleaseHalt()
{
	while (DSPCheckMailToDSP() != 0)
		;
	DSPSendMailToDSP(0);
	if (DSPCheckMailFromDSP() != 0) {
		DSPReadMailFromDSP();
	}

	return 0x88881357;
}

/*
 * --INFO--
 * Address:	800087E0
 * Size:	000058
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

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Dswap(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Dmix(u32, u32, u32, s16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Dcopy(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DloadBuffer1(u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DloadBuffer(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DsaveBuffer(u16, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DsetLoopState(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void DadpcmDec(u32, u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void DloadFilter(u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void DcopyfromARAM(u32, u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DoscStart(u8, u16, u16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void DoscStop(u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DoscStore(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Dmixer(u32, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Dresampletest()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void Dadpcmtest(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80008840
 * Size:	000048
 */
void DsetupTable(u32 cmd1, u32 cmd2, u32 cmd3, u32 cmd4, u32 cmd5)
{
	u32 commands[5];

	commands[0] = (cmd1 & 0xFFFF) | 0x81000000;
	commands[1] = cmd2;
	commands[2] = cmd3;
	commands[3] = cmd4;
	commands[4] = cmd5;

	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
}

/*
 * --INFO--
 * Address:	800088A0
 * Size:	000024
 */
void DsetMixerLevel(f32 level)
{
	DSP_MIXERLEVEL = 4096.0f * level;
}

/*
 * --INFO--
 * Address:	800088E0
 * Size:	000048
 */
void DsyncFrame(u32 subframes, u32 dspbufStart, u32 dspbufEnd)
{
	u32 commands[3];

	u32 val = (subframes << 16 & 0xFF0000);
	val |= 0x82000000;
	commands[0] = val | DSP_MIXERLEVEL;
	commands[1] = dspbufStart;
	commands[2] = dspbufEnd;

	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
}

/*
 * --INFO--
 * Address:	80008940
 * Size:	000034
 */
void DwaitFrame()
{
	u32 commands[1];

	commands[0] = 0x80000000;
	DSPSendCommands(commands, ARRAY_SIZE(commands));
	DSPWaitFinish();
}

/*
 * --INFO--
 * Address:	80008980
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	800089C0
 * Size:	00003C
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
