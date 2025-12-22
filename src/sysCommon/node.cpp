#include "Node.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "stl/stdio.h"
#include "system.h"

NodeMgr* nodeMgr;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Node");

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
int CoreNode::getChildCount()
{
	int count = 0;
	FOREACH_NODE(CoreNode, mChild, node)
	{
		count++;
	}
	return count;
}

/**
 * @TODO: Documentation
 */
void CoreNode::load(immut char* dirPath, immut char* fileName, u32)
{
	char filePath[PATH_MAX];
	sprintf(filePath, "%s%s", dirPath, fileName);
	RandomAccessStream* stream = gsys->openFile(filePath, true, true);
	if (stream) {
		read(*stream);
		stream->close();
	}
}

/**
 * @TODO: Documentation
 */
void Node::init(immut char* name)
{
	initCore(name);
	mFlags = 0x1 | 0x2;
	_1C    = -1;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Node::draw(Graphics& gfx)
{
	FOREACH_NODE(Node, mChild, node)
	{
		node->draw(gfx);
	}
}

/**
 * @TODO: Documentation
 */
void Node::render(Graphics& gfx)
{
	draw(gfx);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000128
 */
SRTNode::SRTNode(immut char* name = "<SRTNode>")
    : Node(name)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000EC
 */
void NodeMgr::recFindNode(CoreNode*, immut char*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A8
 */
CoreNode* NodeMgr::findNode(immut char*, CoreNode*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
NodeMgr::NodeMgr()
{
	mDelete = false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
NodeMgr::~NodeMgr()
{
	// UNUSED FUNCTION
}
