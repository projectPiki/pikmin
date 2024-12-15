#ifndef _GFXOBJECT_H
#define _GFXOBJECT_H

#include "ID32.h"

struct Texture;
struct TexImg;

/**
 * @brief TODO
 */
struct GfxobjInfo {
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
	GfxobjInfo* mPrev; // _04
	GfxobjInfo* mNext; // _08
	char* mString;     // _0C
	ID32 mId;          // _10
	u32 mAttached;     // _1C, check type/name later

	// vtable
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

/**
 * @brief TODO
 */
struct GfxObject {
	virtual void attach() { } // _08
	virtual void detach() { } // _0C

	// TODO: members
};

struct ShpobjInfo : public GfxobjInfo {
	ShpobjInfo()
	    : mTarget(nullptr)
	{
	}

	struct Shape* mTarget; // _20
};

#endif
