#ifndef _TCPSTREAM_H
#define _TCPSTREAM_H

#include "types.h"

#include "Stream.h"

class WSocket;

/**
 * @brief TCP communication stream.
 * @details Used by AtxStream for network communication.
 */
class TcpStream : public Stream {
public:
	TcpStream();
	TcpStream(WSocket*);

	virtual void read(void*, int);
	virtual void write(immut void*, int);
	virtual int getPending();
	virtual int getAvailable();
	virtual void close();
	virtual void flush();
	virtual bool closing();

	bool connect(char* name, int port);

	// _00     = VTBL
	// _00-_08 = Stream
	WSocket* mSocket; // _08, underlying socket used for communication
	int mStreamType;  // _0C, type of stream (e.g. 0 = client, 1 = server)
};

#endif
