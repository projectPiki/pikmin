#include "P2D/Window.h"
#include "zen/ogSub.h"
#include "P2D/Stream.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("P2DWindow")

/*
 * --INFO--
 * Address:	801B37F0
 * Size:	000088
 */
void P2DWindow::makeResident()
{
	mTLCornerTexture->makeResident();
	mBLCornerTexture->makeResident();
	mTRCornerTexture->makeResident();
	mBRCornerTexture->makeResident();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
Texture* P2DWindow::loadResource(char* name)
{
	Texture* tex = nullptr;
	if (name) {
		tex = zen::loadTexExp(name, true, true);
		if (!tex) {
			PRINT("can't load texture\n");
		}
	} else {
		PRINT("No texName.\n");
	}
	return tex;
}

/*
 * --INFO--
 * Address:	801B3878
 * Size:	000160
 */
void P2DWindow::loadResource()
{
	mTLCornerTexture = new P2DWindowTexture(loadResource(mTLTexName));
	mTRCornerTexture = new P2DWindowTexture(loadResource(mTRTexName));
	mBLCornerTexture = new P2DWindowTexture(loadResource(mBLTexName));
	mBRCornerTexture = new P2DWindowTexture(loadResource(mBRTexName));

	mMinWidth  = mTLCornerTexture->getWidth() + mTRCornerTexture->getWidth();
	mMinHeight = mTLCornerTexture->getHeight() + mBLCornerTexture->getHeight();
}

/*
 * --INFO--
 * Address:	801B39D8
 * Size:	000258
 */
P2DWindow::P2DWindow(P2DPane* parent, RandomAccessStream* input, u16 paneType)
    : P2DPane(parent, input, paneType)
{
	P2DStream stream(input);
	mWindowBounds.mMinX = (int)input->readShort();
	mWindowBounds.mMinY = (int)input->readShort();
	mWindowBounds.mMaxX = mWindowBounds.mMinX + (int)input->readShort();
	mWindowBounds.mMaxY = mWindowBounds.mMinY + (int)input->readShort();

	mTLTexName = stream.getResource('TIMG');
	mTRTexName = stream.getResource('TIMG');
	mBLTexName = stream.getResource('TIMG');
	mBRTexName = stream.getResource('TIMG');
	stream.getResource('TLUT');
	mWindowFlag = input->readByte();
	stream.getColour(&mTLCornerColour);
	stream.getColour(&mTRCornerColour);
	stream.getColour(&mBLCornerColour);
	stream.getColour(&mBRCornerColour);

	stream.align(4);
}

/*
 * --INFO--
 * Address:	801B3C30
 * Size:	000068
 */
void P2DWindow::drawSelf(int x, int y)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	drawSelf(x, y, &mtx);
}

/*
 * --INFO--
 * Address:	801B3C98
 * Size:	000098
 */
void P2DWindow::drawSelf(int x, int y, Matrix4f* mtx)
{
	PUTRect bounds(mGlobalBounds.mMinX, mGlobalBounds.mMinY, mGlobalBounds.mMaxX, mGlobalBounds.mMaxY);
	bounds.add(x, y);
	draw_private(bounds, mWindowBounds, mtx);
	clip(mWindowBounds);
}

/*
 * --INFO--
 * Address:	801B3D30
 * Size:	000394
 */
