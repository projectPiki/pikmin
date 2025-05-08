#ifndef _P2D_PANE_H
#define _P2D_PANE_H

#include "types.h"
#include "zen/CallBack.h"
#include "PSU/Tree.h"
#include "PUT/Geometry.h"
#include "Vector.h"
#include "Matrix4f.h"
#include "P2D/Util.h"
#include "Delegate.h"

struct P2DGrafContext;
struct P2DPane;
struct RandomAccessStream;

/**
 * @brief TODO
 */
enum P2DPaneType {
	PANETYPE_Unk0    = 0x0,  // 0
	PANETYPE_Unk1    = 0x1,  // 1
	PANETYPE_Unk2    = 0x2,  // 2
	PANETYPE_Screen  = 0x8,  // 8
	PANETYPE_Pane    = 0x10, // 16
	PANETYPE_Window  = 0x11, // 17
	PANETYPE_Picture = 0x12, // 18
	PANETYPE_TextBox = 0x13, // 19
};

/**
 * @brief TODO
 */
enum P2DAxis {
	PANEAXIS_X = 0,
	PANEAXIS_Y = 1,
	PANEAXIS_Z = 2,
};

/**
 * @brief TODO
 *
 * @note Size: 0x1 (empty).
 */
struct P2DPaneCallBackBase {
	P2DPaneCallBackBase(P2DPane*, P2DPaneType);

	void checkPaneType(P2DPane*, P2DPaneType);

	// empty struct
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct P2DPaneCallBack : public zen::CallBack1<P2DPane*>, public P2DPaneCallBackBase {
	P2DPaneCallBack(P2DPane* pane, P2DPaneType type)
	    : P2DPaneCallBackBase(pane, type)
	{
	}

	virtual bool invoke(P2DPane*) = 0;           // _08
	virtual bool draw(P2DPane*) { return true; } // _0C (weak)

	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	// _04-_04 = P2DPaneCallBackBase (empty)
};

/**
 * @brief TODO
 *
 * @note Size: 0xEC.
 */
struct P2DPane {
	P2DPane();
	P2DPane(P2DPane*, u16, bool, u32, const PUTRect&);
	P2DPane(u32, const PUTRect&);                // unused/inlined
	P2DPane(u16, u32, const PUTRect&);           // unused/inlined
	P2DPane(P2DPane*, RandomAccessStream*, u16); // unused/inlined

	virtual void loadResource() { }     // _08
	virtual void makeResident() { }     // _0C
	virtual ~P2DPane();                 // _10
	virtual void move(int x, int y);    // _14 (weak)
	virtual void move(Vector3f& newPos) // _18
	{
		mBounds.move(newPos.x, newPos.y);
		mPaneZ = newPos.z;
	}
	virtual void move(int, int, f32);                                             // _1C
	virtual void moveZ(f32 newZ) { mPaneZ = newZ; }                               // _20
	virtual void add(int x, int y) { mBounds.add(x, y); }                         // _24
	virtual void resize(int width, int height) { mBounds.resize(width, height); } // _28
	virtual void drawSelf(int x, int y)                                           // _2C
	{
		Matrix4f mtx;
		mtx.makeIdentity();
		drawSelf(x, y, &mtx);
	}
	virtual void drawSelf(int x, int y, Matrix4f* transform); // _30
	virtual P2DPane* search(u32 tag, bool doPanicOnNull);     // _34
	virtual void makeMatrix(int x, int y);                    // _38

	void setCallBack(P2DPaneCallBack*);
	void printTagName(bool);
	void update();
	void draw(int xOffs, int yOffs, const P2DGrafContext* grafContext, bool applyScissor);
	void clip(const PUTRect& clippingRect);
	void loadChildResource();

	// weak
	void rotate(P2DRotateAxis axis, f32 angle)
	{
		mFlag.mRotationAxis = axis;
		mRotation           = angle;
		if (mRotation < 0.0f) {
			mRotation += TAU;
		} else if (mRotation > TAU) {
			mRotation -= TAU;
		}
	}

	// unused/inlined:
	void init();
	void setCullBack(bool);

	u16 getTypeID() { return mPaneType; }
	PSUTree<P2DPane>* getPaneTree() { return &mPaneTree; }

	void show() { mFlag.mIsVisible = true; }
	void hide() { mFlag.mIsVisible = false; }
	bool IsVisible() { return mFlag.mIsVisible; }
	void updateSelf()
	{
		if (mCallBack) {
			mCallBack->invoke(this);
		}
	}

	int getPosH() { return mBounds.mMinX; }
	int getPosV() { return mBounds.mMinY; }

	const PUTRect& getBounds() { return mBounds; }
	void setBounds(const PUTRect& bounds) { mBounds = bounds; }

	// these seem to genuinely be the same
	void place(const PUTRect& bounds) { mBounds = bounds; }

	s32 getWidth() { return mBounds.getWidth(); }
	s32 getHeight() { return mBounds.getHeight(); }

	void setOffset(int offX, int offY)
	{
		mOffsetX = offX;
		mOffsetY = offY;
	}

	f32 getRotate() { return mRotation; }
	void rotateX(f32 angle) { rotate(P2DROTATE_X, angle); }
	void rotateZ(f32 angle) { rotate(P2DROTATE_Z, angle); }
	void rotateZ(int x, int y, f32 rotZ) { rotate(x, y, P2DROTATE_Z, rotZ); }
	void rotate(int x, int y, P2DRotateAxis axis, f32 angle)
	{
		mOffsetX = x;
		mOffsetY = y;
		rotate(axis, angle);
	}

	PSUTree<P2DPane>* getFirstChild() { return mPaneTree.getFirstChild(); }
	PSUTree<P2DPane>* getEndChild() { return mPaneTree.getEndChild(); }

	bool appendChild(P2DPane* child) { return mPaneTree.appendChild(&child->mPaneTree); }

	bool alone() { return mPaneTree.getParent()->removeChild(&mPaneTree); }

	Vector3f& getScale() { return mScale; }
	void setScale(f32 scale) { mScale.set(scale, scale, scale); }
	void setScale(const Vector3f& scale) { mScale = scale; }
	void setScale(f32 x, f32 y, f32 z) { mScale.set(x, y, z); }

	void getDispPos(Vector3f* dispPos)
	{
		Vector3f pos;
		mWorldMtx.getColumn(3, pos);
		*dispPos = pos;
	}

	// _00 = VTBL
	P2DPaneCallBack* mCallBack; // _04
	u16 mPaneType;              // _08, see P2DPaneType enum
	u16 _0A;                    // _0A
	struct {
		bool mIsVisible : 1;
		u16 mRotationAxis : 2;
	} mFlag;                    // _0C
	u32 mTagName;               // _10, unknown
	f32 mPaneZ;                 // _14
	PUTRect mBounds;            // _18
	PUTRect mGlobalBounds;      // _20
	PUTRect mClipBounds;        // _28
	PUTRect mScissorBounds;     // _30
	Matrix4f mLocalMtx;         // _38
	Matrix4f mWorldMtx;         // _78
	s16 mOffsetX;               // _B8
	s16 mOffsetY;               // _BA
	f32 mRotation;              // _BC
	Vector3f mScale;            // _C0
	int mCullMode;              // _CC
	PSUTree<P2DPane> mPaneTree; // _D0
};

#endif
