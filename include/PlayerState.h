#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H

#include "Demo.h"
#include "GlobalGameOptions.h"
#include "PaniPikiAnimator.h"
#include "PelletAnimator.h"
#include "Piki.h"
#include "ResultFlags.h"
#include "Shape.h"
#include "UtilityKando.h"
#include "types.h"

struct Graphics;
struct PelletShapeObject;
struct PermanentEffect;
struct PikiShapeObject;
struct Shape;

/**
 * @brief TODO
 */
enum UfoPartVisType {
	PARTVIS_Uncollected = 0, // have not collected part yet
	PARTVIS_Visible     = 1, // have collected part, displays on ship
	PARTVIS_Invisible   = 2, // have collected part, does not display on ship
};

/**
 * @brief TODO
 */
struct UfoPartsInfo {
	u32 mPartID;      // _00
	bool mUnusedFlag; // _04
};

/**
 * @brief TODO
 */
struct TimeGraph {

	/**
	 * @brief TODO
	 */
	struct PikiNum {

		void set(int color, int num)
		{
			if (color >= PikiMinColor && color <= PikiMaxColor) {
				mNum[color] = num;
				return;
			}

			// cannot condense these or this inlines incorrectly lmfao
			mNum[Yellow] = num;
			mNum[Red]    = num;
			mNum[Blue]   = num;
		}

		int get(int color)
		{
			if (color >= PikiMinColor && color <= PikiMaxColor) {
				return mNum[color];
			}
			return getSum();
		}

		int getSum() { return mNum[Blue] + mNum[Red] + mNum[Yellow]; }

		int mNum[PikiColorCount]; // _00
	};

	TimeGraph(); // unused/inlined

	// unused/inlined:
	void create(u16 startTime, u16 endTime);
	void init();
	void set(u16 time, int color, int num);
	int get(u16 time, int color);

	u16 mStartTime;    // _00
	u16 mEndTime;      // _02
	PikiNum* mEntries; // _04
};

/**
 * @brief TODO
 */
struct PlayerState {
public:
	/**
	 * @brief TODO
	 *
	 * @note Size: 0xE0.
	 */
	struct UfoParts : public PaniAnimKeyListener {
		UfoParts() { }

		virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

		void initAnim(PelletShapeObject*);

		// unused/inlined:
		void startMotion(int);
		void startMotion(int, int);
		void stopMotion();

		// DLL inlines:
		void setMotionSpeed(f32 speed) { mMotionSpeed = speed; }

		// _00 = VTBL
		int mRepairAnimJointIndex;            // _04
		u32 mModelID;                         // _08
		u32 mPelletID;                        // _0C
		PelletAnimator mAnimator;             // _10
		Vector3f mRepairEffectPosition;       // _B8
		ShapeDynMaterials mAnimatedMaterials; // _C4
		PelletShapeObject* mPelletShape;      // _D4
		f32 mMotionSpeed;                     // _D8, specifically 'lower' anim speed (upper always 30.0f)
		u8 mPartVisType;                      // _DC, see UfoPartVisType enum
	};

	PlayerState();

	bool isEnding();
	bool existUfoParts(u32);
	void initGame();
	bool courseOpen(int);
	bool happyEndable();
	void setChallengeMode();
	int getPartsGetCount(int);
	int getCardUfoPartsCount();
	int getTotalPikiCount(int);
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	bool isTutorial();
	bool isGameCourse();
	bool checkLimitGenFlag(int);
	void setLimitGenFlag(int);
	bool displayPikiCount(int);
	void setDisplayPikiCount(int);
	bool hasUfoParts(u32 ufoIndex);
	void update();
	void initCourse();
	void exitCourse();
	void setNavi(bool);
	int getFinalDeadPikis();
	void updateFinalResult();
	int getCurrDay();
	int getTotalDays();
	int getStartHour();
	int getEndHour();
	int getPikiHourCount(int, int);
	int getTotalParts();
	int getCurrParts();
	bool isUfoBroken();
	void registerUfoParts(int repairAnimJointIndex, u32 modelID, u32 pelletID);
	void ufoAssignStart();
	void startSpecialMotions();
	void startAfterMotions();
	void startUfoPartsMotion(u32, int, bool);
	void getUfoParts(u32, bool);
	int getNextPowerupNumber();
	void preloadHenkaMovie();
	void renderParts(Graphics&, Shape*);

