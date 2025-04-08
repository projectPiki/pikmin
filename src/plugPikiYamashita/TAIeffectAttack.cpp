#include "TAI/EffectAttack.h"
#include "teki.h"
#include "NaviMgr.h"
#include "PikiMgr.h"
#include "Vector.h"
#include "zen/Math.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("TAIeffectAttack")

/*
 * --INFO--
 * Address:	801C4960
 * Size:	000038
 */
bool EventTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	mParam->_44->ptclHitMap(ptclGen, mParam);
	return true;
}

/*
 * --INFO--
 * Address:	801C4998
 * Size:	0001E0
 */
void CylinderTypeCallBack::init(TAIeffectAttackParam* param, Teki* teki, Vector3f& p3, Vector3f p4, f32 p5, f32 p6, f32 p7, f32 p8,
                                TAIeffectAttackEventCallBack* eventCB)
{
	mParam = param;
	mParam->init();
	mParam->mTeki = teki;
	mParam->_00   = 0.0f;
	mParam->_04   = p5;
	mParam->_0C   = p7;
	mParam->_1C   = p4;
	mParam->_10   = p3;
	mParam->_28   = p4;
	mParam->_28.normalize();
	mParam->_34 = p6;
	mParam->_08 = p8;
	if (eventCB) {
		mParam->_44 = eventCB;
	}

	mParam->_4C.m0 = 1;
}

/*
 * --INFO--
 * Address:	801C4B78
 * Size:	00019C
 */
