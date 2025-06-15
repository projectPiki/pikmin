#ifndef _GENERATOR_H
#define _GENERATOR_H

#include "types.h"
#include "Node.h"
#include "Actor.h"
#include "Parameters.h"
#include "Ayu.h"
#include "Vector.h"
#include "ID32.h"

#define GENCACHE_HEAP_SIZE (0x6C00)

struct Creature;
struct MapMgr;
struct Pellet;
struct Generator;
struct GenType;
struct GenArea;
struct GenObject;
struct GeneratorMgr;
struct AgeServer;
struct TekiPersonality;

/**
 * @brief TODO
 */
enum GenCarryOverFlags {
	GENCARRY_Unk1         = 1 << 0, // 0x1
	GENCARRY_Unk2         = 1 << 1, // 0x2
	GENCARRY_Unk3         = 1 << 2, // 0x4
	GENCARRY_SavePosition = 1 << 3, // 0x8
};

/**
 * @brief TODO
 */
struct BirthInfo {
	void set(Vector3f& pos, Vector3f& rot, Vector3f& scale, Generator* gen)
	{
		mPosition  = pos;
		mRotation  = rot;
		mScale     = scale;
		mGenerator = gen;
	}

	Vector3f mPosition;    // _00
	Vector3f mRotation;    // _0C
	Vector3f mScale;       // _18
	Generator* mGenerator; // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
template <typename T>
struct Factory {
	typedef T* (*GenFunc)();

	struct Member {
		u32 mID;              // _00
		GenFunc mGenFunction; // _04
		char* mName;          // _08
		u32 mVersion;         // _0C
	};

	Factory(int maxSpawners)
	{
		mSpawnerInfo  = new Member[maxSpawners];
		mMaxSpawners  = maxSpawners;
		mSpawnerCount = 0;
	}

	T* create(u32 id)
	{
		for (int i = 0; i < mSpawnerCount; i++) {
			if (id == mSpawnerInfo[i].mID) {
				return mSpawnerInfo[i].mGenFunction();
			}
		}
		return nullptr;
	}

	void registerMember(u32 id, GenFunc func, char* name, u32 version)
	{
		if (mSpawnerCount >= mMaxSpawners) {
			return;
		}

		mSpawnerInfo[mSpawnerCount].mID          = id;
		mSpawnerInfo[mSpawnerCount].mGenFunction = func;
		mSpawnerInfo[mSpawnerCount].mName        = name;
		mSpawnerInfo[mSpawnerCount].mVersion     = version;

		mSpawnerCount++;
	}

	u32 _getLatestVersion(u32 id)
	{
		for (int i = 0; i < mSpawnerCount; i++) {
			if (id == mSpawnerInfo[i].mID) {
				return mSpawnerInfo[i].mVersion;
			}
		}

		return id;
	}

	// DLL inlines to make:
	// bool isDone(Member*);
	// Member* first();
	// Member* next();

	int mSpawnerCount;    // _00
	int mMaxSpawners;     // _04
	Member* mSpawnerInfo; // _08, array
	u8 _0C[0x4];          // _0C, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x84.
 */
struct GeneratorCache {

	/**
	 * @brief TODO
	 */
	struct Cache : public CoreNode {
		Cache()
		{
			initCore("");
			mCourseIdx      = 0;
			mGenCount       = 0;
			mTotalCacheSize = 0;
			mHeapOffset     = 0;
		}

		Cache(u32 stageIdx)
		    : mCourseIdx(stageIdx)
		{
			initCore("");
			mGenCount       = 0;
			mTotalCacheSize = 0;
			mHeapOffset     = 0;
		}

		void saveCard(RandomAccessStream&);
		void loadCard(RandomAccessStream&);

		// unused/inlined:
		void dump();

