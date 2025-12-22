#include "Dolphin/AmcExi2.h"
#include "Dolphin/hw_regs.h"
#include "stl/stdio.h"

static u8 ucEXI2InputPending;
static u8* pucEXI2InputPending = &ucEXI2InputPending;
static s32 fExi2Selected;
static EXICallback TRK_Callback;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
static void EXI2_SetTRKCallback(EXICallback monitorCallback)
{
	BOOL enable  = OSDisableInterrupts();
	TRK_Callback = monitorCallback;
	OSRestoreInterrupts(enable);
}

/**
 * @TODO: Documentation
 */
static void EXI2_CallBack(s32 chan, OSContext* context)
{
	*pucEXI2InputPending = 1;
	if (TRK_Callback) {
		TRK_Callback(0, context);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
static s32 EXI2_Select(s32 freq, s32)
{
	s32 status = 0;

	while (status == 0) {
		status = AmcEXISelect(freq);
	}

	return status;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
static void EXI2_ToWriteMode(void)
{
	u32 buf = 0x80000000;

	AmcEXIImm(&buf, 2, 1, 0);
	AmcEXISync();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
static void EXI2_ToReadMode(u16 bufAddr)
{
	u32 buf = (bufAddr << 16);

	AmcEXIImm(&buf, 2, 1, 0);
	AmcEXISync();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B4
 */
static s32 EXI2_StartRead(void)
{
	u32 buf;
	s32 status;

	if (fExi2Selected != 0) {
		status = 1;
	} else {
		status = EXI2_Select(5, 0);
		if (status == 0) {
			printf("Can't select EXI2 port!\n");
			return 0;
		}
		fExi2Selected = 1;
		EXI2_ToReadMode(0);
		AmcEXIImm(&buf, 2, 0, 0);
		AmcEXISync();
	}

	return status;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
static void EXI2_FinishRead(void)
{
	AmcEXIDeselect();
	fExi2Selected        = 0;
	*pucEXI2InputPending = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A8
 */
static s32 EXI2_SendCmd(u8 bufAddrHi, u32 bufAddrLo, s32 bufAddr2, u32 p4)
{
	s32 status;
	s32 buf1 = (bufAddrHi << 24) | (bufAddrLo & 0xFFFFFF);
	s32 buf2 = bufAddr2;

	status = EXI2_Select(5, 0);

	EXI2_ToWriteMode();

	AmcEXIImm(&buf1, 4, 1, NULL);
	AmcEXISync();

	AmcEXIImm(&buf2, 4, 1, NULL);
	AmcEXISync();

	AmcEXIDeselect();
	return status;
}

/**
 * @TODO: Documentation
 */
void EXI2_Init(vu8** inputPendingPtrRef, EXICallback monitorCallback)
{
	*inputPendingPtrRef = pucEXI2InputPending;
	EXI2_SetTRKCallback(monitorCallback);
	AmcEXIInit();
	EXI2_SendCmd(1, 3, 0, 0);
}

/**
 * @TODO: Documentation
 */
void EXI2_EnableInterrupts(void)
{
	AmcEXISetExiCallback(EXI2_CallBack);
	AmcEXIEnableInterrupts();
}

/**
 * @TODO: Documentation
 */
int EXI2_Poll(void)
{
	u32 bufAddr;
	u32 bufAddr2;
	u32 stackPad;

	if (!(__PIRegs[PI_INTRPT_SRC] & 0x1000) && (*pucEXI2InputPending == 0)) {
		bufAddr = 0;
	} else {
		// yes this looks like EXI2_StartRead. no, using that function fucks with the stack.
		s32 status;

		if (fExi2Selected != 0) {
			status = 1;
		} else {
			status = EXI2_Select(5, 0);
			if (status == 0) {
				printf("Can't select EXI2 port!\n");
			} else {
				fExi2Selected = 1;
				EXI2_ToReadMode(0);
				AmcEXIImm(&bufAddr2, 2, 0, 0);
				AmcEXISync();
			}
		}
		AmcEXIImm(&bufAddr, 4, 0, 0);
		AmcEXISync();
		if (*pucEXI2InputPending == 0) {
			__PIRegs[PI_INTRPT_SRC] &= 0x1000;
			*pucEXI2InputPending = 1;
		}
	}
	return bufAddr;
}

/**
 * @TODO: Documentation
 */
AmcExiError EXI2_ReadN(void* dest, u32 len)
{
	u8* outputBytes = (u8*)dest;
	u32 wordCount   = len;
	s32 readStatus;
	int i, j;
	s32 size;
	int bytesInWord;
	u32 bufAddr;

	readStatus = EXI2_StartRead();
	if (readStatus == 0) {
		return AMC_EXI_UNSELECTED;
	}

	size = (wordCount / 4) + ((wordCount % 4) ? 1 : 0);

	for (i = 0; i < wordCount; i += 4) {
		AmcEXIImm(&bufAddr, ((u32)(i / 4) < (size - 1)) ? 4 : ((wordCount & 3) + (wordCount & 1)) == 2 ? 2 : 4, 0, 0);
		AmcEXISync();

		if ((wordCount - i) >= 4) {
			bytesInWord = 4;
		} else {
			bytesInWord = (((s32)wordCount) % 4);
		}

		for (j = 0; j < bytesInWord; j++) {
			outputBytes[i + j] = (bufAddr >> ((3 - j) * 8));
		}
	}

	EXI2_FinishRead();
	return AMC_EXI_NO_ERROR;
}

/**
 * @TODO: Documentation
 */
AmcExiError EXI2_WriteN(const void* src, u32 len)
{
	u32 size;
	u32 bufAddr;
	s32 res;
	u32 i;
	u32 unusedStack;
	u32* inputWords = (u32*)src;
	u32 max;

	size = len;
	if ((res = EXI2_Select(5, 0)) == 0) {
		return AMC_EXI_UNSELECTED;
	}

	EXI2_ToWriteMode();
	AmcEXIImm(&size, 4, 1, 0);
	AmcEXISync();

	max = ((size >> 2) + ((size & 3) ? 1 : 0));

	for (i = 0; i < max; i++) {
		AmcEXIImm(inputWords++, (i < (max - 1)) ? 4 : ((u32)((size & 3) + (size & 1)) == 2 ? 2 : 4), 1, 0);
		AmcEXISync();
	}
	AmcEXIDeselect();

	res = EXI2_Select(5, 0);
	if (res == 0) {
		return AMC_EXI_UNSELECTED;
	}

	EXI2_ToReadMode(1);
	AmcEXIImm(&bufAddr, 2, 0, 0);
	AmcEXISync();

	do {
		AmcEXIImm(&bufAddr, 2, 0, 0);
		AmcEXISync();
	} while (!((bufAddr >> 16) & 1));

	AmcEXIDeselect();
	return AMC_EXI_NO_ERROR;
}

/**
 * @TODO: Documentation
 */
void EXI2_Reserve(void)
{
}

/**
 * @TODO: Documentation
 */
void EXI2_Unreserve(void)
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B0
 */
void EXI2_GetStatusReg(void)
{
	// UNUSED FUNCTION
}
