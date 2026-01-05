#include "jaudio/ipldec.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspproc.h"
#include <stddef.h>

DSPTask EX_DSPTASK[4];

static u8 TASK_READPTR;
static u8 TASK_WRITEPTR;
static u8 TASK_REMAIN;

/**
 * @TODO: Documentation
 */
static DSPTask* WriteTask(u8 target, u32 cmd, void* task, DSPCallback callback)
{
	if (TASK_REMAIN == 4) {
		return NULL;
	}

	DSPTask* dspTask  = &EX_DSPTASK[TASK_WRITEPTR];
	dspTask->target   = target;
	dspTask->cmd      = cmd;
	dspTask->task     = task;
	dspTask->callback = callback;

	TASK_WRITEPTR++;
	if (TASK_WRITEPTR == 4) {
		TASK_WRITEPTR = 0;
	}

	TASK_REMAIN++;
	return EX_DSPTASK;
}

/**
 * @TODO: Documentation
 */
static void DoTask()
{
	STACK_PAD_VAR(1);

	while (TASK_REMAIN != 0) {
		DSPTask* dspTask = &EX_DSPTASK[TASK_READPTR];
		void* task       = dspTask->task;
		u32 cmd          = dspTask->cmd;
		DSPCallback cb   = dspTask->callback;
		switch (dspTask->target) {
		case DSPTARGET_IPL:
		{
			DiplSec(cmd);
			break;
		}
		case DSPTARGET_AGB:
		{
			DagbSec(cmd);
			break;
		}
		}

		if (cb) {
			cb(task);
		}

		TASK_READPTR++;
		if (TASK_READPTR == 4) {
			TASK_READPTR = 0;
		}

		TASK_REMAIN--;
	}
}

/**
 * @TODO: Documentation
 */
BOOL DspExtraTaskCheck()
{
	DoTask();
	return TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A8
 */
void Jac_IPLDspSec(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Jac_DSPcardDecodeAsync(void* task, void* cmd, DSPCallback callback)
{
	while (WriteTask(DSPTARGET_IPL, (u32)cmd, task, callback) == NULL) {
		;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void Jac_DSPagbDecodeAsync(void*, void*, void (*)(void*))
{
	// UNUSED FUNCTION
}
