#include "jaudio/fat.h"
#include "jaudio/aictrl.h"
#include "jaudio/sample.h"

static int ACTIVE_FATS;
static int USEFAT_TAIL;
static u8* fatheapptr;

typedef struct FATEntry FATEntry;

struct FATEntry {
	u16 _00;  // _00
	u16 _02;  // _02
	u8* addr; // _04
};

#define FAT_SIZE (256)

static struct FAT_info2 {
	u16 _00;
	u16 _02;
} FH_TO_FAT[FAT_SIZE];

static FATEntry FAT[FAT_SIZE];

// havent figured this out yet
static struct FAT_info2 fattmp[FAT_SIZE * 2];

/*
 * --INFO--
 * Address:	8000DDE0
 * Size:	000044
 */
void Jac_FatMemory_Init(u32 size)
{
	fatheapptr = (u8*)OSAlloc2(size);

	if (fatheapptr) {
		FAT_InitSystem(fatheapptr, size);
	}
}

/*
 * --INFO--
 * Address:	8000DE40
 * Size:	0000BC
 */
void FAT_InitSystem(u8* heap, u32 size)
{
	u32 i;

	int fats = 0;
	for (i = 0; i < FAT_SIZE; i++) {
		if (size < 0x1000) {
			break;
		}

		size -= 0x1000;
		FAT[i].addr = heap;
		fats++;
		heap += 0x1000;

		FAT[i]._02 = 0x1000;
		FAT[i]._00 = 0xffff;
	}

	ACTIVE_FATS = fats;
	USEFAT_TAIL = 0;

	for (i = ACTIVE_FATS; i < FAT_SIZE; i++) {
		FAT[i]._00 = 0xffff;
		FAT[i]._02 = 0;
	}

	for (i = 0; i < FAT_SIZE; i++) {
		FH_TO_FAT[i]._00 = -1;
		FH_TO_FAT[i]._02 = 0;
	}
}

/*
 * --INFO--
 * Address:	8000DF00
 * Size:	0000D4
 */
int FAT_AllocateMemory(u32 size)
{
	u32 a = 0;

	for (int i = 0; i < FAT_SIZE; i++) {
		if (FH_TO_FAT[i]._02 == 0) {
			break;
		}
		a++;
	}

	if (a == FAT_SIZE) {
		return 0xffff;
	}
	u16 res = a;

	if (size == 0) {
		return 0xffff;
	}

	int b = size + 0xfff >> 0xc;
	if (ACTIVE_FATS - USEFAT_TAIL < b) {
		return 0xffff;
	}

	for (u32 i = USEFAT_TAIL; i < USEFAT_TAIL + b; i++) {
		FAT[i]._00 = res;
	}

	FH_TO_FAT[res]._00 = USEFAT_TAIL;
	FH_TO_FAT[res]._02 = b;

	USEFAT_TAIL += b;
	return res;
}

/*
 * --INFO--
 * Address:	8000DFE0
 * Size:	000190
 */
