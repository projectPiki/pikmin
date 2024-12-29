#ifndef _UPDATEMGR_H
#define _UPDATEMGR_H

#include "types.h"

struct Graphics;
struct UpdateMgr;

/**
 * @brief TODO
 */
struct UpdateContext {
	UpdateContext();

	bool updatable();
	void init(UpdateMgr*);
	void exit();

	inline bool isActive() { return mIsActive; }

	UpdateMgr* mMgr;   // _00
	int mMgrSlotIndex; // _04, what slot is client in in mMgr?
	bool mIsActive;    // _08
};

/**
 * @brief TODO
 */
struct UpdateMgr {
	UpdateMgr();

	void update();
	bool updatable(UpdateContext*);
	void create(int);
	void addClient(UpdateContext*);
	void removeClient(UpdateContext*);

	// unused/inlined:
	void balanceClient(UpdateContext*);
	void showInfo(Graphics&, int, int);

	int mSlotCount;             // _00, max possible client slots
	int mClientCount;           // _04, current client count
	int* mClientSlotList;       // _08, each slot holds up to 10000 clients
	int* mActiveClientSlotList; // _0C, each slot holds up to 10000 clients
	int mCurrentIndex;          // _10
	u32 mUnused14;              // _14, just gets zeroed by create
};

extern UpdateMgr* pikiUpdateMgr;
extern UpdateMgr* searchUpdateMgr;
extern UpdateMgr* pikiLookUpdateMgr;
extern UpdateMgr* pikiOptUpdateMgr;
extern UpdateMgr* tekiOptUpdateMgr;

#endif
