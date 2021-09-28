

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80143E48
 * Size:	000094
 */
void TekiAnimationManager::TekiAnimationManager(TekiMgr *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r5, 0x738C
  li        r6, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lis       r3, 0x8022
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x737C
  lis       r3, 0x802D
  stw       r0, 0x0(r30)
  subi      r5, r3, 0x3194
  lis       r3, 0x8023
  stw       r6, 0x10(r30)
  subi      r0, r3, 0x71E0
  addi      r3, r30, 0
  stw       r6, 0xC(r30)
  mr        r4, r5
  stw       r6, 0x8(r30)
  stw       r5, 0x4(r30)
  stw       r0, 0x0(r30)
  bl        -0x103770
  lis       r3, 0x802D
  subi      r0, r3, 0x3134
  stw       r0, 0x0(r30)
  mr        r3, r30
  stw       r31, 0x20(r30)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80143EDC
 * Size:	000080
 */
void TekiAnimationManager::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  li        r30, 0
  rlwinm    r31,r30,2,0,29
  stw       r29, 0x14(r1)
  addi      r29, r4, 0
  stw       r28, 0x10(r1)
  addi      r28, r3, 0

.loc_0x2C:
  lwz       r3, 0x20(r28)
  addi      r0, r31, 0xD8
  addi      r4, r29, 0
  lwzx      r3, r3, r0
  lwz       r3, 0x14(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  addi      r30, r30, 0x1
  cmpwi     r30, 0x23
  addi      r31, r31, 0x4
  blt+      .loc_0x2C
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}