#ifndef _GAMECOURSECLEARSECTION_H
#define _GAMECOURSECLEARSECTION_H

#include "types.h"
#include "Section.h"
#include "Parameters.h"
#include "zen/particle.h"

struct Menu;
struct Font;

/**
 * @brief TODO
 */
struct GameCourseClearScreen : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Name according to the DLL list. Offsets relative to screen for convenience.
	 */
	struct Parms : public Parameters {
		Parms()
		    : _24(this, 300.0f, 0.0f, 1000.0f, "p00", "floatテストだぴょ−ン") // 'float test'
		    , _34(this, 1, 0, 100, "i00", "intテストだぴょ−ン")               // 'int test'
		{
		}

		// _20-_24 = Parameters
		Parm<f32> _24; // _24, p00
		Parm<int> _34; // _34, i00
	};

	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10
	virtual void draw(Graphics&);           // _14

	void menuQuitGame(Menu&);

	// _00     = VTBL
	// _00-_20 = Node
	Parms mCourseClearParms;                  // _20
	u8 _44[0x10];                             // _44, unknown
	zen::particleManager mCourseClearPtclMgr; // _54
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
