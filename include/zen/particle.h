#ifndef _ZEN_PARTICLE_H
#define _ZEN_PARTICLE_H

#include "types.h"
#include "zen/zenList.h"
#include "zen/CallBack.h"
#include "zen/bBoardColourAnim.h"
#include "Dolphin/mtx.h"
#include "Colour.h"
#include "sysNew.h"

struct Colour;
struct Graphics;
struct Texture;
struct Vector3f;

namespace zen {

struct particleMdl;
struct particleMdlManager;

/**
 * @brief TODO
 */
enum ParticleGeneratorControlFlags {
	PTCLCTRL_Stop       = 0x1,
	PTCLCTRL_Finished   = 0x2,
	PTCLCTRL_Active     = 0x4,
	PTCLCTRL_GenStopped = 0x8,
	PTCLCTRL_Visible    = 0x10,
};

/**
 * @brief TODO
 */
enum ParticleGeneratorFlags {
	PTCLFLAG_Unk0 = 1 << 0, // 0x1
	// ...
	PTCLFLAG_Unk16 = 1 << 16, // 0x10000
	PTCLFLAG_Unk17 = 1 << 17, // 0x20000
	PTCLFLAG_Unk18 = 1 << 18, // 0x40000
	PTCLFLAG_Unk19 = 1 << 19, // 0x80000
	PTCLFLAG_Unk20 = 1 << 20, // 0x100000
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct particleMdlBase : public zenList {
	inline particleMdlBase() { InitParam(); }

	virtual void remove() // _0C
	{
		zenList::remove();
		InitParam();
	}

	~particleMdlBase() { }

	Vector3f getPos() { return _0C + _18; }

	void InitParam()
	{
		_0C.set(0.0f, 0.0f, 0.0f);
		_18.set(0.0f, 0.0f, 0.0f);
		_24 = 1.0f;
		_28.set(0, 0, 0, 0);
	}

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f _0C; // _0C
	Vector3f _18; // _18
	f32 _24;      // _24
	Colour _28;   // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x80.
 */
struct particleMdl : public particleMdlBase {
	particleMdl()
	{
		_6C._00       = 0.0f;
		_6C._04       = 0;
		_6C._06       = 1;
		_6C.mAnimData = nullptr;
		InitParam();
	}

	virtual void remove() // _0C
	{
		particleMdlBase::remove();
		InitParam();
	}

	~particleMdl() { }

	void InitParam()
	{
		_2E = 0;
		_2C = 0;
		_30 = 0.0f;
		_34.set(0.0f, 0.0f, 0.0f);
		_54 = 0.0f;
		_50 = 0.0f;
		_50 = 0.0f;
		_5C.set(0.0f, 0.0f, 0.0f);
		_58   = 0;
		_5A   = 0;
		_5C.z = 1.0f;
		_4C   = 0;
		_68   = 0;
		_69   = 0;
		_6A   = 0;
		_6B   = 0;
		_6C.init(nullptr, 1);
		_78 = 0;
	}

	// _00     = VTBL
	// _00-_2C = particleMdlBase
	s16 _2C;              // _2C
	s16 _2E;              // _2E
	f32 _30;              // _30
	Vector3f _34;         // _34
	Vector3f _40;         // _40
	u8 _4C;               // _4C
	f32 _50;              // _50
	f32 _54;              // _54
	s16 _58;              // _58
	s16 _5A;              // _5A
	Vector3f _5C;         // _5C
	u8 _68;               // _68
	u8 _69;               // _69
	u8 _6A;               // _6A
	u8 _6B;               // _6B
	bBoardColourAnim _6C; // _6C
	u32 _78;              // _78, unknown
	u8 _7C[0x4];          // _7C, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct particleChildMdl : public particleMdlBase {
	particleChildMdl()
	{
		_2C = 0.0f;
		_31 = 0;
		_30 = 0;
		_32 = 0;
	}

	virtual void remove() // _0C
	{
		particleMdlBase::remove();
	}

	~particleChildMdl() { }

	// _00     = VTBL
	// _00-_2C = particleMdlBase
	f32 _2C; // _2C
	u8 _30;  // _30
	u8 _31;  // _31
	u8 _32;  // _32
};

/**
 * @brief TODO
 */
struct particleMdlManager {
	// particleMdlManager();

	void init(u32, u32);

	// unused/inlined:
	~particleMdlManager();

	int getSleepPtclNum() { return mSleepPtclList.getListNum(); }
	int getSleepPtclChildNum() { return mSleepPtclChildList.getListNum(); }

	void putPtcl(zenList* ptcl) { mSleepPtclList.put(ptcl); }
	void putPtclChild(zenList* child) { mSleepPtclChildList.put(child); }

	// TODO: make these
	zenList* getPtcl();
	zenList* getPtclChild();

	zenListManager mSleepPtclList;      // _00
	zenListManager mSleepPtclChildList; // _10
	particleMdl* mPtclList;             // _20
	particleChildMdl* mChildPtclList;   // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x200.
 */
struct particleGenerator : public zenList {
	particleGenerator()
	{
		ClearPtclsStatus(nullptr, nullptr);
		mCallBack1     = nullptr;
		mCallBack2     = nullptr;
		mParticleFlags = 0;
		mControlFlags  = 0;
	}

	virtual void remove(); // _0C

	~particleGenerator() { }

	void init(u8*, Texture*, Texture*, Vector3f&, particleMdlManager*, CallBack1<particleGenerator*>*,
	          CallBack2<particleGenerator*, particleMdl*>*);
	bool update(f32);
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
	bool finish(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	bool forceFinish(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	particleMdl* pmGetParticle();
	particleChildMdl* pmGetParticleChild();

	// unused/inlined:
	f32 pmIntpManual(f32*, f32*);
	f32 pmIntpLinear(f32*, f32*);

	// these are correct from the DLL

	void pmSwitchOn(u32 flag) { mParticleFlags |= flag; }
	void pmSwitchOff(u32 flag) { mParticleFlags &= ~flag; }
	void pmSwitch(bool turnOn, u32 flag)
	{
		if (turnOn) {
			pmSwitchOn(flag);
		} else {
			pmSwitchOff(flag);
		}
	}

	zenListManager& getPtclMdlListManager() { return mPtclMdlListManager; }

	void setEmitPos(Vector3f& pos) { mEmitPos = pos; }
	void setEmitPosPtr(Vector3f* posPtr) { mEmitPosPtr = posPtr; }
	void setEmitDir(Vector3f& dir) { mEmitDir = dir; }
	void setEmitVelocity(Vector3f& vel) { mEmitVelocity = vel; }
	void setOrientedNormalVector(Vector3f& vec) { mOrientedNormalVector = vec; }
	void setCallBack(CallBack1<particleGenerator*>* cb1, CallBack2<particleGenerator*, particleMdl*>* cb2)
	{
		mCallBack1 = cb1;
		if (cb1) {
			mCallBack1->invoke(this);
		}
		mCallBack2 = cb2;
	}

	Vector3f& getGPos()
	{
		if (mEmitPosPtr) {
			return *mEmitPosPtr;
		}
		return mEmitPos;
	}

	// these are the same for some reason
	Vector3f& getEmitPos()
	{
		if (mEmitPosPtr) {
			return *mEmitPosPtr;
		}
		return mEmitPos;
	}

	f32 getScaleSize() { return mScaleSize; }
	void setScaleSize(f32 scale) { mScaleSize = scale; }

	void start() { mControlFlags &= ~PTCLCTRL_Stop; }
	void stop() { mControlFlags |= PTCLCTRL_Stop; }
	void startGen() { mControlFlags &= ~PTCLCTRL_GenStopped; }
	void stopGen() { mControlFlags |= PTCLCTRL_GenStopped; }
	void finish() { mControlFlags |= PTCLCTRL_Finished; }
	void visible() { mControlFlags |= PTCLCTRL_Visible; }
	void invisible() { mControlFlags &= ~PTCLCTRL_Visible; }

	bool checkStop() { return mControlFlags & PTCLCTRL_Stop; }
	bool checkEmit() { return !(mControlFlags & PTCLCTRL_Finished); }
	bool checkActive() { return mControlFlags & PTCLCTRL_Active; }
	bool checkStopGen() { return mControlFlags & PTCLCTRL_GenStopped; }

	u32 getControlFlag() { return mControlFlags; }

	void killParticle(particleMdl* ptcl) { pmPutParticle(ptcl); }
	void pmPutParticle(zenList* ptcl) { mMdlMgr->putPtcl(ptcl); }
	void pmPutParticleChild(zenList* child) { mMdlMgr->putPtclChild(child); }

	// might be setGravityField
	void setAirField(Vector3f& field, bool set)
	{
		_138.set(field);
		pmSwitch(set, PTCLFLAG_Unk17);
	}

	void setNewtonField(Vector3f pos, f32 a, bool set)
	{
		_170.set(pos - getGPos());
		_17C = a;
		pmSwitch(set, PTCLFLAG_Unk20);
	}

	void setOrientedConstZAxis(bool set) { _68.m2 = set; }

	void setVortexField(Vector3f pos, f32 a, f32 b, f32 c, f32 d, bool set)
	{
		_144.set(pos);
		_150 = a; // -0.12f;
		_154 = b; // -0.09f;
		_158 = c; // 0.3f;
		_15C = d; // 400.0f;
		pmSwitch(set, PTCLFLAG_Unk18);
	}

	// might be setAirField
	void setGravityField(Vector3f& pos, bool set)
	{
		_12C.set(pos);
		pmSwitch(set, PTCLFLAG_Unk16);
	}

	// might be setFreqFrm
	void setInitVel(f32 vel) { _B8 = vel; }

	// NB: might be getMaxFrame(), unsure
	s16 getCurrentFrame() { return _90; }

	/*
	    These are still to be made/assigned from the DLL:

	    f32 getFreqFrm();
	    void setFreqFrm(f32);

	    f32 getInitVel();
	    void setInitVel(f32);

	    f32 getNewtonFieldFrc();

	    void pmGetArbitUnitVec(Vector3f&);

	    s16 getCurrentFrame();
	    s16 getMaxFrame();
	*/

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f mEmitPos;                  // _0C
	Vector3f* mEmitPosPtr;              // _18
	Vector3f mEmitVelocity;             // _1C
	zenListManager mPtclMdlListManager; // _28
	zenListManager _38;                 // _38
	bBoardColourAnimData mAnimData;     // _48
	u8 _58[0x68 - 0x58];                // _58, unknown
	struct {
		u32 m0 : 1;
		u32 m1 : 1;
		u32 m2 : 1;
	} _68;                                                   // _68
	u8 _6C[0x80 - 0x6C];                                     // _6C, unknown
	u32 mControlFlags;                                       // _80, see ParticleGeneratorControlFlags enum
	u32 mParticleFlags;                                      // _84, see ParticleGeneratorFlags enum
	u8 _88[0x90 - 0x88];                                     // _88, unknown
	s16 _90;                                                 // _90, either current frame or max frame
	Vector3f _94;                                            // _94
	Vector3f mEmitDir;                                       // _A0
	Vector3f _AC;                                            // _AC
	f32 _B8;                                                 // _B8
	u8 _BC[0xF0 - 0xBC];                                     // _BC, unknown
	f32 mScaleSize;                                          // _F0
	u8 _F4[0x120 - 0xF4];                                    // _F4, unknown
	Colour _120;                                             // _120
	u8 _124[0x8];                                            // _124, unknown
	Vector3f _12C;                                           // _12C
	Vector3f _138;                                           // _138
	Vector3f _144;                                           // _144
	f32 _150;                                                // _150
	f32 _154;                                                // _154
	f32 _158;                                                // _158
	f32 _15C;                                                // _15C
	Vector3f _160;                                           // _160
	u8 _16C[0x4];                                            // _16C, unknown
	Vector3f _170;                                           // _170
	f32 _17C;                                                // _17C
	Vector3f _180;                                           // _180
	u8 _18C[0x8];                                            // _18C, unknown
	Vector3f _194;                                           // _194
	u8 _1A0[0x1D0 - 0x1A0];                                  // _1A0, unknown
	particleMdlManager* mMdlMgr;                             // _1D0
	CallBack1<particleGenerator*>* mCallBack1;               // _1D4
	CallBack2<particleGenerator*, particleMdl*>* mCallBack2; // _1D8
	Vector3f mOrientedNormalVector;                          // _1DC
	u8 _1E8[0x200 - 0x1E8];                                  // _1E8
};

/**
 * @brief TODO
 */
struct PCRData : public zenList {

	// _00     = VTBL
	// _00-_0C = zenList
	// TODO: members
};

/**
 * @brief TODO
 */
struct particleLoader {
	u8* load(char*, bool);
	u8* pmFind(char*);

	// unused/inlined:
	~particleLoader();

	// TODO: members
};

/**
 * @brief TODO
 */
struct simplePtclManager {
	// simplePtclManager();

	void update(f32);
	void draw(Graphics&);
	void forceFinish();

	// unused/inlined:
	void create(Texture*, s16, const Vector3f&, const Vector3f&, const Vector3f&, f32, f32, const Colour&, const Colour&,
	            zen::CallBack1<zen::particleMdl*>*);
	~simplePtclManager();

	void init(particleMdlManager* mdlMgr) { mMdlMgr = mdlMgr; }

	// remaining DLL functions:
	// particleMdl* pmGetParticle();
	// void pmPutParticle(zenList*);

	zenListManager _00;          // _00
	particleMdlManager* mMdlMgr; // _10
};

/**
 * @brief TODO
 */
struct particleManager {
	// particleManager();

	void init(u32 numPtclGens, u32 numParticles, u32 numChildParticles, f32 p4);
	particleGenerator* createGenerator(u8*, Texture*, Texture*, Vector3f&, CallBack1<particleGenerator*>*,
	                                   CallBack2<particleGenerator*, particleMdl*>*);
	void update();
	void draw(Graphics& gfx);
	void cullingDraw(Graphics& gfx);
	void killAllGenarator(bool doForceFinish); // dev typo
	void killGenerator(particleGenerator* gen, bool doForceFinish);
	void killGenerator(CallBack1<particleGenerator*>* cb1, CallBack2<particleGenerator*, particleMdl*>* cb2, bool doForceFinish);
	bool pmCheckList(particleGenerator* testGen);
	particleGenerator* pmGetPtclGen();

	// unused/inlined:
	~particleManager();
	void calcActiveList();
	void debugUpdate();
	void debugDraw(Graphics&);

	void pmPutPtclGen(zenList* gen) { _20.put(gen); }

	// remaining DLL functions:
	// particleMdl* createParticle(Texture*, s16, Vector3f&, Vector3f&, Vector3f&, f32, f32, Colour, Colour, CallBack1<particleMdl*>*);

	static const f32 DEFAULT_FRAME_RATE;
	static const u16 MAX_PTCLGENS_NUM;
	static const u16 MAX_PTCLS_NUM;
	static const u16 MAX_PTCL_CHILD_NUM;

	zenListManager _00;               // _00
	zenListManager _10;               // _10
	zenListManager _20;               // _20
	particleGenerator* mPtclGenList;  // _30, array of up to 0x1000 particleGenerators
	particleMdlManager mMdlMgr;       // _34
	u8 _5C[4];                        // _5C, unknown, might be in particleMdlManager
	simplePtclManager mSimplePtclMgr; // _60
	u32 mMaxPtclGens;                 // _74
	u32 mMaxParticles;                // _78
	u32 mMaxChildParticles;           // _7C
	u32 mActivePtclGenCount;          // _80, current active ptcl gen count
	u32 mActiveParticleCount;         // _84, current active particle count
	u32 mActiveChildParticleCount;    // _88, current active child particle count
	u32 mMaxUsedPtclGenCount;         // _8C, max amount of ptcl gens used so far
	u32 mMaxUsedParticleCount;        // _90, max amount of particles used so far
	u32 mMaxUsedChildParticleCount;   // _94, max amount of child particles used so far
	f32 _98;                          // _98
};

/**
 * @brief TODO
 */
struct PtclGenPack {
	inline PtclGenPack(int limit)
	{
		mLimit         = limit;
		mGeneratorList = new particleGenerator*[mLimit];
		for (int i = 0; i < mLimit; i++) {
			mGeneratorList[i] = nullptr;
		}
	}

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
	bool checkStop();
	bool checkEmit();
	bool checkActive();

	inline particleGenerator** getGenList() { return mGeneratorList; }

	u32 mLimit;                         // _00
	particleGenerator** mGeneratorList; // _04
};

} // namespace zen

#endif
