#include "DebugLog.h"
#include "Vector.h"
#include "zen/particle.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(14)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("ptclGenPack")

/**
 * @TODO: Documentation
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

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
particleGenerator* PtclGenPack::getPtclGenPtr(u32 idx)
{
	return mGeneratorList[idx];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
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
 * @TODO: Documentation
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

/*
 * --INFO--
 * Address:	........
 * Size:	000048
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

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void PtclGenPack::setCallBack(zen::CallBack1<zen::particleGenerator*>*, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void PtclGenPack::start()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void PtclGenPack::stop()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
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

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
bool PtclGenPack::checkStop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
bool PtclGenPack::checkEmit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
bool PtclGenPack::checkActive()
{
	// UNUSED FUNCTION
}
} // namespace zen
