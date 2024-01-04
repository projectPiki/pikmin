#ifndef _FASTGRID_H
#define _FASTGRID_H

/*
 * @brief TODO
 */
struct FastGrid {
	FastGrid();
	void initAIGrid(unsigned char);
	void clearAIGrid();
	void delAIGrid();
	void aiCulling();
	void aiCullingLarge(int);
	void doCulling(const FastGrid&, float);
	void updateGrid(const Vector3f&);
	void updateAIGrid(const Vector3f&, bool);
};

#endif
