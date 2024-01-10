#ifndef _SHAPE_H
#define _SHAPE_H

#include "types.h"
#include "CoreNode.h"

struct AnimContext;
struct CmdStream;
template <typename A, typename B>
struct IDelegate2;
struct Joint;

/**
 * @brief TODO
 */
struct Envelope {
	Envelope();

	// unused/inlined:
	void read(RandomAccessStream&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct MtxGroup {
	MtxGroup();

	void read(RandomAccessStream&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DispList : public CoreNode {
	DispList();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct BaseShape : public CoreNode {
	BaseShape();

	virtual void read(RandomAccessStream&); // _0C
	virtual void optimize();                // _10
	virtual void update();                  // _14
	virtual void render(struct Graphics&);  // _18
	virtual void render2d(Graphics&);       // _1C
	virtual void makeRouteGroup();          // _20

	void importIni(RandomAccessStream&);
	void countMaterials(Joint*, u32);
	void recTraverseMaterials(Joint*, IDelegate2<Joint*, u32>*);
	void instanceMaterials(int);
	void makeInstance(struct ShapeDynMaterials&, int);
	void drawculled(Graphics&, struct Camera&, ShapeDynMaterials*);
	void drawshape(Graphics&, Camera&, ShapeDynMaterials*);
	void resolveTextureNames();
	void recAddMatpoly(Joint*, int);
	void initIni(bool);
	void initialise();
	void createCollisions(int);
	void calcBasePose(struct Matrix4f&);
	void loadDck(char*, RandomAccessStream&);
	void importDck(char*, CmdStream*);
	void loadDca(char*, RandomAccessStream&);
	void loadAnimation(char*, bool);
	void getAnimMatrix(int);
	void backupAnimOverrides(AnimContext**);
	void restoreAnimOverrides();
	void overrideAnim(int, AnimContext*);
	void updateAnim(Graphics&, Matrix4f&, f32*);
	void calcWeightedMatrices();
	void makeNormalIndexes(u16*);
	void calcJointWorldPos(Graphics&, int, struct Vector3f&);
	void calcJointWorldDir(Graphics&, int, Vector3f&);

	// unused/inlined:
	void exportIni(RandomAccessStream&, bool);
	void drawobjcolls(Graphics&, Camera&);
	void drawlights(Graphics&, Camera&);
	void drawroutes(Graphics&, Camera&);
	void skipChunk(RandomAccessStream&, u32);
	void importDca(char*, CmdStream*);
	void calcJointWorldScale(Graphics&, int, Vector3f&);
	void findCollTri(Vector3f&, Vector3f&, Vector3f&, char*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u8 _14[0x2AD - 0x14]; // _14, TODO: work out members
};

/**
 * @brief TODO
 */
struct Shape : public BaseShape {
	Shape();

	virtual void optimize(); // _10

	// _00      = VTBL
	// _00-_2B0 = BaseShape
	// TODO: members
};

#endif
