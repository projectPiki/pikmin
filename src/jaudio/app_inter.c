#include "jaudio/app_inter.h"

#include "jaudio/piki_scene.h"
#include "jaudio/piki_bgm.h"
#include "jaudio/hvqm_play.h"

static BOOL demo_fade_flag;

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Jac_Pause(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80017460
 * Size:	000070
 */
void Jac_StreamMovieInit(const char* filepath, u8* param_2, int param_3)
{
	if (Jac_GetCurrentScene() == SCENE_Unk1 && !demo_fade_flag) {
		Jac_EasyCrossFade(1, 50);
		demo_fade_flag = TRUE;
	}
	Jac_HVQM_Init(filepath, param_2, param_3);
	Jac_UpdateStreamLevel();
}

/*
 * --INFO--
 * Address:	800174E0
 * Size:	00004C
 */
void Jac_StreamMovieStop(void)
{
	Jac_HVQM_ForceStop();
	if (Jac_GetCurrentScene() == SCENE_Unk1 && demo_fade_flag) {
		Jac_EasyCrossFade(0, 100);
		demo_fade_flag = FALSE;
	}
}

/*
 * --INFO--
 * Address:	80017540
 * Size:	000020
 */
void Jac_StreamMovieUpdate(void)
{
	Jac_HVQM_Update();
}

/*
 * --INFO--
 * Address:	80017560
 * Size:	000064
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