		// _00     = VTBL
		// _00-_14 = CoreNode
		u32 mCourseIdx;         // _14
		u32 mHeapOffset;        // _18
		u32 mTotalCacheSize;    // _1C
		u32 mGenCacheSize;      // _20
		u32 mCreatureCacheSize; // _24
		u32 mUfoPartsCacheSize; // _28
		u32 mGenCount;          // _2C
		u32 mCreatureCount;     // _30
		u32 mUfoPartsCount;     // _34
	};

	GeneratorCache();

	void init(u8*, int);
	void initGame();
	void addOne(u32);
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	Cache* findCache(Cache&, u32);
	void preload(u32);
	bool hasUfoParts(u32, u32);
	void load(u32);
	void beginSave(u32);
	void endSave();
	void saveGenerator(Generator*);
	void prepareUfoParts(Cache*);
	void loadUfoParts(Cache*);
	void saveUfoParts(Pellet*);
	void saveGeneratorCreature(Generator*);
	void dump();
	void assertValid();

	Cache mAliveCacheList;    // _00, i.e. used caches
	Cache mDeadCacheList;     // _38, i.e. free caches
	u8* mCacheHeap;           // _70
	int mTotalCacheSize;      // _74, max amount of cache bytes (0x6C00 by default)
	int mUsedSize;            // _78, how many bytes of cache space have we used
	int mFreeSize;            // _7C, how many bytes of cache space are left
	u32 mCurrentSaveCacheIdx; // _80
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GeneratorList {
	GeneratorList();

	Generator* findGenerator(int);
	void createRamGenerators();
	void updateUseList();

	Generator* mGenListHead; // _00
};

/**
 * @brief TODO
 */
struct GenBase : public Parameters {
	GenBase(u32 id, char* type, char* name);

	virtual void doWrite(RandomAccessStream&) { }        // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&) { }         // _14
	virtual void update() { }                            // _18
	virtual void render(Graphics&) { }                   // _1C
	virtual u32 getLatestVersion() { return 'udef'; }    // _20

	// unused/inlined:
	void writeVersion(RandomAccessStream&);
	void write(RandomAccessStream&);
	void readVersion(RandomAccessStream&);
	void read(RandomAccessStream&);

	// _04 = VTBL
	// _00-_04 = Parameters
	u32 mID;      // _08
	u32 mVersion; // _0C
	char* mType;  // _10
	char* mName;  // _14
};

/**
 * @brief TODO
 */
struct GenObject : public GenBase {
	inline GenObject(u32 id, char* name) // probably
	    : GenBase(id, "object type", name)
	{
	}

	virtual u32 getLatestVersion();                 // _20
	virtual void updateUseList(Generator*, int) { } // _24
	virtual void init(Generator*) { }               // _28
	virtual void update(Generator*) { }             // _2C
	virtual void render(Graphics&, Generator*) { }  // _30
	virtual Creature* birth(BirthInfo&) = 0;        // _34

	// _04     = VTBL
	// _00-_18 = GenBase
};

/**
 * @brief TODO
 */
struct GenObjectActor : public GenObject {
	inline GenObjectActor()
	    : GenObject('actr', "create actor")
	{
		mActorId = nullptr;
	}

	virtual void doRead(RandomAccessStream&); // _14
	virtual Creature* birth(BirthInfo&);      // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	u32 mActorId; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct GenObjectBoss : public GenObject {
	inline GenObjectBoss()
	    : GenObject('boss', "ボスを生む") // 'generate a boss'
	{
		mBossID          = 0; // BOSS_Spider
		mItemIndex       = 0;
		mItemColour      = 0;
		mItemCount       = 0;
		mPelletConfigIdx = -1;
	}

	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void updateUseList(Generator*, int);         // _24
	virtual Creature* birth(BirthInfo&);                 // _34

	static void initialise();

	void readParameters(RandomAccessStream&);
	void writeParameters(RandomAccessStream&);

