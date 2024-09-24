#ifndef _ZEN_DRAWCONTAINER_H
#define _ZEN_DRAWCONTAINER_H

#include "types.h"
#include "P2D/Pane.h"

struct P2DPicture;
struct P2DScreen;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct DrawContainer {

	/**
	 * @brief TODO
	 */
	enum containerType {

	};

	DrawContainer();

	void start(containerType, int, int, int, int, int, int);
	void draw(Graphics&);
	void setDispParam();
	void operationStatus();
	void update(int&);

	// unused/inlined:
	~DrawContainer();
	void waitStatus();
	void startStatus();
	void endStatus();

	// TODO: members
};

/**
 * @brief TODO
 */
struct ArrowBasicCallBack {

	void judgeArrowType();

	// TODO: members
};

/**
 * @brief TODO
 */
struct ArrowCenterCallBack : public P2DPaneCallBack, public ArrowBasicCallBack {

	virtual bool invoke(P2DPane*); // _08

	void setTexture(P2DPicture*);

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack?
	// _04-_?? = ArrowBasicCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct ArrowLRCallBack : public P2DPaneCallBack, public ArrowBasicCallBack {

	virtual bool invoke(P2DPane*); // _08

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack?
	// _04-_?? = ArrowBasicCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct StickCallBack : public P2DPaneCallBack {

	virtual bool invoke(P2DPane*); // _08

	// _00     = VTBL
	// _00-_04 = P2DPaneCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct MessageMgr {

	/**
	 * @brief TODO
	 */
	enum messageFlag {
		// TODO: this
	};

	void init(DrawContainer::containerType);
	void setTextBox(DrawContainer::containerType, P2DScreen&, int, int, int);
	void setMessage(messageFlag, f32);

	// TODO: members
};

/**
 * @brief TODO
 */
struct WindowPaneMgr {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	void update(modeFlag, f32, f32);

	// TODO: members
};

} // namespace zen

#endif
