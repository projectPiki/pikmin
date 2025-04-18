#ifndef _ZEN_PARTICLE_H
#define _ZEN_PARTICLE_H

#include "types.h"
#include "zen/zenList.h"
#include "zen/CallBack.h"
#include "zen/Math.h"
#include "zen/bBoardColourAnim.h"
#include "Dolphin/mtx.h"
#include "Colour.h"
#include "sysNew.h"
#include "Dolphin/gx.h"

struct Colour;
struct Graphics;
struct Texture;
struct Vector3f;

/**
 * @brief TODO
 *
 * @note Size 0xC. This is used by effectMgr and effectMgr2D to load in particle file addresses.
 */
struct PtclLoadInfo {
	char* mPCRPath;  // _00
	char* mTex1Path; // _04
	char* mTex2Path; // _08
};

/**
 * @brief TODO
 *
 * @note Size 0x10. This is used by effectMgr to load in geometry for EffShpInst things
 */
struct GeometryLoadInfo {
	char* mMODPath;  // _00
	char* mAnimPath; // _04
	f32 mScale;      // _08
	u8 mLoopMax;     // _0C
};

/**
 * @brief TODO
 *
 * @note Size 0xC. This is used by effectMgr to load in simple particle info.
 */
struct SimplePtclLoadInfo {
	char* mBTIPath; // _00
	GXColor _04;    // _04
	GXColor _08;    // _08
};

namespace zen {

struct particleMdl;
struct particleMdlManager;
struct particleGenerator;

typedef void (particleGenerator::*PtclDrawCallBack)(Graphics&);
typedef void (particleGenerator::*RotAxisCallBack)(Mtx&, f32&, f32&);

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
	PTCLFLAG_Unk0     = 1 << 0,  // 0x1
	PTCLFLAG_Unk1     = 1 << 1,  // 0x2
	PTCLFLAG_Unk2     = 1 << 2,  // 0x4
	PTCLFLAG_Unk3     = 1 << 3,  // 0x8
	PTCLFLAG_ClampVel = 1 << 4,  // 0x10
	PTCLFLAG_Unk5     = 1 << 5,  // 0x20
	PTCLFLAG_Unk6     = 1 << 6,  // 0x40
	PTCLFLAG_Unk7     = 1 << 7,  // 0x80
	PTCLFLAG_Unk8     = 1 << 8,  // 0x100
	PTCLFLAG_Unk9     = 1 << 9,  // 0x200
	PTCLFLAG_Unk10    = 1 << 10, // 0x400
	PTCLFLAG_Unk11    = 1 << 11, // 0x800
	PTCLFLAG_Unk12    = 1 << 12, // 0x1000
	PTCLFLAG_Unk13    = 1 << 13, // 0x2000
	PTCLFLAG_Unk14    = 1 << 14, // 0x4000
	// ...
	PTCLFLAG_UseGravityField      = 1 << 16, // 0x10000
	PTCLFLAG_UseAirField          = 1 << 17, // 0x20000
	PTCLFLAG_UseVortexField       = 1 << 18, // 0x40000
	PTCLFLAG_UseDampedNewtonField = 1 << 19, // 0x80000
	PTCLFLAG_UseNewtonField       = 1 << 20, // 0x100000
	PTCLFLAG_UseSolidTex          = 1 << 21, // 0x200000
	PTCLFLAG_UseJitter            = 1 << 22, // 0x400000
	PTCLFLAG_Unk23                = 1 << 23, // 0x800000
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

	Vector3f getPos() { return mPosition + mLocalOffset; }

	void InitParam()
	{
		mPosition.set(0.0f, 0.0f, 0.0f);
		mLocalOffset.set(0.0f, 0.0f, 0.0f);
		_24 = 1.0f;
		mPrimaryColor.set(0, 0, 0, 0);
	}

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f mPosition;    // _0C
	Vector3f mLocalOffset; // _18
	f32 _24;               // _24
	Colour mPrimaryColor;  // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x80.
 */
struct particleMdl : public particleMdlBase {
	particleMdl()
	{
		mBBoardColourAnim.mAge      = 0.0f;
		mBBoardColourAnim.mFrame    = 0;
		mBBoardColourAnim.mLifeTime = 1;
		mBBoardColourAnim.mAnimData = nullptr;
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
		mAge      = 0;
		mLifeTime = 0;
		_30       = 0.0f;
		mVelocity.set(0.0f, 0.0f, 0.0f);
		_54 = 0.0f;
		_50 = 0.0f;
		_50 = 0.0f;
		_5C.set(0.0f, 0.0f, 0.0f);
		_58   = 0;
		_5A   = 0;
		_5C.z = 1.0f;
		_4C   = 0;
		mEnvColor.set(0, 0, 0, 0);
		mBBoardColourAnim.init(nullptr, 1);
		_78 = 0;
	}

