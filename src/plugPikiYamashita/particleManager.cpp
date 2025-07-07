#include "DebugLog.h"
#include "Graphics.h"
#include "zen/particle.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(19)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("particleManager");

const f32 zen::particleManager::DEFAULT_FRAME_RATE = 30.0f;

/*
 * --INFO--
 * Address:	801A1100
 * Size:	00013C
 */
void zen::particleManager::init(u32 numPtclGens, u32 numParticles, u32 numChildParticles, f32 p4)
{
	if (numPtclGens > 0x1000) {
		ERROR("パーティクルジェネレイタの個数が大きすぎます。\n"); // 'The number of particle generators is too large.'
		numPtclGens = 0x1000;
	}

	if (numParticles > 0x2000) {
		ERROR("パーティクルの個数がが大きすぎます. \n"); // 'The number of particles is too large.'
		numParticles = 0x2000;
	}

	if (numChildParticles > 0x2000) {
		ERROR("チャイルドパーティクルの個数がが大きすぎます. \n"); // 'The number of child particles is too large.'
		numChildParticles = 0x2000;
	}

	_98                = p4;
	mMaxPtclGens       = numPtclGens;
	mMaxParticles      = numParticles;
	mMaxChildParticles = numChildParticles;
	mPtclGenList       = new particleGenerator[numPtclGens];

	mActiveGenList.init();
	mInactiveGenList.init();
	_20.init();

	for (int i = 0; i < numPtclGens; i++) {
		mInactiveGenList.put(&mPtclGenList[i]);
	}

	mMdlMgr.init(numParticles, numChildParticles);
	mSimplePtclMgr.init(&mMdlMgr);
	mMaxUsedPtclGenCount       = 0;
	mMaxUsedParticleCount      = 0;
	mMaxUsedChildParticleCount = 0;
}

/*
 * --INFO--
 * Address:	801A1288
 * Size:	000074
 */
zen::particleGenerator* zen::particleManager::createGenerator(u8* data, Texture* tex, Texture* childTex, Vector3f& pos,
                                                              zen::CallBack1<zen::particleGenerator*>* cbGen,
                                                              zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cbPtcl)
{
	particleGenerator* ptclGen = pmGetPtclGen();
	if (ptclGen) {
		ptclGen->init(data, tex, childTex, pos, &mMdlMgr, cbGen, cbPtcl);
	}
	return ptclGen;
}

/*
 * --INFO--
 * Address:	801A12FC
 * Size:	000110
 */
void zen::particleManager::update()
{
	zenList* end  = mActiveGenList.getOrigin();
	f32 timeStep  = _98 * gsys->getFrameTime();
	zenList* list = mActiveGenList.getTopList();
	while (list != end) {
		zenList* next          = list->mNext;
		particleGenerator* gen = (particleGenerator*)list;
		if (gen->update(timeStep)) {
			pmPutPtclGen(list);
		}
		list = next;
	}

	mSimplePtclMgr.update(timeStep);
	mInactiveGenList.merge(&_20); // merges _20 into _10
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::particleManager::calcActiveList()
{
	mActivePtclGenCount       = mActiveGenList.getListNum();
	mActiveParticleCount      = mMaxParticles - mMdlMgr.getSleepPtclNum();
	mActiveChildParticleCount = mMaxChildParticles - mMdlMgr.getSleepPtclChildNum();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::particleManager::debugUpdate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A140C
 * Size:	000074
 */
void zen::particleManager::draw(Graphics& gfx)
{
	zenList* end  = mActiveGenList.getOrigin();
	zenList* list = mActiveGenList.getTopList();
	while (list != end) {
		zenList* next          = list->mNext;
		particleGenerator* gen = (particleGenerator*)list;
		gen->draw(gfx);
		list = next;
	}

	mSimplePtclMgr.draw(gfx);
}

/*
 * --INFO--
 * Address:	801A1480
 * Size:	0000A8
 */
void zen::particleManager::cullingDraw(Graphics& gfx)
{
	zenList* end  = mActiveGenList.getOrigin();
	zenList* list = mActiveGenList.getTopList();
	while (list != end) {
		zenList* next          = list->mNext;
		particleGenerator* gen = (particleGenerator*)list;
		Vector3f genPos        = gen->getGPos();
		if (gfx.mCamera->isPointVisible(genPos, 100.0f)) {
			gen->draw(gfx);
		}
		list = next;
	}

	mSimplePtclMgr.draw(gfx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::particleManager::debugDraw(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A1528
 * Size:	00009C
 */
void zen::particleManager::killAllGenarator(bool doForceFinish)
{
	if (doForceFinish) {
		while (mActiveGenList.getOrigin() != mActiveGenList.getTopList()) {
			particleGenerator* gen = (particleGenerator*)mActiveGenList.getTopList();
			killGenerator(gen, true);
		}
		mSimplePtclMgr.forceFinish();

	} else {
		zenList* end  = mActiveGenList.getOrigin();
		zenList* list = mActiveGenList.getTopList();
		while (list != end) {
			zenList* next          = list->mNext;
			particleGenerator* gen = (particleGenerator*)list;
			killGenerator(gen, false);
			list = next;
		}
	}
}

/*
 * --INFO--
 * Address:	801A15C4
 * Size:	000098
 */
void zen::particleManager::killGenerator(zen::particleGenerator* gen, bool doForceFinish)
{
	if (pmCheckList(gen)) {
		if (doForceFinish) {
			gen->forceFinish();
			pmPutPtclGen(gen);
		} else {
			gen->finish();
		}
	}
}

/*
 * --INFO--
 * Address:	801A165C
 * Size:	0000B4
 */
void zen::particleManager::killGenerator(CallBack1<particleGenerator*>* cb1, CallBack2<particleGenerator*, particleMdl*>* cb2,
                                         bool doForceFinish)
{
	zenList* end  = mActiveGenList.getOrigin();
	zenList* list = mActiveGenList.getTopList();
	while (list != end) {
		zenList* next          = list->mNext;
		particleGenerator* gen = (particleGenerator*)list;
		if (doForceFinish) {
			if (gen->forceFinish(cb1, cb2)) {
				pmPutPtclGen(gen);
			}
		} else {
			gen->finish(cb1, cb2);
		}
		list = next;
	}
}

/*
 * --INFO--
 * Address:	801A1710
 * Size:	000030
 */
bool zen::particleManager::pmCheckList(zen::particleGenerator* testGen)
{
	bool ret               = false;
	particleGenerator* end = (particleGenerator*)mActiveGenList.getOrigin();
	for (particleGenerator* gen = (particleGenerator*)mActiveGenList.getTopList(); gen != end; gen = (particleGenerator*)gen->mNext) {
		if (gen == testGen) {
			ret = true;
			break;
		}
	}

	return ret;
}

/*
 * --INFO--
 * Address:	801A1740
 * Size:	000094
 */
zen::particleGenerator* zen::particleManager::pmGetPtclGen()
{
	particleGenerator* ptclGen = (particleGenerator*)mInactiveGenList.get();
	if (ptclGen) {
		mActiveGenList.put(ptclGen);
	}

	return ptclGen;
}
