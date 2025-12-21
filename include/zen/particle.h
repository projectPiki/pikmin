#ifndef _ZEN_PARTICLE_H
#define _ZEN_PARTICLE_H

#include "Colour.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "sysNew.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/Math.h"
#include "zen/bBoardColourAnim.h"
#include "zen/zenList.h"

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
	immut char* mPCRPath;  // _00
	immut char* mTex1Path; // _04
	immut char* mTex2Path; // _08
};

/**
 * @brief TODO
 *
 * @note Size 0x10. This is used by effectMgr to load in geometry for EffShpInst things
 */
struct GeometryLoadInfo {
	immut char* mMODPath;  // _00
	immut char* mAnimPath; // _04
	f32 mScale;            // _08
	u8 mLoopMax;           // _0C
};

/**
 * @brief TODO
 *
 * @note Size 0xC. This is used by effectMgr to load in simple particle info.
 */
struct SimplePtclLoadInfo {
	immut char* mBTIPath; // _00
	GXColor _04;          // _04
	GXColor _08;          // _08
};

namespace zen {

struct particleMdl;
struct particleMdlManager;
struct particleGenerator;

typedef void (particleGenerator::*PtclDrawCallBack)(Graphics&);
typedef void (particleGenerator::*RotAxisCallBack)(Mtx&, f32&, f32&);

/**
 * @brief Flags for controlling the particle generator's overall state.
 */
enum ParticleGeneratorControlFlags {
	PTCLCTRL_Stop       = 1 << 0, // The generator is running updates.
	PTCLCTRL_Finished   = 1 << 1, // The generator is being drawn.
	PTCLCTRL_Active     = 1 << 2, // The generator is paused.
	PTCLCTRL_GenStopped = 1 << 3, // The generator has finished all passes and is waiting for particles to die.
	PTCLCTRL_Visible    = 1 << 4, // The generator has been explicitly told to stop emitting new particles.
};

/**
 * @brief Flags that define the properties and behaviors of the particles and their emitter.
 */
enum ParticleGeneratorFlags {
	// Emission shape type (2-bit field: bits 0-1)
	PTCLFLAG_EmitShapeSphere = 1 << 0, // 0x1, Spherical emission volume
	PTCLFLAG_EmitShapeBox    = 1 << 1, // 0x2, Box-shaped emission volume

	// Velocity direction type (2-bit field: bits 2-3)
	PTCLFLAG_VelDirOmni        = 1 << 2, // 0x4, Omnidirectional velocity
	PTCLFLAG_VelDirDirectional = 1 << 3, // 0x8, Velocity along emission direction
	PTCLFLAG_ClampVelocity     = 1 << 4, // 0x10, Clamp particle velocity to maximum
	// 0x20 is Unused

	// Emission rate interpolation type
	PTCLFLAG_EmissionRateManual = 1 << 6, // 0x40, Manual keyframe interpolation for emission rate
	PTCLFLAG_EmissionRateLinear = 1 << 7, // 0x80, Linear keyframe interpolation for emission rate

	// Emission radius interpolation type
	PTCLFLAG_EmissionRadiusManual = 1 << 8, // 0x100, Manual keyframe interpolation for emission radius
	PTCLFLAG_EmissionRadiusLinear = 1 << 9, // 0x200, Linear keyframe interpolation for emission radius

	// Initial velocity interpolation type
	PTCLFLAG_InitVelocityManual = 1 << 10, // 0x400, Manual keyframe interpolation for initial velocity
	PTCLFLAG_InitVelocityLinear = 1 << 11, // 0x800, Linear keyframe interpolation for initial velocity

	PTCLFLAG_DisableEmission      = 1 << 12, // 0x1000, Disable particle emission
	PTCLFLAG_EnableChildParticles = 1 << 13, // 0x2000, Enable child particle spawning
	PTCLFLAG_InheritParentColor   = 1 << 14, // 0x4000, Child particles inherit parent color
	// 0x8000 is Unused

	// Physics field flags
	PTCLFLAG_UseGravityField      = 1 << 16, // 0x10000, Apply gravity acceleration
	PTCLFLAG_UseAirField          = 1 << 17, // 0x20000, Apply air/wind velocity
	PTCLFLAG_UseVortexField       = 1 << 18, // 0x40000, Apply vortex/spiral forces
	PTCLFLAG_UseDampedNewtonField = 1 << 19, // 0x80000, Apply damped attraction forces
	PTCLFLAG_UseNewtonField       = 1 << 20, // 0x100000, Apply simple attraction forces
	PTCLFLAG_UseSolidTexField     = 1 << 21, // 0x200000, Apply solid texture-based forces
	PTCLFLAG_UseJitterField       = 1 << 22, // 0x400000, Apply random jitter forces
	PTCLFLAG_UseLineField         = 1 << 23, // 0x800000, Apply line-based axial/radial forces
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

