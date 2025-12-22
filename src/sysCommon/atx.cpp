#include "AtxStream.h"

#include "DebugLog.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/**
 * @TODO: Documentation
 */
void AtxStream::close()
{
	gsys->getAtxRouter()->closeRoute(this);
}

/**
 * @TODO: Documentation
 */
bool AtxStream::open(immut char* name, int port)
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

/**
 * @TODO: Documentation
 */
void AtxStream::write(immut void* buffer, int count)
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

/**
 * @TODO: Documentation
 */
void AtxStream::read(void* buffer, int count)
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	mNetStream->read(buffer, count);

	router->unlock();
}

/**
 * @TODO: Documentation
 */
int AtxStream::getPending()
{
	AtxRouter* router = gsys->getAtxRouter();
	router->lock();

	int pending = mNetStream->getPending();

	router->unlock();
	return pending;
}

/**
 * @TODO: Documentation
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
// void AtxFileStream::open(immut char*, u32)
// {
// 	// UNUSED FUNCTION
// }

/**
 * @TODO: Documentation
 */
void AtxFileStream::setPosition(int pos)
{
	mPosition = pos;

	mAtxStream.writeInt(102);
	mAtxStream.writeInt(mPosition);
}

/**
 * @TODO: Documentation
 */
void AtxFileStream::read(void* buffer, int length)
{
	mAtxStream.writeInt(100);
	mAtxStream.writeInt(length);
	mAtxStream.read(buffer, length);
	mPosition += length;
}

/**
 * @TODO: Documentation
 */
void AtxFileStream::write(immut void* buffer, int length)
{
	mAtxStream.writeInt(101);
	mAtxStream.writeInt(length);
	mAtxStream.write(buffer, length);
	mPosition += length;

	if (mPosition > mLength) {
		mLength = mPosition;
	}
}

/**
 * @TODO: Documentation
 */
void AtxFileStream::close()
{
	mAtxStream.writeInt(103);
	mAtxStream.flush();
	mAtxStream.readInt();
	mAtxStream.close();
}

/**
 * @TODO: Documentation
 */
int AtxFileStream::getPending()
{
	return mLength - mPosition;
}

/**
 * @TODO: Documentation
 */
int AtxFileStream::getPosition()
{
	return mPosition;
}

/**
 * @TODO: Documentation
 */
int AtxFileStream::getLength()
{
	return mLength;
}

/**
 * @TODO: Documentation
 */
void AtxFileStream::setLength(int length)
{
	mLength = length;
}

#ifdef WIN32

// This a .dll exclusive function, equivalence is not guaranteed!

bool AtxFileStream::open(immut char* path, u32 a)
{
	if (!mAtxStream.open("fil", 3)) {
		PRINT("Could not open file service!!\n");
		return false;
	}

	mAtxStream.writeString(path);
	mAtxStream.writeInt(a);
	mLength = getLength();
	mSRT.t  = 0;

	if (mLength < 0) {
		mAtxStream.close();
		return false;
	}

	mPath = path;
	return true;
}
#endif
