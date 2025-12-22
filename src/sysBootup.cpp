#include "App.h"
#include "sysNew.h"
#include "system.h"

/**
 * @TODO: Documentation
 */
TERNARY_BUILD_MATCHING(void, int) main(int argc, char* argv[])
{
	gsys->Initialise();
	nodeMgr = new NodeMgr();
	gsys->run(new PlugPikiApp());

	OSPanic(__FILE__, 29, "End of demo");
}