	Vector3f getPos() { return mLocalPosition + mGlobalPosition; }

	void InitParam()
	{
		mLocalPosition.set(0.0f, 0.0f, 0.0f);
		mGlobalPosition.set(0.0f, 0.0f, 0.0f);
		mSize = 1.0f;
		mPrimaryColor.set(0, 0, 0, 0);
	}

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f mLocalPosition;  // _0C
	Vector3f mGlobalPosition; // _18
	f32 mSize;                // _24
	Colour mPrimaryColor;     // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x80.
 */
struct particleMdl : public particleMdlBase {
	particleMdl()
	{
		mBBoardColourAnim.mProgress     = 0.0f;
		mBBoardColourAnim.mCurrentFrame = 0;
		mBBoardColourAnim.mDuration     = 1;
		mBBoardColourAnim.mAnimData     = nullptr;
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
		mAgeTimer = 0.0f;
		mVelocity.set(0.0f, 0.0f, 0.0f);
		mAlphaFactor = 0.0f;
		mScaleFactor = 0.0f;
		mScaleFactor = 0.0f;
		mOrientedNormal.set(0.0f, 0.0f, 0.0f);
		mRotAngle         = 0;
		mRotSpeed         = 0;
		mOrientedNormal.z = 1.0f;
		_UNUSED4C         = 0;
		mEnvColor.set(0, 0, 0, 0);
		mBBoardColourAnim.init(nullptr, 1);
		mSimpleTex = 0;
	}

	// _00     = VTBL
	// _00-_2C = particleMdlBase
	s16 mLifeTime;                          // _2C
	s16 mAge;                               // _2E, rounded version of mAgeTimer
	f32 mAgeTimer;                          // _30
	Vector3f mVelocity;                     // _34
	Vector3f mAcceleration;                 // _40
	u8 _UNUSED4C;                           // _4C
	f32 mScaleFactor;                       // _50
	f32 mAlphaFactor;                       // _54
	u16 mRotAngle;                          // _58
	s16 mRotSpeed;                          // _5A
	Vector3f mOrientedNormal;               // _5C
	Colour mEnvColor;                       // _68
	bBoardColourAnim mBBoardColourAnim;     // _6C
	Texture* mSimpleTex;                    // _78
	CallBack1<particleMdl*>* mPtclCallBack; // _7C
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
public:
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

protected:
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
public:
	particleGenerator()
	{
		ClearPtclsStatus(nullptr, nullptr);
		mCallBack1     = nullptr;
		mCallBack2     = nullptr;
		mParticleFlags = 0;
		mControlFlags  = 0;
	}

	virtual void remove() // _0C
	{
		zenList::remove();
		ClearPtclsStatus(nullptr, nullptr);
	}

	~particleGenerator() { }

