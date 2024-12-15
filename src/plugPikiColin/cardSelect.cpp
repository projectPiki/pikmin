#include "CardSelectSection.h"
#include "CardSelectSetupSection.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "BaseInf.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "CardSelect");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005503C
 * Size:	00023C
 */
CardSelectSection::CardSelectSection()
{
	Node::init("<CardSelectSection>");
	gsys->mFrameRate = 1;
	flowCont._A8     = nullptr;
	playerState->initGame();
	generatorCache->initGame();
	pikiInfMgr.initGame();
	FOREACH_NODE(StageInfo, flowCont.mRootInfo.mChild, stage)
	{
		stage->_20 = 0;
		stage->mStageInf.initGame();
	}

	gameflow.mGamePrefs._20 = 0;
	gameflow.mGamePrefs._1E = 0;

	if (gameflow._2B4 == 0) {
		Jac_SceneSetup(2, 0);
	}

	gsys->startLoading(nullptr, true, 60);
	add(new CardSelectSetupSection());
	gsys->endLoading();
}
