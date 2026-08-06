#include "AtxDirectRouter.h"

#include "AtxStream.h"
#include "TcpStream.h"
#include "WSocket.h"
#include "system.h"

#include <string.h>

AtxDirectRouter::AtxDirectRouter(immut char* address)
{
	mAddress = !strcmp(address, "self") ? gsys->_3B8 : StdSystem::stringDup(address);
	mStream = nullptr;
}

/**
 * @brief Sets the window handle for asynchronous socket operations.
 * @param hwnd The window handle.
 */
void AtxDirectRouter::setWindow(u32 hwnd)
{
	if (hwnd && mStream) {
		// TODO: Is 0x433 a Windows enum or a Pikmin enum?
		mStream->mSocket->setASync(reinterpret_cast<HWND>(hwnd), 0x433, FD_READ | FD_CLOSE, -1);
	}
}

/**
 * @brief Opens a communication route to the specified address and port.
 * @param stream The AtxStream to associate with the route.
 * @param unused Unused parameter.
 * @return True if the route was successfully opened, false otherwise.
 */
bool AtxDirectRouter::openRoute(AtxStream* stream, int /*unused*/)
{
	mStream              = new TcpStream();
	mStream->mStreamType = 2;

	bool connected = mStream->connect(mAddress, 1369);
	if (!connected) {
		return false;
	}

	if (sysCurrWnd) {
		// TODO: Is 0x433 a Windows enum or a Pikmin enum?
		mStream->mSocket->setASync(sysCurrWnd, 0x433, FD_READ | FD_CLOSE, -1);
	}

	stream->mStream = mStream;
	return true;
}

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::closeRoute(AtxStream* stream)
{
}

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::reset()
{
}

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::closeAll()
{
}

// I'm seriously suspicious of the following functions.  Is everything past this point actually weak functions?

/**
 * @note What is this doing here??
 */
int WSocket::closing()
{
	return 0;
}

/**
 * @note What is this doing here??
 */
TcpStream::TcpStream()
{
	mSocket     = nullptr;
	mStreamType = 0;
}

/**
 * @brief Checks if the router is connected.
 * @return True if connected, false otherwise.
 */
bool AtxDirectRouter::isConnected()
{
	return mIsConnected;
}

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::lock()
{
}

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::unlock()
{
}
