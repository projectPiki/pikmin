// This file is WAY too big to justify having multiple versions of the font in one header, so we do a little decision-making here.
#if defined(VERSION_GPIJ01_01)
#include "bigFont_JPN.h"
#elif defined(VERSION_GPIP01_00)
#include "bigFont_PAL.h"
#else
#include "bigFont_USA.h"
#endif
