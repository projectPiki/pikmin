#include "SearchSystem.h"
#include "AIPerf.h"
#include "NaviMgr.h"
#include "ItemMgr.h"
#include "teki.h"
#include "Boss.h"
#include "PikiMgr.h"
#include "PlantMgr.h"
#include "Pellet.h"
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
DEFINE_PRINT("searchSys")

/*
 * --INFO--
 * Address:	800E2FB4
 * Size:	000004
 */
SearchSystem::SearchSystem()
{
}

/*
 * --INFO--
 * Address:	800E2FB8
 * Size:	00046C
 */
void SearchSystem::update()
{
	if (AIPerf::loopOptimise) {
		updateLoopOptimised();
		naviMgr->search(itemMgr);
		if (tekiMgr) {
			naviMgr->search(tekiMgr);
		}
		naviMgr->search(naviMgr);
		if (bossMgr) {
			naviMgr->search(bossMgr);
		}
		naviMgr->search(plantMgr);
		pikiMgr->search(plantMgr);
		itemMgr->search(itemMgr);
		if (bossMgr) {
			bossMgr->search(bossMgr);
		}
		if (tekiMgr) {
			tekiMgr->search(tekiMgr);
			tekiMgr->search(itemMgr);
		}
		if (bossMgr) {
			bossMgr->search(itemMgr);
		}
	} else {
		pikiMgr->search(itemMgr);
		pikiMgr->search(itemMgr->mMeltingPotMgr);
		if (tekiMgr) {
			pikiMgr->search(tekiMgr);
		}
		if (bossMgr) {
			pikiMgr->search(bossMgr);
		}
		pikiMgr->search(pikiMgr);
		pikiMgr->search(pelletMgr);

		naviMgr->search(itemMgr);
		naviMgr->search(itemMgr->mMeltingPotMgr);
		if (tekiMgr) {
			naviMgr->search(tekiMgr);
		}
		if (bossMgr) {
			naviMgr->search(bossMgr);
		}
		naviMgr->search(naviMgr);
		naviMgr->search(pelletMgr);

		naviMgr->search(plantMgr);
		pikiMgr->search(plantMgr);
		if (tekiMgr) {
			tekiMgr->search(plantMgr);
		}

		pikiMgr->search(naviMgr);
		itemMgr->search(itemMgr);
		itemMgr->search(itemMgr->mMeltingPotMgr);
		pelletMgr->search(itemMgr);
		pelletMgr->search(itemMgr->mMeltingPotMgr);
		if (bossMgr) {
			bossMgr->search(bossMgr);
			bossMgr->search(pelletMgr);
		}
		if (tekiMgr) {
			tekiMgr->search(tekiMgr);
			tekiMgr->search(itemMgr);
			tekiMgr->search(itemMgr->mMeltingPotMgr);
			tekiMgr->search(pelletMgr);
		}
		pelletMgr->search(pelletMgr);
		if (bossMgr) {
			bossMgr->search(itemMgr);
			bossMgr->search(itemMgr->mMeltingPotMgr);
		}
	}
}

/*
 * --INFO--
 * Address:	800E3424
 * Size:	0007EC
 */
