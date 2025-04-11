#ifndef _FASTGRID_H
#define _FASTGRID_H

#include "types.h"

/**
 * @brief TODO
 */
struct FastGrid {
	FastGrid();

	void delAIGrid();
	bool aiCulling();
	bool aiCullingLarge(int);
	bool doCulling(const FastGrid&, f32);
	void updateGrid(const struct Vector3f&);
	void updateAIGrid(const Vector3f&, bool);

	// unused/inlined:
	void addAIGrid();
	void renderAIGrid2D(struct Graphics&);

	static void initAIGrid(u8);
	static void clearAIGrid();
	static void renderAIGrid(Graphics&);

	void setNeighbourSize(int size) { mNeighbourSize = size; }

	static u16 aiGridShift;
	static u8* aiGridMap;
	static u16 aiGridSize;

	s16 mGridPositionX; // _00
	u16 _02;            // _02
	s16 mGridPositionY; // _04
	u16 _06;            // _06
	s16 mGridPositionZ; // _08
	u16 _0A;            // _0A
	s16 mWidth;         // _0C
	u16 _0E;            // _0E
	s16 mHeight;        // _10
	u16 _12;            // _12
	u16 mNeighbourSize; // _14
	u16 _16;            // _16
};

#endif
