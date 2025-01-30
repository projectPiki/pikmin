#include "WeedsItem.h"
#include "SoundMgr.h"
#include "MapMgr.h"
#include "Graphics.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800E467C
 * Size:	000020
 */
bool RockGen::workable()
{
	return mWorkingPikis < 5;
}

/*
 * --INFO--
 * Address:	800E469C
 * Size:	000018
 */
void RockGen::startWork()
{
	if (workable()) {
		mWorkingPikis++;
	}
}

/*
 * --INFO--
 * Address:	800E46B4
 * Size:	000018
 */
void RockGen::finishWork()
{
	if (mWorkingPikis > 0) {
		mWorkingPikis--;
	}
}

/*
 * --INFO--
 * Address:	800E46CC
 * Size:	000020
 */
bool GrassGen::workable()
{
	return mWorkingPikis < 5;
}

/*
 * --INFO--
 * Address:	800E46EC
 * Size:	000018
 */
void GrassGen::startWork()
{
	if (workable()) {
		mWorkingPikis++;
	}
}

/*
 * --INFO--
 * Address:	800E4704
 * Size:	000018
 */
void GrassGen::finishWork()
{
	if (mWorkingPikis > 0) {
		mWorkingPikis--;
	}
}

/*
 * --INFO--
 * Address:	800E471C
 * Size:	00025C
 */
void RockGen::resolve()
{
	u16 max = mMaxPebbles;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max - 1; j++) {
			Vector3f& pos = mPebbles[j].mPosition;

			for (int k = j + 1; k < max; k++) {
				Vector3f& pos2 = mPebbles[k].mPosition;

				Vector3f separation = pos - pos2;
				f32 distance        = std::sqrtf(separation.x * separation.x + separation.z * separation.z);
				separation.normalise();
				if (distance < 30.0f) {
					separation = separation * 15.0f;
					pos        = pos - separation;
					pos2       = pos2 + separation;

					pos.y  = mapMgr->getMinY(pos.x, pos.z, true);
					pos2.y = mapMgr->getMinY(pos2.x, pos2.z, true);
				}
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stfd      f26, 0xC8(r1)
	  stfd      f25, 0xC0(r1)
	  stfd      f24, 0xB8(r1)
	  stmw      r22, 0x90(r1)
	  mr        r31, r3
	  li        r26, 0
	  lhz       r27, 0x3D6(r3)
	  lfs       f28, -0x66F0(r2)
	  lfd       f29, -0x66E8(r2)
	  subi      r30, r27, 0x1
	  lfd       f30, -0x66E0(r2)
	  lfs       f31, -0x66D8(r2)

	.loc_0x50:
	  li        r25, 0
	  li        r28, 0
	  b         .loc_0x214

	.loc_0x5C:
	  lwz       r0, 0x3D0(r31)
	  addi      r23, r25, 0x1
	  rlwinm    r29,r23,4,0,27
	  add       r24, r0, r28
	  b         .loc_0x204

	.loc_0x70:
	  lwz       r0, 0x3D0(r31)
	  lfs       f3, 0x8(r24)
	  add       r22, r0, r29
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r22)
	  lfs       f0, 0x0(r22)
	  fsubs     f25, f3, f2
	  lfs       f3, 0x4(r24)
	  fsubs     f27, f1, f0
	  lfs       f2, 0x4(r22)
	  fmuls     f0, f25, f25
	  fmuls     f1, f27, f27
	  fsubs     f26, f3, f2
	  fadds     f24, f1, f0
	  fcmpo     cr0, f24, f28
	  ble-      .loc_0x100
	  fsqrte    f1, f24
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f24, f0
	  frsp      f0, f0
	  stfs      f0, 0x54(r1)
	  lfs       f24, 0x54(r1)

	.loc_0x100:
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD6BF0
	  fcmpu     cr0, f28, f1
	  beq-      .loc_0x12C
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x12C:
	  fcmpo     cr0, f24, f31
	  bge-      .loc_0x1FC
	  lfs       f1, -0x3868(r13)
	  li        r4, 0x1
	  lfs       f0, 0x0(r24)
	  fmuls     f3, f27, f1
	  fmuls     f2, f26, f1
	  fmuls     f1, f25, f1
	  fsubs     f0, f0, f3
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x4(r24)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x8(r24)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0x0(r24)
	  stw       r0, 0x4(r24)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x8(r24)
	  lfs       f0, 0x0(r22)
	  fadds     f0, f0, f3
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x4(r22)
	  fadds     f0, f0, f2
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x8(r22)
	  fadds     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0x0(r22)
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x8(r22)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r24)
	  bl        -0x7C9F4
	  stfs      f1, 0x4(r24)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r22)
	  lfs       f2, 0x8(r22)
	  bl        -0x7CA0C
	  stfs      f1, 0x4(r22)

	.loc_0x1FC:
	  addi      r29, r29, 0x10
	  addi      r23, r23, 0x1

	.loc_0x204:
	  cmpw      r23, r27
	  blt+      .loc_0x70
	  addi      r28, r28, 0x10
	  addi      r25, r25, 0x1

	.loc_0x214:
	  cmpw      r25, r30
	  blt+      .loc_0x5C
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  blt+      .loc_0x50
	  lmw       r22, 0x90(r1)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lfd       f26, 0xC8(r1)
	  lfd       f25, 0xC0(r1)
	  lfd       f24, 0xB8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4978
 * Size:	00025C
 */
