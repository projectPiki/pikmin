

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
 * Address:	801E9CF8
 * Size:	0000A8
 */
void zen::DrawWMPause::DrawWMPause()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  li        r3, 0x1D8
  bl        -0x1A2D10
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x40
  lis       r4, 0x802E
  addi      r4, r4, 0x63D8
  li        r5, 0
  li        r6, 0
  bl        -0x26C38

.loc_0x40:
  stw       r31, 0x0(r30)
  li        r4, 0
  lwz       r3, 0x0(r30)
  bl        -0x2540C
  lwz       r5, 0x0(r30)
  lis       r3, 0x6261
  addi      r4, r3, 0x636B
  lwz       r12, 0x4(r5)
  addi      r3, r5, 0x4
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x8(r30)
  li        r5, 0
  li        r0, -0x1
  lwz       r4, 0x8(r30)
  mr        r3, r30
  stb       r5, 0xF0(r4)
  stw       r0, 0x4(r30)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9DA0
 * Size:	000060
 */
void zen::DrawWMPause::start()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lwz       r3, 0x0(r3)
  bl        -0x26104
  li        r6, 0
  stw       r6, 0x4(r31)
  li        r5, 0x1
  li        r3, 0x113
  lwz       r4, 0x8(r31)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  lwz       r4, 0x8(r31)
  stb       r6, 0xF0(r4)
  bl        -0x144A74
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9E00
 * Size:	00017C
 */
void zen::DrawWMPause::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stw       r31, 0x6C(r1)
  mr        r31, r3
  lwz       r3, 0x0(r3)
  bl        -0x25944
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x70
  lwz       r4, 0x0(r31)
  lwz       r0, 0x1D0(r4)
  cmpwi     r0, 0
  blt-      .loc_0x3C
  lwz       r3, 0x110(r4)
  b         .loc_0x54

.loc_0x3C:
  lbz       r0, 0x1D4(r4)
  cmplwi    r0, 0
  beq-      .loc_0x50
  li        r3, -0x1
  b         .loc_0x54

.loc_0x50:
  lwz       r3, 0x110(r4)

.loc_0x54:
  lbz       r0, 0x1D4(r4)
  cmplwi    r0, 0
  beq-      .loc_0x68
  li        r0, 0x1
  b         .loc_0x6C

.loc_0x68:
  addi      r0, r3, 0x1

.loc_0x6C:
  stw       r0, 0x4(r31)

.loc_0x70:
  lwz       r3, 0x0(r31)
  lwz       r0, 0x100(r3)
  cmpwi     r0, 0x2
  beq-      .loc_0x164
  bge-      .loc_0x94
  cmpwi     r0, 0
  beq-      .loc_0xA0
  bge-      .loc_0xB8
  b         .loc_0x164

.loc_0x94:
  cmpwi     r0, 0x4
  bge-      .loc_0x164
  b         .loc_0x118

.loc_0xA0:
  lwz       r3, 0x8(r31)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x164

.loc_0xB8:
  lwz       r3, 0x8(r31)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x0(r31)
  lfs       f2, -0x3FC8(r2)
  lfs       f1, 0x10C(r3)
  lfs       f0, -0x3FC4(r2)
  fmuls     f1, f2, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0xF8
  lfs       f0, -0x3FC0(r2)
  fadds     f0, f0, f1
  b         .loc_0x100

.loc_0xF8:
  lfs       f0, -0x3FC0(r2)
  fsubs     f0, f1, f0

.loc_0x100:
  fctiwz    f0, f0
  lwz       r3, 0x8(r31)
  stfd      f0, 0x60(r1)
  lwz       r0, 0x64(r1)
  stb       r0, 0xF0(r3)
  b         .loc_0x164

.loc_0x118:
  lfs       f1, -0x3FBC(r2)
  lfs       f0, 0x10C(r3)
  lfs       f2, -0x3FC8(r2)
  fsubs     f1, f1, f0
  lfs       f0, -0x3FC4(r2)
  fmuls     f1, f2, f1
  fcmpo     cr0, f1, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x148
  lfs       f0, -0x3FC0(r2)
  fadds     f0, f0, f1
  b         .loc_0x150

.loc_0x148:
  lfs       f0, -0x3FC0(r2)
  fsubs     f0, f1, f0

.loc_0x150:
  fctiwz    f0, f0
  lwz       r3, 0x8(r31)
  stfd      f0, 0x60(r1)
  lwz       r0, 0x64(r1)
  stb       r0, 0xF0(r3)

.loc_0x164:
  lwz       r3, 0x4(r31)
  lwz       r0, 0x74(r1)
  lwz       r31, 0x6C(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801E9F7C
 * Size:	000024
 */
void zen::DrawWMPause::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x0(r3)
  bl        -0x256AC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}