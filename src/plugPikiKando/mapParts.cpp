#include "MapMgr.h"
#include "Font.h"
#include "DebugLog.h"
#include "Graphics.h"

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
DEFINE_PRINT("mapParts")

char* MapParts::shapeFiles[4] = {
	"mapparts/cone.mod",
	"mapparts/cylinder.mod",
	"mapparts/cube.mod",
	"mapparts/board.mod",
};

/*
 * --INFO--
 * Address:	801184A8
 * Size:	000018
 */
char* MapParts::getShapeFile(int idx)
{
	return shapeFiles[idx];
}

/*
 * --INFO--
 * Address:	801184C0
 * Size:	00005C
 */
void MapParts::applyVelocity(Plane&, Vector3f&, Vector3f& p3)
{
	mVelocity = mVelocity + p3;
}

/*
 * --INFO--
 * Address:	8011851C
 * Size:	000078
 */
MapEntity::MapEntity(Shape* shape)
    : MapParts(shape)
{
	mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80118594
 * Size:	000100
 */
void MapEntity::update()
{
	mPosition = mPosition + gsys->getFrameTime() * mVelocity;
	mVelocity = mVelocity - mVelocity * 0.1f;
	DynCollShape::update();
}

/*
 * --INFO--
 * Address:	80118694
 * Size:	0000D0
 */
MapSlider::MapSlider(Shape* shape, int p2, int p3, f32 p4, f32 p5, f32 p6, int p7)
    : MapParts(shape)
{
	_160           = p2;
	_164           = p3;
	_168           = p4;
	_16C           = p5;
	_170           = p6;
	_174           = p7;
	mFaceDirection = 0.0f;
}

/*
 * --INFO--
 * Address:	80118764
 * Size:	000040
 */
void MapSlider::init()
{
	if (mCurrentPart) {
		mPosition = mCurrentPart->mStartPosition;
		_180      = _168;
		_178      = 2;
		_17C      = 1;
	}
}

/*
 * --INFO--
 * Address:	801187A4
 * Size:	00036C
 */
void MapSlider::update()
{
	bool check1 = _20 >= _160;
	bool check2 = _20 >= _164;

	f32 val;
	if (_17C == 1) {
		val = _168;
	} else {
		val = _16C;
	}

	if (mCurrentPart) {
		mPosition = mPosition + mVelocity * gsys->getFrameTime();
		Vector3f vec;
		vec = (_17C == 1) ? mCurrentPart->mStartPosition : mCurrentPart->_0C;

		Vector3f dir = vec - mPosition;
		f32 dist     = dir.normalise();
		mVelocity    = dir * _170;

		switch (_178) {
		case 0:
		case 1:
			if (dist < 1.0f) {
				_178 = 3;
				_180 = val;
			}
			break;
		case 2:
			_180 -= gsys->getFrameTime();
			mVelocity.set(0.0f, 0.0f, 0.0f);
			if (_174 == 1 || _17C == 1) {
				if (_180 < 0.0f && check1) {
					_17C = (_17C == 1) ? 0 : 1;
					_178 = _17C;
				} else if (_160 >= 1 && !check1) {
					_180 = val;
				}
			} else if (_180 < 0.0f) {
				_17C = (_17C == 1) ? 0 : 1;
				_178 = _17C;
			}
			break;
		case 3:
			mVelocity.set(0.0f, 0.0f, 0.0f);
			if (!_20) {
				_178 = 2;
				_180 = val;
			}
			break;
		}
	} else {
		mFaceDirection += gsys->getFrameTime();
		mRotation.z = mFaceDirection * 0.5f;
		mPosition.x = mSliderPosition.x;
		mPosition.y = mSliderPosition.y;
		mPosition.z = mSliderPosition.z;
	}

	DynCollShape::update();
}

/*
 * --INFO--
 * Address:	80118B10
 * Size:	0001EC
 */
void MapSlider::refresh(Graphics& gfx)
{
	Vector3f textPos(0.0f, 20.0f, 0.0f);
	textPos.multMatrix(_DC);
	bool light = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useTexture(gsys->mConsFont->mTexture, 0);
	int blend = gfx.setCBlending(0);

	char buf[256];
	int dist = _160 - _20;
	if (dist < 0) {
		dist = 0;
	}

	sprintf(buf, "%d to go!\n", dist);
	int width = -(gsys->mConsFont->stringWidth(buf) / 2);
	gfx.perspPrintf(gsys->mConsFont, textPos, width, 0, buf);

	gfx.setCBlending(blend);
	gfx.setLighting(light, nullptr);
	gfx.useMatrix(_DC, 0);
	DynCollShape::refresh(gfx);
}
