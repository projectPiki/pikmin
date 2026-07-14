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
		// yeah they screwed this up
		PRINT("ptcl index %d is over %d. \n", TERNARY_BUGFIX(MACRO_ARG(idx, mLimit), mLimit));
		ERROR("ptcl index %d is over %d. \n", TERNARY_BUGFIX(MACRO_ARG(idx, mLimit), mLimit));
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
 * @note UNUSED Size: 000048 (Matching by size)
 */
void PtclGenPack::setEmitPos(immut Vector3f& pos)
{
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
 * @note UNUSED Size: 000048 (Matching by size)
 */
void PtclGenPack::setEmitDir(immut Vector3f& pos)
{
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
 * @note UNUSED Size: 000084 (Matching by size)
 */
void PtclGenPack::setCallBack(zen::CallBack1<zen::particleGenerator*>* cb1, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cb2)
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->setCallBack(cb1, cb2);
		}
	}
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
 * @note UNUSED Size: 00003C (Matching by size)
 */
void PtclGenPack::start()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->start();
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
void PtclGenPack::stop()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->stop();
		}
	}
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
 * @note UNUSED Size: 000044 (Matching by size)
 */
bool PtclGenPack::checkStop()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if ((*genList) && (!(*genList)->checkStop())) {
			return false;
		}
	}
	return true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044 (Matching by size)
 */
bool PtclGenPack::checkEmit()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if ((*genList) && (!(*genList)->checkEmit())) {
			return false;
		}
	}
	return true;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044 (Matching by size)
 */
bool PtclGenPack::checkActive()
{
	u32 i;
	particleGenerator** genList = mGeneratorList;

	for (i = 0; i < mLimit; i++, genList++) {
		if ((*genList) && (!(*genList)->checkActive())) {
			return false;
		}
	}
	return true;
}
} // namespace zen
