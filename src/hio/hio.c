

/*
 * --INFO--
 * Address:	8020D388
 * Size:	00000C
 */
void ExtHandler(void)
{
/*
.loc_0x0:
  li        r0, -0x1
  stw       r0, 0x2A60(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	8020D394
 * Size:	000030
 */
void ExiHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x3410(r13)
  cmplwi    r12, 0
  beq-      .loc_0x20
  mtlr      r12
  blrl      

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020D3C4
 * Size:	00003C
 */
void DbgHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xCC00
  stw       r0, 0x4(r1)
  li        r0, 0x1000
  stwu      r1, -0x8(r1)
  lwz       r12, 0x3410(r13)
  stw       r0, 0x3000(r3)
  cmplwi    r12, 0
  beq-      .loc_0x2C
  mtlr      r12
  blrl      

.loc_0x2C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void TxHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void RxHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020D400
 * Size:	0001C4
 */
void HIOEnumDevices(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r30, r3, 0
  lwz       r0, 0x2A60(r13)
  cmpwi     r0, -0x1
  bne-      .loc_0x1AC
  cmplwi    r30, 0
  beq-      .loc_0x1AC
  lis       r3, 0x8021
  subi      r28, r3, 0x2C78
  li        r27, 0x1
  li        r31, 0

.loc_0x38:
  cmpwi     r31, 0x2
  bge-      .loc_0x64

.loc_0x40:
  mr        r3, r31
  bl        -0x14F68
  cmpwi     r3, 0
  beq+      .loc_0x40
  addi      r3, r31, 0
  addi      r4, r28, 0
  bl        -0x14F1C
  cmpwi     r3, 0
  beq-      .loc_0x198

.loc_0x64:
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  bl        -0x14734
  cmpwi     r3, 0
  bne-      .loc_0x88
  mr        r3, r31
  bl        -0x14E60
  b         .loc_0x198

.loc_0x88:
  addi      r3, r31, 0
  li        r4, 0
  li        r5, 0
  bl        -0x14DB8
  cmpwi     r3, 0
  bne-      .loc_0xB4
  mr        r3, r31
  bl        -0x14674
  mr        r3, r31
  bl        -0x14E8C
  b         .loc_0x198

.loc_0xB4:
  li        r0, 0
  stw       r0, 0x10(r1)
  addi      r3, r31, 0
  addi      r4, r1, 0x10
  li        r5, 0x2
  li        r6, 0x1
  li        r7, 0
  bl        -0x15810
  cntlzw    r0, r3
  addi      r3, r31, 0
  rlwinm    r29,r0,27,5,31
  bl        -0x15438
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r31, 0
  or        r29, r29, r0
  addi      r4, r1, 0xC
  li        r5, 0x4
  li        r6, 0
  li        r7, 0
  bl        -0x15844
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r31, 0
  or        r29, r29, r0
  bl        -0x15470
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r31, 0
  or        r29, r29, r0
  bl        -0x14D24
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  addi      r3, r31, 0
  or        r29, r29, r0
  bl        -0x14710
  cmpwi     r29, 0
  bne-      .loc_0x170
  lwz       r3, 0xC(r1)
  subis     r0, r3, 0x101
  cmplwi    r0, 0
  bne-      .loc_0x170
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  blrl      
  mr        r27, r3

.loc_0x170:
  cmpwi     r31, 0x2
  bge-      .loc_0x180
  mr        r3, r31
  bl        -0x14F5C

.loc_0x180:
  mr        r3, r31
  bl        -0x14754
  cmpwi     r27, 0
  bne-      .loc_0x198
  li        r3, 0x1
  b         .loc_0x1B0

.loc_0x198:
  addi      r31, r31, 0x1
  cmpwi     r31, 0x2
  ble+      .loc_0x38
  li        r3, 0x1
  b         .loc_0x1B0

.loc_0x1AC:
  li        r3, 0

.loc_0x1B0:
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020D5C4
 * Size:	000234
 */
void HIOInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  stw       r30, 0x18(r1)
  addi      r30, r4, 0
  bl        -0x17534
  cmplwi    r3, 0xFF
  bne-      .loc_0x38
  li        r0, -0x1
  stw       r0, 0x2A60(r13)
  li        r3, 0
  b         .loc_0x21C

.loc_0x38:
  lwz       r0, 0x2A60(r13)
  cmpwi     r0, -0x1
  beq-      .loc_0x4C
  li        r3, 0x1
  b         .loc_0x21C

.loc_0x4C:
  li        r0, 0
  stw       r31, 0x2A60(r13)
  cmpwi     r31, 0x2
  stw       r30, 0x3410(r13)
  stw       r0, 0x3414(r13)
  stw       r0, 0x3418(r13)
  bge-      .loc_0xA0

.loc_0x68:
  lwz       r3, 0x2A60(r13)
  bl        -0x15154
  cmpwi     r3, 0
  beq+      .loc_0x68
  lis       r4, 0x8021
  lwz       r3, 0x2A60(r13)
  subi      r4, r4, 0x2C78
  bl        -0x1510C
  cmpwi     r3, 0
  bne-      .loc_0xA0
  li        r0, -0x1
  stw       r0, 0x2A60(r13)
  li        r3, 0
  b         .loc_0x21C

.loc_0xA0:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0
  bl        -0x14934
  cmpwi     r3, 0
  bne-      .loc_0xD0
  lwz       r3, 0x2A60(r13)
  bl        -0x15060
  li        r0, -0x1
  stw       r0, 0x2A60(r13)
  li        r3, 0
  b         .loc_0x21C

.loc_0xD0:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0
  bl        -0x14FC4
  cmpwi     r3, 0
  bne-      .loc_0x108
  lwz       r3, 0x2A60(r13)
  bl        -0x14880
  lwz       r3, 0x2A60(r13)
  bl        -0x15098
  li        r0, -0x1
  stw       r0, 0x2A60(r13)
  li        r3, 0
  b         .loc_0x21C

.loc_0x108:
  li        r0, 0
  lwz       r3, 0x2A60(r13)
  stw       r0, 0x14(r1)
  addi      r4, r1, 0x14
  li        r5, 0x2
  li        r6, 0x1
  li        r7, 0
  bl        -0x15A28
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r30,r0,27,5,31
  bl        -0x15650
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r30, r30, r0
  addi      r4, r1, 0x10
  li        r5, 0x4
  li        r6, 0
  li        r7, 0
  bl        -0x15A5C
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r30, r30, r0
  bl        -0x15688
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r30, r30, r0
  bl        -0x14F3C
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r30, r30, r0
  bl        -0x14928
  cmpwi     r30, 0
  bne-      .loc_0x1B0
  lwz       r3, 0x10(r1)
  subis     r0, r3, 0x101
  cmplwi    r0, 0
  beq-      .loc_0x1D8

.loc_0x1B0:
  cmpwi     r31, 0x2
  bge-      .loc_0x1C0
  lwz       r3, 0x2A60(r13)
  bl        -0x15160

.loc_0x1C0:
  lwz       r3, 0x2A60(r13)
  bl        -0x14958
  li        r0, -0x1
  stw       r0, 0x2A60(r13)
  li        r3, 0
  b         .loc_0x21C

.loc_0x1D8:
  lwz       r0, 0x3410(r13)
  cmplwi    r0, 0
  beq-      .loc_0x218
  cmpwi     r31, 0x2
  bge-      .loc_0x200
  lis       r4, 0x8021
  lwz       r3, 0x2A60(r13)
  subi      r4, r4, 0x2C6C
  bl        -0x154C4
  b         .loc_0x218

.loc_0x200:
  lis       r3, 0x8021
  subi      r4, r3, 0x2C3C
  li        r3, 0x19
  bl        -0x14808
  li        r3, 0x40
  bl        -0x14434

.loc_0x218:
  li        r3, 0x1

.loc_0x21C:
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
 * Address:	8020D7F8
 * Size:	000130
 */
void HIOReadMailbox(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lwz       r0, 0x2A60(r13)
  cmpwi     r0, -0x1
  beq-      .loc_0x30
  bl        -0x17770
  cmplwi    r3, 0xFF
  bne-      .loc_0x38

.loc_0x30:
  li        r3, 0
  b         .loc_0x118

.loc_0x38:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0
  bl        -0x14B00
  cmpwi     r3, 0
  bne-      .loc_0x58
  li        r3, 0
  b         .loc_0x118

.loc_0x58:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0x4
  bl        -0x15180
  cmpwi     r3, 0
  bne-      .loc_0x80
  lwz       r3, 0x2A60(r13)
  bl        -0x14A3C
  li        r3, 0
  b         .loc_0x118

.loc_0x80:
  lis       r0, 0x6000
  lwz       r3, 0x2A60(r13)
  stw       r0, 0xC(r1)
  addi      r4, r1, 0xC
  li        r5, 0x2
  li        r6, 0x1
  li        r7, 0
  bl        -0x15BD4
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r31,r0,27,5,31
  bl        -0x157FC
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  addi      r4, r30, 0
  or        r31, r31, r0
  li        r5, 0x4
  li        r6, 0
  li        r7, 0
  bl        -0x15C08
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x15834
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x150E8
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x14AD4
  cntlzw    r0, r31
  rlwinm    r3,r0,27,5,31

.loc_0x118:
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
 * Address:	8020D928
 * Size:	0000F4
 */
void HIOWriteMailbox(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  lwz       r0, 0x2A60(r13)
  cmpwi     r0, -0x1
  beq-      .loc_0x2C
  bl        -0x1789C
  cmplwi    r3, 0xFF
  bne-      .loc_0x34

.loc_0x2C:
  li        r3, 0
  b         .loc_0xE0

.loc_0x34:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0
  bl        -0x14C2C
  cmpwi     r3, 0
  bne-      .loc_0x54
  li        r3, 0
  b         .loc_0xE0

.loc_0x54:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0x4
  bl        -0x152AC
  cmpwi     r3, 0
  bne-      .loc_0x7C
  lwz       r3, 0x2A60(r13)
  bl        -0x14B68
  li        r3, 0
  b         .loc_0xE0

.loc_0x7C:
  rlwinm    r0,r31,0,3,31
  lwz       r3, 0x2A60(r13)
  oris      r0, r0, 0xC000
  stw       r0, 0xC(r1)
  addi      r4, r1, 0xC
  li        r5, 0x4
  li        r6, 0x1
  li        r7, 0
  bl        -0x15D04
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r31,r0,27,5,31
  bl        -0x1592C
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x151E0
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x14BCC
  cntlzw    r0, r31
  rlwinm    r3,r0,27,5,31

.loc_0xE0:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void HIORead(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020DA1C
 * Size:	000144
 */
void HIOWrite(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r3, 0
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  lwz       r0, 0x2A60(r13)
  cmpwi     r0, -0x1
  beq-      .loc_0x3C
  bl        -0x179A0
  cmplwi    r3, 0xFF
  bne-      .loc_0x44

.loc_0x3C:
  li        r3, 0
  b         .loc_0x128

.loc_0x44:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0
  bl        -0x14D30
  cmpwi     r3, 0
  bne-      .loc_0x64
  li        r3, 0
  b         .loc_0x128

.loc_0x64:
  lwz       r3, 0x2A60(r13)
  li        r4, 0
  li        r5, 0x4
  bl        -0x153B0
  cmpwi     r3, 0
  bne-      .loc_0x8C
  lwz       r3, 0x2A60(r13)
  bl        -0x14C6C
  li        r3, 0
  b         .loc_0x128

.loc_0x8C:
  rlwinm    r0,r31,8,7,21
  lwz       r3, 0x2A60(r13)
  oris      r0, r0, 0xA000
  stw       r0, 0x14(r1)
  addi      r4, r1, 0x14
  li        r5, 0x4
  li        r6, 0x1
  li        r7, 0
  bl        -0x15E08
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r31,r0,27,5,31
  bl        -0x15A30
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  addi      r4, r29, 0
  addi      r5, r30, 0
  or        r31, r31, r0
  li        r6, 0x1
  li        r7, 0
  bl        -0x15B40
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x15A68
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x1531C
  cntlzw    r0, r3
  lwz       r3, 0x2A60(r13)
  rlwinm    r0,r0,27,5,31
  or        r31, r31, r0
  bl        -0x14D08
  cntlzw    r0, r31
  rlwinm    r3,r0,27,5,31

.loc_0x128:
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
 * Address:	........
 * Size:	000128
 */
void HIOReadAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void HIOWriteAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void HIOReadStatus(void)
{
	// UNUSED FUNCTION
}