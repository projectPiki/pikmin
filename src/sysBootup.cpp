#include "App.h"
#include "sysNew.h"
#include "system.h"

/**
 * @todo: Documentation
 */
TERNARY_BUILD_MATCHING(void, int) main(int argc, char* argv[])
{
	gsys->Initialise();
	nodeMgr = new NodeMgr();
	gsys->run(new PlugPikiApp());

	OSErrorLine(29, "End of demo");
}
