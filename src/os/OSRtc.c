

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void GetRTC(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void __OSGetRTC(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void __OSSetRTC(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void ReadSram(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FA69C
 * Size:	000060
 */
void WriteSramCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0x24C0
  stw       r30, 0x10(r1)
  addi      r30, r31, 0x40
  lwz       r4, 0x40(r31)
  add       r3, r31, r4
  subfic    r5, r4, 0x40
  bl        .loc_0x60
  stw       r3, 0x4C(r31)
  lwz       r0, 0x4C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x48
  li        r0, 0x40
  stw       r0, 0x0(r30)

.loc_0x48:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr       

.loc_0x60:
*/
}

/*
 * --INFO--
 * Address:	801FA6FC
 * Size:	000118
 */
void WriteSram(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8020
  stw       r0, 0x4(r1)
  subi      r0, r6, 0x5964
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  li        r4, 0x1
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  mr        r5, r0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  li        r3, 0
  bl        -0x19F8
  cmpwi     r3, 0
  bne-      .loc_0x4C
  li        r3, 0
  b         .loc_0xFC

.loc_0x4C:
  li        r3, 0
  li        r4, 0x1
  li        r5, 0x3
  bl        -0x2078
  cmpwi     r3, 0
  bne-      .loc_0x74
  li        r3, 0
  bl        -0x1934
  li        r3, 0
  b         .loc_0xFC

.loc_0x74:
  rlwinm    r31,r31,6,0,25
  addi      r0, r31, 0x100
  oris      r0, r0, 0xA000
  stw       r0, 0x14(r1)
  addi      r4, r1, 0x14
  li        r3, 0
  li        r5, 0x4
  li        r6, 0x1
  li        r7, 0
  bl        -0x2AD4
  cntlzw    r0, r3
  rlwinm    r31,r0,27,5,31
  li        r3, 0
  bl        -0x26FC
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r4, r29, 0
  addi      r5, r30, 0
  or        r31, r31, r0
  li        r3, 0
  li        r6, 0x1
  bl        -0x28A8
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  li        r3, 0
  bl        -0x1FD0
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  li        r3, 0
  bl        -0x19BC
  cntlzw    r0, r31
  rlwinm    r3,r0,27,5,31

.loc_0xFC:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	801FA814
 * Size:	000134
 */
void __OSInitSram(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  li        r4, 0x40
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0x24C0
  addi      r3, r30, 0
  stw       r31, 0x44(r30)
  stw       r31, 0x48(r30)
  bl        -0x3C8C
  li        r3, 0
  li        r4, 0x1
  li        r5, 0
  bl        -0x1B18
  cmpwi     r3, 0
  bne-      .loc_0x50
  b         .loc_0x110

.loc_0x50:
  li        r3, 0
  li        r4, 0x1
  li        r5, 0x3
  bl        -0x2194
  cmpwi     r3, 0
  bne-      .loc_0x74
  li        r3, 0
  bl        -0x1A50
  b         .loc_0x110

.loc_0x74:
  lis       r3, 0x2000
  addi      r0, r3, 0x100
  stw       r0, 0x8(r1)
  addi      r4, r1, 0x8
  li        r3, 0
  li        r5, 0x4
  li        r6, 0x1
  li        r7, 0
  bl        -0x2BE8
  cntlzw    r0, r3
  rlwinm    r31,r0,27,5,31
  li        r3, 0
  bl        -0x2810
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r4, r30, 0
  or        r31, r31, r0
  li        r3, 0
  li        r5, 0x40
  li        r6, 0
  li        r7, 0
  bl        -0x2920
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  li        r3, 0
  bl        -0x2848
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  li        r3, 0
  bl        -0x20FC
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  li        r3, 0
  bl        -0x1AE8
  cntlzw    r0, r31
  rlwinm    r31,r0,27,5,31

.loc_0x110:
  stw       r31, 0x4C(r30)
  li        r0, 0x40
  stw       r0, 0x40(r30)
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
 * Address:	........
 * Size:	000068
 */
void LockSram(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FA948
 * Size:	00005C
 */
void __OSLockSram(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  addi      r31, r3, 0x24C0
  bl        -0x19E4
  lwz       r0, 0x48(r31)
  addi      r4, r31, 0x48
  cmpwi     r0, 0
  beq-      .loc_0x38
  bl        -0x19D0
  li        r31, 0
  b         .loc_0x44

.loc_0x38:
  stw       r3, 0x44(r31)
  li        r0, 0x1
  stw       r0, 0x0(r4)

.loc_0x44:
  lwz       r0, 0x14(r1)
  mr        r3, r31
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FA9A4
 * Size:	00005C
 */
void __OSLockSramEx(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  addi      r31, r3, 0x24C0
  bl        -0x1A40
  lwz       r0, 0x48(r31)
  addi      r4, r31, 0x48
  cmpwi     r0, 0
  beq-      .loc_0x38
  bl        -0x1A2C
  li        r3, 0
  b         .loc_0x48

.loc_0x38:
  stw       r3, 0x44(r31)
  li        r0, 0x1
  addi      r3, r31, 0x14
  stw       r0, 0x0(r4)

.loc_0x48:
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAA00
 * Size:	000308
 */
void UnlockSram(void)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r3, 0
  stw       r0, 0x4(r1)
  lis       r3, 0x803D
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r31, r3, 0x24C0
  beq-      .loc_0x2E0
  cmplwi    r4, 0
  bne-      .loc_0x1D4
  lbz       r3, 0x13(r31)
  rlwinm    r0,r3,0,30,31
  cmplwi    r0, 0x2
  ble-      .loc_0x40
  rlwinm    r0,r3,0,0,29
  stb       r0, 0x13(r31)

.loc_0x40:
  li        r0, 0
  sth       r0, 0x2(r31)
  addi      r5, r31, 0x14
  addi      r6, r31, 0xC
  addi      r3, r5, 0x1
  sth       r0, 0x0(r31)
  sub       r3, r3, r6
  cmplw     r6, r5
  rlwinm    r3,r3,31,1,31
  bge-      .loc_0x1D4
  rlwinm.   r0,r3,29,3,31
  mtctr     r0
  beq-      .loc_0x1A4

.loc_0x74:
  lhz       r5, 0x0(r31)
  lhz       r0, 0x0(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0x0(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0x2(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0x2(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0x4(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0x4(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0x6(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0x6(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0x8(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0x8(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0xA(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0xA(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0xC(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0xC(r6)
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  lhz       r5, 0x0(r31)
  lhz       r0, 0xE(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0xE(r6)
  addi      r6, r6, 0x10
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  bdnz+     .loc_0x74
  andi.     r3, r3, 0x7
  beq-      .loc_0x1D4

.loc_0x1A4:
  mtctr     r3

.loc_0x1A8:
  lhz       r5, 0x0(r31)
  lhz       r0, 0x0(r6)
  add       r0, r5, r0
  sth       r0, 0x0(r31)
  lhz       r0, 0x0(r6)
  addi      r6, r6, 0x2
  lhz       r5, 0x2(r31)
  not       r0, r0
  add       r0, r5, r0
  sth       r0, 0x2(r31)
  bdnz+     .loc_0x1A8

.loc_0x1D4:
  addi      r30, r31, 0x40
  lwz       r0, 0x40(r31)
  cmplw     r4, r0
  bge-      .loc_0x1E8
  stw       r4, 0x0(r30)

.loc_0x1E8:
  lwz       r29, 0x0(r30)
  lis       r3, 0x8020
  subi      r5, r3, 0x5964
  subfic    r27, r29, 0x40
  add       r28, r31, r29
  li        r3, 0
  li        r4, 0x1
  bl        -0x1EC8
  cmpwi     r3, 0
  bne-      .loc_0x218
  li        r0, 0
  b         .loc_0x2C8

.loc_0x218:
  li        r3, 0
  li        r4, 0x1
  li        r5, 0x3
  bl        -0x2548
  cmpwi     r3, 0
  bne-      .loc_0x240
  li        r3, 0
  bl        -0x1E04
  li        r0, 0
  b         .loc_0x2C8

.loc_0x240:
  rlwinm    r3,r29,6,0,25
  addi      r0, r3, 0x100
  oris      r0, r0, 0xA000
  stw       r0, 0x10(r1)
  addi      r4, r1, 0x10
  li        r3, 0
  li        r5, 0x4
  li        r6, 0x1
  li        r7, 0
  bl        -0x2FA4
  cntlzw    r0, r3
  rlwinm    r29,r0,27,5,31
  li        r3, 0
  bl        -0x2BCC
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r4, r28, 0
  addi      r5, r27, 0
  or        r29, r29, r0
  li        r3, 0
  li        r6, 0x1
  bl        -0x2D78
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r29, r29, r0
  li        r3, 0
  bl        -0x24A0
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r29, r29, r0
  li        r3, 0
  bl        -0x1E8C
  cntlzw    r0, r29
  rlwinm    r0,r0,27,5,31

.loc_0x2C8:
  stw       r0, 0x4C(r31)
  lwz       r0, 0x4C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x2E0
  li        r0, 0x40
  stw       r0, 0x0(r30)

.loc_0x2E0:
  li        r0, 0
  stw       r0, 0x48(r31)
  lwz       r3, 0x44(r31)
  bl        -0x1D48
  lwz       r3, 0x4C(r31)
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAD08
 * Size:	000024
 */
void __OSUnlockSram(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x318
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAD2C
 * Size:	000024
 */
void __OSUnlockSramEx(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x14
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x33C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAD50
 * Size:	000010
 */
void __OSSyncSram(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x24C0
  lwz       r3, 0x4C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void __OSCheckSram(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void __OSReadROM(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void __OSReadROMCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void __OSReadROMAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FAD60
 * Size:	000080
 */
void OSGetSoundMode(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0x24C0
  bl        -0x1DFC
  lwz       r0, 0x48(r31)
  addi      r4, r31, 0x48
  cmpwi     r0, 0
  beq-      .loc_0x38
  bl        -0x1DE8
  li        r31, 0
  b         .loc_0x44

.loc_0x38:
  stw       r3, 0x44(r31)
  li        r0, 0x1
  stw       r0, 0x0(r4)

.loc_0x44:
  lbz       r0, 0x13(r31)
  rlwinm.   r0,r0,0,29,29
  beq-      .loc_0x58
  li        r31, 0x1
  b         .loc_0x5C

.loc_0x58:
  li        r31, 0

.loc_0x5C:
  li        r3, 0
  li        r4, 0
  bl        -0x3C4
  lwz       r0, 0x24(r1)
  mr        r3, r31
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FADE0
 * Size:	0000A4
 */
void OSSetSoundMode(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0x24C0
  stw       r30, 0x18(r1)
  rlwinm    r30,r3,2,29,29
  bl        -0x1E84
  lwz       r0, 0x48(r31)
  addi      r4, r31, 0x48
  cmpwi     r0, 0
  beq-      .loc_0x40
  bl        -0x1E70
  li        r31, 0
  b         .loc_0x4C

.loc_0x40:
  stw       r3, 0x44(r31)
  li        r0, 0x1
  stw       r0, 0x0(r4)

.loc_0x4C:
  lbz       r3, 0x13(r31)
  rlwinm    r0,r3,0,29,29
  cmplw     r30, r0
  bne-      .loc_0x6C
  li        r3, 0
  li        r4, 0
  bl        -0x444
  b         .loc_0x8C

.loc_0x6C:
  rlwinm    r0,r3,0,30,28
  stb       r0, 0x13(r31)
  li        r3, 0x1
  li        r4, 0
  lbz       r0, 0x13(r31)
  or        r0, r0, r30
  stb       r0, 0x13(r31)
  bl        -0x468

.loc_0x8C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAE84
 * Size:	000080
 */
void OSGetProgressiveMode(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0x24C0
  bl        -0x1F20
  lwz       r0, 0x48(r31)
  addi      r4, r31, 0x48
  cmpwi     r0, 0
  beq-      .loc_0x38
  bl        -0x1F0C
  li        r31, 0
  b         .loc_0x44

.loc_0x38:
  stw       r3, 0x44(r31)
  li        r0, 0x1
  stw       r0, 0x0(r4)

.loc_0x44:
  lbz       r0, 0x13(r31)
  rlwinm.   r0,r0,0,24,24
  beq-      .loc_0x58
  li        r31, 0x1
  b         .loc_0x5C

.loc_0x58:
  li        r31, 0

.loc_0x5C:
  li        r3, 0
  li        r4, 0
  bl        -0x4E8
  lwz       r0, 0x24(r1)
  mr        r3, r31
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAF04
 * Size:	0000A4
 */
void OSSetProgressiveMode(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0x24C0
  stw       r30, 0x18(r1)
  rlwinm    r30,r3,7,24,24
  bl        -0x1FA8
  lwz       r0, 0x48(r31)
  addi      r4, r31, 0x48
  cmpwi     r0, 0
  beq-      .loc_0x40
  bl        -0x1F94
  li        r31, 0
  b         .loc_0x4C

.loc_0x40:
  stw       r3, 0x44(r31)
  li        r0, 0x1
  stw       r0, 0x0(r4)

.loc_0x4C:
  lbz       r3, 0x13(r31)
  rlwinm    r0,r3,0,24,24
  cmplw     r30, r0
  bne-      .loc_0x6C
  li        r3, 0
  li        r4, 0
  bl        -0x568
  b         .loc_0x8C

.loc_0x6C:
  rlwinm    r0,r3,0,25,23
  stb       r0, 0x13(r31)
  li        r3, 0x1
  li        r4, 0
  lbz       r0, 0x13(r31)
  or        r0, r0, r30
  stb       r0, 0x13(r31)
  bl        -0x58C

.loc_0x8C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void OSGetVideoMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void OSSetVideoMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void OSGetLanguage(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void OSSetLanguage(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void __OSGetBootMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void __OSSetBootMode(void)
{
	// UNUSED FUNCTION
}
