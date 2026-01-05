#include "Dolphin/dsp.h"
#include "Dolphin/os.h"
#include <stddef.h>

#if defined(VERSION_GPIP01_00)

DSPTaskInfo* __DSP_tmp_task;

/**
 * @TODO: Documentation
 */
DSPTaskInfo* DSPAddTask(DSPTaskInfo* info)
{
	int inter;

	if (DSP_prior_task == 0) {
		OSReport("Prior Task is not inited\n");
		return NULL;
	}

	inter = OSDisableInterrupts();
	__DSP_insert_task(info);
	info->state = 0;
	info->flags = 1;
	OSRestoreInterrupts(inter);
	return info;
}

/**
 * @TODO: Documentation
 */
void DSPAddPriorTask(DSPTaskInfo* info)
{
	int inter;

	if (DSP_prior_task) {
		OSReport("Already inited prior DSP task\n");
		return;
	}
	inter          = OSDisableInterrupts();
	DSP_prior_task = info;
	info->state    = 0;
	info->flags    = 1;
	__DSP_boot_task(info);
	OSRestoreInterrupts(inter);
}

#endif
