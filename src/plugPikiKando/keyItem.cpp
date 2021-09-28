

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
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800ED204
 * Size:	0000A8
 */
void KeyItem::KeyItem(CreatureProp *, Shape *)
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
  bl        -0x62348
  lis       r3, 0x802C
  subi      r0, r3, 0x2CE0
  lis       r3, 0x8009
  stw       r0, 0x0(r30)
  subi      r4, r3, 0x5808
  addi      r3, r30, 0x2BC
  li        r5, 0
  li        r6, 0xC
  li        r7, 0x3
  bl        0x127828
  stw       r31, 0x2E0(r30)
  li        r0, 0x4
  addi      r3, r30, 0x1B8
  stw       r0, 0x68(r30)
  addi      r4, r30, 0x2BC
  li        r5, 0x3
  bl        -0x95E4
  lwz       r3, 0xC8(r30)
  li        r4, 0x3
  li        r0, 0x2
  rlwinm    r3,r3,0,23,21
  stw       r3, 0xC8(r30)
  mr        r3, r30
  lwz       r5, 0xC8(r30)
  ori       r5, r5, 0x1
  stw       r5, 0xC8(r30)
  stw       r4, 0x6C(r30)
  stw       r0, 0x2B8(r30)
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
 * Address:	800ED2AC
 * Size:	000008
 */
