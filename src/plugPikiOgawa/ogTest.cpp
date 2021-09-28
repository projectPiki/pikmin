

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
 * Address:	8017D744
 * Size:	0002EC
 */
void zen::OgTestScreen::OgTestScreen()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stmw      r25, 0x3C(r1)
  addi      r31, r3, 0
  addi      r27, r4, 0x738C
  lis       r3, 0x8022
  addi      r28, r3, 0x737C
  lis       r4, 0x802D
  addi      r26, r4, 0x2468
  li        r29, 0
  addi      r3, r31, 0
  addi      r4, r13, 0x8E0
  stw       r27, 0x0(r31)
  stw       r28, 0x0(r31)
  stw       r29, 0x10(r31)
  stw       r29, 0xC(r31)
  stw       r29, 0x8(r31)
  bl        -0x1588BC
  lis       r3, 0x8023
  subi      r30, r3, 0x71E0
  stw       r30, 0x0(r31)
  addi      r3, r31, 0
  addi      r4, r13, 0x8E0
  bl        -0x13D06C
  lis       r3, 0x802D
  addi      r0, r3, 0x2700
  stw       r0, 0x0(r31)
  addi      r3, r31, 0x34
  bl        -0x13A5F8
  addi      r0, r26, 0x1C
  stw       r0, 0x4(r31)
  li        r3, 0x50
  bl        -0x1367C8
  mr.       r25, r3
  beq-      .loc_0xDC
  stw       r27, 0x0(r25)
  addi      r3, r25, 0
  addi      r4, r26, 0x2C
  stw       r28, 0x0(r25)
  stw       r29, 0x10(r25)
  stw       r29, 0xC(r25)
  stw       r29, 0x8(r25)
  bl        -0x158920
  stw       r30, 0x0(r25)
  addi      r3, r25, 0
  addi      r4, r26, 0x2C
  bl        -0x13D0C8
  lis       r3, 0x8023
  subi      r0, r3, 0x714C
  stw       r0, 0x0(r25)
  addi      r3, r25, 0
  li        r4, 0x1
  bl        -0x13CE6C

.loc_0xDC:
  stw       r25, 0x28(r31)
  li        r3, 0
  li        r0, 0xE
  stw       r3, 0x20(r31)
  addi      r4, r26, 0x3C
  li        r5, 0x1
  stw       r0, 0x24(r31)
  sth       r3, 0x37E(r31)
  sth       r3, 0x380(r31)
  sth       r3, 0x384(r31)
  sth       r3, 0x386(r31)
  sth       r3, 0x388(r31)
  sth       r3, 0x38A(r31)
  stb       r3, 0x38C(r31)
  stb       r3, 0x38D(r31)
  sth       r3, 0x37C(r31)
  lwz       r3, 0x2DEC(r13)
  bl        -0x13E75C
  addi      r25, r3, 0
  li        r3, 0x10
  bl        -0x13686C
  stw       r3, 0x30(r31)
  addi      r4, r25, 0
  li        r5, 0x15
  lwz       r3, 0x30(r31)
  li        r6, 0x2A
  bl        -0x155BD0
  lwz       r3, 0x2DEC(r13)
  li        r25, 0
  lfs       f0, -0x5108(r2)
  stfs      f0, 0x8(r3)
  lfs       f0, -0x5104(r2)
  stfs      f0, 0xC(r3)

.loc_0x160:
  addi      r3, r25, 0
  li        r4, -0x7B
  bl        0x28A0
  addi      r25, r25, 0x1
  cmpwi     r25, 0x64
  blt+      .loc_0x160
  lwz       r3, 0x2DEC(r13)
  lwz       r4, 0x194(r3)
  bl        -0x13E8A4
  li        r3, 0x10C
  bl        -0x1368C8
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x19C
  bl        0xF770

.loc_0x19C:
  stw       r25, 0x3A4(r31)
  lwz       r3, 0x2DEC(r13)
  lwz       r4, 0x194(r3)
  bl        -0x13E8CC
  li        r3, 0x58
  bl        -0x1368F0
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x1C4
  bl        0x4A14

.loc_0x1C4:
  stw       r25, 0x39C(r31)
  li        r3, 0x55C
  bl        -0x13690C
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x1E0
  bl        0x68C8

