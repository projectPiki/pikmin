#ifndef _UTILITYKANDO_H
#define _UTILITYKANDO_H

#include "types.h"

struct Graphics;
struct RandomAccessStream;
struct Vector3f;

/**
 * @brief TODO
 *
 * @note Does NOT have an explicit ctor.
 */
struct Choice {
	int mValue;  // _00
	f32 mChance; // _04
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

	u8* mFlags;      // _00
	u16 mEntryCount; // _04
	u16 mSize;       // _06
};

/**
 * @brief TODO
 */
struct LoopChecker {
	LoopChecker(char* loopName, f32 timeLimit);

	void update();

	f32 mLoopTimer;  // _00, counts down. at 0, throws an error
	char* mLoopName; // _04
};

// utility functions
int selectRandomly(Choice* choiceList, int numChoices);
void drawBatten(Graphics&, Vector3f&, f32);
void drawBattenPole(Graphics&, Vector3f&, f32, char*);
void drawArrow(Graphics&, Vector3f&, Vector3f&, f32);
void CRSplineDraw(Graphics&, int, Vector3f*);
void drawCube(Graphics&, Vector3f&, f32);

#endif
