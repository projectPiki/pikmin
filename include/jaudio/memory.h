#ifndef _JAUDIO_MEMORY_H
#define _JAUDIO_MEMORY_H

#include "types.h"
#include "jaudio/audiostruct.h"

// Global functions:
void* Nas_HeapAlloc(ALHeap*, s32);
void Nas_HeapInit(ALHeap*, u8*, s32);

// likely move these to audiostruct.h eventually/as required

/**
 * @brief TODO
 */
typedef struct SZStay {
	// TODO: members
} SZStay_;

/**
 * @brief TODO
 */
typedef struct SZAuto {
	// TODO: members
} SZAuto_;

/**
 * @brief TODO
 */
typedef struct SZCustom {
	// TODO: members
} SZCustom_;

/**
 * @brief TODO
 */
typedef struct AudioHeapstrc {
	// TODO: members
} AudioHeapstrc_;

/**
 * @brief TODO
 */
typedef struct DataHeapstrc {
	// TODO: members
} DataHeapstrc_;

/**
 * @brief TODO
 */
typedef struct StayHeapstrc {
	// TODO: members
} StayHeapstrc_;

/**
 * @brief TODO
 */
typedef struct AutoHeapstrc {
	// TODO: members
} AutoHeapstrc_;

/**
 * @brief TODO
 */
typedef struct delay {
	// TODO: members
} delay_;

/**
 * @brief TODO
 */
typedef struct SwMember {
	// TODO: members
} SwMember_;

/**
 * @brief TODO
 */
typedef struct smzwavetable {
	// TODO: members
} smzwavetable_;

/**
 * @brief TODO
 */
typedef struct Wavelookuptable {
	// TODO: members
} Wavelookuptable_;

/**
 * @brief TODO
 */
typedef struct fxconfig {
	// TODO: members
} fxconfig_;

#endif
