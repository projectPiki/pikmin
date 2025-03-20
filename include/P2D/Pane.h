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
	PANETYPE_Screen = 8,
	PANETYPE_Unk16  = 16,
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

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DPane();                         // _10
	virtual void move(int, int);                // _14 (weak)
	virtual void move(Vector3f&);               // _18
	virtual void move(int, int, f32);           // _1C
	virtual void moveZ(f32);                    // _20
	virtual void add(int, int);                 // _24
	virtual void resize(int, int);              // _28
	virtual void drawSelf(int, int);            // _2C
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

	// DLL inlines to do:
	void setBounds(const PUTRect&);
	void updateSelf();
	s32 getWidth();
	s32 getHeight();
	bool IsVisible();
	bool alone();
	bool appendChild(P2DPane*);
	PSUTree<P2DPane>* getFirstChild();
	PSUTree<P2DPane>* getEndChild();
	const PUTRect& getBounds();
	Vector3f& getScale();
	f32 getRotate();
	int getPosH();
	int getPosV();
	void getDispPos(Vector3f*);
	void place(const PUTRect&);
	void rotate(int, int P2DRotateAxis, f32);
	void rotateX(f32);
	void rotateZ(f32);
	void rotateZ(int, int, f32);
	void setOffset(int, int);
	void setScale(const Vector3f&);
	void setScale(f32);
	void setScale(f32, f32, f32);

	// _00 = VTBL
	P2DPaneCallBack* mCallBack; // _04
	u16 mPaneType;              // _08, see P2DPaneType enum
	u16 _0A;                    // _0A, maybe?
	struct {
		bool mIsVisible : 1;
		u16 m2 : 2;
	} mFlag;                    // _0C
	u32 mTagName;               // _10, unknown
	f32 mPaneZ;                 // _14
	PUTRect mRectTransform;     // _18
	PUTRect _20;                // _20
	PUTRect _28;                // _28
	PUTRect _30;                // _30
	u8 _38[0x78 - 0x38];        // _38, unknown
	Matrix4f _78;               // _78
	u16 _B8;                    // _B8
	u16 _BA;                    // _BA
	f32 _BC;                    // _BC
	Vector3f _C0;               // _C0
	int mCullMode;              // _CC
	PSUTree<P2DPane> mPaneTree; // _D0
};

#endif