	// _04     = VTBL
	// _00-_18 = GenObject
	int mBossID;          // _18, see BossID enum in Boss.h
	int mItemIndex;       // _1C
	int mItemColour;      // _20
	int mItemCount;       // _24
	int mPelletConfigIdx; // _28
};

/**
 * @brief TODO
 */
struct GenObjectDebug : public GenObject {
	GenObjectDebug(); // unused/inlined

	virtual void doRead(RandomAccessStream&); // _14
	virtual Creature* birth(BirthInfo&);      // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> mCollision;    // _18, p00
	Parm<int> mPikiNoAttack; // _28, p01
	Parm<int> mNoCarryover;  // _38, p02
	Parm<int> mPelletDebug;  // _48, p03
};

/**
 * @brief TODO
 */
struct GenObjectItem : public GenObject {
	GenObjectItem(); // unused/inlined

	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void updateUseList(Generator*, int);         // _24
	virtual Creature* birth(BirthInfo&);                 // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> mParameterA; // _18
	Parm<int> mParameterB; // _28
	Parm<int> mParameterC; // _38
	Parm<int> mParameterD; // _48
	int mObjType;          // _58
	char mName1[32];       // _5C
	char mName2[32];       // _7C
};

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct GenObjectMapObject : public GenObject {
	GenObjectMapObject();

	virtual void doRead(RandomAccessStream&);   // _14
	virtual void render(Graphics&, Generator*); // _30
	virtual Creature* birth(BirthInfo&);        // _34

	static void initialise(MapMgr*);

	static MapMgr* mapMgr;

	// _04     = VTBL
	// _00-_18 = GenObject
	// TODO: members
	u32 _18; // _18, unknown
};

/**
 * @brief TODO
 */
struct GenObjectMapParts : public GenObject {
	inline GenObjectMapParts()
	    : GenObject('mpar', "マップパーツを生む") // 'generate map parts',
	    , _18(this, 1, 1, 1, "p00", nullptr)
	    , _28(this, 100, 100, 100, "p01", nullptr)
	    , _38(this, 0.0f, 0.0f, 0.0f, "p02", nullptr)
	    , _48(this, 2.0f, 2.0f, 2.0f, "p04", nullptr)
	    , _58(this, 60.0f, 60.0f, 60.0f, "p03", nullptr)
	{
		mPartKind       = 0;
		mShapeIndex     = 0;
		mUseStartOffset = 0;
		mStartPosition.set(0.0f, 0.0f, 0.0f);
		_84.set(0.0f, 0.0f, 0.0f);
	}

	virtual void doRead(RandomAccessStream&);   // _14
	virtual void render(Graphics&, Generator*); // _30
	virtual Creature* birth(BirthInfo&);        // _34

	static void initialise(MapMgr*);

	static MapMgr* mapMgr;

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> _18;           // _18
	Parm<int> _28;           // _28
	Parm<f32> _38;           // _38
	Parm<f32> _48;           // _48
	Parm<f32> _58;           // _58
	int _68;                 // _68
	int mPartKind;           // _6C
	int mShapeIndex;         // _70
	int mUseStartOffset;     // _74
	Vector3f mStartPosition; // _78
	Vector3f _84;            // _84
};

/**
 * @brief TODO
 */
struct GenObjectNavi : public GenObject {
	inline GenObjectNavi()
	    : GenObject('navi', "プレイヤー２を生む") // 'generate player 2'
	{
	}

	virtual void doRead(RandomAccessStream&); // _14
	virtual Creature* birth(BirthInfo&);      // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	// TODO: members
};

/**
 * @brief TODO
 */
struct GenObjectPellet : public GenObject {
	GenObjectPellet(); // unused/inlined

