#ifndef _ZEN_CALLBACK_H
#define _ZEN_CALLBACK_H

#include "types.h"

namespace zen {

/*
 * @brief TODO
 */
template <typename A>
struct CallBack1 {
	virtual bool invoke(A) = 0; // _08

	// TODO: members
};

/*
 * @brief TODO
 */
template <typename A, typename B>
struct CallBack2 {
	virtual bool invoke(A, B) = 0; // _08

	// TODO: members
};

} // namespace zen

#endif
