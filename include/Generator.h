#ifndef _GENERATOR_H
#define _GENERATOR_H

#include "Actor.h"
#include "ID32.h"
#include "Node.h"
#include "Parameters.h"
#include "Vector.h"
#include "types.h"

/// Maximum size of the generator cache heap, in bytes (for all stages combined).
#define GENCACHE_HEAP_SIZE (0x6C00)

struct AgeServer;
struct Creature;
struct MapMgr;
struct Pellet;
struct Generator;
struct GenType;
struct GenArea;
struct GenObject;
struct GeneratorMgr;
struct RandomAccessStream;
struct TekiPersonality;

/**
 * @brief Controls for what generators and properties of generators carry over to the next day(s).
 *
 * These are set in the .gen files themselves, per generator. For use with Generator::mCarryOverFlags.
 * Not to be confused with the GenType parameter of a similar name, since that's only for preserving face direction.
 *
 * @note GENCARRY_SaveGenerator needs to be set for any others to function.
 */
enum GenCarryOverFlags {
	GENCARRY_SaveGenerator  = 1 << 0, ///< 0x1, save generator between days (will not be added to the cache if not set).
	GENCARRY_SaveCreature   = 1 << 1, ///< 0x2, save spawned creature itself (for walls, bridges, pushable bags).
	GENCARRY_SaveSpawnCount = 1 << 2, ///< 0x4, save how many creatures are alive between days (and reset after certain number of days).
	GENCARRY_SaveProperties = 1 << 3, ///< 0x8, save class-specific info about creature (position, health) (needs `GENCARRY_SaveCreature`).
};

/**
 * @brief Context information for birthing an object via a `Generator`.
 */
struct BirthInfo {

	/**
	 * @brief Sets all variables required to birth an object.
	 *
	 * @param pos Position to birth object at.
	 * @param rot Rotation to birth object with.
	 * @param scale Scale to birth object with.
	 * @param gen Generator used to birth object.
	 */
	void set(immut Vector3f& pos, immut Vector3f& rot, immut Vector3f& scale, Generator* gen)
	{
		mPosition  = pos;
		mRotation  = rot;
		mScale     = scale;
		mGenerator = gen;
	}

	Vector3f mPosition;    ///< _00, position to birth object at.
	Vector3f mRotation;    ///< _0C, rotation to birth object with.
	Vector3f mScale;       ///< _18, scale to birth object with.
	Generator* mGenerator; ///< _24, generator used to birth object.
};

/**
 * @brief Base factory for registering and instantiating generator components (spawners).
 *
 * @tparam The generator component type to produce (`GenObject`, `GenType`, `GenArea`).
 *
 * @note Size: 0x10.
 */
template <typename T>
struct Factory {

	/// Function used to instantiate a produced component, usually a static `makeXYZ` function.
	typedef T* (*GenFunc)();

	/**
	 * @brief Information about a given spawner type.
	 *
	 * @note Size: 0x10.
	 */
	struct Member {
		u32 mID;              ///< _00, character literal (length 4) to identify the spawner type.
		GenFunc mGenFunction; ///< _04, function that should be used to instantiate the spawner.
		immut char* mName;    ///< _08, descriptive name for spawner type.
		u32 mLatestVersion;   ///< _0C, most recent (file) version of spawner type.
	};

	/**
	 * @brief Constructs and initialises a new factory along with a blank spawner array.
	 *
	 * @param maxSpawners Maximum number of spawner types to produce.
	 */
	Factory(int maxSpawners)
	{
		mSpawnerInfo  = new Member[maxSpawners];
		mMaxSpawners  = maxSpawners;
		mSpawnerCount = 0;
	}

	/**
	 * @brief Instantiates a new spawner based on ID.
	 *
	 * @param id Character literal ID of spawner to instantiate.
	 * @return Pointer to new spawner.
	 */
	T* create(u32 id)
	{
		for (int i = 0; i < mSpawnerCount; i++) {
			if (id == mSpawnerInfo[i].mID) {
				return mSpawnerInfo[i].mGenFunction();
			}
		}
		return nullptr;
	}

