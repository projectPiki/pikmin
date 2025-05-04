#include "LifeGauge.h"
#include "Colour.h"
#include "sysNew.h"
#include "system.h"
#include "Light.h"
#include "Graphics.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "DebugLog.h"

static Colour lgborder;
static Colour lglev0;
static Colour lglev1;
static Colour lglev2;
static Colour lglev3;

LifeGaugeMgr* lgMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Gauges")

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GaugeInfo::init()
{
	_18 = 0;
	_34 = 0.0f;
	_3C = 0.0f;
	_38 = 0.0f;
	PRINT("gauge init\n");
	_24 = 0;
}

/*
 * --INFO--
 * Address:	8005B780
 * Size:	000150
 */
void GaugeInfo::update()
{
	switch (_18) {
	case 0: {
		_34 += gsys->getFrameTime() * 2.0f;

		if (_34 >= HALF_PI) {
			_18 = 1;
		}

		f32 rotation = _34 < HALF_PI ? _34 : HALF_PI;

		_3C = sinf(rotation) * 255.0f;
		_38 = sinf(rotation) * 30.0f;
		_40 = sinf(rotation) * 8.0f;
		_44 = sinf(rotation) * 8.0f;
		break;
	}

	case 1:
		if (_24) {
			_18 = 2;
		}
		break;

	case 2:
		_3C -= gsys->getFrameTime() * 1200.0f;
		if (_3C < 0.0f) {
			_3C = 0.0f;
			lgMgr->removeLG(this);
		}
	}
}

/*
 * --INFO--
 * Address:	8005B8D0, 100377F0 in DLL
 * Size:	000210
 */
void GaugeInfo::showDigits(Vector3f position, Colour& colour, int number, f32 width, f32 height)
{
	if (number > 99) {
		number = 99;
	}

	int num = number;

	// Either 1 or 2 digits (0-99)
	int numDigits = num >= 10 ? 2 : 1;

	// If 2 digits, move the position to the left
	if (numDigits == 2) {
		position.x += width * 1.5f * 0.5f;
	}

	for (int i = 0; i < numDigits; i++) {
		f32 divisor = 1 / 11.0f;
		f32 uvStart = (num % 10) * divisor;
		f32 uvEnd   = ((num % 10) + 1.0f) * divisor;

		lgMgr->mLFlare->addLFlare(colour, position, Vector2f(width, height), &Vector2f(uvStart, 0.0f), &Vector2f(uvEnd, 1.0f));

		num /= 10;
		position.x -= width * 1.5f;
	}
}

/*
 * --INFO--
 * Address:	8005BAE0
 * Size:	000270
 */
