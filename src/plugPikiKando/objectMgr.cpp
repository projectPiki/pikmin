#include "ObjectMgr.h"
#include "AIPerf.h"
#include "Creature.h"
#include "CreatureNode.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(13)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("objectMgr");
/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void boundSphereDist(Creature*, Creature*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::stickUpdate()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		(*iter)->stickUpdate();
	}
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::invalidateSearch()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		Creature* c = *iter;
		if (c->mSearchContext.updatable()) {
			c->mSearchBuffer.invalidate();
		}
	}
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::update()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		(*iter)->update();
	}
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::store()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ObjectMgr::restore()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::killAll()
{
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (obj->isAlive()) {
			obj->kill(true);
			obj->exitCourse();
			it.dec();
		}
	}

	// Doing it once wasnt good enough so we do it all again
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (obj->isAlive()) {
			obj->kill(true);
			obj->exitCourse();
			ERROR("xamasita");
			it.dec();
		}
	}
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::postUpdate(int unused, f32 deltaTime)
{
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		obj->postUpdate(unused, deltaTime);
		if (!AIPerf::insQuick && !AIPerf::updateSearchBuffer) {
			if (obj->mSearchBuffer.available()) {
				obj->mSearchBuffer.clear();
			}
		}
	}
}

void ObjectMgr::refresh(Graphics& gfx)
{
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		obj->refresh(gfx);
	}
}

Creature* ObjectMgr::findClosest(immut Vector3f& pos, immut Condition* cond)
{
	Creature* ret = nullptr;
	f32 maxDist   = 12800.0f;
	FastGrid grid;
	grid.updateGrid(pos);
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (!AIPerf::iteratorCull || !obj->mGrid.doCulling(grid, maxDist)) {
			if (!cond || cond->satisfy(obj)) {
				Vector3f diff = obj->getCentre() - pos;
				f32 len       = diff.length();
				if (len < maxDist) {
					maxDist = len;
					ret     = obj;
				}
			}
		}
	}
	return ret;
}

/**
 * @TODO: Documentation
 */
Creature* ObjectMgr::findClosest(immut Vector3f& pos, f32 maxLen, immut Condition* cond)
{
	Creature* ret = nullptr;
	f32 maxDist   = 12800.0f;
	FastGrid grid;
	grid.updateGrid(pos);
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (!AIPerf::iteratorCull || !obj->mGrid.doCulling(grid, maxDist)) {
			if (!cond || cond->satisfy(obj)) {
				Vector3f diff = obj->getCentre() - pos;
				f32 len       = diff.length();
				if (len <= maxLen && len < maxDist) {
					maxDist = len;
					ret     = obj;
				}
			}
		}
	}
	return ret;
}

/**
 * @TODO: Documentation
 */
void ObjectMgr::drawShadow(Graphics& gfx, Texture* tex)
{
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		if (obj->aiCullable())
			obj->drawShadow(gfx);
	}
}

/**
 * @TODO: Documentation
 */
MonoObjectMgr::MonoObjectMgr()
{
	mObjectList  = nullptr;
	mMaxElements = 0;
	mNumObjects  = 0;
	_38          = 0;
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::create(int num)
{
	mMaxElements = num;
	mObjectList  = new Creature*[mMaxElements];
	mEntryStatus = new int[mMaxElements];

	for (int i = 0; i < mMaxElements; i++) {
		mObjectList[i]  = createObject();
		mEntryStatus[i] = -1;
	}
	mNumObjects = 0;
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::postUpdate(int unused, f32 deltaTime)
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			Creature* obj = mObjectList[i];
			obj->postUpdate(unused, deltaTime);
			if (!AIPerf::insQuick && !AIPerf::updateSearchBuffer) {
				if (obj->mSearchBuffer.available()) {
					obj->mSearchBuffer.clear();
				}
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::drawShadow(Graphics& gfx, Texture*)
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			Creature* obj = mObjectList[i];
			if (obj->aiCullable())
				obj->drawShadow(gfx);
		}
	}

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::refresh(Graphics& gfx)
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			Creature* obj = mObjectList[i];
			obj->refresh(gfx);
		}
	}
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::update()
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			mObjectList[i]->update();
		}

		if (mEntryStatus[i] == -2 && mObjectList[i]->getCnt() == 0) {
			kill(mObjectList[i]);
			mEntryStatus[i] = -1;
		} else if (mEntryStatus[i] == -2) {
			PRINT(" objetcts[%d] : %s cannot die ! %d cnt\n", i, ObjType::getName(mObjectList[i]->mObjType), mObjectList[i]->getCnt());
			mObjectList[i]->clearCnt();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int MonoObjectMgr::getEmptyIndex()
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == -1) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int MonoObjectMgr::getIndex(Creature* obj)
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mObjectList[i] == obj) {
			return i;
		}
	}
	return -1;
}

