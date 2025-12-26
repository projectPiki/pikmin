#include "DebugLog.h"
#include "Vector.h"
#include "zen/particle.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(14)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("ptclGenPack")

/**
 * @todo: Documentation
 */
namespace zen {
void PtclGenPack::setPtclGenPtr(u32 idx, particleGenerator* gen)
{
	if (idx < mLimit) {
		mGeneratorList[idx] = gen;
	} else {
		PRINT("ptcl index %d is over %d. \n", idx, mLimit);
		ERROR("ptcl index %d is over %d. \n", idx, mLimit);
	}
};

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
particleGenerator* PtclGenPack::getPtclGenPtr(u32 idx)
{
	return mGeneratorList[idx];
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void PtclGenPack::setEmitPos(immut Vector3f& pos)
{
	// UNUSED FUNCTION (matching by size)
	u32 i;
	particleGenerator** genList = mGeneratorList;
	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->setEmitPos(pos);
		}
	}
}

/**
 * @todo: Documentation
 */
void PtclGenPack::setEmitPosPtr(immut Vector3f* posPtr)
{
	u32 i;
	particleGenerator** genList = mGeneratorList;
	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->setEmitPosPtr(posPtr);
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void PtclGenPack::setEmitDir(immut Vector3f& pos)
{
	// UNUSED FUNCTION (matching by size)
	u32 i;
	particleGenerator** genList = mGeneratorList;
	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->setEmitDir(pos);
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084
 */
void PtclGenPack::setCallBack(zen::CallBack1<zen::particleGenerator*>*, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void PtclGenPack::startGen()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->startGen();
		}
	}
}

/**
 * @todo: Documentation
 */
void PtclGenPack::stopGen()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;
	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->stopGen();
		}
	}
	return;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void PtclGenPack::start()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void PtclGenPack::stop()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void PtclGenPack::finish()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;
	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->finish();
			*genList = nullptr;
		}
	}
}

/**
 * @todo: Documentation
 */
void PtclGenPack::forceFinish()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->forceFinish();
			(*genList) = nullptr;
		}
	}
}

/**
 * @todo: Documentation
 */
bool PtclGenPack::checkStopGen()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if ((*genList) && (!(*genList)->checkStopGen())) {
			return false;
		}
	}
	return true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
bool PtclGenPack::checkStop()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
bool PtclGenPack::checkEmit()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
bool PtclGenPack::checkActive()
{
	// UNUSED FUNCTION
}
} // namespace zen
