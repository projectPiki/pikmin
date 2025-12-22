#include "App.h"
#include "sysNew.h"
#include "system.h"

/**
 * @TODO: Documentation
 */
void main()
{
	int filler[2];

	gsys->Initialise();
	nodeMgr = new NodeMgr();
	gsys->run(new PlugPikiApp());

	OSPanic(__FILE__, 29, "End of demo");
}
