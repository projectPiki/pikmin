#ifndef _JAUDIO_CMDSTACK_H
#define _JAUDIO_CMDSTACK_H

#include "types.h"

typedef struct JPorthead_ JPorthead_;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Add_PortcmdOnce(void);
void Add_PortcmdStay(void); // UNUSED but we know it's extern "C"
void Set_Portcmd(void);
void Add_Portcmd(void);
void Cancel_Portcmd(void);     // UNUSED but we know it's extern "C"
void Cancel_PortcmdStay(void); // UNUSED but we know it's extern "C"
void Jac_Portcmd_Proc_Once(void);
void Jac_Portcmd_Proc_Stay(void);
void Jac_Porthead_Init(void);
void Jac_Portcmd_Init(void);
void JP_Pitch1Shot(void); // UNUSED but we know it's extern "C"
void JP_Start1Shot(void); // UNUSED but we know it's extern "C"
void JP_Stop1Shot(void);  // UNUSED but we know it's extern "C"

#ifdef __cplusplus
}
#endif // ifdef __cplusplus

#endif
