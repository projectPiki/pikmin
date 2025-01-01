#ifndef _ZEN_PARTICLE_H
#define _ZEN_PARTICLE_H

#include "types.h"
#include "zen/zenList.h"
#include "zen/CallBack.h"
#include "zen/bBoardColourAnim.h"
#include "Dolphin/mtx.h"
#include "sysNew.h"

struct Colour;
struct Graphics;
struct Texture;
struct Vector3f;

namespace zen {

struct particleMdl;
struct particleMdlManager;

/*
 * @brief TODO
 */
enum ParticleGeneratorFlags {
	PTCLGEN_Stop       = 0x1,
	PTCLGEN_Finished   = 0x2,
	PTCLGEN_Active     = 0x4,
	PTCLGEN_GenStopped = 0x8,
};

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct particleMdlBase : public zenList {
	inline particleMdlBase()
	{
		_0C.set(0.0f, 0.0f, 0.0f);
		_18.set(0.0f, 0.0f, 0.0f);
		_24 = 1.0f;
		_28 = 0;
		_29 = 0;
		_2A = 0;
		_2B = 0;
	}

	virtual void remove(); // _0C

	// unused/inlined:
	~particleMdlBase() { }

	// todo: make these
	void InitParam();
	Vector3f getPos() { return _0C + _18; }

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f _0C; // _0C
	Vector3f _18; // _18
	f32 _24;      // _24
	u8 _28;       // _28
	u8 _29;       // _29
	u8 _2A;       // _2A
	u8 _2B;       // _2B
};

/*
 * @brief TODO
 */
struct particleMdl : public particleMdlBase {
	particleMdl();

	virtual void remove(); // _0C

	~particleMdl();

	// todo: make this
	void InitParam();

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
};

/*
 * @brief TODO
 */
struct particleChildMdl : public particleMdlBase {
	particleChildMdl();

	virtual void remove(); // _0C

	~particleChildMdl();

	// _00     = VTBL
	// _00-_2C = particleMdlBase
	f32 _2C; // _2C
	u8 _30;  // _30
	u8 _31;  // _31
	u8 _32;  // _32
};

/*
 * @brief TODO
 */
struct particleMdlManager {
	void init(u32, u32);

	// unused/inlined:
	~particleMdlManager();

	// TODO: make these
	int getSleepPtclChildNum();
	int getSleepPtclNum();
	void putPtcl(zenList*);
	void putPtclChild(zenList*);
	zenList* getPtcl();
	zenList* getPtclChild();

	// TODO: members
};

/*
 * @brief TODO
 */
struct particleGenerator : public zenList {
	particleGenerator();

	virtual void remove(); // _0C

	~particleGenerator();

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

	inline void set1DC(Vector3f& vec) { _1DC = vec; }

	// these are correct from the DLL

	void pmSwitchOn(u32 flag) { mGeneratorFlags |= flag; }
	void pmSwitchOff(u32 flag) { mGeneratorFlags &= ~flag; }

	zenListManager& getPtclMdlListManager() { return mPtclMdlListManager; }

	void setEmitPos(Vector3f& pos) { _0C = pos; }
	void setEmitPosPtr(Vector3f* posPtr) { mEmitPosPtr = posPtr; }
	void setEmitDir(Vector3f& vec) { mEmitDir = vec; }
	void setCallBack(CallBack1<particleGenerator*>* cb1, CallBack2<particleGenerator*, particleMdl*>* cb2)
	{
		mCallBack1 = cb1;
		if (cb1) {
			mCallBack1->invoke(this);
		}
		mCallBack2 = cb2;
	}

	Vector3f& getGPos() { return (mEmitPosPtr) ? *mEmitPosPtr : _0C; }

	f32 getScaleSize() { return mScaleSize; }
	void setScaleSize(f32 scale) { mScaleSize = scale; }

	void start() { mGeneratorFlags &= ~PTCLGEN_Stop; }
	void stop() { mGeneratorFlags |= PTCLGEN_Stop; }
	void startGen() { mGeneratorFlags &= ~PTCLGEN_GenStopped; }
	void stopGen() { mGeneratorFlags |= PTCLGEN_GenStopped; }
	void finish() { mGeneratorFlags |= PTCLGEN_Finished; }

	bool checkStop() { return mGeneratorFlags & PTCLGEN_Stop; }
	bool checkEmit() { return !(mGeneratorFlags & PTCLGEN_Finished); }
	bool checkActive() { return mGeneratorFlags & PTCLGEN_Active; }
	bool checkStopGen() { return mGeneratorFlags & PTCLGEN_GenStopped; }

	/*
	    These are still to be made/assigned from the DLL:

	    void visible();
	    void invisible();

	    void killParticle(particleMdl*);

	    void setAirField(Vector3f&, bool);
	    void setEmitVelocity(Vector3f&);
	    void setGravityField(Vector3f&, bool);
	    void setOrientedConstZAxis(bool);
	    void setOrientedNormalVector(Vector3f&);
	    void setVortexField(Vector3f, f32, f32, f32, f32, bool);

	    void setFreqFrm(f32);
	    void setInitVel(f32);
	    void setNewtonField(Vector3f, f32, bool);

	    f32 getFreqFrm();
	    f32 getInitVel();
	    f32 getNewtonFieldFrc();

	    void pmGetArbitUnitVec(Vector3f&);
	    void pmPutParticle(zenList*);
	    void pmPutParticleChild(zenList*);
	    void pmSwitch(bool, u32);

	    s16 getCurrentFrame();
	    s16 getMaxFrame();

	    Vector3f& getEmitPos();

	    u32 getControlFlag();
	*/

	// _00     = VTBL
	// _00-_0C = zenList
	Vector3f _0C;                                            // _0C
	Vector3f* mEmitPosPtr;                                   // _18
	Vector3f _1C;                                            // _1C
	zenListManager mPtclMdlListManager;                      // _28
	zenListManager _38;                                      // _38
	u8 _48[0x80 - 0x48];                                     // _48, unknown
	u32 mGeneratorFlags;                                     // _80
	u32 _84;                                                 // _84, unknown
	u8 _88[0x94 - 0x88];                                     // _88, unknown
	Vector3f _94;                                            // _94
	Vector3f mEmitDir;                                       // _A0
	Vector3f _AC;                                            // _AC
	u8 _B8[0xF0 - 0xB8];                                     // _B8, unknown
	f32 mScaleSize;                                          // _F0
	u8 _F4[0x12C - 0xF4];                                    // _F4, unknown
	Vector3f _12C;                                           // _12C
	Vector3f _138;                                           // _138
	Vector3f _144;                                           // _144
	u8 _150[0x160 - 0x150];                                  // _150, unknown
	Vector3f _160;                                           // _160
	u8 _16C[0x4];                                            // _16C, unknown
	Vector3f _170;                                           // _170
	u8 _17C[0x4];                                            // _17C, unknown
	Vector3f _180;                                           // _180
	u8 _18C[0x8];                                            // _18C, unknown
	Vector3f _194;                                           // _194
	u8 _1A0[0x1D0 - 0x1A0];                                  // _1A0, unknown
	u32 _1D0;                                                // _1D0, unknown
	CallBack1<particleGenerator*>* mCallBack1;               // _1D4
	CallBack2<particleGenerator*, particleMdl*>* mCallBack2; // _1D8
	Vector3f _1DC;                                           // _1DC
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
	void checkStop();
	void checkEmit();
	void checkActive();

	inline particleGenerator** getGenList() { return mGeneratorList; }

	u32 mLimit;                         // _00
	particleGenerator** mGeneratorList; // _04
};

} // namespace zen

#endif
