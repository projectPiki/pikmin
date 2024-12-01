#include "Menu.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005D6F8
 * Size:	0001C8
 */
Menu::Menu(Controller* controller, Font* font, bool p3)
{
	_54 = 0;
	_4C = 0;
	_50 = 0;
	_48 = 0;

	_74 = 0;
	_6C = 0;
	_70 = 0;
	_68 = 0;

	_84 = 0;
	_7C = 0;
	_80 = 0;
	_78 = 0;

	mController = controller;
	_3C         = p3;

	mFont = font;
	_20   = 0;
	_A8   = 0;
	_2C   = new MenuItem(0, 0, "menu", nullptr);

	resetMenuItem(_2C);

	_40 = 0;
	_38 = 0;
	_30 = nullptr;
	_34 = nullptr;

	_48 = 160;
	_4C = 120;
	_50 = 0;
	_54 = 0;

	_78 = 6;
	_7C = 12;
	_80 = 6;
	_84 = 12;

	_60.r = 32;
	_60.g = 32;
	_60.b = 128;
	_60.a = 192;

	_64.r = 32;
	_64.g = 32;
	_64.b = 32;
	_64.a = 64;

	_44 = PI;

	_5C    = 0;
	_8C    = 0;
	_88    = 0;
	_94    = 0;
	_98    = 1;
	_99    = 1;
	_A4    = 0x1001000;
	mState = STATE_Unk0;
	_B0    = 0.0f;
	_28    = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::KeyEvent::insertAfter(Menu::KeyEvent* key)
{
	key->mNext   = mNext;
	key->mPrev   = this;
	mNext->mPrev = key;
	mNext        = key;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::KeyEvent::remove()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::MenuItem::insertAfter(Menu::MenuItem* item)
{
	item->mNext  = mNext;
	item->mPrev  = this;
	mNext->mPrev = item;
	mNext        = item;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Menu::MenuItem::remove()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
Menu::KeyEvent::KeyEvent(int p1, int p2, IDelegate1<Menu&>* delegate)
{
	_08       = p1;
	_0C       = p2;
	mDelegate = delegate;

	mPrev = mNext = nullptr;
}

/*
 * --INFO--
 * Address:	8005D8C0
 * Size:	000094
 */
Menu::MenuItem::MenuItem(int p1, int p2, char* name, IDelegate1<Menu&>* delegate)
{
	_14   = true;
	mName = name;
	_1C   = p2;
	_20   = p1;
	mPrev = mNext = nullptr;
	_08           = 0;
	mMenu         = nullptr;

	mEventList = new KeyEvent(0, 0, nullptr);
	resetKeyEvent(mEventList);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Menu::setOnEnter(IDelegate1<Menu&>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Menu::setOnExit(IDelegate1<Menu&>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005D954
 * Size:	0000C8
 */
void Menu::addKeyEvent(int p1, int p2, IDelegate1<Menu&>* delegate)
{
	KeyEvent* key = new KeyEvent(p1, p2, delegate);

	if (_34) {
		_34->mEventList->mPrev->insertAfter(key);

	} else {
		_2C->mEventList->mPrev->insertAfter(key);
	}
}

/*
 * --INFO--
 * Address:	8005DA1C
 * Size:	000004
 */
void Menu::enterOption() { }

/*
 * --INFO--
 * Address:	8005DA20
 * Size:	000048
 */
Menu* Menu::enterMenu(Menu* menu)
{
	Menu* ret = menu; // yes this is necessary
	if (ret) {
		ret->open(false);
	}
	return ret;
}

/*
 * --INFO--
 * Address:	8005DA68
 * Size:	000044
 */
Menu* Menu::exitMenu(Menu* menu)
{
	Menu* ret = menu;
	if (ret) {
		ret->close();
	}
	return ret;
}

/*
 * --INFO--
 * Address:	8005DAAC
 * Size:	00002C
 */
void Menu::open(bool p1)
{
	_B0    = 0.0;
	mState = STATE_Unk1;
	if (!_30) {
		_30 = _2C->mNext;
	}
}

/*
 * --INFO--
 * Address:	8005DAD8
 * Size:	000024
 */
void Menu::close()
{
	if (!_20) {
		_24 = _20;
	}
	_B0    = 1.0f;
	mState = STATE_Unk3;
}

/*
 * --INFO--
 * Address:	8005DAFC
 * Size:	000020
 */
void Menu::resetOptions()
{
	_40 = 0;
	_30 = nullptr;
	resetMenuItem(_2C);
}

/*
 * --INFO--
 * Address:	8005DB1C
 * Size:	000194
 */
void Menu::addOption(int p1, char* name, IDelegate1<Menu&>* delegate, bool p4)
{
	_34      = new MenuItem(1, p1, name, delegate);
	_34->_14 = p4;
	_2C->mPrev->insertAfter(_34);
	if (delegate) {
		addKeyEvent(16, _A4, delegate);
	}

	if (!_30 && _34->_14) {
		_30 = _34;
	}

	_40++;
}

/*
 * --INFO--
 * Address:	8005DCB0
 * Size:	000184
 */
void Menu::addMenu(Menu* menu, int p2, char* name)
{
	_34        = new MenuItem(2, p2, name, nullptr);
	_34->mMenu = menu;
	menu->_20  = this;
	_2C->mPrev->insertAfter(_34);

	addKeyEvent(16, _A4, nullptr);

	if (!_30) {
		_30 = _34;
	}

	_40++;
}

/*
 * --INFO--
 * Address:	8005DE34
 * Size:	000150
 */
bool Menu::checkNewOption()
{
	// i dont think these button enums are correct
	if (mController->isReleased(KBBTN_CSTICK_DOWN) || mController->isReleased(KBBTN_MSTICK_DOWN)) {
		_30->checkEvents(this, 2);
		_30 = _30->mNext;

		if (_30 == _2C) {
			_30 = _30->mNext;
		}

		while (!_30->mName || !_30->_14) {
			_30 = _30->mNext;
			if (_30 == _2C) {
				_30 = _30->mNext;
			}
		}

		_99 = 1;

	} else if (mController->isReleased(KBBTN_CSTICK_UP) || mController->isReleased(KBBTN_MSTICK_UP)) {
		_30->checkEvents(this, 2);

		_30 = _30->mPrev;

		if (_30 == _2C) {
			_30 = _30->mPrev;
		}

		while (!_30->mName || !_30->_14) {
			_30 = _30->mPrev;
			if (_30 == _2C) {
				_30 = _30->mPrev;
			}
		}

		_99 = 1;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8005DF84
 * Size:	00001C
 */
bool Menu::checkSelectKey() { return mController->isPressed(KBBTN_A) != false; }

/*
 * --INFO--
 * Address:	8005DFA0
 * Size:	00001C
 */
bool Menu::checkCancelKey() { return mController->isPressed(KBBTN_B) != false; }

/*
 * --INFO--
 * Address:	8005DFBC
 * Size:	000258
 */
Menu* Menu::doUpdate(bool p1)
{
	// there's totally a missing inline in here but idk where seems sensible so have some stack padding
	u32 missingInlineBuf1;
	u32 missingInlineBuf2;

	Menu* ret = this;
	_24       = this;
	_44 += 7.0f * gsys->getFrameTime();

	switch (mState) {
	case STATE_Unk1:
		_B0 += 8.0f * gsys->getFrameTime();
		if (_B0 >= 1.0f) {
			_B0    = 1.0f;
			mState = STATE_Unk2;
		}
		break;
	case STATE_Unk3:
		_B0 -= 8.0f * gsys->getFrameTime();
		if (_B0 < 0.0f) {
			_B0    = 0.0f;
			mState = STATE_Unk0;
			ret    = _28;
		}
		break;
	case STATE_Unk2:
		if (p1) {
			_99 = 1;
		}
		checkNewOption();

		if (_98) {
			if (_88) {
				_88->invoke(*this);
			}
			_98 = 0;
			_99 = 1;
		}

		int flag = 0xFFFC;
		if (_99) {
			flag |= 0x1;
			if (_94) {
				_94->invoke(*this);
			}
			_44 = 0.0f;
			_99 = 0;
		}

		if (!_30->checkEvents(this, flag)) {
			_2C->checkEvents(this, flag);
		}

		if (_24 != this) {
			_30->checkEvents(this, 2);
			if (_8C) {
				_8C->invoke(*this);
			}

			if (_24) {
				_24->open(false);
				ret = _24;
			} else {
				close();
			}
			_28 = _24;
		}
		break;
	}

	return ret;
}

/*
 * --INFO--
 * Address:	8005E214
 * Size:	0001FC
 */
bool Menu::MenuItem::checkEvents(Menu* menu, int flags)
{
	KeyEvent* key = mEventList->mNext;
	for (key; key != mEventList; key = key->mNext) {
		if (!(flags & key->_08)) {
			continue;
		}

		switch (key->_08) {
		case 1:
			key->mDelegate->invoke(*menu);
			break;
		case 2:
			key->mDelegate->invoke(*menu);
			break;
		case 4:
			if (menu->mController->isCurrentInput(key->_0C)) {
				key->mDelegate->invoke(*menu);
			}
			break;
		case 8:
		case 0x20:
			if (menu->mController->isReleased(key->_0C)) {
				key->mDelegate->invoke(*menu);
				return true;
			}
			break;
		case 0x10:
			if (menu->mController->isReleased(key->_0C)) {
				if (menu->_30->_20 == 2) {
					checkEvents(menu, 2);
					menu->close();
					menu->_24 = menu;
					menu->_28 = menu->_30->mMenu;
					menu->_28->open(false);

					if (menu->_28->_3C) {
						menu->_28->_4C = menu->_4C - (menu->_40 * 14) / 2 + menu->_A0 * 14;
					}
					menu->_98             = 1;
					menu->_30->mMenu->_98 = 1;
					return false;
				}

				key->mDelegate->invoke(*menu);
				return true;
			}
			break;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	8005E410
 * Size:	00060C
 */
void Menu::draw(Graphics&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stfd      f30, 0x1E8(r1)
	  fmr       f30, f1
	  stfd      f29, 0x1E0(r1)
	  stmw      r19, 0x1AC(r1)
	  mr        r27, r4
	  mr        r26, r3
	  li        r30, 0
	  lwz       r0, 0x40(r3)
	  lwz       r3, 0x2C(r3)
	  mulli     r4, r0, 0xE
	  lwz       r0, 0x4C(r26)
	  lwz       r19, 0x4(r3)
	  srawi     r3, r4, 0x1
	  addze     r3, r3
	  sub       r31, r0, r3
	  b         .loc_0x7C

	.loc_0x50:
	  lwz       r4, 0x18(r19)
	  cmplwi    r4, 0
	  beq-      .loc_0x78
	  lwz       r3, 0x9C(r26)
	  bl        -0x3633C
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  cmpw      r0, r30
	  ble-      .loc_0x78
	  mr        r30, r0

	.loc_0x78:
	  lwz       r19, 0x4(r19)

	.loc_0x7C:
	  lwz       r0, 0x2C(r26)
	  cmplw     r19, r0
	  bne+      .loc_0x50
	  lwz       r0, 0x40(r26)
	  addi      r24, r30, 0x10
	  lfs       f3, 0xB0(r26)
	  li        r28, 0x1
	  mulli     r3, r0, 0x7
	  lfs       f0, -0x7968(r2)
	  fmr       f31, f3
	  lwz       r29, 0x48(r26)
	  add       r21, r31, r3
	  fcmpu     cr0, f0, f3
	  addi      r21, r21, 0x3
	  addi      r20, r3, 0xE
	  beq-      .loc_0x144
	  lwz       r3, 0x28(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  lwz       r0, 0x3C(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xE4
	  lfs       f1, -0x795C(r2)
	  fmuls     f0, f1, f3
	  fadds     f31, f1, f0
	  b         .loc_0x144

	.loc_0xE4:
	  lfs       f0, -0x7968(r2)
	  fcmpu     cr0, f0, f3
	  beq-      .loc_0xF4
	  li        r28, 0

	.loc_0xF4:
	  xoris     r3, r24, 0x8000
	  lfd       f2, -0x7950(r2)
	  xoris     r0, r20, 0x8000
	  stw       r3, 0x1A4(r1)
	  lis       r3, 0x4330
	  stw       r0, 0x194(r1)
	  stw       r3, 0x1A0(r1)
	  stw       r3, 0x190(r1)
	  lfd       f1, 0x1A0(r1)
	  lfd       f0, 0x190(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fmuls     f1, f1, f3
	  fmuls     f0, f0, f3
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x198(r1)
	  stfd      f0, 0x188(r1)
	  lwz       r24, 0x19C(r1)
	  lwz       r20, 0x18C(r1)

	.loc_0x144:
	  mr        r3, r27
	  fmuls     f31, f31, f30
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x63(r26)
	  lis       r25, 0x4330
	  lfd       f1, -0x7948(r2)
	  addi      r4, r1, 0x70
	  stw       r0, 0x18C(r1)
	  lbz       r7, 0x62(r26)
	  mr        r3, r27
	  stw       r25, 0x188(r1)
	  li        r5, 0x1
	  lbz       r6, 0x61(r26)
	  lfd       f0, 0x188(r1)
	  lbz       r0, 0x60(r26)
	  fsubs     f0, f0, f1
	  stb       r0, 0x70(r1)
	  fmuls     f0, f0, f31
	  stb       r6, 0x71(r1)
	  stb       r7, 0x72(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x190(r1)
	  lwz       r0, 0x194(r1)
	  stb       r0, 0x73(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x67(r26)
	  addi      r4, r1, 0x6C
	  lfd       f1, -0x7948(r2)
	  mr        r3, r27
	  stw       r0, 0x19C(r1)
	  lbz       r6, 0x66(r26)
	  stw       r25, 0x198(r1)
	  lbz       r5, 0x65(r26)
	  lfd       f0, 0x198(r1)
	  lbz       r0, 0x64(r26)
	  fsubs     f0, f0, f1
	  stb       r0, 0x6C(r1)
	  fmuls     f0, f0, f31
	  stb       r5, 0x6D(r1)
	  stb       r6, 0x6E(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x1A0(r1)
	  lwz       r0, 0x1A4(r1)
	  stb       r0, 0x6F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  sub       r22, r29, r24
	  stw       r22, 0x5C(r1)
	  sub       r23, r21, r20
	  add       r24, r29, r24
	  stw       r23, 0x60(r1)
	  add       r21, r21, r20
	  addi      r4, r1, 0x5C
	  stw       r24, 0x64(r1)
	  mr        r3, r27
	  stw       r21, 0x68(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7958(r2)
	  li        r20, 0x40
	  stb       r20, 0x58(r1)
	  li        r19, 0xC0
	  fmuls     f0, f0, f31
	  stb       r20, 0x59(r1)
	  addi      r4, r1, 0x58
	  addi      r3, r27, 0
	  fctiwz    f29, f0
	  stb       r19, 0x5A(r1)
	  li        r5, 0x1
	  stfd      f29, 0x180(r1)
	  lwz       r0, 0x184(r1)
	  stb       r0, 0x5B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r20, 0x54(r1)
	  addi      r4, r1, 0x54
	  addi      r3, r27, 0
	  stb       r20, 0x55(r1)
	  stfd      f29, 0x178(r1)
	  stb       r19, 0x56(r1)
	  lwz       r0, 0x17C(r1)
	  stb       r0, 0x57(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  stw       r22, 0x44(r1)
	  addi      r4, r1, 0x44
	  addi      r3, r27, 0
	  stw       r23, 0x48(r1)
	  stw       r24, 0x4C(r1)
	  stw       r21, 0x50(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xDC(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x5EC
	  lbz       r0, 0x63(r26)
	  li        r19, 0
	  lwz       r4, 0x2C(r26)
	  mulli     r3, r19, 0xE
	  stw       r0, 0x17C(r1)
	  lfd       f1, -0x7948(r2)
	  stw       r25, 0x178(r1)
	  addi      r0, r30, 0x8
	  sub       r21, r29, r0
	  lwz       r20, 0x4(r4)
	  lfd       f0, 0x178(r1)
	  li        r0, 0
	  fsubs     f0, f0, f1
	  stw       r0, 0xA0(r26)
	  add       r22, r31, r3
	  lfs       f29, -0x7968(r2)
	  addi      r23, r1, 0x34
	  fmuls     f0, f0, f30
	  lfs       f31, -0x7954(r2)
	  addi      r24, r1, 0x38
	  addi      r28, r1, 0x3C
	  fctiwz    f30, f0
	  addi      r25, r1, 0x40
	  b         .loc_0x51C

	.loc_0x364:
	  lwz       r0, 0x18(r20)
	  cmplwi    r0, 0
	  beq-      .loc_0x510
	  lwz       r0, 0x30(r26)
	  cmplw     r20, r0
	  bne-      .loc_0x424
	  lwz       r0, 0xAC(r26)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C8
	  li        r6, 0xC0
	  stfd      f30, 0x178(r1)
	  li        r5, 0
	  stb       r6, 0x40(r1)
	  mr        r3, r27
	  lwz       r0, 0x17C(r1)
	  mr        r4, r25
	  stb       r6, 0x41(r1)
	  stb       r5, 0x42(r1)
	  li        r5, 0x1
	  stb       r0, 0x43(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4AC

	.loc_0x3C8:
	  stw       r19, 0xA0(r26)
	  lfs       f1, 0x44(r26)
	  bl        0x1BD508
	  fadds     f0, f29, f1
	  stfd      f30, 0x180(r1)
	  mr        r3, r27
	  lwz       r0, 0x184(r1)
	  mr        r4, r28
	  fmuls     f0, f31, f0
	  li        r5, 0x1
	  fctiwz    f0, f0
	  stfd      f0, 0x178(r1)
	  lwz       r6, 0x17C(r1)
	  addi      r6, r6, 0x40
	  stb       r6, 0x3C(r1)
	  stb       r6, 0x3D(r1)
	  stb       r6, 0x3E(r1)
	  stb       r0, 0x3F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4AC

	.loc_0x424:
	  lbz       r0, 0x14(r20)
	  cmplwi    r0, 0
	  bne-      .loc_0x470
	  li        r6, 0xFF
	  stfd      f30, 0x178(r1)
	  li        r5, 0x80
	  stb       r6, 0x38(r1)
	  mr        r3, r27
	  lwz       r0, 0x17C(r1)
	  mr        r4, r24
	  stb       r6, 0x39(r1)
	  stb       r5, 0x3A(r1)
	  li        r5, 0x1
	  stb       r0, 0x3B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4AC

	.loc_0x470:
	  li        r6, 0x80
	  stfd      f30, 0x178(r1)
	  li        r5, 0x40
	  stb       r6, 0x34(r1)
	  mr        r3, r27
	  lwz       r0, 0x17C(r1)
	  mr        r4, r23
	  stb       r6, 0x35(r1)
	  stb       r5, 0x36(r1)
	  li        r5, 0x1
	  stb       r0, 0x37(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl

	.loc_0x4AC:
	  lwz       r5, 0x18(r20)
	  addi      r3, r1, 0x74
	  crclr     6, 0x6
	  subi      r4, r13, 0x6F30
	  bl        0x1B7CCC
	  lwz       r3, 0x9C(r26)
	  addi      r4, r1, 0x74
	  bl        -0x367A4
	  lwz       r0, 0xA8(r26)
	  cmpwi     r0, 0
	  bne-      .loc_0x4E8
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  sub       r5, r29, r0
	  b         .loc_0x4EC

	.loc_0x4E8:
	  mr        r5, r21

	.loc_0x4EC:
	  lwz       r12, 0x3B4(r27)
	  mr        r3, r27
	  lwz       r4, 0x9C(r26)
	  addi      r6, r22, 0
	  lwz       r12, 0xEC(r12)
	  crclr     6, 0x6
	  addi      r7, r1, 0x74
	  mtlr      r12
	  blrl

	.loc_0x510:
	  lwz       r20, 0x4(r20)
	  addi      r22, r22, 0xE
	  addi      r19, r19, 0x1

	.loc_0x51C:
	  lwz       r0, 0x40(r26)
	  cmpw      r19, r0
	  blt+      .loc_0x364
	  lwz       r0, 0xA0(r26)
	  li        r19, 0x80
	  addi      r4, r1, 0x30
	  stb       r19, 0x30(r1)
	  mulli     r3, r0, 0xE
	  stb       r19, 0x31(r1)
	  addi      r20, r3, 0x1
	  stb       r19, 0x32(r1)
	  mr        r3, r27
	  add       r20, r31, r20
	  stb       r19, 0x33(r1)
	  li        r5, 0x1
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xC0
	  stb       r0, 0x2C(r1)
	  addi      r4, r1, 0x2C
	  addi      r3, r27, 0
	  stb       r0, 0x2D(r1)
	  stb       r0, 0x2E(r1)
	  stb       r19, 0x2F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x48(r26)
	  addi      r0, r21, 0x4
	  addi      r4, r1, 0x1C
	  stw       r0, 0x1C(r1)
	  add       r3, r30, r3
	  addi      r5, r3, 0x4
	  stw       r20, 0x20(r1)
	  addi      r0, r20, 0xE
	  addi      r3, r27, 0
	  stw       r5, 0x24(r1)
	  stw       r0, 0x28(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xDC(r12)
	  mtlr      r12
	  blrl

	.loc_0x5EC:
	  lmw       r19, 0x1AC(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  lfd       f29, 0x1E0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005EA1C
 * Size:	000064
 */
void Menu::menuCloseMenu(Menu& menu)
{
	menu._28 = menu._20;
	menu.close();
	if (menu._28) {
		menu._28->open(false);
	}
}
