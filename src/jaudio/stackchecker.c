#include "jaudio/stackchecker.h"

void Jac_StackInit(void* stack, s32 size)
{
	for (u32 i = 1; i < size; i++) {
		((u32*)stack)[2 * i + 1] = 0x12345678;
		((u32*)stack)[2 * i]     = 0xfadebabe;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void Jac_StackCheck(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Jac_CheckInit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void Jac_CheckIn(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Jac_CheckOut(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void Jac_CheckPrint(void)
{
	// UNUSED FUNCTION
}
