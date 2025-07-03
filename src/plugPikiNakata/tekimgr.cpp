#include "teki.h"
#include "MemStat.h"
#include "nlib/System.h"
#include "TekiAnimationManager.h"
#include "TekiStrategy.h"
#include "sysNew.h"
#include "timers.h"
#include "TekiYamashita.h"
#include "Dolphin/os.h"
#include "gameflow.h"
#include "TekiParameters.h"
#include "PlayerState.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("tekiMgr");

TekiMgr* tekiMgr;

char* TekiMgr::typeNames[TEKI_TypeCount] = {
	"frog",     // 0, Yellow Wollywog
	"iwagen",   // 1, Iwagen (unused enemy)
	"iwagon",   // 2, Rolling Boulder
	"chappy",   // 3, Dwarf Bulborb
	"swallow",  // 4, Spotty Bulborb
	"mizigen",  // 5, Honeywisp Spawner
	"qurione",  // 6, Honeywisp
	"palm",     // 7, Pellet Posy
	"collec",   // 8, Breadbug
	"kinoko",   // 9, Puffstool
	"shell",    // 10, Pearly Clamclamp (shell)
	"napkid",   // 11, Swooping Snitchbug
	"hollec",   // 12, Breadbug Nest
	"pearl",    // 13, Pearly Clamclamp (pearl)
	"rocpe",    // 14, Pearly Clamclamp (ship part)
	"tank",     // 15, Fiery Blowhog
	"mar",      // 16, Puffy Blowhog
	"beatle",   // 17, Armored Cannon Beetle
	"kabekuiA", // 18, Female Sheargrub
	"kabekuiB", // 19, Male Sheargrub
	"kabekuiC", // 20, Shearwig
	"tamago",   // 21, Giant Egg (for Smoky Progg)
	"dororo",   // 22, Smoky Progg
	"hibaA",    // 23, Fire Geyser
	"miurin",   // 24, Mamuta
	"otama",    // 25, Wogpole
	"usuba",    // 26, Usuba (unused enemy, crashes)
	"yamash3",  // 27, ? (unused enemy, crashes)
	"yamash4",  // 28, ? (unused enemy, crashes)
	"yamash5",  // 29, ? (unused enemy, crashes)
	"namazu",   // 30, Water Dumple
	"chappb",   // 31, Dwarf Bulbear
	"swallob",  // 32, Spotty Bulbear
	"frow",     // 33, Wollywog
	"nakata1",  // 34, ? (unused enemy, crashes)
};

int TekiMgr::typeIds[TEKI_TypeCount] = {
	'tkfr', // 0, Yellow Wollywog
	'tkig', // 1, Iwagen (unused enemy)
	'tkiw', // 2, Rolling Boulder
	'tkch', // 3, Dwarf Bulborb
	'tksw', // 4, Spotty Bulborb
	'tkmi', // 5, Honeywisp Spawner
	'tkqu', // 6, Honeywisp
	'tkpa', // 7, Pellet Posy
	'tkco', // 8, Breadbug
	'tkki', // 9, Puffstool
	'tksh', // 10, Pearly Clamclamp (shell)
	'tkna', // 11, Swooping Snitchbug
	'tkho', // 12, Breadbug Nest
	'tkpe', // 13, Pearly Clamclamp (pearl)
	'tkro', // 14, Pearly Clamclamp (ship part)
	'tkta', // 15, Fiery Blowhog
	'tkma', // 16, Puffy Blowhog
	'tkbe', // 17, Armored Cannon Beetle
	'tkka', // 18, Female Sheargrub
	'tkkb', // 19, Male Sheargrub
	'tkkc', // 20, Shearwig
	'tktm', // 21, Giant Egg (for Smoky Progg)
	'tkdo', // 22, Smoky Progg
	'tkhi', // 23, Fire Geyser
	'tkmu', // 24, Mamuta
	'tkot', // 25, Wogpole
	'tkus', // 26, Usuba (unused enemy, crashes)
	'tky3', // 27, ? (unused enemy, crashes)
	'tky4', // 28, ? (unused enemy, crashes)
	'tky5', // 29, ? (unused enemy, crashes)
	'tknm', // 30, Water Dumple
	'tkcb', // 31, Dwarf Bulbear
	'tksb', // 32, Spotty Bulbear
	'tkfw', // 33, Wollywog
	'tkn1', // 34, ? (unused enemy, crashes)
};

/*
 * --INFO--
 * Address:	8014A58C
 * Size:	00000C
 */
