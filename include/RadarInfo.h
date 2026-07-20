#ifndef _RADARINFO_H
#define _RADARINFO_H

#include "CoreNode.h"
#include "types.h"

class Creature;
class Vector3f;

/**
 * @brief TODO
 */
class RadarInfo {
public:
	/**
	 * @brief TODO
	 *
	 * @note Size: 0x18.
	 */
	class PartsInfo : public CoreNode {
	public:
		PartsInfo()
		    : mPart(nullptr)
		{
		}

		Vector3f getPos();

		// DLL inlines:
		PartsInfo* getNext() { return static_cast<PartsInfo*>(mNext); }

		// _00     = VTBL
		// _00-_14 = CoreNode
		Creature* mPart; // _14
	};

	RadarInfo();

	void attachParts(Creature*);
	void detachParts(Creature*);

	// DLL inlines:
	PartsInfo* getFirst() { return static_cast<PartsInfo*>(mAlivePartsList.mChild); }

	PartsInfo mAlivePartsList; // _00
	PartsInfo mDeadPartsList;  // _18
};

extern RadarInfo* radarInfo;

#endif
