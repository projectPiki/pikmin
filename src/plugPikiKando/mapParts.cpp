#include "MapMgr.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

char* MapParts::shapeFiles[4] = {
	"mapparts/cone.mod",
	"mapparts/cylinder.mod",
	"mapparts/cube.mod",
	"mapparts/board.mod",
};

/*
 * --INFO--
 * Address:	801184A8
 * Size:	000018
 */
char* MapParts::getShapeFile(int idx)
{
	return shapeFiles[idx];
}

/*
 * --INFO--
 * Address:	801184C0
 * Size:	00005C
 */
void MapParts::applyVelocity(Plane&, Vector3f&, Vector3f& p3)
{
	mVelocity = mVelocity + p3;
}

/*
 * --INFO--
 * Address:	8011851C
 * Size:	000078
 */
MapEntity::MapEntity(Shape* shape)
    : MapParts(shape)
{
	mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80118594
 * Size:	000100
 */
void MapEntity::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f0, 0x144(r3)
	  lfs       f3, 0x28C(r4)
	  lfs       f2, 0x14C(r3)
	  fmuls     f0, f0, f3
	  lfs       f1, 0x148(r3)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f2, 0x98(r1)
	  lfs       f1, 0x134(r3)
	  lfs       f0, 0x90(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f1, 0x138(r3)
	  lfs       f0, 0x94(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x13C(r3)
	  lfs       f0, 0x98(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lwz       r4, 0x9C(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r4, 0x134(r3)
	  stw       r0, 0x138(r3)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0x13C(r3)
	  lfs       f2, -0x2214(r13)
	  lfs       f6, 0x144(r3)
	  lfs       f4, 0x14C(r3)
	  lfs       f5, 0x148(r3)
	  fmuls     f0, f6, f2
	  fmuls     f1, f4, f2
	  fmuls     f3, f5, f2
	  stfs      f0, 0x60(r1)
	  fsubs     f0, f4, f1
	  lfs       f2, 0x60(r1)
	  fsubs     f1, f5, f3
	  fsubs     f2, f6, f2
	  stfs      f2, 0x54(r1)
	  lfs       f2, 0x54(r1)
	  stfs      f2, 0x80(r1)
	  stfs      f1, 0x84(r1)
	  stfs      f0, 0x88(r1)
	  lwz       r4, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stw       r4, 0x144(r3)
	  stw       r0, 0x148(r3)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x14C(r3)
	  bl        -0xB67B4
	  lwz       r0, 0xAC(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80118694
 * Size:	0000D0
 */
MapSlider::MapSlider(Shape* shape, int p2, int p3, f32 p4, f32 p5, f32 p6, int p7)
    : MapParts(shape)
{
	_160           = p2;
	_164           = p3;
	_168           = p4;
	_16C           = p5;
	_170           = p6;
	_174           = p7;
	mFaceDirection = 0.0f;
}

/*
 * --INFO--
 * Address:	80118764
 * Size:	000040
 */
void MapSlider::init()
{
	if (mCurrentPart) {
		mPosition = mCurrentPart->mStartPosition;
		_180      = _168;
		_178      = 2;
		_17C      = 1;
	}
}

/*
 * --INFO--
 * Address:	801187A4
 * Size:	00036C
 */
void MapSlider::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stfd      f28, 0xF0(r1)
	  stw       r31, 0xEC(r1)
	  stw       r30, 0xE8(r1)
	  mr        r30, r3
	  lwz       r0, 0x17C(r3)
	  li        r3, -0x1
	  lwz       r5, 0x20(r30)
	  lwz       r4, 0x160(r30)
	  cmpwi     r0, 0x1
	  subc      r0, r5, r4
	  subfze    r31, r3
	  bne-      .loc_0x50
	  lfs       f31, 0x168(r30)
	  b         .loc_0x54

	.loc_0x50:
	  lfs       f31, 0x16C(r30)

	.loc_0x54:
	  lwz       r0, 0x140(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x300
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x144(r30)
	  lfs       f3, 0x28C(r3)
	  lfs       f2, 0x14C(r30)
	  fmuls     f0, f0, f3
	  lfs       f1, 0x148(r30)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f1, 0xB0(r1)
	  stfs      f2, 0xB4(r1)
	  lfs       f1, 0x134(r30)
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f1, 0x138(r30)
	  lfs       f0, 0xB0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x13C(r30)
	  lfs       f0, 0xB4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r3, 0x134(r30)
	  stw       r0, 0x138(r30)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x13C(r30)
	  lfs       f0, -0x6048(r2)
	  stfs      f0, 0xDC(r1)
	  stfs      f0, 0xD8(r1)
	  lwz       r0, 0x17C(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x104
	  lwz       r4, 0x140(r30)
	  b         .loc_0x10C

	.loc_0x104:
	  lwz       r3, 0x140(r30)
	  addi      r4, r3, 0xC

	.loc_0x10C:
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0xD4(r1)
	  stw       r0, 0xD8(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0xDC(r1)
	  lfs       f3, 0xD4(r1)
	  lfs       f2, 0x134(r30)
	  lfs       f1, 0xD8(r1)
	  lfs       f0, 0x138(r30)
	  fsubs     f30, f3, f2
	  lfs       f2, 0xDC(r1)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x13C(r30)
	  fmuls     f1, f30, f30
	  fsubs     f28, f2, f0
	  fmuls     f0, f29, f29
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x10ACC0
	  lfs       f0, -0x6048(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x178
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1

	.loc_0x178:
	  lfs       f3, 0x170(r30)
	  fmuls     f2, f30, f3
	  fmuls     f0, f29, f3
	  fmuls     f3, f28, f3
	  stfs      f2, 0x6C(r1)
	  lfs       f2, 0x6C(r1)
	  stfs      f2, 0x90(r1)
	  stfs      f0, 0x94(r1)
	  stfs      f3, 0x98(r1)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0x144(r30)
	  stw       r0, 0x148(r30)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x14C(r30)
	  lwz       r0, 0x178(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x1F8
	  bge-      .loc_0x1D0
	  cmpwi     r0, 0
	  bge-      .loc_0x1DC
	  b         .loc_0x33C

	.loc_0x1D0:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x33C
	  b         .loc_0x2CC

	.loc_0x1DC:
	  lfs       f0, -0x6044(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x33C
	  li        r0, 0x3
	  stw       r0, 0x178(r30)
	  stfs      f31, 0x180(r30)
	  b         .loc_0x33C

	.loc_0x1F8:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x180(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x180(r30)
	  lfs       f0, -0x2210(r13)
	  stfs      f0, 0x144(r30)
	  lfs       f0, -0x220C(r13)
	  stfs      f0, 0x148(r30)
	  lfs       f0, -0x2208(r13)
	  stfs      f0, 0x14C(r30)
	  lwz       r0, 0x174(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x23C
	  lwz       r0, 0x17C(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x298

	.loc_0x23C:
	  lfs       f1, 0x180(r30)
	  lfs       f0, -0x6048(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x27C
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x27C
	  lwz       r0, 0x17C(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x268
	  li        r0, 0
	  b         .loc_0x26C

	.loc_0x268:
	  li        r0, 0x1

	.loc_0x26C:
	  stw       r0, 0x17C(r30)
	  lwz       r0, 0x17C(r30)
	  stw       r0, 0x178(r30)
	  b         .loc_0x33C

	.loc_0x27C:
	  lwz       r0, 0x160(r30)
	  cmpwi     r0, 0x1
	  blt-      .loc_0x33C
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0x33C
	  stfs      f31, 0x180(r30)
	  b         .loc_0x33C

	.loc_0x298:
	  lfs       f1, 0x180(r30)
	  lfs       f0, -0x6048(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x33C
	  cmpwi     r0, 0x1
	  bne-      .loc_0x2B8
	  li        r0, 0
	  b         .loc_0x2BC

	.loc_0x2B8:
	  li        r0, 0x1

	.loc_0x2BC:
	  stw       r0, 0x17C(r30)
	  lwz       r0, 0x17C(r30)
	  stw       r0, 0x178(r30)
	  b         .loc_0x33C

	.loc_0x2CC:
	  lfs       f0, -0x2204(r13)
	  stfs      f0, 0x144(r30)
	  lfs       f0, -0x2200(r13)
	  stfs      f0, 0x148(r30)
	  lfs       f0, -0x21FC(r13)
	  stfs      f0, 0x14C(r30)
	  lwz       r0, 0x20(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x33C
	  li        r0, 0x2
	  stw       r0, 0x178(r30)
	  stfs      f31, 0x180(r30)
	  b         .loc_0x33C

	.loc_0x300:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x15C(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x15C(r30)
	  lfs       f1, -0x6040(r2)
	  lfs       f0, 0x15C(r30)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x130(r30)
	  lfs       f0, 0x150(r30)
	  stfs      f0, 0x134(r30)
	  lfs       f0, 0x154(r30)
	  stfs      f0, 0x138(r30)
	  lfs       f0, 0x158(r30)
	  stfs      f0, 0x13C(r30)

	.loc_0x33C:
	  mr        r3, r30
	  bl        -0xB6C18
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lfd       f28, 0xF0(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80118B10
 * Size:	0001EC
 */
void MapSlider::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stw       r31, 0x12C(r1)
	  stw       r30, 0x128(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x124(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x114
	  stw       r28, 0x120(r1)
	  addi      r4, r29, 0xDC
	  lfs       f0, -0x21F8(r13)
	  lfs       f1, -0x21F4(r13)
	  stfs      f0, 0x114(r1)
	  lfs       f0, -0x21F0(r13)
	  stfs      f1, 0x118(r1)
	  stfs      f0, 0x11C(r1)
	  bl        -0xE1408
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r30)
	  addi      r0, r3, 0
	  lis       r4, 0x803A
	  lwz       r12, 0x74(r12)
	  addi      r3, r30, 0
	  subi      r4, r4, 0x77C0
	  mtlr      r12
	  mr        r31, r0
	  li        r5, 0
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r30, 0
	  stb       r0, 0x11(r1)
	  li        r5, 0x1
	  stb       r0, 0x12(r1)
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x3B4(r30)
	  li        r5, 0
	  lwz       r4, 0x10(r4)
	  lwz       r12, 0xCC(r12)
	  lwz       r4, 0x0(r4)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x20(r29)
	  addi      r28, r3, 0
	  lwz       r0, 0x160(r29)
	  sub.      r0, r0, r4
	  mr        r5, r0
	  bge-      .loc_0x114
	  li        r5, 0

	.loc_0x114:
	  lis       r3, 0x802C
	  crclr     6, 0x6
	  addi      r4, r3, 0x3258
	  addi      r3, r1, 0x14
	  bl        0xFD964
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x14
	  lwz       r3, 0x10(r3)
	  bl        -0xF0B10
	  lwz       r12, 0x3B4(r30)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r30, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x114
	  crclr     6, 0x6
	  addi      r8, r1, 0x14
	  li        r7, 0
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  mr        r4, r28
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0xDC
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0xB6D88
	  lwz       r0, 0x134(r1)
	  lwz       r31, 0x12C(r1)
	  lwz       r30, 0x128(r1)
	  lwz       r29, 0x124(r1)
	  lwz       r28, 0x120(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80118CFC
 * Size:	000004
 */
void MapParts::read(RandomAccessStream&)
{
}

/*
 * --INFO--
 * Address:	80118D00
 * Size:	000004
 */
void MapParts::update()
{
}
