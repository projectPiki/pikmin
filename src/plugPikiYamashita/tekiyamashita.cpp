#include "TekiYamashita.h"

#include "DebugLog.h"
#include "TAI/Beatle.h"
#include "TAI/Dororo.h"
#include "TAI/HibaA.h"
#include "TAI/KabekuiA.h"
#include "TAI/KabekuiB.h"
#include "TAI/KabekuiC.h"
#include "TAI/Mar.h"
#include "TAI/Miurin.h"
#include "TAI/Otama.h"
#include "TAI/Tamago.h"
#include "TAI/Tank.h"
#include "TAI/Usuba.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tekiyamashita")

/*
 * --INFO--
 * Address:	801A30F8
 * Size:	000180
 */
void TekiYamashita::makeTekiParameters(TekiMgr* mgr)
{
	mgr->mTekiParams[TEKI_Tank]     = new TAItankParameters();
	mgr->mTekiParams[TEKI_Mar]      = new TAImarParameters();
	mgr->mTekiParams[TEKI_Beatle]   = new TAIbeatleParameters();
	mgr->mTekiParams[TEKI_KabekuiA] = new TAIkabekuiAParameters();
	mgr->mTekiParams[TEKI_KabekuiB] = new TAIkabekuiBParameters();
	mgr->mTekiParams[TEKI_KabekuiC] = new TAIkabekuiCParameters();
	mgr->mTekiParams[TEKI_Tamago]   = new TAItamagoParameters();
	mgr->mTekiParams[TEKI_Dororo]   = new TAIdororoParameters();
	mgr->mTekiParams[TEKI_HibaA]    = new TAIhibaAParameters();
	mgr->mTekiParams[TEKI_Miurin]   = new TAImiurinParameters();
	mgr->mTekiParams[TEKI_Usuba]    = new TAIusubaParameters();
	mgr->mTekiParams[TEKI_Otama]    = new TAIotamaParameters();
}

/*
 * --INFO--
 * Address:	801A3278
 * Size:	00031C
 */
void TekiYamashita::makeTekis(TekiMgr* mgr)
{
	STACK_PAD_VAR(1);

	mgr->mStrategyTable->setStrategy(TEKI_Tank, new TAItankStrategy());
	mgr->mTekiSoundTables[TEKI_Tank] = new TAItankSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_Mar, new TAImarStrategy());
	mgr->mTekiSoundTables[TEKI_Mar] = new TAImarSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_Beatle, new TAIbeatleStrategy());
	mgr->mTekiSoundTables[TEKI_Beatle] = new TAIbeatleSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_KabekuiA, new TAIkabekuiAStrategy());
	mgr->mTekiSoundTables[TEKI_KabekuiA] = new TAIkabekuiASoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_KabekuiB, new TAIkabekuiBStrategy());
	mgr->mTekiSoundTables[TEKI_KabekuiB] = new TAIkabekuiBSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_KabekuiC, new TAIkabekuiCStrategy());
	mgr->mTekiSoundTables[TEKI_KabekuiC] = new TAIkabekuiCSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_Tamago, new TAItamagoStrategy());
	mgr->mTekiSoundTables[TEKI_Tamago] = new TAItamagoSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_Dororo, new TAIdororoStrategy());
	mgr->mTekiSoundTables[TEKI_Dororo] = new TAIdororoSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_HibaA, new TAIhibaAStrategy());
	mgr->mTekiSoundTables[TEKI_HibaA] = new TAIhibaASoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_Miurin, new TAImiurinStrategy());
	mgr->mTekiSoundTables[TEKI_Miurin] = new TAImiurinSoundTable();

	mgr->mStrategyTable->setStrategy(TEKI_Otama, new TAIotamaStrategy());
	mgr->mTekiSoundTables[TEKI_Otama] = new TAIotamaSoundTable();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000488
 */
void TekiYamashita::makeDefaultAnimations()
{
	PRINT_NAKATA("makeDefaultAnimations>\n"); // The DLL says the wrong user print was used here.
	TAItankAnimation().makeDefaultAnimations();
	TAImarAnimation().makeDefaultAnimations();
	TAIbeatleAnimation().makeDefaultAnimations();
	TAIkabekuiBAnimation().makeDefaultAnimations(); // yep, they had this 3 times. nice.
	TAIkabekuiBAnimation().makeDefaultAnimations();
	TAIkabekuiBAnimation().makeDefaultAnimations();
	TAItamagoAnimation().makeDefaultAnimations();
	TAIdororoAnimation().makeDefaultAnimations();
	TAIhibaAAnimation().makeDefaultAnimations();
	TAImiurinAnimation().makeDefaultAnimations();
	TAIusubaAnimation().makeDefaultAnimations();
	TAIotamaAnimation().makeDefaultAnimations();
	PRINT_NAKATA("makeDefaultAnimations<\n"); // The DLL says the wrong user print was used here.
}
