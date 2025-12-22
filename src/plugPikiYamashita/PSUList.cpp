#include "PSU/LinkList.h"

/**
 * @TODO: Documentation
 */
PSUPtrLink::PSUPtrLink(void* value)
{
	mList   = nullptr;
	mObject = value;
	mPrev   = nullptr;
	mNext   = nullptr;
}

/**
 * @TODO: Documentation
 */
PSUPtrLink::~PSUPtrLink()
{
	if (mList) {
		mList->remove(this);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
PSUPtrList::PSUPtrList(bool)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
PSUPtrList::~PSUPtrList()
{
	PSUPtrLink* link = mHead;
	for (int i = 0; i < mLinkCount; i++) {
		link->mList = nullptr;
		link        = link->mNext;
	}
}

/**
 * @TODO: Documentation
 */
void PSUPtrList::initiate()
{
	mHead      = nullptr;
	mTail      = nullptr;
	mLinkCount = 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
void PSUPtrList::setFirst(PSUPtrLink* link)
{
	link->mList = this;
	link->mPrev = nullptr;
	link->mNext = nullptr;
	mHead = mTail = link;
	mLinkCount    = 1;
}

/**
 * @TODO: Documentation
 */
bool PSUPtrList::append(PSUPtrLink* link)
{
	bool isEmpty = link->mList == nullptr;
	if (link->mList) {
		isEmpty = link->mList->remove(link);
	}

	if (isEmpty) {
		if (mLinkCount == 0) {
			setFirst(link);
		} else {
			link->mList  = this;
			link->mPrev  = mTail;
			link->mNext  = nullptr;
			mTail->mNext = link;
			mTail        = link;
			mLinkCount++;
		}
	}

	return isEmpty;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000BC
 */
bool PSUPtrList::prepend(PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001DC
 */
bool PSUPtrList::insert(PSUPtrLink*, PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
bool PSUPtrList::remove(PSUPtrLink* link)
{
	bool isUnlinked = link->mList == this;
	if (link->mList == this) {
		if (mLinkCount == 1) {
			mHead = nullptr;
			mTail = nullptr;
		} else if (link == mHead) {
			link->mNext->mPrev = nullptr;
			mHead              = link->mNext;

		} else if (link == mTail) {
			link->mPrev->mNext = nullptr;
			mTail              = link->mPrev;

		} else {
			link->mPrev->mNext = link->mNext;
			link->mNext->mPrev = link->mPrev;
		}

		link->mList = nullptr;
		mLinkCount--;
	}

	return isUnlinked;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000088
 */
PSUPtrLink* PSUPtrList::getNthLink(u32) const
{
	// UNUSED FUNCTION
}
