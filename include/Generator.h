#ifndef _GENERATOR_H
#define _GENERATOR_H

#include "types.h"
#include "Node.h"
#include "Parameters.h"
#include "Ayu.h"
#include "Vector.h"
#include "ID32.h"

struct Creature;
struct MapMgr;
struct Pellet;
struct Generator;
struct GenType;
struct TekiPersonality;

/**
 * @brief TODO
 */
struct BirthInfo {
	Vector3f mPosition;    // _00
	Vector3f mRotation;    // _0C
	Vector3f mScale;       // _18
	Generator* mGenerator; // _24
};

template <typename T>
struct Factory {
	T* create(u32);

	// TODO: members
};

/**
 * @brief TODO
 */
struct Generator : public Node {
	Generator();
	Generator(int);

	static bool ramMode;

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

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x28 - 0x20]; // _20, unknown
	GenType* _28;        // _28
	u8 _2C[0x58 - 0x2C]; // _2C, unknown
	ID32 _58;            // _58, generator ID?
	ID32 _64;            // _64
	                     // TODO: members
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

		void saveCard(RandomAccessStream&);
		void loadCard(RandomAccessStream&);

		// unused/inlined:
		void dump();

		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	GeneratorCache();

	void init(u8*, int);
	void initGame();
	void addOne(u32);
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	void findCache(Cache&, u32);
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

	u8 _00[0x84]; // _00, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct GeneratorList {
	GeneratorList();

	void findGenerator(int);
	void createRamGenerators();
	void updateUseList();

	u8 _00[0x4]; // _04, unknown
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

	// _00     = VTBL
	// _00-_20 = Node
	u8 _20[0x5C - 0x20]; // _20, unknown
	u8 _5C;              // _5C
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
	virtual void render(Graphics&, Generator*);     // _30
	virtual void* birth(BirthInfo&) = 0;            // _34

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
	}

	virtual void doRead(RandomAccessStream&); // _14
	virtual void* birth(BirthInfo&);          // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	// TODO: members
};

/**
 * @brief TODO
 */
struct GenObjectBoss : public GenObject {
	inline GenObjectBoss()
	    : GenObject('boss', "ボスを生む") // 'generate a boss'
	{
	}

	virtual void doWrite(RandomAccessStream&);           // _08
	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void doRead(RandomAccessStream&);            // _14
	virtual void updateUseList(Generator*, int);         // _24
	virtual void* birth(BirthInfo&);                     // _34

	static void initialise();

	void readParameters(RandomAccessStream&);
	void writeParameters(RandomAccessStream&);

	// _04     = VTBL
	// _00-_18 = GenObject
	// TODO: members
};

/**
 * @brief TODO
 */
struct GenObjectDebug : public GenObject {
	GenObjectDebug(); // unused/inlined

	virtual void doRead(RandomAccessStream&); // _14
	virtual void* birth(BirthInfo&);          // _34

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
	virtual void* birth(BirthInfo&);                     // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	// TODO: members
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
	virtual void* birth(BirthInfo&);            // _34

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
	    : GenObject('mpar', "マップパーツを生む") // 'generate map parts'
	{
	}

	virtual void doRead(RandomAccessStream&);   // _14
	virtual void render(Graphics&, Generator*); // _30
	virtual void* birth(BirthInfo&);            // _34

	static void initialise(MapMgr*);

	// _04     = VTBL
	// _00-_18 = GenObject
	// TODO: members
};

/**
 * @brief TODO
 */
struct GenObjectNavi : public GenObject {
	GenObjectNavi(); // unused/inlined

	virtual void doRead(RandomAccessStream&); // _14
	virtual void* birth(BirthInfo&);          // _34

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
	virtual void* birth(BirthInfo&);             // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	u32 _18;  // _18, unknown
	ID32 _1C; // _1C
};

/**
 * @brief TODO
 */
struct GenObjectPiki : public GenObject {
	inline GenObjectPiki()
	    : GenObject('piki', "create PIKI")
	    , _18(this, 0, 0, 0, "p00", nullptr)
	    , _28(this, 0, 0, 0, "p01", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&); // _0C
	virtual void ramLoadParameters(RandomAccessStream&); // _10
	virtual void* birth(BirthInfo&);                     // _34