void GrassGen::resolve()
{
	u16 max = mTotalGrassCount;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max - 1; j++) {
			Vector3f* pos = &mGrass[j].mPosition;
			for (int k = j + 1; k < max; k++) {
				Vector3f* pos2 = &mGrass[k].mPosition;
				Vector3f diff  = *pos - *pos2;
				f32 len        = std::sqrtf(diff.x * diff.x + diff.z * diff.z);
				diff.normalise();
				if (len < 30.0f) {
					diff  = diff * 15.0f;
					*pos  = *pos - diff;
					*pos2 = *pos2 + diff;

					pos->y  = mapMgr->getMinY(pos->x, pos->z, true);
					pos2->y = mapMgr->getMinY(pos2->x, pos2->z, true);
				}
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stfd      f26, 0xC8(r1)
	  stfd      f25, 0xC0(r1)
	  stfd      f24, 0xB8(r1)
	  stmw      r22, 0x90(r1)
	  mr        r31, r3
	  li        r26, 0
	  lhz       r27, 0x3D2(r3)
	  lfs       f28, -0x66F0(r2)
	  lfd       f29, -0x66E8(r2)
	  subi      r30, r27, 0x1
	  lfd       f30, -0x66E0(r2)
	  lfs       f31, -0x66D8(r2)

	.loc_0x50:
	  li        r25, 0
	  li        r28, 0
	  b         .loc_0x214

	.loc_0x5C:
	  lwz       r0, 0x3CC(r31)
	  addi      r23, r25, 0x1
	  rlwinm    r29,r23,4,0,27
	  add       r24, r0, r28
	  b         .loc_0x204

	.loc_0x70:
	  lwz       r0, 0x3CC(r31)
	  lfs       f3, 0x8(r24)
	  add       r22, r0, r29
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r22)
	  lfs       f0, 0x0(r22)
	  fsubs     f25, f3, f2
	  lfs       f3, 0x4(r24)
	  fsubs     f27, f1, f0
	  lfs       f2, 0x4(r22)
	  fmuls     f0, f25, f25
	  fmuls     f1, f27, f27
	  fsubs     f26, f3, f2
	  fadds     f24, f1, f0
	  fcmpo     cr0, f24, f28
	  ble-      .loc_0x100
	  fsqrte    f1, f24
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f24, f0
	  frsp      f0, f0
	  stfs      f0, 0x54(r1)
	  lfs       f24, 0x54(r1)

	.loc_0x100:
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD6E4C
	  fcmpu     cr0, f28, f1
	  beq-      .loc_0x12C
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x12C:
	  fcmpo     cr0, f24, f31
	  bge-      .loc_0x1FC
	  lfs       f1, -0x3864(r13)
	  li        r4, 0x1
	  lfs       f0, 0x0(r24)
	  fmuls     f3, f27, f1
	  fmuls     f2, f26, f1
	  fmuls     f1, f25, f1
	  fsubs     f0, f0, f3
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x4(r24)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x8(r24)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0x0(r24)
	  stw       r0, 0x4(r24)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x8(r24)
	  lfs       f0, 0x0(r22)
	  fadds     f0, f0, f3
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x4(r22)
	  fadds     f0, f0, f2
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x8(r22)
	  fadds     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0x0(r22)
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x8(r22)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r24)
	  bl        -0x7CC50
	  stfs      f1, 0x4(r24)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r22)
	  lfs       f2, 0x8(r22)
	  bl        -0x7CC68
	  stfs      f1, 0x4(r22)

	.loc_0x1FC:
	  addi      r29, r29, 0x10
	  addi      r23, r23, 0x1

	.loc_0x204:
	  cmpw      r23, r27
	  blt+      .loc_0x70
	  addi      r28, r28, 0x10
	  addi      r25, r25, 0x1

	.loc_0x214:
	  cmpw      r25, r30
	  blt+      .loc_0x5C
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  blt+      .loc_0x50
	  lmw       r22, 0x90(r1)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lfd       f26, 0xC8(r1)
	  lfd       f25, 0xC0(r1)
	  lfd       f24, 0xB8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4BD4
 * Size:	0000A0
 */
