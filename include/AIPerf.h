#ifndef _AIPERF_H
#define _AIPERF_H

#include "types.h"

struct Menu;

/*
 * @brief A static class that contains various settings.
 */
struct AIPerf {
public:
	void addMenu(Menu*);
	static void clearCounts();

protected:
	void toggleMoveType(Menu&);
	void toggleGeneratorMode(Menu&);
	void toggleBridge(Menu&);
	void toggleShowRoute(Menu&);
	void toggleAIGrid(Menu&);
	void toggleKando(Menu&);
	void toggleLOD(Menu&);
	void toggleColls(Menu&);
	void toggleASync(Menu&);
	void toggleInsQuick(Menu&);
	void toggleSoundDebug(Menu&);
	void toggleUpdateMgr(Menu&);
	void togglePikiMabiki(Menu&);
	void togglePsOptimise(Menu&);
	void toggleCollSort(Menu&);
	void toggleIteratorCull(Menu&);
	void toggleUseGrid(Menu&);
	void incGridShift(Menu&);
	void decGridShift(Menu&);
	void incOptLevel(Menu&);
	void decOptLevel(Menu&);
	void incUfoLevel(Menu&);
	void decUfoLevel(Menu&);
	void toggleUpdateSearchBuffer(Menu&);
	void collectPikis(Menu&);
	void fullfillPiki(Menu&);
	void flowerPiki(Menu&);
	void breakSluice(Menu&);

public:
	static int useGrid;
	static int gridShift;
	static bool pikiMabiki;
	static bool useLOD;
	static bool iteratorCull;
	static int optLevel;
	static bool bridgeFast;
	static int drawshapeCullCnt;
	static int outsideViewCnt;
	static int viewCullCnt;
	static int aiCullCnt;
	static int iteratorCullCnt;
	static int collisionCnt;
	static int searchInsertCnt;
	static int searchCullCnt;
	static int searchCnt;
	static int moveType; // 0 = stop, 1 = no stop, 2 = slip
	static bool generatorMode;
	static bool kandoOnly;
	static bool soundDebug;
	static bool updateSearchBuffer;
	static bool loopOptimise;
	static bool useUpdateMgr;
	static int ufoLevel;
	static bool showRoute;
	static bool aiGrid;
	static bool showColls;
	static bool useASync;
	static bool insQuick;
	static bool useCollSort;
};

#endif
