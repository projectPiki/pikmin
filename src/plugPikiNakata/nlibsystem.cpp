#include "DebugLog.h"
#include "Dolphin/os.h"
#include "nlib/Node.h"
#include "nlib/System.h"
#include "sysNew.h"

System* NSystem::system;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("nlibsystem")

NNode::NNode(int size)
{
	if (size > 0) {
		mNodeArray = new NArray<NNode>(size);
	} else {
		mNodeArray = nullptr;
	}
}

void NNode::setChild(int idx, NNode* child)
{
	if (!mNodeArray) {
		PRINT("?setChild:children==null:this:%08x\n", this);
		return;
	}
	mNodeArray->set(idx, child);
}

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

NNode* NNode::getChild(int idx)
{
	if (!mNodeArray) {
		PRINT("?getChild:children==null:this:%08x\n", this);
		return nullptr;
	}

	return mNodeArray->get(idx);
}

void NNode::removeChild(NNode* node)
{
	if (!mNodeArray) {
		PRINT("?removeChild:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->remove(node);
}

void NNode::removeChild(int idx)
{
	if (!mNodeArray) {
		PRINT("?removeChild:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->remove(idx);
}

void NNode::removeAllChildren()
{
	if (!mNodeArray) {
		PRINT("?removeAllChildren:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->removeAll();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
NListNode::NListNode()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NListNode::addChild(NListNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NListNode::removeChild(NListNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
int NListNode::getChildCount()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void NListNode::addChild(int, NListNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NListNode::toString()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
NList::NList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NList::addList(NList*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NList::toString()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
NHeap::NHeap(int size)
{
	if (size > 0) {
		mHeapArray = new NArray<NHeap>(size);
	} else {
		mHeapArray = nullptr;
	}
}

void NHeap::release()
{
	if (mHeapArray) {
		for (int i = 0; i < mHeapArray->getSize(); i++) {
			mHeapArray->get(i)->release();
		}
	}
}

void NSystem::initSystem(System* sys)
{
	system = sys;
}

int NSystem::randomInt(int max)
{
	int val = f32(max + 1) * NSystem::random();
	if (val == max + 1) {
		return max;
	}
	return val;
}

u32 NSystem::getFreeHeap()
{
	return system->getHeap(SYSHEAP_App)->getFree();
}
