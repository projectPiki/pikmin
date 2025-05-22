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

typedef struct Inst_Invented2 Inst_Invented2;
typedef struct Inst_Invented1 Inst_Invented1;

struct Bank_ {
	int magic; // _00 | 'BANK'
	union {    // _04 | Can point to INST, VOICE, PERC.
		// There's no way this was actually an anonymous union, as this only became a feature
		// of the C programming language in C11. However, it does make the code nicer to read.
		void* entry[BANK_ENTRY_COUNT];
		Inst_* inst[BANK_ENTRY_COUNT];
		Voice_* voice[BANK_ENTRY_COUNT];
		Perc_* perc[BANK_ENTRY_COUNT];
	};
};

struct Ibnk_ {
	int magic;           // _00 | 'IBNK'
	u32 _04;             // _04
	u32 _08;             // _08
	u8 _0C[0x20 - 0x0C]; // _0C
	Bank_ bank;
};

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 0x10.
 */
struct Inst_Invented2 {
	u8 _00;
	u8 _01[0x10 - 0x01];
};

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 0x10.
 */
struct Inst_Invented1 {
	u8 _00;              // _00
	u32 _04;             // _04
	Inst_Invented2* _08; // _08
	u8 _0C[0x10 - 0x0C]; // _0C
};

struct Sense_ {
	int _00; // _00
};

struct Osc_ {
	u8 _00;  // _00
	f32 _04; // _04
	int _08; // _08
	int _0C; // _0C
	f32 _10; // _10
	int _14; // _14
};

struct Oscbuf_ {
	u8 _00;
	int _04;
	int _08;
	int _0C;
	int _10;
	u16 _14;
};

/**
 * @note Size: 0x40.
 */
struct Inst_ {
	int magic;              // _00 : 'INST'
	u8 _04[4];              // _04
	int _08;                // _08
	int _0C;                // _0C
	u32 _10;                // _10
	int _14;                // _14
	Rand_* _18;             // _18
	int _1C;                // _1C
	Sense_* _20;            // _20
	u32 _24;                // _24
	u32 _28;                // _28
	Inst_Invented1* _2C[5]; // _2C
};

struct Rand_ {
	u8 _00[0x04 - 0x00]; // _00
	f32 _04;             // _04
	f32 _08;             // _08
	u8 _0C[0x10 - 0x0C]; // _0C
};

struct Pmap_ {
	Rand_* _00;
	int _04;
};

#endif
