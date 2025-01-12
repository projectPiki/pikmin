#include "zen/particle.h"
#include "Vector.h"

/*
 * --INFO--
 * Address:	801DA088
 * Size:	00001C
 */
namespace zen {
void PtclGenPack::setPtclGenPtr(u32 idx, particleGenerator* gen)
{
	if (idx >= mLimit) {
		return;
	}

	mGeneratorList[idx] = gen;
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
void PtclGenPack::setEmitPos(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801DA0A4
 * Size:	000034
 */
void PtclGenPack::setEmitPosPtr(Vector3f* posPtr)
{
	u32 i;
	particleGenerator** genList = mGeneratorList;
	for (i = 0; i < mLimit; i++, genList++) {
		if (*genList) {
			(*genList)->mEmitPosPtr = posPtr;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void PtclGenPack::setEmitDir(Vector3f&)
{
	// UNUSED FUNCTION
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

/*
 * --INFO--
 * Address:	801DA0D8
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	801DA114
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	801DA150
 * Size:	000044
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

/*
 * --INFO--
 * Address:	801DA194
 * Size:	000078
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

/*
 * --INFO--
 * Address:	801DA20C
 * Size:	000044
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
void PtclGenPack::checkStop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PtclGenPack::checkEmit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PtclGenPack::checkActive()
{
	// UNUSED FUNCTION
}
} // namespace zen
