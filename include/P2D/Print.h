#ifndef _P2D_PRINT_H
#define _P2D_PRINT_H

#include "types.h"
#include "P2D/Util.h"
#include "Colour.h"

struct P2DFont;

/**
 * @brief TODO
 */
struct P2DPrint {

	/**
	 * @brief TODO
	 */
	struct TSize {
		f32 _00; // _00
		f32 _04; // _04
		f32 _08; // _08
		f32 _0C; // _0C
	};

	P2DPrint(P2DFont*, int, int, Colour, Colour);

	void private_initiate(P2DFont*, int, int, Colour, Colour);
	void locate(int, int);
	void setFontSize();
	void initchar();
	void printReturn(const char*, int, int, P2DTextBoxHBinding, P2DTextBoxVBinding, int, int);
	f32 parse(const u8*, int, int, u16*, P2DPrint::TSize&, bool);
	u16 doEscapeCode(const u8**);
	void doCtrlCode(int);
	s32 getNumber(const u8**, s32, s32, int);

	// DLL inlines:
	void u32ToColour(u32, Colour*);
	u32 ColourTou32(const Colour&);
	void setFontSize(int, int);
	f32 getCursorH();
	f32 getCursorV();

	P2DFont* mFont; // _00
	int _04;        // _04
	int _08;        // _08
	u8 _0C;         // _0C
	u8 _0D;         // _0D
	int _10;        // _10
	int _14;        // _14
	f32 _18;        // _18
	f32 _1C;        // _1C
	f32 _20;        // _20
	Colour _24;     // _24
	Colour _28;     // _28
	Colour _2C;     // _2C
	Colour _30;     // _30
	int _34;        // _34
	int _38;        // _38
	int _3C;        // _3C
	int _40;        // _40
	int _44;        // _44
	u8 _48;         // _48
	int _4C;        // _4C
	int _50;        // _50
	int _54;        // _54
};

#endif
