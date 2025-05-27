#include "jaudio/bankread.h"

#include "jaudio/connect.h"
#include "jaudio/bx.h"

#define BANKP_SIZE (0x100)
static Bank_* bankp[BANKP_SIZE];

/*
 * --INFO--
 * Address:	8000BE00
 * Size:	000024
 */
static void PTconvert(void** pointer, u32 base_address)
{
	if (*pointer >= (void*)base_address || *pointer == NULL) {
		return;
	}
	*pointer = *(char**)pointer + base_address;
}

/*
 * --INFO--
 * Address:	8000BE40
 * Size:	000270
 */
Bank_* Bank_Test(u8* ibnk_address)
{
	u32 i, j;
	Bank_* startBank = &((Ibnk_*)ibnk_address)->bank;
	if (startBank->mMagic != 'BANK') {
		return nullptr;
	}

	// This entire thing needs a lot of cleanup
	for (i = 0; i < 128; ++i) {
		Inst_* preInst = (Inst_*)(&(startBank->mInstruments[i]));
		PTconvert((void**)preInst, (u32)ibnk_address);

		Inst_* inst = (Inst_*)(*((void**)preInst));
		if (!inst)
			continue;

		// Loop over 2 subentries inside each entry
		for (j = 0; j < 2; j++) {
			PTconvert((void**)&inst->mOscillators[j], (u32)ibnk_address);
			PTconvert((void**)&inst->mEffects[j], (u32)ibnk_address);
			PTconvert((void**)&inst->mSensors[j], (u32)ibnk_address);

			if (inst->mOscillators[j]) {
				PTconvert((void**)&inst->mOscillators[j]->mAttackVecOffset, (u32)ibnk_address);
				PTconvert((void**)&inst->mOscillators[j]->mReleaseVecOffset, (u32)ibnk_address);
			}
		}

		for (j = 0; j < inst->mKeyRegionCount; j++) {
			PTconvert((void**)&inst->mKeyRegions[j], (u32)ibnk_address);

			for (u32 k = 0; k < inst->mKeyRegions[j]->mVelocityCount; k++) {
				PTconvert((void**)&inst->mKeyRegions[j]->mVelocities[k], (u32)ibnk_address);
			}
		}
	}

	for (i = 0; i < 100; i++) {
		Bank_* bank2 = (Bank_*)(&(startBank[i]));
		PTconvert((void**)bank2, (u32)ibnk_address);

		void* entry = (void*)(*((void**)bank2));
		if (!entry)
			continue;

		for (j = 0; j < 2; j++) {
			void* sub         = (char*)entry + j * 4;
			void** nested_ptr = (void**)((char*)sub + 16);

			PTconvert(nested_ptr, (u32)ibnk_address);
			PTconvert((void**)((char*)sub + 24), (u32)ibnk_address);
			PTconvert((void**)((char*)sub + 32), (u32)ibnk_address);

			if (*nested_ptr) {
				PTconvert((void**)((char*)*nested_ptr + 8), (u32)ibnk_address);
				PTconvert((void**)((char*)*nested_ptr + 12), (u32)ibnk_address);
			}
		}
	}

	/*
	for (int i = 0; i < 12; i++) {
	    Bank_* bank3 = (Bank_*)(&bank->entry[i + 0x204]);
	    PTconvert((void**)bank3, (u32)ibnk_address);
	    if (!bank3->entry) continue;

	    for (int j = 0; j < 128; j++) {
	        bank3 = (Bank_*)(&bank->entry[i + 136][j]);
	        PTconvert((void**)bank3, (u32)ibnk_address);
	        if (!bank3->entry) continue;

	        PTconvert((void**)((u8*)((void**)((u8*)bank3 + 136))[j] + 8), (u32)ibnk_address);
	        PTconvert((void**)((u8*)((void**)((u8*)bank3 + 136))[j] + 12), (u32)ibnk_address);

	        for (u32 k = 0; k < (u32)(((u32*)bank3)[4]); k++) {
	            PTconvert(&((void**)((u8*)((void**)((u8*)bank3 + 136))[j] + 20))[k], (u32)ibnk_address);
	        }
	    }
	} */

	return &((Ibnk_*)ibnk_address)->bank;
}
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r22, 0x10(r1)
  addi      r31, r3, 0
  addi      r30, r3, 0x20
  lwz       r4, 0x20(r3)
  subis     r0, r4, 0x4241
  cmplwi    r0, 0x4E4B
  beq-      .loc_0x30
  li        r3, 0
  b         .loc_0x25C

.loc_0x30:
  li        r22, 0
  li        r27, 0

.loc_0x38:
  addi      r28, r27, 0x4
  addi      r4, r31, 0
  add       r28, r30, r28
  addi      r3, r28, 0
  bl        -0x88
  lwz       r26, 0x0(r28)
  cmplwi    r26, 0
  beq-      .loc_0x128
  li        r23, 0
  li        r28, 0

.loc_0x60:
  add       r29, r26, r28
  addi      r4, r31, 0
  addi      r25, r29, 0x10
  addi      r3, r25, 0
  bl        -0xB0
  addi      r3, r29, 0x18
  addi      r4, r31, 0
  bl        -0xBC
  addi      r3, r29, 0x20
  addi      r4, r31, 0
  bl        -0xC8
  lwz       r3, 0x0(r25)
  cmplwi    r3, 0
  beq-      .loc_0xB4
  addi      r3, r3, 0x8
  addi      r4, r31, 0
  bl        -0xE0
  lwz       r3, 0x0(r25)
  addi      r4, r31, 0
  addi      r3, r3, 0xC
  bl        -0xF0

