#include "Age.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "Pellet.h"
#include "PelletState.h"
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
DEFINE_PRINT("genPellet")

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
GenObjectPellet::GenObjectPellet()
    : GenObject('pelt', "ペレットをうむ")
{
	mIndex = 0;
}

/*
 * --INFO--
 * Address:	80099D1C
 * Size:	000080
 */
static GenObject* makeObjectPellet()
{
	return new GenObjectPellet();
}

/*
 * --INFO--
 * Address:	80099D9C
 * Size:	00008C
 */
void GenObjectPellet::initialise()
{
	GenObjectFactory::factory->registerMember('pelt', makeObjectPellet, "ペレットをうむ", 'v0.0');
}

/*
 * --INFO--
 * Address:	80099E28
 * Size:	000054
 */
void GenObjectPellet::doRead(RandomAccessStream& stream)
{
	mPelletId.read(stream);
	mIndex = pelletMgr->getConfigIndex(mPelletId.mId);
	if (mIndex == -1) {
		mIndex = 0;
	}
}

/*
 * --INFO--
 * Address:	80099E7C
 * Size:	000070
 */
void GenObjectPellet::doWrite(RandomAccessStream& stream)
{
	mPelletId = pelletMgr->getConfigFromIdx(mIndex)->mModelId;
	mPelletId.write(stream);
	PRINT("******* WRITE \n");
	mPelletId.print();
}

/*
 * --INFO--
 * Address:	80099EEC
 * Size:	000040
 */
void GenObjectPellet::updateUseList(Generator*, int)
{
	PelletConfig* cfg = pelletMgr->getConfig(mPelletId.mId);
	if (cfg) {
		pelletMgr->addUseList(cfg->mPelletId.mId);
	}
}

/*
 * --INFO--
 * Address:	80099F2C
 * Size:	000100
 */
Creature* GenObjectPellet::birth(BirthInfo& info)
{
	mPelletId.print();
	Pellet* pelt = pelletMgr->newPellet(mPelletId.mId, nullptr);
	if (pelt) {
		pelt->init(info.mPosition);
		pelt->mRotation      = info.mRotation;
		pelt->mFaceDirection = pelt->mRotation.y;
		pelt->mGenerator     = info.mGenerator;
		pelt->startAI(0);
		if (info.mGenerator->doAdjustFaceDir()) {
			pelt->enableFaceDirAdjust();
		}
		f32 scale = pelt->mConfig->mPelletScale();
		pelt->mScale.set(scale, scale, scale);
		pelt->mStateMachine->transit(pelt, 0);
	} else {
		PRINT("FAILED!!!\n");
	}
	return pelt;
}

#ifdef DEVELOP

void GenObjectPellet::doGenAge(AgeServer& server)
{
	server.StartOptionBox("ペレット", (int*)&mPelletId.mId, 252);
	for (int i = 0; i < pelletMgr->getNumConfigs(); i++) {
		PelletConfig* config = pelletMgr->getConfigFromIdx(i);
		server.NewOption(config->mPelletName().mString, config->mPelletId.mId);
	}
	server.EndOptionBox();
}

#endif
