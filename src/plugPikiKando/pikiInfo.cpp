

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119CE4
 * Size:	000024
 */
void PikiInfo::PikiInfo()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x4(r3)
  stw       r0, 0x0(r3)
  stw       r0, 0x8(r3)
  stw       r0, 0x18(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x10(r3)
  stw       r0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80119D08
 * Size:	000024
 */
void PikiInfo::addFormationPiki()
{
/*
.loc_0x0:
  lwz       r4, 0x0(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x0(r3)
  lwz       r0, 0x4(r3)
  lwz       r4, 0x0(r3)
  cmpw      r0, r4
  bgelr-    
  stw       r4, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80119D2C
 * Size:	000010
 */
void PikiInfo::subFormationPiki()
{
/*
.loc_0x0:
  lwz       r5, 0x0(r3)
  subi      r0, r5, 0x1
  stw       r0, 0x0(r3)
  blr
*/
}