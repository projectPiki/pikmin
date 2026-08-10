#include "jaudio/dspboot.h"
#include "Dolphin/dsp.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include "jaudio/dspproc.h"

// For PAL, this data is contained in dsptask.c.
#if defined(VERSION_GPIP01)
#else
#include "jaudio/dsprom.h" // For `jdsp`
#endif

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void WRITEIO(u32, u16)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
void READIO(u32)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
void CHKCDCR(u8)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void DSPCall()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
s32 __DSPCheckMXICBoot2(DSPTaskInfo2* task)
{
	STACK_PAD_VAR(8);
	u32 mail;

	while (DSPCheckMailFromDSP() == 0)
		;
	mail = DSPReadMailFromDSP();

	if (mail == 0x8071FEED) {
		DSPSendMailToDSP(0x80F3A001);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP((u32)task->iram_mmem_addr);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0x80F3A002);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(task->iram_length);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0x80F3C002);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(task->iram_addr);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0x80F3B002);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0x80F3D001);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(task->dsp_init_vector);
		while (DSPCheckMailToDSP() != 0)
			;

		return 1;
	}

	if (mail == 0xC0FF0000 || mail == 0xC0FF0001) {
		DSPSendMailToDSP(0xC0028073);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC000FFCE);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(((u32)task->iram_mmem_addr >> 16) | 0xC0010000);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC000FFCF);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(((u32)task->iram_mmem_addr & 0xffff) | 0xC0010000);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC000FFCD);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(task->iram_addr | 0xC0010000);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC000FFC9);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC0010002);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC000FFCB);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(task->iram_length | 0xC0010000);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(0xC0028073);
		while (DSPCheckMailToDSP() != 0)
			;

		DSPSendMailToDSP(task->dsp_init_vector | 0xC0020000);
		while (DSPCheckMailToDSP() != 0)
			;

		return 1;
	}

	return 0;
}

/**
 * @TODO: Documentation
 */
void DSPInit(void)
{
}

/**
 * @TODO: Documentation
 */
void DSPInit2(DSPTaskInfo2* task)
{
	BOOL enable;
	u16 tmp;

	enable = OSDisableInterrupts();
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_DSP_DSP);

	tmp                           = __DSPRegs[DSP_CONTROL_STATUS];
	tmp                           = (tmp & ~0xA8) | 0x800;
	__DSPRegs[DSP_CONTROL_STATUS] = tmp;

	tmp                           = __DSPRegs[DSP_CONTROL_STATUS];
	tmp                           = (tmp & ~0xAC);
	__DSPRegs[DSP_CONTROL_STATUS] = tmp;

	OSRestoreInterrupts(enable);

	if (__DSPCheckMXICBoot2(task) != 1) {
		OSPanic("mxic.c", 357, "DSPInit(): MXIC Boot failed.");
	}
}

/**
 * @TODO: Documentation
 */
void DspBoot()
{
	// this is dumb
	STACK_PAD_VAR(2);

	DSPTaskInfo2 task;

	// this is also dumb
	STACK_PAD_VAR(2);

	task.iram_mmem_addr = jdsp;
	task.iram_length    = sizeof(jdsp);
	task.iram_addr      = 0;
	task.dram_mmem_addr = jdsp;
	task.dram_length    = 0x100;
	task.dram_addr      = 0;

	task.dsp_init_vector = 0;
	DSPInit2(&task);

	volatile u32 mail;
	do {
		mail = DSPCheckMailFromDSP();
	} while (mail == 0);

	DSPReadMailFromDSP();
	DSPCheckMailFromDSP();
	DwaitFrame();

	// this? definitely also dumb.
	STACK_PAD_VAR(3);
}
