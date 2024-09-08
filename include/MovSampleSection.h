#ifndef _MOVSAMPLESECTION_H
#define _MOVSAMPLESECTION_H

#include "types.h"
#include "Section.h"

/**
 * @brief TODO
 */
struct MovSampleSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_?? = Section
	// TODO: members
};

/**
 * @brief TODO
 */
struct MovSampleSetupSection : public Node {
	virtual void update();        // _10 (weak)
	virtual void draw(Graphics&); // _14 (weak)

	// void movieNames$localstatic0$__ct(); // work out what the hell this is later

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

// Global functions:
void convHVQM4TexY8UV8(int, int, u8*, u8*);

#endif
