#include "Dolphin/os.h"

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
