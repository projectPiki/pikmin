#ifndef _ANODE_H
#define _ANODE_H

#include "types.h"

class AgeServer;

/**
 * @brief A base class for nodes. Shorthand for Age Node.
 * @note 'Age' is the system used for debugging in the Windows version.
 */
class ANode {
public:
#if defined(WIN32)
	virtual void genAge(AgeServer& server) { }
	virtual void genAgeNode(AgeServer& server) { }
#endif
	virtual int getAgeNodeType() { return 0; } // _08 (weak)

	// _00 = VTBL
};

#endif
