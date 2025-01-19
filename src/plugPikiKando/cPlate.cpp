#include "CPlate.h"
#include "Piki.h"
#include "AIPerf.h"
#include "SlotChangeListner.h"
#include "GlobalShape.h"
#include "Graphics.h"
#include "sysNew.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	800A5710
 * Size:	000014
 */
Creature* CPlate::getCreature(int idx)
{
	return mSlotList[idx].mOccupant.getPtr();
}

/*
 * --INFO--
 * Address:	800A5724
 * Size:	00022C
 */
CPlate::CPlate(MapMgr* mgr)
{
	mMaxSlotCount = 110;
	_6C           = 10.0f;
	_68           = 10.0f;
	_88.set(0.0f, 0.0f, 0.0f);
	_AC            = 0.0f;
	mSlotList      = new Slot[mMaxSlotCount];
	_74            = 0;
	_78            = 0;
	mCurrSlotCount = 0;
	_C8            = 0;
	_C9            = 1;

	load("parms/", "cunit.bin", 1);
	_B0.set(0.0f, 0.0f, 0.0f);
	mHappaCounts[0] = mHappaCounts[1] = mHappaCounts[2] = 0;
}

/*
 * --INFO--
 * Address:	800A5980
 * Size:	000008
 */
bool CPlate::canNaviRunFast()
{
	return true;
}

/*
 * --INFO--
 * Address:	800A5988
 * Size:	000004
 */
void CPlate::init(Vector3f&)
{
}

/*
 * --INFO--
 * Address:	800A598C
 * Size:	0001C0
 */
