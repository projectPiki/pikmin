#include "types.h"
#ifndef _DSP_H
#define _DSP_H
#define HW_REG(reg, type) *(volatile type *)(uintptr_t)(reg)
volatile u16 __DSPRegs[] : 0xCC005000;
#endif
