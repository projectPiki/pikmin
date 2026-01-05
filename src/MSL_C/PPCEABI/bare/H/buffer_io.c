#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_files.h"
#include <stddef.h>

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void __convert_from_newlines(char* p, size_t* n)
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
void __convert_to_newlines(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void __prep_buffer(FILE* file)
{
	file->mBufferPtr      = file->mBuffer;
	file->mBufferLength   = file->mBufferSize;
	file->mBufferLength   = file->mBufferLength - (file->mPosition & file->mBufferAlignment);
	file->mBufferPosition = file->mPosition;
	return;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D8
 */
void __load_buffer(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000128
 */
void setvbuf(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
void setbuf(void)
{
	// UNUSED FUNCTION
}
