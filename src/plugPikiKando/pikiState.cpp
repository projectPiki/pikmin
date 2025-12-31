#include "PikiState.h"
#include "AIConstant.h"
#include "BombItem.h"
#include "CPlate.h"
#include "DebugLog.h"
#include "GameStat.h"
#include "Interactions.h"
#include "Interface.h"
#include "ItemMgr.h"
#include "MapCode.h"
#include "MemStat.h"
#include "MizuItem.h"
#include "MoviePlayer.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "Pellet.h"
#include "PikiAI.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "UtilityKando.h"
#include "WorkObject.h"
#include "gameflow.h"
#include "teki.h"
#include "zen/ogTutorial.h"

namespace {
/**
 * @brief Sub-phases for the "called attention" reaction.
 *
 * These values drive a short, animation-keyed sequence where a Piki notices the
 * player, turns to face them, briefly waits, then returns to normal AI.
 */
enum LookAtSubstate {
	LAS_Delay     = 0, ///< Randomized delay before starting the notice animation.
	LAS_Noticing  = 1, ///< Playing the notice animation; waits for key events.
	LAS_Turning   = 2, ///< Turning to face the player (rotation is stepped).
	LAS_Waiting   = 3, ///< Briefly holds facing the player.
	LAS_Returning = 4, ///< Waits out the return timer, then exits to normal.
};

/**
 * @brief Sub-phases for nectar drinking.
 */
enum AbsorbSubstate {
	AS_BeforeDrinkLoop = 0, ///< Started the animation, not yet in the loop window.
	AS_Drinking        = 1, ///< In the loop window; triggers the nectar interaction.
	AS_Finishing       = 2, ///< Nectar is gone; fast-forward to animation completion.
};

/**
 * @brief Sub-phases for drowning (struggle then sink).
 */
enum DrownSubstate {
	DS_PreStruggle = 0, ///< Waiting for the initial water-entry animation to finish.
	DS_Struggle    = 1, ///< Repeats the struggle animation for a random duration.
	DS_Sinking     = 2, ///< Plays the sinking animation; kills the Piki on finish.
};

/**
 * @brief Sub-behaviors for Puffstool-infected Pikmin.
 */
enum KinokoSubstate {
	KS_Boid   = 0, ///< Wander in a boid-like clump.
	KS_Attack = 1, ///< Attack behavior (target-driven).
};

/**
 * @brief Sub-phases for falling recovery.
 */
enum FallSubstate {
	FS_Falling = 0, ///< Airborne fall; waits for a bounce/impact.
	FS_Landed  = 1, ///< Plays the landing stumble animation.
	FS_GetUp   = 2, ///< Plays the recovery/get-up animation.
};

/**
 * @brief Flick reaction phases.
 *
 * Used for the short "hit away" reaction (typically from enemies/impacts).
 */
enum FlickSubstate {
	FLS_FlyingBack = 0, ///< Airborne knockback.
	FLS_Landing    = 1, ///< First ground impact / landing.
	FLS_Downed     = 2, ///< Brief downed/stunned pose.
	FLS_GettingUp  = 3, ///< Recovery back to normal.
};

/**
 * @brief Long knockback flight phases.
 *
 * Similar to flick, but used for longer toss/launch trajectories.
 */
enum FlownSubstate {
	FNS_Airborne  = 0, ///< Extended airborne travel.
	FNS_Landing   = 1, ///< First ground impact / landing.
	FNS_Downed    = 2, ///< Brief downed/stunned pose.
	FNS_GettingUp = 3, ///< Recovery back to normal.
};

/**
 * @brief Sub-phases for cliff/ledge recovery.
 */
enum CliffSubstate {
	CS_SlideStart  = 0, ///< Starts slipping on the ledge.
	CS_EdgeShuffle = 1, ///< Shuffles at the edge (may transition into hang/fall).
	CS_Hanging     = 2, ///< Hanging animation loops before falling.
	CS_FallAnim    = 3, ///< Explicit fall animation started from the ledge.
};

/**
 * @brief Phases for ship-part gazing/cheering behavior.
 */
enum EmotionGazePhase {
	EGP_None        = 0, ///< Not in a gaze sequence.
	EGP_Gazing      = 1, ///< Looking at the ship part (alive).
	EGP_HoldLastPos = 2, ///< Ship part vanished; keep looking at last position for a short time.
	EGP_Done        = 3, ///< Finished; waits for animation to end/transition.
};
} // namespace

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(46)

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pikiState")

/**
 * @brief Registers all Piki state handlers.
 */
void PikiStateMachine::init(Piki* piki)
{
	memStat->start("pikistate");
	create(PIKISTATE_Count);

	registerState(new PikiNormalState());
	registerState(new PikiFlickState());
	registerState(new PikiFlownState());
	registerState(new PikiEmitState());
	registerState(new PikiFallState());
	registerState(new PikiCliffState());
	registerState(new PikiLookAtState());
	registerState(new PikiBulletState());
	registerState(new PikiBubbleState());
	registerState(new PikiFiredState());
	registerState(new PikiSwallowedState());
	registerState(new PikiHangedState());
	registerState(new PikiWaterHangedState());
	registerState(new PikiGoHangState());
	registerState(new PikiFlyingState());
	registerState(new PikiGrowState());
	registerState(new PikiGrowupState());
	registerState(new PikiBuryState());
	registerState(new PikiWaveState());
	registerState(new PikiPushState());
	registerState(new PikiPushPikiState());
	registerState(new PikiNukareState());
	registerState(new PikiNukareWaitState());
	registerState(new PikiAutoNukiState());
	registerState(new PikiPressedState());
	registerState(new PikiAbsorbState());
	registerState(new PikiDyingState());
	registerState(new PikiDeadState());
	registerState(new PikiKinokoState());
	registerState(new PikiDrownState());
	registerState(new PikiEmotionState());
	registerState(new PikiKinokoChangeState());
	registerState(new PikiFallMeckState());

	memStat->end("pikistate");
}

/**
 * @brief Debug: prints state name and any state-specific fields.
 */
void PikiState::dump()
{
	PRINT("*** PikiState (%s)\n", mName);
	doDump();
}

/**
 * @brief Debug: optional state-specific dump payload.
 */
void PikiState::doDump()
{
}

/**
 * @brief Central transition hook for special-case state behavior.
 */
void PikiStateMachine::transit(Piki* piki, int stateID)
{
	if (getCurrID(piki) == PIKISTATE_Grow) {
		// just need something to spawn this properly
		(getCurrID(piki) == PIKISTATE_Grow);
	}
	StateMachine::transit(piki, stateID);
}

/**
 * @brief Default transition implementation.
 */
void PikiState::transit(Piki* piki, int stateID)
{
	AState::transit(piki, stateID);
}

/**
 * @brief Constructs the "look at" (called attention) state.
 */
PikiLookAtState::PikiLookAtState()
    : PikiState(PIKISTATE_LookAt, "LOOKAT")
{
}

/**
 * @brief Enter the called-attention reaction.
 */
void PikiLookAtState::init(Piki* piki)
{
	mTimer = (0.3f * gsys->getRand(1.0f));
	mState = LAS_Delay;
	SeSystem::playPlayerSe(SE_PIKI_CALLED);
	seSystem->playPikiSound(SEF_PIKI_CALLED, piki->mSRT.t);
	piki->endStickObject();
	piki->endStick();
}

/**
 * @brief Keeps the Piki focused on the player until it can resume normal AI.
 */
void PikiLookAtState::exec(Piki* piki)
{
	Vector3f dir = piki->mSRT.t - piki->mNavi->mSRT.t;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.x = piki->mVelocity.z = 0.0f;
	piki->mFaceDirection                  = roundAng(angDist(atan2f(dir.x, dir.z), piki->mFaceDirection) * 0.1f + piki->mFaceDirection);

	// Animation-driven reaction: delay -> notice -> turn -> wait -> return.
	switch (mState) {
	case LAS_Delay:
		// Randomized delay before starting the notice animation.
		mTimer -= gsys->getFrameTime();
		if (mTimer < 0.0f) {
			mTimer = 0.0f;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Kizuku, piki), PaniMotionInfo(PIKIANIM_Kizuku));
			mState = LAS_Noticing;
		}
		break;

	case LAS_Noticing:
		// Wait for animation key events to advance (turn/wait/finish).
		break;

	case LAS_Turning:
		// Step-turn toward the player.
		piki->mFaceDirection += mRotationStep;
		piki->mSRT.r.set(0.0f, mRotationStep, 0.0f);
		break;

	case LAS_Waiting:
		// Hold position/facing; KEY_Finished will move to LAS_Returning.
		break;

	default:
		// Return timer: bail immediately if stuck to something, otherwise exit when it elapses.
		mTimer -= gsys->getFrameTime();
		if (piki->mStickTarget) {
			piki->mFaceDirection = roundAng(piki->mFaceDirection + PI);
			transit(piki, PIKISTATE_Normal);
			return;
		}

		if (mTimer < 0.0f) {
			mTimer               = 0.0f;
			piki->mFaceDirection = roundAng(piki->mFaceDirection + PI);
			transit(piki, PIKISTATE_Normal);
		}
		break;
	}
}

/**
 * @brief Restores player-following behavior after the reaction completes.
 */
void PikiLookAtState::cleanup(Piki* piki)
{
	piki->changeMode(PikiMode::FormationMode, piki->mNavi);
}

/**
 * @brief Advances reaction substate based on animation events.
 */
void PikiLookAtState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		// Compute a smooth multi-frame turn toward the player.
		mState        = LAS_Turning;
		Vector3f dir  = piki->mNavi->mSRT.t - piki->mSRT.t;
		mRotationStep = angDist(atan2f(dir.x, dir.z), piki->mFaceDirection) / 7.0f;
		break;

	case KEY_Action1:
		// Enter a short wait after turning.
		mState = LAS_Waiting;
		break;

	case KEY_Finished:
		// Begin return countdown; state exits when the timer elapses.
		mState = LAS_Returning;
		break;
	}
}

/**
 * @brief Constructs the default active behavior state.
 */
PikiNormalState::PikiNormalState()
    : PikiState(PIKISTATE_Normal, "NORMAL")
{
}

/**
 * @brief Enter normal AI (reset per-state scratch values).
 */
void PikiNormalState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	_UNUSED10 = 0;
	_UNUSED14 = 0.0f;
	_UNUSED1C = C_PIKI_PROP(piki).mUnusedDynWallPushTime();
	mPushPiki = 0;
}

/**
 * @brief Re-initializes the normal state after an interruption.
 */
void PikiNormalState::restart(Piki* piki)
{
	init(piki);
}

/**
 * @brief Ensures dead Pikis promptly stop normal behavior.
 */
void PikiNormalState::exec(Piki* piki)
{
	if (!piki->isAlive()) {
		transit(piki, PIKISTATE_Dead);
	}
}

/**
 * @brief Normal state has no explicit cleanup.
 */
void PikiNormalState::cleanup(Piki* piki)
{
}

/**
 * @brief Wall contacts are handled elsewhere; keep state stable.
 */
void PikiNormalState::procWallMsg(Piki*, MsgWall*)
{
}

/**
 * @brief Clears variables.
 */
void PikiNormalState::procOffWallMsg(Piki*, MsgOffWall*)
{
	_UNUSED10 = 0;
	_UNUSED14 = 0.0f;
}

/**
 * @brief Routes simple environment interactions while in default AI.
 */
void PikiNormalState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (!piki->isKinoko()) {
		Creature* collider = msg->mEvent.mCollider;
		int type           = collider->mObjType;
		mPushPiki          = 0;
		if (!piki->isDamaged() && piki->mMode != PikiMode::TransportMode) {
			// Only handle a few special collisions in Normal; everything else stays AI-driven.
			switch (type) {
			case OBJTYPE_Water:
				// Nectar puddles are modeled as water; non-flower Pikmin can drink to grow.
				if (piki->mHappa != Flower) {
					piki->changeMode(PikiMode::FreeMode, piki->mNavi);
					piki->mCurrNectar = collider;
					transit(piki, PIKISTATE_Absorb);
				}
				break;
			case OBJTYPE_Piki:
				// Remember a nearby pushing Pikmin so we can be shoved coherently.
				if (static_cast<Piki*>(collider)->getState() == PIKISTATE_Push) {
					mPushPiki = static_cast<Piki*>(collider);
				}
				break;
			}
		}
	}
}