void P2DWindow::draw_private(const PUTRect& bounds, const PUTRect& windowBounds, Matrix4f* transform)
{
	if (bounds.getWidth() >= mMinWidth && bounds.getHeight() >= mMinHeight) {
		Matrix4f mtx1;
		transform->multiplyTo(mWorldMtx, mtx1);
		GXLoadPosMtxImm(mtx1.mMtx, 0);
		drawContents(windowBounds);

		int x = bounds.getWidth() - mBRCornerTexture->getWidth();
		int y = bounds.getHeight() - mBRCornerTexture->getHeight();

		GXClearVtxDesc();
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
		GXSetNumTexGens(1);

		mTLCornerTexture->draw(0, 0, mWindowFlag & 0x80, mWindowFlag & 0x40);
		mTRCornerTexture->draw(x, 0, mWindowFlag & 0x20, mWindowFlag & 0x10);
		mBLCornerTexture->draw(0, y, mWindowFlag & 0x8, mWindowFlag & 0x4);
		mBRCornerTexture->draw(x, y, mWindowFlag & 0x2, mWindowFlag & 0x1);

		int height, width;
		width  = mTLCornerTexture->getWidth();
		height = mTLCornerTexture->getHeight();

		u16 flag4, flag3, flag2, flag1;
		flag2 = flag4 = (mWindowFlag & 0x20) ? (u16)0x8000 : (u16)0;
		flag1         = (mWindowFlag & 0x10) ? (u16)0 : (u16)0x8000;
		flag3         = flag1 ^ 0x8000;
		mTRCornerTexture->draw(width, 0, x - width, mTRCornerTexture->getHeight(), flag2, flag1, flag4, flag3);

		flag4 = flag2 = (mWindowFlag & 0x2) ? (u16)0x8000 : (u16)0;
		flag1         = (mWindowFlag & 0x1) ? (u16)0 : (u16)0x8000;
		flag3         = flag1 ^ 0x8000;
		mBRCornerTexture->draw(width, y, x - width, mBRCornerTexture->getHeight(), flag2, flag1, flag4, flag3);

		flag1 = (mWindowFlag & 0x8) ? (u16)0 : (u16)0x8000;
		flag3 = flag1 ^ 0x8000;
		flag2 = (mWindowFlag & 0x4) ? (u16)0x8000 : (u16)0;
		flag4 = flag2;
		int d = y - height;
		mBLCornerTexture->draw(0, height, mBLCornerTexture->getWidth(), d, flag1, flag2, flag3, flag4);

		flag1 = (mWindowFlag & 0x2) ? (u16)0 : (u16)0x8000;
		flag3 = flag1 ^ 0x8000;
		flag2 = (mWindowFlag & 0x1) ? (u16)0x8000 : (u16)0;
		flag4 = flag2;
		d     = y - height;
		mBRCornerTexture->draw(x, height, mBRCornerTexture->getWidth(), d, flag1, flag2, flag3, flag4);

		GXSetNumTexGens(0);
		GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stmw      r26, 0xA8(r1)
	  addi      r27, r4, 0
	  addi      r31, r3, 0
	  mr        r26, r5
	  lha       r4, 0x0(r4)
	  lha       r3, 0x4(r27)
	  lha       r0, 0x128(r31)
	  sub       r3, r3, r4
	  cmpw      r3, r0
	  blt-      .loc_0x380
	  lha       r4, 0x2(r27)
	  lha       r3, 0x6(r27)
	  lha       r0, 0x12A(r31)
	  sub       r3, r3, r4
	  cmpw      r3, r0
	  blt-      .loc_0x380
	  addi      r3, r6, 0
	  addi      r4, r31, 0x78
	  addi      r5, r1, 0x68
	  bl        -0x175CB4
	  addi      r3, r1, 0x68
	  li        r4, 0
	  bl        0x606C0
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        .loc_0x394
	  lwz       r3, 0x110(r31)
	  lha       r5, 0x0(r27)
	  lwz       r7, 0x0(r3)
	  lha       r4, 0x4(r27)
	  lha       r3, 0x2(r27)
	  lha       r0, 0x6(r27)
	  sub       r5, r4, r5
	  lhz       r6, 0x8(r7)
	  lhz       r4, 0xA(r7)
	  sub       r0, r0, r3
	  sub       r29, r5, r6
	  sub       r30, r0, r4
	  bl        0x5BE28
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x5B620
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x5B614
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x5B608
	  li        r3, 0x1
	  bl        0x5C928
	  lwz       r8, 0x114(r31)
	  li        r4, 0
	  lwz       r3, 0x104(r31)
	  li        r5, 0
	  rlwinm    r0,r8,0,24,24
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,25,25
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x514
	  lwz       r8, 0x114(r31)
	  mr        r4, r29
	  lwz       r3, 0x108(r31)
	  li        r5, 0
	  rlwinm    r0,r8,0,26,26
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,27,27
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x4D8
	  lwz       r8, 0x114(r31)
	  mr        r5, r30
	  lwz       r3, 0x10C(r31)
	  li        r4, 0
	  rlwinm    r0,r8,0,28,28
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,29,29
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x49C
	  lwz       r8, 0x114(r31)
	  mr        r4, r29
	  lwz       r3, 0x110(r31)
	  addi      r5, r30, 0
	  rlwinm    r0,r8,0,30,30
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,31,31
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x460
	  lwz       r3, 0x104(r31)
	  lwz       r5, 0x114(r31)
	  lwz       r4, 0x0(r3)
	  rlwinm.   r0,r5,0,26,26
	  lhz       r26, 0x8(r4)
	  lhz       r28, 0xA(r4)
	  beq-      .loc_0x1EC
	  lis       r3, 0x1
	  subi      r3, r3, 0x8000
	  b         .loc_0x1F0

	.loc_0x1EC:
	  li        r3, 0

	.loc_0x1F0:
	  rlwinm.   r0,r5,0,27,27
	  addi      r10, r3, 0
	  addi      r8, r10, 0
	  beq-      .loc_0x208
	  li        r0, 0
	  b         .loc_0x210

	.loc_0x208:
	  lis       r3, 0x1
	  subi      r0, r3, 0x8000

	.loc_0x210:
	  lwz       r3, 0x108(r31)
	  mr        r9, r0
	  sub       r27, r29, r26
	  lwz       r4, 0x0(r3)
	  xori      r0, r0, 0x8000
	  addi      r6, r27, 0
	  lhz       r7, 0xA(r4)
	  addi      r4, r26, 0
	  li        r5, 0
	  stw       r0, 0x8(r1)
	  bl        0x2E8
	  lwz       r4, 0x114(r31)
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x254
	  lis       r3, 0x1
	  subi      r10, r3, 0x8000
	  b         .loc_0x258

	.loc_0x254:
	  li        r10, 0

	.loc_0x258:
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x268
	  li        r9, 0
	  b         .loc_0x270

	.loc_0x268:
	  lis       r3, 0x1
	  subi      r9, r3, 0x8000

	.loc_0x270:
	  lwz       r3, 0x110(r31)
	  xori      r0, r9, 0x8000
	  mr        r4, r26
	  lwz       r5, 0x0(r3)
	  addi      r6, r27, 0
	  mr        r8, r10
	  lhz       r7, 0xA(r5)
	  addi      r5, r30, 0
	  stw       r0, 0x8(r1)
	  bl        0x28C
	  lwz       r4, 0x114(r31)
	  rlwinm.   r0,r4,0,28,28
	  beq-      .loc_0x2AC
	  li        r8, 0
	  b         .loc_0x2B4

	.loc_0x2AC:
	  lis       r3, 0x1
	  subi      r8, r3, 0x8000

	.loc_0x2B4:
	  rlwinm.   r0,r4,0,29,29
	  xori      r10, r8, 0x8000
	  beq-      .loc_0x2CC
	  lis       r3, 0x1
	  subi      r9, r3, 0x8000
	  b         .loc_0x2D0

	.loc_0x2CC:
	  li        r9, 0

	.loc_0x2D0:
	  lwz       r3, 0x10C(r31)
	  sub       r30, r30, r28
	  addi      r5, r28, 0
	  lwz       r4, 0x0(r3)
	  addi      r7, r30, 0
	  lhz       r6, 0x8(r4)
	  li        r4, 0
	  stw       r9, 0x8(r1)
	  bl        0x230
	  lwz       r4, 0x114(r31)
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x308
	  li        r8, 0
	  b         .loc_0x310

	.loc_0x308:
	  lis       r3, 0x1
	  subi      r8, r3, 0x8000

	.loc_0x310:
	  rlwinm.   r0,r4,0,31,31
	  xori      r10, r8, 0x8000
	  beq-      .loc_0x328
	  lis       r3, 0x1
	  subi      r9, r3, 0x8000
	  b         .loc_0x32C

	.loc_0x328:
	  li        r9, 0

	.loc_0x32C:
	  lwz       r3, 0x110(r31)
	  mr        r4, r29
	  addi      r7, r30, 0
	  lwz       r5, 0x0(r3)
	  lhz       r6, 0x8(r5)
	  addi      r5, r28, 0
	  stw       r9, 0x8(r1)
	  bl        0x1D8
	  li        r3, 0
	  bl        0x5C6A8
	  li        r3, 0
	  li        r4, 0x4
	  bl        0x5EF10
	  li        r3, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x5F724
	  li        r3, 0xD
	  li        r4, 0
	  bl        0x5B354

	.loc_0x380:
	  lmw       r26, 0xA8(r1)
	  lwz       r0, 0xC4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x394:
	*/
}

/*
 * --INFO--
 * Address:	801B40C4
 * Size:	00018C
 */
void P2DWindow::drawContents(const PUTRect& windowBounds)
{
	if (!windowBounds.isEmpty()) {
		GXClearVtxDesc();
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetNumChans(1);
		GXSetNumTexGens(0);
		GXSetNumTevStages(1);
		GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
		GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);

		if (mTLCornerColour.a == 255 && mTRCornerColour.a == 255 && mBLCornerColour.a == 255 && mBRCornerColour.a == 255) {
			GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_SET);
		} else {
			GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
		}

		GXBegin(GX_QUADS, GX_VTXFMT0, 4);

		// top left
		GXPosition3s16(windowBounds.mMinX, windowBounds.mMinY, 0);
		GXColor1u32(*(u32*)&mTLCornerColour);

		// top right
		GXPosition3s16(windowBounds.mMaxX, windowBounds.mMinY, 0);
		GXColor1u32(*(u32*)&mTRCornerColour);

		// bottom right
		GXPosition3s16(windowBounds.mMaxX, windowBounds.mMaxY, 0);
		GXColor1u32(*(u32*)&mBRCornerColour);

		// bottom left
		GXPosition3s16(windowBounds.mMinX, windowBounds.mMaxY, 0);
		GXColor1u32(*(u32*)&mBLCornerColour);
	}
}

