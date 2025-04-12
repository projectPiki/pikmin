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
	PANETYPE_Unk0    = 0x0,
	PANETYPE_Unk1    = 0x1,
	PANETYPE_Unk2    = 0x2,
	PANETYPE_Screen  = 0x8,
	PANETYPE_Pane    = 0x10,
	PANETYPE_Window  = 0x11,
	PANETYPE_Picture = 0x12,
	PANETYPE_TextBox = 0x13,
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
 */
struct P2DPaneCallBackBase {
	P2DPaneCallBackBase(P2DPane*, P2DPaneType);

	void checkPaneType(P2DPane*, P2DPaneType);

	// TODO: members
};

/**
 * @brief TODO
 */
struct P2DPaneCallBack : public zen::CallBack1<P2DPane*>, public P2DPaneCallBackBase {
	inline P2DPaneCallBack(); // TODO: make this

	virtual bool invoke(P2DPane*) = 0; // _08
	virtual bool draw(P2DPane*);       // _0C (weak)

	// TODO: members
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
	virtual void move(int, int);        // _14 (weak)
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
	virtual void drawSelf(int, int, Matrix4f*); // _30
	virtual P2DPane* search(u32, bool);         // _34
	virtual void makeMatrix(int, int);          // _38

	void setCallBack(P2DPaneCallBack*);
	void printTagName(bool);
	void update();
	void draw(int, int, const P2DGrafContext*, bool);
	void clip(const PUTRect&);
	void loadChildResource();
	void rotate(P2DRotateAxis, f32);

	// unused/inlined:
	void init();
	void setCullBack(bool);

	u16 getTypeID() { return mPaneType; }
	PSUTree<P2DPane>* getPaneTree() { return &mPaneTree; }

	void show() { mFlag.mIsVisible = true; }
	void hide() { mFlag.mIsVisible = false; }
	bool IsVisible() { return mFlag.mIsVisible; }

	// DLL inlines to do:
	void updateSelf()
	{
		if (mCallBack) {
			mCallBack->invoke(this);
		}
	}

	const PUTRect& getBounds();
	void setBounds(const PUTRect& bounds) { mBounds = bounds; }

	// these seem to genuinely be the same
	void place(const PUTRect& bounds) { mBounds = bounds; }

	s32 getWidth() { return mBounds.getWidth(); }
	s32 getHeight() { return mBounds.getHeight(); }

	int getPosH();
	int getPosV();

	bool alone();

	bool appendChild(P2DPane*);
	PSUTree<P2DPane>* getFirstChild();
	PSUTree<P2DPane>* getEndChild();

	f32 getRotate();
	void rotate(int, int P2DRotateAxis, f32);
	void rotateX(f32);
	void rotateZ(f32);
	void rotateZ(int, int, f32);

	void setOffset(int, int);

	void getDispPos(Vector3f*);

	Vector3f& getScale();
	void setScale(const Vector3f&);
	void setScale(f32);
	void setScale(f32, f32, f32);

	// _00 = VTBL
	P2DPaneCallBack* mCallBack; // _04
	u16 mPaneType;              // _08, see P2DPaneType enum
	u16 _0A;                    // _0A, maybe?
	struct {
		bool mIsVisible : 1;
		u16 mRotationAxis : 2;
	} mFlag;                    // _0C
	u32 mTagName;               // _10, unknown
	f32 mPaneZ;                 // _14
	PUTRect mBounds;            // _18
	PUTRect _20;                // _20
	PUTRect _28;                // _28
	PUTRect _30;                // _30
	Matrix4f _38;               // _38
	Matrix4f _78;               // _78
	s16 _B8;                    // _B8, maybe mOffsetX
	s16 _BA;                    // _BA, maybe mOffsetY
	f32 mRotation;              // _BC
	Vector3f mScale;            // _C0
	int mCullMode;              // _CC
	PSUTree<P2DPane> mPaneTree; // _D0
};

#endif
