#include "Dolphin/os.h"

// forward declarations
static OSAlarmQueue AlarmQueue;

static void DecrementerExceptionHandler(__OSException exception, OSContext* context);

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
int OSCheckAlarmQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
static void SetTimer(OSAlarm* alarm)
{
	OSTime delta;

	delta = alarm->fire - OSGetTime();
	if (delta < 0) {
		PPCMtdec(0);
	} else if (delta < 0x80000000) {
		PPCMtdec((u32)delta);
	} else {
		PPCMtdec(0x7fffffff);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F60C0
 * Size:	00004C
 */
void OSInitAlarm(void)
{
	if (__OSGetExceptionHandler(8) != DecrementerExceptionHandler) {
		AlarmQueue.head = AlarmQueue.tail = nullptr;
		__OSSetExceptionHandler(8, DecrementerExceptionHandler);
	}
}

/*
 * --INFO--
 * Address:	801F610C
 * Size:	00000C
 */
void OSCreateAlarm(OSAlarm* alarm)
{
	alarm->handler = nullptr;
}

/*
 * --INFO--
 * Address:	801F6118
 * Size:	000250
 */
static void InsertAlarm(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler)
{
	OSAlarm* next;
	OSAlarm* prev;

	if (alarm->period > 0) {
		OSTime time = OSGetTime();

		fire = alarm->start;
		if (alarm->start < time) {
			fire += alarm->period * ((time - alarm->start) / alarm->period + 1);
		}
	}

	alarm->handler = handler;
	alarm->fire    = fire;

	for (next = AlarmQueue.head; next; next = next->next) {
		if (next->fire <= fire) {
			continue;
		}

		alarm->prev = next->prev;
		next->prev  = alarm;
		alarm->next = next;
		prev        = alarm->prev;
		if (prev) {
			prev->next = alarm;
		} else {
			AlarmQueue.head = alarm;
			SetTimer(alarm);
		}
		return;
	}
	alarm->next     = nullptr;
	prev            = AlarmQueue.tail;
	AlarmQueue.tail = alarm;
	alarm->prev     = prev;
	if (prev) {
		prev->next = alarm;
	} else {
		AlarmQueue.head = AlarmQueue.tail = alarm;
		SetTimer(alarm);
	}
}

/*
 * --INFO--
 * Address:	801F6368
 * Size:	000068
 */
void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler)
{
	BOOL enabled;
	enabled       = OSDisableInterrupts();
	alarm->period = 0;
	InsertAlarm(alarm, OSGetTime() + tick, handler);
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	801F63D0
 * Size:	000064
 */
void OSSetAbsAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler)
{
	int enabled;

	enabled       = OSDisableInterrupts();
	alarm->period = 0;
	InsertAlarm(alarm, tick, handler);
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void OSSetPeriodicAlarm(OSAlarm*, OSTime, OSTime, OSAlarmHandler)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6434
 * Size:	00011C
 */
void OSCancelAlarm(OSAlarm* alarm)
{
	OSAlarm* next;
	BOOL enabled;

	enabled = OSDisableInterrupts();

	if (alarm->handler == nullptr) {
		OSRestoreInterrupts(enabled);
		return;
	}

	next = alarm->next;
	if (next == nullptr) {
		AlarmQueue.tail = alarm->prev;
	} else {
		next->prev = alarm->prev;
	}
	if (alarm->prev) {
		alarm->prev->next = next;
	} else {
		AlarmQueue.head = next;
		if (next) {
			SetTimer(next);
		}
	}
	alarm->handler = nullptr;

	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	801F6550
 * Size:	000210
 */
static void DecrementerExceptionCallback(__OSException exception, OSContext* context)
{
	OSAlarm* alarm;
	OSAlarm* next;
	OSAlarmHandler handler;
	OSTime time;
	time  = OSGetTime();
	alarm = AlarmQueue.head;
	if (alarm == nullptr) {
		OSLoadContext(context);
	}

	if (time < alarm->fire) {
		SetTimer(alarm);
		OSLoadContext(context);
	}

	next            = alarm->next;
	AlarmQueue.head = next;
	if (next == nullptr) {
		AlarmQueue.tail = nullptr;
	} else {
		next->prev = nullptr;
	}

	handler        = alarm->handler;
	alarm->handler = nullptr;
	if (0 < alarm->period) {
		InsertAlarm(alarm, 0, handler);
	}

	if (AlarmQueue.head) {
		SetTimer(AlarmQueue.head);
	}

	OSDisableScheduler();
	handler(alarm, context);
	OSEnableScheduler();
	__OSReschedule();
	OSLoadContext(context);
}

/*
 * --INFO--
 * Address:	801F6760
 * Size:	00004C
 */
static ASM void DecrementerExceptionHandler(register __OSException exception, register OSContext* context)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	OS_EXCEPTION_SAVE_GPRS(context)
	b DecrementerExceptionCallback
#endif // clang-format on
}
