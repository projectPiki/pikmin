#include "jaudio/audiomesg.h"

/**
 * @TODO: Documentation
 */
void Jac_InitMessageQueue(Jac_MessageQueue* queue, OSMessage* msgArray, s32 count)
{
	queue->msgArray   = msgArray;
	queue->msgCount   = count;
	queue->firstIndex = 0;
	queue->usedCount  = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void Jac_SendMessageBlock(Jac_MessageQueue*, OSMessage)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
BOOL Jac_SendMessage(Jac_MessageQueue* queue, OSMessage msg)
{
	int mesgId;
	BOOL enable = OSDisableInterrupts();

	while (queue->msgCount <= queue->usedCount) {
		OSRestoreInterrupts(enable);
		return FALSE;
	}

	mesgId                  = (queue->msgCount - 1) & (queue->firstIndex + queue->usedCount);
	queue->msgArray[mesgId] = msg;
	queue->usedCount++;

	OSRestoreInterrupts(enable);

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL Jac_ReceiveMessage(Jac_MessageQueue* queue, OSMessage* outMsg)
{
	BOOL enable = OSDisableInterrupts();
	BOOL res    = Jac_ReceiveMessage_Fast(queue, outMsg);
	OSRestoreInterrupts(enable);
	return res;
}

/**
 * @TODO: Documentation
 */
BOOL Jac_ReceiveMessage_Fast(Jac_MessageQueue* queue, OSMessage* outMsg)
{
	while (queue->usedCount == 0) {
		return FALSE;
	}

	if (outMsg) {
		*outMsg = queue->msgArray[queue->firstIndex];
	}

	queue->firstIndex = (queue->firstIndex + 1) & (queue->msgCount - 1);
	queue->usedCount--;

	return TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000088
 */
void Jac_JamMessage(Jac_MessageQueue*, OSMessage)
{
	// UNUSED FUNCTION
}
