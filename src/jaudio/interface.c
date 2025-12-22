#include "jaudio/interface.h"

#include "Dolphin/os.h"
#include "jaudio/aictrl.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/pikidemo.h"
#include "jaudio/pikiinter.h"
#include "jaudio/verysimple.h"

static int process_stack[4];

static BOOL vol_chg   = 0;
static int stacklevel = 0;

static u8 game_bgm_vol     = 8;
static u8 game_se_vol      = 8;
static int current_process = 0xFFFFFFFF;

void Jac_OutputMode(int mode)
{
	Jac_SetOutputMode(mode);
}

void Jac_SetBGMVolume(u8 vol)
{
	game_bgm_vol = vol;
	vol_chg      = TRUE;
}

void Jac_SetSEVolume(u8 vol)
{
	game_se_vol = vol;
	vol_chg     = TRUE;
}

void Jac_Gsync()
{
	if (vol_chg) {
		vol_chg = FALSE;
		Jac_GameVolume(game_bgm_vol, game_se_vol);
	}
	Jac_DemoEventUnPauseCheck();
	Jac_SysSEDemoFadeCheck();
	Jac_EventFrameCheck();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Jac_DebugCall(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void __print_thread(immut char*, OSThread*)
{
	// UNUSED FUNCTION
}

void Jac_SetProcessStatus(u32 processStat)
{
	if (current_process != -1) {
		if ((processStat & 1) == 1) {
			if (current_process == processStat - 1 && stacklevel != 0) {
				stacklevel--;
				current_process = process_stack[stacklevel];
				return;
			}
		} else if ((current_process & 1) == 0) {
			process_stack[stacklevel] = current_process;
			stacklevel++;
		}
	}

	current_process = processStat;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Jac_CheckStreamBufferEmpty(void)
{
	// UNUSED FUNCTION
}
