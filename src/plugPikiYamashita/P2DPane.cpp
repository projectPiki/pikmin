#include "P2D/Pane.h"
#include "PSU/LinkList.h"
#include "PSU/Tree.h"
#include "DebugLog.h"
#include "Dolphin/gx.h"

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
DEFINE_PRINT("P2DPane");

/*
 * --INFO--
 * Address:	801B069C
 * Size:	000008
 */
void P2DPane::setCallBack(P2DPaneCallBack* callback) { mCallBack = callback; }

/*
 * --INFO--
 * Address:	801B06A4
 * Size:	000014
 */
void P2DPane::printTagName(bool doPrint)
{
	if (doPrint) {
		if (mTagName) {
			PRINT("tag[%c%c%c%c] \n", ((u8*)&mTagName)[0], ((u8*)&mTagName)[1], ((u8*)&mTagName)[2], ((u8*)&mTagName)[3]);
		} else {
			PRINT("tag[]\n");
		}
	}
}

/*
 * --INFO--
 * Address:	801B06B8
 * Size:	000048
 */
void P2DPane::drawSelf(int, int, Matrix4f* drawMtx)
{
	if (mCallBack) {
		Matrix4f posMtx;
		drawMtx->multiplyTo(_78, posMtx);
		GXLoadPosMtxImm(posMtx.mMtx, 0);
	}
}

/*
 * --INFO--
 * Address:	801B0700
 * Size:	000030
 */
P2DPaneCallBackBase::P2DPaneCallBackBase(P2DPane* pane, P2DPaneType type) { checkPaneType(pane, type); }

/*
 * --INFO--
 * Address:	801B0730
 * Size:	000014
 */