	void init(u8* data, Texture* tex, Texture* childTex, immut Vector3f& pos, particleMdlManager* mdlMgr,
	          CallBack1<particleGenerator*>* cbGen, CallBack2<particleGenerator*, particleMdl*>* cbPtcl);
	bool update(f32 timeStep);
	void draw(Graphics& gfx);
	void RotAxisX(Mtx&, f32&, f32&);
	void RotAxisY(Mtx&, f32&, f32&);
	void RotAxisZ(Mtx&, f32&, f32&);
	void RotAxisXY(Mtx&, f32&, f32&);
	void RotAxisXZ(Mtx&, f32&, f32&);
	void RotAxisYZ(Mtx&, f32&, f32&);
	void RotAxisXYZ(Mtx&, f32&, f32&);
	void forceFinish();
	bool finish(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	bool forceFinish(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);

	zenListManager& getPtclMdlListManager() { return mPtclMdlListManager; }

	void setEmitPos(immut Vector3f& pos) { mEmitPos = pos; }
	void setEmitPosPtr(immut Vector3f* posPtr) { mEmitPosPtr = posPtr; }
	void setEmitDir(immut Vector3f& dir) { mEmitDir = dir; }
	void setEmitVelocity(immut Vector3f& vel) { mEmitVelocity = vel; }
	void setOrientedNormalVector(immut Vector3f& vec) { mOrientedNormal = vec; }
	void setCallBack(CallBack1<particleGenerator*>* cb1, CallBack2<particleGenerator*, particleMdl*>* cb2)
	{
		mCallBack1 = cb1;
		if (cb1) {
			mCallBack1->invoke(this);
		}
		mCallBack2 = cb2;
	}

	immut Vector3f& getGPos()
	{
		if (mEmitPosPtr) {
			return *mEmitPosPtr;
		}
		return mEmitPos;
	}

	// these are the same for some reason
	immut Vector3f& getEmitPos()
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

	void setAirField(immut Vector3f& vel, bool set)
	{
		mAirFieldVelocity.set(vel);
		pmSwitch(set, PTCLFLAG_UseAirField);
	}
	Vector3f getAirField() { return mAirFieldVelocity; }

	void setNewtonField(Vector3f attractorPos, f32 strength, bool set)
	{
		mNewtonFieldDir.set(attractorPos - getGPos());
		mNewtonFieldStrength = strength;
		pmSwitch(set, PTCLFLAG_UseNewtonField);
	}

	f32 getNewtonFieldFrc() { return mNewtonFieldStrength; }

	void setOrientedConstZAxis(bool set) { mOrientedDrawConfig.mFlipNormal = set; }

	void setVortexField(Vector3f pos, f32 a, f32 b, f32 c, f32 d, bool set)
	{
		mVortexCenter.set(pos);
		mVortexRotationSpeed  = a; // -0.12f;
		mVortexStrength       = b; // -0.09f;
		mVortexFalloffFactor  = c; // 0.3f;
		mVortexFalloffDivisor = d; // 400.0f;
		pmSwitch(set, PTCLFLAG_UseVortexField);
	}

	void setGravityField(immut Vector3f& accel, bool set)
	{
		mGravFieldAccel.set(accel);
		pmSwitch(set, PTCLFLAG_UseGravityField);
	}

	f32 getFreqFrm() { return mEmissionRate; }
	void setFreqFrm(f32 freq) { mEmissionRate = freq; }

	f32 getInitVel() { return mInitVel; }
	void setInitVel(f32 vel) { mInitVel = vel; }

	s16 getCurrentFrame() { return mCurrentFrame; }
	s16 getMaxFrame() { return mMaxFrame; }

protected:
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

	void pmPutParticle(zenList* ptcl) { mMdlMgr->putPtcl(ptcl); }
	void pmSetDDF(u8* data);
	f32 pmIntpManual(f32*, f32*);
	f32 pmIntpLinear(f32*, f32*);
	particleMdl* pmGetParticle();
	particleChildMdl* pmGetParticleChild();
	void pmPutParticleChild(zenList* child) { mMdlMgr->putPtclChild(child); }
	void pmCalcAccel(particleMdl* ptcl);

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

	void ClearPtclsStatus(Texture* tex, Texture* childTex);
	void SetPtclsLife();
	void PtclsGen(particleMdl* ptcl);
	void drawPtclBillboard(Graphics& gfx);
	void drawPtclOriented(Graphics& gfx);
	void drawPtclChildren(Graphics& gfx);

	void UpdatePtclsStatus(f32 timeStep);
	void updatePtclChildren(f32 timeStep);

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f mEmitPos;                    // _0C
	immut Vector3f* mEmitPosPtr;          // _18
	Vector3f mEmitVelocity;               // _1C
	zenListManager mPtclMdlListManager;   // _28
	zenListManager mPtclChildListManager; // _38
	bBoardColourAnimData mAnimData;       // _48
	Texture* mTexture;                    // _58
	Texture* mChildTexture;               // _5C
	f32 mLengthScale;                     // _60
	f32 mPivotOffsetY;                    // _64
	struct {
		u32 mOrientationSource : 1; // 0 = use velocity vector, 1 = use oriented position vector
		u32 mIsDoubleSided : 1;     // If true, render particles double-sided (8 vertices), otherwise single-sided (4 vertices)
		u32 mFlipNormal : 1;        // If true, reverse normal calculation order (affects which side faces camera)
		u32 m3 : 1;
		u32 m4 : 1;
		u32 m5 : 1;
		u32 m6 : 1;
		u32 m7 : 1;
		u32 m8 : 1;
	} mOrientedDrawConfig;                                   // _68
	f32 mScaleRate1;                                         // _6C
	f32 mScaleRate2;                                         // _70
	f32 mAlphaRate1;                                         // _74
	f32 mAlphaRate2;                                         // _78
	u16* mSolidTexFieldData;                                 // _7C
	u32 mControlFlags;                                       // _80, see ParticleGeneratorControlFlags enum
	u32 mParticleFlags;                                      // _84, see ParticleGeneratorFlags enum
	f32 mPartialParticleCount;                               // _88
	f32 mPassTimer;                                          // _8C
	s16 mCurrentFrame;                                       // _90
	u8 mCurrentPass;                                         // _92
	Vector3f mEmitPosOffset;                                 // _94
	Vector3f mEmitDir;                                       // _A0
	Vector3f mEmissionBoxSize;                               // _AC
	f32 mEmissionRate;                                       // _B8
	f32 mEmissionRateJitter;                                 // _BC
	f32 mEmissionSpread;                                     // _C0
	f32 mEmissionRadiusScale;                                // _C4
	f32 mEmissionRadius;                                     // _C8
	f32 mInitVel;                                            // _CC
	f32 mInitialVelocityJitter;                              // _D0
	f32 mDrag;                                               // _D4
	f32 mDragJitter;                                         // _D8
	f32 mMaxVel;                                             // _DC
	f32 mScaleThreshold1;                                    // _E0
	f32 mScaleThreshold2;                                    // _E4
	f32 mMinScaleFactor1;                                    // _E8
	f32 mMinScaleFactor2;                                    // _EC
	f32 mScaleSize;                                          // _F0
	f32 mSizeJitter;                                         // _F4
	f32 mAlphaThreshold1;                                    // _F8
	f32 mAlphaThreshold2;                                    // _FC
	f32 mAlphaJitter;                                        // _100
	s16 mRotSpeedMin;                                        // _104
	s16 mRotSpeedJitter;                                     // _106
	s16 mRotAngle;                                           // _108
	f32 mLifetimeJitter;                                     // _10C
	s16 mBaseLifetime;                                       // _110
	u8 _UNUSED112;                                           // _112
	f32 mChildScaleFactor;                                   // _114
	f32 mChildAlphaMultiplier;                               // _118
	f32 mChildPosJitter;                                     // _11C
	Colour mChildColor;                                      // _120
	u8 _124;                                                 // _124
	u8 mChildSpawnInterval;                                  // _125
	u8 _126[0x6];                                            // _126, unknown
	Vector3f mGravFieldAccel;                                // _12C
	Vector3f mAirFieldVelocity;                              // _138
	Vector3f mVortexCenter;                                  // _144
	f32 mVortexRotationSpeed;                                // _150
	f32 mVortexStrength;                                     // _154
	f32 mVortexFalloffFactor;                                // _158
	f32 mVortexFalloffDivisor;                               // _15C
	Vector3f mDampedNewtonFieldDir;                          // _160
	f32 mDampedNewtonFieldStrength;                          // _16C
	Vector3f mNewtonFieldDir;                                // _170
	f32 mNewtonFieldStrength;                                // _17C
	Vector3f mSolidFieldForceMultiplier;                     // _180
	u8 mSolidFieldGridScale;                                 // _18C
	u8 mSolidFieldSampleOffset;                              // _18D
	u8 mSolidFieldType;                                      // _18E
	f32 mJitterStrength;                                     // _190
	Vector3f mLineFieldAxis;                                 // _194
	f32 mLineFieldAxialForce;                                // _1A0
	f32 mLineFieldRadialForce;                               // _1A4
	u8 mFreePtclMotionTime;                                  // _1A8
	f32* mEmissionRateKeyframes;                             // _1AC
	f32* mEmissionRateValues;                                // _1B0
	f32* mEmissionRadiusKeyframes;                           // _1B4
	f32* mEmissionRadiusValues;                              // _1B8
	f32* mInitVelIntpThresholds;                             // _1BC;
	f32* mInitVelIntpValues;                                 // _1C0
	u8 mEmissionRateKeyCount;                                // _1C4
	u8 mEmissionRadiusKeyCount;                              // _1C5
	u8 mInitialVelocityKeyCount;                             // _1C6
	s16 mMaxFrame;                                           // _1C8
	u8 mMaxPasses;                                           // _1CA
	u8 mBlendFactor;                                         // _1CB
	u8 mZMode;                                               // _1CC
	particleMdlManager* mMdlMgr;                             // _1D0
	CallBack1<particleGenerator*>* mCallBack1;               // _1D4
	CallBack2<particleGenerator*, particleMdl*>* mCallBack2; // _1D8
	Vector3f mOrientedNormal;                                // _1DC
	PtclDrawCallBack mDrawCallBack;                          // _1E8
	RotAxisCallBack mRotAxisCallBack;                        // _1F4
};

/**
 * @brief TODO
 */
struct PCRData : public zenList {
public:
	PCRData(immut char* name, u32 bufSize) { pmSet(name, bufSize); }

