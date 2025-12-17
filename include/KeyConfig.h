#ifndef _KEYCONFIG_H
#define _KEYCONFIG_H

#include "Node.h"
#include "types.h"

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

		void set(immut char* name, int bind)
		{
			setName(name);
			mBind = bind;
		}

		// _00     = VTBL
		// _00-_20 = Node
		int mBind; // _20, unknown
	};

	KeyConfig();

	virtual void read(RandomAccessStream& input); // _0C (weak)

	static void createInstance();

	static KeyConfig* _instance;

	// _00     = VTBL
	// _00-_20 = Node
	Key mThrowKey;     // _20, 'throw'
	Key mSetCursorKey; // _44, 'set cursor'
	Key mExtractKey;   // _68, 'extract'
	Key mAttackKey;    // _8C, 'attack'
	Key mMenuKey;      // _B0, 'menu'
	Key mDisbandKey;   // _C4, 'disband'
};

#endif
