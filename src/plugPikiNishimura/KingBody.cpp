#include "King.h"
#include "EffectMgr.h"
#include "SoundMgr.h"
#include "Pellet.h"
#include "RadarInfo.h"
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
DEFINE_PRINT("KingBody");

/*
 * --INFO--
 * Address:	........
 * Size:	00017C
 */
void KingBody::setSalivaEffect()
{
	mSalivaCallBacks[0].set(&_A8[1], &_A8[2], mKing);
	mSalivaParticleCallBack->set(mKing);
	effectMgr->create(EffectMgr::EFF_Unk116, Vector3f(0.0f, 0.0f, 0.0f), &mSalivaCallBacks[0], mSalivaParticleCallBack);

	mSalivaCallBacks[1].set(&_A8[0], &_A8[3], mKing);
	effectMgr->create(EffectMgr::EFF_Unk116, Vector3f(0.0f, 0.0f, 0.0f), &mSalivaCallBacks[1], mSalivaParticleCallBack);

	mSalivaCallBacks[2].set(&_A8[0], &_A8[1], mKing);
	effectMgr->create(EffectMgr::EFF_Unk117, Vector3f(0.0f, 0.0f, 0.0f), &mSalivaCallBacks[2], mSalivaParticleCallBack);

	mSpreadSalivaCallBack->set(mKing);
	zen::particleGenerator* ptcl
	    = effectMgr->create(EffectMgr::EFF_Unk118, Vector3f(0.0f, 0.0f, 0.0f), mSpreadSalivaCallBack, mSalivaParticleCallBack);
	if (ptcl) {
		ptcl->setEmitPosPtr(&_D8);
	}
}

/*
 * --INFO--
 * Address:	80172D84
 * Size:	0000DC
 */
