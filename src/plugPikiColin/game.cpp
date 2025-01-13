#include "OnePlayerSection.h"
#include "FlowController.h"
#include "CmdStream.h"
#include "MemStat.h"
#include "system.h"
#include "sysNew.h"
#include "gameflow.h"
#include "GameSetupSection.h"
#include "CardSelectSection.h"
#include "MapSelect.h"
#include "IntroGameSection.h"
#include "NewPikiGame.h"
#include "GameCourseClearSection.h"
#include "GameStageClearSection.h"
#include "GameCreditsSection.h"
#include "GameExitSection.h"
#include "stl/stdio.h"
#include "stl/string.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

FlowController flowCont;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("GameOnePlayer");

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void StageInfo::write(RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005315C
 * Size:	000004
 */
void StageInfo::read(RandomAccessStream&)
{
}

/*
 * --INFO--
 * Address:	80053160
 * Size:	000168
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

		u32 byte1;
		sscanf(commands->getToken(true), "%d", &byte1);

		u32 byte2;
		sscanf(commands->getToken(true), "%d", &byte2);

		u32 byte3;
		sscanf(commands->getToken(true), "%d", &byte3);

		fileInfo->_14 = byte1;
		fileInfo->_15 = byte2;
		fileInfo->_16 = byte3;

		mFileInfoList.add(fileInfo);
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void FlowController::setStage(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800532C8
 * Size:	000378
 */
void FlowController::readMapList(char* fileName)
{
	mRootInfo.initCore("stages");
	RandomAccessStream* file = gsys->openFile(fileName, true, true);
	if (!file) {
		return;
	}

	CmdStream* commands = new CmdStream(file);
	u16 stageIdx        = 0;
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);
		if (!commands->isToken("new_map")) {
			continue;
		}

		memStat->start("stageInfo");

		StageInfo* newStage   = new StageInfo();
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
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802A
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x7474
	  li        r6, 0x1
	  stwu      r1, -0x50(r1)
	  stmw      r19, 0x1C(r1)
	  addi      r31, r3, 0
	  li        r3, 0
	  addi      r24, r5, 0x66D0
	  li        r5, 0x1
	  stw       r3, 0x10(r31)
	  stw       r3, 0xC(r31)
	  stw       r3, 0x8(r31)
	  stw       r0, 0x4(r31)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r23, r3
	  beq-      .loc_0x364
	  li        r3, 0x11C
	  bl        -0xC320
	  addi      r19, r3, 0
	  mr.       r3, r19
	  beq-      .loc_0x74
	  mr        r4, r23
	  bl        -0x127BC

	.loc_0x74:
	  lis       r7, 0x8022
	  lis       r6, 0x8022
	  lis       r5, 0x802A
	  lis       r4, 0x802C
	  lis       r3, 0x802A
	  addi      r22, r19, 0
	  addi      r25, r7, 0x738C
	  addi      r26, r6, 0x737C
	  addi      r27, r24, 0x1C
	  addi      r28, r5, 0x6908
	  subi      r29, r4, 0x7CBC
	  addi      r30, r3, 0x68BC
	  li        r20, 0
	  b         .loc_0x314

	.loc_0xAC:
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x122CC
	  addi      r3, r22, 0
	  subi      r4, r13, 0x746C
	  bl        -0x11FB4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x314
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r24, 0x1C
	  bl        0x3339C
	  li        r3, 0xA8
	  bl        -0xC3A0
	  mr.       r19, r3
	  beq-      .loc_0x164
	  stw       r25, 0x0(r19)
	  li        r21, 0
	  addi      r3, r19, 0x2C
	  stw       r26, 0x0(r19)
	  stw       r21, 0x10(r19)
	  stw       r21, 0xC(r19)
	  stw       r21, 0x8(r19)
	  stw       r27, 0x4(r19)
	  stw       r28, 0x0(r19)
	  bl        0x72918
	  stw       r29, 0x2C(r19)
	  addi      r3, r19, 0x90
	  subi      r4, r13, 0x7480
	  stw       r25, 0x90(r19)
	  stw       r26, 0x90(r19)
	  stw       r21, 0xA0(r19)
	  stw       r21, 0x9C(r19)
	  stw       r21, 0x98(r19)
	  bl        -0x2E524
	  stw       r30, 0x90(r19)
	  li        r4, 0x5
	  li        r3, 0x7
	  sth       r21, 0x24(r19)
	  subi      r0, r13, 0x7480
	  sth       r4, 0x26(r19)
	  sth       r3, 0x28(r19)
	  stw       r21, 0x20(r19)
	  stw       r21, 0xA0(r19)
	  stw       r21, 0x9C(r19)
	  stw       r21, 0x98(r19)
	  stw       r0, 0x94(r19)

	.loc_0x164:
	  mr        r21, r19
	  sth       r20, 0x24(r19)
	  addi      r3, r21, 0x2C
	  bl        0x72FAC
	  addi      r3, r31, 0
	  addi      r4, r21, 0
	  bl        -0x12E6C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r24, 0x1C
	  bl        0x333F8
	  addi      r3, r22, 0
	  li        r4, 0x1
	  addi      r20, r20, 0x1
	  bl        -0x123B0
	  addi      r3, r22, 0x8
	  subi      r4, r13, 0x7464
	  bl        0x1C5D58
	  cmpwi     r3, 0
	  bne-      .loc_0x1B8
	  li        r0, 0x1
	  b         .loc_0x1BC

	.loc_0x1B8:
	  li        r0, 0

	.loc_0x1BC:
	  stw       r0, 0x1C(r19)
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x123E0
	  b         .loc_0x2D8

	.loc_0x1D0:
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x123F0
	  addi      r3, r22, 0
	  subi      r4, r13, 0x745C
	  bl        -0x120D8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x208
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x12410
	  bl        -0x13184
	  stw       r3, 0x14(r19)
	  b         .loc_0x2D8

	.loc_0x208:
	  addi      r3, r22, 0
	  subi      r4, r13, 0x7454
	  bl        -0x12104
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x244
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x1243C
	  crclr     6, 0x6
	  addi      r5, r1, 0x14
	  subi      r4, r13, 0x747C
	  bl        0x1C4B98
	  lwz       r0, 0x14(r1)
	  sth       r0, 0x26(r19)
	  b         .loc_0x2D8

	.loc_0x244:
	  addi      r3, r22, 0
	  subi      r4, r13, 0x7450
	  bl        -0x12140
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x12478
	  crclr     6, 0x6
	  addi      r5, r1, 0x10
	  subi      r4, r13, 0x747C
	  bl        0x1C4B5C
	  lwz       r0, 0x10(r1)
	  sth       r0, 0x28(r19)
	  b         .loc_0x2D8

	.loc_0x280:
	  addi      r3, r22, 0
	  subi      r4, r13, 0x7448
	  bl        -0x1217C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2AC
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x124B4
	  bl        -0x13228
	  stw       r3, 0x18(r19)
	  b         .loc_0x2D8

	.loc_0x2AC:
	  addi      r3, r22, 0
	  addi      r4, r24, 0x28
	  bl        -0x121A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D8
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x124E0
	  addi      r3, r21, 0
	  addi      r4, r22, 0
	  bl        -0x43C

	.loc_0x2D8:
	  mr        r3, r22
	  bl        -0x1284C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F8
	  mr        r3, r22
	  bl        -0x1212C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x1D0

	.loc_0x2F8:
	  mr        r3, r22
	  bl        -0x1286C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x314
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x12528

	.loc_0x314:
	  mr        r3, r22
	  bl        -0x12888
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x334
	  mr        r3, r22
	  bl        -0x12168
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xAC

	.loc_0x334:
	  mr        r3, r22
	  bl        -0x128A8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x350
	  addi      r3, r22, 0
	  li        r4, 0x1
	  bl        -0x12564

	.loc_0x350:
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x364:
	  lmw       r19, 0x1C(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

static char* levNames[] = {
	"intro/map0.bti", "intro/map1.bti", "intro/map2.bti", "intro/map3.bti", "intro/map4.bti",
};

/*
 * --INFO--
 * Address:	80053640
 * Size:	00052C
 */
void OnePlayerSection::init()
{
	Node::init("<OnePlayerSection>");
	u32 displayState        = gsys->mTogglePrint;
	Section* currentSection = nullptr;

	while (!currentSection) {
		int nextSectionType = gameflow.mNextOnePlayerSectionID;
		switch (nextSectionType) {
		case ONEPLAYER_GameSetup:
			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			if (gameflow._1FC >= 2 && gameflow._1FC <= 4) {
				gameflow.mLevelBannerTexture   = gameflow.setLoadBanner(levNames[gameflow._1FC]);
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTexture = nullptr;
			}

			currentSection = new GameSetupSection();
			gsys->endLoading();
			break;

		case ONEPLAYER_CardSelect:
			currentSection = new CardSelectSection();
			break;

		case ONEPLAYER_MapSelect:
			currentSection = new MapSelectSection();
			break;

		case ONEPLAYER_Unk2:
			if (!gameflow.mLevelBannerTexture) {
				gameflow.mLevelBannerTexture = gameflow.setLoadBanner(levNames[nextSectionType]);
			}

			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			FOREACH_NODE(StageInfo, flowCont.mRootInfo.mChild, stage)
			{
				if (strcmp(stage->mFileName, "stages/practice.ini") == 0) {
					flowCont.mCurrentStage = stage;
					sprintf(flowCont.mStagePath1, "%s", stage->mFileName);
					sprintf(flowCont.mStagePath2, "%s", stage->mFileName);
					break;
				}
			}

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 1;
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow._1FC                    = 3;
			break;

		case ONEPLAYER_Unk3:
			if (!gameflow.mLevelBannerTexture) {
				gameflow.mLevelBannerTexture = gameflow.setLoadBanner(levNames[nextSectionType]);
			}
			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			FOREACH_NODE(StageInfo, flowCont.mRootInfo.mChild, stage)
			{
				if (strcmp(stage->mFileName, "stages/stage1.ini") == 0) {
					flowCont.mCurrentStage = stage;
					sprintf(flowCont.mStagePath1, "%s", stage->mFileName);
					sprintf(flowCont.mStagePath2, "%s", stage->mFileName);
					break;
				}
			}

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 1;
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow._1FC                    = 4;
			break;

		case ONEPLAYER_Unk4:
			if (!gameflow.mLevelBannerTexture) {
				gameflow.mLevelBannerTexture = gameflow.setLoadBanner(levNames[nextSectionType]);
			}

			gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			FOREACH_NODE(StageInfo, flowCont.mRootInfo.mChild, stage)
			{
				if (strcmp(stage->mFileName, "stages/play_3.ini") == 0) {
					flowCont.mCurrentStage = stage;
					sprintf(flowCont.mStagePath1, "%s", stage->mFileName);
					sprintf(flowCont.mStagePath2, "%s", stage->mFileName);
					break;
				}
			}

			gameflow.mWorldClock.setTime(gameflow.mParameters->mStartHour());
			gameflow.mWorldClock.mCurrentDay = 2;
			gameflow.mNextOnePlayerSectionID = ONEPLAYER_NewPikiGame;
			gameflow._1FC                    = 10;
			break;

		case ONEPLAYER_IntroGame:
			currentSection = new IntroGameSection();
			break;

		case ONEPLAYER_NewPikiGame:
			if (!gsys->_260) {
				gsys->startLoading(&gameflow.mGameLoadIdler, true, 60);
			}

			Texture* tex = nullptr;
			if (flowCont.mCurrentStage->mStageID <= STAGE_LASTVALID) {
				gameflow.mLevelBannerTexture   = gameflow.setLoadBanner(levNames[flowCont.mCurrentStage->mStageID]);
				gameflow.mLevelBannerFadeValue = 0.0f;
			} else {
				gameflow.mLevelBannerTexture = tex;
			}

			currentSection = new NewPikiGameSection();
			break;

		case ONEPLAYER_GameCourseClear:
			currentSection = new GameCourseClearSection();
			break;

		case ONEPLAYER_GameStageClear:
			currentSection = new GameStageClearSection();
			break;

		case ONEPLAYER_GameCredits:
			gsys->startLoading(nullptr, true, 60);
			currentSection = new GameCreditsSection();
			gsys->endLoading();
			break;

		case ONEPLAYER_GameExit:
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

/*
 * --INFO--
 * Address:	80053B6C
 * Size:	0000F0
 */
void __sinit_game_cpp(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  subi      r30, r3, 0x24E0
	  lis       r3, 0x8022
	  stw       r29, 0xC(r1)
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r28, 0x8(r1)
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r30)
	  addi      r4, r3, 0x66EC
	  addi      r3, r30, 0
	  stw       r31, 0x10(r30)
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0x2ECF0
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6908
	  addi      r29, r30, 0x2C
	  stw       r0, 0x0(r30)
	  mr        r3, r29
	  bl        0x72110
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7CBC
	  addi      r28, r30, 0x90
	  stw       r0, 0x0(r29)
	  addi      r3, r28, 0
	  subi      r4, r13, 0x7480
	  bl        -0x1EC40
	  lis       r3, 0x802A
	  addi      r0, r3, 0x68BC
	  stw       r0, 0x0(r28)
	  li        r4, 0x5
	  li        r3, 0x7
	  sth       r31, 0x24(r30)
	  subi      r0, r13, 0x7480
	  sth       r4, 0x26(r30)
	  sth       r3, 0x28(r30)
	  stw       r31, 0x20(r30)
	  stw       r31, 0xA0(r30)
	  stw       r31, 0x9C(r30)
	  stw       r31, 0x98(r30)
	  stw       r0, 0x94(r30)
	  stw       r31, 0x244(r30)
	  stw       r31, 0x230(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
