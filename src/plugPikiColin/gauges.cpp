#include "LifeGauge.h"
#include "Colour.h"
#include "sysNew.h"
#include "system.h"
#include "Light.h"
#include "gameflow.h"
#include "DebugLog.h"

static Colour lgborder;
static Colour lglev0;
static Colour lglev1;
static Colour lglev2;
static Colour lglev3;

LifeGaugeMgr* lgMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GaugeInfo::init()
{
	_18 = 0;
	_34 = 0;
	_3C = 0;
	_38 = 0;
	PRINT("gauge init\n");
	_24 = 0;
}

/*
 * --INFO--
 * Address:	8005B780
 * Size:	000150
 */
void GaugeInfo::update()
{
	switch (_18) {
	case 0: {
		_34 += gsys->getFrameTime() * 2.0f;

		if (_34 >= HALF_PI) {
			_18 = 1;
		}

		f32 rotation = _34 < HALF_PI ? _34 : HALF_PI;

		_3C = sinf(rotation) * 255.0f;
		_38 = sinf(rotation) * 30.0f;
		_40 = sinf(rotation) * 8.0f;
		_44 = sinf(rotation) * 8.0f;
		break;
	}

	case 1:
		if (_24) {
			_18 = 2;
		}
		break;

	case 2:
		_3C -= gsys->getFrameTime() * 1200.0f;
		if (_3C < 0.0f) {
			_3C = 0.0f;
			lgMgr->removeLG(this);
		}
	}
}

/*
 * --INFO--
 * Address:	8005B8D0, 100377F0 in DLL
 * Size:	000210
 */
void GaugeInfo::showDigits(Vector3f position, Colour& colour, int number, f32 width, f32 height)
{
	if (number > 99) {
		number = 99;
	}

	int num = number;

	// Either 1 or 2 digits (0-99)
	int numDigits = num >= 10 ? 2 : 1;

	// If 2 digits, move the position to the left
	if (numDigits == 2) {
		position.x += width * 0.5f * 1.5f;
	}

	for (int i = 0; i < numDigits; i++) {
		f32 divisor = 1 / 11.0f;
		f32 uvStart = (num % 10) * divisor;
		f32 uvEnd   = ((num % 10) + 1.0f) * divisor;

		lgMgr->mLFlare->addLFlare(colour, position, Vector2f(width, height), &Vector2f(uvStart, 0.0f), &Vector2f(uvEnd, 1.0f));

		num /= 10;
		position.x -= width * 1.5f;
	}
}

/*
 * --INFO--
 * Address:	8005BAE0
 * Size:	000270
 */
