#include "jaudio/fxinterface.h"

#include "Dolphin/os.h"
#include "jaudio/sample.h"

static u16 SEND_TABLE[] = {
	0x0D00, 0x0D60, 0x0DC0, 0x0E20, 0x0E80, 0x0EE0, 0x0CA0, 0x0F40, 0x0FA0, 0x0B00, 0x09A0, 0x0000,
};

BOOL DFX_SetFxLine(u8 idx, s16* circularBufferBase, FxlineConfig* config)
{
	STACK_PAD_VAR(2);
	s16** REF_circularBufferBase;

	FXBuffer* buf;
	BOOL restoreInterrupts;

	restoreInterrupts = OSDisableInterrupts();
	buf               = GetFxHandle(idx);

	buf->enabled = DSP_FALSE;
	if (config) {
		buf->dest[0].volume     = config->volume0;
		buf->dest[0].bufferId   = SEND_TABLE[config->sendIdx0];
		buf->dest[1].volume     = config->volume1;
		buf->dest[1].bufferId   = SEND_TABLE[config->sendIdx1];
		buf->circularBufferSize = config->circularBufferSize;
		DSP_SetFilterTable(buf->filterCoeffs, config->filterCoeffs, 8);
	}
	REF_circularBufferBase = &circularBufferBase;
	if (circularBufferBase && config) {
		int size = config->circularBufferSize * 0xa0; // TODO: What is 160 bytes large?

		buf->circularBufferBase = circularBufferBase;
		Jac_bzero(circularBufferBase, size);
		DCFlushRange(circularBufferBase, size);
	} else if (!config || circularBufferBase) {
		buf->circularBufferBase = circularBufferBase;
	}
	if (buf->circularBufferBase) {
		buf->enabled = config->enabled;
	} else {
		buf->enabled = DSP_FALSE;
	}
	DCFlushRange(buf, sizeof(FXBuffer));
	OSRestoreInterrupts(restoreInterrupts);
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void DFX_ChangeFxLineParam(u8, u8, u32)
{
	// UNUSED FUNCTION
}
