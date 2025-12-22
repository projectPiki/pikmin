#include "jaudio/bankread.h"

#include "jaudio/bx.h"
#include "jaudio/connect.h"

#define BANKP_SIZE (0x100)
static Bank_* bankp[BANKP_SIZE];

/**
 * @TODO: Documentation
 */
static void PTconvert(void** pointer, u32 base_address)
{
	if (*pointer >= (void*)base_address || *pointer == NULL) {
		return;
	}
	*pointer = *(char**)pointer + base_address;
}

/**
 * @TODO: Documentation
 */
Bank_* Bank_Test(u8* ibnk_address)
{
	u32 i, k, j;
	u32 base_addr    = (u32)ibnk_address;
	Bank_* startBank = (Bank_*)(ibnk_address + 0x20);
	if (startBank->mMagic != 'BANK') {
		return NULL;
	}

	for (i = 0; i < BANK_TEST_INST_COUNT; ++i) {
		PTconvert((void**)&startBank->mInstruments[i], base_addr);

		Inst_* inst = startBank->mInstruments[i];
		if (!inst) {
			continue;
		}

		// each instrument has two oscillators, effects, and sensors
		for (j = 0; j < 2; j++) {
			PTconvert((void**)&inst->mOscillators[j], base_addr);
			PTconvert((void**)&inst->mEffects[j], base_addr);
			PTconvert((void**)&inst->mSensors[j], base_addr);

			if (inst->mOscillators[j]) {
				PTconvert((void**)&inst->mOscillators[j]->attackVecOffset, base_addr);
				PTconvert((void**)&inst->mOscillators[j]->releaseVecOffset, base_addr);
			}
		}

		// each instrument also has a certain number of key regions
		for (j = 0; j < inst->mKeyRegionCount; j++) {
			PTconvert((void**)&inst->mKeyRegions[j], base_addr);

			for (k = 0; k < inst->mKeyRegions[j]->mVelocityCount; k++) {
				PTconvert((void**)&inst->mKeyRegions[j]->mVelocities[k], base_addr);
			}
		}
	}

	// treat the next block of 100 as voices (for some reason)
	for (i = 0; i < BANK_TEST_VOICE_COUNT; i++) {
		PTconvert((void**)&(startBank->mVoices + BANK_TEST_VOICE_OFFSET)[i], base_addr);

		Voice_* voice = (startBank->mVoices + BANK_TEST_VOICE_OFFSET)[i];
		if (!voice) {
			continue;
		}

		for (j = 0; j < voice->size; j++) {
			PTconvert((void**)&voice->_0C[j], base_addr);
		}
	}

	// treat the next block of 12 as percussion (for some reason)
	for (i = 0; i < BANK_TEST_PERC_COUNT; i++) {
		PTconvert((void**)&(startBank->mPercs + BANK_TEST_PERC_OFFSET)[i], base_addr);

		Perc_* perc = (startBank->mPercs + BANK_TEST_PERC_OFFSET)[i];
		if (!perc) {
			continue;
		}

		for (j = 0; j < 128; j++) {
			PTconvert((void**)&perc->mKeyRegions[j], base_addr);

			PercKeymap_* key = perc->mKeyRegions[j];
			if (!key) {
				continue;
			}

			PTconvert((void**)&key->_08, base_addr);
			PTconvert((void**)&key->_0C, base_addr);

			for (k = 0; k < key->mVelocityCount; k++) {
				PTconvert((void**)&key->mVelocities[k], base_addr);
			}
		}
	}

	return startBank;
}

/**
 * @TODO: Documentation
 */
static BOOL __Bank_Regist_Inner(u8* ibnk, u32 param_2, u32 param_3)
{
	Jac_BnkConnectTableSet(param_3, param_2);
	bankp[param_2] = Bank_Test(ibnk);
	if (!bankp[param_2])
		return FALSE;
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL Bank_Regist(void* ibnk, u32 param_2)
{
	return __Bank_Regist_Inner((u8*)ibnk, param_2, ((Ibnk_*)ibnk)->_08);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
BOOL Bank_Regist_Direct(void* ibnk, u32 param_2, u32 param_3)
{
	return __Bank_Regist_Inner((u8*)ibnk, param_2, param_3);
}

/**
 * @TODO: Documentation
 */
void Bank_Init()
{
	for (int i = 0; i < BANKP_SIZE; ++i) {
		bankp[i] = NULL;
	}
}

/**
 * @TODO: Documentation
 */
Bank_* Bank_Get(u32 index)
{
	if (index >= BANKP_SIZE) {
		return NULL;
	}
	return bankp[index];
}