	virtual void doWrite(RandomAccessStream&);   // _08
	virtual void doRead(RandomAccessStream&);    // _14
	virtual void updateUseList(Generator*, int); // _24
	virtual Creature* birth(BirthInfo&);         // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	int mIndex;     // _18
	ID32 mPelletId; // _1C
};

/**
 * @brief TODO
 */
struct GenObjectPiki : public GenObject {
	inline GenObjectPiki()
	    : GenObject('piki', "create PIKI")
	    , mSpawnState(this, 0, 0, 2, "p00", nullptr)
	    , mSpawnColor(this, 0, 0, 3, "p01", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual Creature* birth(BirthInfo&);                 // _34

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> mSpawnState; // _18, p00, 0:buried, 1:free, 2:team
	Parm<int> mSpawnColor; // _2C, p01, 0-2:blue/red/yellow, 3:random
};

/**
 * @brief TODO
 */
struct GenObjectPlant : public GenObject {
	GenObjectPlant(); // unused/inlined

	virtual void doRead(RandomAccessStream&);    // _14
	virtual void updateUseList(Generator*, int); // _24
	virtual void render(Graphics&, Generator*);  // _30
	virtual Creature* birth(BirthInfo&);         // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	int mPlantType; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GenObjectTeki : public GenObject {
	GenObjectTeki();

	virtual void doWrite(RandomAccessStream&);   // _08
	virtual void doRead(RandomAccessStream&);    // _14
	virtual void updateUseList(Generator*, int); // _24
	virtual Creature* birth(BirthInfo&);         // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	TekiPersonality* mPersonality; // _18
	int mTekiType;                 // _1C
};

/**
 * @brief TODO
 */
struct GenObjectWorkObject : public GenObject {
	GenObjectWorkObject(); // unused/inlined

	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void updateUseList(Generator*, int);         // _24
	virtual Creature* birth(BirthInfo&);                 // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> mDay;               // _18
	Parm<int> mHour;              // _28
	Parm<int> _38;                // _38
	Parm<f32> _48;                // _48
	s32 mObjectType;              // _58
	int mShapeType;               // _5C
	Vector3f mHinderRockPosition; // _60, hinderrock position (or just position?)
};

/**
 * @brief TODO
 */
struct GenObjectFactory : public Factory<GenObject> {
	GenObjectFactory()
	    : Factory<GenObject>(12)
	{
	}

	// unused/inlined:
	static GenObject* getProduct(u32 id);
	static void createInstance();

	static GenObjectFactory* factory;

	// _00-_0C = Factory
};

/**
 * @brief TODO
 */
struct GenType : public GenBase {
	inline GenType(u32 id, char* name)
	    : GenBase(id, "time type", name)
	    , _18(this, 0, 0, 0, "b00", nullptr)
	    , mAdjustFaceDirection(this, 0, 0, 0, "b01", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&);   // _0C
	virtual void ramLoadParameters(RandomAccessStream&);   // _10
	virtual u32 getLatestVersion();                        // _20
	virtual void init(Generator*) { }                      // _24
	virtual void update(Generator*) { }                    // _28
	virtual void render(Graphics&, Generator*) { }         // _2C
	virtual void setBirthInfo(BirthInfo&, Generator*) = 0; // _30
	virtual int getMaxCount()                         = 0; // _34