/*
 * --INFO--
 * Address:	801B4250
 * Size:	000100
 */
void P2DWindow::P2DWindowTexture::draw(int x, int y, int width, int height, u16 u0, u16 v0, u16 u1, u16 v1)
{
	int x1 = x + width;
	int y1 = y + height;

	mTexture->makeResident();
	GXLoadTexObj(mTexture->mTexObj, GX_TEXMAP0);
	setTevMode();

	GXBegin(GX_QUADS, GX_VTXFMT0, 4);

	GXPosition3s16(x, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u1, v1);

	GXPosition3s16(x1, y, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u0, v1);

	GXPosition3s16(x1, y1, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u0, v0);

	GXPosition3s16(x, y1, 0);
	GXColor1u32(0xFFFFFFFF);
	GXTexCoord2s16(u1, v0);
}

/*
 * --INFO--
 * Address:	801B4350
 * Size:	0000A0
 */
void P2DWindow::P2DWindowTexture::draw(int x, int y, bool p3, bool p4)
{
	draw(x, y, mTexture->mWidth, mTexture->mHeight, u16(p3 ? 0 : 0x8000), u16(p4 ? 0 : 0x8000), u16(p3 ? 0x8000 : 0), u16(p4 ? 0x8000 : 0));
}

/*
 * --INFO--
 * Address:	801B43F0
 * Size:	000058
 */
void P2DWindow::P2DWindowTexture::setTevMode()
{
	GXSetNumTevStages(1);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
	GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
}
