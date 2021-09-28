

/*
 * --INFO--
 * Address:	801F5944
 * Size:	000008
 */
void PPCMfmsr(void)
{
/*
.loc_0x0:
  mfmsr     r3
  blr
*/
}

/*
 * --INFO--
 * Address:	801F594C
 * Size:	000008
 */
void PPCMtmsr(void)
{
/*
.loc_0x0:
  mtmsr     r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCOrMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCAndMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCAndCMsr(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5954
 * Size:	000008
 */
void PPCMfhid0(void)
{
/*
.loc_0x0:
  mfspr     r3, 0x3F0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMthid0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfhid1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F595C
 * Size:	000008
 */
void PPCMfl2cr(void)
{
/*
.loc_0x0:
  mfspr     r3, 0x3F9
  blr
*/
}

/*
 * --INFO--
 * Address:	801F5964
 * Size:	000008
 */
void PPCMtl2cr(void)
{
/*
.loc_0x0:
  mtspr     1017, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	801F596C
 * Size:	000008
 */
void PPCMtdec(void)
{
/*
.loc_0x0:
  mtdec     r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfdec(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5974
 * Size:	000008
 */
void PPCSync(void)
{
/*
.loc_0x0:
  sc        
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void PPCEieio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F597C
 * Size:	000014
 */
void PPCHalt(void)
{
/*
.loc_0x0:
  sync      

.loc_0x4:
  nop       
  li        r3, 0
  nop       
  b         .loc_0x4
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfmmcr0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtmmcr0(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfmmcr1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtmmcr1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc1(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc2(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc3(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpmc4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtpmc4(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfsia(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtsia(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5990
 * Size:	000008
 */
void PPCMfhid2(void)
{
/*
.loc_0x0:
  mfspr     r3, 0x398
  blr
*/
}

/*
 * --INFO--
 * Address:	801F5998
 * Size:	000008
 */
void PPCMthid2(void)
{
/*
.loc_0x0:
  mtspr     920, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void PPCMfwpar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F59A0
 * Size:	000008
 */
void PPCMtwpar(void)
{
/*
.loc_0x0:
  mtspr     921, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfdmaU(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfdmaL(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtdmaU(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMtdmaL(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PPCMfpvr(void)
{
	// UNUSED FUNCTION
}