#include "ParaParameters.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Stream.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("paraparameters");

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
ParaParametersI::ParaParametersI(int count, ParaParameterInfoI* info)
    : ParaParameters<int>(count, info)
{
}

/**
 * @TODO: Documentation
 */
void ParaParametersI::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readInt();
	}
}

/**
 * @TODO: Documentation
 */
void ParaParametersI::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeInt(mParameters[i]);
	}
}

/**
 * @TODO: Documentation
 */
void ParaParametersI::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%d\n", mParameters[i]);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
ParaParametersF::ParaParametersF(int count, ParaParameterInfoF* info)
    : ParaParameters<f32>(count, info)
{
}

/**
 * @TODO: Documentation
 */
void ParaParametersF::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readFloat();
	}
}

/**
 * @TODO: Documentation
 */
void ParaParametersF::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeFloat(mParameters[i]);
	}
}

/**
 * @TODO: Documentation
 */
void ParaParametersF::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%f\n", mParameters[i]);
	}
}

/**
 * @TODO: Documentation
 */
ParaMultiParameters::ParaMultiParameters(int iCount, ParaParameterInfoI* iInfo, int fCount, ParaParameterInfoF* fInfo)
{
	mIntParams   = new ParaParametersI(iCount, iInfo);
	mFloatParams = new ParaParametersF(fCount, fInfo);
}

/**
 * @TODO: Documentation
 */
void ParaMultiParameters::input(ParaMultiParameters& other)
{
	mIntParams->input(*other.mIntParams);
	mFloatParams->input(*other.mFloatParams);
}

/**
 * @TODO: Documentation
 */
void ParaMultiParameters::read(Stream& input)
{
	mIntParams->read(input);
	mFloatParams->read(input);
}

/**
 * @TODO: Documentation
 */
void ParaMultiParameters::write(Stream& output)
{
	mIntParams->write(output);
	mFloatParams->write(output);
}

/**
 * @TODO: Documentation
 */
void ParaMultiParameters::print()
{
	mIntParams->print();
	mFloatParams->print();
}