	// unused/inlined:
	void setDebugMode();
	int getCardPikiCount(int);
	int getUfoPercentage();
	void init();
	int getFinalBornPikis();
	int getRestParts();
	void lostUfoParts(u32);

	void setContainer(int color) { mContainerFlag |= 1 << color; }
	bool hasContainer(int color) { return mContainerFlag & (1 << color); }

	void setBootContainer(int color) { mContainerFlag |= 1 << color + 3; }
	bool bootContainer(int color) { return mContainerFlag & (1 << color + 3); }

	int getLastPikmins() { return mLivingPikiNum; }

	bool inDayEnd() { return mInDayEnd; }
	void setDayEnd(bool set) { mInDayEnd = set; }

	bool isChallengeMode() { return mIsChallengeMode; }

	bool hasUfoRightControl() { return mShipEffectPartFlag & 4; }
	bool hasUfoLeftControl() { return mShipEffectPartFlag & 2; }
	bool hasRadar() { return mShipEffectPartFlag & 1; }

	void setDayCollectCount(int day, int parts) { mPartsCollectedByDay[day] = parts; }
	void setDayPowerupCount(int day, int parts) { mPartsToNextByDay[day] = parts; }
	int getDayCollectCount(int day) { return mPartsCollectedByDay[day]; }
	int getDayPowerupCount(int day) { return mPartsToNextByDay[day]; }

protected:
	UfoParts* findUfoParts(u32); // Was it really necessary to make this protected?

	static int totalUfoParts;

public:
	int mSproutedNum;                     // _00
	int mLostBattlePikis;                 // _04
	int mLeftBehindPikis;                 // _08
	int mTotalPluckedPikiCount;           // _0C, tracker for attention camera (stops zooming when >= 100)
	u8 mShipUpgradeLevel;                 // _10
	u8 mShipEffectPartFlag;               // _11, for radar + the ionium jets
	UfoParts* mCurrentRepairingPart;      // _14
	u8 mPartsCollectedByDay[MAX_DAYS];    // _18
	u8 mPartsToNextByDay[MAX_DAYS];       // _38
	DemoFlags mDemoFlags;                 // _54
	ResultFlags mResultFlags;             // _70
	bool mHasExtinctionDemoPlayed;        // _BC, only one extinction cutscene per day/course load
	PikiShapeObject* mOlimarShapeObj;     // _C0
	PaniPikiAnimMgr mOlimarAnimMgr;       // _C4
	int mTotalRegisteredParts;            // _170
	int mTotalParts;                      // _174
	UfoParts* mUfoParts;                  // _178, indexed by UfoPartIndex enum
	int mCurrParts;                       // _17C
	int mRequiredUfoPartCount;            // _180
	u8 mContainerFlag;                    // _184
	bool mIsTutorialMode;                 // _185
	bool _186;                            // _186, saved and reloaded, but never used
	u8 mStagePartsCollected[STAGE_COUNT]; // _187
	TimeGraph mPerHourGraph;              // _18C
	u16 mLastUpdatedTime;                 // _194
	TimeGraph mPerDayGraph;               // _198, initialised but never updated/used
	int mTotalDeadPikiNum;                // _1A0
	int mTotalBornPikiNum;                // _1A4
	int mLivingPikiNum;                   // _1A8
	u8 mDisplayPikiFlag;                  // _1AC
	BitFlags** mCourseFlags;              // _1B0
	bool mIsNaviPilot;                    // _1B4
	bool mInDayEnd;                       // _1B5
	bool mIsChallengeMode;                // _1B6
	PermanentEffect* mNaviLightEfx;       // _1B8
	PermanentEffect* mNaviLightGlowEfx;   // _1BC
	Vector3f mNaviLightEfxPos;            // _1C0
};

extern bool preloadUFO;
extern PlayerState* playerState;

#endif
