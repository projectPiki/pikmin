#include "types.h"

static char file[] = __FILE__;
static char name[] = "OgTutorialSection";

namespace zen {

static char* bloFile_Mezame[3] = { "screen/blo/tu_tx00.blo", "screen/blo/tu_tx01.blo", "END" };

static char* bloFile_Oniyon[2] = { "screen/blo/tu_tx03.blo", "END" };

static char* bloFile_FoundPikmin[2] = { "screen/blo/tu_tx04.blo", "END" };

static char* bloFile_PullHint[2] = { "screen/blo/tu_tx05.blo", "END" };

static char* bloFile_GetPikmin[4] = { "screen/blo/tu_tx06.blo", "screen/blo/tu_tx07.blo", "screen/blo/tu_tx08.blo", "END" };

static char* bloFile_ControlHint[2] = { "screen/blo/tu_tx09.blo", "END" };

static char* bloFile_Pelette[2] = { "screen/blo/tu_tx10.blo", "END" };

static char* bloFile_StoneHint2[3] = { "screen/blo/tu_tx11.blo", "screen/blo/tu_tx12.blo", "END" };

static char* bloFile_FoundEngine[2] = { "screen/blo/tu_tx14.blo", "END" };

static char* bloFile_GetEngine[2] = { "screen/blo/tu_tx15.blo", "END" };

static char* bloFile_RirikuDemo[2] = { "screen/blo/tu_tx16.blo", "END" };

static char* bloFile_Camera[2] = { "screen/blo/tu_tx08.blo", "END" };

static char* bloFile_OnyonInOut[2] = { "screen/blo/tu_tx19.blo", "END" };

static char* bloFile_Zenmetu[2] = { "screen/blo/tu_tx20.blo", "END" };

static char* bloFile_YellowPikmin[2] = { "screen/blo/tu_tx21.blo", "END" };

static char* bloFile_BluePikmin[2] = { "screen/blo/tu_tx22.blo", "END" };

static char* bloFile_FoundBomb[2] = { "screen/blo/tu_tx23.blo", "END" };

static char* bloFile_GetParts[2] = { "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PowerUp[2] = { "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_DayEnd[2] = { "screen/blo/tu_tx26.blo", "END" };

static char* bloFile_BombInfo[3] = { "screen/blo/tu_tx27_00.blo", "screen/blo/tu_tx27_01.blo", "END" };

static char* bloFile_Limit100[2] = { "screen/blo/tu_tx28.blo", "END" };

static char* bloFile_Mitu[2] = { "screen/blo/tu_tx29.blo", "END" };

static char* bloFile_Rute[2] = { "screen/blo/tu_tx30.blo", "END" };

static char* bloFile_APunchUFO[2] = { "screen/blo/tu_tx31.blo", "END" };

static char* bloFile_LifeUp[2] = { "screen/blo/tu_tx32.blo", "END" };

static char* bloFile_HitUFO[2] = { "screen/blo/tu_tx33.blo", "END" };

static char* bloFile_FinishUFO[2] = { "screen/blo/tu_tx34.blo", "END" };

static char* bloFile_BadEnding[2] = { "screen/blo/tu_tx35.blo", "END" };

static char* bloFile_HappyEnding[2] = { "screen/blo/tu_tx36.blo", "END" };

static char* bloFile_NukiAndFree[3] = { "screen/blo/tu_tx38_00.blo", "screen/blo/tu_tx38_01.blo", "END" };

static char* bloFile_InfoDisplay[4] = { "screen/blo/tu_tx37_00.blo", "screen/blo/tu_tx37_01.blo", "screen/blo/tu_tx37_02.blo", "END" };

static char* bloFile_PartsGetOnly_ust1[2] = { "screen/blo/ufo_a_0.blo", "END" };

static char* bloFile_PartsGetOnly_ust2[2] = { "screen/blo/ufo_b_0.blo", "END" };

static char* bloFile_PartsGetOnly_ust3[2] = { "screen/blo/ufo_c_0.blo", "END" };

static char* bloFile_PartsGetOnly_ust4[2] = { "screen/blo/ufo_d_0.blo", "END" };

static char* bloFile_PartsGetOnly_ust5[2] = { "screen/blo/tu_tx14.blo", "END" };

static char* bloFile_PartsGetOnly_uf01[2] = { "screen/blo/ufo_e_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf02[2] = { "screen/blo/ufo_f_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf03[2] = { "screen/blo/ufo_g_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf04[2] = { "screen/blo/ufo_h_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf05[2] = { "screen/blo/ufo_i_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf06[2] = { "screen/blo/ufo_j_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf07[2] = { "screen/blo/ufo_k_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf08[2] = { "screen/blo/ufo_l_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf09[2] = { "screen/blo/ufo_m_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf10[2] = { "screen/blo/ufo_n_0.blo", "END" };

static char* bloFile_PartsGetOnly_uf11[2] = { "screen/blo/ufo_o_0.blo", "END" };

static char* bloFile_PartsGetOnly_un01[2] = { "screen/blo/ufo_p_0.blo", "END" };

static char* bloFile_PartsGetOnly_un02[2] = { "screen/blo/ufo_q_0.blo", "END" };

static char* bloFile_PartsGetOnly_un03[2] = { "screen/blo/ufo_r_0.blo", "END" };

static char* bloFile_PartsGetOnly_un04[2] = { "screen/blo/ufo_s_0.blo", "END" };

static char* bloFile_PartsGetOnly_un05[2] = { "screen/blo/ufo_t_0.blo", "END" };

static char* bloFile_PartsGetOnly_un06[2] = { "screen/blo/ufo_u_0.blo", "END" };

static char* bloFile_PartsGetOnly_un07[2] = { "screen/blo/ufo_v_0.blo", "END" };

static char* bloFile_PartsGetOnly_un08[2] = { "screen/blo/ufo_w_0.blo", "END" };

static char* bloFile_PartsGetOnly_un09[2] = { "screen/blo/ufo_x_0.blo", "END" };

static char* bloFile_PartsGetOnly_un10[2] = { "screen/blo/ufo_y_0.blo", "END" };

static char* bloFile_PartsGetOnly_un11[2] = { "screen/blo/ufo_z_0.blo", "END" };

static char* bloFile_PartsGetOnly_un12[2] = { "screen/blo/ufo_a1_0.blo", "END" };

static char* bloFile_PartsGetOnly_un13[2] = { "screen/blo/ufo_b1_0.blo", "END" };

static char* bloFile_PartsGetOnly_un14[2] = { "screen/blo/ufo_c1_0.blo", "END" };

static char* bloFile_PartsInfo_ust1[2] = { "screen/blo/auf_a_0.blo", "END" };

static char* bloFile_PartsInfo_ust2[2] = { "screen/blo/auf_b_0.blo", "END" };

static char* bloFile_PartsInfo_ust3[2] = { "screen/blo/auf_c_0.blo", "END" };

static char* bloFile_PartsInfo_ust4[2] = { "screen/blo/auf_d_0.blo", "END" };

static char* bloFile_PartsInfo_ust5[2] = { "screen/blo/auf_e_0.blo", "END" };

static char* bloFile_PartsInfo_uf01[2] = { "screen/blo/auf_f_0.blo", "END" };

static char* bloFile_PartsInfo_uf02[2] = { "screen/blo/auf_g_0.blo", "END" };

static char* bloFile_PartsInfo_uf03[2] = { "screen/blo/auf_h_0.blo", "END" };

static char* bloFile_PartsInfo_uf04[2] = { "screen/blo/auf_i_0.blo", "END" };

static char* bloFile_PartsInfo_uf05[2] = { "screen/blo/auf_j_0.blo", "END" };

static char* bloFile_PartsInfo_uf06[2] = { "screen/blo/auf_k_0.blo", "END" };

static char* bloFile_PartsInfo_uf07[2] = { "screen/blo/auf_l_0.blo", "END" };

static char* bloFile_PartsInfo_uf08[2] = { "screen/blo/auf_m_0.blo", "END" };

static char* bloFile_PartsInfo_uf09[2] = { "screen/blo/auf_n_0.blo", "END" };

static char* bloFile_PartsInfo_uf10[2] = { "screen/blo/auf_o_0.blo", "END" };

static char* bloFile_PartsInfo_uf11[2] = { "screen/blo/auf_p_0.blo", "END" };

static char* bloFile_PartsInfo_un01[2] = { "screen/blo/auf_q_0.blo", "END" };

static char* bloFile_PartsInfo_un02[2] = { "screen/blo/auf_r_0.blo", "END" };

static char* bloFile_PartsInfo_un03[2] = { "screen/blo/auf_s_0.blo", "END" };

static char* bloFile_PartsInfo_un04[2] = { "screen/blo/auf_t_0.blo", "END" };

static char* bloFile_PartsInfo_un05[2] = { "screen/blo/auf_u_0.blo", "END" };

static char* bloFile_PartsInfo_un06[2] = { "screen/blo/auf_v_0.blo", "END" };

static char* bloFile_PartsInfo_un07[2] = { "screen/blo/auf_w_0.blo", "END" };

static char* bloFile_PartsInfo_un08[2] = { "screen/blo/auf_x_0.blo", "END" };

static char* bloFile_PartsInfo_un09[2] = { "screen/blo/auf_y_0.blo", "END" };

static char* bloFile_PartsInfo_un10[2] = { "screen/blo/auf_z_0.blo", "END" };

static char* bloFile_PartsInfo_un11[2] = { "screen/blo/auf_a1_0.blo", "END" };

static char* bloFile_PartsInfo_un12[2] = { "screen/blo/auf_b1_0.blo", "END" };

static char* bloFile_PartsInfo_un13[2] = { "screen/blo/auf_c1_0.blo", "END" };

static char* bloFile_PartsInfo_un14[2] = { "screen/blo/auf_d1_0.blo", "END" };

static char* bloFile_PartsGet_ust1[3] = { "screen/blo/auf_a_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_ust2[3] = { "screen/blo/auf_b_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_ust3[3] = { "screen/blo/auf_c_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_ust4[3] = { "screen/blo/auf_d_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_ust5[3] = { "screen/blo/auf_e_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf01[3] = { "screen/blo/auf_f_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf02[3] = { "screen/blo/auf_g_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf03[3] = { "screen/blo/auf_h_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf04[3] = { "screen/blo/auf_i_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf05[3] = { "screen/blo/auf_j_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf06[3] = { "screen/blo/auf_k_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf07[3] = { "screen/blo/auf_l_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf08[3] = { "screen/blo/auf_m_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf09[3] = { "screen/blo/auf_n_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf10[3] = { "screen/blo/auf_o_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_uf11[3] = { "screen/blo/auf_p_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un01[3] = { "screen/blo/auf_q_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un02[3] = { "screen/blo/auf_r_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un03[3] = { "screen/blo/auf_s_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un04[3] = { "screen/blo/auf_t_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un05[3] = { "screen/blo/auf_u_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un06[3] = { "screen/blo/auf_v_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un07[3] = { "screen/blo/auf_w_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un08[3] = { "screen/blo/auf_x_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un09[3] = { "screen/blo/auf_y_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un10[3] = { "screen/blo/auf_z_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un11[3] = { "screen/blo/auf_a1_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un12[3] = { "screen/blo/auf_b1_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un13[3] = { "screen/blo/auf_c1_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsGet_un14[3] = { "screen/blo/auf_d1_0.blo", "screen/blo/tu_tx24.blo", "END" };

static char* bloFile_PartsPower_ust1[3] = { "screen/blo/auf_a_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_ust2[3] = { "screen/blo/auf_b_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_ust3[3] = { "screen/blo/auf_c_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_ust4[3] = { "screen/blo/auf_d_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_ust5[3] = { "screen/blo/auf_e_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf01[3] = { "screen/blo/auf_f_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf02[3] = { "screen/blo/auf_g_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf03[3] = { "screen/blo/auf_h_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf04[3] = { "screen/blo/auf_i_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf05[3] = { "screen/blo/auf_j_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf06[3] = { "screen/blo/auf_k_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf07[3] = { "screen/blo/auf_l_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf08[3] = { "screen/blo/auf_m_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf09[3] = { "screen/blo/auf_n_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf10[3] = { "screen/blo/auf_o_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_uf11[3] = { "screen/blo/auf_p_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un01[3] = { "screen/blo/auf_q_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un02[3] = { "screen/blo/auf_r_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un03[3] = { "screen/blo/auf_s_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un04[3] = { "screen/blo/auf_t_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un05[3] = { "screen/blo/auf_u_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un06[3] = { "screen/blo/auf_v_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un07[3] = { "screen/blo/auf_w_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un08[3] = { "screen/blo/auf_x_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un09[3] = { "screen/blo/auf_y_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un10[3] = { "screen/blo/auf_z_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un11[3] = { "screen/blo/auf_a1_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un12[3] = { "screen/blo/auf_b1_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un13[3] = { "screen/blo/auf_c1_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_PartsPower_un14[3] = { "screen/blo/auf_d1_0.blo", "screen/blo/tu_tx25.blo", "END" };

static char* bloFile_Test[2] = { "screen/blo/test2.blo", "END" };

char** bloFiles_Tutorial[] = { bloFile_Mezame,
	                           bloFile_Oniyon,
	                           bloFile_FoundPikmin,
	                           bloFile_PullHint,
	                           bloFile_GetPikmin,
	                           bloFile_ControlHint,
	                           bloFile_Pelette,
	                           bloFile_StoneHint2,
	                           bloFile_FoundEngine,
	                           bloFile_GetEngine,
	                           bloFile_RirikuDemo,
	                           bloFile_Camera,
	                           bloFile_OnyonInOut,
	                           bloFile_Zenmetu,
	                           bloFile_YellowPikmin,
	                           bloFile_BluePikmin,
	                           bloFile_FoundBomb,
	                           bloFile_GetParts,
	                           bloFile_PowerUp,
	                           bloFile_DayEnd,
	                           bloFile_BombInfo,
	                           bloFile_Limit100,
	                           bloFile_Mitu,
	                           bloFile_Rute,
	                           bloFile_APunchUFO,
	                           bloFile_LifeUp,
	                           bloFile_HitUFO,
	                           bloFile_FinishUFO,
	                           bloFile_BadEnding,
	                           bloFile_HappyEnding,
	                           bloFile_NukiAndFree,
	                           bloFile_InfoDisplay,
	                           bloFile_PartsGetOnly_ust1,
	                           bloFile_PartsGetOnly_ust2,
	                           bloFile_PartsGetOnly_ust3,
	                           bloFile_PartsGetOnly_ust4,
	                           bloFile_PartsGetOnly_ust5,
	                           bloFile_PartsGetOnly_uf01,
	                           bloFile_PartsGetOnly_uf02,
	                           bloFile_PartsGetOnly_uf03,
	                           bloFile_PartsGetOnly_uf04,
	                           bloFile_PartsGetOnly_uf05,
	                           bloFile_PartsGetOnly_uf06,
	                           bloFile_PartsGetOnly_uf07,
	                           bloFile_PartsGetOnly_uf08,
	                           bloFile_PartsGetOnly_uf09,
	                           bloFile_PartsGetOnly_uf10,
	                           bloFile_PartsGetOnly_uf11,
	                           bloFile_PartsGetOnly_un01,
	                           bloFile_PartsGetOnly_un02,
	                           bloFile_PartsGetOnly_un03,
	                           bloFile_PartsGetOnly_un04,
	                           bloFile_PartsGetOnly_un05,
	                           bloFile_PartsGetOnly_un06,
	                           bloFile_PartsGetOnly_un07,
	                           bloFile_PartsGetOnly_un08,
	                           bloFile_PartsGetOnly_un09,
	                           bloFile_PartsGetOnly_un10,
	                           bloFile_PartsGetOnly_un11,
	                           bloFile_PartsGetOnly_un12,
	                           bloFile_PartsGetOnly_un13,
	                           bloFile_PartsGetOnly_un14,
	                           bloFile_PartsInfo_ust1,
	                           bloFile_PartsInfo_ust2,
	                           bloFile_PartsInfo_ust3,
	                           bloFile_PartsInfo_ust4,
	                           bloFile_PartsInfo_ust5,
	                           bloFile_PartsInfo_uf01,
	                           bloFile_PartsInfo_uf02,
	                           bloFile_PartsInfo_uf03,
	                           bloFile_PartsInfo_uf04,
	                           bloFile_PartsInfo_uf05,
	                           bloFile_PartsInfo_uf06,
	                           bloFile_PartsInfo_uf07,
	                           bloFile_PartsInfo_uf08,
	                           bloFile_PartsInfo_uf09,
	                           bloFile_PartsInfo_uf10,
	                           bloFile_PartsInfo_uf11,
	                           bloFile_PartsInfo_un01,
	                           bloFile_PartsInfo_un02,
	                           bloFile_PartsInfo_un03,
	                           bloFile_PartsInfo_un04,
	                           bloFile_PartsInfo_un05,
	                           bloFile_PartsInfo_un06,
	                           bloFile_PartsInfo_un07,
	                           bloFile_PartsInfo_un08,
	                           bloFile_PartsInfo_un09,
	                           bloFile_PartsInfo_un10,
	                           bloFile_PartsInfo_un11,
	                           bloFile_PartsInfo_un12,
	                           bloFile_PartsInfo_un13,
	                           bloFile_PartsInfo_un14,
	                           bloFile_PartsGet_ust1,
	                           bloFile_PartsGet_ust2,
	                           bloFile_PartsGet_ust3,
	                           bloFile_PartsGet_ust4,
	                           bloFile_PartsGet_ust5,
	                           bloFile_PartsGet_uf01,
	                           bloFile_PartsGet_uf02,
	                           bloFile_PartsGet_uf03,
	                           bloFile_PartsGet_uf04,
	                           bloFile_PartsGet_uf05,
	                           bloFile_PartsGet_uf06,
	                           bloFile_PartsGet_uf07,
	                           bloFile_PartsGet_uf08,
	                           bloFile_PartsGet_uf09,
	                           bloFile_PartsGet_uf10,
	                           bloFile_PartsGet_uf11,
	                           bloFile_PartsGet_un01,
	                           bloFile_PartsGet_un02,
	                           bloFile_PartsGet_un03,
	                           bloFile_PartsGet_un04,
	                           bloFile_PartsGet_un05,
	                           bloFile_PartsGet_un06,
	                           bloFile_PartsGet_un07,
	                           bloFile_PartsGet_un08,
	                           bloFile_PartsGet_un09,
	                           bloFile_PartsGet_un10,
	                           bloFile_PartsGet_un11,
	                           bloFile_PartsGet_un12,
	                           bloFile_PartsGet_un13,
	                           bloFile_PartsGet_un14,
	                           bloFile_PartsPower_ust1,
	                           bloFile_PartsPower_ust2,
	                           bloFile_PartsPower_ust3,
	                           bloFile_PartsPower_ust4,
	                           bloFile_PartsPower_ust5,
	                           bloFile_PartsPower_uf01,
	                           bloFile_PartsPower_uf02,
	                           bloFile_PartsPower_uf03,
	                           bloFile_PartsPower_uf04,
	                           bloFile_PartsPower_uf05,
	                           bloFile_PartsPower_uf06,
	                           bloFile_PartsPower_uf07,
	                           bloFile_PartsPower_uf08,
	                           bloFile_PartsPower_uf09,
	                           bloFile_PartsPower_uf10,
	                           bloFile_PartsPower_uf11,
	                           bloFile_PartsPower_un01,
	                           bloFile_PartsPower_un02,
	                           bloFile_PartsPower_un03,
	                           bloFile_PartsPower_un04,
	                           bloFile_PartsPower_un05,
	                           bloFile_PartsPower_un06,
	                           bloFile_PartsPower_un07,
	                           bloFile_PartsPower_un08,
	                           bloFile_PartsPower_un09,
	                           bloFile_PartsPower_un10,
	                           bloFile_PartsPower_un11,
	                           bloFile_PartsPower_un12,
	                           bloFile_PartsPower_un13,
	                           bloFile_PartsPower_un14,
	                           bloFile_Test,
	                           nullptr };

} // namespace zen