/**
 * @TODO: Documentation
 */
Creature* MonoObjectMgr::birth()
{
	if (mNumObjects >= mMaxElements) {
		PRINT("numObjects(%d) exceeds maxObjects(%d)\n", mNumObjects, mMaxElements);
		for (int i = 0; i < mMaxElements; i++) {
			if (mEntryStatus[i] == -2) {
				PRINT("*** (%d) WANT TO DIE : %s (%d refs)\n", mObjectList[i]->removable() ? "removable" : "not removable",
				      mObjectList[i]->getCnt());
			}
		}
		return nullptr;
	}

	int id = getEmptyIndex();
	if (id == -1) {
		PRINT("no empty slot !\n");
		return nullptr;
	}

	mEntryStatus[id] = 0;
	mNumObjects++;
	return mObjectList[id];
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::kill(Creature* obj)
{
	int id = getIndex(obj);
	if (id != -1) {
		if (!obj->removable()) {
			mEntryStatus[id] = -2;
		} else {
			mNumObjects--;
			mEntryStatus[id] = -1;
		}
	}
}

/**
 * @TODO: Documentation
 */
Creature* MonoObjectMgr::getCreature(int id)
{
	if (id < 0 || id >= mMaxElements || mEntryStatus[id] != 0) {
		return nullptr;
	}
	return mObjectList[id];
}

/**
 * @TODO: Documentation
 */
int MonoObjectMgr::getFirst()
{
	int ret = -1;
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			ret = i;
			break;
		}
	}
	if (ret == -1) {
		return mMaxElements;
	}
	return ret;
}

/**
 * @TODO: Documentation
 */
int MonoObjectMgr::getNext(int id)
{
	int ret = -1;
	for (int i = id + 1; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			ret = i;
			break;
		}
	}
	if (ret == -1) {
		return mMaxElements;
	}
	return ret;
}

/**
 * @TODO: Documentation
 */
