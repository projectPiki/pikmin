#include "CardSelectSection.h"
#include "CmdStream.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "FlowController.h"
#include "GameCourseClearSection.h"
#include "GameCreditsSection.h"
#include "GameExitSection.h"
#include "GameSetupSection.h"
#include "GameStageClearSection.h"
#include "IntroGameSection.h"
#include "MapSelect.h"
#include "MemStat.h"
#include "NewPikiGame.h"
#include "OnePlayerSection.h"
#include "gameflow.h"
#include "sysNew.h"
#include "system.h"
#include <stdio.h>
#include <string.h>

FlowController flowCont;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameOnePlayer");

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void StageInfo::write(RandomAccessStream&)
{
	PRINT("writing information for stage %d\n", mStageID);
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void StageInfo::read(RandomAccessStream&)
{
	PRINT("reading information for stage %d\n", mStageID);
}

/**
 * @todo: Documentation
 */
void StageInfo::parseGenerators(CmdStream* commands)
{
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);
		if (!commands->isToken("genfile")) {
			continue;
		}

		GenFileInfo* fileInfo = new GenFileInfo;

		fileInfo->setName(StdSystem::stringDup(commands->getToken(true)));

		u32 startDay;
		sscanf(commands->getToken(true), "%d", &startDay);

		u32 endDay;
		sscanf(commands->getToken(true), "%d", &endDay);

		u32 duration;
		sscanf(commands->getToken(true), "%d", &duration);

		fileInfo->mStartDay = startDay;
		fileInfo->mEndDay   = endDay;
		fileInfo->mDuration = duration;

		PRINT("adding new genfile info %s : %d, %d -> %d\n", fileInfo->mName, fileInfo->mStartDay, fileInfo->mEndDay, fileInfo->mDuration);
		mFileInfoList.add(fileInfo);
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000094
 */
void FlowController::setStage(immut char* fileName)
{
	FOREACH_NODE(StageInfo, mRootInfo.mChild, stage)
	{
		if (strcmp(stage->mFileName, fileName) == 0) {
			mCurrentStage = stage;
			sprintf(mStagePath1, "%s", stage->mFileName);
			sprintf(mStagePath2, "%s", stage->mFileName);
			break;
		}
	}
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void FlowController::readMapList(immut char* fileName)
{
	mRootInfo.initCore("stages");
	RandomAccessStream* file = gsys->openFile(fileName, true, true);
	if (!file) {
		return;
	}

	CmdStream* commands = new CmdStream(file);
	StageInfo* newStage;
	u16 stageIdx = 0;
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);
		if (!commands->isToken("new_map")) {
			continue;
		}

		memStat->start("stageInfo");

		newStage              = new StageInfo();
		newStage->mStageIndex = stageIdx;
		newStage->mStageInf.init();
		mRootInfo.add(newStage);
		memStat->end("stageInfo");
		stageIdx++;

		commands->getToken(true);

		newStage->mIsVisible = strcmp(commands->mCurrentToken, "visible") == 0 ? TRUE : FALSE;

		commands->getToken(true);

		while (!commands->endOfCmds() && !commands->endOfSection()) {
			commands->getToken(true);
			if (commands->isToken("name")) {
				newStage->mStageName = StdSystem::stringDup(commands->getToken(true));
				PRINT("adding new stage %s\n", newStage->mStageName);
				continue;
			}

			if (commands->isToken("id")) {
				u32 stageID;
				sscanf(commands->getToken(true), "%d", &stageID);
				newStage->mStageID = stageID;
				continue;
			}

			if (commands->isToken("chid")) {
				u32 chID;
				sscanf(commands->getToken(true), "%d", &chID);
				newStage->mChalStageID = chID;
				continue;
			}

			if (commands->isToken("file")) {
				newStage->mFileName = StdSystem::stringDup(commands->getToken(true));
				continue;
			}

			if (commands->isToken("generator")) {
				commands->getToken(true);
				newStage->parseGenerators(commands);
			}
		}

		if (!commands->endOfCmds()) {
			commands->getToken(true);
		}
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
	file->close();
}
#if defined(VERSION_G98E01_PIKIDEMO)
static immut char* levNames[]
    = { "intro/map0.bti", "intro/ot_map.bti", "intro/map2.bti", "intro/map3.bti", "intro/map4.bti", "intro/loading.bti" };
#else
static immut char* levNames[STAGE_COUNT] = {
	"intro/map0.bti", "intro/map1.bti", "intro/map2.bti", "intro/map3.bti", "intro/map4.bti",
};
#endif

/**
 * @todo: Documentation
 */
void OnePlayerSection::init()
{
	Node::init("<OnePlayerSection>");
	BOOL displayState       = gsys->mTogglePrint;
	Section* currentSection = nullptr;

	while (!currentSection) {
		int nextSectionType = gameflow.mNextOnePlayerSectionID;
		switch (nextSectionType) {
		case ONEPLAYER_GameSetup:
			PRINT("making new SETUP\n");
			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
#if defined(VERSION_G98E01_PIKIDEMO)
			gameflow.mLevelBannerTex       = gameflow.setLoadBanner(levNames[5]);
			gameflow.mLevelBannerFadeValue = 0.0f;
#else
			if (gameflow.mLevelIndex >= 2 && gameflow.mLevelIndex <= 4) {
				PRINT("setting banner!\n");
				gameflow.mLevelBannerTex       = gameflow.setLoadBanner(levNames[gameflow.mLevelIndex - 2]);
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTex = nullptr;
			}
#endif

			currentSection = new GameSetupSection();
			gsys->endLoading();
			break;

		case ONEPLAYER_CardSelect:
			PRINT("making new CARDSELECT\n");
			currentSection = new CardSelectSection();
			break;

		case ONEPLAYER_MapSelect:
			PRINT("making new MAPSELECT\n");
			currentSection = new MapSelectSection();
			break;

		// The following three cases are leftovers from the E3 2001 showfloor demo!  At the event, the title screen had a
		// unique menu that could directly access three different stages: "Tutorial", "Forest Day 1", and "Forest Day 2".
		case ONEPLAYER_E3Tutorial:
			if (!gameflow.mLevelBannerTex) {
				PRINT("setting banner!\n");
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(levNames[nextSectionType - 2]);
			}

			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			flowCont.setStage("stages/practice.ini");

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 1;
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow.mLevelIndex             = 3;
			break;

		case ONEPLAYER_E3ForestDay1:
			if (!gameflow.mLevelBannerTex) {
				PRINT("setting banner!\n");
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(levNames[nextSectionType - 2]);
			}
			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			flowCont.setStage("stages/stage1.ini");

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 1;
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow.mLevelIndex             = 4;
			break;

		case ONEPLAYER_E3ForestDay2:
			if (!gameflow.mLevelBannerTex) {
				PRINT("setting banner!\n");
				gameflow.mLevelBannerTex = gameflow.setLoadBanner(levNames[nextSectionType - 2]);
			}

			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			flowCont.setStage("stages/play_3.ini");

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 2;
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow.mLevelIndex             = 10;
			break;

		case ONEPLAYER_IntroGame:
			PRINT("making new INTRO\n");
			currentSection = new IntroGameSection();
			break;

		case ONEPLAYER_NewPikiGame:
			// The exact position of this DLL-exclusive code is unclear because some of the following code is DOL-exclusive.
#ifdef WIN32
			_nsPrint = FALSE;
			_yPrint  = FALSE;
			_kPrint  = FALSE;
			_nPrint  = FALSE;
			_cPrint  = FALSE;
#endif

			if (!gsys->mIsLoadingActive) {
				gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			}

			// grr.
			Texture* tex = nullptr;
			u32 stageID  = flowCont.mCurrentStage->mStageID;
			if (stageID <= STAGE_LASTVALID) {
				gameflow.mLevelBannerTex = tex = gameflow.setLoadBanner(levNames[stageID]);
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTex = tex;
			}
			PRINT("making new MAINGAME\n");
			currentSection = new NewPikiGameSection();
			break;

		case ONEPLAYER_GameCourseClear:
			PRINT("making new COURSECLEAR\n");
			currentSection = new GameCourseClearSection();
			break;

		case ONEPLAYER_GameStageClear:
			PRINT("making new STAGECLEAR\n");
			currentSection = new GameStageClearSection();
			break;

		case ONEPLAYER_GameCredits:
			PRINT("making new CREDITS\n");
			gsys->startLoading(nullptr, true, 60);
			currentSection = new GameCreditsSection();
			gsys->endLoading();
			break;

		case ONEPLAYER_GameExit:
			PRINT("making new EXIT\n");
			currentSection = new GameExitSection();
			break;
		}

		if (gameflow.mNextOnePlayerSectionID != nextSectionType) {
			currentSection = nullptr;
		}
	}

	add(currentSection);
	gsys->mTogglePrint = displayState;
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stmw      r15, 0x2C(r1)
	  addi      r30, r4, 0x66D0
	  lis       r4, 0x803A
	  subi      r28, r4, 0x24E0
	  addi      r15, r3, 0
	  addi      r4, r30, 0x98
	  bl        -0x12F30
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  subi      r29, r3, 0x2848
	  lfs       f31, -0x7AB0(r2)
	  lwz       r0, 0x1C(r4)
	  lis       r3, 0x802A
	  stw       r0, 0x24(r1)
	  addi      r16, r29, 0
	  addi      r17, r29, 0
	  addi      r18, r29, 0
	  addi      r24, r29, 0x31C
	  addi      r20, r28, 0x130
	  addi      r21, r28, 0x1B0
	  addi      r22, r29, 0x2D8
	  addi      r26, r29, 0x310
	  addi      r25, r29, 0x1F4
	  addi      r19, r3, 0x67B8
	  li        r27, 0
	  b         .loc_0x4F4

	.loc_0x7C:
	  lwz       r23, 0x0(r25)
	  cmplwi    r23, 0xB
	  bgt-      .loc_0x4E4
	  rlwinm    r0,r23,2,0,29
	  lwzx      r3, r19, r0
	  mtctr     r3
	  bctr
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1FC(r29)
	  cmpwi     r0, 0x2
	  blt-      .loc_0xEC
	  cmpwi     r0, 0x4
	  bgt-      .loc_0xEC
	  rlwinm    r0,r0,2,0,29
	  add       r3, r30, r0
	  lwz       r4, 0x7C(r3)
	  mr        r3, r18
	  bl        -0x1730
	  stw       r3, 0x310(r29)
	  stfs      f31, 0x314(r29)
	  b         .loc_0xF4

	.loc_0xEC:
	  li        r0, 0
	  stw       r0, 0x310(r29)

	.loc_0xF4:
	  li        r3, 0x20
	  bl        -0xC734
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x10C
	  bl        0x157C

	.loc_0x10C:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4E4
	  li        r3, 0x20
	  bl        -0xC764
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x18C4
	  b         .loc_0x4E4
	  li        r3, 0x20
	  bl        -0xC780
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x26BC
	  b         .loc_0x4E4
	  lwz       r3, 0x0(r26)
	  cmplwi    r3, 0
	  bne-      .loc_0x17C
	  add       r3, r30, r0
	  lwz       r4, 0x7C(r3)
	  mr        r3, r17
	  bl        -0x17C8
	  stw       r3, 0x0(r26)

	.loc_0x17C:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x10(r28)
	  b         .loc_0x1EC

	.loc_0x1A4:
	  lwz       r3, 0x18(r31)
	  addi      r4, r30, 0xAC
	  bl        0x1C59D8
	  cmpwi     r3, 0
	  bne-      .loc_0x1E8
	  stw       r31, 0xA8(r28)
	  addi      r3, r20, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7478
	  lwz       r5, 0x18(r31)
	  bl        0x1C2D8C
	  lwz       r5, 0x18(r31)
	  addi      r3, r21, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7478
	  bl        0x1C2D78
	  b         .loc_0x1F4

	.loc_0x1E8:
	  lwz       r31, 0xC(r31)

	.loc_0x1EC:
	  cmplwi    r31, 0
	  bne+      .loc_0x1A4

	.loc_0x1F4:
	  lwz       r4, 0x20(r29)
	  mr        r3, r22
	  lfs       f1, 0x10(r4)
	  bl        -0x2024
	  li        r0, 0x1
	  stw       r0, 0x2FC(r29)
	  li        r3, 0x7
	  li        r0, 0x3
	  stw       r3, 0x0(r25)
	  stw       r0, 0x1FC(r29)
	  b         .loc_0x4E4
	  lwz       r3, 0x0(r26)
	  cmplwi    r3, 0
	  bne-      .loc_0x240
	  add       r3, r30, r0
	  lwz       r4, 0x7C(r3)
	  mr        r3, r16
	  bl        -0x188C
	  stw       r3, 0x0(r26)

	.loc_0x240:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x10(r28)
	  b         .loc_0x2B0

	.loc_0x268:
	  lwz       r3, 0x18(r31)
	  addi      r4, r30, 0xC0
	  bl        0x1C5914
	  cmpwi     r3, 0
	  bne-      .loc_0x2AC
	  stw       r31, 0xA8(r28)
	  addi      r3, r20, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7478
	  lwz       r5, 0x18(r31)
	  bl        0x1C2CC8
	  lwz       r5, 0x18(r31)
	  addi      r3, r21, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7478
	  bl        0x1C2CB4
	  b         .loc_0x2B8

	.loc_0x2AC:
	  lwz       r31, 0xC(r31)

	.loc_0x2B0:
	  cmplwi    r31, 0
	  bne+      .loc_0x268

	.loc_0x2B8:
	  lwz       r4, 0x20(r29)
	  mr        r3, r22
	  lfs       f1, 0x10(r4)
	  bl        -0x20E8
	  li        r0, 0x1
	  stw       r0, 0x2FC(r29)
	  li        r3, 0x7
	  li        r0, 0x4
	  stw       r3, 0x0(r25)
	  stw       r0, 0x1FC(r29)
	  b         .loc_0x4E4
	  lwz       r3, 0x0(r26)
	  cmplwi    r3, 0
	  bne-      .loc_0x304
	  add       r3, r30, r0
	  lwz       r4, 0x7C(r3)
	  mr        r3, r29
	  bl        -0x1950
	  stw       r3, 0x0(r26)

	.loc_0x304:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x10(r28)
	  b         .loc_0x374

	.loc_0x32C:
	  lwz       r3, 0x18(r31)
	  addi      r4, r30, 0xD4
	  bl        0x1C5850
	  cmpwi     r3, 0
	  bne-      .loc_0x370
	  stw       r31, 0xA8(r28)
	  addi      r3, r20, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7478
	  lwz       r5, 0x18(r31)
	  bl        0x1C2C04
	  lwz       r5, 0x18(r31)
	  addi      r3, r21, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7478
	  bl        0x1C2BF0
	  b         .loc_0x37C

	.loc_0x370:
	  lwz       r31, 0xC(r31)

	.loc_0x374:
	  cmplwi    r31, 0
	  bne+      .loc_0x32C

	.loc_0x37C:
	  lwz       r4, 0x20(r29)
	  mr        r3, r22
	  lfs       f1, 0x10(r4)
	  bl        -0x21AC
	  li        r0, 0x2
	  stw       r0, 0x2FC(r29)
	  li        r3, 0x7
	  li        r0, 0xA
	  stw       r3, 0x0(r25)
	  stw       r0, 0x1FC(r29)
	  b         .loc_0x4E4
	  li        r3, 0x20
	  bl        -0xC9E8
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x7420
	  b         .loc_0x4E4
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x260(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3F0
	  lwz       r12, 0x1A0(r3)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  lwz       r12, 0x2C(r12)
	  li        r6, 0x3C
	  mtlr      r12
	  blrl

	.loc_0x3F0:
	  lwz       r3, 0xA8(r28)
	  li        r4, 0
	  lhz       r3, 0x26(r3)
	  cmplwi    r3, 0x4
	  bgt-      .loc_0x424
	  rlwinm    r0,r3,2,0,29
	  add       r3, r30, r0
	  lwz       r4, 0x84(r3)
	  mr        r3, r29
	  bl        -0x1A68
	  stw       r3, 0x310(r29)
	  stfs      f31, 0x314(r29)
	  b         .loc_0x428

	.loc_0x424:
	  stw       r4, 0x310(r29)

	.loc_0x428:
	  li        r3, 0x20
	  bl        -0xCA68
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x5C44
	  b         .loc_0x4E4
	  li        r3, 0x20
	  bl        -0xCA84
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x1459DC
	  b         .loc_0x4E4
	  li        r3, 0x20
	  bl        -0xCAA0
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x147D50
	  b         .loc_0x4E4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x20
	  bl        -0xCADC
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4B4
	  bl        0x147D98

	.loc_0x4B4:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4E4
	  li        r3, 0x20
	  bl        -0xCB0C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x4E4
	  bl        0x7B70

	.loc_0x4E4:
	  lwz       r0, 0x0(r25)
	  cmpw      r0, r23
	  beq-      .loc_0x4F4
	  li        r27, 0

	.loc_0x4F4:
	  cmplwi    r27, 0
	  beq+      .loc_0x7C
	  addi      r3, r15, 0
	  addi      r4, r27, 0
	  bl        -0x1356C
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1C(r3)
	  lmw       r15, 0x2C(r1)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}
