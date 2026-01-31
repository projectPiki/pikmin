#include "AtxStream.h"

#include "BaseApp.h"
#include "DebugLog.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

/**
 * @brief Closes the communication route.
 */
void AtxStream::close()
{
	gsys->getAtxRouter()->closeRoute(this);
}

/**
 * @brief Opens a communication channel to the specified server.
 * @param name The name of the server to connect to.
 * @param unused An unused parameter.
 * @return True if the connection was successful, false otherwise.
 */
bool AtxStream::open(immut char* name, int unused)
{
	AtxRouter* router = gsys->getAtxRouter();
	if (!router) {
		return false;
	}

	// Attempt to open the route
	if (!router->openRoute(this, unused)) {
#if defined(VERSION_GPIJ01) || defined(VERSION_DPIJ01_PIKIDEMO)
#else
		ERROR("Could not open route to server\n");
#endif
		gsys->setAtxRouter(nullptr);
		return false;
	}

	// Send the fixed-width service name to the server (e.g. "fil\0").
	write(name, ATX_SERVICE_NAME_SIZE);
	if (mStream->readInt() == (u32)ATX_REPLY_ERROR) {
		return false;
	}

	// Good to go, flush buffer and we're done
	flush();
	return true;
}

/**
 * @brief Writes data to the stream.
 * @param buffer The buffer containing the data to write.
 * @param count The size of buffer.
 */
void AtxStream::write(immut void* buffer, int count)
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	mStream->write(buffer, count);

	router->unlock();
}

/**
 * @brief Unlocks the communication route.
 * @details Empty virtual function to be overridden in an AtxRouter implementation.
 * @note UNUSED Size: 000004
 */
#ifdef WIN32
void AtxRouter::unlock()
{
}
#endif

/**
 * @brief Locks the communication route.
 * @details Empty virtual function to be overridden in an AtxRouter implementation.
 * @note UNUSED Size: 000004
 */
#ifdef WIN32
void AtxRouter::lock()
{
}
#endif

/**
 * @brief Reads data from the stream.
 * @param buffer The buffer to read data into.
 * @param count The size of buffer.
 */
void AtxStream::read(void* buffer, int count)
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();
	mStream->read(buffer, count);
	router->unlock();
}

/**
 * @brief Gets the number of pending bytes in the stream.
 * @return The number of pending bytes.
 */
int AtxStream::getPending()
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	int pending = mStream->getPending();

	router->unlock();
	return pending;
}

/**
 * @brief Flushes the stream.
 */
void AtxStream::flush()
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	mStream->flush();

	router->unlock();
}

/**
 * @brief Checks for incoming commands from the connected server.
 * @return TRUE if a command was processed, FALSE otherwise.
 * @note UNUSED Size: 0000D0
 */
BOOL AtxCommandStream::checkCommands()
{
	if (!getPending()) {
		return FALSE;
	}

	int command = readInt();
	switch (command) {
	case ATX_CMD_ID:
	{
		PRINT("Atx - Sending identification information\n");
		writeString(mPath);
		break;
	}
	case ATX_CMD_CLOSE:
	{
		PRINT("Atx - Server is closing\n");
		mParentApp->stopAgeServer();
		break;
	}
	case ATX_CMD_START:
	{
		mParentApp->startAgeServer();
		break;
	}
	}

	return TRUE;
}

/**
 * @brief Opens a file stream over ATX.
 * @param path The path of the file to open.
 * @note UNUSED Size: 000170
 */
bool AtxFileStream::open(immut char* path, u32)
{
	if (!mAtxStream.open(ATX_SERVICE_FILE, 3)) {
		PRINT("Could not open file service!!\n");
		return false;
	}

	mAtxStream.writeString(path);
	mAtxStream.writeInt(0);
	mLength   = getLength();
	mPosition = 0;

	if (mLength < 0) {
		mAtxStream.close();
		return false;
	}

	mPath = path;
	return true;
}

/**
 * @brief Sets the current position in the file stream.
 * @param pos The position to set.
 */
void AtxFileStream::setPosition(int pos)
{
	mPosition = pos;

	mAtxStream.writeInt(ATX_FILE_CMD_SET_POS);
	mAtxStream.writeInt(mPosition);
}

/**
 * @brief Reads data from the file stream.
 * @param buffer The buffer to read data into.
 * @param length The number of bytes to read.
 */
void AtxFileStream::read(void* buffer, int length)
{
	mAtxStream.writeInt(ATX_FILE_CMD_READ);
	mAtxStream.writeInt(length);
	mAtxStream.read(buffer, length);
	mPosition += length;
}

/**
 * @brief Writes data to the file stream.
 * @param buffer The buffer containing the data to write.
 * @param length The number of bytes to write.
 */
void AtxFileStream::write(immut void* buffer, int length)
{
	mAtxStream.writeInt(ATX_FILE_CMD_WRITE);
	mAtxStream.writeInt(length);
	mAtxStream.write(buffer, length);
	mPosition += length;

	if (mPosition > mLength) {
		mLength = mPosition;
	}
}

/**
 * @brief Closes the file stream.
 */
void AtxFileStream::close()
{
	mAtxStream.writeInt(ATX_FILE_CMD_CLOSE);
	mAtxStream.flush();
	mAtxStream.readInt();
	mAtxStream.close();
}

/**
 * @brief Gets the number of bytes remaining to read in the file stream.
 * @return The number of pending bytes.
 */
int AtxFileStream::getPending()
{
	return mLength - mPosition;
}

/**
 * @brief Gets the current position in the file stream.
 * @return The current position.
 */
int AtxFileStream::getPosition()
{
	return mPosition;
}

/**
 * @brief Gets the length of the file stream.
 * @return The length of the file.
 */
int AtxFileStream::getLength()
{
	return mLength;
}

/**
 * @brief Sets the length of the file stream.
 * @param length The length to set.
 */
void AtxFileStream::setLength(int length)
{
	mLength = length;
}

#ifdef WIN32

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::closeAll()
{
}

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::closeRoute(AtxStream* /*unused*/)
{
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

/**
 * @brief A no-op function.
 */
void AtxDirectRouter::reset()
{
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

	if (!mStream->connect(mAddress, 1369)) {
		return false;
	}

	if (sysCurrWnd) {
		// TODO: Repalce with actual enum vars
		mStream->mSocket->setASync(sysCurrWnd, 0x433u, 0x21u, -1);
	}

	stream->mStream = mStream;
	return true;
}

/**
 * @brief Sets the window handle for asynchronous socket operations.
 * @param hwnd The window handle.
 */
void AtxDirectRouter::setWindow(HWND hwnd)
{
	if (mStream) {
		mStream->mSocket->setASync(hwnd, 0x433u, 0x21u, -1);
	}
}

#endif
