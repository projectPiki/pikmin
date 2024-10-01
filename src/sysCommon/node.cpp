#include "Node.h"
#include "system.h"
#include "stl/stdio.h"
#include "Dolphin/os.h"

NodeMgr* nodeMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "Node");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800405D8
 * Size:	000038
 */
void CoreNode::add(CoreNode* toAdd)
{
	CoreNode* child = mChild;

	// If there is a child
	if (child) {
		// Find the last child
		while (child->mNext) {
			child = child->mNext;
		}

		//  Add the new child to the end
		child->mNext = toAdd;
	} else {
		// If there is no child, add the new child
		mChild = toAdd;
	}

	// 	Set the parent of the new child to this node
	toAdd->mParent = this;
}

/*
 * --INFO--
 * Address:	80040610
 * Size:	000070
 */
void CoreNode::del()
{
	// If there's no parent, there's nothing to delete
	if (mParent) {
		CoreNode* child = mParent->mChild;
		CoreNode* prev  = nullptr;

		// Iterate through the children to find the one to delete
		for (child; child; prev = child, child = child->mNext) {
			if (child == this) {
				if (prev) {
					// don't break the list, link prev to next
					prev->mNext = child->mNext;

					// Detach the current child
					mNext   = nullptr;
					mParent = nullptr;
					return;
				}
				// If there's no previous child, set the parent's child to the next child
				mParent->mChild = child->mNext;

				// Detach the current child
				mNext   = nullptr;
				mParent = nullptr;
				return;
			}
		}
	}
}
/*
 * --INFO--
 * Address:	80040680
 * Size:	000020
 */
int CoreNode::getChildCount()
{
	int count = 0;
	FOREACH_NODE(CoreNode, mChild, node) { count++; }
	return count;
}

/*
 * --INFO--
 * Address:	800406A0
 * Size:	00009C
 */
void CoreNode::load(char* p1, char* p2, u32 p3)
{
	char buf[256];
	sprintf(buf, "%s%s", p1, p2);
	BufferedInputStream* stream = gsys->openFile(buf, true, true);
	if (stream) {
		read(*stream);
		stream->close();
	}
}

/*
 * --INFO--
 * Address:	8004073C
 * Size:	000028
 */
void Node::init(char* name)
{
	initCore(name);
	mFlags = 0x1 | 0x2;
	_1C    = -1;
}

/*
 * --INFO--
 * Address:	80040764
 * Size:	00006C
 */
void Node::update()
{
	FOREACH_NODE(Node, mChild, node)
	{
		if (node->mFlags & 1) {
			node->concat();
			node->update();
		}
	}
}

/*
 * --INFO--
 * Address:	800407D0
 * Size:	00005C
 */
void Node::draw(Graphics& gfx)
{
	FOREACH_NODE(Node, mChild, node) { node->draw(gfx); }
}

/*
 * --INFO--
 * Address:	8004082C
 * Size:	00002C
 */
void Node::render(Graphics& gfx) { draw(gfx); }

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
SRTNode::SRTNode(char* name = "<SRTNode>")
    : Node(name)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040858
 * Size:	00007C
 */
void SRTNode::update()
{
	// this feels like it should be SRTNode, but it's not
	// if it were, SRTNode::concat would generate after this function rather than the end
	FOREACH_NODE(Node, mChild, node)
	{
		if (node->mFlags & 1) {
			node->concat(mWorldMtx);
			node->update();
		}
	}
}

/*
 * --INFO--
 * Address:	800408D4
 * Size:	000064
 */
void NodeMgr::Del(Node* node)
{
	mDelete = true;
	if (!node) {
		return;
	}
	if (!node->mParent) {
		return;
	}

	Node* child = static_cast<Node*>(node->mParent->mChild);
	Node* prev  = nullptr;
	for (child; child; prev = child, child = static_cast<Node*>(child->mNext)) {
		if (child == node) {
			if (prev) {
				prev->mNext = child->mNext;
				return;
			}

			node->mParent->mChild = child->mNext;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void NodeMgr::recFindNode(CoreNode*, char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
CoreNode* NodeMgr::findNode(char*, CoreNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040938
 * Size:	00003C
 */
NodeMgr::NodeMgr() { mDelete = false; }

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
NodeMgr::~NodeMgr()
{
	// UNUSED FUNCTION
}
