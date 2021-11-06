

/*
 * --INFO--
 * Address:	8000D740
 * Size:	000064
 */
void GetRandom_s32(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        0x1EB82C
  lis       r4, 0x1358
  lwz       r5, -0x7FD0(r13)
  subi      r0, r4, 0x6422
  lwz       r6, -0x7FCC(r13)
  lis       r4, 0x9876
  addi      r4, r4, 0x5432
  stw       r6, -0x7FD0(r13)
  mullw     r0, r5, r0
  mullw     r4, r6, r4
  srawi     r0, r0, 0x4
  add       r31, r4, r0
  addi      r31, r31, 0x1
  stw       r31, -0x7FCC(r13)
  bl        0x1EB81C
  mr        r3, r31
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D7C0
 * Size:	000024
 */
void GetRandom_u32(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x8C
  rlwinm    r3,r3,0,1,31
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D800
 * Size:	000038
 */
void GetRandom_ulimit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0x54
  divwu     r0, r3, r31
  mullw     r0, r0, r31
  sub       r3, r3, r0
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GetRandom_slimit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000D840
 * Size:	000054
 */
void GetRandom_sf32(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  bl        -0x10C
  rlwinm    r4,r3,0,8,31
  lis       r0, 0x4330
  xoris     r4, r4, 0x8000
  lfd       f2, -0x7F68(r2)
  stw       r4, 0x14(r1)
  cmpwi     r3, 0
  lfs       f0, -0x7F70(r2)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f1, f1, f0
  bge-      .loc_0x44
  fneg      f1, f1

.loc_0x44:
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
