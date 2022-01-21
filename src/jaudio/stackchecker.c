

/*
 * --INFO--
 * Address:	800082C0
 * Size:	00003C
 */
void Jac_StackInit(void)
{
	/*
	.loc_0x0:
	  lis       r6, 0x1234
	  lis       r5, 0xFADF
	  addi      r7, r6, 0x5678
	  subi      r6, r5, 0x4542
	  subi      r0, r4, 0x1
	  li        r5, 0x8
	  mtctr     r0
	  cmplwi    r4, 0x1
	  blelr-

	.loc_0x24:
	  add       r4, r3, r5
	  addi      r5, r5, 0x8
	  stw       r7, 0x4(r4)
	  stw       r6, 0x0(r4)
	  bdnz+     .loc_0x24
	  blr
	*/
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
