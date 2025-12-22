#ifndef _CPLATE_H
#define _CPLATE_H

#include "ComplexCreature.h"
#include "GlobalGameOptions.h"
#include "Node.h"
#include "Parameters.h"
#include "Traversable.h"
#include "types.h"

struct MapMgr;
struct Piki;
struct SlotChangeListner;

/**
 * @brief TODO
 */
struct CPlate : public Traversable, public Node {
	// These all all pretty unsurprising.
	friend struct Navi;
	friend struct NaviThrowWaitState;
	friend struct NaviDemoSunsetState;
	friend struct ActCrowd;

public:
	/**
	 * @brief TODO
	 *
	 * @note Offsets are relative to CPlate for ease of use.
	 */
	struct Parms : public Parameters {
		Parms()
		    : mStartOffset(this, 30.0f, 0.0f, 100.0f, "p00", "先頭オフセット")         // 'start offset'
		    , mLengthLimit(this, 150.0f, 10.0f, 1000.0f, "p01", "長さリミット")        // 'length limit'
		    , mMaxPosSize(this, 12.0f, 1.0f, 50.0f, "p02", "ポジションの大きさ(最大)") // 'position size (maximum)'
		{
		}

		// _28-_2C = Parameters
		Parm<f32> mStartOffset; // _2C, p00
		Parm<f32> mLengthLimit; // _3C, p01
		Parm<f32> mMaxPosSize;  // _4C, p02
	};

	/**
	 * @brief TODO
	 */
	struct Slot {
		Slot()
		{
			mOccupant.clear();
			mListener = nullptr;
		}

		Vector3f mPosition;           // _00
		Vector3f mOffsetFromCenter;   // _0C
		SmartPtr<Creature> mOccupant; // _18
		SlotChangeListner* mListener; // _1C
	};

	CPlate(MapMgr*);

	virtual void read(RandomAccessStream& input) { mCPlateParms.read(input); } // _48
	virtual void update();                                                     // _4C
	virtual void render(Graphics&);                                            // _50
	// these need to go last to spawn the vtable further down in cPlate.cpp
	virtual Creature* getCreature(int);                             // _08
	virtual int getFirst() { return 0; }                            // _0C
	virtual int getNext(int idx) { return idx + 1; }                // _10
	virtual bool isDone(int idx) { return idx >= mTotalSlotCount; } // _14

	bool canNaviRunFast();
	void init(immut Vector3f&);
	void setPos(immut Vector3f&, f32, immut Vector3f&);
	void setPosGray(immut Vector3f&, f32, immut Vector3f&);
	int getSlot(Creature*, SlotChangeListner*);
	void changeFlower(Piki*);
	void releaseSlot(Creature*, int);
	bool validSlot(int);
	void sortByColor(Piki*);
	void rearrangeSlot(immut Vector3f&, f32, immut Vector3f&);
	void refresh(int, f32);
	void refreshSlot();

	// unused/inlined:
	void setPosNeutral(immut Vector3f&, f32, immut Vector3f&);
	void postUpdate(f32);

protected:
	void swapSlot(int, int);

	// _00 = VTBL 1
	// _08 = VTBL 2
	// _00-_08 = Traversable
	// _08-_28 = Node
	Parms mCPlateParms;               // _28
	Vector3f mPlateOffset;            // _5C, denoted by a markerShape in debug mode
	f32 mPlateLength;                 // _68
	f32 mPlateSize;                   // _6C
	f32 mInnerRadius;                 // _70
	int mTotalSlotCount;              // _74
	u32 mPlatePikiCount;              // _78
	int mUsedSlotCount;               // _7C
	CPlate::Slot* mSlotList;          // _80
	int mSlotListSize;                // _84, max slots
	Vector3f mOriginPosition;         // _88
	Vector3f mPlateCenter;            // _94, denoted by a markerShape in debug mode
	Vector3f mCurrentVelocity;        // _A0
	f32 mDirectionAngle;              // _AC
	Vector3f mDevOffsetTest;          // _B0, unused
	int mHappaCounts[PikiHappaCount]; // _BC, indexed by PikiHappa
	bool _C8;                         // _C8
	bool mIsNeutral;                  // _C9
};

#endif
