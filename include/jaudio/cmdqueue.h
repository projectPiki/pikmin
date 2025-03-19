#ifndef _JAUDIO_CMDQUEUE_H
#define _JAUDIO_CMDQUEUE_H

#include "types.h"

typedef struct cmdqueue_ cmdqueue_;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jal_AddCmdQueue(void);
void Jal_SendCmdQueue_Noblock(void);
void Jal_SendCmdQueue_Force(void);
void Jal_CmdQueue_Init(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
