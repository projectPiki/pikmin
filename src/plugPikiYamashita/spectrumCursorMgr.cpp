#include "zen/SpectrumCursorMgr.h"
#include "zen/Math.h"
#include "zen/DrawCommon.h"
#include "nlib/Math.h"
#include "P2D/Pane.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("spectrumCursorMgr")

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void zen::SpectrumCursorMgr::setMirror(P2DPane* pane)
{
	if (pane->getRotate() > HALF_PI && pane->getRotate() < 3.0f * HALF_PI) {
		P2DPaneLibrary::setFamilyMirror(pane, P2DMIRROR_Unk2);
	} else {
		P2DPaneLibrary::setFamilyMirror(pane, P2DMIRROR_Unk0);
	}
}

/*
 * --INFO--
 * Address:	801DA814
 * Size:	000394
 */
void zen::SpectrumCursorMgr::update()
{
	f32 t, tComp;
	for (int i = _00 - 1; i > 0; i--) {
		_04[i]->move(_04[i - 1]->getPosH(), _04[i - 1]->getPosV());
		_04[i]->rotate(P2DROTATE_Y, _04[i - 1]->getRotate());
		setMirror(_04[i]);
		_04[i]->setScale(_04[0]->getScale());
	}

	if (_08 < _0C) {
		_08 += gsys->getFrameTime();
		if (_08 > _0C) {
			_08 = _0C;
		}
		t     = NMathF::sin(_08 / _0C * HALF_PI);
		tComp = 1.0f - t;
		_04[0]->move(RoundOff(_18 * t + _10 * tComp), RoundOff(_1C * t + _14 * tComp));
	}

	if (_20 < _24) {
		_20 += gsys->getFrameTime();
		if (_20 > _24) {
			_20 = _24;
		}
		t     = NMathF::sin(_20 / _24 * HALF_PI);
		tComp = 1.0f - t;
		_04[0]->setScale(_28 * tComp + _2C * t);
	}

	t = _04[0]->getRotate() + gsys->getFrameTime() * 10.0f;
	if (t > TAU) {
		t -= TAU;
	} else if (t < 0.0f) {
		t += TAU;
	}

	_04[0]->rotate(P2DROTATE_Y, t);
	setMirror(_04[0]);
}

/*
 * --INFO--
 * Address:	801DABA8
 * Size:	000070
 */
void zen::SpectrumCursorMgr::move(f32 x, f32 y, f32 p3)
{
	_08 = 0.0f;
	_0C = p3;
	_10 = _04[0]->getPosH();
	_14 = _04[0]->getPosV();
	_18 = x;
	_1C = y;
}

/*
 * --INFO--
 * Address:	801DAC18
 * Size:	000024
 */
void zen::SpectrumCursorMgr::scale(f32 p1, f32 p2)
{
	_20 = 0.0f;
	_24 = p2;
	_28 = _04[0]->getScale().x;
	_2C = p1;
}

/*
 * --INFO--
 * Address:	801DAC3C
 * Size:	000374
 */
void zen::SpectrumCursorMgr::init(P2DScreen* screen, P2DPane* parent, u32 p3, f32 p4, f32 p5)
{
	char buf[8];
	_00        = 0;
	*(u32*)buf = makeTag(p3, _00);
	while (screen->search(P2DPaneLibrary::makeTag(buf), false)) {
		_00++;
		*(u32*)buf = makeTag(p3, _00);
	}

	if (_00 == 0) {
		PRINT("残像ペインがありませんなァ。逝ってよし！\n"); // 'there's no spectrum pane - get outta here!'
		ERROR("no spectrum pane.");
	}

	_04 = new P2DPane*[_00];

	for (int i = _00 - 1; i >= 0; i--) {
		*(u32*)buf    = makeTag(p3, i);
		P2DPane* pane = screen->search(P2DPaneLibrary::makeTag(buf), true);
		if (pane->getTypeID() == PANETYPE_Picture) {
			_04[i] = pane;
			P2DPaneLibrary::changeParent(_04[i], parent);
			_04[i]->setOffset(_04[i]->getWidth() >> 1, _04[i]->getHeight() >> 1);
			_04[i]->show();
			_04[i]->setScale(0.0f);

			if (i == 0) {
				P2DPaneLibrary::setFamilyAlpha(_04[i], 255);
			} else {
				P2DPaneLibrary::setFamilyAlpha(_04[i], RoundOff((1.0f - f32(i) / f32(_00)) * 100.0f));
			}
		} else {
			PRINT("not picture pane.\n");
			ERROR("not picture pane.\n");
		}
	}

	initPos(p4, p5);
	initScale(0.0f);
	move(_04[0]->getPosH(), _04[0]->getPosV(), 0.0f);
	scale(1.0f, 0.5f);
}

/*
 * --INFO--
 * Address:	801DAFB0
 * Size:	000108
 */
void zen::SpectrumCursorMgr::initPos(f32 x, f32 y)
{
	for (int i = 0; i < _00; i++) {
		_04[i]->move(RoundOff(x), RoundOff(y));
	}
	_18 = x;
	_1C = y;
}

/*
 * --INFO--
 * Address:	801DB0B8
 * Size:	00004C
 */
void zen::SpectrumCursorMgr::initScale(f32 scale)
{
	_08 = 0.0f;
	_0C = 0.0f;
	for (int i = 0; i < _00; i++) {
		_04[i]->setScale(scale);
	}
	_28 = scale;
	_2C = scale;
}

/*
 * --INFO--
 * Address:	801DB104
 * Size:	000048
 */
u32 zen::SpectrumCursorMgr::makeTag(u32 tag, int idx)
{
	u8 buf[8];
	sprintf((char*)buf, "*%02d*", idx);
	buf[0] = tag >> 24;
	buf[3] = tag & 0xFF;
	return *(u32*)buf;
}
