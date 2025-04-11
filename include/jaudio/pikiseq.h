#ifndef _JAUDIO_PIKISEQ_H
#define _JAUDIO_PIKISEQ_H

#include "types.h"

#define BARC_HEADER_SIZE (32)

typedef struct BarcHeader BarcHeader;
typedef struct BarcEntry BarcEntry;
typedef union Barc Barc;

/**
 * @note This is an invented class that may have an actual name elsewhere in the codebase.
 */
struct BarcHeader {
	char fileMagic[8]; // _00
	u32 _04;           // _08
	u32 seqCount;      // _0C
	char arcName[16];  // _10
};

/**
 * @note This is an invented class that may have an actual name elsewhere in the codebase.
 */
struct BarcEntry {
	char jamName[14]; // _00 | Might actually be char[12] and 2 bytes of padding. piki-tools suggests this, but I don't remember why.
	u16 isDummy;      // _0E | 0xffff for used tracks, 0 for dummy tracks
	u32 _10;          // _10
	u32 _14;          // _14
	u32 offset;       // _18
	u32 size;         // _1C
};

/**
 * @note This is an invented class that may have an actual name elsewhere in the codebase.
 */
union Barc {
	BarcHeader meta;
	BarcEntry entry;
};

extern u8 HEAD_pikiseq[];

#endif
