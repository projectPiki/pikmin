#ifndef _JAUDIO_CMDSTACK_H
#define _JAUDIO_CMDSTACK_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef struct JPorthead_ {
	u32 _00; // _00
	u32 _04; // _04
} JPorthead_;

void Add_PortcmdOnce(u32*);
void Add_PortcmdStay(void); // UNUSED but we know it's extern "C"
int Set_Portcmd(int*, int, int);
BOOL Add_Portcmd(JPorthead_*, u32*);
void Cancel_Portcmd(void);     // UNUSED but we know it's extern "C"
void Cancel_PortcmdStay(void); // UNUSED but we know it's extern "C"
int Jac_Portcmd_Proc_Once(JPorthead_*);
int Jac_Portcmd_Proc_Stay(JPorthead_*);
void Jac_Porthead_Init(JPorthead_*);
void Jac_Portcmd_Init(void);
void JP_Pitch1Shot(void); // UNUSED but we know it's extern "C"
void JP_Start1Shot(void); // UNUSED but we know it's extern "C"
void JP_Stop1Shot(void);  // UNUSED but we know it's extern "C"

END_SCOPE_EXTERN_C

static int Get_Portcmd(JPorthead_* port);
static s32 Portcmd_Main(void* a);

#endif
