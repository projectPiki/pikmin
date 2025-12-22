#include "UpdateMgr.h"
#include "DebugLog.h"
#include "sysNew.h"

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
DEFINE_ERROR(5)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("updateMgr");

UpdateContext::UpdateContext()
{
	mMgr          = nullptr;
	mMgrSlotIndex = -1;
}

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

void UpdateContext::init(UpdateMgr* mgr)
{
	mMgr = mgr;
	mgr->addClient(this);
}

void UpdateContext::exit()
{
	if (mMgr) {
		mMgr->removeClient(this);
		mMgr = nullptr;
	}
	mIsPiki = false;
}

UpdateMgr::UpdateMgr()
{
	mClientSlotList       = nullptr;
	mActiveClientSlotList = nullptr;
	mSlotCount            = 0;
	mClientCount          = 0;
	mCurrentIndex         = 0;
}

void UpdateMgr::update()
{
	if (++mCurrentIndex >= mSlotCount) {
		mCurrentIndex = 0;
	}
}

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
