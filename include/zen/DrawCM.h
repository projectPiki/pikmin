#ifndef _ZEN_DRAWCM_H
#define _ZEN_DRAWCM_H

#include "types.h"
#include "zen/DrawMenu.h"

struct GameChalQuickInfo;
struct Graphics;
struct Controller;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct DrawCMCSmenu : public DrawMenuBase {

	/**
	 * @brief TODO
	 */
	struct MenuExpansion {
		MenuExpansion();

		// TODO: members
	};

	inline DrawCMCSmenu(); // TODO: this

	virtual bool update(Controller*); // _14
	virtual void start();             // _18
	virtual void setModeFunc(int);    // _28

	bool modeAppear(Controller*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMcourseSelect {
	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	DrawCMcourseSelect();

	void start();
	void setBestScore();
	bool update(Controller*);
	void draw(Graphics&);
	returnStatusFlag getReturnStatusFlag();
	bool modeOperation(Controller*);

	// TODO: members
	u8 _00[0x94]; // _00
};

/**
 * @brief TODO
 */
struct DrawCMtitleObj {
	void init(P2DScreen*);
	void update();
	void wait(f32);
	void appear(f32);
	bool modeSleep();
	bool modeAppear();
	bool modeWait();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMscoreObj {
	DrawCMscoreObj();

	bool modeMove();
	bool modeWait();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMscoreMgr {
	void init(P2DScreen*);
	void update();
	void hide();
	void sleep();
	void appear(f32);
	bool modeSleep();
	bool modeAppear();
	bool modeWait();
	void setScore(int, int);

	// unused/inlined:
	void show();

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMBpicObj {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawCMBpicObj();

	bool modeWait();
	bool modeAppear();
	bool modeSleep();
	void setMode(modeFlag);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMbest {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	void init(P2DScreen*);
	void sleep();
	void update();
	void appear();
	void wait();
	bool modeSleep();
	bool modeWait();
	bool modeAppear();
	void setMode(modeFlag);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMresultAlpha {

	virtual bool update(); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMresultGraph : public DrawCMresultAlpha {

	// _00 = VTBL?
	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawCMresult {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawCMresult();

	bool update(Controller*);
	void draw(Graphics&);
	void start(const GameChalQuickInfo&);
	void makeResident();
	void setMode(modeFlag);
	bool modeSleep(Controller*);
	bool modeWaitAppear(Controller*);
	bool modeAppear(Controller*);
	bool modeOperation(Controller*);
	bool modeSave(Controller*);
	void createRankInEffect();

	// TODO: members
	u8 _00[0xa0];
};

} // namespace zen

#endif
