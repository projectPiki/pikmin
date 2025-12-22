#include "EffectMgr.h"
#include "Colour.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MemStat.h"
#include "gameflow.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(24)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("effectMgr")

PtclLoadInfo ptclLoadInfo[EffectMgr::EFF_COUNT] = {
	{ "effects/pcr/ore_rec.pcr", "effects/tex/star8_i.bti", nullptr },
	{ "effects/pcr/ore_nml.pcr", "effects/tex/fuchibal.bti", nullptr },
	{ "effects/pcr/ore_act.pcr", "effects/tex/fuchibal.bti", nullptr },
	{ "effects/pcr/ore_kira.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/nv_dmg_a.pcr", "effects/tex/hitstar.bti", nullptr },
	{ "effects/pcr/nv_dmg_b.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/nv_dmg_c.pcr", "effects/tex/biri1_s.bti", nullptr },
	{ "effects/pcr/nv_hit_a.pcr", "effects/tex/starx1f.bti", nullptr },
	{ "effects/pcr/nv_hit_b.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/nav_fue3.pcr", "effects/tex/ps_glow.bti", "effects/tex/ps_ball.bti" },
	{ "effects/pcr/nav_fue2.pcr", "effects/tex/fuchibal.bti", nullptr },
	{ "effects/pcr/nav_fue1.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/p_hamonc.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/p_hamonx.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/p_hamon.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/p_shibuki.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/nav_asi3.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/nav_asi2.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/nav_asi1.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/nav_asi0.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/g_curs00.pcr", "effects/tex/g_cursor.bti", nullptr },
	{ "effects/pcr/nav_lgt.pcr", "effects/tex/starx1b.bti", nullptr },
	{ "effects/pcr/nav_blur.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/bi_core3.pcr", "effects/tex/starx1f.bti", nullptr },
	{ "effects/pcr/bi_core4.pcr", "effects/tex/ringhalo.bti", nullptr },
	{ "effects/pcr/bi_hiba2.pcr", "effects/tex/starx1f.bti", nullptr },
	{ "effects/pcr/bi_kona2.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/chiru.pcr", "effects/tex/hanabira.bti", nullptr },
	{ "effects/pcr/chiru_s.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/pkpo.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/bi_core1.pcr", "effects/tex/starx1f.bti", nullptr },
	{ "effects/pcr/bi_core2.pcr", "effects/tex/ringhalo.bti", nullptr },
	{ "effects/pcr/bi_gro1.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/bi_kemu1.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/bi_hiba1.pcr", "effects/tex/starx1f.bti", nullptr },
	{ "effects/pcr/bi_kona1.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/pk_slime.pcr", "effects/tex/awaawa.bti", nullptr },
	{ "effects/pcr/pk_recov.pcr", "effects/tex/awaawa.bti", nullptr },
	{ "effects/pcr/pk_dead.pcr", "effects/tex/deadpiki.bti", "effects/tex/deadpiki.bti" },
	{ "effects/pcr/pk_work2.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/pk_fr_y.pcr", "effects/tex/ringhalo.bti", nullptr },
	{ "effects/pcr/pk_fr_r.pcr", "effects/tex/ringhalo.bti", nullptr },
	{ "effects/pcr/pk_fr_b.pcr", "effects/tex/ringhalo.bti", nullptr },
	{ "effects/pcr/pkf.pcr", "effects/tex/pkf.bti", nullptr },
	{ "effects/pcr/pkf2.pcr", "effects/tex/growup01.bti", nullptr },
	{ "effects/pcr/growup00.pcr", "effects/tex/growup00.bti", nullptr },
	{ "effects/pcr/growup01.pcr", "effects/tex/growup01.bti", nullptr },
	{ "effects/pcr/pk_hit_a.pcr", "effects/tex/starx1f.bti", nullptr },
	{ "effects/pcr/pk_hit_b.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/sd_kira.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/sd_rakk1.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/sd_rakk2.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/t_hamon.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/t_hamonx.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/t_hamonc.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/tbm_l_a.pcr", "effects/tex/ringwave.bti", nullptr },
	{ "effects/pcr/tbm_l_b.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/tbm_l_c.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/tbm_m_a.pcr", "effects/tex/ringwave.bti", nullptr },
	{ "effects/pcr/tbm_m_b.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/tbm_m_c.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/tbm_s_a.pcr", "effects/tex/ringwave.bti", nullptr },
	{ "effects/pcr/tbm_s_b.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/tbm_s_c.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/soul_b.pcr", "effects/tex/soulf3.bti", "effects/tex/soulf4.bti" },
	{ "effects/pcr/soul_m.pcr", "effects/tex/soulf3.bti", "effects/tex/soulf4.bti" },
	{ "effects/pcr/soul_s.pcr", "effects/tex/soulf3.bti", "effects/tex/soulf4.bti" },
	{ "effects/pcr/kemuri_m.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/kemuri_s.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/ptoe.pcr", "effects/tex/p_hsbs3.bti", nullptr },
	{ "effects/pcr/gpel_a_1.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/gpel_a_2.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/gpel_b.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/gpel_c.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/sl_dead_i.pcr", "effects/tex/p_hsbs.bti", nullptr },
	{ "effects/pcr/sl_dead_k.pcr", "effects/tex/p_hsbs.bti", nullptr },
	{ "effects/pcr/miu_atk.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/miua_a01.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/miua_a02.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/kb_kui_a.pcr", "effects/tex/woodchip.bti", nullptr },
	{ "effects/pcr/kb_kui_b.pcr", "effects/tex/woodchip.bti", nullptr },
	{ "effects/pcr/shib_fr2.pcr", "effects/tex/yodapota.bti", nullptr },
	{ "effects/pcr/shib_fr3.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/frg_miz2.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/frg_mizu.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/shib_fr.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/qpika.pcr", "effects/tex/qpika.bti", nullptr },
	{ "effects/pcr/kgp_kl.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/kgp_kr.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/kgp_ht.pcr", "effects/tex/hithit.bti", nullptr },
	{ "effects/pcr/runrock_tk.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/shl_bom.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/shell.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/col_ashi.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/col_hiki.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/col_st_a.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/col_st_b.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/col_hm_a.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/col_hm_b.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/tank_bc.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/tankfire.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/chp_hana.pcr", "effects/tex/awa1.bti", nullptr },
	{ "effects/pcr/kch_kem4.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kch_kem3.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kch_kira.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/kch_flk.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kch_jump.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kch_ed_a.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/kch_ed_b.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/kch_ed_c.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/kch_ed_d.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/kch_ed_e.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/kch_st_a.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/kch_st_b.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/kch_st_c.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/kch_st_d.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/kch_yo1a.pcr", "effects/tex/yodare.bti", nullptr },
	{ "effects/pcr/kch_yo1b.pcr", "effects/tex/yodare.bti", nullptr },
	{ "effects/pcr/kch_yo2.pcr", "effects/tex/yodare.bti", nullptr },
	{ "effects/pcr/kch_yopo.pcr", "effects/tex/yodapota.bti", nullptr },
	{ "effects/pcr/kch_kem2.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kch_kem1.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/tk_kmhk1.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/tk_kmhk2.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/tk_kmhks.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kch_haki.pcr", "effects/tex/yodare.bti", nullptr },
	{ "effects/pcr/tk_hbg_a.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/tk_hbg_b.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/tk_hbg_c.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/tk_hbg_d.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/hgs_dbm01.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/hgs_dbm03.pcr", "effects/tex/hane4.bti", nullptr },
	{ "effects/pcr/hgs_dbm04.pcr", "effects/tex/p_hsbs3.bti", nullptr },
	{ "effects/pcr/hgs_rbm01.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/hgs_rbm02.pcr", "effects/tex/p_hsbs3.bti", nullptr },
	{ "effects/pcr/hgs_rbm03.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/ovh_kwa.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/ovh_hd.pcr", "effects/tex/ringwave.bti", nullptr },
	{ "effects/pcr/ovh_hd2.pcr", "effects/tex/p_hsbs3.bti", nullptr },
	{ "effects/pcr/ovh_yuge.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/ovh_kken.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/kbt_eye.pcr", "effects/tex/qpika.bti", nullptr },
	{ "effects/pcr/kbsui3.pcr", "effects/tex/glow2_i.bti", nullptr },
	{ "effects/pcr/kbsui4.pcr", "effects/tex/hithit.bti", nullptr },
	{ "effects/pcr/at_rock1ok.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/at_rock2ok.pcr", "effects/tex/p_hsbs3.bti", nullptr },
	{ "effects/pcr/at_rock3ok.pcr", "effects/tex/rock_a.bti", nullptr },
	{ "effects/pcr/runrock_kb.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/k_dd01.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/k_dd02.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/n_k_cg.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/n_bafu_c.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/k_bafuc1.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/k_bafuc2.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/k_bafuh1.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/k_bafuh2.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/knk_eye.pcr", "effects/tex/qpika.bti", nullptr },
	{ "effects/pcr/dr_eye.pcr", "effects/tex/qpika.bti", nullptr },
	{ "effects/pcr/fw_uchi.pcr", "effects/tex/bomcross.bti", "effects/tex/ps_glow.bti" },
	{ "effects/pcr/fw_main.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/fw_kisek.pcr", "effects/tex/ps_ball.bti", "effects/tex/star4_i.bti" },
	{ "effects/pcr/fw_small.pcr", "effects/tex/p_hsbs_n.bti", "effects/tex/ps_glow.bti" },
	{ "effects/pcr/dr_deadh.pcr", "effects/tex/rct_hahe.bti", nullptr },
	{ "effects/pcr/dr_hoe_a.pcr", "effects/tex/biriri.bti", nullptr },
	{ "effects/pcr/dr_hoe_b.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/dr_hoe_c.pcr", "effects/tex/ringwave.bti", nullptr },
	{ "effects/pcr/dr_dead.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/dregg_c.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/dregg_d.pcr", "effects/tex/qpika.bti", nullptr },
	{ "effects/pcr/dregg_a.pcr", "effects/tex/rct_hahe.bti", nullptr },
	{ "effects/pcr/dregg_b.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/dr_bdy_a.pcr", "effects/tex/rct_hahe.bti", nullptr },
	{ "effects/pcr/dr_bdy_b.pcr", "effects/tex/glow2_i.bti", nullptr },
	{ "effects/pcr/dr_bdy_c.pcr", "effects/tex/rct_hahe.bti", nullptr },
	{ "effects/pcr/dr_bdy_d.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/dr_bdy_e.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/mar_brs1.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/mar_brs2.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/mar_brs3.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/mad.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/mad2.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/dg_aah1.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/dg_aak1.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/dg_hah1.pcr", "effects/tex/dg_hahe2.bti", nullptr },
	{ "effects/pcr/dg_kem1.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/dg_hah2.pcr", "effects/tex/dg_hahe2.bti", nullptr },
	{ "effects/pcr/dg_kem2.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/dg_hah2t.pcr", "effects/tex/dg_hahe2.bti", nullptr },
	{ "effects/pcr/dg_kem2t.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/dg_hib1.pcr", "effects/tex/ps_glow.bti", "effects/tex/ps_ball.bti" },
	{ "effects/pcr/dg_hib2.pcr", "effects/tex/ps_glow.bti", "effects/tex/ps_ball.bti" },
	{ "effects/pcr/dg_kem3.pcr", "effects/tex/ice_smok.bti", nullptr },
	{ "effects/pcr/dg_gel1.pcr", "effects/tex/dg_doro2.bti", nullptr },
	{ "effects/pcr/kk_choro.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/kk_yuge.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/kk_fk_a.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kk_fk_b.pcr", "effects/tex/mizukemu.bti", nullptr },
	{ "effects/pcr/kk_fk_c.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/nobibou1.pcr", "effects/tex/hasikemu.bti", nullptr },
	{ "effects/pcr/nobibou2.pcr", "effects/tex/hasikemu.bti", nullptr },
	{ "effects/pcr/weed.pcr", "effects/tex/weed.bti", nullptr },
	{ "effects/pcr/weed_r.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/weed_s.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/ony_a_yr.pcr", "effects/tex/fuchibal.bti", nullptr },
	{ "effects/pcr/ony_a_rr.pcr", "effects/tex/fuchibal.bti", nullptr },
	{ "effects/pcr/ony_a_br.pcr", "effects/tex/fuchibal.bti", nullptr },
	{ "effects/pcr/ony_ac_y.pcr", "effects/tex/ring_i4.bti", nullptr },
	{ "effects/pcr/ony_ac_r.pcr", "effects/tex/ring_i4.bti", nullptr },
	{ "effects/pcr/ony_ac_b.pcr", "effects/tex/ring_i4.bti", nullptr },
	{ "effects/pcr/wl_hit3.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/wl_hit2.pcr", "effects/tex/p_dust1.bti", nullptr },
	{ "effects/pcr/empl20.pcr", "effects/tex/star4_sp.bti", nullptr },
	{ "effects/pcr/empl10.pcr", "effects/tex/star4_sp.bti", nullptr },
	{ "effects/pcr/empl05.pcr", "effects/tex/star4_sp.bti", nullptr },
	{ "effects/pcr/empl01.pcr", "effects/tex/star4_sp.bti", nullptr },
	{ "effects/pcr/bridge.pcr", "effects/tex/hasikemu.bti", nullptr },
	{ "effects/pcr/ony_kira.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/ony_paf.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/stone_mv_f.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/stone_mv_s.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/wl_brk01.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/wl_brk00.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/wl_hit1.pcr", "effects/tex/p_dust1.bti", nullptr },
	{ "effects/pcr/wl_hit0.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/ef_omoi.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/goal_sui.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/goal_pom.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/z_hiba.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/rkt_opa1.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/kemuri_d.pcr", "effects/tex/kaen_ok.bti", nullptr },
	{ "effects/pcr/ss_light.pcr", "effects/tex/starx1b.bti", nullptr },
	{ "effects/pcr/mtotl01.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/mtotl03.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/rkt_land.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/mc_hiba.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/mc_hahen.pcr", "effects/tex/rock_a.bti", nullptr },
	{ "effects/pcr/ony_shbs.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/ony_shib.pcr", "effects/tex/mizutama.bti", nullptr },
	{ "effects/pcr/ony_ham1.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/ony_ham2.pcr", "effects/tex/hamon.bti", nullptr },
	{ "effects/pcr/r_cpl01.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/r_cpl02.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/r1meteor.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r3meteor.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/r4meteor.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/r5meteor.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/r6meteor.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r7meteor.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r7meteor.pcr", "effects/tex/p_hsbs_n.bti", nullptr },
	{ "effects/pcr/sct01.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/sct02.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/sct03.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/sct01c.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/sct02c.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/sct03c.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/sct01cc.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/sct02cc.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/sct03cc.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/sct00n.pcr", "effects/tex/ov_cloud.bti", "effects/tex/p_cloud05.bti" },
	{ "effects/pcr/jetg01.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/jetg02.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/jetg03.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/r_bst1da.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/r_bst1db.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/bstg.pcr", "effects/tex/ov_cloud.bti", nullptr },
	{ "effects/pcr/rkt_mk_b.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/rkt_mk_s.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/rkt_hiba.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/rkt_biri.pcr", "effects/tex/biriri.bti", nullptr },
	{ "effects/pcr/take_s.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/r_tbc1.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_tbf1.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_tbf2.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/be_bom_k.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/be_bom_p.pcr", "effects/tex/rct_hahe.bti", "effects/tex/hokori4.bti" },
	{ "effects/pcr/be_bom_h.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/be_bom_w.pcr", "effects/tex/ringwave.bti", nullptr },
	{ "effects/pcr/be_bom_c.pcr", "effects/tex/bomcross.bti", nullptr },
	{ "effects/pcr/wake_k1.pcr", "effects/tex/star5_03.bti", nullptr },
	{ "effects/pcr/wake_k2.pcr", "effects/tex/star5_03.bti", nullptr },
	{ "effects/pcr/wake_p1.pcr", "effects/tex/hibana2.bti", nullptr },
	{ "effects/pcr/wake_p2.pcr", "effects/tex/hibana2.bti", nullptr },
	{ "effects/pcr/r_bst1cb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_bst1fa.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_bst1fb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/pca1.pcr", "effects/tex/p_cloud05.bti", nullptr },
	{ "effects/pcr/pca2.pcr", "effects/tex/p_hsbs3.bti", nullptr },
	{ "effects/pcr/rct_gep.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/ony_st1.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/ony_st2.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/rct_bm1o.pcr", "effects/tex/ring_i4.bti", nullptr },
	{ "effects/pcr/rct_bm2o.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/asn01.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/asn02.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/kafun_b.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/kafun_bs.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/kafun_ng.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/f_light.pcr", "effects/tex/g_cursor.bti", nullptr },
	{ "effects/pcr/land_s.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/rkt_c.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/r_nj1ca.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1cb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fa.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1ca2.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1cb2.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fa2.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fb2.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1ca3.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1cb3.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fa3.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fb3.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1ca4.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1cb4.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fa4.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj1fb4.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj2ca.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj2cb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj2fa.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj2fb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj3ca.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj3cb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj3fa.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj3fb.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/r_nj3fb2.pcr", "effects/tex/kaen_2.bti", nullptr },
	{ "effects/pcr/pt_kira1.pcr", "effects/tex/star4_i.bti", nullptr },
	{ "effects/pcr/rct_bm1.pcr", "effects/tex/ring_i4.bti", nullptr },
	{ "effects/pcr/rct_bm2.pcr", "effects/tex/ps_ball.bti", nullptr },
	{ "effects/pcr/rct_sui.pcr", "effects/tex/ps_glow.bti", nullptr },
	{ "effects/pcr/rct_nke1.pcr", "effects/tex/iwa_1_32.bti", nullptr },
	{ "effects/pcr/rct_nke2.pcr", "effects/tex/hokori4.bti", nullptr },
	{ "effects/pcr/rct_fkm1.pcr", "effects/tex/hokori4.bti", nullptr },
};

