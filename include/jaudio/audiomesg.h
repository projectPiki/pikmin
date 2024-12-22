#ifndef _JAUDIO_AUDIOMESG_H
#define _JAUDIO_AUDIOMESG_H

#include "types.h"
#include "jaudio/audiostruct.h"

/////////// JAUDIO MESSAGE DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void Jac_InitMessageQueue(Jac_MessageQueue*, OSMessage*, s32);
BOOL Jac_SendMessage(Jac_MessageQueue*, OSMessage);
BOOL Jac_ReceiveMessage(Jac_MessageQueue*, OSMessage*);
BOOL Jac_ReceiveMessage_Fast(Jac_MessageQueue*, OSMessage*);

//////////////////////////////////////////////////

#endif
