#include "DebugLog.h"
#include "Graphics.h"
#include "zen/particle.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(19)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("particleManager");

const f32 zen::particleManager::DEFAULT_FRAME_RATE = 30.0f;

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
zen::particleGenerator* zen::particleManager::createGenerator(u8* data, Texture* tex, Texture* childTex, immut Vector3f& pos,
                                                              zen::CallBack1<zen::particleGenerator*>* cbGen,
                                                              zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cbPtcl)
{
	particleGenerator* ptclGen = pmGetPtclGen();
	if (ptclGen) {
		ptclGen->init(data, tex, childTex, pos, &mMdlMgr, cbGen, cbPtcl);
	}
	return ptclGen;
}

/**
 * @todo: Documentation
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
#if defined(WIN32)
	debugUpdate();
#endif
	mInactiveGenList.merge(&_20); // merges _20 into _10
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
void zen::particleManager::calcActiveList()
{
	mActivePtclGenCount       = mActiveGenList.getListNum();
	mActiveParticleCount      = mMaxParticles - mMdlMgr.getSleepPtclNum();
	mActiveChildParticleCount = mMaxChildParticles - mMdlMgr.getSleepPtclChildNum();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004 (Matching by size)
 */
void zen::particleManager::debugUpdate()
{
#if defined(WIN32)
	calcActiveList();
	if (mMaxUsedPtclGenCount < mActivePtclGenCount) {
		mMaxUsedPtclGenCount = mActivePtclGenCount;
	}
	if (mMaxUsedParticleCount < mActiveParticleCount) {
		mMaxUsedParticleCount = mActiveParticleCount;
	}
	if (mMaxUsedChildParticleCount < mActiveChildParticleCount) {
		mMaxUsedChildParticleCount = mActiveChildParticleCount;
	}
#endif
}

/**
 * @todo: Documentation
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
#if defined(WIN32)
	debugDraw(gfx);
#endif
}

/**
 * @todo: Documentation
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
#if defined(WIN32)
	debugDraw(gfx);
#endif
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004 (Matching by size)
 */
void zen::particleManager::debugDraw(Graphics& gfx)
{
#if defined(WIN32)
	Matrix4f orthoMtx;

	if (gsys->mToggleDebugExtra) {
		immut int x          = 40;
		immut int y          = 200;
		immut int charHeight = 12;

		gfx.setOrthogonal(orthoMtx.mMtx, AREA_FULL_SCREEN(gfx));
		gfx.setColour(COLOUR_WHITE, true);

		char buffer[PATH_MAX];
		sprintf(buffer, "Gens   %6d  %6d / %6d", mActivePtclGenCount, mMaxUsedPtclGenCount, mMaxPtclGens);
		gfx.texturePrintf(gsys->mConsFont, x, y, buffer);
		sprintf(buffer, "Ptcls  %6d  %6d / %6d", mActiveParticleCount, mMaxUsedParticleCount, mMaxParticles);
		gfx.texturePrintf(gsys->mConsFont, x, y + charHeight, buffer);
		sprintf(buffer, "Child  %6d  %6d / %6d", mActiveChildParticleCount, mMaxUsedChildParticleCount, mMaxChildParticles);
		gfx.texturePrintf(gsys->mConsFont, x, y + charHeight * 2, buffer);
	}

	if (mActivePtclGenCount == mMaxPtclGens) {
		gfx.setOrthogonal(orthoMtx.mMtx, RectArea(AREA_FULL_SCREEN(gfx)));
		gfx.setColour(COLOUR_WHITE, true);

		gfx.texturePrintf(gsys->mConsFont, 200, 240, "PTCL GEN BUF IS EMPTY");
	}

	if (mActiveParticleCount == mMaxParticles) {
		gfx.setOrthogonal(orthoMtx.mMtx, RectArea(AREA_FULL_SCREEN(gfx)));
		gfx.setColour(COLOUR_WHITE, true);

		gfx.texturePrintf(gsys->mConsFont, 230, 260, "PTCL BUF IS EMPTY");
	}

	if (mActiveChildParticleCount == mMaxChildParticles) {
		gfx.setOrthogonal(orthoMtx.mMtx, RectArea(AREA_FULL_SCREEN(gfx)));
		gfx.setColour(COLOUR_WHITE, true);

		gfx.texturePrintf(gsys->mConsFont, 260, 280, "PTCL CHILD BUF IS EMPTY");
	}
#endif
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
zen::particleGenerator* zen::particleManager::pmGetPtclGen()
{
	particleGenerator* ptclGen = (particleGenerator*)mInactiveGenList.get();
	if (ptclGen) {
		mActiveGenList.put(ptclGen);
	}

	return ptclGen;
}