	// _00     = VTBL
	// _00-_2C = particleMdlBase
	s16 mLifeTime;                      // _2C
	s16 mAge;                           // _2E
	f32 _30;                            // _30
	Vector3f mVelocity;                 // _34
	Vector3f mAcceleration;             // _40
	u8 _4C;                             // _4C
	f32 _50;                            // _50
	f32 _54;                            // _54
	u16 _58;                            // _58
	s16 _5A;                            // _5A
	Vector3f _5C;                       // _5C
	Colour mEnvColor;                   // _68
	bBoardColourAnim mBBoardColourAnim; // _6C
	u32 _78;                            // _78, unknown
	u8 _7C[0x4];                        // _7C, unknown
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
	particleMdlManager()
	{
		mPtclList      = nullptr;
		mChildPtclList = nullptr;
	}

	void init(u32, u32);

	// unused/inlined:
	~particleMdlManager();

	int getSleepPtclNum() { return mSleepPtclList.getListNum(); }
	int getSleepPtclChildNum() { return mSleepPtclChildList.getListNum(); }

	void putPtcl(zenList* ptcl) { mSleepPtclList.put(ptcl); }
	void putPtclChild(zenList* child) { mSleepPtclChildList.put(child); }

	// TODO: make these
	zenList* getPtcl() { return mSleepPtclList.get(); }
	zenList* getPtclChild() { return mSleepPtclChildList.get(); }

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

	void init(u8* data, Texture* tex, Texture* childTex, Vector3f& pos, particleMdlManager* mdlMgr, CallBack1<particleGenerator*>* cbGen,
	          CallBack2<particleGenerator*, particleMdl*>* cbPtcl);
	bool update(f32 timeStep);
	void draw(Graphics& gfx);
	void pmSetDDF(u8* data);
	void SetPtclsLife();
	void PtclsGen(particleMdl* ptcl);
	void pmCalcAccel(particleMdl* ptcl);
	void UpdatePtclsStatus(f32 timeStep);
	void ClearPtclsStatus(Texture* tex, Texture* childTex);
	void drawPtclBillboard(Graphics& gfx);
	void drawPtclOriented(Graphics& gfx);
	void RotAxisX(Mtx&, f32&, f32&);
	void RotAxisY(Mtx&, f32&, f32&);
	void RotAxisZ(Mtx&, f32&, f32&);
	void RotAxisXY(Mtx&, f32&, f32&);
	void RotAxisXZ(Mtx&, f32&, f32&);
	void RotAxisYZ(Mtx&, f32&, f32&);
	void RotAxisXYZ(Mtx&, f32&, f32&);
	void updatePtclChildren(f32 timeStep);
	void drawPtclChildren(Graphics& gfx);
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

	void setAirField(Vector3f& vel, bool set)
	{
		mAirFieldVelocity.set(vel);
		pmSwitch(set, PTCLFLAG_UseAirField);
	}

	void setNewtonField(Vector3f attractorPos, f32 strength, bool set)
	{
		mNewtonFieldDir.set(attractorPos - getGPos());
		mNewtonFieldStrength = strength;
		pmSwitch(set, PTCLFLAG_UseNewtonField);
	}

	void setOrientedConstZAxis(bool set) { _68.m2 = set; }

	void setVortexField(Vector3f pos, f32 a, f32 b, f32 c, f32 d, bool set)
	{
		mVortexCenter.set(pos);
		mVortexRotationSpeed = a; // -0.12f;
		mVortexStrength      = b; // -0.09f;
		_158                 = c; // 0.3f;
		_15C                 = d; // 400.0f;
		pmSwitch(set, PTCLFLAG_UseVortexField);
	}

