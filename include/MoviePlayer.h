#ifndef _MOVIEPLAYER_H
#define _MOVIEPLAYER_H

#include "types.h"
#include "CoreNode.h"
#include "CinematicPlayer.h"

struct Creature;
struct Graphics;
struct Vector3f;

/**
 * @brief TODO
 */
struct MovieListInfo {
	int mMovieID;       // _00
	char* mCinFileName; // _04
};

/**
 * @brief TODO
 */
struct MovieTransInfo {
	u32 mMovieID;     // _00
	int* mTransTable; // _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x60.
 */
struct MovieInfo : public CoreNode {
	MovieInfo()
	    : CoreNode("")
	{
		mCin = nullptr;
	}

	// unused/inlined:
	bool update();
	bool setCamera(Graphics&);
	void refresh(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mMovieIndex;       // _14
	CinematicPlayer* mCin; // _18
	Matrix4f _1C;          // _1C
	u32 _5C;               // _5C
};

/**
 * @brief TODO
 *
 * @note Size: 0x174.
 */
struct MoviePlayer {
	MoviePlayer();

	void resetMovieList();
	void fixMovieList();
	void initMovie(MovieInfo*, int);
	void startMovie(int movieIdx, int, Creature* target, Vector3f* pos, Vector3f* rot, u32 p6, bool isPlaying);
	void sndStartMovie(MovieInfo*);
	void initMovieFlags(MovieInfo*);
	void sndStopMovie(MovieInfo*);
	void update();
	void skipScene(int);
	void getLookAtPos(Vector3f&);
	bool setCamera(Graphics&);
	void addLights(Graphics&);
	void refresh(Graphics&);

	// unused/inlined:
	MovieListInfo* findMovie(int);
	int translateIndex(int, int);
	void sndFrameMovie(MovieInfo*);
	void nextFrame();
	void backFrame();

	void setGameCamInfo(bool flag, f32 a1, Vector3f& a2, Vector3f& a3)
	{
		_16C = flag;
		_160 = a1;
		_148 = a2;
		_154 = a3;
	}

	MovieInfo mPlayInfoList;   // _00
	MovieInfo mMovieInfoList;  // _60
	MovieInfo mStackInfoList;  // _C0
	int mCurrentFrame;         // _120
	bool mIsActive;            // _124
	u8 _125;                   // _125
	u32 _128;                  // _128
	Vector3f mTargetViewpoint; // _12C
	Vector3f mLookAtPos;       // _138
	f32 mTargetFov;            // _144
	Vector3f _148;             // _148
	Vector3f _154;             // _154
	f32 _160;                  // _160
	f32 _164;                  // _164
	f32 mCamTransitionFactor;  // _168
	bool _16C;                 // _16C
	u32 _170;                  // _170, unknown
};

/**
 * @brief TODO
 *
 * @note I have these down here because it's a stupid big enum
 */
enum CinDemoIDs {
	DEMOID_NULL            = 0,
	DEMOID_OpeningIntroPt1 = 1,
	DEMOID_OpeningIntroPt2 = 2,
	DEMOID_OlimarWakeUp    = 3,

	DEMOID_FindOnyon       = 4, // translated for each stage
	DEMOID_FindRedOnyon    = 4, // a.k.a. tutorial
	DEMOID_FindYellowOnyon = 5, // a.k.a. forest
	DEMOID_FindBlueOnyon   = 6, // a.k.a. cave - yakushima + last use this one too

	DEMOID_LookAtFirstSprout  = 7,
	DEMOID_WaitForFirstSprout = 8,

	DEMOID_MeetPikmin       = 9,  // translated for each stage
	DEMOID_MeetRedPikmin    = 9,  // a.k.a. tutorial
	DEMOID_MeetYellowPikmin = 10, // a.k.a. forest
	DEMOID_MeetBluePikmin   = 11, // a.k.a. cave - yakushima + last use this one too

	DEMOID_Unk12              = 12,
	DEMOID_Unk13              = 13,
	DEMOID_CollectFirstPellet = 14,
	DEMOID_PushFirstBox       = 15,
	DEMOID_DiscoverMainEngine = 16,

	DEMOID_ShipUpgrade         = 17, // translated for each stage
	DEMOID_ShipUpgradeTutorial = 17,
	DEMOID_ShipUpgradeForest   = 18,
	DEMOID_ShipUpgradeCave     = 19,

	DEMOID_CollectPart              = 79, // translated for each stage
	DEMOID_CollectFirstPartTutorial = 20,
	DEMOID_CollectPartForest        = 21,
	DEMOID_CollectPartCaveLast      = 22,
	DEMOID_CollectPartYakushima     = 23,
	DEMOID_Unk24                    = 24,
	DEMOID_ShipUpgradeYakushima     = 25,
	DEMOID_ShipUpgradeLast          = 26, // a.k.a. the start of the good ending
	// ...

