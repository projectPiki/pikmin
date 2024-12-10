#include "types.h"
extern "C" {
/*
 * --INFO--
 * Address:	80005600
 * Size:	000004
 */
void Probe_Start(s32 id, const char* label) { }

/*
 * --INFO--
 * Address:	80005620
 * Size:	000004
 */
void Probe_Finish(s32 id) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void Console_printf(char*, ...)
{
	// UNUSED FUNCTION
}
}
