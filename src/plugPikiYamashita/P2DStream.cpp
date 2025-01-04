#include "Stream.h"
#include "P2D/Stream.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("P2DStream");

/*
 * --INFO--
 * Address:	801B3274
 * Size:	0000C4
 */
char* P2DStream::getResource(int dataType)
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

/*
 * --INFO--
 * Address:	801B3338
 * Size:	000090
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