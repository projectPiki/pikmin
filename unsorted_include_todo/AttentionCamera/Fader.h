#ifndef _ATTENTIONCAMERA_FADER_H
#define _ATTENTIONCAMERA_FADER_H

/**
 * .obj __vt__Q215AttentionCamera5Fader, weak
 * .4byte __RTTI__Q215AttentionCamera5Fader
 * .4byte 0
 * .4byte initFadeIn__Q215AttentionCamera5FaderFv
 * .4byte updateFadeIn__Q215AttentionCamera5FaderFv
 * .4byte drawFadeIn__Q215AttentionCamera5FaderFR8Graphics
 * .4byte initFadeOut__Q215AttentionCamera5FaderFv
 * .4byte updateFadeOut__Q215AttentionCamera5FaderFv
 * .4byte drawFadeOut__Q215AttentionCamera5FaderFR8Graphics
*/

namespace AttentionCamera {
/**
 * @brief TODO
 */
struct Fader {
	virtual void initFadeIn();            // _08
	virtual void updateFadeIn();          // _0C
	virtual void drawFadeIn(Graphics &);  // _10
	virtual void initFadeOut();           // _14
	virtual void updateFadeOut();         // _18
	virtual void drawFadeOut(Graphics &); // _1C

};
} // namespace AttentionCamera

#endif
