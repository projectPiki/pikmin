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
class CallBack1 {
public:
	virtual bool invoke(A) = 0; // _08

	// _00 = VTBL
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
template <typename A, typename B>
class CallBack2 {
public:
	virtual bool invoke(A, B) = 0; // _08

	// _00 = VTBL
};

} // namespace zen

#endif
