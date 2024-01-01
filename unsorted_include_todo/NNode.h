#ifndef _NNODE_H
#define _NNODE_H

/**
 * .obj __vt__5NNode, global
 * .4byte __RTTI__5NNode
 * .4byte 0
 * .4byte setChild__5NNodeFiP5NNode
 * .4byte addChild__5NNodeFP5NNode
 * .4byte addChild__5NNodeFiP5NNode
 * .4byte removeChild__5NNodeFP5NNode
 * .4byte removeChild__5NNodeFi
 * .4byte removeAllChildren__5NNodeFv
*/

/**
 * @brief TODO
 */
struct NNode {
	virtual void setChild(int, NNode *);  // _08
	virtual void addChild(NNode *);       // _0C
	virtual void addChild(int, NNode *);  // _10
	virtual void removeChild(NNode *);    // _14
	virtual void removeChild(int);        // _18
	virtual void removeAllChildren();     // _1C

};

#endif
