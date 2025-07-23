#ifndef _TEKIYAMASHITA_H
#define _TEKIYAMASHITA_H

#include "teki.h"
#include "types.h"

/*
 * @brief TODO
 */
struct TekiYamashita {
	static void makeTekiParameters(TekiMgr*);
	static void makeTekis(TekiMgr*);
	static void makeDefaultAnimations(); // unused
};

#endif
