#ifndef _P2D_PANE_H
#define _P2D_PANE_H

#include "types.h"
#include "zen/CallBack.h"
#include "P2D/Util.h"

struct P2DGrafContext;
struct P2DPane;
struct PUTRect;
struct Matrix4f;
struct RandomAccessStream;
struct Vector3f;

/**
 * @brief TODO
 *
 * @note Might be a struct?
 */
enum P2DPaneType {

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
	virtual void search(u32, bool);             // _34
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

	// _00 = VTBL
	P2DPaneCallBack* mCallBack; // _04
	                            // TODO: members
};

#endif