void TekiMgr::initTekiMgr()
{
	tekiMgr = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
int TekiMgr::getTypeIndex(char* typeName)
{
	for (int i = 0; i < TEKI_TypeCount; i++) {
		if (strcmp(typeNames[i], typeName) == 0) {
			return i;
		}
	}
	PRINT("!getType:%s\n", typeName);
	return -1;
}

/*
 * --INFO--
 * Address:	8014A598
 * Size:	000300
 */
TekiMgr::TekiMgr()
{
	PRINT("TekiMgr>\n");
	memStat->start("tekiMgr");
	int heapStartSize = NSystem::getFreeHeap();
	mTekiAnimMgr      = new TekiAnimationManager(this);
	mMotionTable      = PaniTekiAnimator::createMotionTable();
	mStrategyTable    = new TekiStrategyTable(TEKI_TypeCount);
	mTekiSoundTables  = new PaniSoundTable*[TEKI_TypeCount];
	int i;
	for (i = 0; i < TEKI_TypeCount; i++) {
		mTekiParams[i]      = nullptr;
		mTekiSoundTables[i] = nullptr;
		mTekiShapes[i]      = nullptr;
	}

	TekiNakata::makeTekiParameters(this);
	TekiYamashita::makeTekiParameters(this);

	for (i = 0; i < TEKI_TypeCount; i++) {
		if (hasType(i)) {
			char buf[128];
			sprintf(buf, "tekipara/%s.bin", typeNames[i]);
			PRINT("TekiMgr:fileName:%d:%s\n", i, buf);
			mTekiParams[i]->load("", buf, 1);
		}
	}

	setUsingTypeTable(false);
	setVisibleTypeTable(true);
	memStat->end("tekiMgr");

	int heapEndSize = NSystem::getFreeHeap();

	memStat->start("tekis");
	int tekisHeapStartSize = NSystem::getFreeHeap();
	create(80);
	memStat->end("tekis");

	int tekiHeapEndSize = NSystem::getFreeHeap();
	PRINT("TekiMgr:manager uses %.2f[KB],%d tekis use %.2f[KB]\n", (heapStartSize - heapEndSize) / 1024.0f, 80,
	      (tekisHeapStartSize - tekiHeapEndSize) / 1024.0f);
	PRINT("TekiMgr<\n");
}

/*
 * --INFO--
 * Address:	8014A898
 * Size:	0001F0
 */
void TekiMgr::startStage()
{
	char filename[128];
	char buf[128];
	PRINT("startStage>\n");
	TekiNakata::makeTekis(this);
	TekiYamashita::makeTekis(this);

	memStat->start("teki data");
	int dataHeapStartSize = NSystem::getFreeHeap();

	for (int i = 0; i < TEKI_TypeCount; i++) {
		if (isUsingType(i) && hasModel(i)) {
			memStat->start(typeNames[i]);
			sprintf(buf, "%s model data", typeNames[i]);
			int tekiHeapStartSize = NSystem::getFreeHeap();
			sprintf(filename, "tekis/%s/%s.mod", typeNames[i], typeNames[i]);
			PRINT("startStage:fileName:%d:%s\n", i, filename);
			mTekiShapes[i]       = new TekiShapeObject(gameflow.loadShape(filename, true));
			int modelHeapEndSize = NSystem::getFreeHeap();

			sprintf(buf, "%s animation data", typeNames[i]);
			int animHeapStartSize = NSystem::getFreeHeap();
			sprintf(filename, "tekikeys/%s.key", typeNames[i]);
			mTekiShapes[i]->mAnimMgr->loadAnims(filename, nullptr);
			PRINT("startStage:%d:%d\n", i, mTekiShapes[i]->mAnimMgr->countAnims());
			memStat->end(typeNames[i]);
			int tekiHeapEndSize = NSystem::getFreeHeap();
			add(mTekiShapes[i]->mAnimMgr);
			PRINT("startStage:%s uses %.2f[KB](model:%.2f,animation:%.2f)\n", typeNames[i], (tekiHeapStartSize - tekiHeapEndSize) / 1024.0f,
			      (tekiHeapStartSize - modelHeapEndSize) / 1024.0f, (animHeapStartSize - tekiHeapEndSize) / 1024.0f);
		}
	}

	memStat->end("teki data");
	NSystem::getFreeHeap();
	reset();
	PRINT("startStage<\n");
}

/*
 * --INFO--
 * Address:	8014AA88
 * Size:	000020
 */
void TekiMgr::update()
{
	gsys->mTimer->start("teki updt", true);
	MonoObjectMgr::update();
	gsys->mTimer->stop("teki updt");
}

/*
 * --INFO--
 * Address:	8014AAA8
 * Size:	0000A4
 */
void TekiMgr::refresh(Graphics& gfx)
{
	gsys->mTimer->start("teki draw", true);
	for (int i = 0; i < mMaxElements; i++) {
		if (mEntryStatus[i] == 0) {
			Teki* teki = (Teki*)mObjectList[i];
			if (isVisibleType(teki->mTekiType)) {
				teki->refresh(gfx);
			}
		}
	}
	gsys->mTimer->stop("teki draw");
}

/*
 * --INFO--
 * Address:	8014AB4C
 * Size:	00007C
 */
Teki* TekiMgr::newTeki(int type)
{
	if (type < TEKI_START || type >= TEKI_TypeCount) {
		PRINT("?newTeki:%d\n", type);
		type = TEKI_Frog; // lol
	}
	Teki* teki = (Teki*)birth();
	if (!teki) {
		PRINT("!!!newTeki:can't create any more\n");
		return nullptr;
	}

	teki->init(type);
	return teki;
}

/*
 * --INFO--
 * Address:	8014ABC8
 * Size:	00010C
 */
void TekiMgr::reset()
{
	PRINT("reset>\n");
	Iterator iter(this);
	CI_LOOP(iter)
	{
		Teki* teki = (Teki*)*iter;
		teki->reset();
	}

	PRINT("reset<\n");
}

/*
 * --INFO--
 * Address:	8014ACD4
 * Size:	000044
 */
Creature* TekiMgr::createObject()
{
	return new Teki();
}

/*
 * --INFO--
 * Address:	8014AD18
 * Size:	000014
 */
TekiStrategy* TekiMgr::getStrategy(int tekiType)
{
	return mStrategyTable->getStrategy(tekiType);
}

/*
 * --INFO--
 * Address:	8014AD2C
 * Size:	000010
 */
TekiParameters* TekiMgr::getTekiParameters(int tekiType)
{
	return mTekiParams[tekiType];
}

/*
 * --INFO--
 * Address:	8014AD3C
 * Size:	000010
 */
TekiShapeObject* TekiMgr::getTekiShapeObject(int tekiType)
{
	return mTekiShapes[tekiType];
}

/*
 * --INFO--
 * Address:	8014AD4C
 * Size:	000010
 */
PaniSoundTable* TekiMgr::getSoundTable(int tekiType)
{
	return mTekiSoundTables[tekiType];
}

/*
 * --INFO--
 * Address:	8014AD5C
 * Size:	00011C
 */
void TekiMgr::refresh2d(Graphics& gfx)
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		Teki* teki = (Teki*)*iter;
		teki->refresh2d(gfx);
	}
}

