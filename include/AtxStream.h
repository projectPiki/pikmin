#ifndef _ATXSTREAM_H
#define _ATXSTREAM_H

#include "Stream.h"
#include "types.h"

// Misc. definitions
#define ATX_SERVICE_NAME_SIZE (4)     // 3 chars + null terminator
#define ATX_SERVICE_FILE      ("fil") // For requesting file operations
#define ATX_SERVICE_AGE       ("age") // For requesting AgeServer operations
#define ATX_SERVICE_APP       ("app") // For requesting App control operations

// TODO: There are some identifier numbers that I THINK reference which service
// is being requested But I'm not 100% sure, see all instances of open(const
// char*, int) in the codebase for more info.

// Opcodes from client to server.
#define ATX_CMD_ID    (1)       // Retrieves identification
#define ATX_CMD_START ('age\0') // Starts the server
#define ATX_CMD_CLOSE (0xFFFFu) // Closes the server

// Generic error reply from server.
// Note: This matches ATX_CMD_CLOSE on purpose in the original protocol.
#define ATX_REPLY_ERROR (0xFFFFu)

// Request opcodes for AtxFileStream.
#define ATX_FILE_CMD_READ    (100) // Read data
#define ATX_FILE_CMD_WRITE   (101) // Write data
#define ATX_FILE_CMD_SET_POS (102) // Set file position
#define ATX_FILE_CMD_CLOSE   (103) // Close file

struct AtxStream;
struct BaseApp;

/**
 * @brief Websocket wrapper for network communication.
 * @details Windows-only code, used by AtxStream for TCP communication.
 * @todo Decompile this struct and its methods.
 */
struct WSocket {
	/// @brief Initializes the Winsock library. (Called once at program start.)
	static void init();

	bool checkForConnections();
	void close();
	bool closing();
	void connect();
	bool create(char*, int);
	bool open(char*, int);
	u32 pending();
	void setASync(HWND hWnd, u32 wMsg, u32 lEvent, int sock);

	void read(void* buf, int length);
	void write(void* buf, int length);
	void flushWrite();

	int mListenSocket;   // _00, socket used for listening for connections
	int mAcceptedSocket; // _04, socket for an accepted connection
};

/**
 * @brief TCP communication stream.
 * @details Used by AtxStream for network communication.
 */
struct TcpStream : public Stream {
#ifdef WIN32
	TcpStream();
	TcpStream(WSocket*);

	virtual void read(void*, int);
	virtual void write(void*, int);
	virtual int getPending();
	virtual int getAvailable();
	virtual void close();
	virtual void flush();
	virtual bool closing();

	bool connect(char* name, int port);

	// _04     = VTBL
	// _00-_08 = Stream
	WSocket* mSocket; // _08, underlying socket used for communication
	int mStreamType;  // _0C, type of stream (e.g. 0 = client, 1 = server)
#endif
};

/**
 * @brief Abstract base class for ATX communication routers.
 * @details Used by AtxStream to route communication over different transports.
 */
struct AtxRouter {
	virtual bool openRoute(AtxStream*, int) = 0; // _00
	virtual void closeRoute(AtxStream*)     = 0; // _04
	virtual void lock() { }                      // _08
	virtual void unlock() { }                    // _0C
	virtual void closeAll() { }                  // _10
	virtual void reset() = 0;                    // _14
	virtual bool isConnected() { return false; } // _18
	virtual void setWindow(HWND) { }             // _1C
};

/**
 * @brief TCP communication stream used across a network.
 * @details This is used to communicate between developer tools, allowing for
 * debug GUIs.
 *
 * @note Size: 0x10.
 */
struct AtxStream : public Stream {
	AtxStream() { init(); }

	virtual void read(void* buffer, int size);        // _3C
	virtual void write(immut void* buffer, int size); // _40
	virtual int getPending();                         // _44
	virtual void close();                             // _4C
	virtual void flush();                             // _54

	bool open(immut char* name, int unused);

	void init() { _0C = 0; }

	// _04     = VTBL
	// _00-_08 = Stream
	TcpStream* mStream; // _08, underlying TCP stream used for communication
	int _0C;            // _0C
};

/**
 * @brief ATX command stream for handling incoming commands.
 * @details Used by PlugPikiApp to process commands from a connected ATX server.
 */
struct AtxCommandStream : public AtxStream {
	AtxCommandStream(BaseApp* app)
	    : mParentApp(app)
	{
	}

	BOOL checkCommands();

	// _04     = VTBL
	// _00-_08 = AtxStream
	BaseApp* mParentApp; // _08, pointer to the parent application
};

/**
 * @brief Wrapper for handling file operations over the ATX protocol.
 */
struct AtxFileStream : public RandomAccessStream {
	virtual void read(void*, int);        // _3C
	virtual void write(immut void*, int); // _40
	virtual int getPending();             // _44 (weak)
	virtual void close();                 // _4C
	virtual int getPosition();            // _58 (weak)
	virtual void setPosition(int);        // _5C
	virtual int getLength();              // _60 (weak)
	virtual void setLength(int);          // _64 (weak)

	bool open(immut char*, u32);

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	int mPosition;        // _08, current position in the file
	int mLength;          // _0C, length of the file
	AtxStream mAtxStream; // _10, underlying ATX stream used for communication
};

#ifdef WIN32
/**
 * @brief Direct router using TCP for AtxStream.
 */
struct AtxDirectRouter : public AtxRouter {
	virtual bool openRoute(AtxStream*, int); // _00
	virtual void closeRoute(AtxStream*);     // _04
	virtual void lock();                     // _08
	virtual void unlock();                   // _0C
	virtual void closeAll();                 // _10
	virtual void reset();                    // _14
	virtual bool isConnected();              // _18
	virtual void setWindow(HWND);            // _1C

	// _04     = VTBL
	char* mAddress;     // _04, the address the router connects to
	u32 _08;            // _08
	u8 _0C;             // _0C
	bool mIsConnected;  // _0D, whether the router is connected
	TcpStream* mStream; // _10, the TCP stream used for communication
};
#endif

#endif
