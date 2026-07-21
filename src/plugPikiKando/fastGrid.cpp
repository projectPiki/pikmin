#include "FastGrid.h"
#include "AIPerf.h"
#include "DebugLog.h"
#include "Font.h"
#include "Graphics.h"
#include "MemStat.h"
#include "WorkObject.h"
#include "sysNew.h"
#include "teki.h"

u8* FastGrid::aiGridMap;
u16 FastGrid::aiGridSize;
u16 FastGrid::aiGridShift = 12;
Texture* FastGrid::aiGridTex; // unused

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

/**
 * @brief Initializes grid coordinates and neighbor radius to defaults.
 */
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
	for (int cellIndex = 0; cellIndex < aiGridSize * aiGridSize; cellIndex++) {
		aiGridMap[cellIndex] = 0;
	}
}

/**
 * @brief Increments the AI grid cell count at the current grid position.
 * @note UNUSED Size: 000028
 */
void FastGrid::addAIGrid()
{
	int cellIndex = mWidth * aiGridSize + mHeight;
	aiGridMap[cellIndex]++;
}

/**
 * @brief Decrements the AI grid cell count at the current grid position if it's greater than zero.
 */
void FastGrid::delAIGrid()
{
	int cellIndex = mWidth * aiGridSize + mHeight;
	if (aiGridMap[cellIndex]) {
		aiGridMap[cellIndex]--;
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
	int centerCellIndex = mHeight + mWidth * aiGridSize;
	if (aiGridMap[centerCellIndex]) {
		return false;
	}

	// Check 8 neighboring cells
	// Right
	if (mHeight < aiGridSize - 1 && aiGridMap[centerCellIndex + 1]) {
		return false;
	}

	// Left
	if (mHeight > 0 && aiGridMap[centerCellIndex - 1]) {
		return false;
	}

	// Down
	if (mWidth < aiGridSize - 1 && aiGridMap[centerCellIndex + aiGridSize]) {
		return false;
	}

	// Up
	if (mWidth > 0 && aiGridMap[centerCellIndex - aiGridSize]) {
		return false;
	}

	// Diagonals
	// Up-Right
	if (mHeight < aiGridSize - 1 && mWidth > 0 && aiGridMap[centerCellIndex + 1 - aiGridSize]) {
		return false;
	}

	// Down-Right
	if (mHeight < aiGridSize - 1 && mWidth < aiGridSize - 1 && aiGridMap[centerCellIndex + 1 + aiGridSize]) {
		return false;
	}

	// Up-Left
	if (mHeight > 0 && mWidth > 0 && aiGridMap[centerCellIndex - 1 - aiGridSize]) {
		return false;
	}

	// Down-Left
	if (mHeight > 0 && mWidth < aiGridSize - 1 && aiGridMap[centerCellIndex - 1 + aiGridSize]) {
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
	int centerCellIndex = mHeight + mWidth * aiGridSize;
	for (int widthOffset = -max; widthOffset <= max; widthOffset++) {
		// Bounds check X
		if (mWidth + widthOffset >= 0 && mWidth + widthOffset < aiGridSize) {
			for (int heightOffset = -max; heightOffset <= max; heightOffset++) {
				// Bounds check Y
				if (mHeight + heightOffset >= 0 && mHeight + heightOffset < aiGridSize
				    && aiGridMap[centerCellIndex + widthOffset * aiGridSize + heightOffset]) {
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

	// When not in "grid xyz" mode, ignore Y entirely.
	if (AIPerf::useGrid != 1) {
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
	f32 worldX      = pos.x;
	f32 worldZ      = pos.z;
	int previousRow = mWidth;
	int previousCol = mHeight;

	if (AIPerf::aiGrid) {
		// Calculate new grid cell indices based on position and grid shift
		mWidth = worldX;
		mWidth = (aiGridSize >> 1) + (mWidth >> aiGridShift);

		mHeight = worldZ;
		mHeight = (aiGridSize >> 1) + (mHeight >> aiGridShift);

		// Update map counts if the grid cell has changed
		if (updateMap && (mWidth != previousRow || mHeight != previousCol)) {
			int previousCellIndex = previousCol + previousRow * aiGridSize;
			if (aiGridMap[previousCellIndex]) {
				aiGridMap[previousCellIndex]--;
			}

			int currentCellIndex = mHeight + mWidth * aiGridSize;
			aiGridMap[currentCellIndex]++;
		}
	}
}

/**
 * @brief Draws a 2D grid onto the screen representing cells of the `FastGrid::aiGridMap` nearby to the creature
 * whose `FastGrid` invoked the member function.  Navi and/or Piki population counts are shown, and Tekis and/or
 * WorkObjects occupying the cells of the fastgrid are represented by a filled square (WorkObjects take priority).
 * A gray square indicates that whatever is occupying that square is being AI culled (`FastGrid::aiCulling`).
 * A red square represents a teki whose AI is NOT being culled, and green square likewise represents a WorkObject.
 * The displayed amount of cells in the on-screen display is configurable via the named constant `dispAmount`.
 * The width and height of individual cells drawn to the screen is configurable via the named constant `cellSize`.
 * Hooking this function into `GameCoreSection::draw2D` or `Navi::refresh2d` is a good way to see it in action.
 * @note UNUSED Size: 000820 (Matching by size)
 */
void FastGrid::renderAIGrid2D(Graphics& gfx)
{
	int rowIndex, colIndex;

	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(155, 155, 155, 255), true);

	// Making the following named constants actually `const` affects matching.  Lovely const memes!
	immut int dispAmount = 12; // Width and height (in cells) of the displayed square grid of cells.
	immut int rowOffset  = mWidth - (dispAmount >> 1);
	immut int colOffset  = mHeight - (dispAmount >> 1);
	immut f32 cellSize   = 20.0f; // Width and height of one single grid cell.

	for (rowIndex = 0; rowIndex < dispAmount; ++rowIndex) {
		Vector3f lineStart(rowIndex * cellSize + 40.0f, 40.0f, 0.0f);
		Vector3f lineEnd(rowIndex * cellSize + 40.0f, dispAmount * cellSize + 40.0f, 0.0f);
		gfx.drawLine(lineStart, lineEnd);

		lineStart.set(40.0f, rowIndex * cellSize + 40.0f, 0.0f);
		lineEnd.set(dispAmount * cellSize + 40.0f, rowIndex * cellSize + 40.0f, 0.0f);
		gfx.drawLine(lineStart, lineEnd);
	}

	char buffer[8];

	for (rowIndex = 0; rowIndex < dispAmount; ++rowIndex) {
		for (colIndex = 0; colIndex < dispAmount; ++colIndex) {
			int myGridCellRow = rowIndex + rowOffset;
			int myGridCellCol = colIndex + colOffset;
			if (myGridCellRow >= 0 && myGridCellCol >= 0 && myGridCellRow < aiGridSize && myGridCellCol < aiGridSize) {
				Iterator tekiIter(tekiMgr);
				CI_LOOP(tekiIter)
				{
					Creature* teki = *tekiIter;
					if (teki->mGrid.mWidth == myGridCellRow && teki->mGrid.mHeight == myGridCellCol) {
						if (teki->mGrid.aiCulling()) {
							gfx.setColour(Colour(100, 100, 100, 255), true);
						} else {
							gfx.setColour(Colour(200, 100, 100, 255), true);
						}
						RectArea tekiRect;
						tekiRect.set(rowIndex * cellSize + 1.0f, colIndex * cellSize + 1.0f,
						             rowIndex * cellSize + cellSize - 1.0f, colIndex * cellSize + cellSize - 1.0f);
						tekiRect.mMinX = tekiRect.mMinX + 40.0f;
						tekiRect.mMinY = tekiRect.mMinY + 40.0f;
						tekiRect.mMaxX = tekiRect.mMaxX + 40.0f;
						tekiRect.mMaxY = tekiRect.mMaxY + 40.0f;
						gfx.fillRectangle(tekiRect);
					}
				}

				Iterator workObjectIter(workObjectMgr);
				CI_LOOP(workObjectIter)
				{
					Creature* workObject = *workObjectIter;
					if (workObject->mGrid.mWidth == myGridCellRow && workObject->mGrid.mHeight == myGridCellCol) {
						if (workObject->mGrid.aiCulling()) {
							gfx.setColour(Colour(100, 100, 100, 255), true);

						} else {
							gfx.setColour(Colour(100, 200, 100, 255), true);
						}
						RectArea workRect;
						workRect.set(rowIndex * cellSize + 1.0f, colIndex * cellSize + 1.0f,
						             rowIndex * cellSize + cellSize - 1.0f, colIndex * cellSize + cellSize - 1.0f);
						workRect.mMinX = workRect.mMinX + 40.0f;
						workRect.mMinY = workRect.mMinY + 40.0f;
						workRect.mMaxX = workRect.mMaxX + 40.0f;
						workRect.mMaxY = workRect.mMaxY + 40.0f;
						gfx.fillRectangle(workRect);
					}
				}

				// Print the population count of the current cell if it's greater than zero.
				u32 cellPopulation = aiGridMap[myGridCellRow * aiGridSize + myGridCellCol];
				if (cellPopulation) {
					f32 textX = rowIndex * cellSize + 40.0f;
					f32 textY = colIndex * cellSize + 40.0f;
					sprintf(buffer, "%d", cellPopulation);
					gfx.setColour(Colour(155, 155, 155, 255), true);
					gfx.texturePrintf(gsys->mConsFont, static_cast<int>(textX) + 4, static_cast<int>(textY) + 4, buffer);
				}
			}
		}
	}
}

/**
 * @brief Draws a red border around cells of the `FastGrid::aiGridMap` containing Navis
 * and/or Pikis, and also prints the population count of said occupied cells above them.
 * Hooking this function into `GameCoreSection::draw` is a good way to see it in action.
 * @note UNUSED Size: 000348 (Matching by size)
 */
void FastGrid::renderAIGrid(Graphics& gfx)
{
	int rowIndex, colIndex;

	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(255, 0, 0, 255), true);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	bool prevSetting = gfx.setLighting(false, nullptr);

	f32 cellSize = (32768.0f / aiGridSize) * 2;
	char buffer[PATH_MAX];

	for (rowIndex = 0; rowIndex < aiGridSize; ++rowIndex) {
		for (colIndex = 0; colIndex < aiGridSize; ++colIndex) {
			if (aiGridMap[rowIndex * aiGridSize + colIndex] != 0) {
				f32 xPos = (rowIndex - (aiGridSize >> 1)) << aiGridShift;
				f32 zPos = (colIndex - (aiGridSize >> 1)) << aiGridShift;
				f32 yPos = 4.0f;

				gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);

				Vector3f northwest(xPos, yPos, zPos);
				Vector3f southwest(xPos, yPos, zPos + cellSize);
				Vector3f northeast(xPos + cellSize, yPos, zPos);
				Vector3f southeast(xPos + cellSize, yPos, zPos + cellSize);

				gfx.drawLine(northwest, southwest); // 1<-----4
				gfx.drawLine(southwest, southeast); // |      ^
				gfx.drawLine(southeast, northeast); // v      |
				gfx.drawLine(northeast, northwest); // 2----->3

				// Check it again just to be sure, lol.
				if (aiGridMap[rowIndex * aiGridSize + colIndex] != 0) {
					gfx.useMatrix(Matrix4f::ident, 0);

					Vector3f printfPos(xPos + cellSize * 0.5f, yPos + 10.0f, zPos + cellSize * 0.5f);
					printfPos.multMatrix(gfx.mCamera->mLookAtMtx);

					sprintf(buffer, "%d", aiGridMap[rowIndex * aiGridSize + colIndex]);
					gfx.perspPrintf(gsys->mConsFont, printfPos, -(gsys->mConsFont->stringWidth(buffer) / 2), 0, buffer);
				}
			}
		}
	}
}
