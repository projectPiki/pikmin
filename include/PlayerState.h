#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H

#include "types.h"
#include "Demo.h"
#include "ResultFlags.h"
#include "PaniPikiAnimator.h"
#include "UtilityKando.h"
#include "PelletAnimator.h"
#include "Shape.h"
#include "Piki.h"

struct Graphics;
struct PelletShapeObject;
struct PermanentEffect;
struct PikiShapeObject;
struct Shape;

/**
 * @brief TODO
 */
struct UfoPartsInfo {
	u32 _00; // _00
	u8 _04;  // _04
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

		int getSum() { return mNum[0] + mNum[1] + mNum[2]; }

		int mNum[3]; // _00
	};

	TimeGraph(); // unused/inlined

	// unused/inlined:
	void create(u16, u16);
	void init();
	void set(u16, int, int);
	int get(u16, int);

	u16 _00;      // _00
	u16 _02;      // _02
	PikiNum* _04; // _04
};

/**
 * @brief TODO
 */
struct PlayerState {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0xE0.
	 */
	struct UfoParts : public PaniAnimKeyListener {
		UfoParts() { }

		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		void initAnim(PelletShapeObject*);

		// unused/inlined:
		void startMotion(int);
		void startMotion(int, int);
		void stopMotion();

		// DLL inlines:
		void setMotionSpeed(f32 speed) { _D8 = speed; }

		// _00 = VTBL
		int mPartIndex;                       // _04
		u32 mModelID;                         // _08
		u32 mPelletId;                        // _0C
		PelletAnimator mAnimator;             // _10
		Vector3f _B8;                         // _B8
		ShapeDynMaterials mAnimatedMaterials; // _C4
		PelletShapeObject* mPelletShape;      // _D4
		f32 _D8;                              // _D8
		u8 _DC;                               // _DC
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
	bool hasUfoParts(u32);
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
	void registerUfoParts(int, u32, u32);
	void ufoAssignStart();
	void startSpecialMotions();
	void startAfterMotions();
	void startUfoPartsMotion(u32, int, bool);
	void getUfoParts(u32, bool);
	int getNextPowerupNumber();
	void preloadHenkaMovie();
	UfoParts* findUfoParts(u32);
	void renderParts(Graphics&, Shape*);

	// unused/inlined:
	void setDebugMode();
	int getCardPikiCount(int);
	int getUfoPercentage();
	void init();
	int getFinalBornPikis();
	int getRestParts();
	void lostUfoParts(u32);

	// these MIGHT be hasContainer and setContainer and vice versa
	void setBootContainer(int color) { _184 |= 1 << color + 3; }
	bool bootContainer(int color) { return _184 & (1 << color + 3); }

	int getLastPikmins() { return _1A8; }

	void setContainer(int color) { _184 |= 1 << color; }
	bool hasContainer(int color) { return _184 & (1 << color); }

	bool inDayEnd() { return mInDayEnd; }
	void setDayEnd(bool set) { mInDayEnd = set; }

	bool isChallengeMode() { return mIsChallengeMode; }

	bool hasUfoLeftControl() { return _11 & 4; }
	bool hasUfoRightControl() { return _11 & 2; }
	bool hasRadar() { return _11 & 1; }

	void setDayCollectCount(int day, int parts) { mPartsCollectedByDay[day] = parts; }
	void setDayPowerupCount(int day, int parts) { mPartsToNextByDay[day] = parts; }

	/*
	    All remaining DLL inlines:

	    int getDayCollectCount(int);
	    int getLastPikmins();
	*/

	static int totalUfoParts;

	int mSproutedNum;             // _00
	int mLostBattlePikis;         // _04
	int mLeftBehindPikis;         // _08
	int _0C;                      // _0C
	u8 mShipUpgradeLevel;         // _10
	u8 _11;                       // _11
	UfoParts* _14;                // _14
	u8 mPartsCollectedByDay[30];  // _18
	u8 mPartsToNextByDay[30];     // _38
	DemoFlags mDemoFlags;         // _54
	ResultFlags mResultFlags;     // _70
	u8 _BC;                       // _BC
	PikiShapeObject* _C0;         // _C0
	PaniPikiAnimMgr mPikiAnimMgr; // _C4
	int mTotalRegisteredParts;    // _170
	int mTotalParts;              // _174
	UfoParts* mUfoParts;          // _178
	int mCurrParts;               // _17C
	int _180;                     // _180
	u8 _184;                      // _184
	bool _185;                    // _185
	bool _186;                    // _186
	u8 _187[5];                   // _187
	TimeGraph _18C;               // _18C
	u16 _194;                     // _194
	TimeGraph _198;               // _198
	int _1A0;                     // _1A0, final dead pikis count?
	int _1A4;                     // _1A4
	int _1A8;                     // _1A8
	u8 mDisplayPikiFlag;          // _1AC
	BitFlags** mCourseFlags;      // _1B0
	u8 _1B4;                      // _1B4
	bool mInDayEnd;               // _1B5
	bool mIsChallengeMode;        // _1B6
	PermanentEffect* _1B8;        // _1B8
	PermanentEffect* _1BC;        // _1BC
	Vector3f _1C0;                // _1C0
};

extern bool preloadUFO;
extern PlayerState* playerState;

#endif
