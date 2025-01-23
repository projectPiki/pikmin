#include "UpdateMgr.h"
#include "sysNew.h"
#include "DebugLog.h"

UpdateMgr* pikiUpdateMgr;
UpdateMgr* searchUpdateMgr;
UpdateMgr* pikiLookUpdateMgr;
UpdateMgr* pikiOptUpdateMgr;
UpdateMgr* tekiOptUpdateMgr;

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
DEFINE_PRINT("updateMgr");

/*
 * --INFO--
 * Address:	800A5444
 * Size:	000014
 */
UpdateContext::UpdateContext()
{
	mMgr          = nullptr;
	mMgrSlotIndex = -1;
}

/*
 * --INFO--
 * Address:	800A5458
 * Size:	00004C
 */
bool UpdateContext::updatable()
{
	if (!mMgr) {
		return false;
	}

	if (mMgr->updatable(this)) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800A54A4
 * Size:	000030
 */
void UpdateContext::init(UpdateMgr* mgr)
{
	mMgr = mgr;
	mgr->addClient(this);
}

/*
 * --INFO--
 * Address:	800A54D4
 * Size:	00004C
 */
void UpdateContext::exit()
{
	if (mMgr) {
		mMgr->removeClient(this);
		mMgr = nullptr;
	}
	mIsPiki = false;
}

/*
 * --INFO--
 * Address:	800A5520
 * Size:	00001C
 */
UpdateMgr::UpdateMgr()
{
	mClientSlotList       = nullptr;
	mActiveClientSlotList = nullptr;
	mSlotCount            = 0;
	mClientCount          = 0;
	mCurrentIndex         = 0;
}

/*
 * --INFO--
 * Address:	800A553C
 * Size:	000024
 */
void UpdateMgr::update()
{
	if (++mCurrentIndex >= mSlotCount) {
		mCurrentIndex = 0;
	}
}

/*
 * --INFO--
 * Address:	800A5560
 * Size:	000030
 */
bool UpdateMgr::updatable(UpdateContext* client)
{
	if (!client) {
		return false;
	}

	if (client->mMgrSlotIndex == mCurrentIndex) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800A5590
 * Size:	000094
 */
void UpdateMgr::create(int slotCount)
{
	mSlotCount            = slotCount;
	mClientSlotList       = new int[slotCount];
	mActiveClientSlotList = new int[slotCount];
	mClientCount          = 0;
	mCurrentIndex         = 0;

	// zero all client slot counts
	for (int i = 0; i < mSlotCount; i++) {
		mClientSlotList[i]       = 0;
		mActiveClientSlotList[i] = 0;
	}

	// no idea what this is
	mUnused14 = 0;
}

/*
 * --INFO--
 * Address:	800A5624
 * Size:	000090
 */
void UpdateMgr::addClient(UpdateContext* client)
{
	int slotIdx       = -1;
	int slotClientNum = 10000;

	// find index of slot with lowest number of clients
	for (int i = 0; i < mSlotCount; i++) {
		if (mClientSlotList[i] < slotClientNum) {
			slotIdx       = i;
			slotClientNum = mClientSlotList[i];
		}
	}

	// no 'free' slot (all >= 10000 clients, or 0 slots)
	if (slotIdx == -1) {
		return;
	}

	// assign client to slot
	client->mMgrSlotIndex = slotIdx;
	mClientSlotList[slotIdx]++;

	// if client is active, assign to active slot as well
	if (client->mIsPiki) {
		mActiveClientSlotList[slotIdx]++;
	}

	mClientCount++;
}

/*
 * --INFO--
 * Address:	800A56B4
 * Size:	00005C
 */
void UpdateMgr::removeClient(UpdateContext* client)
{
	if (client->mMgrSlotIndex < 0 || client->mMgrSlotIndex >= mSlotCount) {
		PRINT("c->index is out of bounds [%d-%d] ; c->index = %d \n", 0, mSlotCount, client->mMgrSlotIndex);
		ERROR("mail to uja\n");
	}

	mClientSlotList[client->mMgrSlotIndex]--;
	if (client->isPiki()) {
		mActiveClientSlotList[client->mMgrSlotIndex]--;
	}

	mClientCount--;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void UpdateMgr::balanceClient(UpdateContext*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void UpdateMgr::showInfo(Graphics&, int, int)
{
	// UNUSED FUNCTION
}
