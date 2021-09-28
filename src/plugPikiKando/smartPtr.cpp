

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
 * Address:	800E4338
 * Size:	000018
 */
void RefCountable::RefCountable()
{
/*
.loc_0x0:
  lis       r4, 0x802C
  subi      r0, r4, 0x4E64
  stw       r0, 0x0(r3)
  li        r0, 0
  stw       r0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E4350
 * Size:	00000C
 */
void RefCountable::clearCnt()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E435C
 * Size:	000010
 */
void RefCountable::addCnt()
{
/*
.loc_0x0:
  lwz       r4, 0x4(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E436C
 * Size:	000024
 */
void RefCountable::subCnt()
{
/*
.loc_0x0:
  lwz       r4, 0x4(r3)
  subi      r0, r4, 0x1
  stw       r0, 0x4(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bgelr-    
  li        r0, 0
  stw       r0, 0x4(r3)
  blr
*/
}