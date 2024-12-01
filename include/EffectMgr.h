#ifndef _EFFECTMGR_H
#define _EFFECTMGR_H

#include "types.h"
#include "Node.h"
#include "zen/particle.h"

struct Texture;

/**
 * @brief TODO
 */
struct SmokeEmitter : public Node {

	/**
	 * @brief TODO
	 */
	struct Smoke {
		Smoke(); // unused/inlined

		// TODO: members
	};

	SmokeEmitter(int, Texture*); // unused/inlined

	virtual void draw(Graphics&); // _14

	// unused/inlined:
	void emit(Vector3f&, Vector3f&);
	void update(f32);

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct EffectShape : public CoreNode {

	// unused/inlined:
	void initShape(char*);
	void update();
	void refresh(Graphics&, Matrix4f&, f32*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct EffShpInst : public CoreNode {

	void update();

	// unused/inlined:
	void initEffShpInst();
	void draw(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct EffectParticleRegistration {
	EffectParticleRegistration(char*, char*, char*); // unused/inlined

	virtual void create(Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
	                    zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct EffectGeometryRegistration {
	EffectGeometryRegistration(char*, char*, f32, u8); // unused/inlined

	virtual void create(Vector3f&, Vector3f&, Vector3f&); // _08

	// TODO: members
};

/**
 * @brief TODO
 */
struct EffectSimpleParticleRegistration {
	EffectSimpleParticleRegistration(char*, Colour, Colour); // unused/inlined

	// TODO: members
};

/**
 * @brief TODO
 */
struct EffectMgr : public CoreNode {

	/**
	 * @brief TODO
	 */
	enum effTypeTable {
		EFF_Unk0 = 0,
		EFF_Unk1 = 1,
		// ...
		EFF_Unk39 = 39,
		// ...
		EFF_Unk47 = 47,
		EFF_Unk48 = 48,
		// ...
		EFF_Unk50 = 50,
		EFF_Unk51 = 51,
		EFF_Unk52 = 52,
		// ...
		EFF_Unk69 = 69,
	};

	/**
	 * @brief TODO
	 */
	enum modelTypeTable {
		// TODO: members
	};

	/**
	 * @brief TODO
	 */
	enum simpleTypeTable {
		// TODO: members
	};

	EffectMgr();

	void initEffectGeometry(int);
	void update();
	void draw(Graphics&);
	void drawshapes(Graphics&);
	void exit();
	zen::particleGenerator* create(EffectMgr::effTypeTable, Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
	                               zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*);
	zen::particleGenerator* create(EffectMgr::modelTypeTable, Vector3f&, Vector3f&, Vector3f&);
	void getShapeInst();
	void killAllShapes();

	// unused/inlined:
	zen::particleGenerator* create(EffectMgr::simpleTypeTable, Vector3f&, s16, Vector3f&, Vector3f&, f32, f32,
	                               zen::CallBack1<zen::particleMdl*>*);
	void putShapeInst(EffShpInst*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	zen::particleManager mPtclMgr; // _14
};

extern EffectMgr* effectMgr;

#endif
