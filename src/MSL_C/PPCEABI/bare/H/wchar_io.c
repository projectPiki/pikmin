

/*
 * --INFO--
 * Address:	8021A690
 * Size:	000080
 */
void fwide(void)
{
/*
.loc_0x0:
  lhz       r0, 0x4(r3)
  rlwinm.   r0,r0,26,29,31
  bne-      .loc_0x14
  li        r3, 0
  blr       

.loc_0x14:
  lbz       r5, 0x5(r3)
  rlwinm    r0,r5,28,30,31
  cmpwi     r0, 0x1
  beq-      .loc_0x78
  bge-      .loc_0x34
  cmpwi     r0, 0
  bge-      .loc_0x40
  blr       

.loc_0x34:
  cmpwi     r0, 0x3
  bgelr-    
  b         .loc_0x70

.loc_0x40:
  cmpwi     r4, 0
  ble-      .loc_0x58
  li        r0, 0x2
  rlwimi    r5,r0,4,26,27
  stb       r5, 0x5(r3)
  b         .loc_0x68

.loc_0x58:
  bge-      .loc_0x68
  li        r0, 0x1
  rlwimi    r5,r0,4,26,27
  stb       r5, 0x5(r3)

.loc_0x68:
  mr        r3, r4
  blr       

.loc_0x70:
  li        r3, 0x1
  blr       

.loc_0x78:
  li        r3, -0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void fgetws(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void fputws(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void ungetwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void fgetwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void getwchar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void getwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void fputwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void putwchar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void putwc(void)
{
	// UNUSED FUNCTION
}