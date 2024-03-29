#ifndef _START_H
#define _START_H

#include "types.h"

#define OS_RESET_RESTART        0
#define FALSE                   0
#define TRUE                    1
#define EXCEPTIONMASK_ADDR      0x80000044
#define BOOTINFO2_ADDR          0x800000F4
#define OS_BI2_DEBUGFLAG_OFFSET 0xC
#define ARENAHI_ADDR            0x80000034
#define DEBUGFLAG_ADDR          0x800030E8
#define DVD_DEVICECODE_ADDR     0x800030E6

extern void InitMetroTRK();

extern void memset(void*, int, int);
extern int main(int argc, char* argv[]);
extern void exit(int);
extern void __init_user(void);
extern void InitMetroTRK_BBA(void);
extern void OSInit(void);
extern void DBInit(void);
extern void OSResetSystem(BOOL reset, u32 resetCode, BOOL forceMenu);
extern void __init_hardware(void);

DECL_SECT(".init") extern void __start(void);
DECL_SECT(".init") extern void __init_registers(void);
DECL_SECT(".init") extern void __init_data(void);

DECL_SECT(".init") extern char _stack_addr[];
DECL_SECT(".init") extern char _SDA_BASE_[];
DECL_SECT(".init") extern char _SDA2_BASE_[];

typedef struct __rom_copy_info {
	char* rom;
	char* addr;
	unsigned int size;
} __rom_copy_info;

DECL_SECT(".init") extern __rom_copy_info _rom_copy_info[];

typedef struct __bss_init_info {
	char* addr;
	unsigned int size;
} __bss_init_info;

DECL_SECT(".init") extern __bss_init_info _bss_init_info[];

#endif
