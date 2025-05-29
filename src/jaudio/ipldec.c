#include "jaudio/ipldec.h"
#include "jaudio/audiostruct.h"
#include "jaudio/dspproc.h"

DSPTask EX_DSPTASK[4];

static u8 TASK_READPTR;
static u8 TASK_WRITEPTR;
static u8 TASK_REMAIN;

/*
 * --INFO--
 * Address:	80008A00
 * Size:	000070
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

/*
 * --INFO--
 * Address:	80008A80
 * Size:	0000C0
 */
static void DoTask()
{
	u32 badCompiler;

	while (TASK_REMAIN != 0) {
		DSPTask* dspTask = &EX_DSPTASK[TASK_READPTR];
		void* task       = dspTask->task;
		u32 cmd          = dspTask->cmd;
		DSPCallback cb   = dspTask->callback;
		switch (dspTask->target) {
		case DSPTARGET_IPL:
			DiplSec(cmd);
			break;
		case DSPTARGET_AGB:
			DagbSec(cmd);
			break;
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

/*
 * --INFO--
 * Address:	80008B40
 * Size:	000024
 */
BOOL DspExtraTaskCheck()
{
	DoTask();
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void Jac_IPLDspSec(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80008B80
 * Size:	00004C
 */
void Jac_DSPcardDecodeAsync(void* task, void* cmd, DSPCallback callback)
{
	while (WriteTask(DSPTARGET_IPL, (u32)cmd, task, callback) == NULL) {
		;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Jac_DSPagbDecodeAsync(void*, void*, void (*)(void*))
{
	// UNUSED FUNCTION
}