/**
 * @brief Constructs the nectar-drinking state.
 */
PikiAbsorbState::PikiAbsorbState()
    : PikiState(PIKISTATE_Absorb, "ABSORB")
{
}

/**
 * @brief Starts the drink animation and locks onto the nectar object.
 */
void PikiAbsorbState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Mizunomi, piki), PaniMotionInfo(PIKIANIM_Mizunomi));
	mState             = AS_BeforeDrinkLoop;
	mNectar            = piki->mCurrNectar;
	mHasAbsorbedNectar = false;
	piki->turnTo(mNectar->mSRT.t);
}

/**
 * @brief Performs the drink interaction during the animation's loop window.
 */
void PikiAbsorbState::exec(Piki* piki)
{
	piki->mVelocity.x = piki->mVelocity.z = 0.0f;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	// Nectar interaction is only applied during the animation's loop window.
	switch (mState) {
	case AS_Drinking:
		if (mNectar->isAlive()) {
			MsgUser msg(0);
			MizuItem* nectar           = static_cast<MizuItem*>(mNectar);
			nectar->mCollidingCreature = piki;
			C_SAI(nectar)->procMsg(nectar, &msg);
		}

		mHasAbsorbedNectar = true;
		break;
	}

	if (piki->getUpperMotionIndex() != PIKIANIM_Mizunomi) {
		transit(piki, PIKISTATE_Normal);
		ERROR("mizunomi err!\n");
	}
}

/**
 * @brief Drives the drink state machine using animation key events.
 */
void PikiAbsorbState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopStart:
		// Start applying the drink interaction each frame during the loop.
		if (mState != AS_Drinking) {
			seSystem->playPikiSound(SEF_PIKI_DRINK, piki->mSRT.t);
		}
		mState = AS_Drinking;
		break;
	case KEY_LoopEnd:
		// If the nectar is gone, cut the loop short and finish the animation.
		if (!mNectar->isAlive()) {
			piki->mPikiAnimMgr.finishMotion(piki);
			mState = AS_Finishing;
		}
		break;
	case KEY_Finished:
		// Grow up only if we actually drank; otherwise return to normal.
		if (mHasAbsorbedNectar) {
			transit(piki, PIKISTATE_GrowUp);
		} else {
			transit(piki, PIKISTATE_Normal);
		}
		break;
	}
}

/**
 * @brief No cleanup required; transition target owns follow-up behavior.
 */
void PikiAbsorbState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the drowning state.
 */
PikiDrownState::PikiDrownState()
    : PikiState(PIKISTATE_Drown, "DROWN")
{
}

/**
 * @brief Begins drowning; cancels incompatible hazards/actions.
 */
void PikiDrownState::init(Piki* piki)
{
	if (piki->mFiredState != 0) {
		piki->endFire();
	}

	if (piki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() == PIKIANIM_TYakusui) {
		mState = DS_PreStruggle;
	} else {
		mState = DS_Struggle;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
	}

	mStruggleDuration = int(2.0f * gsys->getRand(1.0f)) + 6;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_UNUSED14 = int((2.0f * gsys->getRand(1.0f)));
	if (piki->isHolding()) {
		InteractRelease release(piki, 1.0f);
		piki->getHoldCreature()->stimulate(release);
	}

	seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mSRT.t);
	mOutOfWaterFrames = 0;

	// we already did this, but sure
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mActiveAction->abandon(nullptr);
	if (piki->isStickTo()) {
		piki->endStickObject();
		piki->endStick();
	}

	mIsBeingWhistled = false;
	STACK_PAD_TERNARY(mIsBeingWhistled, 1);
}

/**
 * @brief Allows whistle-driven escape velocity while drowning.
 */
void PikiDrownState::exec(Piki* piki)
{
	if (mState != 2 && piki->mInWaterTimer == 0) {
		mOutOfWaterFrames++;
		if (mOutOfWaterFrames > 1) {
			piki->mSRT.t.y += 20.0f;
			Vector3f vel(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
			vel.multiply(80.0f);
			piki->mVelocity = vel;
			if (piki->isKinoko()) {
				transit(piki, PIKISTATE_Kinoko);
			} else {
				piki->mEmotion = PikiEmotion::ShookDry;
				transit(piki, PIKISTATE_Emotion);
			}

			return;
		}
	} else {
		mOutOfWaterFrames = 0;
	}

	if (mState == DS_Struggle) {
		Vector3f dir = piki->mNavi->mSRT.t - piki->mSRT.t;
		dir.normalise();
		mEscapeVelocity = piki->getSpeed(0.5f) * dir;
	} else {
		mEscapeVelocity.set(0.0f, 0.0f, 0.0f);
	}

	if (!mIsBeingWhistled || piki->isKinoko()) {
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	Vector3f velOffset = mEscapeVelocity - piki->mTargetVelocity;
	f32 diff           = velOffset.normalise();

	f32 speed = 15.0f;
	if (mIsBeingWhistled) {
		speed *= 2.0f;
	}

	f32 frame = gsys->getFrameTime();
	if (diff > speed * frame) {
		piki->mTargetVelocity = piki->mTargetVelocity + speed * velOffset * frame;
	} else {
		piki->mTargetVelocity = piki->mTargetVelocity + velOffset * frame;
	}

	piki->mVelocity = piki->mTargetVelocity;
}

/**
 * @brief No explicit cleanup; follow-up state handles recovery/death.
 */
void PikiDrownState::cleanup(Piki* piki)
{
}

/**
 * @brief Advances drowning phases on animation completion.
 */
void PikiDrownState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		// Advance phase on animation completion: struggle loops, sinking kills.
		if (mState == DS_Sinking) {
			seSystem->playSoundDirect(5, SEW_PIKI_DEAD, piki->mSRT.t);
			piki->kill(false);
			break;
		}

		if (mState == DS_Struggle) {
			// Struggle repeats a random number of times before sinking.
			if (--mStruggleDuration == 0) {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Sizumu, piki), PaniMotionInfo(PIKIANIM_Sizumu));
				seSystem->playSoundDirect(5, SEW_PIKI_SINK, piki->mSRT.t);
				mState = DS_Sinking;
			} else {
				piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			}

			break;
		}

		if (mState == DS_PreStruggle) {
			// Transition from initial entry animation into active struggle.
			mState = DS_Struggle;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Oboreru, piki), PaniMotionInfo(PIKIANIM_Oboreru));
			seSystem->playSoundDirect(5, SEW_PIKI_DROWN, piki->mSRT.t);
		}

		break;
	}
}

/**
 * @brief Constructs the Puffstool-infected (mushroom) behavior state.
 */
PikiKinokoState::PikiKinokoState()
    : PikiState(PIKISTATE_Kinoko, "KINOKO")
{
}

/**
 * @brief Begins infection behavior by selecting a target and starting to wander.
 */
void PikiKinokoState::init(Piki* piki)
{
	piki->startKinoko();
	mTarget = tekiMgr->findClosest(piki->mSRT.t, nullptr);
	initWalk(piki);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	mState = KS_Boid;
}

/**
 * @brief Picks a new biased random walk direction toward the chosen target.
 */
void PikiKinokoState::initWalk(Piki* piki)
{
	mWalkTimer   = (2.0f * gsys->getRand(1.0f)) + 1.5f;
	Vector3f dir = mTarget->mSRT.t - piki->mSRT.t;
	f32 d        = dir.normalise();
	Vector3f orthoDir(dir.z, 0.0f, -dir.x);
	if (gsys->getRand(1.0f) > 0.5f) {
		orthoDir.multiply(-1.0f);
	}

	f32 r    = 0.2f * (gsys->getRand(1.0f) - 0.5f);
	orthoDir = orthoDir + r * dir;
	orthoDir.normalise();
	mTargetDir = orthoDir;
}

/**
 * @brief Runs the infection sub-behavior (wander vs attack).
 */
void PikiKinokoState::exec(Piki* piki)
{
	// Infection alternates between wandering (boid) and attack.
	switch (mState) {
	case KS_Boid:
		exeBoid(piki);
		break;
	case KS_Attack:
		exeAttack(piki);
		break;
	}
}

/**
 * @brief Attack behavior for infected Pikis.
 */
void PikiKinokoState::exeAttack(Piki* piki)
{
}

/**
 * @brief Boid-like wandering for infected groups (keeps them clustered).
 */
void PikiKinokoState::exeBoid(Piki* piki)
{
	mWalkTimer -= gsys->getFrameTime();
	if (mWalkTimer < 0.0f) {
		initWalk(piki);
	}

	Iterator iter(&piki->mSearchBuffer);
	int count = 0;
	Vector3f boidPos(0.0f, 0.0f, 0.0f);
	Vector3f boidVel(0.0f, 0.0f, 0.0f);
	Vector3f dirNearest(0.0f, 0.0f, 0.0f);
	bool isNearest = false;
	f32 minDist    = 50.0f;

	CI_LOOP(iter)
	{
		Creature* c = *iter;
		if (c->mObjType != OBJTYPE_Piki) {
			continue;
		}
		Piki* other = static_cast<Piki*>(c);
		if (other == piki) {
			continue;
		}

		if (other->isKinoko()) {
			f32 dist = qdist2(other->mSRT.t.x, other->mSRT.t.z, piki->mSRT.t.x, piki->mSRT.t.z);
			if (dist < minDist) {
				minDist    = dist;
				dirNearest = piki->mSRT.t - other->mSRT.t;
				isNearest  = true;
			}

			boidPos = boidPos + other->mSRT.t;
			boidVel = boidVel + other->mVelocity;
			count++;
		}
	}

	if (count > 0) {
		dirNearest.normalise();
		boidPos.multiply(1.0f / f32(count));
		boidVel.multiply(1.0f / f32(count));
		boidVel.normalise();

		Vector3f dir = boidPos - piki->mSRT.t;
		Vector3f pikiDir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
		dir.normalise();
		Vector3f moveDir;

		if (isNearest) {
			moveDir = pikiDir * 0.01f + dirNearest * 0.99f;
		} else {
			moveDir = pikiDir * 0.4f + dir * 0.5f + mTargetDir * 0.1f;
		}

		moveDir.normalise();
		piki->setSpeed(0.3f, moveDir);
	} else {
		piki->setSpeed(0.3f, mTargetDir);
	}

	Vector3f targetDir = mTarget->mSRT.t - piki->mSRT.t;
	f32 dist           = targetDir.normalise();
	if (dist < 100.0f) {
		return;
	}
	piki->setSpeed(0.5f, targetDir);
}

/**
 * @brief Ends infection behavior when leaving the state.
 */
void PikiKinokoState::cleanup(Piki* piki)
{
	piki->endKinoko();
}

/**
 * @brief Constructs the bubble-trap panic state.
 */
PikiBubbleState::PikiBubbleState()
    : PikiState(PIKISTATE_Bubble, "BUBBLE")
{
}

/**
 * @brief Enters panic movement and starts the bubble visual effect.
 */
void PikiBubbleState::init(Piki* piki)
{
	piki->changeMode(PikiMode::FreeMode, piki->mNavi);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Moeru), PaniMotionInfo(PIKIANIM_Moeru));
	piki->enableMotionBlend();
	mSurvivalTimer = C_PIKI_PROP(piki).mPanicTime();
	mSurvivalTimer *= (0.1f * gsys->getRand(1.0f)) + 1.0f;
	mChangeDirectionTimer = 0.1f;
	mMoveDirection        = piki->mFaceDirection;
	mSpeedRatio           = 1.0f;
	EffectParm parm(piki);
	piki->mSlimeEffect->emit(parm);
	seSystem->playPikiSound(SEF_PIKI_WATERED, piki->mSRT.t);
}

/**
 * @brief Forces aimless panic until the timer expires.
 */