	DEMOID_DayEnd          = 28, // translated for each stage
	DEMOID_DayEndTutorial  = 28,
	DEMOID_DayEndForest    = 29,
	DEMOID_DayEndCaveLast  = 30,
	DEMOID_DayEndYakushima = 31,

	DEMOID_ChalDayEnd          = 32, // translated for each stage
	DEMOID_ChalDayEndTutorial  = 32,
	DEMOID_ChalDayEndForest    = 33,
	DEMOID_ChalDayEndCave      = 34,
	DEMOID_ChalDayEndYakushima = 35,
	DEMOID_EndOfDayResults     = 36, // for both story and challenge modes
	DEMOID_Unk37               = 37,
	DEMOID_Unk38               = 38,
	DEMOID_Unk39               = 39,

	DEMOID_Landing          = 40, // translated for each stage
	DEMOID_LandingTutorial  = 40, // for both story and challenge modes
	DEMOID_LandingForest    = 41, // for both story and challenge modes
	DEMOID_LandingCaveLast  = 42, // for both story and challenge modes
	DEMOID_LandingYakushima = 43, // for both story and challenge modes

	DEMOID_PikminInOnyon         = 44, // translated for each stage
	DEMOID_PikminInOnyonTutorial = 44,
	DEMOID_PikminInOnyonForest   = 45,
	DEMOID_Extinction            = 46,

	DEMOID_ExtDayEnd          = 47, // translated for each stage
	DEMOID_ExtDayEndTutorial  = 47, // day ends after extinction
	DEMOID_ExtDayEndForest    = 48,
	DEMOID_ExtDayEndCaveLast  = 49,
	DEMOID_ExtDayEndYakushima = 50,
	DEMOID_OlimarDown         = 51,

	DEMOID_OliDownDayEnd          = 52, // translated for each stage
	DEMOID_OliDownDayEndTutorial  = 52, // day ends after olimar is at 0 health
	DEMOID_OliDownDayEndForest    = 53,
	DEMOID_OliDownDayEndCaveLast  = 54,
	DEMOID_OliDownDayEndYakushima = 55,

	DEMOID_TakeOff          = 56, // translated for each stage
	DEMOID_TakeOffTutorial  = 56, // taking off at day end
	DEMOID_TakeOffForest    = 57,
	DEMOID_TakeOffCaveLast  = 58,
	DEMOID_TakeOffYakushima = 59,

	DEMOID_Unk60Cat = 60, // translated for each stage, unsure what it's for though
	DEMOID_Unk60    = 60,
	DEMOID_Unk61    = 61,
	DEMOID_Unk62    = 62,
	DEMOID_Unk63    = 63,

	DEMOID_Unk64Cat       = 64, // translated for each stage, unsure what it's for though
	DEMOID_Unk64          = 64,
	DEMOID_Unk65          = 65,
	DEMOID_Unk66          = 66,
	DEMOID_Unk67          = 67,
	DEMOID_YellowWithBomb = 68,

	DEMOID_BadEnding           = 69, // translated for each stage
	DEMOID_BadEndingTutorial   = 69, // also used for start of neutral ending
	DEMOID_BadEndingForest     = 70,
	DEMOID_BadEndingCaveLast   = 71,
	DEMOID_BadEndingYakushima  = 72,
	DEMOID_BadEndingFailEscape = 73, // olimar tries to escape and fails
	DEMOID_BadEndingOlimin     = 74, // olimin cutscene (relative to red onyon)
	DEMOID_GoodEndingWave      = 75, // saying goodbye to the pikmin
	DEMOID_GoodEndingOnyons    = 76, // ship flying in space with the onyons
	DEMOID_EndingSpace         = 77, // flying through space (good and neutral)
	DEMOID_CollectRadar        = 78,
	DEMOID_CollectPartTutorial = 79,
	DEMOID_Unk80               = 80,
	DEMOID_EndOfDayRedOnyon    = 84,
	DEMOID_EndOfDayYellowOnyon = 85,
	DEMOID_EndOfDayBlueOnyon   = 86,
	// ...
	DEMOID_ChalDayEndLast       = 88,  // day end at final trial
	DEMOID_DayEndTakeOffLast    = 109, // day end take off at final trial
	DEMOID_GoodEndingTakeOff    = 113, // ship takes off
	DEMOID_NeutralEndingLeaveOK = 114, // olimar leaves successfully
};

#endif
