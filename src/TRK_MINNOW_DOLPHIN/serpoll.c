#include "PowerPC_EABI_Support/MetroTRK/trk.h"

void* gTRKInputPendingPtr;
static TRKFramingState gTRKFramingState;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void TRKDiscardFrame(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void TRKRejectFrame(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
void TRKProcessFrame(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void TRKProcessInput(TRKBufferID bufID)
{
	TRKEvent event;

	TRKConstructEvent(&event, 2);
	event.msgBufID            = bufID;
	gTRKFramingState.msgBufID = -1;
	TRKPostEvent(&event);
}

/**
 * @TODO: Documentation
 */
DSError TRKInitializeSerialHandler(void)
{
	gTRKFramingState.msgBufID     = -1;
	gTRKFramingState.receiveState = 0;
	gTRKFramingState.isEscape     = 0;
	return 0;
}

/**
 * @TODO: Documentation
 */
DSError TRKTerminateSerialHandler(void)
{
	return 0;
}
