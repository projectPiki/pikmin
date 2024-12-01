#ifndef _GAMECORESECTION_H
#define _GAMECORESECTION_H

#include "types.h"
#include "Node.h"

struct Camera;
struct Controller;
struct Creature;
struct MapMgr;
struct RectArea;

/**
 * @brief TODO
 */
enum CorePauseFlags {
	COREPAUSE_Unk1 = 0x1,
	COREPAUSE_Unk2 = 0x2,
	COREPAUSE_Unk3 = 0x4,
	COREPAUSE_Unk4 = 0x8,
	// ...
	COREPAUSE_Unk16 = 0x8000,
};

/**
 * @brief TODO
 */
struct GameCoreSection : public Node {
	GameCoreSection(Controller*, MapMgr*, Camera&);

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void updateTextDemo();
	void startMovie(u32, bool);
	void endMovie(int);
	void exitDayEnd();
	void forceDayEnd();
	void clearDeadlyPikmins();
	void enterFreePikmins();
	void cleanupDayEnd();
	void prepareBadEnd();
	void exitStage();
	void initStage();
	void finalSetup();
	void startContainerDemo();
	void startSundownWarn();
	void updateAI();
	void draw1D(Graphics&);
	void draw2D(Graphics&);

	static void startTextDemo(Creature*, int);

	// unused/inlined:
	void hideTeki();
	void hideAllPellet();
	void hidePelletExceptSucked();

	static u16 pauseFlag;
	static int textDemoState;
	static u16 textDemoTimer;
	static int textDemoIndex;

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

inline void clearCorePauseFlag() { GameCoreSection::pauseFlag = 0; }

inline void setCorePauseFlag(u32 flag) { GameCoreSection::pauseFlag = flag; }

inline bool isCorePauseFlag(u32 flag) { return GameCoreSection::pauseFlag & flag; }

#endif
