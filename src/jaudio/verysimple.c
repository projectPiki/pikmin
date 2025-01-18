#include "jaudio/verysimple.h"
#include "Dolphin/os.h"

typedef struct seqp_ seqp_;

static BOOL cmdqueue_reset;
static u32 countdown_count;  // TODO: type uncertain
static u32 pausemode;        // TODO: type uncertain
static u32 container;        // TODO: type uncertain
static u32 sys_voldown_flag; // TODO: type uncertain
static BOOL boot_ok;
static u32 count; // TODO: type uncertain
static u8* lend_buffer;

// forward declared statics
static void __ResetCounter();

/*
 * --INFO--
 * Address:	80016A60
 * Size:	00006C
 */
static BOOL InitQueue()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x1
	  stw       r0, 0x4(r1)
	  addi      r3, r3, 0x9
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  bl        -0x6418
	  mr.       r31, r3
	  bne-      .loc_0x2C
	  li        r3, 0
	  b         .loc_0x58

	.loc_0x2C:
	  lis       r3, 0x8036
	  addi      r4, r31, 0
	  addi      r3, r3, 0x36F0
	  li        r5, 0
	  bl        0x4F04
	  lis       r3, 0x8036
	  addi      r4, r31, 0
	  addi      r3, r3, 0x375C
	  li        r5, 0x1
	  bl        0x4EF0
	  li        r3, 0x1

	.loc_0x58:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80016AE0
 * Size:	00000C
 */
void Jac_StopSe(s32)
{
	if (cmdqueue_reset) {
		(cmdqueue_reset != 0);
	}
}

/*
 * --INFO--
 * Address:	80016B00
 * Size:	000010
 */
