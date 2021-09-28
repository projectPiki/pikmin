

/*
 * --INFO--
 * Address:	80220418
 * Size:	000048
 */
void TRK_main(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x4114
  lis       r4, 0x803D
  stwu      r3, 0x6278(r4)
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0
  bne-      .loc_0x2C
  bl        -0x4034
  bl        -0x4480

.loc_0x2C:
  bl        -0x4060
  lis       r4, 0x803D
  stw       r3, 0x6278(r4)
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}