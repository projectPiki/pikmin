#include "TcpStream.h"

#include "WSocket.h"
#include "system.h"

/**
 * @todo Documentation
 */
TcpStream::TcpStream(WSocket* param_1)
{
	mSocket = new WSocket;

	mSocket->mListenSocket = param_1->mListenSocket;
	mSocket->connect();
}

/**
 * @todo Documentation
 */
bool TcpStream::connect(char* hostName, int port)
{
	mSocket = new WSocket;
	return mSocket->open(hostName, port) != false;
}

/**
 * @todo Documentation
 */
int TcpStream::getPending()
{
	return mSocket->pending();
}

/**
 * @todo Documentation
 */
int TcpStream::getAvailable()
{
	return 0;
}

/**
 * @todo Documentation
 */
void TcpStream::flush()
{
	mSocket->flushWrite();
}

/**
 * @todo Documentation
 */
void TcpStream::read(void* buffer, int length)
{
	int oldStreamType = gsys->setStreamType(mStreamType);
	mSocket->read(buffer, length);
	gsys->setStreamType(oldStreamType);
}

/**
 * @todo Documentation
 */
void TcpStream::write(immut void* buffer, int length)
{
	mSocket->write(buffer, length);
}

/**
 * @todo Documentation
 */
void TcpStream::close(void)
{
	mSocket->close();
}

/**
 * @todo Documentation
 */
bool TcpStream::closing()
{
	return mSocket->closing() != FALSE;
}
