#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H

#include "types.h"
#include "Demo.h"
#include "ResultFlags.h"
#include "PaniAnimator.h"

struct Graphics;
struct PelletShapeObject;
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

		// TODO: members
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

		// _00 = VTBL?
		u8 _04[0xE0 - 0x4]; // _04, unknown
	};

	PlayerState();

	bool isEnding();
	bool existUfoParts(u32);
	void initGame();
	void courseOpen(int);
	void happyEndable();
	void setChallengeMode();
	void getPartsGetCount(int);
	void getCardUfoPartsCount();
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
	void getFinalDeadPikis();
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

	static int totalUfoParts;

	// TODO: members
	u8 _00[0x54];                 // _00, unknown
	DemoFlags mDemoFlags;         // _54
	ResultFlags mResultFlags;     // _70
	u8 _BC[0xC4 - 0xBC];          // _BC, unknown
	PaniPikiAnimMgr mPikiAnimMgr; // _C4
	u8 _C8[0x174 - 0xC8];         // _C8, adjust when size of PaniPikiAnimMgr is known
	int mTotalParts;              // _174
	UfoParts* mUfoParts;          // _178
	int mCurrParts;               // _17C
	u32 _180;                     // _180, unknown
	u8 _184;                      // _184
	u8 _185;                      // _185
	u8 _186;                      // _186
	u8 _187;                      // _187
	u8 _188;                      // _188
	u8 _189;                      // _189
	u8 _18A;                      // _18A
	u8 _18B;                      // _18B
	u8 _18C[0x1C0 - 0x18C];       // _18C, unknown
	Vector3f _1C0;                // _1C0
};

extern bool preloadUFO;
extern PlayerState* playerState;

#endif
