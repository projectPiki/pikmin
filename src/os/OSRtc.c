#include "Dolphin/os.h"
#include <stddef.h>

// forward declarations.
static BOOL WriteSram(void* buffer, u32 offset, u32 size);

static SramControlBlock Scb ATTRIBUTE_ALIGN(32);

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000118
 */
static BOOL GetRTC(u32* rtc)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00022C
 */
static BOOL __OSGetRTC(u32* rtc)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000108
 */
static BOOL __OSSetRTC(u32 rtc)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00011C
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

/**
 * @TODO: Documentation
 */
static void WriteSramCallback(s32 channel, OSContext* context)
{
	Scb.sync = WriteSram(Scb.sram + Scb.offset, Scb.offset, RTC_SRAM_SIZE - Scb.offset);
	if (Scb.sync) {
		Scb.offset = RTC_SRAM_SIZE;
	}
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 */
void __OSInitSram(void)
{
	Scb.locked = Scb.enabled = FALSE;
	Scb.sync                 = ReadSram(&Scb);
	Scb.offset               = RTC_SRAM_SIZE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068
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

/**
 * @TODO: Documentation
 */
OSSram* __OSLockSram(void)
{
	return LockSram(0);
}

/**
 * @TODO: Documentation
 */
OSSramEx* __OSLockSramEx(void)
{
	return LockSram(sizeof(OSSram));
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 */
BOOL __OSUnlockSram(BOOL commit)
{
	return UnlockSram(commit, 0);
}

/**
 * @TODO: Documentation
 */
BOOL __OSUnlockSramEx(BOOL commit)
{
	return UnlockSram(commit, sizeof(OSSram));
}

/**
 * @TODO: Documentation
 */
BOOL __OSSyncSram(void)
{
	return Scb.sync;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000110
 */
void __OSCheckSram(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000124
 */
BOOL __OSReadROM(void* buffer, s32 length, s32 offset)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
void __OSReadROMCallback(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000110
 */
void __OSReadROMAsync(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 */
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

inline OSSram* __OSLockSramHACK()
{
	return LockSram(0);
}

/**
 * @TODO: Documentation
 */
u32 OSGetProgressiveMode(void)
{
#if defined(VERSION_G98E01_PIKIDEMO)
	OSSram* sram;
	u32 mode;

	sram = __OSLockSramHACK();
	mode = (sram->flags & 0x80) >> 7;
	__OSUnlockSram(FALSE);
	return mode;
#else

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
#endif
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
void OSGetVideoMode(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B0
 */
void OSSetVideoMode(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
u8 OSGetLanguage(void)
{
	OSSram* sram;
	u8 language;

	sram     = __OSLockSram();
	language = sram->language;
	__OSUnlockSram(FALSE);
	return language;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094
 */
void OSSetLanguage(u8)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void __OSGetBootMode(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A4
 */
void __OSSetBootMode(void)
{
	// UNUSED FUNCTION
}
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
u16 OSGetWirelessID(s32 channel)
{
	OSSramEx* sram;
	u16 id;

	sram = __OSLockSramEx();
	id   = sram->wirelessPadID[channel];
	__OSUnlockSramEx(FALSE);
	return id;
}

void OSSetWirelessID(s32 channel, u16 id)
{
	OSSramEx* sram;

	sram = __OSLockSramEx();
	if (sram->wirelessPadID[channel] != id) {
		sram->wirelessPadID[channel] = id;
		__OSUnlockSramEx(TRUE);
		return;
	}

	__OSUnlockSramEx(FALSE);
}
#endif
