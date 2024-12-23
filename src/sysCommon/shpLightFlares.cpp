#include "Light.h"
#include "Matrix4f.h"
#include "CmdStream.h"
#include "Shape.h"
#include "stl/stdio.h"
#include "stl/string.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void LightFlare::loadini(CmdStream* commands)
{
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);

		if (commands->isToken("size")) {
			sscanf(commands->getToken(true), "%f", &mSize);
			continue;
		}

		if (commands->isToken("pos")) {
			sscanf(commands->getToken(true), "%f", &mPosition.x);
			sscanf(commands->getToken(true), "%f", &mPosition.y);
			sscanf(commands->getToken(true), "%f", &mPosition.z);
			continue;
		}
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void LightFlare::saveini(char*, RandomAccessStream&)
{
	mName = "NULL";
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E8
 */
void LightGroup::saveini(char*, RandomAccessStream&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80035B38
 * Size:	000420
 */
void LightGroup::loadini(CmdStream* commands)
{
	while (!commands->endOfCmds() && !commands->endOfSection()) {
		commands->getToken(true);
		if (commands->isToken("type")) {
			sscanf(commands->getToken(true), "%d", &mType);
			continue;
		}

		if (commands->isToken("flags")) {
			sscanf(commands->getToken(true), "%d", &mFlags);
			continue;
		}

		if (commands->isToken("dir")) {
			sscanf(commands->getToken(true), "%f", &mDirection.x);
			sscanf(commands->getToken(true), "%f", &mDirection.y);
			sscanf(commands->getToken(true), "%f", &mDirection.z);
			continue;
		}

		if (commands->isToken("colour")) {
			u32 r;
			sscanf(commands->getToken(true), "%d", &r);
			u32 g;
			sscanf(commands->getToken(true), "%d", &g);
			u32 b;
			sscanf(commands->getToken(true), "%d", &b);
			u32 a;
			sscanf(commands->getToken(true), "%d", &a);

			mLightColour.set(r, g, b, a);
			continue;
		}

		if (commands->isToken("texture")) {
			char* texSrc = commands->getToken(true);
			if (strcmp(texSrc, "NULL") != 0) {
				mTexSource = (s8*)StdSystem::stringDup(texSrc);
			} else {
				mTexSource = nullptr;
			}
			continue;
		}

		if (commands->isToken("material")) {
			char* matSrc = commands->getToken(true);
			if (strcmp(matSrc, "NULL") != 0) {
				mMatSource = (s8*)StdSystem::stringDup(matSrc);
			} else {
				mMatSource = nullptr;
			}
			continue;
		}

		if (commands->isToken("lightflare")) {
			commands->getToken(true);
			LightFlare* flare = new LightFlare();

			flare->loadini(commands);

			mFlares.add(flare);
		}
	}

	if (!commands->endOfCmds()) {
		commands->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	80035F58
 * Size:	0001CC
 */
void LightGroup::refresh(Graphics& gfx, Matrix4f* lightMtx)
{
	if (!mFlares.mChild) {
		return;
	}

	if (!mFlareGroup) {
		return;
	}

	Matrix4f& mtx = (mJointIndex == -1) ? *lightMtx : _64->getAnimMatrix(mJointIndex);

	FOREACH_NODE(LightFlare, mFlares.mChild, flare)
	{
		Vector3f flarePos = flare->mPosition;
		flarePos.multMatrix(mtx);

		f32 dim = std::sqrtf(mtx.mMtx[0][0] * mtx.mMtx[0][0] + mtx.mMtx[0][1] * mtx.mMtx[0][1] + mtx.mMtx[0][2] * mtx.mMtx[0][2]);
		Vector2f size;
		size.x = flare->mSize * dim;
		size.y = flare->mSize * dim;

		LFlareGroup* group = getLFlareGroup();
		LFInfo* info       = gsys->getLFlareInfo();
		if (info) {
			info->mColour   = mLightColour;
			info->mFlarePos = flarePos;
			info->_10       = size;
			info->_18       = 0.0f;
			info->_1C       = 0.0f;
			info->_20       = 1.0f;
			info->_24       = 1.0f;

			info->mPrevInfo = group->mLFInfo;
			group->mLFInfo  = info;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stfd      f29, 0x50(r1)
	  stfd      f28, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  lwz       r0, 0x50(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  lwz       r0, 0x68(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  lwz       r4, 0x1C(r31)
	  addis     r0, r4, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x60
	  mr        r29, r5
	  b         .loc_0x6C

	.loc_0x60:
	  lwz       r3, 0x64(r31)
	  bl        -0xFD4
	  mr        r29, r3

	.loc_0x6C:
	  lwz       r28, 0x50(r31)
	  lfs       f29, -0x7CB0(r2)
	  lfd       f30, -0x7CA8(r2)
	  lfd       f31, -0x7CA0(r2)
	  lfs       f28, -0x7C98(r2)
	  b         .loc_0x194

	.loc_0x84:
	  lfs       f0, 0x18(r28)
	  addi      r4, r29, 0
	  addi      r3, r1, 0x28
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x1C(r28)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x20(r28)
	  stfs      f0, 0x30(r1)
	  bl        0x1750
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x120
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x1C(r1)
	  lfs       f2, 0x1C(r1)

	.loc_0x120:
	  lfs       f0, 0x14(r28)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r30, 0x68(r31)
	  bl        0x99E4
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  lwz       r0, 0x30(r31)
	  stw       r0, 0x0(r3)
	  lwz       r4, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0xC(r3)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  stfs      f29, 0x18(r3)
	  stfs      f29, 0x1C(r3)
	  stfs      f28, 0x20(r3)
	  stfs      f28, 0x24(r3)
	  lwz       r0, 0x20(r30)
	  stw       r0, 0x28(r3)
	  stw       r3, 0x20(r30)

	.loc_0x190:
	  lwz       r28, 0xC(r28)

	.loc_0x194:
	  cmplwi    r28, 0
	  bne+      .loc_0x84

	.loc_0x19C:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lfd       f29, 0x50(r1)
	  lfd       f28, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}
