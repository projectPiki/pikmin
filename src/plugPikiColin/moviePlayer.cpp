#include "MoviePlayer.h"
#include "system.h"
#include "gameflow.h"
#include "Interface.h"
#include "ItemMgr.h"
#include "GoalItem.h"
#include "RumbleMgr.h"
#include "FlowController.h"
#include "Graphics.h"
#include "PlayerState.h"
#include "EffectMgr.h"
#include "jaudio/pikidemo.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("MoviePlayer")

static MovieListInfo movieTitles[] = {
	{ DEMOID_OpeningIntroPt1, "cinemas/demo01.cin" },
	{ DEMOID_OpeningIntroPt2, "cinemas/demo02.cin" },
	{ DEMOID_OlimarWakeUp, "cinemas/demo03.cin" },
	{ DEMOID_FindRedOnyon, "cinemas/demo04.cin" },
	{ DEMOID_FindYellowOnyon, "cinemas/demo05.cin" },
	{ DEMOID_FindBlueOnyon, "cinemas/demo06.cin" },
	{ DEMOID_LookAtFirstSprout, "cinemas/demo07.cin" },
	{ DEMOID_WaitForFirstSprout, "cinemas/demo08.cin" },
	{ DEMOID_MeetRedPikmin, "cinemas/demo09.cin" },
	{ DEMOID_MeetYellowPikmin, "cinemas/demo10.cin" },
	{ DEMOID_MeetBluePikmin, "cinemas/demo11.cin" },
	{ DEMOID_Unk12, "cinemas/demo12.cin" },
	{ DEMOID_Unk13, "cinemas/demo13.cin" },
	{ DEMOID_CollectFirstPellet, "cinemas/demo14.cin" },
	{ DEMOID_PushFirstBox, "cinemas/demo15.cin" },
	{ DEMOID_DiscoverMainEngine, "cinemas/demo16.cin" },
	{ DEMOID_ShipUpgradeTutorial, "cinemas/demo17.cin" },
	{ DEMOID_CollectFirstPartTutorial, "cinemas/demo20.cin" },
	{ DEMOID_Unk80, "cinemas/demo80.cin" },
	{ DEMOID_ShipUpgradeForest, "cinemas/demo18.cin" },
	{ DEMOID_ShipUpgradeCave, "cinemas/demo19.cin" },
	{ DEMOID_ShipUpgradeYakushima, "cinemas/demo25.cin" },
	{ DEMOID_ShipUpgradeLast, "cinemas/demo26.cin" },
	{ DEMOID_CollectPartTutorial, "cinemas/demo79.cin" },
	{ DEMOID_CollectPartForest, "cinemas/demo21.cin" },
	{ DEMOID_CollectPartCaveLast, "cinemas/demo22.cin" },
	{ DEMOID_CollectPartYakushima, "cinemas/demo23.cin" },
	{ DEMOID_Unk24, "cinemas/demo24.cin" },
	{ DEMOID_DayEndTutorial, "cinemas/demo28.cin" },
	{ DEMOID_DayEndForest, "cinemas/demo29.cin" },
	{ DEMOID_DayEndCaveLast, "cinemas/demo30.cin" },
	{ DEMOID_DayEndYakushima, "cinemas/demo31.cin" },
	{ DEMOID_ChalDayEndTutorial, "cinemas/demo32.cin" },
	{ DEMOID_ChalDayEndForest, "cinemas/demo33.cin" },
	{ DEMOID_ChalDayEndCave, "cinemas/demo34.cin" },
	{ DEMOID_ChalDayEndYakushima, "cinemas/demo35.cin" },
	{ DEMOID_ChalDayEndLast, "cinemas/demo88.cin" },
	{ DEMOID_EndOfDayResults, "cinemas/demo36.cin" },
	{ DEMOID_Unk37, "cinemas/demo37.cin" },
	{ DEMOID_Unk38, "cinemas/demo38.cin" },
	{ DEMOID_Unk39, "cinemas/demo39.cin" },
	{ DEMOID_LandingTutorial, "cinemas/demo40.cin" },
	{ DEMOID_LandingForest, "cinemas/demo41.cin" },
	{ DEMOID_LandingCaveLast, "cinemas/demo42.cin" },
	{ DEMOID_LandingYakushima, "cinemas/demo43.cin" },
	{ DEMOID_PikminInOnyonTutorial, "cinemas/demo44.cin" },
	{ DEMOID_PikminInOnyonForest, "cinemas/demo45.cin" },
	{ DEMOID_Extinction, "cinemas/demo46.cin" },
	{ DEMOID_ExtDayEndTutorial, "cinemas/demo47.cin" },
	{ DEMOID_ExtDayEndForest, "cinemas/demo48.cin" },
	{ DEMOID_ExtDayEndCaveLast, "cinemas/demo49.cin" },
	{ DEMOID_ExtDayEndYakushima, "cinemas/demo50.cin" },
	{ DEMOID_OlimarDown, "cinemas/demo51.cin" },
	{ DEMOID_OliDownDayEndTutorial, "cinemas/demo52.cin" },
	{ DEMOID_OliDownDayEndForest, "cinemas/demo53.cin" },
	{ DEMOID_OliDownDayEndCaveLast, "cinemas/demo54.cin" },
	{ DEMOID_OliDownDayEndYakushima, "cinemas/demo55.cin" },
	{ DEMOID_TakeOffTutorial, "cinemas/demo56.cin" },
	{ DEMOID_TakeOffForest, "cinemas/demo57.cin" },
	{ DEMOID_TakeOffCaveLast, "cinemas/demo58.cin" },
	{ DEMOID_TakeOffYakushima, "cinemas/demo59.cin" },
	{ DEMOID_DayEndTakeOffLast, "cinemas/demo109.cin" },
	{ DEMOID_Unk60, "cinemas/demo60.cin" },
	{ DEMOID_Unk61, "cinemas/demo61.cin" },
	{ DEMOID_Unk62, "cinemas/demo62.cin" },
	{ DEMOID_Unk63, "cinemas/demo63.cin" },
	{ DEMOID_Unk64, "cinemas/demo64.cin" },
	{ DEMOID_Unk65, "cinemas/demo65.cin" },
	{ DEMOID_Unk66, "cinemas/demo66.cin" },
	{ DEMOID_Unk67, "cinemas/demo67.cin" },
	{ DEMOID_YellowWithBomb, "cinemas/demo68.cin" },
	{ DEMOID_BadEndingTutorial, "cinemas/demo69.cin" },
	{ DEMOID_BadEndingForest, "cinemas/demo70.cin" },
	{ DEMOID_BadEndingCaveLast, "cinemas/demo71.cin" },
	{ DEMOID_BadEndingYakushima, "cinemas/demo72.cin" },
	{ DEMOID_BadEndingFailEscape, "cinemas/demo73.cin" },
	{ DEMOID_BadEndingOlimin, "cinemas/demo74.cin" },
	{ DEMOID_GoodEndingWave, "cinemas/demo75.cin" },
	{ DEMOID_CollectRadar, "cinemas/demo78.cin" },
	{ DEMOID_GoodEndingTakeOff, "cinemas/demo113.cin" },
	{ DEMOID_NeutralEndingLeaveOK, "cinemas/demo114.cin" },
	{ DEMOID_GoodEndingOnyons, "cinemas/demo76.cin" },
	{ DEMOID_EndingSpace, "cinemas/demo77.cin" },
	{ DEMOID_EndOfDayRedOnyon, "cinemas/demo84.cin" },
	{ DEMOID_EndOfDayYellowOnyon, "cinemas/demo85.cin" },
	{ DEMOID_EndOfDayBlueOnyon, "cinemas/demo86.cin" },
	{ DEMOID_NULL, nullptr },
};

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
bool MovieInfo::update()
{
	bool isFinished = false;
	if (mPlayer) {
		mPlayer->mPlaybackSpeed = 30.0f;
		isFinished              = mPlayer->update() != FALSE;
	}
	return !isFinished;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
bool MovieInfo::setCamera(Graphics& gfx)
{
	bool res = false;
	if (mPlayer->mCurrentData) {
		gfx.setCamera(&mPlayer->mCurrentData->mCameraData->mCamera);
		gfx.mCamera->update(gfx.mCamera->mAspectRatio, gfx.mCamera->mFov, gfx.mCamera->mNear, gfx.mCamera->mFar);
		res = true;
	}
	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void MovieInfo::refresh(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80076E34
 * Size:	0000BC
 */
MoviePlayer::MoviePlayer()
{
	mCamTransitionFactor = 0.0f;
}

/*
 * --INFO--
 * Address:	80076EF0
 * Size:	0000E0
 */
void MoviePlayer::resetMovieList()
{
	mPlayInfoList.initCore("playList");
	mMovieInfoList.initCore("movieList");
	mStackInfoList.initCore("stackList");

	for (int i = 0; i < 10; i++) {
		MovieInfo* info = new MovieInfo;
		mMovieInfoList.add(info);
	}
	mIsActive = false;
}

/*
 * --INFO--
 * Address:	80076FD0
 * Size:	000090
 */
void MoviePlayer::fixMovieList()
{
	while (mPlayInfoList.getChildCount()) {
		MovieInfo* info = (MovieInfo*)mPlayInfoList.Child();
		sndStopMovie(info);
		info->del();
		info->initCore("");
		mMovieInfoList.add(info);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
MovieListInfo* MoviePlayer::findMovie(int id)
{
	MovieListInfo* movie = nullptr;
	for (MovieListInfo* info = movieTitles; info->mCinFileName; info++) {
		if (info->mMovieID == id) {
			movie = info;
			break;
		}
	}
	return movie;
}

/*
 * --INFO--
 * Address:	80077060
 * Size:	000100
 */
void MoviePlayer::initMovie(MovieInfo* info, int)
{
	int old              = !!gsys->mPrevAllocType; // required for regalloc lol.
	gsys->mPrevAllocType = 0;
	int heapid           = gsys->getHeapNum();
	int type;
	if (heapid == SYSHEAP_App) {
		PRINT("using movie heap!\n");
		gsys->setHeap(SYSHEAP_Movie);
		type = gsys->getHeap(SYSHEAP_Movie)->setAllocType(1);
	}
	info->mPlayer = new CinematicPlayer(info->mName);
	if (mIsGameCam && info->mPlayer->mFlags & CinePlayerFlags::CameraBlend) {
		mInitialCamBlend = 1.0f;
		mIsGameCam       = false;
	}

	if (heapid != SYSHEAP_App) {
		gsys->getHeap(SYSHEAP_Movie)->setAllocType(type);
		gsys->setHeap(heapid);
	}
	gsys->mRetraceCount  = 0;
	gsys->mPrevAllocType = old;
}

int movie04table[STAGE_COUNT]
    = { DEMOID_FindRedOnyon, DEMOID_FindYellowOnyon, DEMOID_FindBlueOnyon, DEMOID_FindBlueOnyon, DEMOID_FindBlueOnyon };
int movie09table[STAGE_COUNT]
    = { DEMOID_MeetRedPikmin, DEMOID_MeetYellowPikmin, DEMOID_MeetBluePikmin, DEMOID_MeetBluePikmin, DEMOID_MeetBluePikmin };
int movie17table[STAGE_COUNT]
    = { DEMOID_ShipUpgradeTutorial, DEMOID_ShipUpgradeForest, DEMOID_ShipUpgradeCave, DEMOID_ShipUpgradeYakushima, DEMOID_ShipUpgradeLast };
int movie20table[STAGE_COUNT] = { DEMOID_CollectPartTutorial, DEMOID_CollectPartForest, DEMOID_CollectPartCaveLast,
	                              DEMOID_CollectPartYakushima, DEMOID_CollectPartCaveLast };
int movie18table[STAGE_COUNT]
    = { DEMOID_Unk80, DEMOID_ShipUpgradeForest, DEMOID_ShipUpgradeCave, DEMOID_ShipUpgradeYakushima, DEMOID_ShipUpgradeLast };
int movie28table[STAGE_COUNT]
    = { DEMOID_DayEndTutorial, DEMOID_DayEndForest, DEMOID_DayEndCaveLast, DEMOID_DayEndYakushima, DEMOID_DayEndCaveLast };
int movie32table[STAGE_COUNT]
    = { DEMOID_ChalDayEndTutorial, DEMOID_ChalDayEndForest, DEMOID_ChalDayEndCave, DEMOID_ChalDayEndYakushima, DEMOID_ChalDayEndLast };
int movie40table[STAGE_COUNT]
    = { DEMOID_LandingTutorial, DEMOID_LandingForest, DEMOID_LandingCaveLast, DEMOID_LandingYakushima, DEMOID_LandingCaveLast };
int movie44table[STAGE_COUNT] = { DEMOID_PikminInOnyonTutorial, DEMOID_PikminInOnyonForest, DEMOID_PikminInOnyonForest,
	                              DEMOID_PikminInOnyonForest, DEMOID_PikminInOnyonForest };
int movie47table[STAGE_COUNT]
    = { DEMOID_ExtDayEndTutorial, DEMOID_ExtDayEndForest, DEMOID_ExtDayEndCaveLast, DEMOID_ExtDayEndYakushima, DEMOID_ExtDayEndCaveLast };
int movie52table[STAGE_COUNT] = { DEMOID_OliDownDayEndTutorial, DEMOID_OliDownDayEndForest, DEMOID_OliDownDayEndCaveLast,
	                              DEMOID_OliDownDayEndYakushima, DEMOID_OliDownDayEndCaveLast };
int movie56table[STAGE_COUNT]
    = { DEMOID_TakeOffTutorial, DEMOID_TakeOffForest, DEMOID_TakeOffCaveLast, DEMOID_TakeOffYakushima, DEMOID_DayEndTakeOffLast };
int movie60table[STAGE_COUNT] = { DEMOID_Unk60, DEMOID_Unk61, DEMOID_Unk62, DEMOID_Unk63, DEMOID_Unk62 };
int movie64table[STAGE_COUNT] = { DEMOID_Unk64, DEMOID_Unk65, DEMOID_Unk66, DEMOID_Unk67, DEMOID_Unk66 };
int movie69table[STAGE_COUNT]
    = { DEMOID_BadEndingTutorial, DEMOID_BadEndingForest, DEMOID_BadEndingCaveLast, DEMOID_BadEndingYakushima, DEMOID_BadEndingCaveLast };

MovieTransInfo transTable[] = {
	{
	    DEMOID_FindOnyon,
	    movie04table,
	},
	{
	    DEMOID_MeetPikmin,
	    movie09table,
	},
	{
	    DEMOID_ShipUpgrade,
	    movie17table,
	},
	{
	    DEMOID_CollectPart,
	    movie20table,
	},
	{
	    DEMOID_ShipUpgradeForest,
	    movie18table,
	},
	{
	    DEMOID_ShipUpgradeCave,
	    movie18table,
	},
	{
	    DEMOID_ShipUpgradeYakushima,
	    movie18table,
	},
	{
	    DEMOID_DayEnd,
	    movie28table,
	},
	{
	    DEMOID_ChalDayEnd,
	    movie32table,
	},
	{
	    DEMOID_Landing,
	    movie40table,
	},
	{
	    DEMOID_PikminInOnyon,
	    movie44table,
	},
	{
	    DEMOID_ExtDayEnd,
	    movie47table,
	},
	{
	    DEMOID_OliDownDayEnd,
	    movie52table,
	},
	{
	    DEMOID_TakeOff,
	    movie56table,
	},
	{
	    DEMOID_Unk60Cat,
	    movie60table,
	},
	{
	    DEMOID_Unk64Cat,
	    movie64table,
	},
	{
	    DEMOID_BadEnding,
	    movie69table,
	},
	{
	    DEMOID_NULL,
	    nullptr,
	},
};

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
int MoviePlayer::translateIndex(int idx, int stage)
{
	PRINT("trying to find translation for index %d in stage %d\n", idx, stage);
	for (MovieTransInfo* info = transTable; info->mMovieID; info++) {
		if (info->mMovieID == idx) {
			int outIdx = info->mTransTable[stage];
			PRINT("found movie %d\n", outIdx);
			return outIdx;
		}
	}
	PRINT("no translation, returning input index\n");
	return idx;
}

/*
 * --INFO--
 * Address:	80077160
 * Size:	00049C
 */
void MoviePlayer::startMovie(int movieIdx, int, Creature* target, Vector3f* pos, Vector3f* rot, u32 mask, bool isPlaying)
{
	MovieInfo* info;
	if (movieIdx < 0) {
		skipScene(SCENESKIP_Invalid);
		return;
	}

	if (movieIdx == DEMOID_Unk12) { // title screen?
		gameflow.mGameInterface->message(MOVIECMD_StartTutorial, 17);
		return;
	}

	if (movieIdx == DEMOID_BadEndingOlimin) {
		GoalItem* onyon = itemMgr->getContainer(Red);
		if (!onyon) {
			return;
		}
		pos = &onyon->mPosition;
		rot = &onyon->mRotation;
	}

	// whimsical radar check?
	if (movieIdx == DEMOID_CollectPart && gameflow.mMovieInfoNum == 5) {
		movieIdx = DEMOID_CollectRadar;
	}

	int translatedIdx    = translateIndex(movieIdx, flowCont.mCurrentStage->mStageID);
	MovieListInfo* movie = findMovie(translatedIdx);
	if (!movie) {
		return;
	}

	if (rumbleMgr) {
		rumbleMgr->stop();
	}

	if (gameflow.mGameInterface) {
		gameflow.mGameInterface->message(MOVIECMD_HideHUD, 0);
	}

	PRINT("starting movie %d <%s> with creature %08x\n", translatedIdx, movie->mCinFileName, target);
	mIsActive = true;
	if (mMovieInfoList.getChildCount() == 0) {
		PRINT("Cannot start to play movie !!\n");
		ERROR(""); // okay
	}

	info = (MovieInfo*)mMovieInfoList.mChild;
	info->del();
	info->initCore(movie->mCinFileName);
	info->mMovieIndex = translatedIdx;
	info->mMaskFlags  = mask;
	if (translatedIdx == DEMOID_PikminInOnyonTutorial || translatedIdx == DEMOID_PikminInOnyonForest) {
		gsys->startLoading(nullptr, false, 0);
	} else {
		gsys->startLoading(nullptr, true, 60);
	}

	if (mPlayInfoList.getChildCount() == 0) {
		sndStartMovie(info);
	}

	initMovie(info, translatedIdx);
	gsys->endLoading();

	PRINT("movie attach\n");
	gsys->attachObjs();

	if (pos && (info->mPlayer->mFlags & CinePlayerFlags::Localized)) {
		if (pos && rot) {
			PRINT("    localized at (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f)\n", pos->x, pos->y, pos->z, rot->x, rot->y, rot->z);
		}
		info->mRootTransform.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), rot ? *rot : Vector3f(0.0f, 0.0f, 0.0f), *pos);
	} else {
		info->mRootTransform.makeIdentity();
	}

	info->mPlayer->mWorldMtx  = info->mRootTransform;
	info->mPlayer->mTarget    = target;
	info->mPlayer->mIsPlaying = isPlaying;

	bool doPlayMovie = false;
	if (mPlayInfoList.getChildCount() == 0) {
		// if there are no currently playing cutscenes, play cutscene now
		doPlayMovie = true;
	} else {
		// something's currently playing - check if we should override it
		if (info->mPlayer->mFlags & CinePlayerFlags::Concurrent) {
			bool check = false;
			// check if all queued movies have takeoff flag
			FOREACH_NODE(MovieInfo, mStackInfoList.mChild, stackInfo)
			{
				if (!(stackInfo->mPlayer->mFlags & CinePlayerFlags::Concurrent)) {
					check = true;
					break;
				}
			}

			// if all queued movies have takeoff flag, play cutscene anyway
			if (!check) {
				doPlayMovie = true;
			}
		}
	}

	if (doPlayMovie) {
		PRINT("playing movie %s\n", info->mName);
		initMovieFlags(info);
		if (info->mPlayer->mFlags & CinePlayerFlags::PauseAll) {
			gameflow.mDisableController = TRUE;
		}
		info->update();
		mPlayInfoList.add(info);
	} else {
		PRINT("stacking movie %s\n", info->mName);
		mStackInfoList.add(info);
	}

	bool printToggle   = gsys->mTogglePrint != 0;
	gsys->mTogglePrint = 1;
	PRINT("*--------------- %.2fk free\n", gsys->getHeap(SYSHEAP_App)->getFree() / 1024.0f);
	gsys->mTogglePrint = printToggle;

	STACK_PAD_TERNARY(printToggle, 1);
}

/*
 * --INFO--
 * Address:	800775FC
 * Size:	000104
 */
void MoviePlayer::sndStartMovie(MovieInfo* info)
{
	Jac_SetDemoPartsID(gameflow.mMovieInfoNum);
	int onyons = 0;
	for (int i = 0; i < 3; i++) {
		if (playerState && playerState->hasContainer(i)) {
			onyons++;
		}
	}
	Jac_SetDemoOnyons(onyons);
	effectMgr->cullingOff();
	Jac_SetDemoPartsCount(playerState ? playerState->getCurrParts() : 0);
	u32 old              = gsys->mPrevAllocType != 0;
	gsys->mPrevAllocType = 0;
	Jac_StartDemo(info->mMovieIndex);
	gsys->mPrevAllocType = old;
}

/*
 * --INFO--
 * Address:	80077700
 * Size:	000124
 */
void MoviePlayer::initMovieFlags(MovieInfo* info)
{
	bool doHideNavi = (info->mPlayer->mFlags & CinePlayerFlags::HideNavi) != 0;
	FOREACH_NODE(SceneCut, info->mPlayer->mSceneList.mChild, cut)
	{
		FOREACH_NODE(ActorInstance, cut->mActorList.mChild, actor)
		{
			if (actor->mFlags & (CAF_MoveDayEndNavi | CAF_MoveAiNavi)) {
				doHideNavi = false;
				break;
			}
		}
	}
	if (info->mPlayer->mFlags & CinePlayerFlags::UseLights) {
		PRINT("Killing all effects!!!\n");
		effectMgr->killAll();
	}

	if (info->mPlayer->mFlags & CinePlayerFlags::CameraReturn) {
		mCamTransitionFactor = 1.0f;
	}

	if (gameflow.mGameInterface) {
		gameflow.mGameInterface->message(
		    MOVIECMD_StartMovie,
		    (doHideNavi ? 0x80000000 : 0)
		        | info->mPlayer->mFlags
		              & (CinePlayerFlags::HideNavi | CinePlayerFlags::HideBluePiki | CinePlayerFlags::HideRedPiki
		                 | CinePlayerFlags::HideYellowPiki | CinePlayerFlags::NaviNoAI | CinePlayerFlags::ShowTekis
		                 | CinePlayerFlags::ShowFreePiki | CinePlayerFlags::UpdateFreePiki | CinePlayerFlags::ShowFormPiki
		                 | CinePlayerFlags::UpdateFormPiki | CinePlayerFlags::ShowWorkPiki | CinePlayerFlags::UpdateWorkPiki
		                 | CinePlayerFlags::ShowPellets | CinePlayerFlags::HideRedCont | CinePlayerFlags::PikiNearUfo));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void MoviePlayer::sndFrameMovie(MovieInfo*)
{
	Jac_DemoFrame(mCurrentFrame);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80077824
 * Size:	000064
 */
void MoviePlayer::sndStopMovie(MovieInfo* info)
{
	Jac_FinishDemo();
	effectMgr->cullingOn();
	if (gameflow.mGameInterface) {
		gameflow.mGameInterface->message(MOVIECMD_EndMovie, info->mMovieIndex);
	}
}

/*
 * --INFO--
 * Address:	80077888
 * Size:	0003CC
 */
void MoviePlayer::update()
{
	gameflow.mDemoFlags = 0;
	if (gsys->mDvdErrorCode >= 0) {
		return;
	}

	if (mIsActive && _125 && static_cast<MovieInfo*>(mPlayInfoList.mChild)->mPlayer->mCurrentPlaybackTime > 0.0f) {
		static_cast<MovieInfo*>(mPlayInfoList.mChild)->mPlayer->mCurrentPlaybackTime -= 1.0f;
	}

	MovieInfo* next;
	for (MovieInfo* info = (MovieInfo*)mPlayInfoList.mChild; info; info = next) {
		next = (MovieInfo*)info->mNext;
		gameflow.mDemoFlags
		    |= info->mPlayer->mFlags
		     & (CinePlayerFlags::HideNavi | CinePlayerFlags::HideBluePiki | CinePlayerFlags::HideRedPiki | CinePlayerFlags::HideYellowPiki
		        | CinePlayerFlags::NaviNoAI | CinePlayerFlags::UseLights | CinePlayerFlags::ShowTekis);
		if (mInitialCamBlend > 0.0f) {
			mInitialCamBlend -= gsys->getFrameTime() * 0.6f;
			if (mInitialCamBlend < 0.0f) {
				mInitialCamBlend = 0.0f;
				if (info->mPlayer) {
					info->mPlayer->mCameraBlendRatio = 0.0f;
				}
			}
		}
		if (info->mPlayer && mInitialCamBlend > 0.0f) {
			info->mPlayer->mCameraTargetFov  = mPreCutsceneCamFov;
			info->mPlayer->mCameraPosition   = mPreCutsceneCamPosition;
			info->mPlayer->mCameraLookAt     = mPreCutsceneCamLookAt;
			info->mPlayer->mCameraBlendRatio = (sinf(mInitialCamBlend * PI - HALF_PI) + 1.0f) * 0.5f;
		}

		if (info->mPlayer && info->mPlayer->mTarget && info->mPlayer->mFlags & CinePlayerFlags::ObjWatching) {
			info->mPlayer->mUseStaticCamera = true;
			info->mPlayer->mStaticLookAt    = info->mPlayer->mTarget->mPosition;
		}

		mMaskFlags = info->mMaskFlags;
		if (!info->update()) { // returns false if playback is finished
			PRINT("movie end!\n");
			sndStopMovie(info);
			info->del();
			info->initCore("");
			mMovieInfoList.add(info);
			while (mStackInfoList.getChildCount() != 0) {
				// get next queued movie
				MovieInfo* stackInfo = (MovieInfo*)mStackInfoList.mChild;
				stackInfo->del();
				stackInfo->initCore(stackInfo->mName);
				PRINT("STARTING MOVIE %s\n", stackInfo->mName);
				sndStartMovie(stackInfo);
				initMovieFlags(stackInfo);
				mPlayInfoList.add(stackInfo);
				stackInfo->update();
				if (!mStackInfoList.mChild) {
					break;
				}
				// queue up all the takeoff movies at once
				if (!(static_cast<MovieInfo*>(mStackInfoList.mChild)->mPlayer->mFlags & CinePlayerFlags::Concurrent)) {
					break;
				}
			}

			if (mPlayInfoList.getChildCount() == 0) {
				mIsActive           = false;
				gameflow.mDemoFlags = 0;
				if (gameflow.mGameInterface) {
					gameflow.mGameInterface->message(MOVIECMD_ShowHUD, 0);
				}
				bool togglePrint   = gsys->mTogglePrint != 0;
				gsys->mTogglePrint = 1;
				PRINT("clearing top heap!\n");
				gsys->resetHeap(SYSHEAP_Movie, 1);
				gsys->mTogglePrint          = togglePrint;
				gameflow.mDisableController = FALSE;
				PRINT("all movies ended!\n");
			}

		} else {
			sndFrameMovie(info);
		}
	}
}

/*
 * --INFO--
 * Address:	80077C54
 * Size:	0000AC
 */
void MoviePlayer::skipScene(int sceneSkipFlag)
{
	if (sceneSkipFlag == SCENESKIP_SkipAll) {
		PRINT("SKIP ALL !!! SKIP ALL !!! SKIP ALL !!! SKIP ALL !!! SKIP ALL !!! \n");
		while (mStackInfoList.getChildCount()) {
			// clear everything out of the queue
			MovieInfo* info = (MovieInfo*)mStackInfoList.mChild;
			info->del();
			info->mChild  = nullptr;
			info->mNext   = nullptr;
			info->mParent = nullptr;
			mMovieInfoList.add(info);
		}
	}

	MovieInfo* info = (MovieInfo*)mPlayInfoList.mChild;
	while (info) {
		// apply skip flag to all active cutscenes
		MovieInfo* next = (MovieInfo*)info->mNext;
		info->mPlayer->skipScene(sceneSkipFlag);
		info = next;
	}
}

/*
 * --INFO--
 * Address:	80077D00
 * Size:	00001C
 */
void MoviePlayer::getLookAtPos(Vector3f& pos)
{
	pos.set(mLookAtPos.x, mLookAtPos.y, mLookAtPos.z);
}

/*
 * --INFO--
 * Address:	80077D1C
 * Size:	000100
 */
bool MoviePlayer::setCamera(Graphics& gfx)
{
	bool res = false;
	MovieInfo* next;
	for (MovieInfo* info = (MovieInfo*)mPlayInfoList.mChild; info; info = next) {
		next = (MovieInfo*)info->mNext;
		res |= info->setCamera(gfx);
	}
	if (res) {
		mTargetFov       = gfx.mCamera->mFov;
		mTargetViewpoint = gfx.mCamera->mPosition;
		mLookAtPos       = gfx.mCamera->mFocus;
	}
	return res;
}

/*
 * --INFO--
 * Address:	80077E1C
 * Size:	000060
 */
void MoviePlayer::addLights(Graphics& gfx)
{
	MovieInfo* info = (MovieInfo*)mPlayInfoList.mChild;
	while (info) {
		CinematicPlayer* cin = info->mPlayer;
		MovieInfo* next      = (MovieInfo*)info->mNext;
		if (cin->mFlags & CinePlayerFlags::UseLights) {
			cin->addLights(gfx);
		}
		info = next;
	}
}

/*
 * --INFO--
 * Address:	80077E7C
 * Size:	000074
 */
void MoviePlayer::refresh(Graphics& gfx)
{
	gfx.setLighting(true, nullptr);
	MovieInfo* info = (MovieInfo*)mPlayInfoList.mChild;
	while (info) {
		MovieInfo* next = (MovieInfo*)info->mNext;
		info->mPlayer->refresh(gfx);
		info = next;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void MoviePlayer::nextFrame()
{
	static_cast<MovieInfo*>(mPlayInfoList.mChild)->mPlayer->mCurrentPlaybackTime++;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void MoviePlayer::backFrame()
{
	if (static_cast<MovieInfo*>(mPlayInfoList.mChild)->mPlayer->mCurrentPlaybackTime > 0.0f) {
		// should this be --? in the DLL it's ++, go figure.
		static_cast<MovieInfo*>(mPlayInfoList.mChild)->mPlayer->mCurrentPlaybackTime++;
	}
}
