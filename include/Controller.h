#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "types.h"

struct Controller {
	u8 _00[0x20];
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	u32 _30;
	u32 _34;
	u32 _38;
	u32 _3C;
	u32 _40;
	bool _44;

	void reset(u32);
	void updateCont(u32);
	void update();
	void getMainStickX();
	void getMainStickY();
	void getSubStickX();
	void getSubStickY();
};

#endif // CONTROLLER_H