void PikiBubbleState::exec(Piki* piki)
{
	piki->setSpeed(mSpeedRatio, mMoveDirection);
	mSurvivalTimer -= gsys->getFrameTime();
	mChangeDirectionTimer -= gsys->getFrameTime();
	if (mSurvivalTimer < 0.0f) {
		transit(piki, PIKISTATE_Dying);
		return;
	}

	if (mChangeDirectionTimer < 0.0f) {
		mChangeDirectionTimer = (0.2f * gsys->getRand(1.0f)) + 0.2f;
		mMoveDirection += (45.0f * gsys->getRand(1.0f)) / 180.0f * PI;
		mMoveDirection = roundAng(mMoveDirection);
		mSpeedRatio *= 0.99f;
	}
}

/**
 * @brief Spawns the recovery burst and stops the bubble effect.
 */
void PikiBubbleState::cleanup(Piki* piki)
{
	Vector3f centre = piki->getCentre();
	effectMgr->create(EffectMgr::EFF_Piki_BubbleRecover, centre, nullptr, nullptr);
	piki->mSlimeEffect->kill();
}

/**
 * @brief Constructs the burning panic state.
 */
PikiFiredState::PikiFiredState()
    : PikiState(PIKISTATE_Fired, "FIRED")
{
}

/**
 * @brief Enters panic movement while on fire.
 */
void PikiFiredState::init(Piki* piki)
{
	piki->changeMode(PikiMode::FreeMode, piki->mNavi);
	piki->startMotion(PaniMotionInfo(PIKIANIM_Moeru), PaniMotionInfo(PIKIANIM_Moeru));
	piki->enableMotionBlend();
	mSurvivalTimer = C_PIKI_PROP(piki).mPanicTime();
	mSurvivalTimer *= (0.1f * gsys->getRand(1.0f)) + 1.0f;
	mChangeDirectionTimer = 0.1f;
	mMoveDirection        = piki->mFaceDirection;
	mSpeedRatio           = 1.0f;
}

/**
 * @brief Runs panicked movement until the burn timer expires.
 */
void PikiFiredState::exec(Piki* piki)
{
	piki->setSpeed(mSpeedRatio, mMoveDirection);
	mSurvivalTimer -= gsys->getFrameTime();
	mChangeDirectionTimer -= gsys->getFrameTime();
	if (mSurvivalTimer < 0.0f) {
		transit(piki, PIKISTATE_Dying);
		return;
	}

	if (mChangeDirectionTimer < 0.0f) {
		mChangeDirectionTimer = (0.2f * gsys->getRand(1.0f)) + 0.2f;
		mMoveDirection += (45.0f * gsys->getRand(1.0f)) / 180.0f * PI;
		mMoveDirection = roundAng(mMoveDirection);
		mSpeedRatio *= 0.99f;
	}
}

/**
 * @brief No explicit cleanup; fire system owns extinguish/death visuals.
 */
void PikiFiredState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the swallowed (in-enemy mouth) state.
 */
PikiSwallowedState::PikiSwallowedState()
    : PikiState(PIKISTATE_Swallowed, "SWALLOWED")
{
}

/**
 * @brief Disables normal AI while the Piki is held in a mouth.
 */
void PikiSwallowedState::init(Piki* piki)
{
	PRINT_KANDO("swallowed init **** \n");
	piki->stopAI();
}

/**
 * @brief Restores normal behavior once the mouth-stick is broken.
 */
void PikiSwallowedState::exec(Piki* piki)
{
	if (!piki->isStickToMouth()) {
		PRINT(" piki wa TASUKATTA !\n"); // 'piki was HELPED'
		if (piki->mActiveAction->mIsSuspended && piki->isAlive() && piki->mActiveAction->resumable()) {
			piki->mActiveAction->restart();
		}
		transit(piki, PIKISTATE_Normal);
		return;
	}

	if (piki->getStickObject() && !piki->getStickObject()->isAlive()) {
		piki->endStickMouth();
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @brief Clears mouth linkage and restarts AI after release.
 */
void PikiSwallowedState::cleanup(Piki* piki)
{
	piki->mSwallowMouthPart = nullptr;
	piki->restartAI();
}

/**
 * @brief Constructs the bullet (launched projectile) state.
 */
PikiBulletState::PikiBulletState()
    : PikiState(PIKISTATE_Bullet, "BULLET")
{
}

/**
 * @brief Starts the launch animation and resets distance tracking.
 */
void PikiBulletState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_RollJmp), PaniMotionInfo(PIKIANIM_RollJmp));
	mDistanceTravelled = 0.0f;
}

/**
 * @brief Auto-acquires nearby enemies; otherwise times out back to formation.
 */
void PikiBulletState::exec(Piki* piki)
{
	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		if (teki->isAlive() && teki->isVisible() && !teki->isFlying()) {
			Vector3f dir = teki->mSRT.t - piki->mSRT.t;
			f32 dist     = dir.length();
			if (dist < 100.0f) {
				piki->mActiveAction->abandon(nullptr);
				piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
				piki->mActiveAction->mChildActions[piki->mActiveAction->mCurrActionIdx].initialise(teki);
				piki->mMode = PikiMode::AttackMode;
				transit(piki, PIKISTATE_Normal);
				return;
			}
		}
	}

	mDistanceTravelled += piki->mVelocity.length() * gsys->getFrameTime();

	if (mDistanceTravelled > 300.0f) {
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		transit(piki, PIKISTATE_Normal);
		return;
	}

	piki->mVelocity.normalise();
	piki->mVelocity = piki->getSpeed(1.0f) * piki->mVelocity;
}

/**
 * @brief Cancels bullet travel if it hits a wall.
 */
void PikiBulletState::procWallMsg(Piki* piki, MsgWall*)
{
	piki->changeMode(PikiMode::FormationMode, piki->mNavi);
	transit(piki, PIKISTATE_Normal);
}

/**
 * @brief No explicit cleanup.
 */
void PikiBulletState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the knockback (flick) reaction state.
 */
PikiFlickState::PikiFlickState()
    : PikiState(PIKISTATE_Flick, "FLICK")
{
}

/**
 * @brief Begins a flick reaction by launching and suspending the current action.
 */
void PikiFlickState::init(Piki* piki)
{
	mState            = FLS_FlyingBack;
	mInitialAngle     = piki->mRotationAngle;
	mRotationDelta    = 0.1f * (PI * gsys->getRand(1.0f));
	piki->mVelocity.y = (50.0f * gsys->getRand(1.0f)) + 100.0f;
	mStrength         = piki->mFlickIntensity * 0.1f * gsys->getRand(1.0f) + piki->mFlickIntensity;
	piki->mActiveAction->resume();
	piki->startMotion(PaniMotionInfo(PIKIANIM_JHit, piki), PaniMotionInfo(PIKIANIM_JHit));
}

/**
 * @brief Applies airborne knockback then waits out the knockdown.
 */
void PikiFlickState::exec(Piki* piki)
{
	PaniAnimator& upper = piki->mPikiAnimMgr.getUpperAnimator();
	if (upper.getCurrentMotionIndex() == PIKIANIM_Kuttuku) {
		PRINT_KANDO("piki %x motion KENKA!\n", piki);
	}

	if (mState == FLS_FlyingBack) {
		f32 rad              = mStrength;
		piki->mVelocity.x    = -rad * sinf(mInitialAngle);
		piki->mVelocity.z    = -rad * cosf(mInitialAngle);
		piki->mFaceDirection = roundAng(piki->mFaceDirection + mRotationDelta);
		return;
	}

	if (mState == FLS_Downed) {
		mGetUpTimer -= gsys->getFrameTime();
		if ((mGetUpTimer < 0.0f || piki->mIsWhistlePending) && piki->isAlive()) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			mState = FLS_GettingUp;
		}

		piki->mVelocity.x = 0.9f * piki->mVelocity.x;
		piki->mVelocity.z = 0.9f * piki->mVelocity.z;
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	piki->mVelocity.x = 0.9f * piki->mVelocity.x;
	piki->mVelocity.z = 0.9f * piki->mVelocity.z;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @brief Advances flick phases based on animation completion.
 */
void PikiFlickState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == FLS_FlyingBack) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
			mState = FLS_Landing;
			break;
		}
		if (mState == FLS_Landing) {
			mState      = FLS_Downed;
			f32 min     = C_PIKI_PROP(piki).mMinFlickKnockDownTime();
			f32 max     = C_PIKI_PROP(piki).mMaxFlickKnockDownTime();
			mGetUpTimer = (max - min) * gsys->getRand(1.0f) + min;
			if (piki->mHealth <= 0.0f) {
				PRINT("piki died !\n");
				transit(piki, PIKISTATE_Dead);
			}
			break;
		}

		PRINT("done\n");
		if (gsys->getRand(1.0f) < 0.25f && piki->mHappa >= Bud) {
			piki->mHappa--;
			piki->setFlower(piki->mHappa);
			zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Piki_DeflowerPetals, piki->mEffectPos, nullptr, nullptr);
			if (ptclGen) {
				ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			}
			effectMgr->create(EffectMgr::EFF_Piki_DeflowerSpores, piki->mEffectPos, nullptr, nullptr);
		}

		if (piki->isKinoko()) {
			piki->mActiveAction->abandon(nullptr);
			piki->changeMode(PikiMode::FormationMode, piki->mNavi);
			transit(piki, PIKISTATE_KinokoChange);
			break;
		}

		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @brief Restores control: either resume prior action or return to formation.
 */
void PikiFlickState::cleanup(Piki* piki)
{
	PRINT("** flick cleanup %x\n", piki);
	if (piki->isKinoko()) {
		return;
	}
	if (piki->isStickToMouth()) {
		return;
	}

	if (piki->isAlive() && piki->mIsWhistlePending) {
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		piki->endStickObject();
		piki->mIsWhistlePending = false;
		return;
	}

	if (piki->isAlive() && piki->mActiveAction->resumable()) {
		piki->mActiveAction->restart();
		return;
	}

	PRINT_KANDO("piki%x FLICK ** aiAction->curr = %d is not resumable!\n", piki, piki->mActiveAction->mCurrActionIdx);
	piki->mActiveAction->abandon(nullptr);
}

/**
 * @brief Constructs the long knockback flight state.
 */
PikiFlownState::PikiFlownState()
    : PikiState(PIKISTATE_Flown, "FLOWN")
{
}

/**
 * @brief Begins a long knockback by starting the hit reaction.
 */
void PikiFlownState::init(Piki* piki)
{
	mState          = FNS_Airborne;
	mInitialAngle   = atan2f(piki->mVelocity.x, piki->mVelocity.z);
	mRotationDelta  = 0.1f * (PI * gsys->getRand(1.0f));
	mFlickIntensity = 0.1f * piki->mFlickIntensity * gsys->getRand(1.0f) + piki->mFlickIntensity;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JHit, piki), PaniMotionInfo(PIKIANIM_JHit));
}

/**
 * @brief Converts airborne flight into a landing stumble on first bounce.
 */
void PikiFlownState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mState == FNS_Airborne) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
		mState = FNS_Landing;
	}
}

/**
 * @brief Spins in-air, then waits out a knockdown timer before recovery.
 */
void PikiFlownState::exec(Piki* piki)
{
	PaniAnimator& upper = piki->mPikiAnimMgr.getUpperAnimator();
	if (upper.getCurrentMotionIndex() == PIKIANIM_Kuttuku) {
		PRINT_KANDO("piki %x motion KENKA!\n", piki);
	}

	if (mState == FNS_Airborne) {
		piki->mFaceDirection = roundAng(piki->mFaceDirection + mRotationDelta);
		return;
	}

	if (mState == FNS_Downed) {
		_10 -= gsys->getFrameTime();
		if ((_10 < 0.0f || piki->mIsWhistlePending) && piki->isAlive()) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			mState = FNS_GettingUp;
		}
		piki->mVelocity.x = 0.9f * piki->mVelocity.x;
		piki->mVelocity.z = 0.9f * piki->mVelocity.z;
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	piki->mVelocity.x = 0.9f * piki->mVelocity.x;
	piki->mVelocity.z = 0.9f * piki->mVelocity.z;
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @brief Advances flown phases based on animation completion.
 */
void PikiFlownState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == FNS_Landing) {
			mState  = FNS_Downed;
			f32 min = C_PIKI_PROP(piki).mMinFlickKnockDownTime();
			f32 max = C_PIKI_PROP(piki).mMaxFlickKnockDownTime();
			_10     = (max - min) * gsys->getRand(1.0f) + min;
			if (piki->mHealth <= 0.0f) {
				PRINT("piki died !\n");
				transit(piki, PIKISTATE_Dead);
			}
			break;
		}

		PRINT("done\n");
		if (gsys->getRand(1.0f) < 0.25f && piki->mHappa >= Bud) {
			piki->mHappa--;
			piki->setFlower(piki->mHappa);
			zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Piki_DeflowerPetals, piki->mEffectPos, nullptr, nullptr);
			if (ptclGen) {
				ptclGen->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			}
			effectMgr->create(EffectMgr::EFF_Piki_DeflowerSpores, piki->mEffectPos, nullptr, nullptr);
		}

		if (piki->isKinoko()) {
			piki->mActiveAction->abandon(nullptr);
			piki->changeMode(PikiMode::FormationMode, piki->mNavi);
			transit(piki, PIKISTATE_KinokoChange);
			break;
		}

		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @brief Drops any pending behavior; recovery is handled by the next state.
 */
