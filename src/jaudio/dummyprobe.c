#include "types.h"
extern "C" {
/*
 * --INFO--
 * Address:	80005600
 * Size:	000004
 */
void Probe_Start(void) { return; }

/*
 * --INFO--
 * Address:	80005620
 * Size:	000004
 */
void Probe_Finish(void) { return; }

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void Console_printf(char*, ...) { return; }
}
