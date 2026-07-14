#ifndef _GFXOBJECT_H
#define _GFXOBJECT_H

#include "ID32.h"

class AnimData;
class Shape;
class TexImg;
class Texture;

/**
 * @brief TODO
 */
class GfxobjInfo {
public:
	GfxobjInfo()
	{
		mPrev = mNext = nullptr;
		mString       = "";
		mId.setID('none');
		mAttached = 0;
	}

	void insertAfter(GfxobjInfo* other)
	{
		other->mNext = mNext;
		other->mPrev = this;
		mNext->mPrev = other;
		mNext        = other;
	}

	void remove()
	{
		mNext->mPrev = mPrev;
		mPrev->mNext = mNext;
	}

	// _1C = VTBL
	GfxobjInfo* mPrev;   // _00
	GfxobjInfo* mNext;   // _04
	immut char* mString; // _08
	ID32 mId;            // _0C
	u32 mAttached;       // _18, check type/name later

	// vtable
	virtual void attach() { } // _08
	virtual void detach() { } // _0C
};

/**
 * @brief TODO
 */
class GfxObject {
public:
	virtual void attach() { } // _08
	virtual void detach() { } // _0C

	// TODO: members
};

class ShpobjInfo : public GfxobjInfo {
public:
	ShpobjInfo()
	    : mTarget(nullptr)
	{
	}

	Shape* mTarget; // _20
};

#endif
