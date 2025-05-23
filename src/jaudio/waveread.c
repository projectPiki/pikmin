#include "jaudio/waveread.h"

#include "jaudio/connect.h"
#include "jaudio/bx.h"

#define WAVEARC_SIZE   (0x100)
#define WAVEGROUP_SIZE (0x100)

static WaveArchiveBank_* wavearc[WAVEARC_SIZE];
static CtrlGroup_* wavegroup[WAVEGROUP_SIZE];

/*
 * --INFO--
 * Address:	8000C200
 * Size:	000038
 */

static void PTconvert(void** pointer, u32 base_address)
{
	if (*pointer == NULL) {
		*pointer = NULL;
		return;
	}
	if (*pointer >= (void*)base_address || *pointer == NULL) {
		return;
	}
	*pointer = *(char**)pointer + base_address;
}

/*
 * --INFO--
 * Address:	8000C240
 * Size:	0002A0
 */
void Wave_Test(u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r22, 0x28(r1)
	  addi      r22, r3, 0
	  addi      r29, r22, 0
	  addi      r3, r22, 0x10
	  addi      r4, r29, 0
	  bl        -0x60
	  addi      r3, r22, 0x14
	  addi      r4, r29, 0
	  bl        -0x6C
	  lwz       r30, 0x10(r22)
	  lis       r3, 0x803E
	  lwz       r31, 0x14(r22)
	  stw       r31, -0x50A0(r3)
	  lwz       r3, 0x0(r30)
	  subis     r0, r3, 0x5749
	  cmplwi    r0, 0x4E46
	  beq-      .loc_0x58
	  li        r3, 0
	  b         .loc_0x28C

	.loc_0x58:
	  lwz       r3, 0x0(r31)
	  subis     r0, r3, 0x5742
	  cmplwi    r0, 0x4354
	  beq-      .loc_0x70
	  li        r3, 0
	  b         .loc_0x28C

	.loc_0x70:
	  li        r22, 0
	  li        r26, 0
	  b         .loc_0xE0

	.loc_0x7C:
	  addi      r25, r26, 0x8
	  addi      r4, r29, 0
	  add       r25, r30, r25
	  addi      r3, r25, 0
	  bl        -0xCC
	  lwz       r0, 0x0(r25)
	  stw       r0, 0x1C(r1)
	  lwz       r27, 0x1C(r1)
	  addi      r3, r27, 0x40
	  bl        0x2920
	  li        r25, 0
	  li        r23, 0
	  stw       r25, 0x48(r27)
	  b         .loc_0xCC

	.loc_0xB4:
	  addi      r3, r25, 0x74
	  addi      r4, r29, 0
	  add       r3, r27, r3
	  bl        -0x100
	  addi      r23, r23, 0x1
	  addi      r25, r25, 0x4

	.loc_0xCC:
	  lwz       r0, 0x70(r27)
	  cmplw     r23, r0
	  blt+      .loc_0xB4
	  addi      r22, r22, 0x1
	  addi      r26, r26, 0x4

	.loc_0xE0:
	  lwz       r0, 0x4(r30)
	  cmplw     r22, r0
	  blt+      .loc_0x7C
	  li        r30, 0
	  li        r27, 0
	  b         .loc_0x274

	.loc_0xF8:
	  addi      r25, r27, 0xC
	  addi      r4, r29, 0
	  add       r25, r31, r25
	  addi      r3, r25, 0
	  bl        -0x148
	  lwz       r28, 0x0(r25)
	  addi      r4, r29, 0
	  addi      r3, r28, 0xC
	  bl        -0x158
	  addi      r3, r28, 0x10
	  addi      r4, r29, 0
	  bl        -0x164
	  addi      r3, r28, 0x14
	  addi      r4, r29, 0
	  bl        -0x170
	  lwz       r24, 0xC(r28)
	  cmplwi    r24, 0
	  beq-      .loc_0x19C
	  lwz       r3, 0x0(r24)
	  subis     r0, r3, 0x432D
	  cmplwi    r0, 0x4446
	  bne-      .loc_0x19C
	  li        r22, 0
	  li        r26, 0
	  addi      r25, r22, 0
	  b         .loc_0x190

	.loc_0x160:
	  addi      r23, r26, 0x8
	  addi      r4, r29, 0
	  add       r23, r24, r23
	  addi      r3, r23, 0
	  bl        -0x1B0
	  lwz       r3, 0x0(r23)
	  addi      r3, r3, 0x4
	  bl        0x2844
	  lwz       r3, 0x0(r23)
	  addi      r22, r22, 0x1
	  addi      r26, r26, 0x4
	  stw       r25, 0xC(r3)

	.loc_0x190:
	  lwz       r0, 0x4(r24)
	  cmplw     r22, r0
	  blt+      .loc_0x160

	.loc_0x19C:
	  lwz       r23, 0x10(r28)
	  cmplwi    r23, 0
	  beq-      .loc_0x204
	  lwz       r3, 0x0(r23)
	  subis     r0, r3, 0x432D
	  cmplwi    r0, 0x4558
	  bne-      .loc_0x204
	  li        r22, 0
	  li        r26, 0
	  addi      r25, r22, 0
	  b         .loc_0x1F8

	.loc_0x1C8:
	  addi      r24, r26, 0x8
	  addi      r4, r29, 0
	  add       r24, r23, r24
	  addi      r3, r24, 0
	  bl        -0x218
	  lwz       r3, 0x0(r24)
	  addi      r3, r3, 0x4
	  bl        0x27DC
	  lwz       r3, 0x0(r24)
	  addi      r22, r22, 0x1
	  addi      r26, r26, 0x4
	  stw       r25, 0xC(r3)

	.loc_0x1F8:
	  lwz       r0, 0x4(r23)
	  cmplw     r22, r0
	  blt+      .loc_0x1C8

	.loc_0x204:
	  lwz       r23, 0x14(r28)
	  cmplwi    r23, 0
	  beq-      .loc_0x26C
	  lwz       r3, 0x0(r23)
	  subis     r0, r3, 0x432D
	  cmplwi    r0, 0x5354
	  bne-      .loc_0x26C
	  li        r25, 0
	  li        r28, 0
	  addi      r26, r25, 0
	  b         .loc_0x260

	.loc_0x230:
	  addi      r24, r28, 0x8
	  addi      r4, r29, 0
	  add       r24, r23, r24
	  addi      r3, r24, 0
	  bl        -0x280
	  lwz       r3, 0x0(r24)
	  addi      r3, r3, 0x4
	  bl        0x2774
	  lwz       r3, 0x0(r24)
	  addi      r25, r25, 0x1
	  addi      r28, r28, 0x4
	  stw       r26, 0xC(r3)

	.loc_0x260:
	  lwz       r0, 0x4(r23)
	  cmplw     r25, r0
	  blt+      .loc_0x230

	.loc_0x26C:
	  addi      r30, r30, 0x1
	  addi      r27, r27, 0x4

	.loc_0x274:
	  lwz       r0, 0x8(r31)
	  cmplw     r30, r0
	  blt+      .loc_0xF8
	  lis       r3, 0x803E
	  subi      r3, r3, 0x50A0
	  lwz       r3, 0x0(r3)

	.loc_0x28C:
	  lmw       r22, 0x28(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GetSound_Test(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000C4E0
 * Size:	000084
 */
BOOL Wavegroup_Regist(void* param_1, u32 param_2)
{
	// Jac_WsConnectTableSet();
	Wave_Test((u8*)param_1);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r31, r3, 0
	  addi      r30, r4, 0
	  lwz       r3, 0x8(r3)
	  bl        0x9C4
	  mr        r3, r31
	  bl        -0x2C4
	  lis       r5, 0x8031
	  lis       r4, 0x8031
	  rlwinm    r6,r30,2,0,29
	  subi      r0, r5, 0x2D20
	  add       r5, r0, r6
	  subi      r0, r4, 0x3120
	  stw       r3, 0x0(r5)
	  add       r3, r0, r6
	  lwz       r0, 0x10(r31)
	  stw       r0, 0x0(r3)
	  lwz       r4, 0x0(r5)
	  cmplwi    r4, 0
	  bne-      .loc_0x64
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x64:
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x4(r4)

	.loc_0x70:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000C580
 * Size:	00002C
 */
void Wavegroup_Init()
{
	for (int i = 0; i < WAVEGROUP_SIZE; ++i) {
		wavegroup[i] = NULL;
	}
}

/*
 * --INFO--
 * Address:	8000C5C0
 * Size:	000064
 */
CtrlGroup_* WaveidToWavegroup(u32 param_1, u32 param_2)
{
	u32 index;
	volatile u16 VOLATILE_param_1;

	u32 badCompiler[2];

	VOLATILE_param_1 = param_1 >> 16;

	if (VOLATILE_param_1 == 0xFFFF) {
		index = param_1;
	} else {
		index = Jac_WsVirtualToPhysical(VOLATILE_param_1);
	}

	return index >= WAVEGROUP_SIZE ? NULL : wavegroup[index];
}

/*
 * --INFO--
 * Address:	8000C640
 * Size:	00008C
 */
static BOOL __WaveScene_Set(u32 param_1, u32 param_2, BOOL param_3)
{
	u32 badCompiler[2];
	u32* REF_param_1;
	u32* REF_param_2;

	CtrlGroup_* group;

	REF_param_1 = &param_1;
	if (param_1 >= WAVEGROUP_SIZE) {
		return FALSE;
	}
	if (!(group = wavegroup[param_1])) {
		return FALSE;
	}
	REF_param_2 = &param_2;
	if (param_2 >= group->_08) {
		return FALSE;
	}
	return Jac_SceneSet(wavearc[param_1], group, param_2, param_3);
}

/*
 * --INFO--
 * Address:	8000C6E0
 * Size:	000024
 */
BOOL WaveScene_Set(u32 param_1, u32 param_2)
{
	return __WaveScene_Set(param_1, param_2, TRUE);
}

/*
 * --INFO--
 * Address:	8000C720
 * Size:	000024
 */
BOOL WaveScene_Load(u32 param_1, u32 param_2)
{
	return __WaveScene_Set(param_1, param_2, FALSE);
}

/*
 * --INFO--
 * Address:	8000C760
 * Size:	000074
 */
static void __WaveScene_Close(u32 param_1, u32 param_2, BOOL param_3)
{
	u32 badCompiler[2];
	u32* REF_param_1;
	u32* REF_param_2;

	CtrlGroup_* group;

	REF_param_1 = &param_1;
	if (param_1 >= WAVEGROUP_SIZE) {
		return;
	}
	if (group = wavegroup[param_1]) {
		REF_param_2 = &param_2;
		if (param_2 < group->_08) {
			Jac_SceneClose(wavearc[param_1], group, param_2, param_3);
		}
	}
}

/*
 * --INFO--
 * Address:	8000C7E0
 * Size:	000024
 */
void WaveScene_Close(u32 param_1, u32 param_2)
{
	__WaveScene_Close(param_1, param_2, TRUE);
}

/*
 * --INFO--
 * Address:	8000C820
 * Size:	000024
 */
void WaveScene_Erase(u32 param_1, u32 param_2)
{
	__WaveScene_Close(param_1, param_2, FALSE);
}
