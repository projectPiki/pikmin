

/*
 * --INFO--
 * Address:	80214870
 * Size:	0000F4
 */
void __va_arg(void)
{
/*
.loc_0x0:
  rlwinm    r0,r4,0,24,31
  lbz       r6, 0x0(r3)
  cmplwi    r0, 0x4
  addi      r7, r3, 0
  extsb     r6, r6
  li        r5, 0x8
  li        r8, 0x4
  li        r9, 0x1
  li        r10, 0
  li        r11, 0
  li        r12, 0x4
  bne-      .loc_0x4C
  lwz       r4, 0x4(r3)
  addi      r0, r4, 0xF
  rlwinm    r4,r0,0,0,27
  addi      r0, r4, 0x10
  stw       r0, 0x4(r3)
  mr        r3, r4
  blr       

.loc_0x4C:
  cmplwi    r0, 0x3
  bne-      .loc_0x6C
  lbz       r6, 0x1(r3)
  addi      r7, r3, 0x1
  li        r8, 0x8
  extsb     r6, r6
  li        r11, 0x20
  li        r12, 0x8

.loc_0x6C:
  rlwinm    r0,r4,0,24,31
  cmplwi    r0, 0x2
  bne-      .loc_0x90
  rlwinm.   r0,r6,0,31,31
  li        r8, 0x8
  li        r5, 0x7
  beq-      .loc_0x8C
  li        r10, 0x1

.loc_0x8C:
  li        r9, 0x2

.loc_0x90:
  cmpw      r6, r5
  bge-      .loc_0xB8
  add       r6, r6, r10
  lwz       r5, 0x8(r3)
  mullw     r3, r6, r12
  add       r0, r6, r9
  add       r6, r11, r3
  stb       r0, 0x0(r7)
  add       r6, r5, r6
  b         .loc_0xE0

.loc_0xB8:
  li        r0, 0x8
  stb       r0, 0x0(r7)
  subi      r0, r8, 0x1
  not       r6, r0
  lwz       r0, 0x4(r3)
  add       r5, r8, r0
  subi      r0, r5, 0x1
  and       r6, r6, r0
  add       r0, r6, r8
  stw       r0, 0x4(r3)

.loc_0xE0:
  rlwinm.   r0,r4,0,24,31
  bne-      .loc_0xEC
  lwz       r6, 0x0(r6)

.loc_0xEC:
  mr        r3, r6
  blr
*/
}
