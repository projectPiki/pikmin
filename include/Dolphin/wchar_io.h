#ifndef _WCHAR_IO_H
#define _WCHAR_IO_H

#include "types.h"

enum __file_kinds { __closed_file, __disk_file, __console_file, __unavailable_file };

enum __file_orientation { __unoriented, __char_oriented, __wide_oriented };

typedef struct {
	unsigned int open_mode : 2;
	unsigned int io_mode : 3;
	unsigned int buffer_mode : 2;
	unsigned int file_kind : 3;
	unsigned int file_orientation : 2;
	unsigned int binary_io : 1;
} __file_modes;

typedef struct _FILE FILE;

typedef u16 wchar_t;

struct _FILE {
	int handle;
	__file_modes mode;
	int state;
	u8 is_dynamically_allocated;
	u8 char_buffer;
	u8 char_buffer_overflow;
	u8 ungetc_buffer[2];
	wchar_t ungetwc_buffer[2];
	u32 position;
	u8* buffer;
	u32 buffer_size;
	u8* buffer_ptr;
	u32 buffer_len;
	u32 buffer_alignment;
	u32 saved_buffer_len;
	u32 buffer_pos;
	int position_proc;
	int read_proc;
	int write_proc;
	int close_proc;
	int idle_proc;
	struct _FILE* next_file_struct;
};

#endif
