#include "teki.h"
#include "TAI/Otimoti.h"
#include "TAI/Iwagen.h"
#include "TAI/Chappy.h"
#include "TAI/Swallow.h"
#include "TAI/Mizinko.h"
#include "TAI/Palm.h"
#include "TAI/Collec.h"
#include "TAI/Kinoko.h"
#include "TAI/Shell.h"
#include "TAI/Napkid.h"
#include "sysNew.h"
#include "DebugLog.h"

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
DEFINE_PRINT("tekinakata")

namespace TekiNakata {

/*
 * --INFO--
 * Address:	8014B124
 * Size:	000244
 */
void makeTekiParameters(TekiMgr* mgr)
{
	mgr->mTekiParams[TEKI_Frog]    = new TaiOtimotiParameters();
	mgr->mTekiParams[TEKI_Iwagen]  = new TaiIwagenParameters();
	mgr->mTekiParams[TEKI_Iwagon]  = new TaiIwagonParameters();
	mgr->mTekiParams[TEKI_Chappy]  = new TaiChappyParameters();
	mgr->mTekiParams[TEKI_Swallow] = new TaiSwallowParameters();
	mgr->mTekiParams[TEKI_Mizigen] = new TaiMizigenParameters();
	mgr->mTekiParams[TEKI_Qurione] = new TaiMizinkoParameters();
	mgr->mTekiParams[TEKI_Palm]    = new TaiPalmParameters();
	mgr->mTekiParams[TEKI_Collec]  = new TaiCollecParameters();
	mgr->mTekiParams[TEKI_Kinoko]  = new TaiKinokoParameters();
	mgr->mTekiParams[TEKI_Shell]   = new TaiShellParameters();
	mgr->mTekiParams[TEKI_Napkid]  = new TaiNapkidParameters();
	mgr->mTekiParams[TEKI_Hollec]  = new TaiHollecParameters();
	mgr->mTekiParams[TEKI_Pearl]   = new TaiPearlParameters();
	mgr->mTekiParams[TEKI_Rocpe]   = new TaiRocpearlParameters();
	mgr->mTekiParams[TEKI_Chappb]  = new TaiBlackChappyParameters();
	mgr->mTekiParams[TEKI_Swallob] = new TaiBlackSwallowParameters();
	mgr->mTekiParams[TEKI_Frow]    = new TaiBlackFrogParameters();
	mgr->mTekiParams[TEKI_Namazu]  = new TaiCatfishParameters();
}

/*
 * --INFO--
 * Address:	8014B368
 * Size:	000690
 */
void makeTekis(TekiMgr* mgr)
{
	if (mgr->isUsingType(TEKI_Frog)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Frog];
		mgr->mStrategyTable->setStrategy(TEKI_Frog, new TaiOtimotiStrategy(param));
		mgr->mTekiSoundTables[TEKI_Frog] = new TaiOtimotiSoundTable();
	}

