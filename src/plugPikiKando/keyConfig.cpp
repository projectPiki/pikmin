#include "KeyConfig.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "DebugLog.h"

KeyConfig* KeyConfig::_instance;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("keyConfig")

/*
 * --INFO--
 * Address:	800846C0
 * Size:	00004C
 */
void KeyConfig::createInstance()
{
	if (!_instance) {
		_instance = new KeyConfig;
	}
}

/*
 * --INFO--
 * Address:	8008470C
 * Size:	0001DC
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

/*
 * --INFO--
 * Address:	800848E8
 * Size:	0000C0
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

/*
 * --INFO--
 * Address:	800849A8
 * Size:	000040
 */
void KeyConfig::Key::read(RandomAccessStream& input)
{
	mBind = input.readInt();
}
