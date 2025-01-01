#include "FishItem.h"
#include "Graphics.h"
#include "UtilityKando.h"
#include "Dolphin/os.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
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
 * Address:	800E6668
 * Size:	0000B0
 */
FishGenerator::FishGenerator()
    : ItemCreature(OBJTYPE_Fish, nullptr, nullptr)
{
	mMaxFish   = 32;
	mFishCount = 0;
	mFish      = new Fish[mMaxFish];
}

/*
 * --INFO--
 * Address:	800E6738
 * Size:	0001B4
 */
void FishGenerator::startAI(int)
{
	mFishCount = 32;
	for (int i = 0; i < mFishCount; i++) {
		Fish* fish      = &mFish[i];
		f32 randMag     = randFloat(40.0f);
		f32 randAngle   = 2.0f * randFloat(PI);
		fish->mPosition = mPosition + Vector3f(randMag * sinf(randAngle), 4.0f, randMag * cosf(randAngle));
		fish->_0C.set(0.0f, 0.0f, 0.0f);
		fish->mDirection = 2.0f * randFloat(PI);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x20
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stfd      f29, 0xC8(r1)
	  stfd      f28, 0xC0(r1)
	  stfd      f27, 0xB8(r1)
	  stfd      f26, 0xB0(r1)
	  stfd      f25, 0xA8(r1)
	  stfd      f24, 0xA0(r1)
	  stfd      f23, 0x98(r1)
	  stmw      r27, 0x84(r1)
	  addi      r27, r3, 0
	  li        r29, 0
	  li        r30, 0
	  lis       r31, 0x4330
	  stw       r0, 0x3C8(r3)
	  lfd       f26, -0x6658(r2)
	  lfs       f27, -0x6668(r2)
	  lfs       f28, -0x666C(r2)
	  lfs       f29, -0x6664(r2)
	  lfs       f30, -0x6660(r2)
	  lfs       f31, -0x665C(r2)
	  b         .loc_0x170

	.loc_0x68:
	  lwz       r0, 0x3D0(r27)
	  add       r28, r0, r30
	  bl        0x1318C8
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x7C(r1)
	  stw       r31, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f26
	  fdivs     f0, f0, f27
	  fmuls     f0, f28, f0
	  fmuls     f24, f29, f0
	  bl        0x1318A4
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x74(r1)
	  stw       r31, 0x70(r1)
	  lfd       f0, 0x70(r1)
	  fsubs     f0, f0, f26
	  fdivs     f0, f0, f27
	  fmuls     f0, f28, f0
	  fmuls     f0, f31, f0
	  fmuls     f23, f30, f0
	  fmr       f1, f23
	  bl        0x13535C
	  fmuls     f25, f24, f1
	  fmr       f1, f23
	  bl        0x1354E4
	  fmuls     f1, f24, f1
	  lfs       f0, -0x3740(r13)
	  stfs      f1, 0x48(r1)
	  lfs       f2, 0x94(r27)
	  lfs       f1, 0x48(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x3C(r1)
	  lfs       f1, 0x3C(r1)
	  stfs      f1, 0x58(r1)
	  lfs       f1, 0x98(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x9C(r27)
	  fadds     f0, f0, f25
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0x0(r28)
	  stw       r0, 0x4(r28)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x8(r28)
	  lfs       f0, -0x373C(r13)
	  stfs      f0, 0xC(r28)
	  lfs       f0, -0x3738(r13)
	  stfs      f0, 0x10(r28)
	  lfs       f0, -0x3734(r13)
	  stfs      f0, 0x14(r28)
	  bl        0x1317FC
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x6C(r1)
	  addi      r30, r30, 0x1C
	  addi      r29, r29, 0x1
	  stw       r31, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f26
	  fdivs     f0, f0, f27
	  fmuls     f0, f28, f0
	  fmuls     f0, f31, f0
	  fmuls     f0, f30, f0
	  stfs      f0, 0x18(r28)

	.loc_0x170:
	  lwz       r0, 0x3C8(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x68
	  lmw       r27, 0x84(r1)
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  lfd       f28, 0xC0(r1)
	  lfd       f27, 0xB8(r1)
	  lfd       f26, 0xB0(r1)
	  lfd       f25, 0xA8(r1)
	  lfd       f24, 0xA0(r1)
	  lfd       f23, 0x98(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E68EC
 * Size:	000140
 */
void FishGenerator::update()
{
	mSchoolCentre.set(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < mFishCount; i++) {
		mSchoolCentre = mSchoolCentre + mFish[i].mPosition;
	}

	mSchoolCentre.scale(1.0f / mFishCount);

	for (int i = 0; i < mFishCount; i++) {
		moveFish(&mFish[i]);
	}
}

/*
 * --INFO--
 * Address:	800E6A2C
 * Size:	000554
 */
void FishGenerator::moveFish(Fish*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x308(r1)
	  stfd      f31, 0x300(r1)
	  stfd      f30, 0x2F8(r1)
	  stfd      f29, 0x2F0(r1)
	  stfd      f28, 0x2E8(r1)
	  stfd      f27, 0x2E0(r1)
	  stfd      f26, 0x2D8(r1)
	  stfd      f25, 0x2D0(r1)
	  stfd      f24, 0x2C8(r1)
	  stfd      f23, 0x2C0(r1)
	  stfd      f22, 0x2B8(r1)
	  stfd      f21, 0x2B0(r1)
	  stmw      r25, 0x294(r1)
	  mr        r25, r3
	  mr        r31, r4
	  li        r28, 0
	  li        r27, 0
	  li        r29, 0
	  li        r30, 0
	  lfs       f21, -0x6650(r2)
	  lfs       f29, -0x3724(r13)
	  fmr       f30, f21
	  lfs       f28, -0x3720(r13)
	  lfs       f27, -0x371C(r13)
	  lfs       f26, -0x3718(r13)
	  lfs       f25, -0x3714(r13)
	  lfs       f24, -0x3710(r13)
	  lfs       f31, -0x664C(r2)
	  lfs       f22, -0x6670(r2)
	  b         .loc_0x140

	.loc_0x80:
	  lwz       r0, 0x3D0(r25)
	  add       r0, r0, r30
	  cmplw     r0, r31
	  mr        r26, r0
	  beq-      .loc_0x138
	  lfs       f1, 0x0(r26)
	  lfs       f2, 0x8(r26)
	  lfs       f3, 0x0(r31)
	  lfs       f4, 0x8(r31)
	  bl        -0xAE4A8
	  fmr       f23, f1
	  fcmpo     cr0, f23, f30
	  bge-      .loc_0xD0
	  lfs       f2, 0xC(r26)
	  addi      r27, r27, 0x1
	  lfs       f1, 0x10(r26)
	  lfs       f0, 0x14(r26)
	  fadds     f29, f29, f2
	  fadds     f28, f28, f1
	  fadds     f27, f27, f0

	.loc_0xD0:
	  fcmpo     cr0, f23, f21
	  bge-      .loc_0x138
	  fcmpo     cr0, f23, f31
	  mr        r28, r26
	  bge-      .loc_0x134
	  lfs       f3, 0x0(r31)
	  lfs       f2, 0x0(r26)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x4(r26)
	  fsubs     f26, f3, f2
	  lfs       f2, 0x8(r31)
	  fsubs     f25, f1, f0
	  lfs       f0, 0x8(r26)
	  fmuls     f1, f26, f26
	  fsubs     f24, f2, f0
	  fmuls     f0, f25, f25
	  fmuls     f2, f24, f24
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD8F08
	  fcmpu     cr0, f22, f1
	  beq-      .loc_0x134
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1

	.loc_0x134:
	  fmr       f21, f23

	.loc_0x138:
	  addi      r30, r30, 0x1C
	  addi      r29, r29, 0x1

	.loc_0x140:
	  lwz       r0, 0x3C8(r25)
	  cmpw      r29, r0
	  blt+      .loc_0x80
	  cmpwi     r27, 0
	  ble-      .loc_0x184
	  xoris     r0, r27, 0x8000
	  lfd       f1, -0x6658(r2)
	  stw       r0, 0x28C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x666C(r2)
	  stw       r0, 0x288(r1)
	  lfd       f0, 0x288(r1)
	  fsubs     f0, f0, f1
	  fdivs     f0, f2, f0
	  fmuls     f29, f29, f0
	  fmuls     f28, f28, f0
	  fmuls     f27, f27, f0

	.loc_0x184:
	  cmplwi    r28, 0
	  beq-      .loc_0x304
	  bl        0x1314B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6658(r2)
	  stw       r0, 0x28C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6668(r2)
	  stw       r0, 0x288(r1)
	  lfs       f1, -0x666C(r2)
	  lfd       f3, 0x288(r1)
	  lfs       f0, -0x6648(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x304
	  lfs       f3, 0x3D4(r25)
	  lfs       f2, 0x0(r31)
	  lfs       f1, 0x3D8(r25)
	  lfs       f0, 0x4(r31)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x3DC(r25)
	  fsubs     f31, f1, f0
	  lfs       f0, 0x8(r31)
	  fmuls     f1, f30, f30
	  fsubs     f23, f2, f0
	  fmuls     f0, f31, f31
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD8FEC
	  lfs       f0, -0x6670(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x21C
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f23, f23, f1

	.loc_0x21C:
	  lfs       f8, -0x3704(r13)
	  lfs       f4, -0x370C(r13)
	  lfs       f5, -0x3708(r13)
	  fmuls     f0, f29, f8
	  fmuls     f1, f30, f4
	  lfs       f7, -0x3700(r13)
	  fmuls     f2, f26, f5
	  stfs      f0, 0x154(r1)
	  lfs       f6, -0x36FC(r13)
	  fmuls     f1, f1, f7
	  lfs       f3, 0x154(r1)
	  fmuls     f2, f2, f6
	  fmuls     f0, f28, f8
	  stfs      f3, 0x1E4(r1)
	  stfs      f2, 0x138(r1)
	  fmuls     f2, f27, f8
	  stfs      f1, 0x14C(r1)
	  fmuls     f1, f31, f4
	  fmuls     f4, f23, f4
	  stfs      f0, 0x1E8(r1)
	  fmuls     f0, f25, f5
	  fmuls     f1, f1, f7
	  stfs      f2, 0x1EC(r1)
	  fmuls     f4, f4, f7
	  lfs       f3, 0x1E4(r1)
	  fmuls     f0, f0, f6
	  lfs       f2, 0x14C(r1)
	  fmuls     f5, f24, f5
	  fadds     f2, f3, f2
	  fmuls     f3, f5, f6
	  stfs      f2, 0x140(r1)
	  lfs       f2, 0x140(r1)
	  stfs      f2, 0x1F0(r1)
	  lfs       f2, 0x1E8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x1F4(r1)
	  lfs       f1, 0x1EC(r1)
	  fadds     f1, f1, f4
	  stfs      f1, 0x1F8(r1)
	  lfs       f2, 0x1F0(r1)
	  lfs       f1, 0x138(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x12C(r1)
	  lfs       f1, 0x12C(r1)
	  stfs      f1, 0x1FC(r1)
	  lfs       f1, 0x1F4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x200(r1)
	  lfs       f0, 0x1F8(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0x204(r1)
	  lwz       r3, 0x1FC(r1)
	  lwz       r0, 0x200(r1)
	  stw       r3, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x204(r1)
	  stw       r0, 0x14(r31)
	  b         .loc_0x468

	.loc_0x304:
	  bl        0x131340
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x6658(r2)
	  stw       r0, 0x28C(r1)
	  lis       r0, 0x4330
	  lfs       f5, -0x6668(r2)
	  stw       r0, 0x288(r1)
	  lfs       f4, -0x666C(r2)
	  lfd       f0, 0x288(r1)
	  lfs       f1, -0x6644(r2)
	  fsubs     f6, f0, f2
	  lfs       f2, -0x665C(r2)
	  lfs       f3, -0x6648(r2)
	  lfs       f0, 0x18(r31)
	  fdivs     f5, f6, f5
	  fmuls     f4, f4, f5
	  fsubs     f1, f4, f1
	  fmuls     f1, f2, f1
	  fmuls     f1, f3, f1
	  fadds     f1, f0, f1
	  bl        -0xAE7F8
	  stfs      f1, 0x18(r31)
	  lfs       f3, 0x3D4(r25)
	  lfs       f2, 0x0(r31)
	  lfs       f1, 0x3D8(r25)
	  lfs       f0, 0x4(r31)
	  fsubs     f24, f3, f2
	  lfs       f2, 0x3DC(r25)
	  fsubs     f25, f1, f0
	  lfs       f0, 0x8(r31)
	  fmuls     f1, f24, f24
	  fsubs     f22, f2, f0
	  fmuls     f0, f25, f25
	  fmuls     f2, f22, f22
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD9180
	  lfs       f0, -0x6670(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x3B0
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f22, f22, f1

	.loc_0x3B0:
	  lfs       f26, -0x36F8(r13)
	  lfs       f1, 0x18(r31)
	  fmuls     f22, f22, f26
	  bl        0x134D6C
	  fmr       f23, f1
	  lfs       f1, 0x18(r31)
	  bl        0x134EF4
	  lfs       f5, -0x36F0(r13)
	  fmuls     f3, f24, f26
	  lfs       f6, -0x36E8(r13)
	  fmuls     f0, f25, f26
	  fmuls     f2, f1, f5
	  lfs       f7, -0x36EC(r13)
	  lfs       f1, -0x36F4(r13)
	  fmuls     f4, f3, f6
	  fmuls     f2, f2, f7
	  fmuls     f1, f1, f5
	  fmuls     f5, f23, f5
	  stfs      f4, 0x104(r1)
	  fmuls     f0, f0, f6
	  stfs      f2, 0x10C(r1)
	  fmuls     f2, f1, f7
	  lfs       f3, 0x10C(r1)
	  fmuls     f1, f5, f7
	  stfs      f3, 0x1A8(r1)
	  fmuls     f3, f22, f6
	  stfs      f2, 0x1AC(r1)
	  stfs      f1, 0x1B0(r1)
	  lfs       f2, 0x1A8(r1)
	  lfs       f1, 0x104(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xF8(r1)
	  lfs       f1, 0xF8(r1)
	  stfs      f1, 0x1B4(r1)
	  lfs       f1, 0x1AC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1B8(r1)
	  lfs       f0, 0x1B0(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0x1BC(r1)
	  lwz       r3, 0x1B4(r1)
	  lwz       r0, 0x1B8(r1)
	  stw       r3, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x1BC(r1)
	  stw       r0, 0x14(r31)

	.loc_0x468:
	  lfs       f0, -0x6670(r2)
	  li        r7, 0
	  addi      r5, r1, 0x214
	  stfs      f0, 0x21C(r1)
	  li        r4, 0
	  stfs      f0, 0x218(r1)
	  stfs      f0, 0x214(r1)
	  stfs      f0, 0x228(r1)
	  stfs      f0, 0x224(r1)
	  stfs      f0, 0x220(r1)
	  stb       r7, 0x234(r1)
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x214(r1)
	  stw       r0, 0x218(r1)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x21C(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x10(r31)
	  stw       r3, 0x220(r1)
	  stw       r0, 0x224(r1)
	  lwz       r0, 0x14(r31)
	  stw       r0, 0x228(r1)
	  lfs       f0, -0x666C(r2)
	  lwz       r6, 0x2DEC(r13)
	  stfs      f0, 0x22C(r1)
	  lwz       r3, 0x2F00(r13)
	  stw       r7, 0x238(r1)
	  stfs      f0, 0x230(r1)
	  lfs       f1, 0x28C(r6)
	  bl        -0x7E0B8
	  lwz       r3, 0x214(r1)
	  lwz       r0, 0x218(r1)
	  stw       r3, 0x0(r31)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x21C(r1)
	  stw       r0, 0x8(r31)
	  lwz       r3, 0x220(r1)
	  lwz       r0, 0x224(r1)
	  stw       r3, 0xC(r31)
	  stw       r0, 0x10(r31)
	  lwz       r0, 0x228(r1)
	  stw       r0, 0x14(r31)
	  lwz       r0, 0x30C(r1)
	  lfd       f31, 0x300(r1)
	  lfd       f30, 0x2F8(r1)
	  lfd       f29, 0x2F0(r1)
	  lfd       f28, 0x2E8(r1)
	  lfd       f27, 0x2E0(r1)
	  lfd       f26, 0x2D8(r1)
	  lfd       f25, 0x2D0(r1)
	  lfd       f24, 0x2C8(r1)
	  lfd       f23, 0x2C0(r1)
	  lfd       f22, 0x2B8(r1)
	  lfd       f21, 0x2B0(r1)
	  lmw       r25, 0x294(r1)
	  addi      r1, r1, 0x308
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6F80
 * Size:	000098
 */
void FishGenerator::refresh(Graphics& gfx)
{
	gfx.useMatrix(Matrix4f::ident, 0);

	for (int i = 0; i < mFishCount; i++) {
		drawBatten(gfx, mFish[i].mPosition, 2.0f);
	}
}
