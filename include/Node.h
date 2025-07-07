#ifndef _NODE_H
#define _NODE_H

#include "CoreNode.h"
#include "Matrix4f.h"
#include "SRT.h"
#include "types.h"

struct Graphics;
struct Vector3f;

/**
 * @brief TODO
 */
struct Node : public CoreNode {
	Node(char* name = "<Node>")
	    : CoreNode(name)
	{
		init(name);
	}

	virtual void update();                                 // _10
	virtual void draw(Graphics&);                          // _14
	virtual void render(Graphics&);                        // _18
	virtual void concat() { }                              // _1C (weak)
	virtual void concat(struct VQS&) { concat(); }         // _20 (weak)
	virtual void concat(SRT&) { concat(); }                // _24 (weak)
	virtual void concat(Matrix4f&) { concat(); }           // _28 (weak)
	virtual Matrix4f* getModelMatrix() { return nullptr; } // _2C (weak)

	void init(char*);

	// Inlined functions
	bool getFlag(int);
	int getFlags();
	int getType();
	void clearFlag(int);
	void setFlag(int);
	void setFlag(int, bool);
	void setFlags(int);
	void setType(int);
	void togFlag(int);

	// _00     = VTBL
	// _00-_14 = CoreNode
	s32 mType;  // _14
	s32 mFlags; // _18
	s32 _1C;    // _1C
};

/**
 * @brief TODO
 */
struct FaceNode : public CoreNode {
	FaceNode()
	    : CoreNode("face")
	{
	}

#ifndef __MWERKS__
	FaceNode(int faceCount)
	{
		mFaceCount        = faceCount;
		mMtxIdx           = 0;
		mVtxIdx           = 0;
		mColIdx           = 0;
		mNrmIdx           = 0;
		mTexCoords[0]     = 0;
		mMtxGroupIndex    = 0;
		mMtxGroupCount    = 0;
		mNumMatrices      = 0;
		_38               = 0;
		mDisplayListFlags = 0;
		mCurrentFaceIndex = 0;
		mHasMatrixData    = 0;
	}
#endif

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFaceCount;     // _14
	int* mMtxIdx;       // _18
	int* mVtxIdx;       // _1C
	int* mColIdx;       // _20
	int* mNrmIdx;       // _24
	int* mTexCoords[8]; // _28

#ifndef __MWERKS__
	int mMtxGroupIndex;    // _2C
	int mMtxGroupCount;    // _30
	int mNumMatrices;      // _34
	int _38;               // _38
	int mDisplayListFlags; // _3C
	int mCurrentFaceIndex; // _40
	int mHasMatrixData;    // _44
#endif
};

/**
 * @brief TODO
 */
struct SRTNode : public Node {
	SRTNode(char* name); // unused/inlined

	virtual void update();                                    // _10
	virtual void concat(Matrix4f&) { }                        // _28 (weak)
	virtual void concat() { }                                 // _1C (weak)
	virtual Matrix4f* getModelMatrix() { return &mWorldMtx; } // _2C (weak)

	Vector3f& getPosition() { return mSRT.mTranslation; }
	Vector3f& getRotation() { return mSRT.mRotation; }
	Vector3f& getScale() { return mSRT.mScale; }
	Vector3f& getWorldPosition() { return (Vector3f&)mWorldMtx.mMtx[3]; }
	void setPosition(Vector3f& pos) { mSRT.mTranslation = pos; }
	void setRotation(Vector3f& rot) { mSRT.mRotation = rot; }
	void setScale(Vector3f& scale) { mSRT.mScale = scale; }

	// _00 - VTBL
	// _00 - _14 - CoreNode
	// _14 - _20 - Node
	Matrix4f mWorldMtx; // _20
	SRT mSRT;           // _60
};

/**
 * @brief TODO
 */
struct NodeMgr {
	NodeMgr();
	~NodeMgr();

	inline CoreNode& firstNode() { return mRootNode; }

	CoreNode* findNode(char*, CoreNode*);
	void recFindNode(CoreNode*, char*);
	void Del(Node*);

	bool mDelete;       // _00
	CoreNode mRootNode; // _04
};

extern NodeMgr* nodeMgr;

#endif
