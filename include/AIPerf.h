#ifndef _AIPERF_H
#define _AIPERF_H

#include "types.h"

struct Menu;

/*
 * @brief TODO
 */
struct AIPerf {
	void clearCounts();
	void addMenu(Menu*);
	void toggleMoveType(Menu&);
	void toggleGeneratorMode(Menu&);
	void toggleBridge(Menu&);
	void toggleShowRoute(Menu&);
	void toggleKando(Menu&);
	void toggleLOD(Menu&);
	void toggleColls(Menu&);
	void toggleASync(Menu&);
	void toggleInsQuick(Menu&);
	void toggleSoundDebug(Menu&);
	void toggleCollSort(Menu&);
	void incOptLevel(Menu&);
	void decOptLevel(Menu&);
	void incUfoLevel(Menu&);
	void decUfoLevel(Menu&);
	void collectPikis(Menu&);
	void fullfillPiki(Menu&);
	void flowerPiki(Menu&);
	void breakSluice(Menu&);

	// unused/inlined:
	void toggleAIGrid(Menu&);
	void toggleUpdateMgr(Menu&);
	void togglePikiMabiki(Menu&);
	void togglePsOptimise(Menu&);
	void toggleIteratorCull(Menu&);
	void toggleUseGrid(Menu&);
	void incGridShift(Menu&);
	void decGridShift(Menu&);
	void toggleUpdateSearchBuffer(Menu&);

	static int useGrid;
	static bool iteratorCull;

	// TODO: members
};

#endif
