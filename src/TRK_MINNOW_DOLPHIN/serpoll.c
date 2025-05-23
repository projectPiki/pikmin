#include "PowerPC_EABI_Support/MetroTRK/trk.h"

void* gTRKInputPendingPtr;
static TRKFramingState gTRKFramingState;

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void TRKDiscardFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void TRKRejectFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CD14
 * Size:	0000D0
 */
TRKBufferID TRKTestForPacket(void)
{
	int bytes;
	int batch;
	DSError err;
	TRKBuffer* b;
	int id;

	bytes = TRKPollUART();

	if (bytes > 0) {
		TRKGetFreeBuffer(&id, &b);
		if (bytes > 0x880) {
			for (; bytes > 0; bytes -= batch) {
				batch = bytes > 0x880 ? 0x880 : bytes;
				TRKReadUARTN(b->data, batch);
			}
			TRKStandardACK(b, DSMSG_ReplyNAK, 6);
		} else {
			err = TRKReadUARTN(b->data, bytes);
			if (err == DS_NoError) {
				b->length = bytes;
				return id;
			}
		}
	}

	if (id != -1) {
		TRKReleaseBuffer(id);
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void TRKProcessFrame(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CDE4
 * Size:	00007C
 */
void TRKGetInput(void)
{
	TRKBuffer* msgbuffer;
	int bufID;
	u8 command;

	bufID = TRKTestForPacket();

	if (bufID != -1) {
		msgbuffer = TRKGetBuffer(bufID);
		TRKSetBufferPosition(msgbuffer, 0);
		TRKReadBuffer1_ui8(msgbuffer, &command);
		if (command < 0x80) {
			TRKProcessInput(bufID);
		} else {
			TRKReleaseBuffer(bufID);
		}
	}
}

/*
 * --INFO--
 * Address:	8021CE60
 * Size:	000050
 */
void TRKProcessInput(TRKBufferID bufID)
{
	TRKEvent event;

	TRKConstructEvent(&event, 2);
	event.msgBufID            = bufID;
	gTRKFramingState.msgBufID = -1;
	TRKPostEvent(&event);
}

/*
 * --INFO--
 * Address:	8021CEB0
 * Size:	000024
 */
DSError TRKInitializeSerialHandler(void)
{
	gTRKFramingState.msgBufID     = -1;
	gTRKFramingState.receiveState = 0;
	gTRKFramingState.isEscape     = 0;
	return 0;
}

/*
 * --INFO--
 * Address:	8021CED4
 * Size:	000008
 */
DSError TRKTerminateSerialHandler(void)
{
	return 0;
}
