#include "DebugLog.h"
#include "zen/particle.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(19)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("particleLoader")

/**
 * @todo: Documentation
 */
u8* zen::particleLoader::load(immut char* fileName, bool p2)
{
	BinobjInfo* obj = (BinobjInfo*)gsys->findGfxObject(fileName, '_bin');
	if (obj) {
		return obj->mData;
	}

	u8* data = pmFind(fileName);
	if (data) {
		PRINT("すでにロードされています。\n"); // 'already loaded.'
	} else {
		RandomAccessStream* file = gsys->openFile(fileName, p2, true);
		if (file) {
			int size     = file->getPending();
			PCRData* pcr = pmCreatePCRData(fileName, size);
			data         = pcr->getDataBuf();
			file->read(data, size);
			file->close();
		} else {
			PRINT("ERROR! Cannot open file.[%s] \n", fileName);
			ERROR("Cannot open file.[%s] \n", fileName);
		}
	}

	return data;
}

/**
 * @todo: Documentation
 */
u8* zen::particleLoader::pmFind(immut char* fileName)
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
