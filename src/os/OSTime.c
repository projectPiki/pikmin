#include "Dolphin/os.h"

#define OS_TIME_MONTH_MAX    12
#define OS_TIME_WEEK_DAY_MAX 7
#define OS_TIME_YEAR_DAY_MAX 365
#define BIAS                 (2000 * 365 + (2000 + 3) / 4 - (2000 - 1) / 100 + (2000 - 1) / 400)

// End of each month in standard year
static s32 YearDays[OS_TIME_MONTH_MAX] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
// End of each month in leap year
static s32 LeapYearDays[OS_TIME_MONTH_MAX] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

/*
 * --INFO--
 * Address:	801FD3A0
 * Size:	000018
 */
ASM OSTime OSGetTime(void) {
#ifdef __MWERKS__ // clang-format off
	nofralloc

	mftbu r3
	mftb r4

	// Check for possible carry from TBL to TBU
	mftbu r5
	cmpw r3, r5
	bne OSGetTime

	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	801FD3B8
 * Size:	000008
 */
ASM u32 OSGetTick(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc

	mftb r3
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void __SetTime(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void __OSSetTime(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FD3C0
 * Size:	000064
 */
OSTime __OSGetSystemTime(void)
{
	BOOL enabled;
	OSTime* timeAdjustAddr = (OSTime*)(OSPhysicalToCached(0x30D8));
	OSTime result;

	enabled = OSDisableInterrupts();
	result  = *timeAdjustAddr + OSGetTime();
	OSRestoreInterrupts(enabled);

	return result;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void __OSSetTick(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
static BOOL IsLeapYear(s32 year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void GetYearDays(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
static s32 GetLeapDays(s32 year)
{
	if (year < 1) {
		return 0;
	}
	return (year + 3) / 4 - (year - 1) / 100 + (year - 1) / 400;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FD424
 * Size:	00019C
 */
static void GetDates(s32 days, OSCalendarTime* cal)
{
	s32 year;
	s32 totalDays;
	s32* p_days;
	s32 month;
	cal->wday = (days + 6) % OS_TIME_WEEK_DAY_MAX;

	for (year = days / OS_TIME_YEAR_DAY_MAX; days < (totalDays = year * OS_TIME_YEAR_DAY_MAX + GetLeapDays(year));) {
		year--;
	}

	days -= totalDays;
	cal->year = year;
	cal->yday = days;

	p_days = IsLeapYear(year) ? LeapYearDays : YearDays;
	month  = OS_TIME_MONTH_MAX;
	while (days < p_days[--month]) {
		;
	}
	cal->mon  = month;
	cal->mday = days - p_days[month] + 1;
	/*
	.loc_0x0:
	  lis       r5, 0x9249
	  addi      r0, r5, 0x2493
	  addi      r7, r3, 0x6
	  mulhw     r6, r0, r7
	  lis       r5, 0xB38D
	  subi      r0, r5, 0x64F
	  mulhw     r0, r0, r3
	  add       r5, r6, r7
	  srawi     r5, r5, 0x2
	  rlwinm    r6,r5,1,31,31
	  add       r5, r5, r6
	  add       r0, r0, r3
	  mulli     r6, r5, 0x7
	  srawi     r0, r0, 0x8
	  rlwinm    r5,r0,1,31,31
	  add       r5, r0, r5
	  sub       r0, r7, r6
	  mulli     r11, r5, 0x16D
	  stw       r0, 0x18(r4)
	  b         .loc_0x50

	.loc_0x50:
	  lis       r6, 0x51EC
	  subi      r10, r6, 0x7AE1
	  b         .loc_0x5C

	.loc_0x5C:
	  b         .loc_0x68

	.loc_0x60:
	  subi      r11, r11, 0x16D
	  subi      r5, r5, 0x1

	.loc_0x68:
	  cmpwi     r5, 0x1
	  bge-      .loc_0x78
	  li        r0, 0
	  b         .loc_0xAC

	.loc_0x78:
	  subi      r0, r5, 0x1
	  mulhw     r0, r10, r0
	  srawi     r8, r0, 0x7
	  srawi     r6, r0, 0x5
	  addi      r0, r5, 0x3
	  rlwinm    r7,r6,1,31,31
	  srawi     r0, r0, 0x2
	  rlwinm    r9,r8,1,31,31
	  add       r6, r6, r7
	  addze     r0, r0
	  add       r7, r8, r9
	  sub       r0, r0, r6
	  add       r0, r7, r0

	.loc_0xAC:
	  add       r0, r11, r0
	  cmpw      r3, r0
	  blt+      .loc_0x60
	  srawi     r6, r5, 0x2
	  stw       r5, 0x14(r4)
	  addze     r6, r6
	  rlwinm    r6,r6,2,0,29
	  subc      r6, r5, r6
	  sub       r0, r3, r0
	  cmpwi     r6, 0
	  stw       r0, 0x1C(r4)
	  li        r7, 0x1
	  li        r8, 0
	  bne-      .loc_0x110
	  lis       r3, 0x51EC
	  subi      r3, r3, 0x7AE1
	  mulhw     r3, r3, r5
	  srawi     r3, r3, 0x5
	  rlwinm    r6,r3,1,31,31
	  add       r3, r3, r6
	  mulli     r3, r3, 0x64
	  sub       r3, r5, r3
	  cmpwi     r3, 0
	  beq-      .loc_0x110
	  mr        r8, r7

	.loc_0x110:
	  cmpwi     r8, 0
	  bne-      .loc_0x144
	  lis       r3, 0x51EC
	  subi      r3, r3, 0x7AE1
	  mulhw     r3, r3, r5
	  srawi     r3, r3, 0x7
	  rlwinm    r6,r3,1,31,31
	  add       r3, r3, r6
	  mulli     r3, r3, 0x190
	  sub       r3, r5, r3
	  cmpwi     r3, 0
	  beq-      .loc_0x144
	  li        r7, 0

	.loc_0x144:
	  cmpwi     r7, 0
	  beq-      .loc_0x158
	  lis       r3, 0x802F
	  subi      r6, r3, 0x7BE8
	  b         .loc_0x160

	.loc_0x158:
	  lis       r3, 0x802F
	  subi      r6, r3, 0x7C18

	.loc_0x160:
	  li        r7, 0xC
	  li        r3, 0x30
	  b         .loc_0x16C

	.loc_0x16C:
	  b         .loc_0x170

	.loc_0x170:
	  subi      r3, r3, 0x4
	  lwzx      r5, r6, r3
	  subi      r7, r7, 0x1
	  cmpw      r0, r5
	  blt+      .loc_0x170
	  stw       r7, 0x10(r4)
	  lwzx      r3, r6, r3
	  sub       r3, r0, r3
	  addi      r0, r3, 0x1
	  stw       r0, 0xC(r4)
	  blr
	*/
}

#pragma dont_inline on

/*
 * --INFO--
 * Address:	801FD5C0
 * Size:	000204
 */
void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime* cal)
{
	int days;
	int secs;
	OSTime d;

	d = ticks % OSSecondsToTicks(1);
	if (d < 0) {
		d += OSSecondsToTicks(1);
	}
	cal->usec = (int)(OSTicksToMicroseconds(d) % 1000);
	cal->msec = (int)(OSTicksToMilliseconds(d) % 1000);

	ticks -= d;
	days = (int)(OSTicksToSeconds(ticks) / 86400 + BIAS);
	secs = (int)(OSTicksToSeconds(ticks) % 86400);
	if (secs < 0) {
		days -= 1;
		secs += 24 * 60 * 60;
	}

	GetDates(days, cal);

	cal->hour = secs / 60 / 60;
	cal->min  = (secs / 60) % 60;
	cal->sec  = secs % 60;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r25, 0x1C(r1)
	  mr        r29, r3
	  mr        r30, r4
	  mr        r31, r5
	  lis       r27, 0x8000
	  lwz       r0, 0xF8(r27)
	  mr        r3, r29
	  mr        r4, r30
	  rlwinm    r6,r0,30,2,31
	  li        r5, 0
	  bl        0x17BD0
	  mr        r26, r3
	  li        r5, 0
	  mr        r25, r4
	  xoris     r4, r26, 0x8000
	  xoris     r3, r5, 0x8000
	  subc      r0, r25, r5
	  subfe     r3, r3, r4
	  subfe     r3, r4, r4
	  neg       r3, r3
	  cmpwi     r3, 0
	  beq-      .loc_0x74
	  lwz       r0, 0xF8(r27)
	  rlwinm    r0,r0,30,2,31
	  addc      r25, r25, r0
	  adde      r26, r26, r5

	.loc_0x74:
	  li        r4, 0x8
	  mullw     r3, r26, r4
	  mulhwu    r0, r25, r4
	  lis       r27, 0x8000
	  lwz       r6, 0xF8(r27)
	  lis       r5, 0x431C
	  subi      r5, r5, 0x217D
	  rlwinm    r6,r6,30,2,31
	  mulhwu    r5, r5, r6
	  rlwinm    r6,r5,17,15,31
	  li        r28, 0
	  add       r3, r3, r0
	  mullw     r0, r25, r28
	  mullw     r4, r25, r4
	  add       r3, r3, r0
	  li        r5, 0
	  bl        0x17934
	  li        r5, 0
	  li        r6, 0x3E8
	  bl        0x17B44
	  stw       r4, 0x24(r31)
	  lis       r3, 0x1062
	  addi      r5, r3, 0x4DD3
	  lwz       r0, 0xF8(r27)
	  mr        r3, r26
	  mr        r4, r25
	  rlwinm    r0,r0,30,2,31
	  mulhwu    r0, r5, r0
	  rlwinm    r6,r0,26,6,31
	  li        r5, 0
	  bl        0x178FC
	  li        r5, 0
	  li        r6, 0x3E8
	  bl        0x17B0C
	  stw       r4, 0x20(r31)
	  subc      r30, r30, r25
	  subfe     r29, r26, r29
	  lwz       r0, 0xF8(r27)
	  lis       r5, 0x1
	  addi      r25, r5, 0x5180
	  mr        r3, r29
	  rlwinm    r6,r0,30,2,31
	  mr        r4, r30
	  li        r5, 0
	  bl        0x178C4
	  mr        r6, r25
	  li        r5, 0
	  bl        0x178B8
	  lis       r5, 0xB
	  lwz       r0, 0xF8(r27)
	  addi      r5, r5, 0x2575
	  addc      r26, r4, r5
	  rlwinm    r6,r0,30,2,31
	  adde      r0, r3, r28
	  mr        r3, r29
	  mr        r4, r30
	  li        r5, 0
	  bl        0x17890
	  mr        r6, r25
	  li        r5, 0
	  bl        0x17AA0
	  mr        r27, r4
	  cmpwi     r27, 0
	  bge-      .loc_0x180
	  addis     r27, r27, 0x1
	  subi      r26, r26, 0x1
	  addi      r27, r27, 0x5180

	.loc_0x180:
	  mr        r3, r26
	  mr        r4, r31
	  bl        -0x324
	  lis       r3, 0x8889
	  subi      r5, r3, 0x7777
	  mulhw     r0, r5, r27
	  add       r4, r0, r27
	  srawi     r0, r4, 0x5
	  rlwinm    r3,r0,1,31,31
	  add       r7, r0, r3
	  mulhw     r0, r5, r7
	  add       r0, r0, r7
	  srawi     r5, r0, 0x5
	  srawi     r0, r0, 0x5
	  rlwinm    r3,r0,1,31,31
	  add       r3, r0, r3
	  srawi     r0, r4, 0x5
	  rlwinm    r6,r5,1,31,31
	  mulli     r4, r3, 0x3C
	  rlwinm    r3,r0,1,31,31
	  add       r5, r5, r6
	  add       r0, r0, r3
	  stw       r5, 0x8(r31)
	  mulli     r0, r0, 0x3C
	  sub       r3, r7, r4
	  stw       r3, 0x4(r31)
	  sub       r0, r27, r0
	  stw       r0, 0x0(r31)
	  lmw       r25, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

#pragma dont_inline reset

/*
 * --INFO--
 * Address:	........
 * Size:	0002E0
 */
OSTime OSCalendarTimeToTicks(OSCalendarTime*)
{
	// UNUSED FUNCTION
}
