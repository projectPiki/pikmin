#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_files.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __convert_from_newlines(char* p, size_t* n)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void __convert_to_newlines(void)
{
	// UNUSED FUNCTION
}

void __prep_buffer(FILE* file)
{
	file->mBufferPtr      = file->mBuffer;
	file->mBufferLength   = file->mBufferSize;
	file->mBufferLength   = file->mBufferLength - (file->mPosition & file->mBufferAlignment);
	file->mBufferPosition = file->mPosition;
	return;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void __load_buffer(void)
{
	// UNUSED FUNCTION
}

int __flush_buffer(FILE* file, size_t* length)
{
	size_t bufferLen;
	int writeCode;

	bufferLen = file->mBufferPtr - file->mBuffer;
	if (bufferLen) {
		file->mBufferLength = bufferLen;

		if (!file->mMode.unk13) {
			__convert_from_newlines(file->mBuffer, &file->mBufferLength);
		}

		writeCode = file->writeFunc(file->mHandle, file->mBuffer, &file->mBufferLength, file->ref_con);
		if (length) {
			*length = file->mBufferLength;
		}
		if (writeCode) {
			return writeCode;
		}
		file->mPosition += file->mBufferLength;
	}

	__prep_buffer(file);
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void setvbuf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void setbuf(void)
{
	// UNUSED FUNCTION
}
