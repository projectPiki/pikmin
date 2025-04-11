#include "TekiPersonality.h"
#include "sysNew.h"
#include "ParaParameters.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tekipersonality");

/*
 * --INFO--
 * Address:	8014CA60
 * Size:	0001F8
 */
TekiPersonality::TekiPersonality()
{
	int i                         = INT_ParamCount;
	ParaParameterInfoI* intParams = new ParaParameterInfoI[i];
	int j                         = 0;
	intParams[j++].init("PELLET_MIN_COUNT", -128, 127);
	intParams[j++].init("PELLET_MAX_COUNT", -128, 127);
	intParams[j++].init("WATER_MIN_COUNT", -128, 127);
	intParams[j++].init("WATER_MAX_COUNT", -128, 127);
	intParams[j++].init("PARAMETER_0", -128, 127);

	i                               = FLT_ParamCount;
	ParaParameterInfoF* floatParams = new ParaParameterInfoF[i];
	j                               = 0;
	floatParams[j++].init("SIZE", 0.1f, 10.0f);
	floatParams[j++].init("STRENGTH", 0.0f, 100.0f);
	floatParams[j++].init("TERRITORY_RANGE", 0.0f, 10000.0f);
	floatParams[j++].init("PELLET_APPEARANCE_PROBABILITY", 0.0f, 1.0f);
	floatParams[j++].init("WATER_APPEARANCE_PROBABILITY", 0.0f, 1.0f);

	mParams = new ParaMultiParameters(INT_ParamCount, intParams, INT_ParamCount, floatParams);
	reset();
}

/*
 * --INFO--
 * Address:	8014CC58
 * Size:	00012C
 */
void TekiPersonality::reset()
{
	mPosition.set(0.0f, 0.0f, 0.0f);
	mFaceDirection = 0.0f;
	mNestPosition.set(0.0f, 0.0f, 0.0f);
	mPelletKind  = 0;
	mPelletColor = 0;
	mID.setID('none');

	setI(INT_PelletMinCount, 0);
	setI(INT_PelletMaxCount, 0);
	setI(INT_NectarMinCount, 0);
	setI(INT_NectarMaxCount, 0);
	setI(INT_Parameter0, 0);

	setF(FLT_Size, 1.0f);
	setF(FLT_Strength, 1.0f);
	setF(FLT_TerritoryRange, 0.0f);
	setF(FLT_PelletAppearChance, 0.0f);
	setF(FLT_NectarAppearChance, 0.0f);
}

/*
 * --INFO--
 * Address:	8014CD84
 * Size:	0000A0
 */
void TekiPersonality::input(TekiPersonality& other)
{
	mPosition.input(other.mPosition);
	mFaceDirection = other.mFaceDirection;
	mNestPosition.set(other.mNestPosition);
	mPelletKind  = other.mPelletKind;
	mPelletColor = other.mPelletColor;
	mID          = other.mID;
	mParams->input(*other.mParams);
}

/*
 * --INFO--
 * Address:	8014CE24
 * Size:	0002F0
 */
void TekiPersonality::read(RandomAccessStream& input, int version)
{
	PRINT("TekiPersonality::read:%d\n", version);

	ParaMultiParameters* params = mParams;

	if (version <= 7) {
		ERROR("TekiPersonality::read:too old version:%d\n", version);
		mPelletKind  = input.readInt();
		mPelletColor = input.readInt();
		mID.setID('none');
		params->read(input);
		return;
	}

	if (version <= 8) {
		mPelletKind  = input.readInt();
		mPelletColor = input.readInt();
		mID.read(input);

		int i;
		for (i = 0; i <= 2; i++) {
			params->mIntParams->mParameters[i] = input.readInt();
		}

		params->setI(4, params->getI(2));
		params->setI(2, 0);
		params->setI(3, 0);

		for (i = 0; i <= 3; i++) {
			params->mFloatParams->mParameters[i] = input.readFloat();
		}

		params->setF(4, 0.0f);
		return;
	}

	if (version <= 9) {
		mPelletKind  = (s8)input.readByte();
		mPelletColor = (s8)input.readByte();
		mID.read(input);

		int i;
		for (i = 0; i <= 2; i++) {
			params->mIntParams->mParameters[i] = input.readInt();
		}

		params->setI(4, params->getI(2));
		params->setI(2, 0);
		params->setI(3, 0);

		for (i = 0; i <= 3; i++) {
			params->mFloatParams->mParameters[i] = input.readFloat();
		}

		params->setF(4, 0.0f);
		return;
	}

	mPelletKind  = (s8)input.readByte();
	mPelletColor = (s8)input.readByte();
	mID.read(input);
	params->read(input);
	PRINT("TekiPersonality::read:pelletColor:%d\n", mPelletColor);
}

/*
 * --INFO--
 * Address:	8014D114
 * Size:	000090
 */
void TekiPersonality::write(RandomAccessStream& output)
{
	PRINT("TekiPersonality::write>\n");
	output.writeByte((s8)mPelletKind);
	output.writeByte((s8)mPelletColor);
	mID.write(output);
	mParams->write(output);
	PRINT("TekiPersonality::write<\n");
}
