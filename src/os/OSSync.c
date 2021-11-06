

/*
 * --INFO--
 * Address:	801FB928
 * Size:	000020
 */
void SystemCallVector(void)
{
/*
.loc_0x0:
  mfspr     r9, 0x3F0
  ori       r10, r9, 0x8
  mtspr     1008, r10
  isync     
  sync      
  mtspr     1008, r9
  rfi       
  nop
*/
}

/*
 * --INFO--
 * Address:	801FB948
 * Size:	000064
 */
void __OSInitSystemCall(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  lis       r5, 0x8000
  lis       r4, 0x8020
  lis       r3, 0x8020
  addi      r31, r5, 0xC00
  subi      r0, r3, 0x46BC
  subi      r4, r4, 0x46D8
  mr        r3, r31
  sub       r5, r0, r4
  bl        -0x1F8564
  mr        r3, r31
  li        r4, 0x100
  bl        -0x4D34
  sync      
  mr        r3, r31
  li        r4, 0x100
  bl        -0x4CB4
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}
