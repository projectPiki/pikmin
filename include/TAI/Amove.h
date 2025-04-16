#ifndef _TAI_AMOVE_H
#define _TAI_AMOVE_H

#include "types.h"
#include "TAI/Amotion.h"

struct Vector3f;

/**
 * @brief TODO
 */
struct TAIAappearKabekui : public TAIAsetMotionSpeed {
	inline TAIAappearKabekui(int nextState, int motionID, f32 motionSpeed, u8 p4) // TODO: this is a guess
	    : TAIAsetMotionSpeed(nextState, motionID, motionSpeed)
	{
		_10 = p4;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_10 = TAIAsetMotionSpeed
	u8 _10; // _10
};

/**
 * @brief TODO
 */
struct TAIAsetTargetPointWorkObject : public TaiAction {
	inline TAIAsetTargetPointWorkObject(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoTargetPriorityFaceDir : public TAIAreserveMotion {
	TAIAgoTargetPriorityFaceDir(int nextState, int motionIdx)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);          // _08
	virtual bool act(Teki&);            // _10
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
	virtual bool checkArrival(Teki&) { return false; } // _1C

	// _04     = VTBL
	// _00-_0C = TAIAgoTargetPriorityFaceDir?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoGoalPath : public TAIAgoTargetPriorityFaceDir {
	TAIAgoGoalPath(int nextState, int motionIdx)
	    : TAIAgoTargetPriorityFaceDir(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);        // _08
	virtual bool act(Teki&);          // _10
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
	inline TAIAsetTargetPointCircleRandom(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsetTargetPointCircle : public TaiAction {
	inline TAIAsetTargetPointCircle() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void setTargetPoint(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoTarget : public TAIAreserveMotion {
	inline TAIAgoTarget() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual f32 getVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAapproachTargetPriorityFaceDir : public TAIAreserveMotion {
	inline TAIAapproachTargetPriorityFaceDir(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual f32 getVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlookAround : public TAIAreserveMotion {
	inline TAIAlookAround() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// unused/inlined:
	void setTargetDirection(Teki&, f32);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnToTarget : public TAIAreserveMotion {
	inline TAIAturnToTarget() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);          // _08
	virtual bool act(Teki&);            // _10
	virtual f32 getTurnVelocity(Teki&); // _1C

	// unused/inlined:
	int getTurnMotionIndex(Teki&);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	int mLeftTurnAnimID;  // _0C
	int mRightTurnAnimID; // _10
};

/**
 * @brief TODO
 */
struct TAIAstop : public TaiAction {
	TAIAstop(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIArandomWalk : public TAIAreserveMotion {
	inline TAIArandomWalk(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void makeTargetPosition(Teki&);

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnOccasion : public TAIAreserveMotion {
	inline TAIAturnOccasion() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnFocusCreature : public TAIAturnToTarget {
	inline TAIAturnFocusCreature() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAturnToTarget?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwait : public TAIAreserveMotion {
	TAIAwait(int nextState, int motionIdx, f32 p3)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
		_0C = p3;
	}

	virtual void start(Teki&);            // _08
	virtual bool act(Teki&);              // _10
	virtual f32 getWaitCounterMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	f32 _0C; // _0C
};

/**
 * @brief TODO
 */
struct TAIApatrol : public TAIAturnToTarget {
	TAIApatrol(int, int, int, int, Vector3f*, int, bool);

	virtual void start(Teki&);     // _08
	virtual bool act(Teki&);       // _10
	virtual f32 getTimeout(Teki&); // _20

	// unused/inlined:
	void changeStatus(int, Teki&);
	void setTargetPosition(Teki&);

	// _04     = VTBL
	// _00-_0C = TAIAturnToTarget?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstepBack : public TAIAreserveMotion {
	inline TAIAstepBack() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual f32 getVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAturnHome : public TAIAturnOccasion {
	inline TAIAturnHome() { }

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAturnOccasion?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoingHome : public TAIAreserveMotion {
	inline TAIAgoingHome() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoingHomePriorityFaceDir : public TAIAreserveMotion {
	inline TAIAgoingHomePriorityFaceDir() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingBase : public TaiAction {
	inline TAIAflyingBase() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&);                // _08
	virtual bool act(Teki&);                  // _10
	virtual f32 getFlyingStayVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingInTerritory : public TaiAction {
	inline TAIAflyingInTerritory() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// unused/inlined:
	void setTargetPosition(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingToGoal : public TAIAreserveMotion {
	inline TAIAflyingToGoal() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);      // _08
	virtual bool act(Teki&);        // _10
	virtual bool goal(Teki&);       // _1C
	virtual f32 getVelocity(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct FlyingDistance {

	// _0C = VTBL
	f32 _00;     // _00
	f32 mOffset; // _04
	f32 _08;     // _08

	virtual f32 getOffset(Teki&); // _08
};

/**
 * @brief TODO
 */
struct TAIAflyingDistance : public TaiAction, public FlyingDistance {
	inline TAIAflyingDistance() // TODO: this is a guess
	    : TaiAction(12)
	{
	}

	virtual void start(Teki&);           // _08
	virtual bool act(Teki&);             // _10
	virtual f32 getGoalAreaRange(Teki&); // _28

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_08 = TaiAction
	// _08-_18 = FlyingDistance
};

/**
 * @brief TODO
 */
struct TAIAflyingDistanceInTerritory : public TAIAflyingToGoal, public FlyingDistance {
	inline TAIAflyingDistanceInTerritory() // TODO: this is a guess
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10
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
	inline TAIAdescent() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10
	virtual f32 getFlyingVelocity(Teki&);    // _1C
	virtual f32 getForceDescentFrame(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlanding : public TAIAreserveMotion {
	inline TAIAlanding() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);         // _08
	virtual bool act(Teki&);           // _10
	virtual void landingEffect(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtakeOff : public TAIAreserveMotion {
	inline TAIAtakeOff() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&);       // _08
	virtual bool act(Teki&);         // _10
	virtual void startFlying(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwatchNavi : public TaiAction {
	inline TAIAwatchNavi() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

#endif
