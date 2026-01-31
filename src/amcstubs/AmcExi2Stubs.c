#include "Dolphin/AmcExi2.h"

// This file is exclusively present in PAL Demo

/**
 * @TODO: Documentation
 */
void EXI2_Init(vu8** inputPendingPtrRef, EXICallback monitorCallback)
{
	return;
}

/**
 * @TODO: Documentation
 */
void EXI2_EnableInterrupts(void)
{
	return;
}

/**
 * @TODO: Documentation
 */
int EXI2_Poll(void)
{
	return 0;
}

AmcExiError EXI2_ReadN(void* dest, u32 len)
{
	return AMC_EXI_NO_ERROR;
}

AmcExiError EXI2_WriteN(const void* src, u32 len)
{
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
 */
BOOL AMC_IsStub(void)
{
	return TRUE;
}
