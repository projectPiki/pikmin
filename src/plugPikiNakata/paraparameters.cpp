#include "ParaParameters.h"
#include "Stream.h"
#include "Dolphin/os.h"
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

/*
 * --INFO--
 * Address:	801215A4
 * Size:	000080
 */
void ParaParametersI::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readInt();
	}
}

/*
 * --INFO--
 * Address:	80121624
 * Size:	000080
 */
void ParaParametersI::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeInt(mParameters[i]);
	}
}

/*
 * --INFO--
 * Address:	801216A4
 * Size:	000058
 */
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

/*
 * --INFO--
 * Address:	801216FC
 * Size:	000080
 */
void ParaParametersF::read(Stream& input)
{
	for (int i = 0; i < mParaCount; i++) {
		mParameters[i] = input.readFloat();
	}
}

/*
 * --INFO--
 * Address:	8012177C
 * Size:	000080
 */
void ParaParametersF::write(Stream& output)
{
	for (int i = 0; i < mParaCount; i++) {
		output.writeFloat(mParameters[i]);
	}
}

/*
 * --INFO--
 * Address:	801217FC
 * Size:	000058
 */
void ParaParametersF::print()
{
	for (int i = 0; i < mParaCount; i++) {
		PRINT("%s:%f\n", mParameters[i]);
	}
}

/*
 * --INFO--
 * Address:	80121854
 * Size:	0000A8
 */
ParaMultiParameters::ParaMultiParameters(int iCount, ParaParameterInfoI* iInfo, int fCount, ParaParameterInfoF* fInfo)
{
	mIntParams   = new ParaParametersI(iCount, iInfo);
	mFloatParams = new ParaParametersF(fCount, fInfo);
}

/*
 * --INFO--
 * Address:	80121A1C
 * Size:	000074
 */
void ParaMultiParameters::input(ParaMultiParameters& other)
{
	mIntParams->input(*other.mIntParams);
	mFloatParams->input(*other.mFloatParams);
}

/*
 * --INFO--
 * Address:	80121A90
 * Size:	000060
 */
void ParaMultiParameters::read(Stream& input)
{
	mIntParams->read(input);
	mFloatParams->read(input);
}

/*
 * --INFO--
 * Address:	80121AF0
 * Size:	000060
 */
void ParaMultiParameters::write(Stream& output)
{
	mIntParams->write(output);
	mFloatParams->write(output);
}

/*
 * --INFO--
 * Address:	80121B50
 * Size:	000050
 */
void ParaMultiParameters::print()
{
	mIntParams->print();
	mFloatParams->print();
}
