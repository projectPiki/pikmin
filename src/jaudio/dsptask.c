#include "jaudio/dsptask.h"

#include "Dolphin/dsp.h"
#include "jaudio/dspboot.h"
#include <stddef.h>

#if defined(VERSION_GPIP01)

static DSPTaskInfo audio_task;
static u32 AUDIO_YIELD_BUFFER[0x800] ATTRIBUTE_ALIGN(32);
#include "jaudio/dsprom.h" // For `jdsp`

static struct TaskWork {
	u16 mTaskId;
	CommandTask mCallback;
} taskwork[0x10];

/**
 * @TODO: Documentation
 */
static void DspHandShake(void* a)
{
	volatile u32 mail;
	STACK_PAD_VAR(2);

	do {
		mail = DSPCheckMailFromDSP();
	} while (mail == 0);
	DSPReadMailFromDSP();
	DSPCheckMailFromDSP();
	Dsp_Running_Start();
}

/**
 * @TODO: Documentation
 */
void DspBoot(DSPCallback cback)
{
	DspInitWork();
	audio_task.priority          = 0xf0;
	audio_task.iram_mmem_addr    = jdsp + 0x40000000;
	audio_task.iram_length       = 0x1a60;
	audio_task.iram_addr         = 0;
	audio_task.dram_mmem_addr    = (u16*)((int)&audio_task + 0x80000000) + 0x30;
	audio_task.dram_length       = 0x2000;
	audio_task.dram_addr         = 0;
	audio_task.dsp_init_vector   = 0;
	audio_task.dsp_resume_vector = 0x10;
	audio_task.init_cb           = DspHandShake;
	audio_task.res_cb            = 0;
	audio_task.done_cb           = 0;
	audio_task.req_cb            = cback;
	DSPInit();
	DSPAddPriorTask(&audio_task);
}

/**
 * @TODO: Documentation
 */
u32 DSPSendCommands2(u32* commands, u32 count, CommandTask callback)
{
	int i;
	u32 interupt;
	u32 res;

	while (Dsp_Running_Check() == 0) { }

	interupt = OSDisableInterrupts();

	if (DSPCheckMailToDSP()) {
		OSRestoreInterrupts(interupt);
		return -1;
	}

	DSPSendMailToDSP(count);
	DSPAssertInt();

	while (DSPCheckMailToDSP()) { }

	if (count == 0) {
		count = 2;
	}

	if (callback != 0) {
		res = DspStartWork(*commands, callback);
	}

	for (i = 0; i < count; i++) {
		DSPSendMailToDSP(commands[i]);

		while (DSPCheckMailToDSP()) { }
	}

	OSRestoreInterrupts(interupt);

	return res;
}

static u32 taskreadp;
static u32 taskwritep;

/**
 * @TODO: Documentation
 */
static void DspInitWork()
{
	for (int i = 0; i < 0x10; i++) {
		taskwork[i].mCallback = NULL;
	}
}

/**
 * @TODO: Documentation
 */
int DspStartWork(u32 a, CommandTask task)
{
	u32 p;

	p = taskwritep + 1;

	if ((p & 0xf) == taskreadp) {
		return 0;
	}

	taskwork[taskwritep].mTaskId = (a >> 0x10);
	taskwork[taskwritep].mCallback = task;

	taskwritep = (p & 0xf);
	return p;
}

/**
 * @TODO: Documentation
 */
void DspFinishWork(u16 a)
{
	if (a == taskwork[taskreadp].mTaskId) {
		if (taskwork[taskreadp].mCallback) {
			taskwork[taskreadp].mCallback(taskreadp);
		}
		taskreadp = (taskreadp + 1 & 0xf);
	}
}
#endif
