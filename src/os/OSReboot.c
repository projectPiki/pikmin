#include "Dolphin/os.h"
#include "Dolphin/ai.h"

static BOOL Prepared;

extern u32 BOOT_REGION_START AT_ADDRESS(0x812FDFF0); //(*(u32 *)0x812fdff0)
extern u32 BOOT_REGION_END AT_ADDRESS(0x812FDFEC);   //(*(u32 *)0x812fdfec)
extern u32 OS_RESET_CODE AT_ADDRESS(0x800030F0);
extern u8 OS_REBOOT_BOOL AT_ADDRESS(0x800030E2); // unknown function, set to true by __OSReboot

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
static void Run(register u32 addr)
{
	OSDisableInterrupts();
	ICFlashInvalidate();
#ifdef __MWERKS__ // clang-format off
	asm {
	sync
	isync
	mtlr addr
	blr
	}
#endif // clang-format on
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void ReadApploader(OSTime time1)
{
	if (!DVDCheckDisk() || OSGetTime() - time1 > OS_TIMER_CLOCK) {
		__OSDoHotReset(0);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F9F04
 * Size:	00000C
 */
static void Callback(void)
{
	Prepared = TRUE;
	/*
	.loc_0x0:
	  li        r0, 0x1
	  stw       r0, 0x3200(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F9F10
 * Size:	0001B0
 */
void __OSReboot(u32 resetCode, u32 bootDol)
{
	OSContext exceptionContext;
	OSTime time1;
	DVDCommandBlock dvdCmd;
	DVDCommandBlock dvdCmd2;
	DVDCommandBlock dvdCmd3;
	u32 numBytes;
	u32 offset;
	OSDisableInterrupts();
	BOOT_REGION_START = resetCode;
	BOOT_REGION_END   = 0;
	OS_REBOOT_BOOL    = TRUE;
	OSClearContext(&exceptionContext);
	OSSetCurrentContext(&exceptionContext);
	DVDInit();

	__DVDPrepareResetAsync(Callback);

	if (DVDCheckDisk() == FALSE) {
		__OSDoHotReset(OS_RESET_CODE);
	}

	__OSMaskInterrupts(-0x20);
	__OSUnmaskInterrupts(0x400);
	OSEnableInterrupts();

	time1 = OSGetTime();
	while (Prepared != TRUE) {
		ReadApploader(time1);
	};

	if (!__OSIsGcam) {
		// if (IsStreamEnabled()) {
		AISetStreamVolLeft(0);
		AISetStreamVolRight(0);
		DVDCancelStreamAsync(&dvdCmd, nullptr);
		time1 = OSGetTime();
		while (DVDGetCommandBlockStatus(&dvdCmd)) {
			ReadApploader(time1);
		}

		AISetStreamPlayState(0);
		// }
	}

	DVDReadAbsAsyncPrio(&dvdCmd2, Header.date, 32, 0x2440, nullptr, 0);

	time1 = OSGetTime();
	while (DVDGetCommandBlockStatus(&dvdCmd2)) {
		ReadApploader(time1);
	}

	offset   = Header.size + 0x20;
	numBytes = OSRoundUp32B(Header.rebootSize);
	DVDReadAbsAsyncPrio(&dvdCmd3, (void*)(OS_BOOTROM_ADDR), numBytes, offset + 0x2440, nullptr, 0);

	time1 = OSGetTime();
	while (DVDGetCommandBlockStatus(&dvdCmd3)) {
		ReadApploader(time1);
	}

	ICInvalidateRange((void*)(OS_BOOTROM_ADDR), numBytes);
	Run(OS_BOOTROM_ADDR);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x348(r1)
	  stw       r31, 0x344(r1)
	  stw       r30, 0x340(r1)
	  stw       r29, 0x33C(r1)
	  mr        r29, r3
	  lis       r3, 0x803D
	  addi      r30, r3, 0x24A0
	  bl        -0xFB8
	  lis       r31, 0x8180
	  li        r3, 0
	  stw       r29, -0x4(r31)
	  li        r0, 0x1
	  lis       r4, 0x8000
	  stw       r3, -0x8(r31)
	  addi      r3, r1, 0x70
	  stb       r0, 0x30E2(r4)
	  bl        -0x2B1C
	  addi      r3, r1, 0x70
	  bl        -0x2CEC
	  bl        0x5A00
	  lis       r3, 0x8020
	  subi      r3, r3, 0x60FC
	  bl        0x7E78
	  bl        0x7D90
	  cmpwi     r3, 0
	  bne-      .loc_0x78
	  lwz       r3, -0x4(r31)
	  bl        0x230

	.loc_0x78:
	  li        r3, -0x20
	  bl        -0xC70
	  li        r3, 0x400
	  bl        -0xBF0
	  bl        -0x1008
	  b         .loc_0x90

	.loc_0x90:
	  b         .loc_0x94

	.loc_0x94:
	  lwz       r0, 0x3200(r13)
	  cmpwi     r0, 0
	  beq+      .loc_0x94
	  mr        r4, r30
	  addi      r3, r1, 0x40
	  li        r5, 0x20
	  li        r6, 0x2440
	  li        r7, 0
	  bl        0x75D8
	  lis       r31, 0x8180
	  b         .loc_0xC0

	.loc_0xC0:
	  b         .loc_0xC4

	.loc_0xC4:
	  lwz       r0, 0x4C(r1)
	  cmpwi     r0, 0x1
	  beq+      .loc_0xC4
	  bge-      .loc_0xE4
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF0
	  bge-      .loc_0xFC
	  b         .loc_0xC4

	.loc_0xE4:
	  cmpwi     r0, 0xC
	  bge+      .loc_0xC4
	  b         .loc_0xF0

	.loc_0xF0:
	  lwz       r3, -0x4(r31)
	  bl        0x1B0
	  b         .loc_0xC4

	.loc_0xFC:
	  lwz       r3, 0x18(r30)
	  lwz       r4, 0x14(r30)
	  addi      r0, r3, 0x1F
	  addi      r4, r4, 0x20
	  rlwinm    r30,r0,0,0,26
	  b         .loc_0x114

	.loc_0x114:
	  b         .loc_0x118

	.loc_0x118:
	  lwz       r0, 0x3200(r13)
	  cmpwi     r0, 0
	  beq+      .loc_0x118
	  mr        r5, r30
	  addi      r3, r1, 0x10
	  addi      r6, r4, 0x2440
	  lis       r4, 0x8130
	  li        r7, 0
	  bl        0x7554
	  lis       r31, 0x8180
	  b         .loc_0x144

	.loc_0x144:
	  b         .loc_0x148

	.loc_0x148:
	  lwz       r0, 0x1C(r1)
	  cmpwi     r0, 0x1
	  beq+      .loc_0x148
	  bge-      .loc_0x168
	  cmpwi     r0, -0x1
	  beq-      .loc_0x174
	  bge-      .loc_0x180
	  b         .loc_0x148

	.loc_0x168:
	  cmpwi     r0, 0xC
	  bge+      .loc_0x148
	  b         .loc_0x174

	.loc_0x174:
	  lwz       r3, -0x4(r31)
	  bl        0x12C
	  b         .loc_0x148

	.loc_0x180:
	  lis       r3, 0x8130
	  mr        r4, r30
	  bl        -0x33B8
	  lis       r3, 0x8130
	  bl        -0x1DC
	  lwz       r0, 0x34C(r1)
	  lwz       r31, 0x344(r1)
	  lwz       r30, 0x340(r1)
	  mtlr      r0
	  lwz       r29, 0x33C(r1)
	  addi      r1, r1, 0x348
	  blr
	*/
}