void SearchSystem::updateLoopOptimised()
{
	for (int i = 0; i < pikiMgr->mMaxElements; i++) {
		if (pikiMgr->mEntryStatus[i]) {
			continue;
		}

		Piki* piki = (Piki*)pikiMgr->mObjectList[i];

		Iterator it(naviMgr);
		CI_LOOP(it)
		{
			Creature* obj = *it;
			if (AIPerf::useGrid) {
				f32 sizeA = obj->getCentreSize();
				f32 sizeB = piki->getCentreSize();
				if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
					continue;
				}
			}
			f32 dist = sphereDist(piki, obj);
			if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
				piki->mSearchBuffer.insert(obj, dist);
			}
			if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
				obj->mSearchBuffer.insert(piki, dist);
			}
		}

		Iterator it2(tekiMgr);
		CI_LOOP(it2)
		{
			Creature* obj = *it2;
			if (!obj->mGrid.aiCulling()) {
				if (AIPerf::useGrid) {
					f32 sizeA = obj->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
						continue;
					}
				}
				f32 dist = sphereDist(piki, obj);
				if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
					piki->mSearchBuffer.insert(obj, dist);
				}
				if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
					obj->mSearchBuffer.insert(piki, dist);
				}
			}
		}

		Iterator it3(bossMgr);
		CI_LOOP(it3)
		{
			Creature* obj = *it3;
			if (!obj->mGrid.aiCulling()) {
				if (AIPerf::useGrid) {
					f32 sizeA = obj->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
						continue;
					}
				}
				f32 dist = sphereDist(piki, obj);
				if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
					piki->mSearchBuffer.insert(obj, dist);
				}
				if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
					obj->mSearchBuffer.insert(piki, dist);
				}
			}
		}

		Iterator it4(itemMgr);
		CI_LOOP(it4)
		{
			Creature* obj = *it4;
			if (!obj->mGrid.aiCulling()) {
				if (AIPerf::useGrid) {
					f32 sizeA = obj->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(obj->mGrid, sizeB + sizeA)) {
						continue;
					}
				}
				f32 dist = sphereDist(piki, obj);
				if (dist <= 300.0f && piki->mSearchBuffer.mDataList) {
					piki->mSearchBuffer.insert(obj, dist);
				}
				if (dist <= 300.0f && obj->mSearchBuffer.mDataList) {
					obj->mSearchBuffer.insert(piki, dist);
				}
			}
		}

		for (int j = i + 1; j < pikiMgr->mMaxElements; j++) {
			if (!pikiMgr->mEntryStatus[j]) {
				Piki* piki2 = (Piki*)pikiMgr->mObjectList[j];
				if ((AIPerf::pikiMabiki || AIPerf::useUpdateMgr) && !piki->mSearchContext.updatable()
				    && !piki2->mSearchContext.updatable()) {
					continue;
				}

				if (AIPerf::useGrid) {
					f32 sizeA = piki2->getCentreSize();
					f32 sizeB = piki->getCentreSize();
					if (piki->mGrid.doCulling(piki2->mGrid, sizeB + sizeA)) {
						continue;
					}
				}
				f32 dist = sphereDist(piki, piki2);
				if (dist <= 300.0f) {
					if (piki->mSearchBuffer.mDataList) {
						piki->mSearchBuffer.insert(piki2, dist);
					}
					if (piki2->mSearchBuffer.mDataList) {
						piki2->mSearchBuffer.insert(piki, dist);
					}
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E3C10
 * Size:	000070
 */
SearchBuffer::SearchBuffer()
{
	mMaxEntries     = 0;
	_20             = 0;
	mCurrentEntries = 0;
	mDataList       = nullptr;
	invalidate();
	_24 = 0;
}

/*
 * --INFO--
 * Address:	800E3C80
 * Size:	0001D8
 */
void SearchBuffer::init(SearchData* data, int p2)
{
	mMaxEntries = p2;
	mDataList   = data;
	for (int i = 0; i < p2; i++) {
		mDataList[i].mSearchIteration = 0;
		if (!mDataList[i].mTargetCreature.isNull()) {
			PRINT(" %x(%d) : [%d] = %x\n", data, p2, i, mDataList[i].mTargetCreature.getPtr());
		}
		mDataList[i].mTargetCreature.clear();
		mDataList[i].mDistance = 12800.0f;
	}
	mCurrentEntries = 0;
	_10             = 0;
	invalidate();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void SearchBuffer::operator=(SearchBuffer& other)
{
	mMaxEntries     = other.mMaxEntries;
	_20             = other._20;
	mCurrentEntries = other.mCurrentEntries;
	_10             = other._10;
	for (int i = 0; i < mMaxEntries; i++) {
		mDataList[i].mSearchIteration = other.mDataList[i].mSearchIteration;
		mDataList[i].mTargetCreature  = other.mDataList[i].mTargetCreature;
		mDataList[i].mDistance        = other.mDataList[i].mDistance;
	}
	invalidate();
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int SearchBuffer::getIndex(Creature* obj)
{
	for (int i = 0; i < mCurrentEntries; i++) {
		if (mDataList[i].mTargetCreature.getPtr() == obj) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800E3E58
 * Size:	00003C
 */
void SearchBuffer::clear()
{
	for (int i = 0; i < mCurrentEntries; i++) {
		mDataList[i].mTargetCreature.clear();
	}
	mCurrentEntries = 0;
	_1C             = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SearchBuffer::reset()
{
	if (mMaxEntries > 0) {
		mDataList[mMaxEntries - 1].mDistance = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	800E3E94
 * Size:	000060
 */
void SearchBuffer::invalidate()
{
	if (!AIPerf::insQuick) {
		return;
	}

	clear();
	mMaxDistance    = -100.0f;
	mLastEntry      = -1;
	mCurrentEntries = 0;
	_1C             = 0;
}

/*
 * --INFO--
 * Address:	800E3EF4
 * Size:	0001E8
 */
void SearchBuffer::insertQuick(Creature* obj, f32 dist)
{
	if (!obj->isVisible() || !obj->isAlive()) {
		return;
	}
	if ((mCurrentEntries < mMaxEntries || !(mMaxDistance < dist)) && getIndex(obj) == -1) {

		if (mCurrentEntries >= mMaxEntries) {
			if (mLastEntry == -1) {
				return;
			}
			mDataList[mLastEntry].mTargetCreature.getPtr();
			mDataList[mLastEntry].mTargetCreature.reset();
			mDataList[mLastEntry].mTargetCreature.set(obj);
			mMaxDistance = dist;
			return;
		}

		mDataList[mCurrentEntries].mTargetCreature.getPtr();
		mDataList[mCurrentEntries].mTargetCreature.reset();
		mDataList[mCurrentEntries].mTargetCreature.set(obj);
		if (mMaxDistance < dist) {
			mMaxDistance = dist;
			mLastEntry   = mCurrentEntries;
		}
		mCurrentEntries++;
	}

	f32 badcompiler[8];
}

/*
 * --INFO--
 * Address:	800E40DC
 * Size:	000204
 */
void SearchBuffer::insert(Creature* creature, f32 distance)
{
	if (AIPerf::insQuick) {
		insertQuick(creature, distance);
		return;
	}

	if (!creature->isVisible()) {
		return;
	}

	int index = getIndex(creature);
	if (index == -1) {
		int i = mCurrentEntries - 1;
		for (i; i >= 0; i--) {
			if (mDataList[i].mDistance > distance) {
				if (i + 1 < mMaxEntries) {
					mDataList[i + 1].mTargetCreature  = mDataList[i].mTargetCreature;
					mDataList[i + 1].mDistance        = mDataList[i].mDistance;
					mDataList[i + 1].mSearchIteration = mDataList[i].mSearchIteration;
				} else {
					mDataList[mMaxEntries - 1].mTargetCreature.reset();
				}
			} else {
				break;
			}
		}
		if (i + 1 < mMaxEntries) {
			mDataList[i + 1].mTargetCreature.set(creature);
			mDataList[i + 1].mSearchIteration = -1;
			mDataList[i + 1].mDistance        = distance;
			mCurrentEntries++;
			if (mCurrentEntries >= mMaxEntries) {
				mCurrentEntries = mMaxEntries;
			}
		}
	} else {
		if (mDataList[index].mSearchIteration > 0) {
			mDataList[index].mSearchIteration = 0;
		}
		mDataList[index].mDistance = distance;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 * Note:	Size isnt exact, but close enough for a stripped function
 */
void SearchBuffer::update()
{
	for (int i = 0; i < mCurrentEntries; i++) {
		int frameSinceLastSeen = mDataList[i].mSearchIteration;

		mDataList[i].mSearchIteration++;
		if (frameSinceLastSeen < 6) {
			if (mDataList[i].mTargetCreature.getPtr()->isAlive()) {
				continue;
			}
			continue;
		}

		// Timeout after 6 frames of not seeing the creature
		mDataList[i].mTargetCreature.getPtr();
		mDataList[i].mTargetCreature.reset();

		int offs = i;
		for (int j = offs + 1; j < mCurrentEntries; j++) {
			mDataList[offs].mDistance        = mDataList[j].mDistance;
			mDataList[offs].mTargetCreature  = mDataList[j].mTargetCreature;
			mDataList[offs].mSearchIteration = mDataList[j].mSearchIteration;
			offs                             = j;
		}

		mCurrentEntries--;
	}
}

/*
 * --INFO--
 * Address:	800E42E0
 * Size:	00002C
 */
Creature* SearchBuffer::getCreature(int id)
{
	if (id < 0 || id >= mCurrentEntries) {
		return nullptr;
	}
	return mDataList[id].mTargetCreature.getPtr();
}

/*
 * --INFO--
 * Address:	800E430C
 * Size:	000008
 */
int SearchBuffer::getFirst()
{
	return 0;
}

/*
 * --INFO--
 * Address:	800E4314
 * Size:	000008
 */
int SearchBuffer::getNext(int i)
{
	return i + 1;
}

/*
 * --INFO--
 * Address:	800E431C
 * Size:	00001C
 */
bool SearchBuffer::isDone(int i)
{
	if (i >= mCurrentEntries) {
		return true;
	}
	return false;
}