bool MonoObjectMgr::isDone(int index)
{
	if (index >= mMaxElements) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::search(ObjectMgr* mgr)
{
	if (mgr == this) {
		searchSelf();
		return;
	}

	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] != 0) {
			continue;
		}

		Creature* obj = mObjectList[i];
		if (AIPerf::insQuick && !obj->mSearchContext.updatable()) {
			continue;
		}

		bool isPlayer = false;
		if (obj->mObjType == OBJTYPE_Piki || obj->mObjType == OBJTYPE_Navi) {
			isPlayer = true;
		}
		if (!isPlayer && obj->mGrid.aiCulling() && !obj->aiCullable()) {
			continue;
		}

		Iterator it(mgr);
		CI_LOOP(it)
		{
			Creature* obj2 = *it;
			if (AIPerf::useUpdateMgr) {
				if (!obj->mSearchContext.updatable() && !obj2->mSearchContext.updatable()) {
					continue;
				}
			}

			bool isPlayer = false;
			if (obj2->mObjType == OBJTYPE_Piki || obj2->mObjType == OBJTYPE_Navi) {
				isPlayer = true;
			}
			if (!isPlayer && obj2->mGrid.aiCulling() && !obj2->aiCullable()) {
				continue;
			}
			if (AIPerf::useGrid) {
				if (obj->mGrid.doCulling(obj2->mGrid, obj->getBoundingSphereRadius() + obj2->getBoundingSphereRadius())) {
					continue;
				}
			}
			f32 dist = centreDist(obj, obj2);
			f32 s2   = obj->getBoundingSphereRadius() + obj2->getBoundingSphereRadius();
			dist     = dist - s2;

			if (dist <= 300.0f && obj->isAlive() && obj->mSearchBuffer.available()) {
				if (!AIPerf::useUpdateMgr || obj->mSearchContext.updatable()) {
					obj->mSearchBuffer.insert(obj2, dist);
				}
			}
			if (dist <= 300.0f && obj2->isAlive() && obj2->mSearchBuffer.available()) {
				if (!AIPerf::useUpdateMgr || obj2->mSearchContext.updatable()) {
					obj2->mSearchBuffer.insert(obj, dist);
				}
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void MonoObjectMgr::searchSelf()
{
	bool mabiki = false;
	for (int i = 0; i < mMaxElements - 1; i++) {
		if (mEntryStatus[i] != 0) {
			continue;
		}

		Creature* obj = mObjectList[i];

		bool isPlayer = false;
		if (obj->mObjType == OBJTYPE_Piki || obj->mObjType == OBJTYPE_Navi) {
			isPlayer = true;
			if (AIPerf::pikiMabiki && obj->mObjType == OBJTYPE_Piki) {
				mabiki = true;
			}
		}
		if (!isPlayer && obj->mGrid.aiCulling() && !obj->aiCullable()) {
			continue;
		}

		for (int j = i + 1; j < mMaxElements; j++) {
			if (mEntryStatus[j] != 0) {
				continue;
			}
			Creature* obj2 = mObjectList[j];

			if (mabiki || AIPerf::useUpdateMgr) {
				if (!obj->mSearchContext.updatable() && !obj2->mSearchContext.updatable()) {
					continue;
				}
			}

			bool isPlayer = false;
			if (obj2->mObjType == OBJTYPE_Piki || obj2->mObjType == OBJTYPE_Navi) {
				isPlayer = true;
			}
			if (!isPlayer && obj2->mGrid.aiCulling() && !obj2->aiCullable()) {
				continue;
			}
			if (AIPerf::useGrid) {
				if (obj->mGrid.doCulling(obj2->mGrid, obj->getBoundingSphereRadius() + obj2->getBoundingSphereRadius())) {
					continue;
				}
			}
			f32 dist1 = centreDist(obj, obj2);
			f32 s1    = obj2->getBoundingSphereRadius();
			f32 s2    = obj->getBoundingSphereRadius();
			s1        = s2 + s1;
			f32 dist  = dist1 - s1;

			if (dist <= 300.0f && obj->isAlive()) {
				if (obj->isAlive() && obj->mSearchBuffer.available()) {
					if ((!AIPerf::useUpdateMgr && !mabiki) || obj->mSearchContext.updatable()) {
						obj->mSearchBuffer.insert(obj2, dist);
					}
				}
				if (obj2->isAlive() && obj2->mSearchBuffer.available()) {
					if ((!AIPerf::useUpdateMgr && !mabiki) || obj2->mSearchContext.updatable()) {
						obj2->mSearchBuffer.insert(obj, dist);
					}
				}
			}
		}
	}

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
PolyObjectMgr::PolyObjectMgr(int num)
{
	mObjectPool     = 0;
	mEntryCount     = 0;
	mMaxClassLength = num;
	mEntries        = new PolyData[num];

	for (int i = 0; i < num; i++) {
		mEntries[i].mClassObj  = 0;
		mEntries[i].mClassSize = 0;
		mEntries[i].mClassId   = -1;
	}
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::create(int num)
{
	mActiveObjects = 0;
	mPoolCapacity  = num;
	mObjectIndices = new int[mPoolCapacity];
	for (int i = 0; i < mPoolCapacity; i++) {
		mObjectIndices[i] = -1;
	}
	mMaxSize = 0;
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::update()
{
	for (int i = 0; i < mPoolCapacity; i++) {

		if (mObjectIndices[i] >= 0) {
			Creature* obj = get(i);
			if (obj) {
				obj->update();
			}
		}

		if (mObjectIndices[i] == -2 && get(i)->removable()) {
			PRINT_KANDO("killing ... %x\n", get(i));
			kill(get(i));
		} else if (mObjectIndices[i] == -2) {
			get(i)->clearCnt();
		}
	}
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::postUpdate(int unused, f32 deltaTime)
{
	for (int i = 0; i < mPoolCapacity; i++) {
		if (mObjectIndices[i] >= 0) {
			Creature* obj = get(i);
			if (obj) {
				obj->postUpdate(unused, deltaTime);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::refresh(Graphics& gfx)
{
	for (int i = 0; i < mPoolCapacity; i++) {
		if (mObjectIndices[i] >= 0) {
			Creature* obj = get(i);
			if (obj) {
				obj->refresh(gfx);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::drawShadow(Graphics& gfx, Texture*)
{
	for (int i = 0; i < mPoolCapacity; i++) {
		if (mObjectIndices[i] >= 0) {
			Creature* obj = get(i);
			if (obj && obj->aiCullable()) {
				obj->drawShadow(gfx);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::beginRegister()
{
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::registerClass(int id, Creature* obj, int size)
{
	for (int i = 0; i < mMaxClassLength; i++) {
		if (id == mEntries[i].mClassId) {
			PRINT("registerClass::id %d duplicates\n", id);
			ERROR("hello mck\n");
			return;
		}
	}

	if (mMaxSize < size) {
		mMaxSize = size;
	}

	mEntries[mEntryCount].mClassObj  = obj;
	mEntries[mEntryCount].mClassSize = size;
	mEntries[mEntryCount].mClassId   = id;
	mEntryCount++;
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::endRegister()
{
	mObjectPool = new u8[mPoolCapacity * mMaxSize];
	for (int i = 0; i < mPoolCapacity * mMaxSize; i++) {
		mObjectPool[i] = -1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int PolyObjectMgr::getEmptyIndex()
{
	for (int i = 0; i < mPoolCapacity; i++) {
		if (mObjectIndices[i] == -1) {
			return i;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
int PolyObjectMgr::getIndex(Creature* obj)
{
	int ret = -1;
	for (int i = 0; i < mPoolCapacity; i++) {
		if (get(i) == obj) {
			ret = i;
			break;
		}
	}
	return ret;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
int PolyObjectMgr::getTemplateIndex(int id)
{
	for (int i = 0; i < mMaxClassLength; i++) {
		if (mEntries[i].mClassId == id) {
			return i;
		}
	}
	return -1;
}

/**
 * @TODO: Documentation
 */
Creature* PolyObjectMgr::get(int i)
{
	return (Creature*)((int)mObjectPool + mMaxSize * i);
}

/**
 * @TODO: Documentation
 */
Creature* PolyObjectMgr::birth(int id)
{
	if (mActiveObjects >= mPoolCapacity) {
		return nullptr;
	}

	int templateId = getTemplateIndex(id);
	if (templateId == -1) {
		PRINT("<PolyObjectMgr::birth> id %d is invalid\n", id);
		return nullptr;
	}

	int emptyId = getEmptyIndex();
	if (emptyId == -1) {
		PRINT("<PolyObjectMgr> failed to give birth new object\n");
		return nullptr;
	}

	u8 *templateData, *newObject;
	PolyData* newTemplate = &mEntries[templateId];

	newObject               = (u8*)get(emptyId);
	mObjectIndices[emptyId] = id;
	templateData            = (u8*)newTemplate->mClassObj;
	for (int i = 0; i < newTemplate->mClassSize; i++) {
		newObject[i] = templateData[i];
	}

	mActiveObjects++;

	return (Creature*)newObject;
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::kill(Creature* obj)
{
	int id = getIndex(obj);
	if (obj->removable()) {
		PRINT_KANDO("%x really dead (index %d) \n", obj, id);
		mObjectIndices[id] = -1;
		mActiveObjects--;
	} else {
		mObjectIndices[id] = -2;
	}
}

/**
 * @TODO: Documentation
 */
Creature* PolyObjectMgr::getCreature(int id)
{
	if (id < 0 || id >= mPoolCapacity || mObjectIndices[id] < 0) {
		return nullptr;
	}
	return get(id);
}

/**
 * @TODO: Documentation
 */
int PolyObjectMgr::getFirst()
{
	int next = -1;
	for (int i = 0; i < mPoolCapacity; i++) {
		int candidate = mObjectIndices[i];
		if (mObjectIndices[i] >= 0) {
			next = i;
			break;
		}
	}
	if (next == -1) {
		return mPoolCapacity;
	}
	return next;
}

/**
 * @TODO: Documentation
 */
int PolyObjectMgr::getNext(int idx)
{
	int next = -1;
	for (int i = idx + 1; i < mPoolCapacity; i++) {
		int candidate = mObjectIndices[i];
		if (mObjectIndices[i] >= 0) {
			next = i;
			break;
		}
	}
	if (next == -1) {
		return mPoolCapacity;
	}
	return next;
}

/**
 * @TODO: Documentation
 */
bool PolyObjectMgr::isDone(int idx)
{
	if (idx >= mPoolCapacity) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::search(ObjectMgr* mgr)
{
	if (mgr == this) {
		searchSelf();
	}
}

/**
 * @TODO: Documentation
 */
void PolyObjectMgr::searchSelf()
{
	for (int i = 0; i < mPoolCapacity - 1; i++) {
		if (mObjectIndices[i] < 0) {
			continue;
		}

		Creature* obj = get(i);

		bool isPlayer = false;
		if (obj->mObjType == OBJTYPE_Piki || obj->mObjType == OBJTYPE_Navi) {
			isPlayer = true;
		}
		if (!isPlayer && obj->mGrid.aiCulling() && !obj->aiCullable()) {
			continue;
		}

		for (int j = i + 1; j < mPoolCapacity; j++) {
			if (mObjectIndices[j] < 0) {
				continue;
			}
			Creature* obj2 = get(j);

			if (AIPerf::useUpdateMgr) {
				if (!obj->mSearchContext.updatable() && !obj2->mSearchContext.updatable()) {
					continue;
				}
			}

			bool isPlayer = false;
			if (obj2->mObjType == OBJTYPE_Piki || obj2->mObjType == OBJTYPE_Navi) {
				isPlayer = true;
			}
			if (!isPlayer && obj2->mGrid.aiCulling() && !obj2->aiCullable()) {
				continue;
			}
			if (AIPerf::useGrid) {
				if (obj->mGrid.doCulling(obj2->mGrid, obj->getBoundingSphereRadius() + obj2->getBoundingSphereRadius())) {
					continue;
				}
			}
			f32 dist1 = centreDist(obj, obj2);
			f32 s1    = obj2->getBoundingSphereRadius();
			f32 s2    = obj->getBoundingSphereRadius();
			s1        = s2 + s1;
			f32 dist  = dist1 - s1;

			if (dist <= 300.0f) {
				if (obj->isAlive() && obj->mSearchBuffer.available()) {
					if ((!AIPerf::useUpdateMgr) || obj->mSearchContext.updatable()) {
						obj->mSearchBuffer.insert(obj2, dist);
					}
				}
				if (obj2->isAlive() && obj2->mSearchBuffer.available()) {
					if ((!AIPerf::useUpdateMgr) || obj2->mSearchContext.updatable()) {
						obj2->mSearchBuffer.insert(obj, dist);
					}
				}
			}
		}
	}

	STACK_PAD_VAR(2);
}

/**
 * Searches for nearby objects and populates each object's search buffer with potential interaction targets.
 * Uses spatial partitioning and culling for performance optimization.
 * @param otherMgr The object manager containing potential target objects
 *
 */
void ObjectMgr::search(ObjectMgr* otherMgr)
{
	Iterator sourceIter(this);
	CI_LOOP(sourceIter)
	{
		Creature* sourceObj = *sourceIter;

		// Skip non-important objects (not Pikmin / Player) unless they have specific flags
		bool skipObj
		    = (sourceObj->mObjType != OBJTYPE_Piki && sourceObj->mObjType != OBJTYPE_Navi) && !sourceObj->isCreatureFlag(CF_AIAlwaysActive);
		if (skipObj && sourceObj->mGrid.aiCulling() && !sourceObj->aiCullable()) {
			continue;
		}

		Iterator it(otherMgr);
		CI_LOOP(it)
		{
			Creature* targetObj = *it;

			skipObj = (targetObj->mObjType != OBJTYPE_Piki && targetObj->mObjType != OBJTYPE_Navi)
			       && !targetObj->isCreatureFlag(CF_AIAlwaysActive);
			if (skipObj && targetObj->mGrid.aiCulling() && !targetObj->aiCullable()) {
				continue;
			}

			// Use spatial grid to quickly cull distant objects
			if (AIPerf::useGrid) {
				if (sourceObj->mGrid.doCulling(targetObj->mGrid,
				                               sourceObj->getBoundingSphereRadius() + targetObj->getBoundingSphereRadius())) {
					continue;
				}
			}

			// Calculate actual distance between objects (accounting for their sizes)
			f32 distance       = centreDist(sourceObj, targetObj);
			f32 combinedRadius = sourceObj->getBoundingSphereRadius() + targetObj->getBoundingSphereRadius();
			distance           = distance - combinedRadius;

			// Check if objects are within interaction range
			const f32 INTERACTION_RANGE = 300.0f;

			// Add objects to each other's search buffers if they're:
			// 1) Within interaction range
			// 2) Alive
			// 3) Have initialized data lists
			// 4) Pass update manager checks (if enabled)
			if (distance <= INTERACTION_RANGE && sourceObj->isAlive() && sourceObj->mSearchBuffer.available()) {
				// Add target to source's search buffer if conditions met
				if (!AIPerf::useUpdateMgr || sourceObj->mSearchContext.updatable()) {
					sourceObj->mSearchBuffer.insert(targetObj, distance);
				}
			}

			if (distance <= INTERACTION_RANGE && targetObj->isAlive() && targetObj->mSearchBuffer.available()) {
				// Add source to target's search buffer if conditions met
				if (!AIPerf::useUpdateMgr || targetObj->mSearchContext.updatable()) {
					targetObj->mSearchBuffer.insert(sourceObj, distance);
				}
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
Creature* CreatureNodeMgr::getCreature(int idx)
{
	CreatureNode* node = static_cast<CreatureNode*>(mRootNode.mChild);
	for (int i = 0; i < idx; i++) {
		node = static_cast<CreatureNode*>(node->mNext);
	}

	if (!node) {
		return nullptr;
	}

	return node->mCreature;
}

/**
 * @TODO: Documentation
 */
int CreatureNodeMgr::getFirst()
{
	return 0;
}

/**
 * @TODO: Documentation
 */
int CreatureNodeMgr::getNext(int idx)
{
	return idx + 1;
}

/**
 * @TODO: Documentation
 */
bool CreatureNodeMgr::isDone(int idx)
{
	if (idx >= mRootNode.getChildCount()) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
int CreatureNodeMgr::getSize()
{
	return mRootNode.getChildCount();
}