/*
 * --INFO--
 * Address:	8014AE78
 * Size:	0000A8
 */
void TekiMgr::setUsingTypeTable(bool isUsingType)
{
	for (int i = 0; i < TEKI_TypeCount; i++) {
		mUsingType[i] = isUsingType;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void TekiMgr::setUsingType(int tekiType, bool isUsing)
{
	mUsingType[tekiType] = isUsing;
}

/*
 * --INFO--
 * Address:	8014AF20
 * Size:	0000A8
 */
void TekiMgr::setVisibleTypeTable(bool isVisibleType)
{
	for (int i = 0; i < TEKI_TypeCount; i++) {
		mVisibleType[i] = isVisibleType;
	}
}

/*
 * --INFO--
 * Address:	8014AFC8
 * Size:	00000C
 */
void TekiMgr::setVisibleType(int tekiType, bool isVisible)
{
	mVisibleType[tekiType] = isVisible;
}

/*
 * --INFO--
 * Address:	8014AFD4
 * Size:	000070
 */
bool TekiMgr::hasModel(int type)
{
	return !(type == TEKI_Mizigen || type == TEKI_Nakata1 || type == TEKI_Yamash3 || type == TEKI_Yamash4 || type == TEKI_Yamash5);
}

/*
 * --INFO--
 * Address:	8014B044
 * Size:	000054
 */
int TekiMgr::getResultFlag(int tekiType)
{
	int resFlag = 0;
	if (tekiType == TEKI_Collec) {
		resFlag = RESFLAG_Collec;

	} else if (tekiType == TEKI_Frow) {
		resFlag = RESFLAG_Otimoti;

	} else if (tekiType == TEKI_Shell) {
		resFlag = RESFLAG_Shell;

	} else if (tekiType == TEKI_Swallow) {
		resFlag = RESFLAG_Swallow;

	} else if (tekiType == TEKI_Qurione) {
		resFlag = RESFLAG_Mizinko;
	} else {
		PRINT("!getResultFlag:not supported type:%d\n", tekiType);
	}

	return resFlag;
}