	/**
	 * @brief Registers a new spawner type in the member array, with all required information to instantiate spawners of that type.
	 *
	 * @param id Character literal ID of spawner type.
	 * @param func Instantiation function for that spawner type (static function, usually something like `make[TypeName]`).
	 * @param name Descriptive name of spawner type.
	 * @param latestVersion Latest (file) version of spawner type available.
	 */
	void registerMember(u32 id, GenFunc func, immut char* name, u32 latestVersion)
	{
		// trying to add more spawner types than the maximum will do nothing (and throw no error)
		if (mSpawnerCount >= mMaxSpawners) {
			return;
		}

		mSpawnerInfo[mSpawnerCount].mID            = id;
		mSpawnerInfo[mSpawnerCount].mGenFunction   = func;
		mSpawnerInfo[mSpawnerCount].mName          = name;
		mSpawnerInfo[mSpawnerCount].mLatestVersion = latestVersion;

		mSpawnerCount++;
	}

	/**
	 * @brief Gets the most recent file version of a spawner type, based on ID.
	 *
	 * @param id Character literal ID of spawner to get version of.
	 * @return Character literal indicating file version, of the form `vX.Y`.
	 */
	u32 _getLatestVersion(u32 id)
	{
		for (int i = 0; i < mSpawnerCount; i++) {
			if (id == mSpawnerInfo[i].mID) {
				return mSpawnerInfo[i].mLatestVersion;
			}
		}

		return id;
	}

	/**
	 * @brief Starts an iteration through member spawners - resets the iteration index and returns the first spawner.
	 * @return Member info for first spawner type in the array (i.e. at index 0).
	 */
	Member* first()
	{
		mIterIndex = 0;
		return next();
	}

	/**
	 * @brief Gets the next spawner member info in an iteration through member spawners and increments the interation index.
	 * @return Member info for next spawner type in the array; `nullptr` if we've hit the end.
	 */
	Member* next()
	{
		if (mIterIndex < mSpawnerCount) {
			return &mSpawnerInfo[mIterIndex++];
		}
		return nullptr;
	}

	/**
	 * @brief Checks if we've hit the end of an iteration through member infos.
	 * @param member Member info to test.
	 * @return True if we've hit the end (since next() will return `nullptr`); false if member exists.
	 */
	bool isDone(Member* member) { return !member; }

	int mSpawnerCount;    ///< _00, count of currently registered spawner infos.
	int mMaxSpawners;     ///< _04, maximum registerable spawner infos.
	Member* mSpawnerInfo; ///< _08, array of registered member spawner infos (size mMaxSpawners).
	int mIterIndex;       ///< _0C, iteration index for iterating through member info array.
};

/**
 * @brief Manages cached generator data for each story area, to spawn or respawn objects appropriately on revisit.
 *
 * @note Size: 0x84.
 */
struct GeneratorCache {

public:
	/**
	 * @brief Cache for a particular story mode stage's generator information/state.
	 */
	struct Cache : public CoreNode {

		/// Constructs a blank cache entry with no initialisation (assigned to Impact Site by default).
		Cache()
		{
			initCore("");
			mStageID         = STAGE_Practice;
			mGenCount        = 0;
			mTotalCacheSize  = 0;
			mCacheHeapOffset = 0;
		}

		/**
		 * @brief Constructs a blank cache entry with no initialisation (assigned to given stage ID).
		 * @param stageID Stage ID to assign cache to - see `StageID` enum.
		 */
		Cache(u32 stageID)
		    : mStageID(stageID)
		{
			initCore("");
			mGenCount        = 0;
			mTotalCacheSize  = 0;
			mCacheHeapOffset = 0;
		}

		void saveCard(RandomAccessStream& output);
		void loadCard(RandomAccessStream& input);

		// unused/inlined:

		void dump();

		// _00     = VTBL
		// _00-_14 = CoreNode
		u32 mStageID;           ///< _14, stage this cache is for - see `StageID` enum.
		u32 mCacheHeapOffset;   ///< _18, offset this cache starts at in the combined `mCacheHeap` in `GeneratorCache`.
		u32 mTotalCacheSize;    ///< _1C, total size of this cache, in bytes (gen size + creature size + ufo parts size).
		u32 mGenCacheSize;      ///< _20, total size of the generator information in this cache, in bytes.
		u32 mCreatureCacheSize; ///< _24, total size of the creature information in this cache, in bytes.
		u32 mUfoPartsCacheSize; ///< _28, total size of the ship parts information in this cache, in bytes.
		u32 mGenCount;          ///< _2C, total number of generators tracked by this cache, in bytes.
		u32 mCreatureCount;     ///< _30, total number of creatures tracked by this cache, in bytes.
		u32 mUfoPartsCount;     ///< _34, total number of ship parts tracked by this cache, in bytes.
	};

