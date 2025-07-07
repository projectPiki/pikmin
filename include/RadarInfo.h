#ifndef _RADARINFO_H
#define _RADARINFO_H

#include "CoreNode.h"
#include "types.h"

struct Creature;
struct Vector3f;

/**
 * @brief TODO
 */
struct RadarInfo {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x18.
	 */
	struct PartsInfo : public CoreNode {
		PartsInfo()
		    : mPart(nullptr)
		{
		}

		Vector3f getPos();

		// DLL inlines:
		PartsInfo* getNext() { return (PartsInfo*)mNext; }

		// _00     = VTBL
		// _00-_14 = CoreNode
		Creature* mPart; // _14
	};

	RadarInfo();

	void attachParts(Creature*);
	void detachParts(Creature*);

	// DLL inlines:
	PartsInfo* getFirst() { return (PartsInfo*)mAlivePartsList.mChild; }

	PartsInfo mAlivePartsList; // _00
	PartsInfo mDeadPartsList;  // _18
};

extern RadarInfo* radarInfo;

#endif
