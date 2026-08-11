#ifndef _TRISTRIPIFIER_H
#define _TRISTRIPIFIER_H

#include "types.h"

#include "Common/llist.h"

class RandomAccessStream;
class TriInfo;

/**
 * @todo Documentation
 */
class TriLink {
public:
	TriLink(TriInfo* infoA, TriInfo* infoB, int onVtx)
	    : mInfoA(infoA)
	    , mInfoB(infoB)
	    , mOnVtx(onVtx)
	{
	}

	TriInfo* mInfoA; // _00
	TriInfo* mInfoB; // _04
	int mOnVtx;      // _08, Which corner the tris are linked by.  Should be 0, 1, or 2.
};

/**
 * @todo Documentation
 */
class TriInfo {
public:
	void unlink(TriInfo* info)
	{
		for (int i = 0; i < mLinks.num; ++i) {
			if (mLinks[i]->mInfoB == info) {
				mLinks.DelIndex(i);
				break;
			}
		}
	}

	int mVertices[3];      // _00
	List<TriLink*> mLinks; // _0C
};

/**
 * @todo Documentation
 * @note Size: 0x18
 */
class TriStrip {
public:
	List<TriInfo*> mInfos; // _00
	List<TriLink*> mLinks; // _0C
};

/**
 * @todo Documentation
 */
class TriVert {
public:
	int mMeshVtxIdx; // _00
};

/**
 * @todo Documentation
 */
class TriStripifier {
public:
	/**
	 * @todo Documentation / what do these flags mean for the created display list?
	 */
	BEGIN_ENUM_TYPE(Mode)
	enum {
		Unk0 = 1 << 0,
		Unk1 = 1 << 1,
	} END_ENUM_TYPE;

	void findStrips();
	void outputTriStrips(RandomAccessStream&);

	List<TriVert*> mVerts;   // _00
	List<TriInfo*> mInfos;   // _0C
	List<TriStrip*> mStrips; // _18
	u8 _24[0x2C - 0x24];     // _24
	int mTriCount;           // _2C, how many triangles were processed by `outputTriStrips`.
	u32 _30;                 // _30, bitfield controlling `outputTriStrips`.  See `TriStripifier::Mode`.
};

#endif