	void setGravityField(Vector3f& accel, bool set)
	{
		mGravFieldAccel.set(accel);
		pmSwitch(set, PTCLFLAG_UseGravityField);
	}

	f32 getFreqFrm() { return _B8; }
	void setFreqFrm(f32 freq) { _B8 = freq; }

	f32 getInitVel() { return mInitVel; }
	void setInitVel(f32 vel) { mInitVel = vel; }

	// NB: might be getMaxFrame(), unsure
	s16 getCurrentFrame() { return mCurrentFrame; }
	s16 getMaxFrame() { return mMaxFrame; }

	void pmGetArbitUnitVec(Vector3f& unitVec)
	{
		f32 angle1 = zen::Rand(TAU);
		f32 angle2 = zen::Rand(TAU);

		f32 sin1 = sinf(angle1);
		f32 cos1 = cosf(angle1);
		f32 sin2 = sinf(angle2);
		f32 cos2 = cosf(angle2);
		unitVec.set(sin1 * cos2, sin1 * sin2, cos1);
	}

	/*
	    These are still to be made/assigned from the DLL:
	    Vector3f getAirField();
	    f32 getNewtonFieldFrc();
	*/

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f mEmitPos;                    // _0C
	Vector3f* mEmitPosPtr;                // _18
	Vector3f mEmitVelocity;               // _1C
	zenListManager mPtclMdlListManager;   // _28
	zenListManager mPtclChildListManager; // _38
	bBoardColourAnimData mAnimData;       // _48
	Texture* mTexture;                    // _58
	Texture* mChildTexture;               // _5C
	f32 _60;                              // _60
	f32 _64;                              // _64
	struct {
		u32 m0 : 1;
		u32 m1 : 1;
		u32 m2 : 1;
		u32 m3 : 1;
		u32 m4 : 1;
		u32 m5 : 1;
		u32 m6 : 1;
		u32 m7 : 1;
		u32 m8 : 1;
	} _68;                                                   // _68
	f32 _6C;                                                 // _6C
	f32 _70;                                                 // _70
	f32 _74;                                                 // _74
	f32 _78;                                                 // _78
	u16* mSolidTexFieldData;                                 // _7C
	u32 mControlFlags;                                       // _80, see ParticleGeneratorControlFlags enum
	u32 mParticleFlags;                                      // _84, see ParticleGeneratorFlags enum
	f32 _88;                                                 // _88
	f32 mPassTimer;                                          // _8C
	s16 mCurrentFrame;                                       // _90
	u8 mCurrentPass;                                         // _92
	Vector3f mEmitPosOffset;                                 // _94
	Vector3f mEmitDir;                                       // _A0
	Vector3f _AC;                                            // _AC
	f32 _B8;                                                 // _B8
	f32 _BC;                                                 // _BC
	f32 _C0;                                                 // _C0
	f32 _C4;                                                 // _C4
	f32 _C8;                                                 // _C8
	f32 mInitVel;                                            // _CC
	f32 _D0;                                                 // _D0
	f32 mDrag;                                               // _D4
	f32 mDragJitter;                                         // _D8
	f32 mMaxVel;                                             // _DC
	f32 _E0;                                                 // _E0
	f32 _E4;                                                 // _E4
	f32 _E8;                                                 // _E8
	f32 _EC;                                                 // _EC
	f32 mScaleSize;                                          // _F0
	f32 _F4;                                                 // _F4
	f32 _F8;                                                 // _F8
	f32 _FC;                                                 // _FC
	f32 _100;                                                // _100
	s16 _104;                                                // _104
	s16 _106;                                                // _106
	s16 _108;                                                // _108
	f32 _10C;                                                // _10C
	s16 _110;                                                // _110
	u8 _112;                                                 // _112
	f32 _114;                                                // _114
	f32 _118;                                                // _118
	f32 _11C;                                                // _11C
	Colour _120;                                             // _120
	u8 _124;                                                 // _124
	u8 _125;                                                 // _125
	u8 _126[0x6];                                            // _126, unknown
	Vector3f mGravFieldAccel;                                // _12C
	Vector3f mAirFieldVelocity;                              // _138
	Vector3f mVortexCenter;                                  // _144
	f32 mVortexRotationSpeed;                                // _150
	f32 mVortexStrength;                                     // _154
	f32 _158;                                                // _158
	f32 _15C;                                                // _15C
	Vector3f mDampedNewtonFieldDir;                          // _160
	f32 mDampedNewtonFieldStrength;                          // _16C
	Vector3f mNewtonFieldDir;                                // _170
	f32 mNewtonFieldStrength;                                // _17C
	Vector3f _180;                                           // _180
	u8 _18C;                                                 // _18C
	u8 _18D;                                                 // _18D
	u8 mSolidFieldType;                                      // _18E
	f32 mJitterStrength;                                     // _190
	Vector3f _194;                                           // _194
	f32 _1A0;                                                // _1A0
	f32 _1A4;                                                // _1A4
	u8 mFreePtclMotionTime;                                  // _1A8
	f32* _1AC;                                               // _1AC
	f32* _1B0;                                               // _1B0
	f32* _1B4;                                               // _1B4
	f32* _1B8;                                               // _1B8
	f32* _1BC;                                               // _1BC;
	f32* _1C0;                                               // _1C0
	u8 _1C4;                                                 // _1C4
	u8 _1C5;                                                 // _1C5
	u8 _1C6;                                                 // _1C6
	s16 mMaxFrame;                                           // _1C8
	u8 mMaxPasses;                                           // _1CA
	u8 mBlendFactor;                                         // _1CB
	u8 mZMode;                                               // _1CC
	particleMdlManager* mMdlMgr;                             // _1D0
	CallBack1<particleGenerator*>* mCallBack1;               // _1D4
	CallBack2<particleGenerator*, particleMdl*>* mCallBack2; // _1D8
	Vector3f mOrientedNormalVector;                          // _1DC
	PtclDrawCallBack mDrawCallBack;                          // _1E8
	RotAxisCallBack mRotAxisCallBack;                        // _1F4
};

/**
 * @brief TODO
 */
struct PCRData : public zenList {
	PCRData(char* name, u32 bufSize) { pmSet(name, bufSize); }

