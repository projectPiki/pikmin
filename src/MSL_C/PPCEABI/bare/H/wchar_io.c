#include "Dolphin/wchar_io.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void putwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void putwchar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void fputwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void getwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void getwchar(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void fgetwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void ungetwc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void fputws(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void fgetws(void)
{
	// UNUSED FUNCTION
}

int fwide(FILE* stream, int mode)
{
	int orientation;
	int result;

	if (stream->mode.file_kind == __closed_file)
		return 0;
	orientation = stream->mode.file_orientation;
	switch (orientation) {
	case __unoriented:
		if (mode > 0)
			stream->mode.file_orientation = __wide_oriented;
		else if (mode < 0)
			stream->mode.file_orientation = __char_oriented;
		result = mode;
		break;

	case __wide_oriented:
		result = 1;
		break;

	case __char_oriented:
		result = -1;
		break;
	}
	return result;
}
