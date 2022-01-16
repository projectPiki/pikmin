#include "types.h"

/*
 * --INFO--
 * Address:	80005560
 * Size:	000088
 */

struct BaseApp {};

struct System {
    void Initialise();
    static void* alloc(size_t);
    void run(BaseApp* ptr);
};

extern System* gsys;

struct NodeMgr {
    char filler0[0x18];
    NodeMgr();
};
extern NodeMgr* nodeMgr;
struct PlugPikiApp : public BaseApp {
    char filler0[0x54];
    PlugPikiApp();
};

extern "C" void OSPanic(const char* filename, int line, const char* msg, ...);

inline void* operator new(size_t size) {
    return System::alloc(size);
}
void main() {
    int filler[2];

    gsys->Initialise();
    nodeMgr = new NodeMgr();
    gsys->run(new PlugPikiApp());

    OSPanic(__FILE__, 29, "End of demo");
}
