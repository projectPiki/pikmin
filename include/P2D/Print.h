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
		// TODO: members
	};

	P2DPrint(P2DFont*, int, int, Colour, Colour);

	void private_initiate(P2DFont*, int, int, Colour, Colour);
	void locate(int, int);
	void setFontSize();
	void initchar();
	void printReturn(const char*, int, int, P2DTextBoxHBinding, P2DTextBoxVBinding, int, int);
	void parse(const u8*, int, int, u16*, P2DPrint::TSize&, bool);
	void doEscapeCode(const u8**);
	void doCtrlCode(int);
	void getNumber(const u8**, s32, s32, int);

	P2DFont* mFont;      // _00
	int _04;             // _04
	int _08;             // _08
	u8 _0C;              // _0C
	u8 _0D;              // _0D
	u8 _0E[0x24 - 0x0E]; // _0E, unknown
	Colour _24;          // _24
	Colour _28;          // _28
	Colour _2C;          // _2C
	Colour _30;          // _30
	int _34;             // _34
	int _38;             // _38
	int _3C;             // _3C
};

#endif