void P2DPaneCallBackBase::checkPaneType(P2DPane* pane, P2DPaneType type)
{
	if (pane && pane->getPaneType() != type) {
		PRINT("This pane type is [%d]. not [%d] \n", pane->getPaneType(), type);
		ERROR("Can't set Call Back class.");
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void P2DPane::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B0744
 * Size:	000134
 */
void P2DPane::update()
{
	if (mCallBack) {
		mCallBack->invoke(this);
	}

	PSUTree<P2DPane>* tree = getPaneTree();
	PSUTreeIterator<P2DPane> iterator(tree->getFirstChild());
	while (iterator != nullptr) {
		iterator->update();
		iterator++;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  stw       r30, 0x90(r1)
	  stw       r29, 0x8C(r1)
	  mr        r29, r3
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
	  lwz       r29, 0xD0(r29)
	  cmplwi    r29, 0
	  beq-      .loc_0x110
	  subi      r29, r29, 0xC
	  b         .loc_0x110

	.loc_0x50:
	  lwz       r31, 0xC(r29)
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r30, 0xD0(r31)
	  cmplwi    r30, 0
	  beq-      .loc_0xF8
	  subi      r30, r30, 0xC
	  b         .loc_0xF8

	.loc_0x88:
	  lwz       r31, 0xC(r30)
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xAC:
	  addi      r3, r31, 0xD0
	  bl        .loc_0x134
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  subi      r3, r3, 0xC

	.loc_0xC0:
	  mr        r31, r3
	  b         .loc_0xE0

	.loc_0xC8:
	  lwz       r3, 0xC(r31)
	  bl        .loc_0x0
	  lwz       r31, 0x18(r31)
	  cmplwi    r31, 0
	  beq-      .loc_0xE0
	  subi      r31, r31, 0xC

	.loc_0xE0:
	  cmplwi    r31, 0
	  bne+      .loc_0xC8
	  lwz       r30, 0x18(r30)
	  cmplwi    r30, 0
	  beq-      .loc_0xF8
	  subi      r30, r30, 0xC

	.loc_0xF8:
	  cmplwi    r30, 0
	  bne+      .loc_0x88
	  lwz       r29, 0x18(r29)
	  cmplwi    r29, 0
	  beq-      .loc_0x110
	  subi      r29, r29, 0xC

	.loc_0x110:
	  cmplwi    r29, 0
	  bne+      .loc_0x50
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr

	.loc_0x134:
	*/
}

/*
 * --INFO--
 * Address:	801B0880
 * Size:	00014C
 */
P2DPane::P2DPane()
    : mPaneTree(this)
{
	mPaneType = PANETYPE_Unk16;

	setFlag(1, 7, 1);
	mTagName = 0;
	_18.set(0, 0, 0, 0);
	_B8 = 0;
	_BA = 0;
	setFlag(0, 5, 2);
	_BC = 0.0f;
	_C0.set(1.0f, 1.0f, 1.0f);
	mCullMode = GX_CULL_NONE;
	mCallBack = nullptr;
	mPaneZ    = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
PSUTree<P2DPane>::~PSUTree()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
PSULink<P2DPane>::~PSULink()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
PSUList<P2DPane>::~PSUList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B09CC
 * Size:	000168
 */
P2DPane::P2DPane(P2DPane* parent, u16 paneType, bool, u32 tag, const PUTRect& p5)
    : mPaneTree(this)
{
	mPaneType = paneType;
	setFlag(1, 7, 1);
	mTagName = tag;
	_18      = p5;
	if (parent) {
		parent->mPaneTree.append(getPaneTree());
	}

	_B8 = 0;
	_BA = 0;
	setFlag(0, 5, 2);
	_BC = 0.0f;
	_C0.set(1.0f, 1.0f, 1.0f);
	mCullMode = GX_CULL_NONE;
	mCallBack = nullptr;
	mPaneZ    = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
 */
P2DPane::P2DPane(u32, const PUTRect&)
    : mPaneTree(this)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
P2DPane::P2DPane(u16, u32, const PUTRect&)
    : mPaneTree(this)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B0B34
 * Size:	000290
 */
P2DPane::P2DPane(P2DPane* parent, RandomAccessStream* input, u16 paneType)
    : mPaneTree(this)
{
	mPaneType = paneType;
	if (input->checkInput()) {
		setFlag(1, 7, 1);
	} else {
		setFlag(0, 7, 1);
	}

	u8 tag[4];
	input->readByte();
	tag[0] = input->readByte();
	tag[1] = input->readByte();
	tag[2] = input->readByte();
	tag[3] = input->readByte();

	mTagName = *(u32*)tag;

	_18.mMin.x = (int)input->readShort();
	_18.mMin.y = (int)input->readShort();
	_18.mMax.x = _18.mMin.x + (int)input->readShort();
	_18.mMax.y = _18.mMin.y + (int)input->readShort();

	if (parent) {
		parent->mPaneTree.append(getPaneTree());
	}

	_B8 = 0;
	_BA = 0;
	setFlag(0, 5, 2);
	_BC = 0.0f;
	_C0.set(1.0f, 1.0f, 1.0f);
	mCullMode = GX_CULL_NONE;
	mCallBack = nullptr;
	mPaneZ    = 0.0f;
}

/*
 * --INFO--
 * Address:	801B0DC4
 * Size:	0000E0
 */
P2DPane::~P2DPane()
{
	PSUTree<P2DPane>* tree = getPaneTree();
	PSUTreeIterator<P2DPane> iterator(tree->getFirstChild());
	while (iterator != nullptr) {
		delete (iterator++).getObject();
	}
}

/*
 * --INFO--
 * Address:	801B0EA4
 * Size:	0004A4
 */
void P2DPane::draw(int, int, const P2DGrafContext*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r8, 0x802E
	  stw       r0, 0x4(r1)
	  addi      r0, r8, 0x5D4
	  stwu      r1, -0x140(r1)
	  stmw      r25, 0x124(r1)
	  addi      r26, r3, 0
	  addi      r29, r6, 0
	  addi      r27, r4, 0
	  addi      r28, r5, 0
	  addi      r30, r7, 0
	  addi      r3, r1, 0x54
	  addi      r4, r29, 0x8
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x4(r6)
	  stw       r0, 0x50(r1)
	  bl        0x2768
	  addi      r3, r1, 0x5C
	  addi      r4, r29, 0x10
	  bl        0x275C
	  lbz       r0, 0x18(r29)
	  addi      r31, r1, 0xBC
	  stb       r0, 0x64(r1)
	  lbz       r0, 0x19(r29)
	  stb       r0, 0x65(r1)
	  lbz       r0, 0x1A(r29)
	  stb       r0, 0x66(r1)
	  lbz       r0, 0x1B(r29)
	  stb       r0, 0x67(r1)
	  lbz       r0, 0x1C(r29)
	  stb       r0, 0x68(r1)
	  lbz       r0, 0x1D(r29)
	  stb       r0, 0x69(r1)
	  lbz       r0, 0x1E(r29)
	  stb       r0, 0x6A(r1)
	  lbz       r0, 0x1F(r29)
	  stb       r0, 0x6B(r1)
	  lbz       r0, 0x20(r29)
	  stb       r0, 0x6C(r1)
	  lbz       r0, 0x21(r29)
	  stb       r0, 0x6D(r1)
	  lbz       r0, 0x22(r29)
	  stb       r0, 0x6E(r1)
	  lbz       r0, 0x23(r29)
	  stb       r0, 0x6F(r1)
	  lbz       r0, 0x24(r29)
	  stb       r0, 0x70(r1)
	  lbz       r0, 0x25(r29)
	  stb       r0, 0x71(r1)
	  lbz       r0, 0x26(r29)
	  stb       r0, 0x72(r1)
	  lbz       r0, 0x27(r29)
	  stb       r0, 0x73(r1)
	  lbz       r0, 0x28(r29)
	  stb       r0, 0x74(r1)
	  lha       r0, 0x2A(r29)
	  sth       r0, 0x76(r1)
	  lha       r0, 0x2C(r29)
	  sth       r0, 0x78(r1)
	  lwz       r3, 0x30(r29)
	  lwz       r0, 0x34(r29)
	  stw       r3, 0x7C(r1)
	  stw       r0, 0x80(r1)
	  lwz       r3, 0x38(r29)
	  lwz       r0, 0x3C(r29)
	  stw       r3, 0x84(r1)
	  stw       r0, 0x88(r1)
	  lwz       r3, 0x40(r29)
	  lwz       r0, 0x44(r29)
	  stw       r3, 0x8C(r1)
	  stw       r0, 0x90(r1)
	  lwz       r3, 0x48(r29)
	  lwz       r0, 0x4C(r29)
	  stw       r3, 0x94(r1)
	  stw       r0, 0x98(r1)
	  lwz       r3, 0x50(r29)
	  lwz       r0, 0x54(r29)
	  stw       r3, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r3, 0x58(r29)
	  lwz       r0, 0x5C(r29)
	  stw       r3, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r3, 0x60(r29)
	  lwz       r0, 0x64(r29)
	  stw       r3, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r3, 0x68(r29)
	  lwz       r0, 0x6C(r29)
	  stw       r3, 0xB4(r1)
	  stw       r0, 0xB8(r1)
	  lwz       r3, 0x70(r29)
	  lwz       r0, 0x74(r29)
	  stw       r3, 0xBC(r1)
	  stw       r0, 0xC0(r1)
	  lwz       r3, 0x78(r29)
	  lwz       r0, 0x7C(r29)
	  stw       r3, 0xC4(r1)
	  stw       r0, 0xC8(r1)
	  lwz       r3, 0x80(r29)
	  lwz       r0, 0x84(r29)
	  stw       r3, 0xCC(r1)
	  stw       r0, 0xD0(r1)
	  lwz       r3, 0x88(r29)
	  lwz       r0, 0x8C(r29)
	  stw       r3, 0xD4(r1)
	  stw       r0, 0xD8(r1)
	  lwz       r3, 0x90(r29)
	  lwz       r0, 0x94(r29)
	  stw       r3, 0xDC(r1)
	  stw       r0, 0xE0(r1)
	  lwz       r3, 0x98(r29)
	  lwz       r0, 0x9C(r29)
	  stw       r3, 0xE4(r1)
	  stw       r0, 0xE8(r1)
	  lwz       r3, 0xA0(r29)
	  lwz       r0, 0xA4(r29)
	  stw       r3, 0xEC(r1)
	  stw       r0, 0xF0(r1)
	  lwz       r3, 0xA8(r29)
	  lwz       r0, 0xAC(r29)
	  stw       r3, 0xF4(r1)
	  stw       r0, 0xF8(r1)
	  lwz       r3, 0xB0(r29)
	  lwz       r0, 0xB4(r29)
	  stw       r3, 0xFC(r1)
	  stw       r0, 0x100(r1)
	  lwz       r0, 0xB8(r29)
	  stw       r0, 0x104(r1)
	  lwz       r3, 0xBC(r29)
	  lwz       r0, 0xC0(r29)
	  stw       r3, 0x108(r1)
	  stw       r0, 0x10C(r1)
	  lwz       r0, 0xC4(r29)
	  stw       r0, 0x110(r1)
	  lwz       r3, 0xC8(r29)
	  lwz       r0, 0xCC(r29)
	  stw       r3, 0x114(r1)
	  stw       r0, 0x118(r1)
	  lwz       r0, 0xD0(r29)
	  stw       r0, 0x11C(r1)
	  lwz       r0, 0x50(r1)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x244
	  li        r30, 0

	.loc_0x244:
	  lwz       r3, 0xE0(r26)
	  li        r25, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x258
	  lwz       r25, 0xC(r3)

	.loc_0x258:
	  lbz       r0, 0xC(r26)
	  rlwinm.   r0,r0,25,31,31
	  beq-      .loc_0x484
	  addi      r3, r26, 0x18
	  bl        0x26B4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x484
	  lwz       r4, 0x18(r26)
	  mr        r3, r26
	  lwz       r0, 0x1C(r26)
	  stw       r4, 0x20(r26)
	  stw       r0, 0x24(r26)
	  lwz       r4, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r4, 0x28(r26)
	  stw       r0, 0x2C(r26)
	  lwz       r12, 0x0(r26)
	  lha       r4, 0x18(r26)
	  lwz       r12, 0x38(r12)
	  lha       r0, 0x1A(r26)
	  add       r4, r4, r27
	  mtlr      r12
	  add       r5, r0, r28
	  blrl
	  cmplwi    r25, 0
	  beq-      .loc_0x300
	  lha       r4, 0x20(r25)
	  addi      r3, r26, 0x20
	  lha       r5, 0x22(r25)
	  bl        0x2500
	  addi      r3, r25, 0x78
	  addi      r4, r26, 0x38
	  addi      r5, r26, 0x78
	  bl        -0x1730AC
	  lha       r4, 0x20(r25)
	  addi      r3, r26, 0x28
	  lha       r5, 0x22(r25)
	  bl        0x24E0
	  addi      r3, r26, 0x28
	  addi      r4, r25, 0x28
	  bl        0x2508
	  b         .loc_0x3A0

	.loc_0x300:
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  addi      r3, r26, 0x20
	  bl        0x24C0
	  lwz       r6, 0x38(r26)
	  mr        r4, r27
	  lwz       r0, 0x3C(r26)
	  addi      r5, r28, 0
	  addi      r3, r26, 0x28
	  stw       r6, 0x78(r26)
	  stw       r0, 0x7C(r26)
	  lwz       r6, 0x40(r26)
	  lwz       r0, 0x44(r26)
	  stw       r6, 0x80(r26)
	  stw       r0, 0x84(r26)
	  lwz       r6, 0x48(r26)
	  lwz       r0, 0x4C(r26)
	  stw       r6, 0x88(r26)
	  stw       r0, 0x8C(r26)
	  lwz       r6, 0x50(r26)
	  lwz       r0, 0x54(r26)
	  stw       r6, 0x90(r26)
	  stw       r0, 0x94(r26)
	  lwz       r6, 0x58(r26)
	  lwz       r0, 0x5C(r26)
	  stw       r6, 0x98(r26)
	  stw       r0, 0x9C(r26)
	  lwz       r6, 0x60(r26)
	  lwz       r0, 0x64(r26)
	  stw       r6, 0xA0(r26)
	  stw       r0, 0xA4(r26)
	  lwz       r6, 0x68(r26)
	  lwz       r0, 0x6C(r26)
	  stw       r6, 0xA8(r26)
	  stw       r0, 0xAC(r26)
	  lwz       r6, 0x70(r26)
	  lwz       r0, 0x74(r26)
	  stw       r6, 0xB0(r26)
	  stw       r0, 0xB4(r26)
	  bl        0x2430

	.loc_0x3A0:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x3B8
	  addi      r3, r29, 0
	  addi      r4, r26, 0x30
	  addi      r5, r26, 0x28
	  bl        -0x1390

	.loc_0x3B8:
	  addi      r3, r26, 0x28
	  bl        0x2560
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3D0
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x484

	.loc_0x3D0:
	  addi      r3, r1, 0x4C
	  addi      r4, r26, 0x20
	  bl        -0x1728
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x3F8
	  addi      r3, r1, 0x4C
	  addi      r4, r26, 0x30
	  bl        -0x1750
	  addi      r3, r1, 0x4C
	  bl        -0x17F8

	.loc_0x3F8:
	  lwz       r3, 0xCC(r26)
	  bl        0x5FBA8
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  lwz       r12, 0x30(r12)
	  addi      r6, r31, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x440
	  lwz       r12, 0x0(r3)
	  mr        r4, r26
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x440:
	  lwz       r26, 0xD0(r26)
	  cmplwi    r26, 0
	  beq-      .loc_0x47C
	  subi      r26, r26, 0xC
	  b         .loc_0x47C

	.loc_0x454:
	  lwz       r3, 0xC(r26)
	  addi      r6, r29, 0
	  addi      r7, r30, 0
	  li        r4, 0
	  li        r5, 0
	  bl        .loc_0x0
	  lwz       r26, 0x18(r26)
	  cmplwi    r26, 0
	  beq-      .loc_0x47C
	  subi      r26, r26, 0xC

	.loc_0x47C:
	  cmplwi    r26, 0
	  bne+      .loc_0x454

	.loc_0x484:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x144(r1)
	  lmw       r25, 0x124(r1)
	  addi      r1, r1, 0x140
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B1348
 * Size:	00004C
 */
bool P2DPane::clip(const PUTRect& rect)
{
	PUTRect newRect = rect;
	newRect.add(_20.mMin.x, _20.mMin.y);
	return _28.intersect(newRect);
}

/*
 * --INFO--
 * Address:	801B1394
 * Size:	0000A4
 */
P2DPane* P2DPane::search(u32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r5
	  stw       r4, 0xC(r1)
	  lwz       r4, 0xC(r1)
	  lwz       r0, 0x10(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x30
	  b         .loc_0x8C

	.loc_0x30:
	  lwz       r31, 0xD0(r3)
	  cmplwi    r31, 0
	  beq-      .loc_0x7C
	  subi      r31, r31, 0xC
	  b         .loc_0x7C

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  li        r5, 0
	  lwz       r4, 0xC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  b         .loc_0x8C

	.loc_0x6C:
	  lwz       r31, 0x18(r31)
	  cmplwi    r31, 0
	  beq-      .loc_0x7C
	  subi      r31, r31, 0xC

	.loc_0x7C:
	  cmplwi    r31, 0
	  bne+      .loc_0x44
	  rlwinm.   r0,r30,0,24,31
	  li        r3, 0

	.loc_0x8C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B1438
 * Size:	00025C
 */
void P2DPane::makeMatrix(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lfs       f0, -0x4958(r2)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  lbz       r0, 0xC(r3)
	  rlwinm    r0,r0,27,30,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x70
	  bge-      .loc_0x48
	  cmpwi     r0, 0
	  bge-      .loc_0x54
	  b         .loc_0xA4

	.loc_0x48:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xA4
	  b         .loc_0x8C

	.loc_0x54:
	  lfs       f1, 0xBC(r30)
	  lfs       f0, 0x18E4(r13)
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x18E8(r13)
	  stfs      f0, 0x30(r1)
	  b         .loc_0xA4

	.loc_0x70:
	  lfs       f0, 0x18EC(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0xBC(r30)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x18F0(r13)
	  stfs      f0, 0x30(r1)
	  b         .loc_0xA4

	.loc_0x8C:
	  lfs       f1, 0x18F4(r13)
	  lfs       f0, 0x18F8(r13)
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0xBC(r30)
	  stfs      f0, 0x30(r1)

	.loc_0xA4:
	  lha       r3, 0xB8(r30)
	  xoris     r0, r4, 0x8000
	  xoris     r7, r5, 0x8000
	  lha       r4, 0xBA(r30)
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x74(r1)
	  xoris     r8, r4, 0x8000
	  lis       r31, 0x4330
	  lfd       f3, -0x4950(r2)
	  stw       r0, 0x6C(r1)
	  addi      r6, r1, 0x1C
	  stw       r31, 0x70(r1)
	  addi      r3, r30, 0x38
	  addi      r4, r30, 0xC0
	  stw       r31, 0x68(r1)
	  addi      r5, r1, 0x28
	  lfd       f1, 0x70(r1)
	  lfd       f0, 0x68(r1)
	  stw       r8, 0x84(r1)
	  fsubs     f1, f1, f3
	  fsubs     f0, f0, f3
	  stw       r7, 0x7C(r1)
	  stw       r31, 0x80(r1)
	  fadds     f0, f1, f0
	  stw       r31, 0x78(r1)
	  lfd       f2, 0x80(r1)
	  lfd       f1, 0x78(r1)
	  stfs      f0, 0x18(r1)
	  fsubs     f2, f2, f3
	  fsubs     f1, f1, f3
	  lfs       f0, 0x18(r1)
	  fadds     f1, f2, f1
	  stfs      f0, 0x1C(r1)
	  stfs      f1, 0x20(r1)
	  lfs       f0, 0x14(r30)
	  stfs      f0, 0x24(r1)
	  bl        -0x173478
	  lha       r3, 0xB8(r30)
	  lha       r0, 0xBA(r30)
	  neg       r3, r3
	  lfd       f5, -0x4950(r2)
	  neg       r0, r0
	  lfs       f3, 0x38(r30)
	  xoris     r3, r3, 0x8000
	  lfs       f1, 0x3C(r30)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x64(r1)
	  lfs       f4, 0x44(r30)
	  stw       r0, 0x5C(r1)
	  stw       r31, 0x60(r1)
	  stw       r31, 0x58(r1)
	  lfd       f2, 0x60(r1)
	  lfd       f0, 0x58(r1)
	  fsubs     f2, f2, f5
	  fsubs     f0, f0, f5
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x44(r30)
	  lha       r3, 0xB8(r30)
	  lha       r0, 0xBA(r30)
	  neg       r3, r3
	  lfs       f3, 0x48(r30)
	  neg       r0, r0
	  lfs       f1, 0x4C(r30)
	  xoris     r3, r3, 0x8000
	  lfs       f4, 0x54(r30)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x54(r1)
	  stw       r0, 0x4C(r1)
	  stw       r31, 0x50(r1)
	  stw       r31, 0x48(r1)
	  lfd       f2, 0x50(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f2, f2, f5
	  fsubs     f0, f0, f5
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x54(r30)
	  lha       r3, 0xB8(r30)
	  lha       r0, 0xBA(r30)
	  neg       r3, r3
	  lfs       f3, 0x58(r30)
	  neg       r0, r0
	  lfs       f1, 0x5C(r30)
	  xoris     r3, r3, 0x8000
	  lfs       f4, 0x64(r30)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x44(r1)
	  stw       r0, 0x3C(r1)
	  stw       r31, 0x40(r1)
	  stw       r31, 0x38(r1)
	  lfd       f2, 0x40(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f2, f2, f5
	  fsubs     f0, f0, f5
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x64(r30)
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void P2DPane::setCullBack(bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B1694
 * Size:	00010C
 */
void P2DPane::loadChildResource()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stw       r31, 0xC4(r1)
	  stw       r30, 0xC0(r1)
	  stw       r29, 0xBC(r1)
	  lwz       r29, 0xD0(r3)
	  cmplwi    r29, 0
	  beq-      .loc_0xE8
	  subi      r29, r29, 0xC
	  b         .loc_0xE8

	.loc_0x2C:
	  lwz       r3, 0xC(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r29)
	  lwz       r30, 0xD0(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0xD0
	  subi      r30, r30, 0xC
	  b         .loc_0xD0

	.loc_0x58:
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  addi      r3, r3, 0xD0
	  bl        -0xE90
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  subi      r3, r3, 0xC

	.loc_0x84:
	  mr        r31, r3
	  b         .loc_0xB8

	.loc_0x8C:
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  bl        .loc_0x0
	  lwz       r31, 0x18(r31)
	  cmplwi    r31, 0
	  beq-      .loc_0xB8
	  subi      r31, r31, 0xC

	.loc_0xB8:
	  cmplwi    r31, 0
	  bne+      .loc_0x8C
	  lwz       r30, 0x18(r30)
	  cmplwi    r30, 0
	  beq-      .loc_0xD0
	  subi      r30, r30, 0xC

	.loc_0xD0:
	  cmplwi    r30, 0
	  bne+      .loc_0x58
	  lwz       r29, 0x18(r29)
	  cmplwi    r29, 0
	  beq-      .loc_0xE8
	  subi      r29, r29, 0xC

	.loc_0xE8:
	  cmplwi    r29, 0
	  bne+      .loc_0x2C
	  lwz       r0, 0xCC(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  lwz       r29, 0xBC(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B17A0
 * Size:	000004
 */
void P2DPane::loadResource() { }

/*
 * --INFO--
 * Address:	801B17A4
 * Size:	000004
 */
void P2DPane::makeResident() { }

/*
 * --INFO--
 * Address:	801B17A8
 * Size:	000064
 */
void P2DPane::move(Vector3f& newPos)
{
	_18.move(newPos.x, newPos.y);
	mPaneZ = newPos.z;
}

/*
 * --INFO--
 * Address:	801B180C
 * Size:	000008
 */
void P2DPane::moveZ(f32 newZ) { mPaneZ = newZ; }

/*
 * --INFO--
 * Address:	801B1814
 * Size:	000024
 */
void P2DPane::add(int x, int y) { _18.add(x, y); }

/*
 * --INFO--
 * Address:	801B1838
 * Size:	000024
 */
void P2DPane::resize(int width, int height) { _18.resize(width, height); }

/*
 * --INFO--
 * Address:	801B185C
 * Size:	000068
 */
void P2DPane::drawSelf(int p1, int p2)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	drawSelf(p1, p2, &mtx);
}
