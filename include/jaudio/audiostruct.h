#ifndef _JAUDIO_AUDIOSTRUCT_H
#define _JAUDIO_AUDIOSTRUCT_H

#include "types.h"
#include "Dolphin/os.h"
#include "jaudio/bx.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

///////////////// JAUDIO STRUCTURES /////////////////
// Members and names from AC and SMS Decomp with gratitude.

typedef struct ALHeap ALHeap;
typedef struct dspch_ dspch_; // TODO: Figure out why there is another struct named `DSPChannel_` in syncstream.c.
typedef struct Jac_MessageQueue Jac_MessageQueue;
typedef struct JCMgr JCMgr;
typedef struct jc_ jc_;
typedef struct jcs_ jcs_;
typedef struct Wave_ Wave_;

typedef enum JCSTATUS {
	// TODO: This is probably also a struct and not an enum.  Confirm.
} JCSTATUS;

/**
 * @brief Audio heap.
 *
 * @note Size: 0x14.
 */
struct ALHeap {
	u8* base;    // _00
	u8* current; // _04
	int length;  // _08
	u32 count;   // _0C
	u8* last;    // _10
};

typedef BOOL (*DSPChannelCallback)(dspch_*, u32);

/**
 * @brief TODO.
 */
struct dspch_ {
	u8 buffer_idx;          // _00
	u8 _01;                 // _00
	u8 _02;                 // _00
	u8 _03;                 // _00
	u16 _04;                // _04
	u16 _06;                // _06
	u32 _08;                // _08
	DSPChannelCallback _0C; // _0C

	// DSPBuffer* _0C; // TODO: SMS says this exists, Pikmin 1 disagrees.
};

typedef struct PanMatrix_ {
	f32 _00[3];
} PanMatrix_;

/**
 * @brief TODO
 *
 * @note Size: 0x74.
 */
struct jcs_ {
	u32 _00;     // _00
	int _04;     // _04
	jc_* _08;    // _08
	jc_* _0C;    // _0C
	jc_* _10;    // _10
	jc_* _14;    // _14
	f32 _18;     // _18
	f32 _1C;     // _1C
	f32 _20;     // _20
	f32 _24;     // _24
	f32 _28;     // _28
	s16 _2C[8];  // _2C
	s16 _3C[4];  // _3C
	char _44[8]; // _44
	s16 _4C;     // _4C
	u16 _4E[6];  // _4E | Exact length unknown, but it is an array.
	u8 _5A[6];   // _5A
	u8 _60;      // _60
	u8 _61;      // _61
	u8 _62[3];   // _62
	u32 _68;     // _68
	u16 _6C;     // _6C
	int _70;     // _70
};

/**
 * @brief TODO.
 */
struct jc_ {
	u8 _00;                      // _00
	u8 _01;                      // _01
	u8 _02;                      // _02
	u8 _03;                      // _03
	jcs_* mMgr;                  // _04
	void** _08;                  // _08
	u8 _0C;                      // _0C
	void* _10;                   // _10
	u32 _14;                     // _14
	u32 _18;                     // _18
	u32 _1C;                     // _1C
	dspch_* _20;                 // _20
	void* mNext;                 // _24
	BOOL (*_28)(jc_*, JCSTATUS); // _28
	BOOL (*_2C)(jc_*, JCSTATUS); // _2C
	s32 _30;                     // _30
	s32 _34;                     // _34
	struct Osc_* _38[4];         // _38
	struct Oscbuf_ _48[2];       // _48
	f32 _78;                     // _78
	char _7C[8];                 // _7C
	f32 _84;                     // _84
	char _88[4];                 // _88
	f32 _8C;                     // _8C
	f32 _90;                     // _90
	f32 _94;                     // _94
	u16 _98;                     // _98
	u16 _9A;                     // _9A
	void* _9C;                   // _9C
	char _A0[8];                 // _A0
	f32 _A8;                     // _A8
	f32 _AC;                     // _AC
	f32 _B0;                     // _B0
	f32 _B4;                     // _B4
	f32 _B8;                     // _B8
	PanMatrix_ _BC[4];           // _BC
	f32 _E8[3];                  // _E8
	u16 _F8;                     // _F8
	u16 _FA;                     // _FA
	u8 _FC[0x114 - 0xFC];        // _FC
	u16 _114[6];                 // _114
	u32 _120;                    // _120
	u16 _124;                    // _124
	u16 _126;                    // _126
	int _128;                    // _128
	int _12C;                    // _12C
	int _130;                    // _130
	int _134;                    // _134
	int _138;                    // _138
	int _13C;                    // _13C
};

/**
 * @brief TODO.
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

/////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
