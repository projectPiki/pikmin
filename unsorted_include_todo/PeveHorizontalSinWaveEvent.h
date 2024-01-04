#ifndef _PEVEHORIZONTALSINWAVEEVENT_H
#define _PEVEHORIZONTALSINWAVEEVENT_H

/**
 * .obj __vt__26PeveHorizontalSinWaveEvent, global
 * .4byte __RTTI__26PeveHorizontalSinWaveEvent
 * .4byte 0
 * .4byte setChild__5NNodeFiP5NNode
 * .4byte addChild__5NNodeFP5NNode
 * .4byte addChild__5NNodeFiP5NNode
 * .4byte removeChild__5NNodeFP5NNode
 * .4byte removeChild__5NNodeFi
 * .4byte removeAllChildren__5NNodeFv
 * .4byte reset__26PeveHorizontalSinWaveEventFv
 * .4byte update__26PeveHorizontalSinWaveEventFv
 * .4byte isFinished__9PeveEventFv
 * .4byte finish__9PeveEventFv
 * .4byte setEventOption__9PeveEventFi
 * .4byte clearEventOption__9PeveEventFi
 * .4byte setEventOptions__9PeveEventFi
 */

struct NNode {
	virtual void setChild(int, NNode*); // _08
	virtual void addChild(NNode*);      // _0C
	virtual void addChild(int, NNode*); // _10
	virtual void removeChild(NNode*);   // _14
	virtual void removeChild(int);      // _18
	virtual void removeAllChildren();   // _1C
};

struct PeveEvent {
	virtual void _08() = 0;             // _08
	virtual void _0C() = 0;             // _0C
	virtual void _10() = 0;             // _10
	virtual void _14() = 0;             // _14
	virtual void _18() = 0;             // _18
	virtual void _1C() = 0;             // _1C
	virtual void reset();               // _20
	virtual void update();              // _24
	virtual void isFinished();          // _28 (weak)
	virtual void finish();              // _2C (weak)
	virtual void setEventOption(int);   // _30
	virtual void clearEventOption(int); // _34
	virtual void setEventOptions(int);  // _38
};

/**
 * @brief TODO
 */
struct PeveHorizontalSinWaveEvent : public NNode, public PeveEvent {
	virtual void reset();  // _20
	virtual void update(); // _24
};

#endif