void KeyItem::getSize()
{
/*
.loc_0x0:
  lfs       f1, -0x6528(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED2B4
 * Size:	000054
 */
void KeyItem::init(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f0, -0x6524(r2)
  stfs      f0, 0x7C(r3)
  stfs      f0, 0x80(r31)
  stfs      f0, 0x84(r31)
  bl        -0x626D4
  addi      r3, r31, 0x1B8
  addi      r4, r31, 0x2BC
  li        r5, 0x3
  bl        -0x9668
  li        r0, 0x2
  stw       r0, 0x2B8(r31)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED308
 * Size:	00000C
 */
void KeyItem::startAI(int)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x2B8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED314
 * Size:	000020
 */
void KeyItem::isVisible()
{
/*
.loc_0x0:
  lwz       r0, 0x2B8(r3)
  li        r3, 0
  cmpwi     r0, 0x1
  beqlr-    
  cmpwi     r0, 0x2
  beqlr-    
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED334
 * Size:	00003C
 */
void KeyItem::doKill()
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x8(r1)
  stw       r0, 0x2B8(r3)
  lwz       r3, 0x30AC(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x7C(r12)
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
 * Address:	800ED370
 * Size:	00010C
 */
void KeyItem::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lfs       f2, 0x70(r3)
  lfs       f1, 0x74(r3)
  fmuls     f2, f2, f2
  lfs       f3, 0x78(r3)
  fmuls     f1, f1, f1
  lfs       f0, -0x6520(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x98
  fsqrte    f1, f4
  lfd       f3, -0x6518(r2)
  lfd       f2, -0x6510(r2)
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
  stfs      f0, 0x10(r1)
  lfs       f4, 0x10(r1)

.loc_0x98:
  lfs       f0, -0x6500(r2)
  lfs       f2, -0x6504(r2)
  fdivs     f1, f4, f0
  lfs       f3, -0x6508(r2)
  lfs       f0, -0x64FC(r2)
  fmuls     f1, f2, f1
  fadds     f1, f3, f1
  fcmpo     cr0, f1, f0
  fmr       f2, f1
  ble-      .loc_0xC4
  fmr       f2, f0

.loc_0xC4:
  lfs       f0, -0x64F8(r2)
  lfs       f1, 0xA0(r31)
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0xA0(r31)
  lfs       f1, 0xA0(r31)
  bl        -0xB4EC4
  stfs      f1, 0xA0(r31)
  addi      r3, r31, 0x40
  addi      r4, r31, 0x94
  bl        -0x58F3C
  mr        r3, r31
  bl        -0x61AE8
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED47C
 * Size:	000004
 */
void KeyItem::collisionCallback(CollEvent &)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED480
 * Size:	000008
 */
void KeyItem::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x64F4(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED488
 * Size:	00014C
 */
void KeyItem::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA8(r1)
  stw       r31, 0xA4(r1)
  addi      r6, r1, 0x10
  mr        r31, r4
  stw       r30, 0xA0(r1)
  mr        r30, r3
  addi      r4, r30, 0x7C
  lfs       f2, -0x64F0(r2)
  addi      r5, r30, 0x88
  lfs       f1, 0x98(r3)
  lfs       f0, 0x94(r3)
  addi      r3, r30, 0x228
  fadds     f1, f2, f1
  stfs      f0, 0x10(r1)
  stfs      f1, 0x14(r1)
  lfs       f0, 0x9C(r30)
  stfs      f0, 0x18(r1)
  bl        -0xAF3E0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r30, 0x228
  addi      r5, r1, 0x20
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x20
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  addi      r0, r30, 0x94
  lwz       r4, 0x2E4(r31)
  neg       r3, r0
  subic     r0, r3, 0x1
  subfe     r0, r0, r3
  stb       r0, 0x154(r4)
  lbz       r0, 0x154(r4)
  cmplwi    r0, 0
  beq-      .loc_0xC4
  lwz       r3, 0x94(r30)
  lwz       r0, 0x98(r30)
  stw       r3, 0x158(r4)
  stw       r0, 0x15C(r4)
  lwz       r0, 0x9C(r30)
  stw       r0, 0x160(r4)

.loc_0xC4:
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x94(r30)
  lfs       f2, 0x9C(r30)
  bl        -0x857C0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  li        r4, 0x1
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2E0(r30)
  mr        r4, r31
  lwz       r5, 0x2E4(r31)
  li        r6, 0
  bl        -0xBD11C
  lwz       r4, 0x2E4(r31)
  li        r0, 0
  stb       r0, 0x154(r4)
  lbz       r0, 0x154(r4)
  cmplwi    r0, 0
  beq-      .loc_0x134
  lwz       r3, 0x0(r0)
  lwz       r0, 0x4(r0)
  stw       r3, 0x158(r4)
  stw       r0, 0x15C(r4)
  lwz       r0, 0x8(r0)
  stw       r0, 0x160(r4)

.loc_0x134:
  lwz       r0, 0xAC(r1)
  lwz       r31, 0xA4(r1)
  lwz       r30, 0xA0(r1)
  addi      r1, r1, 0xA8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED5D4
 * Size:	000060
 */
void DoorItem::DoorItem(int, CreatureProp *, Shape *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  bl        0x82C4
  lis       r3, 0x802C
  subi      r3, r3, 0x2E58
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x114
  li        r4, 0x2
  stw       r0, 0x2B8(r31)
  li        r0, 0
  addi      r3, r31, 0
  stw       r4, 0x3CC(r31)
  lfs       f0, -0x6520(r2)
  stfs      f0, 0x3C8(r31)
  stw       r0, 0x3D0(r31)
  stw       r0, 0x3D4(r31)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED634
 * Size:	000020
 */
void DoorItem::disappear()
{
/*
.loc_0x0:
  lwz       r0, 0x3CC(r3)
  cmpwi     r0, 0x3
  beqlr-    
  li        r0, 0x3
  stw       r0, 0x3CC(r3)
  lfs       f0, -0x64EC(r2)
  stfs      f0, 0x3C8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void DoorItem::becomeGate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800ED654
 * Size:	00001C
 */
void DoorItem::getSize()
{
/*
.loc_0x0:
  lwz       r0, 0x6C(r3)
  cmpwi     r0, 0x5
  bne-      .loc_0x14
  lfs       f1, -0x64E8(r2)
  blr       

.loc_0x14:
  lfs       f1, -0x64E4(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED670
 * Size:	000054
 */
void DoorItem::init(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x82F0
  lwz       r0, 0x6C(r31)
  lfs       f0, -0x6524(r2)
  cmpwi     r0, 0x5
  bne-      .loc_0x2C
  lfs       f0, -0x64FC(r2)

.loc_0x2C:
  stfs      f0, 0x7C(r31)
  li        r0, 0x2
  stfs      f0, 0x80(r31)
  stfs      f0, 0x84(r31)
  stw       r0, 0x3CC(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED6C4
 * Size:	00000C
 */
void DoorItem::startAI(int)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x3CC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED6D0
 * Size:	0000A8
 */
void DoorItem::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x3CC(r3)
  cmpwi     r0, 0x3
  bne-      .loc_0x94
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x3C8(r3)
  lfs       f0, 0x28C(r4)
  fsubs     f0, f1, f0
  stfs      f0, 0x3C8(r3)
  lfs       f1, 0x3C8(r3)
  lfs       f0, -0x64EC(r2)
  lwz       r4, 0x2DEC(r13)
  fdivs     f3, f1, f0
  lfs       f4, -0x64FC(r2)
  lfs       f1, -0x64E0(r2)
  lfs       f0, 0x28C(r4)
  lfs       f2, 0x98(r3)
  fmuls     f0, f1, f0
  fmuls     f1, f4, f3
  fsubs     f0, f2, f0
  stfs      f0, 0x98(r3)
  lfs       f0, -0x3378(r13)
  stfs      f0, 0x7C(r3)
  stfs      f1, 0x80(r3)
  lfs       f0, -0x3374(r13)
  stfs      f0, 0x84(r3)
  lfs       f1, 0x3C8(r3)
  lfs       f0, -0x6520(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x98
  li        r0, 0x1
  stw       r0, 0x3CC(r3)
  li        r4, 0
  bl        -0x62A7C
  b         .loc_0x98

.loc_0x94:
  bl        0x8490

.loc_0x98:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED778
 * Size:	000020
 */
void DoorItem::isVisible()
{
/*
.loc_0x0:
  lwz       r0, 0x3CC(r3)
  li        r3, 0
  cmpwi     r0, 0x1
  beqlr-    
  cmpwi     r0, 0x2
  beqlr-    
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED798
 * Size:	000008
 */
void DoorItem::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x6520(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED7A0
 * Size:	000020
 */
void DoorItem::isAtari()
{
/*
.loc_0x0:
  lwz       r0, 0x3CC(r3)
  li        r3, 0x1
  cmpwi     r0, 0
  beqlr-    
  cmpwi     r0, 0x3
  beqlr-    
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED7C0
 * Size:	000204
 */
void DoorItem::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x170(r1)
  stw       r31, 0x16C(r1)
  stw       r30, 0x168(r1)
  stw       r29, 0x164(r1)
  addi      r29, r4, 0
  stw       r28, 0x160(r1)
  addi      r28, r3, 0
  addi      r3, r28, 0x228
  addi      r4, r28, 0x7C
  addi      r5, r28, 0x88
  addi      r6, r28, 0x94
  bl        -0xAF700
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  addi      r4, r28, 0x228
  addi      r5, r1, 0x120
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x3370(r13)
  addi      r3, r1, 0x114
  lfs       f1, -0x336C(r13)
  addi      r4, r1, 0x120
  stfs      f0, 0x114(r1)
  lfs       f0, -0x3368(r13)
  stfs      f1, 0x118(r1)
  stfs      f0, 0x11C(r1)
  bl        -0xB60E8
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  li        r4, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x3B4(r29)
  addi      r0, r3, 0
  lis       r4, 0x803A
  lwz       r12, 0x74(r12)
  addi      r3, r29, 0
  subi      r4, r4, 0x77C0
  mtlr      r12
  mr        r31, r0
  li        r5, 0
  blrl      
  li        r0, 0xFF
  stb       r0, 0x10(r1)
  addi      r4, r1, 0x10
  addi      r3, r29, 0
  stb       r0, 0x11(r1)
  li        r5, 0x1
  stb       r0, 0x12(r1)
  stb       r0, 0x13(r1)
  lwz       r12, 0x3B4(r29)
  lwz       r12, 0xA8(r12)
  mtlr      r12
  blrl      
  mr        r3, r29
  lwz       r4, 0x2DEC(r13)
  lwz       r12, 0x3B4(r29)
  li        r5, 0
  lwz       r4, 0x10(r4)
  lwz       r12, 0xCC(r12)
  lwz       r4, 0x0(r4)
  mtlr      r12
  blrl      
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  li        r4, 0
  lwz       r12, 0x60(r12)
  mtlr      r12
  blrl      
  lwz       r5, 0x3D4(r28)
  addi      r30, r3, 0
  crclr     6, 0x6
  addi      r3, r1, 0x14
  subi      r4, r13, 0x3364
  bl        0x128C9C
  lwz       r3, 0x2DEC(r13)
  addi      r4, r1, 0x14
  lwz       r3, 0x10(r3)
  bl        -0xC57D8
  lwz       r12, 0x3B4(r29)
  srawi     r0, r3, 0x1
  lwz       r4, 0x2DEC(r13)
  addze     r0, r0
  lwz       r12, 0xF0(r12)
  lwz       r4, 0x10(r4)
  addi      r3, r29, 0
  mtlr      r12
  neg       r6, r0
  addi      r5, r1, 0x114
  crclr     6, 0x6
  addi      r8, r1, 0x14
  li        r7, 0
  blrl      
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  mr        r4, r30
  lwz       r12, 0x60(r12)
  mtlr      r12
  blrl      
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  addi      r4, r31, 0
  li        r5, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r29
  lwz       r12, 0x3B4(r29)
  addi      r4, r1, 0x120
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  addi      r3, r28, 0
  addi      r4, r29, 0
  bl        0x82D8
  lwz       r0, 0x174(r1)
  lwz       r31, 0x16C(r1)
  lwz       r30, 0x168(r1)
  lwz       r29, 0x164(r1)
  lwz       r28, 0x160(r1)
  addi      r1, r1, 0x170
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED9C4
 * Size:	000008
 */
void DoorItem::isAlive()
{
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED9CC
 * Size:	000008
 */
void DoorItem::getHeight()
{
/*
.loc_0x0:
  lfs       f1, -0x6520(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ED9D4
 * Size:	000008
 */
void KeyItem::getHeight()
{
/*
.loc_0x0:
  lfs       f1, -0x6520(r2)
  blr
*/
}