void GaugeInfo::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r3
	  stw       r30, 0x78(r1)
	  stw       r29, 0x74(r1)
	  stw       r28, 0x70(r1)
	  lwz       r3, 0x14(r3)
	  lfs       f1, 0x38(r31)
	  lfs       f2, 0x4(r3)
	  addi      r5, r3, 0x8
	  lfs       f0, 0x0(r3)
	  addi      r3, r1, 0x5C
	  fadds     f1, f2, f1
	  stfs      f0, 0x5C(r1)
	  stfs      f1, 0x60(r1)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x64(r1)
	  lwz       r4, 0x2E4(r4)
	  addi      r4, r4, 0x1E0
	  bl        -0x243EC
	  lfs       f0, 0x3C(r31)
	  li        r3, 0xFF
	  li        r0, 0x20
	  fctiwz    f0, f0
	  stb       r3, 0x58(r1)
	  stb       r0, 0x59(r1)
	  stfd      f0, 0x68(r1)
	  lwz       r3, 0x6C(r1)
	  stb       r0, 0x5A(r1)
	  stb       r3, 0x5B(r1)
	  lwz       r3, 0x1C(r31)
	  lwz       r0, 0x20(r31)
	  cmpw      r3, r0
	  bge-      .loc_0x9C
	  lfs       f2, -0x79C8(r2)
	  b         .loc_0xA0

	.loc_0x9C:
	  lfs       f2, -0x79DC(r2)

	.loc_0xA0:
	  cmpw      r3, r0
	  bge-      .loc_0xB0
	  lfs       f31, -0x79DC(r2)
	  b         .loc_0xB4

	.loc_0xB0:
	  lfs       f31, -0x79C8(r2)

	.loc_0xB4:
	  lfs       f0, 0x5C(r1)
	  addi      r4, r1, 0x40
	  addi      r3, r31, 0
	  stfs      f0, 0x40(r1)
	  addi      r5, r1, 0x58
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x40(r31)
	  lfs       f0, 0x44(r31)
	  fmuls     f1, f1, f2
	  lwz       r6, 0x1C(r31)
	  fmuls     f2, f0, f2
	  bl        -0x2FC
	  lfs       f1, 0x60(r1)
	  addi      r29, r1, 0x28
	  lfs       f0, -0x79C4(r2)
	  addi      r28, r1, 0x30
	  fadds     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f1, -0x79DC(r2)
	  lfs       f0, -0x79C0(r2)
	  stfs      f1, 0x28(r1)
	  lfs       f1, -0x7004(r13)
	  stfs      f0, 0x30(r1)
	  lfs       f0, -0x7008(r13)
	  stfs      f1, 0x2C(r1)
	  lwz       r4, 0x2EAC(r13)
	  stfs      f0, 0x34(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x40(r31)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x44(r31)
	  stfs      f0, 0x3C(r1)
	  lwz       r30, 0x90(r4)
	  bl        -0x1C1B0
	  cmplwi    r3, 0
	  beq-      .loc_0x1D8
	  lwz       r0, 0x58(r1)
	  cmplwi    r28, 0
	  stw       r0, 0x0(r3)
	  lwz       r4, 0x5C(r1)
	  lwz       r0, 0x60(r1)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0xC(r3)
	  lwz       r4, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  beq-      .loc_0x1B4
	  cmplwi    r29, 0
	  beq-      .loc_0x1B4
	  lwz       r4, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r4, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  b         .loc_0x1CC

	.loc_0x1B4:
	  lfs       f0, -0x7A00(r2)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, -0x79DC(r2)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x24(r3)

	.loc_0x1CC:
	  lwz       r0, 0x20(r30)
	  stw       r0, 0x28(r3)
	  stw       r3, 0x20(r30)

	.loc_0x1D8:
	  lfs       f1, 0x60(r1)
	  li        r6, 0x20
	  lfs       f0, -0x79C4(r2)
	  li        r0, 0xFF
	  addi      r4, r1, 0x1C
	  fadds     f0, f1, f0
	  addi      r3, r31, 0
	  addi      r5, r1, 0x58
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x3C(r31)
	  fctiwz    f0, f0
	  stb       r6, 0x58(r1)
	  stb       r6, 0x59(r1)
	  stfd      f0, 0x68(r1)
	  lwz       r6, 0x6C(r1)
	  stb       r0, 0x5A(r1)
	  stb       r6, 0x5B(r1)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x40(r31)
	  lfs       f0, 0x44(r31)
	  fmuls     f1, f1, f31
	  lwz       r6, 0x20(r31)
	  fmuls     f2, f0, f31
	  bl        -0x458
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  lwz       r28, 0x70(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005BD50
 * Size:	0000F0
 */
void LifeGaugeMgr::init(int count)
{
	_00.initCore("");
	_48.initCore("");

	GaugeInfo* gaugeList = new GaugeInfo[count];

	for (int i = 0; i < count; i++) {
		_48.add(&gaugeList[i]);
	}

	mLFlare             = gsys->registerLFlare(gsys->loadTexture("intro/item_0_9.bti", true));
	mLFlare->mBlendMode = 5;
}

/*
 * --INFO--
 * Address:	8005BE94
 * Size:	000040
 */
void LifeGaugeMgr::update()
{
	FOREACH_NODE(GaugeInfo, _00.mChild, gauge)
	{
		gauge->update();
	}
}

/*
 * --INFO--
 * Address:	8005BED4
 * Size:	000068
 */
void LifeGaugeMgr::refresh(Graphics& gfx)
{
	// WTF

	FOREACH_NODE(GaugeInfo, _00.mChild, gauge)
	{
		gauge->refresh(gfx);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r5, 0x1DC(r5)
	  lbz       r0, 0x124(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x50
	  lwz       r31, 0x10(r3)
	  b         .loc_0x48

	.loc_0x38:
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0x434
	  lwz       r31, 0xC(r31)

	.loc_0x48:
	  cmplwi    r31, 0
	  bne+      .loc_0x38

	.loc_0x50:
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
 * Address:	........
 * Size:	000080
 */
GaugeInfo* LifeGaugeMgr::getGaugeInfo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void LifeGaugeMgr::addLG(GaugeInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005BF3C
 * Size:	000060
 */
void LifeGaugeMgr::removeLG(GaugeInfo* info)
{
	info->del();
	info->initCore("");
	_48.add(info);
}

/*
 * --INFO--
 * Address:	8005BF9C
 * Size:	0000D8
 */
LifeGauge::LifeGauge()
{
	_1C          = 0;
	mIsNotFull   = 0;
	_24          = 0.0f;
	_28          = 0.0f;
	_20          = 0;
	_30          = 1.0f;
	mHealthRatio = 1.0f;

	lgborder.set(0x80, 0x80, 0x80, 0xC0);
	lglev3.set(0x00, 0xFF, 0x00, 0xFF);
	lglev2.set(0x80, 0xFF, 0x00, 0xFF);
	lglev1.set(0xFF, 0xFF, 0x00, 0xFF);
	lglev0.set(0xFF, 0x00, 0x00, 0xFF);

	mOffset.set(0.0f, 100.0f, 0.0f);
	mScale = 48.0f;
	_38    = 0;
}

/*
 * --INFO--
 * Address:	8005C074
 * Size:	000030
 */
void LifeGauge::updValue(f32 currHealth, f32 maxHealth)
{
	mHealthRatio = currHealth / maxHealth;
	if (mHealthRatio < 1.0f && _24 != 1.0f) {
		mIsNotFull = 1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void LifeGauge::adjustValue()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005C0A4
 * Size:	000EC8
 */
void LifeGauge::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x2B8(r1)
	  stfd      f31, 0x2B0(r1)
	  stfd      f30, 0x2A8(r1)
	  stfd      f29, 0x2A0(r1)
	  stfd      f28, 0x298(r1)
	  stfd      f27, 0x290(r1)
	  stfd      f26, 0x288(r1)
	  stfd      f25, 0x280(r1)
	  stfd      f24, 0x278(r1)
	  stfd      f23, 0x270(r1)
	  stmw      r26, 0x258(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  lwz       r5, 0x1DC(r5)
	  lbz       r0, 0x124(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0xE90
	  lwz       r0, 0x18(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x118
	  bge-      .loc_0x70
	  cmpwi     r0, 0x1
	  bge-      .loc_0x7C
	  b         .loc_0x20C

	.loc_0x70:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x20C
	  b         .loc_0x1D4

	.loc_0x7C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f3, 0x30(r29)
	  lfs       f2, 0x2C(r29)
	  lfs       f1, -0x79FC(r2)
	  lfs       f0, 0x28C(r3)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x30(r29)
	  lbz       r0, 0x20(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xCC
	  lfs       f2, 0x30(r29)
	  lfs       f1, 0x2C(r29)
	  lfs       f0, -0x79B8(r2)
	  fsubs     f1, f2, f1
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xD4

	.loc_0xCC:
	  lfs       f0, 0x2C(r29)
	  stfs      f0, 0x30(r29)

	.loc_0xD4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x79FC(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x24(r29)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x24(r29)
	  lfs       f1, 0x24(r29)
	  lfs       f0, -0x79DC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x20C
	  stfs      f0, 0x24(r29)
	  li        r0, 0x2
	  stw       r0, 0x18(r29)
	  lfs       f0, -0x79B4(r2)
	  stfs      f0, 0x28(r29)
	  b         .loc_0x20C

	.loc_0x118:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f3, 0x30(r29)
	  lfs       f2, 0x2C(r29)
	  lfs       f1, -0x79FC(r2)
	  lfs       f0, 0x28C(r3)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x30(r29)
	  lbz       r0, 0x20(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x168
	  lfs       f2, 0x30(r29)
	  lfs       f1, 0x2C(r29)
	  lfs       f0, -0x79B8(r2)
	  fsubs     f1, f2, f1
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x170

	.loc_0x168:
	  lfs       f0, 0x2C(r29)
	  stfs      f0, 0x30(r29)

	.loc_0x170:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x28(r29)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r29)
	  lfs       f1, 0x28(r29)
	  lfs       f0, -0x7A00(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x20C
	  stfs      f0, 0x28(r29)
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x1C8
	  lfs       f1, 0x30(r29)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x1C8
	  lfs       f0, -0x79DC(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x20C

	.loc_0x1C8:
	  li        r0, 0x3
	  stw       r0, 0x18(r29)
	  b         .loc_0x20C

	.loc_0x1D4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x79FC(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x24(r29)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x24(r29)
	  lfs       f1, 0x24(r29)
	  lfs       f0, -0x7A00(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x20C
	  stfs      f0, 0x24(r29)
	  li        r0, 0
	  stw       r0, 0x18(r29)

	.loc_0x20C:
	  lwz       r0, 0x18(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0xE90
	  lfs       f2, 0x30(r29)
	  lfs       f0, -0x79C8(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x3A0
	  fsubs     f1, f2, f0
	  lbz       r6, 0x2EA8(r13)
	  lfs       f0, -0x79B0(r2)
	  lis       r5, 0x4330
	  lbz       r0, 0x2EA4(r13)
	  fdivs     f0, f1, f0
	  stw       r0, 0x24C(r1)
	  lfs       f1, -0x79DC(r2)
	  addi      r4, r13, 0x2EA8
	  stw       r6, 0x244(r1)
	  stw       r5, 0x248(r1)
	  fsubs     f1, f1, f0
	  lfd       f0, -0x7988(r2)
	  addi      r3, r13, 0x2EA4
	  stw       r5, 0x240(r1)
	  lfd       f3, 0x248(r1)
	  lfd       f2, 0x240(r1)
	  stw       r6, 0x254(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x250(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x250(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x238(r1)
	  lwz       r0, 0x23C(r1)
	  stb       r0, 0x1D0(r1)
	  lbz       r6, 0x1(r4)
	  lbz       r0, 0x1(r3)
	  stw       r6, 0x224(r1)
	  stw       r0, 0x22C(r1)
	  stw       r5, 0x228(r1)
	  stw       r5, 0x220(r1)
	  lfd       f3, 0x228(r1)
	  lfd       f2, 0x220(r1)
	  stw       r6, 0x234(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x230(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x230(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x218(r1)
	  lwz       r0, 0x21C(r1)
	  stb       r0, 0x1D1(r1)
	  lbz       r6, 0x2(r4)
	  lbz       r0, 0x2(r3)
	  stw       r6, 0x204(r1)
	  stw       r0, 0x20C(r1)
	  stw       r5, 0x208(r1)
	  stw       r5, 0x200(r1)
	  lfd       f3, 0x208(r1)
	  lfd       f2, 0x200(r1)
	  stw       r6, 0x214(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x210(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x210(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x1F8(r1)
	  lwz       r0, 0x1FC(r1)
	  stb       r0, 0x1D2(r1)
	  lbz       r4, 0x3(r4)
	  lbz       r0, 0x3(r3)
	  stw       r4, 0x1E4(r1)
	  stw       r0, 0x1EC(r1)
	  stw       r5, 0x1E8(r1)
	  stw       r5, 0x1E0(r1)
	  lfd       f3, 0x1E8(r1)
	  lfd       f2, 0x1E0(r1)
	  stw       r4, 0x1F4(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x1F0(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x1F0(r1)
	  fsubs     f3, f3, f0
	  fmuls     f0, f1, f2
	  fadds     f0, f3, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x1D8(r1)
	  lwz       r0, 0x1DC(r1)
	  stb       r0, 0x1D3(r1)
	  b         .loc_0x6AC

	.loc_0x3A0:
	  lfs       f0, -0x79E4(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x524
	  fsubs     f1, f2, f0
	  lbz       r6, 0x2EA4(r13)
	  lfs       f0, -0x79B0(r2)
	  lis       r5, 0x4330
	  lbz       r0, 0x2EA0(r13)
	  fdivs     f0, f1, f0
	  stw       r0, 0x1E4(r1)
	  lfs       f1, -0x79DC(r2)
	  addi      r4, r13, 0x2EA4
	  stw       r6, 0x1EC(r1)
	  stw       r5, 0x1E0(r1)
	  fsubs     f1, f1, f0
	  lfd       f0, -0x7988(r2)
	  addi      r3, r13, 0x2EA0
	  stw       r5, 0x1E8(r1)
	  lfd       f3, 0x1E0(r1)
	  lfd       f2, 0x1E8(r1)
	  stw       r6, 0x1DC(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x1D8(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x1D8(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x1F0(r1)
	  lwz       r0, 0x1F4(r1)
	  stb       r0, 0x1D0(r1)
	  lbz       r6, 0x1(r4)
	  lbz       r0, 0x1(r3)
	  stw       r6, 0x20C(r1)
	  stw       r0, 0x204(r1)
	  stw       r5, 0x200(r1)
	  stw       r5, 0x208(r1)
	  lfd       f3, 0x200(r1)
	  lfd       f2, 0x208(r1)
	  stw       r6, 0x1FC(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x1F8(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x1F8(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x210(r1)
	  lwz       r0, 0x214(r1)
	  stb       r0, 0x1D1(r1)
	  lbz       r6, 0x2(r4)
	  lbz       r0, 0x2(r3)
	  stw       r6, 0x22C(r1)
	  stw       r0, 0x224(r1)
	  stw       r5, 0x220(r1)
	  stw       r5, 0x228(r1)
	  lfd       f3, 0x220(r1)
	  lfd       f2, 0x228(r1)
	  stw       r6, 0x21C(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x218(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x218(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x230(r1)
	  lwz       r0, 0x234(r1)
	  stb       r0, 0x1D2(r1)
	  lbz       r4, 0x3(r4)
	  lbz       r0, 0x3(r3)
	  stw       r4, 0x24C(r1)
	  stw       r0, 0x244(r1)
	  stw       r5, 0x240(r1)
	  stw       r5, 0x248(r1)
	  lfd       f3, 0x240(r1)
	  lfd       f2, 0x248(r1)
	  stw       r4, 0x23C(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x238(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x238(r1)
	  fsubs     f3, f3, f0
	  fmuls     f0, f1, f2
	  fadds     f0, f3, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x250(r1)
	  lwz       r0, 0x254(r1)
	  stb       r0, 0x1D3(r1)
	  b         .loc_0x6AC

	.loc_0x524:
	  lfs       f1, -0x79B0(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x6A4
	  fsubs     f0, f2, f1
	  lbz       r6, 0x2EA0(r13)
	  lbz       r0, 0x2E9C(r13)
	  lis       r5, 0x4330
	  stw       r6, 0x1EC(r1)
	  fdivs     f0, f0, f1
	  stw       r0, 0x1E4(r1)
	  lfs       f1, -0x79DC(r2)
	  addi      r4, r13, 0x2EA0
	  stw       r5, 0x1E0(r1)
	  stw       r5, 0x1E8(r1)
	  fsubs     f1, f1, f0
	  lfd       f0, -0x7988(r2)
	  addi      r3, r13, 0x2E9C
	  lfd       f3, 0x1E0(r1)
	  lfd       f2, 0x1E8(r1)
	  stw       r6, 0x1DC(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x1D8(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x1D8(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x1F0(r1)
	  lwz       r0, 0x1F4(r1)
	  stb       r0, 0x1D0(r1)
	  lbz       r6, 0x1(r4)
	  lbz       r0, 0x1(r3)
	  stw       r6, 0x20C(r1)
	  stw       r0, 0x204(r1)
	  stw       r5, 0x200(r1)
	  stw       r5, 0x208(r1)
	  lfd       f3, 0x200(r1)
	  lfd       f2, 0x208(r1)
	  stw       r6, 0x1FC(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x1F8(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x1F8(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x210(r1)
	  lwz       r0, 0x214(r1)
	  stb       r0, 0x1D1(r1)
	  lbz       r6, 0x2(r4)
	  lbz       r0, 0x2(r3)
	  stw       r6, 0x22C(r1)
	  stw       r0, 0x224(r1)
	  stw       r5, 0x220(r1)
	  stw       r5, 0x228(r1)
	  lfd       f3, 0x220(r1)
	  lfd       f2, 0x228(r1)
	  stw       r6, 0x21C(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x218(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x218(r1)
	  fsubs     f3, f3, f0
	  fmuls     f2, f1, f2
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x230(r1)
	  lwz       r0, 0x234(r1)
	  stb       r0, 0x1D2(r1)
	  lbz       r4, 0x3(r4)
	  lbz       r0, 0x3(r3)
	  stw       r4, 0x24C(r1)
	  stw       r0, 0x244(r1)
	  stw       r5, 0x240(r1)
	  stw       r5, 0x248(r1)
	  lfd       f3, 0x240(r1)
	  lfd       f2, 0x248(r1)
	  stw       r4, 0x23C(r1)
	  fsubs     f3, f3, f0
	  fsubs     f2, f2, f0
	  stw       r5, 0x238(r1)
	  fsubs     f2, f3, f2
	  lfd       f3, 0x238(r1)
	  fsubs     f3, f3, f0
	  fmuls     f0, f1, f2
	  fadds     f0, f3, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x250(r1)
	  lwz       r0, 0x254(r1)
	  stb       r0, 0x1D3(r1)
	  b         .loc_0x6AC

	.loc_0x6A4:
	  lwz       r0, 0x2E9C(r13)
	  stw       r0, 0x1D0(r1)

	.loc_0x6AC:
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x0(r29)
	  mr        r4, r30
	  lfs       f0, 0xC(r29)
	  addi      r5, r1, 0x1C4
	  lfs       f3, 0x4(r29)
	  lfs       f2, 0x10(r29)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r29)
	  lfs       f1, 0x14(r29)
	  fadds     f2, f3, f2
	  stfs      f0, 0x1C4(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x1C8(r1)
	  stfs      f0, 0x1CC(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0xC(r29)
	  lfs       f3, 0x4(r29)
	  lfs       f2, 0x10(r29)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r29)
	  lfs       f1, 0x14(r29)
	  fadds     f2, f3, f2
	  stfs      f0, 0x1B8(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x1BC(r1)
	  stfs      f0, 0x1C0(r1)
	  lwz       r3, 0x2E4(r30)
	  bl        -0x19790
	  fmr       f25, f1
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r30, 0
	  addi      r5, r1, 0x1B8
	  bl        -0x197A4
	  li        r31, 0xFF
	  fmr       f24, f1
	  stb       r31, 0x140(r1)
	  addi      r4, r1, 0x140
	  addi      r3, r30, 0
	  stb       r31, 0x141(r1)
	  li        r5, 0x1
	  stb       r31, 0x142(r1)
	  stb       r31, 0x143(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x13C(r1)
	  addi      r4, r1, 0x13C
	  addi      r3, r30, 0
	  stb       r31, 0x13D(r1)
	  stb       r31, 0x13E(r1)
	  stb       r31, 0x13F(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lfs       f28, -0x7A00(r2)
	  fcmpo     cr0, f25, f28
	  ble-      .loc_0xE90
	  fcmpo     cr0, f24, f28
	  ble-      .loc_0xE90
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0xB2C
	  addi      r27, r13, 0x2E98
	  lbzu      r3, 0x3(r27)
	  lis       r31, 0x4330
	  lfd       f2, -0x7988(r2)
	  stw       r3, 0x1DC(r1)
	  addi      r28, r13, 0x2E98
	  lfs       f0, 0x24(r29)
	  addi      r26, r13, 0x2E98
	  stw       r31, 0x1D8(r1)
	  lbz       r0, 0x2E98(r13)
	  addi      r4, r1, 0x138
	  lfd       f1, 0x1D8(r1)
	  mr        r3, r30
	  stb       r0, 0x138(r1)
	  fsubs     f1, f1, f2
	  li        r5, 0x1
	  lbzu      r0, 0x1(r28)
	  fmuls     f0, f1, f0
	  stb       r0, 0x139(r1)
	  lbzu      r0, 0x2(r26)
	  fctiwz    f0, f0
	  stb       r0, 0x13A(r1)
	  stfd      f0, 0x1E0(r1)
	  lwz       r0, 0x1E4(r1)
	  stb       r0, 0x13B(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x0(r27)
	  addi      r4, r1, 0x134
	  lfd       f2, -0x7988(r2)
	  mr        r3, r30
	  stw       r0, 0x1EC(r1)
	  lfs       f0, 0x24(r29)
	  stw       r31, 0x1E8(r1)
	  lbz       r0, 0x2E98(r13)
	  lfd       f1, 0x1E8(r1)
	  stb       r0, 0x134(r1)
	  fsubs     f1, f1, f2
	  lbz       r0, 0x0(r28)
	  fmuls     f0, f1, f0
	  stb       r0, 0x135(r1)
	  lbz       r0, 0x0(r26)
	  fctiwz    f0, f0
	  stb       r0, 0x136(r1)
	  stfd      f0, 0x1F0(r1)
	  lwz       r0, 0x1F4(r1)
	  stb       r0, 0x137(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lfs       f4, 0x1B8(r1)
	  addi      r4, r1, 0x124
	  lfs       f1, -0x79AC(r2)
	  mr        r3, r30
	  lfs       f2, -0x79C4(r2)
	  fsubs     f3, f4, f1
	  lfs       f0, -0x79A8(r2)
	  fadds     f1, f1, f4
	  fctiwz    f3, f3
	  fctiwz    f1, f1
	  stfd      f3, 0x1F8(r1)
	  lwz       r0, 0x1FC(r1)
	  stfd      f1, 0x208(r1)
	  stw       r0, 0x124(r1)
	  lwz       r5, 0x20C(r1)
	  lfs       f3, 0x1BC(r1)
	  fsubs     f1, f3, f2
	  fsubs     f0, f3, f0
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x200(r1)
	  lwz       r0, 0x204(r1)
	  stfd      f0, 0x210(r1)
	  stw       r0, 0x128(r1)
	  lwz       r0, 0x214(r1)
	  stw       r5, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xDC(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x1C4(r1)
	  addi      r5, r1, 0x104
	  lfs       f1, 0x1B8(r1)
	  addi      r4, r1, 0x118
	  lfs       f0, -0x79C4(r2)
	  stfs      f2, 0x104(r1)
	  mr        r3, r30
	  fsubs     f0, f1, f0
	  lfs       f3, -0x6FEC(r13)
	  lfs       f2, 0x1C8(r1)
	  lfs       f1, -0x79B4(r2)
	  stfs      f0, 0x114(r1)
	  lfs       f0, -0x6FF0(r13)
	  stfs      f2, 0x108(r1)
	  lfs       f2, 0x114(r1)
	  stfs      f3, 0x10C(r1)
	  stfs      f2, 0x118(r1)
	  lfs       f2, 0x1BC(r1)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x11C(r1)
	  stfs      f0, 0x120(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x1C4(r1)
	  addi      r5, r1, 0xE4
	  lfs       f0, 0x1B8(r1)
	  addi      r4, r1, 0xF8
	  stfs      f1, 0xE4(r1)
	  lfs       f2, -0x79B4(r2)
	  mr        r3, r30
	  lfs       f4, 0x1C8(r1)
	  fsubs     f1, f0, f2
	  lfs       f3, -0x6FE4(r13)
	  stfs      f4, 0xE8(r1)
	  lfs       f0, -0x6FE8(r13)
	  stfs      f1, 0xF4(r1)
	  lfs       f1, 0xF4(r1)
	  stfs      f3, 0xEC(r1)
	  stfs      f1, 0xF8(r1)
	  lfs       f1, 0x1BC(r1)
	  fsubs     f1, f1, f2
	  stfs      f1, 0xFC(r1)
	  stfs      f0, 0x100(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x1D3(r1)
	  addi      r4, r1, 0xE0
	  lfd       f2, -0x7988(r2)
	  mr        r3, r30
	  stw       r0, 0x21C(r1)
	  lfs       f0, 0x24(r29)
	  li        r5, 0x1
	  stw       r31, 0x218(r1)
	  lbz       r0, 0x1D0(r1)
	  lfd       f1, 0x218(r1)
	  stb       r0, 0xE0(r1)
	  fsubs     f1, f1, f2
	  lbz       r0, 0x1D1(r1)
	  fmuls     f0, f1, f0
	  stb       r0, 0xE1(r1)
	  lbz       r0, 0x1D2(r1)
	  fctiwz    f0, f0
	  stb       r0, 0xE2(r1)
	  stfd      f0, 0x220(r1)
	  lwz       r0, 0x224(r1)
	  stb       r0, 0xE3(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x1D3(r1)
	  addi      r4, r1, 0xDC
	  lfd       f2, -0x7988(r2)
	  mr        r3, r30
	  stw       r0, 0x22C(r1)
	  lfs       f0, 0x24(r29)
	  stw       r31, 0x228(r1)
	  lbz       r0, 0x1D0(r1)
	  lfd       f1, 0x228(r1)
	  stb       r0, 0xDC(r1)
	  fsubs     f1, f1, f2
	  lbz       r0, 0x1D1(r1)
	  fmuls     f0, f1, f0
	  stb       r0, 0xDD(r1)
	  lbz       r0, 0x1D2(r1)
	  fctiwz    f0, f0
	  stb       r0, 0xDE(r1)
	  stfd      f0, 0x230(r1)
	  lwz       r0, 0x234(r1)
	  stb       r0, 0xDF(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x1B8(r1)
	  addi      r4, r1, 0xCC
	  lfs       f1, -0x79A4(r2)
	  mr        r3, r30
	  lfs       f0, 0x30(r29)
	  fsubs     f4, f2, f1
	  lfs       f2, -0x79A0(r2)
	  lfs       f1, -0x799C(r2)
	  fmuls     f3, f2, f0
	  lfs       f0, -0x7998(r2)
	  fctiwz    f2, f4
	  fadds     f3, f4, f3
	  stfd      f2, 0x240(r1)
	  fctiwz    f2, f3
	  lwz       r0, 0x244(r1)
	  stw       r0, 0xCC(r1)
	  lfs       f3, 0x1BC(r1)
	  stfd      f2, 0x238(r1)
	  fsubs     f1, f3, f1
	  fsubs     f0, f3, f0
	  lwz       r5, 0x23C(r1)
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x248(r1)
	  lwz       r0, 0x24C(r1)
	  stfd      f0, 0x250(r1)
	  stw       r0, 0xD0(r1)
	  lwz       r0, 0x254(r1)
	  stw       r5, 0xD4(r1)
	  stw       r0, 0xD8(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE90

	.loc_0xB2C:
	  lfs       f0, -0x79DC(r2)
	  addi      r28, r1, 0xC8
	  lfs       f1, 0x34(r29)
	  addi      r27, r1, 0xC4
	  fsubs     f0, f0, f25
	  stfs      f28, 0x184(r1)
	  li        r26, 0
	  lis       r31, 0x4330
	  stfs      f28, 0x180(r1)
	  fmuls     f1, f1, f0
	  stfs      f28, 0x17C(r1)
	  lfs       f0, -0x7994(r2)
	  stfs      f28, 0x190(r1)
	  fneg      f27, f1
	  fmuls     f0, f0, f1
	  lfs       f29, -0x7990(r2)
	  stfs      f28, 0x18C(r1)
	  lfd       f30, -0x79D0(r2)
	  stfs      f28, 0x15C(r1)
	  fneg      f26, f0
	  lfs       f31, -0x798C(r2)
	  stfs      f28, 0x188(r1)
	  stfs      f28, 0x160(r1)
	  stfs      f28, 0x19C(r1)
	  stfs      f28, 0x164(r1)
	  stfs      f28, 0x198(r1)
	  stfs      f28, 0x168(r1)
	  stfs      f28, 0x194(r1)
	  stfs      f28, 0x16C(r1)
	  stfs      f28, 0x1A8(r1)
	  stfs      f28, 0x170(r1)
	  stfs      f28, 0x1A4(r1)
	  stfs      f28, 0x174(r1)
	  stfs      f28, 0x1A0(r1)
	  stfs      f28, 0x178(r1)

	.loc_0xBB8:
	  addi      r3, r26, 0x1
	  lfs       f0, 0x1B8(r1)
	  srawi     r0, r3, 0x5
	  addze     r0, r0
	  stfs      f0, 0x17C(r1)
	  rlwinm    r0,r0,5,0,26
	  subc      r0, r3, r0
	  lfs       f0, 0x1BC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1E4(r1)
	  xoris     r0, r26, 0x8000
	  stw       r31, 0x1E0(r1)
	  stw       r0, 0x1DC(r1)
	  lfd       f1, 0x1E0(r1)
	  stw       r31, 0x1D8(r1)
	  fsubs     f1, f1, f30
	  lfd       f2, 0x1D8(r1)
	  stfs      f0, 0x180(r1)
	  fsubs     f2, f2, f30
	  fmuls     f24, f29, f1
	  lfs       f0, -0x6FE0(r13)
	  fmuls     f25, f29, f2
	  stfs      f0, 0x184(r1)
	  fmr       f1, f24
	  bl        0x1BEE98
	  fmuls     f2, f27, f1
	  lfs       f0, 0x1BC(r1)
	  fmr       f1, f24
	  fadds     f23, f0, f2
	  bl        0x1BF018
	  fmuls     f2, f27, f1
	  lfs       f0, 0x1B8(r1)
	  fmr       f1, f25
	  fadds     f0, f0, f2
	  stfs      f0, 0x188(r1)
	  stfs      f23, 0x18C(r1)
	  lfs       f0, -0x6FDC(r13)
	  stfs      f0, 0x190(r1)
	  bl        0x1BEE60
	  fmuls     f2, f27, f1
	  lfs       f0, 0x1BC(r1)
	  fmr       f1, f25
	  fadds     f23, f0, f2
	  bl        0x1BEFE0
	  fmuls     f1, f27, f1
	  lfs       f0, 0x1B8(r1)
	  fadds     f0, f0, f1
	  stfs      f0, 0x194(r1)
	  stfs      f23, 0x198(r1)
	  lfs       f0, -0x6FD8(r13)
	  stfs      f0, 0x19C(r1)
	  lfs       f0, 0x30(r29)
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0xC98
	  cmpwi     r26, 0
	  beq-      .loc_0xCB0

	.loc_0xC98:
	  fmuls     f0, f31, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x1D8(r1)
	  lwz       r0, 0x1DC(r1)
	  cmpw      r26, r0
	  bge-      .loc_0xCF4

	.loc_0xCB0:
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x1D0
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x17C
	  addi      r6, r1, 0x15C
	  lwz       r12, 0xA0(r12)
	  li        r5, 0
	  li        r7, 0x3
	  mtlr      r12
	  blrl
	  b         .loc_0xD4C

	.loc_0xCF4:
	  li        r6, 0x20
	  stb       r6, 0xC8(r1)
	  li        r0, 0xC0
	  addi      r3, r30, 0
	  stb       r6, 0xC9(r1)
	  addi      r4, r28, 0
	  li        r5, 0x1
	  stb       r6, 0xCA(r1)
	  stb       r0, 0xCB(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x17C
	  addi      r6, r1, 0x15C
	  lwz       r12, 0xA0(r12)
	  li        r5, 0
	  li        r7, 0x3
	  mtlr      r12
	  blrl

	.loc_0xD4C:
	  fmr       f1, f24
	  bl        0x1BED60
	  fmuls     f2, f27, f1
	  lfs       f0, 0x1BC(r1)
	  fmr       f1, f24
	  fadds     f23, f0, f2
	  bl        0x1BEEE0
	  fmuls     f2, f27, f1
	  lfs       f0, 0x1B8(r1)
	  fmr       f1, f24
	  fadds     f0, f0, f2
	  stfs      f0, 0x17C(r1)
	  stfs      f23, 0x180(r1)
	  lfs       f0, -0x6FD4(r13)
	  stfs      f0, 0x184(r1)
	  bl        0x1BED28
	  fmuls     f2, f26, f1
	  lfs       f0, 0x1BC(r1)
	  fmr       f1, f24
	  fadds     f23, f0, f2
	  bl        0x1BEEA8
	  fmuls     f2, f26, f1
	  lfs       f0, 0x1B8(r1)
	  fmr       f1, f25
	  fadds     f0, f0, f2
	  stfs      f0, 0x188(r1)
	  stfs      f23, 0x18C(r1)
	  lfs       f0, -0x6FD0(r13)
	  stfs      f0, 0x190(r1)
	  bl        0x1BECF0
	  fmuls     f2, f26, f1
	  lfs       f0, 0x1BC(r1)
	  fmr       f1, f25
	  fadds     f23, f0, f2
	  bl        0x1BEE70
	  fmuls     f2, f26, f1
	  lfs       f0, 0x1B8(r1)
	  fmr       f1, f25
	  fadds     f0, f0, f2
	  stfs      f0, 0x194(r1)
	  stfs      f23, 0x198(r1)
	  lfs       f0, -0x6FCC(r13)
	  stfs      f0, 0x19C(r1)
	  bl        0x1BECB8
	  fmuls     f2, f27, f1
	  lfs       f0, 0x1BC(r1)
	  fmr       f1, f25
	  fadds     f23, f0, f2
	  bl        0x1BEE38
	  fmuls     f2, f27, f1
	  lfs       f1, 0x1B8(r1)
	  li        r3, 0
	  lfs       f0, -0x6FC8(r13)
	  stb       r3, 0xC4(r1)
	  fadds     f1, f1, f2
	  stb       r3, 0xC5(r1)
	  li        r0, 0xFF
	  stb       r3, 0xC6(r1)
	  mr        r3, r30
	  stfs      f1, 0x1A0(r1)
	  addi      r4, r27, 0
	  li        r5, 0x1
	  stfs      f23, 0x1A4(r1)
	  stfs      f0, 0x1A8(r1)
	  stb       r0, 0xC7(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x17C
	  addi      r6, r1, 0x15C
	  lwz       r12, 0xA0(r12)
	  li        r5, 0
	  li        r7, 0x4
	  mtlr      r12
	  blrl
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x20
	  blt+      .loc_0xBB8

	.loc_0xE90:
	  lmw       r26, 0x258(r1)
	  lwz       r0, 0x2BC(r1)
	  lfd       f31, 0x2B0(r1)
	  lfd       f30, 0x2A8(r1)
	  lfd       f29, 0x2A0(r1)
	  lfd       f28, 0x298(r1)
	  lfd       f27, 0x290(r1)
	  lfd       f26, 0x288(r1)
	  lfd       f25, 0x280(r1)
	  lfd       f24, 0x278(r1)
	  lfd       f23, 0x270(r1)
	  addi      r1, r1, 0x2B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005CF6C
 * Size:	000148
 */
void LifeGauge::countOn(Vector3f&, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r26, 0x30(r1)
	  mr        r30, r3
	  addi      r31, r4, 0
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  lwz       r3, 0x38(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0xEC
	  xoris     r0, r26, 0x8000
	  lfd       f1, -0x79D0(r2)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  li        r3, 0
	  stw       r0, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x30(r30)
	  stw       r3, 0x18(r30)
	  lfs       f0, -0x7A00(r2)
	  stfs      f0, 0x28(r30)
	  lwz       r4, 0x38(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x74
	  li        r0, 0x1
	  stw       r0, 0x24(r4)
	  stw       r3, 0x38(r30)

	.loc_0x74:
	  lwz       r3, 0x2EAC(r13)
	  lwz       r28, 0x58(r3)
	  cmplwi    r28, 0
	  beq-      .loc_0xC0
	  li        r29, 0
	  stw       r29, 0x18(r28)
	  mr        r3, r28
	  lfs       f0, -0x7A00(r2)
	  stfs      f0, 0x34(r28)
	  stfs      f0, 0x3C(r28)
	  stfs      f0, 0x38(r28)
	  stw       r29, 0x24(r28)
	  bl        -0x1CA00
	  stw       r29, 0x10(r28)
	  subi      r0, r13, 0x7000
	  stw       r29, 0xC(r28)
	  stw       r29, 0x8(r28)
	  stw       r0, 0x4(r28)
	  b         .loc_0xC4

	.loc_0xC0:
	  li        r28, 0

	.loc_0xC4:
	  cmplwi    r28, 0
	  addi      r4, r28, 0
	  beq-      .loc_0xF8
	  stw       r30, 0x14(r28)
	  stw       r26, 0x1C(r28)
	  stw       r27, 0x20(r28)
	  lwz       r3, 0x2EAC(r13)
	  bl        -0x1CA74
	  stw       r28, 0x38(r30)
	  b         .loc_0xF8

	.loc_0xEC:
	  stw       r26, 0x1C(r3)
	  lwz       r3, 0x38(r30)
	  stw       r27, 0x20(r3)

	.loc_0xF8:
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  stw       r3, 0x0(r30)
	  stw       r0, 0x4(r30)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x8(r30)
	  lwz       r4, 0x38(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x134
	  lwz       r3, 0x0(r30)
	  lwz       r0, 0x4(r30)
	  stw       r3, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x30(r4)

	.loc_0x134:
	  lmw       r26, 0x30(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D0B4
 * Size:	000030
 */
void LifeGauge::countOff()
{
	/*
	.loc_0x0:
	  li        r0, -0x1
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x7A00(r2)
	  stfs      f0, 0x28(r3)
	  lwz       r4, 0x38(r3)
	  cmplwi    r4, 0
	  beqlr-
	  li        r0, 0x1
	  stw       r0, 0x24(r4)
	  li        r0, 0
	  stw       r0, 0x38(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005D0E4
 * Size:	000004
 */
void __sinit_gauges_cpp(void)
{
}
