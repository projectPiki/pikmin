#include "DebugLog.h"
#include "zen/ogSub.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	801F2424
 * Size:	0001BC
 */
void zen::makePathName(const char* directoryPath, const char* fileName, char* outputPath)
{
	int i, j;
	char buffer[PATH_MAX];

	int strLength = strlen(fileName);
	for (i = 0; strLength - i - 1 >= 0 && (u8)fileName[strLength - i - 1] != (u8)'/'; ++i) {
		buffer[i] = fileName[strLength - i - 1];
	}
	buffer[i]     = '\0';
	outputPath[0] = '\0';

	int sourceLength = strlen(directoryPath);
	strcat(outputPath, directoryPath);
	for (j = 0; j < i; ++j) {
		outputPath[j + sourceLength] = buffer[i - j - 1];
	}
	outputPath[sourceLength + i] = '\0';
}

/*
 * --INFO--
 * Address:	801F25E0
 * Size:	00007C
 */
Texture* zen::loadTexExp(const char* textureName, bool useDirectory, bool makePath)
{
	if (useDirectory) {
		char fullPath[PATH_MAX];
		char* dirPath = gsys->mTexDir;
		if (makePath) {
			zen::makePathName(dirPath, textureName, fullPath);
		} else {
			sprintf(fullPath, "%s%s", dirPath, textureName);
		}

		return gsys->loadTexture(fullPath, true);
	}

	return gsys->loadTexture((char*)textureName, true);
}
