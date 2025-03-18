#include "nlib/System.h"
#include "nlib/Node.h"
#include "sysNew.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

System* NSystem::system;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("nlibsystem")

/*
 * --INFO--
 * Address:	8011E0F8
 * Size:	0000CC
 */
NNode::NNode(int size)
{
	if (size > 0) {
		mNodeArray = new NArray<NNode>(size);
	} else {
		mNodeArray = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8011E1C4
 * Size:	000038
 */
void NNode::setChild(int idx, NNode* child)
{
	if (!mNodeArray) {
		PRINT("?setChild:children==null:this:%08x\n", this);
		return;
	}
	mNodeArray->set(idx, child);
}

/*
 * --INFO--
 * Address:	8011E238
 * Size:	000038
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

/*
 * --INFO--
 * Address:	8011E2A8
 * Size:	000038
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

/*
 * --INFO--
 * Address:	8011E444
 * Size:	000040
 */
NNode* NNode::getChild(int idx)
{
	if (!mNodeArray) {
		PRINT("?getChild:children==null:this:%08x\n", this);
		return nullptr;
	}

	return mNodeArray->get(idx);
}

/*
 * --INFO--
 * Address:	8011E4B4
 * Size:	000038
 */
void NNode::removeChild(NNode* node)
{
	if (!mNodeArray) {
		PRINT("?removeChild:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->remove(node);
}

/*
 * --INFO--
 * Address:	8011E610
 * Size:	000038
 */
void NNode::removeChild(int idx)
{
	if (!mNodeArray) {
		PRINT("?removeChild:children==null:this:%08x\n", this);
		return;
	}

	mNodeArray->remove(idx);
}

/*
 * --INFO--
 * Address:	8011E648
 * Size:	000038
 */
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

/*
 * --INFO--
 * Address:	8011E7F0
 * Size:	00007C
 */
void NHeap::release()
{
	if (mHeapArray) {
		for (int i = 0; i < mHeapArray->getSize(); i++) {
			mHeapArray->get(i)->release();
		}
	}
}

/*
 * --INFO--
 * Address:	8011E89C
 * Size:	000008
 */
void NSystem::initSystem(System* sys)
{
	system = sys;
}

/*
 * --INFO--
 * Address:	8011E8A4
 * Size:	000094
 */
int NSystem::randomInt(int max)
{
	int val = f32(max + 1) * NSystem::random();
	if (val == max + 1) {
		return max;
	}
	return val;
}

/*
 * --INFO--
 * Address:	8011E938
 * Size:	000034
 */
u32 NSystem::getFreeHeap()
{
	return system->getHeap(SYSHEAP_App)->getFree();
}
