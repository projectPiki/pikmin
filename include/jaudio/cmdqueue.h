#ifndef _JAUDIO_CMDQUEUE_H
#define _JAUDIO_CMDQUEUE_H

#include "jaudio/audiomesg.h"
#include "jaudio/jammain_2.h"

#include "types.h"

typedef struct cmdqueue_ CmdQueue;

struct cmdqueue_ {
	Jac_MessageQueue msgQueue; // _00
	OSMessage message;         // _20
	u8 _24[0x60 - 0x24];       // _24
	seqp_* track;              // _60
	u8 _64;                    // _64
	CmdQueue* next;            // _68;
};

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

extern CmdQueue* queue_list; // Pointer to the start of a linked list

void Jal_AddCmdQueue(CmdQueue*, seqp_*, u8); // TODO: Types uncertain
void Jal_SendCmdQueue_Noblock(CmdQueue* queue, u16 msg);
void Jal_SendCmdQueue_Force(CmdQueue* queue, u16 msg);
void Jal_CmdQueue_Init(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
