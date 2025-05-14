#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	801F97B4
 * Size:	000060
 */
void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* msgArray, s32 msgCount)
{
	OSInitThreadQueue(&queue->queueSend);
	OSInitThreadQueue(&queue->queueReceive);
	queue->msgArray   = msgArray;
	queue->msgCount   = msgCount;
	queue->firstIndex = 0;
	queue->usedCount  = 0;
}

/*
 * --INFO--
 * Address:	801F9814
 * Size:	0000C8
 */
BOOL OSSendMessage(OSMessageQueue* queue, OSMessage msg, s32 flags)
{
	int mesgId;
	u32 interrupt;

	interrupt = OSDisableInterrupts();

	while (queue->msgCount <= queue->usedCount) {
		if (!(flags & OS_MSG_PERSISTENT)) {
			OSRestoreInterrupts(interrupt);
			return FALSE;
		}

		OSSleepThread(&queue->queueSend);
	}

	mesgId                  = (queue->firstIndex + queue->usedCount) % queue->msgCount;
	queue->msgArray[mesgId] = msg;
	queue->usedCount++;

	OSWakeupThread(&queue->queueReceive);
	OSRestoreInterrupts(interrupt);
	return TRUE;
}

/*
 * --INFO--
 * Address:	801F98DC
 * Size:	0000DC
 */
BOOL OSReceiveMessage(OSMessageQueue* queue, OSMessage* buffer, s32 flags)
{
	u32 interrupt;

	interrupt = OSDisableInterrupts();

	while (queue->usedCount == 0) {
		if (!(flags & OS_MSG_PERSISTENT)) {
			OSRestoreInterrupts(interrupt);
			return FALSE;
		}

		OSSleepThread(&queue->queueReceive);
	}

	if (buffer) {
		buffer[0] = queue->msgArray[queue->firstIndex];
	}

	queue->firstIndex = (queue->firstIndex + 1) % queue->msgCount;
	queue->usedCount--;

	OSWakeupThread(&queue->queueSend);
	OSRestoreInterrupts(interrupt);
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
BOOL OSJamMessage(OSMessageQueue* queue, OSMessage msg, s32 flags)
{
	// UNUSED FUNCTION
}
