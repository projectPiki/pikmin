#ifndef _TRISTRIPIFIER_H
#define _TRISTRIPIFIER_H

#include "types.h"

class RandomAccessStream;

/**
 * @todo Documentation
 */
class TriInfo {
public:
	void unlink(TriInfo*);

	// TODO: Members
};

/**
 * @todo Documentation
 */
class TriLink {
public:
	TriLink(TriInfo*, TriInfo*, int);

	// TODO: Members
};

/**
 * @todo Documentation
 */
class TriStrip {
public:
	TriStrip();

	// TODO: Members
};

/**
 * @todo Documentation
 */
class TriStripifier {
public:
	void findStrips();
	void outputTriStrips(RandomAccessStream&);

	// TODO: Members
};

#endif
