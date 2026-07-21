#include "DebugLog.h"
#include "Dolphin/os.h"
#include "nlib/Node.h"
#include "nlib/System.h"
#include "sysNew.h"

System* NSystem::system;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("nlibsystem")

/**
 * @todo: Documentation
 */
NNode::NNode(int size)
{
	if (size > 0) {
		mNodeArray = new NArray<NNode>(size);
	} else {
		mNodeArray = nullptr;
	}
}

/**
 * @todo: Documentation
 */
void NNode::setChild(int idx, NNode* child)
{
	if (!mNodeArray) {
		PRINT("?setChild:children==null:this:%08x\n", this);
		return;
	}
	mNodeArray->set(idx, child);
}

/**
 * @todo: Documentation
 */
void NNode::addChild(NNode* child)
{
	if (!mNodeArray) {
		PRINT("?addChild:children==null:this:%08x\n", this);
		return;
	}

	if (mNodeArray->getSize() == mNodeArray->getCapacity()) {
		PRINT("?full:%08x\n", this);
	}
	mNodeArray->add(child);
}

/**
 * @todo: Documentation
 */
void NNode::addChild(int idx, NNode* child)
{
	if (!mNodeArray) {
		PRINT("?addChild:children==null:this:%08x\n", this);
		return;
	}

	if (mNodeArray->getSize() == mNodeArray->getCapacity()) {
		PRINT("?full:%08x\n", this);
	}
	mNodeArray->add(idx, child);
}

/**
 * @todo: Documentation
 */
NNode* NNode::getChild(int idx)
{
	if (!mNodeArray) {
		PRINT("?getChild:children==null:this:%08x\n", this);
		return nullptr;
	}

	return mNodeArray->get(idx);
}

/**
 * @todo: Documentation
 */
void NNode::removeChild(NNode* node)
{
	if (!mNodeArray) {
		PRINT("?removeChild:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->remove(node);
}

/**
 * @todo: Documentation
 */
void NNode::removeChild(int idx)
{
	if (!mNodeArray) {
		PRINT("?removeChild:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->remove(idx);
}

/**
 * @todo: Documentation
 */
void NNode::removeAllChildren()
{
	if (!mNodeArray) {
		PRINT("?removeAllChildren:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->removeAll();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
NListNode::NListNode()
{
	mNextSibling = mFirstChild = nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void NListNode::addChild(NListNode* child)
{
	if (!child) {
		return;
	}

	if (!mFirstChild) {
		mFirstChild = child;
	} else {
		NListNode* currentChild = mFirstChild;
		while (currentChild->mNextSibling) {
			currentChild = currentChild->mNextSibling;
		}
		currentChild->mNextSibling = child;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
void NListNode::removeChild(NListNode* child)
{
	if (!child) {
		return;
	}

	if (mFirstChild == child) {
		mFirstChild = mFirstChild->mNextSibling;
	} else {
		NListNode* currentChild = mFirstChild;
		while (currentChild->mNextSibling) {
			if (currentChild->mNextSibling == child) {
				break;
			}
			currentChild = currentChild->mNextSibling;
		}
		if (!currentChild->mNextSibling) {
			return;
		}
		currentChild->mNextSibling = currentChild->mNextSibling->mNextSibling;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
int NListNode::getChildCount()
{
	int count    = 0;
	NListNode* currentChild = mFirstChild;
	while (currentChild) {
		currentChild = currentChild->mNextSibling;
		// nice bug. this should be:
		// count++;
	}
	return count;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void NListNode::addChild(int idx, NListNode* child)
{
	if (idx == 0) {
		child->mNextSibling = mFirstChild;
		mFirstChild         = child;
		return;
	}

	NListNode* currentChild = mFirstChild;
	int childIndex          = 0;
	for (childIndex; childIndex < idx - 1; childIndex++) {
		if (!currentChild) {
			PRINT_NAKATA("!NListNode::insertList\n");
			break;
		}
		currentChild = currentChild->mNextSibling;
	}
	child->mNextSibling        = currentChild->mNextSibling;
	currentChild->mNextSibling = child;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NListNode::toString()
{
	PRINT("NListNode::toString:%08x,%08x,%08x\n", this, mFirstChild, mNextSibling);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
NList::NList()
{
	mNextList = nullptr;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NList::addList(NList* list)
{
	if (!list) {
		return;
	}

	NList* currentList = this;
	while (currentList->mNextList) {
		currentList = currentList->mNextList;
	}
	currentList->mNextList = list;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NList::toString()
{
	PRINT("NList::toString:%08x,%08x\n", this, mNextList);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000CC
 */
NHeap::NHeap(int size)
{
	if (size > 0) {
		mHeapArray = new NArray<NHeap>(size);
	} else {
		mHeapArray = nullptr;
	}
}

/**
 * @todo: Documentation
 */
void NHeap::release()
{
	if (mHeapArray) {
		for (int i = 0; i < mHeapArray->getSize(); i++) {
			mHeapArray->get(i)->release();
		}
	}
}

/**
 * @todo: Documentation
 */
void NSystem::initSystem(System* sys)
{
	system = sys;
}

/**
 * @todo: Documentation
 */
int NSystem::randomInt(int max)
{
	int val = f32(max + 1) * NSystem::random();
	if (val == max + 1) {
		return max;
	}
	return val;
}

/**
 * @todo: Documentation
 */
u32 NSystem::getFreeHeap()
{
	return system->getHeap(SYSHEAP_App)->getFree();
}

#if defined(__MWERKS__) && defined(BUILD_MATCHING)
/**
 * @note this is a fake struct to make the weak function emission order line up.
 * it'll get stripped, so it's "fine" (read: ugly and awful and I hate it)
 */
template <typename T>
struct NArrayInstantiator {
	bool fake(NArray<T>* array, T* elem);
};
template <typename T>
bool NArrayInstantiator<T>::fake(NArray<T>* array, T* elem)
{
	return array->contains(elem);
}
template class NArrayInstantiator<NNode>;
#endif
