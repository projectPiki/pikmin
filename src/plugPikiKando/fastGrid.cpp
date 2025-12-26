#include "FastGrid.h"
#include "AIPerf.h"
#include "DebugLog.h"
#include "MemStat.h"
#include "sysNew.h"

u8* FastGrid::aiGridMap;
u16 FastGrid::aiGridSize;
u16 FastGrid::aiGridShift = 12;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("fastGrid")

FastGrid::FastGrid()
{
	mGridPositionX = mGridPositionY = mGridPositionZ = mWidth = mHeight = 0;
	mNeighbourSize                                                      = 1;
}

/**
 * @brief Clears and initializes the AI grid used for culling.
 * @param shift The bit shift amount to determine grid cell size (2^shift units).
 */
void FastGrid::initAIGrid(u8 shift)
{
	aiGridShift = shift;

	// Set the grid size to 2^(16 - shift), so higher shift means fewer, larger cells.
	aiGridSize = (1 << (16 - aiGridShift));

	memStat->start("aiGrid");
	aiGridMap = new (0x20) u8[aiGridSize * aiGridSize];
	clearAIGrid();
	memStat->end("aiGrid");
	PRINT("aiGridSize = %d : total = %d (KBytes)\n", aiGridSize, aiGridSize * aiGridSize);
	PRINT("@@@@@@@@@@ aiGridSize = %d : griz size = %f\n", aiGridSize, 32768.0f / aiGridSize);
}

/**
 * @brief Clears the AI grid map, setting all cells to zero.
 */
void FastGrid::clearAIGrid()
{
	for (int i = 0; i < aiGridSize * aiGridSize; i++) {
		aiGridMap[i] = 0;
	}
}

/**
 * @brief Increments the AI grid cell count at the current grid position.
 * @note UNUSED Size: 000028
 */
void FastGrid::addAIGrid()
{
	int id = mWidth * aiGridSize + mHeight;
	aiGridMap[id]++;
}

/**
 * @brief Decrements the AI grid cell count at the current grid position if it's greater than zero.
 */
void FastGrid::delAIGrid()
{
	int id = mWidth * aiGridSize + mHeight;
	if (aiGridMap[id]) {
		aiGridMap[id]--;
	}
}

/**
 * @brief Checks if the current grid position is culled based on neighboring AI grid cells.
 */
bool FastGrid::aiCulling()
{
	if (!AIPerf::aiGrid) {
		return false;
	}

	// Check neighboring cells for culling
	if (mNeighbourSize != 1) {
		return aiCullingLarge(mNeighbourSize);
	}

	// Standard neighbor check (1-cell radius)
	int offset = mHeight + mWidth * aiGridSize;
	if (aiGridMap[offset]) {
		return false;
	}

	// Check 8 neighboring cells
	// Right
	if (mHeight < aiGridSize - 1 && aiGridMap[offset + 1]) {
		return false;
	}

	// Left
	if (mHeight > 0 && aiGridMap[offset - 1]) {
		return false;
	}

	// Down
	if (mWidth < aiGridSize - 1 && aiGridMap[offset + aiGridSize]) {
		return false;
	}

	// Up
	if (mWidth > 0 && aiGridMap[offset - aiGridSize]) {
		return false;
	}

	// Diagonals
	// Up-Right
	if (mHeight < aiGridSize - 1 && mWidth > 0 && aiGridMap[offset + 1 - aiGridSize]) {
		return false;
	}

	// Down-Right
	if (mHeight < aiGridSize - 1 && mWidth < aiGridSize - 1 && aiGridMap[offset + 1 + aiGridSize]) {
		return false;
	}

	// Up-Left
	if (mHeight > 0 && mWidth > 0 && aiGridMap[offset - 1 - aiGridSize]) {
		return false;
	}

	// Down-Left
	if (mHeight > 0 && mWidth < aiGridSize - 1 && aiGridMap[offset - 1 + aiGridSize]) {
		return false;
	}

	return true;
}

/**
 * @brief Checks if the current grid position is culled based on a larger neighborhood.
 * @param max The radius of neighboring cells to check.
 */
bool FastGrid::aiCullingLarge(int max)
{
	if (!AIPerf::aiGrid) {
		return false;
	}

	// Check a square area of side length (2*max + 1) around the current cell
	int offset = mHeight + mWidth * aiGridSize;
	for (int x = -max; x <= max; x++) {
		// Bounds check X
		if (mWidth + x >= 0 && mWidth + x < aiGridSize) {
			for (int y = -max; y <= max; y++) {
				// Bounds check Y
				if (mHeight + y >= 0 && mHeight + y < aiGridSize && aiGridMap[offset + x * aiGridSize + y]) {
					return false;
				}
			}
		}
	}

	return true;
}

/**
 * @brief Returns true when `grid` is far enough away to be considered "culled".
 * @param other The other grid to compare against.
 * @param radius The culling radius.
 *
 * @note The "- 1" in the axis checks treats immediate neighbors as distance 0 for culling purposes (gives a 1-cell cushion).
 */
bool FastGrid::doCulling(const FastGrid& other, f32 radius)
{
	s16 cellLimit = s16(radius) >> AIPerf::gridShift;

	// X axis
	s16 dx     = mGridPositionX - other.mGridPositionX;
	s16 absDx  = (dx > 0) ? dx : -(dx);
	s16 excess = (absDx == 0) ? 0 : absDx - 1;
	if (excess > cellLimit) {
		return true;
	}

	// Z axis
	s16 dz    = mGridPositionZ - other.mGridPositionZ;
	s16 absDz = (dz > 0) ? dz : -(dz);
	excess    = (absDz == 0) ? 0 : absDz - 1;
	if (excess > cellLimit) {
		return true;
	}

	// When disabled, ignore Y entirely.
	if (AIPerf::useGrid != true) {
		return false;
	}

	// Y axis
	s16 dy    = mGridPositionY - other.mGridPositionY;
	s16 absDy = (dy > 0) ? dy : -(dy);
	excess    = (absDy == 0) ? 0 : absDy - 1;
	if (excess > cellLimit) {
		return true;
	}

	return false;
}

/**
 * @brief Updates the grid position based on the given world position.
 * @param pos The world position to update the grid coordinates from.
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

/**
 * @brief Updates the AI grid position based on the given world position.
 * @param pos The world position to update the AI grid coordinates from.
 * @param updateMap A flag indicating whether to update the AI grid map counts.
 */
void FastGrid::updateAIGrid(const Vector3f& pos, bool updateMap)
{
	f32 x      = pos.x;
	f32 z      = pos.z;
	int width  = mWidth;
	int height = mHeight;

	if (AIPerf::aiGrid) {
		// Calculate new grid cell indices based on position and grid shift
		mWidth = x;
		mWidth = (aiGridSize >> 1) + (mWidth >> aiGridShift);

		mHeight = z;
		mHeight = (aiGridSize >> 1) + (mHeight >> aiGridShift);

		// Update map counts if the grid cell has changed
		if (updateMap && (mWidth != width || mHeight != height)) {
			int offset = height + width * aiGridSize;
			if (aiGridMap[offset]) {
				aiGridMap[offset]--;
			}

			int newOffset = mHeight + mWidth * aiGridSize;
			aiGridMap[newOffset]++;
		}
	}
}

/**
 * @brief Unused.
 * @note UNUSED Size: 000820
 * @note 100BD9A0 in the DLL
 */
void FastGrid::renderAIGrid2D(Graphics&)
{
}

/**
 * @brief Unused.
 * @note UNUSED Size: 000348
 * @note 100BE130 in the DLL
 */
void FastGrid::renderAIGrid(Graphics&)
{
}
