#ifndef _PEVEINTERPOLATIONEVENT_H
#define _PEVEINTERPOLATIONEVENT_H

/**
 * .obj __vt__22PeveInterpolationEvent, global
 * .4byte __RTTI__22PeveInterpolationEvent
 * .4byte 0
 * .4byte setChild__5NNodeFiP5NNode
 * .4byte addChild__5NNodeFP5NNode
 * .4byte addChild__5NNodeFiP5NNode
 * .4byte removeChild__5NNodeFP5NNode
 * .4byte removeChild__5NNodeFi
 * .4byte removeAllChildren__5NNodeFv
 * .4byte reset__22PeveInterpolationEventFv
 * .4byte update__22PeveInterpolationEventFv
 * .4byte isFinished__22PeveInterpolationEventFv
 * .4byte finish__9PeveEventFv
 * .4byte setEventOption__9PeveEventFi
 * .4byte clearEventOption__9PeveEventFi
 * .4byte setEventOptions__9PeveEventFi
 * .4byte setStartTime__22PeveInterpolationEventFf
 * .4byte getStartTime__22PeveInterpolationEventFv
 * .4byte setPeriod__22PeveInterpolationEventFf
 * .4byte getPeriod__22PeveInterpolationEventFv
 * .4byte setTime__22PeveInterpolationEventFf
 * .4byte getTime__22PeveInterpolationEventFv
 * .4byte getEndTime__22PeveInterpolationEventFv
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
	virtual void isFinished();          // _28
	virtual void finish();              // _2C (weak)
	virtual void setEventOption(int);   // _30
	virtual void clearEventOption(int); // _34
	virtual void setEventOptions(int);  // _38
};

/**
 * @brief TODO
 */
struct PeveInterpolationEvent : public NNode, public PeveEvent {
	virtual void reset();             // _20
	virtual void update();            // _24
	virtual void isFinished();        // _28
	virtual void setStartTime(float); // _3C
	virtual void getStartTime();      // _40
	virtual void setPeriod(float);    // _44
	virtual void getPeriod();         // _48
	virtual void setTime(float);      // _4C
	virtual void getTime();           // _50
	virtual void getEndTime();        // _54
};

#endif
