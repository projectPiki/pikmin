#include "jaudio/virload.h"

#include "jaudio/dvdthread.h"

#include "stl/string.h"

#define JV_DIR_NAME_LENGTH (16)
static char JV_DIR_NAME[JV_DIR_NAME_LENGTH][16];

#define JV_ARC_NAME_LENGTH (16)
static char JV_ARC_NAME[JV_ARC_NAME_LENGTH][32];

#define JV_ARC_LENGTH ()
static Barc* JV_ARC[16]; // Pointers to BARC metadata (*.hed). In practice, just the first element points to pikiseq.hed.

static u32 JV_CURRENT_ARCS = 0; // TODO: type unknown, init unclear

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void JV_InitHeader(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E580
 * Size:	000138
 */
void JV_InitHeader_M(char*, u8*, u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr.       r30, r4
	  lis       r4, 0x8031
	  addi      r31, r5, 0
	  subi      r29, r4, 0xD18
	  stw       r3, 0x8(r1)
	  bne-      .loc_0x74
	  lwz       r28, 0x8(r1)
	  mr        r3, r28
	  bl        -0x6730
	  cmplwi    r3, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x44:
	  bl        -0x8E44
	  mr.       r30, r3
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x58:
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x66E0
	  cmplwi    r3, 0
	  bne-      .loc_0x74
	  li        r3, 0
	  b         .loc_0x124

	.loc_0x74:
	  lwz       r28, 0x8(r1)
	  mr        r3, r28
	  bl        0x20AE10
	  subic.    r27, r3, 0x1
	  add       r3, r28, r27
	  mtctr     r27
	  beq-      .loc_0xA8

	.loc_0x90:
	  lbz       r0, 0x0(r3)
	  cmpwi     r0, 0x2F
	  beq-      .loc_0xA8
	  subi      r27, r27, 0x1
	  subi      r3, r3, 0x1
	  bdnz+     .loc_0x90

	.loc_0xA8:
	  cmplwi    r27, 0
	  bne-      .loc_0xC8
	  lwz       r0, 0x2C10(r13)
	  subi      r4, r2, 0x7F30
	  rlwinm    r0,r0,6,0,25
	  add       r3, r29, r0
	  bl        0x20AD18
	  b         .loc_0xE0

	.loc_0xC8:
	  lwz       r0, 0x2C10(r13)
	  addi      r4, r28, 0
	  addi      r5, r27, 0
	  rlwinm    r0,r0,6,0,25
	  add       r3, r29, r0
	  bl        0x20ACB8

	.loc_0xE0:
	  lwz       r0, 0x2C10(r13)
	  add       r4, r27, r28
	  addi      r4, r4, 0x1
	  rlwinm    r0,r0,5,0,26
	  add       r3, r29, r0
	  addi      r3, r3, 0x400
	  bl        0x20ACE0
	  lwz       r0, 0x2C10(r13)
	  li        r3, 0x1
	  rlwinm    r0,r0,2,0,29
	  add       r4, r29, r0
	  stw       r30, 0x600(r4)
	  lwz       r4, 0x600(r4)
	  stw       r31, 0x8(r4)
	  lwz       r4, 0x2C10(r13)
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C10(r13)

	.loc_0x124:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000E6C0
 * Size:	00007C
 */
u32 JV_GetArchiveHandle(char* name)
{
	u32 i;

	for (i = 0; i < JV_CURRENT_ARCS; ++i) {
		if (!strcmp(name, JV_ARC_NAME[i])) {
			break;
		}
	}
	if (i != JV_CURRENT_ARCS) {
		return i * 0x10000;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void JV_GetLogicalHandleS(char*, char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void JV_GetLogicalHandle(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void JV_GetHandle(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E740
 * Size:	000080
 */
BarcEntry* JV_GetRealHandle(u32 handle)
{
	u32 i;
	Barc* hed;
	u16 temp;
	u16 temp2;

	temp2 = (handle & 0x0000ffff);
	temp  = (handle & 0xffff0000) >> 16;

	if (temp >= JV_CURRENT_ARCS) {
		return 0;
	}
	hed = JV_ARC[temp];
	if (!hed) {
		return NULL;
	}
	if (temp2 >= hed->meta.seqCount) {
		return NULL;
	}
	for (i = temp2; hed[i].entry.isDummy != 0xffff; ++i) { }
	return &hed[i].entry;
}

/*
 * --INFO--
 * Address:	8000E7C0
 * Size:	000034
 */
u32 JV_CheckSize(u32 handle)
{
	BarcEntry* entry;

	entry = JV_GetRealHandle(handle);
	if (!entry)
		return 0;
	return entry->size;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __JV_Callback(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E800
 * Size:	0000D0
 */
u32 JV_LoadFile(volatile u32 handle, u8* volatile dst, u32 param_3, volatile u32 length)
{
	BarcEntry* entry;
	volatile u32 status;
	u32 src;
	u32 badCompiler;
	char name[128];

	status = 0;
	src    = JV_GetRealHandle(handle)->offset + param_3;
	strcpy(name, JV_DIR_NAME[handle >> 16]);
	strcat(name, "/");
	strcat(name, JV_ARC[handle >> 16]->meta.arcName);
	DVDT_LoadtoDRAM(0, name, (u32)dst, src, length, &status, NULL);
	while (!status) { }
	return status;
}

/*
 * --INFO--
 * Address:	8000E8E0
 * Size:	0000E0
 */
unknown JV_LoadFile_Async2(u32, u8*, u32, u32, void (*)(u32), u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stmw      r28, 0xC8(r1)
	  mr        r28, r5
	  addi      r31, r7, 0
	  addi      r29, r8, 0
	  lbz       r0, 0x2C18(r13)
	  stw       r3, 0x8(r1)
	  extsb.    r0, r0
	  stw       r4, 0xC(r1)
	  stw       r6, 0x14(r1)
	  bne-      .loc_0x40
	  li        r0, 0x1
	  stw       r0, 0x2C14(r13)
	  stb       r0, 0x2C18(r13)

	.loc_0x40:
	  lwz       r3, 0x8(r1)
	  rlwinm    r30,r3,16,16,31
	  bl        -0x1E8
	  lwz       r5, 0x18(r3)
	  lis       r3, 0x8031
	  subi      r0, r3, 0xD18
	  rlwinm    r4,r30,6,0,25
	  stw       r5, 0xBC(r1)
	  add       r4, r0, r4
	  addi      r3, r1, 0x3C
	  lwz       r0, 0xBC(r1)
	  add       r0, r0, r28
	  stw       r0, 0xBC(r1)
	  bl        0x20AA04
	  addi      r3, r1, 0x3C
	  subi      r4, r2, 0x7F30
	  bl        0x20A988
	  lis       r3, 0x8031
	  rlwinm    r4,r30,2,0,29
	  subi      r0, r3, 0x718
	  addi      r3, r1, 0x3C
	  add       r4, r0, r4
	  lwz       r4, 0x0(r4)
	  addi      r4, r4, 0x10
	  bl        0x20A968
	  lwz       r30, 0x14(r1)
	  mr        r3, r29
	  lwz       r5, 0xC(r1)
	  mr        r9, r31
	  lwz       r6, 0xBC(r1)
	  addi      r7, r30, 0
	  addi      r4, r1, 0x3C
	  li        r8, 0
	  bl        -0x70A4
	  mr        r3, r30
	  lmw       r28, 0xC8(r1)
	  lwz       r0, 0xDC(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void JV_GetMemoryFile(u32)
{
	// UNUSED FUNCTION
}
