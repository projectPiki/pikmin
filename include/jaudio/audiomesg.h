#ifndef _JAUDIO_AUDIOMESG_H
#define _JAUDIO_AUDIOMESG_H

#include "types.h"
#include "jaudio/audiostruct.h"

typedef struct Jac_MessageQueue Jac_MessageQueue;

/**
 * @brief This is exactly the same as OSMessageQueue. _00-_10 don't seem to get called, but this makes sense.
 *
 * @note This was moved from audiostruct.h. TODO: Is that okay?
 */
struct Jac_MessageQueue {
	OSThreadQueue queueSend;    // _00
	OSThreadQueue queueReceive; // _08
	OSMessage* msgArray;        // _10, array of messages.
	s32 msgCount;               // _14, array limit size.
	s32 firstIndex;             // _18, first message index in array.
	s32 usedCount;              // _1C, actual number of used messages.
};

/////////// JAUDIO MESSAGE DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void Jac_InitMessageQueue(Jac_MessageQueue* queue, OSMessage* msgArray, s32 count);
BOOL Jac_SendMessage(Jac_MessageQueue* queue, OSMessage message);
BOOL Jac_ReceiveMessage(Jac_MessageQueue* queue, OSMessage* outMsg);
BOOL Jac_ReceiveMessage_Fast(Jac_MessageQueue* queue, OSMessage* outMsg);

//////////////////////////////////////////////////

#endif
