#include "PowerPC_EABI_Support/MSL_C/MSL_Common/direct_io.h"
#include "PowerPC_EABI_Support/MSL_C/MSL_Common/ansi_files.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000378
 */
void fread(void)
{
	// UNUSED FUNCTION
}

size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream)
{
	char* write_ptr;
	size_t num_bytes, bytes_to_go, bytes_written;
	int ioresult, always_buffer;

	if (fwide(stream, 0) == 0)
		fwide(stream, -1);

	bytes_to_go = size * count;

	if (!bytes_to_go || stream->mState.error || stream->mMode.file_kind == __closed_file)
		return 0;

	if ((int)stream->mMode.file_kind == __console_file)
		__stdio_atexit();

	always_buffer = !stream->mMode.unk13 || (int)stream->mMode.file_kind == __unavailable_file || stream->mMode.buffer_mode == 2
	             || stream->mMode.buffer_mode == 1;

	if (stream->mState.io_state == __neutral) {
		if (stream->mMode.io_mode & __reading) {
			stream->mState.io_state = __writing;

			__prep_buffer(stream);
		}
	}

	if (stream->mState.io_state != __writing) {
		set_error(stream);
		return 0;
	}

	write_ptr     = (char*)buffer;
	bytes_written = 0;

	if (bytes_to_go && (stream->mBufferPtr != stream->mBuffer || always_buffer)) {
		stream->mBufferLength = stream->mBufferSize - (stream->mBufferPtr - stream->mBuffer);

		do {
			unsigned char* newline = NULL;

			num_bytes = stream->mBufferLength;

			if (num_bytes > bytes_to_go)
				num_bytes = bytes_to_go;

			if (num_bytes) {
				memcpy(stream->mBufferPtr, write_ptr, num_bytes);

				write_ptr += num_bytes;
				bytes_written += num_bytes;
				bytes_to_go -= num_bytes;

				stream->mBufferPtr += num_bytes;
				stream->mBufferLength -= num_bytes;
			}

			if (!stream->mBufferLength && (int)stream->mMode.file_kind == __unavailable_file) {
				bytes_written += bytes_to_go;
				break;
			}

			if (!stream->mBufferLength || newline != NULL || (stream->mMode.buffer_mode == 0)) {
				ioresult = __flush_buffer(stream, NULL);

				if (ioresult) {
					set_error(stream);
					bytes_to_go = 0;
					break;
				}
			}
		} while (bytes_to_go && always_buffer);
	}

	if (bytes_to_go && !always_buffer) {
		char* save_buffer = stream->mBuffer;
		size_t save_size  = stream->mBufferSize;

		stream->mBuffer     = write_ptr;
		stream->mBufferSize = bytes_to_go;
		stream->mBufferPtr  = write_ptr + bytes_to_go;

		if (__flush_buffer(stream, &num_bytes) != 0)
			set_error(stream);

		bytes_written += num_bytes;

		stream->mBuffer     = save_buffer;
		stream->mBufferSize = save_size;

		__prep_buffer(stream);

		stream->mBufferLength = 0;
	}

	if (stream->mMode.buffer_mode != 2)
		stream->mBufferLength = 0;

	return ((bytes_written + size - 1) / size);
}
