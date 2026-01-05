#include "zen/DrawProgre.h"
#include "DebugLog.h"
#include "SoundMgr.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("drawProgre")

/**
 * @todo: Documentation
 */
zen::DrawProgre::DrawProgre()
{
	mMenu = new DrawMenu("screen/blo/progre.blo", false, false);
	mMenu->setCancelSelectMenuNo(1);
	mMenu->setCancelKeyAssign(KBBTN_NONE); // can't cancel the progressive mode screen!
	mMenu->setDecideKeyAssign(KBBTN_START | KBBTN_A);

	mProgreMes   = new DrawProgreMes();
	mReturnState = RETSTATE_NULL;
}

/**
 * @todo: Documentation
 */
void zen::DrawProgre::start()
{
	mMenu->start(0);
	mReturnState = RETSTATE_Active;
	SeSystem::playSysSe(SYSSE_PAUSE);
	mProgreMes->init();
}

/**
 * @todo: Documentation
 */
zen::DrawProgre::returnStatusFlag zen::DrawProgre::update(Controller* controller)
{
	mProgreMes->update(controller);
	if (mMenu->update(controller)) {
		switch (mMenu->getSelectMenu()) {
		case 0:
			// Yes
			mProgreMes->start(DrawProgreMes::MES_Progressive);
			break;

		case 1:
			// No
			mProgreMes->start(DrawProgreMes::MES_Interlace);
			break;
		}
	}

	switch (mProgreMes->getModeFlag()) {
	case DrawProgreMes::MODE_Finished:
		mReturnState = (returnStatusFlag)(mMenu->getSelectMenu() + 1);
		break;
	}

	STACK_PAD_VAR(6);
	return mReturnState;
}

/**
 * @todo: Documentation
 */
void zen::DrawProgre::draw(Graphics& gfx)
{
	mMenu->draw(gfx);
	mProgreMes->draw(gfx);
}
