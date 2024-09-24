#ifndef _ZEN_PARTICLE_H
#define _ZEN_PARTICLE_H

#include "types.h"
#include "zen/zenList.h"
#include "Dolphin/mtx.h"

struct Colour;
struct Graphics;
struct Texture;
struct Vector3f;

namespace zen {
template <typename A>
struct CallBack1;

template <typename A, typename B>
struct CallBack2;

struct particleMdl;
struct particleMdlManager;

/*
 * @brief TODO
 */
enum ParticleGeneratorFlags {
	PTCLGEN_Unk1        = 0x1,
	PTCLGEN_GenFinished = 0x2,
	PTCLGEN_Unk3        = 0x4,
	PTCLGEN_GenStopped  = 0x8,
};

/*
 * @brief TODO
 */
struct particleMdlBase : public zenList {
	virtual void remove(); // _0C

	// unused/inlined:
	~particleMdlBase();

	// _00     = VTBL
	// _00-_0C = zenList
	// TODO: members
};

/*
 * @brief TODO
 */
struct particleMdl : public particleMdlBase {
	particleMdl();

	virtual void remove(); // _0C

	~particleMdl();

	// _00     = VTBL
	// _00-_0C = particleMdlBase?
	// TODO: members
};

/*
 * @brief TODO
 */
struct particleChildMdl : public particleMdlBase {
	particleChildMdl();

	virtual void remove(); // _0C

	~particleChildMdl();

	// _00     = VTBL
	// _00-_0C = particleMdlBase?
	// TODO: members
};

/*
 * @brief TODO
 */
struct particleMdlManager {
	void init(u32, u32);

	// unused/inlined:
	~particleMdlManager();

	// TODO: members
};

/*
 * @brief TODO
 */
struct particleGenerator : public zenList {
	particleGenerator();

	virtual void remove(); // _0C

	~particleGenerator();

	void getGPos();
	void init(u8*, Texture*, Texture*, Vector3f&, particleMdlManager*, CallBack1<particleGenerator*>*,
	          CallBack2<particleGenerator*, particleMdl*>*);
	void update(f32);
	void draw(Graphics&);
	void pmSetDDF(u8*);
	void SetPtclsLife();
	void PtclsGen(particleMdl*);
	void pmCalcAccel(particleMdl*);
	void UpdatePtclsStatus(f32);
	void ClearPtclsStatus(Texture*, Texture*);
	void drawPtclBillboard(Graphics&);
	void drawPtclOriented(Graphics&);
	void RotAxisX(Mtx&, f32&, f32&);
	void RotAxisY(Mtx&, f32&, f32&);
	void RotAxisZ(Mtx&, f32&, f32&);
	void RotAxisXY(Mtx&, f32&, f32&);
	void RotAxisXZ(Mtx&, f32&, f32&);
	void RotAxisYZ(Mtx&, f32&, f32&);
	void RotAxisXYZ(Mtx&, f32&, f32&);
	void updatePtclChildren(f32);
	void drawPtclChildren(Graphics&);
	void forceFinish();
	void finish(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	void forceFinish(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	void pmGetParticle();
	void pmGetParticleChild();

	// unused/inlined:
	void pmIntpManual(f32*, f32*);
	void pmIntpLinear(f32*, f32*);

	inline void setFlag(u32 flag) { mGeneratorFlags |= flag; }
	inline void resetFlag(u32 flag) { mGeneratorFlags &= ~flag; }
	inline bool isFlag(u32 flag) { return mGeneratorFlags & flag; }

	// _00     = VTBL
	// _00-_0C = zenList
	// TODO: members
	u8 _0C[0x18 - 0xC];    // _0C, unknown
	Vector3f* mEmitPosPtr; // _18
	u8 _1C[0x80 - 0x1C];   // _1C, unknown
	u32 mGeneratorFlags;   // _80
};

/*
 * @brief TODO
 */
struct particleManager {
	void init(u32, u32, u32, f32);
	void createGenerator(u8*, Texture*, Texture*, Vector3f&, CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	void update();
	void draw(Graphics&);
	void cullingDraw(Graphics&);
	void killAllGenarator(bool);
	void killGenerator(particleGenerator*, bool);
	void killGenerator(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*, bool);
	void pmCheckList(particleGenerator*);
	void pmGetPtclGen();

	// unused/inlined:
	~particleManager();
	void calcActiveList();
	void debugUpdate();
	void debugDraw(Graphics&);

	// TODO: members
};

/*
 * @brief TODO
 */
struct PCRData : public zenList {

	// _00     = VTBL
	// _00-_0C = zenList
	// TODO: members
};

/*
 * @brief TODO
 */
struct particleLoader {
	void load(char*, bool);
	void pmFind(char*);

	// unused/inlined:
	~particleLoader();

	// TODO: members
};

/*
 * @brief TODO
 */
struct simplePtclManager {
	void update(f32);
	void draw(Graphics&);
	void forceFinish();

	// unused/inlined:
	void create(Texture*, s16, const Vector3f&, const Vector3f&, const Vector3f&, f32, f32, const Colour&, const Colour&,
	            zen::CallBack1<zen::particleMdl*>*);
	~simplePtclManager();

	// TODO: members
};

/*
 * @brief TODO
 */
struct PtclGenPack {
	void setPtclGenPtr(u32, particleGenerator*);
	void setEmitPosPtr(Vector3f*);
	void startGen();
	void stopGen();
	void finish();
	void forceFinish();
	bool checkStopGen();

	// unused/inlined:
	particleGenerator* getPtclGenPtr(u32 idx);
	void setEmitPos(Vector3f&);
	void setEmitDir(Vector3f&);
	void setCallBack(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	void start();
	void stop();
	void checkStop();
	void checkEmit();
	void checkActive();

	inline particleGenerator** getGenList() { return mGeneratorList; }

	u32 mLimit;                         // _00
	particleGenerator** mGeneratorList; // _04
};

} // namespace zen

#endif