void CPlate::setPos(Vector3f& p1, f32 p2, Vector3f& p3)
{
	f32 offset = mCPlateParms.mStartOffset();
	if (speedy_sqrtf(_A0.x * _A0.x + _A0.z * _A0.z) > 5.0f) {
		offset = 0.0f;
	}

	f32 dist = _68 + offset;
	_AC      = p2;
	_88      = p1;
	_94      = _88 + Vector3f(dist * sinf(p2), 0.0f, dist * cosf(p2));
	_A0      = p3;
	_5C      = p1 + Vector3f(_70 * sinf(p2), 0.0f, _70 * cosf(p2));
	_C9      = 0;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800A5B4C
 * Size:	0001BC
 */
void CPlate::setPosGray(Vector3f& p1, f32 p2, Vector3f& p3)
{
	f32 offset = mCPlateParms.mStartOffset();
	if (speedy_sqrtf(_A0.x * _A0.x + _A0.z * _A0.z) > 5.0f) {
		offset = 0.0f;
	}

	f32 dist = _68 + offset;
	_88      = p1;
	_94      = _88 + Vector3f(dist * sinf(p2), 0.0f, dist * cosf(p2));
	_A0      = p3;
	_5C      = p1 + Vector3f(_70 * sinf(p2), 0.0f, _70 * cosf(p2));
	_C9      = 0;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E0
 */
void CPlate::setPosNeutral(Vector3f& p1, f32 p2, Vector3f& p3)
{
	setPos(p1, p2, p3);
	_C9 = 1;
	_94 = _88;
}

/*
 * --INFO--
 * Address:	800A5D08
 * Size:	0000B0
 */
int CPlate::getSlot(Creature* occupant, SlotChangeListner* listener)
{
	mHappaCounts[static_cast<Piki*>(occupant)->mHappa]++;
	int idx = mCurrSlotCount;
	mSlotList[idx].mOccupant.set(occupant);
	mSlotList[idx].mListener = listener;
	mCurrSlotCount++;
	return idx;
}

/*
 * --INFO--
 * Address:	800A5DB8
 * Size:	000050
 */
void CPlate::changeFlower(Piki* piki)
{
	int oldHappa = (piki->mHappa + 2) % PikiHappaCount;
	mHappaCounts[piki->mHappa]++;
	mHappaCounts[oldHappa]--;
}

/*
 * --INFO--
 * Address:	800A5E08
 * Size:	000144
 */
void CPlate::releaseSlot(Creature* occupant, int idx)
{
	Slot* slot = &mSlotList[idx];
	if (slot->mOccupant.getPtr() != occupant) {
		PRINT(" %x try to release slot (%d) but owner is %x\n", occupant, idx, slot->mOccupant.getPtr());
		ERROR(" sorry ...\n");
	}
	mHappaCounts[static_cast<Piki*>(occupant)->mHappa]--;
	slot->mOccupant.reset();
	mCurrSlotCount--;
	_74--;
	for (int i = idx; i < mCurrSlotCount; i++) {
		mSlotList[i].mOccupant.reset();
		mSlotList[i].mOccupant.set(mSlotList[i + 1].mOccupant.getPtr());
		mSlotList[i].mListener = mSlotList[i + 1].mListener;
		mSlotList[i].mListener->inform(i);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void CPlate::swapSlot(int idx1, int idx2)
{
	Slot* slot1 = &mSlotList[idx1];
	Slot* slot2 = &mSlotList[idx2];

	Creature* owner1             = slot1->mOccupant.getPtr();
	SlotChangeListner* listener1 = slot1->mListener;
	Creature* owner2             = slot2->mOccupant.getPtr();
	SlotChangeListner* listener2 = slot2->mListener;

	slot1->mOccupant.reset();
	slot1->mOccupant.set(owner2);
	slot1->mListener = listener2;
	slot1->mListener->inform(idx1);

	slot2->mOccupant.reset();
	slot2->mOccupant.set(owner1);
	slot2->mListener = listener1;
	slot2->mListener->inform(idx2);
}

/*
 * --INFO--
 * Address:	800A5F4C
 * Size:	000024
 */
bool CPlate::validSlot(int idx)
{
	if (idx < 0 || idx >= mCurrSlotCount) {
		PRINT("slot %d : out of range [0..%d]\n", idx, mCurrSlotCount);
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800A5F70
 * Size:	000424
 */
void CPlate::sortByColor(Piki* piki)
{
	BOOL hasBomb1;
	if (piki->hasBomb()) {
		hasBomb1 = TRUE;
	} else {
		hasBomb1 = FALSE;
	}
	bool hasBomb  = hasBomb1;
	int color     = piki->mColor;
	int nextColor = (color + 1) % PikiColorCount;
	int happa     = piki->mHappa;

	for (int i = 0; i < mCurrSlotCount; i++) {
		for (int j = 0; j < mCurrSlotCount; j++) {
			Piki* iOwner = static_cast<Piki*>(mSlotList[i].mOccupant.getPtr());
			Piki* jOwner = static_cast<Piki*>(mSlotList[j].mOccupant.getPtr());

			int iColor = iOwner->mColor;
			int jColor = jOwner->mColor;

			if (iColor != jColor) {
				int iCheck = (iColor == color) ? 1 : (iColor == nextColor) ? 2 : 3;
				int jCheck = (jColor == color) ? 1 : (jColor == nextColor) ? 2 : 3;

				if (j > i && jCheck < iCheck) {
					swapSlot(j, i);
				}

				continue;
			}

			int iBomb;
			int jBomb;
			if (hasBomb) {
				iBomb = iOwner->hasBomb() ? 0 : 1;
				jBomb = jOwner->hasBomb() ? 0 : 1;
			} else {
				iBomb = iOwner->hasBomb() ? 1 : 0;
				jBomb = jOwner->hasBomb() ? 1 : 0;
			}

			int iCheck = (happa == iOwner->mHappa) ? 0 : 1;

			iBomb += iCheck;

			int jCheck = (happa == jOwner->mHappa) ? 0 : 1;
			jBomb += jCheck;

			if (j > i && jBomb < iBomb) {
				swapSlot(j, i);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800A6394
 * Size:	0002DC
 */
void CPlate::rearrangeSlot(Vector3f& p1, f32, Vector3f&)
{
	for (int i = mCurrSlotCount - 1; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			Vector3f sep = p1 - mSlotList[j].mOccupant.getPtr()->mPosition;
			f32 jDist    = sep.length();

			sep          = p1 - mSlotList[j - 1].mOccupant.getPtr()->mPosition;
			f32 prevDist = sep.length();

			if (jDist < prevDist) {
				swapSlot(j, j - 1);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800A6670
 * Size:	000188
 */
void CPlate::refresh(int p1, f32 p2)
{
	if (p1 < _74) {
		mCurrSlotCount -= _74 - p1;
	}

	_74 = p1;
	_70 = (2.0f * mCPlateParms.mMaxPosSize()) * speedy_sqrtf(p1 / PI);
	_70 = (2.1f * mCPlateParms.mMaxPosSize()) * speedy_sqrtf(p1 / PI);

	f32 max;
	f32 min;
	f32 size = 1.9f * mCPlateParms.mMaxPosSize();
	if (size > _70) {
		max = size;
		min = _70;
	} else {
		max = _70;
		min = size;
	}

	_6C       = -(max - min) * p2 + max;
	_68       = ((4.0f * p1) * mCPlateParms.mMaxPosSize() * mCPlateParms.mMaxPosSize()) / (_6C * PI);
	f32 limit = mCPlateParms.mLengthLimit();
	if (_68 > limit) {
		_68 = limit;
		_6C = ((4.0f * p1) * mCPlateParms.mMaxPosSize() * mCPlateParms.mMaxPosSize()) / (_68 * PI);
	}
	refreshSlot();
}

/*
 * --INFO--
 * Address:	800A67F8
 * Size:	000234
 */
void CPlate::refreshSlot()
{
	int val2, idx, flip;

	f32 zVal = -_68;
	idx      = 0;
	Matrix4f mtx;
	Vector3f vec(_94);
	vec.multiply(-1.0f);

	mtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, _AC, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
	Vector3f vec2(0.0f, 0.0f, 0.0f);
	vec2.multMatrixTo(mtx, _B0);

	flip = 1;
	while (idx < _74) {
		int val = (speedy_sqrtf(_68 * _68 - zVal * zVal) * _6C / _68) / (2.0f * mCPlateParms.mMaxPosSize());
		if (val < 0) {
			val = 0;
		}

		f32 xVal = f32(flip) * (2.0f * (f32(val) * mCPlateParms.mMaxPosSize()));
		val2     = 2 * val + 1;
		while (val2 > 0) {
			if (idx < _74) {
				mSlotList[idx].mPosition.set(xVal, 0.0f, zVal);
				mSlotList[idx].mPosition.multMatrixTo(mtx, mSlotList[idx]._0C);
				idx++;
			}

			val2--;
			xVal -= (2.0f * (f32(flip) * mCPlateParms.mMaxPosSize()));
		}

		zVal += 2.0f * mCPlateParms.mMaxPosSize();
		flip *= -1;
	}
}

/*
 * --INFO--
 * Address:	800A6A2C
 * Size:	000038
 */
void CPlate::update()
{
	// the hell was this even for kando
	Vector3f vec;
	f32 val = _5C.y + 2.0f;
	vec.set(sinf(_AC), 0.0f, cosf(_AC));
	if (mHappaCounts[1]) {
		val = 0.0f;
	}

	u32 badCompiler[12];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CPlate::postUpdate(f32)
{
}

/*
 * --INFO--
 * Address:	800A6A64
 * Size:	0002CC
 */
void CPlate::render(Graphics& gfx)
{
	if (!AIPerf::kandoOnly) {
		return;
	}

	Matrix4f mtx1;
	Matrix4f mtx2;
	Vector3f scale;
	f32 s = 0.25f;
	scale.set(s, s, s);

	mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), _5C);

	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);

	Colour colour;
	colour.set(125, 255, 0, 255);

	GlobalShape::markerShape->mMaterialList->Colour() = colour;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

	mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), _94);

	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);

	colour.set(125, 175, 200, 255);
	GlobalShape::markerShape->mMaterialList->Colour() = colour;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

	for (int i = 0; i < mCurrSlotCount; i++) {
		Vector3f pos(mSlotList[i]._0C);
		pos = pos + _94;
		s   = 0.08f;
		scale.set(s, s, s);
		mtx1.makeSRT(scale, Vector3f(0.0f, 4.0f, 0.0f), pos);

		gfx.calcViewMatrix(mtx1, mtx2);
		gfx.useMatrix(mtx2, 0);

		colour.set(0, 255, 10, 255);
		GlobalShape::markerShape->mMaterialList->Colour() = colour;
		GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}
