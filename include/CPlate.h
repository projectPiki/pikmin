#ifndef _CPLATE_H
#define _CPLATE_H

#include "types.h"
#include "Traversable.h"
#include "Parameters.h"
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

		Vector3f mPosition; // _00
		float _0C;          // _0C
		float _10;          // _10
		float _14;          // _14
		u32 _18;            // _18
		u32 _1C;            // _1C
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
	u32 _28;                 // _28
	Parm<f32> _2C;           // _2C
	Parm<f32> _3C;           // _3C
	Parm<f32> _4C;           // _4C
	u32 _54;                 // _54
	f32 _58;                 // _58
	Vector3f _5C;            // _5C, denoted by a markerShape in debug mode
	f32 _68;                 // _68
	f32 _6C;                 // _6C
	f32 _70;                 // _70
	u32 _74;                 // _74
	u32 _78;                 // _78
	u32 _7C;                 // _7C
	CPlate::Slot* mSlotList; // _80
	u32 mSlotCount;          // _84
	f32 _88;                 // _88
	f32 _8C;                 // _8C
	f32 _90;                 // _90
	Vector3f _94;            // _94, denoted by a markerShape in debug mode
	f32 _A0;                 // _A0
	f32 _A4;                 // _A4
	f32 _A8;                 // _A8
	f32 _AC;                 // _AC
	f32 _B0;                 // _B0
	f32 _B4;                 // _B4
	f32 _B8;                 // _B8
	u32 _BC;                 // _BC
	u32 _C0;                 // _C0
	u32 _C4;                 // _C4
	u8 _C8;                  // _C8
	u8 _C9;                  // _C9
};

#endif
