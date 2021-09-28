

/*
 * --INFO--
 * Address:	8021B4D4
 * Size:	00009C
 */
void frexp(void)
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r0, 0x7FF0
  li        r4, 0
  stfd      f1, 0x8(r1)
  lwz       r5, 0x8(r1)
  lwz       r8, 0xC(r1)
  rlwinm    r6,r5,0,1,31
  cmpw      r6, r0
  stw       r4, 0x0(r3)
  addi      r7, r5, 0
  addi      r4, r6, 0
  bge-      .loc_0x38
  or.       r0, r4, r8
  bne-      .loc_0x40

.loc_0x38:
  lfd       f1, 0x8(r1)
  b         .loc_0x94

.loc_0x40:
  lis       r0, 0x10
  cmpw      r4, r0
  bge-      .loc_0x70
  lfd       f1, 0x8(r1)
  li        r0, -0x36
  lfd       f0, -0x3A40(r2)
  fmul      f0, f1, f0
  stfd      f0, 0x8(r1)
  lwz       r4, 0x8(r1)
  stw       r0, 0x0(r3)
  addi      r7, r4, 0
  rlwinm    r4,r4,0,1,31

.loc_0x70:
  lwz       r5, 0x0(r3)
  srawi     r4, r4, 0x14
  rlwinm    r0,r7,0,12,0
  add       r4, r4, r5
  subi      r4, r4, 0x3FE
  stw       r4, 0x0(r3)
  oris      r0, r0, 0x3FE0
  stw       r0, 0x8(r1)
  lfd       f1, 0x8(r1)

.loc_0x94:
  addi      r1, r1, 0x18
  blr
*/
}