#include "Stream.h"

#include "String.h"
#include <stl/string.h>

// operator new[] is used without this header being included.
#if defined(BUGFIX)
#include "sysNew.h"
#endif

int Stream::readInt()
{
	int i;
	read(&i, sizeof(int));
	return i;
}

u8 Stream::readByte()
{
	u8 c;
	read(&c, sizeof(u8));
	return c;
}

s16 Stream::readShort()
{
	s16 s;
	read(&s, sizeof(s16));
	return s;
}

f32 Stream::readFloat()
{
	f32 f;
	read(&f, sizeof(f32));
	return f;
}

char* Stream::readString()
{
	int size = readInt();

	char* str = new char[size + 1];
	read(str, size);
	str[size] = '\0';
	return str;
}

void Stream::readString(char* dest, int size)
{
	String str(dest, size);
	readString(str);
}

void Stream::readString(String& str)
{
	int size = readInt();
	if (str.mLength < size) {
		str.init(size);
	}

	read(str.mString, size);
	str.mString[size] = '\0';
}

void Stream::writeInt(int i)
{
	int result = i;
#ifdef WIN32
	result = (((result & 0xFF000000) >> 24) | ((result & 0xFF0000) >> 8) | ((result & 0xFF00) << 8) | (result << 24));
#endif
	write(&result, sizeof(result));
}

void Stream::writeByte(u8 c)
{
	write(&c, sizeof(u8));
}

void Stream::writeShort(s16 _s)
{
	s16 s = _s;
#ifdef WIN32
	s = (((s & 0xFF00) >> 8) | (s << 8));
#endif
	write(&s, sizeof(s16));
}

void Stream::writeFloat(f32 f)
{
	f32 result = f;
#ifdef WIN32
	int c  = *static_cast<int*>(&result);
	result = ((u8)c << 24) | ((c & 0xFF00) << 8) | ((c & 0xFF0000) >> 8) | ((c & 0xFF000000) >> 24);
#endif
	write(&result, sizeof(f32));
}

void Stream::writeString(immut char* str)
{
	// `String` can't decide if it wants to be owning or non-owning.
	String s(const_cast<char*>(str), 0);
	writeString(s);
}

void Stream::writeString(immut String& s)
{
	s32 length = ALIGN_NEXT(s.getLength(), 4);
	writeInt(length);
	write(s.mString, s.getLength());

	char c = 0;
	for (s32 i = 0; i < length - s.getLength(); i++) {
		write(&c, 1);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void Stream::print(immut char* fmt, ...)
{
	char dest[1024];
	va_list args;
	va_start(args, fmt);
	vsprintf(dest, fmt, args);
	if (strlen(dest)) {
		write(dest, strlen(dest));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
// void Stream::vPrintf(char*, std::@class$1stream_cpp*)
// {
// 	// UNUSED FUNCTION
// }

void Stream::read(void*, int)
{
}

void Stream::write(immut void*, int)
{
}

int Stream::getPending()
{
	return 0;
}

int Stream::getAvailable()
{
	return 0;
}

void Stream::close()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void RandomAccessStream::writeTo(int p1, void*, int)
{
	// this is just here to spawn the weak function setPosition(int);
	setPosition(p1);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
// void RandomAccessStream::readFrom(int, void*, int)
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
// void RandomAccessStream::writeIntTo(int, int)
// {
// 	// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
// void RandomAccessStream::readIntFrom(int)
// {
// 	// UNUSED FUNCTION
// }

// bool Stream::getClosing() { return false; }
