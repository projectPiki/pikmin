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
	_20.setName("投げ"); // 'throw'
	_20._20 = 0x1000;

	_44.setName("集合カーソル"); // 'set cursor'
	_44._20 = 0x2000;

	_68.setName("抜き"); // 'extract'
	_68._20 = 0x2000;

	_8C.setName("アタック"); // 'attack'
	_8C._20 = 0x1000;

	_D4.setName("解散"); // 'disband'
	_D4._20 = 0x4000;

	_B0.setName("メニュー"); // 'menu'
	_B0._20 = 0x8000;

	load("parms/", "key.bin", 1);
}

/*
 * --INFO--
 * Address:	800848E8
 * Size:	0000C0
 */
void KeyConfig::read(RandomAccessStream& input)
{
	_20.read(input);
	_44.read(input);
	_68.read(input);
	_8C.read(input);
	_D4.read(input);
	_B0.read(input);
}

/*
 * --INFO--
 * Address:	800849A8
 * Size:	000040
 */
void KeyConfig::Key::read(RandomAccessStream& input) { _20 = input.readInt(); }
