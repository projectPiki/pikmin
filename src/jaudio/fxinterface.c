

/*
 * --INFO--
 * Address:	8000BCC0
 * Size:	000138
 */
void DFX_SetFxLine(unsigned char, short *, FxlineConfig_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  addi      r27, r3, 0
  addi      r29, r5, 0
  stw       r4, 0xC(r1)
  bl        0x1ED2A0
  addi      r0, r3, 0
  addi      r3, r27, 0
  mr        r30, r0
  bl        -0x76C
  li        r0, 0
  cmplwi    r29, 0
  sth       r0, 0x0(r3)
  addi      r31, r3, 0
  beq-      .loc_0x9C
  lha       r0, 0x4(r29)
  lis       r3, 0x8022
  addi      r7, r3, 0x4E00
  addi      r3, r31, 0x10
  sth       r0, 0xA(r31)
  addi      r4, r29, 0x10
  li        r5, 0x8
  lhz       r0, 0x2(r29)
  rlwinm    r0,r0,1,0,30
  add       r6, r7, r0
  lhz       r0, 0x0(r6)
  sth       r0, 0x8(r31)
  lha       r0, 0x8(r29)
  sth       r0, 0xE(r31)
  lhz       r0, 0x6(r29)
  rlwinm    r0,r0,1,0,30
  add       r6, r7, r0
  lhz       r0, 0x0(r6)
  sth       r0, 0xC(r31)
  lwz       r0, 0xC(r29)
  sth       r0, 0x2(r31)
  bl        -0x418

.loc_0x9C:
  lwz       r28, 0xC(r1)
  cmplwi    r28, 0
  beq-      .loc_0xD8
  cmplwi    r29, 0
  beq-      .loc_0xD8
  lwz       r0, 0xC(r29)
  addi      r3, r28, 0
  mulli     r27, r0, 0xA0
  stw       r28, 0x4(r31)
  mr        r4, r27
  bl        -0x5CC4
  addi      r3, r28, 0
  addi      r4, r27, 0
  bl        0x1EAE58
  b         .loc_0xEC

.loc_0xD8:
  cmplwi    r29, 0
  beq-      .loc_0xE8
  cmplwi    r28, 0
  beq-      .loc_0xEC

.loc_0xE8:
  stw       r28, 0x4(r31)

.loc_0xEC:
  lwz       r0, 0x4(r31)
  cmplwi    r0, 0
  beq-      .loc_0x104
  lbz       r0, 0x0(r29)
  sth       r0, 0x0(r31)
  b         .loc_0x10C

.loc_0x104:
  li        r0, 0
  sth       r0, 0x0(r31)

.loc_0x10C:
  addi      r3, r31, 0
  li        r4, 0x20
  bl        0x1EAE14
  mr        r3, r30
  bl        0x1ED1C8
  lmw       r27, 0x24(r1)
  li        r3, 0x1
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void DFX_ChangeFxLineParam(unsigned char, unsigned char, unsigned long)
{
	// UNUSED FUNCTION
}