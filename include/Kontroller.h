#ifndef _KONTROLLER_H
#define _KONTROLLER_H

#include "types.h"
#include "Controller.h"

/**
 * @brief TODO
 */
struct Kontroller : public Controller {
	Kontroller(int);

	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10

	void save(RamStream*, int);
	void load(RamStream*, int);
	void write(RandomAccessStream&);

	static int getSaveSize(int);

	// unused/inlined:
	void stop();

	// _00     = VTBL
	// _00-_50 = Controller
	int _50;        // _50
	int _54;        // _54
	RamStream* _58; // _58
};

extern RamStream* controllerBuffer;

#endif
