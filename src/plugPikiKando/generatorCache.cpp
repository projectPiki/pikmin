#include "DebugLog.h"
#include "Generator.h"
#include "OnePlayerSection.h"
#include "Pellet.h"
#include "PelletState.h"
#include "gameflow.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(11)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("GeneratorCache");

GeneratorCache* generatorCache;

/*
 * --INFO--
 * Address:	800DED68
 * Size:	000130
 */
GeneratorCache::GeneratorCache()
{
	init(new u8[GENCACHE_HEAP_SIZE], GENCACHE_HEAP_SIZE);
	mAliveCacheList.initCore("");
	mDeadCacheList.initCore("");

	for (int i = STAGE_START; i < STAGE_COUNT; i++) {
		addOne(i);
	}
}

/*
 * --INFO--
 * Address:	800DEE98
 * Size:	000018
 */
void GeneratorCache::init(u8* heap, int size)
{
	mCacheHeap      = heap;
	mTotalCacheSize = size;
	mUsedSize       = 0;
	mFreeSize       = size;
}

/*
 * --INFO--
 * Address:	800DEEB0
 * Size:	0000B8
 */
void GeneratorCache::initGame()
{
	mUsedSize    = 0;
	mFreeSize    = mTotalCacheSize;
	Cache* cache = static_cast<Cache*>(mAliveCacheList.mChild);
	while (cache) {
		Cache* next = static_cast<Cache*>(cache->mNext);
		cache->del();
		mDeadCacheList.add(cache);
		cache = next;
	}

	int idx = 0;
	FOREACH_NODE(Cache, mDeadCacheList.mChild, cache)
	{
		cache->mCourseIdx         = idx;
		cache->mHeapOffset        = 0;
		cache->mTotalCacheSize    = 0;
		cache->mGenCacheSize      = 0;
		cache->mCreatureCacheSize = 0;
		cache->mUfoPartsCacheSize = 0;
		cache->mGenCount          = 0;
		cache->mCreatureCount     = 0;
		cache->mUfoPartsCount     = 0;
		idx++;
	}

	PRINT("*********** INIT GAME CALLED !!!!!!!!!!!!!!!!!\n");
}

/*
 * --INFO--
 * Address:	800DEF68
 * Size:	0000F4
 */
void GeneratorCache::addOne(u32 stageIdx)
{
	if (!findCache(mAliveCacheList, stageIdx) && !findCache(mDeadCacheList, stageIdx)) {
		Cache* cache = new Cache(stageIdx);
		mDeadCacheList.add(cache);
	}
}

/*
 * --INFO--
 * Address:	800DF05C
 * Size:	000134
 */
void GeneratorCache::saveCard(RandomAccessStream& output)
{
	output.writeInt(mUsedSize);
	output.writeInt(mFreeSize);
	PRINT("heap saved @ %d\n", output.getPosition());

	for (int i = 0; i < GENCACHE_HEAP_SIZE; i++) {
		output.writeByte(mCacheHeap[i]);
	}

	int aliveCount;
	int deadCount;
	for (int i = STAGE_START; i < STAGE_COUNT; i++) {
		Cache* cache = findCache(mAliveCacheList, i);
		if (cache) {
			output.writeByte(0);
			aliveCount++;
		} else {
			cache = findCache(mDeadCacheList, i);
			if (!cache) {
				ERROR("no cache for course %d\n", i);
			}
			output.writeByte(255);
			deadCount++;
		}
		cache->saveCard(output);
	}

	PRINT("*** SAVE CARD (%d alives %d deads) \n", aliveCount, deadCount);
}

/*
 * --INFO--
 * Address:	800DF190
 * Size:	00023C
 */
