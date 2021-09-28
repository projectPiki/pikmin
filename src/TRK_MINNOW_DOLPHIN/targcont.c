

/*
 * --INFO--
 * Address:	802207B8
 * Size:	000034
 */
void TRKTargetContinue(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0xCC0
  bl        -0x68
  bl        -0x12CC
  bl        -0xA0
  li        r3, 0
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}