	immut char* getName() { return mName; }
	u8* getDataBuf() { return mDataBuf; }

protected:
	// DLL inlines to do:
	u8* pmSet(immut char* name, u32 bufSize)
	{
		mName    = StdSystem::stringDup(name);
		mDataBuf = new (0x20) u8[bufSize];
	}

	// _00     = VTBL
	// _00-_0C = zenList
	immut char* mName; // _0C
	u8* mDataBuf;      // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct particleLoader : public zenListManager {
public:
	u8* load(immut char*, bool);

	// unused/inlined:
	~particleLoader();

protected:
	u8* pmFind(immut char*);

	PCRData* pmCreatePCRData(immut char* name, u32 bufSize)
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
struct simplePtclManager : public zenListManager {
public:
	simplePtclManager() { mMdlMgr = nullptr; }

	void update(f32);
	void draw(Graphics&);
	void forceFinish();

	// unused/inlined:
	zen::particleMdl* create(Texture* simpleTex, s16 lifeTime, const Vector3f& globalPos, const Vector3f& vel, const Vector3f& accel,
	                         f32 size, f32 rotSpeed, const Colour& primColor, const Colour& envColor,
	                         zen::CallBack1<zen::particleMdl*>* cbPtcl);
	~simplePtclManager();

	void init(particleMdlManager* mdlMgr) { mMdlMgr = mdlMgr; }

protected:
	void pmPutParticle(zenList* ptcl) { mMdlMgr->putPtcl(ptcl); }

