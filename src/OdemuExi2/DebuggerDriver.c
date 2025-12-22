#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include "types.h"

typedef void (*MTRCallbackType)(int);

static MTRCallbackType MTRCallback;
static void (*DBGCallback)(u32, OSContext*);

static u32 SendMailData;
static s32 RecvDataLeng;

static u8* pEXIInputFlag;
static u8 EXIInputFlag;

static u8 SendCount = 0x80;

#define IS_TRUE(x)         ((x) != FALSE)
#define IS_FALSE(x)        !IS_TRUE(x)
#define ROUND_UP(x, align) (((x) + (align) - 1) & (-(align)))

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void DBGEXIInit()
{
	__OSMaskInterrupts(0x18000);
	__EXIRegs[10] = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */

static u32 DBGEXISelect(u32 v)
{
	u32 regs = __EXIRegs[10];
	regs &= 0x405;
	regs |= 0x80 | (v << 4);
	__EXIRegs[10] = regs;
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
BOOL DBGEXIDeselect(void)
{
	__EXIRegs[10] &= 0x405;
	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
static BOOL DBGEXISync()
{
	while (__EXIRegs[13] & 1)
		;

	return TRUE;
}

/*
 * --INFO--
 * Address:	802214D8
 * Size:	000298
 */
static BOOL DBGEXIImm(void* buffer, s32 bytecounter, u32 write)
{
	u8* tempPointer;
	u32 writeOutValue;
	int i;

	if (write) {
		tempPointer   = buffer;
		writeOutValue = 0;
		for (i = 0; i < bytecounter; i++) {
			u8* temp = ((u8*)buffer) + i;
			writeOutValue |= *temp << ((3 - i) << 3);
		}
		__EXIRegs[14] = writeOutValue;
	}

	__EXIRegs[13] = 1 | write << 2 | (bytecounter - 1) << 4;
	DBGEXISync();

	if (!write) {
		writeOutValue = __EXIRegs[14];
		tempPointer   = buffer;
		for (i = 0; i < bytecounter; i++) {
			*tempPointer++ = writeOutValue >> ((3 - i) << 3);
		}
	}

	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void DBGEXIClearInterrupts(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void DBGCheckID(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
static BOOL DBGWriteMailbox(u32 p1)
{
	BOOL total = FALSE;
	u32 v;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	v = (p1 & 0x1fffffff) | (0xC0000000);
	total |= IS_FALSE(DBGEXIImm(&v, sizeof(v), 1));
	total |= IS_FALSE(DBGEXISync());
	total |= IS_FALSE(DBGEXIDeselect());

	return IS_FALSE(total);
}

/*
 * --INFO--
 * Address:	80221770
 * Size:	0000AC
 */
static BOOL DBGReadMailbox(u32* p1)
{
	BOOL total = FALSE;
	u32 v;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	v = 0x60000000;
	total |= IS_FALSE(DBGEXIImm(&v, 2, 1));
	total |= IS_FALSE(DBGEXISync());

	total |= IS_FALSE(DBGEXIImm(p1, 4, 0));
	total |= IS_FALSE(DBGEXISync());

	total |= IS_FALSE(DBGEXIDeselect());

	return IS_FALSE(total);
}

/*
 * --INFO--
 * Address:	8022181C
 * Size:	0000DC
 */
static BOOL DBGRead(u32 count, u32* buffer, s32 param3)
{
	BOOL total = FALSE;
	u32* buf_p = (u32*)buffer;
	u32 v1;
	u32 v;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	v1 = (count & 0x1fffc) << 8 | 0x20000000;
	total |= IS_FALSE(DBGEXIImm(&v1, sizeof(v1), 1));
	total |= IS_FALSE(DBGEXISync());

	while (param3) {
		total |= IS_FALSE(DBGEXIImm(&v, sizeof(v), 0));
		total |= IS_FALSE(DBGEXISync());

		*buf_p++ = v;

		param3 -= 4;
		if (param3 < 0) {
			param3 = 0;
		}
	}

	total |= IS_FALSE(DBGEXIDeselect());
	return IS_FALSE(total);
}

/*
 * --INFO--
 * Address:	802218F8
 * Size:	0000DC
 */
static BOOL DBGWrite(u32 count, void* buffer, s32 param3)
{
	BOOL total = FALSE;
	u32* buf_p = (u32*)buffer;
	u32 v1;
	u32 v;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	v1 = (count & 0x1fffc) << 8 | 0xa0000000;
	total |= IS_FALSE(DBGEXIImm(&v1, sizeof(v1), 1));
	total |= IS_FALSE(DBGEXISync());

	while (param3 != 0) {
		v = *buf_p++;

		total |= IS_FALSE(DBGEXIImm(&v, sizeof(v), 1));
		total |= IS_FALSE(DBGEXISync());

		param3 -= 4;
		if (param3 < 0) {
			param3 = 0;
		}
	}

	total |= IS_FALSE(DBGEXIDeselect());
	return IS_FALSE(total);
}

/*
 * --INFO--
 * Address:	802219D4
 * Size:	0000AC
 */
static BOOL DBGReadStatus(u32* p1)
{
	BOOL total = FALSE;
	u32 v;

	if (!DBGEXISelect(4)) {
		return FALSE;
	}

	v = 1 << 30;
	total |= IS_FALSE(DBGEXIImm((u8*)&v, 2, 1));
	total |= IS_FALSE(DBGEXISync());

	total |= IS_FALSE(DBGEXIImm(p1, 4, 0));
	total |= IS_FALSE(DBGEXISync());

	total |= IS_FALSE(DBGEXIDeselect());

	return IS_FALSE(total);
}

/*
 * --INFO--
 * Address:	80221A80
 * Size:	00003C
 */
static void MWCallback(u32 a, OSContext* b)
{
	EXIInputFlag = TRUE;
	if (MTRCallback) {
		MTRCallback(0);
	}
}

/*
 * --INFO--
 * Address:	80221ABC
 * Size:	000040
 */
static void DBGHandler(s16 a, OSContext* b)
{
	*__PIRegs = 0x1000;
	if (DBGCallback) {
		DBGCallback(a, b);
	}
}

/*
 * --INFO--
 * Address:	80221AFC
 * Size:	000078
 */
void DBInitComm(u8** a, MTRCallbackType b)
{
	BOOL interrupts = OSDisableInterrupts();
	{
		pEXIInputFlag = (u8*)EXIInputFlag;
		pEXIInputFlag = &EXIInputFlag;

		*a = pEXIInputFlag;

		MTRCallback = b;

		DBGEXIInit();
	}
	OSRestoreInterrupts(interrupts);
}

/*
 * --INFO--
 * Address:	80221B74
 * Size:	000054
 */
void DBInitInterrupts(void)
{
	__OSMaskInterrupts(0x18000);
	__OSMaskInterrupts(0x40);
	DBGCallback = &MWCallback;
	__OSSetInterruptHandler(0x19, DBGHandler);
	__OSUnmaskInterrupts(0x40);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
static void CheckMailBox(void)
{
	u32 v;
	DBGReadStatus(&v);
	if (v & 1) {
		DBGReadMailbox(&v);
		v &= 0x1fffffff;

		if ((v & 0x1f000000) == 0x1f000000) {
			SendMailData = v;
			RecvDataLeng = v & 0x7fff;
			EXIInputFlag = 1;
		}
	}
}

/*
 * --INFO--
 * Address:	80221BC8
 * Size:	00009C
 */
u32 DBQueryData(void)
{
	BOOL interrupts;

	EXIInputFlag = 0;
	if (!RecvDataLeng) {
		interrupts = OSDisableInterrupts();
		CheckMailBox();
	}
	OSRestoreInterrupts(interrupts);
	return RecvDataLeng;
}

/*
 * --INFO--
 * Address:	80221C64
 * Size:	00008C
 */
BOOL DBRead(u32* buffer, s32 count)
{
	u32 interrupts = OSDisableInterrupts();
	u32 v          = SendMailData & 0x10000 ? 0x1000 : 0;

	DBGRead(v + 0x1e000, buffer, ROUND_UP(count, 4));

	RecvDataLeng = 0;
	EXIInputFlag = 0;

	OSRestoreInterrupts(interrupts);

	return 0;
}

/*
 * --INFO--
 * Address:	80221CF0
 * Size:	000260
 */
BOOL DBWrite(const void* src, u32 size)
{
	u32 v;
	u32 busyFlag;
	BOOL interrupts;

	interrupts = OSDisableInterrupts();

	do {
		DBGReadStatus(&busyFlag);
	} while (busyFlag & 2);

	SendCount++;
	v = ((SendCount & 1) ? 0x1000 : 0);

	while (!DBGWrite(v | 0x1c000, (u32*)src, ROUND_UP(size, 4)))
		;

	do {
		DBGReadStatus(&busyFlag);
	} while (busyFlag & 2);

	v = (SendCount << 0x10) | 0x1F000000 | size;
	while (!DBGWriteMailbox(v))
		;

	do {
		while (!DBGReadStatus(&busyFlag))
			;
	} while (busyFlag & 2);

	OSRestoreInterrupts(interrupts);

	return 0;
}

/*
 * --INFO--
 * Address:	80221F50
 * Size:	000004
 */
void DBOpen(void)
{
	return;
}

void DBClose(void)
{
	return;
}
