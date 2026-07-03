// Link stubs for the sysCore Windows (VC6) thin-slice matching experiment.
//
// The thin slice builds a *minimal* DLL containing only ayuStack.cpp -- enough for reccmp to diff
// its functions against the shipped sysCore.dll -- rather than the whole module.  ayuStack.cpp
// references a handful of symbols that, in a full sysCore build, are provided by other translation
// units (system.cpp / stdsystem.cpp / stream.cpp).  We satisfy them here with trivial stubs so the
// linker can resolve the references.
//
// These stubs are NOT under test and are NOT matched.  The functions actually being compared
// (AyuStack::pop, ::push, ::create, ::reset, ::checkStack, ...) never call into them, so their code
// generation is unaffected by the stub bodies.
//
// The `System::halt` / `Stream::print` / `sysCon` group is only referenced when building with
// DEVELOP defined (which turns PRINT/ERROR into real console/halt calls); they link harmlessly
// either way.
#include "system.h"

// gsys's reccmp GLOBAL annotation lives at its real definition (src/sysDolphin/system.cpp); a
// marker here would be ignored (this file is outside the reccmp source-root).
struct System* gsys = 0;

void* System::alloc(size_t) { return 0; }

void StdSystem::invalidateObjs(u32, u32) { }

struct Stream* sysCon = 0;

void System::halt(char*, int, char*) { }

void Stream::print(char*, ...) { }
