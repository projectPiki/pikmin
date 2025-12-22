#include "jaudio/app_inter.h"

#include "jaudio/hvqm_play.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/piki_scene.h"

static BOOL demo_fade_flag;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000094
 */
void Jac_Pause(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Jac_StreamMovieInit(immut char* filepath, u8* param_2, int param_3)
{
	if (Jac_GetCurrentScene() == SCENE_Unk1 && !demo_fade_flag) {
		Jac_EasyCrossFade(1, 50);
		demo_fade_flag = TRUE;
	}
	Jac_HVQM_Init(filepath, param_2, param_3);
	Jac_UpdateStreamLevel();
}

/**
 * @TODO: Documentation
 */
void Jac_StreamMovieStop(void)
{
	Jac_HVQM_ForceStop();
	if (Jac_GetCurrentScene() == SCENE_Unk1 && demo_fade_flag) {
		Jac_EasyCrossFade(0, 100);
		demo_fade_flag = FALSE;
	}
}

/**
 * @TODO: Documentation
 */
void Jac_StreamMovieUpdate(void)
{
	Jac_HVQM_Update();
}

/**
 * @TODO: Documentation
 */
int Jac_StreamMovieGetPicture(void* p1, int* p2, int* p3)
{
	int picture;

	picture = Jac_GetPicture(p1, p2, p3);
	if (picture == -1) {
		if (Jac_GetCurrentScene() == SCENE_Unk1 && demo_fade_flag) {
			Jac_EasyCrossFade(0, 100);
			demo_fade_flag = FALSE;
		}
	}
	return picture;
}
