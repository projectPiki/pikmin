#include "FastGrid.h"
#include "MemStat.h"
#include "sysNew.h"
#include "AIPerf.h"
#include "DebugLog.h"

u8* FastGrid::aiGridMap;
u16 FastGrid::aiGridSize;
u16 FastGrid::aiGridShift = 12;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("fastGrid")

/*
 * --INFO--
 * Address:	80094098
 * Size:	000024
 */
FastGrid::FastGrid()
{
	mGridPositionX = mGridPositionY = mGridPositionZ = mWidth = mHeight = 0;
	mNeighbourSize                                                      = 1;
}

/*
 * --INFO--
 * Address:	800940BC
 * Size:	000078
 */
void FastGrid::initAIGrid(u8 shift)
{
	aiGridShift = shift;
	aiGridSize  = 1 << 0x10 - aiGridShift;
	memStat->start("aiGrid");
	aiGridMap = new (0x20) u8[aiGridSize * aiGridSize];
	clearAIGrid();
	memStat->end("aiGrid");
	PRINT("aiGridSize = %d : total = %d (KBytes)\n", aiGridSize, aiGridSize * aiGridSize);
	PRINT("@@@@@@@@@@ aiGridSize = %d : griz size = %f\n", aiGridSize, 32768.0f / aiGridSize);
}

/*
 * --INFO--
 * Address:	80094134
 * Size:	00002C
 */
void FastGrid::clearAIGrid()
{
	for (int i = 0; i < aiGridSize * aiGridSize; i++) {
		aiGridMap[i] = 0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void FastGrid::addAIGrid()
{
	int id = mWidth * aiGridSize + mHeight;
	aiGridMap[id]++;
}

/*
 * --INFO--
 * Address:	80094160
 * Size:	000030
 */
void FastGrid::delAIGrid()
{
	int id = mWidth * aiGridSize + mHeight;
	if (aiGridMap[id]) {
		aiGridMap[id]--;
	}
}

/*
 * --INFO--
 * Address:	80094190
 * Size:	0001A8
 */
bool FastGrid::aiCulling()
{
	if (!AIPerf::aiGrid) {
		return false;
	}

	if (mNeighbourSize != 1) {
		return aiCullingLarge(mNeighbourSize);
	}

	int offset = mHeight + mWidth * aiGridSize;
	if (aiGridMap[offset]) {
		return false;
	}

	if (mHeight < aiGridSize - 1 && aiGridMap[offset + 1]) {
		return false;
	}

	if (mHeight > 0 && aiGridMap[offset - 1]) {
		return false;
	}

	if (mWidth < aiGridSize - 1 && aiGridMap[offset + aiGridSize]) {
		return false;
	}

	if (mWidth > 0 && aiGridMap[offset - aiGridSize]) {
		return false;
	}

	if (mHeight < aiGridSize - 1 && mWidth > 0 && aiGridMap[offset + 1 - aiGridSize]) {
		return false;
	}

	if (mHeight < aiGridSize - 1 && mWidth < aiGridSize - 1 && aiGridMap[offset + 1 + aiGridSize]) {
		return false;
	}

	if (mHeight > 0 && mWidth > 0 && aiGridMap[offset - 1 - aiGridSize]) {
		return false;
	}

	if (mHeight > 0 && mWidth < aiGridSize - 1 && aiGridMap[offset - 1 + aiGridSize]) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	80094338
 * Size:	0000B8
 */
bool FastGrid::aiCullingLarge(int max)
{
	if (!AIPerf::aiGrid) {
		return false;
	}

	int offset = mHeight + mWidth * aiGridSize;
	for (int x = -max; x <= max; x++) {
		if (mWidth + x >= 0 && mWidth + x < aiGridSize) {
			for (int y = -max; y <= max; y++) {
				if (mHeight + y >= 0 && mHeight + y < aiGridSize && aiGridMap[offset + x * aiGridSize + y]) {
					return false;
				}
			}
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	800943F0
 * Size:	000130
 */
bool FastGrid::doCulling(const FastGrid& grid, f32 p2)
{
	s16 limit = s16(p2) >> AIPerf::gridShift;
	s16 xDiff = mGridPositionX - grid.mGridPositionX;
	s16 xAbs  = (xDiff > 0) ? xDiff : -(xDiff);
	s16 val   = (xAbs == 0) ? 0 : xAbs - 1;
	if (val > limit) {
		return true;
	}

	s16 zDiff = mGridPositionZ - grid.mGridPositionZ;
	s16 zAbs  = (zDiff > 0) ? zDiff : -(zDiff);
	val       = (zAbs == 0) ? 0 : zAbs - 1;
	if (val > limit) {
		return true;
	}

	if (AIPerf::useGrid != true) {
		return false;
	}

	s16 yDiff = mGridPositionY - grid.mGridPositionY;
	s16 yAbs  = (yDiff > 0) ? yDiff : -(yDiff);
	val       = (yAbs == 0) ? 0 : yAbs - 1;
	if (val > limit) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80094520
 * Size:	00009C
 */
void FastGrid::updateGrid(const Vector3f& pos)
{
	if (AIPerf::useGrid) {
		mGridPositionX = pos.x;
		mGridPositionX = mGridPositionX >> AIPerf::gridShift;

		mGridPositionZ = pos.z;
		mGridPositionZ = mGridPositionZ >> AIPerf::gridShift;
		if (AIPerf::useGrid == 1) {
			mGridPositionY = pos.y;
			mGridPositionY = mGridPositionY >> AIPerf::gridShift;
		}
	}
}

/*
 * --INFO--
 * Address:	800945BC
 * Size:	0000E8
 */
void FastGrid::updateAIGrid(const Vector3f& pos, bool p2)
{
	f32 x      = pos.x;
	f32 z      = pos.z;
	int width  = mWidth;
	int height = mHeight;
	if (AIPerf::aiGrid) {
		mWidth = x;
		mWidth = (aiGridSize >> 1) + (mWidth >> aiGridShift);

		mHeight = z;
		mHeight = (aiGridSize >> 1) + (mHeight >> aiGridShift);

		if (p2 && (mWidth != width || mHeight != height)) {
			int offset = height + width * aiGridSize;
			if (aiGridMap[offset]) {
				aiGridMap[offset]--;
			}

			int newOffset = mHeight + mWidth * aiGridSize;
			aiGridMap[newOffset]++;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000820
 */
void FastGrid::renderAIGrid2D(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000348
 */
void FastGrid::renderAIGrid(Graphics&)
{
	// UNUSED FUNCTION
}
