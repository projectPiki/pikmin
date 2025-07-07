#ifndef _MSL_COMMON_FILE_STRUC_H
#define _MSL_COMMON_FILE_STRUC_H
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_files.h"
#include "types.h"

#define stdin  &(__files[0])
#define stdout &(__files[1])
#define stderr &(__files[2])

#endif
