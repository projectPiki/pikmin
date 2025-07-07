#ifndef _STDIO_H
#define _STDIO_H

#include "stl/stdarg.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef u32 __file_handle;
typedef u32 fpos_t;
typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

#define __ungetc_buffer_size 2

#define set_error(file)            \
	do {                           \
		(file)->mState.error  = 1; \
		(file)->mBufferLength = 0; \
	} while (0)

enum __file_kinds { __closed_file, __disk_file, __console_file, __unavailable_file };

enum __file_orientation { __unoriented, __char_oriented, __wide_oriented };

typedef struct __file_modes {
	u32 open_mode : 2;
	u32 io_mode : 3;
	u32 buffer_mode : 2;
	u32 file_kind : 3;

#ifdef _MSL_WIDE_CHAR
	u32 file_orientation : 2;
#endif /* _MSL_WIDE_CHAR */

	u32 binary_io : 1;
	u32 unk12 : 1;
	u32 unk13 : 1;
} file_modes;

enum __io_states { __neutral, __writing, __reading, __rereading };

typedef struct __file_states {
	u32 io_state : 3;
	u32 free_buffer : 1;

	u8 eof;
	u8 error;
} file_states;

typedef void* __ref_con;
typedef void (*__idle_proc)(void);
typedef int (*__pos_proc)(__file_handle file, fpos_t* position, int mode, __idle_proc ref_con);
typedef int (*__io_proc)(__file_handle file, char* buff, size_t* count, __idle_proc ref_con);
typedef int (*__close_proc)(__file_handle file);

struct _IO_FILE {
	__file_handle mHandle;                  // _00
	file_modes mMode;                       // _04
	file_states mState;                     // _08
	u8 mIsDynamicallyAllocated;             // _0C
	u8 mCharBuffer;                         // _0D
	u8 mCharBufferOverflow;                 // _0E
	u8 mUngetcBuffer[__ungetc_buffer_size]; // _0F
	// wchar_t mUngetcWideBuffer[__ungetc_buffer_size]; // _12
	u32 mPosition;           // _14
	char* mBuffer;           // _18
	u32 mBufferSize;         // _1C
	char* mBufferPtr;        // _20
	u32 mBufferLength;       // _24
	u32 mBufferAlignment;    // _28
	u32 mBufferLength2;      // _2C
	u32 mBufferPosition;     // _30
	__pos_proc positionFunc; // _34
	__io_proc readFunc;      // _38
	__io_proc writeFunc;     // _3C
	__close_proc closeFunc;  // _40
	__ref_con ref_con;       // _44
	                         // _IO_FILE* mNextFile;     // _48
};

typedef struct _IO_FILE FILE;

typedef struct {
	char* CharStr;
	size_t MaxCharCount;
	size_t CharsWritten;
} __OutStrCtrl;

typedef struct {
	char* NextChar;
	int NullCharDetected;
} __InStrCtrl;

typedef struct {
	wchar_t* wCharStr;
	size_t MaxCharCount;
	size_t CharsWritten;
} __wOutStrCtrl;

typedef struct {
	wchar_t* wNextChar;
	int wNullCharDetected;
} __wInStrCtrl;

int puts(const char* s);
int printf(const char*, ...);
// int fprintf(FILE*, const char* format, ...);
int vprintf(const char* format, va_list arg);
int vsnprintf(char* s, size_t n, const char* format, va_list arg);
int vsprintf(char* s, const char* format, va_list arg);
int snprintf(char* s, size_t n, const char* format, ...);
int sprintf(char* s, const char* format, ...);
int sscanf(const char* s, const char* format, ...);

extern FILE __files[3];

#define stdin  (&__files[0])
#define stdout (&__files[1])
#define stderr (&__files[2])

// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/FILE_POS.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/direct_io.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/file_io.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/printf.h"
// #include "PowerPC_EABI_Support/MSL_C/MSL_Common/scanf.h"

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
