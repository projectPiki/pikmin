#ifndef _ZEN_DRAWHURRYUP_H
#define _ZEN_DRAWHURRYUP_H

#include "types.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct DrawHurryUp {

	/**
	 * @brief TODO
	 */
	enum messageTypeFlag {
		// TODO: this
	};

	DrawHurryUp();

	void initPanes();
	void start(messageTypeFlag);
	void startStatus();
	void endStatus();
	void update();
	void draw(Graphics&);

	// unused/inlined:
	~DrawHurryUp();
	void enlargeStatus();
	void brightShotStatus();
	void brightStatus();

	// TODO: members
};

} // namespace zen

#endif
