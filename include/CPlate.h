#ifndef _CPLATE_H
#define _CPLATE_H

#include "types.h"
#include "Traversable.h"
#include "Node.h"

struct MapMgr;
struct Piki;
struct SlotChangeListner;

/**
 * @brief TODO
 */
struct CPlate : public Traversable, public Node {

	/**
	 * @brief TODO
	 */
	struct Slot {
		Slot();

		// TODO: members
	};

	CPlate(MapMgr*);

	virtual Creature* getCreature(int);     // _08
	virtual int getFirst();                 // _0C
	virtual int getNext(int);               // _10
	virtual bool isDone(int);               // _14
	virtual void read(RandomAccessStream&); // _48
	virtual void update();                  // _4C
	virtual void render(Graphics&);         // _50

	bool canNaviRunFast();
	void init(Vector3f&);
	void setPos(Vector3f&, f32, Vector3f&);
	void setPosGray(Vector3f&, f32, Vector3f&);
	void getSlot(Creature*, SlotChangeListner*);
	void changeFlower(Piki*);
	void releaseSlot(Creature*, int);
	void validSlot(int);
	void sortByColor(Piki*);
	void rearrangeSlot(Vector3f&, f32, Vector3f&);
	void refresh(int, f32);
	void refreshSlot();

	// unused/inlined:
	void setPosNeutral(Vector3f&, f32, Vector3f&);
	void swapSlot(int, int);
	void postUpdate(f32);

	// _00 = VTBL 1
	// _08 = VTBL 2
	// _00-_08 = Traversable
	// _08-_28 = Node
	// TODO: members
};

#endif