.loc_0x1E0:
  stw       r25, 0x390(r31)
  li        r3, 0xA8
  bl        -0x136928
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x1FC
  bl        0x3754

.loc_0x1FC:
  stw       r25, 0x394(r31)
  li        r3, 0x8
  bl        -0x136944
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x218
  bl        0x523C

.loc_0x218:
  stw       r25, 0x398(r31)
  li        r3, 0x30
  bl        -0x136960
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x234
  bl        0x5540

.loc_0x234:
  stw       r25, 0x3A0(r31)
  li        r3, 0x2F0
  bl        -0x13697C
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x250
  bl        0x1278C

.loc_0x250:
  stw       r25, 0x3B4(r31)
  li        r3, 0x18
  bl        -0x136998
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x26C
  bl        0x15BE8

.loc_0x26C:
  stw       r25, 0x3A8(r31)
  li        r3, 0x830
  bl        -0x1369B4
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x28C
  li        r4, 0
  bl        0x16838

.loc_0x28C:
  stw       r25, 0x3AC(r31)
  li        r3, 0x14
  bl        -0x1369D4
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x2A8
  bl        0x1AFA0

.loc_0x2A8:
  stw       r25, 0x3B0(r31)
  li        r3, 0x6C
  bl        -0x1369F0
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x2C8
  li        r4, 0
  bl        0x42908

.loc_0x2C8:
  stw       r25, 0x2C(r31)
  mr        r3, r31
  lfs       f0, -0x5100(r2)
  stfs      f0, 0x31B0(r13)
  lwz       r0, 0x5C(r1)
  lmw       r25, 0x3C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017DA30
 * Size:	0004DC
 */
void zen::OgTestScreen::modeSelectSub()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  mr        r31, r3
  lwz       r3, 0x28(r3)
  lwz       r0, 0x28(r3)
  rlwinm.   r0,r0,0,12,12
  beq-      .loc_0x38
  lha       r3, 0x37C(r31)
  cmpwi     r3, 0
  ble-      .loc_0x38
  subi      r0, r3, 0x1
  sth       r0, 0x37C(r31)

.loc_0x38:
  lwz       r3, 0x28(r31)
  lwz       r0, 0x28(r3)
  rlwinm.   r0,r0,0,10,10
  beq-      .loc_0x5C
  lha       r3, 0x37C(r31)
  cmpwi     r3, 0xA
  bge-      .loc_0x5C
  addi      r0, r3, 0x1
  sth       r0, 0x37C(r31)

