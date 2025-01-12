#include "types.h"
#include "Stream.h"
#include "String.h"

/*
 * --INFO--
 * Address:	800250B0
 * Size:	000038
 */
int Stream::readInt()
{
	int i;
	read(&i, sizeof(int));
	return i;
}

/*
 * --INFO--
 * Address:	800250E8
 * Size:	000038
 */
u8 Stream::readByte()
{
	u8 c;
	read(&c, sizeof(char));
	return c;
}

/*
 * --INFO--
 * Address:	80025120
 * Size:	000038
 */
s16 Stream::readShort()
{
	s16 s;
	read(&s, sizeof(s16));
	return s;
}

/*
 * --INFO--
 * Address:	80025158
 * Size:	000038
 */
f32 Stream::readFloat()
{
	f32 f;
	read(&f, sizeof(f32));
	return f;
}

/*
 * --INFO--
 * Address:	80025190
 * Size:	00007C
 */
char* Stream::readString()
{
	int size = readInt();

	char* str = new char[size + 1];
	read(str, size);
	str[size] = '\0';
	return str;
}

/*
 * --INFO--
 * Address:	8002520C
 * Size:	000038
 */
void Stream::readString(char* dest, int size)
{
	String str(dest, size);
	readString(str);
}

/*
 * --INFO--
 * Address:	80025244
 * Size:	0000A4
 */
void Stream::readString(String& str)
{
	int size = readInt();
	if (str.mLength < size) {
		str.init(size);
	}

	read(str.mString, size);
	str.mString[size] = '\0';
}

/*
 * --INFO--
 * Address:	800252E8
 * Size:	000038
 */
void Stream::writeInt(int i)
{
	int result = i;
#ifndef __MWERKS__
	result = (((result & 0xFF000000) >> 24) | ((result & 0xFF0000) >> 8) | ((result & 0xFF00) << 8) | (result << 24));
#endif
	write(&result, sizeof(result));
}

/*
 * --INFO--
 * Address:	80025320
 * Size:	000038
 */
void Stream::writeByte(u8 c)
{
	write(&c, sizeof(u8));
}

/*
 * --INFO--
 * Address:	80025358
 * Size:	000038
 */
void Stream::writeShort(s16 _s)
{
	s16 s = _s;
#ifndef __MWERKS__
	s = (((s & 0xFF00) >> 8) | (s << 8));
#endif
	write(&s, sizeof(s16));
}

/*
 * --INFO--
 * Address:	80025390
 * Size:	000038
 */
void Stream::writeFloat(f32 f)
{
	f32 result = f;
#ifndef __MWERKS__
	int c  = *(int*)&result;
	result = ((u8)c << 24) | ((c & 0xFF00) << 8) | ((c & 0xFF0000) >> 8) | ((c & 0xFF000000) >> 24);
#endif
	write(&result, sizeof(float));
}

/*
 * --INFO--
 * Address:	800253C8
 * Size:	00003C
 */
void Stream::writeString(char* str)
{
	String s(str, 0);
	writeString(s);
}

/*
 * --INFO--
 * Address:	80025404
 * Size:	0000D4
 */
void Stream::writeString(String& s)
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
void Stream::print(char*, ...)
{
	// UNUSED FUNCTION
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

/*
 * --INFO--
 * Address:	800254D8
 * Size:	000004
 */
void Stream::read(void*, int)
{
}

/*
 * --INFO--
 * Address:	800254DC
 * Size:	000004
 */
void Stream::write(void*, int)
{
}

/*
 * --INFO--
 * Address:	800254E0
 * Size:	000008
 */
int Stream::getPending()
{
	return 0;
}

/*
 * --INFO--
 * Address:	800254E8
 * Size:	000008
 */
int Stream::getAvailable()
{
	return 0;
}

/*
 * --INFO--
 * Address:	800254F0
 * Size:	000004
 */
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

/*
 * --INFO--
 * Address:	800254F8
 * Size:	000008
 */
// bool Stream::getClosing() { return false; }