	GeneratorCache();

	void init(u8*, int);
	void initGame();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
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

protected:
	void addOne(u32);
	Cache* findCache(Cache&, u32);

	Cache mAliveCacheList;    ///< _00, list of all currently active/used caches.
	Cache mDeadCacheList;     ///< _38, list of all inactive/free caches.
	u8* mCacheHeap;           ///< _70, pointer to buffer to use for saving and loading caches.
	int mTotalCacheSize;      ///< _74, max amount of cache bytes (0x6C00 by default).
	int mUsedSize;            ///< _78, how many bytes of cache space are currently used.
	int mFreeSize;            ///< _7C, how many bytes of cache space are free to be used.
	u32 mCurrentSaveCacheIdx; ///< _80, index of current active cache being used for saving.
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GeneratorList {
	GeneratorList();

	Generator* findGenerator(int idx);
	void createRamGenerators();
	void updateUseList();

	Generator* mGenListHead; ///< _00, pointer to first generator in the list; also the parent of the list.
};

/**
 * @brief TODO
 */
struct GenBase : public Parameters {
	GenBase(u32 id, immut char* type, immut char* name);

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

#ifdef WIN32
	void genAge(AgeServer&) { }
#endif

	// _04 = VTBL
	// _00-_04 = Parameters
	u32 mID;           // _08
	u32 mVersion;      // _0C
	immut char* mType; // _10
	immut char* mName; // _14
};

/**
 * @brief TODO
 */
struct GenObject : public GenBase {
	GenObject(u32 id, immut char* name)
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
	GenObjectActor()
	    : GenObject('actr', "create actor")
	{
		mActorId = 0; // POLICE
	}

	virtual void doRead(RandomAccessStream&); // _14
	virtual Creature* birth(BirthInfo&);      // _34

	static void initialise();

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

	// _04     = VTBL
	// _00-_18 = GenObject
	int mActorId; // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct GenObjectBoss : public GenObject {
	GenObjectBoss()
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

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

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

#ifdef WIN32
	virtual void doGenAge(AgeServer&) { }
#endif

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

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> mParameterA; // _18
	Parm<int> mParameterB; // _28
	Parm<int> mParameterC; // _38
	Parm<int> mParameterD; // _48
	int mObjType;          // _58
	char mStageName[32];   // _5C
	char mPrintName[32];   // _7C
};

/**
 * @brief Unfinished spawner for map objects of various types. Unused.
 *
 * This only exists because it's initialised by GameCoreSection, but is never actually used to spawn any objects. Its data files are also
 * not present on disc. Some (very limited) information remains from the DLL.
 *
 * @warning Implementation not usable in its current state, as almost no map object types were finished or remained in release or DLL.
 * @note Size: 0x1C.
 */
struct GenObjectMapObject : public GenObject {

	/**
	 * @brief Map object types to spawn, exposed from DLL age server strings.
	 *
	 * None are usable, and only SeeSaw has any implementation details, assuming it uses `DynObjSeeSaw`.
	 */
	enum MapObjectType {
		TYPE_SeeSaw,
		TYPE_Log,
		TYPE_Tabaco,
		TYPE_Faller,
		TYPE_Iwa,
		TYPE_MiniSeeSaw,
		TYPE_Kinoko,
		TYPE_Lift,
	};

	GenObjectMapObject();

	virtual void doRead(RandomAccessStream& input); // _14
	virtual void render(Graphics&, Generator*);     // _30
	virtual Creature* birth(BirthInfo&);            // _34

	static void initialise(MapMgr* mgr);

#ifdef WIN32
	virtual void doWrite(RandomAccessStream& output);
	virtual void doGenAge(AgeServer& server);

	void refreshSection(AgeServer& server);
#endif

	static MapMgr* mapMgr;

