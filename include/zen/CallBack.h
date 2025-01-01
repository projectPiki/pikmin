#ifndef _ZEN_CALLBACK_H
#define _ZEN_CALLBACK_H

#include "types.h"

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
template <typename A>
struct CallBack1 {
	virtual bool invoke(A) = 0; // _08

	// _00 = VTBL
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
template <typename A, typename B>
struct CallBack2 {
	virtual bool invoke(A, B) = 0; // _08

	// _00 = VTBL
};

} // namespace zen

#endif
