#ifndef _JAUDIO_BX_H
#define _JAUDIO_BX_H

// This is an invented header containing several structs related to the file structure of pikibank.bx

#include "types.h"
#include "jaudio/heapctrl.h"

#define BANK_INST_COUNT        (0xF0)
#define BANK_TEST_INST_COUNT   (0x80)
#define BANK_TEST_VOICE_OFFSET (BANK_TEST_INST_COUNT)
#define BANK_TEST_VOICE_COUNT  (0x64)
#define BANK_TEST_PERC_OFFSET  (BANK_TEST_INST_COUNT + BANK_TEST_VOICE_COUNT)
#define BANK_TEST_PERC_COUNT   (0x0C)

typedef struct Bank_ Bank_;
typedef struct Ibnk_ Ibnk_;
typedef struct Inst_ Inst_;
typedef struct Perc_ Perc_;
typedef struct Voice_ Voice_;
typedef struct Sense_ Sense_;
typedef struct Rand_ Rand_;
typedef struct Osc_ Osc_;
typedef struct Oscbuf_ Oscbuf_;

typedef struct Vmap_ Vmap_;
typedef struct InstKeymap_ InstKeymap_;
typedef struct PercKeymap_ PercKeymap_;

// these type names are confirmed:
typedef struct WaveArchiveBank_ WaveArchiveBank_;
typedef struct CtrlGroup_ CtrlGroup_;
typedef struct Ctrl_ Ctrl_;
typedef struct WaveArchive_ WaveArchive_;
typedef struct Wave_ Wave_;

// these type names are fabricated, feel free to rename if found:
typedef struct Wsys_ Wsys_;
typedef struct SCNE_ SCNE_;
typedef struct WaveID_ WaveID_;

//////////////////////////////////////////////////////////
////////////////////// BANK STRUCTS //////////////////////

struct Bank_ {
	int mMagic; // _00 | 'BANK'
	union {     // _04 | Can point to INST, VOICE, PERC.
		// There's no way this was actually an anonymous union, as this only became a feature
		// of the C programming language in C11. However, it does make the code nicer to read.
		Inst_* mInstruments[BANK_INST_COUNT];
		Voice_* mVoices[BANK_INST_COUNT];
		Perc_* mPercs[BANK_INST_COUNT];
	};
};

struct Ibnk_ {
	int magic;                    // _00 | 'IBNK'
	u32 _04;                      // _04
	u32 _08;                      // _08
	int _0C;                      // _0C
	struct WaveArchiveBank_* _10; // _10
	u8 _14[0x20 - 0x14];          // _14
	Bank_ bank;                   // _20
};

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 0x10.
 */
struct Vmap_ {
	u8 mBaseVelocity; // _00
	s16 mWsysID;      // _04
	s16 mWaveID;      // _06
	f32 mVolume;      // _08
	f32 mPitch;       // _0C
};

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 0x10.
 */
struct InstKeymap_ {
	u8 mBaseKey;           // _00
	u32 mVelocityCount;    // _04
	Vmap_* mVelocities[2]; // _08
};

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 0x18.
 */
struct PercKeymap_ {
	f32 mPitch;            // _00
	f32 mVolume;           // _04
	void* _08;             // _08, pointer type unknown, but gets hit by PTconvert in Bank_Test
	void* _0C;             // _0C, pointer type unknown, but gets hit by PTconvert in Bank_Test
	int mVelocityCount;    // _10
	Vmap_* mVelocities[2]; // _14
};

struct Sense_ {
	u8 _00;  // _00
	u8 _01;  // _01
	u8 _02;  // _02
	f32 _04; // _04
	f32 _08; // _08
};

struct Osc_ {
	u8 mMode;               // _00
	f32 mRate;              // _04
	s16* mAttackVecOffset;  // _08
	s16* mReleaseVecOffset; // _0C
	f32 mWidth;             // _10
	f32 mVertex;            // _14
};

struct Oscbuf_ {
	u8 _00;  // _00
	int _04; // _04
	int _08; // _08
	int _0C; // _0C
	int _10; // _10
	u16 _14; // _14
};

/**
 * @note Size: 0x40.
 */
struct Inst_ {
	int mMagic;                  // _00 | 'INST'
	u8 _04[4];                   // _04, unused?
	f32 mFreqMultiplier;         // _08
	f32 mGainMultiplier;         // _0C
	Osc_* mOscillators[2];       // _10
	Rand_* mEffects[2];          // _18
	Sense_* mSensors[2];         // _20
	int mKeyRegionCount;         // _28
	InstKeymap_* mKeyRegions[5]; // _2C
};

struct Voice_ {
	u8 _00[0x8];  // _00, unknown
	int _08;      // _08, count of whatever's at 0xC
	void* _0C[1]; // _0C, unsure of length of array or type
};

struct Perc_ {
	int mMagic;                    // _00 | 'PER2' (or 'PERC'?)
	u8 _04[0x84];                  // _04, unknown
	PercKeymap_* mKeyRegions[128]; // _88
};

struct Rand_ {
	u8 _00;              // _00
	f32 _04;             // _04
	f32 _08;             // _08
	u8 _0C[0x10 - 0x0C]; // _0C
};

struct Pmap_ {
	Rand_* _00; // _00
	int _04;    // _04
};

//////////////////////////////////////////////////////////
////////////////////// WAVE STRUCTS //////////////////////

// Name fabricated, but makes sense in line with Ibnk_
struct Wsys_ {
	int magic;                     // _00, 'WSYS'
	int size;                      // _04
	int globalID;                  // _08
	int _0C;                       // _0C, unused?
	WaveArchiveBank_* waveArcBank; // _10
	CtrlGroup_* ctrlGroup;         // _14
};

struct WaveArchiveBank_ {
	int magic;                   // _00, 'WINF'
	int count;                   // _04, same count as CtrlGroup_
	WaveArchive_* waveGroups[1]; // _08, array size variable
};

struct CtrlGroup_ {
	int magic;        // _00, 'WBCT'
	u32 _04;          // _04, unknown
	int count;        // _08, same count as WaveArchiveBank_
	SCNE_* scenes[1]; // _0C, array size variable
};

// Name fabricated based on magic ID.
struct SCNE_ {
	int magic;   // _00, 'SCNE'
	u8 _04[0x8]; // _04, unknown
	Ctrl_* cdf;  // _0C
	Ctrl_* cex;  // _10
	Ctrl_* cst;  // _14
};

struct Ctrl_ {
	int magic;           // _00, 'C-DF', 'C-EX' or 'C-ST'
	int count;           // _04
	WaveID_* waveIDs[1]; // _08, array size variable
};

// Name fabricated from Xayr's tools.
struct WaveID_ {
	s16 awID;     // _00
	s16 waveID;   // _02
	jaheap_ heap; // _04
};

struct WaveArchive_ {
	char arcName[0x40]; // _00, might be smaller, unsure
	jaheap_ heap;       // _40
	u32 _6C;            // _6C
	int waveCount;      // _70
	Wave_* waves[1];    // _74, array size variable
};

/**
 * @brief TODO. Bigger than this size for sure.
 */
struct Wave_ {
	u8 _00;                // _00
	u8 compBlockIdx;       // _01
	u8 _02;                // _02
	s8 _04[12];            // _04
	s32 isLooping;         // _10
	s32 loopAddress;       // _14
	s32 loopStartPosition; // _18
	s32 _1C;               // _1C
	s16 loopYN1;           // _20
	s16 loopYN2;           // _22
};

#endif
