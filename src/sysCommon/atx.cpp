#include "types.h"
#include "AtxStream.h"
#include "system.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	800438EC
 * Size:	000038
 */
void AtxStream::close()
{
	gsys->getAtxRouter()->closeRoute(this);
}

/*
 * --INFO--
 * Address:	80043924
 * Size:	0000D8
 */
bool AtxStream::open(char* name, int port)
{
	AtxRouter* router = gsys->getAtxRouter();
	if (!router)
		return false;

	if (!router->openRoute(this, port)) {
		ERROR("Could not open route to server\n");
		gsys->setAtxRouter(nullptr);
		return false;
	}

	write(name, 4);
	if (mNetStream->readInt() == (u32)0xFFFF) {
		return false;
	}

	flush();
	return true;
}

/*
 * --INFO--
 * Address:	800439FC
 * Size:	000094
 */
void AtxStream::write(void* buffer, int count)
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	mNetStream->write(buffer, count);

	router->unlock();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
// void AtxRouter::unlock()
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
// void AtxRouter::lock()
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	80043A90
 * Size:	000094
 */
void AtxStream::read(void* buffer, int count)
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	mNetStream->read(buffer, count);

	router->unlock();
}

/*
 * --INFO--
 * Address:	80043B24
 * Size:	000080
 */
int AtxStream::getPending()
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	int pending = mNetStream->getPending();

	router->unlock();
	return pending;
}

/*
 * --INFO--
 * Address:	80043BA4
 * Size:	000074
 */
void AtxStream::flush()
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	mNetStream->flush();

	router->unlock();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
// void AtxCommandStream::checkCommands()
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
// void AtxFileStream::open(char*, u32)
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	80043C18
 * Size:	00005C
 */
void AtxFileStream::setPosition(int pos)
{
	mPosition = pos;

	mAtxStream.writeInt(102);
	mAtxStream.writeInt(mPosition);
}

/*
 * --INFO--
 * Address:	80043C74
 * Size:	000098
 */
void AtxFileStream::read(void* buffer, int length)
{
	mAtxStream.writeInt(100);
	mAtxStream.writeInt(length);
	mAtxStream.read(buffer, length);
	mPosition += length;
}

/*
 * --INFO--
 * Address:	80043D0C
 * Size:	0000AC
 */
void AtxFileStream::write(void* buffer, int length)
{
	mAtxStream.writeInt(101);
	mAtxStream.writeInt(length);
	mAtxStream.write(buffer, length);
	mPosition += length;

	if (mPosition > mLength) {
		mLength = mPosition;
	}
}

/*
 * --INFO--
 * Address:	80043DB8
 * Size:	00007C
 */
void AtxFileStream::close()
{
	mAtxStream.writeInt(103);
	mAtxStream.flush();
	mAtxStream.readInt();
	mAtxStream.close();
}

/*
 * --INFO--
 * Address:	80043E34
 * Size:	000010
 */
int AtxFileStream::getPending()
{
	return mLength - mPosition;
}

/*
 * --INFO--
 * Address:	80043E44
 * Size:	000008
 */
int AtxFileStream::getPosition()
{
	return mPosition;
}

/*
 * --INFO--
 * Address:	80043E4C
 * Size:	000008
 */
int AtxFileStream::getLength()
{
	return mLength;
}

/*
 * --INFO--
 * Address:	80043E54
 * Size:	000008
 */
void AtxFileStream::setLength(int length)
{
	mLength = length;
}
