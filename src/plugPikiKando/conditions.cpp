

/*
 * --INFO--
 * Address:	800DAC28
 * Size:	000030
 */
void CndIsVisible::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r3, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r4)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DAC58
 * Size:	000030
 */
void CndIsAtari::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r3, r4
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r4)
  lwz       r12, 0x84(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DAC88
 * Size:	00002C
 */
void CndStickMouth::satisfy(Creature *)
{
/*
.loc_0x0:
  lwz       r0, 0xC8(r4)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x24
  lwz       r4, 0x184(r4)
  lwz       r0, 0x4(r3)
  cmplw     r4, r0
  bne-      .loc_0x24
  li        r3, 0x1
  blr       

.loc_0x24:
  li        r3, 0
  blr
*/
}