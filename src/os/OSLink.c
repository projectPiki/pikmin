#include "types.h"

#define OS_MODULE_LIST_ADDR  0x800030C8
#define OS_STRING_TABLE_ADDR 0x800030D0
#define OS_BASE_CACHED       0x80003000

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void OSNotifyLink(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void OSNotifyUnlink(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void OSSetStringTable(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000274
 */
void Relocate(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000200
 */
void OSLink(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00020C
 */
void Undo(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094
 */
void OSUnlink(void)
{
	TRAP_UNIMPLEMENTED;
}

struct OSModuleQueue { /* Relocatable Module Queue @ 800030c8 */
	int* pFirst;
	int* pLast;
};

extern struct OSModuleQueue __OSModuleInfoList AT_ADDRESS(OS_BASE_CACHED | OS_MODULE_LIST_ADDR);
extern const void* __OSStringTable AT_ADDRESS(OS_BASE_CACHED | OS_STRING_TABLE_ADDR);

/**
 * @TODO: Documentation
 */
void __OSModuleInit(void)
{
	__OSModuleInfoList.pLast  = 0;
	__OSModuleInfoList.pFirst = 0;
	__OSStringTable           = 0;
}
