#include "zen/DrawProgre.h"
#include "DebugLog.h"
#include "SoundMgr.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("drawProgre")

zen::DrawProgre::DrawProgre()
{
	mMenu = new DrawMenu("screen/blo/progre.blo", false, false);
	mMenu->setCancelSelectMenuNo(1);
	mMenu->setCancelKeyAssign(KBBTN_NONE); // can't cancel the progressive mode screen!
	mMenu->setDecideKeyAssign(KBBTN_START | KBBTN_A);

	mProgreMes   = new DrawProgreMes();
	mReturnState = RETSTATE_NULL;
}

void zen::DrawProgre::start()
{
	mMenu->start(0);
	mReturnState = RETSTATE_Unk0;
	SeSystem::playSysSe(SYSSE_PAUSE);
	mProgreMes->init();
}

zen::DrawProgre::returnStatusFlag zen::DrawProgre::update(Controller* controller)
{
	mProgreMes->update(controller);
	if (mMenu->update(controller)) {
		switch (mMenu->getSelectMenu()) {
		case 0:
			mProgreMes->start(DrawProgreMes::MES_Unk0);
			break;

		case 1:
			mProgreMes->start(DrawProgreMes::MES_Unk1);
			break;
		}
	}

	switch (mProgreMes->getModeFlag()) {
	case DrawProgreMes::MODE_Unk4:
		mReturnState = (returnStatusFlag)(mMenu->getSelectMenu() + 1);
		break;
	}

	STACK_PAD_VAR(6);
	return mReturnState;
}

void zen::DrawProgre::draw(Graphics& gfx)
{
	mMenu->draw(gfx);
	mProgreMes->draw(gfx);
}
