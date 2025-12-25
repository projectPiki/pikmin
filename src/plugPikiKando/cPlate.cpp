#include "CPlate.h"
#include "AIPerf.h"
#include "DebugLog.h"
#include "GlobalShape.h"
#include "Graphics.h"
#include "Piki.h"
#include "SlotChangeListner.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(10)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("cPlate");

/**
 * @TODO: Documentation
 */
Creature* CPlate::getCreature(int idx)
{
	return mSlotList[idx].mOccupant.getPtr();
}

/**
 * @TODO: Documentation
 */
CPlate::CPlate(MapMgr* mgr)
{
	mSlotListSize = 110;
	mPlateSize    = 10.0f;
	mPlateLength  = 10.0f;
	mOriginPosition.set(0.0f, 0.0f, 0.0f);
	mDirectionAngle = 0.0f;
	mSlotList       = new Slot[mSlotListSize];
	mTotalSlotCount = 0;
	mPlatePikiCount = 0;
	mUsedSlotCount  = 0;
	_C8             = false;
	mIsNeutral      = true;

	load("parms/", "cunit.bin", 1);
	mDevOffsetTest.set(0.0f, 0.0f, 0.0f);
	mHappaCounts[0] = mHappaCounts[1] = mHappaCounts[2] = 0;
}

/**
 * @TODO: Documentation
 */
bool CPlate::canNaviRunFast()
{
	return true;
}

/**
 * @TODO: Documentation
 */
void CPlate::init(immut Vector3f&)
{
}

/**
 * @TODO: Documentation
 */
