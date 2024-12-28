#ifndef _ZEN_PARTICLE_H
#define _ZEN_PARTICLE_H

#include "types.h"
#include "zen/zenList.h"
#include "Dolphin/mtx.h"
#include "sysNew.h"

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
	~particleMdlBase();

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

	inline void start() { mGeneratorFlags &= ~PTCLGEN_GenStopped; }
	inline void stop() { mGeneratorFlags |= PTCLGEN_GenStopped; }

	inline bool isFlag4() { return mGeneratorFlags & PTCLGEN_Unk3; }

	inline void setF0(f32 val) { _F0 = val; } // unsure what this does, rename later

	inline void setA0(Vector3f& vec) { _A0 = vec; }
	inline void set1DC(Vector3f& vec) { _1DC = vec; }

	// _00     = VTBL
	// _00-_0C = zenList
	// TODO: members
	Vector3f _0C;           // _0C
	Vector3f* mEmitPosPtr;  // _18
	Vector3f _1C;           // _1C
	zenListManager _28;     // _28
	zenListManager _38;     // _38
	u8 _48[0x80 - 0x48];    // _48, unknown
	u32 mGeneratorFlags;    // _80
	u32 _84;                // _84, unknown
	u8 _88[0x94 - 0x88];    // _88, unknown
	Vector3f _94;           // _94
	Vector3f _A0;           // _A0
	Vector3f _AC;           // _AC
	u8 _B8[0xF0 - 0xB8];    // _B8, unknown
	f32 _F0;                // _F0
	u8 _F4[0x12C - 0xF4];   // _F4, unknown
	Vector3f _12C;          // _12C
	Vector3f _138;          // _138
	Vector3f _144;          // _144
	u8 _150[0x160 - 0x150]; // _150, unknown
	Vector3f _160;          // _160
	u8 _16C[0x4];           // _16C, unknown
	Vector3f _170;          // _170
	u8 _17C[0x4];           // _17C, unknown
	Vector3f _180;          // _180
	u8 _18C[0x8];           // _18C, unknown
	Vector3f _194;          // _194
	u8 _1A0[0x1D4 - 0x1A0]; // _1A0, unknown
	u32 _1D4;               // _1D4, unknown
	u32 _1D8;               // _1D8, unknown
	Vector3f _1DC;          // _1DC
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
