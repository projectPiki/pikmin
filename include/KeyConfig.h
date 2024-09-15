#ifndef _KEYCONFIG_H
#define _KEYCONFIG_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 *
 * @note Size: 0xF8.
 */
struct KeyConfig : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x24.
	 */
	struct Key : public Node {
		virtual void read(RandomAccessStream&); // _0C

		// _00     = VTBL
		// _00-_20 = Node
		int _20; // _20, unknown
	};

	KeyConfig();

	virtual void read(RandomAccessStream& input); // _0C (weak)

	static void createInstance();

	static KeyConfig* _instance;

	// _00     = VTBL
	// _00-_20 = Node
	Key _20; // _20, 'throw'
	Key _44; // _44, 'set cursor'
	Key _68; // _68, 'extract'
	Key _8C; // _8C, 'attack'
	Key _B0; // _B0, 'menu'
	Key _D4; // _C4, 'disband'
};

#endif
