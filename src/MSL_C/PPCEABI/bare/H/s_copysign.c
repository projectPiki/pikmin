

/*
 * --INFO--
 * Address:	8021B4A8
 * Size:	00002C
 */
void copysign(void)
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  stfd      f1, 0x8(r1)
  stfd      f2, 0x10(r1)
  lwz       r3, 0x8(r1)
  lwz       r0, 0x10(r1)
  rlwinm    r0,r0,0,0,0
  rlwimi    r0,r3,0,1,31
  stw       r0, 0x8(r1)
  lfd       f1, 0x8(r1)
  addi      r1, r1, 0x18
  blr
*/
}