void GeneratorCache::loadCard(RandomAccessStream& input)
{
	PRINT("********** LOAD FROM MEMORY CARD ********\n");
	mUsedSize = input.readInt();
	mFreeSize = input.readInt();

	CoreNode* node = mAliveCacheList.mChild;
	while (node) {
		CoreNode* next = node->mNext;
		Cache* cache   = static_cast<Cache*>(node);
		cache->del();
		mDeadCacheList.add(cache);
		node = next;
	}

	PRINT("heap load from %d\n", input.getPosition());
	int i;
	for (i = 0; i < GENCACHE_HEAP_SIZE; i++) {
		mCacheHeap[i] = input.readByte();
	}

	Cache tempList;
	for (i = STAGE_START; i < STAGE_COUNT; i++) {
		u8 deadOrAlive = input.readByte(); // 0 = alive, 255 = dead
		Cache* cache   = findCache(mDeadCacheList, i);
		if (!cache) {
			PRINT("NO CACHE %d in DeadList\n", i);
			FOREACH_NODE(Cache, mDeadCacheList.mChild, dead)
			{
				PRINT_GLOBAL("deadList : id %d", dead->mCourseIdx);
			}
			ERROR("bikkuri %d", i);
		}

		PRINT("load cache %d from %d\n", input.getPosition());
		cache->loadCard(input);
		if (deadOrAlive == 0) { // alive
			cache->del();
			tempList.add(cache);
		} else { // dead
			cache->del();
			mDeadCacheList.add(cache);
		}
	}

	for (Cache* cache = static_cast<Cache*>(tempList.mChild); cache; cache = static_cast<Cache*>(tempList.mChild)) {
		int minVal      = -1;
		Cache* minCache = nullptr;
		FOREACH_NODE(Cache, tempList.mChild, subCache)
		{
			if (minVal > subCache->mHeapOffset) {
				minVal   = subCache->mHeapOffset;
				minCache = subCache;
			}
		}
		if (minCache) {
			minCache->del();
			mAliveCacheList.add(minCache);
		}
	}

	assertValid();
}

/*
 * --INFO--
 * Address:	800DF3CC
 * Size:	00010C
 */
void GeneratorCache::Cache::saveCard(RandomAccessStream& output)
{
	output.writeInt(mCourseIdx);
	output.writeInt(mHeapOffset);
	output.writeInt(mTotalCacheSize);
	output.writeInt(mGenCacheSize);
	output.writeInt(mCreatureCacheSize);
	output.writeInt(mUfoPartsCacheSize);
	output.writeInt(mGenCount);
	output.writeInt(mCreatureCount);
	output.writeInt(mUfoPartsCount);
}

/*
 * --INFO--
 * Address:	800DF4D8
 * Size:	00010C
 */
void GeneratorCache::Cache::loadCard(RandomAccessStream& input)
{
	mCourseIdx         = input.readInt();
	mHeapOffset        = input.readInt();
	mTotalCacheSize    = input.readInt();
	mGenCacheSize      = input.readInt();
	mCreatureCacheSize = input.readInt();
	mUfoPartsCacheSize = input.readInt();
	mGenCount          = input.readInt();
	mCreatureCount     = input.readInt();
	mUfoPartsCount     = input.readInt();
}

/*
 * --INFO--
 * Address:	800DF5E4
 * Size:	000028
 */
