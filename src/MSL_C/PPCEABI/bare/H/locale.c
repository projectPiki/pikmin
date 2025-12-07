#include "types.h"

typedef struct {
	const char* _0;
	const char* _4;
	const char* _8;
	const char* _C;
	const char* _10;
	const char* _14;
	const char* _18;
	const char* _1C;
	const char* _20;
	const char* _2C;
	char _30;
	char _31;
	char _32;
	char _33;
	char _34;
	char _35;
	char _36;
	char _37;
} lconv;

const char stringBase0[] = ".\0\0C";

lconv __lconv = { stringBase0,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              stringBase0 + 2,
	              0x7F,
	              0x7F,
	              0x7F,
	              0x7F,
	              0x7F,
	              0x7F,
	              0x7F,
	              0x7F };
