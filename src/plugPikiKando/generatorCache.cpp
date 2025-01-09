#include "Generator.h"
#include "OnePlayerSection.h"
#include "gameflow.h"
#include "Pellet.h"
#include "sysNew.h"
#include "DebugLog.h"

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
			FOREACH_NODE(Cache, mDeadCacheList.mChild, dead) { PRINT("deadList : id %d", dead->mCourseIdx); }
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
			Generator* gen     = new Generator();
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

	u32 badCompiler[2]; // idk, this has all the inlines in the map - probably some extra temp variable usage.
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

	u32 badCompiler[2];
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
		u32 size         = cache->mTotalCacheSize;
		Cache* nextCache = cache;
		while (nextCache = static_cast<Cache*>(nextCache->mNext)) {
			PRINT("** n = %x n->sibling = %x\n", nextCache, nextCache->mNext);
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

	u32 badCompiler;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  stw       r29, 0x34(r1)
	  lwz       r31, 0x10(r3)
	  b         .loc_0x38

	.loc_0x24:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r4
	  bne-      .loc_0x34
	  b         .loc_0x44

	.loc_0x34:
	  lwz       r31, 0xC(r31)

	.loc_0x38:
	  cmplwi    r31, 0
	  bne+      .loc_0x24
	  li        r31, 0

	.loc_0x44:
	  cmplwi    r31, 0
	  beq-      .loc_0x180
	  lis       r3, 0x8022
	  lwz       r7, 0x20(r31)
	  addi      r0, r3, 0x7398
	  lwz       r5, 0x18(r31)
	  lwz       r6, 0x70(r30)
	  lis       r4, 0x8022
	  lwz       r8, 0x24(r31)
	  lis       r3, 0x802A
	  li        r29, 0
	  stw       r0, 0x1C(r1)
	  addi      r0, r4, 0x74C8
	  add       r4, r5, r7
	  stw       r0, 0x1C(r1)
	  addi      r0, r3, 0x755C
	  add       r4, r6, r4
	  stw       r0, 0x1C(r1)
	  li        r0, 0
	  stw       r4, 0x20(r1)
	  stw       r0, 0x24(r1)
	  stw       r8, 0x28(r1)
	  b         .loc_0xC4

	.loc_0xA0:
	  addi      r3, r1, 0x18
	  bl        -0xBA888
	  mr        r0, r3
	  lwz       r3, 0x3094(r13)
	  mr        r4, r0
	  bl        -0xD58
	  addi      r4, r1, 0x18
	  bl        -0x3B74
	  addi      r29, r29, 0x1

	.loc_0xC4:
	  lwz       r0, 0x30(r31)
	  cmplw     r29, r0
	  blt+      .loc_0xA0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x44C
	  mr        r3, r30
	  bl        0x848
	  lwz       r29, 0x1C(r31)
	  mr        r4, r31
	  b         .loc_0x138

	.loc_0xF0:
	  lwz       r3, 0x70(r30)
	  li        r6, 0
	  lwz       r0, 0x18(r4)
	  add       r5, r3, r0
	  sub       r0, r5, r29
	  mr        r3, r0
	  b         .loc_0x120

	.loc_0x10C:
	  lbz       r0, 0x0(r5)
	  addi      r6, r6, 0x1
	  addi      r5, r5, 0x1
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1

	.loc_0x120:
	  lwz       r0, 0x1C(r4)
	  cmplw     r6, r0
	  blt+      .loc_0x10C
	  lwz       r0, 0x18(r4)
	  sub       r0, r0, r29
	  stw       r0, 0x18(r4)

	.loc_0x138:
	  lwz       r4, 0xC(r4)
	  cmplwi    r4, 0
	  bne+      .loc_0xF0
	  mr        r3, r31
	  bl        -0x9F3CC
	  addi      r3, r30, 0x38
	  addi      r4, r31, 0
	  bl        -0x9F410
	  lwz       r0, 0x78(r30)
	  addi      r3, r30, 0
	  sub       r0, r0, r29
	  stw       r0, 0x78(r30)
	  lwz       r0, 0x7C(r30)
	  add       r0, r0, r29
	  stw       r0, 0x7C(r30)
	  bl        0x7B4
	  mr        r3, r30
	  bl        0x750

	.loc_0x180:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
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
			ERROR("unknown pellet id %c%c%c%c\n", 0, 0, 0, (u32)id);
		}

		stream.readFloat();
		stream.readFloat();
		stream.readFloat();
		stream.readByte();
		stream.readFloat();
		stream.readFloat();
		stream.readFloat();
		pelletMgr->addUseList(config->_44.mId);
	}

	u32 badCompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  li        r29, 0
	  stw       r28, 0x38(r1)
	  lwz       r6, 0x70(r3)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x7398
	  lwz       r8, 0x24(r4)
	  lwz       r7, 0x20(r4)
	  lwz       r5, 0x18(r4)
	  lis       r4, 0x8022
	  lwz       r9, 0x28(r31)
	  lis       r3, 0x802A
	  add       r5, r5, r7
	  stw       r0, 0x28(r1)
	  addi      r0, r4, 0x74C8
	  add       r4, r5, r8
	  stw       r0, 0x28(r1)
	  addi      r0, r3, 0x755C
	  add       r4, r6, r4
	  stw       r0, 0x28(r1)
	  li        r0, 0
	  stw       r4, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  stw       r9, 0x34(r1)
	  b         .loc_0xEC

	.loc_0x7C:
	  addi      r3, r1, 0x24
	  bl        -0xBAC70
	  addi      r28, r3, 0
	  addi      r4, r28, 0
	  addi      r3, r1, 0x18
	  bl        -0x9BE9C
	  lwz       r3, 0x301C(r13)
	  mr        r4, r28
	  bl        -0x47018
	  mr.       r30, r3
	  addi      r3, r1, 0x24
	  bl        -0xBABF0
	  addi      r3, r1, 0x24
	  bl        -0xBABF8
	  addi      r3, r1, 0x24
	  bl        -0xBAC00
	  addi      r3, r1, 0x24
	  bl        -0xBAC78
	  addi      r3, r1, 0x24
	  bl        -0xBAC10
	  addi      r3, r1, 0x24
	  bl        -0xBAC18
	  addi      r3, r1, 0x24
	  bl        -0xBAC20
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x44(r30)
	  bl        -0x47280
	  addi      r29, r29, 0x1

	.loc_0xEC:
	  lwz       r0, 0x34(r31)
	  cmplw     r29, r0
	  blt+      .loc_0x7C
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
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
		part->init(part->mPosition);
		part->startAI(0);
		part->mStateMachine->transit(part, 5);
		PRINT("CREATE PELLET !!!!!!!!\n");
	}
	u32 badCompiler;
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
	// TODO: work this out once more of pellet is done
	// I assume it writes the pellet config ID, so
	// stream.writeInt(part->mConfig->_2C.mId);
	// stream.writeInt(part->_55C->_2C);
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r4
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r3, 0x80(r3)
	  lwz       r31, 0x48(r29)
	  b         .loc_0x40

	.loc_0x2C:
	  lwz       r0, 0x14(r31)
	  cmplw     r0, r3
	  bne-      .loc_0x3C
	  b         .loc_0x4C

	.loc_0x3C:
	  lwz       r31, 0xC(r31)

	.loc_0x40:
	  cmplwi    r31, 0
	  bne+      .loc_0x2C
	  li        r31, 0

	.loc_0x4C:
	  cmplwi    r31, 0
	  lis       r3, 0x8022
	  lwz       r6, 0x70(r29)
	  addi      r4, r3, 0x7398
	  lwz       r5, 0x78(r29)
	  lwz       r7, 0x7C(r29)
	  lis       r3, 0x8022
	  addi      r0, r3, 0x74C8
	  stw       r4, 0x18(r1)
	  lis       r3, 0x802A
	  addi      r3, r3, 0x755C
	  stw       r0, 0x18(r1)
	  add       r4, r6, r5
	  li        r0, 0
	  stw       r3, 0x18(r1)
	  addi      r3, r1, 0x14
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  stw       r7, 0x24(r1)
	  lwz       r4, 0x55C(r30)
	  lwz       r4, 0x2C(r4)
	  bl        -0xBAC8C
	  addi      r3, r30, 0
	  addi      r4, r1, 0x14
	  li        r5, 0x1
	  bl        -0x55E14
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x78(r29)
	  add       r0, r0, r4
	  stw       r0, 0x78(r29)
	  lwz       r0, 0x7C(r29)
	  sub       r0, r0, r4
	  stw       r0, 0x7C(r29)
	  lwz       r0, 0x7C(r29)
	  cmpwi     r0, 0
	  bgt-      .loc_0xE0
	  b         .loc_0xE4

	.loc_0xE0:
	  cmpwi     r0, 0x400

	.loc_0xE4:
	  lwz       r3, 0x34(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x34(r31)
	  lwz       r0, 0x1C(r31)
	  add       r0, r0, r4
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x28(r31)
	  add       r0, r0, r4
	  stw       r0, 0x28(r31)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
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
		PRINT("currID(%d) is broken !\n", mCurrentSaveCacheIdx);
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
	PRINT("\tcreature = %d size = %d\n", mCreatureCount, mCreatureCacheSize);
	PRINT("\tufo parts = %d size = %d\n", mUfoPartsCount, mUfoPartsCacheSize);
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
	FOREACH_NODE(Cache, mAliveCacheList.mChild, cache) { cache->dump(); }
	PRINT("--- dead cache ---\n");
	FOREACH_NODE(Cache, mDeadCacheList.mChild, cache) { cache->dump(); }
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