RockGen::RockGen(Shape* shape, CreatureProp* props)
    : ItemCreature(OBJTYPE_RockGen, props, nullptr)
{
	mPebbles       = 0;
	mMaxPebbles    = 0;
	mActivePebbles = 0;
	mSeContext     = new SeContext;
	mSeContext->setContext(this, 4);
}

/*
 * --INFO--
 * Address:	800E4C74
 * Size:	000284
 */
void RockGen::create(int num, f32 radius, int)
{
	mPebbles       = new Pebble[num];
	mActivePebbles = num;
	mMaxPebbles    = num;
	mSize          = radius;

	for (int i = 0; i < num; i++) {
		f32 randomFactor = gsys->getRand(1.0f);
		f32 finalRadius  = ((1.0f - randomFactor) * gsys->getRand(1.0f) + randomFactor) * radius;

		f32 randomAngle = gsys->getRand(1.0f) * TAU;
		Vector3f pebbleOffset(sinf(randomAngle) * finalRadius, 0.0f, cosf(randomAngle) * finalRadius);
		pebbleOffset   = pebbleOffset + mPosition;
		pebbleOffset.y = mapMgr->getMinY(pebbleOffset.x, pebbleOffset.z, true);

		Pebble& obj          = mPebbles[i];
		obj.mPosition        = pebbleOffset;
		obj.mRotationDegrees = gsys->getRand(1.0f) * 0.999999f * 255.0f;
		obj.mShapeIndex      = gsys->getRand(1.0f) * 0.999999f * 3.0f;
		obj.mHealth          = obj.mShapeIndex * 2 + 2;
	}

	resolve();
	f32 badcompiler[4];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stfd      f29, 0xD8(r1)
	  stfd      f28, 0xD0(r1)
	  stfd      f27, 0xC8(r1)
	  fmr       f27, f1
	  stfd      f26, 0xC0(r1)
	  stfd      f25, 0xB8(r1)
	  stfd      f24, 0xB0(r1)
	  stfd      f23, 0xA8(r1)
	  stfd      f22, 0xA0(r1)
	  stfd      f21, 0x98(r1)
	  stmw      r26, 0x80(r1)
	  mr        r28, r4
	  rlwinm    r4,r4,4,0,27
	  addi      r27, r3, 0
	  addi      r3, r4, 0x8
	  bl        -0x9DCC0
	  lis       r4, 0x800E
	  addi      r4, r4, 0x4EF8
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x12FF4C
	  stw       r3, 0x3D0(r27)
	  li        r29, 0
	  li        r30, 0
	  sth       r28, 0x3D4(r27)
	  lis       r31, 0x4330
	  sth       r28, 0x3D6(r27)
	  stfs      f27, 0x3E4(r27)
	  lfd       f28, -0x66B8(r2)
	  lfs       f29, -0x66D0(r2)
	  lfs       f30, -0x66D4(r2)
	  lfs       f31, -0x66CC(r2)
	  lfs       f24, -0x66C8(r2)
	  lfs       f25, -0x66C4(r2)
	  lfs       f26, -0x66C0(r2)
	  b         .loc_0x234

	.loc_0xA8:
	  bl        0x133354
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x7C(r1)
	  stw       r31, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f23, f30, f0
	  bl        0x133334
	  xoris     r0, r3, 0x8000
	  fsubs     f0, f30, f23
	  stw       r0, 0x74(r1)
	  stw       r31, 0x70(r1)
	  lfd       f1, 0x70(r1)
	  fsubs     f1, f1, f28
	  fdivs     f1, f1, f29
	  fmuls     f1, f30, f1
	  fmuls     f0, f0, f1
	  fadds     f22, f23, f0
	  fmuls     f22, f22, f27
	  bl        0x133304
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x6C(r1)
	  stw       r31, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f21, f31, f0
	  fmr       f1, f21
	  bl        0x136DC0
	  fmuls     f23, f22, f1
	  fmr       f1, f21
	  bl        0x136F48
	  fmuls     f1, f22, f1
	  lfs       f0, -0x3860(r13)
	  li        r4, 0x1
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  stfs      f23, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x94(r27)
	  lfs       f3, 0x3C(r1)
	  lfs       f2, 0x98(r27)
	  fadds     f0, f1, f0
	  lfs       f4, 0x40(r1)
	  lfs       f1, 0x9C(r27)
	  fadds     f2, f3, f2
	  stfs      f0, 0x38(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x7CEF4
	  stfs      f1, 0x3C(r1)
	  lwz       r4, 0x3D0(r27)
	  lwz       r3, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  add       r26, r4, r30
	  stw       r3, 0x0(r26)
	  stw       r0, 0x4(r26)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x8(r26)
	  bl        0x133250
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x64(r1)
	  stw       r31, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f0, f25, f0
	  fmuls     f0, f24, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stb       r0, 0xC(r26)
	  bl        0x133218
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x54(r1)
	  addi      r30, r30, 0x10
	  addi      r29, r29, 0x1
	  stw       r31, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f0, f26, f0
	  fmuls     f0, f24, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stb       r0, 0xD(r26)
	  lbz       r0, 0xD(r26)
	  rlwinm    r3,r0,1,0,30
	  addi      r0, r3, 0x2
	  stb       r0, 0xE(r26)

	.loc_0x234:
	  cmpw      r29, r28
	  blt+      .loc_0xA8
	  mr        r3, r27
	  bl        -0x798
	  lmw       r26, 0x80(r1)
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lfd       f28, 0xD0(r1)
	  lfd       f27, 0xC8(r1)
	  lfd       f26, 0xC0(r1)
	  lfd       f25, 0xB8(r1)
	  lfd       f24, 0xB0(r1)
	  lfd       f23, 0xA8(r1)
	  lfd       f22, 0xA0(r1)
	  lfd       f21, 0x98(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4EF8
 * Size:	000014
 */
Pebble::Pebble()
{
}

/*
 * --INFO--
 * Address:	800E4F0C
 * Size:	000010
 */
void RockGen::setSizeAndNum(f32 size, int num)
{
	mActivePebbles = num;
	mMaxPebbles    = num;
	mSize          = size;
}

/*
 * --INFO--
 * Address:	800E4F1C
 * Size:	00005C
 */
void RockGen::startAI(int state)
{
	mWorkingPikis = 0;
	create(mMaxPebbles, mSize, 0);
	PRINT("++++++++ CREATE ROCK GEN +++++++\n");
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
}

/*
 * --INFO--
 * Address:	800E4F78
 * Size:	000010
 */
void RockGen::killPebble()
{
	mActivePebbles--;
}

/*
 * --INFO--
 * Address:	800E4F88
 * Size:	00003C
 */
void RockGen::doSave(RandomAccessStream& data)
{
	data.writeByte(mActivePebbles);
}

/*
 * --INFO--
 * Address:	800E4FC4
 * Size:	000080
 */
void RockGen::doLoad(RandomAccessStream& data)
{
	mActivePebbles = data.readByte();
	for (int i = 0; i < mMaxPebbles - mActivePebbles; i++) {
		int offset = mMaxPebbles - 1 - i;

		mPebbles[offset].mHealth = 0;
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  sth       r0, 0x3D4(r31)
	  li        r6, 0
	  li        r5, 0
	  b         .loc_0x58

	.loc_0x3C:
	  subi      r0, r3, 0x1
	  lwz       r4, 0x3D0(r31)
	  sub       r0, r0, r6
	  rlwinm    r3,r0,4,0,27
	  addi      r0, r3, 0xE
	  stbx      r5, r4, r0
	  addi      r6, r6, 0x1

	.loc_0x58:
	  lhz       r4, 0x3D4(r31)
	  lhz       r3, 0x3D6(r31)
	  sub       r0, r3, r4
	  cmpw      r6, r0
	  blt+      .loc_0x3C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5044
 * Size:	00002C
 */
void RockGen::update()
{
	if (mSeContext) {
		mSeContext->update();
	}
}

/*
 * --INFO--
 * Address:	800E5070
 * Size:	000190
 */
void RockGen::refresh(Graphics& gfx)
{
	if (!gfx.mCamera->isPointVisible(mPosition, getSize() * 4.0f)) {
		return;
	}

	for (int i = 0; i < mMaxPebbles; i++) {
		Pebble& pebble = mPebbles[i];
		if (!pebble.mHealth) {
			continue;
		}

		Matrix4f mtx;
		f32 yRotation = pebble.mRotationDegrees / 255.0f * PI * 2;
		mtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, yRotation, 0.0f), pebble.mPosition);
		Matrix4f mtx2;
		gfx.calcViewMatrix(mtx, mtx2);
		gfx._324 = 1;
		gfx.useMatrix(mtx2, 0);
		itemMgr->getPebbleShape(pebble.mShapeIndex)->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}

/*
 * --INFO--
 * Address:	800E5200
 * Size:	000008
 */
f32 RockGen::getSize()
{
	return mSize;
}

/*
 * --INFO--
 * Address:	800E5208
 * Size:	0000E0
 */
Pebble* RockGen::getRandomPebble()
{
	if (mActivePebbles <= 0) {
		return nullptr;
	}

	int randomPebbleCount = mActivePebbles * gsys->getRand(1.0f) * 0.999999f;
	for (int i = 0; i < mMaxPebbles; i++) {
		Pebble& pebble = mPebbles[i];
		if (!pebble.mHealth) {
			continue;
		}

		if (randomPebbleCount <= 0) {
			return &pebble;
		}

		randomPebbleCount--;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800E52E8
 * Size:	0000A0
 */
GrassGen::GrassGen(Shape* shape, CreatureProp* props)
    : ItemCreature(OBJTYPE_GrassGen, props, nullptr)
{
	mGrass           = 0;
	mTotalGrassCount = 0;
	mActiveGrass     = 0;
	mSeContext       = new SeContext;
	mSeContext->setContext(this, 4);
}

/*
 * --INFO--
 * Address:	800E5388
 * Size:	000244
 */
void GrassGen::create(int num, f32 size, int)
{
	mGrass           = new Grass[num];
	mActiveGrass     = num;
	mTotalGrassCount = num;
	mSize            = size;

	for (int i = 0; i < num; i++) {
		f32 a     = gsys->getRand(1.0f);
		f32 b     = ((1.0f - a) * gsys->getRand(1.0f) + a) * size;
		f32 angle = gsys->getRand(1.0f) * TAU;
		Vector3f dir(sinf(angle) * b, 0.0f, cosf(angle) * b);
		dir   = dir + mPosition;
		dir.y = mapMgr->getMinY(dir.x, dir.z, true);

		Grass* obj     = &mGrass[i];
		obj->mPosition = dir;
		obj->_0E       = gsys->getRand(1.0f) * 0.999999f * 255.0f;
		obj->_0D       = 0;
		obj->mHealth   = 1;
	}

	resolve();
	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stfd      f29, 0xB8(r1)
	  stfd      f28, 0xB0(r1)
	  stfd      f27, 0xA8(r1)
	  fmr       f27, f1
	  stfd      f26, 0xA0(r1)
	  stfd      f25, 0x98(r1)
	  stfd      f24, 0x90(r1)
	  stfd      f23, 0x88(r1)
	  stfd      f22, 0x80(r1)
	  stmw      r26, 0x68(r1)
	  mr        r31, r4
	  rlwinm    r4,r4,4,0,27
	  addi      r30, r3, 0
	  addi      r29, r31, 0
	  addi      r3, r4, 0x8
	  bl        -0x9E3D4
	  lis       r4, 0x800E
	  addi      r4, r4, 0x55CC
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x12F838
	  stw       r3, 0x3CC(r30)
	  li        r27, 0
	  li        r28, 0
	  sth       r31, 0x3D0(r30)
	  lis       r29, 0x4330
	  sth       r31, 0x3D2(r30)
	  stfs      f27, 0x3E0(r30)
	  lfd       f28, -0x66B8(r2)
	  lfs       f29, -0x66D0(r2)
	  lfs       f30, -0x66D4(r2)
	  lfs       f31, -0x66CC(r2)
	  lfs       f25, -0x66C8(r2)
	  lfs       f26, -0x66C4(r2)
	  b         .loc_0x1F8

	.loc_0xA4:
	  bl        0x132C44
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x64(r1)
	  stw       r29, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f24, f30, f0
	  bl        0x132C24
	  xoris     r0, r3, 0x8000
	  fsubs     f0, f30, f24
	  stw       r0, 0x5C(r1)
	  stw       r29, 0x58(r1)
	  lfd       f1, 0x58(r1)
	  fsubs     f1, f1, f28
	  fdivs     f1, f1, f29
	  fmuls     f1, f30, f1
	  fmuls     f0, f0, f1
	  fadds     f23, f24, f0
	  fmuls     f23, f23, f27
	  bl        0x132BF4
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r29, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f22, f31, f0
	  fmr       f1, f22
	  bl        0x1366B0
	  fmuls     f24, f23, f1
	  fmr       f1, f22
	  bl        0x136838
	  fmuls     f1, f23, f1
	  lfs       f0, -0x3848(r13)
	  li        r4, 0x1
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f24, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x94(r30)
	  lfs       f3, 0x38(r1)
	  lfs       f2, 0x98(r30)
	  fadds     f0, f1, f0
	  lfs       f4, 0x3C(r1)
	  lfs       f1, 0x9C(r30)
	  fadds     f2, f3, f2
	  stfs      f0, 0x34(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x3C(r1)
	  bl        -0x7D604
	  stfs      f1, 0x38(r1)
	  lwz       r4, 0x3CC(r30)
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  add       r26, r4, r28
	  stw       r3, 0x0(r26)
	  stw       r0, 0x4(r26)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x8(r26)
	  bl        0x132B40
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x4C(r1)
	  li        r3, 0
	  li        r0, 0x1
	  stw       r29, 0x48(r1)
	  addi      r28, r28, 0x10
	  addi      r27, r27, 0x1
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f0, f26, f0
	  fmuls     f0, f25, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x40(r1)
	  lwz       r4, 0x44(r1)
	  stb       r4, 0xE(r26)
	  stb       r3, 0xD(r26)
	  stb       r0, 0xC(r26)

	.loc_0x1F8:
	  cmpw      r27, r31
	  blt+      .loc_0xA4
	  mr        r3, r30
	  bl        -0xC14
	  lmw       r26, 0x68(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  lfd       f27, 0xA8(r1)
	  lfd       f26, 0xA0(r1)
	  lfd       f25, 0x98(r1)
	  lfd       f24, 0x90(r1)
	  lfd       f23, 0x88(r1)
	  lfd       f22, 0x80(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E55CC
 * Size:	000014
 */
Grass::Grass()
{
}

/*
 * --INFO--
 * Address:	800E55E0
 * Size:	000010
 */
void GrassGen::setSizeAndNum(f32 size, int num)
{
	mActiveGrass     = num;
	mTotalGrassCount = num;
	mSize            = size;
}

/*
 * --INFO--
 * Address:	800E55F0
 * Size:	00005C
 */
void GrassGen::startAI(int)
{
	mWorkingPikis = 0;
	create(mTotalGrassCount, mSize, 0);
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
	PRINT("++++++++ CREATE GRASS GEN +++++++\n");
}

/*
 * --INFO--
 * Address:	800E564C
 * Size:	00002C
 */
void GrassGen::update()
{
	if (mSeContext) {
		mSeContext->update();
	}
}

/*
 * --INFO--
 * Address:	800E5678
 * Size:	000190
 */
void GrassGen::refresh(Graphics& gfx)
{
	if (gfx.mCamera->isPointVisible(mPosition, getSize() * 4.0f)) {
		for (int i = 0; i < mTotalGrassCount; i++) {
			Grass* pb = &mGrass[i];
			if (pb->mHealth) {
				Matrix4f mtx;
				f32 test = pb->mHealth / 255.0f * PI * 2;
				mtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, test, 0.0f), pb->mPosition);
				Matrix4f mtx2;
				gfx.calcViewMatrix(mtx, mtx2);
				gfx._324 = 1;
				gfx.useMatrix(mtx2, 0);
				itemMgr->getGrassShape(pb->_0D)->drawshape(gfx, *gfx.mCamera, nullptr);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E5808
 * Size:	000008
 */
f32 GrassGen::getSize()
{
	return mSize;
}

/*
 * --INFO--
 * Address:	800E5810
 * Size:	0000E0
 */
Grass* GrassGen::getRandomGrass()
{
	if (mActiveGrass <= 0)
		return nullptr;

	int id = mActiveGrass * gsys->getRand(1.0f) * 0.999999f;
	for (int i = 0; i < mTotalGrassCount; i++) {
		Grass& pb = mGrass[i];
		if (!pb.mHealth) {
			continue;
		}

		if (id <= 0) {
			return &pb;
		}

		id--;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
WeedsGen::WeedsGen(Shape* shape, CreatureProp* props)
    : ItemCreature(0, props, shape)
{
	if (!shape) {
		ERROR("ERR\n");
	}
	mWeedsCount      = 0;
	mWeedsGenProps   = props;
	mItemShapeObject = nullptr;
	mWeedShape       = shape;
}

/*
 * --INFO--
 * Address:	800E58F0
 * Size:	000004
 */
void WeedsGen::update()
{
}

/*
 * --INFO--
 * Address:	800E58F4
 * Size:	000004
 */
void WeedsGen::refresh(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800E58F8
 * Size:	0001CC
 */
void WeedsGen::startAI(int ai)
{
	for (int i = 0; i < mWeedsCount; i++) {
		Weed* gen = (Weed*)itemMgr->birth(OBJTYPE_Weed);
		if (!gen) {
			continue;
		}

		f32 size  = gsys->getRand(1.0f) * 50.0f;
		f32 angle = gsys->getRand(1.0f) * TAU;

		Vector3f offset(sinf(angle) * size, 0.0f, cosf(angle) * size);
		offset   = offset + mPosition;
		offset.y = mapMgr->getMinY(offset.x, offset.z, true);

		if (!mWeedShape) {
			ERROR("STAI\n");
		}

		gen->mProps = mWeedsGenProps;
		gen->mGen   = this;
		gen->init(offset);
		gen->mItemShape = mWeedShape;
		gen->startAI(0);
	}

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
Weed::Weed()
    : ItemCreature(0, nullptr, nullptr)
{
	mItemShapeObject = nullptr;
	setCreatureFlag(0x11);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E5AC4
 * Size:	000024
 */
void Weed::startAI(int)
{
	mScale.set(0.1f, 0.1f, 0.1f);
	mIsPulled = 0;
}

/*
 * --INFO--
 * Address:	800E5AE8
 * Size:	0000CC
 */
bool Weed::interactPullout(Creature* item)
{
	if (!mIsPulled) {
		mIsPulled     = 1;
		mPulloutTimer = 0;
		f32 size      = 20.0f;
		f32 angle     = item->mFaceDirection;
		Vector3f velocity(sinf(angle) * -size, 370.0f, cosf(angle) * -size);

		mVelocity       = velocity;
		mTargetVelocity = velocity;
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800E5BB4
 * Size:	00009C
 */
void Weed::update()
{
	ItemCreature::update();

	if (mIsPulled == 1) {
		mPulloutTimer++;
		if (mPulloutTimer > 30) {
			kill(nullptr);
		} else {
			f32 s = (1.0f - mPulloutTimer / 30.0f);
			s *= 0.1f;
			mScale.set(s, s, s);
		}
	}
}

/*
 * --INFO--
 * Address:	800E5C50
 * Size:	000108
 */
void Weed::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mScale, mRotation, mPosition);
	Matrix4f mtx;
	gfx.calcViewMatrix(mWorldMtx, mtx);
	gfx._324 = 1;
	gfx.useMatrix(mtx, 0);
	gfx.mCamera->setBoundOffset(&mPosition);
	mItemShape->drawshape(gfx, *gfx.mCamera, nullptr);
	gfx.mCamera->setBoundOffset(nullptr);
}

/*
 * --INFO--
 * Address:	800E5D58
 * Size:	000014
 */
bool Weed::isVisible()
{
	return mIsPulled == 0;
}

/*
 * --INFO--
 * Address:	800E5D6C
 * Size:	000008
 */
bool Weed::isAlive()
{
	return true;
}

/*
 * --INFO--
 * Address:	800E5D74
 * Size:	000014
 */
bool Weed::isAtari()
{
	return mIsPulled == 0;
}
