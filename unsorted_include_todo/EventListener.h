#ifndef _EVENTLISTENER_H
#define _EVENTLISTENER_H

/**
 * .obj __vt__13EventListener, weak
 * .4byte __RTTI__13EventListener
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte gotEvent__13EventListenerFR5Event
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

/**
 * @brief TODO
 */
struct EventListener : public ANode, public CoreNode {
	virtual void gotEvent(Event &);  // _10 (weak)

};

#endif
