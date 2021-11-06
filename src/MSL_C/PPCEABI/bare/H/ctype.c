

/*
 * --INFO--
 * Address:	80215DB4
 * Size:	000028
 */
void toupper(void)
{
/*
.loc_0x0:
  cmpwi     r3, -0x1
  bne-      .loc_0x10
  li        r3, -0x1
  blr       

.loc_0x10:
  lis       r4, 0x8022
  rlwinm    r3,r3,0,24,31
  addi      r0, r4, 0x2A08
  add       r3, r0, r3
  lbz       r3, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80215DDC
 * Size:	000028
 */
void tolower(void)
{
/*
.loc_0x0:
  cmpwi     r3, -0x1
  bne-      .loc_0x10
  li        r3, -0x1
  blr       

.loc_0x10:
  lis       r4, 0x8022
  rlwinm    r3,r3,0,24,31
  addi      r0, r4, 0x2908
  add       r3, r0, r3
  lbz       r3, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isxdigit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isupper(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isspace(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void ispunct(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isprint(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void islower(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isgraph(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isdigit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void iscntrl(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isalpha(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void isalnum(void)
{
	// UNUSED FUNCTION
}
