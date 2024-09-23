#ifndef _P2D_PRINT_H
#define _P2D_PRINT_H

#include "types.h"
#include "P2D/Util.h"

struct Colour;
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

	// TODO: members
};

#endif
