#ifndef _ZEN_DRAWHURRYUP_H
#define _ZEN_DRAWHURRYUP_H

#include "types.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x154.
 */
struct DrawHurryUp {

	/**
	 * @brief TODO
	 */
	enum messageTypeFlag {
		MesgType1 = 1,
		// TODO: this
	};

	DrawHurryUp();

	void initPanes();
	void start(messageTypeFlag);
	void startStatus();
	bool endStatus();
	bool update();
	void draw(Graphics&);

	// unused/inlined:
	~DrawHurryUp();
	void enlargeStatus();
	void brightShotStatus();
	void brightStatus();

	u8 _00[0x154]; // _00, unknown
};

} // namespace zen

extern zen::DrawHurryUp* hurryupWindow;

#endif
