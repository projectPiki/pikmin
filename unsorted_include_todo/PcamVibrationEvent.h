#ifndef _PCAMVIBRATIONEVENT_H
#define _PCAMVIBRATIONEVENT_H

/**
 * .obj __vt__18PcamVibrationEvent, weak
 * .4byte __RTTI__18PcamVibrationEvent
 * .4byte 0
 * .4byte setChild__5NNodeFiP5NNode
 * .4byte addChild__5NNodeFP5NNode
 * .4byte addChild__5NNodeFiP5NNode
 * .4byte removeChild__5NNodeFP5NNode
 * .4byte removeChild__5NNodeFi
 * .4byte removeAllChildren__5NNodeFv
 * .4byte reset__9PeveEventFv
 * .4byte update__18PeveVibrationEventFv
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
	virtual void reset();               // _20 (weak)
	virtual void _24() = 0;             // _24
	virtual void isFinished();          // _28 (weak)
	virtual void finish();              // _2C (weak)
	virtual void setEventOption(int);   // _30
	virtual void clearEventOption(int); // _34
	virtual void setEventOptions(int);  // _38
};

struct PeveVibrationEvent {
	virtual void _08() = 0; // _08
	virtual void _0C() = 0; // _0C
	virtual void _10() = 0; // _10
	virtual void _14() = 0; // _14
	virtual void _18() = 0; // _18
	virtual void _1C() = 0; // _1C
	virtual void _20() = 0; // _20
	virtual void update();  // _24
};

/**
 * @brief TODO
 */
struct PcamVibrationEvent : public NNode, public PeveEvent, public PeveVibrationEvent {
};

#endif