.loc_0x5C:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x1
  bne-      .loc_0xC0
  lwz       r4, 0x2C(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x4(r4)
  and.      r0, r3, r0
  beq-      .loc_0x94
  lha       r3, 0x37E(r31)
  cmpwi     r3, 0x98
  bge-      .loc_0x94
  addi      r0, r3, 0x1
  sth       r0, 0x37E(r31)

.loc_0x94:
  lwz       r4, 0x2C(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x4(r4)
  and.      r0, r3, r0
  beq-      .loc_0xC0
  lha       r3, 0x37E(r31)
  cmpwi     r3, 0
  ble-      .loc_0xC0
  subi      r0, r3, 0x1
  sth       r0, 0x37E(r31)

.loc_0xC0:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x6
  bne-      .loc_0x124
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0xF8
  lha       r3, 0x380(r31)
  cmpwi     r3, 0x1E
  bge-      .loc_0xF8
  addi      r0, r3, 0x1
  sth       r0, 0x380(r31)

.loc_0xF8:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x124
  lha       r3, 0x380(r31)
  cmpwi     r3, 0
  ble-      .loc_0x124
  subi      r0, r3, 0x1
  sth       r0, 0x380(r31)

.loc_0x124:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x4
  bne-      .loc_0x188
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x15C
  lha       r3, 0x384(r31)
  cmpwi     r3, 0x9
  bge-      .loc_0x15C
  addi      r0, r3, 0x1
  sth       r0, 0x384(r31)

.loc_0x15C:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x188
  lha       r3, 0x384(r31)
  cmpwi     r3, 0
  ble-      .loc_0x188
  subi      r0, r3, 0x1
  sth       r0, 0x384(r31)

.loc_0x188:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x3
  bne-      .loc_0x1EC
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x1C0
  lha       r3, 0x386(r31)
  cmpwi     r3, 0x1
  bge-      .loc_0x1C0
  addi      r0, r3, 0x1
  sth       r0, 0x386(r31)

.loc_0x1C0:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x1EC
  lha       r3, 0x386(r31)
  cmpwi     r3, 0
  ble-      .loc_0x1EC
  subi      r0, r3, 0x1
  sth       r0, 0x386(r31)

.loc_0x1EC:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x2
  bne-      .loc_0x250
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x224
  lha       r3, 0x388(r31)
  cmpwi     r3, 0x7
  bge-      .loc_0x224
  addi      r0, r3, 0x1
  sth       r0, 0x388(r31)

.loc_0x224:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x250
  lha       r3, 0x388(r31)
  cmpwi     r3, 0
  ble-      .loc_0x250
  subi      r0, r3, 0x1
  sth       r0, 0x388(r31)

.loc_0x250:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x8
  bne-      .loc_0x29C
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x27C
  li        r0, 0x1
  stb       r0, 0x38C(r31)

.loc_0x27C:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x29C
  li        r0, 0
  stb       r0, 0x38C(r31)

.loc_0x29C:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0x5
  bne-      .loc_0x2E8
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x2C8
  li        r0, 0x1
  stb       r0, 0x38D(r31)

.loc_0x2C8:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x2E8
  li        r0, 0
  stb       r0, 0x38D(r31)

.loc_0x2E8:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0
  bne-      .loc_0x334
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x314
  li        r0, 0x1
  stb       r0, 0x38E(r31)

.loc_0x314:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x334
  li        r0, 0
  stb       r0, 0x38E(r31)

.loc_0x334:
  lha       r0, 0x37C(r31)
  cmpwi     r0, 0xC
  bne-      .loc_0x398
  lwz       r4, 0x28(r31)
  lis       r3, 0x10
  addi      r0, r3, 0x2
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x36C
  lha       r3, 0x38A(r31)
  cmpwi     r3, 0x5
  bge-      .loc_0x36C
  addi      r0, r3, 0x1
  sth       r0, 0x38A(r31)

.loc_0x36C:
  lwz       r4, 0x28(r31)
  lis       r3, 0x40
  addi      r0, r3, 0x1
  lwz       r3, 0x28(r4)
  and.      r0, r3, r0
  beq-      .loc_0x398
  lha       r3, 0x38A(r31)
  cmpwi     r3, 0
  ble-      .loc_0x398
  subi      r0, r3, 0x1
  sth       r0, 0x38A(r31)

.loc_0x398:
  lwz       r3, 0x28(r31)
  lwz       r0, 0x28(r3)
  rlwinm.   r0,r0,0,19,19
  beq-      .loc_0x4C8
  lha       r0, 0x37C(r31)
  cmplwi    r0, 0xB
  bgt-      .loc_0x4C8
  lis       r3, 0x802D
  addi      r3, r3, 0x24B0
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lwz       r3, 0x394(r31)
  lbz       r4, 0x38E(r31)
  bl        0x3734
  li        r0, 0
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x398(r31)
  lha       r4, 0x37E(r31)
  bl        0x4EE4
  li        r0, 0x1
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3B4(r31)
  bl        0x1271C
  li        r0, 0x6
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x39C(r31)
  lbz       r4, 0x38C(r31)
  bl        0x47F4
  li        r0, 0x8
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3A0(r31)
  lha       r4, 0x386(r31)
  bl        0x4F80
  li        r0, 0x3
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x390(r31)
  bl        0x6660
  li        r0, 0x7
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3A4(r31)
  lha       r4, 0x384(r31)
  bl        0x100C0
  li        r0, 0x4
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3A8(r31)
  lbz       r4, 0x38D(r31)
  bl        0x15800
  li        r0, 0x5
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3A8(r31)
  bl        0x1583C
  li        r0, 0x2
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3AC(r31)
  bl        0x16D44
  li        r0, 0x9
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  li        r0, 0xB
  stw       r0, 0x24(r31)
  b         .loc_0x4C8
  lwz       r3, 0x3B0(r31)
  bl        0x1AB94
  li        r0, 0xA
  stw       r0, 0x24(r31)

.loc_0x4C8:
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017DF0C
 * Size:	000188
 */
void zen::OgTestScreen::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  mr        r31, r3
  lwz       r3, 0x28(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x28(r31)
  lwz       r3, 0x2C(r31)
  stw       r0, 0x0(r3)
  lwz       r3, 0x2C(r31)
  bl        0x42460
  lwz       r0, 0x24(r31)
  cmplwi    r0, 0xE
  bne-      .loc_0x50
  mr        r3, r31
  bl        -0x528

.loc_0x50:
  lwz       r3, 0x390(r31)
  lwz       r4, 0x28(r31)
  bl        0x6CB4
  cmpwi     r3, 0x7
  blt-      .loc_0x6C
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0x6C:
  lwz       r3, 0x394(r31)
  lwz       r4, 0x28(r31)
  bl        0x369C
  cmpwi     r3, 0x3
  blt-      .loc_0x88
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0x88:
  lwz       r3, 0x39C(r31)
  lwz       r4, 0x28(r31)
  bl        0x472C
  cmpwi     r3, 0x5
  blt-      .loc_0xA4
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0xA4:
  lwz       r3, 0x3A0(r31)
  lwz       r4, 0x28(r31)
  bl        0x50C8
  cmpwi     r3, 0x4
  blt-      .loc_0xC0
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0xC0:
  lwz       r3, 0x398(r31)
  lwz       r4, 0x28(r31)
  bl        0x4C40
  cmpwi     r3, 0x4
  blt-      .loc_0xDC
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0xDC:
  lwz       r3, 0x3A4(r31)
  lwz       r4, 0x28(r31)
  bl        0x100EC
  cmpwi     r3, 0x13
  blt-      .loc_0xF8
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0xF8:
  lwz       r3, 0x3B4(r31)
  lwz       r4, 0x28(r31)
  bl        0x12918
  cmpwi     r3, 0x4
  blt-      .loc_0x114
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0x114:
  lwz       r3, 0x3AC(r31)
  lwz       r4, 0x28(r31)
  bl        0x16C24
  cmpwi     r3, 0x3
  blt-      .loc_0x130
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0x130:
  lwz       r3, 0x3B0(r31)
  lwz       r4, 0x28(r31)
  bl        0x1AA9C
  cmpwi     r3, 0x3
  blt-      .loc_0x14C
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0x14C:
  li        r0, 0
  stw       r0, 0x1C(r1)
  addi      r5, r1, 0x14
  lwz       r3, 0x3A8(r31)
  lwz       r4, 0x28(r31)
  bl        0x156DC
  cmpwi     r3, 0x1
  blt-      .loc_0x174
  li        r0, 0xE
  stw       r0, 0x24(r31)

.loc_0x174:
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017E094
 * Size:	0006A8
 */
void zen::OgTestScreen::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802D
  stw       r0, 0x4(r1)
  stwu      r1, -0x12C8(r1)
  stmw      r26, 0x12B0(r1)
  li        r27, 0
  mr        r31, r4
  mr        r30, r3
  addi      r3, r31, 0
  addi      r29, r5, 0x2468
  lwz       r6, 0x310(r4)
  lwz       r0, 0x30C(r4)
  addi      r4, r1, 0x6C
  stw       r27, 0x6C(r1)
  stw       r27, 0x70(r1)
  stw       r0, 0x74(r1)
  stw       r6, 0x78(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x48(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x310(r31)
  addi      r4, r1, 0x5C
  lwz       r0, 0x30C(r31)
  mr        r3, r31
  stw       r27, 0x5C(r1)
  stw       r27, 0x60(r1)
  stw       r0, 0x64(r1)
  stw       r5, 0x68(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x50(r12)
  mtlr      r12
  blrl      
  stb       r27, 0x58(r1)
  li        r28, 0xFF
  addi      r4, r1, 0x58
  stb       r27, 0x59(r1)
  mr        r3, r31
  stb       r27, 0x5A(r1)
  stb       r28, 0x5B(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xB4(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0x3
  li        r5, 0
  lwz       r12, 0x38(r12)
  mtlr      r12
  blrl      
  addi      r3, r1, 0xF58
  bl        -0x13AFA0
  lfs       f1, 0x8E8(r13)
  addi      r3, r1, 0xF58
  lfs       f0, 0x8F4(r13)
  addi      r4, r1, 0xF0C
  stfs      f1, 0xF0C(r1)
  lfs       f1, 0x8EC(r13)
  addi      r5, r1, 0xF00
  stfs      f0, 0xF00(r1)
  lfs       f0, 0x8F8(r13)
  stfs      f1, 0xF10(r1)
  lfs       f1, 0x8F0(r13)
  stfs      f0, 0xF04(r1)
  lfs       f0, 0x8FC(r13)
  stfs      f1, 0xF14(r1)
  stfs      f0, 0xF08(r1)
  bl        -0x13B400
  lwz       r5, 0x30C(r31)
  lis       r4, 0x4330
  lwz       r0, 0x310(r31)
  addi      r3, r1, 0xF58
  xoris     r5, r5, 0x8000
  xoris     r0, r0, 0x8000
  stw       r5, 0x12AC(r1)
  lfd       f5, -0x50F0(r2)
  stw       r0, 0x12A4(r1)
  lfs       f2, -0x50FC(r2)
  stw       r4, 0x12A8(r1)
  lfs       f3, -0x5108(r2)
  stw       r4, 0x12A0(r1)
  lfd       f1, 0x12A8(r1)
  lfd       f0, 0x12A0(r1)
  fsubs     f1, f1, f5
  lfs       f4, -0x50F8(r2)
  fsubs     f0, f0, f5
  fdivs     f1, f1, f0
  bl        -0x13B5A0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0xF58
  lwz       r12, 0x6C(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x3B4(r31)
  lis       r4, 0x803A
  mr        r3, r31
  lwz       r12, 0x70(r12)
  subi      r4, r4, 0x77C0
  addi      r5, r1, 0xF18
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0x1124(r1)
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x11B8
  lfs       f2, 0x111C(r1)
  lwz       r12, 0x3C(r12)
  lfs       f3, 0x1128(r1)
  mtlr      r12
  lfs       f4, 0x112C(r1)
  lfs       f5, -0x5108(r2)
  blrl      
  mr        r3, r31
  lwz       r4, 0x2E4(r31)
  lwz       r12, 0x3B4(r31)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x390(r30)
  mr        r4, r31
  bl        0x6D18
  lwz       r3, 0x394(r30)
  mr        r4, r31
  bl        0x3D84
  lwz       r3, 0x39C(r30)
  mr        r4, r31
  bl        0x47EC
  lwz       r3, 0x3A0(r30)
  mr        r4, r31
  bl        0x50D4
  lwz       r3, 0x398(r30)
  mr        r4, r31
  bl        0x4A1C
  lwz       r3, 0x3B4(r30)
  mr        r4, r31
  bl        0x12EE4
  lwz       r3, 0x3A8(r30)
  mr        r4, r31
  bl        0x15614
  lwz       r3, 0x3AC(r30)
  mr        r4, r31
  bl        0x16B04
  lwz       r3, 0x3B0(r30)
  mr        r4, r31
  bl        0x1A9BC
  lwz       r0, 0x24(r30)
  cmplwi    r0, 0xE
  bne-      .loc_0x54C
  lwz       r6, 0x310(r31)
  addi      r5, r1, 0x48
  lwz       r0, 0x30C(r31)
  mr        r3, r31
  addi      r4, r1, 0xEC0
  stw       r27, 0x48(r1)
  stw       r27, 0x4C(r1)
  stw       r0, 0x50(r1)
  stw       r6, 0x54(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  stb       r28, 0x44(r1)
  addi      r4, r1, 0x44
  addi      r3, r31, 0
  stb       r28, 0x45(r1)
  li        r5, 0x1
  stb       r28, 0x46(r1)
  stb       r28, 0x47(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  stb       r28, 0x40(r1)
  addi      r4, r1, 0x40
  addi      r3, r31, 0
  stb       r28, 0x41(r1)
  stb       r27, 0x42(r1)
  stb       r28, 0x43(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  addi      r3, r1, 0xDC0
  crclr     6, 0x6
  addi      r4, r29, 0x78
  bl        0x98210
  lwz       r3, 0x30(r30)
  addi      r4, r1, 0xDC0
  bl        -0x156260
  lwz       r12, 0x3B4(r31)
  srawi     r0, r3, 0x1
  addze     r0, r0
  lwz       r4, 0x30(r30)
  lwz       r12, 0xEC(r12)
  addi      r3, r31, 0
  crclr     6, 0x6
  mtlr      r12
  subfic    r5, r0, 0x140
  addi      r7, r1, 0xDC0
  li        r6, 0x14
  blrl      
  li        r0, 0xC8
  stb       r0, 0x3C(r1)
  addi      r4, r1, 0x3C
  addi      r3, r31, 0
  stb       r28, 0x3D(r1)
  li        r5, 0x1
  stb       r28, 0x3E(r1)
  stb       r28, 0x3F(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  li        r0, 0x32
  stb       r0, 0x38(r1)
  addi      r4, r1, 0x38
  addi      r3, r31, 0
  stb       r0, 0x39(r1)
  stb       r28, 0x3A(r1)
  stb       r28, 0x3B(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  lbz       r5, 0x38E(r30)
  addi      r3, r1, 0x2C0
  addi      r4, r29, 0x94
  crclr     6, 0x6
  bl        0x98164
  lha       r5, 0x37E(r30)
  addi      r3, r1, 0x3C0
  addi      r4, r29, 0xA4
  crclr     6, 0x6
  bl        0x98150
  lha       r5, 0x388(r30)
  addi      r3, r1, 0x4C0
  addi      r4, r29, 0xB8
  crclr     6, 0x6
  bl        0x9813C
  lha       r5, 0x386(r30)
  addi      r3, r1, 0x5C0
  addi      r4, r29, 0xCC
  crclr     6, 0x6
  bl        0x98128
  lha       r5, 0x384(r30)
  addi      r3, r1, 0x6C0
  addi      r4, r29, 0xD8
  crclr     6, 0x6
  bl        0x98114
  lbz       r5, 0x38D(r30)
  addi      r3, r1, 0x7C0
  addi      r4, r29, 0xF0
  crclr     6, 0x6
  bl        0x98100
  lha       r5, 0x380(r30)
  addi      r3, r1, 0x8C0
  addi      r4, r29, 0x108
  crclr     6, 0x6
  bl        0x980EC
  addi      r3, r1, 0x9C0
  crclr     6, 0x6
  addi      r4, r29, 0x114
  bl        0x980DC
  lbz       r5, 0x38C(r30)
  addi      r3, r1, 0xAC0
  addi      r4, r29, 0x120
  crclr     6, 0x6
  bl        0x980C8
  addi      r3, r1, 0xBC0
  crclr     6, 0x6
  addi      r4, r29, 0x12C
  bl        0x980B8
  addi      r3, r1, 0xCC0
  crclr     6, 0x6
  addi      r4, r29, 0x13C
  bl        0x980A8
  li        r26, 0
  mulli     r3, r26, 0x1E
  rlwinm    r0,r26,8,0,23
  addi      r27, r1, 0x2C0
  add       r27, r27, r0
  addi      r28, r3, 0x3C

.loc_0x478:
  mr        r3, r31
  lwz       r4, 0x30(r30)
  lwz       r12, 0x3B4(r31)
  addi      r6, r28, 0
  addi      r7, r27, 0
  crclr     6, 0x6
  lwz       r12, 0xEC(r12)
  li        r5, 0xC8
  mtlr      r12
  blrl      
  addi      r26, r26, 0x1
  cmpwi     r26, 0xB
  addi      r27, r27, 0x100
  addi      r28, r28, 0x1E
  blt+      .loc_0x478
  li        r27, 0xFF
  stb       r27, 0x34(r1)
  addi      r4, r1, 0x34
  addi      r3, r31, 0
  stb       r27, 0x35(r1)
  li        r5, 0x1
  stb       r27, 0x36(r1)
  stb       r27, 0x37(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  stb       r27, 0x30(r1)
  addi      r4, r1, 0x30
  addi      r3, r31, 0
  stb       r27, 0x31(r1)
  stb       r27, 0x32(r1)
  stb       r27, 0x33(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  addi      r3, r1, 0x1C0
  crclr     6, 0x6
  addi      r4, r13, 0x900
  bl        0x97FEC
  mr        r3, r31
  lha       r0, 0x37C(r30)
  lwz       r12, 0x3B4(r31)
  addi      r7, r1, 0x1C0
  mulli     r5, r0, 0x1E
  lwz       r4, 0x30(r30)
  lwz       r12, 0xEC(r12)
  crclr     6, 0x6
  mtlr      r12
  addi      r6, r5, 0x3C
  li        r5, 0xAA
  blrl      

.loc_0x54C:
  lwz       r0, 0x24(r30)
  cmplwi    r0, 0x1
  bne-      .loc_0x66C
  lwz       r7, 0x310(r31)
  li        r0, 0
  lwz       r6, 0x30C(r31)
  addi      r5, r1, 0x20
  addi      r3, r31, 0
  stw       r0, 0x20(r1)
  addi      r4, r1, 0x180
  stw       r0, 0x24(r1)
  stw       r6, 0x28(r1)
  stw       r7, 0x2C(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  li        r27, 0xFF
  stb       r27, 0x1C(r1)
  addi      r4, r1, 0x1C
  addi      r3, r31, 0
  stb       r27, 0x1D(r1)
  li        r5, 0x1
  stb       r27, 0x1E(r1)
  stb       r27, 0x1F(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  stb       r27, 0x18(r1)
  li        r0, 0x96
  addi      r4, r1, 0x18
  stb       r27, 0x19(r1)
  mr        r3, r31
  stb       r0, 0x1A(r1)
  stb       r27, 0x1B(r1)
  lwz       r12, 0x3B4(r31)
  lwz       r12, 0xAC(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x398(r30)
  addi      r3, r1, 0x7C
  addi      r4, r29, 0x148
  crclr     6, 0x6
  lwz       r27, 0x0(r5)
  addis     r5, r27, 0x1
  lha       r5, -0x5A64(r5)
  bl        0x97EFC
  mr        r3, r31
  lwz       r4, 0x30(r30)
  lwz       r12, 0x3B4(r31)
  addi      r7, r1, 0x7C
  crclr     6, 0x6
  li        r5, 0x1E
  lwz       r12, 0xEC(r12)
  li        r6, 0x14
  mtlr      r12
  blrl      
  lha       r0, 0x4D0(r27)
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  crclr     6, 0x6
  rlwinm    r0,r0,2,0,29
  add       r4, r27, r0
  lwz       r12, 0xEC(r12)
  lwz       r6, 0x1C(r4)
  li        r5, 0x1E
  mtlr      r12
  lwz       r4, 0x30(r30)
  lwz       r7, 0x0(r6)
  li        r6, 0x28
  blrl      

.loc_0x66C:
  lwz       r3, 0x3A4(r30)
  mr        r4, r31
  bl        0x10898
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lmw       r26, 0x12B0(r1)
  lwz       r0, 0x12CC(r1)
  addi      r1, r1, 0x12C8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017E73C
 * Size:	000094
 */
void zen::OgTestSection::OgTestSection()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r13, 0x8E0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        -0x14979C
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r31)
  addi      r3, r31, 0
  addi      r4, r13, 0x8E0
  bl        -0x13E030
  lis       r3, 0x802A
  addi      r0, r3, 0x642C
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x2668
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  addi      r4, r3, 0x25D8
  addi      r3, r31, 0
  bl        -0x13E058
  lwz       r4, 0x2DEC(r13)
  li        r0, 0x1
  lis       r3, 0x803A
  stw       r0, 0x14(r4)
  subi      r4, r3, 0x24E0
  li        r0, 0
  stw       r0, 0x24C(r4)
  mr        r3, r31
  stw       r0, 0x250(r4)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017E7D0
 * Size:	000080
 */
void zen::OgTestSection::init()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  subi      r31, r4, 0x6800
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  bl        -0x1377F0
  lwz       r4, 0x2DEC(r13)
  addi      r6, r3, 0
  addi      r7, r31, 0
  addi      r3, r4, 0x144
  addi      r4, r13, 0x904
  li        r5, 0x2
  bl        -0x159F08
  li        r3, 0x3C0
  bl        -0x137814
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x5C
  bl        -0x10E4

.loc_0x5C:
  addi      r4, r31, 0
  addi      r3, r30, 0
  bl        -0x13E25C
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}