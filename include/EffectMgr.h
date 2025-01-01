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
		EFF_NULL = -1,
		EFF_Unk0 = 0,
		EFF_Unk1 = 1,
		// ...
		EFF_Unk12 = 12,
		EFF_Unk13 = 13,
		EFF_Unk14 = 14,
		EFF_Unk15 = 15,
		EFF_Unk16 = 16,
		EFF_Unk17 = 17,
		EFF_Unk18 = 18,
		EFF_Unk19 = 19,
		// ...
		EFF_Unk39 = 39,
		// ...
		EFF_Unk47 = 47,
		EFF_Unk48 = 48,
		EFF_Unk49 = 49,
		// ...
		EFF_Unk50 = 50,
		EFF_Unk51 = 51,
		EFF_Unk52 = 52,
		// ...
		EFF_Unk55 = 55,
		EFF_Unk56 = 56,
		EFF_Unk57 = 57,
		// ...
		EFF_Unk61 = 61,
		EFF_Unk62 = 62,
		EFF_Unk63 = 63,
		// ...
		EFF_Unk69 = 69,
		// ...
		EFF_Unk87 = 87,
		EFF_Unk88 = 88,
		EFF_Unk89 = 89,
		// ...
		EFF_Unk104 = 104,
		// ...
		EFF_Unk116 = 116,
		EFF_Unk117 = 117,
		EFF_Unk118 = 118,
		// ...
		EFF_Unk120 = 120,
		EFF_Unk121 = 121,
		EFF_Unk122 = 122,
		EFF_Unk123 = 123,
		EFF_Unk124 = 124,
		// ...
		EFF_Unk193 = 193,
		EFF_Unk194 = 194,
		EFF_Unk195 = 195,
		EFF_Unk196 = 196,
		EFF_Unk197 = 197,
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

	inline void killGenerator(zen::CallBack1<zen::particleGenerator*>* cb1, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cb2,
	                          bool p3)
	{
		mPtclMgr.killGenerator(cb1, cb2, p3);
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	zen::particleManager mPtclMgr; // _14
};

extern EffectMgr* effectMgr;

#endif
