#include "TekiParameters.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tekiparameters");

TekiParameters::TekiParameters(int iParamNum, int fParamNum)
{
	for (int i = 0; i < 8; i++) {
		mParaIDs[i].setID('none');
	}

	ParaParameterInfoI* intParams = new ParaParameterInfoI[iParamNum];
	int j                         = 0;
	intParams[j++].init("CORPSE_TYPE", 0, 1);
	intParams[j++].init("SHADOW_TYPE", 0, 1);
	intParams[j++].init("CULLING_TYPE", 0, 1);
	intParams[j++].init("SPAWN_TYPE", -1, 34);
	intParams[j++].init("SPAWN_COUNT", 0, 100);
	intParams[j++].init("ANIMATION_TYPE", 0, 1);
	intParams[j++].init("死体:CARCASS_SIZE", 0, 2);
	intParams[j++].init("MODEL_TYPE", 0, 1);
	intParams[j++].init("LIGHT_TYPE", 0, 1);
	intParams[j++].init("SWALLOW_COUNT", 0, 200);
	intParams[j++].init("FLICK_PIKI_COUNT_1", 0, 200);
	intParams[j++].init("FLICK_PIKI_COUNT_2", 0, 200);
	intParams[j++].init("FLICK_PIKI_COUNT_3", 0, 200);
	intParams[j++].init("FLICK_DAMAGE_COUNT_1", 0, 100);
	intParams[j++].init("FLICK_DAMAGE_COUNT_2", 0, 100);
	intParams[j++].init("FLICK_DAMAGE_COUNT_3", 0, 100);
	intParams[j++].init("FLICK_DAMAGE_COUNT_4", 0, 100);
	intParams[j++].init("SPAWN_PELLET_SCALE_OFF", 0, 1);
	intParams[j++].init("SPAWN_PELLET_FORWARD", 0, 1);
	intParams[j++].init("IPARA_RESERVED_1", 0, 100);

	ParaParameterInfoF* f32Params = new ParaParameterInfoF[fParamNum];
	j                             = 0;
	f32Params[j++].init("LIFE", 1.0f, 100000.0f);
	f32Params[j++].init("SCALE", 0.0f, 100.0f);
	f32Params[j++].init("WEIGHT", 0.0f, 10000.0f);
	f32Params[j++].init("WALK_VELOCITY", 0.0f, 1000.0f);
	f32Params[j++].init("RUN_VELOCITY", 0.0f, 1000.0f);
	f32Params[j++].init("TURN_VELOCITY", 0.0f, PI);
	f32Params[j++].init("VISIBLE_RANGE", 0.0f, 10000.0f);
	f32Params[j++].init("VISIBLE_ANGLE", 0.0f, 10000.0f);
	f32Params[j++].init("ATTACKABLE_RANGE", 0.0f, 10000.0f);
	f32Params[j++].init("ATTACKABLE_ANGLE", 0.0f, 10000.0f);
	f32Params[j++].init("ATTACK_RANGE", 1.0f, 1000.0f);
	f32Params[j++].init("ATTACK_HIT_RANGE", 0.0f, 1000.0f);
	f32Params[j++].init("ATTACK_POWER", 0.0f, 1000.0f);
	f32Params[j++].init("ATTACK_WAIT_PERIOD", 0.0f, 100.0f);
	f32Params[j++].init("UNGUARDED_PERIOD", 0.0f, 100.0f);
	f32Params[j++].init("DANGER_TERRITORY_RANGE", 1.0f, 10000.0f);
	f32Params[j++].init("SAFETY_TERRITORY_RANGE", 1.0f, 10000.0f);
	f32Params[j++].init("LIFE_GAUGE_OFFSET", -100.0f, 500.0f);
	f32Params[j++].init("SHADOW_SIZE", 1.0f, 1000.0f);
	f32Params[j++].init("RIPPLE_SCALE", 0.0f, 10.0f);
	f32Params[j++].init("CORPSE_SIZE", 1.0f, 1000.0f);
	f32Params[j++].init("CORPSE_HEIGHT", 1.0f, 1000.0f);
	f32Params[j++].init("SPAWN_DISTANCE", 0.0f, 1000.0f);
	f32Params[j++].init("SPAWN_HEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("SPAWN_VELOCITY", 0.0f, 1000.0f);
	f32Params[j++].init("LIFE_PERIOD", 0.0f, 100.0f);
	f32Params[j++].init("MESSAGE_RANGE", 0.0f, 1000.0f);
	f32Params[j++].init("WARN_PERIOD", 0.0f, 100.0f);
	f32Params[j++].init("VISIBLE_HEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("FLIGHT_HEIGHT", 0.0f, 1000.0f);
	f32Params[j++].init("DAMAGE_MOTION_PERIOD", 0.0f, 1.0f);
	f32Params[j++].init("DAMAGE_MOTION_AMPLITUDE", 0.0f, 0.5f);
	f32Params[j++].init("FLICK_PROBABILITY", 0.0f, 1.0f);
	f32Params[j++].init("UPPER_FLICK_POWER", 0.0f, 1000.0f);
	f32Params[j++].init("LOWER_FLICK_POWER", 0.0f, 1000.0f);
	f32Params[j++].init("UPPER_ATTACK_POWER", 0.0f, 1000.0f);
	f32Params[j++].init("LOWER_ATTACK_POWER", 0.0f, 1000.0f);
	f32Params[j++].init("LIFE_RECOVER_RATE", 0.0f, 1.0f);
	f32Params[j++].init("TRACE_ANGLE", 0.0f, 360.0f);
	f32Params[j++].init("SPAWN_PELLET_VELOCITY_HORIZONTAL", 0.0f, 1000.0f);
	f32Params[j++].init("SPAWN_PELLET_VELOCITY_VERTICAL", 0.0f, 1000.0f);
	f32Params[j++].init("CORPSE_VELOCITY_HORIZONTAL", 0.0f, 1000.0f);
	f32Params[j++].init("CORPSE_VELOCITY_VERTICAL", 0.0f, 1000.0f);
	f32Params[j++].init("BOMB_DAMAGE_RATE", 0.0f, 100.0f);
	f32Params[j++].init("COLLISION_RADIUS", 0.0f, 64.0f);
	f32Params[j++].init("LOWER_RANGE", 0.0f, 1000.0f);
	f32Params[j++].init("FPARA_RESERVED_4", 0.0f, 1000.0f);
	f32Params[j++].init("FPARA_RESERVED_3", 0.0f, 1000.0f);
	f32Params[j++].init("FPARA_RESERVED_2", 0.0f, 1000.0f);
	f32Params[j++].init("FPARA_RESERVED_1", 0.0f, 1000.0f);

	mParameters                 = new ParaMultiParameters(iParamNum, intParams, fParamNum, f32Params);
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_SpawnType, -1);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_VisibleHeight, 1000.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);
}

