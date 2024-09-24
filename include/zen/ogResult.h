#ifndef _ZEN_OGRESULT_H
#define _ZEN_OGRESULT_H

#include "types.h"

struct P2DPane;
struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
enum EnumResult {

};

/**
 * @brief TODO
 */
struct ogScrResultMgr {
	ogScrResultMgr();
	ogScrResultMgr(EnumResult*);

	void ogScrResultMgrSub();
	void start();
	void update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void check1000(int, P2DPane*, P2DPane*, int);
	void setEnumResultTable(EnumResult*);
	void StartRESULT();

	// TODO: members
};

} // namespace zen

#endif