void CPlate::setPos(immut Vector3f& position, f32 angle, immut Vector3f& velocity)
{
	f32 offset = mCPlateParms.mStartOffset();
	if (speedy_sqrtf(mCurrentVelocity.x * mCurrentVelocity.x + mCurrentVelocity.z * mCurrentVelocity.z) > 5.0f) {
		offset = 0.0f;
	}

	f32 totalRadius  = mPlateLength + offset;
	mDirectionAngle  = angle;
	mOriginPosition  = position;
	mPlateCenter     = mOriginPosition + Vector3f(totalRadius * sinf(angle), 0.0f, totalRadius * cosf(angle));
	mCurrentVelocity = velocity;
	mPlateOffset     = position + Vector3f(mInnerRadius * sinf(angle), 0.0f, mInnerRadius * cosf(angle));
	mIsNeutral       = false;

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
void CPlate::setPosGray(immut Vector3f& position, f32 angle, immut Vector3f& velocity)
{
	f32 offset = mCPlateParms.mStartOffset();
	if (speedy_sqrtf(mCurrentVelocity.x * mCurrentVelocity.x + mCurrentVelocity.z * mCurrentVelocity.z) > 5.0f) {
		offset = 0.0f;
	}

	f32 dist         = mPlateLength + offset;
	mOriginPosition  = position;
	mPlateCenter     = mOriginPosition + Vector3f(dist * sinf(angle), 0.0f, dist * cosf(angle));
	mCurrentVelocity = velocity;
	mPlateOffset     = position + Vector3f(mInnerRadius * sinf(angle), 0.0f, mInnerRadius * cosf(angle));
	mIsNeutral       = false;

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001E0
 */
void CPlate::setPosNeutral(immut Vector3f& position, f32 angle, immut Vector3f& velocity)
{
	setPos(position, angle, velocity);
	mIsNeutral   = true;
	mPlateCenter = mOriginPosition;
}

/**
 * @TODO: Documentation
 */
int CPlate::getSlot(Creature* occupant, SlotChangeListner* listener)
{
	mHappaCounts[static_cast<Piki*>(occupant)->mHappa]++;
	int idx = mUsedSlotCount;
	mSlotList[idx].mOccupant.set(occupant);
	mSlotList[idx].mListener = listener;
	mUsedSlotCount++;
	return idx;
}

/**
 * @TODO: Documentation
 */
void CPlate::changeFlower(Piki* piki)
{
	int oldHappa = (piki->mHappa + 2) % PikiHappaCount;
	mHappaCounts[piki->mHappa]++;
	mHappaCounts[oldHappa]--;
}

/**
 * @TODO: Documentation
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
	mUsedSlotCount--;
	mTotalSlotCount--;

	for (int i = idx; i < mUsedSlotCount; i++) {
		mSlotList[i].mOccupant.reset();
		mSlotList[i].mOccupant.set(mSlotList[i + 1].mOccupant.getPtr());
		mSlotList[i].mListener = mSlotList[i + 1].mListener;
		mSlotList[i].mListener->inform(i);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000118
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

/**
 * @TODO: Documentation
 */
bool CPlate::validSlot(int idx)
{
	if (idx < 0 || idx >= mUsedSlotCount) {
		PRINT("slot %d : out of range [0..%d]\n", idx, mUsedSlotCount);
		return false;
	}

	return true;
}

/**
 * @TODO: Documentation
 */
void CPlate::sortByColor(Piki* piki)
{
	bool hasBomb  = piki->hasBomb() ? 1 : 0;
	int color     = piki->mColor;
	int nextColor = (color + 1) % PikiColorCount;
	int happa     = piki->mHappa;

	for (int i = 0; i < mUsedSlotCount; i++) {
		for (int j = 0; j < mUsedSlotCount; j++) {
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

/**
 * @TODO: Documentation
 */
void CPlate::rearrangeSlot(immut Vector3f& position, f32, immut Vector3f&)
{
	for (int i = mUsedSlotCount - 1; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			Vector3f sep = position - mSlotList[j].mOccupant.getPtr()->mSRT.t;
			f32 jDist    = sep.length();

			sep          = position - mSlotList[j - 1].mOccupant.getPtr()->mSRT.t;
			f32 prevDist = sep.length();

			if (jDist < prevDist) {
				swapSlot(j, j - 1);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void CPlate::refresh(int slotCount, f32 interpT)
{
	if (slotCount < mTotalSlotCount) {
		mUsedSlotCount -= mTotalSlotCount - slotCount;
	}

	mTotalSlotCount = slotCount;
	mInnerRadius    = (2.0f * mCPlateParms.mMaxPosSize()) * speedy_sqrtf(slotCount / PI);
	mInnerRadius    = (2.1f * mCPlateParms.mMaxPosSize()) * speedy_sqrtf(slotCount / PI);

	f32 maxRadius;
	f32 minRadius;
	f32 baseSize = 1.9f * mCPlateParms.mMaxPosSize();
	if (baseSize > mInnerRadius) {
		maxRadius = baseSize;
		minRadius = mInnerRadius;
	} else {
		maxRadius = mInnerRadius;
		minRadius = baseSize;
	}

	mPlateSize   = -(maxRadius - minRadius) * interpT + maxRadius;
	mPlateLength = ((4.0f * slotCount) * mCPlateParms.mMaxPosSize() * mCPlateParms.mMaxPosSize()) / (mPlateSize * PI);

	f32 limit = mCPlateParms.mLengthLimit();
	if (mPlateLength > limit) {
		mPlateLength = limit;
		mPlateSize   = ((4.0f * slotCount) * mCPlateParms.mMaxPosSize() * mCPlateParms.mMaxPosSize()) / (mPlateLength * PI);
	}

	refreshSlot();
}

/**
 * @TODO: Documentation
 */
void CPlate::refreshSlot()
{
	int slotsInRow, slotIndex;
	BOOL flip;

	f32 zExtent = -mPlateLength;
	slotIndex   = 0;

	Matrix4f transformMtx;

	Vector3f centerOffset(mPlateCenter);
	centerOffset.multiply(-1.0f);

	transformMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, mDirectionAngle, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));

	Vector3f devOffsetTest(0.0f, 0.0f, 0.0f);
	devOffsetTest.multMatrixTo(transformMtx, mDevOffsetTest);

	flip = TRUE;
	while (slotIndex < mTotalSlotCount) {
		int slotsPerSize = (speedy_sqrtf(mPlateLength * mPlateLength - zExtent * zExtent) * mPlateSize / mPlateLength)
		                 / (2.0f * mCPlateParms.mMaxPosSize());
		if (slotsPerSize < 0) {
			slotsPerSize = 0;
		}

		f32 xExtent = f32(flip) * (2.0f * (f32(slotsPerSize) * mCPlateParms.mMaxPosSize()));
		slotsInRow  = 2 * slotsPerSize + 1;
		while (slotsInRow > 0) {
			if (slotIndex < mTotalSlotCount) {
				mSlotList[slotIndex].mPosition.set(xExtent, 0.0f, zExtent);
				mSlotList[slotIndex].mPosition.multMatrixTo(transformMtx, mSlotList[slotIndex].mOffsetFromCenter);
				slotIndex++;
			}

			slotsInRow--;
			xExtent -= (2.0f * (f32(flip) * mCPlateParms.mMaxPosSize()));
		}

		zExtent += 2.0f * mCPlateParms.mMaxPosSize();
		flip *= -1;
	}
}

/**
 * @TODO: Documentation
 */
void CPlate::update()
{
	// the hell was this even for kando
	Vector3f vec;
	f32 val = mPlateOffset.y + 2.0f;
	vec.set(sinf(mDirectionAngle), 0.0f, cosf(mDirectionAngle));
	if (mHappaCounts[1]) {
		val = 0.0f;
	}

	STACK_PAD_VAR(12);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void CPlate::postUpdate(f32)
{
}

/**
 * @TODO: Documentation
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

	mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), mPlateOffset);

	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);

	Colour colour;
	colour.set(125, 255, 0, 255);

	GlobalShape::markerShape->mMaterialList->Colour() = colour;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

	mtx1.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), mPlateCenter);

	gfx.calcViewMatrix(mtx1, mtx2);
	gfx.useMatrix(mtx2, 0);

	colour.set(125, 175, 200, 255);
	GlobalShape::markerShape->mMaterialList->Colour() = colour;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

	for (int i = 0; i < mUsedSlotCount; i++) {
		Vector3f globalPos(mSlotList[i].mOffsetFromCenter);
		globalPos = globalPos + mPlateCenter;

		s = 0.08f;
		scale.set(s, s, s);

		mtx1.makeSRT(scale, Vector3f(0.0f, 4.0f, 0.0f), globalPos);

		gfx.calcViewMatrix(mtx1, mtx2);
		gfx.useMatrix(mtx2, 0);

		colour.set(0, 255, 10, 255);
		GlobalShape::markerShape->mMaterialList->Colour() = colour;
		GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}
