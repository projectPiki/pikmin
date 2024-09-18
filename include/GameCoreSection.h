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
struct GameCoreSection : public Node {
	GameCoreSection(Controller*, MapMgr*, Camera&);

	virtual void update();        // _10
	virtual void draw(Graphics&); // _14

	void startTextDemo(Creature*, int);
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

	// unused/inlined:
	void hideTeki();
	void hideAllPellet();
	void hidePelletExceptSucked();

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

#endif