	// _04     = VTBL
	// _00-_18 = GenObject
	u32 mObjType; ///< _18, object type to spawn, guessed from DLL code - see `MapObjectType` enum.
};

/**
 * @brief TODO
 */
struct GenObjectMapParts : public GenObject {
	GenObjectMapParts()
	    : GenObject('mpar', "マップパーツを生む")                // 'generate map parts',
	    , _18(this, 1, 1, 1, "p00", "稼動最低人数")              // 'min number of people required'
	    , _28(this, 100, 100, 100, "p01", "稼動最大人数")        // 'max number of people required'
	    , _38(this, 0.0f, 0.0f, 0.0f, "p02", "起動までの時間")   // 'start-up time'
	    , _48(this, 2.0f, 2.0f, 2.0f, "p04", "終点での停止時間") // 'stop time'
	    , _58(this, 60.0f, 60.0f, 60.0f, "p03", "スピード")      // 'speed'
	{
		mPartKind       = 0;
		mShapeIndex     = 0;
		mUseStartOffset = 0;
		mStartPosition.set(0.0f, 0.0f, 0.0f);
		mEndPosition.set(0.0f, 0.0f, 0.0f);
	}

	virtual void doRead(RandomAccessStream&);   // _14
	virtual void render(Graphics&, Generator*); // _30
	virtual Creature* birth(BirthInfo&);        // _34

	static void initialise(MapMgr*);

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif
	void refreshSection(AgeServer&);

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
	Vector3f mEndPosition;   // _84
};

/**
 * @brief TODO
 */
struct GenObjectNavi : public GenObject {
	GenObjectNavi()
	    : GenObject('navi', "プレイヤー２を生む") // 'generate player 2'
	{
	}

	virtual void doRead(RandomAccessStream&); // _14
	virtual Creature* birth(BirthInfo&);      // _34

	static void initialise();

#ifdef WIN32
	virtual void doGenAge(AgeServer&) { }
#endif

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

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

	// _04     = VTBL
	// _00-_18 = GenObject
	int mIndex;     // _18
	ID32 mPelletId; // _1C
};

/**
 * @brief TODO
 */
struct GenObjectPiki : public GenObject {
	GenObjectPiki()
	    : GenObject('piki', "create PIKI")
	    , mSpawnState(this, 0, 0, 2, "p00", "state (0:buried) (1:free) (2:team)")
	    , mSpawnColor(this, 0, 0, 3, "p01", "color (0-2:3 random)")
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual Creature* birth(BirthInfo&);                 // _34

	// no doGenAge here for some reason?

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

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

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

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

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

#ifdef WIN32
	virtual void doGenAge(AgeServer&);
#endif

	void changeNaviPos();
	void setNaviPos();

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
protected:
	GenObjectFactory()
	    : Factory<GenObject>(12)
	{
	}

public:
	static GenObject* getProduct(u32 id);
	static void createInstance();

	static GenObjectFactory* factory;

	// _00-_0C = Factory
};

/**
 * @brief TODO
 */
struct GenType : public GenBase {
	GenType(u32 id, immut char* name)
	    : GenBase(id, "time type", name)
	    , mDaysToResurrection(this, 0, 0, 0, "b00", "復活日数") // 'days to resurrection'
	    , mCarryOver(this, 0, 0, 0, "b01", "キャリーオーバー")  // 'carryover'
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
	Parm<int> mDaysToResurrection; // _18, b00
	Parm<int> mCarryOver;          // _28, b01, This is *really* poorly named (see `Generator::doAdjustFaceDir`)
};

/**
 * @brief TODO
 */
struct GenTypeAtOnce : public GenType {
	GenTypeAtOnce()
	    : GenType('aton', "最初から全部生む")   // 'generate everything from the beginning'
	    , mMaxCount(this, 1, 0, 0, "p00", "数") // 'number'
	{
	}

	virtual void init(Generator*);                       // _24
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
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
	GenTypeInitRand()
	    : GenType('irnd', "最初から生む（ランダム）") // 'generate from the beginning (random)'
	    , _38(this, 1, 0, 0, "p00", "最低数")         // 'minimum number'
	    , mMaxCount(this, 5, 0, 0, "p01", "最高数")   // 'maximum number'
	{
	}

	virtual void init(Generator*);                       // _24
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
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
	GenTypeOne()
	    : GenType('1one', "１つだけうむ")      // 'just one thing'
	    , _38(this, 0, 0, 0, "p00", "回転(x)") // 'rotation (x)'
	    , _48(this, 0, 0, 0, "p01", "回転(y)") // 'rotation (y)'
	    , _58(this, 0, 0, 0, "p02", "回転(z)") // 'rotation (z)'
	{
	}

	virtual void init(Generator*);                       // _24
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
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
protected:
	GenTypeFactory()
	    : Factory<GenType>(6)
	{
	}

public:
	static GenType* getProduct(u32 id);
	static void createInstance();

