#include "P2D/Pane.h"
#include "P2D/Graph.h"
#include "PSU/LinkList.h"
#include "PSU/Tree.h"
#include "DebugLog.h"
#include "Dolphin/gx.h"

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
DEFINE_PRINT("P2DPane");

/*
 * --INFO--
 * Address:	801B069C
 * Size:	000008
 */
void P2DPane::setCallBack(P2DPaneCallBack* callback)
{
	mCallBack = callback;
}

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
P2DPaneCallBackBase::P2DPaneCallBackBase(P2DPane* pane, P2DPaneType type)
{
	checkPaneType(pane, type);
}

/*
 * --INFO--
 * Address:	801B0730
 * Size:	000014
 */
void P2DPaneCallBackBase::checkPaneType(P2DPane* pane, P2DPaneType type)
{
	if (pane && pane->getTypeID() != type) {
		PRINT("This pane type is [%d]. not [%d] \n", pane->getTypeID(), type);
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
	_B8                 = 0;
	_BA                 = 0;
	mFlag.mRotationAxis = PANEAXIS_X;
	mRotation           = 0.0f;
	mScale.set(1.0f, 1.0f, 1.0f);
	mCullMode = GX_CULL_NONE;
	mCallBack = nullptr;
	mPaneZ    = 0.0f;
}

/*
 * --INFO--
 * Address:	801B0744
 * Size:	000134
 */
void P2DPane::update()
{
	updateSelf();

	PSUTreeIterator<P2DPane> iterator(mPaneTree.getFirstChild());
	while (iterator != mPaneTree.getEndChild()) {
		iterator->update();
		++iterator;
	}
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

	show();
	mTagName = 0;
	mRectTransform.set(0, 0, 0, 0);
	init();
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
	show();
	mTagName       = tag;
	mRectTransform = p5;
	if (parent) {
		parent->mPaneTree.appendChild(&mPaneTree);
	}

	init();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
 */
P2DPane::P2DPane(u32 tag, const PUTRect& rect)
    : mPaneTree(this)
{
	mPaneType = PANETYPE_Unk16;
	show();
	mTagName       = tag;
	mRectTransform = rect;
	init();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
P2DPane::P2DPane(u16 paneType, u32 tag, const PUTRect& rect)
    : mPaneTree(this)
{
	mPaneType = paneType;
	show();
	mTagName       = tag;
	mRectTransform = rect;
	init();
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
		show();
	} else {
		hide();
	}

	u8 tag[4];
	input->readByte();
	tag[0] = input->readByte();
	tag[1] = input->readByte();
	tag[2] = input->readByte();
	tag[3] = input->readByte();

	mTagName = *(u32*)tag;

	mRectTransform.mMinX = (int)input->readShort();
	mRectTransform.mMinY = (int)input->readShort();
	mRectTransform.mMaxX = mRectTransform.mMinX + (int)input->readShort();
	mRectTransform.mMaxY = mRectTransform.mMinY + (int)input->readShort();

	if (parent) {
		parent->mPaneTree.appendChild(&mPaneTree);
	}

	init();
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
void P2DPane::draw(int p1, int p2, const P2DGrafContext* grafContext, bool p4)
{
	P2DGrafContext context(*grafContext);
	if (context.mGrafType != P2DGRAF_Ortho) {
		p4 = false;
	}

	PSUTree<P2DPane>* parentTree = mPaneTree.getParent();
	P2DPane* parentPane          = nullptr;
	if (parentTree) {
		parentPane = parentTree->getObject();
	}

	if (IsVisible() && !mRectTransform.isEmpty()) {
		_20 = mRectTransform;
		_28 = mRectTransform;
		makeMatrix(mRectTransform.mMinX + p1, mRectTransform.mMinY + p2);

		if (parentPane) {
			_20.add(parentPane->_20.mMinX, parentPane->_20.mMinY);
			parentPane->_78.multiplyTo(_38, _78);
			_28.add(parentPane->_20.mMinX, parentPane->_20.mMinY);
			_28.intersect(parentPane->_28);
		} else {
			_20.add(p1, p2);
			_78 = _38;
			_28.add(p1, p2);
		}

		if (p4) {
			((P2DOrthoGraph*)grafContext)->scissorBounds(&_30, &_28);
		}

		if (!_28.isEmpty() || !p4) {
			context.place(_20);

			if (p4) {
				context.scissor(_30);
				context.setScissor();
			}

			GXSetCullMode((GXCullMode)mCullMode);
			drawSelf(p1, p2, &context._70);
			if (mCallBack) {
				mCallBack->draw(this);
			}

			PSUTreeIterator<P2DPane> iter(mPaneTree.getFirstChild());
			while (iter != mPaneTree.getEndChild()) {
				iter->draw(0, 0, grafContext, p4);
				++iter;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	801B1348
 * Size:	00004C
 */
void P2DPane::clip(const PUTRect& rect)
{
	PUTRect newRect = rect;
	newRect.add(_20.mMinX, _20.mMinY);
	_28.intersect(newRect);
}

/*
 * --INFO--
 * Address:	801B1394
 * Size:	0000A4
 */
P2DPane* P2DPane::search(u32 tag, bool p2)
{
	if (tag == mTagName) {
		return this;
	}

	PSUTreeIterator<P2DPane> iter(mPaneTree.getFirstChild());
	while (iter != mPaneTree.getEndChild()) {
		P2DPane* pane = iter->search(tag, false);
		if (pane) {
			return pane;
		}
		++iter;
	}

	if (p2) {
		PRINT("tag <%c%c%c%c> is not found.\n", ((u8*)&tag)[0], ((u8*)&tag)[1], ((u8*)&tag)[2], ((u8*)&tag)[3]);
		ERROR("tag <%c%c%c%c> is not found.\n", ((u8*)&tag)[0], ((u8*)&tag)[1], ((u8*)&tag)[2], ((u8*)&tag)[3]);
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	801B1438
 * Size:	00025C
 */
void P2DPane::makeMatrix(int x, int y)
{
	Vector3f rotAxis;
	switch (mFlag.mRotationAxis) {
	case PANEAXIS_X:
		rotAxis.set(mRotation, 0.0f, 0.0f);
		break;
	case PANEAXIS_Y:
		rotAxis.set(0.0f, mRotation, 0.0f);
		break;
	case PANEAXIS_Z:
		rotAxis.set(0.0f, 0.0f, mRotation);
		break;
	}

	_38.makeSRT(mScale, rotAxis, Vector3f(f32(_B8) + f32(x), f32(_BA) + f32(y), mPaneZ));
	_38.mMtx[0][3] += _38.mMtx[0][0] * -_B8 + _38.mMtx[0][1] * -_BA;
	_38.mMtx[1][3] += _38.mMtx[1][0] * -_B8 + _38.mMtx[1][1] * -_BA;
	_38.mMtx[2][3] += _38.mMtx[2][0] * -_B8 + _38.mMtx[2][1] * -_BA;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void P2DPane::setCullBack(bool isCullBack)
{
	mCullMode = (isCullBack) ? GX_CULL_BACK : GX_CULL_NONE;

	PSUTreeIterator<P2DPane> iter(mPaneTree.getFirstChild());
	while (iter != mPaneTree.getEndChild()) {
		iter->setCullBack(isCullBack);
		++iter;
	}
}

/*
 * --INFO--
 * Address:	801B1694
 * Size:	00010C
 */
void P2DPane::loadChildResource()
{
	PSUTreeIterator<P2DPane> iter(mPaneTree.getFirstChild());
	while (iter != mPaneTree.getEndChild()) {
		iter->loadResource();
		iter->loadChildResource();
		++iter;
	}
}
