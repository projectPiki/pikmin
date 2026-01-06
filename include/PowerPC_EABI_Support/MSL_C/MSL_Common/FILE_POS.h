#ifndef _MSL_FILE_POS_H
#define _MSL_FILE_POS_H

#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_files.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

int fseek(FILE* stream, u32 offset, int whence);
int _fseek(FILE* stream, u32 offset, int whence);
int ftell(FILE* stream);
int _ftell(FILE* stream);

END_SCOPE_EXTERN_C

#endif
