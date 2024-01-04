#ifndef _PEVEEVENT_H
#define _PEVEEVENT_H

/**
 * .obj __vt__9PeveEvent, weak
 * .4byte __RTTI__9PeveEvent
 * .4byte 0
 * .4byte setChild__5NNodeFiP5NNode
 * .4byte addChild__5NNodeFP5NNode
 * .4byte addChild__5NNodeFiP5NNode
 * .4byte removeChild__5NNodeFP5NNode
 * .4byte removeChild__5NNodeFi
 * .4byte removeAllChildren__5NNodeFv
 * .4byte reset__9PeveEventFv
 * .4byte update__9PeveEventFv
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

/**
 * @brief TODO
 */
struct PeveEvent : public NNode {
	virtual void reset();               // _20 (weak)
	virtual void update();              // _24 (weak)
	virtual void isFinished();          // _28 (weak)
	virtual void finish();              // _2C (weak)
	virtual void setEventOption(int);   // _30
	virtual void clearEventOption(int); // _34
	virtual void setEventOptions(int);  // _38
};

#endif