	particleMdl* pmGetParticle()
	{
		particleMdl* ptcl = (particleMdl*)mMdlMgr->getPtcl();
		if (ptcl) {
			put(ptcl);
		}
		return ptcl;
	}

	// _00-_10 = zenListManager (type = particleMdl)
	particleMdlManager* mMdlMgr; // _10
};

/**
 * @brief TODO
 *
 * @note Size: 0x9C.
 */
struct particleManager {
public:
	particleManager()
	{
		mPtclGenList = nullptr;
		_5C          = 0;
	}

	void init(u32 numPtclGens, u32 numParticles, u32 numChildParticles, f32 p4);
	particleGenerator* createGenerator(u8*, Texture*, Texture*, immut Vector3f&, CallBack1<particleGenerator*>*,
	                                   CallBack2<particleGenerator*, particleMdl*>*);
	void update();
	void draw(Graphics& gfx);
	void cullingDraw(Graphics& gfx);
	void killAllGenarator(bool doForceFinish); // dev typo
	void killGenerator(particleGenerator* gen, bool doForceFinish);
	void killGenerator(CallBack1<particleGenerator*>* cb1, CallBack2<particleGenerator*, particleMdl*>* cb2, bool doForceFinish);

	// unused/inlined:
	~particleManager();
	void debugUpdate();
	void debugDraw(Graphics&);

	particleMdl* createParticle(Texture* simpleTex, s16 lifeTime, immut Vector3f& globalPos, immut Vector3f& vel, immut Vector3f& accel,
	                            f32 size, f32 rotSpeed, Colour primColor, Colour envColor, CallBack1<particleMdl*>* cbPtcl)
	{
		return mSimplePtclMgr.create(simpleTex, lifeTime, globalPos, vel, accel, size, rotSpeed, primColor, envColor, cbPtcl);
	}

	static const f32 DEFAULT_FRAME_RATE;

protected:
	void calcActiveList();
	bool pmCheckList(particleGenerator* testGen);
	particleGenerator* pmGetPtclGen();
	void pmPutPtclGen(zenList* gen) { _20.put(gen); }

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
public:
	inline PtclGenPack(int limit)
	{
		mLimit         = limit;
		mGeneratorList = new particleGenerator*[mLimit];
		for (int i = 0; i < mLimit; i++) {
			mGeneratorList[i] = nullptr;
		}
	}

	void setPtclGenPtr(u32, particleGenerator*);
	void setEmitPosPtr(immut Vector3f*);
	void startGen();
	void stopGen();
	void finish();
	void forceFinish();
	bool checkStopGen();

	// unused/inlined:
	particleGenerator* getPtclGenPtr(u32 idx);
	void setEmitPos(immut Vector3f&);
	void setEmitDir(immut Vector3f&);
	void setCallBack(CallBack1<particleGenerator*>*, CallBack2<particleGenerator*, particleMdl*>*);
	void start();
	void stop();
	bool checkStop();
	bool checkEmit();
	bool checkActive();

protected:
	u32 mLimit;                         // _00
	particleGenerator** mGeneratorList; // _04
};

extern u16* UseSolidTex[6];

} // namespace zen

#endif