void GaugeInfo::refresh(Graphics& gfx)
{
	Vector3f pos(_14->mPosition.x, _14->mPosition.y + _38, _14->mPosition.z);
	pos.multMatrix(gfx.mCamera->mLookAtMtx);
	Colour colour;
	colour.set(255, 32, 32, (int)_3C);
	f32 a = (_1C < _20) ? 0.75f : 1.0f;
	f32 b = (_1C < _20) ? 1.0f : 0.75f;
	showDigits(pos, colour, _1C, _40 * a, _44 * a);
	pos.y += 10.0f;
	f32 c = 1.0f;
	f32 d = 10.0f / 11.0f;
	lgMgr->mLFlare->addLFlare(colour, pos, Vector2f(_40, _44), &Vector2f(d, 0.0f), &Vector2f(c, 1.0f));
	pos.y += 10.0f;
	colour.set(32, 32, 255, (int)_3C);
	showDigits(pos, colour, _20, _40 * b, _44 * b);

	u32 badCompiler;
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	8005BD50
 * Size:	0000F0
 */
void LifeGaugeMgr::init(int count)
{
	_00.initCore("");
	_48.initCore("");

	GaugeInfo* gaugeList = new GaugeInfo[count];

	for (int i = 0; i < count; i++) {
		_48.add(&gaugeList[i]);
	}

	mLFlare             = gsys->registerLFlare(gsys->loadTexture("intro/item_0_9.bti", true));
	mLFlare->mBlendMode = 5;
}

/*
 * --INFO--
 * Address:	8005BE94
 * Size:	000040
 */
void LifeGaugeMgr::update()
{
	FOREACH_NODE(GaugeInfo, _00.mChild, gauge)
	{
		gauge->update();
	}
}

/*
 * --INFO--
 * Address:	8005BED4
 * Size:	000068
 */
void LifeGaugeMgr::refresh(Graphics& gfx)
{
	// WTF
	if (!gameflow.mMoviePlayer->mIsActive) {
		FOREACH_NODE(GaugeInfo, _00.mChild, gauge)
		{
			gauge->refresh(gfx);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
GaugeInfo* LifeGaugeMgr::getGaugeInfo()
{
	if (_48.mChild) {
		GaugeInfo* info = (GaugeInfo*)_48.mChild;
		info->init();
		info->del();
		info->initCore("");
		return info;
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void LifeGaugeMgr::addLG(GaugeInfo* info)
{
	_00.add(info);
}

/*
 * --INFO--
 * Address:	8005BF3C
 * Size:	000060
 */
void LifeGaugeMgr::removeLG(GaugeInfo* info)
{
	info->del();
	info->initCore("");
	_48.add(info);
}

/*
 * --INFO--
 * Address:	8005BF9C
 * Size:	0000D8
 */
LifeGauge::LifeGauge()
{
	_1C          = 0;
	_18          = 0;
	_24          = 0.0f;
	_28          = 0.0f;
	_20          = 0;
	_30          = 1.0f;
	mHealthRatio = 1.0f;

	lgborder.set(0x80, 0x80, 0x80, 0xC0);
	lglev3.set(0x00, 0xFF, 0x00, 0xFF);
	lglev2.set(0x80, 0xFF, 0x00, 0xFF);
	lglev1.set(0xFF, 0xFF, 0x00, 0xFF);
	lglev0.set(0xFF, 0x00, 0x00, 0xFF);

	mOffset.set(0.0f, 100.0f, 0.0f);
	mScale = 48.0f;
	_38    = 0;
}

/*
 * --INFO--
 * Address:	8005C074
 * Size:	000030
 */
void LifeGauge::updValue(f32 currHealth, f32 maxHealth)
{
	mHealthRatio = currHealth / maxHealth;
	if (mHealthRatio < 1.0f && _24 != 1.0f) {
		_18 = 1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void LifeGauge::adjustValue()
{
	_30 += 2.0f * gsys->getFrameTime() * (mHealthRatio - _30);
	if (_20 || absF(_30 - mHealthRatio) < 1.0f / 64.0f) {
		_30 = mHealthRatio;
	}
}

/*
 * --INFO--
 * Address:	8005C0A4
 * Size:	000EC8
 */
void LifeGauge::refresh(Graphics& gfx)
{
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	switch (_18) {
	case 1:
		adjustValue();
		_24 += 2.0f * gsys->getFrameTime();
		if (_24 > 1.0f) {
			_24 = 1.0f;
			_18 = 2;
			_28 = 5.0f;
		}
		break;

	case 2:
		adjustValue();
		_28 -= gsys->getFrameTime();
		if (_28 <= 0.0f) {
			_28 = 0.0f;
			if (_1C == 0 || _30 <= 0.0f || _30 >= 1.0f) {
				_18 = 3;
			}
		}
		break;

	case 3:
		_24 -= 2.0f * gsys->getFrameTime();
		if (_24 < 0.0f) {
			_24 = 0.0f;
			_18 = 0;
		}
		break;
	}

	if (_18 == 0) {
		return;
	}

	Colour colour;
	if (_30 > 0.75f) {
		lglev3.lerpTo(lglev2, 1.0f - (_30 - 0.75f) / 0.25f, colour);
	} else if (_30 > 0.5f) {
		lglev2.lerpTo(lglev1, 1.0f - (_30 - 0.5f) / 0.25f, colour);
	} else if (_30 > 0.25f) {
		lglev1.lerpTo(lglev0, 1.0f - (_30 - 0.25f) / 0.25f, colour);
	} else {
		colour = lglev0;
	}

	gfx.useTexture(nullptr, 0);
	Vector3f pos1 = mPosition + mOffset;
	Vector3f pos2 = mPosition + mOffset;

	f32 proj1 = gfx.mCamera->projectWorldPoint(gfx, pos1);
	f32 proj2 = gfx.mCamera->projectWorldPoint(gfx, pos2);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setAuxColour(Colour(255, 255, 255, 255));

	u32 badCompiler[2];
	if (proj1 > 0.0f && proj2 > 0.0f) {
		if (_1C == 0) {
			gfx.setColour(Colour(lgborder.r, lgborder.g, lgborder.b, (int)(f32(lgborder.a) * _24)), true);
			gfx.setAuxColour(Colour(lgborder.r, lgborder.g, lgborder.b, (int)(f32(lgborder.a) * _24)));
			gfx.lineRectangle(RectArea(pos2.x - 19.0f, pos2.y - 10.0f, pos2.x + 19.0f, pos2.y - 6.0f));

			gfx.drawLine(Vector3f(pos2.x - 10.0f, pos2.y - 5.0f, 0.0f), Vector3f(pos1.x, pos1.y, 0.0f));
			gfx.drawLine(Vector3f(pos2.x - 5.0f, pos2.y - 5.0f, 0.0f), Vector3f(pos1.x, pos1.y, 0.0f));

			gfx.setColour(Colour(colour.r, colour.g, colour.b, (int)(f32(colour.a) * _24)), true);
			gfx.setAuxColour(Colour(colour.r, colour.g, colour.b, (int)(f32(colour.a) * _24)));
			gfx.fillRectangle(RectArea(pos2.x - 18.0f, pos2.y - 9.0f, pos2.x - 18.0f + (_30 * 37.0f), pos2.y - 7.0f));
			return;
		}

		f32 a = mScale * (1.0f - proj1);
		f32 b = a * 1.1666f;

		Vector3f vecs3D[4];
		Vector2f vecs2D[4];

		vecs2D[0].set(0.0f, 0.0f);
		vecs2D[1].set(0.0f, 0.0f);
		vecs2D[2].set(0.0f, 0.0f);
		vecs2D[3].set(0.0f, 0.0f);

		for (int i = 0; i < 32; i++) {
			f32 angle1 = f32(i) * (11.25f * PI / 180.0f);
			f32 angle2 = f32((i + 1) % 32) * (11.25f * PI / 180.0f);
			vecs3D[0].set(pos2.x, pos2.y, 0.0f);
			vecs3D[1].set(sinf(angle2) * -a + pos2.x, cosf(angle2) * -a + pos2.y, 0.0f);
			vecs3D[2].set(sinf(angle1) * -a + pos2.x, cosf(angle1) * -a + pos2.y, 0.0f);
			if ((_30 > 0.0f && i == 0) || i < int(32.0f * _30)) {
				gfx.setColour(colour, true);
				gfx.drawOneTri(vecs3D, nullptr, vecs2D, 3);
			} else {
				gfx.setColour(Colour(32, 32, 32, 192), true);
				gfx.drawOneTri(vecs3D, nullptr, vecs2D, 3);
			}

			vecs3D[0].set(sinf(angle2) * -a + pos2.x, cosf(angle2) * -a + pos2.y, 0.0f);
			vecs3D[1].set(sinf(angle2) * -b + pos2.x, cosf(angle2) * -b + pos2.y, 0.0f);
			vecs3D[2].set(sinf(angle1) * -b + pos2.x, cosf(angle1) * -b + pos2.y, 0.0f);
			vecs3D[3].set(sinf(angle1) * -a + pos2.x, cosf(angle1) * -a + pos2.y, 0.0f);

			gfx.setColour(Colour(0, 0, 0, 255), true);
			gfx.drawOneTri(vecs3D, nullptr, vecs2D, 4);
		}
	}
}

/*
 * --INFO--
 * Address:	8005CF6C
 * Size:	000148
 */
void LifeGauge::countOn(Vector3f& p1, int p2, int p3)
{
	if (!_38) {
		_30 = p2;
		_18 = 0;
		_28 = 0.0f;
		if (_38) {
			_38->_24 = 1;
			_38      = nullptr;
		}
		GaugeInfo* info = lgMgr->getGaugeInfo();
		if (info) {
			info->_14 = this;
			info->_1C = p2;
			info->_20 = p3;
			lgMgr->addLG(info);
			_38 = info;
		}
	} else {
		_38->_1C = p2;
		_38->_20 = p3;
	}

	mPosition = p1;
	if (_38) {
		_38->_28 = mPosition;
	}

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	8005D0B4
 * Size:	000030
 */
void LifeGauge::countOff()
{
	_18 = -1;
	_28 = 0.0f;
	if (_38) {
		_38->_24 = 1;
		_38      = nullptr;
	}
}
