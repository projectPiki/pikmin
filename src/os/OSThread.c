#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

static vu32 RunQueueBits;
static volatile BOOL RunQueueHint;
static vs32 Reschedule;

static OSThreadQueue RunQueue[32];
static OSThread IdleThread;
static OSThread DefaultThread;
static OSContext IdleContext;
static void DefaultSwitchThreadCallback(OSThread* from, OSThread* to);

// Fabricated helper inlines.
// Initialise mutex queue (mutex equiv. to OSInitThreadQueue below).
static inline void InitMutexQueue(OSMutexQueue* queue)
{
	queue->head = queue->tail = NULL;
}

void __OSThreadInit(void)
{
	OSThread* thread = &DefaultThread;
	int prio;

	thread->state    = OS_THREAD_STATE_RUNNING;
	thread->attr     = OS_THREAD_ATTR_DETACH;
	thread->priority = thread->base = 16;
	thread->suspend                 = 0;
	thread->val                     = (void*)-1;
	thread->mutex                   = NULL;
	OSInitThreadQueue(&thread->queueJoin);
	InitMutexQueue(&thread->queueMutex);

	__OSFPUContext = &thread->context;

	OSClearContext(&thread->context);
	OSSetCurrentContext(&thread->context);
	thread->stackBase   = (void*)_stack_addr;
	thread->stackEnd    = (void*)_stack_end;
	*(thread->stackEnd) = OS_THREAD_STACK_MAGIC;

	RunQueueBits      = 0;
	__OSCurrentThread = thread;
	RunQueueHint      = FALSE;
	for (prio = OS_PRIORITY_MIN; prio <= OS_PRIORITY_MAX; ++prio) {
		OSInitThreadQueue(&RunQueue[prio]);
	}

	OSInitThreadQueue(&__OSActiveThreadQueue);
	AddTail(&__OSActiveThreadQueue, thread, linkActive);
	OSClearContext(&IdleContext);
	Reschedule = 0;
}

void OSInitThreadQueue(OSThreadQueue* threadQueue)
{
	threadQueue->head = threadQueue->tail = NULL;
}

