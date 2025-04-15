#include "Dolphin/os.h"
#include "Dolphin/ai.h"

static volatile BOOL Prepared;

extern void* BOOT_REGION_START AT_ADDRESS(0x812FDFF0);
extern void* BOOT_REGION_END AT_ADDRESS(0x812FDFEC);
extern u32 OS_RESET_CODE AT_ADDRESS(0x800030F0);
// unknown function, set to true by __OSReboot
extern u8 OS_REBOOT_BOOL AT_ADDRESS(0x800030E2);
extern u32 OS_UNK_CODE AT_ADDRESS(0x817FFFF8);
extern u32 OS_HOT_RESET_CODE AT_ADDRESS(0x817FFFFC);

extern void* __OSSavedRegionStart;
extern void* __OSSavedRegionEnd;

// Struct for Apploader header (size 0x20).
typedef struct _ApploaderHeader {
	char date[16];  // _00
	u32 entry;      // _10
	u32 size;       // _14
	u32 rebootSize; // _18
	u32 reserved2;  // _1C
} ApploaderHeader;

static ApploaderHeader Header ATTRIBUTE_ALIGN(32);

/*
 * --INFO--
 * Address:	801F9EC4
 * Size:	000040
 */
static ASM void Run(register u32 addr)
{
#ifdef __MWERKS__ // clang-format off
	fralloc
	bl OSDisableInterrupts
	bl ICFlashInvalidate
	sync
	isync
	mtlr addr
	blr
	frfree
	blr
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
static void ReadApploader(DVDCommandBlock* dvdCmd, void* addr, u32 offset, u32 numBytes)
{
	while (Prepared == FALSE) { }
	DVDReadAbsAsyncForBS(dvdCmd, addr, numBytes, offset + 0x2440, NULL);

	while (TRUE) {
		switch (dvdCmd->state) {
		case 0:
			break;
		case 1:
		default:
			continue;
		case -1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			__OSDoHotReset(OS_HOT_RESET_CODE);
			continue;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	801F9F04
 * Size:	00000C
 */
static void Callback(s32 result, struct DVDCommandBlock* block)
{
	Prepared = TRUE;
}

/*
 * --INFO--
 * Address:	801F9F10
 * Size:	0001B0
 */
void __OSReboot(u32 resetCode, u32 bootDol)
{
	OSContext exceptionContext;
	DVDCommandBlock dvdCmd;
	DVDCommandBlock dvdCmd2;
	u32 numBytes;
	u32 offset;

	OSDisableInterrupts();

	OS_HOT_RESET_CODE = resetCode;
	OS_UNK_CODE       = 0;
	OS_REBOOT_BOOL    = TRUE;
	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);
	DVDInit();

	__DVDPrepareResetAsync(Callback);

	if (!DVDCheckDisk()) {
		__OSDoHotReset(OS_HOT_RESET_CODE);
	}

	__OSMaskInterrupts(0xffffffe0);
	__OSUnmaskInterrupts(0x400);

	OSEnableInterrupts();

	offset   = 0;
	numBytes = 32;
	ReadApploader(&dvdCmd, (void*)&Header, offset, numBytes);

	offset   = Header.size + 0x20;
	numBytes = OSRoundUp32B(Header.rebootSize);
	ReadApploader(&dvdCmd2, (void*)OS_BOOTROM_ADDR, offset, numBytes);

	ICInvalidateRange((void*)OS_BOOTROM_ADDR, numBytes);
	Run(OS_BOOTROM_ADDR);
}
