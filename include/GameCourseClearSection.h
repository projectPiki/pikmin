#ifndef _GAMECOURSECLEARSECTION_H
#define _GAMECOURSECLEARSECTION_H

#include "types.h"
#include "Section.h"

struct Menu;
struct Font;

/**
 * @brief TODO
 */
struct GameCourseClearScreen : public Node {
	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10
	virtual void draw(Graphics&);           // _14

	void menuQuitGame(Menu&);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GameCourseClearSection : public Section {
	GameCourseClearSection();

	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 */
struct GameModeMgr {
	GameModeMgr(int);

	void updateSelect(Controller*);
	void drawSelect(Graphics&, Font*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// TODO: members
};

/**
 * @brief TODO
 */
struct CMcourseSelectMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct CMresultMode : public GameModeBase {
	CMresultMode();

	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct ContainerMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct CountDownMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct FinalResultMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameInfoMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameOverMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct HiScoreMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct HurryUpMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct ProgressiveMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct SaveFailureMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct SaveMesMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct UfoPartsMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct WMPauseMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

/**
 * @brief TODO
 */
struct WorldMapMode : public GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C

	// _??     = VTBL
	// _00-_?? = GameModeBase
	// TODO: members
};

#endif
