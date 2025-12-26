#include "KeyConfig.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "sysNew.h"

KeyConfig* KeyConfig::_instance;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("keyConfig")

/**
 * @todo: Documentation
 */
void KeyConfig::createInstance()
{
	if (!_instance) {
		_instance = new KeyConfig;
	}
}

/**
 * @todo: Documentation
 */
KeyConfig::KeyConfig()
{
	mThrowKey.set("投げ", KBBTN_A);             // 'throw'
	mSetCursorKey.set("集合カーソル", KBBTN_B); // 'set cursor'
	mExtractKey.set("抜き", KBBTN_B);           // 'extract'
	mAttackKey.set("アタック", KBBTN_A);        // 'attack'
	mDisbandKey.set("解散", KBBTN_X);           // 'disband'
	mMenuKey.set("メニュー", KBBTN_Y);          // 'menu'

	load("parms/", "key.bin", 1);
}

/**
 * @todo: Documentation
 */
void KeyConfig::read(RandomAccessStream& input)
{
	mThrowKey.read(input);
	mSetCursorKey.read(input);
	mExtractKey.read(input);
	mAttackKey.read(input);
	mDisbandKey.read(input);
	mMenuKey.read(input);
}

/**
 * @todo: Documentation
 */
void KeyConfig::Key::read(RandomAccessStream& input)
{
	mBind = input.readInt();
}
