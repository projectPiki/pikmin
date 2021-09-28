

/*
 * --INFO--
 * Address:	802154C0
 * Size:	000008
 */
void GetR2()
{
/*
.loc_0x0:
  mr        r3, r2
  blr
*/
}

/*
 * --INFO--
 * Address:	802154C8
 * Size:	000034
 */
void __fini_cpp_exceptions(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2AC0(r13)
  cmpwi     r3, -0x2
  beq-      .loc_0x24
  bl        -0x788
  li        r0, -0x2
  stw       r0, 0x2AC0(r13)

.loc_0x24:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	802154FC
 * Size:	000040
 */
void __init_cpp_exceptions(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x2AC0(r13)
  cmpwi     r0, -0x2
  bne-      .loc_0x30
  bl        -0x54
  lis       r5, 0x8000
  mr        r4, r3
  addi      r3, r5, 0x5530
  bl        -0x798
  stw       r3, 0x2AC0(r13)

.loc_0x30:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}