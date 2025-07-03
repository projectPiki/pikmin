#include "zen/particle.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(19)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("particleLoader")

/*
 * --INFO--
 * Address:	801A0F24
 * Size:	000158
 */
u8* zen::particleLoader::load(char* fileName, bool p2)
{
	BinobjInfo* obj = (BinobjInfo*)gsys->findGfxObject(fileName, '_bin');
	if (obj) {
		return (u8*)obj->mData;
	}

	u8* data = pmFind(fileName);
	if (data) {
		PRINT("すでにロードされています。\n"); // 'already loaded.'
	} else {
		RandomAccessStream* file = gsys->openFile(fileName, p2, true);
		if (!file) {
			PRINT("ERROR! Cannot open file.[%s] \n", fileName);
			ERROR("Cannot open file.[%s] \n", fileName);

		} else {
			int size     = file->getPending();
			PCRData* pcr = pmCreatePCRData(fileName, size);
			data         = pcr->getDataBuf();
			file->read(data, size);
			file->close();
		}
	}

	return data;
}

/*
 * --INFO--
 * Address:	801A107C
 * Size:	000084
 */
u8* zen::particleLoader::pmFind(char* fileName)
{
	PCRData* pcr;
	u8* data = nullptr;
	for (pcr = (PCRData*)getTopList(); pcr != getOrigin(); pcr = (PCRData*)pcr->mNext) {
		if (strcmp(pcr->getName(), fileName) == 0) {
			data = pcr->getDataBuf();
			break;
		}
	}

	return data;
}
