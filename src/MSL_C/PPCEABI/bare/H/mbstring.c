

/*
 * --INFO--
 * Address:	802160E0
 * Size:	00003C
 */
void wcstombs(void)
{
/*
.loc_0x0:
  cmplwi    r5, 0
  mtctr     r5
  li        r6, 0
  ble-      .loc_0x34

.loc_0x10:
  lhz       r0, 0x0(r4)
  addi      r4, r4, 0x2
  extsb     r5, r0
  extsb.    r0, r5
  stb       r5, 0x0(r3)
  addi      r3, r3, 0x1
  beq-      .loc_0x34
  addi      r6, r6, 0x1
  bdnz+     .loc_0x10

.loc_0x34:
  mr        r3, r6
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void mbstowcs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void wctomb(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021611C
 * Size:	000050
 */
void mbtowc(void)
{
/*
.loc_0x0:
  cmplwi    r4, 0
  bne-      .loc_0x10
  li        r3, 0
  blr       

.loc_0x10:
  cmplwi    r5, 0
  bne-      .loc_0x20
  li        r3, -0x1
  blr       

.loc_0x20:
  cmplwi    r3, 0
  beq-      .loc_0x34
  lbz       r0, 0x0(r4)
  extsb     r0, r0
  sth       r0, 0x0(r3)

.loc_0x34:
  lbz       r0, 0x0(r4)
  extsb.    r0, r0
  bne-      .loc_0x48
  li        r3, 0
  blr       

.loc_0x48:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void mblen(void)
{
	// UNUSED FUNCTION
}