	if (mgr->isUsingType(TEKI_Iwagen)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Iwagen];
		mgr->mStrategyTable->setStrategy(TEKI_Iwagen, new TaiIwagenStrategy(param));
		// no sound table.
	}

	if (mgr->isUsingType(TEKI_Iwagon)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Iwagon];
		mgr->mStrategyTable->setStrategy(TEKI_Iwagon, new TaiIwagonStrategy(param));
		mgr->mTekiSoundTables[TEKI_Iwagon] = new TaiIwagonSoundTable();
	}

	if (mgr->isUsingType(TEKI_Chappy)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Chappy];
		mgr->mStrategyTable->setStrategy(TEKI_Chappy, new TaiChappyStrategy(param));
		mgr->mTekiSoundTables[TEKI_Chappy] = new TaiChappySoundTable();
	}

	if (mgr->isUsingType(TEKI_Swallow)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Swallow];
		mgr->mStrategyTable->setStrategy(TEKI_Swallow, new TaiSwallowStrategy(param));
		mgr->mTekiSoundTables[TEKI_Swallow] = new TaiSwallowSoundTable();
	}

	if (mgr->isUsingType(TEKI_Mizigen)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Mizigen];
		mgr->mStrategyTable->setStrategy(TEKI_Mizigen, new TaiMizigenStrategy(param));
		// no sound table.
	}

	if (mgr->isUsingType(TEKI_Qurione)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Qurione];
		mgr->mStrategyTable->setStrategy(TEKI_Qurione, new TaiMizinkoStrategy(param));
		mgr->mTekiSoundTables[TEKI_Qurione] = new TaiMizinkoSoundTable();
	}

	if (mgr->isUsingType(TEKI_Palm)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Palm];
		mgr->mStrategyTable->setStrategy(TEKI_Palm, new TaiPalmStrategy(param));
		mgr->mTekiSoundTables[TEKI_Palm] = new TaiPalmSoundTable();
	}

	if (mgr->isUsingType(TEKI_Collec)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Collec];
		mgr->mStrategyTable->setStrategy(TEKI_Collec, new TaiCollecStrategy(param));
		mgr->mTekiSoundTables[TEKI_Collec] = new TaiCollecSoundTable();
	}

	if (mgr->isUsingType(TEKI_Kinoko)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Kinoko];
		mgr->mStrategyTable->setStrategy(TEKI_Kinoko, new TaiKinokoStrategy(param));
		mgr->mTekiSoundTables[TEKI_Kinoko] = new TaiKinokoSoundTable();
	}

	if (mgr->isUsingType(TEKI_Shell)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Shell];
		mgr->mStrategyTable->setStrategy(TEKI_Shell, new TaiShellStrategy(param));
		mgr->mTekiSoundTables[TEKI_Shell] = new TaiShellSoundTable();
	}

	if (mgr->isUsingType(TEKI_Napkid)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Napkid];
		mgr->mStrategyTable->setStrategy(TEKI_Napkid, new TaiNapkidStrategy(param));
		mgr->mTekiSoundTables[TEKI_Napkid] = new TaiNapkidSoundTable();
	}

	if (mgr->isUsingType(TEKI_Hollec)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Hollec];
		mgr->mStrategyTable->setStrategy(TEKI_Hollec, new TaiHollecStrategy(param));
		// no sound table.
	}

	// i hate this but it's necessary.
	int pearlType = TEKI_Pearl;
	if (mgr->isUsingType(pearlType) || mgr->isUsingType(TEKI_Shell)) {
		mgr->mUsingType[pearlType] = true;
		TekiParameters* param      = mgr->mTekiParams[TEKI_Pearl];
		mgr->mStrategyTable->setStrategy(TEKI_Pearl, new TaiPearlStrategy(param));
		mgr->mTekiSoundTables[TEKI_Pearl] = new TaiPearlSoundTable();
	}

	pearlType = TEKI_Rocpe;
	if (mgr->isUsingType(pearlType) || mgr->isUsingType(TEKI_Shell)) {
		mgr->mUsingType[pearlType] = true;
		TekiParameters* param      = mgr->mTekiParams[TEKI_Rocpe];
		mgr->mStrategyTable->setStrategy(TEKI_Rocpe, new TaiPearlStrategy(param));
		mgr->mTekiSoundTables[TEKI_Rocpe] = new TaiPearlSoundTable();
	}

	if (mgr->isUsingType(TEKI_Chappb)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Chappb];
		mgr->mStrategyTable->setStrategy(TEKI_Chappb, new TaiChappyStrategy(param));
		mgr->mTekiSoundTables[TEKI_Chappb] = new TaiChappySoundTable();
	}

	if (mgr->isUsingType(TEKI_Swallob)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Swallob];
		mgr->mStrategyTable->setStrategy(TEKI_Swallob, new TaiSwallowStrategy(param));
		mgr->mTekiSoundTables[TEKI_Swallob] = new TaiSwallowSoundTable();
	}

	if (mgr->isUsingType(TEKI_Frow)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Frow];
		mgr->mStrategyTable->setStrategy(TEKI_Frow, new TaiOtimotiStrategy(param));
		mgr->mTekiSoundTables[TEKI_Frow] = new TaiBlackFrogSoundTable();
	}

	if (mgr->isUsingType(TEKI_Namazu)) {
		TekiParameters* param = mgr->mTekiParams[TEKI_Namazu];
		mgr->mStrategyTable->setStrategy(TEKI_Namazu, new TaiChappyStrategy(param));
		mgr->mTekiSoundTables[TEKI_Namazu] = new TaiCatfishSoundTable();
	}
}
} // namespace TekiNakata
