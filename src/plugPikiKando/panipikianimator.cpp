#include "PaniPikiAnimator.h"
#include "sysNew.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "panipikianimator");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

char* PaniPikiAnimator::motionLabels[90] = {
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

/*
 * --INFO--
 * Address:	80118D04
 * Size:	000CD0
 */
PaniMotionTable* PaniPikiAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(PIKIANIM_COUNT);
	table->mMotions[0]     = new PaniMotion(0);
	table->mMotions[1]     = new PaniMotion(4);
	table->mMotions[2]     = new PaniMotion(25);
	table->mMotions[3]     = new PaniMotion(12);
	table->mMotions[4]     = new PaniMotion(1);
	table->mMotions[5]     = new PaniMotion(28);
	table->mMotions[6]     = new PaniMotion(29);
	table->mMotions[7]     = new PaniMotion(20);
	table->mMotions[8]     = new PaniMotion(42);
	table->mMotions[9]     = new PaniMotion(48);
	table->mMotions[10]    = new PaniMotion(21);
	table->mMotions[11]    = new PaniMotion(44);
	table->mMotions[12]    = new PaniMotion(45);
	table->mMotions[13]    = new PaniMotion(52);
	table->mMotions[14]    = new PaniMotion(53);
	table->mMotions[15]    = new PaniMotion(34);
	table->mMotions[17]    = new PaniMotion(39);
	table->mMotions[18]    = new PaniMotion(40);
	table->mMotions[19]    = new PaniMotion(41);
	table->mMotions[20]    = new PaniMotion(24);
	table->mMotions[21]    = new PaniMotion(9);
	table->mMotions[22]    = new PaniMotion(13);
	table->mMotions[23]    = new PaniMotion(18);
	table->mMotions[24]    = new PaniMotion(33);
	table->mMotions[25]    = new PaniMotion(94);
	table->mMotions[26]    = new PaniMotion(36);
	table->mMotions[27]    = new PaniMotion(54);
	table->mMotions[28]    = new PaniMotion(55);
	table->mMotions[29]    = new PaniMotion(56);
	table->mMotions[30]    = new PaniMotion(57);
	table->mMotions[31]    = new PaniMotion(58);
	table->mMotions[32]    = new PaniMotion(59);
	table->mMotions[33]    = new PaniMotion(60);
	table->mMotions[34]    = new PaniMotion(61);
	table->mMotions[35]    = new PaniMotion(62);
	table->mMotions[36]    = new PaniMotion(63);
	table->mMotions[37]    = new PaniMotion(64);
	table->mMotions[38]    = new PaniMotion(31);
	table->mMotions[39]    = new PaniMotion(10);
	table->mMotions[40]    = new PaniMotion(16);
	table->mMotions[41]    = new PaniMotion(3);
	table->mMotions[42]    = new PaniMotion(38);
	table->mMotions[43]    = new PaniMotion(47);
	table->mMotions[44]    = new PaniMotion(32);
	table->mMotions[45]    = new PaniMotion(66);
	table->mMotions[46]    = new PaniMotion(68);
	table->mMotions[47]    = new PaniMotion(67);
	table->mMotions[48]    = new PaniMotion(71);
	table->mMotions[49]    = new PaniMotion(74);
	table->mMotions[50]    = new PaniMotion(75);
	table->mMotions[51]    = new PaniMotion(76);
	table->mMotions[52]    = new PaniMotion(77);
	table->mMotions[53]    = new PaniMotion(78);
	table->mMotions[54]    = new PaniMotion(79);
	table->mMotions[55]    = new PaniMotion(80);
	table->mMotions[56]    = new PaniMotion(81);
	table->mMotions[57]    = new PaniMotion(82);
	table->mMotions[58]    = new PaniMotion(83);
	table->mMotions[59]    = new PaniMotion(84);
	table->mMotions[60]    = new PaniMotion(85);
	table->mMotions[61]    = new PaniMotion(86);
	table->mMotions[62]    = new PaniMotion(87);
	table->mMotions[63]    = new PaniMotion(88);
	table->mMotions[64]    = new PaniMotion(89);
	table->mMotions[65]    = new PaniMotion(90);
	table->mMotions[66]    = new PaniMotion(91);
	table->mMotions[67]    = new PaniMotion(92);
	table->mMotions[69]    = new PaniMotion(95);
	table->mMotions[70]    = new PaniMotion(8);
	table->mMotions[71]    = new PaniMotion(26);
	table->mMotions[16]    = new PaniMotion(35);
	table->mMotions[72]    = new PaniMotion(5);
	table->mMotions[73]    = new PaniMotion(6);
	table->mMotions[74]    = new PaniMotion(7);
	table->mMotions[75]    = new PaniMotion(14);
	table->mMotions[76]    = new PaniMotion(11);
	table->mMotions[77]    = new PaniMotion(17);
	table->mMotions[78]    = new PaniMotion(19);
	table->mMotions[79]    = new PaniMotion(27);
	table->mMotions[80]    = new PaniMotion(37);
	table->mMotions[81]    = new PaniMotion(22);
	table->mMotions[82]    = new PaniMotion(43);
	table->mMotions[83]    = new PaniMotion(93);
	table->mMotions[84]    = new PaniMotion(69);
	table->mMotions[85]    = new PaniMotion(72);
	table->mMotions[86]    = new PaniMotion(96);
	table->mMotions[87]    = new PaniMotion(97);
	table->mMotions[88]    = new PaniMotion(98);
	table->mMotions[89]    = new PaniMotion(99);
	return table;
}

/*
 * --INFO--
 * Address:	801199D4
 * Size:	00003C
 */
PaniPikiAnimator::PaniPikiAnimator() { }
