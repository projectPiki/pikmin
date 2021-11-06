

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void getEncoderType(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void cntlzd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void VISetRegs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020247C
 * Size:	000210
 */
void __VIRetraceHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xCC00
  stw       r0, 0x4(r1)
  li        r6, 0
  stwu      r1, -0x2F8(r1)
  stmw      r27, 0x2E4(r1)
  addi      r30, r4, 0
  lhzu      r5, 0x2030(r3)
  rlwinm.   r0,r5,0,16,16
  beq-      .loc_0x34
  rlwinm    r0,r5,0,17,15
  sth       r0, 0x0(r3)
  ori       r6, r6, 0x1

.loc_0x34:
  lis       r3, 0xCC00
  lhzu      r4, 0x2034(r3)
  rlwinm.   r0,r4,0,16,16
  beq-      .loc_0x50
  rlwinm    r0,r4,0,17,15
  sth       r0, 0x0(r3)
  ori       r6, r6, 0x2

.loc_0x50:
  lis       r3, 0xCC00
  lhzu      r4, 0x2038(r3)
  rlwinm.   r0,r4,0,16,16
  beq-      .loc_0x6C
  rlwinm    r0,r4,0,17,15
  sth       r0, 0x0(r3)
  ori       r6, r6, 0x4

.loc_0x6C:
  lis       r3, 0xCC00
  lhzu      r4, 0x203C(r3)
  rlwinm.   r0,r4,0,16,16
  beq-      .loc_0x88
  rlwinm    r0,r4,0,17,15
  sth       r0, 0x0(r3)
  ori       r6, r6, 0x8

.loc_0x88:
  rlwinm.   r0,r6,0,29,29
  bne-      .loc_0x98
  rlwinm.   r0,r6,0,28,28
  beq-      .loc_0xA4

.loc_0x98:
  mr        r3, r30
  bl        -0xB2A4
  b         .loc_0x1FC

.loc_0xA4:
  lwz       r4, 0x3310(r13)
  addi      r3, r1, 0x18
  addi      r0, r4, 0x1
  stw       r0, 0x3310(r13)
  bl        -0xB0F4
  addi      r3, r1, 0x18
  bl        -0xB2C4
  lwz       r12, 0x3320(r13)
  cmplwi    r12, 0
  beq-      .loc_0xD8
  lwz       r3, 0x3310(r13)
  mtlr      r12
  blrl      

.loc_0xD8:
  lwz       r0, 0x3314(r13)
  cmplwi    r0, 0
  beq-      .loc_0x1C0
  lwz       r0, 0x3340(r13)
  cmplwi    r0, 0x1
  bne-      .loc_0xFC
  bl        0x155C
  cmplwi    r3, 0
  beq-      .loc_0x1AC

.loc_0xFC:
  lis       r4, 0x803D
  lis       r3, 0xCC00
  addi      r31, r4, 0x32E0
  addi      r29, r3, 0x2000
  b         .loc_0x184

.loc_0x110:
  lwz       r3, 0x3348(r13)
  li        r5, 0x20
  lwz       r27, 0x334C(r13)
  addi      r4, r27, 0
  bl        0x12D58
  cntlzw    r4, r4
  cmpwi     r4, 0x20
  li        r0, -0x1
  and       r0, r27, r0
  bge-      .loc_0x13C
  b         .loc_0x144

.loc_0x13C:
  cntlzw    r3, r0
  addi      r4, r3, 0x20

.loc_0x144:
  rlwinm    r6,r4,1,0,30
  add       r3, r31, r6
  lhz       r0, 0x0(r3)
  subfic    r5, r4, 0x3F
  li        r3, 0
  sthx      r0, r29, r6
  li        r4, 0x1
  bl        0x12CF4
  lwz       r0, 0x3348(r13)
  not       r5, r3
  not       r4, r4
  lwz       r3, 0x334C(r13)
  and       r0, r0, r5
  and       r3, r3, r4
  stw       r3, 0x334C(r13)
  stw       r0, 0x3348(r13)

.loc_0x184:
  lwz       r0, 0x3348(r13)
  li        r4, 0
  lwz       r3, 0x334C(r13)
  xor       r0, r0, r4
  xor       r3, r3, r4
  or.       r0, r3, r0
  bne+      .loc_0x110
  stw       r4, 0x3340(r13)
  li        r0, 0x1
  b         .loc_0x1B0

.loc_0x1AC:
  li        r0, 0

.loc_0x1B0:
  cmpwi     r0, 0
  beq-      .loc_0x1C0
  li        r0, 0
  stw       r0, 0x3314(r13)

.loc_0x1C0:
  lwz       r0, 0x3324(r13)
  cmplwi    r0, 0
  beq-      .loc_0x1E4
  addi      r3, r1, 0x18
  bl        -0xB210
  lwz       r12, 0x3324(r13)
  lwz       r3, 0x3310(r13)
  mtlr      r12
  blrl      

.loc_0x1E4:
  addi      r3, r13, 0x3318
  bl        -0x5BBC
  addi      r3, r1, 0x18
  bl        -0xB230
  mr        r3, r30
  bl        -0xB400

.loc_0x1FC:
  lmw       r27, 0x2E4(r1)
  lwz       r0, 0x2FC(r1)
  addi      r1, r1, 0x2F8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void VISetPreRetraceCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020268C
 * Size:	000044
 */
void VISetPostRetraceCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r31, 0x3324(r13)
  bl        -0x972C
  stw       r30, 0x3324(r13)
  bl        -0x970C
  lwz       r0, 0x1C(r1)
  mr        r3, r31
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	802026D0
 * Size:	000068
 */
void getTiming(void)
{
/*
.loc_0x0:
  cmplwi    r3, 0x9
  lis       r4, 0x802F
  subi      r5, r4, 0x7620
  bgt-      .loc_0x60
  lis       r4, 0x802F
  subi      r4, r4, 0x74E0
  rlwinm    r0,r3,2,0,29
  lwzx      r0, r4, r0
  mtctr     r0
  bctr      
  mr        r3, r5
  blr       
  addi      r3, r5, 0x26
  blr       
  addi      r3, r5, 0x4C
  blr       
  addi      r3, r5, 0x72
  blr       
  addi      r3, r5, 0x98
  blr       
  addi      r3, r5, 0xBE
  blr       
  addi      r3, r5, 0xE4
  blr       

.loc_0x60:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	80202738
 * Size:	0001E8
 */
void __VIInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  rlwinm    r31,r3,30,2,31
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  addi      r29, r3, 0
  lis       r3, 0x8000
  stw       r31, 0xCC(r3)
  addi      r3, r29, 0
  rlwinm    r30,r29,0,30,30
  bl        -0x98
  lis       r4, 0xCC00
  li        r0, 0x2
  addi      r5, r4, 0x2000
  sthu      r0, 0x2(r5)
  li        r0, 0
  stw       r0, 0x1C(r1)
  lwz       r0, 0x1C(r1)
  cmplwi    r0, 0x3E8
  bge-      .loc_0x74
  b         .loc_0x68

.loc_0x5C:
  lwz       r4, 0x1C(r1)
  addi      r0, r4, 0x8
  stw       r0, 0x1C(r1)

.loc_0x68:
  lwz       r0, 0x1C(r1)
  cmplwi    r0, 0x3E8
  blt+      .loc_0x5C

.loc_0x74:
  li        r0, 0
  sth       r0, 0x0(r5)
  lis       r12, 0xCC00
  li        r8, 0x2828
  lhz       r6, 0x1A(r3)
  li        r7, 0x1
  cmpwi     r29, 0x2
  sth       r6, 0x2006(r12)
  li        r6, 0x1001
  addi      r4, r12, 0x2000
  lbz       r9, 0x1D(r3)
  lbz       r10, 0x1E(r3)
  rlwimi    r10,r9,8,16,23
  sth       r10, 0x2004(r12)
  lbz       r9, 0x1F(r3)
  lbz       r10, 0x1C(r3)
  rlwinm    r9,r9,7,0,24
  or        r9, r10, r9
  sth       r9, 0x200A(r12)
  lhz       r9, 0x20(r3)
  rlwinm    r9,r9,1,16,30
  sth       r9, 0x2008(r12)
  lhz       r9, 0x2(r3)
  lbz       r11, 0x0(r3)
  rlwinm    r9,r9,1,0,30
  lhz       r10, 0x4(r3)
  subi      r9, r9, 0x2
  sth       r11, 0x2000(r12)
  add       r9, r10, r9
  sth       r9, 0x200E(r12)
  lhz       r9, 0x8(r3)
  addi      r9, r9, 0x2
  sth       r9, 0x200C(r12)
  lhz       r9, 0x2(r3)
  lhz       r10, 0x6(r3)
  rlwinm    r9,r9,1,0,30
  subi      r9, r9, 0x2
  add       r9, r10, r9
  sth       r9, 0x2012(r12)
  lhz       r9, 0xA(r3)
  addi      r9, r9, 0x2
  sth       r9, 0x2010(r12)
  lhz       r9, 0x10(r3)
  lbz       r10, 0xC(r3)
  rlwinm    r9,r9,5,0,26
  or        r9, r10, r9
  sth       r9, 0x2016(r12)
  lhz       r9, 0x14(r3)
  lbz       r10, 0xE(r3)
  rlwinm    r9,r9,5,0,26
  or        r9, r10, r9
  sth       r9, 0x2014(r12)
  lhz       r9, 0x12(r3)
  lbz       r10, 0xD(r3)
  rlwinm    r9,r9,5,0,26
  or        r9, r10, r9
  sth       r9, 0x201A(r12)
  lhz       r9, 0x16(r3)
  lbz       r10, 0xF(r3)
  rlwinm    r9,r9,5,0,26
  or        r9, r10, r9
  sth       r9, 0x2018(r12)
  sth       r8, 0x2048(r12)
  sth       r7, 0x2036(r12)
  sth       r6, 0x2034(r12)
  lhz       r6, 0x18(r3)
  lhz       r3, 0x1A(r3)
  srawi     r6, r6, 0x1
  addi      r3, r3, 0x1
  addze     r6, r6
  sth       r3, 0x2032(r12)
  addi      r6, r6, 0x1
  ori       r3, r6, 0x1000
  sth       r3, 0x2030(r12)
  beq-      .loc_0x1BC
  rlwinm    r3,r30,2,0,29
  ori       r6, r3, 0x1
  rlwinm    r3,r31,8,0,23
  or        r3, r6, r3
  sth       r3, 0x0(r5)
  sth       r0, 0x6C(r4)
  b         .loc_0x1CC

.loc_0x1BC:
  rlwinm    r0,r31,8,0,23
  ori       r0, r0, 0x5
  sth       r0, 0x0(r5)
  sth       r7, 0x6C(r4)

.loc_0x1CC:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000160
 */
void AdjustPosition(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void ImportAdjustingValues(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80202920
 * Size:	000438
 */
void VIInit(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xCC00
  stw       r0, 0x4(r1)
  li        r0, 0x1
  lis       r4, 0x803D
  stwu      r1, -0x20(r1)
  stmw      r27, 0xC(r1)
  addi      r28, r3, 0x2000
  lis       r3, 0x802F
  addi      r30, r4, 0x3268
  subi      r31, r3, 0x7620
  stw       r0, 0x3328(r13)
  lhzu      r0, 0x2(r28)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x44
  li        r3, 0
  bl        -0x228

.loc_0x44:
  li        r29, 0
  stw       r29, 0x3310(r13)
  lis       r3, 0xCC00
  addi      r3, r3, 0x2000
  stw       r29, 0x333C(r13)
  addi      r4, r31, 0x11A
  li        r27, 0x280
  stw       r29, 0x3338(r13)
  stw       r29, 0x334C(r13)
  stw       r29, 0x3348(r13)
  stw       r29, 0x3330(r13)
  stw       r29, 0x3340(r13)
  stw       r29, 0x3314(r13)
  lhz       r0, 0x10E(r31)
  lhz       r5, 0x10C(r31)
  rlwinm    r0,r0,10,16,21
  or        r0, r5, r0
  sth       r0, 0x4E(r3)
  lhz       r5, 0x10E(r31)
  lhz       r0, 0x110(r31)
  srawi     r5, r5, 0x6
  rlwinm    r0,r0,4,0,27
  or        r0, r5, r0
  sth       r0, 0x4C(r3)
  lhz       r0, 0x114(r31)
  lhz       r5, 0x112(r31)
  rlwinm    r0,r0,10,16,21
  or        r0, r5, r0
  sth       r0, 0x52(r3)
  lhz       r5, 0x114(r31)
  lhz       r0, 0x116(r31)
  srawi     r5, r5, 0x6
  rlwinm    r0,r0,4,0,27
  or        r0, r5, r0
  sth       r0, 0x50(r3)
  lhz       r0, 0x11A(r31)
  lhz       r5, 0x118(r31)
  rlwinm    r0,r0,10,16,21
  or        r0, r5, r0
  sth       r0, 0x56(r3)
  lhz       r4, 0x0(r4)
  lhz       r0, 0x11C(r31)
  srawi     r4, r4, 0x6
  rlwinm    r0,r0,4,0,27
  or        r0, r4, r0
  sth       r0, 0x54(r3)
  lhz       r0, 0x120(r31)
  lhz       r4, 0x11E(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x5A(r3)
  lhz       r0, 0x124(r31)
  lhz       r4, 0x122(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x58(r3)
  lhz       r0, 0x128(r31)
  lhz       r4, 0x126(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x5E(r3)
  lhz       r0, 0x12C(r31)
  lhz       r4, 0x12A(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x5C(r3)
  lhz       r0, 0x130(r31)
  lhz       r4, 0x12E(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x62(r3)
  lhz       r0, 0x134(r31)
  lhz       r4, 0x132(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x60(r3)
  lhz       r0, 0x138(r31)
  lhz       r4, 0x136(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x66(r3)
  lhz       r0, 0x13C(r31)
  lhz       r4, 0x13A(r31)
  rlwinm    r0,r0,8,0,23
  or        r0, r4, r0
  sth       r0, 0x64(r3)
  sth       r27, 0x70(r3)
  bl        -0x8178
  lbz       r0, 0x10(r3)
  li        r3, 0
  extsb     r0, r0
  sth       r29, 0x332E(r13)
  sth       r0, 0x332C(r13)
  bl        -0x7DD0
  sth       r27, 0xF4(r30)
  li        r0, 0x1E0
  addi      r3, r30, 0xF6
  sth       r0, 0xF6(r30)
  addi      r4, r30, 0xF2
  lhz       r0, 0xF4(r30)
  subfic    r0, r0, 0x2D0
  srawi     r0, r0, 0x1
  addze     r0, r0
  sth       r0, 0xF0(r30)
  lhz       r0, 0xF6(r30)
  subfic    r0, r0, 0x1E0
  srawi     r0, r0, 0x1
  addze     r0, r0
  sth       r0, 0xF2(r30)
  lhz       r0, 0xF4(r30)
  lha       r6, 0xF0(r30)
  lha       r5, 0x332C(r13)
  subfic    r0, r0, 0x2D0
  add       r5, r6, r5
  cmpw      r5, r0
  ble-      .loc_0x218
  b         .loc_0x22C

.loc_0x218:
  cmpwi     r5, 0
  bge-      .loc_0x224
  b         .loc_0x228

.loc_0x224:
  mr        r29, r5

.loc_0x228:
  mr        r0, r29

.loc_0x22C:
  sth       r0, 0xF8(r30)
  addi      r6, r30, 0x110
  lwz       r0, 0x110(r30)
  cmpwi     r0, 0
  bne-      .loc_0x248
  li        r8, 0x2
  b         .loc_0x24C

.loc_0x248:
  li        r8, 0x1

.loc_0x24C:
  lhz       r0, 0x0(r4)
  lha       r10, 0x332E(r13)
  extsh     r5, r0
  rlwinm    r9,r0,0,31,31
  add       r0, r5, r10
  cmpw      r0, r9
  ble-      .loc_0x26C
  b         .loc_0x270

.loc_0x26C:
  mr        r0, r9

.loc_0x270:
  sth       r0, 0xFA(r30)
  subfic    r11, r9, 0x1E0
  lhz       r12, 0x0(r3)
  lha       r7, 0x0(r4)
  extsh     r0, r12
  add       r5, r0, r10
  add       r5, r7, r5
  sub.      r0, r5, r11
  ble-      .loc_0x29C
  sub       r5, r5, r11
  b         .loc_0x2A0

.loc_0x29C:
  li        r5, 0

.loc_0x2A0:
  add       r7, r7, r10
  sub.      r0, r7, r9
  bge-      .loc_0x2B4
  sub       r0, r7, r9
  b         .loc_0x2B8

.loc_0x2B4:
  li        r0, 0

.loc_0x2B8:
  add       r0, r12, r0
  sub       r0, r0, r5
  sth       r0, 0xFC(r30)
  lha       r0, 0x0(r4)
  add       r5, r0, r10
  sub.      r0, r5, r9
  bge-      .loc_0x2DC
  sub       r0, r5, r9
  b         .loc_0x2E0

.loc_0x2DC:
  li        r0, 0

.loc_0x2E0:
  divw      r7, r0, r8
  addi      r5, r30, 0x108
  lhz       r0, 0x108(r30)
  sub       r0, r0, r7
  sth       r0, 0xFE(r30)
  lha       r0, 0x0(r3)
  lha       r7, 0x0(r4)
  add       r3, r0, r10
  add       r3, r7, r3
  sub.      r0, r3, r11
  ble-      .loc_0x314
  sub       r4, r3, r11
  b         .loc_0x318

.loc_0x314:
  li        r4, 0

.loc_0x318:
  add       r3, r7, r10
  sub.      r0, r3, r9
  bge-      .loc_0x32C
  sub       r0, r3, r9
  b         .loc_0x330

.loc_0x32C:
  li        r0, 0

.loc_0x330:
  divw      r0, r0, r8
  lhz       r3, 0x10C(r30)
  add       r0, r3, r0
  divw      r4, r4, r8
  sub       r0, r0, r4
  sth       r0, 0x100(r30)
  li        r3, 0x280
  li        r0, 0x1E0
  sth       r3, 0x102(r30)
  li        r4, 0
  addi      r9, r30, 0x114
  sth       r0, 0x104(r30)
  sth       r4, 0x106(r30)
  sth       r4, 0x0(r5)
  sth       r3, 0x10A(r30)
  sth       r0, 0x10C(r30)
  stw       r4, 0x0(r6)
  lhz       r27, 0x0(r28)
  rlwinm    r0,r27,30,31,31
  stw       r0, 0x114(r30)
  rlwinm    r0,r27,24,30,31
  stw       r0, 0x118(r30)
  lwz       r0, 0x118(r30)
  cmplwi    r0, 0x3
  bne-      .loc_0x398
  b         .loc_0x39C

.loc_0x398:
  mr        r4, r0

.loc_0x39C:
  lwz       r0, 0x0(r9)
  rlwinm    r3,r4,2,0,29
  add       r3, r3, r0
  bl        -0x5F8
  stw       r3, 0x144(r30)
  li        r4, 0x28
  li        r28, 0
  sth       r27, 0x2(r30)
  li        r0, 0x1
  addi      r3, r13, 0x3318
  stb       r4, 0x11C(r30)
  stb       r4, 0x11D(r30)
  stb       r4, 0x11E(r30)
  stb       r28, 0x12C(r30)
  stw       r0, 0x130(r30)
  stw       r28, 0x134(r30)
  bl        -0x7228
  lis       r3, 0xCC00
  lhz       r0, 0x2030(r3)
  addi      r4, r3, 0x2000
  addi      r5, r3, 0x2000
  rlwinm    r0,r0,0,17,31
  sth       r0, 0x30(r4)
  lis       r3, 0x8020
  addi      r4, r3, 0x247C
  lhz       r0, 0x34(r5)
  li        r3, 0x18
  rlwinm    r0,r0,0,17,31
  sth       r0, 0x34(r5)
  stw       r28, 0x3320(r13)
  stw       r28, 0x3324(r13)
  bl        -0x9D70
  li        r3, 0x80
  bl        -0x999C
  lmw       r27, 0xC(r1)
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80202D58
 * Size:	000054
 */
void VIWaitForRetrace(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  stw       r30, 0x8(r1)
  bl        -0x9DF0
  lwz       r30, 0x3310(r13)
  mr        r31, r3

.loc_0x20:
  addi      r3, r13, 0x3318
  bl        -0x63C0
  lwz       r0, 0x3310(r13)
  cmplw     r30, r0
  beq+      .loc_0x20
  mr        r3, r31
  bl        -0x9DEC
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  lwz       r30, 0x8(r1)
  mtlr      r0
  addi      r1, r1, 0x10
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void setInterruptRegs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void setPicConfig(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void setBBIntervalRegs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void setScalingRegs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void calcFbbs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80202DAC
 * Size:	0002D4
 */
void setFbbRegs(void)
{
/*
.loc_0x0:
  stwu      r1, -0x48(r1)
  lis       r9, 0x803D
  addi      r9, r9, 0x3268
  stw       r31, 0x44(r1)
  lbz       r8, 0x2C(r3)
  lhz       r0, 0xE(r3)
  rlwinm    r31,r8,5,0,26
  lhz       r8, 0x16(r3)
  mullw     r0, r31, r0
  lwz       r11, 0x20(r3)
  lwz       r10, 0x30(r3)
  lhz       r12, 0xA(r3)
  rlwinm    r8,r8,1,0,26
  add       r0, r8, r0
  add       r0, r10, r0
  cmpwi     r11, 0
  stw       r0, 0x0(r4)
  bne-      .loc_0x50
  lwz       r8, 0x0(r4)
  b         .loc_0x58

.loc_0x50:
  lwz       r0, 0x0(r4)
  add       r8, r0, r31

.loc_0x58:
  srawi     r0, r12, 0x1
  stw       r8, 0x0(r5)
  addze     r0, r0
  rlwinm    r0,r0,1,0,30
  subc      r0, r12, r0
  cmpwi     r0, 0x1
  bne-      .loc_0x84
  lwz       r8, 0x0(r4)
  lwz       r0, 0x0(r5)
  stw       r0, 0x0(r4)
  stw       r8, 0x0(r5)

.loc_0x84:
  lwz       r0, 0x0(r4)
  rlwinm    r0,r0,0,2,31
  stw       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm    r0,r0,0,2,31
  stw       r0, 0x0(r5)
  lwz       r0, 0x44(r3)
  cmpwi     r0, 0
  beq-      .loc_0x134
  lbz       r8, 0x2C(r3)
  lhz       r0, 0xE(r3)
  rlwinm    r31,r8,5,0,26
  lhz       r8, 0x16(r3)
  mullw     r0, r31, r0
  lwz       r11, 0x20(r3)
  lwz       r10, 0x48(r3)
  lhz       r12, 0xA(r3)
  rlwinm    r8,r8,1,0,26
  add       r0, r8, r0
  add       r0, r10, r0
  cmpwi     r11, 0
  stw       r0, 0x0(r6)
  bne-      .loc_0xE8
  lwz       r8, 0x0(r6)
  b         .loc_0xF0

.loc_0xE8:
  lwz       r0, 0x0(r6)
  add       r8, r0, r31

.loc_0xF0:
  srawi     r0, r12, 0x1
  stw       r8, 0x0(r7)
  addze     r0, r0
  rlwinm    r0,r0,1,0,30
  subc      r0, r12, r0
  cmpwi     r0, 0x1
  bne-      .loc_0x11C
  lwz       r8, 0x0(r6)
  lwz       r0, 0x0(r7)
  stw       r0, 0x0(r6)
  stw       r8, 0x0(r7)

.loc_0x11C:
  lwz       r0, 0x0(r6)
  rlwinm    r0,r0,0,2,31
  stw       r0, 0x0(r6)
  lwz       r0, 0x0(r7)
  rlwinm    r0,r0,0,2,31
  stw       r0, 0x0(r7)

.loc_0x134:
  lwz       r0, 0x0(r4)
  lis       r8, 0x100
  cmplw     r0, r8
  bge-      .loc_0x170
  lwz       r0, 0x0(r5)
  cmplw     r0, r8
  bge-      .loc_0x170
  lwz       r0, 0x0(r6)
  cmplw     r0, r8
  bge-      .loc_0x170
  lwz       r0, 0x0(r7)
  cmplw     r0, r8
  bge-      .loc_0x170
  li        r10, 0
  b         .loc_0x174

.loc_0x170:
  li        r10, 0x1

.loc_0x174:
  cmplwi    r10, 0
  beq-      .loc_0x1AC
  lwz       r0, 0x0(r4)
  rlwinm    r0,r0,27,5,31
  stw       r0, 0x0(r4)
  lwz       r0, 0x0(r5)
  rlwinm    r0,r0,27,5,31
  stw       r0, 0x0(r5)
  lwz       r0, 0x0(r6)
  rlwinm    r0,r0,27,5,31
  stw       r0, 0x0(r6)
  lwz       r0, 0x0(r7)
  rlwinm    r0,r0,27,5,31
  stw       r0, 0x0(r7)

.loc_0x1AC:
  lwz       r0, 0x0(r4)
  rlwinm    r11,r10,12,0,19
  lis       r8, 0x1
  sth       r0, 0x1E(r9)
  lis       r0, 0x2
  lwz       r10, 0x3338(r13)
  lwz       r12, 0x333C(r13)
  or        r10, r10, r8
  stw       r12, 0x333C(r13)
  stw       r10, 0x3338(r13)
  lwz       r10, 0x0(r4)
  lbz       r4, 0x3C(r3)
  rlwinm    r10,r10,16,16,31
  rlwinm    r4,r4,8,0,23
  or        r4, r10, r4
  or        r4, r11, r4
  sth       r4, 0x1C(r9)
  lwz       r4, 0x3338(r13)
  lwz       r10, 0x333C(r13)
  or        r0, r4, r0
  stw       r10, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x0(r5)
  sth       r0, 0x26(r9)
  lwz       r0, 0x3338(r13)
  lwz       r4, 0x333C(r13)
  ori       r0, r0, 0x1000
  stw       r4, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x0(r5)
  rlwinm    r0,r0,16,16,31
  sth       r0, 0x24(r9)
  lwz       r0, 0x3338(r13)
  lwz       r4, 0x333C(r13)
  ori       r0, r0, 0x2000
  stw       r4, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x44(r3)
  cmpwi     r0, 0
  beq-      .loc_0x2C8
  lwz       r3, 0x0(r6)
  subi      r0, r8, 0x8000
  sth       r3, 0x22(r9)
  lwz       r3, 0x3338(r13)
  lwz       r4, 0x333C(r13)
  ori       r3, r3, 0x4000
  stw       r4, 0x333C(r13)
  stw       r3, 0x3338(r13)
  lwz       r3, 0x0(r6)
  rlwinm    r3,r3,16,16,31
  sth       r3, 0x20(r9)
  lwz       r3, 0x3338(r13)
  lwz       r4, 0x333C(r13)
  or        r0, r3, r0
  stw       r4, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x0(r7)
  sth       r0, 0x2A(r9)
  lwz       r0, 0x3338(r13)
  lwz       r3, 0x333C(r13)
  ori       r0, r0, 0x400
  stw       r3, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x0(r7)
  rlwinm    r0,r0,16,16,31
  sth       r0, 0x28(r9)
  lwz       r0, 0x3338(r13)
  lwz       r3, 0x333C(r13)
  ori       r0, r0, 0x800
  stw       r3, 0x333C(r13)
  stw       r0, 0x3338(r13)

.loc_0x2C8:
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void setHorizontalRegs(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203080
 * Size:	0001A0
 */
void setVerticalRegs(void)
{
/*
.loc_0x0:
  stwu      r1, -0x28(r1)
  rlwinm    r0,r5,0,24,31
  lis       r11, 0x803D
  stw       r31, 0x24(r1)
  cmplwi    r0, 0xA
  lwz       r31, 0x30(r1)
  addi      r11, r11, 0x3268
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  blt-      .loc_0x34
  li        r12, 0x1
  li        r29, 0x2
  b         .loc_0x3C

.loc_0x34:
  li        r12, 0x2
  li        r29, 0x1

.loc_0x3C:
  rlwinm    r30,r3,0,16,31
  srawi     r0, r30, 0x1
  addze     r0, r0
  rlwinm    r0,r0,1,0,30
  subc.     r0, r30, r0
  bne-      .loc_0x8C
  rlwinm    r3,r12,0,16,31
  rlwinm    r0,r6,0,16,31
  mullw     r0, r3, r0
  rlwinm    r3,r4,0,16,31
  sub       r0, r0, r3
  rlwinm    r3,r29,0,16,31
  mullw     r29, r3, r30
  sub       r0, r0, r30
  mullw     r30, r3, r0
  add       r0, r7, r29
  add       r6, r9, r30
  add       r3, r8, r29
  add       r7, r10, r30
  b         .loc_0xC0

.loc_0x8C:
  rlwinm    r3,r12,0,16,31
  rlwinm    r0,r6,0,16,31
  mullw     r0, r3, r0
  rlwinm    r3,r4,0,16,31
  sub       r0, r0, r3
  rlwinm    r3,r29,0,16,31
  mullw     r29, r3, r30
  sub       r0, r0, r30
  mullw     r30, r3, r0
  add       r0, r8, r29
  add       r6, r10, r30
  add       r3, r7, r29
  add       r7, r9, r30

.loc_0xC0:
  rlwinm    r8,r4,0,16,31
  rlwinm    r4,r12,0,16,31
  divw      r4, r8, r4
  cmpwi     r31, 0
  rlwinm    r4,r4,0,16,31
  beq-      .loc_0xF4
  rlwinm    r4,r4,1,0,30
  subi      r4, r4, 0x2
  add       r0, r0, r4
  add       r3, r3, r4
  li        r4, 0
  addi      r6, r6, 0x2
  addi      r7, r7, 0x2

.loc_0xF4:
  rlwinm    r5,r5,0,24,31
  rlwinm    r4,r4,4,12,27
  or        r4, r5, r4
  sth       r4, 0x0(r11)
  lis       r4, 0x8000
  lis       r9, 0x100
  lwz       r5, 0x3338(r13)
  lis       r8, 0x200
  lwz       r10, 0x333C(r13)
  or        r4, r5, r4
  lis       r5, 0x40
  stw       r10, 0x333C(r13)
  stw       r4, 0x3338(r13)
  lis       r4, 0x80
  sth       r0, 0xE(r11)
  lwz       r0, 0x3338(r13)
  lwz       r10, 0x333C(r13)
  or        r0, r0, r9
  stw       r10, 0x333C(r13)
  stw       r0, 0x3338(r13)
  sth       r6, 0xC(r11)
  lwz       r0, 0x3338(r13)
  lwz       r6, 0x333C(r13)
  or        r0, r0, r8
  stw       r6, 0x333C(r13)
  stw       r0, 0x3338(r13)
  sth       r3, 0x12(r11)
  lwz       r0, 0x3338(r13)
  lwz       r3, 0x333C(r13)
  or        r0, r0, r5
  stw       r3, 0x333C(r13)
  stw       r0, 0x3338(r13)
  sth       r7, 0x10(r11)
  lwz       r0, 0x3338(r13)
  lwz       r3, 0x333C(r13)
  or        r0, r0, r4
  stw       r3, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	80203220
 * Size:	00069C
 */
void VIConfigure(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stmw      r15, 0x3C(r1)
  addi      r31, r3, 0
  addi      r29, r4, 0x3268
  bl        -0xA2C0
  lwz       r4, 0x0(r31)
  addi      r28, r29, 0x114
  lwz       r0, 0x114(r29)
  addi      r15, r3, 0
  rlwinm    r4,r4,0,30,31
  cmplw     r0, r4
  beq-      .loc_0x48
  li        r0, 0x1
  stw       r0, 0x3330(r13)
  stw       r4, 0x0(r28)

.loc_0x48:
  bl        0x91C
  addi      r24, r29, 0x118
  stw       r3, 0x118(r29)
  lhz       r0, 0xA(r31)
  sth       r0, 0xF0(r29)
  lwz       r0, 0x0(r28)
  cmplwi    r0, 0x1
  bne-      .loc_0x74
  lhz       r0, 0xC(r31)
  rlwinm    r0,r0,1,16,30
  b         .loc_0x78

.loc_0x74:
  lhz       r0, 0xC(r31)

.loc_0x78:
  sth       r0, 0xF2(r29)
  addi      r22, r29, 0xF2
  addi      r23, r29, 0xF4
  lhz       r0, 0xE(r31)
  addi      r27, r29, 0x102
  addi      r25, r29, 0x110
  sth       r0, 0xF4(r29)
  li        r0, 0
  addi      r17, r29, 0x10A
  lhz       r3, 0x4(r31)
  addi      r26, r29, 0x10C
  addi      r16, r29, 0x106
  sth       r3, 0x102(r29)
  addi      r18, r29, 0x108
  lhz       r3, 0x8(r31)
  sth       r3, 0x104(r29)
  lwz       r3, 0x14(r31)
  stw       r3, 0x110(r29)
  lhz       r3, 0x102(r29)
  sth       r3, 0x10A(r29)
  lhz       r3, 0x104(r29)
  sth       r3, 0x10C(r29)
  sth       r0, 0x106(r29)
  sth       r0, 0x108(r29)
  lwz       r0, 0x0(r28)
  cmplwi    r0, 0x2
  bne-      .loc_0xEC
  lhz       r0, 0x0(r26)
  b         .loc_0x108

.loc_0xEC:
  lwz       r0, 0x0(r25)
  cmpwi     r0, 0
  bne-      .loc_0x104
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,1,16,30
  b         .loc_0x108

.loc_0x104:
  lhz       r0, 0x0(r26)

.loc_0x108:
  addi      r21, r29, 0xF6
  sth       r0, 0xF6(r29)
  lwz       r3, 0x0(r24)
  lwz       r0, 0x0(r28)
  rlwinm    r3,r3,2,0,29
  add       r3, r3, r0
  bl        -0xC70
  mr        r30, r3
  stw       r30, 0x144(r29)
  lhz       r0, 0x0(r23)
  lha       r4, 0xF0(r29)
  lha       r3, 0x332C(r13)
  subfic    r0, r0, 0x2D0
  lhz       r6, 0x2(r30)
  add       r3, r4, r3
  cmpw      r3, r0
  ble-      .loc_0x150
  b         .loc_0x160

.loc_0x150:
  cmpwi     r3, 0
  bge-      .loc_0x15C
  li        r3, 0

.loc_0x15C:
  mr        r0, r3

.loc_0x160:
  sth       r0, 0xF8(r29)
  addi      r3, r29, 0xF8
  lwz       r0, 0x0(r25)
  cmpwi     r0, 0
  bne-      .loc_0x17C
  li        r0, 0x2
  b         .loc_0x180

.loc_0x17C:
  li        r0, 0x1

.loc_0x180:
  lhz       r4, 0x0(r22)
  lha       r5, 0x332E(r13)
  extsh     r7, r4
  rlwinm    r4,r4,0,31,31
  add       r7, r7, r5
  cmpw      r7, r4
  ble-      .loc_0x1A0
  b         .loc_0x1A4

.loc_0x1A0:
  mr        r7, r4

.loc_0x1A4:
  sth       r7, 0xFA(r29)
  extsh     r6, r6
  rlwinm    r6,r6,1,0,30
  lhz       r7, 0x0(r21)
  sub       r6, r6, r4
  lha       r10, 0x0(r22)
  addi      r19, r29, 0xFA
  extsh     r8, r7
  add       r9, r8, r5
  add       r9, r10, r9
  sub.      r8, r9, r6
  ble-      .loc_0x1DC
  sub       r9, r9, r6
  b         .loc_0x1E0

.loc_0x1DC:
  li        r9, 0

.loc_0x1E0:
  add       r10, r10, r5
  sub.      r8, r10, r4
  bge-      .loc_0x1F4
  sub       r8, r10, r4
  b         .loc_0x1F8

.loc_0x1F4:
  li        r8, 0

.loc_0x1F8:
  add       r7, r7, r8
  sub       r7, r7, r9
  addi      r20, r29, 0xFC
  sth       r7, 0xFC(r29)
  lha       r7, 0x0(r22)
  add       r8, r7, r5
  sub.      r7, r8, r4
  bge-      .loc_0x220
  sub       r7, r8, r4
  b         .loc_0x224

.loc_0x220:
  li        r7, 0

.loc_0x224:
  divw      r8, r7, r0
  lhz       r7, 0x0(r18)
  sub       r7, r7, r8
  sth       r7, 0xFE(r29)
  lha       r7, 0x0(r21)
  lha       r9, 0x0(r22)
  add       r8, r7, r5
  add       r8, r9, r8
  sub.      r7, r8, r6
  ble-      .loc_0x254
  sub       r6, r8, r6
  b         .loc_0x258

.loc_0x254:
  li        r6, 0

.loc_0x258:
  add       r7, r9, r5
  sub.      r5, r7, r4
  bge-      .loc_0x26C
  sub       r4, r7, r4
  b         .loc_0x270

.loc_0x26C:
  li        r4, 0

.loc_0x270:
  divw      r4, r4, r0
  lhz       r5, 0x0(r26)
  divw      r6, r6, r0
  add       r0, r5, r4
  sub       r0, r0, r6
  sth       r0, 0x100(r29)
  lwz       r0, 0x3328(r13)
  cmplwi    r0, 0
  bne-      .loc_0x29C
  li        r0, 0x3
  stw       r0, 0x0(r24)

.loc_0x29C:
  lhz       r5, 0x18(r30)
  srawi     r4, r5, 0x1
  addze     r4, r4
  srawi     r0, r5, 0x1
  addze     r0, r0
  rlwinm    r0,r0,1,0,30
  subc      r0, r5, r0
  rlwinm.   r0,r0,0,16,31
  rlwinm    r4,r4,0,16,31
  beq-      .loc_0x2CC
  lhz       r5, 0x1A(r30)
  b         .loc_0x2D0

.loc_0x2CC:
  li        r5, 0

.loc_0x2D0:
  addi      r0, r5, 0x1
  sth       r0, 0x32(r29)
  addi      r0, r4, 0x1
  ori       r0, r0, 0x1000
  lwz       r5, 0x3338(r13)
  addi      r4, r29, 0x2
  lwz       r6, 0x333C(r13)
  ori       r5, r5, 0x40
  stw       r6, 0x333C(r13)
  stw       r5, 0x3338(r13)
  sth       r0, 0x30(r29)
  lwz       r0, 0x3338(r13)
  lwz       r5, 0x333C(r13)
  ori       r0, r0, 0x80
  stw       r5, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x0(r28)
  lhz       r5, 0x2(r29)
  cmplwi    r0, 0x2
  bne-      .loc_0x32C
  rlwinm    r0,r5,0,30,28
  ori       r6, r0, 0x4
  b         .loc_0x334

.loc_0x32C:
  rlwinm    r6,r5,0,30,28
  rlwimi    r6,r0,2,29,29

.loc_0x334:
  lwz       r5, 0x0(r24)
  rlwinm    r6,r6,0,24,21
  lis       r0, 0x4000
  rlwinm    r5,r5,8,0,23
  or        r5, r6, r5
  sth       r5, 0x0(r4)
  addi      r6, r29, 0x6C
  lwz       r4, 0x3338(r13)
  lwz       r5, 0x333C(r13)
  or        r0, r4, r0
  stw       r5, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lwz       r0, 0x0(r31)
  lhz       r4, 0x6C(r29)
  cmpwi     r0, 0x2
  beq-      .loc_0x37C
  rlwinm    r0,r4,0,0,30
  b         .loc_0x384

.loc_0x37C:
  rlwinm    r0,r4,0,0,30
  ori       r0, r0, 0x1

.loc_0x384:
  sth       r0, 0x0(r6)
  lwz       r4, 0x3338(r13)
  lwz       r0, 0x333C(r13)
  ori       r0, r0, 0x200
  stw       r0, 0x333C(r13)
  stw       r4, 0x3338(r13)
  lwz       r0, 0x134(r29)
  lhz       r4, 0x0(r23)
  cmpwi     r0, 0
  lhz       r5, 0x0(r17)
  beq-      .loc_0x3B8
  rlwinm    r0,r5,1,0,30
  b         .loc_0x3BC

.loc_0x3B8:
  mr        r0, r5

.loc_0x3BC:
  rlwinm    r8,r0,0,16,31
  cmplw     r8, r4
  bge-      .loc_0x414
  rlwinm    r6,r8,8,0,23
  subi      r0, r6, 0x1
  add       r0, r4, r0
  divwu     r0, r0, r4
  ori       r0, r0, 0x1000
  sth       r0, 0x4A(r29)
  lis       r0, 0x400
  lwz       r6, 0x3338(r13)
  lwz       r7, 0x333C(r13)
  or        r0, r7, r0
  stw       r0, 0x333C(r13)
  stw       r6, 0x3338(r13)
  sth       r8, 0x70(r29)
  lwz       r6, 0x3338(r13)
  lwz       r0, 0x333C(r13)
  ori       r0, r0, 0x80
  stw       r0, 0x333C(r13)
  stw       r6, 0x3338(r13)
  b         .loc_0x434

.loc_0x414:
  li        r0, 0x100
  sth       r0, 0x4A(r29)
  lis       r0, 0x400
  lwz       r6, 0x3338(r13)
  lwz       r7, 0x333C(r13)
  or        r0, r7, r0
  stw       r0, 0x333C(r13)
  stw       r6, 0x3338(r13)

.loc_0x434:
  lhz       r0, 0x0(r3)
  subfic    r12, r4, 0x2D0
  lhz       r6, 0x1A(r30)
  lis       r3, 0x1000
  lis       r8, 0x2000
  sth       r6, 0x6(r29)
  lis       r9, 0x400
  lis       r7, 0x800
  lwz       r10, 0x3338(r13)
  lis       r6, 0x10
  lis       r4, 0x20
  lwz       r11, 0x333C(r13)
  or        r10, r10, r3
  lis       r3, 0x4
  stw       r11, 0x333C(r13)
  stw       r10, 0x3338(r13)
  lbz       r10, 0x1D(r30)
  lbz       r11, 0x1E(r30)
  rlwimi    r11,r10,8,16,23
  sth       r11, 0x4(r29)
  lwz       r10, 0x3338(r13)
  lwz       r11, 0x333C(r13)
  or        r8, r10, r8
  stw       r11, 0x333C(r13)
  stw       r8, 0x3338(r13)
  lbz       r8, 0x1F(r30)
  lbz       r10, 0x1C(r30)
  add       r17, r8, r0
  lhz       r11, 0x20(r30)
  subi      r17, r17, 0x28
  rlwinm    r8,r17,7,16,24
  or        r8, r10, r8
  sth       r8, 0xA(r29)
  add       r8, r11, r0
  addi      r0, r8, 0x28
  lwz       r10, 0x3338(r13)
  sub       r0, r0, r12
  rlwinm    r8,r17,23,9,31
  lwz       r11, 0x333C(r13)
  rlwinm    r0,r0,1,0,30
  or        r9, r10, r9
  stw       r11, 0x333C(r13)
  or        r0, r8, r0
  stw       r9, 0x3338(r13)
  sth       r0, 0x8(r29)
  lwz       r0, 0x3338(r13)
  lwz       r8, 0x333C(r13)
  or        r0, r0, r7
  stw       r8, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lhz       r0, 0x10(r30)
  lbz       r7, 0xC(r30)
  rlwinm    r0,r0,5,0,26
  or        r0, r7, r0
  sth       r0, 0x16(r29)
  lwz       r0, 0x3338(r13)
  lwz       r7, 0x333C(r13)
  or        r0, r0, r6
  stw       r7, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lhz       r0, 0x14(r30)
  lbz       r6, 0xE(r30)
  rlwinm    r0,r0,5,0,26
  or        r0, r6, r0
  sth       r0, 0x14(r29)
  lwz       r0, 0x3338(r13)
  lwz       r6, 0x333C(r13)
  or        r0, r0, r4
  stw       r6, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lhz       r0, 0x12(r30)
  lbz       r4, 0xD(r30)
  rlwinm    r0,r0,5,0,26
  or        r0, r4, r0
  sth       r0, 0x1A(r29)
  lwz       r0, 0x3338(r13)
  lwz       r4, 0x333C(r13)
  or        r0, r0, r3
  stw       r4, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lhz       r0, 0x16(r30)
  lbz       r3, 0xF(r30)
  rlwinm    r0,r0,5,0,26
  or        r0, r3, r0
  sth       r0, 0x18(r29)
  lwz       r3, 0x3338(r13)
  lis       r0, 0x8
  addi      r6, r29, 0x11C
  lwz       r4, 0x333C(r13)
  or        r0, r3, r0
  stw       r4, 0x333C(r13)
  stw       r0, 0x3338(r13)
  lhz       r3, 0x0(r27)
  lwz       r4, 0x0(r25)
  addi      r0, r3, 0xF
  lhz       r3, 0x0(r16)
  srawi     r0, r0, 0x4
  addze     r0, r0
  cmpwi     r4, 0
  stb       r0, 0x11C(r29)
  bne-      .loc_0x5D0
  lbz       r4, 0x0(r6)
  b         .loc_0x5D8

.loc_0x5D0:
  lbz       r0, 0x0(r6)
  rlwinm    r4,r0,1,24,30

.loc_0x5D8:
  srawi     r0, r3, 0x4
  stb       r4, 0x11D(r29)
  addze     r0, r0
  rlwinm    r0,r0,4,0,27
  subc      r0, r3, r0
  stb       r0, 0x12C(r29)
  addi      r0, r5, 0xF
  lis       r3, 0x800
  lbz       r4, 0x12C(r29)
  add       r0, r4, r0
  srawi     r0, r0, 0x4
  addze     r0, r0
  stb       r0, 0x11E(r29)
  lbz       r0, 0x11E(r29)
  lbz       r4, 0x11D(r29)
  rlwimi    r4,r0,8,16,23
  sth       r4, 0x48(r29)
  lwz       r4, 0x3338(r13)
  lwz       r0, 0x3350(r13)
  lwz       r5, 0x333C(r13)
  cmplwi    r0, 0
  or        r0, r5, r3
  stw       r0, 0x333C(r13)
  stw       r4, 0x3338(r13)
  beq-      .loc_0x654
  addi      r3, r29, 0xF0
  addi      r4, r29, 0x124
  addi      r5, r29, 0x128
  addi      r6, r29, 0x13C
  addi      r7, r29, 0x140
  bl        -0xAC4

.loc_0x654:
  lwz       r0, 0x130(r29)
  stw       r0, 0x8(r1)
  lhz       r3, 0x0(r19)
  lhz       r4, 0x0(r20)
  lbz       r5, 0x0(r30)
  lhz       r6, 0x2(r30)
  lhz       r7, 0x4(r30)
  lhz       r8, 0x6(r30)
  lhz       r9, 0x8(r30)
  lhz       r10, 0xA(r30)
  bl        -0x81C
  mr        r3, r15
  bl        -0xA900
  lmw       r15, 0x3C(r1)
  lwz       r0, 0x84(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000384
 */
void VIConfigurePan(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802038BC
 * Size:	00011C
 */
void VIFlush(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  bl        -0xA950
  lwz       r7, 0x3340(r13)
  lis       r4, 0x803D
  lis       r5, 0x803D
  lwz       r6, 0x3330(r13)
  li        r0, 0
  addi      r29, r4, 0x32E0
  or        r6, r7, r6
  stw       r6, 0x3340(r13)
  addi      r31, r5, 0x3268
  addi      r30, r3, 0
  stw       r0, 0x3330(r13)
  lwz       r4, 0x3348(r13)
  lwz       r5, 0x334C(r13)
  lwz       r0, 0x3338(r13)
  lwz       r3, 0x333C(r13)
  or        r0, r4, r0
  or        r3, r5, r3
  stw       r3, 0x334C(r13)
  stw       r0, 0x3348(r13)
  b         .loc_0xDC

.loc_0x64:
  lwz       r3, 0x3338(r13)
  li        r5, 0x20
  lwz       r27, 0x333C(r13)
  addi      r4, r27, 0
  bl        0x119C4
  cntlzw    r4, r4
  cmpwi     r4, 0x20
  li        r0, -0x1
  and       r0, r27, r0
  bge-      .loc_0x90
  b         .loc_0x98

.loc_0x90:
  cntlzw    r3, r0
  addi      r4, r3, 0x20

.loc_0x98:
  rlwinm    r5,r4,1,0,30
  add       r3, r31, r5
  lhz       r0, 0x0(r3)
  add       r3, r29, r5
  subfic    r5, r4, 0x3F
  sth       r0, 0x0(r3)
  li        r3, 0
  li        r4, 0x1
  bl        0x1195C
  lwz       r0, 0x3338(r13)
  not       r5, r3
  not       r4, r4
  lwz       r3, 0x333C(r13)
  and       r0, r0, r5
  and       r3, r3, r4
  stw       r3, 0x333C(r13)
  stw       r0, 0x3338(r13)

.loc_0xDC:
  lwz       r0, 0x3338(r13)
  li        r3, 0
  lwz       r4, 0x333C(r13)
  xor       r0, r0, r3
  xor       r3, r4, r3
  or.       r0, r3, r0
  bne+      .loc_0x64
  li        r0, 0x1
  stw       r0, 0x3314(r13)
  mr        r3, r30
  bl        -0xAA1C
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	802039D8
 * Size:	00006C
 */
void VISetNextFrameBuffer(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0x3268
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  bl        -0xAA7C
  stw       r30, 0x120(r31)
  li        r0, 0x1
  addi      r30, r3, 0
  stw       r0, 0x3350(r13)
  addi      r3, r31, 0xF0
  addi      r4, r31, 0x124
  addi      r5, r31, 0x128
  addi      r6, r31, 0x13C
  addi      r7, r31, 0x140
  bl        -0xC74
  mr        r3, r30
  bl        -0xAA84
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void VISetNextRightFrameBuffer(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203A44
 * Size:	00007C
 */
void VISetBlack(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0x3268
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  bl        -0xAAE8
  stw       r30, 0x130(r31)
  mr        r30, r3
  lwz       r10, 0x144(r31)
  lwz       r0, 0x130(r31)
  stw       r0, 0x8(r1)
  lhz       r3, 0xFA(r31)
  lhz       r4, 0xF6(r31)
  lbz       r5, 0x0(r10)
  lhz       r6, 0x2(r10)
  lhz       r7, 0x4(r10)
  lhz       r8, 0x6(r10)
  lhz       r9, 0x8(r10)
  lhz       r10, 0xA(r10)
  bl        -0xA1C
  mr        r3, r30
  bl        -0xAB00
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
 * Size:	000100
 */
void VISet3D(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203AC0
 * Size:	000008
 */
void VIGetRetraceCount(void)
{
/*
.loc_0x0:
  lwz       r3, 0x3310(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void getCurrentHalfLine(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203AC8
 * Size:	0000BC
 */
void getCurrentFieldEvenOdd(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xCC00
  stw       r0, 0x4(r1)
  addi      r3, r3, 0x2000
  stwu      r1, -0x8(r1)
  lhz       r0, 0x6C(r3)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x2C
  li        r3, 0x2
  bl        -0x141C
  b         .loc_0x40

.loc_0x2C:
  lhz       r0, 0x2(r3)
  rlwinm    r3,r0,26,28,29
  rlwinm    r0,r0,30,31,31
  add       r3, r3, r0
  bl        -0x1434

.loc_0x40:
  lis       r4, 0xCC00
  lhz       r9, 0x18(r3)
  addi      r8, r4, 0x2000
  lhzu      r0, 0x2C(r8)
  lis       r3, 0x803D
  addi      r3, r3, 0x3358
  lwz       r5, 0x54(r3)
  rlwinm    r6,r0,0,21,31
  addi      r4, r4, 0x2000

.loc_0x64:
  lhz       r0, 0x0(r8)
  mr        r7, r6
  lhz       r3, 0x2E(r4)
  rlwinm    r6,r0,0,21,31
  cmplw     r7, r6
  rlwinm    r3,r3,0,21,31
  bne+      .loc_0x64
  lhz       r0, 0x1A(r5)
  subi      r3, r3, 0x1
  subi      r4, r6, 0x1
  divwu     r0, r3, r0
  rlwinm    r3,r4,1,0,30
  add       r0, r3, r0
  cmplw     r0, r9
  bge-      .loc_0xA8
  li        r3, 0x1
  b         .loc_0xAC

.loc_0xA8:
  li        r3, 0

.loc_0xAC:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void VIGetNextField(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void VIGetCurrentLine(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203B84
 * Size:	00000C
 */
void VIGetTvFormat(void)
{
/*
.loc_0x0:
  lis       r3, 0x8000
  lwz       r3, 0xCC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80203B90
 * Size:	00003C
 */
void VIGetDTVStatus(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0xAC24
  lis       r4, 0xCC00
  lhz       r0, 0x206E(r4)
  rlwinm    r31,r0,0,30,31
  bl        -0xAC0C
  lwz       r0, 0x14(r1)
  rlwinm    r3,r31,0,31,31
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
void __VISetAdjustingValues(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void __VIGetAdjustingValues(void)
{
	// UNUSED FUNCTION
}
