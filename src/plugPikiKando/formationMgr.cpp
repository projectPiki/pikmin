#include "FormationMgr.h"
#include "Graphics.h"
#include "system.h"
#include "GlobalShape.h"
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
DEFINE_PRINT("formation")

/*
 * --INFO--
 * Address:	8007DF5C
 * Size:	000010
 */
Creature* FormationMgr::getCreature(int idx)
{
	return mFormMembers[idx];
}

/*
 * --INFO--
 * Address:	8007DF6C
 * Size:	000008
 */
int FormationMgr::getFirst()
{
	return 0;
}

/*
 * --INFO--
 * Address:	8007DF74
 * Size:	000008
 */
int FormationMgr::getNext(int idx)
{
	return idx + 1;
}

/*
 * --INFO--
 * Address:	8007DF7C
 * Size:	00001C
 */
bool FormationMgr::isDone(int idx)
{
	if (idx >= mCount) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8007DF98
 * Size:	0000E0
 */
Vector3f FormPoint::getPos()
{
	f32 angle = mFormMgr->_0C;
	Vector3f pos(sinf(angle) * _18.x + cosf(angle) * _18.z, 0.0f, cosf(angle) * _18.x - sinf(angle) * _18.z);
	pos = pos + mFormMgr->_10;
	return pos + mOffset;
}

/*
 * --INFO--
 * Address:	8007E078
 * Size:	0000A8
 */
Vector3f FormationMgr::getLastCentre()
{
	f32 angle  = _0C;
	f32 radius = -mArranger->getLength(this);
	Vector3f centre(radius * sinf(angle), 0.0f, radius * cosf(angle));
	centre = centre + _10;
	return centre;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
FormationMgr::FormationMgr()
{
	mMax         = 300;
	_24          = 0;
	_0C          = 0.0f;
	mFormPoints  = new FormPoint[mMax];
	mFormMembers = new Creature*[mMax];
	for (int i = 0; i < mMax; i++) {
		mFormPoints[i].setMgr(this);
		mFormMembers[i] = nullptr;
	}

	mCount = 0;
	clear();
	_10.set(0.0f, 0.0f, 0.0f);
	mOffset.set(0.0f, 0.0f, 0.0f);
	mAngOffset = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
FormPoint::FormPoint()
{
	mOwner.clear();
	mOffset.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8007E128
 * Size:	0001E4
 */
FormPoint* FormationMgr::getFormPoint(Creature* target)
{
	int replaceIdx      = -1;
	Creature* toReplace = nullptr;
	int i;
	for (i = 0; i < _24; i++) {
		toReplace = mFormPoints[i].getOwner();
		if (!mFormPoints[i].isFree()) {
			if (toReplace->getFormationPri() > target->getFormationPri()) {
				replaceIdx = i;
				break;
			}
		}
	}

	int freeIdx = -1;
	for (i = 0; i < mMax; i++) {
		if (mFormPoints[i].isFree()) {
			freeIdx = i;
			break;
		}
	}

	if (replaceIdx != -1) {
		// replace member
		mFormPoints[replaceIdx].setOwner(target);
		for (int j = 0; j < mCount; j++) {
			if (mFormMembers[j] == toReplace) {
				mFormMembers[j] = target;
			}
		}
		// insert replaced member one over
		slide(toReplace, replaceIdx + 1);
		return &mFormPoints[replaceIdx];
	}

	if (freeIdx == -1) {
		ERROR("no empty index for formation : numClients=%d\n", mCount);
	}

	mFormPoints[freeIdx].setOwner(target);
	mFormMembers[mCount++] = target;
	return &mFormPoints[freeIdx];
}

/*
 * --INFO--
 * Address:	8007E30C
 * Size:	0001F4
 */
void FormationMgr::slide(Creature* target, int idx)
{
	int replaceIdx      = -1;
	Creature* toReplace = nullptr;

	for (int i = 0; i < mCount; i++) {
		toReplace = mFormPoints[i].getOwner();
		if (!mFormPoints[i].isFree()) {
			if (toReplace->getFormationPri() > target->getFormationPri()) {
				replaceIdx = i;
				break;
			}
		}
	}

	if (replaceIdx != -1) {
		mFormPoints[replaceIdx].setOwner(target);
		for (int i = 0; i < mCount; i++) {
			if (mFormMembers[i] == toReplace) {
				mFormMembers[i] = target;
			}
		}

		target->mFormPoint    = &mFormPoints[replaceIdx];
		toReplace->mFormPoint = nullptr;
		slide(toReplace, idx + 1);
		return;
	}

	int freeIdx = -1;
	for (int i = 0; i < _24; i++) {
		if (mFormPoints[i].isFree()) {
			freeIdx = i;
			break;
		}
	}

	mFormPoints[freeIdx].setOwner(target);
	mFormMembers[mCount++] = target;
	target->mFormPoint     = &mFormPoints[freeIdx];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void FormationMgr::add(Vector3f& p1, Vector3f& p2)
{
	Colour col;
	// something is going on with this re: instruction ordering :(
	col.set(255.0f * p2.x, 255.0f * p2.y, 255.0f * p2.z, 255);
	mFormPoints[_24].reset();
	mFormPoints[_24]._18 = p1;
	mFormPoints[_24]._00 = col;
	_24++;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int FormationMgr::getIndex(Creature* target)
{
	for (int i = 0; i < mCount; i++) {
		if (mFormMembers[i] == target) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
int FormationMgr::getFptIndex(FormPoint* point)
{
	for (int i = 0; i < _24; i++) {
		if (point == &mFormPoints[i]) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	8007E500
 * Size:	0001A0
 */
void FormationMgr::exit(Creature* target)
{
	int i;
	int idx = getIndex(target);
	if (idx == -1) {
		return;
	}

	if (mCount == 1) {
		mFormMembers[0]->mFormPoint->reset();
		mCount = 0;
		return;
	}

	int ptIdx = getFptIndex(target->mFormPoint);
	for (i = idx; i < mCount - 1; i++) {
		mFormMembers[i]             = mFormMembers[i + 1];
		mFormMembers[i]->mFormPoint = &mFormPoints[ptIdx];
		mFormMembers[i]->mFormPoint->setOwner(mFormMembers[i]);
		ptIdx++;
	}

	mFormPoints[ptIdx].reset();
	mCount--;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void FormationMgr::clear()
{
	for (int i = 0; i < mMax; i++) {
		mFormPoints[i].reset();
	}

	for (int i = 0; i < mCount; i++) {
		if (mFormMembers[i]) {
			mFormMembers[i]->mFormPoint = nullptr;
			mFormMembers[i]             = nullptr;
		}
	}

	mCount = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void FormationMgr::rearrange()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void FormationMgr::setOffset(Vector3f& offset)
{
	mOffset = offset;
	for (int i = 0; i < mMax; i++) {
		mFormPoints[i].mOffset = mOffset;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void FormationMgr::setAngOffset(f32 offset)
{
	mAngOffset = offset;
}

/*
 * --INFO--
 * Address:	8007E6A0
 * Size:	000300
 */
void CircleArranger::arrange(FormationMgr* mgr)
{
	Vector3f vec(1.0f, 0.0f, 0.0f);
	Vector3f vec2(1.0f, 1.0f, 0.0f);
	f32 val1 = 0.0f;
	f32 val2 = 40.0f;
	f32 val3 = HALF_PI;
	int i    = 0;
	while (i < 300) {
		f32 angle = val3;
		int j     = 0;
		while (j < 4) {
			Vector3f vec3;
			vec3.set(val2 * cosf(angle), 0.0f, val2 * sinf(angle));
			Vector3f vec4 = (1.0f - val1) * vec + val1 * vec2;
			mgr->add(vec3, vec4);
			angle += HALF_PI;
			j++;
			i++;
		}

		val3 *= 0.5f;
		if (val3 * val2 < 30.0f) {
			val2 = 30.0f + val2;
			val3 = HALF_PI;
			val1 += 0.1f;
			if (val1 >= 1.0f) {
				val1 = 1.0f;
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1A8(r1)
	  stfd      f31, 0x1A0(r1)
	  stfd      f30, 0x198(r1)
	  stfd      f29, 0x190(r1)
	  stfd      f28, 0x188(r1)
	  stfd      f27, 0x180(r1)
	  stfd      f26, 0x178(r1)
	  stfd      f25, 0x170(r1)
	  stfd      f24, 0x168(r1)
	  stfd      f23, 0x160(r1)
	  stfd      f22, 0x158(r1)
	  stfd      f21, 0x150(r1)
	  stfd      f20, 0x148(r1)
	  stfd      f19, 0x140(r1)
	  stfd      f18, 0x138(r1)
	  stfd      f17, 0x130(r1)
	  stfd      f16, 0x128(r1)
	  stfd      f15, 0x120(r1)
	  stfd      f14, 0x118(r1)
	  stmw      r23, 0xF4(r1)
	  mr        r23, r4
	  addi      r31, r1, 0x44
	  addi      r30, r1, 0x40
	  addi      r29, r1, 0x3C
	  addi      r28, r1, 0x38
	  addi      r27, r1, 0x34
	  addi      r26, r1, 0x30
	  li        r25, 0
	  lfs       f0, -0x6200(r13)
	  lfs       f19, -0x7678(r2)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, -0x61FC(r13)
	  fmr       f30, f19
	  lfs       f18, -0x766C(r2)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, -0x61F8(r13)
	  fmr       f20, f18
	  lfs       f17, -0x7668(r2)
	  stfs      f0, 0xB8(r1)
	  lfs       f0, -0x61F4(r13)
	  lfs       f14, -0x61F0(r13)
	  stfs      f0, 0xB4(r1)
	  lfs       f0, -0x7664(r2)
	  lfs       f15, -0x61EC(r13)
	  stfd      f0, 0xC8(r1)
	  lfs       f0, -0x765C(r2)
	  lfs       f28, -0x7670(r2)
	  lfs       f29, -0x7674(r2)
	  lfs       f16, -0x7660(r2)
	  stfd      f0, 0xD0(r1)
	  b         .loc_0x29C

	.loc_0xD4:
	  lfs       f0, 0xB4(r1)
	  fsubs     f1, f17, f19
	  fmr       f31, f18
	  li        r24, 0
	  fmuls     f26, f0, f19
	  lfs       f0, 0xB8(r1)
	  fmuls     f24, f15, f19
	  fmuls     f23, f0, f1
	  lfs       f0, 0xBC(r1)
	  fmuls     f25, f14, f19
	  fmuls     f22, f0, f1
	  lfs       f0, 0xC0(r1)
	  fmuls     f21, f0, f1

	.loc_0x108:
	  stfs      f30, 0x98(r1)
	  fmr       f1, f31
	  stfs      f30, 0x94(r1)
	  stfs      f30, 0x90(r1)
	  bl        0x19D530
	  fmuls     f27, f28, f1
	  fmr       f1, f31
	  bl        0x19D390
	  fmuls     f1, f28, f1
	  lfs       f0, -0x61E8(r13)
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  stfs      f1, 0x90(r1)
	  mr        r6, r31
	  stfs      f0, 0x94(r1)
	  addi      r3, r1, 0x5C
	  stfs      f27, 0x98(r1)
	  stfs      f24, 0x44(r1)
	  stfs      f25, 0x40(r1)
	  stfs      f26, 0x3C(r1)
	  bl        -0x476DC
	  stfs      f23, 0x38(r1)
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  stfs      f22, 0x34(r1)
	  addi      r6, r28, 0
	  addi      r3, r1, 0x6C
	  stfs      f21, 0x30(r1)
	  bl        -0x476FC
	  lfs       f1, 0x6C(r1)
	  li        r0, 0xFF
	  lfs       f0, 0x5C(r1)
	  lfs       f3, 0x70(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0x60(r1)
	  lfs       f2, 0x74(r1)
	  fadds     f3, f3, f1
	  lfs       f1, 0x64(r1)
	  fadds     f1, f2, f1
	  fmuls     f0, f29, f0
	  fmuls     f2, f29, f3
	  fmuls     f1, f29, f1
	  fctiwz    f0, f0
	  fctiwz    f2, f2
	  stfd      f0, 0xE8(r1)
	  fctiwz    f0, f1
	  stfd      f2, 0xE0(r1)
	  lwz       r5, 0xEC(r1)
	  stfd      f0, 0xD8(r1)
	  lwz       r4, 0xE4(r1)
	  stb       r5, 0x58(r1)
	  lwz       r3, 0xDC(r1)
	  stb       r4, 0x59(r1)
	  stb       r3, 0x5A(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r0, 0x24(r23)
	  lwz       r3, 0x1C(r23)
	  mulli     r0, r0, 0x24
	  add       r3, r3, r0
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x208
	  li        r0, 0
	  stw       r0, 0x10(r3)

	.loc_0x208:
	  lwz       r0, 0x24(r23)
	  addi      r24, r24, 0x1
	  lwz       r5, 0x1C(r23)
	  cmpwi     r24, 0x4
	  mulli     r4, r0, 0x24
	  lwz       r3, 0x90(r1)
	  fadds     f31, f31, f20
	  lwz       r0, 0x94(r1)
	  addi      r4, r4, 0x18
	  add       r4, r5, r4
	  stw       r3, 0x0(r4)
	  addi      r25, r25, 0x1
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x8(r4)
	  lwz       r0, 0x24(r23)
	  lwz       r4, 0x1C(r23)
	  mulli     r3, r0, 0x24
	  lwz       r0, 0x58(r1)
	  stwx      r0, r4, r3
	  lwz       r3, 0x24(r23)
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r23)
	  blt+      .loc_0x108
	  lfd       f0, 0xC8(r1)
	  fmuls     f18, f18, f0
	  fmuls     f0, f18, f28
	  fcmpo     cr0, f0, f16
	  bge-      .loc_0x29C
	  lfd       f0, 0xD0(r1)
	  fadds     f28, f16, f28
	  lfs       f18, -0x766C(r2)
	  fadds     f19, f19, f0
	  fcmpo     cr0, f19, f17
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x29C
	  fmr       f19, f17

	.loc_0x29C:
	  cmpwi     r25, 0x12C
	  blt+      .loc_0xD4
	  lmw       r23, 0xF4(r1)
	  lwz       r0, 0x1AC(r1)
	  lfd       f31, 0x1A0(r1)
	  lfd       f30, 0x198(r1)
	  lfd       f29, 0x190(r1)
	  lfd       f28, 0x188(r1)
	  lfd       f27, 0x180(r1)
	  lfd       f26, 0x178(r1)
	  lfd       f25, 0x170(r1)
	  lfd       f24, 0x168(r1)
	  lfd       f23, 0x160(r1)
	  lfd       f22, 0x158(r1)
	  lfd       f21, 0x150(r1)
	  lfd       f20, 0x148(r1)
	  lfd       f19, 0x140(r1)
	  lfd       f18, 0x138(r1)
	  lfd       f17, 0x130(r1)
	  lfd       f16, 0x128(r1)
	  lfd       f15, 0x120(r1)
	  lfd       f14, 0x118(r1)
	  addi      r1, r1, 0x1A8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007E9A0
 * Size:	0002B8
 */
void PyramidArranger::arrange(FormationMgr* mgr)
{
	Vector3f vec(0.0f, 1.0f, 0.0f);
	Vector3f vec2(0.5f, 1.0f, 0.0f);
	f32 val1 = 0.0f;
	int j    = 1;
	f32 val2 = 26.0f;
	Vector3f vec3(-val2, 0.0f, 0.0f);
	int k   = 1;
	f32 dir = -1.0f;
	for (int i = 0; i < 300; i++) {
		Vector3f vec4 = (1.0f - val1) * vec + val1 * vec2;
		mgr->add(vec3, vec4);
		if (k >= j) {
			j++;
			vec3.x -= val2;
			vec3.z = dir * (j / 2) * val2;
			dir    = -dir;
			k      = 1;
			val1 += 0.1f;
			if (val1 >= 1.0f) {
				val1 = 1.0f;
			}
		} else {
			vec3.z += dir * val2;
			k++;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x168(r1)
	  stfd      f31, 0x160(r1)
	  stfd      f30, 0x158(r1)
	  stfd      f29, 0x150(r1)
	  stfd      f28, 0x148(r1)
	  stfd      f27, 0x140(r1)
	  stfd      f26, 0x138(r1)
	  stfd      f25, 0x130(r1)
	  stfd      f24, 0x128(r1)
	  stfd      f23, 0x120(r1)
	  stfd      f22, 0x118(r1)
	  stfd      f21, 0x110(r1)
	  stfd      f20, 0x108(r1)
	  stfd      f19, 0x100(r1)
	  stmw      r21, 0xD4(r1)
	  mr        r22, r4
	  addi      r31, r1, 0x44
	  addi      r30, r1, 0x40
	  addi      r29, r1, 0x3C
	  addi      r28, r1, 0x38
	  addi      r27, r1, 0x34
	  addi      r26, r1, 0x30
	  li        r25, 0x1
	  li        r24, 0x1
	  li        r23, 0
	  lis       r21, 0x4330
	  lfs       f28, -0x7658(r2)
	  lfs       f0, -0x61CC(r13)
	  fneg      f1, f28
	  lfs       f27, -0x61E4(r13)
	  lfs       f26, -0x61E0(r13)
	  lfs       f25, -0x61DC(r13)
	  stfs      f1, 0x90(r1)
	  lfs       f24, -0x61D8(r13)
	  stfs      f0, 0x94(r1)
	  lfs       f23, -0x61D4(r13)
	  lfs       f22, -0x61D0(r13)
	  lfs       f21, -0x7678(r2)
	  lfs       f0, -0x61C8(r13)
	  stfs      f0, 0x98(r1)
	  lfs       f29, -0x7668(r2)
	  lfs       f20, -0x7654(r2)
	  lfs       f30, -0x7674(r2)
	  lfd       f31, -0x7650(r2)
	  lfs       f19, -0x765C(r2)

	.loc_0xBC:
	  fmuls     f2, f22, f21
	  mr        r4, r29
	  fmuls     f1, f23, f21
	  mr        r5, r30
	  fmuls     f0, f24, f21
	  stfs      f2, 0x44(r1)
	  addi      r6, r31, 0
	  addi      r3, r1, 0x5C
	  stfs      f1, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  bl        -0x47968
	  fsubs     f0, f29, f21
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  addi      r6, r28, 0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  addi      r3, r1, 0x68
	  fmuls     f0, f27, f0
	  stfs      f2, 0x38(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0x47998
	  lfs       f1, 0x68(r1)
	  li        r0, 0xFF
	  lfs       f0, 0x5C(r1)
	  lfs       f2, 0x6C(r1)
	  fadds     f3, f1, f0
	  lfs       f0, 0x60(r1)
	  lfs       f1, 0x70(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x64(r1)
	  fadds     f0, f1, f0
	  fmuls     f1, f30, f2
	  fmuls     f3, f30, f3
	  fmuls     f0, f30, f0
	  fctiwz    f1, f1
	  fctiwz    f2, f3
	  fctiwz    f0, f0
	  stfd      f1, 0xC0(r1)
	  stfd      f2, 0xC8(r1)
	  lwz       r4, 0xC4(r1)
	  lwz       r5, 0xCC(r1)
	  stfd      f0, 0xB8(r1)
	  stb       r5, 0x58(r1)
	  lwz       r3, 0xBC(r1)
	  stb       r4, 0x59(r1)
	  stb       r3, 0x5A(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r0, 0x24(r22)
	  lwz       r3, 0x1C(r22)
	  mulli     r0, r0, 0x24
	  add       r3, r3, r0
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  li        r0, 0
	  stw       r0, 0x10(r3)

	.loc_0x1A4:
	  lwz       r0, 0x24(r22)
	  cmpw      r24, r25
	  lwz       r5, 0x1C(r22)
	  mulli     r4, r0, 0x24
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  addi      r4, r4, 0x18
	  add       r4, r5, r4
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x8(r4)
	  lwz       r0, 0x24(r22)
	  lwz       r4, 0x1C(r22)
	  mulli     r3, r0, 0x24
	  lwz       r0, 0x58(r1)
	  stwx      r0, r4, r3
	  lwz       r3, 0x24(r22)
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r22)
	  blt-      .loc_0x250
	  addi      r25, r25, 0x1
	  lfs       f0, 0x90(r1)
	  srawi     r0, r25, 0x1
	  fadds     f21, f21, f19
	  addze     r0, r0
	  fsubs     f1, f0, f28
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xBC(r1)
	  fcmpo     cr0, f21, f29
	  li        r24, 0x1
	  stw       r21, 0xB8(r1)
	  lfd       f0, 0xB8(r1)
	  stfs      f1, 0x90(r1)
	  fsubs     f0, f0, f31
	  cror      2, 0x1, 0x2
	  fmuls     f0, f20, f0
	  fneg      f20, f20
	  fmuls     f0, f28, f0
	  stfs      f0, 0x98(r1)
	  bne-      .loc_0x264
	  fmr       f21, f29
	  b         .loc_0x264

	.loc_0x250:
	  fmuls     f0, f20, f28
	  lfs       f1, 0x98(r1)
	  addi      r24, r24, 0x1
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r1)

	.loc_0x264:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x12C
	  blt+      .loc_0xBC
	  lmw       r21, 0xD4(r1)
	  lwz       r0, 0x16C(r1)
	  lfd       f31, 0x160(r1)
	  lfd       f30, 0x158(r1)
	  lfd       f29, 0x150(r1)
	  lfd       f28, 0x148(r1)
	  lfd       f27, 0x140(r1)
	  lfd       f26, 0x138(r1)
	  lfd       f25, 0x130(r1)
	  lfd       f24, 0x128(r1)
	  lfd       f23, 0x120(r1)
	  lfd       f22, 0x118(r1)
	  lfd       f21, 0x110(r1)
	  lfd       f20, 0x108(r1)
	  lfd       f19, 0x100(r1)
	  addi      r1, r1, 0x168
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007EC58
 * Size:	0000EC
 */
f32 PyramidArranger::getLength(FormationMgr* mgr)
{
	int count = mgr->mCount; // load bearing temp. try it.
	return (-1.0f + std::sqrtf(count * 8.0f + 1.0f)) / 2.0f * 26.0f;
}

/*
 * --INFO--
 * Address:	8007ED44
 * Size:	00026C
 */
void LineArranger::arrange(FormationMgr* mgr)
{
	Vector3f vec(1.0f, 1.0f, 1.0f);
	Vector3f vec2(0.0f, 1.0f, 0.0f);
	f32 val1 = 0.0f;
	f32 val2 = 25.0f;
	f32 val3 = 2 * val2;
	int j    = 0;
	Vector3f vec3(0.0f, 0.0f, val2);
	for (int i = 0; i < 300; i++) {
		vec3.z        = val3;
		Vector3f vec4 = (1.0f - val1) * vec + val1 * vec2;
		mgr->add(vec3, vec4);
		if (j == 0) {
			val3 = -val3;
			j    = 1;
		} else if (j == 1) {
			val3 = -val3 + val2;
			j    = 0;
			val1 += 0.1f;
			if (val1 >= 1.0f) {
				val1 = 1.0f;
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stfd      f29, 0x140(r1)
	  stfd      f28, 0x138(r1)
	  stfd      f27, 0x130(r1)
	  stfd      f26, 0x128(r1)
	  stfd      f25, 0x120(r1)
	  stfd      f24, 0x118(r1)
	  stfd      f23, 0x110(r1)
	  stfd      f22, 0x108(r1)
	  stfd      f21, 0x100(r1)
	  stfd      f20, 0xF8(r1)
	  stmw      r23, 0xD4(r1)
	  mr        r23, r4
	  addi      r31, r1, 0x44
	  addi      r30, r1, 0x40
	  addi      r29, r1, 0x3C
	  addi      r28, r1, 0x38
	  addi      r27, r1, 0x34
	  addi      r26, r1, 0x30
	  li        r25, 0
	  li        r24, 0
	  lfs       f1, -0x61AC(r13)
	  lfs       f0, -0x61A8(r13)
	  stfs      f1, 0x8C(r1)
	  lfs       f28, -0x61C4(r13)
	  stfs      f0, 0x90(r1)
	  lfs       f27, -0x61C0(r13)
	  lfs       f26, -0x61BC(r13)
	  lfs       f25, -0x61B8(r13)
	  lfs       f24, -0x61B4(r13)
	  lfs       f23, -0x61B0(r13)
	  lfs       f22, -0x7678(r2)
	  lfs       f21, -0x7630(r2)
	  lfs       f29, -0x762C(r2)
	  stfs      f29, 0x94(r1)
	  lfs       f30, -0x7668(r2)
	  lfs       f31, -0x7674(r2)
	  lfs       f20, -0x765C(r2)

	.loc_0xA8:
	  fmuls     f2, f23, f22
	  stfs      f21, 0x94(r1)
	  fmuls     f1, f24, f22
	  mr        r4, r29
	  fmuls     f0, f25, f22
	  stfs      f2, 0x44(r1)
	  addi      r5, r30, 0
	  addi      r6, r31, 0
	  stfs      f1, 0x40(r1)
	  addi      r3, r1, 0x5C
	  stfs      f0, 0x3C(r1)
	  bl        -0x47CFC
	  fsubs     f0, f30, f22
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  addi      r6, r28, 0
	  fmuls     f2, f26, f0
	  fmuls     f1, f27, f0
	  addi      r3, r1, 0x68
	  fmuls     f0, f28, f0
	  stfs      f2, 0x38(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0x47D2C
	  lfs       f1, 0x68(r1)
	  li        r0, 0xFF
	  lfs       f0, 0x5C(r1)
	  lfs       f2, 0x6C(r1)
	  fadds     f3, f1, f0
	  lfs       f0, 0x60(r1)
	  lfs       f1, 0x70(r1)
	  fadds     f2, f2, f0
	  lfs       f0, 0x64(r1)
	  fadds     f0, f1, f0
	  fmuls     f1, f31, f2
	  fmuls     f3, f31, f3
	  fmuls     f0, f31, f0
	  fctiwz    f1, f1
	  fctiwz    f2, f3
	  fctiwz    f0, f0
	  stfd      f1, 0xC0(r1)
	  stfd      f2, 0xC8(r1)
	  lwz       r4, 0xC4(r1)
	  lwz       r5, 0xCC(r1)
	  stfd      f0, 0xB8(r1)
	  stb       r5, 0x58(r1)
	  lwz       r3, 0xBC(r1)
	  stb       r4, 0x59(r1)
	  stb       r3, 0x5A(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r0, 0x24(r23)
	  lwz       r3, 0x1C(r23)
	  mulli     r0, r0, 0x24
	  add       r3, r3, r0
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x194
	  li        r0, 0
	  stw       r0, 0x10(r3)

	.loc_0x194:
	  lwz       r0, 0x24(r23)
	  cmpwi     r25, 0
	  lwz       r5, 0x1C(r23)
	  mulli     r4, r0, 0x24
	  lwz       r3, 0x8C(r1)
	  lwz       r0, 0x90(r1)
	  addi      r4, r4, 0x18
	  add       r4, r5, r4
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x94(r1)
	  stw       r0, 0x8(r4)
	  lwz       r0, 0x24(r23)
	  lwz       r4, 0x1C(r23)
	  mulli     r3, r0, 0x24
	  lwz       r0, 0x58(r1)
	  stwx      r0, r4, r3
	  lwz       r3, 0x24(r23)
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r23)
	  bne-      .loc_0x1F4
	  fneg      f21, f21
	  li        r25, 0x1
	  b         .loc_0x21C

	.loc_0x1F4:
	  cmpwi     r25, 0x1
	  bne-      .loc_0x21C
	  fadds     f22, f22, f20
	  li        r25, 0
	  fneg      f0, f21
	  fcmpo     cr0, f22, f30
	  fadds     f21, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x21C
	  fmr       f22, f30

	.loc_0x21C:
	  addi      r24, r24, 0x1
	  cmpwi     r24, 0x12C
	  blt+      .loc_0xA8
	  lmw       r23, 0xD4(r1)
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lfd       f28, 0x138(r1)
	  lfd       f27, 0x130(r1)
	  lfd       f26, 0x128(r1)
	  lfd       f25, 0x120(r1)
	  lfd       f24, 0x118(r1)
	  lfd       f23, 0x110(r1)
	  lfd       f22, 0x108(r1)
	  lfd       f21, 0x100(r1)
	  lfd       f20, 0xF8(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007EFB0
 * Size:	0002FC
 */
void WingArranger::arrange(FormationMgr* mgr)
{
	int a    = 0;
	int b    = 0;
	int c    = 1;
	int d    = 1;
	f32 val1 = 30.0f;
	f32 val2 = 80.0f;
	f32 val3 = -80.0f;
	for (int i = 0; i < 300; i++) {
		if (i % 2 == 0) {
			Vector3f vec(val2 / c * a, 0.0f, val2 - a * val2 / c);
			mgr->add(vec, Vector3f(1.0f, 0.0f, 1.0f));
			a++;
			if (a == c) {
				a = 0;
				c++;
				val2 += val1;
			}
		} else {
			Vector3f vec(-val3 / d * b, 0.0f, val3 - b * val3 / d);
			mgr->add(vec, Vector3f(1.0f, 1.0f, 0.0f));
			b++;
			if (b == d) {
				b = 0;
				d++;
				val3 -= val1;
			}
		}
	}
	/*
	.loc_0x0:
	  stwu      r1, -0xC0(r1)
	  li        r0, 0x12C
	  mtctr     r0
	  li        r3, 0
	  stfd      f31, 0xB8(r1)
	  li        r5, 0
	  stfd      f30, 0xB0(r1)
	  li        r6, 0x1
	  li        r7, 0x1
	  lfs       f5, -0x7674(r2)
	  li        r8, 0
	  lfs       f2, -0x6190(r13)
	  lis       r0, 0x4330
	  lfs       f1, -0x618C(r13)
	  lfs       f0, -0x6188(r13)
	  fmuls     f4, f5, f2
	  lfs       f2, -0x61A0(r13)
	  fmuls     f3, f5, f1
	  lfs       f7, -0x619C(r13)
	  fmuls     f9, f5, f2
	  lfs       f6, -0x6198(r13)
	  fmuls     f7, f5, f7
	  fmuls     f0, f5, f0
	  lfs       f1, -0x7628(r2)
	  fmuls     f6, f5, f6
	  lfs       f2, -0x7624(r2)
	  fctiwz    f5, f4
	  fctiwz    f4, f3
	  lfd       f11, -0x7650(r2)
	  fctiwz    f3, f0
	  lfs       f8, -0x6194(r13)
	  fctiwz    f30, f9
	  fctiwz    f31, f7
	  lfs       f0, -0x61A4(r13)
	  fctiwz    f13, f6
	  lfs       f12, -0x7660(r2)

	.loc_0x90:
	  srawi     r9, r8, 0x1
	  addze     r9, r9
	  rlwinm    r9,r9,1,0,30
	  subc.     r9, r8, r9
	  bne-      .loc_0x1C4
	  xoris     r10, r6, 0x8000
	  stfd      f30, 0x88(r1)
	  xoris     r11, r3, 0x8000
	  stw       r10, 0xA4(r1)
	  li        r9, 0xFF
	  lwz       r12, 0x8C(r1)
	  stw       r11, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  stw       r0, 0x98(r1)
	  lfd       f7, 0xA0(r1)
	  stw       r10, 0x94(r1)
	  fsubs     f9, f7, f11
	  lfd       f6, 0x98(r1)
	  stw       r0, 0x90(r1)
	  fsubs     f7, f6, f11
	  lfd       f6, 0x90(r1)
	  fdivs     f9, f1, f9
	  stw       r11, 0xAC(r1)
	  stw       r0, 0xA8(r1)
	  lfd       f10, 0xA8(r1)
	  stfd      f31, 0x80(r1)
	  fsubs     f10, f10, f11
	  stfd      f13, 0x78(r1)
	  fmuls     f7, f1, f7
	  lwz       r11, 0x84(r1)
	  fsubs     f6, f6, f11
	  fmuls     f9, f10, f9
	  stb       r12, 0x30(r1)
	  fdivs     f6, f7, f6
	  lwz       r10, 0x7C(r1)
	  stb       r11, 0x31(r1)
	  stfs      f9, 0x68(r1)
	  stb       r10, 0x32(r1)
	  fsubs     f6, f1, f6
	  stfs      f0, 0x6C(r1)
	  stb       r9, 0x33(r1)
	  stfs      f6, 0x70(r1)
	  lwz       r9, 0x24(r4)
	  lwz       r10, 0x1C(r4)
	  mulli     r9, r9, 0x24
	  add       r10, r10, r9
	  lwz       r9, 0x10(r10)
	  cmplwi    r9, 0
	  beq-      .loc_0x15C
	  li        r9, 0
	  stw       r9, 0x10(r10)

	.loc_0x15C:
	  lwz       r9, 0x24(r4)
	  addi      r3, r3, 0x1
	  lwz       r12, 0x1C(r4)
	  cmpw      r3, r6
	  mulli     r11, r9, 0x24
	  lwz       r10, 0x68(r1)
	  lwz       r9, 0x6C(r1)
	  addi      r11, r11, 0x18
	  add       r11, r12, r11
	  stw       r10, 0x0(r11)
	  stw       r9, 0x4(r11)
	  lwz       r9, 0x70(r1)
	  stw       r9, 0x8(r11)
	  lwz       r9, 0x24(r4)
	  lwz       r11, 0x1C(r4)
	  mulli     r10, r9, 0x24
	  lwz       r9, 0x30(r1)
	  stwx      r9, r11, r10
	  lwz       r9, 0x24(r4)
	  addi      r9, r9, 0x1
	  stw       r9, 0x24(r4)
	  bne-      .loc_0x2E4
	  fadds     f1, f1, f12
	  li        r3, 0
	  addi      r6, r6, 0x1
	  b         .loc_0x2E4

	.loc_0x1C4:
	  xoris     r10, r7, 0x8000
	  stfd      f5, 0x98(r1)
	  xoris     r11, r5, 0x8000
	  fneg      f10, f2
	  stw       r10, 0x84(r1)
	  li        r9, 0xFF
	  lwz       r12, 0x9C(r1)
	  stw       r11, 0x8C(r1)
	  stw       r0, 0x80(r1)
	  stw       r0, 0x88(r1)
	  lfd       f7, 0x80(r1)
	  stw       r10, 0x94(r1)
	  fsubs     f9, f7, f11
	  lfd       f6, 0x88(r1)
	  stw       r0, 0x90(r1)
	  fsubs     f7, f6, f11
	  lfd       f6, 0x90(r1)
	  fdivs     f9, f10, f9
	  stw       r11, 0x7C(r1)
	  stw       r0, 0x78(r1)
	  lfd       f10, 0x78(r1)
	  stfd      f4, 0xA0(r1)
	  fsubs     f10, f10, f11
	  stfd      f3, 0xA8(r1)
	  fmuls     f7, f2, f7
	  lwz       r11, 0xA4(r1)
	  fsubs     f6, f6, f11
	  fmuls     f9, f10, f9
	  stb       r12, 0x2C(r1)
	  fdivs     f6, f7, f6
	  lwz       r10, 0xAC(r1)
	  stb       r11, 0x2D(r1)
	  stfs      f9, 0x5C(r1)
	  stb       r10, 0x2E(r1)
	  fsubs     f6, f2, f6
	  stfs      f8, 0x60(r1)
	  stb       r9, 0x2F(r1)
	  stfs      f6, 0x64(r1)
	  lwz       r9, 0x24(r4)
	  lwz       r10, 0x1C(r4)
	  mulli     r9, r9, 0x24
	  add       r10, r10, r9
	  lwz       r9, 0x10(r10)
	  cmplwi    r9, 0
	  beq-      .loc_0x280
	  li        r9, 0
	  stw       r9, 0x10(r10)

	.loc_0x280:
	  lwz       r9, 0x24(r4)
	  addi      r5, r5, 0x1
	  lwz       r12, 0x1C(r4)
	  cmpw      r5, r7
	  mulli     r11, r9, 0x24
	  lwz       r10, 0x5C(r1)
	  lwz       r9, 0x60(r1)
	  addi      r11, r11, 0x18
	  add       r11, r12, r11
	  stw       r10, 0x0(r11)
	  stw       r9, 0x4(r11)
	  lwz       r9, 0x64(r1)
	  stw       r9, 0x8(r11)
	  lwz       r9, 0x24(r4)
	  lwz       r11, 0x1C(r4)
	  mulli     r10, r9, 0x24
	  lwz       r9, 0x2C(r1)
	  stwx      r9, r11, r10
	  lwz       r9, 0x24(r4)
	  addi      r9, r9, 0x1
	  stw       r9, 0x24(r4)
	  bne-      .loc_0x2E4
	  fsubs     f2, f2, f12
	  li        r5, 0
	  addi      r7, r7, 0x1

	.loc_0x2E4:
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x90
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  addi      r1, r1, 0xC0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
Rope::Rope()
{
	_38 = _3C = nullptr;
	_0C.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000A1C
 */
void Rope::move(Vector3f& p1, Vector3f& p2, Vector3f& p3)
{
	Vector3f vec1 = p1 + p2 * gsys->getFrameTime();
	Vector3f vec2 = vec1 - _18;
	f32 dist      = vec2.length();
	vec2          = vec2 * (1.0f / dist) * (dist - _30);
	if (_3C) {
		_0C = _0C + (vec2 - _0C) * gsys->getFrameTime() / 0.1f;
		_3C->move(_18, _0C, p3);
	} else {
		_0C = _0C + (vec2 - _0C) * gsys->getFrameTime() / 0.1f + 10.0f * p3;
	}

	_18           = _18 + _0C * gsys->getFrameTime();
	Vector3f vec3 = _18 - vec1;
	vec3.normalise();
	_18 = vec1 + _30 * vec3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
void Rope::refresh(Graphics& gfx)
{
	Matrix4f mtx1;
	Vector3f vec;
	Matrix4f mtx2;
	f32 scale = 0.15f;
	mtx1.makeSRT(Vector3f(scale, 2.0f * scale, scale), Vector3f(0.0f, 0.0f, 0.0f), _18);
	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);
	GlobalShape::arrowShape->drawshape(gfx, *gfx.mCamera, nullptr);
	if (_3C) {
		_3C->refresh(gfx);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
Spine::Spine()
{
	_0C.clear();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000340
 */
void Spine::init(Creature* target)
{
	Vector3f pos = target->mPosition;
	_0C.set(target);
	mRope      = new Rope();
	f32 rad    = 7.0f;
	mRope->_30 = 7.0f;
	_04        = 10;
	f32 angle  = 2.0f * (PI * gsys->getRand(1.0f));
	pos        = pos + Vector3f(rad * sinf(angle), 0.0f, rad * cosf(angle));
	mRope->_18 = pos;
	Rope* rope = mRope;
	for (int i = 0; i < _04 - 1; i++) {
		rope->_3C  = new Rope();
		Rope* prev = rope;
		rope       = rope->_3C;
		rope->_38  = prev;

		f32 angle2 = 2.0f * (PI * gsys->getRand(1.0f));
		pos        = pos + Vector3f(rad * sinf(angle2), 0.0f, rad * cosf(angle2));
		rope->_18  = pos;
		rope->_30  = rad;
	}

	_10.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000A8C
 */
void Spine::preMove()
{
	// i'm not strong enough to do this blind, it's a lot of vector math.
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Spine::postMove()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Spine::move()
{
	_0C.getPtr();
	preMove();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void Spine::refresh(Graphics& gfx)
{
	if (mRope) {
		mRope->refresh(gfx);
	}
}
