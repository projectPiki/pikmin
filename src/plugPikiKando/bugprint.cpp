#include "bugprint.h"

#include "Delegate.h"
#include "Graphics.h"
#include "sysNew.h"

#include <stdarg.h>

// Very mysterious file; it was completely deadstripped from retail.
// Here's what we know about it:

// Seen in the MetroWerks linker map:
//      5] __vt__22IDelegate1<R8Graphics> (object,weak) found in sysDolphin.a system.cpp
//      5] >>> UNREFERENCED DUPLICATE __vt__22IDelegate1<R8Graphics>
//      5] >>> (object,weak) found in plugPikiKando.a bugprint.cpp

// The following symbols are known via the plugPiki.dll ILK symbol scrape:
// _bugPrint
// class BugPrintBuffer * bugPrintBuffer
// public: __thiscall BugPrintBuffer::BugPrintBuffer(void)
// public: void __thiscall BugPrintBuffer::update(void)
// public: void __thiscall BugPrintBuffer::clear(void)
// public: void __thiscall BugPrintBuffer::print(char *,int)
// protected: int __thiscall BugPrintBuffer::findLine(int)
// public: int __thiscall BugPrintBuffer::getFrame(void)

// I assume this class was meant to do more than pointlessly store text in a circular buffer.
// Perhaps it was used for an on-screen display, but only in the GCN version of the game?
// That would explain the presence of the `Graphics` class in this otherwise simple file.

BugPrintBuffer* bugPrintBuffer;

/**
 * @todo Documentation
 */
BugPrintBuffer::BugPrintBuffer()
{
	mFrame       = 0;
	mCapacity    = 0x5000;
	mBuffer      = new char[mCapacity];
	mBufPos      = 0;
	clear();
}

/**
 * @todo Documentation
 */
void BugPrintBuffer::clear()
{
	for (int i = 0; i < mCapacity; ++i) {
		mBuffer[i] = '\0';
	}
	mBufPos = 0;
	mFrame  = 0;
}

/**
 * @todo Documentation
 */
void BugPrintBuffer::print(immut char* str, int len)
{
	for (int i = 0; i < len; ++i) {
		mBuffer[mBufPos] = *str++;
		mBufPos          = (mBufPos + 1) % mCapacity;
	}
	mBuffer[mBufPos] = '\0';
	mBufPos          = (mBufPos + 1) % mCapacity;
}

/**
 * @todo Documentation
 */
void BugPrintBuffer::update(void)
{
	++mFrame;
	if (mFrame >= 36000) {
		mFrame = 0;
	}
}

/**
 * @todo Documentation
 */
int BugPrintBuffer::findLine(int offset)
{
	int nullCharCounter = 0;
	while (true) {
		if (mBuffer[offset] == '\0') {
			if (++nullCharCounter == 2) {
				return (offset + 1) % mCapacity;
			}
		}
		if (--offset < 0) {
			offset = mCapacity - 1;
		}
	}
}

/**
 * @todo Documentation
 */
void bugPrint(immut char* fmt, ...)
{
	va_list args;
	char message[1024];
	char temp[1024];

	va_start(args, fmt);
	vsprintf(message, fmt, args);
	if (strlen(message) != 0 && bugPrintBuffer) {
		sprintf(temp, "%d:%s", bugPrintBuffer->getFrame(), message);
		bugPrintBuffer->print(temp, strlen(temp));
	}
	va_end(args);
}
