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

/*
 * --INFO--
 * Address:	800E0228
 * Size:	00010C
 */
void ObjectMgr::stickUpdate()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		(*iter)->stickUpdate();
	}
}

/*
 * --INFO--
 * Address:	800E0334
 * Size:	000124
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

/*
 * --INFO--
 * Address:	800E0458
 * Size:	00010C
 */
void ObjectMgr::update()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		(*iter)->update();
	}
}

/*
 * --INFO--
 * Address:	800E0564
 * Size:	000004
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

/*
 * --INFO--
 * Address:	800E0568
 * Size:	000264
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

/*
 * --INFO--
 * Address:	800E07CC
 * Size:	00016C
 */
void ObjectMgr::postUpdate(int a1, f32 a2)
{
	Iterator it(this);
	CI_LOOP(it)
	{
		Creature* obj = *it;
		obj->postUpdate(a1, a2);
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

/*
 * --INFO--
 * Address:	800E0CB0
 * Size:	000274
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

/*
 * --INFO--
 * Address:	800E0F24
 * Size:	000128
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

/*
 * --INFO--
 * Address:	800E104C
 * Size:	0000A4
 */
MonoObjectMgr::MonoObjectMgr()
{
	mObjectList  = nullptr;
	mMaxElements = 0;
	mNumObjects  = 0;
	_38          = 0;
}

/*
 * --INFO--
 * Address:	800E10F0
 * Size:	0000B4
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

/*
 * --INFO--
 * Address:	800E11A4
 * Size:	0000B8
 */
void MonoObjectMgr::postUpdate(int a1, f32 a2)
{
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			Creature* obj = mObjectList[i];
			obj->postUpdate(a1, a2);
			if (!AIPerf::insQuick && !AIPerf::updateSearchBuffer) {
				if (obj->mSearchBuffer.available()) {
					obj->mSearchBuffer.clear();
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E125C
 * Size:	00009C
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

/*
 * --INFO--
 * Address:	800E12F8
 * Size:	000090
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

/*
 * --INFO--
 * Address:	800E1388
 * Size:	0000EC
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

/*
 * --INFO--
 * Address:	800E1474
 * Size:	0000AC
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

/*
 * --INFO--
 * Address:	800E1520
 * Size:	000084
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

/*
 * --INFO--
 * Address:	800E15A4
 * Size:	00003C
 */
Creature* MonoObjectMgr::getCreature(int id)
{
	if (id < 0 || id >= mMaxElements || mEntryStatus[id] != 0) {
		return nullptr;
	}
	return mObjectList[id];
}

/*
 * --INFO--
 * Address:	800E15E0
 * Size:	000058
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

/*
 * --INFO--
 * Address:	800E1638
 * Size:	00005C
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

/*
 * --INFO--
 * Address:	800E1694
 * Size:	00001C
 */
bool MonoObjectMgr::isDone(int index)
{
	if (index >= mMaxElements) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800E16B0
 * Size:	000388
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

/*
 * --INFO--
 * Address:	800E1A38
 * Size:	00030C
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

/*
 * --INFO--
 * Address:	800E1D44
 * Size:	000260
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

/*
 * --INFO--
 * Address:	800E1FA4
 * Size:	00007C
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

/*
 * --INFO--
 * Address:	800E2020
 * Size:	000108
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

/*
 * --INFO--
 * Address:	800E2128
 * Size:	0000AC
 */
void PolyObjectMgr::postUpdate(int a1, f32 a2)
{
	for (int i = 0; i < mPoolCapacity; i++) {
		if (mObjectIndices[i] >= 0) {
			Creature* obj = get(i);
			if (obj) {
				obj->postUpdate(a1, a2);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E21D4
 * Size:	00009C
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

/*
 * --INFO--
 * Address:	800E2270
 * Size:	0000A8
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

/*
 * --INFO--
 * Address:	800E2318
 * Size:	000004
 */
void PolyObjectMgr::beginRegister()
{
}

/*
 * --INFO--
 * Address:	800E231C
 * Size:	000088
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

/*
 * --INFO--
 * Address:	800E23A4
 * Size:	000068
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

/*
 * --INFO--
 * Address:	800E240C
 * Size:	000014
 */
Creature* PolyObjectMgr::get(int i)
{
	return (Creature*)((int)mObjectPool + mMaxSize * i);
}

/*
 * --INFO--
 * Address:	800E2420
 * Size:	00011C
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

/*
 * --INFO--
 * Address:	800E253C
 * Size:	000080
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

/*
 * --INFO--
 * Address:	800E25BC
 * Size:	000044
 */
Creature* PolyObjectMgr::getCreature(int id)
{
	if (id < 0 || id >= mPoolCapacity || mObjectIndices[id] < 0) {
		return nullptr;
	}
	return get(id);
}

/*
 * --INFO--
 * Address:	800E2600
 * Size:	000058
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

/*
 * --INFO--
 * Address:	800E2658
 * Size:	00005C
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

/*
 * --INFO--
 * Address:	800E26B4
 * Size:	00001C
 */
bool PolyObjectMgr::isDone(int idx)
{
	if (idx >= mPoolCapacity) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800E26D0
 * Size:	000028
 */
void PolyObjectMgr::search(ObjectMgr* mgr)
{
	if (mgr == this) {
		searchSelf();
	}
}

/*
 * --INFO--
 * Address:	800E26F8
 * Size:	0002C0
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

/*
 * --INFO--
 * Address:	800E29B8
 * Size:	000404
 *
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

/*
 * --INFO--
 * Address:	800E2DBC
 * Size:	000088
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

/*
 * --INFO--
 * Address:	800E2E44
 * Size:	000008
 */
int CreatureNodeMgr::getFirst()
{
	return 0;
}

/*
 * --INFO--
 * Address:	800E2E4C
 * Size:	000008
 */
int CreatureNodeMgr::getNext(int idx)
{
	return idx + 1;
}

/*
 * --INFO--
 * Address:	800E2E54
 * Size:	000044
 */
bool CreatureNodeMgr::isDone(int idx)
{
	if (idx >= mRootNode.getChildCount()) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800E2E98
 * Size:	000024
 */
int CreatureNodeMgr::getSize()
{
	return mRootNode.getChildCount();
}