	// _04     = VTBL
	// _00-_18 = GenBase
	Parm<int> _18;                  // _18, b00
	Parm<int> mAdjustFaceDirection; // _28, b01
};

/**
 * @brief TODO
 */
struct GenTypeAtOnce : public GenType {
	inline GenTypeAtOnce()
	    : GenType('aton', "最初から全部生む") // 'generate everything from the beginning'
	    , mMaxCount(this, 1, 0, 0, "p00", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void init(Generator*);                       // _24
	virtual void setBirthInfo(BirthInfo&, Generator*);   // _30
	virtual int getMaxCount();                           // _34

	// _04     = VTBL
	// _00-_38 = GenType
	Parm<int> mMaxCount; // _38, p00
};

/**
 * @brief TODO
 */
struct GenTypeInitRand : public GenType {
	inline GenTypeInitRand()
	    : GenType('irnd', "最初から生む（ランダム）") // 'generate from the beginning (random)'
	    , _38(this, 1, 0, 0, "p00", nullptr)
	    , mMaxCount(this, 5, 0, 0, "p01", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void init(Generator*);                       // _24
	virtual void setBirthInfo(BirthInfo&, Generator*);   // _30
	virtual int getMaxCount();                           // _34

	// _04     = VTBL
	// _00-_38 = GenType
	Parm<int> _38;       // _38
	Parm<int> mMaxCount; // _48, p01
};

/**
 * @brief TODO
 */
struct GenTypeOne : public GenType {
	inline GenTypeOne()
	    : GenType('1one', "１つだけうむ") // 'just one thing'
	    , _38(this, 0, 0, 0, "p00", nullptr)
	    , _48(this, 0, 0, 0, "p01", nullptr)
	    , _58(this, 0, 0, 0, "p02", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void init(Generator*);                       // _24
	virtual void render(Graphics&, Generator*);          // _2C
	virtual void setBirthInfo(BirthInfo&, Generator*);   // _30
	virtual int getMaxCount() { return 1; }              // _34

	// _04     = VTBL
	// _00-_38 = GenType
	Parm<int> _38; // _38, p00
	Parm<int> _48; // _48, p01
	Parm<int> _58; // _48, p02
};

/**
 * @brief TODO
 */
struct GenTypeFactory : public Factory<GenType> {
	GenTypeFactory()
	    : Factory<GenType>(6)
	{
	}

	// unused/inlined:
	static GenType* getProduct(u32 id);
	static void createInstance();

	static GenTypeFactory* factory;

	// TODO: members
};

/**
 * @brief TODO
 */
struct GenArea : public GenBase {
	inline GenArea(u32 id, char* name)
	    : GenBase(id, "area type", name)
	{
	}

	virtual void doWrite(RandomAccessStream&);     // _08
	virtual void doRead(RandomAccessStream&);      // _14
	virtual u32 getLatestVersion();                // _20
	virtual void init(Generator*) { }              // _24
	virtual void update(Generator*) { }            // _28
	virtual void render(Graphics&, Generator*) { } // _2C
	virtual Vector3f getPos(Generator*) = 0;       // _30
	virtual f32 getRadius() { return 0.0f; }       // _34

	// _04     = VTBL
	// _00-_18 = GenBase
	Vector3f _18; // _18
};

/**
 * @brief TODO
 */
struct GenAreaCircle : public GenArea {
	inline GenAreaCircle()
	    : GenArea('circ', "inside circle")
	    , mRadius(this, 50.0f, 0.0f, 0.0f, "p00", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void render(Graphics&, Generator*);          // _2C
	virtual Vector3f getPos(Generator*);                 // _30
	virtual f32 getRadius() { return mRadius(); }        // _34

	// _04     = VTBL
	// _00-_24 = GenArea
	Parm<f32> mRadius; // _24, p00
};

/**
 * @brief TODO
 */
struct GenAreaPoint : public GenArea {
	inline GenAreaPoint()
	    : GenArea('pint', "at a point")
	{
	}

	virtual void render(Graphics&, Generator*); // _2C
	virtual Vector3f getPos(Generator*);        // _30

	// _04     = VTBL
	// _00-_24 = GenArea
};

/**
 * @brief TODO
 */
struct GenAreaFactory : public Factory<GenArea> {
	GenAreaFactory()
	    : Factory<GenArea>(6)
	{
	}

	// unused/inlined:
	static GenArea* getProduct(u32 id);
	static void createInstance();

	static GenAreaFactory* factory;

	// TODO: members
};

/**
 * @brief TODO
 */
struct Generator : public Node {
	Generator();
	Generator(int);

	virtual void read(struct RandomAccessStream&); // _0C
	virtual void update();                         // _10
	virtual void render(struct Graphics&);         // _18

