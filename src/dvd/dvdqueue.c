#include "types.h"
#include "Dolphin/dvd.h"

struct DVDQueue WaitingQueue[4];

/*
 * --INFO--
 * Address:	80201F04
 * Size:	000038
 */
void __DVDClearWaitingQueue()
{
	int i;

	for (i = 0; i < 4; i++) {
		struct DVDQueue* ptr = &WaitingQueue[i];

		ptr->mHead = ptr;
		ptr->mTail = ptr;
	}
}

/*
 * --INFO--
 * Address:	80201F3C
 * Size:	000068
 */
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

/*
 * --INFO--
 * Address:	80201FA4
 * Size:	0000A0
 */
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

			outQueue->mHead = nullptr;
			outQueue->mTail = nullptr;
			return outQueue;
		}
	}
	OSRestoreInterrupts(intrEnabled);
	return nullptr;
}

/*
 * --INFO--
 * Address:	80202044
 * Size:	000058
 */
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

/*
 * --INFO--
 * Address:	8020209C
 * Size:	000060
 */
BOOL __DVDDequeueWaitingQueue(DVDQueue* queue)
{
	BOOL intrEnabled      = OSDisableInterrupts();
	struct DVDQueue* tail = queue->mTail;
	struct DVDQueue* head = queue->mHead;

	if (tail == nullptr || head == nullptr) {
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
