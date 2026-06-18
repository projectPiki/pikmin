#include "PSU/LinkList.h"

/**
 * @todo: Documentation
 */
PSUPtrLink::PSUPtrLink(void* value)
{
	mList   = nullptr;
	mObject = value;
	mPrev   = nullptr;
	mNext   = nullptr;
}

/**
 * @todo: Documentation
 */
PSUPtrLink::~PSUPtrLink()
{
	if (mList) {
		mList->remove(this);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C (Matching by size)
 */
PSUPtrList::PSUPtrList(bool initialize)
{
	if (initialize) {
		initiate();
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void PSUPtrList::initiate()
{
	mHead      = nullptr;
	mTail      = nullptr;
	mLinkCount = 0;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
bool PSUPtrList::append(PSUPtrLink* link)
{
	bool isEmpty = link->mList == nullptr;
	if (!isEmpty) {
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
 * @todo: Documentation
 * @note UNUSED Size: 0000BC (Matching by size)
 */
bool PSUPtrList::prepend(PSUPtrLink* link)
{
	bool isEmpty = link->mList == nullptr;
	if (!isEmpty) {
		isEmpty = link->mList->remove(link);
	}

	if (isEmpty) {
		if (mLinkCount == 0) {
			setFirst(link);
		} else {
			link->mList  = this;
			link->mPrev  = nullptr;
			link->mNext  = mHead;
			mHead->mPrev = link;
			mHead        = link;
			mLinkCount++;
		}
	}

	return isEmpty;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001DC (Matching by size)
 */
bool PSUPtrList::insert(PSUPtrLink* list, PSUPtrLink* link)
{
	if (list == mHead) {
		return prepend(link);
	}
	if (list == nullptr) {
		return append(link);
	}
	if (list->mList != this) {
		return false;
	}

	bool isEmpty = link->mList == nullptr;
	if (!isEmpty) {
		isEmpty = link->mList->remove(link);
	}

	if (isEmpty) {
		// Totally unnecessary variable... necessary for matching.
		PSUPtrLink* listPrev = list->mPrev;

		link->mList     = this;
		link->mPrev     = listPrev;
		link->mNext     = list;
		listPrev->mNext = link;
		list->mPrev     = link;
		mLinkCount++;
	}

	return isEmpty;
}

/**
 * @todo: Documentation
 */
bool PSUPtrList::remove(PSUPtrLink* link)
{
	bool isUnlinked = link->mList == this;
	if (isUnlinked) {
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
 * @todo: Documentation
 * @note UNUSED Size: 000088 (Matching by size)
 */
PSUPtrLink* PSUPtrList::getNthLink(u32 n) const
{
	if (n >= mLinkCount) {
		return nullptr;
	}
	PSUPtrLink* link = mHead;
	for (u32 i = 0; i < n; ++i) {
		link = link->mNext;
	}
	return link;
}
