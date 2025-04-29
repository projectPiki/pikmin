#include "P2D/Font.h"
#include "Texture.h"
#include "DebugLog.h"
#include "sysNew.h"

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
 * Address:	801B5C64
 * Size:	000150
 */
Font* P2DFont::loadFont(char* name, int& p2, int& p3)
{
	Font* font       = nullptr;
	FntobjInfo* info = (FntobjInfo*)gsys->findGfxObject(name, 'font');
	if (info) {
		font = info->mFont;
	}

	if (!font) {
		font             = new Font();
		FntobjInfo* info = new FntobjInfo();
		info->mString    = StdSystem::stringDup(name);
		info->mId.setID('font');
		info->mFont = font;
		gsys->addGfxObject(info);

		char unused[PATH_MAX];
		sprintf(unused, "%s", name); // why.

		Texture* fontTex = gsys->loadTexture("bigFont.bti", true);
		p2               = 21;
		p3               = 42;
		font->setTexture(fontTex, p2, p3);

	} else {
		p2 = 21;
		p3 = 42;
	}

	return font;
}

/*
 * --INFO--
 * Address:	801B5DB4
 * Size:	0000BC
 */
P2DFont::P2DFont(char* fileName)
{
	int a, b;
	mFont    = loadFont(fileName, a, b);
	_04      = 2;
	mWidth   = (mFont->mTexture->mWidth / a);
	mLeading = 5;
	_0C      = (mFont->mTexture->mHeight / b) * 0.0f;
	_0A      = (mFont->mTexture->mHeight / b) - _0C;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r5, r1, 0x18
	  addi      r6, r1, 0x14
	  bl        -0x16C
	  stw       r3, 0x0(r31)
	  li        r3, 0x2
	  li        r0, 0x5
	  sth       r3, 0x4(r31)
	  lis       r5, 0x4330
	  addi      r3, r31, 0
	  lwz       r6, 0x0(r31)
	  lwz       r4, 0x18(r1)
	  lwz       r6, 0x0(r6)
	  lhz       r6, 0x8(r6)
	  divw      r4, r6, r4
	  sth       r4, 0x6(r31)
	  sth       r0, 0x8(r31)
	  lwz       r6, 0x0(r31)
	  lfs       f0, -0x48F0(r2)
	  lwz       r6, 0x0(r6)
	  fctiwz    f0, f0
	  lwz       r4, 0x14(r1)
	  lhz       r6, 0xA(r6)
	  divw      r4, r6, r4
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  sth       r0, 0xC(r31)
	  xoris     r0, r4, 0x8000
	  lwz       r4, 0x0(r31)
	  stw       r0, 0x2C(r1)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x14(r1)
	  lhz       r4, 0xA(r4)
	  stw       r5, 0x28(r1)
	  divw      r0, r4, r0
	  lhz       r4, 0xC(r31)
	  sub       r0, r0, r4
	  sth       r0, 0xA(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B5E70
 * Size:	0000D8
 */
void P2DFont::setGX()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x5C054
	  li        r3, 0x1
	  bl        0x5DADC
	  li        r3, 0x1
	  bl        0x5A898
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x5D920
	  li        r3, 0
	  li        r4, 0
	  bl        0x5D0EC
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x5DD88
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x59D6C
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x59D54
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0xF
	  bl        0x59D3C
	  bl        0x59CEC
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x594E4
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x594D8
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x594CC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B5F48
 * Size:	000024
 */
void P2DFont::setGradColor(const Colour&, const Colour&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  stw       r0, 0xE(r3)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x12(r3)
	  lwz       r0, 0x0(r5)
	  stw       r0, 0x16(r3)
	  lwz       r0, 0x0(r5)
	  stw       r0, 0x1A(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
int P2DFont::charToIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B5F6C
 * Size:	0000C4
 */
f32 P2DFont::getWidth(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,0,23
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x34
	  lwz       r3, 0x0(r30)
	  rlwinm    r4,r4,0,16,31
	  bl        -0x18DF40
	  b         .loc_0x40

	.loc_0x34:
	  lwz       r3, 0x0(r30)
	  rlwinm    r4,r4,0,24,31
	  bl        -0x18DFF4

	.loc_0x40:
	  lhz       r0, 0x6(r30)
	  xoris     r4, r31, 0x8000
	  lwz       r6, 0x0(r30)
	  lis       r5, 0x4330
	  stw       r4, 0x2C(r1)
	  lfd       f3, -0x48E8(r2)
	  mulli     r3, r3, 0x1C
	  stw       r0, 0x24(r1)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x28(r1)
	  lfd       f1, -0x48D8(r2)
	  add       r3, r0, r3
	  stw       r5, 0x20(r1)
	  lfd       f2, 0x28(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f2, f2, f3
	  lha       r0, 0x8(r3)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x48E0(r2)
	  xoris     r0, r0, 0x8000
	  fdivs     f1, f2, f1
	  stw       r0, 0x34(r1)
	  stw       r5, 0x30(r1)
	  lfd       f2, 0x30(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f2, f1
	  fadds     f1, f0, f2
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
 * Address:	801B6030
 * Size:	000308
 */
f32 P2DFont::drawChar(f32, f32, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,0,23
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  fmr       f29, f1
	  stfd      f28, 0xE0(r1)
	  fmr       f28, f2
	  stmw      r27, 0xCC(r1)
	  addi      r31, r3, 0
	  addi      r28, r5, 0
	  addi      r27, r6, 0
	  beq-      .loc_0x4C
	  lwz       r3, 0x0(r31)
	  rlwinm    r4,r4,0,16,31
	  bl        -0x18E01C
	  b         .loc_0x58

	.loc_0x4C:
	  lwz       r3, 0x0(r31)
	  rlwinm    r4,r4,0,24,31
	  bl        -0x18E0D0

	.loc_0x58:
	  lwz       r8, 0x0(r31)
	  xoris     r6, r28, 0x8000
	  lhz       r5, 0x6(r31)
	  xoris     r4, r27, 0x8000
	  lwz       r0, 0x8(r8)
	  lwz       r10, 0x0(r8)
	  mulli     r7, r3, 0x1C
	  lwz       r9, 0xC(r8)
	  stw       r6, 0xC4(r1)
	  xoris     r6, r0, 0x8000
	  lhz       r3, 0xA(r31)
	  lis       r8, 0x4330
	  stw       r5, 0xBC(r1)
	  add       r7, r9, r7
	  lhz       r0, 0xC(r31)
	  stw       r4, 0xB4(r1)
	  xoris     r5, r3, 0x8000
	  lwz       r3, 0xC(r7)
	  xoris     r4, r0, 0x8000
	  stw       r6, 0xAC(r1)
	  lwz       r0, 0x10(r7)
	  xoris     r3, r3, 0x8000
	  stw       r8, 0xC0(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f0, -0x48E8(r2)
	  stw       r8, 0xB8(r1)
	  lfd       f1, 0xC0(r1)
	  stw       r8, 0xB0(r1)
	  lfd       f4, -0x48D8(r2)
	  fsubs     f6, f1, f0
	  stw       r8, 0xA8(r1)
	  lfd       f3, 0xB8(r1)
	  lfd       f2, 0xB0(r1)
	  lfd       f1, 0xA8(r1)
	  fsubs     f5, f3, f4
	  stw       r3, 0x84(r1)
	  fsubs     f4, f2, f0
	  fsubs     f3, f1, f0
	  stw       r0, 0x74(r1)
	  lha       r6, 0xA(r7)
	  fdivs     f11, f6, f5
	  stw       r8, 0x80(r1)
	  lha       r0, 0x4(r7)
	  xoris     r3, r6, 0x8000
	  stw       r8, 0x70(r1)
	  lfd       f2, 0x80(r1)
	  sub       r0, r0, r6
	  lfd       f1, 0x70(r1)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0xA4(r1)
	  fdivs     f12, f4, f3
	  lfs       f5, -0x48CC(r2)
	  stw       r0, 0x9C(r1)
	  lfs       f6, -0x48D0(r2)
	  stw       r5, 0x94(r1)
	  fsubs     f3, f2, f0
	  stw       r4, 0x8C(r1)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x28(r10)
	  stw       r8, 0xA0(r1)
	  fadds     f4, f5, f3
	  stw       r8, 0x98(r1)
	  fadds     f3, f5, f2
	  lfd       f7, 0xA0(r1)
	  stw       r8, 0x90(r1)
	  stw       r8, 0x88(r1)
	  fmuls     f2, f6, f4
	  lfd       f9, 0x98(r1)
	  fsubs     f10, f7, f0
	  lfd       f8, 0x90(r1)
	  lfd       f7, 0x88(r1)
	  fmuls     f4, f2, f1
	  lfs       f2, 0x2C(r10)
	  fmuls     f3, f6, f3
	  fsubs     f9, f9, f0
	  fsubs     f8, f8, f0
	  fmuls     f3, f3, f2
	  fsubs     f7, f7, f0
	  fctiwz    f4, f4
	  fctiwz    f3, f3
	  fmuls     f10, f10, f11
	  fmuls     f9, f11, f9
	  stfd      f4, 0x78(r1)
	  fmuls     f8, f12, f8
	  fmuls     f4, f12, f7
	  stfd      f3, 0x68(r1)
	  fsubs     f31, f29, f10
	  lwz       r30, 0x7C(r1)
	  fadds     f30, f29, f9
	  fsubs     f29, f28, f8
	  lwz       r29, 0x6C(r1)
	  fadds     f28, f28, f4
	  lwz       r5, 0x14(r7)
	  li        r3, 0
	  lwz       r0, 0x18(r7)
	  li        r4, 0x9
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x64(r1)
	  li        r5, 0x1
	  stw       r0, 0x54(r1)
	  li        r6, 0x4
	  li        r7, 0
	  stw       r8, 0x60(r1)
	  stw       r8, 0x50(r1)
	  lfd       f4, 0x60(r1)
	  lfd       f3, 0x50(r1)
	  fsubs     f4, f4, f0
	  fsubs     f0, f3, f0
	  fadds     f3, f5, f4
	  fadds     f0, f5, f0
	  fmuls     f3, f6, f3
	  fmuls     f0, f6, f0
	  fmuls     f1, f3, f1
	  fmuls     f0, f0, f2
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x58(r1)
	  stfd      f0, 0x48(r1)
	  lwz       r28, 0x5C(r1)
	  lwz       r27, 0x4C(r1)
	  bl        0x599DC
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x5A958
	  lis       r8, 0xCC01
	  lfs       f0, -0x48F0(r2)
	  stfs      f31, -0x8000(r8)
	  li        r3, 0
	  li        r4, 0x9
	  stfs      f29, -0x8000(r8)
	  li        r5, 0x1
	  li        r6, 0x3
	  stfs      f0, -0x8000(r8)
	  li        r7, 0
	  lwz       r0, 0xE(r31)
	  stw       r0, -0x8000(r8)
	  sth       r30, -0x8000(r8)
	  sth       r29, -0x8000(r8)
	  stfs      f30, -0x8000(r8)
	  stfs      f29, -0x8000(r8)
	  stfs      f0, -0x8000(r8)
	  lwz       r0, 0x12(r31)
	  stw       r0, -0x8000(r8)
	  sth       r28, -0x8000(r8)
	  sth       r29, -0x8000(r8)
	  stfs      f30, -0x8000(r8)
	  stfs      f28, -0x8000(r8)
	  stfs      f0, -0x8000(r8)
	  lwz       r0, 0x1A(r31)
	  stw       r0, -0x8000(r8)
	  sth       r28, -0x8000(r8)
	  sth       r27, -0x8000(r8)
	  stfs      f31, -0x8000(r8)
	  stfs      f28, -0x8000(r8)
	  stfs      f0, -0x8000(r8)
	  lwz       r0, 0x16(r31)
	  stw       r0, -0x8000(r8)
	  sth       r30, -0x8000(r8)
	  sth       r27, -0x8000(r8)
	  bl        0x5993C
	  lmw       r27, 0xCC(r1)
	  fsubs     f1, f30, f31
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}
