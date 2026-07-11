#include "Node.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "system.h"
#include <stdio.h>

NodeMgr* nodeMgr;

int Node::currID;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Node");

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
void CoreNode::load(immut char* dirPath, immut char* fileName, u32)
{
	char filePath[PATH_MAX];
	sprintf(filePath, "%s%s", dirPath, fileName);
	RandomAccessStream* stream = gsys->openFile(filePath);
	if (stream) {
		read(*stream);
		stream->close();
	}
}

/**
 * @todo: Documentation
 */
void Node::init(immut char* name)
{
	initCore(name);
	mFlags = 0x1 | 0x2;
	_1C    = -1;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void Node::draw(Graphics& gfx)
{
	FOREACH_NODE(Node, mChild, node)
	{
		node->draw(gfx);
	}
}

/**
 * @todo: Documentation
 */
void Node::render(Graphics& gfx)
{
	draw(gfx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000128 (Matching by size)
 */
SRTNode::SRTNode(immut char* name = "<SRTNode>")
    : Node(name)
{
	setPosition(Vector3f(0.0f, 0.0f, 0.0f));
	setScale(Vector3f(1.0f, 1.0f, 1.0f));
	setRotation(Vector3f(0.0f, 0.0f, 0.0f));
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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

static bool foundNode;
static CoreNode* nodeFound;

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000EC (Matching by size)
 * @warning Broken and thread-unsafe
 */
void NodeMgr::recFindNode(CoreNode* head, immut char* name)
{
	// Shouldn't this condition be somewhere inside the loop?  It only
	// prevents the recursion from going deeper, meaning other sibling
	// nodes can still hijack the node found before the loops conclude.
	if (!foundNode) {
		for (CoreNode* currNode = head; currNode; currNode = currNode->Next()) {
			if (!strcmp(name, currNode->mName)) {
				foundNode = true;
				nodeFound = currNode;
				return;
			}
			if (currNode->mChild) {
				recFindNode(currNode->mChild, name);
			}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A8 (Matching by size)
 * @warning Broken and thread-unsafe
 */
CoreNode* NodeMgr::findNode(immut char* name, CoreNode* head)
{
	nodeFound = nullptr;
	foundNode = false;

	if (!head) {
		head = &firstNode();
	}
	recFindNode(head, name);

	return nodeFound;
}

/**
 * @todo: Documentation
 */
NodeMgr::NodeMgr()
{
	mDelete = false;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
NodeMgr::~NodeMgr()
{
	// UNUSED FUNCTION
}
