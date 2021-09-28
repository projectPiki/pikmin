

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
 * Address:	801171C4
 * Size:	000180
 */
void NaviMgr::NaviMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r3, 0x8(r1)
  lis       r3, 0x802C
  addi      r30, r3, 0x2E70
  lwz       r3, 0x8(r1)
  bl        -0x361A0
  lis       r4, 0x802C
  lwz       r3, 0x8(r1)
  addi      r4, r4, 0x2FD8
  stw       r4, 0x0(r3)
  addi      r0, r4, 0x18
  addi      r4, r30, 0x18
  stw       r0, 0x8(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0x90AD8
  li        r3, 0x43C
  bl        -0xD0214
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x68
  bl        -0x1E680

.loc_0x68:
  lwz       r31, 0x8(r1)
  addi      r5, r30, 0x24
  subi      r4, r13, 0x2350
  stw       r29, 0x58(r31)
  addi      r3, r31, 0x8
  li        r6, 0x1
  bl        -0xD6BA4
  lwz       r3, 0x2FE8(r13)
  addi      r4, r30, 0x18
  bl        -0x90A08
  lwz       r3, 0x2FE8(r13)
  addi      r4, r30, 0x30
  bl        -0x90B24
  lwz       r3, 0x2FE8(r13)
  addi      r4, r30, 0x40
  bl        -0x90B30
  bl        0x1A98
  stw       r3, 0x50(r31)
  addi      r4, r30, 0x40
  lwz       r3, 0x2FE8(r13)
  bl        -0x90A34
  lwz       r3, 0x2FE8(r13)
  addi      r4, r30, 0x4C
  bl        -0x90B50
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0xC458C
  stw       r3, 0x40(r31)
  addi      r4, r30, 0x4C
  lwz       r3, 0x2FE8(r13)
  bl        -0x90A64
  lwz       r3, 0x2FE8(r13)
  addi      r4, r30, 0x6C
  bl        -0x90B80
  li        r3, 0x28
  bl        -0xD02BC
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x114
  lwz       r4, 0x40(r31)
  bl        -0x3E800

.loc_0x114:
  lwz       r31, 0x8(r1)
  addi      r4, r30, 0x6C
  stw       r29, 0x48(r31)
  lwz       r3, 0x2FE8(r13)
  bl        -0x90AA0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r30, 0x80
  bl        -0x90BBC
  bl        -0x3EA14
  lwz       r5, 0x48(r31)
  addi      r4, r30, 0x80
  stw       r3, 0x24(r5)
  lwz       r3, 0x2FE8(r13)
  bl        -0x90AC4
  li        r0, 0
  stw       r0, 0x54(r31)
  addi      r4, r30, 0x30
  lwz       r3, 0x2FE8(r13)
  bl        -0x90AD8
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NaviMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80117344
 * Size:	000060
 */
void NaviMgr::createObject()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  li        r3, 0xAE0
  bl        -0xD035C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x38
  lwz       r4, 0x58(r30)
  lwz       r5, 0x54(r30)
  bl        -0x1D7EC

.loc_0x38:
  lwz       r4, 0x54(r30)
  addi      r3, r31, 0
  addi      r0, r4, 0x1
  stw       r0, 0x54(r30)
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
 * Address:	801173A4
 * Size:	000020
 */
void NaviMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x36028
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801173C4
 * Size:	000074
 */
void NaviMgr::getNavi()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  addi      r4, r3, 0
  cmpwi     r4, -0x1
  bne-      .loc_0x4C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x60

.loc_0x4C:
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x60:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80117438
 * Size:	000018
 */
void NaviMgr::getNavi(int)
{
/*
.loc_0x0:
  lwz       r0, 0x30(r3)
  cmpw      r4, r0
  lwz       r3, 0x28(r3)
  rlwinm    r0,r4,2,0,29
  lwzx      r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80117450
 * Size:	00011C
 */
void NaviMgr::refresh2d(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r4
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xA4

.loc_0x38:
  cmpwi     r30, -0x1
  bne-      .loc_0x5C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x74

.loc_0x5C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xF0(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xA4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xCC
  li        r0, 0x1
  b         .loc_0xF8

.loc_0xCC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xF4
  li        r0, 0x1
  b         .loc_0xF8

.loc_0xF4:
  li        r0, 0

.loc_0xF8:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x38
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011756C
 * Size:	000110
 */
void NaviMgr::renderCircle(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r4
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x98

.loc_0x38:
  cmpwi     r30, -0x1
  bne-      .loc_0x5C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x74

.loc_0x5C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  mr        r4, r29
  bl        -0x18038
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x98:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xC0
  li        r0, 0x1
  b         .loc_0xEC

.loc_0xC0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xE8
  li        r0, 0x1
  b         .loc_0xEC

.loc_0xE8:
  li        r0, 0

.loc_0xEC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x38
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011767C
 * Size:	00011C
 */
void NaviMgr::drawShadow(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r4
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xA4

.loc_0x38:
  cmpwi     r30, -0x1
  bne-      .loc_0x5C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x74

.loc_0x5C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xF8(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xA4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xCC
  li        r0, 0x1
  b         .loc_0xF8

.loc_0xCC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xF4
  li        r0, 0x1
  b         .loc_0xF8

.loc_0xF4:
  li        r0, 0

.loc_0xF8:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x38
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80117798
 * Size:	000030
 */
void NaviMgr::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x58(r3)
  lwz       r12, 0x54(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801177C8
 * Size:	000084
 */
void NaviMgr::~NaviMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x6C
  lis       r3, 0x802C
  addi      r3, r3, 0x2FD8
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)
  beq-      .loc_0x5C
  lis       r3, 0x802C
  subi      r3, r3, 0x5038
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)
  beq-      .loc_0x5C
  lis       r3, 0x802C
  subi      r3, r3, 0x4F80
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)

.loc_0x5C:
  extsh.    r0, r4
  ble-      .loc_0x6C
  mr        r3, r31
  bl        -0xD0684

.loc_0x6C:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011784C
 * Size:	000008
 */
void NaviMgr::@8@read(RandomAccessStream &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0xB8
*/
}

/*
 * --INFO--
 * Address:	80117854
 * Size:	000008
 */
void NaviMgr::@8@update()
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0x4B4
*/
}