	bool isExpired();
	void loadCreature(RandomAccessStream&);
	void saveCreature(RandomAccessStream&);
	void init();
	void informDeath(Creature*);
	void write(RandomAccessStream&);

	// unused/inlined:
	~Generator();
	void updateUseList();

	static bool ramMode;

	void setDayLimit(int limit) { mDayLimit = limit; }
	Vector3f getPos() { return mGenPosition + mGenOffset; }

	int getRebirthDay() { return mGenType->_18(); }
	bool readFromRam() { return !mIsRamReadDisabled; }

	// this is an inline in the DLL, but I cant tell what its name is from the list
	bool doAdjustFaceDir() { return mGenType->mAdjustFaceDirection(); }

	// DLL inlines to make:
	// void changeNaviPos();
	// void setNaviPos();
	void setOffset(Vector3f& ofs) { mGenOffset = ofs; }
	void setPos(Vector3f& pos) { mGenPosition = pos; }
	// int isCarryOver();

#ifdef DEVELOP
	void genAge(AgeServer&);
	void changeArea(AgeServer&);
	void changeObject(AgeServer&);
	void changeType(AgeServer&);
#endif

	// _00     = VTBL
	// _00-_20 = Node
	GenArea* mGenArea;              // _20
	u32 mGenAreaID;                 // _24
	GenType* mGenType;              // _28
	u32 mGenTypeID;                 // _2C
	GenObject* mGenObject;          // _30
	u32 mGenObjectID;               // _34
	char mMemo[0x20];               // _38
	ID32 mGeneratorName;            // _58
	ID32 mGeneratorVersion;         // _64
	u32 _70;                        // _70
	u32 mCarryOverFlags;            // _74, see GenCarryOverFlags enum
	Generator* mPrevGenerator;      // _78, prev generator in GeneratorMgr list
	Generator* mNextGenerator;      // _7C, next generator in GeneratorMgr list
	GeneratorMgr* mMgr;             // _80
	Creature* mLatestSpawnCreature; // _84, most recently spawned creature
	int mAliveCount;                // _88
	int mLatestSpawnDay;            // _8C, most recent spawn date
	int mRespawnInterval;           // _90, number of days before respawning
	int mDayLimit;                  // _94, will stop spawning after this day
	Vector3f mGenPosition;          // _98
	Vector3f mGenOffset;            // _A4
	bool mIsRamReadDisabled;        // _B0
	int mGeneratorListIdx;          // _B4
};

/**
 * @brief TODO
 *
 * @note Size: 0x60.
 */
struct GeneratorMgr : public Node {
	GeneratorMgr();

	virtual void update();          // _10
	virtual void render(Graphics&); // _18

	void init();
	void setDayLimit(int);
	void updateUseList();
	void read(RandomAccessStream&, bool);

	// unused/inlined:
	void write(RandomAccessStream&);
	void setNaviPos();
	void changeNaviPos();

	// DLL inlines:
	void setLimitGenerator(bool val) { mIsLimitGenerator = val; }

#ifdef DEVELOP
	virtual void genAge(AgeServer&);
	void genWrite(AgeServer&);
	void addGenerator(AgeServer&);
#endif

	// _00     = VTBL
	// _00-_20 = Node
	Generator* mGenListHead;  // _20
	ID32 _24;                 // _24
	ID32 mGeneratorVersionId; // _30
	int mGenCount;            // _3C, number of generators in list
	ID32 _40;                 // _40
	Vector3f mNaviPos;        // _4C
	f32 mNaviDirection;       // _58
	bool mIsLimitGenerator;   // _5C
};

extern GeneratorCache* generatorCache;
extern GeneratorList* generatorList;
extern GeneratorMgr* generatorMgr;
extern GeneratorMgr* onceGeneratorMgr;
extern GeneratorMgr* dailyGeneratorMgr;
extern GeneratorMgr* plantGeneratorMgr;
extern GeneratorMgr* limitGeneratorMgr;

#endif
