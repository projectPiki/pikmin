#ifndef _FASTGRID_H
#define _FASTGRID_H

#include "types.h"

/**
 * @brief TODO
 */
struct FastGrid {
	FastGrid();

	void initAIGrid(u8);
	void clearAIGrid();
	void delAIGrid();
	void aiCulling();
	void aiCullingLarge(int);
	void doCulling(const FastGrid&, f32);
	void updateGrid(const struct Vector3f&);
	void updateAIGrid(const Vector3f&, bool);

	// unused/inlined:
	void addAIGrid();
	void renderAIGrid2D(struct Graphics&);
	void renderAIGrid(Graphics&);

	static u16 aiGridShift;
	static u32 aiGridMap; // type unsure
	static u16 aiGridSize;

	u16 _00; // _00
	u16 _02; // _02
	u16 _04; // _04
	u16 _06; // _06
	u16 _08; // _08
	u16 _0A; // _0A
	u16 _0C; // _0C
	u16 _0E; // _0E
	u16 _10; // _10
	u16 _12; // _12
	u16 _14; // _14
	u16 _16; // _16
};

#endif