void PikiFlownState::cleanup(Piki* piki)
{
	if (piki->isKinoko()) {
		return;
	}
	if (piki->isStickToMouth()) {
		return;
	}

	if (piki->isAlive() && piki->mIsWhistlePending) {
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		piki->mIsWhistlePending = false;
		return;
	}

	piki->mActiveAction->abandon(nullptr);
}

/**
 * @brief Constructs fall state.
 */
PikiFallMeckState::PikiFallMeckState()
    : PikiState(PIKISTATE_FallMeck, "FALLMECK")
{
}

/**
 * @brief Starts a fall animation and clears mouth-stuck swallow state.
 */
void PikiFallMeckState::init(Piki* piki)
{
	PRINT_KANDO("--- fall start\n");
	piki->startMotion(PaniMotionInfo(PIKIANIM_Fall, piki), PaniMotionInfo(PIKIANIM_Fall));
	piki->endStickMouth();
	piki->mSwallowMouthPart = nullptr;
}

/**
 * @brief FallMeck behavior is driven by external physics/impacts.
 */
void PikiFallMeckState::exec(Piki* piki)
{
}

/**
 * @brief On impact, optionally converts the Piki into a buried sprout.
 */
void PikiFallMeckState::procBounceMsg(Piki* piki, MsgBounce*)
{
	int attr = ATTR_NULL;
	if (piki->mGroundTriangle) {
		attr = MapCode::getAttribute(piki->mGroundTriangle);
	}

	if (!piki->hasBomb() && Piki::isSafeMePos(piki->mSRT.t) && !MapCode::isBald(piki->mGroundTriangle) && attr != ATTR_Water) {
		PikiHeadMgr::buryMode = true;
		PikiHeadItem* sprout  = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
		PikiHeadMgr::buryMode = false;

		if (sprout) {
			Vector3f pos(piki->mSRT.t);
			pos.y = mapMgr->getMinY(pos.x, pos.z, true);
			effectMgr->create(EffectMgr::EFF_SD_DirtCloud, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_SD_DirtSpray, pos, nullptr, nullptr);
			sprout->init(pos);
			sprout->setColor(piki->mColor);
			f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
			sprout->mVelocity.set(220.0f * sinf(randAngle), 540.0f, 220.0f * cosf(randAngle));
			sprout->startAI(0);
			sprout->mParentOnion = nullptr;
			C_SAI(sprout)->start(sprout, PikiHeadAI::PIKIHEAD_Unk5);
			piki->setEraseKill();
			piki->kill(true);
			STACK_PAD_VAR(1);
			return;
		}
	}

	transit(piki, PIKISTATE_Normal);
	if (piki->hasBomb()) {
		Creature* held = piki->getHoldCreature();
		held->resetStateGrabbed();
		if (held->mObjType == OBJTYPE_Bomb) {
			AICreature* ai = (AICreature*)held;
			if (ai->getCurrState()->getID() != 1) {
				MsgUser msg(1);
				BombItem* bomb    = (BombItem*)held;
				bomb->mCurrAnimId = 1;
				C_SAI(bomb)->procMsg(bomb, &msg);
			}
		}
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiFallMeckState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the generic falling state.
 */
PikiFallState::PikiFallState()
    : PikiState(PIKISTATE_Fall, "FALL")
{
}

/**
 * @brief Starts a fall animation and waits for landing.
 */
void PikiFallState::init(Piki* piki)
{
	PRINT_KANDO("--- fall start\n");
	piki->startMotion(PaniMotionInfo(PIKIANIM_Fall, piki), PaniMotionInfo(PIKIANIM_Fall));
	mState = FS_Falling;
}

/**
 * @brief Fall physics/pose is handled by core; keep state active.
 */
void PikiFallState::exec(Piki* piki)
{
}

/**
 * @brief Converts the fall into a landing stumble on first impact.
 */
void PikiFallState::procBounceMsg(Piki* piki, MsgBounce*)
{
	PRINT_KANDO("fall : got bounce\n");
	mState = FS_Landed;
	piki->startMotion(PaniMotionInfo(PIKIANIM_JKoke, piki), PaniMotionInfo(PIKIANIM_JKoke));
}

/**
 * @brief Returns the Piki to normal after recovery animations complete.
 */
void PikiFallState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mState == FS_Landed) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_GetUp, piki), PaniMotionInfo(PIKIANIM_GetUp));
			mState = FS_GetUp;
			break;
		}

		if (mState == FS_GetUp) {
			transit(piki, PIKISTATE_Normal);
		}
		break;
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiFallState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the cliff-edge recovery state.
 */
PikiCliffState::PikiCliffState()
    : PikiState(PIKISTATE_Cliff, "CLIFF")
{
}

/**
 * @brief Begins a ledge-slip sequence (may lead into hang or fall).
 */
void PikiCliffState::init(Piki* piki)
{
	mInitialVelocity = piki->mVelocity;

	f32 speed = mInitialVelocity.normalise();
	if (speed < 1.0f) {
		mCliffHangType = 0;
	} else {
		mCliffHangType = 1;
	}

	piki->startMotion(PaniMotionInfo(PIKIANIM_LSuberu, piki), PaniMotionInfo(PIKIANIM_LSuberu));
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mState = CS_SlideStart;
	PRINT_KANDO("%x cliff start :: %s\n", piki, mCliffHangType ? "BURAN" : "OTIKAKE"); // 'hang' and 'fall' (i think)
	mInitialFaceDir = piki->mFaceDirection;
}

/**
 * @brief Forces a fall if floor contact vanishes mid-sequence.
 */
void PikiCliffState::exec(Piki* piki)
{
	if (!piki->mGroundTriangle) {
		PRINT_KANDO("piki %x: no floor !\n", piki);
		transit(piki, PIKISTATE_Fall);
	}
}

/**
 * @brief Starts the explicit falling animation from a ledge.
 * @note UNUSED Size: 000088
 */
void PikiCliffState::startFall(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Otiru, piki), PaniMotionInfo(PIKIANIM_Otiru));
	mState = CS_FallAnim;
}

/**
 * @brief Checks if the Piki is close enough to a ledge to justify hanging.
 */
bool PikiCliffState::nearEnough(Piki* piki)
{
	Vector3f dir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
	f32 maxProj  = -1.0f;
	int planeIdx = -1;
	for (int i = 0; i < 3; i++) {
		f32 proj = piki->mGroundTriangle->mEdgePlanes[i].mNormal.DP(dir);
		if (proj > maxProj) {
			proj     = maxProj; // this is absolutely a typo
			planeIdx = i;
		}
	}

	f32 dist = piki->mGroundTriangle->mEdgePlanes[planeIdx].dist(piki->mSRT.t);
	if (dist < piki->mCollisionRadius + 0.2f) {
		f32 x     = piki->mSRT.t.x;
		f32 z     = piki->mSRT.t.z;
		f32 currY = piki->mSRT.t.y;
		x += dir.x * piki->mCollisionRadius * 1.5f;
		z += dir.z * piki->mCollisionRadius * 1.5f;
		f32 botY = mapMgr->getMinY(x, z, true);
		if (currY - botY >= 5.0f * piki->getCentreSize()) {
			return true;
		}

		PRINT_KANDO("currY = %.1f botY = %.1f\n", currY, botY);
	}

	return false;
}

/**
 * @brief Drives cliff recovery using animation loop/finish events.
 */
void PikiCliffState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		// Some animations end once per phase; interpret finish based on cliff substate.
		switch (mState) {
		case CS_SlideStart:
			// Initial slip finished: move into edge shuffle loop.
			if (mCliffHangType >= 2 || mCliffHangType < 0) {
				return;
			}

			mState       = CS_EdgeShuffle;
			mLoopCounter = int((2.0f * gsys->getRand(1.0f))) + 1;
			PRINT_KANDO("otikake motion start\n");
			piki->startMotion(PaniMotionInfo(PIKIANIM_Otikake, piki), PaniMotionInfo(PIKIANIM_Otikake));
			break;

		case CS_FallAnim:
			// Falling animation finished: either we landed (back to normal) or keep falling.
			if (!piki->mGroundTriangle) {
				PRINT_KANDO("piki fall (otiru) %x\n", piki);
				transit(piki, PIKISTATE_Fall);
				return;
			}
			PRINT_KANDO("otiru escaped\n");
			transit(piki, PIKISTATE_Normal);
			break;

		case CS_EdgeShuffle:
			// Edge shuffle finished without transitioning into hang/fall: recover.
			PRINT_KANDO("goto normal !?\n");
			transit(piki, PIKISTATE_Normal);
			break;
		}
		break;

	case KEY_LoopEnd:
		// Loop-end is used for repeated edge/hang loops and their exit conditions.
		switch (mState) {
		case CS_EdgeShuffle:
			// After N loops: attempt hang, otherwise start the fall animation.
			mLoopCounter--;
			if (mLoopCounter > 0) {
				break;
			}
			if (mCliffHangType == 1) {
				if (piki->mGroundTriangle && nearEnough(piki)) {
					piki->mFaceDirection = roundAng(mInitialFaceDir + PI);
					piki->startMotion(PaniMotionInfo(PIKIANIM_Hikakaru, piki), PaniMotionInfo(PIKIANIM_Hikakaru));
					Plane* plane = piki->getNearestPlane(piki->mGroundTriangle);
					if (plane) {
						f32 dist = plane->dist(piki->mSRT.t);
						PRINT_KANDO("dist is %.1f ( radius=%f : centresize=%f\n", dist, piki->mCollisionRadius, piki->getCentreSize());
						if (dist > -0.2f && dist < 3.0f) {
							PRINT_KANDO("piki%x : ####### start buran motion :: floor = %s\n", piki,
							            piki->mGroundTriangle ? "on floor" : "air");
							mState       = CS_Hanging;
							mLoopCounter = int((2.0f * gsys->getRand(1.0f))) + 2;
							break;
						}
						PRINT_KANDO("buran is not executable : dist is too far\n");
						transit(piki, PIKISTATE_Normal);
						break;
					}
					PRINT_KANDO("buran is not executable : no plane\n");
					transit(piki, PIKISTATE_Normal);
					break;
				}
				PRINT_KANDO("buran is not executable : no floorCollTri\n");
				startFall(piki);
				break;
			}

			if (piki->mGroundTriangle) {
				PRINT_KANDO("piki escaped from falling!\n");
				transit(piki, PIKISTATE_Normal);
				break;
			}

			PRINT_KANDO("fall start : \n");
			startFall(piki);
			break;

		case CS_Hanging:
			// Hanging loops a few times, then drops into the generic fall state.
			mLoopCounter--;
			if (mLoopCounter > 0) {
				break;
			}

			piki->mSRT.t = piki->getCentre();
			PRINT_KANDO("piki %x : do fall\n", piki);
			transit(piki, PIKISTATE_Fall);
			break;
		}
		break;
	}
}

/**
 * @brief Emits debug trace and leaves cleanup to the next state.
 */
void PikiCliffState::cleanup(Piki* piki)
{
	PRINT_KANDO("cliff cleanup\n");
}

/**
 * @brief Constructs the "run to player hand" state used before throwing.
 */
