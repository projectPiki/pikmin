#ifndef _GAMEFLOW_H
#define _GAMEFLOW_H

#include "types.h"
#include "Node.h"

struct BaseApp;
struct GameQuickInfo;
struct GameChalQuickInfo;
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

	// unused/inlined:
	void addOptionsMenu(Menu*);
	void addFilterMenu(Menu*);

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x1F0 - 0x20];   // _20, unknown
	u32 _1F0;               // _1F0, could be int
	u32 _1F4;               // _1F4, could be int
	u8 _1F8[0x2B0 - 0x1F8]; // _1F8, unknown
	u32 _2B0;               // _2B0, could be int
	u8 _2B4[0x355 - 0x2B4]; // _2B4, unknown
};

/**
 * @brief TODO
 */
struct GameGenNode : public Node {
	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameGenFlow : public Node {
	virtual void update(); // _10

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameHiscores {
	void Initialise();

	// TODO: members
};

/**
 * @brief TODO
 */
struct PlayState : public CoreNode {
	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void openStage(int);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct GamePrefs : public CoreNode {
	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void Initialise();
	void setBgmVol(u8);
	void setSfxVol(u8);
	void setStereoMode(bool);
	void setVibeMode(bool);
	void setChildMode(bool);
	void getChallengeScores(GameChalQuickInfo&);
	bool checkIsHiscore(GameChalQuickInfo&);
	bool checkIsHiscore(GameQuickInfo&);
	void fixSoundMode();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct GameRecChalCourse {
	GameRecChalCourse();

	// TODO: members
};

/**
 * @brief TODO
 */
struct GameRecDeadPikmin {
	GameRecDeadPikmin();

	// TODO: members
};

/**
 * @brief TODO
 */
struct GameRecBornPikmin {
	GameRecBornPikmin();

	// TODO: members
};

/**
 * @brief TODO
 */
struct GameRecMinDay {
	GameRecMinDay();

	// TODO: members
};

extern GameFlow gameflow;

#endif
