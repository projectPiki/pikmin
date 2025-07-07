#include "Dolphin/AmcExi2.h"
#include "stl/stdio.h"
#include "types.h"

static inline int __init_console(void)
{
	static BOOL initialized;
	int res = 0;

	if (!initialized) {
		res = InitializeUART(0xE100);
		if (res == 0) {
			initialized = TRUE;
		}
	}
	return res;
}

/*
 * --INFO--
 * Address:	8021A5B0
 * Size:	0000E0
 */
int __read_console(__file_handle handle, unsigned char* buffer, size_t* count, __idle_proc idle_proc)
{
	int res;
	size_t len;

	if (__init_console() != 0) {
		return 1;
	}

	len    = *count;
	res    = 0;
	*count = 0;
	while (*count <= len && res == 0) {
		res = ReadUARTN(buffer, 1);
		*count += 1;
		if (*buffer == '\r') {
			break;
		}
		buffer += 1;
	}

	return (res == 0 ? 0 : 1) & 0xFF;
}

/*
 * --INFO--
 * Address:	8021A518
 * Size:	000098
 */
WEAKFUNC BOOL __write_console(__file_handle handle, unsigned char* buffer, size_t* count, __idle_proc idle_proc)
{
	if (__init_console() != 0) {
		return 1;
	}

	if (WriteUARTN(buffer, *count) != 0) {
		*count = 0;
		return 1;
	}

	return 0;
}

/*
 * --INFO--
 * Address:	8021A510
 * Size:	000008
 */
u32 __close_console(void)
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void __init_uart_console(void)
{
	// UNUSED FUNCTION
}
