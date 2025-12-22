#include "Dolphin/os.h"

// forward declarations.
static BOOL WriteSram(void* buffer, u32 offset, u32 size);

static SramControlBlock Scb ATTRIBUTE_ALIGN(32);

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
static BOOL GetRTC(u32* rtc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
static BOOL __OSGetRTC(u32* rtc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
static BOOL __OSSetRTC(u32 rtc)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
static BOOL ReadSram(void* buffer)
{
	BOOL err;
	u32 cmd;

	DCInvalidateRange(buffer, RTC_SRAM_SIZE);

	if (!EXILock(RTC_CHAN, RTC_DEV, 0)) {
		return FALSE;
	}
	if (!EXISelect(RTC_CHAN, RTC_DEV, RTC_FREQ)) {
		EXIUnlock(RTC_CHAN);
		return FALSE;
	}

	cmd = RTC_CMD_READ | RTC_SRAM_ADDR;
	err = FALSE;
	err |= !EXIImm(RTC_CHAN, &cmd, 4, 1, NULL);
	err |= !EXISync(RTC_CHAN);
	err |= !EXIDma(RTC_CHAN, buffer, RTC_SRAM_SIZE, 0, NULL);
	err |= !EXISync(RTC_CHAN);
	err |= !EXIDeselect(RTC_CHAN);
	EXIUnlock(RTC_CHAN);

	return !err;
	// UNUSED FUNCTION
}

static void WriteSramCallback(s32 channel, OSContext* context)
{
	Scb.sync = WriteSram(Scb.sram + Scb.offset, Scb.offset, RTC_SRAM_SIZE - Scb.offset);
	if (Scb.sync) {
		Scb.offset = RTC_SRAM_SIZE;
	}
}

static BOOL WriteSram(void* buffer, u32 offset, u32 size)
{
	BOOL err;
	u32 cmd;

	if (!EXILock(RTC_CHAN, RTC_DEV, WriteSramCallback)) {
		return FALSE;
	}
	if (!EXISelect(RTC_CHAN, RTC_DEV, RTC_FREQ)) {
		EXIUnlock(RTC_CHAN);
		return FALSE;
	}

	offset <<= 6;
	cmd = RTC_CMD_WRITE | RTC_SRAM_ADDR + offset;
	err = FALSE;
	err |= !EXIImm(RTC_CHAN, &cmd, 4, 1, NULL);
	err |= !EXISync(RTC_CHAN);
	err |= !EXIImmEx(RTC_CHAN, buffer, (s32)size, 1);
	err |= !EXIDeselect(RTC_CHAN);
	EXIUnlock(RTC_CHAN);

	return !err;
}

void __OSInitSram(void)
{
	Scb.locked = Scb.enabled = FALSE;
	Scb.sync                 = ReadSram(&Scb);
	Scb.offset               = RTC_SRAM_SIZE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
static void* LockSram(u32 offset)
{
	BOOL enabled;
	enabled = OSDisableInterrupts();

	if (Scb.locked != FALSE) {
		OSRestoreInterrupts(enabled);
		return NULL;
	}

	Scb.enabled = enabled;
	Scb.locked  = TRUE;

	return Scb.sram + offset;
}

OSSram* __OSLockSram(void)
{
	return LockSram(0);
}

OSSramEx* __OSLockSramEx(void)
{
	return LockSram(sizeof(OSSram));
}

static BOOL UnlockSram(BOOL commit, u32 offset)
{
	u16* p;

	if (commit) {
		if (offset == 0) {
			OSSram* sram = (OSSram*)Scb.sram;

			if (2u < (sram->flags & 3)) {
				sram->flags &= ~3;
			}

			sram->checkSum = sram->checkSumInv = 0;
			for (p = (u16*)&sram->counterBias; p < (u16*)(Scb.sram + sizeof(OSSram)); p++) {
				sram->checkSum += *p;
				sram->checkSumInv += ~*p;
			}
		}

		if (offset < Scb.offset) {
			Scb.offset = offset;
		}

		if (Scb.offset <= 20) {
			OSSramEx* sramEx = (OSSramEx*)(&Scb.sram[20]);
		}

		Scb.sync = WriteSram(Scb.sram + Scb.offset, Scb.offset, RTC_SRAM_SIZE - Scb.offset);
		if (Scb.sync) {
			Scb.offset = RTC_SRAM_SIZE;
		}
	}
	Scb.locked = FALSE;
	OSRestoreInterrupts(Scb.enabled);
	return Scb.sync;
}

BOOL __OSUnlockSram(BOOL commit)
{
	return UnlockSram(commit, 0);
}

BOOL __OSUnlockSramEx(BOOL commit)
{
	return UnlockSram(commit, sizeof(OSSram));
}

BOOL __OSSyncSram(void)
{
	return Scb.sync;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void __OSCheckSram(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
BOOL __OSReadROM(void* buffer, s32 length, s32 offset)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void __OSReadROMCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void __OSReadROMAsync(void)
{
	// UNUSED FUNCTION
}

u32 OSGetSoundMode(void)
{
	OSSram* sram;
	u32 mode;
	u32 tmp; // dumbass compiler

	sram = LockSram(0);
	mode = (sram->flags & 0x4) ? OS_SOUND_MODE_STEREO : OS_SOUND_MODE_MONO;
	__OSUnlockSram(FALSE);
	return mode;
}

void OSSetSoundMode(u32 mode)
{
	OSSram* sram;
	u32 tmp; // dumbass compiler

	mode <<= 2;
	mode &= 4;

	sram = LockSram(0);
	if (mode == (sram->flags & 4)) {
		__OSUnlockSram(FALSE);
		return;
	}

	sram->flags &= ~4;
	sram->flags |= mode;
	__OSUnlockSram(TRUE);
}

u32 OSGetProgressiveMode(void)
{
	OSSram* sram;
	u32 mode;
	u32 tmp;  // dumbass compiler
	u32 tmp2; // dumbass compiler

	sram = LockSram(0);
	if (sram->flags & 0x80) {
		mode = 1;
	} else {
		mode = 0;
	}
	__OSUnlockSram(FALSE);
	return mode;
}

void OSSetProgressiveMode(u32 mode)
{
	OSSram* sram;
	u32 tmp; // dumbass compiler

	mode <<= 7;
	mode &= 0x80;

	sram = LockSram(0);
	if (mode == (sram->flags & 0x80)) {
		__OSUnlockSram(FALSE);
		return;
	}

	sram->flags &= ~0x80;
	sram->flags |= mode;
	__OSUnlockSram(TRUE);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void OSGetVideoMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void OSSetVideoMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
u8 OSGetLanguage(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void OSSetLanguage(u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void __OSGetBootMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void __OSSetBootMode(void)
{
	// UNUSED FUNCTION
}
