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
 *
 * @note Size: 0x55C.
 */
struct ogScrResultMgr {

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	ogScrResultMgr();
	ogScrResultMgr(EnumResult*);

	void ogScrResultMgrSub();
	void start();
	returnStatusFlag update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void check1000(int, P2DPane*, P2DPane*, int);
	void setEnumResultTable(EnumResult*);
	void StartRESULT();

	u8 _00[0x55C]; // _00, unknown
};

extern char* bloFile_Res_Table[];

} // namespace zen

#endif
