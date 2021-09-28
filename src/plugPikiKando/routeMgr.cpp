

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
 * Address:	........
 * Size:	00009C
 */
void PathFinder::PathFinder(RouteMgr::Group &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009F5E4
 * Size:	000014
 */
void PathFinder::Buffer::Buffer()
{
/*
.loc_0x0:
  li        r0, 0xFF
  stb       r0, 0x4(r3)
  li        r0, -0x1
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void PathFinder::handle2idx(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009F5F8
 * Size:	0000B4
 */
void PathFinder::findASync(PathFinder::Buffer *, int, int, bool)
{
/*
.loc_0x0:
  lwz       r8, 0x10(r3)
  lwz       r0, 0x14(r3)
  cmpw      r8, r0
  blt-      .loc_0x18
  li        r3, 0
  blr       

.loc_0x18:
  lwz       r9, 0xC(r3)
  lis       r8, 0x3
  addi      r0, r8, 0xD40
  addi      r8, r9, 0x1
  stw       r8, 0xC(r3)
  mr        r11, r9
  lwz       r8, 0xC(r3)
  cmpw      r8, r0
  blt-      .loc_0x44
  li        r0, 0x1
  stw       r0, 0xC(r3)

.loc_0x44:
  lwz       r9, 0x10(r3)
  li        r0, 0
  lwz       r10, 0x18(r3)
  cmpw      r5, r6
  mulli     r8, r9, 0x28
  addi      r9, r9, 0x1
  stw       r9, 0x10(r3)
  add       r8, r10, r8
  stw       r4, 0x0(r8)
  stw       r5, 0x4(r8)
  stw       r6, 0x8(r8)
  stb       r7, 0xC(r8)
  lhz       r3, 0x3028(r13)
  sth       r3, 0x14(r8)
  stw       r11, 0x10(r8)
  stw       r0, 0x18(r8)
  stw       r0, 0x1C(r8)
  stb       r0, 0x20(r8)
  lwz       r3, 0x0(r8)
  stw       r5, 0x0(r3)
  bne-      .loc_0xAC
  li        r0, 0x1
  stw       r0, 0x1C(r8)
  mr        r3, r11
  stw       r0, 0x24(r8)
  blr       

.loc_0xAC:
  mr        r3, r11
  blr
*/
}

/*
 * --INFO--
 * Address:	8009F6AC
 * Size:	000088
 */
void PathFinder::checkASync(unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x10(r3)
  li        r6, 0
  addi      r7, r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x3C

.loc_0x18:
  lwz       r5, 0x18(r3)
  addi      r0, r7, 0x10
  lwzx      r0, r5, r0
  cmplw     r4, r0
  bne-      .loc_0x30
  b         .loc_0x40

.loc_0x30:
  addi      r7, r7, 0x28
  addi      r6, r6, 0x1
  bdnz+     .loc_0x18

.loc_0x3C:
  li        r6, -0x1

.loc_0x40:
  cmpwi     r6, -0x1
  bne-      .loc_0x50
  li        r3, -0x3
  blr       

.loc_0x50:
  mulli     r0, r6, 0x28
  lwz       r3, 0x18(r3)
  add       r3, r3, r0
  lwz       r0, 0x1C(r3)
  cmpwi     r0, 0x2
  bne-      .loc_0x70
  li        r3, -0x2
  blr       

.loc_0x70:
  cmpwi     r0, 0x1
  bne-      .loc_0x80
  lwz       r3, 0x24(r3)
  blr       

.loc_0x80:
  li        r3, -0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8009F734
 * Size:	0000D8
 */
void PathFinder::releaseHandle(unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x10(r3)
  li        r6, 0
  addi      r7, r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x3C

.loc_0x18:
  lwz       r5, 0x18(r3)
  addi      r0, r7, 0x10
  lwzx      r0, r5, r0
  cmplw     r4, r0
  bne-      .loc_0x30
  b         .loc_0x40

.loc_0x30:
  addi      r7, r7, 0x28
  addi      r6, r6, 0x1
  bdnz+     .loc_0x18

.loc_0x3C:
  li        r6, -0x1

.loc_0x40:
  cmpwi     r6, -0x1
  beqlr-    
  lwz       r4, 0x10(r3)
  mulli     r5, r6, 0x28
  subi      r0, r4, 0x1
  stw       r0, 0x10(r3)
  b         .loc_0xC8

.loc_0x5C:
  addi      r0, r6, 0x1
  lwz       r4, 0x18(r3)
  mulli     r0, r0, 0x28
  add       r7, r4, r0
  lwz       r0, 0x0(r7)
  add       r4, r4, r5
  addi      r5, r5, 0x28
  stw       r0, 0x0(r4)
  addi      r6, r6, 0x1
  lwz       r0, 0x4(r7)
  stw       r0, 0x4(r4)
  lwz       r0, 0x8(r7)
  stw       r0, 0x8(r4)
  lbz       r0, 0xC(r7)
  stb       r0, 0xC(r4)
  lwz       r0, 0x10(r7)
  stw       r0, 0x10(r4)
  lhz       r0, 0x14(r7)
  sth       r0, 0x14(r4)
  lwz       r0, 0x18(r7)
  stw       r0, 0x18(r4)
  lwz       r0, 0x1C(r7)
  stw       r0, 0x1C(r4)
  lbz       r0, 0x20(r7)
  stb       r0, 0x20(r4)
  lwz       r0, 0x24(r7)
  stw       r0, 0x24(r4)

.loc_0xC8:
  lwz       r0, 0x10(r3)
  cmpw      r6, r0
  blt+      .loc_0x5C
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void PathFinder::updateASync()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009F80C
 * Size:	000340
 */
void PathFinder::updateClient(PathFinder::Client &, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r5, 0
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  stw       r28, 0x20(r1)
  addi      r28, r3, 0
  b         .loc_0x30C

.loc_0x2C:
  lwz       r0, 0x18(r29)
  mr        r3, r28
  lwz       r4, 0x0(r29)
  subi      r30, r30, 0x1
  rlwinm    r0,r0,3,0,28
  lwzx      r4, r4, r0
  bl        0x5B0
  lbz       r0, 0x20(r29)
  addi      r31, r3, 0
  cmplwi    r0, 0
  bne-      .loc_0x1EC
  li        r0, 0x2
  mtctr     r0
  addi      r6, r31, 0
  li        r7, 0

.loc_0x68:
  lwz       r0, 0x14(r6)
  cmpwi     r0, -0x1
  bne-      .loc_0x9C
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  xor       r0, r3, r0
  stbx      r0, r5, r4
  b         .loc_0xC0

.loc_0x9C:
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  or        r0, r3, r0
  stbx      r0, r5, r4

.loc_0xC0:
  lwz       r0, 0x18(r6)
  addi      r6, r6, 0x4
  addi      r7, r7, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0xFC
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  xor       r0, r3, r0
  stbx      r0, r5, r4
  b         .loc_0x120

.loc_0xFC:
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  or        r0, r3, r0
  stbx      r0, r5, r4

.loc_0x120:
  lwz       r0, 0x18(r6)
  addi      r6, r6, 0x4
  addi      r7, r7, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x15C
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  xor       r0, r3, r0
  stbx      r0, r5, r4
  b         .loc_0x180

.loc_0x15C:
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  or        r0, r3, r0
  stbx      r0, r5, r4

.loc_0x180:
  lwz       r0, 0x18(r6)
  addi      r6, r6, 0x4
  addi      r7, r7, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x1BC
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  xor       r0, r3, r0
  stbx      r0, r5, r4
  b         .loc_0x1E0

.loc_0x1BC:
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r5, 0x0(r29)
  slw       r0, r0, r7
  rlwinm    r3,r3,3,0,28
  addi      r4, r3, 0x4
  lbzx      r3, r5, r4
  or        r0, r3, r0
  stbx      r0, r5, r4

.loc_0x1E0:
  addi      r6, r6, 0x4
  addi      r7, r7, 0x1
  bdnz+     .loc_0x68

.loc_0x1EC:
  lwz       r7, 0x18(r29)
  mr        r3, r28
  lwz       r6, 0x0(r29)
  rlwinm    r0,r7,3,0,28
  lwz       r5, 0x8(r29)
  lbz       r8, 0xC(r29)
  add       r4, r6, r0
  bl        0x400
  cmpwi     r3, -0x1
  beq-      .loc_0x2C4
  rlwinm    r4,r3,2,0,29
  lwz       r5, 0x8(r29)
  addi      r0, r4, 0x14
  lwzx      r7, r31, r0
  cmpw      r7, r5
  bne-      .loc_0x25C
  lwz       r3, 0x18(r29)
  li        r0, 0x1
  lwz       r4, 0x0(r29)
  addi      r3, r3, 0x1
  stw       r3, 0x18(r29)
  rlwinm    r3,r3,3,0,28
  stwx      r5, r4, r3
  stw       r0, 0x1C(r29)
  lwz       r3, 0x18(r29)
  addi      r0, r3, 0x1
  stw       r0, 0x24(r29)
  b         .loc_0x320

.loc_0x25C:
  lwz       r5, 0x18(r29)
  li        r4, 0x1
  lwz       r6, 0x0(r29)
  slw       r0, r4, r3
  rlwinm    r3,r5,3,0,28
  addi      r5, r3, 0x4
  lbzx      r3, r6, r5
  xor       r0, r3, r0
  stbx      r0, r6, r5
  lwz       r3, 0x18(r29)
  addi      r0, r3, 0x1
  stw       r0, 0x18(r29)
  lwz       r3, 0x18(r29)
  lwz       r0, 0x4(r28)
  cmpw      r3, r0
  blt-      .loc_0x2AC
  subi      r0, r3, 0x1
  stw       r0, 0x18(r29)
  stb       r4, 0x20(r29)
  b         .loc_0x30C

.loc_0x2AC:
  lwz       r4, 0x0(r29)
  rlwinm    r3,r3,3,0,28
  li        r0, 0
  stwx      r7, r4, r3
  stb       r0, 0x20(r29)
  b         .loc_0x30C

.loc_0x2C4:
  li        r0, 0x1
  stb       r0, 0x20(r29)
  li        r4, -0x1
  lwz       r0, 0x18(r29)
  lwz       r3, 0x0(r29)
  rlwinm    r0,r0,3,0,28
  stwx      r4, r3, r0
  lwz       r3, 0x18(r29)
  subi      r0, r3, 0x1
  stw       r0, 0x18(r29)
  lwz       r0, 0x18(r29)
  cmpwi     r0, 0
  bge-      .loc_0x30C
  li        r0, 0x2
  stw       r0, 0x1C(r29)
  li        r0, -0x2
  stw       r0, 0x24(r29)
  b         .loc_0x320

.loc_0x30C:
  lwz       r0, 0x1C(r29)
  cmpwi     r0, 0
  bne-      .loc_0x320
  cmpwi     r30, 0
  bgt+      .loc_0x2C

.loc_0x320:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8009FB4C
 * Size:	000084
 */
void PathFinder::findSync(WayPoint **, int, int, int, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r26, 0x20(r1)
  addi      r30, r4, 0
  addi      r27, r5, 0
  addi      r5, r6, 0
  addi      r6, r7, 0
  addi      r26, r3, 0
  addi      r7, r8, 0
  lwz       r4, 0x8(r3)
  bl        .loc_0x84
  mr.       r29, r3
  ble-      .loc_0x6C
  li        r28, 0
  rlwinm    r31,r28,3,0,28
  b         .loc_0x64

.loc_0x44:
  lwz       r4, 0x8(r26)
  mr        r3, r26
  lwzx      r4, r4, r31
  bl        0x264
  stw       r3, 0x0(r30)
  addi      r31, r31, 0x8
  addi      r30, r30, 0x4
  addi      r28, r28, 0x1

.loc_0x64:
  cmpw      r28, r27
  blt+      .loc_0x44

.loc_0x6C:
  mr        r3, r29
  lmw       r26, 0x20(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr       

.loc_0x84:
*/
}

/*
 * --INFO--
 * Address:	8009FBD0
 * Size:	000230
 */
void PathFinder::findSync(PathFinder::Buffer *, int, int, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stmw      r24, 0x38(r1)
  addi      r26, r6, 0
  cmpw      r5, r26
  addi      r25, r4, 0
  addi      r24, r3, 0
  addi      r27, r7, 0
  li        r30, 0
  stw       r5, 0x0(r4)
  bne-      .loc_0x38
  li        r3, 0x1
  b         .loc_0x21C

.loc_0x38:
  li        r29, 0
  li        r28, 0
  b         .loc_0x200

.loc_0x44:
  rlwinm    r0,r30,3,0,28
  add       r31, r25, r0
  lwz       r4, 0x0(r31)
  mr        r3, r24
  bl        .loc_0x230
  rlwinm.   r0,r28,0,24,31
  addi      r28, r3, 0
  bne-      .loc_0x15C
  li        r0, 0x2
  mtctr     r0
  addi      r5, r28, 0
  li        r6, 0
  li        r4, 0x1

.loc_0x78:
  lwz       r0, 0x14(r5)
  cmpwi     r0, -0x1
  bne-      .loc_0x98
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r31)
  b         .loc_0xA8

.loc_0x98:
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r31)

.loc_0xA8:
  lwz       r0, 0x18(r5)
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0xD0
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r31)
  b         .loc_0xE0

.loc_0xD0:
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r31)

.loc_0xE0:
  lwz       r0, 0x18(r5)
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x108
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r31)
  b         .loc_0x118

.loc_0x108:
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r31)

.loc_0x118:
  lwz       r0, 0x18(r5)
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x140
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r31)
  b         .loc_0x150

.loc_0x140:
  lbz       r3, 0x4(r31)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r31)

.loc_0x150:
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  bdnz+     .loc_0x78

.loc_0x15C:
  addi      r3, r24, 0
  addi      r4, r31, 0
  addi      r5, r26, 0
  addi      r6, r25, 0
  addi      r7, r30, 0
  addi      r8, r27, 0
  bl        0xD0
  cmpwi     r3, -0x1
  beq-      .loc_0x1E8
  rlwinm    r4,r3,2,0,29
  addi      r0, r4, 0x14
  lwzx      r5, r28, r0
  cmpw      r5, r26
  bne-      .loc_0x1A8
  addi      r30, r30, 0x1
  rlwinm    r0,r30,3,0,28
  stwx      r26, r25, r0
  li        r29, 0x1
  b         .loc_0x208

.loc_0x1A8:
  li        r0, 0x1
  lbz       r4, 0x4(r31)
  slw       r0, r0, r3
  xor       r0, r4, r0
  stb       r0, 0x4(r31)
  addi      r30, r30, 0x1
  lwz       r0, 0x4(r24)
  cmpw      r30, r0
  blt-      .loc_0x1D8
  li        r28, 0x1
  subi      r30, r30, 0x1
  b         .loc_0x200

.loc_0x1D8:
  rlwinm    r0,r30,3,0,28
  stwx      r5, r25, r0
  li        r28, 0
  b         .loc_0x200

.loc_0x1E8:
  li        r0, -0x1
  subic.    r30, r30, 0x1
  stw       r0, 0x0(r31)
  li        r28, 0x1
  bge-      .loc_0x200
  li        r29, 0x2

.loc_0x200:
  cmpwi     r29, 0
  beq+      .loc_0x44

.loc_0x208:
  cmpwi     r29, 0x1
  bne-      .loc_0x218
  addi      r3, r30, 0x1
  b         .loc_0x21C

.loc_0x218:
  li        r3, 0

.loc_0x21C:
  lmw       r24, 0x38(r1)
  lwz       r0, 0x5C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr       

.loc_0x230:
*/
}

/*
 * --INFO--
 * Address:	8009FE00
 * Size:	000014
 */
