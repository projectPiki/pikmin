#include "TekiPersonality.h"
#include "sysNew.h"
#include "ParaParameters.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tekipersonality");

/*
 * --INFO--
 * Address:	8014CA60
 * Size:	0001F8
 */
TekiPersonality::TekiPersonality()
{
	int i                         = INT_ParamCount;
	ParaParameterInfoI* intParams = new ParaParameterInfoI[i];

	intParams[0].set("PELLET_MIN_COUNT", -128, 127);
	intParams[1].set("PELLET_MAX_COUNT", -128, 127);
	intParams[2].set("WATER_MIN_COUNT", -128, 127);
	intParams[3].set("WATER_MAX_COUNT", -128, 127);
	intParams[4].set("PARAMETER_0", -128, 127);

	ParaParameterInfoF* floatParams = new ParaParameterInfoF[i];

	floatParams[0].set("SIZE", 0.1f, 10.0f);
	floatParams[1].set("STRENGTH", 0.0f, 100.0f);
	floatParams[2].set("TERRITORY_RANGE", 0.0f, 10000.0f);
	floatParams[3].set("PELLET_APPEARANCE_PROBABILITY", 0.0f, 1.0f);
	floatParams[4].set("WATER_APPEARANCE_PROBABILITY", 0.0f, 1.0f);

	mParams = new ParaMultiParameters(INT_ParamCount, intParams, 5, floatParams);
	reset();
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0x1964
	  stwu      r1, -0x48(r1)
	  stmw      r23, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  lis       r3, 0x802D
	  subi      r24, r3, 0x1A48
	  lfs       f0, -0x5818(r2)
	  addi      r3, r31, 0x28
	  stfs      f0, 0xC(r31)
	  stfs      f0, 0x8(r31)
	  stfs      f0, 0x4(r31)
	  stfs      f0, 0x18(r31)
	  stfs      f0, 0x14(r31)
	  stfs      f0, 0x10(r31)
	  bl        -0x108C4C
	  li        r0, 0x5
	  mulli     r25, r0, 0xC
	  addi      r3, r25, 0x8
	  bl        -0x105AB4
	  lis       r4, 0x8012
	  addi      r4, r4, 0x5454
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x5
	  bl        0xC8158
	  li        r0, 0
	  mulli     r26, r0, 0xC
	  add       r7, r3, r26
	  addi      r4, r24, 0x24
	  li        r0, 0x1
	  stw       r4, 0x0(r7)
	  mulli     r27, r0, 0xC
	  li        r6, -0x80
	  li        r0, 0x2
	  stw       r6, 0x4(r7)
	  li        r5, 0x7F
	  mulli     r28, r0, 0xC
	  stw       r5, 0x8(r7)
	  li        r0, 0x3
	  mulli     r29, r0, 0xC
	  add       r4, r3, r27
	  addi      r0, r24, 0x38
	  stw       r0, 0x0(r4)
	  li        r0, 0x4
	  mulli     r30, r0, 0xC
	  stw       r6, 0x4(r4)
	  stw       r5, 0x8(r4)
	  add       r7, r3, r28
	  addi      r0, r24, 0x4C
	  stw       r0, 0x0(r7)
	  add       r8, r3, r29
	  addi      r4, r24, 0x5C
	  stw       r6, 0x4(r7)
	  add       r9, r3, r30
	  addi      r0, r24, 0x6C
	  stw       r5, 0x8(r7)
	  addi      r23, r3, 0
	  addi      r3, r25, 0x8
	  stw       r4, 0x0(r8)
	  stw       r6, 0x4(r8)
	  stw       r5, 0x8(r8)
	  stw       r0, 0x0(r9)
	  stw       r6, 0x4(r9)
	  stw       r5, 0x8(r9)
	  bl        -0x105B6C
	  lis       r4, 0x8012
	  addi      r4, r4, 0x543C
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x5
	  bl        0xC80A0
	  add       r7, r3, r26
	  subi      r0, r13, 0x5D8
	  stw       r0, 0x0(r7)
	  add       r8, r3, r27
	  addi      r6, r24, 0x78
	  lfs       f0, -0x5814(r2)
	  add       r9, r3, r28
	  addi      r5, r24, 0x84
	  stfs      f0, 0x4(r7)
	  add       r10, r3, r29
	  addi      r4, r24, 0x94
	  lfs       f0, -0x5810(r2)
	  add       r11, r3, r30
	  addi      r25, r3, 0
	  stfs      f0, 0x8(r7)
	  addi      r0, r24, 0xB4
	  li        r3, 0xC
	  stw       r6, 0x0(r8)
	  lfs       f1, -0x5818(r2)
	  stfs      f1, 0x4(r8)
	  lfs       f0, -0x580C(r2)
	  stfs      f0, 0x8(r8)
	  stw       r5, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  lfs       f0, -0x5808(r2)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0x0(r10)
	  stfs      f1, 0x4(r10)
	  lfs       f0, -0x5804(r2)
	  stfs      f0, 0x8(r10)
	  stw       r0, 0x0(r11)
	  stfs      f1, 0x4(r11)
	  stfs      f0, 0x8(r11)
	  bl        -0x105C0C
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x1D4
	  addi      r5, r23, 0
	  addi      r7, r25, 0
	  li        r4, 0x5
	  li        r6, 0x5
	  bl        -0x2B3DC

	.loc_0x1D4:
	  stw       r24, 0x34(r31)
	  mr        r3, r31
	  bl        .loc_0x1F8
	  mr        r3, r31
	  lmw       r23, 0x24(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x1F8:
	*/
}

/*
 * --INFO--
 * Address:	8014CC58
 * Size:	00012C
 */
void TekiPersonality::reset()
{
	mPosition.set(0.0f, 0.0f, 0.0f);
	mFaceDirection = 0.0f;
	mScale.set(0.0f, 0.0f, 0.0f);
	_20 = 0;
	_24 = 0;
	mID.setID('none');

	mParams->setI(0, 0);
	mParams->setI(1, 0);
	mParams->setI(2, 0);
	mParams->setI(3, 0);
	mParams->setI(4, 0);

	mParams->setF(0, 1.0f);
	mParams->setF(1, 1.0f);
	mParams->setF(2, 0.0f);
	mParams->setF(3, 0.0f);
	mParams->setF(4, 0.0f);
}

/*
 * --INFO--
 * Address:	8014CD84
 * Size:	0000A0
 */
void TekiPersonality::input(TekiPersonality&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x2C
	  lfs       f0, 0x4(r4)
	  addi      r4, r31, 0x2C
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x8(r30)
	  lfs       f0, 0xC(r31)
	  stfs      f0, 0xC(r30)
	  lfs       f0, 0x1C(r31)
	  stfs      f0, 0x1C(r30)
	  lfs       f0, 0x10(r31)
	  stfs      f0, 0x10(r30)
	  lfs       f0, 0x14(r31)
	  stfs      f0, 0x14(r30)
	  lfs       f0, 0x18(r31)
	  stfs      f0, 0x18(r30)
	  lwz       r0, 0x20(r31)
	  stw       r0, 0x20(r30)
	  lwz       r0, 0x24(r31)
	  stw       r0, 0x24(r30)
	  lwz       r0, 0x28(r31)
	  stw       r0, 0x28(r30)
	  bl        0xC7BC8
	  lwz       r3, 0x34(r30)
	  lwz       r4, 0x34(r31)
	  bl        -0x2B3EC
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014CE24
 * Size:	0002F0
 */
void TekiPersonality::read(RandomAccessStream& input, int version)
{
	if (false) {
		PRINT("TekiPersonality::read:%d\n", version);
	}

	ParaMultiParameters* params = mParams;

	if (version <= 7) {
		ERROR("TekiPersonality::read:too old version:%d\n", version);
		_20 = input.readInt();
		_24 = input.readInt();
		mID.setID('none');
		params->read(input);
		return;
	}

	if (version <= 8) {
		_20 = input.readInt();
		_24 = input.readInt();
		mID.read(input);		

		for (int i = 0; i <= 2; i++) {
			params->mIntParams->mParameters[i] = input.readInt();
		}

		params->setI(4, params->getI(2));
		params->setI(2, 0);
		params->setI(3, 0);
		
		for (int i = 0; i <= 3; i++) {
			params->mFloatParams->mParameters[i] = input.readFloat();
		}

		params->setF(4, 0.0f);
		return;
	}

	if (version <= 9) {
		_20 = input.readByte();
		_24 = input.readByte();
		mID.read(input);

		for (int i = 0; i <= 2; i++) {
			params->mIntParams->mParameters[i] = input.readInt();
		}

		params->setI(4, params->getI(2));
		params->setI(2, 0);
		params->setI(3, 0);

		for (int i = 0; i <= 3; i++) {
			params->mFloatParams->mParameters[i] = input.readFloat();
		}

		params->setF(4, 0.0f);
		return;
	}

	_20 = input.readByte();
	_24 = input.readByte();
	mID.read(input);
	params->read(input);
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r5, 0x7
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  mr        r30, r4
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  addi      r28, r3, 0
	  lwz       r31, 0x34(r3)
	  bgt-      .loc_0x8C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r28)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r28)
	  lis       r4, 0x6E6F
	  addi      r3, r28, 0x28
	  addi      r4, r4, 0x6E65
	  bl        -0x108FCC
	  mr        r3, r31
	  lwz       r12, 0x8(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2D0

	.loc_0x8C:
	  cmpwi     r5, 0x8
	  bgt-      .loc_0x17C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r28)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r28)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x28
	  bl        -0x108E54
	  li        r28, 0
	  li        r29, 0

	.loc_0xD8:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x0(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x2
	  lwz       r4, 0x0(r4)
	  stwx      r3, r4, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0xD8
	  lwz       r3, 0x0(r31)
	  li        r28, 0
	  mr        r29, r28
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x0(r3)
	  stw       r28, 0x8(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x0(r3)
	  stw       r28, 0xC(r3)

	.loc_0x138:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  lwz       r3, 0x0(r3)
	  stfsx     f1, r3, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0x138
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5818(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  b         .loc_0x2D0

	.loc_0x17C:
	  cmpwi     r5, 0x9
	  bgt-      .loc_0x274
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  extsb     r0, r3
	  stw       r0, 0x20(r28)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  extsb     r0, r3
	  stw       r0, 0x24(r28)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x28
	  bl        -0x108F4C
	  li        r28, 0
	  li        r29, 0

	.loc_0x1D0:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x0(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x2
	  lwz       r4, 0x0(r4)
	  stwx      r3, r4, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0x1D0
	  lwz       r3, 0x0(r31)
	  li        r28, 0
	  mr        r29, r28
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x0(r3)
	  stw       r28, 0x8(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x0(r3)
	  stw       r28, 0xC(r3)

	.loc_0x230:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  lwz       r3, 0x0(r3)
	  stfsx     f1, r3, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0x230
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5818(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  b         .loc_0x2D0

	.loc_0x274:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  extsb     r0, r3
	  stw       r0, 0x20(r28)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  extsb     r0, r3
	  stw       r0, 0x24(r28)
	  addi      r4, r30, 0
	  addi      r3, r28, 0x28
	  bl        -0x10903C
	  mr        r3, r31
	  lwz       r12, 0x8(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D0:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014D114
 * Size:	000090
 */
void TekiPersonality::write(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r0, 0x20(r30)
	  lwz       r12, 0x28(r12)
	  extsb     r4, r0
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x24(r30)
	  lwz       r12, 0x4(r31)
	  extsb     r4, r0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x28
	  addi      r4, r31, 0
	  bl        -0x109168
	  lwz       r3, 0x34(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
