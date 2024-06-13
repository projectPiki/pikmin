#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#include "types.h"
#include "Node.h"

struct BaseApp;
struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x355.
 */
struct GameFlow : public Node {
	inline GameFlow(); // TODO: work this out later

	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10

	void drawLoadLogo(Graphics&, bool, Texture*, f32);
	void menuToggleTimers(struct Menu&);
	void menuTogglePrint(Menu&);
	void menuToggleDInfo(Menu&);
	void menuToggleDExtra(Menu&);
	void menuToggleBlur(Menu&);
	void menuToggleInfo(Menu&);
	void menuToggleColls(Menu&);
	void menuChangeFilter(Menu&);
	void menuIncreaseFilter(Menu&);
	void menuDecreaseFilter(Menu&);
	void setLoadBanner(char*);
	void hardReset(BaseApp*);
	void softReset();
	void* loadShape(char*, bool);
	void addGenNode(char*, CoreNode*);

	// _00     = VTBL
	// _00-_1C = Node
};

extern GameFlow gameflow;

#endif