BOOL Jac_PauseCheck()
{
	return pausemode | container;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void Jac_UpdateRocketParam(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80016B20
 * Size:	000068
 */
void Jac_SysSEDemoFadeCheck()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2C64(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  cmplwi    r3, 0x1
	  bne-      .loc_0x50
	  li        r3, 0
	  li        r4, 0x5
	  bl        0x6898
	  cmpwi     r3, 0
	  bne-      .loc_0x58
	  lfs       f1, -0x7E78(r2)
	  li        r3, 0
	  li        r4, 0x64
	  bl        0x2AA0
	  li        r0, 0
	  stw       r0, 0x2C64(r13)
	  b         .loc_0x58

	.loc_0x50:
	  subi      r0, r3, 0x1
	  stw       r0, 0x2C64(r13)

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80016BA0
 * Size:	0003A0
 */
void Jac_PlaySystemSe()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x2C54(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x34
	  bl        -0x160
	  stw       r3, 0x2C54(r13)
	  lwz       r0, 0x2C54(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x38C

	.loc_0x34:
	  subi      r0, r31, 0x3
	  cmplwi    r0, 0x25
	  bgt-      .loc_0x370
	  lis       r3, 0x8022
	  rlwinm    r0,r0,2,0,29
	  addi      r3, r3, 0x5950
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r3, 0xE
	  bl        0x17A4
	  b         .loc_0x38C
	  bl        0x357C
	  cmpwi     r3, 0x1
	  beq-      .loc_0x38C
	  bl        -0x110
	  cmpwi     r3, 0x1
	  beq-      .loc_0x38C
	  bl        0x2C24
	  cmplwi    r3, 0x5
	  beq-      .loc_0x370
	  b         .loc_0x38C
	  lwz       r3, 0x2C58(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2C58(r13)
	  lwz       r0, 0x2C58(r13)
	  cmplwi    r0, 0xA
	  bne-      .loc_0x370
	  li        r3, 0
	  li        r4, 0x3C
	  bl        0x1EF4
	  li        r3, 0x1
	  li        r4, 0x3C
	  bl        0x1EE8
	  b         .loc_0x370
	  li        r3, 0
	  li        r4, 0x2
	  li        r5, 0x1
	  bl        0x22D4
	  b         .loc_0x370
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        0x22C0
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        0x22B0
	  li        r0, 0x1
	  li        r3, 0
	  stw       r0, 0x2C60(r13)
	  li        r4, 0
	  bl        0x155C
	  bl        0x1958
	  lis       r3, 0x2
	  bl        -0x6650
	  li        r4, 0x1
	  bl        -0x57D8
	  b         .loc_0x370
	  lwz       r0, 0x2C60(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38C
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x2268
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x2258
	  li        r0, 0
	  lis       r3, 0x2
	  stw       r0, 0x2C60(r13)
	  bl        -0x6698
	  li        r4, 0x1
	  bl        -0x56E0
	  bl        0x193C
	  li        r3, 0x23
	  bl        .loc_0x3A0
	  li        r3, 0x21
	  bl        .loc_0x3A0
	  b         .loc_0x370
	  b         .loc_0x38C
	  lwz       r0, 0x2C60(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x1CC
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        0x2208
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        0x21F8
	  lis       r3, 0x2
	  bl        -0x66F0
	  li        r4, 0x1
	  bl        -0x5878
	  bl        0x18A4
	  li        r3, 0
	  li        r4, 0
	  bl        0x1498

	.loc_0x1CC:
	  li        r0, 0x1
	  stw       r0, 0x2C5C(r13)
	  b         .loc_0x370
	  lwz       r0, 0x2C5C(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x230
	  lwz       r0, 0x2C60(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x224
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x21A4
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x2194
	  lis       r3, 0x2
	  bl        -0x6754
	  li        r4, 0x1
	  bl        -0x579C
	  bl        0x1880

	.loc_0x224:
	  li        r0, 0
	  stw       r0, 0x2C5C(r13)
	  b         .loc_0x370

	.loc_0x230:
	  li        r0, 0
	  stw       r0, 0x2C58(r13)
	  stw       r0, 0x2C64(r13)
	  b         .loc_0x38C
	  li        r3, 0xD
	  li        r4, 0x6
	  bl        -0xA708
	  li        r3, 0x8
	  bl        0x3670
	  b         .loc_0x38C
	  lwz       r0, 0x2C64(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x274
	  lfs       f1, -0x7E74(r2)
	  li        r3, 0x1
	  li        r4, 0x5
	  bl        0x27F0

	.loc_0x274:
	  li        r3, 0x5
	  bl        0x3208
	  li        r0, 0x14
	  stw       r0, 0x2C64(r13)
	  b         .loc_0x38C
	  lis       r3, 0x2
	  bl        -0x67CC
	  li        r4, 0x1
	  bl        -0x5954
	  lis       r3, 0x1
	  addi      r3, r3, 0xF
	  bl        -0x67E0
	  li        r4, 0x1
	  bl        -0x5968
	  bl        0x17B4
	  li        r3, 0
	  li        r4, 0
	  bl        0x13A8
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        0x20D8
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x1
	  bl        0x20C8
	  li        r3, 0
	  li        r4, 0x1
	  bl        0x6A9C
	  li        r31, 0x1C
	  b         .loc_0x370
	  lis       r3, 0x2
	  bl        -0x6834
	  li        r4, 0x1
	  bl        -0x587C
	  lis       r3, 0x1
	  addi      r3, r3, 0xF
	  bl        -0x6848
	  li        r4, 0x1
	  bl        -0x5890
	  bl        0x178C
	  li        r3, 0
	  li        r4, 0
	  bl        0x6A60
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x2070
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x2060
	  b         .loc_0x38C
	  lis       r3, 0x2
	  bl        -0x688C
	  li        r4, 0x1
	  bl        -0x5A14
	  li        r3, 0
	  li        r4, 0
	  bl        0x1300
	  li        r0, 0x1
	  stw       r0, 0x2C5C(r13)
	  b         .loc_0x38C

	.loc_0x370:
	  lwz       r0, 0x2C54(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38C
	  lis       r3, 0x8036
	  rlwinm    r4,r31,0,16,31
	  addi      r3, r3, 0x36F0
	  bl        0x4AD8

	.loc_0x38C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x3A0:
	*/
}

/*
 * --INFO--
 * Address:	80016F40
 * Size:	000070
 */
void Jac_StopSystemSe(s32 p1)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x2C54(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x28
	  bl        -0x500
	  stw       r3, 0x2C54(r13)

	.loc_0x28:
	  cmpwi     r31, 0x10
	  beq-      .loc_0x34
	  b         .loc_0x40

	.loc_0x34:
	  li        r3, 0xE
	  bl        0x1708
	  b         .loc_0x5C

	.loc_0x40:
	  lwz       r0, 0x2C54(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x5C
	  lis       r3, 0x8036
	  rlwinm    r4,r31,0,16,31
	  addi      r3, r3, 0x375C
	  bl        0x4A68

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Jac_PlaySe(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80016FC0
 * Size:	000050
 */
static void Jac_PlayInit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x322C
	  bl        0x5130
	  bl        -0xA054
	  lis       r3, 0x8022
	  lis       r4, 0x8022
	  addi      r3, r3, 0x2118
	  addi      r4, r4, 0x6FE0
	  li        r5, 0
	  bl        0x43F4
	  bl        0x19D0
	  lis       r3, 0x8022
	  addi      r3, r3, 0x212C
	  bl        0x69A4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017020
 * Size:	000004
 */
static void Jac_Archiver_Init()
{
}

/*
 * --INFO--
 * Address:	80017040
 * Size:	0000AC
 */
static void TrackReceive(seqp_*, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,0,16,31
	  cmplwi    r0, 0x1000
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  addi      r30, r4, 0
	  addi      r29, r3, 0
	  bne-      .loc_0x30
	  li        r3, 0xD
	  li        r4, 0x6
	  bl        -0xA88C

	.loc_0x30:
	  rlwinm    r31,r30,0,16,31
	  rlwinm    r3,r30,0,16,16
	  addis     r0, r3, 0
	  cmplwi    r0, 0x8000
	  bne-      .loc_0x64
	  lwz       r4, 0x88(r29)
	  rlwinm    r5,r31,0,20,31
	  rlwinm    r0,r4,24,28,31
	  rlwinm    r3,r4,28,28,31
	  cmplwi    r0, 0x1
	  rlwinm    r4,r4,0,28,31
	  bne-      .loc_0x64
	  bl        0xE20

	.loc_0x64:
	  andi.     r3, r31, 0x9000
	  addis     r0, r3, 0
	  cmplwi    r0, 0x9000
	  bne-      .loc_0x94
	  addi      r3, r29, 0
	  addi      r5, r1, 0xE
	  li        r4, 0x2
	  bl        -0x6CC0
	  lwz       r0, 0x88(r29)
	  lhz       r4, 0xE(r1)
	  rlwinm    r3,r0,0,28,31
	  bl        0xE70

	.loc_0x94:
	  lmw       r29, 0x1C(r1)
	  li        r3, 0
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017100
 * Size:	00007C
 */
static void AuxBusInit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  li        r29, 0
	  addi      r30, r3, 0x59E8
	  li        r31, 0

	.loc_0x20:
	  cmplwi    r29, 0x3
	  bge-      .loc_0x44
	  add       r3, r30, r31
	  lwz       r0, 0xC(r3)
	  mulli     r0, r0, 0xA0
	  stw       r0, 0x10(r1)
	  lwz       r3, 0x10(r1)
	  bl        -0x119BC
	  b         .loc_0x48

	.loc_0x44:
	  li        r3, 0

	.loc_0x48:
	  addi      r4, r3, 0
	  add       r5, r30, r31
	  rlwinm    r3,r29,0,24,31
	  bl        -0xB494
	  addi      r29, r29, 0x1
	  addi      r31, r31, 0x20
	  cmplwi    r29, 0x4
	  blt+      .loc_0x20
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Jac_SetThreadPriority(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80017180
 * Size:	00000C
 */
static void __BootSoundOK(u32)
{
	boot_ok = TRUE;
}

/*
 * --INFO--
 * Address:	800171A0
 * Size:	000008
 */
BOOL Jac_CheckBootOk()
{
	return boot_ok;
}

/*
 * --INFO--
 * Address:	800171C0
 * Size:	000144
 */
void Jac_Start(void* heap, u32 heapSize, u32 aramSize)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r6, 0
	  stw       r0, 0x4(r1)
	  lis       r7, 0x8022
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r31, r7, 0x2118
	  beq-      .loc_0x34
	  mr        r3, r6
	  bl        -0xFD10

	.loc_0x34:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  li        r6, 0x3
	  bl        -0x10B64
	  bl        -0x108
	  addi      r3, r31, 0x28
	  bl        -0xF250
	  addi      r3, r31, 0x3C
	  bl        -0xF258
	  addi      r3, r31, 0x50
	  bl        -0xF260
	  addi      r3, r31, 0x64
	  bl        -0xF268
	  addi      r3, r31, 0x78
	  bl        -0xF270
	  addi      r3, r31, 0x8C
	  bl        -0xF278
	  addi      r3, r31, 0xA0
	  bl        -0xF280
	  addi      r3, r31, 0xB4
	  bl        -0xF288
	  addi      r3, r31, 0xC8
	  bl        -0xF290
	  addi      r3, r31, 0xDC
	  bl        -0xF298
	  addi      r3, r31, 0xF0
	  bl        -0xF2A0
	  addi      r3, r31, 0x104
	  bl        -0xF2A8
	  addi      r3, r31, 0x118
	  bl        -0xF2B0
	  addi      r3, r31, 0x124
	  bl        -0xF2B8
	  addi      r3, r31, 0x130
	  bl        -0xF2C0
	  addi      r3, r31, 0x13C
	  bl        -0xF2C8
	  addi      r3, r31, 0x14C
	  bl        -0xF2D0
	  lis       r3, 0x1
	  bl        -0x94B8
	  bl        -0x27C
	  bl        -0x2E0
	  li        r3, 0
	  li        r4, 0
	  bl        -0xABCC
	  lis       r4, 0x8001
	  li        r3, 0
	  addi      r5, r4, 0x7180
	  li        r4, 0
	  bl        -0xF340
	  bl        -0x8D84
	  bl        0x4858
	  lfs       f1, -0x7E70(r2)
	  lfs       f2, -0x7E6C(r2)
	  bl        -0x11414
	  lis       r3, 0x8001
	  addi      r3, r3, 0x7040
	  bl        -0x6880
	  bl        0x3BC
	  bl        0x31D8
	  bl        0x2C14
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void Jac_StopSoundAll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80017320
 * Size:	00004C
 */
void Jac_Freeze_Precall()
{
	BOOL level = OSDisableInterrupts();
	// jcs_* handle = Get_GlobalHandle();
	// AllStop_1Shot(handle);
	// FlushRelease_1Shot(handle);
	OSRestoreInterrupts(level);
	__ResetCounter();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stmw      r30, 0x8(r1)
	  bl        0x1E1C4C
	  mr        r31, r3
	  bl        -0xDEF8
	  mr        r30, r3
	  bl        -0x1680
	  mr        r3, r30
	  bl        -0x1368
	  mr        r3, r31
	  bl        0x1E1C54
	  bl        0x6C
	  lwz       r0, 0x14(r1)
	  lmw       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017380
 * Size:	000038
 */
void Jac_Freeze()
{
	BOOL level = OSDisableInterrupts();
	// StopAudioThread();
	OSRestoreInterrupts(level);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        0x1E1BEC
	  mr        r31, r3
	  bl        -0x11038
	  mr        r3, r31
	  bl        0x1E1C04
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800173C0
 * Size:	00000C
 */
static void __ResetCounter()
{
	count = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void Jac_Silence_Check(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800173E0
 * Size:	000038
 */
void Jac_AddDVDBuffer(u8* buf, u32 p2)
{
	// DVDT_SetBuffer(buf, 1, p2);
	lend_buffer = buf;
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0xF99C
	  stw       r31, 0x2C70(r13)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80017420
 * Size:	000034
 */
void Jac_BackDVDBuffer()
{
	if (lend_buffer) {
		// DVDT_CloseBuffer(lend_buffer);
	}
	lend_buffer = nullptr;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2C70(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C
	  bl        -0xF978

	.loc_0x1C:
	  li        r0, 0
	  stw       r0, 0x2C70(r13)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
