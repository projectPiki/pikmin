#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void __strerror(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void strerror(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802190E8
 * Size:	00006C
 */
void strstr(void)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0
	  subi      r5, r3, 0x1
	  subi      r4, r4, 0x1
	  beqlr-
	  lbzu      r6, 0x1(r4)
	  cmplwi    r6, 0
	  bne-      .loc_0x58
	  blr

	.loc_0x20:
	  cmplw     r0, r6
	  bne-      .loc_0x58
	  subi      r7, r5, 0x1
	  subi      r8, r4, 0x1

	.loc_0x30:
	  lbzu      r0, 0x1(r7)
	  lbzu      r3, 0x1(r8)
	  cmplw     r0, r3
	  bne-      .loc_0x48
	  cmplwi    r0, 0
	  bne+      .loc_0x30

	.loc_0x48:
	  cmplwi    r3, 0
	  bne-      .loc_0x58
	  mr        r3, r5
	  blr

	.loc_0x58:
	  lbzu      r0, 0x1(r5)
	  cmplwi    r0, 0
	  bne+      .loc_0x20
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void strtok(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void strcspn(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void strspn(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void strpbrk(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void strrchr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void strxfrm(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void strcoll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80219154
 * Size:	000030
 */
void strchr(void)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x1
	  rlwinm    r0,r4,0,24,31
	  b         .loc_0x14

	.loc_0xC:
	  cmplw     r4, r0
	  beqlr-

	.loc_0x14:
	  lbzu      r4, 0x1(r3)
	  cmplwi    r4, 0
	  bne+      .loc_0xC
	  cmplwi    r0, 0
	  beqlr-
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80219184
 * Size:	000040
 */
void strncmp(void)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x1
	  subi      r4, r4, 0x1
	  addi      r6, r5, 0x1
	  b         .loc_0x30

	.loc_0x10:
	  lbzu      r0, 0x1(r3)
	  lbzu      r5, 0x1(r4)
	  cmplw     r0, r5
	  beq-      .loc_0x28
	  sub       r3, r0, r5
	  blr

	.loc_0x28:
	  cmplwi    r0, 0
	  beq-      .loc_0x38

	.loc_0x30:
	  subic.    r6, r6, 0x1
	  bne+      .loc_0x10

	.loc_0x38:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802191C4
 * Size:	000124
 */
void strcmp(void)
{
	/*
	.loc_0x0:
	  lbz       r6, 0x0(r3)
	  lbz       r5, 0x0(r4)
	  sub.      r0, r6, r5
	  beq-      .loc_0x18
	  sub       r3, r6, r5
	  blr

	.loc_0x18:
	  rlwinm    r0,r4,0,30,31
	  rlwinm    r5,r3,0,30,31
	  cmplw     r0, r5
	  bne-      .loc_0xEC
	  cmplwi    r5, 0
	  beq-      .loc_0x84
	  cmplwi    r6, 0
	  bne-      .loc_0x40
	  li        r3, 0
	  blr

	.loc_0x40:
	  subfic    r0, r5, 0x3
	  cmplwi    r0, 0
	  mtctr     r0
	  beq-      .loc_0x7C

	.loc_0x50:
	  lbzu      r5, 0x1(r3)
	  lbzu      r0, 0x1(r4)
	  sub.      r0, r5, r0
	  beq-      .loc_0x68
	  mr        r3, r0
	  blr

	.loc_0x68:
	  cmplwi    r5, 0
	  bne-      .loc_0x78
	  li        r3, 0
	  blr

	.loc_0x78:
	  bdnz+     .loc_0x50

	.loc_0x7C:
	  addi      r3, r3, 0x1
	  addi      r4, r4, 0x1

	.loc_0x84:
	  lwz       r7, 0x0(r3)
	  lwz       r6, 0x2AE4(r13)
	  lwz       r5, 0x2AE0(r13)
	  add       r0, r7, r6
	  lwz       r8, 0x0(r4)
	  and.      r0, r0, r5
	  bne-      .loc_0xD4
	  b         .loc_0xB8

	.loc_0xA4:
	  lwzu      r7, 0x4(r3)
	  lwzu      r8, 0x4(r4)
	  add       r0, r7, r6
	  and.      r0, r0, r5
	  bne-      .loc_0xD4

	.loc_0xB8:
	  cmplw     r7, r8
	  beq+      .loc_0xA4
	  ble-      .loc_0xCC
	  li        r3, 0x1
	  blr

	.loc_0xCC:
	  li        r3, -0x1
	  blr

	.loc_0xD4:
	  lbz       r6, 0x0(r3)
	  lbz       r5, 0x0(r4)
	  sub.      r0, r6, r5
	  beq-      .loc_0xEC
	  sub       r3, r6, r5
	  blr

	.loc_0xEC:
	  cmplwi    r6, 0
	  bne-      .loc_0xFC
	  li        r3, 0
	  blr

	.loc_0xFC:
	  lbzu      r5, 0x1(r3)
	  lbzu      r0, 0x1(r4)
	  sub.      r0, r5, r0
	  beq-      .loc_0x114
	  mr        r3, r0
	  blr

	.loc_0x114:
	  cmplwi    r5, 0
	  bne+      .loc_0xFC
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void strncat(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802192E8
 * Size:	00002C
 */
void strcat(void)
{
	/*
	.loc_0x0:
	  subi      r4, r4, 0x1
	  subi      r5, r3, 0x1

	.loc_0x8:
	  lbzu      r0, 0x1(r5)
	  cmplwi    r0, 0
	  bne+      .loc_0x8
	  subi      r5, r5, 0x1

	.loc_0x18:
	  lbzu      r0, 0x1(r4)
	  cmplwi    r0, 0
	  stbu      r0, 0x1(r5)
	  bne+      .loc_0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80219314
 * Size:	000044
 */
void strncpy(void)
{
	/*
	.loc_0x0:
	  subi      r4, r4, 0x1
	  subi      r6, r3, 0x1
	  addi      r5, r5, 0x1
	  b         .loc_0x38

	.loc_0x10:
	  lbzu      r0, 0x1(r4)
	  cmplwi    r0, 0
	  stbu      r0, 0x1(r6)
	  bne-      .loc_0x38
	  li        r0, 0
	  b         .loc_0x2C

	.loc_0x28:
	  stbu      r0, 0x1(r6)

	.loc_0x2C:
	  subic.    r5, r5, 0x1
	  bne+      .loc_0x28
	  blr

	.loc_0x38:
	  subic.    r5, r5, 0x1
	  bne+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80219358
 * Size:	0000B4
 */
void strcpy(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r3,0,30,31
	  rlwinm    r5,r4,0,30,31
	  cmplw     r0, r5
	  addi      r7, r3, 0
	  bne-      .loc_0x90
	  cmplwi    r5, 0
	  beq-      .loc_0x58
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  stb       r0, 0x0(r7)
	  beqlr-
	  subfic    r0, r5, 0x3
	  cmplwi    r0, 0
	  mtctr     r0
	  beq-      .loc_0x50

	.loc_0x3C:
	  lbzu      r0, 0x1(r4)
	  cmplwi    r0, 0
	  stbu      r0, 0x1(r7)
	  beqlr-
	  bdnz+     .loc_0x3C

	.loc_0x50:
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0x1

	.loc_0x58:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x2AE4(r13)
	  lwz       r6, 0x2AE0(r13)
	  addi      r8, r5, 0
	  add       r5, r5, r0
	  and.      r5, r5, r6
	  bne-      .loc_0x90
	  subi      r7, r7, 0x4

	.loc_0x78:
	  stwu      r8, 0x4(r7)
	  lwzu      r8, 0x4(r4)
	  add       r5, r8, r0
	  and.      r5, r5, r6
	  beq+      .loc_0x78
	  addi      r7, r7, 0x4

	.loc_0x90:
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  stb       r0, 0x0(r7)
	  beqlr-

	.loc_0xA0:
	  lbzu      r0, 0x1(r4)
	  cmplwi    r0, 0
	  stbu      r0, 0x1(r7)
	  bne+      .loc_0xA0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021940C
 * Size:	000020
 */
void strlen(void)
{
	/*
	.loc_0x0:
	  li        r4, -0x1
	  subi      r3, r3, 0x1

	.loc_0x8:
	  lbzu      r0, 0x1(r3)
	  addi      r4, r4, 0x1
	  cmplwi    r0, 0
	  bne+      .loc_0x8
	  mr        r3, r4
	  blr
	*/
}
