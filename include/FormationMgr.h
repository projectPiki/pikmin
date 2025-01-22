#ifndef _FORMATIONMGR_H
#define _FORMATIONMGR_H

#include "types.h"
#include "Traversable.h"
#include "Vector.h"

struct Graphics;
struct FormArranger;

/**
 * @brief Stripped struct.
 */
struct Rope {
	Rope(); // unused/inlined

	// unused/inlined:
	void move(Vector3f&, Vector3f&, Vector3f&);
	void refresh(Graphics&);
};

/**
 * @brief Stripped struct.
 */
struct Spine {
	Spine(); // unused/inlined

	// unused/inlined:
	void init(Creature*);
	void preMove();
	void postMove();
	void move();
	void refresh(Graphics&);
};

/**
 * @brief TODO
 */
struct FormPoint {
	FormPoint(); // unused/inlined

	Vector3f getPos();

	// TODO: members
};

/**
 * @brief TODO
 */
struct FormationMgr : public Traversable {
	FormationMgr(); // unused/inlined

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14

	Vector3f getLastCentre();
	FormPoint* getFormPoint(Creature*);
	void slide(Creature*, int);
	void exit(Creature*);

	// unused/inlined:
	void add(Vector3f&, Vector3f&);
	int getIndex(Creature*);
	int getFptIndex(FormPoint*);
	void clear();
	void rearrange();
	void setOffset(Vector3f&);
	void setAngOffset(f32);

	// _00     = VTBL
	// _00-_08 = Traversable
	u8 _08[0x4];             // _08, unknown
	f32 _0C;                 // _0C
	Vector3f _10;            // _10
	u8 _1C[0x4];             // _1C, unknown
	Creature** _20;          // _20, maybe Piki**?
	u8 _24[0x8];             // _24, unknown
	int _2C;                 // _2C
	u8 _30[0xC];             // _30, unknown
	FormArranger* mArranger; // _3C
};

/**
 * @brief TODO
 */
struct FormArranger {
	virtual void arrange(FormationMgr*) = 0;              // _08
	virtual f32 getLength(FormationMgr*) { return 0.0f; } // _0C

	// TODO: members
};

/**
 * @brief TODO
 */
struct CircleArranger : public FormArranger {
	virtual void arrange(FormationMgr*); // _08

	// _00-_?? = FormArranger
	// TODO: members
};

/**
 * @brief TODO
 */
struct PyramidArranger : public FormArranger {
	virtual void arrange(FormationMgr*);  // _08
	virtual f32 getLength(FormationMgr*); // _0C

	// _00-_?? = FormArranger
	// TODO: members
};

/**
 * @brief TODO
 */
struct LineArranger : public FormArranger {
	virtual void arrange(FormationMgr*); // _08

	// _00-_?? = FormArranger
	// TODO: members
};

/**
 * @brief TODO
 */
struct WingArranger : public FormArranger {
	virtual void arrange(FormationMgr*); // _08

	// _00-_?? = FormArranger
	// TODO: members
};

#endif
