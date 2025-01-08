#ifndef _PIKIINF_H
#define _PIKIINF_H

#include "types.h"
#include "CoreNode.h"
#include "ObjType.h"
#include "Vector.h"

struct Creature;
struct CreatureInf;
struct Piki;
struct RandomAccessStream;

typedef CreatureInf* (*InfFuncType1)(Creature*); // rename later to something sensible
typedef Creature* (*InfFuncType2)(CreatureInf*); // rename later to something sensible

/**
 * @brief TODO
 */
struct BaseInf : public CoreNode {
	BaseInf(); // unused/inlined

	virtual void doStore(Creature*) { }         // _10
	virtual void doRestore(Creature*) { }       // _14
	virtual void saveCard(RandomAccessStream&); // _18
	virtual void loadCard(RandomAccessStream&); // _1C

	void store(Creature*);
	void restore(Creature*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	Vector3f mPosition; // _14
	Vector3f mRotation; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct BPikiInf : public BaseInf {
	BPikiInf(); // unused/inlined

	virtual void doStore(Creature*);            // _10
	virtual void doRestore(Creature*);          // _14
	virtual void saveCard(RandomAccessStream&); // _18
	virtual void loadCard(RandomAccessStream&); // _1C

	// _00     = VTBL
	// _00-_2C = BaseInf
	u8 _2C; // _2C
	u8 _2D; // _2D
};

/**
 * @brief TODO
 *
 * @note Size: 0x4C.
 */
struct CreatureInf : public BaseInf {
	CreatureInf(); // unused/inlined

	virtual void doStore(Creature*);   // _10
	virtual void doRestore(Creature*); // _14

	// _00     = VTBL
	// _00-_2C = BaseInf
	EObjType mObjType; // _2C
	int mCurrentDay;   // _30, or something related to it, maybe last seen day etc
	int _34;           // _34
	int _38;           // _38
	int mTekiType;     // _3C
	int _40;           // _40
	f32 _44;           // _44
	f32 _48;           // _48
};

/**
 * @brief TODO
 */
struct InfMgr {
	virtual void init(int) { }         // _08
	virtual BaseInf* getFreeInf() = 0; // _0C
	virtual void delInf(BaseInf*) = 0; // _10
	virtual int getFreeNum()      = 0; // _14
	virtual int getActiveNum()    = 0; // _18

	// _00 = VTBL
};

/**
 * @brief TODO
 *
 * @note Size: 0x64.
 */
struct MonoInfMgr : public InfMgr {
	MonoInfMgr();

	virtual void init(int);        // _08
	virtual BaseInf* getFreeInf(); // _0C
	virtual void delInf(BaseInf*); // _10
	virtual int getFreeNum();      // _14
	virtual int getActiveNum();    // _18
	virtual BaseInf* newInf() = 0; // _1C

	void loadCard(RandomAccessStream&);

	// unused/inlined:
	void saveCard(RandomAccessStream&);

	inline void clearActiveList()
	{
		BaseInf* next;
		BaseInf* inf;

		inf = static_cast<BaseInf*>(mActiveList.mChild);
		while (inf) {
			next = static_cast<BaseInf*>(inf->mNext);
			inf->del();
			mFreeList.add(inf);
			inf = next;
		}
	}

	// _00     = VTBL
	// _00-_04 = InfMgr
	int mInfCount;       // _04
	BaseInf** mInfs;     // _08
	BaseInf mActiveList; // _0C
	BaseInf mFreeList;   // _38
};

/**
 * @brief TODO
 *
 * @note Size: 0x64.
 */
struct BPikiInfMgr : public MonoInfMgr {
	virtual BPikiInf* newInf(); // _1C

	int getPikiCount(int color);

	// unused/inlined:
	void initGame();

	// _00     = VTBL
	// _00-_64 = MonoInfMgr
};

/**
 * @brief TODO
 */
struct CreatureInfMgr : public MonoInfMgr {
	virtual CreatureInf* newInf(); // _1C

	// unused/inlined:
	void beginRegister(int);
	void registerType(int, InfFuncType1, InfFuncType2);
	void endRegister();
	void getStoreFun(int);
	void getRestoreFun(int);
	void updateUseList();
	void restoreAll();

	// _00     = VTBL
	// _00-_64 = MonoInfMgr
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct PikiInfMgr {
	PikiInfMgr(); // unused/inlined

	void initGame();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	void incPiki(Piki*);
	void incPiki(int, int);
	void decPiki(Piki*);
	void clear();

	// unused/inlined:
	void getTotal();

	// TODO: members
	int mPikiCounts[3][3]; // _00, indexed by color and happa maybe?
};

/**
 * @brief TODO
 *
 * @note Size: 0x64.
 */
struct StageInf {
	void init();
	void initGame();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);

	BPikiInfMgr mBPikiInfMgr; // _00
};

extern PikiInfMgr pikiInfMgr;

#endif