	// _04     = VTBL
	// _00-_18 = GenObject
	Parm<int> _18; // _18, p00
	Parm<int> _28; // _2C, p01
};

/**
 * @brief TODO
 */
struct GenObjectPlant : public GenObject {
	GenObjectPlant(); // unused/inlined

	virtual void doRead(RandomAccessStream&);    // _14
	virtual void updateUseList(Generator*, int); // _24
	virtual void render(Graphics&, Generator*);  // _30
	virtual void* birth(BirthInfo&);             // _34

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
	virtual void* birth(BirthInfo&);             // _34

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
	virtual void* birth(BirthInfo&);                     // _34

	static void initialise();

	// _04     = VTBL
	// _00-_18 = GenObject
	u32 _18;         // _18
	u32 _1C;         // _1C
	u32 _20;         // _20
	u32 _24;         // _24
	u8 _28[12];      // _28
	u32 _34;         // _34
	u8 _38[12];      // _38
	u32 _44;         // _44
	u8 _48[12];      // _48
	f32 _54;         // _54
	s32 mObjectType; // _58
	u32 mShapeType;  // _5C
	Vector3f _60;    // _60, hinderrock position (or just position?)
};

typedef GenObject* (*GenFunc)();

/**
 * @brief Fabricated. Need an array of something to go at 0x8 in GenObjectFactory
 */
struct GenObjectInfo {
	u32 mID;              // _00
	GenFunc mGenFunction; // _04
	char* mName;          // _08
	u32 mVersion;         // _0C
};

/**
 * @brief TODO
 */
struct GenObjectFactory : public Factory<GenObject> {

	// unused/inlined:
	void getProduct(u32);
	void createInstance();

	static GenObjectFactory* factory;

	int mSpawnerCount;           // _00
	int mMaxSpawners;            // _04
	GenObjectInfo* mSpawnerInfo; // _08, array
};

/**
 * @brief TODO
 */
struct GenType : public GenBase {
	inline GenType(u32 id, char* name)
	    : GenBase(id, "time type", name)
	    , _18(this, 0, 0, 0, "b00", nullptr)
	    , _28(this, 0, 0, 0, "b01", nullptr)
	{
	}

	virtual void ramSaveParameters(RandomAccessStream&);   // _0C
	virtual void ramLoadParameters(RandomAccessStream&);   // _10
	virtual u32 getLatestVersion();                        // _20
	virtual void init(Generator*);                         // _24
	virtual void update(Generator*);                       // _28
	virtual void render(Graphics&, Generator*);            // _2C
	virtual void setBirthInfo(BirthInfo&, Generator*) = 0; // _30
	virtual int getMaxCount()                         = 0; // _34

	// _04     = VTBL
	// _00-_18 = GenBase
	Parm<int> _18; // _18, b00
	Parm<int> _28; // _28, b01
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
	virtual int getMaxCount();                           // _34

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

	// unused/inlined:
	void getProduct(u32);
	void createInstance();

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

	virtual void doWrite(RandomAccessStream&);  // _08
	virtual void doRead(RandomAccessStream&);   // _14
	virtual u32 getLatestVersion();             // _20
	virtual void init(Generator*);              // _24
	virtual void update(Generator*);            // _28
	virtual void render(Graphics&, Generator*); // _2C
	virtual void getPos(Generator*) = 0;        // _30
	virtual f32 getRadius();                    // _34

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
	virtual void getPos(Generator*);                     // _30
	virtual f32 getRadius();                             // _34

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
	virtual void getPos(Generator*);            // _30

	// _04     = VTBL
	// _00-_24 = GenArea
};

/**
 * @brief TODO
 */
struct GenAreaFactory : public Factory<GenArea> {

	// unused/inlined:
	void getProduct(u32);
	void createInstance();

	static GenAreaFactory* factory;

	// TODO: members
};

extern GeneratorCache* generatorCache;
extern GeneratorList* generatorList;
extern GeneratorMgr* generatorMgr;
extern GeneratorMgr* onceGeneratorMgr;
extern GeneratorMgr* dailyGeneratorMgr;
extern GeneratorMgr* plantGeneratorMgr;
extern GeneratorMgr* limitGeneratorMgr;

#endif
