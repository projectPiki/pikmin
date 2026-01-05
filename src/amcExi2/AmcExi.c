#include "Dolphin/AmcExi2.h"
#include "Dolphin/hw_regs.h"
#include <string.h>

static ECB Ecb;
static ECB* exi = &Ecb;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000144
 */
static void CompleteTransfer()
{
	u8* dst;
	u32 immData2;
	s32 i;
	s32 dstLen;

	if (exi->state & 3) {
		if (exi->state & 2) {
			dstLen = exi->length;
			if (dstLen != 0) {
				dst      = exi->buffer;
				immData2 = __EXIRegs[EXI_CHAN_2_IMM];

				for (i = 0; i < dstLen; i++) {
					*dst++ = (immData2 >> ((3 - i) * 8));
				}
			}
		}
		exi->state &= 0xFFFFFFFC;
	}
}

/**
 * @TODO: Documentation
 */
s32 AmcEXIImm(void* buf, s32 len, u32 type, EXICallback cb)
{
	BOOL intrEnable;
	int immData;
	int i;
	int maskType = 2;

	intrEnable = OSDisableInterrupts();

	if ((exi->state & 3) || !(exi->state & 4)) {
		OSRestoreInterrupts(intrEnable);
		return 0;
	}

	exi->exiCallback2 = cb;
	if ((u32)exi->exiCallback2 != 0U) {
		AmcEXIClearInterrupts(0, 1);
		__OSUnmaskInterrupts(0x200000U >> (maskType * 3));
	}

	exi->state |= 2;
	if (type != 0) {
		immData = 0;

		for (i = 0; i < len; i++) {
			immData |= (int)((u8*)buf)[i] << ((3 - i) * 8);
		}
		__EXIRegs[EXI_CHAN_2_IMM] = immData;
	}

	exi->buffer                   = buf;
	exi->length                   = (type != 1) ? len : 0;
	__EXIRegs[EXI_CHAN_2_CONTROL] = (type * 4) | 1 | ((len - 1) * 0x10);

	OSRestoreInterrupts(intrEnable);
	return 1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000DC
 */
void AmcEXIDma(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void AmcEXISync()
{
	while (exi->state & 4) {
		if (!(__EXIRegs[EXI_CHAN_2_CONTROL] & 1)) {
			s32 intrEnable = OSDisableInterrupts();
			CompleteTransfer();
			OSRestoreInterrupts(intrEnable);
			break;
		}
	}
}

/**
 * @TODO: Documentation
 */
void AmcEXIClearInterrupts(s32 doProcessInterface, s32 doExternalInterface)
{
	u32 exiStat;
	u32 piCause;

	if (doProcessInterface != 0) {
		piCause = __PIRegs[PI_INTRPT_SRC];
		piCause &= 0x1000;
		piCause |= 0x1000;
		__PIRegs[PI_INTRPT_SRC] = piCause;
	}
	if (doExternalInterface != 0) {
		exiStat = __EXIRegs[EXI_CHAN_2_STAT];
		exiStat &= 0x7F5;
		exiStat |= 8;
		__EXIRegs[EXI_CHAN_2_STAT] = exiStat;
	}
}

/**
 * @TODO: Documentation
 */
void* AmcEXISetExiCallback(EXICallback cb)
{
	EXICallback exiCallback;
	s32 intrEnable;

	intrEnable = OSDisableInterrupts();
	if (cb) {
		__OSUnmaskInterrupts(0x40);
	} else {
		__OSMaskInterrupts(0x40);
	}

	exiCallback      = exi->exiCallback;
	exi->exiCallback = cb;
	OSRestoreInterrupts(intrEnable);
	return exiCallback;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void AmcEXIEnable32MHz(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void AmcEXIDisable32MHz(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 AmcEXISelect(u32 freq)
{
	BOOL intrEnable;
	int exiStat;

	intrEnable = OSDisableInterrupts();
	if (exi->state & 4) {
		OSRestoreInterrupts(intrEnable);
		return 0;
	}
	exi->state |= 4;
	exiStat = __EXIRegs[EXI_CHAN_2_STAT];
	exiStat &= 0x405;
	exiStat |= ((freq * 0x10) | 0x80);
	__EXIRegs[EXI_CHAN_2_STAT] = exiStat;
	OSRestoreInterrupts(intrEnable);
	return 1;
}

/**
 * @TODO: Documentation
 */
s32 AmcEXIDeselect()
{
	s32 intrEnable = OSDisableInterrupts();
	int exiStat;

	if (!(exi->state & 4)) {
		OSRestoreInterrupts(intrEnable);
		return 0;
	}
	exi->state &= ~0x4;
	exiStat = __EXIRegs[EXI_CHAN_2_STAT];
	exiStat &= 0x405;
	__EXIRegs[EXI_CHAN_2_STAT] = exiStat;
	OSRestoreInterrupts(intrEnable);
	return 1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001DC
 */
void AmcTCIntrruptHandler(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static void AmcDebugIntHandler(__OSInterrupt intr, OSContext* context)
{
	EXICallback exiCallback;

	AmcEXIClearInterrupts(TRUE, FALSE);
	exiCallback = exi->exiCallback;
	if (exiCallback) {
		exiCallback(2, context);
	}
}

/**
 * @TODO: Documentation
 */
void AmcEXIEnableInterrupts()
{
	__OSMaskInterrupts(0x8000);
	__OSSetInterruptHandler(__OS_INTERRUPT_PI_DEBUG, AmcDebugIntHandler);
	__OSUnmaskInterrupts(0x40);
}

/**
 * @TODO: Documentation
 */
void AmcEXIInit()
{
	memset(&Ecb, 0, sizeof(Ecb));
	__EXIRegs[EXI_CHAN_2_STAT] = 0;
	__SIRegs[SI_EXI_LOCK]      = 0;
}
