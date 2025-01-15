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
	 *
	 * Please rename these as they get used, using the code in combo with:
	 * https://pikmintkb.com/wiki/PCR_particles
	 *
	 * Names for the moment are based on code if possible, otherwise file name
	 */
	enum effTypeTable {
		EFF_NULL                        = -1,  // invalid effect ID
		EFF_Rocket_NaviRecover          = 0,   // ore_rec.pcr
		EFF_Rocket_NaviNormalRings      = 1,   // ore_nml.pcr
		EFF_Rocket_NaviActionRings      = 2,   // ore_act.pcr
		EFF_Rocket_NaviSparkle          = 3,   // ore_kira.pcr
		EFF_Navi_DamageA                = 4,   // nv_dmg_a.pcr
		EFF_Navi_DamageB                = 5,   // nv_dmg_b.pcr
		EFF_Navi_DamageC                = 6,   // nv_dmg_c.pcr
		EFF_Navi_PunchA                 = 7,   // nv_hit_a.pcr
		EFF_Navi_PunchB                 = 8,   // nv_hit_b.pcr
		EFF_Navi_Whistle3               = 9,   // nav_fue3.pcr
		EFF_Navi_Whistle2               = 10,  // nav_fue2.pcr
		EFF_Navi_Whistle1               = 11,  // nav_fue1.pcr
		EFF_RippleSurface               = 12,  // p_hamonc.pcr
		EFF_RippleBlack                 = 13,  // p_hamonx.pcr
		EFF_RippleWhite                 = 14,  // p_hamon.pcr
		EFF_P_Bubbles                   = 15,  // p_shibuki.pcr
		EFF_Kogane_Walk3                = 16,  // nav_asi3.pcr
		EFF_Kogane_Walk2                = 17,  // nav_asi2.pcr
		EFF_Kogane_Walk1                = 18,  // nav_asi1.pcr
		EFF_Kogane_Walk0                = 19,  // nav_asi0.pcr
		EFF_Navi_WhistleCursor          = 20,  // g_curs00.pcr
		EFF_Navi_Light                  = 21,  // nav_lgt.pcr
		EFF_Navi_LightGlow              = 22,  // nav_blur.pcr
		EFF_BombLight_Bang              = 23,  // bi_core3.pcr
		EFF_BombLight_Wave              = 24,  // bi_core4.pcr
		EFF_BombLight_FireBang          = 25,  // bi_hiba2.pcr
		EFF_BombLight_FireGlow          = 26,  // bi_kona2.pcr
		EFF_Piki_DeflowerPetals         = 27,  // chiru.pcr
		EFF_Piki_DeflowerSpores         = 28,  // chiru_s.pcr
		EFF_Piki_FireRecover            = 29,  // pkpo.pcr
		EFF_Bomb_Bang                   = 30,  // bi_core1.pcr
		EFF_Bomb_Wave                   = 31,  // bi_core2.pcr
		EFF_Bomb_Glow                   = 32,  // bi_gro1.pcr
		EFF_Bomb_DustRing               = 33,  // bi_kemu1.pcr
		EFF_Bomb_FireBang               = 34,  // bi_hiba1.pcr
		EFF_Bomb_FireGlow               = 35,  // bi_kona1.pcr
		EFF_Piki_Bubble                 = 36,  // pk_slime.pcr
		EFF_Piki_BubbleRecover          = 37,  // pk_recov.pcr
		EFF_Piki_DeadSoul               = 38,  // pk_dead.pcr
		EFF_Piki_WorkCloud              = 39,  // pk_work2.pcr
		EFF_Piki_IdleYellow             = 40,  // pk_fr_y.pcr
		EFF_Piki_IdleRed                = 41,  // pk_fr_r.pcr
		EFF_Piki_IdleBlue               = 42,  // pk_fr_b.pcr
		EFF_Piki_Fire                   = 43,  // pkf.pcr
		EFF_Piki_FireSparkles           = 44,  // pkf2.pcr
		EFF_Piki_GrowUp1                = 45,  // growup00.pcr
		EFF_Piki_GrowUp2                = 46,  // growup01.pcr
		EFF_Piki_HitA                   = 47,  // pk_hit_a.pcr
		EFF_Piki_HitB                   = 48,  // pk_hit_b.pcr
		EFF_SD_Sparkle                  = 49,  // sd_kira.pcr
		EFF_SD_DirtCloud                = 50,  // sd_rakk1.pcr
		EFF_SD_DirtSpray                = 51,  // sd_rakk2.pcr
		EFF_RippleWhite2                = 52,  // t_hamon.pcr
		EFF_RippleBlack2                = 53,  // t_hamonx.pcr
		EFF_RippleSurface2              = 54,  // t_hamonc.pcr
		EFF_Teki_DeathWaveL             = 55,  // tbm_l_a.pcr
		EFF_Teki_DeathGlowL             = 56,  // tbm_l_b.pcr
		EFF_Teki_DeathSmokeL            = 57,  // tbm_l_c.pcr
		EFF_Teki_DeathWaveM             = 58,  // tbm_m_a.pcr
		EFF_Teki_DeathGlowM             = 59,  // tbm_m_b.pcr
		EFF_Teki_DeathSmokeM            = 60,  // tbm_m_c.pcr
		EFF_Teki_DeathWaveS             = 61,  // tbm_s_a.pcr
		EFF_Teki_DeathGlowS             = 62,  // tbm_s_b.pcr
		EFF_Teki_DeathSmokeS            = 63,  // tbm_s_c.pcr
		EFF_Teki_SoulL                  = 64,  // soul_b.pcr
		EFF_Teki_SoulM                  = 65,  // soul_m.pcr
		EFF_Teki_SoulS                  = 66,  // soul_s.pcr
		EFF_SmokeRing_M                 = 67,  // kemuri_m.pcr
		EFF_SmokeRing_S                 = 68,  // kemuri_s.pcr
		EFF_Piki_BigHit                 = 69,  // ptoe.pcr
		EFF_GrowPellet_A1               = 70,  // gpel_a_1.pcr
		EFF_GrowPellet_A2               = 71,  // gpel_a_2.pcr
		EFF_GrowPellet_B                = 72,  // gpel_b.pcr
		EFF_GrowPellet_C                = 73,  // gpel_c.pcr
		EFF_Slime_DeadI                 = 74,  // sl_dead_i.pcr
		EFF_Slime_DeadK                 = 75,  // sl_dead_k.pcr
		EFF_Miurin_Attack               = 76,  // miu_atk.pcr
		EFF_Miurin_A01                  = 77,  // miua_a01.pcr
		EFF_Miurin_A02                  = 78,  // miua_a02.pcr
		EFF_Kabekui_EatBridgeA          = 79,  // kb_kui_a.pcr
		EFF_Kabekui_EatBridgeB          = 80,  // kb_kui_b.pcr
		EFF_Frog_BubbleRingL            = 81,  // shib_fr2.pcr
		EFF_Frog_Bubble2                = 82,  // shib_fr3.pcr
		EFF_Frog_Water1                 = 83,  // frg_miz2.pcr
		EFF_Frog_Water2                 = 84,  // frg_mizu.pcr
		EFF_Frog_BubbleRingS            = 85,  // shib_fr.pcr
		EFF_Mizinko_Spawn               = 86,  // qpika.pcr (q = qurione)
		EFF_Kogane_SmokeL               = 87,  // kgp_kl.pcr
		EFF_Kogane_SmokeR               = 88,  // kgp_kr.pcr
		EFF_Kogane_Hit                  = 89,  // kgp_ht.pcr
		EFF_Iwagon_Start1               = 90,  // runrock_tk.pcr
		EFF_Shell_Boom                  = 91,  // shl_bom.pcr (unused?)
		EFF_Shell_Twinkle               = 92,  // shell.pcr
		EFF_Collec_Ashi                 = 93,  // col_ashi.pcr
		EFF_Collec_Hiki                 = 94,  // col_hiki.pcr
		EFF_Collec_StA                  = 95,  // col_st_a.pcr
		EFF_Collec_StB                  = 96,  // col_st_b.pcr
		EFF_Collec_HmA                  = 97,  // col_hm_a.pcr
		EFF_Collec_HmB                  = 98,  // col_hm_b.pcr
		EFF_Tank_Smoke                  = 99,  // tank_bc.pcr
		EFF_Tank_Fire                   = 100, // tankfire.pcr
		EFF_Chappy_SnoreBubble          = 101, // chp_hana.pcr
		EFF_King_Slip                   = 102, // kch_kem4.pcr
		EFF_King_StepCloud              = 103, // kch_kem3.pcr
		EFF_King_SeedFlash              = 104, // kch_kira.pcr
		EFF_King_Flick                  = 105, // kch_flk.pcr
		EFF_King_Jump                   = 106, // kch_jump.pcr
		EFF_King_DeadA                  = 107, // kch_ed_a.pcr
		EFF_King_DeadB                  = 108, // kch_ed_b.pcr
		EFF_King_DeadC                  = 109, // kch_ed_c.pcr
		EFF_King_DeadD                  = 110, // kch_ed_d.pcr
		EFF_King_DeadE                  = 111, // kch_ed_e.pcr
		EFF_King_AppearA                = 112, // kch_st_a.pcr
		EFF_King_AppearB                = 113, // kch_st_b.pcr
		EFF_King_AppearC                = 114, // kch_st_c.pcr
		EFF_King_AppearD                = 115, // kch_st_d.pcr
		EFF_King_Saliva1A               = 116, // kch_yo1a.pcr
		EFF_King_Saliva1B               = 117, // kch_yo1b.pcr
		EFF_King_Saliva2                = 118, // kch_yo2.pcr
		EFF_King_SalivaDroplet          = 119, // kch_yopo.pcr
		EFF_CloudOfDust_2               = 120, // kch_kem2.pcr
		EFF_CloudOfDust_1               = 121, // kch_kem1.pcr
		EFF_King_EatBomb1               = 122, // tk_kmhk1.pcr
		EFF_King_EatBomb2               = 123, // tk_kmhk2.pcr
		EFF_King_EatBomb3               = 124, // tk_kmhks.pcr
		EFF_King_SpitParts              = 125, // kch_haki.pcr
		EFF_Snake_Appear1               = 126, // tk_hbg_a.pcr (hbg = hebi something)
		EFF_Snake_Appear2               = 127, // tk_hbg_b.pcr
		EFF_Snake_OnGround              = 128, // tk_hbg_c.pcr
		EFF_Snake_Rotate                = 129, // tk_hbg_d.pcr
		EFF_Snake_DeadHeadCloud         = 130, // hgs_dbm01.pcr
		EFF_Snake_DeadHeadFeathers      = 131, // hgs_dbm03.pcr
		EFF_Snake_DeadHeadSpecks        = 132, // hgs_dbm04.pcr
		EFF_Snake_DeadBody1             = 133, // hgs_rbm01.pcr
		EFF_Snake_DeadBodyExplode       = 134, // hgs_rbm02.pcr
		EFF_Snake_DeadBody2             = 135, // hgs_rbm03.pcr
		EFF_Beatle_Flick1               = 136, // ovh_kwa.pcr
		EFF_Beatle_ShootRockHalo        = 137, // ovh_hd.pcr
		EFF_Beatle_ShootRockSpecks      = 138, // ovh_hd2.pcr
		EFF_Beatle_Flick2               = 139, // ovh_yuge.pcr
		EFF_Beatle_Flick3               = 140, // ovh_kken.pcr
		EFF_Beatle_EyeGlow              = 141, // kbt_eye.pcr
		EFF_Beatle_SuckAir1             = 142, // kbsui3.pcr
		EFF_Beatle_SuckAir2             = 143, // kbsui4.pcr
		EFF_Beatle_RockClouds           = 144, // at_rock1ok.pcr
		EFF_Beatle_RockSpray            = 145, // at_rock2ok.pcr
		EFF_Beatle_RockBlast            = 146, // at_rock3ok.pcr
		EFF_Iwagon_Start2               = 147, // runrock_kb.pcr
		EFF_Kinoko_DeathSpores          = 148, // k_dd01.pcr
		EFF_Kinoko_DeathSmoke           = 149, // k_dd02.pcr
		EFF_Kinoko_ChargeSpores         = 150, // n_k_cg.pcr
		EFF_Kinoko_SporesUp             = 151, // n_bafu_c.pcr
		EFF_Kinoko_AttackCloud          = 152, // k_bafuc1.pcr
		EFF_Kinoko_PostAttackCloud      = 153, // k_bafuc2.pcr
		EFF_Kinoko_AttackSpores         = 154, // k_bafuh1.pcr
		EFF_Kinoko_PostAttackSpores     = 155, // k_bafuh2.pcr
		EFF_Kinoko_EyeGlow              = 156, // knk_eye.pcr
		EFF_Dororo_Eye                  = 157, // dr_eye.pcr
		EFF_Onyon_FireworkTrail         = 158, // fw_uchi.pcr
		EFF_Onyon_FireworkMain          = 159, // fw_main.pcr
		EFF_Onyon_FireworkKisek         = 160, // fw_kisek.pcr
		EFF_Onyon_FireworkSmall         = 161, // fw_small.pcr
		EFF_Dororo_DeadFragments        = 162, // dr_deadh.pcr
		EFF_Dororo_HowlZigZags          = 163, // dr_hoe_a.pcr
		EFF_Dororo_HowlRipples          = 164, // dr_hoe_b.pcr
		EFF_Dororo_HowlHalo             = 165, // dr_hoe_c.pcr
		EFF_Dororo_DeadFumes            = 166, // dr_dead.pcr
		EFF_Tamago_DeadFumes            = 167, // dregg_c.pcr
		EFF_Tamago_EyeGlow              = 168, // dregg_d.pcr
		EFF_Tamago_DeadFragments        = 169, // dregg_a.pcr
		EFF_Tamago_DeadSmoke            = 170, // dregg_b.pcr
		EFF_Dororo_BodyFragments        = 171, // dr_bdy_a.pcr
		EFF_Dororo_BodySpecks           = 172, // dr_bdy_b.pcr
		EFF_Dororo_BodyTrail            = 173, // dr_bdy_c.pcr
		EFF_Dororo_BodyGlow             = 174, // dr_bdy_d.pcr
		EFF_Dororo_BodySmoke            = 175, // dr_bdy_e.pcr
		EFF_Mar_WindJet                 = 176, // mar_brs1.pcr
		EFF_Mar_WindSpray               = 177, // mar_brs2.pcr
		EFF_Mar_WindDust                = 178, // mar_brs3.pcr
		EFF_Mar_DeadSmoke               = 179, // mad.pcr
		EFF_Mar_DeadJet                 = 180, // mad2.pcr
		EFF_Spider_OffGroundDebris      = 181, // dg_aah1.pcr
		EFF_Spider_OffGroundSmoke       = 182, // dg_aak1.pcr
		EFF_Spider_HalfDeadFall         = 183, // dg_hah1.pcr
		EFF_Spider_HalfDead             = 184, // dg_kem1.pcr
		EFF_Spider_DeadBombDebris       = 185, // dg_hah2.pcr
		EFF_Spider_DeadBombSmoke        = 186, // dg_kem2.pcr
		EFF_Spider_UnusedDeadBombDebris = 187, // dg_hah2t.pcr
		EFF_Spider_UnusedDeadBombSmoke  = 188, // dg_kem2t.pcr
		EFF_Spider_DeadBombSparks       = 189, // dg_hib1.pcr
		EFF_Spider_SmallSparks          = 190, // dg_hib2.pcr
		EFF_Spider_PerishSmoke          = 191, // dg_kem3.pcr
		EFF_Spider_PerishBubbles        = 192, // dg_gel1.pcr
		EFF_Mizu_IdleBubbles            = 193, // kk_choro.pcr
		EFF_Mizu_IdleMist               = 194, // kk_yuge.pcr
		EFF_Mizu_JetStream              = 195, // kk_fk_a.pcr
		EFF_Mizu_JetPuff                = 196, // kk_fk_b.pcr
		EFF_Mizu_JetMist                = 197, // kk_fk_c.pcr
		EFF_Kusa_Extend1                = 198, // nobibou1.pcr
		EFF_Kusa_Extend2                = 199, // nobibou2.pcr
		EFF_Weed_Pull                   = 200, // weed.pcr
		EFF_Weed_Rocks                  = 201, // weed_r.pcr
		EFF_Weed_Smoke                  = 202, // weed_s.pcr
		EFF_Onyon_HaloRingYellow        = 203, // ony_a_yr.pcr
		EFF_Onyon_HaloRingRed           = 204, // ony_a_rr.pcr
		EFF_Onyon_HaloRingBlue          = 205, // ony_a_br.pcr
		EFF_Onyon_BeaconRingYellow      = 206, // ony_ac_y.pcr
		EFF_Onyon_BeaconRingRed         = 207, // ony_ac_r.pcr
		EFF_Onyon_BeaconRingBlue        = 208, // ony_ac_b.pcr
		EFF_WL_Hit3                     = 209, // wl_hit3.pcr
		EFF_WL_Hit2                     = 210, // wl_hit2.pcr
		EFF_Empl_20                     = 211, // empl20.pcr
		EFF_Empl_10                     = 212, // empl10.pcr
		EFF_Empl_05                     = 213, // empl05.pcr
		EFF_Empl_01                     = 214, // empl01.pcr
		EFF_Bridge_FinishStage          = 215, // bridge.pcr
		EFF_Onyon_Sparkles              = 216, // ony_kira.pcr
		EFF_Onyon_Puff                  = 217, // ony_paf.pcr
		EFF_HinderRock_MoveF            = 218, // stone_mv_f.pcr
		EFF_HinderRock_MoveS            = 219, // stone_mv_s.pcr
		EFF_Wl_Brk01                    = 220, // wl_brk01.pcr
		EFF_Wl_Brk00                    = 221, // wl_brk00.pcr
		EFF_Wl_Hit1                     = 222, // wl_hit1.pcr
		EFF_Wl_Hit0                     = 223, // wl_hit0.pcr
		EFF_BigDustRing                 = 224, // ef_omoi.pcr
		EFF_Onyon_Suck                  = 225, // goal_sui.pcr
		EFF_Onyon_ActEffect             = 226, // goal_pom.pcr
		EFF_Hiba_Fire                   = 227, // z_hiba.pcr
		EFF_Rocket_Opa1                 = 228, // rkt_opa1.pcr
		EFF_Rocket_SmokeD               = 229, // kemuri_d.pcr
		EFF_Rocket_SSLight              = 230, // ss_light.pcr
		EFF_MTotl01                     = 231, // mtotl01.pcr
		EFF_MTotl03                     = 232, // mtotl03.pcr
		EFF_Rocket_Land                 = 233, // rkt_land.pcr
		EFF_MC_Bang                     = 234, // mc_hiba.pcr
		EFF_MC_Debris                   = 235, // mc_hahen.pcr
		EFF_Onyon_BubblesSmall          = 236, // ony_shbs.pcr
		EFF_Onyon_Bubbles               = 237, // ony_shib.pcr
		EFF_Onyon_Ripples1              = 238, // ony_ham1.pcr
		EFF_Onyon_Ripples2              = 239, // ony_ham2.pcr
		EFF_Rocket_Complete1            = 240, // r_cpl01.pcr
		EFF_Rocket_Complete2            = 241, // r_cpl02.pcr
		EFF_Rocket_1Meteor              = 242, // r1meteor.pcr
		EFF_Rocket_3Meteor              = 243, // r3meteor.pcr
		EFF_Rocket_4Meteor              = 244, // r4meteor.pcr
		EFF_Rocket_5Meteor              = 245, // r5meteor.pcr
		EFF_Rocket_6Meteor              = 246, // r6meteor.pcr
		EFF_Rocket_7Meteor              = 247, // r7meteor.pcr
		EFF_Rocket_SCT01                = 248, // sct01.pcr
		EFF_Rocket_SCT02                = 249, // sct02.pcr
		EFF_Rocket_SCT03                = 250, // sct03.pcr
		EFF_Rocket_SCT01C               = 251, // sct01c.pcr
		EFF_Rocket_SCT02C               = 252, // sct02c.pcr
		EFF_Rocket_SCT01CC              = 254, // sct01cc.pcr
		EFF_Rocket_SCT03C               = 253, // sct03c.pcr
		EFF_Rocket_SCT02CC              = 255, // sct02cc.pcr
		EFF_Rocket_SCT03CC              = 256, // sct03cc.pcr
		EFF_Rocket_SCT00N               = 257, // sct00n.pcr
		EFF_Rocket_JetG01               = 258, // jetg01.pcr
		EFF_Rocket_JetG02               = 259, // jetg02.pcr
		EFF_Rocket_JetG03               = 260, // jetg03.pcr
		EFF_Rocket_Bst1da               = 261, // r_bst1da.pcr
		EFF_Rocket_Bst1db               = 262, // r_bst1db.pcr
		EFF_Rocket_Bstg                 = 263, // bstg.pcr
		EFF_Rocket_MkB                  = 264, // rkt_mk_b.pcr
		EFF_Rocket_MkS                  = 265, // rkt_mk_s.pcr
		EFF_Rocket_Hiba                 = 266, // rkt_hiba.pcr
		EFF_Rocket_Biri                 = 267, // rkt_biri.pcr
		EFF_Rocket_TakeS                = 268, // take_s.pcr
		EFF_Rocket_Tbc1                 = 269, // r_tbc1.pcr
		EFF_Rocket_Tbf1                 = 270, // r_tbf1.pcr
		EFF_Rocket_Tbf2                 = 271, // r_tbf2.pcr
		EFF_Rocket_BeBomK               = 272, // be_bom_k.pcr
		EFF_Rocket_BeBomP               = 273, // be_bom_p.pcr
		EFF_Rocket_BeBomH               = 274, // be_bom_h.pcr
		EFF_Rocket_BeBomW               = 275, // be_bom_w.pcr
		EFF_Rocket_BeBomC               = 276, // be_bom_c.pcr
		EFF_Rocket_WakeK1               = 277, // wake_k1.pcr
		EFF_Rocket_WakeK2               = 278, // wake_k2.pcr
		EFF_Rocket_WakeP1               = 279, // wake_p1.pcr
		EFF_Rocket_WakeP2               = 280, // wake_p2.pcr
		EFF_Rocket_Bst1cb               = 281, // r_bst1cb.pcr
		EFF_Rocket_Bst1fa               = 282, // r_bst1fa.pcr
		EFF_Rocket_Bst1fb               = 283, // r_bst1fb.pcr
		EFF_Rocket_PCA1                 = 284, // pca1.pcr
		EFF_Rocket_PCA2                 = 285, // pca2.pcr
		EFF_Rocket_Gep                  = 286, // rct_gep.pcr
		EFF_Rocket_Suck1                = 287, // ony_st1.pcr
		EFF_Onyon_Suck2                 = 288, // ony_st2.pcr
		EFF_Rocket_Bm1o                 = 289, // rct_bm1o.pcr
		EFF_Rocket_Bm2o                 = 290, // rct_bm2o.pcr
		EFF_UfoPart_ASN01               = 291, // asn01.pcr
		EFF_UfoPart_ASN02               = 292, // asn02.pcr
		EFF_UfoPart_KafunB              = 293, // kafun_b.pcr
		EFF_Kafun_BS                    = 294, // kafun_bs.pcr
		EFF_Kafun_NG                    = 295, // kafun_ng.pcr
		EFF_Rocket_FlowLight            = 296, // f_light.pcr
		EFF_Rocket_LandS                = 297, // land_s.pcr
		EFF_Rocket_C                    = 298, // rkt_c.pcr
		EFF_Rocket_NJ1CA                = 299, // r_nj1ca.pcr
		EFF_Rocket_NJ1CB                = 300, // r_nj1cb.pcr
		EFF_Rocket_NJ1FA                = 301, // r_nj1fa.pcr
		EFF_Rocket_NJ1FB                = 302, // r_nj1fb.pcr
		EFF_Rocket_NJ1CA2               = 303, // r_nj1ca2.pcr
		EFF_Rocket_NJ1CB2               = 304, // r_nj1cb2.pcr
		EFF_Rocket_NJ1FA2               = 305, // r_nj1fa2.pcr
		EFF_Rocket_NJ1FB2               = 306, // r_nj1fb2.pcr
		EFF_Rocket_NJ1CA3               = 307, // r_nj1ca3.pcr
		EFF_Rocket_NJ1CB3               = 308, // r_nj1cb3.pcr
		EFF_Rocket_NJ1FA3               = 309, // r_nj1fa3.pcr
		EFF_Rocket_NJ1FB3               = 310, // r_nj1fb3.pcr
		EFF_Rocket_NJ1CA4               = 311, // r_nj1ca4.pcr
		EFF_Rocket_NJ1CB4               = 312, // r_nj1cb4.pcr
		EFF_Rocket_NJ1FA4               = 313, // r_nj1fa4.pcr
		EFF_Rocket_NJ1FB4               = 314, // r_nj1fb4.pcr
		EFF_Rocket_NJ2CA                = 315, // r_nj2ca.pcr
		EFF_Rocket_NJ2CB                = 316, // r_nj2cb.pcr
		EFF_Rocket_NJ2FA                = 317, // r_nj2fa.pcr
		EFF_Rocket_NJ2FB                = 318, // r_nj2fa.pcr
		EFF_Rocket_NJ3CA                = 319, // r_nj3ca.pcr
		EFF_Rocket_NJ3CB                = 320, // r_nj3ca.pcr
		EFF_Rocket_NJ3FA                = 321, // r_nj3fa.pcr
		EFF_Rocket_NJ3FB                = 322, // r_nj3fa.pcr
		EFF_Rocket_NJ3FB2               = 323, // r_nj3fb2.pcr
		EFF_Rocket_Sparkles1            = 324, // pt_kira1.pcr
		EFF_Rocket_Bm1                  = 325, // rct_bm1.pcr
		EFF_Rocket_Bm2                  = 326, // rct_bm2.pcr
		EFF_Rocket_Suck2                = 327, // rct_sui.pcr
		EFF_Rocket_Nke1                 = 328, // rct_nke1.pcr
		EFF_Rocket_Nke2                 = 329, // rct_nke2.pcr
		EFF_Rocket_Fkm1                 = 330, // rct_fkm1.pcr
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
	u8 _18[0x600];                 // _18
};

extern EffectMgr* effectMgr;

#endif