int FAT_FreeMemory(u16 size)
{
	int total = 0;
	int old0  = FAT[size]._00;
	int old1  = FAT[size]._02;
	u16 size2 = old0 + old1;
	u16 tail  = USEFAT_TAIL - size2;
	if (tail == 0) {
		USEFAT_TAIL = USEFAT_TAIL - old1;
	}
	FAT[size]._02 = 0;
	return 0;
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lis       r4, 0x8031
	  subi      r4, r4, 0x2118
	  rlwinm    r0,r3,2,14,29
	  stmw      r30, 0x18(r1)
	  add       r3, r4, r0
	  li        r11, 0
	  lhzx      r0, r4, r0
	  lhz       r5, 0x2(r3)
	  sth       r11, 0x2(r3)
	  add       r3, r0, r5
	  rlwinm    r3,r3,0,16,31
	  lwz       r6, 0x2BF4(r13)
	  sub       r7, r6, r3
	  rlwinm.   r30,r7,0,16,31
	  bne-      .loc_0x84
	  sub       r0, r6, r5
	  lis       r3, 0x1
	  stw       r0, 0x2BF4(r13)
	  subi      r6, r3, 0x1
	  li        r8, 0
	  lwz       r7, 0x2BF4(r13)
	  mtctr     r5
	  cmplwi    r5, 0
	  ble-      .loc_0x7C

	.loc_0x64:
	  add       r0, r7, r8
	  addi      r8, r8, 0x1
	  rlwinm    r0,r0,3,0,28
	  add       r3, r4, r0
	  sth       r6, 0x400(r3)
	  bdnz+     .loc_0x64

	.loc_0x7C:
	  li        r3, 0
	  b         .loc_0x184

	.loc_0x84:
	  lis       r7, 0x1
	  addi      r6, r11, 0
	  subi      r7, r7, 0x1
	  mtctr     r5
	  cmplwi    r5, 0
	  ble-      .loc_0xCC

	.loc_0x9C:
	  add       r8, r0, r11
	  add       r10, r4, r6
	  rlwinm    r8,r8,3,0,28
	  addi      r11, r11, 0x1
	  add       r8, r4, r8
	  addi      r6, r6, 0x8
	  lwz       r9, 0x400(r8)
	  lwz       r8, 0x404(r8)
	  stw       r9, 0xC00(r10)
	  stw       r8, 0xC04(r10)
	  sth       r7, 0xC00(r10)
	  bdnz+     .loc_0x9C

	.loc_0xCC:
	  lis       r6, 0x1
	  li        r12, 0
	  subi      r31, r6, 0x1
	  mtctr     r30
	  cmplwi    r30, 0
	  ble-      .loc_0x130

	.loc_0xE4:
	  add       r6, r3, r12
	  add       r11, r0, r12
	  rlwinm    r7,r6,3,0,28
	  rlwinm    r6,r11,3,0,28
	  add       r10, r4, r7
	  add       r9, r4, r6
	  lwz       r8, 0x400(r10)
	  rlwinm    r6,r31,0,16,31
	  lwz       r7, 0x404(r10)
	  stw       r8, 0x400(r9)
	  stw       r7, 0x404(r9)
	  lhz       r7, 0x400(r10)
	  cmplw     r6, r7
	  beq-      .loc_0x128
	  rlwinm    r6,r7,2,0,29
	  mr        r31, r7
	  sthx      r11, r4, r6

	.loc_0x128:
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0xE4

	.loc_0x130:
	  lwz       r0, 0x2BF4(r13)
	  li        r9, 0
	  li        r3, 0
	  sub       r0, r0, r5
	  stw       r0, 0x2BF4(r13)
	  lwz       r8, 0x2BF4(r13)
	  mtctr     r5
	  cmplwi    r5, 0
	  ble-      .loc_0x180

	.loc_0x154:
	  add       r7, r4, r3
	  add       r0, r8, r9
	  rlwinm    r6,r0,3,0,28
	  lwz       r5, 0xC00(r7)
	  lwz       r0, 0xC04(r7)
	  add       r6, r4, r6
	  addi      r9, r9, 0x1
	  addi      r3, r3, 0x8
	  stw       r5, 0x400(r6)
	  stw       r0, 0x404(r6)
	  bdnz+     .loc_0x154

	.loc_0x180:
	  li        r3, 0

	.loc_0x184:
	  lmw       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000E180
 * Size:	000048
 */
u8* FAT_GetPointer(u16 a, u32 b)
{
	u32 c = b >> 12;
	if (FH_TO_FAT[a]._02 <= c) {
		return 0;
	}

	b &= 0xFFF;
	return FAT[c + FH_TO_FAT[a]._00].addr + b;
}

/*
 * --INFO--
 * Address:	8000E1E0
 * Size:	000034
 */
u8 FAT_ReadByte(u16 a, u32 b)
{
	u8* ptr = FAT_GetPointer(a, b);
	if (ptr == NULL) {
		return 0;
	}
	return *ptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
u16 FAT_ReadWord(u16 a, u32 b)
{
	// Guessing based on name/size

	u16* ptr = (u16*)FAT_GetPointer(a, b);
	if (ptr == NULL) {
		return 0;
	}
	return *ptr;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void FAT_ReadWordD(u16 a, u32 b)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
u32 FAT_ReadLong(u16 a, u32 b)
{
	// UNUSED FUNCTION

	// Guessing based on name/size
	return *(u32*)FAT_GetPointer(a, b);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void FAT_ReadLongD(u16, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E220
 * Size:	0000E0
 */
int FAT_StoreBlock(u8* ptr, u16 a, u32 b, u32 c)
{
	u32 badCompiler[2];
	u8* ptr2 = FAT_GetPointer(a, b);

	int size = b;
	b &= 0xFFF;
	size -= b;
	// this whole thing is wrong
	while (c != 0) {
		b++;
		*ptr2++ = *ptr++;
		c--;

		if (b == 0x1000) {
			size += 0x1000;

			ptr2 = FAT_GetPointer(a, size);
			break;
		}
	}

	for (; 0x1000 <= c;) {
		Jac_bcopy(ptr, ptr2, 0x1000);
		size += 0x1000;
		c -= 0x1000;
		ptr += 0x1000;
		ptr2 = FAT_GetPointer(a, size);
	}

	if (c != 0) {
		Jac_bcopy(ptr, ptr2, c);
	}
	return 0;
}
