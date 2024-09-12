#ifndef _UTILITYKANDO_H
#define _UTILITYKANDO_H

#include "types.h"

struct Graphics;
struct RandomAccessStream;
struct Vector3f;

/**
 * @brief TODO
 */
struct Choice {
	// TODO: members
};

/**
 * @brief TODO
 */
struct BitFlags {
	BitFlags();

	void dump();
	void loadCard(RandomAccessStream&);
	void saveCard(RandomAccessStream&);
	void create(u16, u8*);
	void reset();
	void setFlag(u16);
	bool isFlag(u16);

	// unused/inlined:
	void resetFlag(u16);

	u8* _00; // _00
	u16 _04; // _04
	u16 _06; // _06
};

/**
 * @brief TODO
 */
struct LoopChecker {
	LoopChecker(char*, f32);

	void update();

	f32 _00;   // _00
	char* _04; // _04
};

// utility functions
void selectRandomly(Choice*, int);
void drawBatten(Graphics&, Vector3f&, f32);
void drawBattenPole(Graphics&, Vector3f&, f32, char*);
void drawArrow(Graphics&, Vector3f&, Vector3f&, f32);
void CRSplineDraw(Graphics&, int, Vector3f*);
void drawCube(Graphics&, Vector3f&, f32);

#endif
