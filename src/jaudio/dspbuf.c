

/*
 * --INFO--
 * Address:	80006B80
 * Size:	000008
 */
void Jac_GetCurrentSCounter()
{
/*
.loc_0x0:
  lwz       r3, 0x2B64(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	80006BA0
 * Size:	000250
 */
void DspbufProcess(DSPBUF_EVENTS)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r3, 0x1
  stw       r0, 0x4(r1)
  lis       r4, 0x802F
  stwu      r1, -0x20(r1)
  stmw      r28, 0x10(r1)
  subi      r31, r4, 0x68D0
  beq-      .loc_0xB8
  bge-      .loc_0x30
  cmpwi     r3, 0
  bge-      .loc_0x3C
  b         .loc_0x238

.loc_0x30:
  cmpwi     r3, 0x3
  bge-      .loc_0x238
  b         .loc_0x13C

.loc_0x3C:
  li        r0, 0x2
  li        r29, 0
  stb       r0, 0x2B60(r13)
  li        r28, 0
  li        r30, 0
  stb       r29, 0x2B61(r13)

.loc_0x54:
  lwz       r0, -0x7FF8(r13)
  rlwinm    r3,r0,2,0,29
  bl        -0x147C
  add       r5, r31, r30
  li        r4, 0
  stw       r3, 0x0(r5)
  lwz       r6, -0x7FF8(r13)
  rlwinm    r0,r6,1,0,30
  mtctr     r0
  cmplwi    r0, 0
  ble-      .loc_0x90

.loc_0x80:
  lwz       r3, 0x0(r5)
  sthx      r29, r3, r4
  addi      r4, r4, 0x2
  bdnz+     .loc_0x80

.loc_0x90:
  lwz       r3, 0x0(r5)
  rlwinm    r4,r6,2,0,29
  bl        0x1EFFE4
  addi      r28, r28, 0x1
  addi      r30, r30, 0x4
  cmplwi    r28, 0x3
  blt+      .loc_0x54
  li        r0, 0
  stb       r0, 0x2B62(r13)
  b         .loc_0x238

.loc_0xB8:
  bl        0x1EE8
  lbz       r3, 0x2B60(r13)
  addi      r0, r3, 0x1
  rlwinm    r4,r0,0,24,31
  cmplwi    r4, 0x3
  bne-      .loc_0xD4
  li        r4, 0

.loc_0xD4:
  lbz       r0, 0x2B61(r13)
  rlwinm    r3,r4,0,24,31
  cmplw     r3, r0
  bne-      .loc_0xF0
  li        r0, 0
  stb       r0, 0x2B62(r13)
  b         .loc_0x238

.loc_0xF0:
  stb       r4, 0x2B60(r13)
  lwz       r3, -0x7FFC(r13)
  bl        -0x9D8
  lis       r4, 0x8022
  li        r3, 0x7
  addi      r4, r4, 0x2008
  bl        -0x16A8
  lbz       r3, 0x2B60(r13)
  lwz       r0, -0x7FF8(r13)
  rlwinm    r4,r3,2,0,29
  lwz       r3, -0x7FFC(r13)
  lwzx      r4, r31, r4
  rlwinm    r0,r0,1,0,30
  add       r5, r4, r0
  bl        0x1C18
  li        r0, 0x1
  stb       r0, 0x2B62(r13)
  bl        0x12C
  b         .loc_0x238

.loc_0x13C:
  lbz       r4, 0x2B61(r13)
  addi      r0, r4, 0x1
  rlwinm    r5,r0,0,24,31
  cmplwi    r5, 0x3
  bne-      .loc_0x154
  li        r5, 0

.loc_0x154:
  lbz       r0, 0x2B60(r13)
  rlwinm    r3,r5,0,24,31
  cmplw     r3, r0
  bne-      .loc_0x1F8
  rlwinm    r0,r4,2,0,29
  lwz       r6, -0x7FF8(r13)
  lwzx      r4, r31, r0
  li        r3, 0
  lbz       r0, 0x2B61(r13)
  rlwinm    r5,r6,0,0,30
  subi      r7, r4, 0x2
  rlwinm    r4,r6,1,0,30
  lhax      r5, r7, r5
  rlwinm    r0,r0,2,0,29
  lhax      r7, r7, r4
  mtctr     r6
  cmplwi    r6, 0
  ble-      .loc_0x1AC

.loc_0x19C:
  lwzx      r4, r31, r0
  sthx      r5, r4, r3
  addi      r3, r3, 0x2
  bdnz+     .loc_0x19C

.loc_0x1AC:
  lwz       r0, -0x7FF8(r13)
  rlwinm    r3,r6,1,0,30
  lbz       r5, 0x2B61(r13)
  rlwinm    r4,r0,1,0,30
  sub       r0, r4, r6
  rlwinm    r5,r5,2,0,29
  mtctr     r0
  cmplw     r6, r4
  bge-      .loc_0x1E0

.loc_0x1D0:
  lwzx      r4, r31, r5
  sthx      r7, r4, r3
  addi      r3, r3, 0x2
  bdnz+     .loc_0x1D0

.loc_0x1E0:
  lbz       r0, 0x2B62(r13)
  cmplwi    r0, 0
  bne-      .loc_0x228
  li        r3, 0x1
  bl        .loc_0x0
  b         .loc_0x228

.loc_0x1F8:
  stb       r5, 0x2B61(r13)
  lwz       r0, -0x7FF8(r13)
  lbz       r3, 0x2B61(r13)
  rlwinm    r4,r0,2,0,29
  rlwinm    r0,r3,2,0,29
  lwzx      r3, r31, r0
  bl        0x1EFE08
  lbz       r0, 0x2B62(r13)
  cmplwi    r0, 0
  bne-      .loc_0x228
  li        r3, 0x1
  bl        .loc_0x0

.loc_0x228:
  lbz       r0, 0x2B61(r13)
  rlwinm    r0,r0,2,0,29
  lwzx      r3, r31, r0
  b         .loc_0x23C

.loc_0x238:
  li        r3, 0

.loc_0x23C:
  lmw       r28, 0x10(r1)
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80006E00
 * Size:	000054
 */
void UpdateDSP()
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8022
  stw       r0, 0x4(r1)
  addi      r4, r3, 0x2014
  li        r3, 0x3
  stwu      r1, -0x8(r1)
  lwz       r5, 0x2B64(r13)
  addi      r0, r5, 0x1
  stw       r0, 0x2B64(r13)
  bl        -0x1824
  bl        0x4D38
  bl        0x534
  bl        0x4530
  bl        0x194C
  bl        0x4A8
  li        r3, 0x3
  bl        -0x1820
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80006E60
 * Size:	000040
 */
void MixDsp(long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lbz       r0, 0x2B6C(r13)
  extsb.    r0, r0
  bne-      .loc_0x28
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2B68(r13)
  stb       r0, 0x2B6C(r13)

.loc_0x28:
  li        r3, 0x2
  bl        -0x2EC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80006EA0
 * Size:	000024
 */
void DspFrameEnd()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x310
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}