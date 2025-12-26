#include "DebugLog.h"
#include "P2D/Stream.h"
#include "Stream.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(21)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("P2DStream");

/**
 * @todo: Documentation
 */
immut char* P2DStream::getResource(int dataType)
{
	u8 refType = mStream->readByte();
	u8 resSize = mStream->readByte();

	char* res = nullptr;

	if (resSize) {
		res = new char[resSize + 1];

		switch (refType) {
		case 0:
		case 2:
			mStream->read(res, resSize);
			res[resSize] = 0;

			if (dataType != 'FONT' && dataType != 'TIMG' && dataType != 'TLUT') {
				PRINT("Unknown dataType.\n");
				ERROR("can't load.");
			}
			break;

		default:
			PRINT("Unknown refType %d \n", refType);
			ERROR("Screen Data is wrong.\n");
			break;
		}
	}

	return res;
}

/**
 * @todo: Documentation
 */
void P2DStream::align(int paddingAmount)
{
	int position        = mStream->getPosition();
	u32 mask            = ~(paddingAmount - 1);
	int alignedPosition = (position + (paddingAmount - 1)) & mask;

	for (int i = 0; i < alignedPosition - position; i++) {
		mStream->readByte();
	}
}
