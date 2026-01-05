#ifndef _MSL_COMMON_ANSI_FILES_H
#define _MSL_COMMON_ANSI_FILES_H

#include "stdio.h"
#include "types.h"
#include <stddef.h>

typedef struct _files {
	FILE _stdin;
	FILE _stdout;
	FILE _stderr;
} files;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

extern int __close_console(__file_handle file);
extern int __write_console(__file_handle file, char* buf, size_t* count, __idle_proc idle_fn);
extern int __read_console(__file_handle file, char* buf, size_t* count, __idle_proc idle_fn);

void __close_all(void);

int fflush(FILE* __stream);
void free(void*);
int __flush_buffer(FILE* file, size_t* length);
void __prep_buffer(FILE* file);
u32 __flush_all();

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
