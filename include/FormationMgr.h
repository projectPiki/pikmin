#ifndef _FORMATIONMGR_H
#define _FORMATIONMGR_H

#include "types.h"
#include "Traversable.h"
#include "Vector.h"
#include "Colour.h"
#include "ComplexCreature.h"
#include "Creature.h"

struct Graphics;
struct FormArranger;
struct FormationMgr;

/**
 * @brief Stripped struct.
 *
 * @note Size: 0x40.
 */
struct Rope {
	Rope(); // unused/inlined

	// unused/inlined:
	void move(Vector3f&, Vector3f&, Vector3f&);
	void refresh(Graphics&);

	Vector3f _UNUSED00; // _00
	Vector3f mVelocity; // _0C
	Vector3f mPosition; // _18
	Vector3f _24;       // _24
	f32 mRadius;        // _30
	u8 _34[0x4];        // _34, unknown
	Rope* mPrevLink;    // _38
	Rope* mNextLink;    // _3C
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

	u8 _00[0x4];                        // _00, unknown
	int mLinkCount;                     // _04
	Rope* mRope;                        // _08
	SmartPtr<Creature> mTargetCreature; // _0C
	Vector3f _UNUSED10;                 // _10
};

/**
 * @brief TODO
 */
struct FormPoint {
	FormPoint(); // unused/inlined

	Vector3f getPos();

	// DLL inlines to do:
	void reset()
	{
		if (!mOwner.isNull()) {
			mOwner.clear();
		}
	}

	void setMgr(FormationMgr* mgr) { mFormMgr = mgr; }
	Creature* getOwner() { return mOwner.getPtr(); }

	bool isFree() { return mOwner.isNull(); }
	void setOwner(Creature* owner) { mOwner.set(owner); }

	Colour mDebugColor;        // _00
	Vector3f mOffset;          // _04
	SmartPtr<Creature> mOwner; // _10
	FormationMgr* mFormMgr;    // _14
	Vector3f mLocalPosition;   // _18
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
	f32 mAngOffset;           // _08
	f32 mRotationAngle;       // _0C
	Vector3f mCenterPosition; // _10
	FormPoint* mFormPoints;   // _1C
	Creature** mFormMembers;  // _20
	int mFormPointCount;      // _24
	int mMax;                 // _28, total slots
	int mCount;               // _2C, total used slots
	Vector3f mOffset;         // _30
	FormArranger* mArranger;  // _3C
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