void CylinderTypeCallBack::hitCheckCommon(zen::particleGenerator* ptclGen, Creature* creature)
{
	f32 lineDist;
	Vector3f vec1;
	Vector3f vec2;

	if (mParam->_44->hitCheckCulling(ptclGen, mParam, creature)) {
		f32 pointDist
		    = zen::getDistPointAndLine(creature->getPosition(), ptclGen->getEmitPos(), mParam->_10 + mParam->_28 * mParam->_08, lineDist);
		if (pointDist < creature->getCentreSize() + mParam->_08 && lineDist >= 0.0f && lineDist <= 1.0f) {
			mParam->_44->hitCreature(mParam, creature);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E4
 */
void CylinderTypeCallBack::hitCheck(zen::particleGenerator* ptclGen)
{
	Navi* navi = naviMgr->getNavi();
	hitCheckCommon(ptclGen, navi);

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		hitCheckCommon(ptclGen, *iter);
	}
}

/*
 * --INFO--
 * Address:	801C4D14
 * Size:	000384
 */
bool CylinderTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	mParam->_44->playEventSound(ptclGen, mParam);
	f32 nextTime = gsys->getFrameTime() + mParam->_00;
	mParam->_00  = nextTime;

	if (nextTime < mParam->_04 && mParam->mTeki->mHealth > 0.0f) {
		Vector3f vec1;

		if (mParam->_4C.m0) {
			mParam->_10.add(Vector3f(mParam->_1C * gsys->getFrameTime()));
			vec1 = mParam->_10 - ptclGen->getEmitPos();
			if (vec1.length() > mParam->_0C) {
				mParam->_4C.m0 = 0;
				mParam->_1C.normalize();
			} else if (mParam->_44->hitMap(mParam)) {
				mParam->_4C.m0 = 0;
			}
		}

		hitCheck(ptclGen);
	}

	mParam->_44->ptclHitMap(ptclGen, mParam);
	return true;
}

/*
 * --INFO--
 * Address:	801C5098
 * Size:	0001E8
 */
void ConeTypeCallBack::init(TAIeffectAttackParam* param, Teki* teki, Vector3f& p3, Vector3f p4, f32 p5, f32 p6, f32 p7, f32 p8,
                            TAIeffectAttackEventCallBack* eventCB)
{
	mParam = param;
	mParam->init();
	mParam->mTeki = teki;
	mParam->_00   = 0.0f;
	mParam->_04   = p5;
	mParam->_0C   = p7;
	mParam->_10   = p3;
	mParam->_28   = p4;
	mParam->_28.normalize();
	mParam->_1C = p4;
	mParam->_34 = p8;
	if (mParam->_3C && !mParam->_3C->checkEmit()) {
		ERROR("EMIT IS ALIVE! ");
	}
	if (mParam->_40 && !mParam->_40->checkEmit()) {
		ERROR("EMIT IS ALIVE! ");
	}
	mParam->_3C = mParam->_40 = nullptr;
	if (eventCB) {
		mParam->_44 = eventCB;
	}
	_08 = p6;
}

/*
 * --INFO--
 * Address:	801C5280
 * Size:	000320
 */
void ConeTypeCallBack::hitCheckCommon(zen::particleGenerator* ptclGen, Creature* creature)
{
	Vector3f emitPos(ptclGen->getEmitPos());
	Vector3f cPos(creature->getPosition());
	Vector3f dir1 = mParam->_10 - ptclGen->getEmitPos();
	Vector3f dir2(cPos.x - emitPos.x, cPos.y - emitPos.y, cPos.z - emitPos.z);

	if (dir1.DP(dir2) > 0.0f) {
		f32 dist1 = dir1.length();
		f32 dist2 = dir2.length();

		f32 val;
		if (mParam->_1C.x == 0.0f && mParam->_1C.y == 0.0f && mParam->_1C.z == 0.0f) {
			val = mParam->_0C;
		} else {
			val = dist1;
		}

		if (dist2 < val) {
			if (dist1 != 0.0f) {
				dir1.div(dist1);
			}
			if (dist2 != 0.0f) {
				dir2.div(dist2);
			}

			// idk why the instruction order is getting weird here.
			f32 dot12 = dir1.DP(dir2);
			f32 angle = cosf(_08);

			if (dot12 > angle) {
				Vector3f vec1;
				f32 scale = (dot12 - angle) / (1.0f - angle);
				scale *= 1.005f;
				if (scale >= 1.0f) {
					scale = 3.0f;
				}

				vec1.set(dir2.x - dir1.x, 0.5f, dir2.z - dir1.z);
				vec1.normalize();
				vec1.multiply(scale);

				u32 flag = ptclGen->getControlFlag();

				mParam->_44->hitCreature(ptclGen, mParam, creature, vec1);
			}
		}
	}

	PRINT("fake", ptclGen ? "fake" : "fake");
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
	  stw       r31, 0xCC(r1)
	  addi      r31, r5, 0
	  stw       r30, 0xC8(r1)
	  mr        r30, r4
	  stw       r29, 0xC4(r1)
	  addi      r29, r3, 0
	  lwz       r6, 0x18(r4)
	  cmplwi    r6, 0
	  beq-      .loc_0x4C
	  mr        r3, r6
	  b         .loc_0x50

	.loc_0x4C:
	  addi      r3, r30, 0xC

	.loc_0x50:
	  cmplwi    r6, 0
	  lfs       f0, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f4, 0x8(r3)
	  lfs       f3, 0x94(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f5, 0x9C(r31)
	  beq-      .loc_0x74
	  b         .loc_0x78

	.loc_0x74:
	  addi      r6, r30, 0xC

	.loc_0x78:
	  lwz       r3, 0x4(r29)
	  fsubs     f28, f5, f4
	  fsubs     f29, f3, f0
	  lfs       f0, 0x4(r6)
	  addi      r3, r3, 0x10
	  fsubs     f2, f2, f1
	  lfs       f1, 0x4(r3)
	  lfs       f3, 0x0(r3)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x0(r6)
	  lfs       f6, 0x8(r3)
	  fsubs     f31, f3, f1
	  lfs       f4, 0x8(r6)
	  fmuls     f1, f0, f2
	  lfs       f5, -0x4648(r2)
	  fmuls     f3, f31, f29
	  fsubs     f30, f6, f4
	  fadds     f1, f3, f1
	  fmuls     f3, f30, f28
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f5
	  ble-      .loc_0x2F0
	  fmuls     f3, f31, f31
	  fmuls     f1, f0, f0
	  fmuls     f4, f30, f30
	  fadds     f1, f3, f1
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f5
	  ble-      .loc_0x144
	  fsqrte    f4, f1
	  lfd       f6, -0x4640(r2)
	  lfd       f5, -0x4638(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f1, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f1, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f1, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f1, f1, f3
	  frsp      f1, f1
	  stfs      f1, 0x40(r1)
	  lfs       f1, 0x40(r1)

	.loc_0x144:
	  fmuls     f5, f29, f29
	  lfs       f3, -0x4648(r2)
	  fmuls     f4, f2, f2
	  fmuls     f6, f28, f28
	  fadds     f4, f5, f4
	  fadds     f7, f6, f4
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0x1BC
	  fsqrte    f4, f7
	  lfd       f6, -0x4640(r2)
	  lfd       f5, -0x4638(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f7, f3
	  frsp      f3, f3
	  stfs      f3, 0x3C(r1)
	  lfs       f7, 0x3C(r1)

	.loc_0x1BC:
	  lwz       r3, 0x4(r29)
	  lfs       f4, -0x4648(r2)
	  lfs       f3, 0x1C(r3)
	  fcmpu     cr0, f4, f3
	  bne-      .loc_0x1F0
	  lfs       f3, 0x20(r3)
	  fcmpu     cr0, f4, f3
	  bne-      .loc_0x1F0
	  lfs       f3, 0x24(r3)
	  fcmpu     cr0, f4, f3
	  bne-      .loc_0x1F0
	  lfs       f3, 0xC(r3)
	  b         .loc_0x1F4

	.loc_0x1F0:
	  fmr       f3, f1

	.loc_0x1F4:
	  fcmpo     cr0, f7, f3
	  bge-      .loc_0x2F0
	  lfs       f3, -0x4648(r2)
	  fcmpu     cr0, f3, f1
	  beq-      .loc_0x214
	  fdivs     f31, f31, f1
	  fdivs     f0, f0, f1
	  fdivs     f30, f30, f1

	.loc_0x214:
	  lfs       f1, -0x4648(r2)
	  fcmpu     cr0, f1, f7
	  beq-      .loc_0x22C
	  fdivs     f29, f29, f7
	  fdivs     f2, f2, f7
	  fdivs     f28, f28, f7

	.loc_0x22C:
	  fmuls     f0, f0, f2
	  lfs       f1, 0x8(r29)
	  fmuls     f3, f31, f29
	  fmuls     f2, f30, f28
	  fadds     f0, f3, f0
	  fadds     f27, f2, f0
	  bl        0x56690
	  fcmpo     cr0, f27, f1
	  ble-      .loc_0x2F0
	  lfs       f2, -0x4630(r2)
	  fsubs     f3, f27, f1
	  lfs       f0, -0x462C(r2)
	  fsubs     f1, f2, f1
	  fdivs     f27, f3, f1
	  fmuls     f27, f27, f0
	  fcmpo     cr0, f27, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x278
	  lfs       f27, -0x4628(r2)

	.loc_0x278:
	  fsubs     f31, f29, f31
	  lfs       f29, 0x1BD4(r13)
	  fsubs     f28, f28, f30
	  fmuls     f0, f29, f29
	  fmuls     f1, f31, f31
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B78D8
	  lfs       f0, -0x4648(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2B4
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1

	.loc_0x2B4:
	  fmuls     f31, f31, f27
	  addi      r7, r1, 0x50
	  fmuls     f29, f29, f27
	  mr        r4, r30
	  fmuls     f28, f28, f27
	  stfs      f31, 0x50(r1)
	  mr        r6, r31
	  stfs      f29, 0x54(r1)
	  stfs      f28, 0x58(r1)
	  lwz       r5, 0x4(r29)
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x2F0:
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000214
 */
void ConeTypeCallBack::hitCheck(zen::particleGenerator* ptclGen)
{
	Iterator iterN(naviMgr);
	CI_LOOP(iterN)
	{
		hitCheckCommon(ptclGen, *iterN);
	}

	Iterator iterP(pikiMgr);
	CI_LOOP(iterP)
	{
		hitCheckCommon(ptclGen, *iterP);
	}
}

/*
 * --INFO--
 * Address:	801C55A0
 * Size:	000434
 */
bool ConeTypeCallBack::invoke(zen::particleGenerator* ptclGen)
{
	f32 nextTime = mParam->_00 + gsys->getFrameTime();
	mParam->_00  = nextTime;

	if (nextTime < mParam->_04 && mParam->mTeki->mHealth > 0.0f) {
		Vector3f vec1;

		mParam->_10.add(Vector3f(mParam->_1C * gsys->getFrameTime()));
		vec1 = mParam->_10 - ptclGen->getEmitPos();
		if (vec1.length() > mParam->_0C) {
			mParam->_1C.set(0.0f, 0.0f, 0.0f);
		} else if (ptclGen->checkEmit()) {
			if (mParam->_44->hitMap(mParam)) {
				mParam->_1C.set(0.0f, 0.0f, 0.0f);
			}
		} else {
			ERROR("HEN! %f %f \n", mParam->_00, mParam->_04);
		}

		hitCheck(ptclGen);
	} else {
		ptclGen->finish();
		if (mParam->_3C) {
			mParam->_3C->finish();
		}
		if (mParam->_40) {
			mParam->_40->finish();
		}
	}

	mParam->_44->ptclHitMap(ptclGen, mParam);
	mParam->_44->playEventSound(ptclGen, mParam);
	return true;
}
