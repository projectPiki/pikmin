#include "zen/DrawSave.h"
#include "SoundMgr.h"
#include "gameflow.h"
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
DEFINE_PRINT("drawOptionSave")

/*
 * --INFO--
 * Address:	801F5500
 * Size:	00004C
 */
zen::DrawOptionSave::DrawOptionSave()
{
	setMode(MODE_Sleep, nullptr);
}

/*
 * --INFO--
 * Address:	801F554C
 * Size:	000188
 */
bool zen::DrawOptionSave::update(Controller* controller)
{
	bool res = false;
	switch (mMode) {
	case MODE_Sleep:
		break;

	case MODE_Start:
		if (mSaveMes.update(controller)) {
			switch (mSaveMes.getModeFlag()) {
			case DrawSaveMes::MODE_Unk3:
				setMode(MODE_CardCheck, controller);
				break;
			case DrawSaveMes::MODE_Unk6:
				setMode(MODE_Unk8, nullptr);
				break;
			default:
				PRINT("MODE ERROR \n");
				ERROR("MODE ERROR \n");
				break;
			}
		}
		break;

	case MODE_CardCheck:
		modeCardCheck(controller);
		break;

	case MODE_Saving:
		gameflow.mMemoryCard.saveOptions();
		if (gameflow.mMemoryCard.didSaveFail()) {
			setMode(MODE_SaveFail, nullptr);
		} else {
			setMode(MODE_SaveOK, nullptr);
		}
		break;

	case MODE_SaveOK:
		if (mSaveMes.update(controller)) {
			if (mSaveMes.getModeFlag() == DrawSaveMes::MODE_Finish) {
				setMode(MODE_Unk6, nullptr);
			} else {
				PRINT("MODE ERROR \n");
				ERROR("MODE ERROR \n");
			}
		}
		break;

	case MODE_SaveFail:
		if (mSaveMes.update(controller)) {
			if (mSaveMes.getModeFlag() == DrawSaveMes::MODE_Finish) {
				setMode(MODE_Unk7, nullptr);
			} else {
				PRINT("MODE ERROR \n");
				ERROR("MODE ERROR \n");
			}
		}
		break;

	case MODE_Unk6:
	case MODE_Unk7:
	case MODE_Unk8:
	case MODE_Unk9:
		res = true;
		break;

	default:
		PRINT("Unknown mode:%d \n", mMode);
		break;
	}

	return res;
}

/*
 * --INFO--
 * Address:	801F56D4
 * Size:	00006C
 */
void zen::DrawOptionSave::draw(Graphics& gfx)
{
	if (mMode != MODE_Sleep && mMode != MODE_Unk8) {
		mSaveMes.draw(gfx);
		if (mMode == MODE_CardCheck) {
			mMemChkMgr.draw(gfx);
		}
	}
}

/*
 * --INFO--
 * Address:	801F5740
 * Size:	000094
 */
void zen::DrawOptionSave::modeCardCheck(Controller* controller)
{
	if (controller) {
		switch (mMemChkMgr.update(controller)) {
		case ogScrMemChkMgr::ExitFailure:
			setMode(MODE_Unk7, nullptr);
			break;
		case ogScrMemChkMgr::ExitSuccess:
			setMode(MODE_Unk9, nullptr);
			break;
		case ogScrMemChkMgr::Finished:
			setMode(MODE_Saving, nullptr);
			break;
		}
	} else {
		PRINT("Controller is NULL. \n");
		ERROR("Controller is NULL. \n");
	}
}

/*
 * --INFO--
 * Address:	801F57D4
 * Size:	000028
 */
void zen::DrawOptionSave::init()
{
	setMode(MODE_Sleep, nullptr);
}

/*
 * --INFO--
 * Address:	801F57FC
 * Size:	000028
 */
void zen::DrawOptionSave::start()
{
	setMode(MODE_Start, nullptr);
}

/*
 * --INFO--
 * Address:	801F5824
 * Size:	000120
 */
void zen::DrawOptionSave::setMode(u32 mode, Controller* controller)
{
	mMode = mode;
	switch (mMode) {
	case MODE_Sleep:
		mSaveMes.sleep();
		break;

	case MODE_Start:
		mSaveMes.mesAppear();
		break;

	case MODE_CardCheck:
		mMemChkMgr.start();
		modeCardCheck(controller);
		break;

	case MODE_Saving:
#if defined(VERSION_G98E01_PIKIDEMO)
		SeSystem::playSysSe(SE_PIKI_DAMAGED);
#else
		SeSystem::playSysSe(SYSSE_CARDACCESS);
#endif
		break;

	case MODE_SaveFail:
#if defined(VERSION_G98E01_PIKIDEMO)
		SeSystem::playSysSe(SE_WALL_HIT);
#else
		SeSystem::playSysSe(SYSSE_CARDERROR);
#endif
		mSaveMes.saveError();
		break;

	case MODE_SaveOK:
#if defined(VERSION_G98E01_PIKIDEMO)
		SeSystem::playSysSe(SE_PIKI_PRESSED);
#else
		SeSystem::playSysSe(SYSSE_CARDOK);
#endif
		mSaveMes.saveFinish();
		break;

	case MODE_Unk6:
	case MODE_Unk7:
	case MODE_Unk8:
	case MODE_Unk9:
		break;
	default:
		PRINT("Unknown set mode:%d \n", mMode);
		break;
	}
}
