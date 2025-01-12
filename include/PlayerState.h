#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H

#include "types.h"
#include "Demo.h"
#include "ResultFlags.h"
#include "PaniPikiAnimator.h"
#include "PelletAnimator.h"
#include "Shape.h"

struct Graphics;
struct PelletShapeObject;
struct PermanentEffect;
struct Shape;

/**
 * @brief TODO
 */
struct TimeGraph {

	/**
	 * @brief TODO
	 */
	struct PikiNum {

		void set(int, int);

		int mNum[3]; // _00
	};

	TimeGraph(); // unused/inlined

	// unused/inlined:
	void create(u16, u16);
	void init();
	void set(u16, int, int);
	void get(u16, int);

	// TODO: members
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
		UfoParts();

		virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

		void initAnim(PelletShapeObject*);

		// unused/inlined:
		void startMotion(int);
		void startMotion(int, int);
		void stopMotion();

		// _00 = VTBL
		int _04;                              // _04
		u32 mModelID;                         // _08
		u32 _0C;                              // _0C
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
	void getPartsGetCount(int);
	int getCardUfoPartsCount();
	void getTotalPikiCount(int);
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	bool isTutorial();
	bool isGameCourse();
	void checkLimitGenFlag(int);
	void setLimitGenFlag(int);
	void displayPikiCount(int);
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
	void getNextPowerupNumber();
	void preloadHenkaMovie();
	void findUfoParts(u32);
	void renderParts(Graphics&, Shape*);

	// unused/inlined:
	void setDebugMode();
	void getCardPikiCount(int);
	void getUfoPercentage();
	void init();
	void getFinalBornPikis();
	void getRestParts();
	void lostUfoParts(u32);

	inline bool is184(u32 flag) { return _184 & (1 << flag); }

	static int totalUfoParts;

	u8 _00[0x10];                 // _00, unknown
	u8 _10;                       // _10
	u8 _11;                       // _11
	u8 _12[0x54 - 0x12];          // _12, unknown
	DemoFlags mDemoFlags;         // _54
	ResultFlags mResultFlags;     // _70
	u8 _BC[0xC4 - 0xBC];          // _BC, unknown
	PaniPikiAnimMgr mPikiAnimMgr; // _C4
	int mTotalRegisteredParts;    // _170
	int mTotalParts;              // _174
	UfoParts* mUfoParts;          // _178
	int mCurrParts;               // _17C
	int _180;                     // _180
	u8 _184;                      // _184
	bool _185;                    // _185
	u8 _186;                      // _186
	u8 _187;                      // _187
	u8 _188;                      // _188, might be piki discovery flag?
	u8 _189;                      // _189
	u8 _18A;                      // _18A
	u8 _18B;                      // _18B
	u8 _18C[0x1A0 - 0x18C];       // _18C, unknown
	int _1A0;                     // _1A0, final dead pikis count?
	u8 _1A4[0x1AC - 0x1A4];       // _1A4, unknown
	u8 _1AC;                      // _1AC
	u8 _1AD[0x1B4 - 0x1AD];       // _1AD, unknown
	u8 _1B4;                      // _1B4
	u8 _1B5;                      // _1B5
	u8 _1B6;                      // _1B6
	PermanentEffect* _1B8;        // _1B8
	PermanentEffect* _1BC;        // _1BC
	Vector3f _1C0;                // _1C0
};

extern bool preloadUFO;
extern PlayerState* playerState;

#endif
