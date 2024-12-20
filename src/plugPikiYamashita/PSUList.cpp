#include "PSU/LinkList.h"

/*
 * --INFO--
 * Address:	801B33C8
 * Size:	000018
 */
PSUPtrLink::PSUPtrLink(void* value)
{
	mList   = nullptr;
	mObject = value;
	mPrev   = nullptr;
	mNext   = nullptr;
}

/*
 * --INFO--
 * Address:	801B33E0
 * Size:	000060
 */
PSUPtrLink::~PSUPtrLink()
{
	if (mList) {
		mList->remove(this);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
PSUPtrList::PSUPtrList(bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3440
 * Size:	000068
 */
PSUPtrList::~PSUPtrList()
{
	PSUPtrLink* link = mHead;
	for (int i = 0; i < mLinkCount; i++) {
		link->mList = nullptr;
		link        = link->mNext;
	}
}

/*
 * --INFO--
 * Address:	801B34A8
 * Size:	000014
 */
void PSUPtrList::initiate()
{
	mHead      = nullptr;
	mTail      = nullptr;
	mLinkCount = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PSUPtrList::setFirst(PSUPtrLink* link)
{
	link->mList = this;
	link->mPrev = nullptr;
	link->mNext = nullptr;
	mHead = mTail = link;
	mLinkCount    = 1;
}

/*
 * --INFO--
 * Address:	801B34BC
 * Size:	0000BC
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void PSUPtrList::prepend(PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
void PSUPtrList::insert(PSUPtrLink*, PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3578
 * Size:	0000B0
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

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void PSUPtrList::getNthLink(u32) const
{
	// UNUSED FUNCTION
}
