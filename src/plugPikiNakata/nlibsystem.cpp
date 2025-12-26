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
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void NListNode::addChild(NListNode*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
void NListNode::removeChild(NListNode*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
int NListNode::getChildCount()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void NListNode::addChild(int, NListNode*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NListNode::toString()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
NList::NList()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NList::addList(NList*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NList::toString()
{
	// UNUSED FUNCTION
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
