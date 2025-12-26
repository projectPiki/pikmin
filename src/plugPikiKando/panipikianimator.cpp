#include "PaniPikiAnimator.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("panipikianimator");

immut char* PaniPikiAnimator::motionLabels[PIKIANIM_COUNT] = {
	"RUN",      "NIGERU",    "WALK",      "WAIT",        "PICK",     // 0-4
	"NUKU",     "NUKARERU",  "DEAD",      "DEAD2",       "DEAD3",    // 5-9
	"DAMAGE",   "ASIBUMI",   "OCARRY",    "LSUBERU",     "RSUBERU",  // 10-14
	"TANEMAKI", "JOB1",      "GROWUP1",   "GROWUP2",     "JOB2",     // 15-19
	"KOROBU",   "JUMP",      "STILLJUMP", "ATTACK",      "BUTUKARU", // 20-24
	"PUNCH",    "KENKA",     "THROW",     "HANG",        "FALL",     // 25-29
	"JKOKE",    "JHIT",      "GETUP",     "NEWJMP",      "ROLLJMP",  // 30-34
	"WAVEJMP",  "THROWWAIT", "PUSH",      "UMARU",       "AKUBI",    // 35-39
	"RINBOW",   "IRAIRA",    "FURIMUKU",  "JUMPKICK",    "KAIFUKU",  // 40-44
	"KIZUKU",   "PICKLOOP",  "MIZUNOMI",  "KUTTUKU",     "FUE",      // 45-49
	"SUWARU",   "AOGU",      "NERU",      "PRESS1",      "PRESS2",   // 50-54
	"SPRESS",   "TYAKUSUI",  "OBORERU",   "SIZUMU",      "HIKAKARU", // 55-59
	"OTIKAKE",  "OTIRU",     "HNOBORU",   "NOBORU",      "CHATTING", // 60-64
	"SAGASU2",  "OTIKAKE2",  "KAIFUKU3",  "Punch!",      "MOERU",    // 65-69
	"ESA",      "GAMEOVER",  "GATTU",     "GAKKARI",     "OKORU",    // 70-74
	"ROTJUMP",  "gwait1",    "gwait2",    "gfuri1",      "gfuri2",   // 75-79
	"gnuke",    "jump b1",   "nuku fast", "nukare fast", "mizuage",  // 80-84
	"sagasu",   "osu",       "osu-walk",  "noru",        "odead",    // 85-89
};

/**
 * @todo: Documentation
 */
PaniMotionTable* PaniPikiAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(PIKIANIM_COUNT);
	table->setMotion(0, new PaniMotion(0));
	table->setMotion(1, new PaniMotion(4));
	table->setMotion(2, new PaniMotion(25));
	table->setMotion(3, new PaniMotion(12));
	table->setMotion(4, new PaniMotion(1));
	table->setMotion(5, new PaniMotion(28));
	table->setMotion(6, new PaniMotion(29));
	table->setMotion(7, new PaniMotion(20));
	table->setMotion(8, new PaniMotion(42));
	table->setMotion(9, new PaniMotion(48));
	table->setMotion(10, new PaniMotion(21));
	table->setMotion(11, new PaniMotion(44));
	table->setMotion(12, new PaniMotion(45));
	table->setMotion(13, new PaniMotion(52));
	table->setMotion(14, new PaniMotion(53));
	table->setMotion(15, new PaniMotion(34));
	table->setMotion(17, new PaniMotion(39));
	table->setMotion(18, new PaniMotion(40));
	table->setMotion(19, new PaniMotion(41));
	table->setMotion(20, new PaniMotion(24));
	table->setMotion(21, new PaniMotion(9));
	table->setMotion(22, new PaniMotion(13));
	table->setMotion(23, new PaniMotion(18));
	table->setMotion(24, new PaniMotion(33));
	table->setMotion(25, new PaniMotion(94));
	table->setMotion(26, new PaniMotion(36));
	table->setMotion(27, new PaniMotion(54));
	table->setMotion(28, new PaniMotion(55));
	table->setMotion(29, new PaniMotion(56));
	table->setMotion(30, new PaniMotion(57));
	table->setMotion(31, new PaniMotion(58));
	table->setMotion(32, new PaniMotion(59));
	table->setMotion(33, new PaniMotion(60));
	table->setMotion(34, new PaniMotion(61));
	table->setMotion(35, new PaniMotion(62));
	table->setMotion(36, new PaniMotion(63));
	table->setMotion(37, new PaniMotion(64));
	table->setMotion(38, new PaniMotion(31));
	table->setMotion(39, new PaniMotion(10));
	table->setMotion(40, new PaniMotion(16));
	table->setMotion(41, new PaniMotion(3));
	table->setMotion(42, new PaniMotion(38));
	table->setMotion(43, new PaniMotion(47));
	table->setMotion(44, new PaniMotion(32));
	table->setMotion(45, new PaniMotion(66));
	table->setMotion(46, new PaniMotion(68));
	table->setMotion(47, new PaniMotion(67));
	table->setMotion(48, new PaniMotion(71));
	table->setMotion(49, new PaniMotion(74));
	table->setMotion(50, new PaniMotion(75));
	table->setMotion(51, new PaniMotion(76));
	table->setMotion(52, new PaniMotion(77));
	table->setMotion(53, new PaniMotion(78));
	table->setMotion(54, new PaniMotion(79));
	table->setMotion(55, new PaniMotion(80));
	table->setMotion(56, new PaniMotion(81));
	table->setMotion(57, new PaniMotion(82));
	table->setMotion(58, new PaniMotion(83));
	table->setMotion(59, new PaniMotion(84));
	table->setMotion(60, new PaniMotion(85));
	table->setMotion(61, new PaniMotion(86));
	table->setMotion(62, new PaniMotion(87));
	table->setMotion(63, new PaniMotion(88));
	table->setMotion(64, new PaniMotion(89));
	table->setMotion(65, new PaniMotion(90));
	table->setMotion(66, new PaniMotion(91));
	table->setMotion(67, new PaniMotion(92));
	table->setMotion(69, new PaniMotion(95));
	table->setMotion(70, new PaniMotion(8));
	table->setMotion(71, new PaniMotion(26));
	table->setMotion(16, new PaniMotion(35));
	table->setMotion(72, new PaniMotion(5));
	table->setMotion(73, new PaniMotion(6));
	table->setMotion(74, new PaniMotion(7));
	table->setMotion(75, new PaniMotion(14));
	table->setMotion(76, new PaniMotion(11));
	table->setMotion(77, new PaniMotion(17));
	table->setMotion(78, new PaniMotion(19));
	table->setMotion(79, new PaniMotion(27));
	table->setMotion(80, new PaniMotion(37));
	table->setMotion(81, new PaniMotion(22));
	table->setMotion(82, new PaniMotion(43));
	table->setMotion(83, new PaniMotion(93));
	table->setMotion(84, new PaniMotion(69));
	table->setMotion(85, new PaniMotion(72));
	table->setMotion(86, new PaniMotion(96));
	table->setMotion(87, new PaniMotion(97));
	table->setMotion(88, new PaniMotion(98));
	table->setMotion(89, new PaniMotion(99));
	return table;
}

/**
 * @todo: Documentation
 */
PaniPikiAnimator::PaniPikiAnimator()
{
}
