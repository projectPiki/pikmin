#ifndef _TAI_AMOVE_H
#define _TAI_AMOVE_H

#include "NaviMgr.h"
#include "TAI/Amotion.h"
#include "types.h"

struct Vector3f;

/**
 * @brief TODO
 */
struct TAIAappearKabekui : public TAIAsetMotionSpeed {
public:
	inline TAIAappearKabekui(int nextState, int motionID, f32 motionSpeed, bool p4) // TODO: this is a guess
	    : TAIAsetMotionSpeed(nextState, motionID, motionSpeed)
	{
		_10 = p4;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_10 = TAIAsetMotionSpeed
	bool _10; // _10
};

/**
 * @brief TODO
 */
struct TAIAsetTargetPointWorkObject : public TaiAction {
public:
	inline TAIAsetTargetPointWorkObject(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoTargetPriorityFaceDir : public TAIAreserveMotion {
public:
	TAIAgoTargetPriorityFaceDir(int nextState, int motionIdx)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);          // _08
	virtual bool act(Teki&);            // _10

protected:
	virtual bool checkArrival(Teki&);   // _1C
	virtual f32 getWalkVelocity(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoTargetPiki : public TAIAgoTargetPriorityFaceDir {
public:
	TAIAgoTargetPiki(int nextState, int motionIdx)
	    : TAIAgoTargetPriorityFaceDir(nextState, motionIdx)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		Creature* target = teki.getCreaturePointer(0);
		if (target) {
			if (target->isAlive()) {
				if (teki.getPosition().distance(target->getPosition()) < teki.getParameterF(TPF_VisibleRange)) {
					teki.mTargetPosition.set(target->getPosition());
					return TAIAgoTargetPriorityFaceDir::act(teki);
				}
				// were
				return true;
			}
			// these
			return true;
		}
		// necessary
		return true;
	}

protected:
	virtual bool checkArrival(Teki&) { return false; } // _1C

	// _04     = VTBL
	// _00-_0C = TAIAgoTargetPriorityFaceDir?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoGoalPath : public TAIAgoTargetPriorityFaceDir {
public:
	TAIAgoGoalPath(int nextState, int motionIdx)
	    : TAIAgoTargetPriorityFaceDir(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);        // _08
	virtual bool act(Teki&);          // _10

protected:
	virtual bool checkArrival(Teki&); // _1C

	bool makePath(Teki&);

	// _04     = VTBL
	// _00-_0C = TAIAgoTargetPriorityFaceDir?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsetTargetPointCircleRandom : public TaiAction {
public:
	inline TAIAsetTargetPointCircleRandom(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsetTargetPointCircle : public TaiAction {
public:
	TAIAsetTargetPointCircle(int nextState, f32 p2)
	    : TaiAction(nextState)
	{
		mAngleOffset = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	void setTargetPoint(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	f32 mAngleOffset; // _08
};

/**
 * @brief TODO
 */
struct TAIAgoTarget : public TAIAreserveMotion {
public:
	TAIAgoTarget(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);          // _08
	virtual bool act(Teki&);            // _10

protected:
	virtual f32 getVelocity(Teki& teki) // _1C
	{
		return teki.getParameterF(TPF_WalkVelocity);
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAapproachTargetPriorityFaceDir : public TAIAreserveMotion {
public:
	inline TAIAapproachTargetPriorityFaceDir(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);          // _08
	virtual bool act(Teki&);            // _10

protected:
	virtual f32 getVelocity(Teki& teki) // _1C
	{
		return teki.getParameterF(TPF_WalkVelocity);
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlookAround : public TAIAreserveMotion {
public:
	TAIAlookAround(int nextState, int motionID, int p3, int p4)
	    : TAIAreserveMotion(nextState, motionID)
	{
		_0C = p3;
		_10 = p4;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	void setTargetDirection(Teki&, f32);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	int _0C; // _0C
	int _10; // _10
};

/**
 * @brief TODO
 */
struct TAIAturnToTarget : public TAIAreserveMotion {
public:
	TAIAturnToTarget(int nextState, int leftMotionID, int rightMotionID, bool p4)
	    : TAIAreserveMotion(nextState, leftMotionID)
	{
		mLeftTurnAnimID  = leftMotionID;
		mRightTurnAnimID = rightMotionID;
		_14              = p4;
	}

	virtual void start(Teki&);              // _08
	virtual bool act(Teki&);                // _10

protected:
	virtual f32 getTurnVelocity(Teki& teki) // _1C
	{
		return teki.getParameterF(TPF_TurnVelocity);
	}

	int getTurnMotionIndex(Teki&);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	int mLeftTurnAnimID;  // _0C
	int mRightTurnAnimID; // _10
	bool _14;             // _14
};

/**
 * @brief TODO
 */
struct TAIAstop : public TaiAction {
public:
	TAIAstop(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIArandomWalk : public TAIAreserveMotion {
public:
	inline TAIArandomWalk(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void makeTargetPosition(Teki&);

protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnOccasion : public TAIAreserveMotion {
public:
	TAIAturnOccasion(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnFocusCreature : public TAIAturnToTarget {
public:
	TAIAturnFocusCreature(int nextState, int leftMotionID, int rightMotionID, bool p4)
	    : TAIAturnToTarget(nextState, leftMotionID, rightMotionID, p4)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAturnToTarget?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwait : public TAIAreserveMotion {
public:
	TAIAwait(int nextState, int motionIdx, f32 waitCounterMax)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
		mWaitCounterMax = waitCounterMax;
	}

	virtual void start(Teki&);                // _08
	virtual bool act(Teki&);                  // _10

protected:
	virtual f32 getWaitCounterMax(Teki& teki) // _1C
	{
		return mWaitCounterMax;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	f32 mWaitCounterMax; // _0C
};

/**
 * @brief TODO
 */
struct TAIApatrol : public TAIAturnToTarget {
public:
	TAIApatrol(int, int, int, int, Vector3f*, int, bool);

	virtual void start(Teki&);                     // _08
	virtual bool act(Teki&);                       // _10

protected:
	virtual f32 getTimeout(Teki&) { return 5.0f; } // _20

	void changeStatus(int, Teki&);
	void setTargetPosition(Teki&);

	// _04     = VTBL
	// _00-_18 = TAIAturnToTarget
	Vector3f* _18; // _18
	int _1C;       // _1C
	int _20;       // _20
};

/**
 * @brief TODO
 */
struct TAIAstepBack : public TAIAreserveMotion {
public:
	TAIAstepBack(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);          // _08
	virtual bool act(Teki&);            // _10

protected:
	virtual f32 getVelocity(Teki& teki) // _1C
	{
		return teki.getParameterF(TPF_WalkVelocity);
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnHome : public TAIAturnOccasion {
public:
	TAIAturnHome(int nextState, int motionID, int p3)
	    : TAIAturnOccasion(nextState, motionID)
	{
		_0C = motionID;
		_10 = p3;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAturnOccasion
	int _0C; // _0C
	int _10; // _10
};

/**
 * @brief TODO
 */
struct TAIAgoingHome : public TAIAreserveMotion {
public:
	inline TAIAgoingHome(int nextState, int motionIdx) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoingHomePriorityFaceDir : public TAIAreserveMotion {
	TAIAgoingHomePriorityFaceDir(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingBase : public TaiAction {
	inline TAIAflyingBase(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&);                    // _08
	virtual bool act(Teki&);                      // _10

protected:
	virtual f32 getFlyingStayVelocity(Teki& teki) // _1C
	{
		// nice illusion of choice
		if (teki.getChokeSwitch()) {
			return teki.getParameterF(TPF_WalkVelocity);
		}
		return teki.getParameterF(TPF_WalkVelocity);
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingInTerritory : public TaiAction {
	inline TAIAflyingInTerritory(int nextState, f32 p2) // TODO: this is a guess
	    : TaiAction(nextState)
	{
		mFaceDirAdjust = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void setTargetPosition(Teki&);

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 mFaceDirAdjust;
};

/**
 * @brief TODO
 */
struct TAIAflyingToGoal : public TAIAreserveMotion {
	TAIAflyingToGoal(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);                                                           // _08
	virtual bool act(Teki&);                                                             // _10

protected:
	virtual bool goal(Teki&) { return true; }                                            // _1C
	virtual f32 getVelocity(Teki& teki) { return teki.getParameterF(TPF_WalkVelocity); } // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct FlyingDistance {
public:
	FlyingDistance(f32 p1, f32 p2, f32 p3)
	{
		mDiveAngle = p1;
		mOffset    = p2;
		_08        = p3;
	}

protected:
	// _0C = VTBL
	f32 mDiveAngle; // _00
	f32 mOffset;    // _04
	f32 _08;        // _08

	virtual f32 getOffset(Teki&) { return mOffset; } // _08
};

/**
 * @brief TODO
 */
struct TAIAflyingDistance : public TaiAction, public FlyingDistance {
public:
	TAIAflyingDistance(int nextState, f32 p2, f32 p3, f32 p4)
	    : TaiAction(nextState)
	    , FlyingDistance(p2, p3, p4)
	{
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10

protected:
	virtual f32 getGoalAreaRange(Teki& teki) // _28
	{
		return 0.25f * teki.getParameterF(TPF_RunVelocity);
	}

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_08 = TaiAction
	// _08-_18 = FlyingDistance
};

/**
 * @brief TODO
 */
struct TAIAflyingDistanceInTerritory : public TAIAflyingToGoal, public FlyingDistance {
public:
	TAIAflyingDistanceInTerritory(int nextState, int motionID, f32 p3, f32 p4, f32 p5)
	    : TAIAflyingToGoal(nextState, motionID)
	    , FlyingDistance(p3, p4, p5)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

protected:
	virtual bool goal(Teki&);  // _1C

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_0C = TAIAflyingToGoal
	// _0C-_14 = FlyingDistance
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdescent : public TAIAreserveMotion {
public:
	TAIAdescent(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);                // _08
	virtual bool act(Teki&);                  // _10

protected:
	virtual f32 getFlyingVelocity(Teki& teki) // _1C
	{
		return teki.getParameterF(TPF_WalkVelocity);
	}
	virtual f32 getForceDescentFrame(Teki& teki) // _20
	{
		return 0.5f;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlanding : public TAIAreserveMotion {
public:
	TAIAlanding(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);            // _08
	virtual bool act(Teki&);              // _10

protected:
	virtual void landingEffect(Teki&) { } // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtakeOff : public TAIAreserveMotion {
public:
	TAIAtakeOff(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);       // _08
	virtual bool act(Teki&);         // _10

protected:
	virtual void startFlying(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwatchNavi : public TaiAction {
public:
	TAIAwatchNavi(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) { teki.setCreaturePointer(0, naviMgr->getNavi()); } // _08
	virtual bool act(Teki&) { return true; }                                           // _10

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