GeometryLoadInfo geometryLoadInfo[EffectMgr::MOD_COUNT] = {
	{ "effects/shapes/b_goal.mod", nullptr, 0.1f, 0 },
	{ "effects/shapes/r_goal.mod", nullptr, 0.1f, 0 },
	{ "effects/shapes/y_goal.mod", nullptr, 0.1f, 0 },
};

SimplePtclLoadInfo simplePtclLoadInfo[EffectMgr::SIMPLE_COUNT] = {
	{ "effects/tex/hokori4.bti", { 149, 127, 70, 255 }, { 176, 104, 69, 255 } },
};

EffectMgr* effectMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	0001C0
 */
SmokeEmitter::SmokeEmitter(int count, Texture* tex)
{
	mTexture                = tex;
	mSmokeCount             = count;
	mSmokes                 = new Smoke[mSmokeCount];
	mActiveSmokeList        = new Smoke();
	mActiveSmokeList->mNext = mActiveSmokeList->mPrev = mActiveSmokeList;
	mInactiveSmokeList                                = new Smoke();
	mInactiveSmokeList->mNext = mInactiveSmokeList->mPrev = mInactiveSmokeList;

	for (int i = 0; i < mSmokeCount; i++) {
		mInactiveSmokeList->insertAfter(&mSmokes[i]);
	}
	mBlendMode = 1;
	mModel     = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
SmokeEmitter::Smoke* SmokeEmitter::emit(immut Vector3f& pos, immut Vector3f& vel)
{
	if (mInactiveSmokeList->mNext != mInactiveSmokeList) {
		Smoke* smoke     = mInactiveSmokeList->mNext;
		smoke->mVelocity = vel;
		smoke->mVelocity.x *= 0.85f;
		smoke->mVelocity.y *= 0.15f;
		smoke->mVelocity.y += 0.25f;
		smoke->mVelocity.z *= 0.85f;
		smoke->mLifeTimer    = 10.0f;
		smoke->mPosition     = pos;
		smoke->mSize         = 0.001f;
		smoke->mExpandRate   = 5.2f;
		smoke->mMaxSize      = 2.0f;
		smoke->mAlpha        = 0.75f;
		smoke->mAlphaIncRate = -0.85f;

		smoke->remove();
		mActiveSmokeList->insertAfter(smoke);
		return smoke;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void SmokeEmitter::update(f32 timeStep)
{
	Smoke* smoke;
	Smoke* next;
	for (smoke = mActiveSmokeList->mNext; smoke != mActiveSmokeList; smoke = next) {
		next = smoke->mNext;
		smoke->mLifeTimer -= timeStep;
		if (smoke->mLifeTimer <= 0.0f) {
			smoke->remove();
			mInactiveSmokeList->insertAfter(smoke);
			continue;
		}

		smoke->mVelocity.x *= 0.99f;
		smoke->mVelocity.y -= 0.125f;
		smoke->mVelocity.z *= 0.99f;

		smoke->mPosition.add(smoke->mVelocity);

		if (smoke->mPosition.y < 1.0f) {
			smoke->mPosition.y -= smoke->mVelocity.y;
			smoke->mVelocity.y = -smoke->mVelocity.y * 0.5f;
		}
		smoke->mSize += timeStep * smoke->mExpandRate;

		if (smoke->mSize > smoke->mMaxSize) {
			smoke->mSize = smoke->mMaxSize;

		} else if (smoke->mSize < 0.0f) {
			smoke->mSize      = 0.0f;
			smoke->mLifeTimer = 0.0f;
		}

		smoke->mAlpha += timeStep * smoke->mAlphaIncRate;
		if (smoke->mAlpha < 0.0f) {
			smoke->mAlpha     = 0.0f;
			smoke->mLifeTimer = 0.0f;
		}
	}
}

/**
 * @TODO: Documentation
 */
void SmokeEmitter::draw(Graphics& gfx)
{
	if (!mModel) {
		bool light = gfx.setLighting(false, nullptr);
		int blend  = gfx.setCBlending(mBlendMode);
		gfx.setDepth(false);

		Matrix4f mtx;
		gfx.calcViewMatrix(Matrix4f::ident, mtx);
		gfx.useMatrix(mtx, 0);
		gfx.useTexture(mTexture, GX_TEXMAP0);

		if (gfx.initParticle(true)) {
			for (Smoke* smoke = mActiveSmokeList->mNext; smoke != mActiveSmokeList; smoke = smoke->mNext) {
				if (mBlendMode == 0) {
					gfx.setColour(Colour(255, 255, 255, smoke->mAlpha * 255), true);
				} else {
					gfx.setColour(Colour(smoke->mAlpha * 255.0f, smoke->mAlpha * 255.0f, smoke->mAlpha * 255.0f, smoke->mAlpha * 255.0f),
					              true);
				}

				gfx.drawParticle(*gfx.mCamera, smoke->mPosition, 6.0f * smoke->mSize);
			}
		}

		gfx.setDepth(true);
		gfx.setCBlending(blend);
		gfx.setLighting(light, nullptr);
		return;
	}

	for (Smoke* smoke = mActiveSmokeList->mNext; smoke != mActiveSmokeList; smoke = smoke->mNext) {
		Matrix4f mtx1;
		Matrix4f mtx2;
		mtx1.makeSRT(Vector3f(smoke->mSize, smoke->mSize, smoke->mSize), Vector3f(0.0f, 0.0f, 0.0f), smoke->mPosition);
		gfx.calcViewMatrix(mtx1, mtx2);
		gfx.useMatrix(mtx2, 0);
		mModel->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
EffectParticleRegistration::EffectParticleRegistration(immut char* pcrFile, immut char* ptclTexFile, immut char* childPtclTexFile)
{
	mPtclData = effectMgr->mPtclLoader.load(pcrFile, true);
	mPtclTex  = gsys->loadTexture(ptclTexFile, true);
	if (!mPtclTex) {
		PRINT("Cannot open file. [%s]\n", ptclTexFile);
		ERROR("Cannot open file. [%s]\n", ptclTexFile);
	}

	if (childPtclTexFile) {
		mChildPtclTex = gsys->loadTexture(childPtclTexFile, true);
	} else {
		mChildPtclTex = nullptr;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void EffectShape::initShape(immut char* modelFile)
{
	mModel = gameflow.loadShape(modelFile, true);
	mModel->mSystemFlags |= ShapeFlags::AlwaysRedraw;
	mModel->makeInstance(mDynMats, 0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool EffectShape::update()
{
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void EffectShape::refresh(Graphics& gfx, Matrix4f& mtx, f32* p4)
{
	if (mModel->mCurrentAnimation->mData->mTotalFrameCount == 0) {
		p4 = nullptr;
	}
	mDynMats.animate(p4);
	mModel->updateAnim(gfx, mtx, p4);
	gfx.useMatrix(Matrix4f::ident, 0);
	mModel->drawshape(gfx, *gfx.mCamera, &mDynMats);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void EffShpInst::initEffShpInst()
{
	_3C          = 0.0f;
	mEffectShape = 0;
	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mSRT.r.set(0.0f, 0.0f, 0.0f);
	mSRT.t.set(0.0f, 0.0f, 0.0f);
	mLoop    = 0;
	mLoopMax = 0;
	visible();
}

/**
 * @TODO: Documentation
 */
bool EffShpInst::update()
{
	bool isDone = false;

	if (isVisible()) {
		if (mEffectShape->mModel->mCurrentAnimation->mData->mTotalFrameCount > 0) {
			_3C += 30.0f * gsys->getFrameTime();
			if (_3C > f32(mEffectShape->mModel->mCurrentAnimation->mData->mTotalFrameCount - 1)) {
				_3C -= f32(mEffectShape->mModel->mCurrentAnimation->mData->mTotalFrameCount);
				if (mLoopMax && ++mLoop >= mLoopMax) {
					isDone = true;
				}
			}

		} else {
			_3C += 30.0f * gsys->getFrameTime();
			if (_3C > 2.0f && mLoopMax && ++mLoop >= mLoopMax) {
				isDone = true;
			}
		}
	}

	return isDone;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void EffShpInst::draw(Graphics& gfx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;
	if (!isVisible()) {
		return;
	}

	mtx1.makeSRT(mSRT);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx1, mtx2);
	mEffectShape->refresh(gfx, mtx2, &_3C);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
EffectGeometryRegistration::EffectGeometryRegistration(immut char* modelFile, immut char* animFile, f32 scale, u8 loopMax)
{
	mEffectShape = new EffectShape(modelFile);
	if (mEffectShape) {
		if (animFile) {
			mEffectShape->mModel->loadAnimation(animFile, true);
		}
		effectMgr->mEffectShapeList.add(mEffectShape);
		mScale   = scale;
		mLoopMax = loopMax;
	} else {
		ERROR("Memory alloc error");
	}
}

/**
 * @TODO: Documentation
 */
EffShpInst* EffectGeometryRegistration::create(immut Vector3f& pos, immut Vector3f& scale, immut Vector3f& rot)
{
	EffShpInst* inst = effectMgr->getShapeInst();
	if (inst) {
		inst->initCore("");
		inst->mEffectShape = mEffectShape;
		inst->mSRT.s.set(mScale, mScale, mScale);
		inst->mSRT.s.x *= scale.x;
		inst->mSRT.s.y *= scale.y;
		inst->mSRT.s.z *= scale.z;

		inst->mSRT.r = rot;
		inst->mSRT.t = pos;

		inst->setLoop(0);
		inst->setLoopMax(mLoopMax);
		effectMgr->mActiveGeomList.add(inst);
	}

	return inst;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
EffectSimpleParticleRegistration::EffectSimpleParticleRegistration(immut char* texFile, Colour p2, Colour p3)
{
	mSimpleTex = gsys->loadTexture(texFile, true);
	mPrimColor = p2;
	mEnvColor  = p3;
	if (!mSimpleTex) {
		ERROR("NO TEX !  \n");
	}
}

/**
 * @TODO: Documentation
 */
EffectMgr::EffectMgr()
    : CoreNode("effectMgr")
{
	if (effectMgr) {
		PRINT("エフェクトマネージャが２度構築されています。逝ってよし\n"); // 'effects manager built twice. go away' lol
		ERROR("effectMgr is constructed twice\n");
	} else {
		effectMgr = this;
	}

	memStat->start("ptclMgr");
	mPtclMgr.init(0x200, 0x700, 0x400, zen::particleManager::DEFAULT_FRAME_RATE);
	memStat->end("ptclMgr");

	mEffectShapeList.initCore("");

	if (EFF_COUNT != EFF_COUNT) { // Bruh moment.
		PRINT("ptcl data is wrong. %d %d\n", EFF_COUNT, EFF_COUNT);
		ERROR("ptcl data is wrong.\n");
	}
	memStat->start("ptclRegist");
	int i;
	for (i = 0; i < EFF_COUNT; i++) {
		PtclLoadInfo* info = &ptclLoadInfo[i];
		mParticles[i]      = new EffectParticleRegistration(info->mPCRPath, info->mTex1Path, info->mTex2Path);
	}
	memStat->end("ptclRegist");

	memStat->start("modelRegist");
	for (i = 0; i < MOD_COUNT; i++) {
		GeometryLoadInfo* info = &geometryLoadInfo[i];
		mModels[i]             = new EffectGeometryRegistration(info->mMODPath, info->mAnimPath, info->mScale, info->mLoopMax);
	}
	memStat->end("modelRegist");

	memStat->start("simpleRegist");
	for (i = 0; i < SIMPLE_COUNT; i++) {
		SimplePtclLoadInfo* info = &simplePtclLoadInfo[i];
		mSimpleParticles[i]
		    = new EffectSimpleParticleRegistration(info->mBTIPath, Colour(info->_04.r, info->_04.g, info->_04.b, info->_04.a),
		                                           Colour(info->_08.r, info->_08.g, info->_08.b, info->_08.a));
	}
	memStat->end("simpleRegist");
	initEffectGeometry(16);
	cullingOn();

	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
void EffectMgr::initEffectGeometry(int effShpCount)
{
	mActiveGeomList.initCore("");
	for (int i = 0; i < effShpCount; i++) {
		mInactiveGeomList.add(new EffShpInst());
	}
}

/**
 * @TODO: Documentation
 */
void EffectMgr::update()
{
	mPtclMgr.update();
	EffShpInst* next;
	for (EffShpInst* inst = (EffShpInst*)mActiveGeomList.mChild; inst; inst = next) {
		next = (EffShpInst*)inst->mNext;
		if (inst->update()) {
			inst->del();
			mInactiveGeomList.add(inst);
		}
	}
}

/**
 * @TODO: Documentation
 */
void EffectMgr::draw(Graphics& gfx)
{
	if (mDoCulling) {
		mPtclMgr.cullingDraw(gfx);
	} else {
		mPtclMgr.draw(gfx);
	}
}

/**
 * @TODO: Documentation
 */
void EffectMgr::drawshapes(Graphics& gfx)
{
	for (EffShpInst* inst = (EffShpInst*)mActiveGeomList.mChild; inst; inst = (EffShpInst*)inst->mNext) {
		inst->draw(gfx);
	}
}

/**
 * @TODO: Documentation
 */
void EffectMgr::exit()
{
	mPtclMgr.killAllGenarator(true);
	effectMgr = nullptr;
}

/**
 * @TODO: Documentation
 */
zen::particleGenerator* EffectMgr::create(EffectMgr::effTypeTable effID, immut Vector3f& pos,
                                          zen::CallBack1<zen::particleGenerator*>* cbGen,
                                          zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cbPtcl)
{
	return mParticles[effID]->create(pos, cbGen, cbPtcl);
}

/**
 * @TODO: Documentation
 */
EffShpInst* EffectMgr::create(EffectMgr::modelTypeTable modID, immut Vector3f& pos, immut Vector3f& scale, immut Vector3f& rot)
{
	return mModels[modID]->create(pos, scale, rot);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
zen::particleMdl* EffectMgr::create(EffectMgr::simpleTypeTable simpleID, immut Vector3f& globalPos, s16 lifeTime, immut Vector3f& vel,
                                    immut Vector3f& accel, f32 size, f32 rotSpeed, zen::CallBack1<zen::particleMdl*>* cbPtcl)
{
	return mSimpleParticles[simpleID]->create(lifeTime, globalPos, vel, accel, size, rotSpeed, cbPtcl);
}

/**
 * @TODO: Documentation
 */
EffShpInst* EffectMgr::getShapeInst()
{
	EffShpInst* inst = (EffShpInst*)mInactiveGeomList.mChild;
	if (inst) {
		inst->del();
		inst->initEffShpInst();
	} else {
		PRINT("Shape effect buffer is empty." MISSING_NEWLINE);
	}

	return inst;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void EffectMgr::putShapeInst(EffShpInst* inst)
{
	inst->del();
	mInactiveGeomList.add(inst);
}

/**
 * @TODO: Documentation
 */
void EffectMgr::killAllShapes()
{
	EffShpInst* next;
	for (EffShpInst* inst = (EffShpInst*)mActiveGeomList.mChild; inst; inst = next) {
		next = (EffShpInst*)inst->mNext;
		inst->del();
		mInactiveGeomList.add(inst);
	}
}
