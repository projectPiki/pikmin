#ifndef _ZEN_DRAWHURRYUP_H
#define _ZEN_DRAWHURRYUP_H

/*
 * @brief TODO
 */
namespace zen {
struct DrawHurryUp {
	DrawHurryUp();
	void initPanes();
	void start(zen::DrawHurryUp::messageTypeFlag);
	void startStatus();
	void endStatus();
	void update();
	void draw(Graphics&);
};
} // namespace zen

#endif