void KingBody::setSeedFlashEffect()
{
	mDamageStarCallBack->set(mKing);

	for (int i = 0; i < 2; i++) {
		effectMgr->create(EffectMgr::EFF_Unk47, _78[i], nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Unk48, _78[i], nullptr, nullptr);
		zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Unk104, Vector3f(0.0f, 0.0f, 0.0f), mDamageStarCallBack, nullptr);
		if (ptcl) {
			ptcl->setEmitPosPtr(&_78[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	80172E60
 * Size:	00024C
 */
void KingBody::setEatBombEffect()
{
	Vector3f dir(sinf(mKing->mDirection), 0.0f, cosf(mKing->mDirection));
	Vector3f effectPos            = _6C + 50.0f * dir;
	zen::particleGenerator* ptcl1 = effectMgr->create(EffectMgr::EFF_Unk123, effectPos, nullptr, nullptr);
	if (ptcl1) {
		ptcl1->setEmitDir(dir);
	}
	zen::particleGenerator* ptcl2 = effectMgr->create(EffectMgr::EFF_Unk122, effectPos, nullptr, nullptr);
	if (ptcl2) {
		ptcl2->setEmitDir(dir);
	}

	mDamageStarCallBack->set(mKing);
	for (int i = 0; i < 2; i++) {
		zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Unk124, _90[i], nullptr, nullptr);
		if (ptcl) {
			ptcl->setEmitDir(dir);
		}
	}

	setSeedFlashEffect();
}

/*
 * --INFO--
 * Address:	801730AC
 * Size:	000210
 */
void KingBody::createWaterEffect(int idx)
{
	effectMgr->create(EffectMgr::EFF_Unk15, _24[idx], nullptr, nullptr);
	if (!_0B[idx]) {
		_0B[idx] = true;
		mRippleCallBacks[idx].set(mKing, &_24[idx], &_0B[idx]);
		zen::particleGenerator* ptcl1
		    = effectMgr->create(EffectMgr::EFF_Unk14, Vector3f(0.0f, 0.0f, 0.0f), &mRippleCallBacks[idx], nullptr);
		if (ptcl1) {
			ptcl1->set1DC(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = ptcl1->getScaleSize();
			ptcl1->setScaleSize(2.0f * f0);
		}
		zen::particleGenerator* ptcl2
		    = effectMgr->create(EffectMgr::EFF_Unk12, Vector3f(0.0f, 0.0f, 0.0f), &mRippleCallBacks[idx], nullptr);
		if (ptcl2) {
			ptcl2->set1DC(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = ptcl2->getScaleSize();
			ptcl2->setScaleSize(2.0f * f0);
		}
		zen::particleGenerator* ptcl3
		    = effectMgr->create(EffectMgr::EFF_Unk13, Vector3f(0.0f, 0.0f, 0.0f), &mRippleCallBacks[idx], nullptr);
		if (ptcl3) {
			ptcl3->set1DC(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = ptcl3->getScaleSize();
			ptcl3->setScaleSize(2.0f * f0);
		}
	}
}

/*
 * --INFO--
 * Address:	801732BC
 * Size:	000250
 */
void KingBody::createUfoParts()
{
	Pellet* ufoPart = pelletMgr->newPellet(mKing->mPelletID.mId, nullptr);
	if (ufoPart) {
		CollPart* nosePart = mKing->mCollInfo->getSphere('nose');
		f32 angle          = atan2f(nosePart->mCentre.x - mKing->mPosition.x, nosePart->mCentre.z - mKing->mPosition.z);
		f32 xOffs          = sinf(angle) + sinf(mKing->mDirection);
		f32 zOffs          = cosf(angle) + cosf(mKing->mDirection);
		Vector3f dir(xOffs, 0.0f, zOffs);
		Vector3f partPos(nosePart->mCentre);
		partPos.y -= 80.0f;

		ufoPart->init(partPos);

		dir.normalise();
		ufoPart->mVelocity.set(250.0f * dir.x, 0.0f, 250.0f * dir.z);

		ufoPart->mDirection = mKing->mDirection;
		ufoPart->startAI(0);

		zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Unk125, partPos, nullptr, mSpitPartsParticleCallBack);

		radarInfo->detachParts(mKing);

		if (ptcl) {
			dir.y = -0.5f;
			ptcl->setEmitDir(dir);
		}

		if (Pellet::isUfoPartsID(mKing->mPelletID.mId)) {
			SeSystem::playSysSe(0x122);
		}
	}

	mKing->mIsBossBgm = false;
	mKing->detachGenerator();
}

/*
 * --INFO--
 * Address:	8017350C
 * Size:	0000DC
 */
void KingBody::killCallBackEffect(bool p1)
{
	int i;
	for (i = 0; i < 3; i++) {
		effectMgr->killGenerator(&mSalivaCallBacks[i], mSalivaParticleCallBack, p1);
	}

	effectMgr->killGenerator(mSpreadSalivaCallBack, mSalivaParticleCallBack, p1);
	effectMgr->killGenerator(mDamageStarCallBack, nullptr, p1);

	for (i = 0; i < 2; i++) {
		effectMgr->killGenerator(&mRippleCallBacks[i], nullptr, p1);
	}
}

/*
 * --INFO--
 * Address:	801735E8
 * Size:	00023C
 */
KingBody::KingBody(King*)
{
	_F0                        = new Matrix4f[66];
	_F4                        = new Matrix4f[66];
	mSalivaCallBacks           = new KingGenSalivaCallBack[3];
	mSpreadSalivaCallBack      = new KingGenSpreadSalivaCallBack;
	mSalivaParticleCallBack    = new KingGenSalivaParticleCallBack;
	mDamageStarCallBack        = new KingGenDamageStarCallBack;
	mRippleCallBacks           = new KingGenRippleCallBack[2];
	mSpitPartsParticleCallBack = new KingGenSpitPartsParticleCallBack;
}

/*
 * --INFO--
 * Address:	8017385C
 * Size:	00023C
 */
void KingBody::init(King* king)
{
	mKing = king;
	_04   = 0;
	_1C   = 0.0f;
	_20   = 0.0f;
	_05   = 0;
	_06   = 0;

	for (int i = 0; i < 2; i++) {
		_09[i] = 1;
		_07[i] = 1;
		_0B[i] = 0;
		_10[i] = -1;
		_24[i].set(0.0f, 0.0f, 0.0f);
		_3C[i].set(0.0f, 0.0f, 0.0f);
	}

	_54.set(0.0f, 0.0f, 0.0f);
	setSalivaEffect();
}

/*
 * --INFO--
 * Address:	80173A98
 * Size:	000028
 */
void KingBody::initBlending(f32 p1)
{
	if (_1C > 0.0f) {
		_04 = 1;
	}

	_18 = p1;
	/*
	.loc_0x0:
	  lfs       f2, 0x1C(r3)
	  lfs       f0, -0x5320(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x18
	  li        r0, 0x1
	  stb       r0, 0x4(r3)

	.loc_0x18:
	  lfs       f0, -0x5300(r2)
	  stfs      f0, 0x1C(r3)
	  stfs      f1, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void KingBody::updateBlendingRatio()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void KingBody::checkOnGround()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80173AC0
 * Size:	0001E0
 */
void KingBody::setVelocityFromPosition()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  stw       r30, 0xB0(r1)
	  lfs       f0, -0x5320(r2)
	  lfs       f1, 0x20(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x180
	  lwz       r3, 0x0(r31)
	  li        r30, 0
	  lfs       f1, 0xA0(r3)
	  bl        0xA805C
	  lwz       r3, 0x0(r31)
	  fmr       f31, f1
	  lfs       f1, 0xA0(r3)
	  bl        0xA81E0
	  lbz       r0, 0x7(r31)
	  lfs       f4, 0x3D0(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  li        r30, 0x1

	.loc_0x60:
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  li        r30, 0x1

	.loc_0x70:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0x138
	  lwz       r4, 0x0(r31)
	  lbz       r0, 0x2BF(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  lfs       f3, 0x20(r31)
	  fmuls     f2, f2, f0
	  lfs       f0, -0x52F0(r2)
	  fmuls     f2, f3, f2
	  fdivs     f0, f2, f0
	  fmuls     f2, f1, f0
	  fmuls     f1, f4, f0
	  fmuls     f0, f31, f0
	  stfs      f2, 0x60(r1)
	  lfs       f2, 0x60(r1)
	  stfs      f2, 0x94(r1)
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x94(r1)
	  lwz       r0, 0x98(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0xAC(r4)
	  b         .loc_0x1B8

	.loc_0xE4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  lfs       f3, 0x20(r31)
	  fmuls     f0, f2, f0
	  fmuls     f0, f3, f0
	  fmuls     f2, f1, f0
	  fmuls     f1, f4, f0
	  fmuls     f0, f31, f0
	  stfs      f2, 0x54(r1)
	  lfs       f2, 0x54(r1)
	  stfs      f2, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f0, 0x90(r1)
	  lwz       r3, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stw       r3, 0xA4(r4)
	  stw       r0, 0xA8(r4)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0xAC(r4)
	  b         .loc_0x1B8

	.loc_0x138:
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x2BF(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1B8
	  lfs       f0, 0x3D4(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, 0x3D8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x3DC(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x3E0(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, 0x3E4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x3E8(r13)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x1B8

	.loc_0x180:
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x3EC(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, 0x3F0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x3F4(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x3F8(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, 0x3FC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x400(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x1B8:
	  lwz       r3, 0x0(r31)
	  li        r0, 0
	  stb       r0, 0x2BF(r3)
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80173CA0
 * Size:	000140
 */
void KingBody::emitOnGroundEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stmw      r27, 0x34(r1)
	  li        r28, 0
	  addi      r27, r3, 0
	  mulli     r0, r28, 0xC
	  addi      r30, r27, 0
	  add       r31, r27, r0
	  lfs       f31, -0x52F0(r2)

	.loc_0x2C:
	  add       r29, r27, r28
	  lbz       r0, 0x7(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x114
	  lbz       r0, 0x9(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x114
	  lwz       r3, 0x0(r27)
	  addi      r4, r31, 0x24
	  bl        -0x24980
	  stw       r3, 0x10(r30)
	  lwz       r0, 0x10(r30)
	  cmpwi     r0, 0x5
	  bne-      .loc_0x74
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  bl        -0xC60
	  b         .loc_0x7C

	.loc_0x74:
	  li        r0, 0
	  stb       r0, 0xB(r29)

	.loc_0x7C:
	  lwz       r3, 0x0(r27)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x114
	  cmpwi     r0, 0xF
	  bge-      .loc_0x114
	  lfs       f0, 0x24(r31)
	  addi      r5, r1, 0x20
	  li        r4, 0x67
	  stfs      f0, 0x20(r1)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, 0x28(r31)
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x2C(r31)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x24(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x3180(r13)
	  bl        0x28DCC
	  lwz       r3, 0x0(r27)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  li        r4, 0x4D
	  bl        -0xCFFB4

	.loc_0xE8:
	  lwz       r6, 0x0(r27)
	  li        r4, 0x4
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  addi      r6, r6, 0x94
	  bl        0x9038
	  lwz       r5, 0x0(r27)
	  li        r4, 0x3
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r5, 0x94
	  bl        -0x4FDD8

	.loc_0x114:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x2
	  addi      r31, r31, 0xC
	  addi      r30, r30, 0x4
	  blt+      .loc_0x2C
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void KingBody::emitSlipEffect()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void KingBody::copyOnGround()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80173DE0
 * Size:	000198
 */
void KingBody::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lfs       f2, -0x5320(r2)
	  lfs       f3, 0x1C(r3)
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0x60
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x18(r29)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x1C(r29)
	  lfs       f1, 0x1C(r29)
	  lfs       f0, -0x52FC(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x60
	  stfs      f2, 0x1C(r29)

	.loc_0x60:
	  lwz       r4, 0x0(r29)
	  li        r3, 0x1
	  lfs       f3, 0x28(r29)
	  li        r0, 0
	  lfs       f2, 0x98(r4)
	  lfs       f1, -0x52F8(r2)
	  fsubs     f2, f3, f2
	  lfs       f0, -0x52F4(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x90
	  stb       r3, 0x7(r29)
	  b         .loc_0x9C

	.loc_0x90:
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x9C
	  stb       r0, 0x7(r29)

	.loc_0x9C:
	  lwz       r4, 0x0(r29)
	  lfs       f3, 0x34(r29)
	  lfs       f2, 0x98(r4)
	  fsubs     f2, f3, f2
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0xBC
	  stb       r3, 0x8(r29)
	  b         .loc_0xC8

	.loc_0xBC:
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xC8
	  stb       r0, 0x8(r29)

	.loc_0xC8:
	  mr        r3, r29
	  bl        -0x3EC
	  mr        r3, r29
	  bl        -0x214
	  li        r31, 0
	  lfs       f31, -0x52F0(r2)
	  mulli     r0, r31, 0xC
	  lfs       f30, -0x5328(r2)
	  add       r30, r29, r0

	.loc_0xEC:
	  addi      r0, r31, 0x7
	  lbzx      r0, r29, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lfs       f1, 0x24(r30)
	  lfs       f2, 0x2C(r30)
	  lfs       f3, 0x3C(r30)
	  lfs       f4, 0x44(r30)
	  bl        -0x13B8C4
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x154
	  lfs       f0, 0x24(r30)
	  addi      r5, r1, 0x24
	  li        r4, 0x66
	  stfs      f0, 0x24(r1)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, 0x28(r30)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x2C(r30)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x28(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x28(r1)
	  lwz       r3, 0x3180(r13)
	  bl        0x28C08

	.loc_0x154:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x2
	  addi      r30, r30, 0xC
	  blt+      .loc_0xEC
	  lbz       r0, 0x7(r29)
	  stb       r0, 0x9(r29)
	  lbz       r0, 0x8(r29)
	  stb       r0, 0xA(r29)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00012C
 */
void KingBody::makeAnimation(BossShapeObject*, Graphics&, Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000AD0
 */
void KingBody::checkBlendingParm(Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80173F78
 * Size:	000578
 */
void KingBody::makeBlending(Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x428(r1)
	  stfd      f31, 0x420(r1)
	  stfd      f30, 0x418(r1)
	  stfd      f29, 0x410(r1)
	  stfd      f28, 0x408(r1)
	  stmw      r26, 0x3F0(r1)
	  mr        r26, r3
	  mr        r28, r4
	  lfs       f0, -0x5320(r2)
	  lfs       f1, 0x1C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x554
	  lfs       f0, -0x52FC(r2)
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  fsubs     f30, f0, f1
	  addi      r3, r1, 0xD4
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x42
	  bl        0xA0AA0
	  li        r0, 0x16
	  mtctr     r0
	  addi      r7, r28, 0
	  addi      r8, r1, 0xD4
	  li        r6, 0

	.loc_0x70:
	  lwz       r3, 0xF0(r26)
	  addi      r5, r6, 0xC
	  lfs       f2, 0x1C(r26)
	  addi      r4, r6, 0x1C
	  lfsx      f0, r3, r5
	  lfs       f1, 0xC(r7)
	  addi      r0, r6, 0x2C
	  fmuls     f0, f30, f0
	  addi      r5, r6, 0x4C
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f2, 0x1C(r26)
	  lfsx      f0, r3, r4
	  addi      r4, r6, 0x5C
	  lfs       f1, 0x1C(r7)
	  fmuls     f0, f30, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f1, 0x2C(r7)
	  lfsx      f0, r3, r0
	  addi      r0, r6, 0x6C
	  lfs       f2, 0x1C(r26)
	  fmuls     f0, f30, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f2, 0x1C(r26)
	  lfsx      f0, r3, r5
	  addi      r5, r6, 0x8C
	  lfs       f1, 0x4C(r7)
	  fmuls     f0, f30, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f2, 0x1C(r26)
	  lfsx      f0, r3, r4
	  addi      r4, r6, 0x9C
	  lfs       f1, 0x5C(r7)
	  fmuls     f0, f30, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f1, 0x6C(r7)
	  lfsx      f0, r3, r0
	  addi      r0, r6, 0xAC
	  lfs       f2, 0x1C(r26)
	  addi      r6, r6, 0xC0
	  fmuls     f0, f30, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f2, 0x1C(r26)
	  lfs       f1, 0x8C(r7)
	  lfsx      f0, r3, r5
	  fmuls     f1, f2, f1
	  fmuls     f0, f30, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f2, 0x1C(r26)
	  lfs       f1, 0x9C(r7)
	  lfsx      f0, r3, r4
	  fmuls     f1, f2, f1
	  fmuls     f0, f30, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r8)
	  lwz       r3, 0xF0(r26)
	  lfs       f1, 0xAC(r7)
	  addi      r7, r7, 0xC0
	  lfs       f2, 0x1C(r26)
	  lfsx      f0, r3, r0
	  fmuls     f1, f2, f1
	  fmuls     f0, f30, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r8)
	  addi      r8, r8, 0x24
	  bdnz+     .loc_0x70
	  li        r27, 0
	  lfs       f29, -0x5320(r2)
	  mulli     r0, r27, 0xC
	  lfd       f30, -0x5310(r2)
	  lfd       f31, -0x5308(r2)
	  lfs       f28, -0x52FC(r2)
	  addi      r29, r1, 0xD4
	  addi      r31, r28, 0
	  rlwinm    r30,r27,6,0,25
	  add       r29, r29, r0
	  li        r28, 0x9

	.loc_0x1F0:
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x10(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x20(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, 0x4(r31)
	  fmuls     f4, f3, f3
	  fadds     f1, f2, f1
	  lfs       f8, 0x14(r31)
	  lfs       f7, 0x24(r31)
	  lfs       f3, 0x8(r31)
	  fadds     f4, f4, f1
	  lfs       f2, 0x18(r31)
	  lfs       f1, 0x28(r31)
	  fcmpo     cr0, f4, f29
	  ble-      .loc_0x280
	  fsqrte    f6, f4
	  fmul      f5, f6, f6
	  fmul      f6, f30, f6
	  fmul      f5, f4, f5
	  fsub      f5, f31, f5
	  fmul      f6, f6, f5
	  fmul      f5, f6, f6
	  fmul      f6, f30, f6
	  fmul      f5, f4, f5
	  fsub      f5, f31, f5
	  fmul      f6, f6, f5
	  fmul      f5, f6, f6
	  fmul      f6, f30, f6
	  fmul      f5, f4, f5
	  fsub      f5, f31, f5
	  fmul      f5, f6, f5
	  fmul      f4, f4, f5
	  frsp      f4, f4
	  stfs      f4, 0x2C(r1)
	  lfs       f4, 0x2C(r1)

	.loc_0x280:
	  fmuls     f5, f0, f0
	  fmuls     f0, f8, f8
	  fmuls     f6, f7, f7
	  fadds     f0, f5, f0
	  fadds     f0, f6, f0
	  fcmpo     cr0, f0, f29
	  ble-      .loc_0x2EC
	  fsqrte    f6, f0
	  fmul      f5, f6, f6
	  fmul      f6, f30, f6
	  fmul      f5, f0, f5
	  fsub      f5, f31, f5
	  fmul      f6, f6, f5
	  fmul      f5, f6, f6
	  fmul      f6, f30, f6
	  fmul      f5, f0, f5
	  fsub      f5, f31, f5
	  fmul      f6, f6, f5
	  fmul      f5, f6, f6
	  fmul      f6, f30, f6
	  fmul      f5, f0, f5
	  fsub      f5, f31, f5
	  fmul      f5, f6, f5
	  fmul      f0, f0, f5
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x28(r1)

	.loc_0x2EC:
	  fmuls     f3, f3, f3
	  fmuls     f2, f2, f2
	  fmuls     f5, f1, f1
	  fadds     f1, f3, f2
	  fadds     f3, f5, f1
	  fcmpo     cr0, f3, f29
	  ble-      .loc_0x358
	  fsqrte    f2, f3
	  fmul      f1, f2, f2
	  fmul      f2, f30, f2
	  fmul      f1, f3, f1
	  fsub      f1, f31, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f30, f2
	  fmul      f1, f3, f1
	  fsub      f1, f31, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f30, f2
	  fmul      f1, f3, f1
	  fsub      f1, f31, f1
	  fmul      f1, f2, f1
	  fmul      f1, f3, f1
	  frsp      f1, f1
	  stfs      f1, 0x24(r1)
	  lfs       f3, 0x24(r1)

	.loc_0x358:
	  cmpwi     r28, 0x8
	  li        r3, 0
	  ble-      .loc_0x534
	  stfs      f29, 0x80(r1)
	  li        r3, 0x8
	  stfs      f29, 0x84(r1)
	  stfs      f29, 0x88(r1)
	  stfs      f29, 0x8C(r1)
	  stfs      f29, 0x90(r1)
	  stfs      f29, 0x94(r1)
	  stfs      f29, 0x98(r1)
	  stfs      f29, 0x9C(r1)
	  b         .loc_0x534

	.loc_0x38C:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x3A8

	.loc_0x39C:
	  stfs      f29, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x39C

	.loc_0x3A8:
	  stfs      f28, 0xA0(r1)
	  cmpwi     r28, 0x8
	  li        r3, 0
	  stfs      f28, 0x90(r1)
	  stfs      f28, 0x80(r1)
	  ble-      .loc_0x544
	  stfs      f29, 0x5C(r1)
	  li        r3, 0x8
	  stfs      f29, 0x60(r1)
	  stfs      f29, 0x64(r1)
	  stfs      f29, 0x68(r1)
	  stfs      f29, 0x6C(r1)
	  stfs      f29, 0x70(r1)
	  stfs      f29, 0x74(r1)
	  stfs      f29, 0x78(r1)
	  b         .loc_0x544

	.loc_0x3E8:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x404

	.loc_0x3F8:
	  stfs      f29, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x3F8

	.loc_0x404:
	  stfs      f28, 0x7C(r1)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x80
	  stfs      f29, 0x54(r1)
	  stfs      f29, 0x44(r1)
	  stfs      f4, 0x30(r1)
	  stfs      f28, 0x6C(r1)
	  stfs      f29, 0x50(r1)
	  stfs      f29, 0x40(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f28, 0x5C(r1)
	  stfs      f29, 0x4C(r1)
	  stfs      f29, 0x3C(r1)
	  stfs      f3, 0x38(r1)
	  bl        0x8468
	  addi      r3, r1, 0x4C
	  addi      r4, r1, 0x80
	  bl        -0x13CB04
	  lwz       r0, 0xF0(r26)
	  addi      r4, r1, 0x5C
	  add       r3, r0, r30
	  bl        0x844C
	  addi      r3, r1, 0x3C
	  addi      r4, r1, 0x5C
	  bl        -0x13CB20
	  lfs       f1, 0x1C(r26)
	  addi      r3, r1, 0x3C
	  addi      r4, r1, 0x4C
	  li        r5, 0
	  bl        -0x13C26C
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r1, 0x3C
	  addi      r6, r1, 0x30
	  bl        -0x135700
	  lwz       r0, 0xF4(r26)
	  addi      r27, r27, 0x1
	  lwz       r3, 0x0(r31)
	  cmpwi     r27, 0x42
	  add       r4, r0, r30
	  lwz       r0, 0x4(r31)
	  addi      r30, r30, 0x40
	  addi      r29, r29, 0xC
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  stw       r3, 0x8(r4)
	  stw       r0, 0xC(r4)
	  lwz       r3, 0x10(r31)
	  lwz       r0, 0x14(r31)
	  stw       r3, 0x10(r4)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x18(r31)
	  lwz       r0, 0x1C(r31)
	  stw       r3, 0x18(r4)
	  stw       r0, 0x1C(r4)
	  lwz       r3, 0x20(r31)
	  lwz       r0, 0x24(r31)
	  stw       r3, 0x20(r4)
	  stw       r0, 0x24(r4)
	  lwz       r3, 0x28(r31)
	  lwz       r0, 0x2C(r31)
	  stw       r3, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x34(r31)
	  stw       r3, 0x30(r4)
	  stw       r0, 0x34(r4)
	  lwz       r3, 0x38(r31)
	  lwz       r0, 0x3C(r31)
	  addi      r31, r31, 0x40
	  stw       r3, 0x38(r4)
	  stw       r0, 0x3C(r4)
	  blt+      .loc_0x1F0
	  b         .loc_0x554

	.loc_0x534:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0x80
	  add       r4, r4, r0
	  b         .loc_0x38C

	.loc_0x544:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0x5C
	  add       r4, r4, r0
	  b         .loc_0x3E8

	.loc_0x554:
	  lmw       r26, 0x3F0(r1)
	  lwz       r0, 0x42C(r1)
	  lfd       f31, 0x420(r1)
	  lfd       f30, 0x418(r1)
	  lfd       f29, 0x410(r1)
	  lfd       f28, 0x408(r1)
	  addi      r1, r1, 0x428
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801744F0
 * Size:	000230
 */
void KingBody::copyJointPosition(Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x24(r3)
	  lwz       r0, 0x28(r30)
	  stw       r3, 0x3C(r30)
	  stw       r0, 0x40(r30)
	  lwz       r0, 0x2C(r30)
	  stw       r0, 0x44(r30)
	  lwz       r3, 0x30(r30)
	  lwz       r0, 0x34(r30)
	  stw       r3, 0x48(r30)
	  stw       r0, 0x4C(r30)
	  lwz       r0, 0x38(r30)
	  stw       r0, 0x50(r30)
	  lfs       f0, 0xCC(r4)
	  stfs      f0, 0x24(r30)
	  lfs       f0, 0xDC(r4)
	  stfs      f0, 0x28(r30)
	  lfs       f0, 0xEC(r4)
	  stfs      f0, 0x2C(r30)
	  lfs       f0, 0x18C(r4)
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x19C(r4)
	  stfs      f0, 0x34(r30)
	  lfs       f0, 0x1AC(r4)
	  stfs      f0, 0x38(r30)
	  lfs       f0, 0x7C4(r4)
	  stfs      f0, 0x60(r30)
	  lfs       f0, 0x7D4(r4)
	  stfs      f0, 0x64(r30)
	  lfs       f0, 0x7E4(r4)
	  stfs      f0, 0x68(r30)
	  lfs       f0, 0x60(r30)
	  lfs       f1, -0x52EC(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x60(r30)
	  lfs       f0, 0x64(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x64(r30)
	  lfs       f0, 0x68(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x68(r30)
	  lfs       f1, 0x60(r30)
	  lfs       f0, 0x64(r30)
	  lfs       f2, 0x68(r30)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x16698C
	  lfs       f0, -0x5320(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x110
	  lfs       f0, 0x60(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x60(r30)
	  lfs       f0, 0x64(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x64(r30)
	  lfs       f0, 0x68(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x68(r30)

	.loc_0x110:
	  lfs       f0, 0x38C(r31)
	  stfs      f0, 0xCC(r30)
	  lfs       f0, 0x39C(r31)
	  stfs      f0, 0xD0(r30)
	  lfs       f0, 0x3AC(r31)
	  stfs      f0, 0xD4(r30)
	  lfs       f0, 0x3CC(r31)
	  stfs      f0, 0xC0(r30)
	  lfs       f0, 0x3DC(r31)
	  stfs      f0, 0xC4(r30)
	  lfs       f0, 0x3EC(r31)
	  stfs      f0, 0xC8(r30)
	  lfs       f0, 0x40C(r31)
	  stfs      f0, 0xB4(r30)
	  lfs       f0, 0x41C(r31)
	  stfs      f0, 0xB8(r30)
	  lfs       f0, 0x42C(r31)
	  stfs      f0, 0xBC(r30)
	  lfs       f0, 0x44C(r31)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0x45C(r31)
	  stfs      f0, 0xAC(r30)
	  lfs       f0, 0x46C(r31)
	  stfs      f0, 0xB0(r30)
	  lwz       r3, 0xD8(r30)
	  lwz       r0, 0xDC(r30)
	  stw       r3, 0xE4(r30)
	  stw       r0, 0xE8(r30)
	  lwz       r0, 0xE0(r30)
	  stw       r0, 0xEC(r30)
	  lfs       f0, 0x7CC(r31)
	  stfs      f0, 0xD8(r30)
	  lfs       f0, 0x7DC(r31)
	  stfs      f0, 0xDC(r30)
	  lfs       f0, 0x7EC(r31)
	  stfs      f0, 0xE0(r30)
	  lfs       f0, 0xB4C(r31)
	  stfs      f0, 0x78(r30)
	  lfs       f0, 0xB5C(r31)
	  stfs      f0, 0x7C(r30)
	  lfs       f0, 0xB6C(r31)
	  stfs      f0, 0x80(r30)
	  lfs       f0, 0xCCC(r31)
	  stfs      f0, 0x84(r30)
	  lfs       f0, 0xCDC(r31)
	  stfs      f0, 0x88(r30)
	  lfs       f0, 0xCEC(r31)
	  stfs      f0, 0x8C(r30)
	  lfs       f0, 0x28C(r31)
	  stfs      f0, 0x90(r30)
	  lfs       f0, 0x29C(r31)
	  stfs      f0, 0x94(r30)
	  lfs       f0, 0x2AC(r31)
	  stfs      f0, 0x98(r30)
	  lfs       f0, 0x24C(r31)
	  stfs      f0, 0x9C(r30)
	  lfs       f0, 0x25C(r31)
	  stfs      f0, 0xA0(r30)
	  lfs       f0, 0x26C(r31)
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0x34C(r31)
	  stfs      f0, 0x6C(r30)
	  lfs       f0, 0x35C(r31)
	  stfs      f0, 0x70(r30)
	  lfs       f0, 0x36C(r31)
	  stfs      f0, 0x74(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void KingBody::returnJoint(BossShapeObject*, Graphics&, Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80174720
 * Size:	000C6C
 */
void KingBody::refresh(BossShapeObject*, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8004
	  stw       r0, 0x4(r1)
	  subi      r0, r6, 0xFE4
	  li        r6, 0x40
	  stwu      r1, -0x1148(r1)
	  li        r7, 0x42
	  stfd      f31, 0x1140(r1)
	  stfd      f30, 0x1138(r1)
	  stmw      r27, 0x1124(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  mr        r4, r0
	  addi      r3, r1, 0x9C
	  li        r5, 0
	  bl        0xA0310
	  lwz       r3, 0x2E4(r29)
	  addi      r4, r1, 0x5C
	  addi      r3, r3, 0x1E0
	  bl        -0x136334
	  li        r31, 0
	  lfs       f30, -0x5320(r2)
	  rlwinm    r0,r31,6,0,25
	  lfs       f31, -0x52FC(r2)
	  addi      r30, r1, 0x9C
	  add       r30, r30, r0

	.loc_0x6C:
	  lwz       r3, 0x0(r28)
	  mr        r4, r31
	  bl        -0x13F7AC
	  lwz       r6, 0x0(r3)
	  mr        r5, r30
	  lwz       r0, 0x4(r3)
	  addi      r4, r1, 0x1C
	  stw       r6, 0x1C(r1)
	  stw       r0, 0x20(r1)
	  lwz       r6, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r6, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r6, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r6, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  lwz       r6, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r6, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r6, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r6, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r6, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r6, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r6, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  addi      r3, r1, 0x5C
	  stw       r6, 0x54(r1)
	  stw       r0, 0x58(r1)
	  stfs      f30, 0x4C(r1)
	  stfs      f30, 0x50(r1)
	  stfs      f30, 0x54(r1)
	  stfs      f31, 0x58(r1)
	  bl        -0x136760
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x42
	  addi      r30, r30, 0x40
	  blt+      .loc_0x6C
	  lfs       f1, -0x5320(r2)
	  lfs       f0, 0x1C(r27)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x664
	  li        r0, 0x8
	  li        r3, 0
	  mtctr     r0
	  addi      r5, r3, 0
	  addi      r4, r1, 0x9C

	.loc_0x14C:
	  lwz       r9, 0xF0(r27)
	  addi      r8, r5, 0x40
	  lwz       r6, 0x0(r4)
	  addi      r7, r5, 0x80
	  lwz       r0, 0x4(r4)
	  add       r9, r9, r5
	  stw       r6, 0x0(r9)
	  stw       r0, 0x4(r9)
	  lwz       r6, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r6, 0x8(r9)
	  stw       r0, 0xC(r9)
	  lwz       r6, 0x10(r4)
	  lwz       r0, 0x14(r4)
	  stw       r6, 0x10(r9)
	  stw       r0, 0x14(r9)
	  lwz       r6, 0x18(r4)
	  lwz       r0, 0x1C(r4)
	  stw       r6, 0x18(r9)
	  stw       r0, 0x1C(r9)
	  lwz       r6, 0x20(r4)
	  lwz       r0, 0x24(r4)
	  stw       r6, 0x20(r9)
	  stw       r0, 0x24(r9)
	  lwz       r6, 0x28(r4)
	  lwz       r0, 0x2C(r4)
	  stw       r6, 0x28(r9)
	  stw       r0, 0x2C(r9)
	  lwz       r6, 0x30(r4)
	  lwz       r0, 0x34(r4)
	  stw       r6, 0x30(r9)
	  stw       r0, 0x34(r9)
	  lwz       r6, 0x38(r4)
	  lwz       r0, 0x3C(r4)
	  stw       r6, 0x38(r9)
	  stw       r0, 0x3C(r9)
	  lwz       r9, 0xF0(r27)
	  lwz       r6, 0x40(r4)
	  lwz       r0, 0x44(r4)
	  add       r8, r9, r8
	  stw       r6, 0x0(r8)
	  stw       r0, 0x4(r8)
	  lwz       r6, 0x48(r4)
	  lwz       r0, 0x4C(r4)
	  stw       r6, 0x8(r8)
	  stw       r0, 0xC(r8)
	  lwz       r6, 0x50(r4)
	  lwz       r0, 0x54(r4)
	  stw       r6, 0x10(r8)
	  stw       r0, 0x14(r8)
	  lwz       r6, 0x58(r4)
	  lwz       r0, 0x5C(r4)
	  stw       r6, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  lwz       r6, 0x60(r4)
	  lwz       r0, 0x64(r4)
	  stw       r6, 0x20(r8)
	  stw       r0, 0x24(r8)
	  lwz       r6, 0x68(r4)
	  lwz       r0, 0x6C(r4)
	  stw       r6, 0x28(r8)
	  stw       r0, 0x2C(r8)
	  lwz       r6, 0x70(r4)
	  lwz       r0, 0x74(r4)
	  stw       r6, 0x30(r8)
	  stw       r0, 0x34(r8)
	  lwz       r6, 0x78(r4)
	  lwz       r0, 0x7C(r4)
	  stw       r6, 0x38(r8)
	  stw       r0, 0x3C(r8)
	  lwz       r8, 0xF0(r27)
	  lwz       r6, 0x80(r4)
	  lwz       r0, 0x84(r4)
	  add       r7, r8, r7
	  stw       r6, 0x0(r7)
	  stw       r0, 0x4(r7)
	  lwz       r6, 0x88(r4)
	  lwz       r0, 0x8C(r4)
	  stw       r6, 0x8(r7)
	  stw       r0, 0xC(r7)
	  lwz       r6, 0x90(r4)
	  lwz       r0, 0x94(r4)
	  stw       r6, 0x10(r7)
	  stw       r0, 0x14(r7)
	  lwz       r6, 0x98(r4)
	  lwz       r0, 0x9C(r4)
	  stw       r6, 0x18(r7)
	  stw       r0, 0x1C(r7)
	  lwz       r6, 0xA0(r4)
	  lwz       r0, 0xA4(r4)
	  stw       r6, 0x20(r7)
	  stw       r0, 0x24(r7)
	  lwz       r6, 0xA8(r4)
	  lwz       r0, 0xAC(r4)
	  stw       r6, 0x28(r7)
	  stw       r0, 0x2C(r7)
	  lwz       r6, 0xB0(r4)
	  lwz       r0, 0xB4(r4)
	  stw       r6, 0x30(r7)
	  stw       r0, 0x34(r7)
	  lwz       r6, 0xB8(r4)
	  lwz       r0, 0xBC(r4)
	  stw       r6, 0x38(r7)
	  stw       r0, 0x3C(r7)
	  lwz       r9, 0xF0(r27)
	  addi      r7, r5, 0xC0
	  lwz       r6, 0xC0(r4)
	  addi      r8, r5, 0x100
	  lwz       r0, 0xC4(r4)
	  add       r9, r9, r7
	  stw       r6, 0x0(r9)
	  addi      r7, r5, 0x140
	  stw       r0, 0x4(r9)
	  lwz       r6, 0xC8(r4)
	  lwz       r0, 0xCC(r4)
	  stw       r6, 0x8(r9)
	  stw       r0, 0xC(r9)
	  lwz       r6, 0xD0(r4)
	  lwz       r0, 0xD4(r4)
	  stw       r6, 0x10(r9)
	  stw       r0, 0x14(r9)
	  lwz       r6, 0xD8(r4)
	  lwz       r0, 0xDC(r4)
	  stw       r6, 0x18(r9)
	  stw       r0, 0x1C(r9)
	  lwz       r6, 0xE0(r4)
	  lwz       r0, 0xE4(r4)
	  stw       r6, 0x20(r9)
	  stw       r0, 0x24(r9)
	  lwz       r6, 0xE8(r4)
	  lwz       r0, 0xEC(r4)
	  stw       r6, 0x28(r9)
	  stw       r0, 0x2C(r9)
	  lwz       r6, 0xF0(r4)
	  lwz       r0, 0xF4(r4)
	  stw       r6, 0x30(r9)
	  stw       r0, 0x34(r9)
	  lwz       r6, 0xF8(r4)
	  lwz       r0, 0xFC(r4)
	  stw       r6, 0x38(r9)
	  stw       r0, 0x3C(r9)
	  lwz       r9, 0xF0(r27)
	  lwz       r6, 0x100(r4)
	  lwz       r0, 0x104(r4)
	  add       r8, r9, r8
	  stw       r6, 0x0(r8)
	  stw       r0, 0x4(r8)
	  lwz       r6, 0x108(r4)
	  lwz       r0, 0x10C(r4)
	  stw       r6, 0x8(r8)
	  stw       r0, 0xC(r8)
	  lwz       r6, 0x110(r4)
	  lwz       r0, 0x114(r4)
	  stw       r6, 0x10(r8)
	  stw       r0, 0x14(r8)
	  lwz       r6, 0x118(r4)
	  lwz       r0, 0x11C(r4)
	  stw       r6, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  lwz       r6, 0x120(r4)
	  lwz       r0, 0x124(r4)
	  stw       r6, 0x20(r8)
	  stw       r0, 0x24(r8)
	  lwz       r6, 0x128(r4)
	  lwz       r0, 0x12C(r4)
	  stw       r6, 0x28(r8)
	  stw       r0, 0x2C(r8)
	  lwz       r6, 0x130(r4)
	  lwz       r0, 0x134(r4)
	  stw       r6, 0x30(r8)
	  stw       r0, 0x34(r8)
	  lwz       r6, 0x138(r4)
	  lwz       r0, 0x13C(r4)
	  stw       r6, 0x38(r8)
	  stw       r0, 0x3C(r8)
	  lwz       r8, 0xF0(r27)
	  lwz       r6, 0x140(r4)
	  lwz       r0, 0x144(r4)
	  add       r7, r8, r7
	  stw       r6, 0x0(r7)
	  stw       r0, 0x4(r7)
	  lwz       r6, 0x148(r4)
	  lwz       r0, 0x14C(r4)
	  stw       r6, 0x8(r7)
	  stw       r0, 0xC(r7)
	  lwz       r6, 0x150(r4)
	  lwz       r0, 0x154(r4)
	  stw       r6, 0x10(r7)
	  stw       r0, 0x14(r7)
	  lwz       r6, 0x158(r4)
	  lwz       r0, 0x15C(r4)
	  stw       r6, 0x18(r7)
	  stw       r0, 0x1C(r7)
	  lwz       r6, 0x160(r4)
	  lwz       r0, 0x164(r4)
	  stw       r6, 0x20(r7)
	  stw       r0, 0x24(r7)
	  lwz       r6, 0x168(r4)
	  lwz       r0, 0x16C(r4)
	  stw       r6, 0x28(r7)
	  stw       r0, 0x2C(r7)
	  lwz       r6, 0x170(r4)
	  lwz       r0, 0x174(r4)
	  stw       r6, 0x30(r7)
	  stw       r0, 0x34(r7)
	  lwz       r6, 0x178(r4)
	  lwz       r0, 0x17C(r4)
	  stw       r6, 0x38(r7)
	  stw       r0, 0x3C(r7)
	  lwz       r9, 0xF0(r27)
	  addi      r8, r5, 0x180
	  lwz       r6, 0x180(r4)
	  addi      r7, r5, 0x1C0
	  lwz       r0, 0x184(r4)
	  add       r8, r9, r8
	  stw       r6, 0x0(r8)
	  addi      r5, r5, 0x200
	  addi      r3, r3, 0x8
	  stw       r0, 0x4(r8)
	  lwz       r6, 0x188(r4)
	  lwz       r0, 0x18C(r4)
	  stw       r6, 0x8(r8)
	  stw       r0, 0xC(r8)
	  lwz       r6, 0x190(r4)
	  lwz       r0, 0x194(r4)
	  stw       r6, 0x10(r8)
	  stw       r0, 0x14(r8)
	  lwz       r6, 0x198(r4)
	  lwz       r0, 0x19C(r4)
	  stw       r6, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  lwz       r6, 0x1A0(r4)
	  lwz       r0, 0x1A4(r4)
	  stw       r6, 0x20(r8)
	  stw       r0, 0x24(r8)
	  lwz       r6, 0x1A8(r4)
	  lwz       r0, 0x1AC(r4)
	  stw       r6, 0x28(r8)
	  stw       r0, 0x2C(r8)
	  lwz       r6, 0x1B0(r4)
	  lwz       r0, 0x1B4(r4)
	  stw       r6, 0x30(r8)
	  stw       r0, 0x34(r8)
	  lwz       r6, 0x1B8(r4)
	  lwz       r0, 0x1BC(r4)
	  stw       r6, 0x38(r8)
	  stw       r0, 0x3C(r8)
	  lwz       r8, 0xF0(r27)
	  lwz       r6, 0x1C0(r4)
	  lwz       r0, 0x1C4(r4)
	  add       r7, r8, r7
	  stw       r6, 0x0(r7)
	  stw       r0, 0x4(r7)
	  lwz       r6, 0x1C8(r4)
	  lwz       r0, 0x1CC(r4)
	  stw       r6, 0x8(r7)
	  stw       r0, 0xC(r7)
	  lwz       r6, 0x1D0(r4)
	  lwz       r0, 0x1D4(r4)
	  stw       r6, 0x10(r7)
	  stw       r0, 0x14(r7)
	  lwz       r6, 0x1D8(r4)
	  lwz       r0, 0x1DC(r4)
	  stw       r6, 0x18(r7)
	  stw       r0, 0x1C(r7)
	  lwz       r6, 0x1E0(r4)
	  lwz       r0, 0x1E4(r4)
	  stw       r6, 0x20(r7)
	  stw       r0, 0x24(r7)
	  lwz       r6, 0x1E8(r4)
	  lwz       r0, 0x1EC(r4)
	  stw       r6, 0x28(r7)
	  stw       r0, 0x2C(r7)
	  lwz       r6, 0x1F0(r4)
	  lwz       r0, 0x1F4(r4)
	  stw       r6, 0x30(r7)
	  stw       r0, 0x34(r7)
	  lwz       r6, 0x1F8(r4)
	  lwz       r0, 0x1FC(r4)
	  addi      r4, r4, 0x200
	  stw       r6, 0x38(r7)
	  stw       r0, 0x3C(r7)
	  bdnz+     .loc_0x14C
	  b         .loc_0xC38

	.loc_0x5BC:
	  subfic    r0, r3, 0x42
	  cmpwi     r3, 0x42
	  mtctr     r0
	  bge-      .loc_0xBDC

	.loc_0x5CC:
	  lwz       r0, 0xF0(r27)
	  lwz       r3, 0x0(r5)
	  add       r4, r0, r6
	  lwz       r0, 0x4(r5)
	  addi      r6, r6, 0x40
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r3, 0x8(r5)
	  lwz       r0, 0xC(r5)
	  stw       r3, 0x8(r4)
	  stw       r0, 0xC(r4)
	  lwz       r3, 0x10(r5)
	  lwz       r0, 0x14(r5)
	  stw       r3, 0x10(r4)
	  stw       r0, 0x14(r4)
	  lwz       r3, 0x18(r5)
	  lwz       r0, 0x1C(r5)
	  stw       r3, 0x18(r4)
	  stw       r0, 0x1C(r4)
	  lwz       r3, 0x20(r5)
	  lwz       r0, 0x24(r5)
	  stw       r3, 0x20(r4)
	  stw       r0, 0x24(r4)
	  lwz       r3, 0x28(r5)
	  lwz       r0, 0x2C(r5)
	  stw       r3, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  lwz       r3, 0x30(r5)
	  lwz       r0, 0x34(r5)
	  stw       r3, 0x30(r4)
	  stw       r0, 0x34(r4)
	  lwz       r3, 0x38(r5)
	  lwz       r0, 0x3C(r5)
	  addi      r5, r5, 0x40
	  stw       r3, 0x38(r4)
	  stw       r0, 0x3C(r4)
	  bdnz+     .loc_0x5CC
	  b         .loc_0xBDC

	.loc_0x664:
	  lbz       r0, 0x4(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0xBDC
	  li        r0, 0x8
	  li        r4, 0
	  mtctr     r0
	  addi      r3, r4, 0

	.loc_0x680:
	  lwz       r5, 0xF4(r27)
	  addi      r8, r3, 0x40
	  lwz       r0, 0xF0(r27)
	  addi      r7, r3, 0x80
	  add       r6, r5, r3
	  lwz       r5, 0x0(r6)
	  add       r9, r0, r3
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x0(r9)
	  stw       r0, 0x4(r9)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r9)
	  stw       r0, 0xC(r9)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r9)
	  stw       r0, 0x14(r9)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r9)
	  stw       r0, 0x1C(r9)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r9)
	  stw       r0, 0x24(r9)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r9)
	  stw       r0, 0x2C(r9)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r9)
	  stw       r0, 0x34(r9)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r9)
	  stw       r0, 0x3C(r9)
	  lwz       r5, 0xF4(r27)
	  lwz       r0, 0xF0(r27)
	  add       r6, r5, r8
	  lwz       r5, 0x0(r6)
	  add       r8, r0, r8
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x0(r8)
	  stw       r0, 0x4(r8)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r8)
	  stw       r0, 0xC(r8)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r8)
	  stw       r0, 0x14(r8)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r8)
	  stw       r0, 0x24(r8)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r8)
	  stw       r0, 0x2C(r8)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r8)
	  stw       r0, 0x34(r8)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r8)
	  stw       r0, 0x3C(r8)
	  lwz       r5, 0xF4(r27)
	  lwz       r0, 0xF0(r27)
	  add       r6, r5, r7
	  lwz       r5, 0x0(r6)
	  add       r7, r0, r7
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x0(r7)
	  stw       r0, 0x4(r7)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r7)
	  stw       r0, 0xC(r7)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r7)
	  stw       r0, 0x14(r7)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r7)
	  stw       r0, 0x1C(r7)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r7)
	  stw       r0, 0x24(r7)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r7)
	  stw       r0, 0x2C(r7)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r7)
	  stw       r0, 0x34(r7)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r7)
	  stw       r0, 0x3C(r7)
	  lwz       r5, 0xF4(r27)
	  addi      r7, r3, 0xC0
	  lwz       r0, 0xF0(r27)
	  addi      r8, r3, 0x100
	  add       r6, r5, r7
	  lwz       r5, 0x0(r6)
	  add       r9, r0, r7
	  lwz       r0, 0x4(r6)
	  addi      r7, r3, 0x140
	  stw       r5, 0x0(r9)
	  stw       r0, 0x4(r9)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r9)
	  stw       r0, 0xC(r9)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r9)
	  stw       r0, 0x14(r9)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r9)
	  stw       r0, 0x1C(r9)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r9)
	  stw       r0, 0x24(r9)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r9)
	  stw       r0, 0x2C(r9)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r9)
	  stw       r0, 0x34(r9)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r9)
	  stw       r0, 0x3C(r9)
	  lwz       r5, 0xF4(r27)
	  lwz       r0, 0xF0(r27)
	  add       r6, r5, r8
	  lwz       r5, 0x0(r6)
	  add       r8, r0, r8
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x0(r8)
	  stw       r0, 0x4(r8)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r8)
	  stw       r0, 0xC(r8)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r8)
	  stw       r0, 0x14(r8)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r8)
	  stw       r0, 0x24(r8)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r8)
	  stw       r0, 0x2C(r8)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r8)
	  stw       r0, 0x34(r8)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r8)
	  stw       r0, 0x3C(r8)
	  lwz       r5, 0xF4(r27)
	  lwz       r0, 0xF0(r27)
	  add       r6, r5, r7
	  lwz       r5, 0x0(r6)
	  add       r7, r0, r7
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x0(r7)
	  stw       r0, 0x4(r7)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r7)
	  stw       r0, 0xC(r7)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r7)
	  stw       r0, 0x14(r7)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r7)
	  stw       r0, 0x1C(r7)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r7)
	  stw       r0, 0x24(r7)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r7)
	  stw       r0, 0x2C(r7)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r7)
	  stw       r0, 0x34(r7)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r7)
	  stw       r0, 0x3C(r7)
	  lwz       r5, 0xF4(r27)
	  addi      r8, r3, 0x180
	  lwz       r0, 0xF0(r27)
	  addi      r7, r3, 0x1C0
	  add       r6, r5, r8
	  add       r8, r0, r8
	  lwz       r5, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  addi      r3, r3, 0x200
	  addi      r4, r4, 0x8
	  stw       r5, 0x0(r8)
	  stw       r0, 0x4(r8)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r8)
	  stw       r0, 0xC(r8)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r8)
	  stw       r0, 0x14(r8)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r8)
	  stw       r0, 0x1C(r8)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r8)
	  stw       r0, 0x24(r8)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r8)
	  stw       r0, 0x2C(r8)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r8)
	  stw       r0, 0x34(r8)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r8)
	  stw       r0, 0x3C(r8)
	  lwz       r5, 0xF4(r27)
	  lwz       r0, 0xF0(r27)
	  add       r6, r5, r7
	  add       r7, r0, r7
	  lwz       r5, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x0(r7)
	  stw       r0, 0x4(r7)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x8(r7)
	  stw       r0, 0xC(r7)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x10(r7)
	  stw       r0, 0x14(r7)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x18(r7)
	  stw       r0, 0x1C(r7)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x20(r7)
	  stw       r0, 0x24(r7)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0x28(r7)
	  stw       r0, 0x2C(r7)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0x30(r7)
	  stw       r0, 0x34(r7)
	  lwz       r5, 0x38(r6)
	  lwz       r0, 0x3C(r6)
	  stw       r5, 0x38(r7)
	  stw       r0, 0x3C(r7)
	  bdnz+     .loc_0x680
	  b         .loc_0xC48

	.loc_0xB2C:
	  subfic    r0, r4, 0x42
	  cmpwi     r4, 0x42
	  mtctr     r0
	  bge-      .loc_0xBD4

	.loc_0xB3C:
	  lwz       r3, 0xF4(r27)
	  lwz       r0, 0xF0(r27)
	  add       r4, r3, r6
	  add       r5, r0, r6
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  addi      r6, r6, 0x40
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  stw       r3, 0x8(r5)
	  stw       r0, 0xC(r5)
	  lwz       r3, 0x10(r4)
	  lwz       r0, 0x14(r4)
	  stw       r3, 0x10(r5)
	  stw       r0, 0x14(r5)
	  lwz       r3, 0x18(r4)
	  lwz       r0, 0x1C(r4)
	  stw       r3, 0x18(r5)
	  stw       r0, 0x1C(r5)
	  lwz       r3, 0x20(r4)
	  lwz       r0, 0x24(r4)
	  stw       r3, 0x20(r5)
	  stw       r0, 0x24(r5)
	  lwz       r3, 0x28(r4)
	  lwz       r0, 0x2C(r4)
	  stw       r3, 0x28(r5)
	  stw       r0, 0x2C(r5)
	  lwz       r3, 0x30(r4)
	  lwz       r0, 0x34(r4)
	  stw       r3, 0x30(r5)
	  stw       r0, 0x34(r5)
	  lwz       r3, 0x38(r4)
	  lwz       r0, 0x3C(r4)
	  stw       r3, 0x38(r5)
	  stw       r0, 0x3C(r5)
	  bdnz+     .loc_0xB3C

	.loc_0xBD4:
	  li        r0, 0
	  stb       r0, 0x4(r27)

	.loc_0xBDC:
	  addi      r3, r27, 0
	  addi      r4, r1, 0x9C
	  bl        -0x138C
	  addi      r3, r27, 0
	  addi      r4, r1, 0x9C
	  bl        -0xE20
	  li        r27, 0
	  rlwinm    r0,r27,6,0,25
	  addi      r30, r1, 0x9C
	  add       r30, r30, r0

	.loc_0xC04:
	  lwz       r3, 0x0(r28)
	  mr        r4, r27
	  bl        -0x140344
	  lwz       r6, 0x2E4(r29)
	  addi      r5, r3, 0
	  addi      r4, r30, 0
	  addi      r3, r6, 0x1E0
	  bl        -0x13726C
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x42
	  addi      r30, r30, 0x40
	  blt+      .loc_0xC04
	  b         .loc_0xC50

	.loc_0xC38:
	  rlwinm    r6,r3,6,0,25
	  addi      r5, r1, 0x9C
	  add       r5, r5, r6
	  b         .loc_0x5BC

	.loc_0xC48:
	  rlwinm    r6,r4,6,0,25
	  b         .loc_0xB2C

	.loc_0xC50:
	  lmw       r27, 0x1124(r1)
	  lwz       r0, 0x114C(r1)
	  lfd       f31, 0x1140(r1)
	  lfd       f30, 0x1138(r1)
	  addi      r1, r1, 0x1148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175528
 * Size:	000080
 */