void TekiParameters::read(RandomAccessStream& input)
{
	mVersion                    = input.readInt();
	ParaMultiParameters* multiP = mParameters;
	if (mVersion <= 7) {
		PRINT("TekiParameters::read:TEKIPARAMETERS_VERSION_0615\n");
		int i;
		for (i = 0; i < 8; i++) {
			mParaIDs[i].read(input);
		}

		input.readInt();
		input.readInt();

		for (i = 0; i <= 16; i++) {
			multiP->mIntParams->mParameters[i] = input.readInt();
		}
		for (i = 20; i < multiP->mIntParams->mParaCount; i++) {
			multiP->mIntParams->mParameters[i] = input.readInt();
		}
		for (i = 0; i <= 38; i++) {
			multiP->mFloatParams->mParameters[i] = input.readFloat();
		}
		for (i = 50; i < multiP->mFloatParams->mParaCount; i++) {
			multiP->mFloatParams->mParameters[i] = input.readFloat();
		}

		multiP->setF(TPF_VisibleHeight, 1000.0f);
		multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
		multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
		multiP->setF(TPF_CorpseVelocityHoriz, 0.0f);
		multiP->setF(TPF_CorpseVelocityVert, 0.0f);

	} else if (mVersion <= 8) {
		PRINT("TekiParameters::read:TEKIPARAMETERS_VERSION_0823\n");
		int i;
		for (i = 0; i < 8; i++) {
			mParaIDs[i].read(input);
		}

		multiP->mIntParams->read(input);

		for (i = 0; i <= 39; i++) {
			multiP->mFloatParams->mParameters[i] = input.readFloat();
		}
		for (i = 50; i < multiP->mFloatParams->mParaCount; i++) {
			multiP->mFloatParams->mParameters[i] = input.readFloat();
		}

		multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
		multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);

	} else if (mVersion <= 9) {
		PRINT("TekiParameters::read:TEKIPARAMETERS_VERSION_0908\n");

		int i;
		for (i = 0; i < 8; i++) {
			mParaIDs[i].read(input);
		}

		mParameters->read(input);

		multiP->setF(TPF_CollisionRadius, 16.0f);

	} else if (mVersion <= 10) {
		PRINT("TekiParameters::read:TEKIPARAMETERS_VERSION_0925\n");

		int i;
		for (i = 0; i < 8; i++) {
			mParaIDs[i].read(input);
		}

		mParameters->read(input);

		multiP->setF(TPF_LowerRange, multiP->getF(TPF_AttackRange));

	} else {
		int i;
		for (i = 0; i < 8; i++) {
			mParaIDs[i].read(input);
		}

		mParameters->read(input);
	}
}

#if 0
void TekiParameters::write(RandomAccessStream& output)
{
	PRINT_NAKATA("TekiParameters::write>\n");

	output.writeInt(11);
	for (int i = 0; i < 8; i++) {
		mParaIDs[i].write(output);
	}
	mParameters->write(output);

	PRINT_NAKATA("TekiParameters::write<\n");
}
#endif
