#ifndef _ATXDIRECTROUTER_H
#define _ATXDIRECTROUTER_H

#include "types.h"

#include "AtxRouter.h"

class TcpStream;

/**
 * @brief Direct router using TCP for AtxStream.
 */
class AtxDirectRouter : public AtxRouter {
public:
	AtxDirectRouter(immut char*);

	virtual bool openRoute(AtxStream*, int); // _00
	virtual void closeRoute(AtxStream*);     // _04
	virtual void lock();                     // _08
	virtual void unlock();                   // _0C
	virtual void closeAll();                 // _10
	virtual void reset();                    // _14
	virtual bool isConnected();              // _18
	virtual void setWindow(u32);             // _1C

	// _00     = VTBL
	// _00-_04 = AtxRouter
	char* mAddress;     // _04, the address the router connects to
	u32 _08;            // _08
	bool _0C;           // _0C
	bool mIsConnected;  // _0D, whether the router is connected
	TcpStream* mStream; // _10, the TCP stream used for communication
};

#endif
