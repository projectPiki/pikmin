#include "Age.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "Pellet.h"
#include "PelletState.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("genPellet")

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
GenObjectPellet::GenObjectPellet()
    : GenObject('pelt', "ペレットをうむ")
{
	mIndex = 0;
}

/**
 * @TODO: Documentation
 */
static GenObject* makeObjectPellet()
{
	return new GenObjectPellet();
}

/**
 * @TODO: Documentation
 */
void GenObjectPellet::initialise()
{
	GenObjectFactory::factory->registerMember('pelt', makeObjectPellet, "ペレットをうむ", 'v0.0');
}

/**
 * @TODO: Documentation
 */
void GenObjectPellet::doRead(RandomAccessStream& stream)
{
	mPelletId.read(stream);
	mIndex = pelletMgr->getConfigIndex(mPelletId.mId);
	if (mIndex == -1) {
		mIndex = 0;
	}
}

/**
 * @TODO: Documentation
 */
void GenObjectPellet::doWrite(RandomAccessStream& stream)
{
	mPelletId = pelletMgr->getConfigFromIdx(mIndex)->mModelId;
	mPelletId.write(stream);
	PRINT("******* WRITE \n");
	mPelletId.print();
}

/**
 * @TODO: Documentation
 */
void GenObjectPellet::updateUseList(Generator*, int)
{
	PelletConfig* cfg = pelletMgr->getConfig(mPelletId.mId);
	if (cfg) {
		pelletMgr->addUseList(cfg->mPelletId.mId);
	}
}

/**
 * @TODO: Documentation
 */
Creature* GenObjectPellet::birth(BirthInfo& info)
{
	mPelletId.print();
	Pellet* pelt = pelletMgr->newPellet(mPelletId.mId, nullptr);
	if (pelt) {
		pelt->init(info.mPosition);
		pelt->mSRT.r         = info.mRotation;
		pelt->mFaceDirection = pelt->mSRT.r.y;
		pelt->mGenerator     = info.mGenerator;
		pelt->startAI(0);
		if (info.mGenerator->doAdjustFaceDir()) {
			pelt->enableFaceDirAdjust();
		}
		f32 scale = pelt->mConfig->mPelletScale();
		pelt->mSRT.s.set(scale, scale, scale);
		pelt->mStateMachine->transit(pelt, 0);
	} else {
		PRINT("FAILED!!!\n");
	}
	return pelt;
}

#ifdef WIN32

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
