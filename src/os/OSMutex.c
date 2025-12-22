#include "Dolphin/os.h"

void OSInitMutex(OSMutex* mutex)
{
	OSInitThreadQueue(&mutex->queue);
	mutex->thread = NULL;
	mutex->count  = 0;
}

void OSLockMutex(OSMutex* mutex)
{
	BOOL enabled            = OSDisableInterrupts();
	OSThread* currentThread = OSGetCurrentThread();
	OSThread* ownerThread;

	while (TRUE) {
		ownerThread = mutex->thread;
		if (ownerThread == 0) {
			mutex->thread = currentThread;
			mutex->count++;
			AddTailMutex(&currentThread->queueMutex, mutex, link);
			break;
		} else if (ownerThread == currentThread) {
			mutex->count++;
			break;
		} else {
			currentThread->mutex = mutex;
			__OSPromoteThread(mutex->thread, currentThread->priority);
			OSSleepThread(&mutex->queue);
			currentThread->mutex = NULL;
		}
	}
	OSRestoreInterrupts(enabled);
}

void OSUnlockMutex(OSMutex* mutex)
{
	BOOL enabled            = OSDisableInterrupts();
	OSThread* currentThread = OSGetCurrentThread();

	if (mutex->thread == currentThread && --mutex->count == 0) {
		RemoveItemMutex(&currentThread->queueMutex, mutex, link);
		mutex->thread = NULL;
		if (currentThread->priority < currentThread->base) {
			currentThread->priority = __OSGetEffectivePriority(currentThread);
		}

		OSWakeupThread(&mutex->queue);
	}
	OSRestoreInterrupts(enabled);
}

void __OSUnlockAllMutex(OSThread* thread)
{
	OSMutex* mutex;

	while (thread->queueMutex.head) {
		RemoveHeadMutex(&thread->queueMutex, mutex, link);
		mutex->count  = 0;
		mutex->thread = NULL;
		OSWakeupThread(&mutex->queue);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
BOOL OSTryLockMutex(OSMutex* mutex)
{
	// UNUSED FUNCTION
}

void OSInitCond(OSCond* cond)
{
	OSInitThreadQueue(&cond->queue);
}

void OSWaitCond(OSCond* cond, OSMutex* mutex)
{
	BOOL enabled            = OSDisableInterrupts();
	OSThread* currentThread = OSGetCurrentThread();
	s32 count;

	if (mutex->thread == currentThread) {
		count        = mutex->count;
		mutex->count = 0;
		RemoveItemMutex(&currentThread->queueMutex, mutex, link);
		mutex->thread = NULL;

		if (currentThread->priority < currentThread->base) {
			currentThread->priority = __OSGetEffectivePriority(currentThread);
		}

		OSDisableScheduler();
		OSWakeupThread(&mutex->queue);
		OSEnableScheduler();
		OSSleepThread(&cond->queue);
		OSLockMutex(mutex);
		mutex->count = count;
	}

	OSRestoreInterrupts(enabled);
}

void OSSignalCond(OSCond* cond)
{
	OSWakeupThread(&cond->queue);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void IsMember(void)
{
	// UNUSED FUNCTION
}

int __OSCheckMutex(OSMutex* mutex)
{
	OSThread* thread;
	OSThreadQueue* queue;
	s32 priority;

	priority = 0;
	queue    = &mutex->queue;

	if (queue->head != NULL && queue->head->link.prev != NULL) {
		return 0;
	}
	if (queue->tail != NULL && queue->tail->link.next != NULL) {
		return 0;
	}
	thread = queue->head;
	while (thread) {
		if (thread->link.next != NULL && (thread != thread->link.next->link.prev)) {
			return 0;
		}
		if (thread->link.prev != NULL && (thread != thread->link.prev->link.next)) {
			return 0;
		}
		if (thread->state != 4) {
			return 0;
		}
		if (thread->priority < priority) {
			return 0;
		}
		priority = thread->priority;
		thread   = thread->link.next;
	}
	if (mutex->thread) {
		if (mutex->count <= 0) {
			return 0;
		}
	} else if (mutex->count != 0) {
		return 0;
	}
	return 1;
}

int __OSCheckDeadLock(OSThread* thread)
{
	OSMutex* mutex = thread->mutex;

	while (mutex && mutex->thread) {
		if (mutex->thread == thread) {
			return 1;
		}
		mutex = mutex->thread->mutex;
	}
	return 0;
}

int __OSCheckMutexes(OSThread* thread)
{
	OSMutex* mutex = thread->queueMutex.head;

	while (mutex) {
		if (mutex->thread != thread) {
			return 0;
		}
		if (__OSCheckMutex(mutex) == 0) {
			return 0;
		}
		mutex = mutex->link.next;
	}
	return 1;
}