PikiGoHangState::PikiGoHangState()
    : PikiState(PIKISTATE_GoHang, "GOHANG")
{
}

/**
 * @brief Starts running toward the player to be picked up.
 */
void PikiGoHangState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Run), PaniMotionInfo(PIKIANIM_Run));
}

/**
 * @brief Pulls the Piki toward the player's hand during throw prep.
 */
void PikiGoHangState::exec(Piki* piki)
{
	CollPart* naviHand = piki->mNavi->mCollInfo->getSphere('rhnd');
	Vector3f dir       = naviHand->mCentre - piki->mSRT.t;
	f32 dist           = dir.normalise();
	f32 speedFactor    = 1.0f;
	if (dist > 2.0f * C_NAVI_PROP(piki->mNavi)._1BC()) {
		speedFactor = 2.0f;
	}
	piki->mTargetVelocity = dir * C_PIKI_PROP(piki).mMaxLeafMoveSpeed() * speedFactor;
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiGoHangState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the "held for throw" state.
 */
PikiHangedState::PikiHangedState()
    : PikiState(PIKISTATE_Hanged, "HANGED")
{
}

/**
 * @brief Plays the "ready to throw" sound on animation loop.
 */
void PikiHangedState::procAnimMsg(Piki*, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		SeSystem::playPlayerSe(SE_PIKI_FLYREADY);
		break;
	}
}

/**
 * @brief Freezes movement and holds the throw-ready pose.
 */
void PikiHangedState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Hang, piki), PaniMotionInfo(PIKIANIM_Hang));
	piki->mHasCollChangedVelocity = 0;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @brief Cancels the held state if the player stops throw-prep.
 */
void PikiHangedState::exec(Piki* piki)
{
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @brief Stops the throw-ready sound.
 */
void PikiHangedState::cleanup(Piki* piki)
{
	SeSystem::stopPlayerSe(SE_PIKI_FLYREADY);
}

/**
 * @brief Constructs the "held over water" variant of throw-ready.
 */
PikiWaterHangedState::PikiWaterHangedState()
    : PikiState(PIKISTATE_WaterHanged, "WATER_HANGED")
{
}

/**
 * @brief Plays the "ready to throw" sound on animation loop.
 */
void PikiWaterHangedState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		SeSystem::playPlayerSe(SE_PIKI_FLYREADY);
		break;
	}
}

/**
 * @brief Holds the throw-ready pose while forcing zero velocity.
 */
void PikiWaterHangedState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_Hang, piki), PaniMotionInfo(PIKIANIM_Hang));
	piki->mHasCollChangedVelocity = 0;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	PRINT("water hang init!\n");
}

/**
 * @brief Cancels the held state if the player stops throw-prep.
 */
void PikiWaterHangedState::exec(Piki* piki)
{
	if (piki->mNavi->getCurrState()->getID() != NAVISTATE_ThrowWait) {
		PRINT("???\n");
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @brief Stops the throw-ready sound.
 */
void PikiWaterHangedState::cleanup(Piki* piki)
{
	PRINT("water hang exit\n");
	SeSystem::stopPlayerSe(SE_PIKI_FLYREADY);
}

/**
 * @brief Constructs the Onion ejection state.
 */
PikiEmitState::PikiEmitState()
    : PikiState(PIKISTATE_Emit, "EMIT")
{
}

/**
 * @brief Stops normal AI while playing the ejection animation.
 */
void PikiEmitState::init(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_WaveJmp, piki), PaniMotionInfo(PIKIANIM_WaveJmp));
	piki->stopAI();
	piki->mHasCollChangedVelocity = 0;
	mHasLanded                    = true;
}

/**
 * @brief Prevents motion while waiting for the "landed" phase.
 */
void PikiEmitState::exec(Piki* piki)
{
	if (!mHasLanded) {
		piki->mVelocity.set(0.0f, 0.0f, 0.0f);
		piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}
}

/**
 * @brief Restarts AI once the ejection sequence finishes.
 */
void PikiEmitState::cleanup(Piki* piki)
{
	piki->restartAI();
}

/**
 * @brief Switches from airborne to bury animation on first bounce.
 */
void PikiEmitState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mHasLanded) {
		mHasLanded = false;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Umaru, piki), PaniMotionInfo(PIKIANIM_Umaru));
	}
}

/**
 * @brief Loops the jump until it "lands", then transitions into planting.
 */
void PikiEmitState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (mHasLanded) {
			piki->startMotion(PaniMotionInfo(PIKIANIM_WaveJmp, piki), PaniMotionInfo(PIKIANIM_WaveJmp));
		} else {
			transit(piki, PIKISTATE_Bury);
		}
		break;
	}
}

/**
 * @brief Constructs the thrown-airborne flight state.
 */
PikiFlyingState::PikiFlyingState()
    : PikiState(PIKISTATE_Flying, "FLYING")
{
}

/**
 * @brief Halts any flight-specific looping effects.
 */
void PikiFlyingState::stopEffect()
{
	mSparkleEffect.stop();
}

/**
 * @brief Restarts flight-specific looping effects.
 */
void PikiFlyingState::restartEffect()
{
	mSparkleEffect.restart();
}

/**
 * @brief Enters thrown flight: stop AI, play flight sound, enable sticking.
 */
void PikiFlyingState::init(Piki* piki)
{
	PRINT_KANDO("flying state init\n");
	PRINT_KANDO("piki is %s\n", piki->isHolding() ? "holding" : "not holding");
	piki->mMotionSpeed = 30.0f;
	piki->startMotion(PaniMotionInfo(PIKIANIM_RollJmp), PaniMotionInfo(PIKIANIM_RollJmp));
	piki->stopAI();
	piki->mHasCollChangedVelocity = 0;
	SeSystem::playPlayerSe(SE_PIKI_FLY);
	piki->mWantToStick = true;
	mIsFlowerGliding   = false;
	mSparkleEffect.init(piki->mSRT.t, EffectMgr::EFF_SD_Sparkle);
	mGroundTouchFrames = 0;
	mHasBounced        = false;
}

/**
 * @brief Implements flower gliding and failsafes to ensure landing.
 */
void PikiFlyingState::exec(Piki* piki)
{
	if (piki->isCreatureFlag(CF_IsOnGround)) {
		mGroundTouchFrames++;
		if (mGroundTouchFrames >= 10) {
			for (int i = 0; i < 10; i++) {
				PRINT("** WARNING *** FLYING MIGHT LAST FOREVER !!!\n");
			}
			piki->dump();
			procBounceMsg(piki, nullptr);
			return;
		}
	} else {
		mGroundTouchFrames = 0;
	}

	mSparkleEffect.updatePos(piki->mSRT.t);

	f32 startGrav          = AIConstant::_instance->mConstants.mGravity() * 0.8f;
	f32 glideGrav          = AIConstant::_instance->mConstants.mGravity() * C_PIKI_PROP(piki).mFlowerGravityScale();
	f32 gravTransitionTime = 0.15f;
	f32 gravInterp         = startGrav * gravTransitionTime - 0.5f * 0.15f * (startGrav - glideGrav) - glideGrav * gravTransitionTime;
	if (!mIsFlowerGliding && piki->mHappa == Flower && piki->mVelocity.y <= 0.0f) {
		mIsFlowerGliding = true;
		piki->startMotion(PaniMotionInfo(PIKIANIM_Hang), PaniMotionInfo(PIKIANIM_Hang));
		f32 glideDist;
		if (piki->mColor == Yellow) {
			glideDist = C_NAVI_PROP(piki->mNavi)._19C();
		} else {
			glideDist = C_NAVI_PROP(piki->mNavi)._17C();
		}

		f32 glideTime        = (speedy_sqrtf(gravInterp * gravInterp + 2.0f * glideDist * glideGrav) + -gravInterp) / glideGrav;
		f32 glideSpeedXZ     = C_NAVI_PROP(piki->mNavi)._1AC() * 0.5f;
		f32 glideSpeedFactor = glideSpeedXZ / glideTime;

		mHorizontalDirection.x = piki->mVelocity.x;
		mHorizontalDirection.y = 0.0f;
		mHorizontalDirection.z = piki->mVelocity.z;
		mHorizontalDirection.normalise();

		f32 startSpeedXZ        = speedy_sqrtf(piki->mVelocity.x * piki->mVelocity.x + piki->mVelocity.z * piki->mVelocity.z);
		mInitialHorizontalSpeed = startSpeedXZ;

		f32 targetSpeedXZ      = startSpeedXZ * 0.5f;
		mTargetHorizontalSpeed = targetSpeedXZ;

		// this calc is unused
		glideTime = ((startSpeedXZ * glideSpeedXZ) - (startSpeedXZ - (startSpeedXZ - targetSpeedXZ) * 0.5f - targetSpeedXZ) * 0.15f)
		          / targetSpeedXZ;

		piki->mVelocity.x *= glideSpeedFactor;
		piki->mVelocity.z *= glideSpeedFactor;

		piki->mTargetVelocity.x = piki->mVelocity.x;
		piki->mTargetVelocity.z = piki->mVelocity.z;

		piki->mVelocity.y       = 0.0f;
		piki->mTargetVelocity.y = 0.0f;
		mGlideTimer             = 0.0f;
		return;
	}

	if (!mIsFlowerGliding) {
		return;
	}

	piki->mFaceDirection = roundAng(gsys->getFrameTime() * PI / 0.42f + piki->mFaceDirection);
	mGlideTimer += gsys->getFrameTime();

	// for some natural variation in fall speed
	f32 randomFactor = (gsys->getRand(1.0f) - 0.5f) * 0.01f;

	STACK_PAD_TERNARY(randomFactor, 1);

	f32 gravAdjust;
	if (mGlideTimer < 0.15f) {
		gravAdjust = startGrav - (startGrav - glideGrav) / 0.15f * mGlideTimer;
	} else {
		gravAdjust = glideGrav;
	}

	piki->mVelocity.y += ((AIConstant::_instance->mConstants.mGravity() - gravAdjust) * (randomFactor + 1.0f)) * gsys->getFrameTime();

	STACK_PAD_VAR(4);
}

/**
 * @brief Cleans up flight effects and restores AI control.
 */
void PikiFlyingState::cleanup(Piki* piki)
{
	mSparkleEffect.kill();
	piki->restartAI();
	piki->mWantToStick = false;
}

/**
 * @brief Converts mid-air collisions into appropriate actions (stick/attack/work).
 */
