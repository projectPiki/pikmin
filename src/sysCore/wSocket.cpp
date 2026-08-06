#include "WSocket.h"

#include "DebugLog.h"

DEFINE_ERROR(7)
DEFINE_PRINT("wSocket")

/**
 * @brief Initializes the Winsock library.  Called once at program start.
 */
void WSocket::init()
{
	WORD wVersionRequired = MAKEWORD(2, 0); // Windows Sockets specification 2.0
	WSADATA WSAData;

	int startupResult = WSAStartup(wVersionRequired, &WSAData);
	if (startupResult != NO_ERROR) {
		PRINT("Can't open win sock DLL !!\n");
	}
}

/**
 * @todo Documentation
 */
bool WSocket::open(char* hostName, int port)
{
	LPHOSTENT host = gethostbyname(hostName);
	if (!host) {
		PRINT("could not get host by name\n");
		return false;
	}

	mConnectedSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mConnectedSocket <= 0) {
		PRINT("Could not create socket!!\n");
		return false;
	}

	sockaddr_in name;
	memset(&name, 0, sizeof(name));
	name.sin_family      = AF_INET;
	name.sin_addr.s_addr = 0;
	name.sin_port        = htons(0);

	int bindResult = bind(mConnectedSocket, reinterpret_cast<sockaddr*>(&name), sizeof(name));
	if (bindResult != NO_ERROR) {
		PRINT("Error binding socket!!\n");
		return false;
	}

	name.sin_port = htons(port);
	memcpy(&name.sin_addr, host->h_addr_list[0], host->h_length);
	if (::connect(mConnectedSocket, reinterpret_cast<sockaddr*>(&name), sizeof(name)) == SOCKET_ERROR) {
		PRINT("Could not connect to server\n");
		return false;
	}

	return true;
}

/**
 * @todo Documentation
 */
bool WSocket::create(char*, int port)
{
	mListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mListenSocket <= 0) {
		PRINT("Could not create socket!!\n");
		return false;
	}
	PRINT("got socket id %d\n", mListenSocket);

	sockaddr_in name;
	// No `memset` this time?
	name.sin_family      = AF_INET;
	name.sin_addr.s_addr = 0;
	name.sin_port        = htons(port);

	int bindResult = bind(mListenSocket, reinterpret_cast<sockaddr*>(&name), sizeof(name));
	if (bindResult != NO_ERROR) {
		PRINT("Error binding socket!!\n");
		return false;
	}

	int listenResult = listen(mListenSocket, 0x8000); // 8 KiB backlog

	return true;
}

/**
 * @brief This function isn't even virtual; it's a no-op for the love of the game.
 */
void WSocket::flushWrite()
{
}

/**
 * @brief Reports the total amount of data that can be read in a single receive operation.
 */
int WSocket::pending()
{
	u_long receiveAmount = 0; // `mConnectedSocket` is always SOCK_STREAM oriented
	if (ioctlsocket(mConnectedSocket, FIONREAD, &receiveAmount) < NO_ERROR) {
		return 0;
	}
	return receiveAmount;
}

/**
 * @todo Documentation
 */
bool WSocket::checkForConnections()
{
	fd_set readfds;
	readfds.fd_count = 0;
	FD_SET(mListenSocket, &readfds);

	TIMEVAL timeout;
	memset(&timeout, 0, sizeof(timeout));
	timeout.tv_usec = 1;

	// man7: `nfds` is the highest-numbered file descriptor in any of the three sets, plus 1.
	int selectResult = select(0 + 1, &readfds, nullptr, nullptr, &timeout);
	if (selectResult < NO_ERROR) {
		return false;
	}

	if (selectResult > 0) {
		if (FD_ISSET(mListenSocket, &readfds)) {
			return true;
		}
	}
	return false;
}

/**
 * @todo Documentation
 */
void WSocket::connect()
{
	sockaddr_in addr;
	int addrlen      = sizeof(addr);
	mConnectedSocket = accept(mListenSocket, reinterpret_cast<sockaddr*>(&addr), &addrlen);

	PRINT("got connected socket = %d : connection from %d.%d.%d.%d\n", mConnectedSocket, addr.sin_addr.s_net, addr.sin_addr.s_host,
	      addr.sin_addr.s_lh, addr.sin_addr.s_impno);
}

/**
 * @todo Documentation
 */
void WSocket::write(immut void* buffer, int length)
{
	int timeoutLimit = 200;
	while (length != 0) {
		int bytesSent = send(mConnectedSocket, static_cast<immut char*>(buffer), length, 0);
		if (bytesSent < 0) {
			int lastError = WSAGetLastError();
			if (lastError == WSAEWOULDBLOCK) {
				if (timeoutLimit-- <= 0) {
					ERROR("write timeout");
					return;
				}
				gsys->sleep(0.010f); // 10 milliseconds
				bytesSent = 0;
			} else {
				ERROR("send error %d", lastError);
			}
		} else if (bytesSent != length) {
			PRINT("!!! Not sent all data !!\n");
		}
		length -= bytesSent;
		buffer = static_cast<immut char*>(buffer) + bytesSent;
	}
}

/**
 * @todo Documentation
 */
void WSocket::read(void* buffer, int length)
{
	while (length != 0) {
		int bytesRead = recv(mConnectedSocket, static_cast<char*>(buffer), length, 0);
		if (bytesRead < 0) {
			int lastError = WSAGetLastError();
			if (lastError == WSAEWOULDBLOCK) {
				WaitMessage();
				bytesRead = 0;
			} else {
				ERROR("recv on sock %d : error %d", mConnectedSocket, lastError);
			}
		}
		length -= bytesRead;
		buffer = static_cast<char*>(buffer) + bytesRead;
	}
}

/**
 * @todo Documentation
 */
void WSocket::setASync(HWND hWnd, u32 wMsg, u32 lEvent, int socket)
{
	SOCKET s = (socket != -1) ? socket : mConnectedSocket;
	if (WSAAsyncSelect(s, hWnd, wMsg, lEvent) == SOCKET_ERROR) {
		PRINT("Error switching to Async mode\n");
	}
}

/**
 * @todo Documentation
 */
void WSocket::close()
{
	closesocket(mConnectedSocket);
}
