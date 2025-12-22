#include "ParaParameters.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Stream.h"

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
DEFINE_PRINT("paraparameters");

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
ParaParametersI::ParaParametersI(int count, ParaParameterInfoI* info)
    : ParaParameters<int>(count, info)
{
}

void ParaParametersI::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readInt();
	}
}

void ParaParametersI::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeInt(mParameters[i]);
	}
}

void ParaParametersI::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%d\n", mParameters[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
ParaParametersF::ParaParametersF(int count, ParaParameterInfoF* info)
    : ParaParameters<f32>(count, info)
{
}

void ParaParametersF::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readFloat();
	}
}

void ParaParametersF::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeFloat(mParameters[i]);
	}
}

void ParaParametersF::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%f\n", mParameters[i]);
	}
}

ParaMultiParameters::ParaMultiParameters(int iCount, ParaParameterInfoI* iInfo, int fCount, ParaParameterInfoF* fInfo)
{
	mIntParams   = new ParaParametersI(iCount, iInfo);
	mFloatParams = new ParaParametersF(fCount, fInfo);
}

void ParaMultiParameters::input(ParaMultiParameters& other)
{
	mIntParams->input(*other.mIntParams);
	mFloatParams->input(*other.mFloatParams);
}

void ParaMultiParameters::read(Stream& input)
{
	mIntParams->read(input);
	mFloatParams->read(input);
}

void ParaMultiParameters::write(Stream& output)
{
	mIntParams->write(output);
	mFloatParams->write(output);
}

void ParaMultiParameters::print()
{
	mIntParams->print();
	mFloatParams->print();
}
