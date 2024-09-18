#include "KusaItem.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E5DD8
 * Size:	0000A4
 */
KusaItem::KusaItem(CreatureProp* props, Shape* shape)
    : ItemCreature(0, props, shape)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  li        r4, 0x1D
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x224(r3)
	  bl        0xFAAC
	  lis       r3, 0x802C
	  subi      r3, r3, 0x43F0
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x114
	  addi      r3, r30, 0x3C8
	  stw       r0, 0x2B8(r30)
	  li        r4, 0
	  bl        -0x5D1F0
	  lis       r3, 0x8008
	  addi      r4, r3, 0x7E48
	  addi      r3, r30, 0x3DC
	  li        r5, 0
	  li        r6, 0x68
	  li        r7, 0xA
	  bl        0x12EC34
	  lfs       f0, -0x6688(r2)
	  mr        r3, r30
	  stfs      f0, 0x81C(r30)
	  stfs      f0, 0x818(r30)
	  stfs      f0, 0x814(r30)
	  stw       r31, 0x224(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x200
	  stw       r0, 0xC8(r30)
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
 * Address:	800E5E7C
 * Size:	000118
 */
void KusaItem::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  addi      r0, r31, 0x3C8
	  lwz       r3, 0xC8(r3)
	  addi      r5, r31, 0x3DC
	  addi      r6, r31, 0x7EC
	  ori       r3, r3, 0x200
	  stw       r3, 0xC8(r31)
	  stw       r0, 0x220(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x308(r31)
	  bl        -0x5C350
	  lis       r4, 0x726F
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x7065
	  li        r5, 0x1
	  bl        -0x5C2C0
	  lfs       f0, -0x37B8(r13)
	  li        r4, 0x1
	  stfs      f0, 0x7C(r31)
	  lfs       f0, -0x37B4(r13)
	  stfs      f0, 0x80(r31)
	  lfs       f0, -0x37B0(r13)
	  stfs      f0, 0x84(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x814(r31)
	  stw       r0, 0x818(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x81C(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x7E008
	  stfs      f1, 0x818(r31)
	  li        r4, 0x23
	  lfs       f0, -0x6684(r2)
	  stfs      f0, 0x58(r31)
	  lfs       f0, -0x6680(r2)
	  stfs      f0, 0x5C(r31)
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x820(r31)
	  lwz       r3, 0x820(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0x814
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x820(r31)
	  li        r4, 0
	  stw       r31, 0x820(r3)
	  lwz       r3, 0x820(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x104:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5F94
 * Size:	000060
 */
void KusaItem::doLoad(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x58(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, 0x5C(r31)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4C
	  lwz       r3, 0x820(r31)
	  li        r0, 0
	  stb       r0, 0x824(r3)

	.loc_0x4C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5FF4
 * Size:	000038
 */
void KusaItem::doSave(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x4(r4)
	  lfs       f1, 0x58(r5)
	  lwz       r12, 0x30(r12)
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
 * Address:	800E602C
 * Size:	00001C
 */
bool KusaItem::ignoreAtari(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x184(r4)
	  cmplw     r0, r3
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6048
 * Size:	000008
 */
f32 KusaItem::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x667C(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6050
 * Size:	000008
 */
f32 KusaItem::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x6688(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6058
 * Size:	000038
 */
void KusaItem::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x814(r3)
	  lwz       r0, 0x818(r3)
	  stw       r4, 0x94(r3)
	  stw       r0, 0x98(r3)
	  lwz       r0, 0x81C(r3)
	  stw       r0, 0x9C(r3)
	  bl        0xFB78
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6090
 * Size:	000144
 */
void KusaItem::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  addi      r0, r1, 0x28
	  mr        r31, r4
	  stw       r30, 0xB8(r1)
	  mr        r30, r3
	  addi      r6, r1, 0x10
	  lfs       f4, 0x58(r3)
	  addi      r5, r1, 0x1C
	  lfs       f3, 0x5C(r3)
	  mr        r4, r0
	  lfs       f2, -0x3794(r13)
	  fsubs     f5, f4, f3
	  lfs       f1, -0x37A0(r13)
	  stfs      f2, 0x10(r1)
	  addi      r3, r1, 0x34
	  lfs       f0, -0x37AC(r13)
	  stfs      f1, 0x1C(r1)
	  lfs       f3, -0x379C(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f1, -0x37A8(r13)
	  lfs       f4, -0x3790(r13)
	  stfs      f5, 0x14(r1)
	  lfs       f2, -0x3798(r13)
	  stfs      f3, 0x20(r1)
	  lfs       f0, -0x37A4(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f4, 0x18(r1)
	  stfs      f2, 0x24(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0xA801C
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xA8030
	  addi      r3, r30, 0x228
	  addi      r4, r1, 0x34
	  bl        -0xA81FC
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x74
	  addi      r3, r3, 0x1E0
	  bl        -0xA8070
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x308(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x74
	  li        r6, 0
	  bl        -0xB0E80
	  lwz       r3, 0x308(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xB5D3C
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x5C6CC
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E61D4
 * Size:	0000D8
 */
BoBaseItem::BoBaseItem(CreatureProp* props, Shape* shape)
    : ItemCreature(0, props, shape)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  li        r4, 0x23
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x224(r3)
	  bl        0xF6B0
	  lis       r3, 0x802C
	  subi      r3, r3, 0x458C
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x114
	  addi      r3, r30, 0x3C8
	  stw       r0, 0x2B8(r30)
	  li        r4, 0
	  bl        -0x5D5EC
	  lis       r3, 0x8008
	  addi      r4, r3, 0x7E48
	  addi      r3, r30, 0x3DC
	  li        r5, 0
	  li        r6, 0x68
	  li        r7, 0xA
	  bl        0x12E838
	  lfs       f0, -0x6688(r2)
	  li        r0, 0
	  li        r3, 0x28
	  stfs      f0, 0x81C(r30)
	  stfs      f0, 0x818(r30)
	  stfs      f0, 0x814(r30)
	  stw       r31, 0x224(r30)
	  lwz       r4, 0xC8(r30)
	  ori       r4, r4, 0x200
	  stw       r4, 0xC8(r30)
	  stw       r0, 0x820(r30)
	  bl        -0x9F264
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xA8
	  bl        -0x4261C

	.loc_0xA8:
	  stw       r31, 0x2C(r30)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r3, 0x2C(r30)
	  bl        -0x42558
	  mr        r3, r30
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
 * Address:	800E62AC
 * Size:	0000AC
 */
void BoBaseItem::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  addi      r0, r31, 0x3C8
	  lwz       r3, 0xC8(r3)
	  addi      r5, r31, 0x3DC
	  addi      r6, r31, 0x7EC
	  ori       r3, r3, 0x200
	  stw       r3, 0xC8(r31)
	  stw       r0, 0x220(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x308(r31)
	  bl        -0x5C780
	  lfs       f0, -0x378C(r13)
	  li        r4, 0x1
	  stfs      f0, 0x7C(r31)
	  lfs       f0, -0x3788(r13)
	  stfs      f0, 0x80(r31)
	  lfs       f0, -0x3784(r13)
	  stfs      f0, 0x84(r31)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x814(r31)
	  stw       r0, 0x818(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x81C(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x7E424
	  stfs      f1, 0x818(r31)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x824(r31)
	  stw       r0, 0x828(r31)
	  stb       r0, 0x825(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6358
 * Size:	000030
 */
bool BoBaseItem::ignoreAtari(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x184(r4)
	  cmplw     r0, r3
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lwz       r0, 0x820(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x28
	  li        r3, 0x1
	  blr

	.loc_0x28:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6388
 * Size:	000008
 */
f32 BoBaseItem::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x667C(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6390
 * Size:	000008
 */
f32 BoBaseItem::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x6688(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6398
 * Size:	0000B4
 */
void BoBaseItem::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lbz       r0, 0x824(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  lwz       r4, 0x814(r30)
	  mr        r3, r30
	  lwz       r0, 0x818(r30)
	  stw       r4, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0x81C(r30)
	  stw       r0, 0x9C(r30)
	  bl        0xF81C
	  lbz       r3, 0x825(r30)
	  subi      r0, r3, 0x1
	  stb       r0, 0x825(r30)
	  lbz       r0, 0x825(r30)
	  extsb.    r0, r0
	  bgt-      .loc_0x9C
	  li        r31, 0
	  stb       r31, 0x825(r30)
	  lwz       r4, 0x828(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x9C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBB1B0
	  stw       r31, 0x828(r30)
	  b         .loc_0x9C

	.loc_0x88:
	  lbz       r3, 0x825(r30)
	  extsb.    r0, r3
	  ble-      .loc_0x9C
	  subi      r0, r3, 0x1
	  stb       r0, 0x825(r30)

	.loc_0x9C:
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
 * Address:	800E644C
 * Size:	0000EC
 */
void BoBaseItem::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  lbz       r0, 0x824(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  bne-      .loc_0xD4
	  lbz       r0, 0x825(r30)
	  extsb.    r0, r0
	  ble-      .loc_0xD4

	.loc_0x38:
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xA83A0
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0xA83D4
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x308(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x10
	  li        r6, 0
	  bl        -0xB11E4
	  lwz       r3, 0x308(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xB60A0
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x5CA30

	.loc_0xD4:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6538
 * Size:	000110
 */
void BoBaseItem::interactBuild(InteractBuild&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x820(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  lfs       f1, -0x6678(r2)
	  lfs       f0, 0xC(r4)
	  lfsu      f2, 0x58(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x820(r31)
	  lfs       f1, 0x5C(r3)
	  addi      r4, r3, 0x58
	  lfs       f0, 0x58(r3)
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB0
	  stfs      f1, 0x0(r4)
	  li        r0, 0
	  addi      r5, r31, 0x94
	  stb       r0, 0x824(r31)
	  li        r4, 0xC7
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  bl        0xB658C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAB
	  bl        -0x5C008
	  li        r0, 0x1E
	  stb       r0, 0x825(r31)
	  lwz       r4, 0x828(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xF0
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBAFE4
	  b         .loc_0xF0

	.loc_0xB0:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAD
	  bl        -0x5C040
	  li        r0, 0x1E
	  stb       r0, 0x825(r31)
	  lwz       r0, 0x828(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xF0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xC6
	  li        r6, 0
	  li        r7, 0
	  bl        0xB6518
	  stw       r3, 0x828(r31)

	.loc_0xF0:
	  li        r3, 0x1
	  b         .loc_0xFC

	.loc_0xF8:
	  li        r3, 0

	.loc_0xFC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6648
 * Size:	000008
 */
bool BoBaseItem::isAlive()
{
	/*
	.loc_0x0:
	  lbz       r3, 0x824(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6650
 * Size:	000008
 */
bool BoBaseItem::isVisible() { return true; }

/*
 * --INFO--
 * Address:	800E6658
 * Size:	000008
 */
bool KusaItem::isVisible() { return true; }

/*
 * --INFO--
 * Address:	800E6660
 * Size:	000008
 */
bool KusaItem::isAlive() { return true; }