	static GenTypeFactory* factory;

	// _00-_0C = Factory
};

/**
 * @brief TODO
 */
struct GenArea : public GenBase {
	GenArea(u32 id, immut char* name)
	    : GenBase(id, "area type", name)
	{
	}

	virtual u32 getLatestVersion();                // _20
	virtual void init(Generator*) { }              // _24
	virtual void update(Generator*) { }            // _28
	virtual void render(Graphics&, Generator*) { } // _2C
	virtual Vector3f getPos(Generator*) = 0;       // _30
	virtual f32 getRadius() { return 0.0f; }       // _34
	virtual void doWrite(RandomAccessStream&);     // _08
	virtual void doRead(RandomAccessStream&);      // _14

	// _04     = VTBL
	// _00-_18 = GenBase
	Vector3f _18; // _18
};

/**
 * @brief TODO
 */
struct GenAreaCircle : public GenArea {
	GenAreaCircle()
	    : GenArea('circ', "inside circle")
	    , mRadius(this, 50.0f, 0.0f, 0.0f, "p00", "半径") // 'radius'
	{
	}

	virtual Vector3f getPos(Generator*);                 // _30
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void render(Graphics&, Generator*);          // _2C
	virtual f32 getRadius() { return mRadius(); }        // _34

	// _04     = VTBL
	// _00-_24 = GenArea
	Parm<f32> mRadius; // _24, p00
};

/**
 * @brief TODO
 */
struct GenAreaPoint : public GenArea {
	GenAreaPoint()
	    : GenArea('pint', "at a point")
	{
	}

	virtual Vector3f getPos(Generator*);        // _30
	virtual void render(Graphics&, Generator*); // _2C

	// _04     = VTBL
	// _00-_24 = GenArea
};

/**
 * @brief TODO
 */
struct GenAreaFactory : public Factory<GenArea> {
protected:
	GenAreaFactory()
	    : Factory<GenArea>(6)
	{
	}

public:
	static GenArea* getProduct(u32 id);
	static void createInstance();

	static GenAreaFactory* factory;

	// _00-_0C = Factory
};

/**
 * @brief TODO
 */
struct Generator : public Node {
	Generator();
	Generator(int);

	virtual void read(RandomAccessStream&); // _0C
	virtual void update();                  // _10
	virtual void render(Graphics&);         // _18

	bool isExpired();
	void loadCreature(RandomAccessStream&);
	void saveCreature(RandomAccessStream&);
	void init();
	void informDeath(Creature*);
	void write(RandomAccessStream&);

	// unused/inlined:
	~Generator();
	void updateUseList();

	void removeSelf(AgeServer&);

	static bool ramMode;

	void setDayLimit(int limit) { mDayLimit = limit; }
	Vector3f getPos() { return mGenPosition + mGenOffset; }

	int getRebirthDay() { return mGenType->mDaysToResurrection(); }
	bool readFromRam() { return !mIsRamReadDisabled; }

	// This inline is actually called `isCarryOver`, but it is *not* used for this purpose (carry-over configuration as it exists in
	// the final game is stored in `Generator::mCarryOverFlags`).  I would leave it with its original name if it wasn't so confusing.
	int doAdjustFaceDir() { return mGenType->mCarryOver(); }

	// DLL inlines to make:
	void changeNaviPos();
	void setNaviPos();
	void setOffset(immut Vector3f& ofs) { mGenOffset = ofs; }
	void setPos(immut Vector3f& pos) { mGenPosition = pos; }

	void genAge(AgeServer&);
	void changeArea(AgeServer&);
	void changeObject(AgeServer&);
	void changeType(AgeServer&);

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
public:
	GeneratorMgr();

#ifdef WIN32
	virtual void genAge(AgeServer&);
#endif

	virtual void update();          // _10
	virtual void render(Graphics&); // _18

	void init();
	void setDayLimit(int);
	void updateUseList();
	void read(RandomAccessStream&, bool);

	// unused/inlined:
	void write(RandomAccessStream&);

	// DLL inlines:
	void setLimitGenerator(bool val) { mIsLimitGenerator = val; }

	void genWrite(AgeServer&);
	void addGenerator(AgeServer&);
	void removeGenerator(AgeServer&, Generator*);

protected:
	void setNaviPos();
	void changeNaviPos();

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
