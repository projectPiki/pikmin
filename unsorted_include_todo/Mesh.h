#ifndef _MESH_H
#define _MESH_H

/**
 * .obj __vt__4Mesh, global
 * .4byte __RTTI__4Mesh
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__4MeshFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

/**
 * @brief TODO
 */
struct Mesh : public ANode {
	virtual void read(RandomAccessStream &);  // _0C

};

#endif
