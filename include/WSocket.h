#ifndef _WSOCKET_H
#define _WSOCKET_H

#include "types.h"

#include <windows.h>

/**
 * @brief Websocket wrapper for network communication.
 * @details Windows-only code, used by AtxStream for TCP communication.
 */
class SYSCORE_API WSocket {
public:
	static void init();

	bool checkForConnections();
	void close();
	int closing();
	void connect();
	bool create(char*, int);
	bool open(char*, int);
	int pending();
	void setASync(HWND hWnd, u32 wMsg, u32 lEvent, int sock);

	void read(void* buf, int length);
	void write(immut void* buf, int length);
	void flushWrite();

	int mListenSocket;    // _00, socket used for listening for connections
	int mConnectedSocket; // _04, socket for an accepted connection
};

#endif
