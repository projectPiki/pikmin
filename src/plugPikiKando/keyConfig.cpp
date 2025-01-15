#include "KeyConfig.h"
#include "Dolphin/os.h"
#include "sysNew.h"

KeyConfig* KeyConfig::_instance;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "keyConfig");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
	mThrowKey.setName("投げ"); // 'throw'
	mThrowKey._20 = 0x1000;

	mSetCursorKey.setName("集合カーソル"); // 'set cursor'
	mSetCursorKey._20 = 0x2000;

	mExtractKey.setName("抜き"); // 'extract'
	mExtractKey._20 = 0x2000;

	mAttackKey.setName("アタック"); // 'attack'
	mAttackKey._20 = 0x1000;

	mDisbandKey.setName("解散"); // 'disband'
	mDisbandKey._20 = 0x4000;

	mMenuKey.setName("メニュー"); // 'menu'
	mMenuKey._20 = 0x8000;

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
	_20 = input.readInt();
}
