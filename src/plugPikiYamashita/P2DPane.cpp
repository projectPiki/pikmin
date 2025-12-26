#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "P2D/Graph.h"
#include "P2D/Pane.h"
#include "PSU/LinkList.h"
#include "PSU/Tree.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(30) // Why is this one suddenly capitalized?

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("P2DPane");

/**
 * @todo: Documentation
 */
void P2DPane::setCallBack(P2DPaneCallBack* callback)
{
	mCallBack = callback;
}

/**
 * @todo: Documentation
 */
void P2DPane::printTagName(bool doPrint)
{
	if (doPrint) {
		if (mTagName) {
			const char* s = reinterpret_cast<char*>(&mTagName);
			PRINT("tag[%c%c%c%c] \n", s[0], s[1], s[2], s[3]);
		} else {
			PRINT("tag[]\n");
		}
	}
}

/**
 * @todo: Documentation
 */
void P2DPane::drawSelf(int, int, immut Matrix4f* drawMtx)
{
	if (mCallBack) {
		Matrix4f posMtx;
		drawMtx->multiplyTo(mWorldMtx, posMtx);
		GXLoadPosMtxImm(posMtx.mMtx, 0);
	}
}

/**
 * @todo: Documentation
 */
P2DPaneCallBackBase::P2DPaneCallBackBase(P2DPane* pane, P2DPaneType type)
{
	checkPaneType(pane, type);
}

/**
 * @todo: Documentation
 */
void P2DPaneCallBackBase::checkPaneType(P2DPane* pane, P2DPaneType type)
{
	if (pane && pane->getTypeID() != type) {
		PRINT("This pane type is [%d]. not [%d] \n", pane->getTypeID(), type);
		ERROR("Can't set Call Back class.");
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void P2DPane::init()
{
	mOffsetX            = 0;
	mOffsetY            = 0;
	mFlag.mRotationAxis = PANEAXIS_X;
	mRotation           = 0.0f;
	mScale.set(1.0f, 1.0f, 1.0f);
	mCullMode = GX_CULL_NONE;
	mCallBack = nullptr;
	mPaneZ    = 0.0f;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
P2DPane::P2DPane()
    : mPaneTree(this)
{
	mPaneType = PANETYPE_Pane;

	show();
	mTagName = 0;
	mBounds.set(0, 0, 0, 0);
	init();
}

/**
 * @todo: Documentation
 */
P2DPane::P2DPane(P2DPane* parent, u16 paneType, bool, u32 tag, const PUTRect& p5)
    : mPaneTree(this)
{
	mPaneType = paneType;
	show();
	mTagName = tag;
	mBounds  = p5;
	if (parent) {
		parent->mPaneTree.appendChild(&mPaneTree);
	}

	init();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000158
 */
P2DPane::P2DPane(u32 tag, const PUTRect& rect)
    : mPaneTree(this)
{
	mPaneType = PANETYPE_Pane;
	show();
	mTagName = tag;
	mBounds  = rect;
	init();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000140
 */
P2DPane::P2DPane(u16 paneType, u32 tag, const PUTRect& rect)
    : mPaneTree(this)
{
	mPaneType = paneType;
	show();
	mTagName = tag;
	mBounds  = rect;
	init();
}

/**
 * @todo: Documentation
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

	mBounds.mMinX = (int)input->readShort();
	mBounds.mMinY = (int)input->readShort();
	mBounds.mMaxX = mBounds.mMinX + (int)input->readShort();
	mBounds.mMaxY = mBounds.mMinY + (int)input->readShort();

	if (parent) {
		parent->mPaneTree.appendChild(&mPaneTree);
	}

	init();
}

/**
 * @todo: Documentation
 */
P2DPane::~P2DPane()
{
	PSUTree<P2DPane>* tree = getPaneTree();
	PSUTreeIterator<P2DPane> iterator(tree->getFirstChild());
	while (iterator != nullptr) {
		delete (iterator++).getObject();
	}
}

/**
 * @todo: Documentation
 */
void P2DPane::draw(int xOffs, int yOffs, const P2DGrafContext* grafContext, bool applyScissor)
{
	P2DGrafContext context(*grafContext);
	if (context.mGrafType != P2DGRAF_Ortho) {
		applyScissor = false;
	}

	PSUTree<P2DPane>* parentTree = mPaneTree.getParent();
	P2DPane* parentPane          = nullptr;
	if (parentTree) {
		parentPane = parentTree->getObject();
	}

	if (IsVisible() && !mBounds.isEmpty()) {
		mGlobalBounds = mBounds;
		mClipBounds   = mBounds;
		makeMatrix(mBounds.mMinX + xOffs, mBounds.mMinY + yOffs);

		if (parentPane) {
			mGlobalBounds.add(parentPane->mGlobalBounds.mMinX, parentPane->mGlobalBounds.mMinY);
			parentPane->mWorldMtx.multiplyTo(mLocalMtx, mWorldMtx);
			mClipBounds.add(parentPane->mGlobalBounds.mMinX, parentPane->mGlobalBounds.mMinY);
			mClipBounds.intersect(parentPane->mClipBounds);
		} else {
			mGlobalBounds.add(xOffs, yOffs);
			mWorldMtx = mLocalMtx;
			mClipBounds.add(xOffs, yOffs);
		}

		if (applyScissor) {
			((P2DOrthoGraph*)grafContext)->scissorBounds(&mScissorBounds, &mClipBounds);
		}

		if (!mClipBounds.isEmpty() || !applyScissor) {
			context.place(mGlobalBounds);

			if (applyScissor) {
				context.scissor(mScissorBounds);
				context.setScissor();
			}

			GXSetCullMode((GXCullMode)mCullMode);
			drawSelf(xOffs, yOffs, &context.mViewMtx);
			if (mCallBack) {
				mCallBack->draw(this);
			}

			PSUTreeIterator<P2DPane> iter(mPaneTree.getFirstChild());
			while (iter != mPaneTree.getEndChild()) {
				iter->draw(0, 0, grafContext, applyScissor);
				++iter;
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void P2DPane::clip(const PUTRect& rect)
{
	PUTRect newRect = rect;
	newRect.add(mGlobalBounds.mMinX, mGlobalBounds.mMinY);
	mClipBounds.intersect(newRect);
}

/**
 * @todo: Documentation
 */
P2DPane* P2DPane::search(u32 tag, bool doPanicOnNull)
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

	if (doPanicOnNull) {
		const char* s = reinterpret_cast<char*>(&tag);
		PRINT("tag <%c%c%c%c> is not found.\n", s[0], s[1], s[2], s[3]);
		ERROR("tag <%c%c%c%c> is not found. 逝ってよし\n", s[0], s[1], s[2], s[3]); // "Go away"
	}
	return nullptr;
}

/**
 * @todo: Documentation
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

	mLocalMtx.makeSRT(mScale, rotAxis, Vector3f(f32(mOffsetX) + f32(x), f32(mOffsetY) + f32(y), mPaneZ));
	mLocalMtx.mMtx[0][3] += mLocalMtx.mMtx[0][0] * -mOffsetX + mLocalMtx.mMtx[0][1] * -mOffsetY;
	mLocalMtx.mMtx[1][3] += mLocalMtx.mMtx[1][0] * -mOffsetX + mLocalMtx.mMtx[1][1] * -mOffsetY;
	mLocalMtx.mMtx[2][3] += mLocalMtx.mMtx[2][0] * -mOffsetX + mLocalMtx.mMtx[2][1] * -mOffsetY;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000114
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

/**
 * @todo: Documentation
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
