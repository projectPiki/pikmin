#include "PowerPC_EABI_Support/MetroTRK/trk.h"

TRKEventQueue gTRKEventQueue;

DSError TRKInitializeEventQueue()
{
	TRKInitializeMutex(&gTRKEventQueue);
	TRKAcquireMutex(&gTRKEventQueue);
	gTRKEventQueue.count   = 0;
	gTRKEventQueue.next    = 0;
	gTRKEventQueue.eventID = 0x100;
	TRKReleaseMutex(&gTRKEventQueue);
	return DS_NoError;
}

void TRKCopyEvent(TRKEvent* dstEvent, const TRKEvent* srcEvent)
{
	TRK_memcpy(dstEvent, srcEvent, sizeof(TRKEvent));
}

BOOL TRKGetNextEvent(TRKEvent* event)
{
	BOOL status = FALSE;
	TRKAcquireMutex(&gTRKEventQueue);
	if (0 < gTRKEventQueue.count) {
		TRKCopyEvent(event, &gTRKEventQueue.events[gTRKEventQueue.next]);
		gTRKEventQueue.count--;
		gTRKEventQueue.next++;
		if (gTRKEventQueue.next == 2)
			gTRKEventQueue.next = 0;

		status = TRUE;
	}
	TRKReleaseMutex(&gTRKEventQueue);
	return status;
}

DSError TRKPostEvent(TRKEvent* event)
{
	DSError ret = DS_NoError;
	int nextEventID;

	TRKAcquireMutex(&gTRKEventQueue);

	if (gTRKEventQueue.count == 2) {
		ret = DS_EventQueueFull;
	} else {
		nextEventID = (gTRKEventQueue.next + gTRKEventQueue.count) % 2;
		TRKCopyEvent(&gTRKEventQueue.events[nextEventID], event);
		gTRKEventQueue.events[nextEventID].eventID = gTRKEventQueue.eventID;
		gTRKEventQueue.eventID++;
		if (gTRKEventQueue.eventID < 0x100)
			gTRKEventQueue.eventID = 0x100;

		gTRKEventQueue.count++;
	}

	TRKReleaseMutex(&gTRKEventQueue);
	return ret;
}

void TRKConstructEvent(TRKEvent* event, int eventType)
{
	event->eventType = eventType;
	event->eventID   = 0;
	event->msgBufID  = -1;
}

void TRKDestructEvent(TRKEvent* event)
{
	TRKReleaseBuffer(event->msgBufID);
}
