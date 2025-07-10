#include "zen/ogRader.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "GoalItem.h"
#include "NaviMgr.h"
#include "P2D/Graph.h"
#include "P2D/Screen.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RadarInfo.h"
#include "SoundMgr.h"
#include "UfoItem.h"
#include "VersionGroups.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/ogSub.h"

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
DEFINE_PRINT("OgRaderSection")

namespace zen {
static f32 map_area_data[5][3] = { { -698.0f, 2024.0f, 2880.0f },
	                               { -334.0f, 2024.0f, 2880.0f },
	                               { -170.0f, 554.0f, 2654.0f },
	                               { -480.0f, 160.0f, 3950.0f },
	                               { -44.0f, 1504.0f, 2322.0f } };
}; // namespace zen

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
Vector3f zen::ogRaderMgr::ogCalcDispXZ(Vector3f in)
{
	Vector3f disp;

	f32 x  = in.x + 2800.0f;
	f32 z  = in.z + 4300.0f;
	disp.y = 0.0f;
	disp.x = x * 310.0f * 10.0f / 5400.0f;
	disp.z = z * 528.0f * 10.0f / 9200.0f;
	return disp;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::setOffsetSub(P2DPicture* pic)
{
	int x = pic->getWidth();
	int y = pic->getHeight();
	pic->setOffset(x / 2, y / 2);
}

/*
 * --INFO--
 * Address:	801850A0
 * Size:	000970
 */
zen::ogRaderMgr::ogRaderMgr()
{
	int i;
	P2DScreen* screen = new P2DScreen;

	PRINT("----- RADER MAP (%d) -----\n", flowCont.mCurrentStage->mStageID);
#if defined(VERSION_PIKIDEMO)
	switch (flowCont.mCurrentStage->mStageID) {
#else
	s16 stage = flowCont.mCurrentStage->mStageID;
	_24       = map_area_data[stage][0];
	_28       = map_area_data[stage][1];
	_2C       = map_area_data[stage][2];

	switch (stage) {
#endif
	case 0:
		_54 = 0;
		screen->set("screen/blo/p_map00.blo", true);
		_4C = (P2DPicture*)screen->search('map0', true);
		break;
	case 1:
		_54 = 1;
		screen->set("screen/blo/p_map01.blo", true);
		_4C = (P2DPicture*)screen->search('map1', true);
		break;
	case 2:
		_54 = 2;
		screen->set("screen/blo/p_map02.blo", true);
		_4C = (P2DPicture*)screen->search('map2', true);
		break;
	case 3:
		_54 = 3;
		screen->set("screen/blo/p_map03.blo", true);
		_4C = (P2DPicture*)screen->search('map3', true);
		break;
	case 4:
		_54 = 4;
		screen->set("screen/blo/p_map04.blo", true);
		_4C = (P2DPicture*)screen->search('map4', true);
		break;
	default:
		PRINT("----- UNKNOWN MAP !!! -----\n");
		_54 = 0;
		screen->set("screen/blo/p_map00.blo", true);
		_4C = (P2DPicture*)screen->search('map0', true);
		break;
	}

	_50         = new PikaAlphaMgr(screen);
	_450        = 0.0f;
	mMainScreen = screen;
	_58         = screen->search('root', true);
	_5C         = (P2DPicture*)screen->search('mbpi', true);
	_60         = (P2DPicture*)screen->search('mrpi', true);
	_64         = (P2DPicture*)screen->search('mypi', true);
	_68         = (P2DPicture*)screen->search('mmpi', true);
	_80         = (P2DPicture*)screen->search('part', true);
	_6C         = (P2DPicture*)screen->search('orim', true);
	_70         = (P2DPicture*)screen->search('mbci', true);
	_74         = (P2DPicture*)screen->search('mrci', true);
	_78         = (P2DPicture*)screen->search('myci', true);
	_7C         = (P2DPicture*)screen->search('mroi', true);

	setOffsetSub(_6C);
	setOffsetSub(_70);
	setOffsetSub(_74);
	setOffsetSub(_78);
	setOffsetSub(_7C);

	_5C->hide();
	_60->hide();
	_64->hide();
	_68->hide();
	_80->hide();
	_424 = screen->search('i_bs', true);
	Colour white(255, 255, 255, 255);
	Colour black(0, 0, 0, 0);

	PikiRaderEntry* data = _100;
	for (i = 0; i < MAX_PIKI_ON_FIELD; i++) {
		data->mPic = new P2DPicture(_5C->getTexture(0));
		_424->appendChild(data->mPic);
		data->mPic->move((i % 10) * 10 + 10, (i / 10) * 10 + 10);
		data->mPic->setScale(10.0f);
		data->mPic->setWhite(white);
		data->mPic->setBlack(black);
		data->mPic->hide();
		setOffsetSub(data->mPic);
		data++;
	}

	// hardcoded ship part count my beloved
	for (i = 0; i < MAX_UFO_PARTS; i++) {
		_84[i] = new P2DPicture(_80->getTexture(0));
		_424->appendChild(_84[i]);
		_84[i]->move((i % 10) * 10 + 10, (i / 10) * 10 + 10);
		_84[i]->setScale(7.5f);
		_84[i]->setWhite(white);
		_84[i]->setBlack(black);
		_84[i]->hide();
		setOffsetSub(_84[i]);
	}

	int w = _4C->getTexture(0)->mWidth;
	int h = _4C->getTexture(0)->mHeight;
	PRINT("MAP(%d,%d)\n", w, h);
	_4C->hide();
	_420 = _4C;
	_420->setOffset(0, 0);
	_424->setOffset(0, 0);
#if defined(VERSION_PIKIDEMO)
	_24demo[0].set(-150.0f, 0.0f, -160.0f);
	_24demo[1].set(150.0f, 0.0f, -160.0f);
	_24demo[2].set(150.0f, 0.0f, 160.0f);
	_24demo[3].set(-150.0f, 0.0f, 160.0f);
#endif
	_458 = 0;
	_420->setAlpha(_458);
	white.set(128, 128, 255, 255);
	_420->setWhite(white);
	_420->show();
	_424->show();
	setRaderScroll(0, 0);
	_428 = 2.0f;
	_34  = 0.0f;
	_38  = 0.0f;
	_454 = 0.0f;
	setRaderAngle(_454);
	mStatus = STATE_NULL;

	STACK_PAD_TERNARY(mStatus, 5);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::ogRaderMgr::setRaderScale(f32 scale)
{
	_428 = scale;
	_42C = scale;
	_420->setScale(_428);
	_424->setScale(_428 / 10.0f);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void zen::ogRaderMgr::chaseRaderScale(f32 scale)
{
	_428 += (scale - _428) / 5.0f;
	_420->setScale(_428);
	_424->setScale(_428 / 10.0f);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80185A10
 * Size:	00008C
 */
void zen::ogRaderMgr::setRaderAngle(f32 angle)
{
	_58->setOffset(_0C, _10);
	_58->rotate(P2DROTATE_Unk2, angle);
}

/*
 * --INFO--
 * Address:	80185A9C
 * Size:	000098
 */
void zen::ogRaderMgr::setRaderScroll(int x, int y)
{
	x += int(_0C);
	y += int(_10);
	_420->move(x, y);
	_424->move(x, y);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00025C
 */
void zen::ogRaderMgr::getOrimaPos()
{
	Navi* navi = naviMgr->getNavi();
	_430       = navi->getPosition();

	_43C = ogCalcDispXZ(_430);
	_448 = _43C.x;
	_44C = _43C.z;
	_6C->move(_448, _44C);
	_6C->setScale(10.0f / _428);
	_450 = PI - navi->mRotation.y;
	_6C->rotate(P2DROTATE_Unk2, _450);
	f32 x = (_428 * -(_43C.x + _34)) / 10.0f;
	f32 y = (_428 * -(_43C.z + _38)) / 10.0f;
	setRaderScroll(x, y);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
 */
void zen::ogRaderMgr::getContainerPos()
{
	for (int i = 0; i < 3; i++) {
		GoalItem* goal = itemMgr->getContainer(i);
		if (goal) {
			Vector3f pos  = goal->getPosition();
			Vector3f disp = ogCalcDispXZ(pos);
			_40[i]->move(disp.x, disp.z);
			_40[i]->setScale(10.0f / _428);
			_40[i]->show();
		} else {
			_40[i]->hide();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void zen::ogRaderMgr::getRocketPos()
{
	UfoItem* ufo = itemMgr->getUfo();

#if defined(VERSION_PIKIDEMO)
	_7C->hide();
	return;
#endif

	// Hmm, what a rather unfortunate lack of a nullptr check here.  If you wanted to use the radar in a test
	// map lacking the SS Dolphin, or wanted to re-enable the radar in Challenge Mode, this would be a problem.
	// Hiding the `P2DPicture` in this case aligns with what is seen in `getContainerPos`.
#if defined(BUGFIX)
	if (!ufo) {
		_7C->hide();
		return;
	}
#endif
	Vector3f pos  = ufo->getPosition();
	Vector3f disp = ogCalcDispXZ(pos);
	_7C->move(disp.x, disp.z);
	_7C->setScale(10.0f / _428);
}

/*
 * --INFO--
 * Address:	80185B34
 * Size:	000220
 */
void zen::ogRaderMgr::getPartsPos()
{
	for (int i = 0; i < MAX_UFO_PARTS; i++) {
		_84[i]->hide();
	}

	int i = 0;
	for (RadarInfo::PartsInfo* info = radarInfo->getFirst(); info; info = info->getNext()) {

		Vector3f inPos = info->getPos();
		Vector3f pos   = ogCalcDispXZ(inPos);
		_84[i]->show();
		_84[i]->move(pos.x, pos.z);
		_84[i]->setScale(7.5f / _428);
		i++;
	}
}

/*
 * --INFO--
 * Address:	80185D54
 * Size:	0004E4
 */
void zen::ogRaderMgr::getAllPikiPos()
{
	PikiRaderEntry* data = _100;
	_FC                  = 0;
	for (int i = 0; i < MAX_PIKI_ON_FIELD; i++) {
		data->mPic->hide();
		data++;
	}

	data = _100;
	Iterator iterator(pikiMgr);
	CI_LOOP(iterator)
	{
		Piki* piki = (Piki*)*iterator;
		if (piki->isAlive()) {
			Vector3f pos = ogCalcDispXZ(piki->mPosition);
			data->mColor = piki->mColor;
			data->mPic->show();
			data->mPic->move(pos.x, pos.z);
			data->mPic->setScale(10.0f / _428);
			data++;
			_FC++;
		}
	}

	Iterator iterator2(itemMgr->getPikiHeadMgr());
	CI_LOOP(iterator2)
	{
		PikiHeadItem* piki = (PikiHeadItem*)*iterator2;

		Vector3f pos = ogCalcDispXZ(piki->mPosition);
		data->mColor = -1;
		data->mPic->show();
		data->mPic->move(pos.x, pos.z);
		data->mPic->setScale(10.0f / _428);
		data++;
		_FC++;
	}
}

/*
 * --INFO--
 * Address:	80186238
 * Size:	0005D4
 */
void zen::ogRaderMgr::startSub()
{
	mStatus = STATE_4;
	_50->startFadeIn(0.5f);
	_458 = 0;
	_420->setAlpha(_458);
	setRaderScale(2.0f);
	PRINT("ogRader start!\n");

	_6C->alone();
	_424->appendChild(_6C);

	_40[0] = _70;
	_40[1] = _74;
	_40[2] = _78;
	for (int i = 0; i < 3; i++) {
		_40[i]->alone();
		_424->appendChild(_40[i]);
	}

	_7C->alone();
	_424->appendChild(_7C);

	getOrimaPos();
	getContainerPos();
	getRocketPos();
	getAllPikiPos();
	_34 = 0.0f;
	_38 = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void zen::ogRaderMgr::start()
{
	if (mStatus == -1) {
		_04  = 0;
		_45A = 64;
		_0C  = 320.0f;
		_10  = 220.0f;
		_1C  = 155;
		_20  = 264;
		_14  = 320 - _1C / 2;
		_18  = 220 - _20 / 2;
		startSub();
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80186854
 * Size:	000128
 */
void zen::ogRaderMgr::startMenu(P2DPane* pane)
{
	if (mStatus == -1 && (!playerState || playerState->hasRadar())) {
		_04  = 1;
		_00  = false;
		_01  = false;
		_02  = false;
		_45A = 200;

		int posH = pane->getPosH();
		int posV = pane->getPosV();
		int w    = pane->getWidth();
		int h    = pane->getHeight();
		_0C      = posH + w / 2;
		_10      = posV + h / 2;
		_1C      = w;
		_20      = h;
		_14      = posH;
		_18      = posV;
		startSub();
		setRaderScale(2.0f);
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	8018697C
 * Size:	000024
 */
void zen::ogRaderMgr::MapOn()
{
	if (!playerState || playerState->hasRadar()) {
		mStatus = STATE_0;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void zen::ogRaderMgr::MapOff()
{
	if (!playerState || playerState->hasRadar()) {
		mStatus = STATE_6;
	}
}

/*
 * --INFO--
 * Address:	801869A0
 * Size:	000168
 */
void zen::ogRaderMgr::updateGame(Controller* input)
{
	if (input->keyClick(KBBTN_DPAD_UP)) {
		switch (mStatus) {
		case 0:
			_42C    = 2.0f;
			mStatus = STATE_1;
			break;
		case 1:
			_42C    = 4.0f;
			mStatus = STATE_2;
			break;
		case 2:
			_42C    = 8.0f;
			mStatus = STATE_3;
			break;
		case 3:
			mStatus = STATE_5;
			_50->startFadeOut(0.2f);
			break;
		}
	} else if (input->keyDown(KBBTN_DPAD_LEFT) && _45A > 0) {
		_45A--;
		_458 = _45A;
		_420->setAlpha(_458);
	} else if (input->keyDown(KBBTN_DPAD_RIGHT) && _45A < 255) {
		_45A++;
		_458 = _45A;
		_420->setAlpha(_458);
	}

	chaseRaderScale(_42C);
}

#if defined(VERSION_PIKIDEMO)
#else
/*
 * --INFO--
 * Address:	80186B08
 * Size:	000100
 */
void zen::ogRaderMgr::AreaScroll(f32* p1, f32* p2, f32 p3, f32 p4)
{
	f32 a  = *p1 + p3;
	f32 b  = *p2 + p4;
	f32 c  = _24;
	f32 d  = _28;
	f32 x  = _430.x;
	f32 z  = _430.z;
	f32 x1 = a + x - c;
	f32 z1 = b + z - d;
	PRINT("scroll(%7.2f, %7.2f)  orima(%7.2f, %7.2f)  area(%7.2f, %7.2f)\n", p3, p4, _430.x, _430.z, _24, _28);
	f32 dist = std::sqrtf(x1 * x1 + z1 * z1);
	if (dist < _2C) {
		*p1 = a;
		*p2 = b;
		seSystem->playSysSe(SYSSE_YMENU_SCROLL);
		_00 = true;
	} else {
		seSystem->stopSysSe(SYSSE_YMENU_SCROLL);
		_00 = false;
	}
}
#endif

/*
 * --INFO--
 * Address:	80186C08
 * Size:	000298
 */
void zen::ogRaderMgr::updateMenu(Controller* input)
{
#if defined(VERSION_PIKIDEMO)
#else
	if (mStatus == -1) {
		return;
	}
#endif
	f32 x = _428;
	f32 y = input->getSubStickY();
	if (y > 0.3f) {
		x *= 1.1f;
		if (x > 10.0f) {
			x = 10.0f;
#if defined(VERSION_PIKIDEMO)
#else
			seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
			_01 = false;
#endif
		} else {
			if (!_01) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_MenuZoomIn);
			}
			_01 = true;
#else
				seSystem->playSysSe(SYSSE_YMENU_ZOOMIN);
				_01 = true;
			}
#endif
		}
	} else if (y < -0.3f) {
		x *= 0.9f;
		if (x < 1.0f) {
			x = 1.0f;
#if defined(VERSION_PIKIDEMO)
#else
			seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
			_02 = false;
#endif
		} else {
			if (!_02) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_MenuZoomOut);
			}
			_02 = true;
#else
				seSystem->playSysSe(SYSSE_YMENU_ZOOMOUT);
				_02 = true;
			}
#endif
		}
	}

	f32 c = cosf(_454);
	f32 s = sinf(_454);
	if (input->keyDown(KBBTN_MSTICK_UP)) {
#if defined(VERSION_PIKIDEMO)
		if (!_00) {
			seSystem->playSysSe(JACSYS_MenuScroll);
		}
		_00 = true;
		_34 -= 20.0f * s;
		_38 -= 20.0f * c;
#else
		AreaScroll(&_34, &_38, s * -20.0f, c * -20.0f);
#endif
	} else if (input->keyDown(KBBTN_MSTICK_DOWN)) {
#if defined(VERSION_PIKIDEMO)
		if (!_00) {
			seSystem->playSysSe(JACSYS_MenuScroll);
		}
		_00 = true;
		_34 += 20.0f * s;
		_38 += 20.0f * c;
#else
		AreaScroll(&_34, &_38, s * 20.0f, c * 20.0f);
#endif
	}
	if (input->keyDown(KBBTN_MSTICK_LEFT)) {
#if defined(VERSION_PIKIDEMO)
		if (!_00) {
			seSystem->playSysSe(JACSYS_MenuScroll);
		}
		_00 = true;
		_34 -= 20.0f * c;
		_38 += 20.0f * s;
#else
		AreaScroll(&_34, &_38, c * -20.0f, s * 20.0f);
#endif
	} else if (input->keyDown(KBBTN_MSTICK_RIGHT)) {
#if defined(VERSION_PIKIDEMO)
		if (!_00) {
			seSystem->playSysSe(JACSYS_MenuScroll);
		}
		_00 = true;
		_34 += 20.0f * c;
		_38 -= 20.0f * s;
#else
		AreaScroll(&_34, &_38, c * 20.0f, s * -20.0f);
#endif
	}

	if (_00 && !input->keyDown(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN | KBBTN_MSTICK_RIGHT | KBBTN_MSTICK_LEFT)) {
#if defined(VERSION_PIKIDEMO)
		seSystem->stopSysSe(JACSYS_MenuScroll);
#else
		seSystem->stopSysSe(SYSSE_YMENU_SCROLL);
#endif
		_00 = false;
	}

#if defined(VERSION_PIKIDEMO)
	if (_01 && !(y < 0.2f)) {
		seSystem->stopSysSe(JACSYS_MenuZoomIn);
		_01 = false;
	}
	if (_02 && !(y > -0.2f)) {
		seSystem->stopSysSe(JACSYS_MenuZoomOut);
		_02 = false;
	}
	if (_34 < -4096.0f) {
		_34 = -4096.0f;
	}
	if (_34 > 4096.0f) {
		_34 = 4096.0f;
	}
	if (_38 < -4096.0f) {
		_38 = -4096.0f;
	}
	if (_38 > 4096.0f) {
		_38 = 4096.0f;
	}
#else
	if (_01 && y < 0.2f) {
		seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
		_01 = false;
	}
	if (_02 && y > -0.2f) {
		seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
		_02 = false;
	}
#endif

	if (x != _428) {
		setRaderScale(x);
	}
}

/*
 * --INFO--
 * Address:	80186EA0
 * Size:	000748
 */
zen::ogRaderMgr::RaderStatus zen::ogRaderMgr::update(Controller* input)
{
	if (mStatus == STATE_NULL) {
		return mStatus;
	}

	if (mStatus == STATE_7) {
		mStatus = STATE_NULL;
		return mStatus;
	}

	if (mStatus == STATE_5) {
		if (_458 > 0) {
			_458 -= 10;
			if (_458 < 0) {
				_458 = 0;
			}
			_420->setAlpha(_458);
		} else {
			mStatus = STATE_7;
		}
		return mStatus;
	}

	if (mStatus == STATE_4) {
		if (_458 < _45A) {
			_458 += 10;
			if (_458 > _45A) {
				_458 = _45A;
			}
			_420->setAlpha(_458);
		} else {
			mStatus = STATE_0;
		}
		return mStatus;
	}

	_50->update();

	if (mStatus != STATE_6) {
		if (_04 == 0) {
			updateGame(input);
		} else if (_04 == 1) {
			updateMenu(input);
		}
	}

	getOrimaPos();
	getContainerPos();
	getRocketPos();
	getAllPikiPos();
	getPartsPos();

	PikiRaderEntry* data = _100;
	for (int i = 0; i < _FC; i++) {
		Colour col1;
		Colour col2;
		u8 alpha;
		switch (data->mColor) {
		case Blue:
			col1  = _5C->getWhite();
			col2  = _5C->getBlack();
			alpha = _5C->getAlpha();
			break;
		case Red:
			col1  = _60->getWhite();
			col2  = _60->getBlack();
			alpha = _60->getAlpha();
			break;
		case Yellow:
			col1  = _64->getWhite();
			col2  = _64->getBlack();
			alpha = _64->getAlpha();
			break;
		default: // seeds
			col1  = _68->getWhite();
			col2  = _68->getBlack();
			alpha = _68->getAlpha();
			break;
		}
		data->mPic->setWhite(col1);
		data->mPic->setBlack(col2);
		data->mPic->setAlpha(alpha);
		data++;
	}

	mMainScreen->update();

	return mStatus;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void zen::ogRaderMgr::RotatePos(f32* x, f32* y)
{
	Matrix4f mtx;
	mtx.makeIdentity();
	mtx.rotateZ(-_454);

	Vector3f pos;
	pos.x = *x;
	pos.y = *y;
	pos.z = 0.0f;
	pos.rotateTranspose(mtx);

	*x = pos.x;
	*y = pos.y;

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00045C
 */
void zen::ogRaderMgr::DrawCircle(u8, u8, u8, u8, f32)
{
	// No

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801875E8
 * Size:	00003C
 */
void zen::ogRaderMgr::end()
{
	mStatus = STATE_NULL;
	seSystem->stopSysSe(SYSSE_YMENU_SCROLL);
	seSystem->stopSysSe(SYSSE_YMENU_ZOOMIN);
	seSystem->stopSysSe(SYSSE_YMENU_ZOOMOUT);
}

/*
 * --INFO--
 * Address:	80187624
 * Size:	00016C
 */
void zen::ogRaderMgr::draw(Graphics& gfx)
{
	if (mStatus != STATE_NULL) {
		_454 = atan2f(-gfx.mCamera->mViewZAxis.x, -gfx.mCamera->mViewZAxis.z);
		setRaderAngle(_454);

		if (mStatus != STATE_6) {
			GXColor col = { 0 };
			GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, col);
			GXSetFogRangeAdj(GX_FALSE, 0, nullptr);
			P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
			graf.setPort();
			if (_04 == 1) {
				GXSetScissor(_14, _18, _1C, _20);
			}
			mMainScreen->draw(0, 0, &graf);
			if (_04 == 1) {
				GXSetScissor(0, 0, 640, 480);
			}
		}
	}
}