void PathFinder::getWayPoint(int)
{
/*
.loc_0x0:
  lwz       r3, 0x0(r3)
  mulli     r0, r4, 0xC4
  lwz       r3, 0x0(r3)
  add       r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8009FE14
 * Size:	0001FC
 */
void PathFinder::selectWay(PathFinder::Buffer &, int, PathFinder::Buffer *, int, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x130(r1)
  stfd      f31, 0x128(r1)
  stfd      f30, 0x120(r1)
  stmw      r18, 0xE8(r1)
  addi      r18, r3, 0
  addi      r20, r5, 0
  addi      r26, r1, 0xA4
  addi      r27, r1, 0xC4
  mulli     r0, r20, 0xC4
  addi      r19, r4, 0
  addi      r21, r6, 0
  addi      r22, r7, 0
  addi      r29, r26, 0
  addi      r28, r27, 0
  rlwinm    r31,r8,0,24,31
  li        r25, -0x1
  li        r24, 0
  li        r23, 0
  lwz       r3, 0x0(r3)
  li        r30, 0
  lwz       r3, 0x0(r3)
  add       r3, r3, r0
  lfs       f31, 0x0(r3)
  lfs       f30, 0x8(r3)

.loc_0x68:
  li        r0, 0x1
  lbz       r3, 0x4(r19)
  slw       r0, r0, r23
  and.      r3, r3, r0
  beq-      .loc_0x19C
  lwz       r8, 0x0(r19)
  lhz       r7, 0x3028(r13)
  lwz       r3, 0x0(r18)
  mulli     r5, r8, 0xC4
  lwz       r3, 0x0(r3)
  rlwinm.   r4,r7,0,30,30
  add       r5, r3, r5
  beq-      .loc_0xB4
  lwz       r6, -0x53C8(r13)
  cmpwi     r6, -0x1
  beq-      .loc_0xB4
  lwz       r4, 0x10(r5)
  cmpw      r4, r6
  beq-      .loc_0x19C

.loc_0xB4:
  rlwinm.   r4,r7,0,31,31
  beq-      .loc_0xC8
  lbz       r4, 0x40(r5)
  rlwinm.   r4,r4,0,31,31
  bne-      .loc_0x19C

.loc_0xC8:
  addi      r4, r30, 0x14
  lwzx      r5, r5, r4
  cmpw      r5, r8
  beq-      .loc_0x19C
  cmpwi     r5, -0x1
  bne-      .loc_0xF0
  lbz       r3, 0x4(r19)
  xor       r0, r3, r0
  stb       r0, 0x4(r19)
  b         .loc_0x19C

.loc_0xF0:
  cmplwi    r31, 0
  bne-      .loc_0x11C
  mulli     r4, r5, 0xC4
  addi      r4, r4, 0x38
  lbzx      r3, r3, r4
  cmplwi    r3, 0
  bne-      .loc_0x11C
  lbz       r3, 0x4(r19)
  xor       r0, r3, r0
  stb       r0, 0x4(r19)
  b         .loc_0x19C

.loc_0x11C:
  cmpwi     r22, 0
  mtctr     r22
  addi      r3, r21, 0
  li        r4, 0
  ble-      .loc_0x14C

.loc_0x130:
  lwz       r0, 0x0(r3)
  cmpw      r5, r0
  bne-      .loc_0x144
  li        r4, 0x1
  b         .loc_0x14C

.loc_0x144:
  addi      r3, r3, 0x8
  bdnz+     .loc_0x130

.loc_0x14C:
  rlwinm.   r0,r4,0,24,31
  bne-      .loc_0x19C
  cmpw      r5, r20
  stw       r23, 0x0(r29)
  bne-      .loc_0x168
  mr        r3, r23
  b         .loc_0x1E0

.loc_0x168:
  lwz       r3, 0x0(r18)
  mulli     r0, r5, 0xC4
  fmr       f3, f31
  lwz       r3, 0x0(r3)
  fmr       f4, f30
  add       r3, r3, r0
  lfs       f1, 0x0(r3)
  lfs       f2, 0x8(r3)
  bl        -0x67974
  stfs      f1, 0x0(r28)
  addi      r29, r29, 0x4
  addi      r28, r28, 0x4
  addi      r24, r24, 0x1

.loc_0x19C:
  addi      r23, r23, 0x1
  cmpwi     r23, 0x8
  addi      r30, r30, 0x4
  blt+      .loc_0x68
  cmpwi     r24, 0
  mtctr     r24
  lfs       f1, -0x72D0(r2)
  ble-      .loc_0x1DC

.loc_0x1BC:
  lfs       f0, 0x0(r27)
  fcmpo     cr0, f0, f1
  bge-      .loc_0x1D0
  fmr       f1, f0
  lwz       r25, 0x0(r26)

.loc_0x1D0:
  addi      r27, r27, 0x4
  addi      r26, r26, 0x4
  bdnz+     .loc_0x1BC

.loc_0x1DC:
  mr        r3, r25

.loc_0x1E0:
  lmw       r18, 0xE8(r1)
  lwz       r0, 0x134(r1)
  lfd       f31, 0x128(r1)
  lfd       f30, 0x120(r1)
  addi      r1, r1, 0x130
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A0010
 * Size:	000048
 */
void RouteMgr::getPathFinder(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x1B1C
  cmpwi     r3, -0x1
  beq-      .loc_0x30
  lwz       r4, 0x24(r31)
  rlwinm    r0,r3,2,0,29
  lwzx      r3, r4, r0
  b         .loc_0x34

.loc_0x30:
  li        r3, 0

.loc_0x34:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A0058
 * Size:	0000B0
 */
void RouteMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x7465
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x7374
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r27, r3, 0
  bl        0x1ACC
  cmpwi     r3, -0x1
  beq-      .loc_0x38
  lwz       r4, 0x24(r27)
  rlwinm    r0,r3,2,0,29
  lwzx      r31, r4, r0
  b         .loc_0x3C

.loc_0x38:
  li        r31, 0

.loc_0x3C:
  cmplwi    r31, 0
  beq-      .loc_0x9C
  lwz       r3, 0x10(r31)
  cmpwi     r3, 0
  beq-      .loc_0x9C
  li        r0, 0x100
  divw      r28, r0, r3
  li        r29, 0
  addi      r27, r29, 0
  b         .loc_0x90

.loc_0x64:
  lwz       r0, 0x18(r31)
  mr        r3, r31
  lhz       r30, 0x3028(r13)
  addi      r5, r28, 0
  add       r4, r0, r27
  lhz       r0, 0x14(r4)
  sth       r0, 0x3028(r13)
  bl        -0x8CC
  sth       r30, 0x3028(r13)
  addi      r27, r27, 0x28
  addi      r29, r29, 0x1

.loc_0x90:
  lwz       r0, 0x10(r31)
  cmpw      r29, r0
  blt+      .loc_0x64

.loc_0x9C:
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A0108
 * Size:	00004C
 */
void RouteMgr::getNumWayPoints(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x1A24
  cmpwi     r3, -0x1
  beq-      .loc_0x34
  lwz       r4, 0x20(r31)
  rlwinm    r0,r3,3,0,28
  add       r3, r4, r0
  lwz       r3, 0x4(r3)
  b         .loc_0x38

.loc_0x34:
  li        r3, -0x1

.loc_0x38:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A0154
 * Size:	0003B8
 */
void RouteMgr::getSafePosition(unsigned long, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x190(r1)
  stfd      f31, 0x188(r1)
  stfd      f30, 0x180(r1)
  stfd      f29, 0x178(r1)
  stfd      f28, 0x170(r1)
  stfd      f27, 0x168(r1)
  stfd      f26, 0x160(r1)
  stfd      f25, 0x158(r1)
  stw       r31, 0x154(r1)
  addi      r31, r6, 0
  stw       r30, 0x150(r1)
  addi      r30, r3, 0
  stw       r29, 0x14C(r1)
  stw       r28, 0x148(r1)
  mr        r28, r4
  li        r4, 0x1
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x0(r6)
  lfs       f2, 0x8(r6)
  bl        -0x37FD0
  cmplwi    r3, 0
  li        r29, 0
  beq-      .loc_0xBC
  bl        0x75EC8
  cmpwi     r3, 0x5
  bne-      .loc_0xBC
  lwz       r3, 0x2F00(r13)
  li        r4, 0
  lfs       f1, 0x0(r31)
  lfs       f2, 0x8(r31)
  bl        -0x3816C
  fmr       f25, f1
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x0(r31)
  li        r4, 0x1
  lfs       f2, 0x8(r31)
  bl        -0x382E8
  fcmpo     cr0, f25, f1
  cror      2, 0, 0x2
  bne-      .loc_0xBC
  lfs       f0, 0x4(r31)
  fcmpo     cr0, f0, f1
  cror      2, 0, 0x2
  bne-      .loc_0xBC
  li        r29, 0x1

.loc_0xBC:
  lis       r6, 0x7465
  addi      r3, r28, 0
  addi      r7, r31, 0
  addi      r10, r29, 0
  addi      r4, r1, 0x144
  addi      r5, r1, 0x140
  addi      r6, r6, 0x7374
  li        r8, 0
  li        r9, 0x1
  bl        0x74C
  lwz       r3, 0x144(r1)
  cmplwi    r3, 0
  beq-      .loc_0xF8
  lwz       r0, 0x140(r1)
  cmplwi    r0, 0

.loc_0xF8:
  lwz       r4, 0x140(r1)
  lfs       f2, 0x4(r3)
  lfs       f3, 0x4(r4)
  lfs       f1, 0x0(r4)
  lfs       f0, 0x0(r3)
  fsubs     f27, f3, f2
  lfs       f2, 0x8(r4)
  fsubs     f28, f1, f0
  lfs       f0, 0x8(r3)
  fmr       f30, f27
  fsubs     f26, f2, f0
  fmr       f31, f28
  fmuls     f0, f30, f30
  fmr       f29, f26
  fmuls     f1, f31, f31
  fmuls     f2, f29, f29
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x92654
  lfs       f0, -0x72CC(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x15C
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0x15C:
  lwz       r29, 0x144(r1)
  addi      r6, r1, 0x88
  lfs       f2, 0x0(r31)
  addi      r5, r1, 0x84
  lfs       f0, 0x0(r29)
  lfs       f5, 0x8(r31)
  addi      r4, r1, 0x80
  fsubs     f0, f2, f0
  lfs       f4, 0x8(r29)
  lfs       f3, 0x4(r31)
  lfs       f2, 0x4(r29)
  addi      r3, r1, 0xF0
  stfs      f0, 0xCC(r1)
  fsubs     f3, f3, f2
  fsubs     f2, f5, f4
  lfs       f0, 0xCC(r1)
  stfs      f0, 0xFC(r1)
  stfs      f3, 0x100(r1)
  stfs      f2, 0x104(r1)
  lfs       f2, 0xFC(r1)
  lfs       f0, 0x100(r1)
  fmuls     f3, f31, f2
  lfs       f4, 0x104(r1)
  fmuls     f0, f30, f0
  lfs       f2, -0x72C8(r2)
  fmuls     f5, f29, f4
  fadds     f3, f3, f0
  lwz       r7, 0x140(r1)
  lfs       f4, 0xC(r29)
  lfs       f0, 0xC(r7)
  fadds     f3, f5, f3
  fdivs     f25, f3, f1
  fmuls     f5, f25, f1
  fsubs     f1, f2, f25
  fmuls     f3, f25, f0
  fmuls     f2, f29, f5
  fmuls     f4, f1, f4
  fmuls     f1, f30, f5
  fmuls     f0, f31, f5
  stfs      f2, 0x88(r1)
  fadds     f29, f4, f3
  stfs      f1, 0x84(r1)
  stfs      f0, 0x80(r1)
  bl        -0x69240
  lfs       f1, 0xF0(r1)
  lfs       f0, 0x0(r29)
  lfs       f3, 0xF8(r1)
  fadds     f1, f1, f0
  lfs       f2, 0x8(r29)
  lfs       f0, 0x0(r31)
  fadds     f3, f3, f2
  lfs       f2, 0x8(r31)
  fsubs     f0, f1, f0
  lfs       f1, -0x72CC(r2)
  fsubs     f2, f3, f2
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f0, f1
  fadds     f4, f2, f0
  fcmpo     cr0, f4, f1
  ble-      .loc_0x2A8
  fsqrte    f1, f4
  lfd       f3, -0x72C0(r2)
  lfd       f2, -0x72B8(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x98(r1)
  lfs       f4, 0x98(r1)

.loc_0x2A8:
  fsubs     f1, f4, f29
  lfs       f0, -0x72CC(r2)
  fcmpo     cr0, f1, f0
  bgt-      .loc_0x2CC
  fcmpo     cr0, f25, f0
  blt-      .loc_0x2CC
  lfs       f0, -0x72C8(r2)
  fcmpo     cr0, f25, f0
  ble-      .loc_0x364

.loc_0x2CC:
  lfs       f0, -0x72CC(r2)
  fcmpo     cr0, f25, f0
  bge-      .loc_0x2E0
  fmr       f25, f0
  b         .loc_0x2F0

.loc_0x2E0:
  lfs       f0, -0x72C8(r2)
  fcmpo     cr0, f25, f0
  ble-      .loc_0x2F0
  fmr       f25, f0

.loc_0x2F0:
  fmuls     f1, f28, f25
  lwz       r3, 0x144(r1)
  fmuls     f0, f27, f25
  li        r4, 0x1
  fmuls     f3, f26, f25
  stfs      f1, 0x8C(r1)
  lfs       f2, 0x0(r3)
  lfs       f1, 0x8C(r1)
  lfs       f4, 0x8(r3)
  fadds     f1, f2, f1
  fadds     f2, f4, f3
  stfs      f1, 0xAC(r1)
  lfs       f1, 0xAC(r1)
  stfs      f1, 0xE4(r1)
  lfs       f1, 0x4(r3)
  fadds     f0, f1, f0
  stfs      f0, 0xE8(r1)
  stfs      f2, 0xEC(r1)
  lwz       r3, 0xE4(r1)
  lwz       r0, 0xE8(r1)
  stw       r3, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r0, 0xEC(r1)
  stw       r0, 0x8(r31)
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x0(r31)
  lfs       f2, 0x8(r31)
  bl        -0x385AC
  stfs      f1, 0x4(r31)

.loc_0x364:
  lfs       f0, 0x0(r31)
  stfs      f0, 0x0(r30)
  lfs       f0, 0x4(r31)
  stfs      f0, 0x4(r30)
  lfs       f0, 0x8(r31)
  stfs      f0, 0x8(r30)
  lwz       r0, 0x194(r1)
  lfd       f31, 0x188(r1)
  lfd       f30, 0x180(r1)
  lfd       f29, 0x178(r1)
  lfd       f28, 0x170(r1)
  lfd       f27, 0x168(r1)
  lfd       f26, 0x160(r1)
  lfd       f25, 0x158(r1)
  lwz       r31, 0x154(r1)
  lwz       r30, 0x150(r1)
  lwz       r29, 0x14C(r1)
  lwz       r28, 0x148(r1)
  addi      r1, r1, 0x190
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A050C
 * Size:	000474
 */
void RouteMgr::findNearestEdge(WayPoint **, WayPoint **, unsigned long, Vector3f &, bool, bool, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x1C8(r1)
  stfd      f31, 0x1C0(r1)
  stfd      f30, 0x1B8(r1)
  stfd      f29, 0x1B0(r1)
  stfd      f28, 0x1A8(r1)
  stfd      f27, 0x1A0(r1)
  stfd      f26, 0x198(r1)
  stfd      f25, 0x190(r1)
  stfd      f24, 0x188(r1)
  stfd      f23, 0x180(r1)
  stmw      r14, 0x138(r1)
  addi      r14, r4, 0
  addi      r24, r3, 0
  stw       r5, 0x134(r1)
  addi      r29, r7, 0
  addi      r17, r8, 0
  addi      r15, r9, 0
  addi      r16, r10, 0
  addi      r4, r6, 0
  bl        0x15E0
  cmpwi     r3, -0x1
  bne-      .loc_0x74
  li        r0, 0
  lwz       r3, 0x134(r1)
  stw       r0, 0x0(r14)
  stw       r0, 0x0(r3)
  b         .loc_0x43C

.loc_0x74:
  lfs       f23, -0x72D0(r2)
  rlwinm    r23,r3,3,0,28
  lfs       f31, -0x72C8(r2)
  addi      r19, r1, 0x7C
  lfs       f28, -0x72CC(r2)
  lfd       f29, -0x72C0(r2)
  addi      r20, r1, 0x78
  lfd       f30, -0x72B8(r2)
  addi      r21, r1, 0x74
  rlwinm    r22,r15,0,24,31
  rlwinm    r26,r16,0,24,31
  rlwinm    r25,r17,0,24,31
  li        r17, 0
  li        r18, 0
  li        r16, 0
  li        r15, 0
  b         .loc_0x41C

.loc_0xB8:
  lwz       r0, 0x0(r3)
  cmplwi    r25, 0
  add       r31, r0, r15
  bne-      .loc_0xDC
  cmplwi    r26, 0
  beq-      .loc_0xDC
  lbz       r0, 0x40(r31)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x414

.loc_0xDC:
  cmplwi    r26, 0
  bne-      .loc_0xF8
  cmplwi    r25, 0
  beq-      .loc_0xF8
  lbz       r0, 0x40(r31)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x414

.loc_0xF8:
  cmplwi    r22, 0
  beq-      .loc_0x10C
  lbz       r0, 0x38(r31)
  cmplwi    r0, 0
  beq-      .loc_0x414

.loc_0x10C:
  cmplwi    r26, 0
  beq-      .loc_0x120
  lbz       r0, 0x40(r31)
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x414

.loc_0x120:
  li        r28, 0
  addi      r27, r31, 0

.loc_0x128:
  lwz       r0, 0x14(r27)
  cmpwi     r0, -0x1
  beq-      .loc_0x404
  lwz       r3, 0x20(r24)
  mulli     r0, r0, 0xC4
  lwzx      r3, r23, r3
  cmplwi    r25, 0
  add       r30, r3, r0
  beq-      .loc_0x160
  cmplwi    r26, 0
  beq-      .loc_0x160
  lbz       r0, 0x40(r30)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x404

.loc_0x160:
  cmplwi    r26, 0
  bne-      .loc_0x17C
  cmplwi    r25, 0
  beq-      .loc_0x17C
  lbz       r0, 0x40(r30)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x404

.loc_0x17C:
  cmplwi    r22, 0
  beq-      .loc_0x190
  lbz       r0, 0x38(r30)
  cmplwi    r0, 0
  beq-      .loc_0x404

.loc_0x190:
  lfs       f3, 0x0(r30)
  lfs       f2, 0x0(r31)
  lfs       f1, 0x4(r30)
  lfs       f0, 0x4(r31)
  fsubs     f27, f3, f2
  lfs       f2, 0x8(r30)
  fsubs     f26, f1, f0
  lfs       f0, 0x8(r31)
  fmuls     f1, f27, f27
  fsubs     f25, f2, f0
  fmuls     f0, f26, f26
  fmuls     f2, f25, f25
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x92A94
  fcmpu     cr0, f28, f1
  beq-      .loc_0x1E0
  fdivs     f27, f27, f1
  fdivs     f26, f26, f1
  fdivs     f25, f25, f1

.loc_0x1E0:
  lfs       f8, 0x0(r29)
  lfs       f9, 0x0(r31)
  lfs       f4, 0x8(r29)
  lfs       f5, 0x8(r31)
  fsubs     f0, f8, f9
  lfs       f6, 0x4(r29)
  lfs       f7, 0x4(r31)
  fsubs     f2, f4, f5
  stfs      f0, 0xBC(r1)
  fsubs     f0, f6, f7
  fmuls     f3, f25, f2
  lfs       f2, 0xBC(r1)
  fmuls     f0, f26, f0
  fmuls     f2, f27, f2
  fadds     f0, f2, f0
  fadds     f0, f3, f0
  fdivs     f24, f0, f1
  fcmpo     cr0, f24, f28
  blt-      .loc_0x234
  fcmpo     cr0, f24, f31
  ble-      .loc_0x350

.loc_0x234:
  fsubs     f0, f7, f6
  fsubs     f1, f9, f8
  fsubs     f2, f5, f4
  fmuls     f0, f0, f0
  fmuls     f1, f1, f1
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  fcmpo     cr0, f0, f28
  ble-      .loc_0x2AC
  fsqrte    f2, f0
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f0, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f0, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f0, f1
  fsub      f1, f30, f1
  fmul      f1, f2, f1
  fmul      f0, f0, f1
  frsp      f0, f0
  stfs      f0, 0x88(r1)
  lfs       f0, 0x88(r1)

.loc_0x2AC:
  lfs       f4, 0x4(r30)
  lfs       f3, 0x4(r29)
  lfs       f2, 0x0(r30)
  lfs       f1, 0x0(r29)
  fsubs     f4, f4, f3
  lfs       f3, 0x8(r30)
  fsubs     f5, f2, f1
  lfs       f2, 0x8(r29)
  fmuls     f1, f4, f4
  fsubs     f3, f3, f2
  fmuls     f2, f5, f5
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f3, f3, f1
  fcmpo     cr0, f3, f28
  ble-      .loc_0x33C
  fsqrte    f2, f3
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f3, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f3, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f3, f1
  fsub      f1, f30, f1
  fmul      f1, f2, f1
  fmul      f1, f3, f1
  frsp      f1, f1
  stfs      f1, 0x84(r1)
  lfs       f3, 0x84(r1)

.loc_0x33C:
  fcmpo     cr0, f3, f0
  bge-      .loc_0x3F0
  fmr       f0, f3
  b         .loc_0x3F0
  b         .loc_0x3F0

.loc_0x350:
  fmuls     f0, f24, f1
  addi      r4, r21, 0
  addi      r5, r20, 0
  addi      r6, r19, 0
  fmuls     f2, f25, f0
  fmuls     f1, f26, f0
  addi      r3, r1, 0xC8
  fmuls     f0, f27, f0
  stfs      f2, 0x7C(r1)
  stfs      f1, 0x78(r1)
  stfs      f0, 0x74(r1)
  bl        -0x6976C
  lfs       f3, 0xC8(r1)
  fsubs     f4, f31, f24
  lfs       f2, 0x0(r31)
  lfs       f1, 0xCC(r1)
  lfs       f0, 0x4(r31)
  fadds     f6, f3, f2
  lfs       f5, 0x0(r29)
  fadds     f3, f1, f0
  lfs       f2, 0x4(r29)
  fsubs     f7, f6, f5
  lfs       f1, 0xD0(r1)
  lfs       f0, 0x8(r31)
  fsubs     f6, f3, f2
  lfs       f3, 0xC(r31)
  lfs       f2, 0xC(r30)
  fadds     f1, f1, f0
  lfs       f0, 0x8(r29)
  fsubs     f5, f1, f0
  fmuls     f1, f7, f7
  fmuls     f0, f6, f6
  fmuls     f4, f4, f3
  fmuls     f3, f24, f2
  fmuls     f2, f5, f5
  fadds     f0, f1, f0
  fadds     f24, f4, f3
  fadds     f1, f2, f0
  bl        -0x92CB4
  fsubs     f0, f1, f24

.loc_0x3F0:
  fcmpo     cr0, f23, f0
  ble-      .loc_0x404
  fmr       f23, f0
  addi      r17, r31, 0
  addi      r18, r30, 0

.loc_0x404:
  addi      r28, r28, 0x1
  cmpwi     r28, 0x8
  addi      r27, r27, 0x4
  blt+      .loc_0x128

.loc_0x414:
  addi      r15, r15, 0xC4
  addi      r16, r16, 0x1

.loc_0x41C:
  lwz       r0, 0x20(r24)
  add       r3, r23, r0
  lwz       r0, 0x4(r3)
  cmpw      r16, r0
  blt+      .loc_0xB8
  stw       r17, 0x0(r14)
  lwz       r3, 0x134(r1)
  stw       r18, 0x0(r3)

.loc_0x43C:
  lmw       r14, 0x138(r1)
  lwz       r0, 0x1CC(r1)
  lfd       f31, 0x1C0(r1)
  lfd       f30, 0x1B8(r1)
  lfd       f29, 0x1B0(r1)
  lfd       f28, 0x1A8(r1)
  lfd       f27, 0x1A0(r1)
  lfd       f26, 0x198(r1)
  lfd       f25, 0x190(r1)
  lfd       f24, 0x188(r1)
  lfd       f23, 0x180(r1)
  addi      r1, r1, 0x1C8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A0980
 * Size:	000768
 */
void RouteMgr::findNearestEdgeAvoidOff(WayPoint **, WayPoint **, unsigned long, Vector3f &, bool, bool, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x1F8(r1)
  stfd      f31, 0x1F0(r1)
  stfd      f30, 0x1E8(r1)
  stfd      f29, 0x1E0(r1)
  stfd      f28, 0x1D8(r1)
  stfd      f27, 0x1D0(r1)
  stfd      f26, 0x1C8(r1)
  stfd      f25, 0x1C0(r1)
  stfd      f24, 0x1B8(r1)
  stfd      f23, 0x1B0(r1)
  stmw      r14, 0x168(r1)
  addi      r15, r6, 0
  addi      r22, r3, 0
  stw       r4, 0x15C(r1)
  addi      r28, r7, 0
  addi      r14, r8, 0
  stw       r5, 0x160(r1)
  addi      r20, r9, 0
  addi      r24, r10, 0
  addi      r4, r15, 0
  bl        0x1168
  addi      r16, r3, 0
  cmpwi     r16, -0x1
  bne-      .loc_0x80
  lwz       r3, 0x15C(r1)
  li        r0, 0
  stw       r0, 0x0(r3)
  lwz       r3, 0x160(r1)
  stw       r0, 0x0(r3)
  b         .loc_0x730

.loc_0x80:
  addi      r3, r22, 0
  addi      r4, r15, 0
  addi      r5, r28, 0
  addi      r6, r14, 0
  bl        0x844
  mr.       r31, r3
  bne-      .loc_0xC4
  lwz       r4, 0x15C(r1)
  mr        r3, r22
  lwz       r5, 0x160(r1)
  addi      r6, r15, 0
  addi      r7, r28, 0
  addi      r8, r14, 0
  addi      r9, r20, 0
  addi      r10, r24, 0
  bl        -0x530
  b         .loc_0x730

.loc_0xC4:
  lfs       f0, -0x72CC(r2)
  addi      r3, r22, 0
  addi      r4, r15, 0
  stfs      f0, 0x154(r1)
  mr        r6, r31
  addi      r5, r1, 0x14C
  stfs      f0, 0x150(r1)
  stfs      f0, 0x14C(r1)
  bl        0x95C
  lfs       f3, 0x14C(r1)
  lfs       f2, 0x0(r28)
  lfs       f1, 0x150(r1)
  lfs       f0, 0x4(r28)
  fmuls     f3, f3, f2
  lfs       f4, 0x154(r1)
  fmuls     f2, f1, f0
  lfs       f0, 0x8(r28)
  lfs       f1, 0x158(r1)
  fmuls     f4, f4, f0
  lfs       f0, -0x72CC(r2)
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  fsubs     f1, f2, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x134
  li        r0, 0x1
  b         .loc_0x138

.loc_0x134:
  li        r0, 0

.loc_0x138:
  neg       r3, r0
  lfs       f23, -0x72D0(r2)
  subic     r0, r3, 0x1
  lfs       f31, -0x72C8(r2)
  subfe     r0, r0, r3
  lfs       f28, -0x72CC(r2)
  rlwinm    r23,r0,0,24,31
  lfd       f29, -0x72C0(r2)
  li        r0, 0
  lfd       f30, -0x72B8(r2)
  rlwinm    r21,r16,3,0,28
  stw       r0, 0x164(r1)
  rlwinm    r25,r24,0,24,31
  rlwinm    r24,r14,0,24,31
  addi      r17, r1, 0x94
  addi      r18, r1, 0x90
  addi      r19, r1, 0x8C
  rlwinm    r20,r20,0,24,31
  li        r15, 0
  li        r16, 0
  li        r14, 0
  b         .loc_0x70C

.loc_0x190:
  lwz       r3, 0x0(r3)
  cmplwi    r24, 0
  lwz       r0, 0x164(r1)
  add       r29, r3, r0
  bne-      .loc_0x1B8
  cmplwi    r25, 0
  beq-      .loc_0x1B8
  lbz       r0, 0x40(r29)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x6FC

.loc_0x1B8:
  cmplwi    r25, 0
  bne-      .loc_0x1D4
  cmplwi    r24, 0
  beq-      .loc_0x1D4
  lbz       r0, 0x40(r29)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x6FC

.loc_0x1D4:
  cmplwi    r25, 0
  beq-      .loc_0x1E8
  lbz       r0, 0x40(r29)
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x6FC

.loc_0x1E8:
  cmplwi    r20, 0
  beq-      .loc_0x1FC
  lbz       r0, 0x38(r29)
  cmplwi    r0, 0
  beq-      .loc_0x6FC

.loc_0x1FC:
  li        r27, 0
  addi      r26, r29, 0

.loc_0x204:
  lwz       r0, 0x14(r26)
  cmpwi     r0, -0x1
  beq-      .loc_0x6EC
  lwz       r3, 0x20(r22)
  mulli     r0, r0, 0xC4
  lwzx      r3, r21, r3
  cmplwi    r24, 0
  add       r30, r3, r0
  beq-      .loc_0x23C
  cmplwi    r25, 0
  beq-      .loc_0x23C
  lbz       r0, 0x40(r30)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x6EC

.loc_0x23C:
  cmplwi    r25, 0
  bne-      .loc_0x258
  cmplwi    r24, 0
  beq-      .loc_0x258
  lbz       r0, 0x40(r30)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x6EC

.loc_0x258:
  cmplwi    r20, 0
  beq-      .loc_0x26C
  lbz       r0, 0x38(r30)
  cmplwi    r0, 0
  beq-      .loc_0x6EC

.loc_0x26C:
  lfs       f4, 0x14C(r1)
  lfs       f10, 0x0(r29)
  lfs       f3, 0x150(r1)
  lfs       f8, 0x4(r29)
  fmuls     f1, f4, f10
  lfs       f5, 0x154(r1)
  fmuls     f0, f3, f8
  lfs       f7, 0x8(r29)
  lfs       f6, 0x158(r1)
  fmuls     f2, f5, f7
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  fsubs     f0, f0, f6
  fcmpo     cr0, f0, f28
  cror      2, 0x1, 0x2
  bne-      .loc_0x2B4
  li        r0, 0x1
  b         .loc_0x2B8

.loc_0x2B4:
  li        r0, 0

.loc_0x2B8:
  lfs       f11, 0x0(r30)
  neg       r3, r0
  lfs       f9, 0x4(r30)
  subic     r0, r3, 0x1
  fmuls     f1, f4, f11
  fmuls     f0, f3, f9
  lfs       f3, 0x8(r30)
  subfe     r0, r0, r3
  fmuls     f2, f5, f3
  fadds     f0, f1, f0
  rlwinm    r9,r0,0,24,31
  fadds     f0, f2, f0
  fsubs     f0, f0, f6
  fcmpo     cr0, f0, f28
  cror      2, 0x1, 0x2
  bne-      .loc_0x300
  li        r0, 0x1
  b         .loc_0x304

.loc_0x300:
  li        r0, 0

.loc_0x304:
  lwz       r7, 0x14(r29)
  neg       r4, r0
  lwz       r0, 0x10(r31)
  subic     r3, r4, 0x1
  subfe     r3, r3, r4
  cmpw      r7, r0
  rlwinm    r8,r3,0,24,31
  li        r5, 0
  li        r6, 0
  bne-      .loc_0x330
  li        r5, 0x1

.loc_0x330:
  lwz       r7, 0x14(r30)
  cmpw      r7, r0
  bne-      .loc_0x340
  li        r6, 0x1

.loc_0x340:
  addi      r3, r29, 0x4
  lwz       r0, 0x10(r31)
  lwz       r7, 0x18(r29)
  addi      r4, r30, 0x4
  cmpw      r7, r0
  bne-      .loc_0x35C
  li        r5, 0x1

.loc_0x35C:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x36C
  li        r6, 0x1

.loc_0x36C:
  lwz       r7, 0x18(r3)
  addi      r3, r3, 0x4
  lwz       r0, 0x10(r31)
  addi      r4, r4, 0x4
  cmpw      r7, r0
  bne-      .loc_0x388
  li        r5, 0x1

.loc_0x388:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x398
  li        r6, 0x1

.loc_0x398:
  lwz       r7, 0x18(r3)
  addi      r3, r3, 0x4
  lwz       r0, 0x10(r31)
  addi      r4, r4, 0x4
  cmpw      r7, r0
  bne-      .loc_0x3B4
  li        r5, 0x1

.loc_0x3B4:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x3C4
  li        r6, 0x1

.loc_0x3C4:
  lwz       r7, 0x18(r3)
  addi      r3, r3, 0x4
  lwz       r0, 0x10(r31)
  addi      r4, r4, 0x4
  cmpw      r7, r0
  bne-      .loc_0x3E0
  li        r5, 0x1

.loc_0x3E0:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x3F0
  li        r6, 0x1

.loc_0x3F0:
  lwz       r7, 0x18(r3)
  addi      r3, r3, 0x4
  lwz       r0, 0x10(r31)
  addi      r4, r4, 0x4
  cmpw      r7, r0
  bne-      .loc_0x40C
  li        r5, 0x1

.loc_0x40C:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x41C
  li        r6, 0x1

.loc_0x41C:
  lwz       r7, 0x18(r3)
  addi      r3, r3, 0x4
  lwz       r0, 0x10(r31)
  addi      r4, r4, 0x4
  cmpw      r7, r0
  bne-      .loc_0x438
  li        r5, 0x1

.loc_0x438:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x448
  li        r6, 0x1

.loc_0x448:
  lwz       r0, 0x10(r31)
  addi      r4, r4, 0x4
  lwz       r7, 0x18(r3)
  cmpw      r7, r0
  bne-      .loc_0x460
  li        r5, 0x1

.loc_0x460:
  lwz       r7, 0x14(r4)
  cmpw      r7, r0
  bne-      .loc_0x470
  li        r6, 0x1

.loc_0x470:
  rlwinm.   r0,r5,0,24,31
  beq-      .loc_0x480
  cmplw     r9, r23
  bne-      .loc_0x6EC

.loc_0x480:
  rlwinm.   r0,r6,0,24,31
  beq-      .loc_0x490
  cmplw     r8, r23
  bne-      .loc_0x6EC

.loc_0x490:
  fsubs     f27, f11, f10
  fsubs     f26, f9, f8
  fsubs     f25, f3, f7
  fmuls     f1, f27, f27
  fmuls     f0, f26, f26
  fmuls     f2, f25, f25
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x931F0
  fcmpu     cr0, f28, f1
  beq-      .loc_0x4C8
  fdivs     f27, f27, f1
  fdivs     f26, f26, f1
  fdivs     f25, f25, f1

.loc_0x4C8:
  lfs       f8, 0x0(r28)
  lfs       f9, 0x0(r29)
  lfs       f4, 0x8(r28)
  lfs       f5, 0x8(r29)
  fsubs     f0, f8, f9
  lfs       f6, 0x4(r28)
  lfs       f7, 0x4(r29)
  fsubs     f2, f4, f5
  stfs      f0, 0xD4(r1)
  fsubs     f0, f6, f7
  fmuls     f3, f25, f2
  lfs       f2, 0xD4(r1)
  fmuls     f0, f26, f0
  fmuls     f2, f27, f2
  fadds     f0, f2, f0
  fadds     f0, f3, f0
  fdivs     f24, f0, f1
  fcmpo     cr0, f24, f28
  blt-      .loc_0x51C
  fcmpo     cr0, f24, f31
  ble-      .loc_0x638

.loc_0x51C:
  fsubs     f0, f7, f6
  fsubs     f1, f9, f8
  fsubs     f2, f5, f4
  fmuls     f0, f0, f0
  fmuls     f1, f1, f1
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  fcmpo     cr0, f0, f28
  ble-      .loc_0x594
  fsqrte    f2, f0
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f0, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f0, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f0, f1
  fsub      f1, f30, f1
  fmul      f1, f2, f1
  fmul      f0, f0, f1
  frsp      f0, f0
  stfs      f0, 0xA0(r1)
  lfs       f0, 0xA0(r1)

.loc_0x594:
  lfs       f4, 0x4(r30)
  lfs       f3, 0x4(r28)
  lfs       f2, 0x0(r30)
  lfs       f1, 0x0(r28)
  fsubs     f4, f4, f3
  lfs       f3, 0x8(r30)
  fsubs     f5, f2, f1
  lfs       f2, 0x8(r28)
  fmuls     f1, f4, f4
  fsubs     f3, f3, f2
  fmuls     f2, f5, f5
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f3, f3, f1
  fcmpo     cr0, f3, f28
  ble-      .loc_0x624
  fsqrte    f2, f3
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f3, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f3, f1
  fsub      f1, f30, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f29, f2
  fmul      f1, f3, f1
  fsub      f1, f30, f1
  fmul      f1, f2, f1
  fmul      f1, f3, f1
  frsp      f1, f1
  stfs      f1, 0x9C(r1)
  lfs       f3, 0x9C(r1)

.loc_0x624:
  fcmpo     cr0, f3, f0
  bge-      .loc_0x6D8
  fmr       f0, f3
  b         .loc_0x6D8
  b         .loc_0x6D8

.loc_0x638:
  fmuls     f0, f24, f1
  addi      r4, r19, 0
  addi      r5, r18, 0
  addi      r6, r17, 0
  fmuls     f2, f25, f0
  fmuls     f1, f26, f0
  addi      r3, r1, 0xE0
  fmuls     f0, f27, f0
  stfs      f2, 0x94(r1)
  stfs      f1, 0x90(r1)
  stfs      f0, 0x8C(r1)
  bl        -0x69EC8
  lfs       f3, 0xE0(r1)
  fsubs     f4, f31, f24
  lfs       f2, 0x0(r29)
  lfs       f1, 0xE4(r1)
  lfs       f0, 0x4(r29)
  fadds     f6, f3, f2
  lfs       f5, 0x0(r28)
  fadds     f3, f1, f0
  lfs       f2, 0x4(r28)
  fsubs     f7, f6, f5
  lfs       f1, 0xE8(r1)
  lfs       f0, 0x8(r29)
  fsubs     f6, f3, f2
  lfs       f3, 0xC(r29)
  lfs       f2, 0xC(r30)
  fadds     f1, f1, f0
  lfs       f0, 0x8(r28)
  fsubs     f5, f1, f0
  fmuls     f1, f7, f7
  fmuls     f0, f6, f6
  fmuls     f4, f4, f3
  fmuls     f3, f24, f2
  fmuls     f2, f5, f5
  fadds     f0, f1, f0
  fadds     f24, f4, f3
  fadds     f1, f2, f0
  bl        -0x93410
  fsubs     f0, f1, f24

.loc_0x6D8:
  fcmpo     cr0, f23, f0
  ble-      .loc_0x6EC
  fmr       f23, f0
  addi      r15, r29, 0
  addi      r16, r30, 0

.loc_0x6EC:
  addi      r27, r27, 0x1
  cmpwi     r27, 0x8
  addi      r26, r26, 0x4
  blt+      .loc_0x204

.loc_0x6FC:
  lwz       r3, 0x164(r1)
  addi      r14, r14, 0x1
  addi      r3, r3, 0xC4
  stw       r3, 0x164(r1)

.loc_0x70C:
  lwz       r0, 0x20(r22)
  add       r3, r21, r0
  lwz       r0, 0x4(r3)
  cmpw      r14, r0
  blt+      .loc_0x190
  lwz       r3, 0x15C(r1)
  stw       r15, 0x0(r3)
  lwz       r3, 0x160(r1)
  stw       r16, 0x0(r3)

.loc_0x730:
  lmw       r14, 0x168(r1)
  lwz       r0, 0x1FC(r1)
  lfd       f31, 0x1F0(r1)
  lfd       f30, 0x1E8(r1)
  lfd       f29, 0x1E0(r1)
  lfd       f28, 0x1D8(r1)
  lfd       f27, 0x1D0(r1)
  lfd       f26, 0x1C8(r1)
  lfd       f25, 0x1C0(r1)
  lfd       f24, 0x1B8(r1)
  lfd       f23, 0x1B0(r1)
  addi      r1, r1, 0x1F8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A10E8
 * Size:	00016C
 */
void RouteMgr::findNearestWayPoint(unsigned long, Vector3f &, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r6, 0
  stw       r30, 0x48(r1)
  addi      r30, r5, 0
  stw       r29, 0x44(r1)
  addi      r29, r3, 0
  bl        0xA34
  cmpwi     r3, -0x1
  beq-      .loc_0x14C
  lfs       f0, -0x72D0(r2)
  rlwinm    r6,r3,3,0,28
  lfs       f5, -0x72CC(r2)
  rlwinm    r3,r31,0,24,31
  lfd       f4, -0x72C0(r2)
  lfd       f3, -0x72B8(r2)
  li        r8, -0x1
  li        r9, 0
  li        r4, 0
  b         .loc_0x128

.loc_0x58:
  lwz       r0, 0x0(r5)
  cmplwi    r3, 0
  add       r5, r0, r4
  beq-      .loc_0x74
  lbz       r0, 0x40(r5)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x120

.loc_0x74:
  lbz       r0, 0x38(r5)
  cmplwi    r0, 0
  beq-      .loc_0x120
  lfs       f7, 0x4(r5)
  lfs       f6, 0x4(r30)
  lfs       f2, 0x0(r5)
  lfs       f1, 0x0(r30)
  fsubs     f7, f7, f6
  lfs       f6, 0x8(r5)
  fsubs     f8, f2, f1
  lfs       f2, 0x8(r30)
  fmuls     f1, f7, f7
  fsubs     f6, f6, f2
  fmuls     f2, f8, f8
  fmuls     f6, f6, f6
  fadds     f1, f2, f1
  fadds     f6, f6, f1
  fcmpo     cr0, f6, f5
  ble-      .loc_0x110
  fsqrte    f2, f6
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f1, f2, f1
  fmul      f1, f6, f1
  frsp      f1, f1
  stfs      f1, 0x28(r1)
  lfs       f6, 0x28(r1)

.loc_0x110:
  fcmpo     cr0, f0, f6
  ble-      .loc_0x120
  fmr       f0, f6
  mr        r8, r9

.loc_0x120:
  addi      r4, r4, 0xC4
  addi      r9, r9, 0x1

.loc_0x128:
  lwz       r7, 0x20(r29)
  add       r5, r6, r7
  lwz       r0, 0x4(r5)
  cmpw      r9, r0
  blt+      .loc_0x58
  mulli     r0, r8, 0xC4
  lwzx      r3, r7, r6
  add       r3, r3, r0
  b         .loc_0x150

.loc_0x14C:
  li        r3, 0

.loc_0x150:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  lwz       r29, 0x44(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A1254
 * Size:	00016C
 */
void RouteMgr::findNearestOffWayPoint(unsigned long, Vector3f &, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r6, 0
  stw       r30, 0x48(r1)
  addi      r30, r5, 0
  stw       r29, 0x44(r1)
  addi      r29, r3, 0
  bl        0x8C8
  cmpwi     r3, -0x1
  beq-      .loc_0x14C
  lfs       f0, -0x72D0(r2)
  rlwinm    r6,r3,3,0,28
  lfs       f5, -0x72CC(r2)
  rlwinm    r3,r31,0,24,31
  lfd       f4, -0x72C0(r2)
  lfd       f3, -0x72B8(r2)
  li        r8, -0x1
  li        r9, 0
  li        r4, 0
  b         .loc_0x128

.loc_0x58:
  lwz       r0, 0x0(r5)
  cmplwi    r3, 0
  add       r5, r0, r4
  beq-      .loc_0x74
  lbz       r0, 0x40(r5)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x120

.loc_0x74:
  lbz       r0, 0x38(r5)
  cmplwi    r0, 0
  bne-      .loc_0x120
  lfs       f7, 0x4(r5)
  lfs       f6, 0x4(r30)
  lfs       f2, 0x0(r5)
  lfs       f1, 0x0(r30)
  fsubs     f7, f7, f6
  lfs       f6, 0x8(r5)
  fsubs     f8, f2, f1
  lfs       f2, 0x8(r30)
  fmuls     f1, f7, f7
  fsubs     f6, f6, f2
  fmuls     f2, f8, f8
  fmuls     f6, f6, f6
  fadds     f1, f2, f1
  fadds     f6, f6, f1
  fcmpo     cr0, f6, f5
  ble-      .loc_0x110
  fsqrte    f2, f6
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f1, f2, f1
  fmul      f1, f6, f1
  frsp      f1, f1
  stfs      f1, 0x28(r1)
  lfs       f6, 0x28(r1)

.loc_0x110:
  fcmpo     cr0, f0, f6
  ble-      .loc_0x120
  fmr       f0, f6
  mr        r8, r9

.loc_0x120:
  addi      r4, r4, 0xC4
  addi      r9, r9, 0x1

.loc_0x128:
  lwz       r7, 0x20(r29)
  add       r5, r6, r7
  lwz       r0, 0x4(r5)
  cmpw      r9, r0
  blt+      .loc_0x58
  mulli     r0, r8, 0xC4
  lwzx      r3, r7, r6
  add       r3, r3, r0
  b         .loc_0x150

.loc_0x14C:
  li        r3, 0

.loc_0x150:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  lwz       r29, 0x44(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A13C0
 * Size:	00017C
 */
void RouteMgr::createOffPlane(unsigned long, Plane &, WayPoint *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r31, r6, 0
  stw       r30, 0x58(r1)
  addi      r30, r5, 0
  stw       r29, 0x54(r1)
  addi      r29, r3, 0
  bl        0x75C
  cmpwi     r3, -0x1
  beq-      .loc_0x160
  lwz       r0, 0x34(r31)
  cmpwi     r0, 0
  ble-      .loc_0x160
  li        r0, 0x8
  mtctr     r0
  addi      r4, r31, 0
  li        r5, -0x1
  li        r6, 0

.loc_0x50:
  lwz       r0, 0x14(r4)
  cmpwi     r0, -0x1
  beq-      .loc_0x6C
  rlwinm    r0,r6,2,0,29
  add       r4, r31, r0
  lwz       r5, 0x14(r4)
  b         .loc_0x78

.loc_0x6C:
  addi      r4, r4, 0x4
  addi      r6, r6, 0x1
  bdnz+     .loc_0x50

.loc_0x78:
  cmpwi     r5, -0x1
  beq-      .loc_0x160
  lwz       r4, 0x20(r29)
  rlwinm    r3,r3,3,0,28
  mulli     r0, r5, 0xC4
  lfs       f0, 0x0(r31)
  lwzx      r3, r4, r3
  lfs       f2, 0x4(r31)
  add       r3, r3, r0
  lfs       f1, 0x0(r3)
  lfs       f3, 0x4(r3)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r3)
  lfs       f1, 0x8(r31)
  fsubs     f2, f3, f2
  stfs      f0, 0x40(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x44(r1)
  stfs      f0, 0x48(r1)
  lfs       f1, 0x40(r1)
  lfs       f0, 0x44(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x48(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x93864
  lfs       f0, -0x72CC(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x118
  lfs       f0, 0x40(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x40(r1)
  lfs       f0, 0x44(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x44(r1)
  lfs       f0, 0x48(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x48(r1)

.loc_0x118:
  lwz       r3, 0x40(r1)
  lwz       r0, 0x44(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0x48(r1)
  stw       r0, 0x8(r30)
  lfs       f3, 0x40(r1)
  lfs       f2, 0x0(r31)
  lfs       f1, 0x44(r1)
  lfs       f0, 0x4(r31)
  fmuls     f2, f3, f2
  lfs       f3, 0x48(r1)
  fmuls     f0, f1, f0
  lfs       f1, 0x8(r31)
  fmuls     f1, f3, f1
  fadds     f0, f2, f0
  fadds     f0, f1, f0
  stfs      f0, 0xC(r30)

.loc_0x160:
  lwz       r0, 0x64(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  lwz       r29, 0x54(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void RouteMgr::dump(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A153C
 * Size:	00013C
 */
void RouteMgr::findNearestWayPointAll(unsigned long, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r31, r5, 0
  stw       r30, 0x38(r1)
  addi      r30, r3, 0
  bl        0x5E8
  cmpwi     r3, -0x1
  beq-      .loc_0x120
  lfs       f0, -0x72D0(r2)
  rlwinm    r5,r3,3,0,28
  lfs       f5, -0x72CC(r2)
  li        r7, -0x1
  lfd       f4, -0x72C0(r2)
  lfd       f3, -0x72B8(r2)
  li        r8, 0
  li        r4, 0
  b         .loc_0xFC

.loc_0x4C:
  lwz       r0, 0x0(r3)
  lfs       f6, 0x4(r31)
  add       r3, r0, r4
  lfs       f1, 0x0(r31)
  lfs       f7, 0x4(r3)
  lfs       f2, 0x0(r3)
  fsubs     f7, f7, f6
  lfs       f6, 0x8(r3)
  fsubs     f2, f2, f1
  lfs       f1, 0x8(r31)
  fsubs     f6, f6, f1
  fmuls     f2, f2, f2
  fmuls     f1, f7, f7
  fmuls     f6, f6, f6
  fadds     f1, f2, f1
  fadds     f6, f6, f1
  fcmpo     cr0, f6, f5
  ble-      .loc_0xE4
  fsqrte    f2, f6
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f4, f2
  fmul      f1, f6, f1
  fsub      f1, f3, f1
  fmul      f1, f2, f1
  fmul      f1, f6, f1
  frsp      f1, f1
  stfs      f1, 0x24(r1)
  lfs       f6, 0x24(r1)

.loc_0xE4:
  fcmpo     cr0, f0, f6
  ble-      .loc_0xF4
  fmr       f0, f6
  mr        r7, r8

.loc_0xF4:
  addi      r4, r4, 0xC4
  addi      r8, r8, 0x1

.loc_0xFC:
  lwz       r6, 0x20(r30)
  add       r3, r5, r6
  lwz       r0, 0x4(r3)
  cmpw      r8, r0
  blt+      .loc_0x4C
  mulli     r0, r7, 0xC4
  lwzx      r3, r6, r5
  add       r3, r3, r0
  b         .loc_0x124

.loc_0x120:
  li        r3, 0

.loc_0x124:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A1678
 * Size:	00005C
 */
void RouteMgr::getWayPoint(unsigned long, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r5, 0
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  bl        0x4AC
  cmpwi     r3, -0x1
  beq-      .loc_0x40
  lwz       r4, 0x20(r30)
  rlwinm    r3,r3,3,0,28
  mulli     r0, r31, 0xC4
  lwzx      r3, r4, r3
  add       r3, r3, r0
  b         .loc_0x44

.loc_0x40:
  li        r3, 0

.loc_0x44:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A16D4
 * Size:	00009C
 */
void RouteMgr::RouteMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x738C
  subi      r4, r13, 0x53C4
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lis       r3, 0x8022
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x737C
  addi      r3, r30, 0
  stw       r0, 0x0(r30)
  stw       r31, 0x10(r30)
  stw       r31, 0xC(r30)
  stw       r31, 0x8(r30)
  bl        -0x7C848
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  subi      r4, r13, 0x53C4
  bl        -0x60FF8
  lis       r3, 0x802B
  addi      r0, r3, 0x1B3C
  stw       r0, 0x0(r30)
  mr        r3, r30
  stw       r31, 0x28(r30)
  stw       r31, 0x20(r30)
  stw       r31, 0x24(r30)
  stw       r31, 0x2C(r30)
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
 * Address:	800A1770
 * Size:	000014
 */
void WayPoint::setFlag(bool)
{
/*
.loc_0x0:
  stb       r4, 0x38(r3)
  rlwinm    r0,r4,0,24,31
  lwz       r3, 0x3C(r3)
  stw       r0, 0x34(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A1784
 * Size:	000274
 */
void RouteMgr::construct(MapMgr *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stmw      r15, 0x44(r1)
  mr        r31, r4
  addi      r30, r3, 0
  lwz       r4, 0x60(r4)
  addi      r3, r4, 0x178
  bl        -0x61124
  stw       r3, 0x28(r30)
  lwz       r0, 0x28(r30)
  cmpwi     r0, 0
  beq-      .loc_0x260
  rlwinm    r3,r0,2,0,29
  bl        -0x5A7B8
  stw       r3, 0x2C(r30)
  lwz       r0, 0x28(r30)
  rlwinm    r3,r0,3,0,28
  bl        -0x5A7C8
  stw       r3, 0x20(r30)
  lwz       r0, 0x28(r30)
  rlwinm    r3,r0,2,0,29
  bl        -0x5A7D8
  stw       r3, 0x24(r30)
  li        r26, 0
  lis       r3, 0x800A
  lwz       r5, 0x60(r31)
  lis       r4, 0x800A
  addi      r29, r26, 0
  lwz       r28, 0x188(r5)
  subi      r22, r3, 0xA1C
  addi      r24, r4, 0x19F8
  li        r25, 0
  b         .loc_0x254

.loc_0x88:
  lwz       r5, 0x20(r30)
  addi      r3, r28, 0x68
  lwz       r0, 0x58(r28)
  lwz       r4, 0x2C(r30)
  add       r27, r5, r26
  stwx      r0, r4, r29
  bl        -0x611A4
  stw       r3, 0x4(r27)
  lwz       r18, 0x4(r27)
  mulli     r3, r18, 0xC4
  addi      r3, r3, 0x8
  bl        -0x5A834
  addi      r4, r24, 0
  addi      r7, r18, 0
  li        r5, 0
  li        r6, 0xC4
  bl        0x1733DC
  stw       r3, 0x0(r27)
  li        r3, 0x1C
  lwz       r23, 0x78(r28)
  bl        -0x5A858
  addi      r21, r3, 0
  mr.       r0, r21
  beq-      .loc_0x14C
  stw       r27, 0x0(r21)
  lwz       r3, 0x0(r21)
  lwz       r0, 0x4(r3)
  stw       r0, 0x4(r21)
  lwz       r18, 0x4(r21)
  rlwinm    r3,r18,3,0,28
  addi      r3, r3, 0x8
  bl        -0x5A884
  addi      r4, r22, 0
  addi      r7, r18, 0
  li        r5, 0
  li        r6, 0x8
  bl        0x17338C
  stw       r3, 0x8(r21)
  li        r4, 0
  li        r3, 0x1
  sth       r4, 0x3028(r13)
  li        r0, 0x64
  stw       r3, 0xC(r21)
  stw       r4, 0x10(r21)
  stw       r0, 0x14(r21)
  lwz       r0, 0x14(r21)
  mulli     r3, r0, 0x28
  bl        -0x5A8C4
  stw       r3, 0x18(r21)

.loc_0x14C:
  lwz       r3, 0x24(r30)
  li        r19, 0
  li        r20, 0
  stwx      r21, r3, r29
  b         .loc_0x238

.loc_0x160:
  lwz       r4, 0x0(r27)
  li        r3, 0x1
  li        r0, 0
  add       r21, r4, r20
  stb       r3, 0x38(r21)
  addi      r3, r31, 0
  li        r4, 0x1
  stw       r19, 0x10(r21)
  lwz       r6, 0x28(r23)
  lwz       r5, 0x2C(r23)
  stw       r6, 0x0(r21)
  stw       r5, 0x4(r21)
  lwz       r5, 0x30(r23)
  stw       r5, 0x8(r21)
  stb       r0, 0x40(r21)
  lfs       f1, 0x0(r21)
  lfs       f2, 0x8(r21)
  bl        -0x39750
  cmplwi    r3, 0
  beq-      .loc_0x1C8
  bl        0x7474C
  cmpwi     r3, 0x5
  bne-      .loc_0x1C8
  lbz       r0, 0x40(r21)
  ori       r0, r0, 0x1
  stb       r0, 0x40(r21)

.loc_0x1C8:
  lfs       f0, 0x24(r23)
  addi      r3, r23, 0x3C
  stfs      f0, 0xC(r21)
  stw       r23, 0x3C(r21)
  bl        -0x612DC
  mr        r18, r3
  stw       r18, 0x34(r21)
  addi      r17, r21, 0
  li        r15, 0
  lwz       r16, 0x4C(r23)
  li        r21, -0x1

.loc_0x1F4:
  cmpw      r18, r15
  bgt-      .loc_0x204
  stw       r21, 0x14(r17)
  b         .loc_0x21C

.loc_0x204:
  lwz       r5, 0x14(r16)
  addi      r3, r30, 0
  addi      r4, r28, 0
  bl        0x1F4
  stw       r3, 0x14(r17)
  lwz       r16, 0xC(r16)

.loc_0x21C:
  addi      r15, r15, 0x1
  cmpwi     r15, 0x8
  addi      r17, r17, 0x4
  blt+      .loc_0x1F4
  lwz       r23, 0xC(r23)
  addi      r20, r20, 0xC4
  addi      r19, r19, 0x1

.loc_0x238:
  lwz       r0, 0x4(r27)
  cmpw      r19, r0
  blt+      .loc_0x160
  lwz       r28, 0xC(r28)
  addi      r26, r26, 0x8
  addi      r29, r29, 0x4
  addi      r25, r25, 0x1

.loc_0x254:
  lwz       r0, 0x28(r30)
  cmpw      r25, r0
  blt+      .loc_0x88

.loc_0x260:
  lmw       r15, 0x44(r1)
  lwz       r0, 0x8C(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A19F8
 * Size:	000014
 */
void WayPoint::WayPoint()
{
/*
.loc_0x0:
  lfs       f0, -0x72CC(r2)
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A1A0C
 * Size:	000134
 */
void RouteMgr::initLinks()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x7465
  stw       r0, 0x4(r1)
  li        r0, 0
  addi      r4, r4, 0x7374
  stwu      r1, -0x28(r1)
  stmw      r26, 0x10(r1)
  addi      r31, r3, 0
  lwz       r5, 0x2DEC(r13)
  addi      r6, r5, 0x2A4
  lwz       r5, 0x2A4(r5)
  neg       r5, r5
  stw       r0, 0x0(r6)
  subic     r0, r5, 0x1
  subfe     r0, r0, r5
  rlwinm    r29,r0,0,24,31
  bl        .loc_0x134
  cmpwi     r3, -0x1
  beq-      .loc_0x60
  lwz       r4, 0x20(r31)
  rlwinm    r0,r3,3,0,28
  add       r3, r4, r0
  lwz       r28, 0x4(r3)
  b         .loc_0x64

.loc_0x60:
  li        r28, -0x1

.loc_0x64:
  li        r26, 0
  li        r27, 0
  lis       r30, 0x7465
  b         .loc_0xB0

.loc_0x74:
  addi      r3, r31, 0
  addi      r4, r30, 0x7374
  bl        .loc_0x134
  cmpwi     r3, -0x1
  beq-      .loc_0x9C
  lwz       r4, 0x20(r31)
  rlwinm    r0,r3,3,0,28
  lwzx      r0, r4, r0
  add       r0, r0, r27
  b         .loc_0xA0

.loc_0x9C:
  li        r0, 0

.loc_0xA0:
  mr        r3, r0
  bl        0x104
  addi      r27, r27, 0xC4
  addi      r26, r26, 0x1

.loc_0xB0:
  cmpw      r26, r28
  blt+      .loc_0x74
  li        r26, 0
  addi      r27, r26, 0
  lis       r30, 0x7465
  b         .loc_0x104

.loc_0xC8:
  addi      r3, r31, 0
  addi      r4, r30, 0x7374
  bl        .loc_0x134
  cmpwi     r3, -0x1
  beq-      .loc_0xF0
  lwz       r4, 0x20(r31)
  rlwinm    r0,r3,3,0,28
  lwzx      r0, r4, r0
  add       r0, r0, r27
  b         .loc_0xF4

.loc_0xF0:
  li        r0, 0

.loc_0xF4:
  mr        r3, r0
  bl        0x140
  addi      r27, r27, 0xC4
  addi      r26, r26, 0x1

.loc_0x104:
  cmpw      r26, r28
  blt+      .loc_0xC8
  lwz       r3, 0x2DEC(r13)
  li        r0, 0
  stw       r29, 0x2A4(r3)
  lwz       r3, 0x2DEC(r13)
  stw       r0, 0x2A0(r3)
  lwz       r0, 0x2C(r1)
  lmw       r26, 0x10(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr       

.loc_0x134:
*/
}

/*
 * --INFO--
 * Address:	800A1B40
 * Size:	000048
 */
void RouteMgr::id2idx(unsigned long)
{
/*
.loc_0x0:
  lwz       r5, 0x2C(r3)
  cmplwi    r5, 0
  bne-      .loc_0x14
  li        r3, -0x1
  blr       

.loc_0x14:
  lwz       r0, 0x28(r3)
  li        r3, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x40

.loc_0x28:
  lwz       r0, 0x0(r5)
  cmplw     r4, r0
  beqlr-    
  addi      r5, r5, 0x4
  addi      r3, r3, 0x1
  bdnz+     .loc_0x28

.loc_0x40:
  li        r3, -0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void RouteMgr::idx2id(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A1B88
 * Size:	00002C
 */
void RouteMgr::getColinIndex(RouteGroup *, RoutePoint *)
{
/*
.loc_0x0:
  lwz       r4, 0x78(r4)
  li        r3, 0
  b         .loc_0x1C

.loc_0xC:
  cmplw     r4, r5
  beqlr-    
  lwz       r4, 0xC(r4)
  addi      r3, r3, 0x1

.loc_0x1C:
  cmplwi    r4, 0
  bne+      .loc_0xC
  li        r3, -0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void RouteTracer::RouteTracer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void RouteTracer::Context::PointInfo::PointInfo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000764
 */
void RouteTracer::render(Graphics &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000278
 */
void RouteTracer::Context::makeContext(RouteTracer *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002EC
 */
void RouteTracer::Context::setTarget(RouteTracer *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000224
 */
void RouteTracer::Context::recognise(RouteTracer *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void RouteTracer::noLink()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void RouteTracer::startConsult(Creature *, PathFinder *, PathFinder::Buffer *, int, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000364
 */
void RouteTracer::updateState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void RouteTracer::getTarget()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void WayPoint::getLinkIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A1BB4
 * Size:	000090
 */
void WayPoint::resetLinkInfos()
{
/*
.loc_0x0:
  li        r0, -0x2
  stw       r0, 0x44(r3)
  addi      r4, r3, 0x44
  addi      r3, r3, 0x10
  stw       r0, 0x4(r4)
  stw       r0, 0x8(r4)
  stw       r0, 0xC(r4)
  stw       r0, 0x44(r3)
  stw       r0, 0x48(r3)
  stw       r0, 0x4C(r3)
  stw       r0, 0x50(r3)
  stw       r0, 0x54(r3)
  stw       r0, 0x58(r3)
  stw       r0, 0x5C(r3)
  stw       r0, 0x60(r3)
  stw       r0, 0x64(r3)
  stw       r0, 0x68(r3)
  stw       r0, 0x6C(r3)
  stw       r0, 0x70(r3)
  stw       r0, 0x74(r3)
  stw       r0, 0x78(r3)
  stw       r0, 0x7C(r3)
  stw       r0, 0x80(r3)
  stw       r0, 0x84(r3)
  stw       r0, 0x88(r3)
  stw       r0, 0x8C(r3)
  stw       r0, 0x90(r3)
  stw       r0, 0x94(r3)
  stw       r0, 0x98(r3)
  stw       r0, 0x9C(r3)
  stw       r0, 0xA0(r3)
  stw       r0, 0xA4(r3)
  stw       r0, 0xA8(r3)
  stw       r0, 0xAC(r3)
  stw       r0, 0xB0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A1C44
 * Size:	0003BC
 */
void WayPoint::initLinkInfos()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stfd      f31, 0xD8(r1)
  stfd      f30, 0xD0(r1)
  stfd      f29, 0xC8(r1)
  stmw      r17, 0x8C(r1)
  mr        r18, r3
  addi      r25, r18, 0
  mr        r24, r18
  li        r23, 0
  lis       r31, 0x7465
  lhz       r0, 0x3028(r13)
  lfs       f29, -0x72CC(r2)
  ori       r0, r0, 0x2
  lfd       f30, -0x72C0(r2)
  sth       r0, 0x3028(r13)
  lfd       f31, -0x72B8(r2)
  lwz       r0, 0x10(r3)
  stw       r0, -0x53C8(r13)

.loc_0x50:
  lwz       r0, 0x14(r24)
  addi      r3, r25, 0x44
  cmpwi     r0, -0x1
  bne-      .loc_0x78
  li        r0, -0x2
  stw       r0, 0x0(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x8(r3)
  stw       r0, 0xC(r3)
  b         .loc_0x380

.loc_0x78:
  addi      r27, r3, 0
  li        r22, 0
  li        r26, 0

.loc_0x84:
  cmpwi     r22, 0x3
  li        r17, -0x1
  beq-      .loc_0xBC
  bge-      .loc_0xD0
  cmpwi     r22, 0
  bge-      .loc_0xA0
  b         .loc_0xD0

.loc_0xA0:
  lwz       r3, 0x30AC(r13)
  mr        r4, r22
  bl        0x50CCC
  cmplwi    r3, 0
  beq-      .loc_0xD0
  lha       r17, 0x42A(r3)
  b         .loc_0xD0

.loc_0xBC:
  lwz       r3, 0x30AC(r13)
  bl        0x50F34
  cmplwi    r3, 0
  beq-      .loc_0xD0
  lwz       r17, 0x558(r3)

.loc_0xD0:
  cmpwi     r17, -0x1
  beq-      .loc_0x364
  lwz       r19, 0x302C(r13)
  addi      r4, r31, 0x7374
  lwz       r20, 0x14(r24)
  mr        r3, r19
  bl        -0x1EC
  cmpwi     r3, -0x1
  beq-      .loc_0x104
  lwz       r4, 0x24(r19)
  rlwinm    r0,r3,2,0,29
  lwzx      r30, r4, r0
  b         .loc_0x108

.loc_0x104:
  li        r30, 0

.loc_0x108:
  lwz       r4, 0x8(r30)
  mr        r3, r30
  addi      r5, r20, 0
  addi      r6, r17, 0
  li        r7, 0x1
  bl        -0x2190
  cmpwi     r3, 0
  bne-      .loc_0x134
  li        r0, -0x2
  stw       r0, 0x0(r27)
  b         .loc_0x36C

.loc_0x134:
  subi      r21, r3, 0x1
  rlwinm    r28,r21,3,0,28
  li        r20, 0
  b         .loc_0x358

.loc_0x144:
  lwz       r0, 0x8(r30)
  cmpwi     r21, 0
  add       r3, r0, r28
  lwz       r19, 0x0(r3)
  bne-      .loc_0x160
  lwz       r17, 0x10(r18)
  b         .loc_0x164

.loc_0x160:
  lwz       r17, -0x8(r3)

.loc_0x164:
  lwz       r29, 0x302C(r13)
  addi      r4, r31, 0x7374
  addi      r3, r29, 0
  bl        -0x274
  cmpwi     r3, -0x1
  beq-      .loc_0x194
  lwz       r4, 0x20(r29)
  rlwinm    r3,r3,3,0,28
  mulli     r0, r17, 0xC4
  lwzx      r3, r4, r3
  add       r29, r3, r0
  b         .loc_0x198

.loc_0x194:
  li        r29, 0

.loc_0x198:
  lwz       r17, 0x302C(r13)
  addi      r4, r31, 0x7374
  addi      r3, r17, 0
  bl        -0x2A8
  cmpwi     r3, -0x1
  beq-      .loc_0x1C8
  lwz       r4, 0x20(r17)
  rlwinm    r3,r3,3,0,28
  mulli     r0, r19, 0xC4
  lwzx      r3, r4, r3
  add       r3, r3, r0
  b         .loc_0x1CC

.loc_0x1C8:
  li        r3, 0

.loc_0x1CC:
  lwz       r0, 0x14(r29)
  cmpw      r0, r19
  bne-      .loc_0x1E0
  li        r0, 0
  b         .loc_0x288

.loc_0x1E0:
  addi      r4, r29, 0x4
  lwz       r0, 0x18(r29)
  cmpw      r0, r19
  bne-      .loc_0x1F8
  li        r0, 0x1
  b         .loc_0x288

.loc_0x1F8:
  lwz       r0, 0x18(r4)
  addi      r4, r4, 0x4
  cmpw      r0, r19
  bne-      .loc_0x210
  li        r0, 0x2
  b         .loc_0x288

.loc_0x210:
  lwz       r0, 0x18(r4)
  addi      r4, r4, 0x4
  cmpw      r0, r19
  bne-      .loc_0x228
  li        r0, 0x3
  b         .loc_0x288

.loc_0x228:
  lwz       r0, 0x18(r4)
  addi      r4, r4, 0x4
  cmpw      r0, r19
  bne-      .loc_0x240
  li        r0, 0x4
  b         .loc_0x288

.loc_0x240:
  lwz       r0, 0x18(r4)
  addi      r4, r4, 0x4
  cmpw      r0, r19
  bne-      .loc_0x258
  li        r0, 0x5
  b         .loc_0x288

.loc_0x258:
  lwz       r0, 0x18(r4)
  addi      r4, r4, 0x4
  cmpw      r0, r19
  bne-      .loc_0x270
  li        r0, 0x6
  b         .loc_0x288

.loc_0x270:
  lwz       r0, 0x18(r4)
  cmpw      r0, r19
  bne-      .loc_0x284
  li        r0, 0x7
  b         .loc_0x288

.loc_0x284:
  li        r0, -0x1

.loc_0x288:
  lfs       f3, 0x4(r29)
  lfs       f2, 0x4(r3)
  lfs       f1, 0x0(r29)
  lfs       f0, 0x0(r3)
  fsubs     f3, f3, f2
  lfs       f2, 0x8(r29)
  fsubs     f4, f1, f0
  lfs       f1, 0x8(r3)
  fmuls     f0, f3, f3
  fsubs     f2, f2, f1
  fmuls     f1, f4, f4
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x318
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0x3C(r1)
  lfs       f2, 0x3C(r1)

.loc_0x318:
  rlwinm    r0,r0,4,0,27
  fctiwz    f0, f2
  add       r3, r29, r0
  addi      r4, r3, 0x44
  add       r4, r26, r4
  stfd      f0, 0x80(r1)
  lwz       r3, 0x0(r4)
  lwz       r0, 0x84(r1)
  cmpwi     r3, 0
  add       r20, r20, r0
  blt-      .loc_0x34C
  cmpw      r3, r20
  ble-      .loc_0x350

.loc_0x34C:
  stw       r20, 0x0(r4)

.loc_0x350:
  subi      r28, r28, 0x8
  subi      r21, r21, 0x1

.loc_0x358:
  cmpwi     r21, 0
  bge+      .loc_0x144
  b         .loc_0x36C

.loc_0x364:
  li        r0, -0x2
  stw       r0, 0x0(r27)

.loc_0x36C:
  addi      r22, r22, 0x1
  cmpwi     r22, 0x4
  addi      r27, r27, 0x4
  addi      r26, r26, 0x4
  blt+      .loc_0x84

.loc_0x380:
  addi      r23, r23, 0x1
  cmpwi     r23, 0x8
  addi      r25, r25, 0x10
  addi      r24, r24, 0x4
  blt+      .loc_0x50
  li        r0, 0
  sth       r0, 0x3028(r13)
  lmw       r17, 0x8C(r1)
  lwz       r0, 0xE4(r1)
  lfd       f31, 0xD8(r1)
  lfd       f30, 0xD0(r1)
  lfd       f29, 0xC8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void PathFinder::findFirstStepOnyon(int, int, PathFinder::Buffer *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A2000
 * Size:	000580
 */
void PathFinder::findSyncOnyon(Vector3f &, PathFinder::Buffer *, int, int, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x198(r1)
  stfd      f31, 0x190(r1)
  stfd      f30, 0x188(r1)
  stfd      f29, 0x180(r1)
  stmw      r18, 0x148(r1)
  addi      r28, r7, 0
  cmpwi     r28, 0x3
  addi      r26, r3, 0
  addi      r19, r4, 0
  addi      r27, r5, 0
  addi      r18, r6, 0
  addi      r29, r8, 0
  li        r22, -0x1
  beq-      .loc_0x6C
  bge-      .loc_0x80
  cmpwi     r28, 0
  bge-      .loc_0x50
  b         .loc_0x80

.loc_0x50:
  lwz       r3, 0x30AC(r13)
  mr        r4, r28
  bl        0x50960
  cmplwi    r3, 0
  beq-      .loc_0x80
  lha       r22, 0x42A(r3)
  b         .loc_0x80

.loc_0x6C:
  lwz       r3, 0x30AC(r13)
  bl        0x50BC8
  cmplwi    r3, 0
  beq-      .loc_0x80
  lwz       r22, 0x558(r3)

.loc_0x80:
  cmpwi     r22, -0x1
  bne-      .loc_0x90
  li        r3, 0
  b         .loc_0x560

.loc_0x90:
  cmpw      r18, r22
  stw       r18, 0x0(r27)
  li        r21, 0
  bne-      .loc_0xA8
  li        r3, 0x1
  b         .loc_0x560

.loc_0xA8:
  rlwinm    r0,r21,3,0,28
  stw       r29, 0x8(r1)
  addi      r3, r26, 0
  addi      r4, r19, 0
  addi      r6, r28, 0
  addi      r8, r22, 0
  addi      r9, r27, 0
  addi      r5, r1, 0x134
  add       r7, r27, r0
  li        r20, 0
  li        r19, 0
  li        r31, 0
  li        r10, 0
  bl        0x708
  addi      r30, r3, 0
  cmpwi     r30, -0x1
  li        r0, 0x1
  lfs       f29, -0x72CC(r2)
  lfd       f30, -0x72C0(r2)
  slw       r24, r0, r30
  lfd       f31, -0x72B8(r2)
  li        r18, 0
  b         .loc_0x518

.loc_0x104:
  rlwinm    r0,r21,3,0,28
  lwz       r4, 0x0(r26)
  add       r23, r27, r0
  lwz       r3, 0x0(r23)
  rlwinm.   r0,r19,0,24,31
  lwz       r4, 0x0(r4)
  mulli     r0, r3, 0xC4
  add       r5, r4, r0
  addi      r19, r5, 0
  bne-      .loc_0x220
  li        r0, 0x2
  mtctr     r0
  li        r6, 0
  li        r4, 0x1

.loc_0x13C:
  lwz       r0, 0x14(r5)
  cmpwi     r0, -0x1
  bne-      .loc_0x15C
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r23)
  b         .loc_0x16C

.loc_0x15C:
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r23)

.loc_0x16C:
  lwz       r0, 0x18(r5)
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x194
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r23)
  b         .loc_0x1A4

.loc_0x194:
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r23)

.loc_0x1A4:
  lwz       r0, 0x18(r5)
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x1CC
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r23)
  b         .loc_0x1DC

.loc_0x1CC:
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r23)

.loc_0x1DC:
  lwz       r0, 0x18(r5)
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  cmpwi     r0, -0x1
  bne-      .loc_0x204
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  xor       r0, r3, r0
  stb       r0, 0x4(r23)
  b         .loc_0x214

.loc_0x204:
  lbz       r3, 0x4(r23)
  slw       r0, r4, r6
  or        r0, r3, r0
  stb       r0, 0x4(r23)

.loc_0x214:
  addi      r5, r5, 0x4
  addi      r6, r6, 0x1
  bdnz+     .loc_0x13C

.loc_0x220:
  addi      r3, r26, 0
  addi      r4, r31, 0
  addi      r5, r28, 0
  addi      r6, r23, 0
  addi      r7, r22, 0
  addi      r8, r27, 0
  addi      r9, r21, 0
  addi      r10, r29, 0
  bl        .loc_0x580
  rlwinm.   r0,r18,0,24,31
  beq-      .loc_0x2FC
  lwz       r0, 0x134(r1)
  cmpw      r31, r0
  ble-      .loc_0x2FC
  cmpwi     r21, 0
  mtctr     r21
  ble-      .loc_0x2CC

.loc_0x264:
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x1
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x2
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x4
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x8
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x10
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x20
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x40
  stb       r0, 0x4(r23)
  lbz       r0, 0x4(r23)
  ori       r0, r0, 0x80
  stb       r0, 0x4(r23)
  subi      r23, r23, 0x8
  bdnz+     .loc_0x264

.loc_0x2CC:
  lwz       r4, 0x0(r26)
  mr        r3, r30
  lwz       r0, 0x0(r27)
  li        r21, 0
  lwz       r5, 0x0(r4)
  mulli     r4, r0, 0xC4
  lbz       r0, 0x4(r27)
  xor       r0, r0, r24
  add       r4, r5, r4
  stb       r0, 0x4(r27)
  addi      r19, r4, 0
  li        r18, 0

.loc_0x2FC:
  cmpwi     r3, -0x1
  beq-      .loc_0x42C
  rlwinm    r4,r3,2,0,29
  lwz       r5, 0x0(r26)
  addi      r6, r4, 0x14
  lfs       f3, 0x4(r19)
  add       r6, r19, r6
  lwz       r4, 0x0(r5)
  lwz       r0, 0x0(r6)
  lfs       f1, 0x0(r19)
  mulli     r0, r0, 0xC4
  lfs       f4, 0x8(r19)
  add       r4, r4, r0
  lfs       f2, 0x4(r4)
  lfs       f0, 0x0(r4)
  fsubs     f3, f3, f2
  lfs       f2, 0x8(r4)
  fsubs     f1, f1, f0
  fsubs     f2, f4, f2
  fmuls     f0, f3, f3
  fmuls     f1, f1, f1
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x3B4
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0xCC(r1)
  lfs       f2, 0xCC(r1)

.loc_0x3B4:
  fctiwz    f0, f2
  lwz       r6, 0x0(r6)
  cmpw      r6, r22
  stfd      f0, 0x140(r1)
  lwz       r0, 0x144(r1)
  add       r31, r31, r0
  bne-      .loc_0x3E4
  addi      r21, r21, 0x1
  rlwinm    r0,r21,3,0,28
  stwx      r22, r27, r0
  li        r20, 0x1
  b         .loc_0x520

.loc_0x3E4:
  rlwinm    r4,r21,3,0,28
  addi      r5, r4, 0x4
  li        r0, 0x1
  lbzx      r4, r27, r5
  slw       r0, r0, r3
  xor       r0, r4, r0
  stbx      r0, r27, r5
  addi      r21, r21, 0x1
  lwz       r0, 0x4(r26)
  cmpw      r21, r0
  blt-      .loc_0x41C
  li        r19, 0x1
  subi      r21, r21, 0x1
  b         .loc_0x518

.loc_0x41C:
  rlwinm    r0,r21,3,0,28
  stwx      r6, r27, r0
  li        r19, 0
  b         .loc_0x518

.loc_0x42C:
  cmpwi     r21, 0x1
  li        r19, 0x1
  blt-      .loc_0x500
  rlwinm    r0,r21,3,0,28
  lwz       r4, 0x0(r26)
  add       r5, r27, r0
  lwz       r3, -0x8(r5)
  lwz       r0, 0x0(r5)
  mulli     r3, r3, 0xC4
  lwz       r4, 0x0(r4)
  add       r3, r4, r3
  mulli     r0, r0, 0xC4
  lfs       f2, 0x4(r3)
  lfs       f0, 0x0(r3)
  lfs       f4, 0x8(r3)
  add       r3, r4, r0
  lfs       f3, 0x4(r3)
  lfs       f1, 0x0(r3)
  fsubs     f3, f3, f2
  lfs       f2, 0x8(r3)
  fsubs     f1, f1, f0
  fsubs     f2, f2, f4
  fmuls     f0, f3, f3
  fmuls     f1, f1, f1
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x4F0
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0xC0(r1)
  lfs       f2, 0xC0(r1)

.loc_0x4F0:
  fctiwz    f0, f2
  stfd      f0, 0x140(r1)
  lwz       r0, 0x144(r1)
  sub       r31, r31, r0

.loc_0x500:
  rlwinm    r0,r21,3,0,28
  li        r3, -0x1
  subic.    r21, r21, 0x1
  stwx      r3, r27, r0
  bge-      .loc_0x518
  li        r20, 0x2

.loc_0x518:
  cmpwi     r20, 0
  beq+      .loc_0x104

.loc_0x520:
  cmpwi     r20, 0x1
  bne-      .loc_0x55C
  cmpwi     r21, 0
  addi      r3, r21, 0x1
  blt-      .loc_0x554
  rlwinm.   r0,r3,29,3,31
  mtctr     r0
  beq-      .loc_0x54C

.loc_0x540:
  bdnz-     .loc_0x540
  andi.     r3, r3, 0x7
  beq-      .loc_0x554

.loc_0x54C:
  mtctr     r3

.loc_0x550:
  bdnz-     .loc_0x550

.loc_0x554:
  addi      r3, r21, 0x1
  b         .loc_0x560

.loc_0x55C:
  li        r3, 0

.loc_0x560:
  lmw       r18, 0x148(r1)
  lwz       r0, 0x19C(r1)
  lfd       f31, 0x190(r1)
  lfd       f30, 0x188(r1)
  lfd       f29, 0x180(r1)
  addi      r1, r1, 0x198
  mtlr      r0
  blr       

.loc_0x580:
*/
}

/*
 * --INFO--
 * Address:	800A2580
 * Size:	000264
 */
void PathFinder::selectWayOnyon(int, int, PathFinder::Buffer &, int, PathFinder::Buffer *, int, bool)
{
/*
.loc_0x0:
  stwu      r1, -0x168(r1)
  li        r11, 0
  addi      r12, r11, 0
  stmw      r22, 0x140(r1)
  addi      r25, r1, 0x100
  addi      r26, r1, 0x120
  addi      r31, r25, 0
  addi      r30, r26, 0
  rlwinm    r5,r5,2,0,29
  rlwinm    r0,r10,0,24,31
  li        r24, -0x1
  li        r23, 0
  li        r22, 0

.loc_0x34:
  li        r4, 0x1
  lbz       r10, 0x4(r6)
  slw       r28, r4, r22
  and.      r4, r10, r28
  beq-      .loc_0x140
  lwz       r10, 0x0(r6)
  lhz       r4, 0x3028(r13)
  lwz       r27, 0x0(r3)
  mulli     r29, r10, 0xC4
  lwz       r27, 0x0(r27)
  rlwinm.   r4,r4,0,31,31
  add       r4, r27, r29
  beq-      .loc_0x74
  lbz       r29, 0x40(r4)
  rlwinm.   r29,r29,0,31,31
  bne-      .loc_0x140

.loc_0x74:
  addi      r29, r11, 0x14
  lwzx      r29, r4, r29
  cmpw      r29, r10
  beq-      .loc_0x140
  cmpwi     r29, -0x1
  bne-      .loc_0x9C
  lbz       r4, 0x4(r6)
  xor       r4, r4, r28
  stb       r4, 0x4(r6)
  b         .loc_0x140

.loc_0x9C:
  cmplwi    r0, 0
  bne-      .loc_0xC8
  mulli     r10, r29, 0xC4
  addi      r10, r10, 0x38
  lbzx      r10, r27, r10
  cmplwi    r10, 0
  bne-      .loc_0xC8
  lbz       r4, 0x4(r6)
  xor       r4, r4, r28
  stb       r4, 0x4(r6)
  b         .loc_0x140

.loc_0xC8:
  cmpwi     r9, 0
  mtctr     r9
  addi      r27, r8, 0
  li        r28, 0
  ble-      .loc_0xF8

.loc_0xDC:
  lwz       r10, 0x0(r27)
  cmpw      r29, r10
  bne-      .loc_0xF0
  li        r28, 0x1
  b         .loc_0xF8

.loc_0xF0:
  addi      r27, r27, 0x8
  bdnz+     .loc_0xDC

.loc_0xF8:
  add       r4, r4, r12
  addi      r10, r4, 0x44
  add       r10, r5, r10
  lwz       r4, 0x0(r10)
  cmpwi     r4, -0x2
  beq-      .loc_0x140
  rlwinm.   r4,r28,0,24,31
  bne-      .loc_0x140
  cmpw      r29, r7
  stw       r22, 0x0(r31)
  bne-      .loc_0x12C
  mr        r3, r22
  b         .loc_0x258

.loc_0x12C:
  lwz       r4, 0x0(r10)
  addi      r31, r31, 0x4
  addi      r23, r23, 0x1
  stw       r4, 0x0(r30)
  addi      r30, r30, 0x4

.loc_0x140:
  addi      r22, r22, 0x1
  cmpwi     r22, 0x8
  addi      r11, r11, 0x4
  addi      r12, r12, 0x10
  blt+      .loc_0x34
  cmpwi     r23, 0
  mtctr     r23
  lis       r4, 0x2
  subi      r4, r4, 0xC00
  ble-      .loc_0x188

.loc_0x168:
  lwz       r0, 0x0(r26)
  cmpw      r0, r4
  bge-      .loc_0x17C
  mr        r4, r0
  lwz       r24, 0x0(r25)

.loc_0x17C:
  addi      r26, r26, 0x4
  addi      r25, r25, 0x4
  bdnz+     .loc_0x168

.loc_0x188:
  cmpwi     r24, -0x1
  beq-      .loc_0x254
  lwz       r4, 0x0(r6)
  rlwinm    r0,r24,2,0,29
  lwz       r5, 0x0(r3)
  mulli     r3, r4, 0xC4
  lfs       f0, -0x72CC(r2)
  lwz       r5, 0x0(r5)
  add       r4, r5, r3
  add       r3, r4, r0
  lfs       f3, 0x4(r4)
  lwz       r0, 0x14(r3)
  lfs       f1, 0x0(r4)
  mulli     r0, r0, 0xC4
  lfs       f5, 0x8(r4)
  add       r3, r5, r0
  lfs       f4, 0x4(r3)
  lfs       f2, 0x0(r3)
  fsubs     f4, f4, f3
  lfs       f3, 0x8(r3)
  fsubs     f2, f2, f1
  fsubs     f3, f3, f5
  fmuls     f1, f4, f4
  fmuls     f2, f2, f2
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x254
  fsqrte    f1, f4
  lfd       f3, -0x72C0(r2)
  lfd       f2, -0x72B8(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x8C(r1)
  lfs       f0, 0x8C(r1)

.loc_0x254:
  mr        r3, r24

.loc_0x258:
  lmw       r22, 0x140(r1)
  addi      r1, r1, 0x168
  blr
*/
}

/*
 * --INFO--
 * Address:	800A27E4
 * Size:	00052C
 */
void PathFinder::selectSecondBestWayOnyon(Vector3f &, int &, int, PathFinder::Buffer &, int, PathFinder::Buffer *, int, bool)
{
/*
.loc_0x0:
  mflr      r0
  li        r11, 0
  stw       r0, 0x4(r1)
  rlwinm    r6,r6,2,0,29
  stwu      r1, -0x1F8(r1)
  stfd      f31, 0x1F0(r1)
  lbz       r0, 0x203(r1)
  stmw      r19, 0x1BC(r1)
  addi      r31, r1, 0x198
  addi      r24, r3, 0
  addi      r26, r5, 0
  addi      r30, r1, 0x178
  addi      r27, r7, 0
  addi      r25, r4, 0
  addi      r5, r11, 0
  addi      r7, r30, 0
  addi      r12, r31, 0
  li        r29, -0x1
  li        r28, 0
  li        r3, 0

.loc_0x50:
  li        r4, 0x1
  lbz       r19, 0x4(r27)
  slw       r21, r4, r3
  and.      r4, r19, r21
  beq-      .loc_0x158
  lwz       r22, 0x0(r27)
  lhz       r4, 0x3028(r13)
  lwz       r20, 0x0(r24)
  mulli     r19, r22, 0xC4
  lwz       r20, 0x0(r20)
  rlwinm.   r4,r4,0,31,31
  add       r4, r20, r19
  beq-      .loc_0x90
  lbz       r19, 0x40(r4)
  rlwinm.   r19,r19,0,31,31
  bne-      .loc_0x158

.loc_0x90:
  addi      r19, r11, 0x14
  lwzx      r23, r4, r19
  cmpw      r23, r22
  beq-      .loc_0x158
  cmpwi     r23, -0x1
  bne-      .loc_0xB8
  lbz       r4, 0x4(r27)
  xor       r4, r4, r21
  stb       r4, 0x4(r27)
  b         .loc_0x158

.loc_0xB8:
  cmplwi    r0, 0
  bne-      .loc_0xE4
  mulli     r19, r23, 0xC4
  addi      r19, r19, 0x38
  lbzx      r19, r20, r19
  cmplwi    r19, 0
  bne-      .loc_0xE4
  lbz       r4, 0x4(r27)
  xor       r4, r4, r21
  stb       r4, 0x4(r27)
  b         .loc_0x158

.loc_0xE4:
  cmpwi     r10, 0
  mtctr     r10
  addi      r20, r9, 0
  li        r21, 0
  ble-      .loc_0x114

.loc_0xF8:
  lwz       r19, 0x0(r20)
  cmpw      r23, r19
  bne-      .loc_0x10C
  li        r21, 0x1
  b         .loc_0x114

.loc_0x10C:
  addi      r20, r20, 0x8
  bdnz+     .loc_0xF8

.loc_0x114:
  add       r4, r4, r5
  addi      r19, r4, 0x44
  add       r19, r6, r19
  lwz       r4, 0x0(r19)
  cmpwi     r4, -0x2
  beq-      .loc_0x158
  rlwinm.   r4,r21,0,24,31
  bne-      .loc_0x158
  cmpw      r23, r8
  stw       r3, 0x0(r7)
  bne-      .loc_0x144
  b         .loc_0x514

.loc_0x144:
  lwz       r4, 0x0(r19)
  addi      r7, r7, 0x4
  addi      r28, r28, 0x1
  stw       r4, 0x0(r12)
  addi      r12, r12, 0x4

.loc_0x158:
  addi      r3, r3, 0x1
  cmpwi     r3, 0x8
  addi      r11, r11, 0x4
  addi      r5, r5, 0x10
  blt+      .loc_0x50
  cmpwi     r28, 0
  mtctr     r28
  lis       r3, 0x2
  addi      r4, r31, 0
  addi      r5, r30, 0
  subi      r3, r3, 0xC00
  ble-      .loc_0x1A8

.loc_0x188:
  lwz       r0, 0x0(r4)
  cmpw      r0, r3
  bge-      .loc_0x19C
  mr        r3, r0
  lwz       r29, 0x0(r5)

.loc_0x19C:
  addi      r4, r4, 0x4
  addi      r5, r5, 0x4
  bdnz+     .loc_0x188

.loc_0x1A8:
  lis       r3, 0x2
  subi      r0, r3, 0xC00
  stw       r0, 0x0(r26)
  li        r21, -0x1
  li        r20, 0
  lfs       f31, -0x72CC(r2)
  b         .loc_0x508

.loc_0x1C4:
  cmpw      r20, r29
  beq-      .loc_0x4FC
  lwz       r3, 0x0(r31)
  lwz       r0, 0x0(r26)
  cmpw      r3, r0
  bge-      .loc_0x4FC
  lwz       r3, 0x0(r27)
  li        r19, 0x1
  lwz       r5, 0x0(r24)
  lwz       r0, 0x0(r30)
  mulli     r4, r3, 0xC4
  lwz       r5, 0x0(r5)
  rlwinm    r3,r0,2,0,29
  add       r23, r5, r4
  addi      r0, r3, 0x14
  lbz       r3, 0x38(r23)
  lwzx      r0, r23, r0
  cmplwi    r3, 0
  mulli     r0, r0, 0xC4
  add       r22, r5, r0
  lbz       r0, 0x38(r22)
  bne-      .loc_0x380
  stfs      f31, 0x148(r1)
  stfs      f31, 0x144(r1)
  stfs      f31, 0x140(r1)
  lfs       f1, 0x0(r22)
  lfs       f0, 0x0(r23)
  lfs       f3, 0x4(r22)
  lfs       f2, 0x4(r23)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r22)
  lfs       f1, 0x8(r23)
  fsubs     f2, f3, f2
  stfs      f0, 0x134(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x138(r1)
  stfs      f0, 0x13C(r1)
  lfs       f1, 0x134(r1)
  lfs       f0, 0x138(r1)
  lfs       f2, 0x13C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x94E1C
  fcmpu     cr0, f31, f1
  beq-      .loc_0x2A8
  lfs       f0, 0x134(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x134(r1)
  lfs       f0, 0x138(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x138(r1)
  lfs       f0, 0x13C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x13C(r1)

.loc_0x2A8:
  lwz       r0, 0x134(r1)
  lwz       r3, 0x138(r1)
  stw       r0, 0x140(r1)
  lwz       r0, 0x13C(r1)
  stw       r3, 0x144(r1)
  lfs       f3, 0x134(r1)
  stw       r0, 0x148(r1)
  lfs       f2, 0x0(r23)
  lfs       f1, 0x138(r1)
  lfs       f0, 0x4(r23)
  fmuls     f2, f3, f2
  lfs       f3, 0x13C(r1)
  fmuls     f0, f1, f0
  lfs       f1, 0x8(r23)
  fmuls     f1, f3, f1
  fadds     f0, f2, f0
  fadds     f0, f1, f0
  stfs      f0, 0x14C(r1)
  lfs       f6, 0x144(r1)
  lfs       f0, 0x4(r25)
  lfs       f8, 0x140(r1)
  lfs       f2, 0x0(r25)
  fmuls     f3, f6, f0
  lfs       f1, 0x0(r22)
  fmuls     f4, f8, f2
  lfs       f0, 0x4(r22)
  lfs       f7, 0x148(r1)
  lfs       f5, 0x8(r25)
  fmuls     f1, f8, f1
  fmuls     f0, f6, f0
  lfs       f2, 0x8(r22)
  fmuls     f5, f7, f5
  lfs       f6, 0x14C(r1)
  fadds     f3, f4, f3
  fmuls     f2, f7, f2
  fadds     f3, f5, f3
  fadds     f0, f1, f0
  fsubs     f1, f3, f6
  fadds     f0, f2, f0
  fcmpu     cr0, f1, f31
  fsubs     f0, f0, f6
  mfcr      r0
  fcmpu     cr0, f0, f31
  rlwinm    r0,r0,3,31,31
  xori      r0, r0, 0x1
  rlwinm    r3,r0,0,24,31
  mfcr      r0
  rlwinm    r0,r0,3,31,31
  xori      r0, r0, 0x1
  rlwinm    r0,r0,0,24,31
  cmplw     r3, r0
  beq-      .loc_0x4E8
  li        r19, 0
  b         .loc_0x4E8

.loc_0x380:
  cmplwi    r0, 0
  bne-      .loc_0x4E8
  stfs      f31, 0x128(r1)
  stfs      f31, 0x124(r1)
  stfs      f31, 0x120(r1)
  lfs       f1, 0x0(r22)
  lfs       f0, 0x0(r23)
  lfs       f3, 0x4(r22)
  lfs       f2, 0x4(r23)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r22)
  lfs       f1, 0x8(r23)
  fsubs     f2, f3, f2
  stfs      f0, 0x114(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x118(r1)
  stfs      f0, 0x11C(r1)
  lfs       f1, 0x114(r1)
  lfs       f0, 0x118(r1)
  lfs       f2, 0x11C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x94F88
  fcmpu     cr0, f31, f1
  beq-      .loc_0x414
  lfs       f0, 0x114(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x114(r1)
  lfs       f0, 0x118(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x118(r1)
  lfs       f0, 0x11C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x11C(r1)

.loc_0x414:
  lwz       r0, 0x114(r1)
  lwz       r3, 0x118(r1)
  stw       r0, 0x120(r1)
  lwz       r0, 0x11C(r1)
  stw       r3, 0x124(r1)
  lfs       f3, 0x114(r1)
  stw       r0, 0x128(r1)
  lfs       f2, 0x0(r22)
  lfs       f1, 0x118(r1)
  lfs       f0, 0x4(r22)
  fmuls     f2, f3, f2
  lfs       f3, 0x11C(r1)
  fmuls     f0, f1, f0
  lfs       f1, 0x8(r22)
  fmuls     f1, f3, f1
  fadds     f0, f2, f0
  fadds     f0, f1, f0
  stfs      f0, 0x12C(r1)
  lfs       f6, 0x124(r1)
  lfs       f0, 0x4(r25)
  lfs       f8, 0x120(r1)
  lfs       f2, 0x0(r25)
  fmuls     f3, f6, f0
  lfs       f1, 0x0(r23)
  fmuls     f4, f8, f2
  lfs       f0, 0x4(r23)
  lfs       f7, 0x128(r1)
  lfs       f5, 0x8(r25)
  fmuls     f1, f8, f1
  fmuls     f0, f6, f0
  lfs       f2, 0x8(r23)
  fmuls     f5, f7, f5
  lfs       f6, 0x12C(r1)
  fadds     f3, f4, f3
  fmuls     f2, f7, f2
  fadds     f3, f5, f3
  fadds     f0, f1, f0
  fsubs     f1, f3, f6
  fadds     f0, f2, f0
  fcmpu     cr0, f1, f31
  fsubs     f0, f0, f6
  mfcr      r0
  fcmpu     cr0, f0, f31
  rlwinm    r0,r0,3,31,31
  xori      r0, r0, 0x1
  rlwinm    r3,r0,0,24,31
  mfcr      r0
  rlwinm    r0,r0,3,31,31
  xori      r0, r0, 0x1
  rlwinm    r0,r0,0,24,31
  cmplw     r3, r0
  beq-      .loc_0x4E8
  li        r19, 0

.loc_0x4E8:
  rlwinm.   r0,r19,0,24,31
  beq-      .loc_0x4FC
  lwz       r0, 0x0(r31)
  mr        r21, r20
  stw       r0, 0x0(r26)

.loc_0x4FC:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x4
  addi      r20, r20, 0x1

.loc_0x508:
  cmpw      r20, r28
  blt+      .loc_0x1C4
  mr        r3, r21

.loc_0x514:
  lmw       r19, 0x1BC(r1)
  lwz       r0, 0x1FC(r1)
  lfd       f31, 0x1F0(r1)
  addi      r1, r1, 0x1F8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A2D10
 * Size:	000134
 */
void RouteMgr::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  li        r0, 0xFF
  stwu      r1, -0x30(r1)
  stmw      r26, 0x18(r1)
  addi      r27, r4, 0
  addi      r26, r3, 0
  addi      r4, r1, 0x10
  addi      r3, r27, 0
  stb       r0, 0x10(r1)
  stb       r0, 0x11(r1)
  stb       r0, 0x12(r1)
  stb       r0, 0x13(r1)
  lwz       r12, 0x3B4(r27)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  mr        r3, r27
  lwz       r12, 0x3B4(r27)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r27
  lwz       r12, 0x3B4(r27)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0xCC(r12)
  mtlr      r12
  blrl      
  li        r29, 0
  li        r30, 0
  lis       r31, 0x7465
  b         .loc_0xEC

.loc_0x90:
  addi      r3, r26, 0
  addi      r4, r31, 0x7374
  bl        -0x1268
  cmpwi     r3, -0x1
  beq-      .loc_0xB8
  lwz       r4, 0x20(r26)
  rlwinm    r0,r3,3,0,28
  lwzx      r0, r4, r0
  add       r0, r0, r30
  b         .loc_0xBC

.loc_0xB8:
  li        r0, 0

.loc_0xBC:
  mr        r28, r0
  lwz       r3, 0x2E4(r27)
  lfs       f1, -0x72B0(r2)
  mr        r4, r28
  bl        -0x61858
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE4
  addi      r3, r28, 0
  addi      r4, r27, 0
  bl        0x278

.loc_0xE4:
  addi      r30, r30, 0xC4
  addi      r29, r29, 0x1

.loc_0xEC:
  addi      r3, r26, 0
  addi      r4, r31, 0x7374
  bl        -0x12C4
  cmpwi     r3, -0x1
  beq-      .loc_0x114
  rlwinm    r3,r3,3,0,28
  lwz       r4, 0x20(r26)
  addi      r0, r3, 0x4
  lwzx      r0, r4, r0
  b         .loc_0x118

.loc_0x114:
  li        r0, -0x1

.loc_0x118:
  cmpw      r29, r0
  blt+      .loc_0x90
  lmw       r26, 0x18(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A2E44
 * Size:	000224
 */
void drawBattenPoleSpec(Graphics &, Vector3f &, float, char *, Colour &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  fmr       f31, f1
  stmw      r27, 0x44(r1)
  mr        r27, r3
  addi      r28, r5, 0
  addi      r29, r6, 0
  lfs       f0, 0x0(r4)
  stfs      f0, 0x34(r1)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x38(r1)
  lfs       f0, 0x8(r4)
  li        r4, 0x1
  stfs      f0, 0x3C(r1)
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x34(r1)
  lfs       f2, 0x3C(r1)
  bl        -0x3AF8C
  stfs      f1, 0x38(r1)
  li        r30, 0xFF
  li        r31, 0
  lfs       f0, 0x34(r1)
  addi      r4, r1, 0x24
  addi      r3, r27, 0
  stfs      f0, 0x28(r1)
  li        r5, 0x1
  lfs       f0, 0x38(r1)
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x3C(r1)
  stfs      f0, 0x30(r1)
  lfs       f0, 0x2C(r1)
  fadds     f0, f0, f31
  stfs      f0, 0x2C(r1)
  stb       r30, 0x24(r1)
  stb       r31, 0x25(r1)
  stb       r31, 0x26(r1)
  stb       r30, 0x27(r1)
  lwz       r12, 0x3B4(r27)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lfs       f1, -0x72AC(r2)
  addi      r3, r27, 0
  addi      r4, r1, 0x34
  bl        0x73524
  stb       r30, 0x20(r1)
  addi      r4, r1, 0x20
  addi      r3, r27, 0
  stb       r30, 0x21(r1)
  li        r5, 0x1
  stb       r31, 0x22(r1)
  stb       r30, 0x23(r1)
  lwz       r12, 0x3B4(r27)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lfs       f1, -0x72AC(r2)
  addi      r3, r27, 0
  addi      r4, r1, 0x28
  bl        0x734E8
  mr        r3, r27
  lwz       r4, 0x2E4(r27)
  lwz       r12, 0x3B4(r27)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  stb       r31, 0x1C(r1)
  addi      r4, r1, 0x1C
  addi      r3, r27, 0
  stb       r30, 0x1D(r1)
  li        r5, 0x1
  stb       r31, 0x1E(r1)
  stb       r30, 0x1F(r1)
  lwz       r12, 0x3B4(r27)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  mr        r3, r27
  lwz       r12, 0x3B4(r27)
  addi      r4, r1, 0x34
  addi      r5, r1, 0x28
  lwz       r12, 0x98(r12)
  mtlr      r12
  blrl      
  cmplwi    r28, 0
  beq-      .loc_0x20C
  lwz       r12, 0x3B4(r27)
  lis       r4, 0x803A
  mr        r3, r27
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  mr        r3, r27
  lwz       r12, 0x3B4(r27)
  addi      r4, r29, 0
  li        r5, 0x1
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lfs       f1, 0x2C(r1)
  addi      r3, r1, 0x28
  lfs       f0, -0x72A8(r2)
  fadds     f0, f1, f0
  stfs      f0, 0x2C(r1)
  lwz       r4, 0x2E4(r27)
  addi      r4, r4, 0x1E0
  bl        -0x6B8B8
  lwz       r3, 0x2DEC(r13)
  mr        r4, r28
  lwz       r3, 0x10(r3)
  bl        -0x7AEE0
  lwz       r12, 0x3B4(r27)
  neg       r0, r3
  lwz       r4, 0x2DEC(r13)
  srawi     r6, r0, 0x1
  lwz       r12, 0xF0(r12)
  lwz       r4, 0x10(r4)
  addi      r3, r27, 0
  mtlr      r12
  addze     r6, r6
  addi      r8, r28, 0
  crclr     6, 0x6
  addi      r5, r1, 0x28
  li        r7, 0
  blrl      

.loc_0x20C:
  lmw       r27, 0x44(r1)
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A3068
 * Size:	0003C0
 */
void WayPoint::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  crclr     6, 0x6
  stwu      r1, -0x170(r1)
  stfd      f31, 0x168(r1)
  stfd      f30, 0x160(r1)
  stfd      f29, 0x158(r1)
  stfd      f28, 0x150(r1)
  stfd      f27, 0x148(r1)
  stfd      f26, 0x140(r1)
  stfd      f25, 0x138(r1)
  stmw      r17, 0xFC(r1)
  addi      r20, r4, 0
  addi      r19, r3, 0
  subi      r4, r13, 0x53BC
  lwz       r5, 0x10(r3)
  addi      r3, r1, 0xB8
  bl        0x1734EC
  lwz       r12, 0x3B4(r20)
  lis       r4, 0x803A
  mr        r3, r20
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  lbz       r0, 0x38(r19)
  cmplwi    r0, 0
  beq-      .loc_0x8C
  li        r0, 0xFF
  stb       r0, 0xB4(r1)
  stb       r0, 0xB5(r1)
  stb       r0, 0xB6(r1)
  stb       r0, 0xB7(r1)
  b         .loc_0xA4

.loc_0x8C:
  li        r3, 0x80
  stb       r3, 0xB4(r1)
  li        r0, 0xFF
  stb       r3, 0xB5(r1)
  stb       r3, 0xB6(r1)
  stb       r0, 0xB7(r1)

.loc_0xA4:
  lfs       f1, -0x72A4(r2)
  addi      r3, r20, 0
  addi      r4, r19, 0
  addi      r5, r1, 0xB8
  addi      r6, r1, 0xB4
  bl        -0x2DC
  lis       r3, 0x803A
  lfs       f31, -0x72A0(r2)
  lfs       f28, -0x72CC(r2)
  mr        r24, r19
  lfs       f29, -0x729C(r2)
  mr        r23, r19
  lfs       f30, -0x7298(r2)
  addi      r29, r1, 0x78
  addi      r28, r1, 0x30
  addi      r27, r1, 0x2C
  addi      r26, r1, 0x28
  addi      r25, r1, 0x50
  subi      r31, r3, 0x77C0
  li        r22, 0
  lis       r30, 0x7465

.loc_0xF8:
  lfs       f0, 0x0(r19)
  stfs      f0, 0xA8(r1)
  lfs       f0, 0x4(r19)
  stfs      f0, 0xAC(r1)
  lfs       f0, 0x8(r19)
  stfs      f0, 0xB0(r1)
  lfs       f0, 0xAC(r1)
  fadds     f0, f0, f31
  stfs      f0, 0xAC(r1)
  lwz       r0, 0x4C(r24)
  cmpwi     r0, 0
  mr        r21, r0
  ble-      .loc_0x37C
  mr        r3, r20
  lwz       r4, 0x2E4(r20)
  lwz       r12, 0x3B4(r20)
  li        r5, 0
  addi      r4, r4, 0x1E0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  li        r0, 0x9B
  stb       r0, 0x78(r1)
  li        r0, 0xFF
  addi      r3, r20, 0
  stb       r0, 0x79(r1)
  addi      r4, r29, 0
  li        r5, 0x1
  stb       r0, 0x7A(r1)
  stb       r0, 0x7B(r1)
  lwz       r12, 0x3B4(r20)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  lwz       r18, 0x302C(r13)
  addi      r4, r30, 0x7374
  lwz       r17, 0x14(r23)
  mr        r3, r18
  bl        -0x16B8
  cmpwi     r3, -0x1
  beq-      .loc_0x1B4
  lwz       r4, 0x20(r18)
  rlwinm    r3,r3,3,0,28
  mulli     r0, r17, 0xC4
  lwzx      r3, r4, r3
  add       r6, r3, r0
  b         .loc_0x1B8

.loc_0x1B4:
  li        r6, 0

.loc_0x1B8:
  lfs       f0, 0x0(r6)
  addi      r3, r20, 0
  addi      r4, r1, 0xA8
  stfs      f0, 0x98(r1)
  addi      r5, r1, 0x98
  lfs       f0, 0x4(r6)
  stfs      f0, 0x9C(r1)
  lfs       f0, 0x8(r6)
  stfs      f0, 0xA0(r1)
  lfs       f0, 0x9C(r1)
  fadds     f0, f0, f31
  stfs      f0, 0x9C(r1)
  lwz       r12, 0x3B4(r20)
  lwz       r12, 0x98(r12)
  mtlr      r12
  blrl      
  lfs       f3, 0x98(r1)
  lfs       f2, 0xA8(r1)
  lfs       f1, 0x9C(r1)
  lfs       f0, 0xAC(r1)
  fsubs     f27, f3, f2
  lfs       f2, 0xA0(r1)
  fsubs     f26, f1, f0
  lfs       f0, 0xB0(r1)
  fmuls     f1, f27, f27
  fsubs     f25, f2, f0
  fmuls     f0, f26, f26
  fmuls     f2, f25, f25
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x95658
  fcmpu     cr0, f28, f1
  beq-      .loc_0x248
  fdivs     f27, f27, f1
  fdivs     f26, f26, f1
  fdivs     f25, f25, f1

.loc_0x248:
  fmuls     f0, f29, f1
  addi      r4, r26, 0
  addi      r5, r27, 0
  addi      r6, r28, 0
  fmuls     f2, f25, f0
  fmuls     f1, f26, f0
  addi      r3, r1, 0x54
  fmuls     f0, f27, f0
  stfs      f2, 0x30(r1)
  stfs      f1, 0x2C(r1)
  stfs      f0, 0x28(r1)
  bl        -0x6C1C0
  lfs       f1, 0xA8(r1)
  li        r8, 0x64
  lfs       f0, 0x54(r1)
  li        r7, 0xE6
  lfs       f3, 0xAC(r1)
  lfs       f2, 0x58(r1)
  fadds     f0, f1, f0
  lfs       f4, 0xB0(r1)
  li        r6, 0x8C
  lfs       f1, 0x5C(r1)
  fadds     f2, f3, f2
  stfs      f0, 0x7C(r1)
  fadds     f0, f4, f1
  li        r0, 0xFF
  stfs      f2, 0x80(r1)
  mr        r3, r20
  stfs      f0, 0x84(r1)
  addi      r4, r25, 0
  li        r5, 0x1
  lfs       f0, 0x80(r1)
  fadds     f0, f0, f30
  stfs      f0, 0x80(r1)
  stb       r8, 0x50(r1)
  stb       r7, 0x51(r1)
  stb       r6, 0x52(r1)
  stb       r0, 0x53(r1)
  lwz       r12, 0x3B4(r20)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  mr        r3, r20
  lwz       r12, 0x3B4(r20)
  addi      r4, r31, 0
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x2E4(r20)
  addi      r3, r1, 0x7C
  addi      r4, r4, 0x1E0
  bl        -0x6BC34
  lwz       r5, 0x14(r23)
  addi      r6, r21, 0
  addi      r3, r1, 0xB8
  crclr     6, 0x6
  subi      r4, r13, 0x53B8
  bl        0x173200
  lwz       r3, 0x2DEC(r13)
  addi      r4, r1, 0xB8
  lwz       r3, 0x10(r3)
  bl        -0x7B274
  lwz       r12, 0x3B4(r20)
  srawi     r0, r3, 0x1
  lwz       r4, 0x2DEC(r13)
  addze     r0, r0
  lwz       r12, 0xF0(r12)
  lwz       r4, 0x10(r4)
  addi      r3, r20, 0
  mtlr      r12
  neg       r6, r0
  addi      r5, r1, 0x7C
  crclr     6, 0x6
  addi      r8, r1, 0xB8
  li        r7, 0
  blrl      

.loc_0x37C:
  addi      r22, r22, 0x1
  cmpwi     r22, 0x8
  addi      r24, r24, 0x10
  addi      r23, r23, 0x4
  blt+      .loc_0xF8
  lmw       r17, 0xFC(r1)
  lwz       r0, 0x174(r1)
  lfd       f31, 0x168(r1)
  lfd       f30, 0x160(r1)
  lfd       f29, 0x158(r1)
  lfd       f28, 0x150(r1)
  lfd       f27, 0x148(r1)
  lfd       f26, 0x140(r1)
  lfd       f25, 0x138(r1)
  addi      r1, r1, 0x170
  mtlr      r0
  blr
*/
}