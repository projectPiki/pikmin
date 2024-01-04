#ifndef _ZEN_ALPHAWIPE_H
#define _ZEN_ALPHAWIPE_H

/*
 * @brief TODO
 */
namespace zen {
struct AlphaWipe {
	AlphaWipe();
	void update();
	void draw(Graphics&);
	void start(float, float, zen::AlphaWipe::typeFlag);
};
} // namespace zen

#endif
