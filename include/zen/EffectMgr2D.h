#ifndef _ZEN_EFFECTMGR2D_H
#define _ZEN_EFFECTMGR2D_H

#include "Camera.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

/**
 * @brief TODO
 */
enum EffType2D {
	EFF2D_Unk0 = 0,        // 0 - frt_l
	EFF2D_Unk1,            // 1 - frt_h_l
	EFF2D_Unk2,            // 2 - frt_s
	EFF2D_Unk3,            // 3 - frt_h_s
	EFF2D_Unk4,            // 4 - bg_od01
	EFF2D_Unk5,            // 5 - bg_od01r
	EFF2D_Unk6,            // 6 - bg_od01g
	EFF2D_Unk7,            // 7 - bg_od01b
	EFF2D_Unk8,            // 8 - bg_od02
	EFF2D_Unk9,            // 9 - bg_od02r
	EFF2D_Unk10,           // 10 - bg_od02g
	EFF2D_Unk11,           // 11 - bg_od02b
	EFF2D_Unk12,           // 12 - record_l
	EFF2D_Unk13,           // 13 - rec_h_l
	EFF2D_Unk14,           // 14 - star
	EFF2D_Unk15,           // 15 - record_s
	EFF2D_Unk16,           // 16 - rec_h_s
	EFF2D_Unk17,           // 17 - bg_ds01
	EFF2D_Unk18,           // 18 - bg_ds01r
	EFF2D_Unk19,           // 19 - bg_ds01g
	EFF2D_Unk20,           // 20 - bg_ds01b
	EFF2D_Unk21,           // 21 - bg_ds02
	EFF2D_Unk22,           // 22 - bg_ds02r
	EFF2D_Unk23,           // 23 - bg_ds02g
	EFF2D_Unk24,           // 24 - bg_ds02b
	EFF2D_Unk25,           // 25 - bg_cms01
	EFF2D_Unk26,           // 26 - bg_cms01r
	EFF2D_Unk27,           // 27 - bg_cms01g
	EFF2D_Unk28,           // 28 - bg_cms01b
	EFF2D_Unk29,           // 29 - bg_cms02
	EFF2D_Unk30,           // 30 - bg_cms02r
	EFF2D_Unk31,           // 31 - bg_cms02g
	EFF2D_Unk32,           // 32 - bg_cms02b
	EFF2D_Unk33,           // 33 - selec_tm
	EFF2D_Unk34,           // 34 - selec_km
	EFF2D_Unk35,           // 35 - file_slm
	EFF2D_Unk36,           // 36 - file_sel
	EFF2D_Unk37,           // 37 - select_k
	EFF2D_Unk38,           // 38 - select_t
	EFF2D_Unk39,           // 39 - syokika2
	EFF2D_Unk40,           // 40 - syokika
	EFF2D_Unk41,           // 41 - file_cpm
	EFF2D_Unk42,           // 42 - file_cp
	EFF2D_Unk43,           // 43 - file_dlm
	EFF2D_Unk44,           // 44 - file_del
	EFF2D_MapRocketIn,     // 45 - rktin1
	EFF2D_MapAppear1,      // 46 - mapap1
	EFF2D_MapAppear2,      // 47 - mapap2
	EFF2D_MapRocketFire,   // 48 - z_ufoF
	EFF2D_MapRocketSmoke,  // 49 - z_ufoS
	EFF2D_MapOnyonSparkle, // 50 - z_ony
	EFF2D_MapShootingStar, // 51 - z_sstar
	EFF2D_COUNT,           // 52
};

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct EffectRegister2D {
	EffectRegister2D(particleLoader& loader, immut char* pcrFile, immut char* tex1File, immut char* tex2File)
	{
		mData = loader.load(pcrFile, true);
		mTex1 = gsys->loadTexture(tex1File, true);
		if (tex2File) {
			mTex2 = gsys->loadTexture(tex2File, true);
		} else {
			mTex2 = nullptr;
		}
	}

	particleGenerator* create(particleManager& mgr, immut Vector3f& pos, CallBack1<particleGenerator*>* cb1,
	                          CallBack2<particleGenerator*, particleMdl*>* cb2)
	{
		return mgr.createGenerator(mData, mTex1, mTex2, pos, cb1, cb2);
	}

	u8* mData;      // _00
	Texture* mTex1; // _04
	Texture* mTex2; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x4C4.
 */
struct EffectMgr2D {
	EffectMgr2D(int, int, int);

	particleGenerator* create(u32, immut Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
	                          zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*);
	void update();
	void draw(Graphics&);
	void killAll(bool);

	// unused/inlined:
	~EffectMgr2D();

	particleLoader mParticleLoader;          // _00
	particleManager mParticleManager;        // _10
	EffectRegister2D* mEffects[EFF2D_COUNT]; // _AC
	Camera mCamera;                          // _17C
};

} // namespace zen

#endif
