

/*
 * --INFO--
 * Address:	801B3628
 * Size:	000024
 */
void PUTRect::set(int, int, int, int)
{
/*
.loc_0x0:
  extsh     r0, r4
  sth       r0, 0x0(r3)
  extsh     r0, r5
  extsh     r4, r6
  sth       r0, 0x2(r3)
  extsh     r0, r7
  sth       r4, 0x4(r3)
  sth       r0, 0x6(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801B364C
 * Size:	000024
 */
void PUTRect::copy(const PUTRect &)
{
/*
.loc_0x0:
  lha       r0, 0x0(r4)
  sth       r0, 0x0(r3)
  lha       r0, 0x2(r4)
  sth       r0, 0x2(r3)
  lha       r0, 0x4(r4)
  sth       r0, 0x4(r3)
  lha       r0, 0x6(r4)
  sth       r0, 0x6(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PUTRect::add(const PUTPoint &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3670
 * Size:	000034
 */
void PUTRect::add(int, int)
{
/*
.loc_0x0:
  lha       r0, 0x0(r3)
  add       r0, r0, r4
  sth       r0, 0x0(r3)
  lha       r0, 0x4(r3)
  add       r0, r0, r4
  sth       r0, 0x4(r3)
  lha       r0, 0x2(r3)
  add       r0, r0, r5
  sth       r0, 0x2(r3)
  lha       r0, 0x6(r3)
  add       r0, r0, r5
  sth       r0, 0x6(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801B36A4
 * Size:	000080
 */
void PUTRect::intersect(const PUTRect &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lha       r5, 0x0(r4)
  lha       r0, 0x0(r3)
  cmpw      r0, r5
  bge-      .loc_0x20
  sth       r5, 0x0(r3)

.loc_0x20:
  lha       r0, 0x2(r3)
  lha       r5, 0x2(r4)
  cmpw      r0, r5
  bge-      .loc_0x34
  sth       r5, 0x2(r3)

.loc_0x34:
  lha       r0, 0x4(r3)
  lha       r5, 0x4(r4)
  cmpw      r0, r5
  ble-      .loc_0x48
  sth       r5, 0x4(r3)

.loc_0x48:
  lha       r0, 0x6(r3)
  lha       r4, 0x6(r4)
  cmpw      r0, r4
  ble-      .loc_0x5C
  sth       r4, 0x6(r3)

.loc_0x5C:
  bl        0xC0
  rlwinm    r0,r3,0,24,31
  cntlzw    r0, r0
  rlwinm    r0,r0,27,5,31
  mr        r3, r0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PUTRect::move(const PUTPoint &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3724
 * Size:	000044
 */
void PUTRect::move(int, int)
{
/*
.loc_0x0:
  lha       r8, 0x0(r3)
  extsh     r4, r4
  lha       r7, 0x4(r3)
  extsh     r0, r5
  lha       r6, 0x2(r3)
  lha       r5, 0x6(r3)
  sub       r7, r7, r8
  sth       r4, 0x0(r3)
  sub       r4, r5, r6
  sth       r0, 0x2(r3)
  lha       r0, 0x0(r3)
  add       r0, r0, r7
  sth       r0, 0x4(r3)
  lha       r0, 0x2(r3)
  add       r0, r0, r4
  sth       r0, 0x6(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801B3768
 * Size:	00001C
 */
void PUTRect::resize(int, int)
{
/*
.loc_0x0:
  lha       r0, 0x0(r3)
  add       r0, r0, r4
  sth       r0, 0x4(r3)
  lha       r0, 0x2(r3)
  add       r0, r0, r5
  sth       r0, 0x6(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void PUTRect::reform(int, int, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3784
 * Size:	00003C
 */
void PUTRect::normalize()
{
/*
.loc_0x0:
  lha       r4, 0x0(r3)
  lha       r0, 0x4(r3)
  cmpw      r4, r0
  ble-      .loc_0x1C
  sth       r4, 0x4(r3)
  extsh     r0, r0
  sth       r0, 0x0(r3)

.loc_0x1C:
  lha       r4, 0x2(r3)
  lha       r0, 0x6(r3)
  cmpw      r4, r0
  blelr-    
  sth       r4, 0x6(r3)
  extsh     r0, r0
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801B37C0
 * Size:	000030
 */
void PUTRect::isEmpty() const
{
/*
.loc_0x0:
  lha       r4, 0x0(r3)
  li        r5, 0x1
  lha       r0, 0x4(r3)
  cmpw      r4, r0
  bge-      .loc_0x28
  lha       r4, 0x2(r3)
  lha       r0, 0x6(r3)
  cmpw      r4, r0
  bge-      .loc_0x28
  li        r5, 0

.loc_0x28:
  mr        r3, r5
  blr
*/
}