#include "Dolphin/dvd.h"

struct DVDQueue WaitingQueue[4];

void __DVDClearWaitingQueue()
{
	int i;

	for (i = 0; i < 4; i++) {
		struct DVDQueue* ptr = &WaitingQueue[i];

		ptr->mHead = ptr;
		ptr->mTail = ptr;
	}
}

BOOL __DVDPushWaitingQueue(int idx, struct DVDQueue* newTail)
{
	BOOL intrEnabled = OSDisableInterrupts();

	struct DVDQueue* waitingQueue = &WaitingQueue[idx];

	waitingQueue->mTail->mHead = newTail;
	newTail->mTail             = waitingQueue->mTail;
	newTail->mHead             = waitingQueue;
	waitingQueue->mTail        = newTail;

	OSRestoreInterrupts(intrEnabled);
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void PopWaitingQueuePrio(void)
{
	// UNUSED FUNCTION
}

DVDQueue* __DVDPopWaitingQueue()
{
	BOOL intrEnabled = OSDisableInterrupts();
	int i;

	for (i = 0; i < 4; i++) {
		if (WaitingQueue[i].mHead != &WaitingQueue[i]) {
			DVDQueue* tempQueue;
			DVDQueue* outQueue;

			OSRestoreInterrupts(intrEnabled);

			intrEnabled            = OSDisableInterrupts();
			tempQueue              = &WaitingQueue[i];
			outQueue               = tempQueue->mHead;
			tempQueue->mHead       = outQueue->mHead;
			outQueue->mHead->mTail = tempQueue;
			OSRestoreInterrupts(intrEnabled);

			outQueue->mHead = NULL;
			outQueue->mTail = NULL;
			return outQueue;
		}
	}
	OSRestoreInterrupts(intrEnabled);
	return NULL;
}

BOOL __DVDCheckWaitingQueue()
{
	BOOL intrEnabled = OSDisableInterrupts();
	int i;

	for (i = 0; i < 4; i++) {
		if (WaitingQueue[i].mHead != &WaitingQueue[i]) {
			OSRestoreInterrupts(intrEnabled);
			return TRUE;
		}
	}
	OSRestoreInterrupts(intrEnabled);
	return FALSE;
}

BOOL __DVDDequeueWaitingQueue(DVDQueue* queue)
{
	BOOL intrEnabled      = OSDisableInterrupts();
	struct DVDQueue* tail = queue->mTail;
	struct DVDQueue* head = queue->mHead;

	if (tail == NULL || head == NULL) {
		OSRestoreInterrupts(intrEnabled);
		return FALSE;
	}
	tail->mHead = head;
	head->mTail = tail;
	OSRestoreInterrupts(intrEnabled);
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void __DVDIsBlockInWaitingQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void DVDDumpWaitingQueue(void)
{
	// UNUSED FUNCTION
}