void PikiFlyingState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	Creature* collider = msg->mEvent.mCollider;
	int colliderType   = collider->mObjType;

	if (colliderType == OBJTYPE_WorkObject && piki->mVelocity.y >= 0.0f) {
		return;
	}

	if (colliderType == OBJTYPE_RockGen || colliderType == OBJTYPE_GrassGen) {
		return;
	}

	if (colliderType == OBJTYPE_Water && piki->mHappa != Flower) {
		return;
	}

	if (playerState->inDayEnd()) {
		return;
	}

	if (piki->isHolding()) {
		return;
	}

	if (colliderType == OBJTYPE_WorkObject) {
		WorkObject* obj = (WorkObject*)collider;
		if (obj->isBridge()) {
			PRINT("FLYING COLLIDE BRIDGE bridge is %s!!!\n", obj->workable(piki->mSRT.t) ? "workable" : "dame!");
			piki->mActiveAction->abandon(nullptr);
			piki->mActiveAction->mCurrActionIdx = PikiAction::Bridge;
			piki->mActiveAction->mChildActions[PikiAction::Bridge].initialise(collider);
			piki->mMode = PikiMode::BridgeMode;
			return;
		}

		if (obj->isHinderRock()) {
			piki->mActiveAction->abandon(nullptr);
			piki->mActiveAction->mCurrActionIdx = PikiAction::Push;
			piki->mActiveAction->mChildActions[PikiAction::Push].initialise(collider);
			piki->mMode = PikiMode::PushstoneMode;
			return;
		}

		ERROR("unknown work object!\n");
	}

	if (colliderType == OBJTYPE_Plant) {
		return;
	}

	if (colliderType == OBJTYPE_Weed) {
		return;
	}

	// kando we already did this check
	if (colliderType == OBJTYPE_RockGen || colliderType == OBJTYPE_GrassGen) {
		return;
	}

	// we also know this??? you checked this???
	if (colliderType != OBJTYPE_Plant) {
		SeSystem::playPlayerSe(SE_THROWHIT);
	}

	if (colliderType == OBJTYPE_Teki || collider->isBoss()) {
		Vector3f effPos = collider->mSRT.t - piki->mSRT.t;
		effPos.normalise();
		Vector3f effDir(effPos);
		effPos.multiply(piki->getCentreSize() * 1.5f);
		effPos.add(piki->mSRT.t);
		InteractHitEffect hit(piki, effPos, effDir, msg->mEvent.mColliderPart);
		collider->stimulate(hit);
	}

	CollPart* part = msg->mEvent.mColliderPart;
	if (part && part->isBouncy()) {
		if (!mHasBounced) {
			Vector3f bounceDir = piki->mSRT.t - collider->mSRT.t;
			bounceDir.normalise();
			bounceDir.multiply(140.0f);
			piki->mVelocity       = bounceDir;
			piki->mTargetVelocity = bounceDir;
		}

		mHasBounced = true;
		return;
	}

	if (colliderType == OBJTYPE_Teki && collider->isOrganic()) {
		piki->mActiveAction->abandon(nullptr);
		PRINT_KANDO("FLYING .. collide\n");
		if (msg->mEvent.mColliderPart->isPlatformType()) {
			if (msg->mEvent.mColliderPart->isStickable()) {
				PRINT_KANDO("flying ... stick to platform::%s(code %s)\n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				            msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				piki->startStick(collider, msg->mEvent.mColliderPart);
				SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
			} else if (msg->mEvent.mColliderPart->isClimbable()) {
				PRINT_KANDO("flying ... stick to platform::%s(code %s)\n", msg->mEvent.mColliderPart->mCollInfo->mId.mStringID,
				            msg->mEvent.mColliderPart->mCollInfo->mCode.mStringID);
				piki->startStick(collider, msg->mEvent.mColliderPart);
				SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
			}
		} else if ((msg->mEvent.mColliderPart->isCollisionType() || msg->mEvent.mColliderPart->isTubeType())
		           && msg->mEvent.mColliderPart->isStickable()) {
			PRINT_KANDO("flying ... stick to sphere\n");
			piki->startStickObject(collider, msg->mEvent.mColliderPart, -1, 0.0f);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		}

		transit(piki, PIKISTATE_Normal);
		PRINT_KANDO("++++++++++++++++++++++++++++++++\n");
		PRINT_KANDO(" _stickPart = %x : %s\n", piki->mStickPart,
		            piki->mStickPart ? piki->mStickPart->mCollInfo->mId.mStringID : "nothing!");
		PRINT_KANDO(" _stickPart = %x\n", piki->mStickPart);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
		PRINT_KANDO("----------------\n");
		piki->mActiveAction->mChildActions[PikiAction::Attack].initialise(collider);
		PRINT_KANDO("----------------\n");
		piki->mMode = PikiMode::AttackMode;
		PRINT_KANDO(" _stickPart = %x\n", piki->mStickPart);
		PRINT_KANDO("(%x) stick OBJECT attack start ? ########\n", piki);
		PRINT_KANDO(" _stickPart = %x\n", piki->mStickPart); // this is excessive.
		return;
	}

	if (collider->isBoss() && msg->mEvent.mColliderPart && msg->mEvent.mColliderPart->isStickable()) {
		if (msg->mEvent.mColliderPart->isPlatformType()) {
			piki->startStick(collider, msg->mEvent.mColliderPart);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		} else {
			piki->startStickObject(collider, msg->mEvent.mColliderPart, -1, 0.0f);
			SeSystem::playPlayerSe(SE_PIKI_ATTACHENEMY);
		}
		transit(piki, PIKISTATE_Normal);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Attack;
		piki->mActiveAction->mChildActions[PikiAction::Attack].initialise(collider);
		piki->mMode = PikiMode::AttackMode;
		return;
	}

	if (collider->isSluice()) {
		PRINT_KANDO("got here\n");
		piki->mMode                         = PikiMode::BreakwallMode;
		piki->mActiveAction->mCurrActionIdx = PikiAction::BreakWall;
		piki->mActiveAction->mChildActions[PikiAction::BreakWall].initialise(collider);
		transit(piki, PIKISTATE_Normal);
		return;
	}

	if (colliderType == OBJTYPE_Pellet && ((Pellet*)collider)->getMinFreeSlotIndex() != -1) {
		piki->mActiveAction->abandon(nullptr);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Transport;
		piki->mActiveAction->mChildActions[piki->mActiveAction->mCurrActionIdx].initialise(collider);
		piki->mMode = PikiMode::TransportMode;
		return;
	}

	if (colliderType != OBJTYPE_Navi) {
		PRINT_KANDO("collide restart!!\n");
		piki->restartAI();
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @brief Ignored for this state (sticking is handled via collisions).
 */
void PikiFlyingState::procStickMsg(Piki*, MsgStick*)
{
}

/**
 * @brief Finalizes flight: bounce-handling vs normal landing behavior.
 */
void PikiFlyingState::procBounceMsg(Piki* piki, MsgBounce*)
{
	if (mHasBounced) {
		piki->restartAI();
		transit(piki, PIKISTATE_Normal);
		piki->mActiveAction->mCurrActionIdx = PikiAction::Crowd;
		piki->mActiveAction->mChildActions[PikiAction::Crowd].initialise(piki->mNavi);
		piki->mMode = PikiMode::FormationMode;
		return;
	}

	piki->restartAI();
	transit(piki, PIKISTATE_Normal);
	seSystem->playPikiSound(SEF_PIKI_LAND, piki->mSRT.t);
	if (piki->isHolding()) {
		if (piki->getHoldCreature()->mObjType != OBJTYPE_Bomb) {
			PRINT("*** HOLD CREATURE = %x\n", piki->getHoldCreature());
			PRINT("piki = %x : holdCreature->holder = %x\n", piki, piki->getHoldCreature()->getHolder());
			ERROR("piki holds ??\n");
		}

		piki->changeMode(PikiMode::PutbombMode, piki->mNavi);
	} else {
		piki->actOnSituaton();
	}
}

/**
 * @brief Constructs the pre-bury growth state.
 */
PikiGrowState::PikiGrowState()
    : PikiState(PIKISTATE_Grow, "GROW")
{
}

/**
 * @brief Plays the first growth animation and clears formation priority.
 */
void PikiGrowState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
	piki->mFormationPriority = 0;
}

/**
 * @brief Growth is animation-driven.
 */
void PikiGrowState::exec(Piki* piki)
{
}

/**
 * @brief No explicit cleanup.
 */
void PikiGrowState::cleanup(Piki* piki)
{
}

/**
 * @brief Transitions into planting once the growth animation finishes.
 */
void PikiGrowState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		transit(piki, PIKISTATE_Bury);
		break;
	}
}

/**
 * @brief Constructs the kinoko (infection) transform state.
 */
PikiKinokoChangeState::PikiKinokoChangeState()
    : PikiState(PIKISTATE_KinokoChange, "KINOKO_CHANGE")
{
}

/**
 * @brief Plays a transform animation and decides direction (enter/exit infection).
 */
void PikiKinokoChangeState::init(Piki* piki)
{
	if (piki->isKinoko()) {
		mDoBecomeKinoko = false;
	} else {
		mDoBecomeKinoko = true;
	}

	piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
}

/**
 * @brief Replays the transform sequence.
 */
void PikiKinokoChangeState::restart(Piki* piki)
{
	init(piki);
}

/**
 * @brief Freezes movement until the animation reaches the morph point.
 */
void PikiKinokoChangeState::exec(Piki* piki)
{
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_GrowUp1) {
		if (mDoBecomeKinoko) {
			piki->startKinoko();
		} else {
			piki->endKinoko();
		}
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiKinokoChangeState::cleanup(Piki* piki)
{
}

/**
 * @brief Applies the morph at the keyed moment and returns to normal.
 */
void PikiKinokoChangeState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		if (mDoBecomeKinoko) {
			piki->startKinoko();
			piki->playEventSound(piki->mLeaderCreature, SE_KINOKOPIKI_MORPH);
		} else {
			piki->endKinoko();
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @brief Constructs the nectar-driven grow-up state.
 */
PikiGrowupState::PikiGrowupState()
    : PikiState(PIKISTATE_GrowUp, "GROWUP")
{
}

/**
 * @brief Chooses which grow-up animation to play based on timer.
 */
void PikiGrowupState::init(Piki* piki)
{
	if (piki->mFloweringTimer < 1) {
		piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp1, piki), PaniMotionInfo(PIKIANIM_GrowUp1));
	} else {
		piki->startMotion(PaniMotionInfo(PIKIANIM_GrowUp2, piki), PaniMotionInfo(PIKIANIM_GrowUp2));
	}
}

/**
 * @brief Holds still during the grow-up animation and exits when complete.
 */
void PikiGrowupState::exec(Piki* piki)
{
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	int motionID = piki->getUpperMotionIndex();
	if (motionID != PIKIANIM_GrowUp1 && motionID != PIKIANIM_GrowUp2) {
		transit(piki, PIKISTATE_Normal);
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiGrowupState::cleanup(Piki* piki)
{
}

/**
 * @brief Applies the flower-stage upgrade on key events.
 */
void PikiGrowupState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		piki->mFloweringTimer++;
		seSystem->playPikiSound(SEF_PIKI_GROW4, piki->mSRT.t);
		piki->setFlower(Flower);
		playerState->mResultFlags.setOn(zen::RESFLAG_PikminSeeds);
		if (!playerState->mDemoFlags.isFlag(DEMOFLAG_FirstNectar) && !gameflow.mMoviePlayer->mIsActive && piki->aiCullable()) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_FirstNectar);
			gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_Mitu);
		}
		if (piki->mMode == PikiMode::FormationMode) {
			piki->mNavi->mPlateMgr->changeFlower(piki);
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @brief Constructs the shockwave stun state.
 */
PikiWaveState::PikiWaveState()
    : PikiState(PIKISTATE_Wave, "WAVE")
{
}

/**
 * @brief Shockwave handling is animation/driver controlled.
 */
void PikiWaveState::init(Piki* piki)
{
}

/**
 * @brief Shockwave handling is animation/driver controlled.
 */
void PikiWaveState::exec(Piki* piki)
{
}

/**
 * @brief No explicit cleanup.
 */
void PikiWaveState::cleanup(Piki* piki)
{
}

/**
 * @brief Allows interrupted shockwave states to return to normal.
 */
void PikiWaveState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/**
 * @brief Re-entry uses init/animation side effects.
 */
void PikiWaveState::restart(Piki* piki)
{
}

/**
 * @brief Returns to normal once the stun animation completes.
 */
void PikiWaveState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	case KEY_Action0:
	case KEY_Action1: // idk, nothing in the DLL about this
		break;
	}
}

/**
 * @brief Unused helper for applying a wave hit to the Piki.
 * @note UNUSED Size: 000004
 */
void PikiWaveState::waveAttack(Piki* piki)
{
}

/**
 * @brief Constructs the wall-pushing state.
 */
PikiPushState::PikiPushState()
    : PikiState(PIKISTATE_Push, "PUSH")
{
}

/**
 * @brief Starts the push animation and arms finish detection.
 */
void PikiPushState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Push, piki), PaniMotionInfo(PIKIANIM_Run));
	mIsFinishing = false;
}

/**
 * @brief Keeps pushing while the player input remains committed.
 */
void PikiPushState::exec(Piki* piki)
{
	piki->mMotionSpeed = 30.0f;
	Vector3f vec(piki->mNavi->mMainStick);
	Vector3f dir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
	if (vec.DP(dir) < 0.4f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	}

	if (!mIsFinishing && piki->mNavi->mCStick.length() <= 0.1f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	} else if (piki->mWallObj && AIConstant::_instance->mConstants._64()) {
		piki->_4D8 = 1;
	}
}

/**
 * @brief Clears the cached wall target.
 */
void PikiPushState::cleanup(Piki* piki)
{
	piki->mWallObj = nullptr;
}

/**
 * @brief If resumed, abandon pushing and return to normal.
 */
