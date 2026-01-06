#ifndef _DOLPHIN_OS_OSMESSAGE_H
#define _DOLPHIN_OS_OSMESSAGE_H

#include "Dolphin/OS/OSThread.h"
#include "Dolphin/OS/OSUtil.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

///////// MESSAGE TYPES //////////
typedef struct OSMesgQueue_s OSMesgQueue_s;
typedef struct OSMesgQueue_s OSMessageQueue;

// Useful typedef for messages.
typedef void* OSMessage;

// Struct for managing the message queue.
struct OSMesgQueue_s {
	OSThreadQueue queueSend;    // _00
	OSThreadQueue queueReceive; // _08
	OSMessage* msgArray;        // _10, array of messages.
	s32 msgCount;               // _14, array limit size.
	s32 firstIndex;             // _18, first message index in array.
	s32 usedCount;              // _1C, actual number of used messages.
};

// Defines for message flags for sending/receiving.
#define OS_MESSAGE_NOBLOCK (0)
#define OS_MESSAGE_BLOCK   (1)

typedef enum {
	OS_MSG_PERSISTENT = (1 << 0),
} OSMessageFlags;

//////////////////////////////////

/////// MESSAGE FUNCTIONS ////////
// Functions for handling messages.
void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* msgArray, s32 msgCount);
BOOL OSSendMessage(OSMessageQueue* queue, OSMessage msg, s32 flags);
BOOL OSJamMessage(OSMessageQueue* queue, OSMessage msg, s32 flags);
BOOL OSReceiveMessage(OSMessageQueue* queue, OSMessage* msgPtr, s32 flags);

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
