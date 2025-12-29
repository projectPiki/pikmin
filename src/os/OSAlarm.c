#include "Dolphin/os.h"

// forward declarations
static OSAlarmQueue AlarmQueue;

static void DecrementerExceptionHandler(__OSException exception, OSContext* context);

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00013C
 */
int OSCheckAlarmQueue(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000098
 */
static void SetTimer(OSAlarm* alarm)
{
	OSTime delta;

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	delta = alarm->fire - __OSGetSystemTime();
#else
	delta = alarm->fire - OSGetTime();
#endif

	if (delta < 0) {
		PPCMtdec(0);
	} else if (delta < 0x80000000) {
		PPCMtdec((u32)delta);
	} else {
		PPCMtdec(0x7fffffff);
	}
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void OSInitAlarm(void)
{
	if (__OSGetExceptionHandler(8) != DecrementerExceptionHandler) {
		AlarmQueue.head = AlarmQueue.tail = NULL;
		__OSSetExceptionHandler(8, DecrementerExceptionHandler);
	}
}

/**
 * @TODO: Documentation
 */
void OSCreateAlarm(OSAlarm* alarm)
{
	alarm->handler = NULL;
}

/**
 * @TODO: Documentation
 */
static void InsertAlarm(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler)
{
	OSAlarm* next;
	OSAlarm* prev;

	if (alarm->period > 0) {
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSTime time = __OSGetSystemTime();
#else
		OSTime time = OSGetTime();
#endif

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
	alarm->next     = NULL;
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

/**
 * @TODO: Documentation
 */
void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler)
{
	BOOL enabled;
	enabled       = OSDisableInterrupts();
	alarm->period = 0;
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);
#else
	InsertAlarm(alarm, OSGetTime() + tick, handler);
#endif
	OSRestoreInterrupts(enabled);
}

/**
 * @TODO: Documentation
 */
void OSSetAbsAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler)
{
	int enabled;

	enabled       = OSDisableInterrupts();
	alarm->period = 0;
	InsertAlarm(alarm, tick, handler);
	OSRestoreInterrupts(enabled);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
void OSSetPeriodicAlarm(OSAlarm*, OSTime, OSTime, OSAlarmHandler)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void OSCancelAlarm(OSAlarm* alarm)
{
	OSAlarm* next;
	BOOL enabled;

	enabled = OSDisableInterrupts();

	if (alarm->handler == NULL) {
		OSRestoreInterrupts(enabled);
		return;
	}

	next = alarm->next;
	if (next == NULL) {
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
	alarm->handler = NULL;

	OSRestoreInterrupts(enabled);
}

/**
 * @TODO: Documentation
 */
static void DecrementerExceptionCallback(__OSException exception, OSContext* context)
{
	OSAlarm* alarm;
	OSAlarm* next;
	OSAlarmHandler handler;
	OSTime time;

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	OSContext exceptionContext;
	time = __OSGetSystemTime();
#else
	time = OSGetTime();
#endif
	alarm = AlarmQueue.head;
	if (alarm == NULL) {
		OSLoadContext(context);
	}

	if (time < alarm->fire) {
		SetTimer(alarm);
		OSLoadContext(context);
	}

	next            = alarm->next;
	AlarmQueue.head = next;
	if (next == NULL) {
		AlarmQueue.tail = NULL;
	} else {
		next->prev = NULL;
	}

	handler        = alarm->handler;
	alarm->handler = NULL;
	if (0 < alarm->period) {
		InsertAlarm(alarm, 0, handler);
	}

	if (AlarmQueue.head) {
		SetTimer(AlarmQueue.head);
	}

	OSDisableScheduler();
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);
#endif
	handler(alarm, context);
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	OSClearContext(&exceptionContext);
	OSSetCurrentContext(context);
#endif
	OSEnableScheduler();
	__OSReschedule();
	OSLoadContext(context);
}

/**
 * @TODO: Documentation
 */
static ASM void DecrementerExceptionHandler(register __OSException exception, register OSContext* context)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	OS_EXCEPTION_SAVE_GPRS(context)
	b DecrementerExceptionCallback
#endif // clang-format on
}