GeneratorCache::Cache* GeneratorCache::findCache(GeneratorCache::Cache& list, u32 stageIdx)
{
	FOREACH_NODE(Cache, list.mChild, cache)
	{
		if (cache->mCourseIdx == stageIdx) {
			return cache;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800DF60C
 * Size:	000160
 */
void GeneratorCache::preload(u32 stageIdx)
{
	for (int i = 0; i < 10; i++) {
		PRINT("************** PRELOAD **************\n"); // lol
	}

	Cache* cache = findCache(mAliveCacheList, stageIdx);
	if (cache) {
		PRINT("cache = %x\n", cache);
		u8* heapedCache = &mCacheHeap[cache->mHeapOffset];
		PRINT("load from %x : %d generators\n", heapedCache, cache->mGenCount);

		RamStream stream(heapedCache, cache->mTotalCacheSize);
		for (int i = 0; i < cache->mGenCount; i++) {
			PRINT("reading generator %d from ram : %x\n", i, stream.getPosition());
			Generator* gen = new Generator();
			PRINT("NEW DONE\n");
			Generator::ramMode = true;
			gen->read(stream);
			PRINT("generator read done\n");
			Generator::ramMode      = false;
			gen->mGeneratorListIdx  = i;
			gen->mIsRamReadDisabled = false;
			generatorList->mGenListHead->add(gen);
		}

		prepareUfoParts(cache);
	} else {
		PRINT("no data for stage %d\n", stageIdx);
	}

	for (int i = 0; i < 10; i++) {
		PRINT("**************-----------************\n"); // lol
	}

	STACK_PAD_VAR(2); // idk, this has all the inlines in the map - probably some extra temp variable usage.
}

/*
 * --INFO--
 * Address:	800DF76C
 * Size:	000128
 */
bool GeneratorCache::hasUfoParts(u32 stageIdx, u32 ufoPartIdx)
{
	Cache* cache = findCache(mAliveCacheList, stageIdx);
	if (cache) {
		void* heap = (void*)(((u32)mCacheHeap + cache->mHeapOffset + cache->mGenCacheSize) + cache->mCreatureCacheSize);
		RamStream stream(heap, cache->mUfoPartsCacheSize);
		for (int i = 0; i < cache->mUfoPartsCount; i++) {
			int thisPartIdx = stream.readInt();
			if (thisPartIdx == ufoPartIdx) {
				return true;
			}

			stream.readFloat();
			stream.readFloat();
			stream.readFloat();
			stream.readByte();
			stream.readFloat();
			stream.readFloat();
			stream.readFloat();
		}
	}
	return false;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800DF894
 * Size:	00019C
 */
void GeneratorCache::load(u32 stageIdx)
{
	PRINT("loading stage %d ...\n", stageIdx);
	Cache* cache = findCache(mAliveCacheList, stageIdx);
	PRINT("cahce = %x\n", cache);
	if (cache) {
		PRINT("cache = %x\n", cache);
		void* heap = (void*)(((u32)mCacheHeap + cache->mHeapOffset + cache->mGenCacheSize));
		PRINT("load from %x : %d creatures\n", heap, cache->mCreatureCount);
		RamStream stream(heap, cache->mCreatureCacheSize);
		for (int i = 0; i < cache->mCreatureCount; i++) {
			PRINT("reading creature %d from ram\n", i);
			int genNum = stream.readInt();

			PRINT("generator number : %d\n", genNum);
			Generator* gen = generatorList->findGenerator(genNum);
			if (!gen) {
				PRINT("*******************************************************************\n");
				PRINT("\tno generator : genNo = %d\n", genNum);
				ERROR("why?\n");
			}

			gen->loadCreature(stream);
		}

		loadUfoParts(cache);
		PRINT("** VALID CHECK BEFORE SLIDING \n");
		assertValid();
		u32 size       = cache->mTotalCacheSize;
		CoreNode* node = cache;
		while (node->mNext) {
			Cache* nextCache = (Cache*)node->mNext;
			node             = node->mNext;

			PRINT("** n = %x n->sibling = %x\n", node, node->mNext);
			PRINT("** start slide : length = %x size = %x\n", nextCache->mTotalCacheSize, size);

			u8* srcCache = mCacheHeap + nextCache->mHeapOffset;
			u8* dstCache = srcCache - size;
			PRINT("heap is %x to %x\n", mCacheHeap, mCacheHeap + GENCACHE_HEAP_SIZE);

			PRINT("** COPY SRC %x(offset %x) TO DST %x\n", srcCache, nextCache->mHeapOffset, dstCache);
			for (int i = 0; i < nextCache->mTotalCacheSize; i++) {
				dstCache[i] = srcCache[i];
			}

			nextCache->mHeapOffset -= size;
			PRINT("** (%d) length : copy done\n", nextCache->mTotalCacheSize);
		}

		cache->del();
		mDeadCacheList.add(cache);
		mUsedSize -= size;
		mFreeSize += size;
		PRINT("** VALID CHECK AFTER SLIDING \n");
		assertValid();
		dump();
	}
}

/*
 * --INFO--
 * Address:	800DFA30
 * Size:	000090
 */
void GeneratorCache::beginSave(u32 stageIdx)
{
	Cache* cache = findCache(mDeadCacheList, stageIdx);
	if (!cache) {
		cache = findCache(mAliveCacheList, stageIdx);
		if (cache) {
			PRINT("try to write alive cache (%d)! \n", stageIdx);
			ERROR("try to write alive cache %d\n", stageIdx);
		} else {
			PRINT("cache id %d is not valid!\n", stageIdx);
			ERROR("cache id %d is not valid\n", stageIdx);
		}
	}

	cache->mHeapOffset        = mUsedSize;
	cache->mTotalCacheSize    = 0;
	cache->mGenCacheSize      = 0;
	cache->mCreatureCacheSize = 0;
	cache->mUfoPartsCacheSize = 0;
	cache->mGenCount          = 0;
	cache->mCreatureCount     = 0;
	cache->mUfoPartsCount     = 0;
	mCurrentSaveCacheIdx      = stageIdx;
}

/*
 * --INFO--
 * Address:	800DFAC0
 * Size:	000080
 */
void GeneratorCache::endSave()
{
	Cache* cache = findCache(mDeadCacheList, mCurrentSaveCacheIdx);
	if (!cache) {
		ERROR("endSave() : currID(%d) is broken !\n", mCurrentSaveCacheIdx);
	}

	cache->del();
	mAliveCacheList.add(cache);
	assertValid();
}

/*
 * --INFO--
 * Address:	800DFB40
 * Size:	000160
 */
void GeneratorCache::saveGenerator(Generator* gen)
{
	if (gen->mDayLimit == -1 || gen->mDayLimit > gameflow.mWorldClock.mCurrentDay) {
		Cache* cache = findCache(mDeadCacheList, mCurrentSaveCacheIdx);
		if (!cache) {
			ERROR("currID(%d) is broken !\n", mCurrentSaveCacheIdx);
		}

		void* heap = (void*)(((u32)mCacheHeap + mUsedSize));
		RamStream stream(heap, mFreeSize);
		PRINT("ramStream :%08x - %08x (%.2fK free)\n", (u32)heap, (u32)heap + mFreeSize, mFreeSize / 1024.0f);

		Generator::ramMode     = true;
		gen->mGeneratorListIdx = cache->mGenCount;
		gen->write(stream);
		Generator::ramMode = false;

		int streamPos = stream.getPosition();
		mUsedSize += streamPos;
		mFreeSize -= streamPos;

		if (mFreeSize <= 0) {
			PRINT("cache overflow ! : id %d\n", mCurrentSaveCacheIdx);
			dump();
			ERROR("cache overflow! %d\n", mCurrentSaveCacheIdx);
		} else {
			if (mFreeSize < 0x400) {
				PRINT("WARNING ** GEN CACHE is about to overflow (id %d)!\n", mCurrentSaveCacheIdx);
			}
		}

		cache->mGenCount++;
		cache->mTotalCacheSize += streamPos;
		cache->mGenCacheSize += streamPos;
	}
}

/*
 * --INFO--
 * Address:	800DFCA0
 * Size:	000118
 */
void GeneratorCache::prepareUfoParts(GeneratorCache::Cache* cache)
{
	PRINT("prepare ufo parts ** %d\n", cache->mUfoPartsCount);

	void* heap = (void*)(((u32)mCacheHeap + cache->mHeapOffset + cache->mGenCacheSize) + cache->mCreatureCacheSize);
	RamStream stream(heap, cache->mUfoPartsCacheSize);

	for (int i = 0; i < cache->mUfoPartsCount; i++) {
		u32 id = stream.readInt();
		ID32 partID(id);
		PRINT("::preload ufoparts %d (id = %s)\n", i, partID.mStringID);

		PelletConfig* config = pelletMgr->getConfig(id);
		if (!config) {
			ERROR("unknown pellet id %c%c%c%c\n", 0, 0, 0, (u8)id);
		}

		stream.readFloat();
		stream.readFloat();
		stream.readFloat();
		stream.readByte();
		stream.readFloat();
		stream.readFloat();
		stream.readFloat();
		pelletMgr->addUseList(config->mPelletId.mId);
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	800DFDB8
 * Size:	00011C
 */
void GeneratorCache::loadUfoParts(GeneratorCache::Cache* cache)
{
	void* heap = (void*)(((u32)mCacheHeap + cache->mHeapOffset + cache->mGenCacheSize) + cache->mCreatureCacheSize);
	PRINT("load from %x : %d ufo parts\n", (u32)heap, cache->mUfoPartsCount);
	RamStream stream(heap, cache->mUfoPartsCacheSize);
	PRINT("********* LOAD UFO PARTS (%d)*************************\n", cache->mUfoPartsCount);

	for (int i = 0; i < cache->mUfoPartsCount; i++) {
		u32 id       = stream.readInt();
		Pellet* part = pelletMgr->newPellet(id, nullptr);
		if (!part) {
			ERROR("loadUfoParts:create pellet failed!\n");
		}

		part->load(stream, true);
		part->init(part->mSRT.t);
		part->startAI(0);
		part->mStateMachine->transit(part, 5);
		PRINT("CREATE PELLET !!!!!!!!\n");
	}
	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	800DFED4
 * Size:	000124
 */
void GeneratorCache::saveUfoParts(Pellet* part)
{
	Cache* cache = findCache(mDeadCacheList, mCurrentSaveCacheIdx);
	if (!cache) {
		ERROR("currID(%d) is broken !\n", mCurrentSaveCacheIdx);
	}

	void* heap = (void*)(((u32)mCacheHeap + mUsedSize));
	RamStream stream(heap, mFreeSize);
	stream.writeInt(part->mConfig->mModelId.mId);
	part->save(stream, true);
	int pos = stream.getPosition();
	mUsedSize += pos;
	mFreeSize -= pos;
	if (mFreeSize <= 0) {
		PRINT("cache overflow ! : id %d\n", mCurrentSaveCacheIdx);
		ERROR("cache over-flow ! id %d\n", mCurrentSaveCacheIdx);
	} else if (mFreeSize < 0x400) {
		PRINT("WARNING ** GEN CACHE is about to overflow (id %d)!\n", mCurrentSaveCacheIdx);
	}

	cache->mUfoPartsCount++;
	cache->mTotalCacheSize += pos;
	cache->mUfoPartsCacheSize += pos;
}

/*
 * --INFO--
 * Address:	800DFFF8
 * Size:	000168
 */
void GeneratorCache::saveGeneratorCreature(Generator* gen)
{
	if (gen->isExpired()) {
		PRINT("SAVE GENERATOR CREATURE * EXPIRED\n");
		return;
	}

	Cache* cache = findCache(mDeadCacheList, mCurrentSaveCacheIdx);
	if (!cache) {
		ERROR("currID(%d) is broken !\n", mCurrentSaveCacheIdx);
	}

	void* heap = (void*)(((u32)mCacheHeap + mUsedSize));
	RamStream stream(heap, mFreeSize);
	PRINT("ramStream :%08x - %08x (%.2fK free)\n", (u32)heap, (u32)heap + mFreeSize, mFreeSize / 1024.0f);
	if (!gen->mLatestSpawnCreature) {
		return;
	}
	Generator::ramMode = true;
	if (gen->mLatestSpawnCreature) {
		PRINT("** WRITING generator no %d\n", gen->mGeneratorListIdx);
		stream.writeInt(gen->mGeneratorListIdx);
		gen->saveCreature(stream);
	}

	Generator::ramMode = false;
	int pos            = stream.getPosition();
	mUsedSize += pos;
	mFreeSize -= pos;

	if (mFreeSize <= 0) {
		PRINT("cache overflow ! : id %d\n", mCurrentSaveCacheIdx);
		ERROR("cache overflow %d\n", mCurrentSaveCacheIdx);
	} else if (mFreeSize < 0x400) {
		PRINT("WARNING ** GEN CACHE is about to overflow (id %d)!\n", mCurrentSaveCacheIdx);
	}

	cache->mCreatureCount++;
	cache->mTotalCacheSize += pos;
	cache->mCreatureCacheSize += pos;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void GeneratorCache::Cache::dump()
{
	PRINT("\tcourse %d\n", mCourseIdx);
	PRINT("\t%x - %x : (%.2fK)\n", mHeapOffset, mTotalCacheSize + mHeapOffset, mTotalCacheSize / 1024.0f);
	PRINT("\tgenerator = %d size = %d\n", mGenCount, mGenCacheSize);
	PRINT("\tcreature  = %d size = %d\n", mCreatureCount, mCreatureCacheSize);
	PRINT("\tufo parts  = %d size = %d\n", mUfoPartsCount, mUfoPartsCacheSize);
}

/*
 * --INFO--
 * Address:	800E0160
 * Size:	00005C
 */
void GeneratorCache::dump()
{
	PRINT("************ Generator Cache ***********\n");
	PRINT("--- alive caches ---\n");
	FOREACH_NODE(Cache, mAliveCacheList.mChild, cache)
	{
		cache->dump();
	}
	PRINT("--- dead cache ---\n");
	FOREACH_NODE(Cache, mDeadCacheList.mChild, cache)
	{
		cache->dump();
	}
	PRINT("*******************************\n");

	// need this to not inline in assertValid
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	800E01BC
 * Size:	00006C
 */
void GeneratorCache::assertValid()
{
	Cache* cache = static_cast<Cache*>(mAliveCacheList.mChild);
	u32 heapPos  = 0;
	for (cache; cache; cache = static_cast<Cache*>(cache->mNext)) {
		if (cache->mHeapOffset != heapPos) {
			dump();
			PRINT("right offset = %x\n", heapPos);
			ERROR("GenCache Broken!");
		}
		heapPos += cache->mTotalCacheSize;
	}
}