void PikiPushState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/**
 * @brief Re-entry uses init/animation side effects.
 */
void PikiPushState::restart(Piki* piki)
{
}

/**
 * @brief Stops pushing if the wall contact is lost.
 */
void PikiPushState::procOffWallMsg(Piki* piki, MsgOffWall*)
{
	piki->mPikiAnimMgr.finishMotion(piki);
}

/**
 * @brief Exits pushing when the animation completes.
 */
void PikiPushState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		if (piki->mWallObj && !AIConstant::_instance->mConstants._64()) {
			piki->_4D8 = 1;
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @brief Constructs the "pushing another Piki" variant.
 */
PikiPushPikiState::PikiPushPikiState()
    : PikiState(PIKISTATE_PushPiki, "PUSHPIKI")
{
}

/**
 * @brief Starts the push animation and initializes collision bookkeeping.
 */
void PikiPushPikiState::init(Piki* piki)
{
	piki->startMotion(PaniMotionInfo(PIKIANIM_Push, piki), PaniMotionInfo(PIKIANIM_Push));
	mCollisionFrameCount = 1;
	mIsFinishing         = false;
}

/**
 * @brief Continues the shove while the target remains in a push state.
 */
void PikiPushPikiState::exec(Piki* piki)
{
	if (!mIsFinishing && piki->mPushTargetPiki->getState() != PIKISTATE_Push && piki->mPushTargetPiki->getState() != PIKISTATE_PushPiki) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	}

	piki->mMotionSpeed = 30.0f;

	if (!mIsFinishing && piki->mNavi->mCStick.length() <= 0.1f) {
		piki->mPikiAnimMgr.finishMotion(piki);
		mIsFinishing = true;
	}

	mCollisionFrameCount = 0;
}

/**
 * @brief Clears the push target.
 */
void PikiPushPikiState::cleanup(Piki* piki)
{
	piki->mPushTargetPiki = nullptr;
}

/**
 * @brief If resumed, abandon pushing and return to normal.
 */
void PikiPushPikiState::resume(Piki* piki)
{
	transit(piki, PIKISTATE_Normal);
}

/**
 * @brief Re-entry uses init/animation side effects.
 */
void PikiPushPikiState::restart(Piki* piki)
{
}

/**
 * @brief Mirrors the pushed Piki's target direction when colliding with it.
 */
void PikiPushPikiState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	STACK_PAD_VAR(1);
	Creature* collider = msg->mEvent.mCollider;
	switch (collider->mObjType) {
	case OBJTYPE_Piki:
		Piki* other = (Piki*)collider;
		if (other->getState() == PIKISTATE_Push) {
			Vector3f pos(other->mPushTargetPos);
			piki->mFaceDirection = other->mFaceDirection;
			piki->mPushTargetPos = pos;
			mCollisionFrameCount = 1;
		}
	}
}

/**
 * @brief Ignored; pushing logic is driven by collisions/animation.
 */
void PikiPushPikiState::procWallMsg(Piki*, MsgWall*)
{
}

/**
 * @brief Exits pushing when the animation completes.
 */
void PikiPushPikiState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_LoopEnd:
		if (piki->mWallObj) {
			Vector3f dir(sinf(piki->mFaceDirection), 0.0f, cosf(piki->mFaceDirection));
			dir = dir * 2.0f;
			// this is just straight up how it is in the DLL, probably commented out code
		}
		break;
	case KEY_Finished:
		transit(piki, PIKISTATE_Normal);
		break;
	}
}

/**
 * @brief Constructs the bury (sprout creation) state.
 */
PikiBuryState::PikiBuryState()
    : PikiState(PIKISTATE_Bury, "BURY")
{
}

/**
 * @brief Burying is executed immediately in exec().
 */
void PikiBuryState::init(Piki* piki)
{
}

/**
 * @brief Spawns a sprout at the current position and erases the Piki.
 */
void PikiBuryState::exec(Piki* piki)
{
	// The developers were averse to Pikmin sprouts being placed in water, but if this code used by Miurin (Mamuta) were to actually
	// encounter water, it would produce uninitialized PikiHeadItems.  If stale data is found, this results in Pikmin sprout duplication.
	// If zero-initialized data is found, the Pikmin sprout will be unpluckable and will cause a crash during end-of-day cleanup.  In
	// order to fit everything into one if-statement, I had to abuse the comma operator.  This bug fix respects the developers' original
	// intentions, but their intentions make the Mamuta worthless when in water and allow sprouts where there is no ground triangle, so
	// you might wish to change it anyway.
#ifdef BUGFIX
	PikiHeadItem* sprout;
	if ((!piki->mGroundTriangle || MapCode::getAttribute(piki->mGroundTriangle) != ATTR_Water)
	    && (PikiHeadMgr::buryMode = true, sprout = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead), PikiHeadMgr::buryMode = false, sprout))
#else
	PikiHeadMgr::buryMode = true;
	PikiHeadItem* sprout  = (PikiHeadItem*)itemMgr->birth(OBJTYPE_Pikihead);
	PikiHeadMgr::buryMode = false;
	int attr              = ATTR_NULL;
	if (piki->mGroundTriangle) {
		attr = MapCode::getAttribute(piki->mGroundTriangle);
	}

	if (sprout && attr != ATTR_Water)
#endif
	{
		Vector3f pos(piki->mSRT.t);
		pos.y = mapMgr->getMinY(pos.x, pos.z, true);
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, pos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, pos, nullptr, nullptr);
		sprout->init(pos);
		sprout->setColor(piki->mColor);
		f32 angle = 2.0f * (PI * gsys->getRand(1.0f));
		sprout->mVelocity.set(220.0f * sinf(angle), 540.0f, 220.0f * cosf(angle));
		sprout->mFlowerStage = piki->mHappa;
		sprout->startAI(0);
		sprout->mParentOnion = nullptr;
		C_SAI(sprout)->start(sprout, PikiHeadAI::PIKIHEAD_Unk5);
		piki->setEraseKill();
		piki->kill(true);
		STACK_PAD_VAR(1);
		return;
	}

	transit(piki, PIKISTATE_Normal);
}

/**
 * @brief No explicit cleanup.
 */
void PikiBuryState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the "plucked but frozen" wait state.
 */
PikiNukareWaitState::PikiNukareWaitState()
    : PikiState(PIKISTATE_NukareWait, "NUKARE_WAIT")
{
}

/**
 * @brief Enters the pluck animation and optionally locks player input for tutorials.
 */
void PikiNukareWaitState::init(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mPikiAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_Nukareru, piki), PaniMotionInfo(PIKIANIM_Nukareru));

	if ((piki->mColor == Red && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckRedPikmin))
	    || (piki->mColor == Yellow && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckYellowPikmin))
	    || (piki->mColor == Blue && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckBluePikmin))) {
		gameflow.mGameInterface->message(MOVIECMD_SetPauseAllowed, FALSE);
	}
}

/**
 * @brief Holds the pluck animation at frame 0 until released.
 */
void PikiNukareWaitState::exec(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Nukareru) {
		piki->dump();
		ERROR("damedayo!");
	}

	piki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 0.0f;
	piki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 0.0f;
}

/**
 * @brief No explicit cleanup.
 */
void PikiNukareWaitState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the active pluck ("nukare") state.
 */
PikiNukareState::PikiNukareState()
    : PikiState(PIKISTATE_Nukare, "NUKARE")
{
}

/**
 * @brief Locks movement/input and arms tutorial/demo progression.
 */
void PikiNukareState::init(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
	playerState->mDemoFlags.setFlagOnly(DEMOFLAG_NoPikminTimeout);
	piki->finishLook();
	gameflow.mGameInterface->message(MOVIECMD_SetPauseAllowed, FALSE);
}

/**
 * @brief Plucking is animation-driven.
 */
void PikiNukareState::exec(Piki* piki)
{
}

/**
 * @brief Updates tutorial flags/unlocks after a successful pluck.
 */
void PikiNukareState::cleanup(Piki* piki)
{
	if (playerState->isTutorial() && !playerState->mDemoFlags.isFlag(DEMOFLAG_Pluck15thPikmin) && GameStat::allPikis >= 15) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Pluck15thPikmin);
		gameflow.mGameInterface->message(MOVIECMD_TextDemo, zen::ogScrTutorialMgr::TUT_NukiAndFree);
	}

	if (piki->mColor == Red && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckRedPikmin)) {
		PRINT("** NUKARE STATE CLEANUP !!!\n");
		playerState->mDemoFlags.setFlag(DEMOFLAG_PluckRedPikmin, piki);
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_NoPikminTimeout);
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_ApproachSeed);
		playerState->mDemoFlags.setTimer(demoParms->mParms._30(), DEMOFLAG_Unk9, naviMgr->getNavi());
		playerState->setDisplayPikiCount(Red);

	} else if (piki->mColor == Yellow && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckYellowPikmin)) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_PluckYellowPikmin, piki);
		playerState->mResultFlags.setOn(zen::RESFLAG_MeetYellowPikminNoBomb);
		playerState->mResultFlags.setOn(zen::RESFLAG_Onyons);
		playerState->setContainer(Yellow);
		playerState->setDisplayPikiCount(Yellow);

	} else if (piki->mColor == Blue && !playerState->mDemoFlags.isFlag(DEMOFLAG_PluckBluePikmin)) {
		playerState->mDemoFlags.setFlag(DEMOFLAG_PluckBluePikmin, piki);
		playerState->mResultFlags.setOn(zen::RESFLAG_MeetBluePikmin);
		playerState->setContainer(Blue);
		playerState->setDisplayPikiCount(Blue);

		// plucking a blue pikmin just. force unlocks the first 3 maps? sure.
		gameflow.mGamePrefs.openStage(STAGE_Practice);
		gameflow.mGamePrefs.openStage(STAGE_Forest);
		gameflow.mGamePrefs.openStage(STAGE_Cave);
	}

	gameflow.mGameInterface->message(MOVIECMD_SetPauseAllowed, TRUE);
}

/**
 * @brief Spawns pluck effects and returns the Piki to normal on finish.
 */
void PikiNukareState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		rumbleMgr->start(RUMBLE_Unk0, 0, nullptr);
		if (piki->mGroundTriangle && MapCode::getAttribute(piki->mGroundTriangle) == ATTR_Water) {
			effectMgr->create(EffectMgr::EFF_P_Bubbles, piki->mSRT.t, nullptr, nullptr);
		} else {
			effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mSRT.t, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mSRT.t, nullptr, nullptr);
		}
		break;
	case KEY_Finished:
		piki->mSRT.r.y       = piki->mNavi->mFaceDirection;
		piki->mFaceDirection = piki->mSRT.r.y;
		piki->mSRT.t         = piki->mShadowPos;
		f32 minY             = mapMgr->getMinY(piki->mSRT.t.x, piki->mSRT.t.z, true);
		if (minY > piki->mSRT.t.y) {
			PRINT("*** ABUNAI !!\n");
			piki->mSRT.t.y = minY + 1.0f;
		}
		transit(piki, PIKISTATE_Normal);
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		if (piki->mNavi->mIsCursorVisible == FALSE) {
			piki->mNavi->mPluckCursorVisibilityTimer++;
			if (piki->mNavi->mPluckCursorVisibilityTimer >= C_NAVI_PROP(piki->mNavi)._3EC()) {
				piki->mNavi->mIsCursorVisible = TRUE;
			}
		}
		break;
	}
}

/**
 * @brief Constructs the automatic unbury/unpluck recovery state.
 */
PikiAutoNukiState::PikiAutoNukiState()
    : PikiState(PIKISTATE_AutoNuki, "AUTONUKI")
{
}

/**
 * @brief Plays a recovery motion and freezes movement until it completes.
 */
