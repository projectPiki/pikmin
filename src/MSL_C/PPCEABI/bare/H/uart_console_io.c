#include "types.h"

s32 InitializeUART(u32);                      /* extern */
s32 OSGetConsoleType();                       /* extern */
s32 WriteUARTN(s32, s32);                     /* extern */
s32 __TRK_write_console(s32, s32, s32*, s32); /* extern */
static BOOL initialized;

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void __init_uart_console(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021A510
 * Size:	000008
 */
u32 __close_console(void)
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	8021A518
 * Size:	000098
 */
WEAKFUNC BOOL __write_console(s32 arg0, s32 arg1, s32* arg2, s32 arg3)
{
	int a;

	// if ((OSGetConsoleType() & 0x20000000) == 0) {
	int r3_cond = 0;
	if (initialized == FALSE) {
		r3_cond = InitializeUART(0xE100);
		;
		if (r3_cond == 0) {
			initialized = TRUE;
		}
	}
	if (r3_cond != 0) {
		return TRUE;
	}
	if (WriteUARTN(arg1, *arg2) != 0) {
		*arg2 = 0;
		return TRUE;
	}
	//}

	//__TRK_write_console(arg0, arg1, arg2, arg3);
	return FALSE;
}

/*
 * --INFO--
 * Address:	8021A5B0
 * Size:	0000E0
 */
void __read_console(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  lwz       r0, 0x3498(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x4C
	  lis       r3, 0x1
	  subi      r3, r3, 0x1F00
	  bl        -0x1CE24
	  cmpwi     r3, 0
	  bne-      .loc_0x4C
	  li        r0, 0x1
	  stw       r0, 0x3498(r13)

	.loc_0x4C:
	  cmpwi     r3, 0
	  beq-      .loc_0x5C
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0x5C:
	  lwz       r31, 0x0(r30)
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r30)
	  b         .loc_0x98

	.loc_0x70:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x1CE1C
	  lwz       r4, 0x0(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r30)
	  lbz       r0, 0x0(r29)
	  cmplwi    r0, 0xD
	  beq-      .loc_0xAC
	  addi      r29, r29, 0x1

	.loc_0x98:
	  lwz       r0, 0x0(r30)
	  cmplw     r0, r31
	  bgt-      .loc_0xAC
	  cmpwi     r3, 0
	  beq+      .loc_0x70

	.loc_0xAC:
	  cmpwi     r3, 0
	  bne-      .loc_0xBC
	  li        r0, 0
	  b         .loc_0xC0

	.loc_0xBC:
	  li        r0, 0x1

	.loc_0xC0:
	  rlwinm    r3,r0,0,24,31

	.loc_0xC4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  mtlr      r0
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  blr
	*/
}
