#include "jaudio/cmdqueue.h"

#include "jaudio/jammain_2.h"
#include "jaudio/playercall.h"
#include "jaudio/verysimple.h"

/**
 * @TODO: Documentation
 */
static void Add_Queue(CmdQueue* cmdQueue)
{
	CmdQueue* curr;
	CmdQueue* prev;

	curr           = queue_list;
	cmdQueue->next = NULL;
	if (!queue_list) {
		queue_list = cmdQueue;
		return;
	}

	while (prev = curr->next) {
		curr = prev;
	}
	curr->next = cmdQueue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void Del_Queue(CmdQueue*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Jal_AddCmdQueue(CmdQueue* cmdQueue, seqp_* track, u8 param_3)
{
	BOOL restoreInterrupts;

	restoreInterrupts = OSDisableInterrupts();
	cmdQueue->track   = track;
	cmdQueue->_64     = param_3;
	Jac_InitMessageQueue(&cmdQueue->msgQueue, &cmdQueue->message, 16);
	Add_Queue(cmdQueue);
	OSRestoreInterrupts(restoreInterrupts);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void Jal_RemoveCmdQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void Jal_SendCmdQueue(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Jal_SendCmdQueue_Noblock(CmdQueue* queue, u16 msg)
{
	CmdQueue** REF_queue;
	u16* REF_msg;

	REF_queue = &queue;
	REF_msg   = &msg;
	Jac_SendMessage(&queue->msgQueue, (OSMessage)msg);
}

/**
 * @TODO: Documentation
 */
void Jal_SendCmdQueue_Force(CmdQueue* queue, u16 msg)
{
	OSMessage outMsg;
	if (!Jac_SendMessage(&queue->msgQueue, (OSMessage)msg)) {
		Jac_ReceiveMessage(&queue->msgQueue, &outMsg);
		Jac_SendMessage(&queue->msgQueue, (OSMessage)msg);
	}
}

/**
 * @TODO: Documentation
 */
static s32 Jal_FrameWork(void*)
{
	CmdQueue* curr;
	OSMessage message;
	STACK_PAD_VAR(1);

	for (curr = queue_list; curr; curr = curr->next) {
		if (Jam_CheckPortAppDirect(curr->track, curr->_64, 1) == 1) {
			if (Jac_ReceiveMessage_Fast(&curr->msgQueue, &message) == 1) {
				Jam_WritePortAppDirect(curr->track, curr->_64, (u16)message);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void Jal_CmdQueue_Init(void)
{
	Jac_RegisterPlayerCallback(Jal_FrameWork, NULL);
}
