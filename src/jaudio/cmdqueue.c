#include "jaudio/cmdqueue.h"

#include "jaudio/playercall.h"
#include "jaudio/verysimple.h"
#include "jaudio/jammain_2.h"

/*
 * --INFO--
 * Address:	8001B960
 * Size:	00003C
 */
static void Add_Queue(CmdQueue* cmdQueue)
{
	CmdQueue* curr;
	CmdQueue* prev;

	curr           = queue_list;
	cmdQueue->next = (CmdQueue*)NULL;
	if (!queue_list) {
		queue_list = cmdQueue;
		return;
	}
	while (curr) {
		prev = curr;
		curr = prev->next;
	}
	prev->next = cmdQueue;
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

/*
 * --INFO--
 * Address:	8001B9A0
 * Size:	000060
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

/*
 * --INFO--
 * Address:	8001BA00
 * Size:	000030
 */
void Jal_SendCmdQueue_Noblock(CmdQueue* volatile queue, volatile u16 msg)
{
	u32 badCompiler;
	Jac_SendMessage(&queue->msgQueue, (OSMessage)msg);
}

/*
 * --INFO--
 * Address:	8001BA40
 * Size:	000054
 */
void Jal_SendCmdQueue_Force(CmdQueue* queue, u16 msg)
{
	OSMessage outMsg;
	if (!Jac_SendMessage(&queue->msgQueue, (OSMessage)msg)) {
		Jac_ReceiveMessage(&queue->msgQueue, &outMsg);
		Jac_SendMessage(&queue->msgQueue, (OSMessage)msg);
	}
}

/*
 * --INFO--
 * Address:	8001BAA0
 * Size:	000078
 */
static s32 Jal_FrameWork(void*)
{
	CmdQueue* curr;
	OSMessage message;
	u32 badCompiler;

	for (curr = queue_list; curr; curr = curr->next) {
		if (Jam_CheckPortAppDirect(curr->track, curr->_64, 1) == 1) {
			if (Jac_ReceiveMessage_Fast(&curr->msgQueue, &message) == 1) {
				Jam_WritePortAppDirect(curr->track, curr->_64, (u16)message);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8001BB20
 * Size:	00002C
 */
void Jal_CmdQueue_Init(void)
{
	Jac_RegisterPlayerCallback(Jal_FrameWork, NULL);
}
