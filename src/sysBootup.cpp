#include "system.h"
#include "App.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	80005560
 * Size:	000088
 */
void main()
{
	int filler[2];

	gsys->Initialise();
	nodeMgr = new NodeMgr();
	gsys->run(new PlugPikiApp());

	OSPanic(__FILE__, 29, "End of demo");
}
