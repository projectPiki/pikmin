#ifndef _JAUDIO_BX_H
#define _JAUDIO_BX_H

// This is an invented header containing several structs related to the file structure of pikibank.bx

#include "types.h"

#define BANK_ENTRY_COUNT (0x80)

typedef struct Bank_ Bank_;
typedef struct Ibnk_ Ibnk_;
typedef struct Inst_ Inst_;
typedef struct Perc_ Perc_;
typedef struct Voice_ Voice_;
typedef struct Sense_ Sense_;
typedef struct Rand_ Rand_;
typedef struct Osc_ Osc_;
typedef struct Oscbuf_ Oscbuf_;
typedef struct Wave_ Wave_;

typedef struct Vmap_ Vmap_;
typedef struct InstKeymap_ InstKeymap_;
typedef struct PercKeymap_ PercKeymap_;

struct Bank_ {
	int mMagic; // _00 | 'BANK'
	union {     // _04 | Can point to INST, VOICE, PERC.
		// There's no way this was actually an anonymous union, as this only became a feature
		// of the C programming language in C11. However, it does make the code nicer to read.
		void* mEntries[BANK_ENTRY_COUNT];
		Inst_* mInstruments[BANK_ENTRY_COUNT];
		Voice_* mVoices[BANK_ENTRY_COUNT];
		Perc_* mPercs[BANK_ENTRY_COUNT];
	};
};

struct Ibnk_ {
	int magic;           // _00 | 'IBNK'
	u32 _04;             // _04
	u32 _08;             // _08
	u8 _0C[0x20 - 0x0C]; // _0C
	Bank_ bank;          // _20
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
	u8 _08[0x8];           // _08, unknown
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
	u8 mMode;              // _00
	f32 mRate;             // _04
	int mAttackVecOffset;  // _08
	int mReleaseVecOffset; // _0C
	f32 mWidth;            // _10
	f32 mVertex;           // _14
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

struct Perc_ {
	int mMagic;                    // _00 | 'PER2'
	u8 _04[0x84];                  // _04, unknown
	PercKeymap_* mKeyRegions[100]; // _88
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

#endif