bool KingGenRippleCallBack::invoke(zen::particleGenerator* ptcl)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lwz       r5, 0xC(r3)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0x1C(r1)
	  lwz       r5, 0x8(r3)
	  lfs       f0, 0x98(r5)
	  stfs      f0, 0x18(r1)
	  lwz       r5, 0x14(r1)
	  lwz       r0, 0x18(r1)
	  stw       r5, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x14(r4)
	  lwz       r5, 0x8(r3)
	  lfs       f0, -0x5320(r2)
	  lfs       f1, 0x2C4(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x68
	  lwz       r3, 0x4(r3)
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x74

	.loc_0x68:
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x74:
	  li        r3, 0x1
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801755A8
 * Size:	0001AC
 */
bool KingGenSpitPartsParticleCallBack::invoke(zen::particleGenerator*, zen::particleMdl*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  addi      r0, r1, 0x14
	  addi      r6, r1, 0x1C
	  stw       r31, 0x54(r1)
	  addi      r3, r1, 0x20
	  stw       r30, 0x50(r1)
	  addi      r30, r4, 0
	  mr        r4, r0
	  stw       r29, 0x4C(r1)
	  mr        r29, r5
	  lfs       f1, 0x14(r5)
	  lfs       f0, 0x20(r5)
	  addi      r5, r1, 0x18
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r1)
	  lfs       f1, 0x10(r29)
	  lfs       f0, 0x1C(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lfs       f1, 0xC(r29)
	  lfs       f0, 0x18(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r1)
	  bl        -0x13E4F4
	  lfs       f1, 0x20(r1)
	  li        r4, 0x1
	  lfs       f0, 0x24(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x10D738
	  fmr       f31, f1
	  lfs       f0, 0x3C(r1)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x188
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x10D488
	  mr.       r31, r3
	  beq-      .loc_0x188
	  lfs       f0, 0x28(r31)
	  mr        r3, r29
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x2C(r31)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x30(r31)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x2C(r1)
	  lfs       f1, -0x52E4(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x30(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  stfs      f31, 0x3C(r1)
	  lwz       r12, 0x0(r29)
	  lwz       r30, 0x1D0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x38
	  li        r4, 0x77
	  li        r6, 0
	  li        r7, 0
	  bl        0x27444
	  cmplwi    r3, 0
	  beq-      .loc_0x188
	  lwz       r4, 0x18(r31)
	  lwz       r0, 0x1C(r31)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x20(r31)
	  stw       r0, 0x1E4(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0xA8(r3)

	.loc_0x188:
	  lwz       r0, 0x64(r1)
	  li        r3, 0x1
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175754
 * Size:	00001C
 */
void zen::zenList::insertAfter(zen::zenList*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x8(r4)
	  stw       r3, 0x4(r4)
	  lwz       r5, 0x8(r3)
	  stw       r4, 0x4(r5)
	  stw       r4, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175770
 * Size:	00001C
 */
void zen::zenList::remove()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x4(r3)
	  lwz       r4, 0x8(r3)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017578C
 * Size:	00002C
 */
bool KingGenDamageStarCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x24
	  cmpwi     r0, 0x2
	  beq-      .loc_0x24
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x24:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801757B8
 * Size:	000200
 */
bool KingGenSalivaParticleCallBack::invoke(zen::particleGenerator* ptcl, zen::particleMdl* mdl)
{
	if (mdl->_2E == 0) {
		mdl->_34.x += (mKing->mKingBody->_D8.x - mKing->mKingBody->_E4.x) / 2.0f;
		mdl->_34.z += (mKing->mKingBody->_D8.z - mKing->mKingBody->_E4.z) / 2.0f;
	}

	Vector3f mdlPos = mdl->getPos();
	f32 minY        = mapMgr->getMinY(mdlPos.x, mdlPos.z, true);

	if (minY > mdlPos.y) {
		CollTriInfo* currTri = mapMgr->getCurrTri(mdlPos.x, mdlPos.z, true);
		if (currTri) {
			Vector3f norm(currTri->_28[0].mNormal);
			norm.multiply(0.01f);
			mdlPos.y = minY;

			zen::particleGenerator* newPtcl = effectMgr->create(EffectMgr::EFF_Unk119, mdlPos, nullptr, nullptr);
			if (newPtcl) {
				newPtcl->set1DC(currTri->_18);
				newPtcl->setEmitDir(norm);
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x4C(r1)
	  mr        r29, r5
	  lha       r0, 0x2E(r5)
	  cmpwi     r0, 0
	  bne-      .loc_0x7C
	  lwz       r4, 0x4(r3)
	  lfs       f3, -0x52E8(r2)
	  lwz       r4, 0x3C0(r4)
	  lfs       f2, 0x34(r29)
	  lfs       f1, 0xD8(r4)
	  lfs       f0, 0xE4(r4)
	  fsubs     f0, f1, f0
	  fmuls     f0, f0, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x34(r29)
	  lwz       r3, 0x4(r3)
	  lfs       f2, 0x3C(r29)
	  lwz       r3, 0x3C0(r3)
	  lfs       f1, 0xE0(r3)
	  lfs       f0, 0xEC(r3)
	  fsubs     f0, f1, f0
	  fmuls     f0, f0, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x3C(r29)

	.loc_0x7C:
	  lfs       f1, 0x14(r29)
	  addi      r6, r1, 0x1C
	  lfs       f0, 0x20(r29)
	  addi      r5, r1, 0x18
	  addi      r4, r1, 0x14
	  fadds     f0, f1, f0
	  addi      r3, r1, 0x20
	  stfs      f0, 0x1C(r1)
	  lfs       f1, 0x10(r29)
	  lfs       f0, 0x1C(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lfs       f1, 0xC(r29)
	  lfs       f0, 0x18(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r1)
	  bl        -0x13E758
	  lfs       f1, 0x20(r1)
	  li        r4, 0x1
	  lfs       f0, 0x24(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x10D99C
	  fmr       f31, f1
	  lfs       f0, 0x3C(r1)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x1DC
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x10D6EC
	  mr.       r31, r3
	  beq-      .loc_0x1DC
	  lfs       f0, 0x28(r31)
	  mr        r3, r29
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x2C(r31)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x30(r31)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x2C(r1)
	  lfs       f1, -0x52E4(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x30(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  stfs      f31, 0x3C(r1)
	  lwz       r12, 0x0(r29)
	  lwz       r30, 0x1D0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x38
	  li        r4, 0x77
	  li        r6, 0
	  li        r7, 0
	  bl        0x271E0
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  lwz       r4, 0x18(r31)
	  lwz       r0, 0x1C(r31)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x20(r31)
	  stw       r0, 0x1E4(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0xA0(r3)
	  stw       r0, 0xA4(r3)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0xA8(r3)

	.loc_0x1DC:
	  lwz       r0, 0x64(r1)
	  li        r3, 0x1
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}
