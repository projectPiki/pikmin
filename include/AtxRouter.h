#ifndef _ATXROUTER_H
#define _ATXROUTER_H

#include "types.h"

class AtxStream;

/**
 * @brief Abstract base class for ATX communication routers.
 * @details Used by AtxStream to route communication over different transports.
 */
class AtxRouter {
public:
	virtual bool openRoute(AtxStream*, int) = 0; // _00
	virtual void closeRoute(AtxStream*)     = 0; // _04
	virtual void lock() { }                      // _08
	virtual void unlock() { }                    // _0C
	virtual void closeAll() { }                  // _10
	virtual void reset() = 0;                    // _14
	virtual bool isConnected() { return false; } // _18
	virtual void setWindow(u32) { }              // _1C

	// _00     = VTBL
};

#endif
