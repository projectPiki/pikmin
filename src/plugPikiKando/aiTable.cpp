#include "DebugLog.h"
#include "PikiAI.h"

AiTable* AiTable::uniqueInstance; // used once in pikiMgr, just to be set to nullptr lol.
int AiTable::Row::numInputs;      // stripped

#if 0 // This must have been some DLL-exclusive thing, because there's not even UNUSED functions in the symbol map.

DEFINE_ERROR(__LINE__) // Never used in the DLL

DEFINE_PRINT("aiTable")

AiTable::Tables* enemyTable;
AiTable::Tables* naviTable;
AiTable::Tables* ballTable;

#endif
