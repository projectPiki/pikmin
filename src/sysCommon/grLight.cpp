#include "Light.h"
#include "Camera.h"

static char file[] = __FILE__;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
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
 * Address:	80029A48
 * Size:	000200
 */
Light::Light()
    : CoreNode("light")
{
	_1C9 = 0;
	_1D8.set(0.0f, 0.0f, 0.0f);
	_240 = 60.0f;
	_244 = 1.0f;
	_248 = 1000.0f;
	_14  = 770;
	_24  = 3;
	_18  = 3005.0f;
	_1C  = 0.5036f;
	_28  = 2;
	_20  = 45.0f;
	_2C  = 0.0f;
	_30  = 0.0f;
	_34  = 0.99559999f;
	_38  = 1.0f;
	_3C  = 0.0f;
	_40  = 0.0f;
	_48  = 0.15f;
	_44  = 0.05f;
	_54.set(0.0f, 100.0f, 0.0f);
	_60.set(0.0f, -1.0f, 0.0f);
	_6C = 255;
	_6D = 255;
	_6E = 255;
	_6F = 255;

	setLightDistAttn(_18, _1C, _24);
}

/*
 * --INFO--
 * Address:	80029C5C
 * Size:	0000E4
 */
void Light::setLightDistAttn(f32 p1, f32 p2, int p3)
{
	_18 = p1;
	_1C = p2;
	_24 = p3;

	if (p1 < 0.0f) {
		p3 = 0;
	}
	if (p2 <= 0.0f || p2 >= 1.0f) {
		p3 = 0;
	}

	f32 val1;
	f32 val3;
	f32 val2;
	switch (p3) {
	case 1:
		val1 = 1.0f;
		val2 = 0.0f;
		val3 = (1.0f - p2) / (p2 * p1);
		break;
	case 2:
		val1 = 1.0f;
		val3 = 0.5f * (1.0f - p2) / (p2 * p1);
		val2 = 0.5f * (1.0f - p2) / (p1 * (p2 * p1));
		break;
	case 3:
		val1 = 1.0f;
		val3 = 0.0f;
		val2 = (1.0f - p2) / (p1 * (p2 * p1));
		break;
	case 0:
	default:
		val1 = 1.0f;
		val3 = 0.0f;
		val2 = 0.0f;
		break;
	}

	_2C = val1;
	_30 = val3;
	_34 = val2;
	_70 = 1;
}

/*
 * --INFO--
 * Address:	80029D40
 * Size:	000188
 */
void Light::setLightSpot(f32 p1, int p2)
{
	if (p1 <= 0.0f || p1 > 90.0f) {
		p2 = 0;
	}
	f32 cosTheta = cosf((PI * p1) / 180.0f);
	f32 val38; // f5
	f32 val3C; // f2
	f32 val40; // f3
	switch (p2) {
	case 1:
		val38 = -1000.0f * cosTheta;
		val3C = 1000.0f;
		val40 = 0.0f;
		break;
	case 2:
		val38 = -cosTheta / (1.0f - cosTheta);
		val3C = 1.0f / (1.0f - cosTheta);
		val40 = 0.0f;
		break;
	case 3:
		val38 = 0.0f;
		val3C = -cosTheta / (1.0f - cosTheta);
		val40 = 1.0f / (1.0f - cosTheta);
		break;
	case 4:
		f32 tmp = SQUARE(1.0f - cosTheta);
		val38   = (cosTheta * (cosTheta - 2.0f)) / tmp;
		val3C   = 2.0f / tmp;
		val40   = -1.0f / tmp;
		break;
	case 5:
		val38 = -4.0f * cosTheta / SQUARE(1.0f - cosTheta);
		val3C = 4.0f * (1.0f + cosTheta) / SQUARE(1.0f - cosTheta);
		val40 = -4.0f / SQUARE(1.0f - cosTheta);
		break;
	case 6:
		val38 = 1.0f - (2.0f * cosTheta * cosTheta) / SQUARE(1.0f - cosTheta);
		val3C = 4.0f * cosTheta / SQUARE(1.0f - cosTheta);
		val40 = -2.0f / SQUARE(1.0f - cosTheta);
		break;
	case 0:
	default:
		val38 = 1.0f;
		val3C = 0.0f;
		val40 = 0.0f;
		break;
	}

	_38 = val38;
	_3C = val3C;
	_40 = val40;
	_70 = 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Light::setLightParallel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000218
 */
void Light::calcLightSizes()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Light::calcLightMapRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Light::calcLightObjRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C4
 */
void Light::refresh(Graphics&, LFlareGroup*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80029EC8
 * Size:	0000D0
 */
void Light::update()
{
	switch (_14 & 0xFF) {
	case 1:
		_2C = 1.0f;
		_30 = _34 = 0.0f;
		_38       = 1.0f;
		_3C = _40 = 0.0f;
		_70       = 1;
		break;
	case 2:
		setLightDistAttn(_18, _1C, _24);
		_38 = 1.0f;
		_3C = _40 = 0.0f;
		break;
	case 3:
		setLightSpot(_20, _28);
		_2C = 1.0f;
		_30 = _34 = 0.0f;
		break;
	}
}