OSThread* OSGetCurrentThread(void)
{
	return __OSCurrentThread;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
static void __OSSwitchThread(OSThread* nextThread)
{
	__OSCurrentThread = nextThread;
	OSSetCurrentContext(&nextThread->context);
	OSLoadContext(&nextThread->context);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
BOOL OSIsThreadSuspended(OSThread* thread)
{
	// UNUSED FUNCTION
}

BOOL OSIsThreadTerminated(OSThread* thread)
{
	return (thread->state == OS_THREAD_STATE_MORIBUND || thread->state == OS_THREAD_STATE_NULL) ? TRUE : FALSE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
static BOOL __OSIsThreadActive(OSThread* thread)
{
	OSThread* active;

	if (thread->state == 0) {
		return FALSE;
	}

	for (active = __OSActiveThreadQueue.head; active; active = active->linkActive.next) {
		if (thread == active) {
			return TRUE;
		}
	}
	return FALSE;
	// UNUSED FUNCTION
}

s32 OSDisableScheduler(void)
{
	BOOL enabled;
	s32 count;

	enabled = OSDisableInterrupts();
	count   = Reschedule++;
	OSRestoreInterrupts(enabled);
	return count;
}

s32 OSEnableScheduler(void)
{
	BOOL enabled;
	s32 count;

	enabled = OSDisableInterrupts();
	count   = Reschedule--;
	OSRestoreInterrupts(enabled);
	return count;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
static void SetRun(OSThread* thread)
{
	thread->queue = &RunQueue[thread->priority];
	AddTail(thread->queue, thread, link);
	RunQueueBits |= 1u << (OS_PRIORITY_MAX - thread->priority);
	RunQueueHint = TRUE;
}

#pragma dont_inline on

static void UnsetRun(OSThread* thread)
{
	OSThreadQueue* queue;
	queue = thread->queue;
	RemoveItem(queue, thread, link);
	if (queue->head == 0)
		RunQueueBits &= ~(1u << (OS_PRIORITY_MAX - thread->priority));
	thread->queue = NULL;
}

#pragma dont_inline reset

OSPriority __OSGetEffectivePriority(OSThread* thread)
{
	OSPriority priority;
	OSMutex* mutex;
	OSThread* blocked;

	priority = thread->base;
	for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
		blocked = mutex->queue.head;
		if (blocked && blocked->priority < priority) {
			priority = blocked->priority;
		}
	}
	return priority;
}

static OSThread* SetEffectivePriority(OSThread* thread, OSPriority priority)
{
	switch (thread->state) {
	case OS_THREAD_STATE_READY:
		UnsetRun(thread);
		thread->priority = priority;
		SetRun(thread);
		break;

	case OS_THREAD_STATE_WAITING:
		RemoveItem(thread->queue, thread, link);
		thread->priority = priority;
		AddPrio(thread->queue, thread, link);
		if (thread->mutex) {
			return thread->mutex->thread;
		}
		break;

	case OS_THREAD_STATE_RUNNING:
		RunQueueHint     = TRUE;
		thread->priority = priority;
		break;
	}
	return NULL;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
static void UpdatePriority(OSThread* thread)
{
	OSPriority priority;

	do {
		if (thread->suspend > 0) {
			break;
		}
		priority = __OSGetEffectivePriority(thread);
		if (thread->priority == priority) {
			break;
		}
		thread = SetEffectivePriority(thread, priority);
	} while (thread);
	// UNUSED FUNCTION
}

void __OSPromoteThread(OSThread* thread, OSPriority priority)
{
	do {
		if (thread->suspend > 0) {
			break;
		}
		if (thread->priority <= priority) {
			break;
		}

		thread = SetEffectivePriority(thread, priority);
	} while (thread);
}

static OSThread* SelectThread(BOOL yield)
{
	OSContext* currentContext;
	OSThread* currentThread;
	OSThread* nextThread;
	OSPriority priority;
	OSThreadQueue* queue;

	if (0 < Reschedule) {
		return 0;
	}

	currentContext = OSGetCurrentContext();
	currentThread  = OSGetCurrentThread();
	if (currentContext != &currentThread->context) {
		return 0;
	}

	if (currentThread) {
		if (currentThread->state == OS_THREAD_STATE_RUNNING) {
			if (!yield) {
				priority = __cntlzw(RunQueueBits);
				if (currentThread->priority <= priority) {
					return 0;
				}
			}
			currentThread->state = OS_THREAD_STATE_READY;
			SetRun(currentThread);
		}

		if (!(currentThread->context.state & OS_CONTEXT_STATE_EXC) && OSSaveContext(&currentThread->context)) {
			return 0;
		}
	}

	__OSCurrentThread = NULL;
	if (RunQueueBits == 0) {
		OSSetCurrentContext(&IdleContext);
		do {
			OSEnableInterrupts();
			while (RunQueueBits == 0)
				;
			OSDisableInterrupts();
		} while (RunQueueBits == 0);

		OSClearContext(&IdleContext);
	}

	RunQueueHint = FALSE;

	priority = __cntlzw(RunQueueBits);
	queue    = &RunQueue[priority];
	RemoveHead(queue, nextThread, link);
	if (queue->head == 0) {
		RunQueueBits &= ~(1u << (OS_PRIORITY_MAX - priority));
	}
	nextThread->queue = NULL;
	nextThread->state = OS_THREAD_STATE_RUNNING;
	__OSSwitchThread(nextThread);
	return nextThread;
}

void __OSReschedule(void)
{
	if (!RunQueueHint) {
		return;
	}

	SelectThread(FALSE);
}

void OSYieldThread(void)
{
	BOOL enabled;

	enabled = OSDisableInterrupts();
	SelectThread(TRUE);
	OSRestoreInterrupts(enabled);
}

BOOL OSCreateThread(OSThread* thread, OSThreadStartFunction func, void* param, void* stack, u32 stackSize, OSPriority priority, u16 attr)
{
	BOOL enable;
	u32 stackThing;
	int i;

	if (priority < OS_PRIORITY_MIN || priority > OS_PRIORITY_MAX) {
		return FALSE;
	}

	stackThing       = ((u32)stack & 0xFFFFFFF8); // ??
	thread->state    = OS_THREAD_STATE_READY;
	thread->attr     = attr & OS_THREAD_ATTR_DETACH;
	thread->base     = priority;
	thread->priority = priority;
	thread->suspend  = 1;
	thread->val      = (void*)-1;
	thread->mutex    = NULL;
	OSInitThreadQueue(&thread->queueJoin);
	InitMutexQueue(&thread->queueMutex);
	*(u32*)(stackThing - 8) = 0;
	*(u32*)(stackThing - 4) = 0;

	OSInitContext(&thread->context, (u32)func, (u32)(stackThing - 8));

	thread->context.lr     = (u32)&OSExitThread;
	thread->context.gpr[3] = (u32)param;
	thread->stackBase      = stack;
	thread->stackEnd       = (u32*)((u32)stack - stackSize);
	*(thread->stackEnd)    = OS_THREAD_STACK_MAGIC;

	enable = OSDisableInterrupts();

	AddTail(&__OSActiveThreadQueue, thread, linkActive);
	OSRestoreInterrupts(enable);
	return TRUE;
}

void OSExitThread(void* val)
{
	OSThread* thread;
	BOOL enable;

	enable = OSDisableInterrupts();
	thread = __OSCurrentThread;
	OSClearContext(&thread->context);

	if (thread->attr & OS_THREAD_ATTR_DETACH) {
		RemoveItem(&__OSActiveThreadQueue, thread, linkActive);
		thread->state = OS_THREAD_STATE_NULL;

	} else {
		thread->state = OS_THREAD_STATE_MORIBUND;
		thread->val   = val;
	}

	__OSUnlockAllMutex(thread);
	OSWakeupThread(&thread->queueJoin);
	RunQueueHint = TRUE;
	if (RunQueueHint != FALSE) {
		SelectThread(FALSE);
	}

	OSRestoreInterrupts(enable);
}

void OSCancelThread(OSThread* thread)
{
	BOOL enabled;

	enabled = OSDisableInterrupts();

	switch (thread->state) {
	case OS_THREAD_STATE_READY:
		if (!(0 < thread->suspend)) {
			UnsetRun(thread);
		}
		break;
	case OS_THREAD_STATE_RUNNING:
		RunQueueHint = TRUE;
		break;
	case OS_THREAD_STATE_WAITING:
		RemoveItem(thread->queue, thread, link);
		thread->queue = NULL;
		if (!(0 < thread->suspend) && thread->mutex) {
			UpdatePriority(thread->mutex->thread);
		}
		break;
	default:
		OSRestoreInterrupts(enabled);
		return;
	}

	OSClearContext(&thread->context);
	if (thread->attr & OS_THREAD_ATTR_DETACH) {
		RemoveItem(&__OSActiveThreadQueue, thread, linkActive);
		thread->state = OS_THREAD_STATE_NULL;
	} else {
		thread->state = OS_THREAD_STATE_MORIBUND;
	}

	__OSUnlockAllMutex(thread);

	OSWakeupThread(&thread->queueJoin);

	__OSReschedule();
	OSRestoreInterrupts(enabled);

	return;
}

BOOL OSJoinThread(OSThread* thread, void** val)
{
	BOOL enabled = OSDisableInterrupts();

	if (!(thread->attr & 1) && (thread->state != 8) && (thread->queueJoin.head == NULL)) {
		OSSleepThread(&thread->queueJoin);
		if (__OSIsThreadActive(thread) == 0) {
			OSRestoreInterrupts(enabled);
			return 0;
		}
	}

	if (thread->state == 8) {
		if (val) {
			*(s32*)val = (s32)thread->val;
		}
		RemoveItem(&__OSActiveThreadQueue, thread, linkActive);
		thread->state = 0;
		OSRestoreInterrupts(enabled);
		return 1;
	}
	OSRestoreInterrupts(enabled);
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void OSDetachThread(OSThread* thread)
{
	// UNUSED FUNCTION
}

s32 OSResumeThread(OSThread* thread)
{
	BOOL enabled;
	s32 suspendCount;

	enabled      = OSDisableInterrupts();
	suspendCount = thread->suspend--;
	if (thread->suspend < 0) {
		thread->suspend = 0;
	} else if (thread->suspend == 0) {
		switch (thread->state) {
		case OS_THREAD_STATE_READY:
			thread->priority = __OSGetEffectivePriority(thread);
			SetRun(thread);
			break;
		case OS_THREAD_STATE_WAITING:
			RemoveItem(thread->queue, thread, link);
			thread->priority = __OSGetEffectivePriority(thread);
			AddPrio(thread->queue, thread, link);
			if (thread->mutex) {
				UpdatePriority(thread->mutex->thread);
			}
			break;
		}
		__OSReschedule();
	}
	OSRestoreInterrupts(enabled);
	return suspendCount;
}

s32 OSSuspendThread(OSThread* thread)
{
	BOOL enabled;
	s32 suspendCount;

	enabled      = OSDisableInterrupts();
	suspendCount = thread->suspend++;
	if (suspendCount == 0) {
		switch (thread->state) {
		case OS_THREAD_STATE_RUNNING:
			RunQueueHint  = TRUE;
			thread->state = OS_THREAD_STATE_READY;
			break;
		case OS_THREAD_STATE_READY:
			UnsetRun(thread);
			break;
		case OS_THREAD_STATE_WAITING:
			RemoveItem(thread->queue, thread, link);
			thread->priority = 32;
			AddTail(thread->queue, thread, link);
			if (thread->mutex) {
				UpdatePriority(thread->mutex->thread);
			}
			break;
		}

		__OSReschedule();
	}
	OSRestoreInterrupts(enabled);
	return suspendCount;
}

void OSSleepThread(OSThreadQueue* threadQueue)
{
	BOOL enabled;
	OSThread* currentThread;

	enabled       = OSDisableInterrupts();
	currentThread = OSGetCurrentThread();

	currentThread->state = OS_THREAD_STATE_WAITING;
	currentThread->queue = threadQueue;
	AddPrio(threadQueue, currentThread, link);
	RunQueueHint = TRUE;
	__OSReschedule();
	OSRestoreInterrupts(enabled);
}

void OSWakeupThread(OSThreadQueue* threadQueue)
{
	BOOL enabled;
	OSThread* thread;

	enabled = OSDisableInterrupts();
	while (threadQueue->head) {
		RemoveHead(threadQueue, thread, link);
		thread->state = OS_THREAD_STATE_READY;
		if (!(0 < thread->suspend)) {
			SetRun(thread);
		}
	}
	__OSReschedule();
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
BOOL OSSetThreadPriority(OSThread*, s32)
{
	// UNUSED FUNCTION
}

OSPriority OSGetThreadPriority(OSThread* thread)
{
	return thread->base;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
OSThread* OSSetIdleFunction(OSIdleFunction idleFunc, void* param, void* stack, u32 stackSize)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
OSThread* OSGetIdleFunction(void)
{
	// UNUSED FUNCTION
}

static int CheckThreadQueue(OSThreadQueue* queue)
{
	OSThread* thread;

	if ((queue->head != NULL) && (queue->head->link.prev != NULL)) {
		return 0;
	}
	if ((queue->tail != NULL) && (queue->tail->link.next != NULL)) {
		return 0;
	}
	thread = queue->head;
	while (thread) {
		if ((thread->link.next != NULL) && (thread != thread->link.next->link.prev)) {
			return 0;
		}
		if ((thread->link.prev != NULL) && (thread != thread->link.prev->link.next)) {
			return 0;
		}
		thread = thread->link.next;
	}
	return 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
static BOOL IsMember(OSThreadQueue* queue, OSThread* thread)
{
	struct OSThread* member = queue->head;

	while (member) {
		if (thread == member) {
			return 1;
		}
		member = member->link.next;
	}
	return 0;
	// UNUSED FUNCTION
}

// custom macro for OSCheckActiveThreads?
#define ASSERTREPORT(line, cond)                                          \
	if (!(cond)) {                                                        \
		OSReport("OSCheckActiveThreads: Failed " #cond " in %d\n", line); \
		OSPanic(__FILE__, line, "");                                      \
	}

#define IsSuspended(suspend) (suspend > 0)

s32 OSCheckActiveThreads(void)
{
	OSThread* thread;
	s32 prio;
	s32 cThread;
	int enabled;

	cThread = 0;
	enabled = OSDisableInterrupts();

	for (prio = 0; prio <= 0x1F; prio++) {
		if (RunQueueBits & (1 << (0x1F - prio))) {
			ASSERTREPORT(0x566, RunQueue[prio].head != NULL && RunQueue[prio].tail != NULL);
		} else {
			ASSERTREPORT(0x56B, RunQueue[prio].head == NULL && RunQueue[prio].tail == NULL);
		}
		ASSERTREPORT(0x56D, CheckThreadQueue(&RunQueue[prio]));
	}

	ASSERTREPORT(0x572, __OSActiveThreadQueue.head == NULL || __OSActiveThreadQueue.head->linkActive.prev == NULL);
	ASSERTREPORT(0x574, __OSActiveThreadQueue.tail == NULL || __OSActiveThreadQueue.tail->linkActive.next == NULL);

	thread = __OSActiveThreadQueue.head;
	while (thread) {
		cThread++;
		ASSERTREPORT(0x57C, thread->linkActive.next == NULL || thread == thread->linkActive.next->linkActive.prev);
		ASSERTREPORT(0x57E, thread->linkActive.prev == NULL || thread == thread->linkActive.prev->linkActive.next);
		ASSERTREPORT(0x581, *(thread->stackEnd) == OS_THREAD_STACK_MAGIC);

		// need to not have spaces around the plus in the line below
		// clang-format off
		ASSERTREPORT(0x584, OS_PRIORITY_MIN <= thread->priority && thread->priority <= OS_PRIORITY_MAX+1);
		// clang-format reset

		ASSERTREPORT(0x585, 0 <= thread->suspend);
		ASSERTREPORT(0x586, CheckThreadQueue(&thread->queueJoin));

		switch (thread->state) {
		case 1:
			if (thread->suspend <= 0) {
				ASSERTREPORT(0x58C, thread->queue == &RunQueue[thread->priority]);
				ASSERTREPORT(0x58D, IsMember(&RunQueue[thread->priority], thread));
				ASSERTREPORT(0x58E, thread->priority == __OSGetEffectivePriority(thread));
			}
			break;
		case 2:
			ASSERTREPORT(0x592, !IsSuspended(thread->suspend));
			ASSERTREPORT(0x593, thread->queue == NULL);
			ASSERTREPORT(0x594, thread->priority == __OSGetEffectivePriority(thread));
			break;
		case 4:
			ASSERTREPORT(0x597, thread->queue != NULL);
			ASSERTREPORT(0x598, CheckThreadQueue(thread->queue));
			ASSERTREPORT(0x599, IsMember(thread->queue, thread));
			if (thread->suspend <= 0) {
				ASSERTREPORT(0x59C, thread->priority == __OSGetEffectivePriority(thread));
			} else {
				ASSERTREPORT(0x5A0, thread->priority == 32);
			}
			ASSERTREPORT(0x5A2, !__OSCheckDeadLock(thread));
			break;
		case 8:
			ASSERTREPORT(0x5A6, thread->queueMutex.head == NULL && thread->queueMutex.tail == NULL);
			break;
		default:
			OSReport("OSCheckActiveThreads: Failed. unkown thread state (%d) of thread %p\n", thread->state, thread);
			OSPanic("OSThread.c", 0x5AC, "");
		}
		ASSERTREPORT(0x5B1, __OSCheckMutexes(thread));
		thread = thread->linkActive.next;
	}
	OSRestoreInterrupts(enabled);
	return cThread;
}
