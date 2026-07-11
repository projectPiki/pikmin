#ifndef _JAUDIO_CMDSTACK_H
#define _JAUDIO_CMDSTACK_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef struct JPorthead_ JPorthead_;
typedef struct Portcmd_ Portcmd_;
typedef struct Portargs_ Portargs_; // Defined in "pikiinter.c"

struct JPorthead_ {
	Portcmd_* _00; // _00
	Portcmd_* _04; // _04
};

typedef void (*Portfunc)(Portargs_*); // Function signature of `__SetVolandPan`

/**
 * @note FABRICATED
 * Name is based on functions that use it + `JPorthead_` and `Portargs_`.
 */
struct Portcmd_ {
	u8 _00[0x0C - 0x00]; // _00
	JPorthead_* _0C;     // _0C
	Portcmd_* _10;       // _10
	Portfunc func;       // _14
	Portargs_* args;     // _18
};

void Add_PortcmdOnce(Portcmd_*);
void Add_PortcmdStay(Portcmd_*); // UNUSED but we know it's extern "C"
BOOL Set_Portcmd(Portcmd_*, Portfunc, Portargs_*);
BOOL Add_Portcmd(JPorthead_*, Portcmd_*);
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

#endif