	// DLL inlines to do:
	u8* pmSet(char* name, u32 bufSize)
	{
		mName    = StdSystem::stringDup(name);
		mDataBuf = new (0x20) u8[bufSize];
	}

	char* getName() { return mName; }
	u8* getDataBuf() { return mDataBuf; }

	// _00     = VTBL
	// _00-_0C = zenList
	char* mName;  // _0C
	u8* mDataBuf; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct particleLoader : public zenListManager {
	u8* load(char*, bool);
	u8* pmFind(char*);

	// unused/inlined:
	~particleLoader();

	// DLL inlines to do:
	PCRData* pmCreatePCRData(char* name, u32 bufSize)
	{
		PCRData* data = new PCRData(name, bufSize);
		put(data);
		return data;
	}

	// _00-_10 = zenListManager (members are PCRData*)
};

/**
 * @brief TODO
 */
struct simplePtclManager {
	simplePtclManager() { mMdlMgr = nullptr; }

	void update(f32);
	void draw(Graphics&);
	void forceFinish();

	// unused/inlined:
	zen::particleMdl* create(Texture*, s16, const Vector3f&, const Vector3f&, const Vector3f&, f32, f32, const Colour&, const Colour&,
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
	particleManager()
	{
		mPtclGenList = nullptr;
		_5C          = 0;
	}

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
	particleMdl* createParticle(Texture* tex, s16 p2, Vector3f& p3, Vector3f& p4, Vector3f& p5, f32 p6, f32 p7, Colour p8, Colour p9,
	                            CallBack1<particleMdl*>* cbPtcl)
	{
		return mSimplePtclMgr.create(tex, p2, p3, p4, p5, p6, p7, p8, p9, cbPtcl);
	}

	static const f32 DEFAULT_FRAME_RATE;
	static const u16 MAX_PTCLGENS_NUM;
	static const u16 MAX_PTCLS_NUM;
	static const u16 MAX_PTCL_CHILD_NUM;

	zenListManager mActiveGenList;    // _00
	zenListManager mInactiveGenList;  // _10
	zenListManager _20;               // _20
	particleGenerator* mPtclGenList;  // _30, array of up to 0x1000 particleGenerators
	particleMdlManager mMdlMgr;       // _34
	u32 _5C;                          // _5C, unknown, might be in particleMdlManager
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

extern u16* UseSolidTex[6];

} // namespace zen

#endif