void PikiAutoNukiState::init(Piki* piki)
{
	immut Choice motionChoice[1] = { PIKIANIM_Kaifuku, 1.0f }; // lol
	int motionIdx                = selectRandomly(motionChoice, 1);
	piki->mPikiAnimMgr.startMotion(PaniMotionInfo(motionIdx, piki), PaniMotionInfo(motionIdx));
	mToCreateEffect = false;
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @brief Spawns the dirt burst at the keyed animation moment.
 */
void PikiAutoNukiState::exec(Piki* piki)
{
	if (mToCreateEffect) {
		Vector3f pos(piki->mSRT.t); // lol
		effectMgr->create(EffectMgr::EFF_SD_DirtCloud, piki->mSRT.t, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_SD_DirtSpray, piki->mSRT.t, nullptr, nullptr);
		mToCreateEffect = false;
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiAutoNukiState::cleanup(Piki* piki)
{
}

/**
 * @brief Drives effect timing and exits to formation when finished.
 */
void PikiAutoNukiState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Action0:
		mToCreateEffect = true;
		SeSystem::playPlayerSe(SE_PIKI_PULLED);
		break;
	case KEY_Finished:
		piki->mSRT.t = piki->mShadowPos;
		transit(piki, PIKISTATE_Normal);
		piki->changeMode(PikiMode::FormationMode, piki->mNavi);
		break;
	}
}

/**
 * @brief Constructs the flattened (pressed) state.
 */
PikiPressedState::PikiPressedState()
    : PikiState(PIKISTATE_Pressed, "PRESSED")
{
}

/**
 * @brief Pressed-by-enemy collisions extend stun/invincibility.
 */
void PikiPressedState::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (msg->mEvent.mCollider->mObjType == OBJTYPE_Teki) {
		mStunTimer    = 1.5f;
		mIsInvincible = true;
	}
}

/**
 * @brief Flattens the model and enters a short invincibility window.
 */
void PikiPressedState::init(Piki* piki)
{
	f32 scale = 2.0f * C_PIKI_PROP(piki).mPikiDisplayScale();
	piki->mSRT.s.set(scale, 0.01f, scale);
	mStunTimer    = 1.5f;
	mIsInvincible = true;
	PRINT_KANDO("pressed init !\n");
}

/**
 * @brief Counts down press recovery and triggers death if health runs out.
 */
void PikiPressedState::exec(Piki* piki)
{
	if (!mIsInvincible) {
		piki->mDeathTimer -= gsys->getFrameTime();
	}

	if (piki->mDeathTimer > C_PIKI_PROP(piki).mPressDeathFactor() - C_PIKI_PROP(piki).mNormalPikiPressFactor() && piki->mHealth <= 0.0f) {
		PRINT("*** PRESS DIE ! timer = %.1f\n", piki->mDeathTimer);
		transit(piki, PIKISTATE_Dead);
		return;
	}

	if (piki->mDeathTimer < 0.0f) {
		piki->mDeathTimer = 0.0f;
		transit(piki, PIKISTATE_Normal);
		f32 scale = C_PIKI_PROP(piki).mPikiDisplayScale();
		piki->mSRT.s.set(scale, scale, scale);
	}

	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	if (mStunTimer > 0.0f) {
		mStunTimer -= gsys->getFrameTime();
	} else {
		mIsInvincible = false;
	}
}

/**
 * @brief No explicit cleanup.
 */
void PikiPressedState::cleanup(Piki* piki)
{
}

/**
 * @brief Constructs the dying (death animation) state.
 */
PikiDyingState::PikiDyingState()
    : PikiState(PIKISTATE_Dying, "DYING")
{
}

/**
 * @brief Stops current actions, plays a death anim, and drops held bombs.
 */
void PikiDyingState::init(Piki* piki)
{
	piki->mActiveAction->abandon(nullptr);
	immut Choice motionChoices[3] = {
		{ PIKIANIM_Dead, 0.33f },
		{ PIKIANIM_Dead2, 0.33f },
		{ PIKIANIM_Dead3, 0.33f },
	};

	int motionID = selectRandomly(motionChoices, 3);
	piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
	if (piki->hasBomb()) {
		BombItem* bomb = (BombItem*)piki->getHoldCreature();
		MsgUser msg(0);
		C_SAI(bomb)->procMsg(bomb, &msg);
		bomb->resetStateGrabbed();
	}
}

/**
 * @brief Holds still while the death animation plays.
 */
void PikiDyingState::exec(Piki* piki)
{
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @brief No explicit cleanup.
 */
void PikiDyingState::cleanup(Piki* piki)
{
}

/**
 * @brief Finishes dying by transitioning into the dead (fade/shrink) state.
 */
void PikiDyingState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (piki->isFired()) {
			piki->endFire();
			effectMgr->create(EffectMgr::EFF_Piki_FireRecover, piki->mEffectPos, nullptr, nullptr);
		}
		transit(piki, PIKISTATE_Dead);
		break;
	}
}

/**
 * @brief Constructs the dead (shrink-out) state.
 */
PikiDeadState::PikiDeadState()
    : PikiState(PIKISTATE_Dead, "DEAD")
{
}

/**
 * @brief Starts the shrink timer and detaches from any held object.
 */
void PikiDeadState::init(Piki* piki)
{
	piki->mDeathTimer = 1.5f;
	// this is probably some optimised OR check but i haven't figured out which. works for now.
	if (1 - piki->mMode == 0) { }
	piki->endStickObject();
}

/**
 * @brief Shrinks over time and destroys the Piki when the timer expires.
 */
void PikiDeadState::exec(Piki* piki)
{
	f32 scale = piki->mDeathTimer / 1.5f;
	piki->mSRT.s.set(scale, scale, scale);
	if (piki->mDeathTimer > 8.0f) {
		// also not in the DLL, i assume it's commented out code
	}
	piki->mDeathTimer -= gsys->getFrameTime();

	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	piki->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mDeathTimer < 0.0f) {
		piki->kill(false);
	}
}

/**
 * @brief Ensures the model is fully hidden at state exit.
 */
void PikiDeadState::cleanup(Piki* piki)
{
	piki->mSRT.s.set(0.0f, 0.0f, 0.0f);
}

/**
 * @brief Constructs the transient emotion/celebration state.
 */
PikiEmotionState::PikiEmotionState()
    : PikiState(PIKISTATE_Emotion, "EMOTION")
    , mCheerCount(0)
{
}

/**
 * @brief Selects an emotion animation/sound and optionally starts ship-part gazing.
 */
void PikiEmotionState::init(Piki* piki)
{
	mGazeFlag = EGP_None;
	if (piki->mEmotion == PikiEmotion::None) {
		return;
	}

	switch (piki->mEmotion) {
	case PikiEmotion::Excited: {
		immut Choice motionChoices[2] = {
			{ PIKIANIM_Jump_B1, 0.5f },
			{ PIKIANIM_Gattu, 0.5f },
		};

		int soundChoices[2] = {
			SEF_PIKI_JUMP1,
			SEF_PIKI_ANGRY1,
		};

		int randIdx  = (2.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
		PRINT("play sound %d\n", TERNARY_BUGFIX(soundChoices[randIdx], motionID)); // wrong variable kando
	} break;

	case PikiEmotion::Happy: {
		immut Choice motionChoices[3] = {
			{ PIKIANIM_Jump_B1, 0.33f },
			{ PIKIANIM_Jump, 0.33f },
			{ PIKIANIM_RotJump, 0.33f },
		};

		int soundChoices[3] = {
			SEF_PIKI_JUMP1,
			SEF_PIKI_JUMP2,
			SEF_PIKI_JUMP3,
		};

		int randIdx  = (3.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Searching: {
		immut Choice motionChoices[2] = {
			{ PIKIANIM_Sagasu, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int motionID = selectRandomly(motionChoices, 2);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Confused: {
		immut Choice motionChoices[2] = {
			{ PIKIANIM_Gakkari, 0.5f },
			{ PIKIANIM_Sagasu2, 0.5f },
		};

		int soundChoices[2] = {
			SEF_PIKI_GAKKARI,
			SEF_PIKI_SNEEZE,
		};

		int randIdx  = (2.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
	} break;

	case PikiEmotion::Sad: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Gakkari, piki), PaniMotionInfo(PIKIANIM_Gakkari));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_GAKKARI, piki->mSRT.t);
	} break;

	case PikiEmotion::ShookDry: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Mizuage, piki), PaniMotionInfo(PIKIANIM_Mizuage));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_BURUBURU, piki->mSRT.t);
	} break;

	case PikiEmotion::Victorious: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Jump_B1, piki), PaniMotionInfo(PIKIANIM_Jump_B1));
		piki->mPikiAnimMgr.finishMotion(piki);
		seSystem->playPikiSound(SEF_PIKI_YATTA, piki->mSRT.t);
	} break;

	case PikiEmotion::ShipPartGaze: {
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		piki->startLook(&piki->mCarryingShipPart->mSRT.t);
		mGazeFlag = EGP_Gazing;
	} break;

	case PikiEmotion::ShipPartCheer: {
		immut Choice motionChoices[5] = {
			{ PIKIANIM_Jump, 0.2f },   { PIKIANIM_Jump_B1, 0.2f }, { PIKIANIM_RotJump, 0.2f },
			{ PIKIANIM_Rinbow, 0.2f }, { PIKIANIM_Gattu, 0.2f },
		};

		int soundChoices[5] = {
			SEF_PIKI_JUMP1, SEF_PIKI_JUMP2, SEF_PIKI_JUMP3, SEF_PIKI_NOBI, SEF_PIKI_YATTA,
		};

		int randIdx  = (5.0f * gsys->getRand(1.0f)) * 0.9999f;
		int motionID = motionChoices[randIdx].mValue;
		seSystem->playPikiSound(soundChoices[randIdx], piki->mSRT.t);
		piki->startMotion(PaniMotionInfo(motionID, piki), PaniMotionInfo(motionID));
		piki->mPikiAnimMgr.finishMotion(piki);
		if (mCheerCount == 0) {
			mCheerCount = 5;
			piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
			piki->startLook(&piki->mCarryingShipPart->mSRT.t);
			mGazeFlag = EGP_Gazing;
		}
	} break;
	}
}

/**
 * @brief Debug dump of gaze/emotion bookkeeping.
 */
void PikiEmotionState::doDump()
{
	PRINT("gazeFlag=%d rapCnt=%d timer=%.1f gazePos(%.1f %.1f %.1f)\n", mGazeFlag, mCheerCount, mTimer, mGazePosition.x, mGazePosition.y,
	      mGazePosition.z);
}

/**
 * @brief Advances special gaze sequencing and exits when emotion clears.
 */
void PikiEmotionState::exec(Piki* piki)
{
	piki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (piki->mEmotion == PikiEmotion::None) {
		transit(piki, PIKISTATE_Normal);
	}

	if (piki->mEmotion == PikiEmotion::ShipPartGaze || (piki->mEmotion == PikiEmotion::ShipPartCheer && mCheerCount == 5)) {
		switch (mGazeFlag) {
		case EGP_Gazing:
			// If the part disappears, keep gazing at its last known position for a moment.
			if (!piki->mCarryingShipPart->isAlive()) {
				mGazeFlag     = EGP_HoldLastPos;
				mGazePosition = piki->mCarryingShipPart->mSRT.t;
				piki->startLook(&mGazePosition);
				mTimer = (0.4f * gsys->getRand(1.0f)) + 1.5f;
			}
			break;
		case EGP_HoldLastPos:
			// After a short delay, stop looking and allow the animation to end naturally.
			mTimer -= gsys->getFrameTime();
			if (mTimer < 0.0f) {
				piki->finishLook();
				mGazeFlag = EGP_Done;
				piki->mPikiAnimMgr.finishMotion(piki);
			}
			break;
		case EGP_Done:
			// Nothing to do; wait for procAnimMsg to transition out.
			break;
		}
	}
}

/**
 * @brief Clears emotion state and look targets.
 */
void PikiEmotionState::cleanup(Piki* piki)
{
	piki->mEmotion          = PikiEmotion::None;
	piki->mCarryingShipPart = nullptr;
	piki->finishLook();
}

/**
 * @brief Loops cheer animations a fixed number of times, then returns to normal.
 */
void PikiEmotionState::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	switch (msg->mKeyEvent->mEventType) {
	case KEY_Finished:
		if (piki->mEmotion == PikiEmotion::ShipPartCheer) {
			mCheerCount--;
			if (mCheerCount) {
				init(piki);
				break;
			}
		}

		mCheerCount = 0;
		transit(piki, PIKISTATE_Normal);
		break;
	}
}
