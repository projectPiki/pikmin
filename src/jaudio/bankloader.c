#include "jaudio/bankloader.h"

#include "jaudio/bankread.h"
#include "jaudio/dvdthread.h"
#include "jaudio/aictrl.h"
#include "jaudio/waveread.h"

/*
 * --INFO--
 * Address:	8001D9A0
 * Size:	0000E0
 */
void Bank_Setup(char* filename)
{
	unknown32 iVar1;
	unknown32 iVar2;
	unknown32 iVar3;

	u32 i;
	u8* space;

	Bank_Init();

	space = (u8*)OSAlloc2(DVDT_CheckFile(filename));
	DVDT_LoadFile(filename, space);

	Wavegroup_Init();

	// Nothing past this point is particularly good. The space pointer
	// is probably cast to some kind of struct that represents the bank.
	// Super Mario Sunshine's `TBasicWaveBank` seems promising.
	// FYI: This function is used to load pikibank.bx

	iVar1 = *(unknown32*)(space + 0);
	iVar2 = *(unknown32*)(space + 4);
	iVar3 = 0;
	for (i = 0; i < iVar2; ++i) {
		if (*(unknown32*)(space + iVar3 + iVar1 + 4)) {
			Wavegroup_Regist(space + *(unknown32*)(space + iVar3 + iVar1), i);
		}
		iVar3 += 8;
	}

	iVar1 = *(unknown32*)(space + 8);
	iVar2 = *(unknown32*)(space + 12);
	iVar3 = 0;
	for (i = 0; i < iVar2; ++i) {
		if (*(unknown32*)(space + iVar3 + iVar1 + 4)) {
			Bank_Regist(space + *(unknown32*)(space + iVar3 + iVar1), i);
		}
		iVar3 += 8;
	}
}
