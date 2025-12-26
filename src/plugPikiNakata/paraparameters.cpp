#include "ParaParameters.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Stream.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("paraparameters");

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
ParaParametersI::ParaParametersI(int count, ParaParameterInfoI* info)
    : ParaParameters<int>(count, info)
{
}

/**
 * @todo: Documentation
 */
void ParaParametersI::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readInt();
	}
}

/**
 * @todo: Documentation
 */
void ParaParametersI::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeInt(mParameters[i]);
	}
}

/**
 * @todo: Documentation
 */
void ParaParametersI::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%d\n", mParameters[i]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
ParaParametersF::ParaParametersF(int count, ParaParameterInfoF* info)
    : ParaParameters<f32>(count, info)
{
}

/**
 * @todo: Documentation
 */
void ParaParametersF::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readFloat();
	}
}

/**
 * @todo: Documentation
 */
void ParaParametersF::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeFloat(mParameters[i]);
	}
}

/**
 * @todo: Documentation
 */
void ParaParametersF::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%f\n", mParameters[i]);
	}
}

/**
 * @todo: Documentation
 */
ParaMultiParameters::ParaMultiParameters(int iCount, ParaParameterInfoI* iInfo, int fCount, ParaParameterInfoF* fInfo)
{
	mIntParams   = new ParaParametersI(iCount, iInfo);
	mFloatParams = new ParaParametersF(fCount, fInfo);
}

/**
 * @todo: Documentation
 */
void ParaMultiParameters::input(ParaMultiParameters& other)
{
	mIntParams->input(*other.mIntParams);
	mFloatParams->input(*other.mFloatParams);
}

/**
 * @todo: Documentation
 */
void ParaMultiParameters::read(Stream& input)
{
	mIntParams->read(input);
	mFloatParams->read(input);
}

/**
 * @todo: Documentation
 */
void ParaMultiParameters::write(Stream& output)
{
	mIntParams->write(output);
	mFloatParams->write(output);
}

/**
 * @todo: Documentation
 */
void ParaMultiParameters::print()
{
	mIntParams->print();
	mFloatParams->print();
}