.loc_0xB4:
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4
  cmplwi    r23, 0x2
  blt+      .loc_0x60
  li        r23, 0
  li        r28, 0
  b         .loc_0x11C

.loc_0xD0:
  add       r25, r26, r28
  addi      r4, r31, 0
  addi      r3, r25, 0x2C
  bl        -0x11C
  li        r24, 0
  li        r29, 0
  b         .loc_0x104

.loc_0xEC:
  addi      r3, r29, 0x8
  addi      r4, r31, 0
  add       r3, r5, r3
  bl        -0x138
  addi      r24, r24, 0x1
  addi      r29, r29, 0x4

.loc_0x104:
  lwz       r5, 0x2C(r25)
  lwz       r0, 0x4(r5)
  cmplw     r24, r0
  blt+      .loc_0xEC
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4

.loc_0x11C:
  lwz       r0, 0x28(r26)
  cmplw     r23, r0
  blt+      .loc_0xD0

.loc_0x128:
  addi      r22, r22, 0x1
  addi      r27, r27, 0x4
  cmplwi    r22, 0x80
  blt+      .loc_0x38
  li        r24, 0
  li        r27, 0

.loc_0x140:
  addi      r25, r27, 0x204
  addi      r4, r31, 0
  add       r25, r30, r25
  addi      r3, r25, 0
  bl        -0x190
  lwz       r25, 0x0(r25)
  cmplwi    r25, 0
  beq-      .loc_0x190
  li        r23, 0
  li        r28, 0
  b         .loc_0x184

.loc_0x16C:
  addi      r3, r28, 0xC
  addi      r4, r31, 0
  add       r3, r25, r3
  bl        -0x1B8
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4

.loc_0x184:
  lwz       r0, 0x8(r25)
  cmplw     r23, r0
  blt+      .loc_0x16C

.loc_0x190:
  addi      r24, r24, 0x1
  addi      r27, r27, 0x4
  cmplwi    r24, 0x64
  blt+      .loc_0x140
  li        r24, 0
  li        r29, 0

.loc_0x1A8:
  addi      r25, r29, 0x394
  addi      r4, r31, 0
  add       r25, r30, r25
  addi      r3, r25, 0
  bl        -0x1F8
  lwz       r25, 0x0(r25)
  cmplwi    r25, 0
  beq-      .loc_0x248
  li        r23, 0
  li        r28, 0

.loc_0x1D0:
  addi      r26, r28, 0x88
  addi      r4, r31, 0
  add       r26, r25, r26
  addi      r3, r26, 0
  bl        -0x220
  lwz       r26, 0x0(r26)
  cmplwi    r26, 0
  beq-      .loc_0x238
  addi      r3, r26, 0x8
  addi      r4, r31, 0
  bl        -0x238
  addi      r3, r26, 0xC
  addi      r4, r31, 0
  bl        -0x244
  li        r22, 0
  li        r27, 0
  b         .loc_0x22C

.loc_0x214:
  addi      r3, r27, 0x14
  addi      r4, r31, 0
  add       r3, r26, r3
  bl        -0x260
  addi      r22, r22, 0x1
  addi      r27, r27, 0x4

.loc_0x22C:
  lwz       r0, 0x10(r26)
  cmplw     r22, r0
  blt+      .loc_0x214

.loc_0x238:
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4
  cmplwi    r23, 0x80
  blt+      .loc_0x1D0

.loc_0x248:
  addi      r24, r24, 0x1
  addi      r29, r29, 0x4
  cmplwi    r24, 0xC
  blt+      .loc_0x1A8
  mr        r3, r30

.loc_0x25C:
  lmw       r22, 0x10(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/

/*
 * --INFO--
 * Address:	8000C0C0
 * Size:	000068
 */
static BOOL __Bank_Regist_Inner(u8* ibnk, u32 param_2, u32 param_3)
{
	Jac_BnkConnectTableSet(param_3, param_2);
	bankp[param_2] = Bank_Test(ibnk);
	if (!bankp[param_2])
		return FALSE;
	return TRUE;
}

/*
 * --INFO--
 * Address:	8000C140
 * Size:	000024
 */
BOOL Bank_Regist(void* ibnk, u32 param_2)
{
	return __Bank_Regist_Inner((u8*)ibnk, param_2, ((Ibnk_*)ibnk)->_08);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
BOOL Bank_Regist_Direct(void* ibnk, u32 param_2, u32 param_3)
{
	return __Bank_Regist_Inner((u8*)ibnk, param_2, param_3);
}

/*
 * --INFO--
 * Address:	8000C180
 * Size:	00002C
 */
void Bank_Init()
{
	for (int i = 0; i < BANKP_SIZE; ++i) {
		bankp[i] = NULL;
	}
}

/*
 * --INFO--
 * Address:	8000C1C0
 * Size:	000028
 */
Bank_* Bank_Get(u32 index)
{
	if (index >= BANKP_SIZE) {
		return NULL;
	}
	return bankp[index];
}
