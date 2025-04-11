#include "Generator.h"
#include "MapMgr.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "sysNew.h"
#include "GlobalShape.h"

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
DEFINE_PRINT("genMapParts")

MapMgr* GenObjectMapParts::mapMgr;
int numShapes = 5;

static char* shapeNames[] = { "box", "1", "2", "3", "log" };
static char* kindNames[]  = { "slider", "entity", "dynamic" };

/*
 * --INFO--
 * Address:	8011785C
 * Size:	0001C0
 */
static GenObject* makeObjectMapParts()
{
	return new GenObjectMapParts;
}

/*
 * --INFO--
 * Address:	80117A1C
 * Size:	000090
 */
void GenObjectMapParts::initialise(MapMgr* mgr)
{
	mapMgr = mgr;
	GenObjectFactory::factory->registerMember('mpar', makeObjectMapParts, "マップパーツを発生", 'v0.0');
}

/*
 * --INFO--
 * Address:	80117AAC
 * Size:	000118
 */
void GenObjectMapParts::doRead(RandomAccessStream& input)
{
	mPartKind       = input.readInt();
	mShapeIndex     = input.readInt();
	mUseStartOffset = input.readInt();
	if (mUseStartOffset == 1) {
		mStartPosition.x = input.readFloat();
		mStartPosition.y = input.readFloat();
		mStartPosition.z = input.readFloat();

		_84.x = input.readFloat();
		_84.y = input.readFloat();
		_84.z = input.readFloat();
	}
}

/*
 * --INFO--
 * Address:	80117BC4
 * Size:	000664
 */
void GenObjectMapParts::render(Graphics& gfx, Generator* gen)
{
	Matrix4f mtx0;
	Matrix4f mtx4;
	Vector3f scale;
	f32 scl = 0.2f;
	scale.set(scl, scl, scl);
	// int id = _70;
	BaseShape* shape;
	if (mShapeIndex < numShapes) {
		shape = mapMgr->mMapPartShapes[mShapeIndex];
	} else {
		shape = mapMgr->loadPlatshape(MapParts::getShapeFile(mShapeIndex - numShapes));
	}
	Matrix4f mtx;
	Vector3f globalPos = mStartPosition + gen->getPos();
	static bool first  = true;
	if (first) {
		PRINT("render :: start (%.1f %.1f %.1f)\n", globalPos.x, globalPos.y, globalPos.z);
		PRINT(" start (%.1f %.1f %.1f) gen(%.1f %.1f %.1f)\n", mStartPosition.x, mStartPosition.y, mStartPosition.z, gen->getPos().x,
		      gen->getPos().y, gen->getPos().z);
		first = false;
	}
	Matrix4f mtx2;
	mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), globalPos);
	gfx.calcViewMatrix(mtx2, mtx);
	gfx.useMatrix(mtx, 0);
	gfx.setLighting(true, nullptr);
	shape->drawshape(gfx, *gfx.mCamera, nullptr);

	globalPos = _84 + gen->getPos();
	mtx2.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), globalPos);
	gfx.calcViewMatrix(mtx2, mtx);
	gfx.useMatrix(mtx, 0);
	shape->drawshape(gfx, *gfx.mCamera, nullptr);

	if (mUseStartOffset != 1) {
		return;
	}

	Vector3f pos3 = mStartPosition + gen->getPos();
	mtx0.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), pos3);
	gfx.calcViewMatrix(mtx0, mtx4);
	gfx.useMatrix(mtx4, 0);

	Colour color1;
	color1.set(255, 0, 0, 255);
	GlobalShape::markerShape->mMaterialList->Colour() = color1;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);
	Vector3f globalPos2 = _84 + gen->getPos();
	mtx0.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), globalPos2);
	gfx.calcViewMatrix(mtx0, mtx4);
	gfx.useMatrix(mtx4, 0);

	color1.set(0, 0, 255, 255);
	GlobalShape::markerShape->mMaterialList->Colour() = color1;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

	bool light = gfx.setLighting(false, nullptr);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useTexture(nullptr, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setAuxColour(Colour(255, 255, 255, 255));
	gfx.drawLine(pos3, globalPos2);
	gfx.setLighting(light, nullptr);
}

/*
 * --INFO--
 * Address:	80118228
 * Size:	00027C
 */
Creature* GenObjectMapParts::birth(BirthInfo& info)
{
	MapParts* ent = nullptr;
	PRINT("kind is %d\n", mPartKind);
	BaseShape* shape;
	if (mShapeIndex < numShapes) {
		shape = mapMgr->mMapPartShapes[mShapeIndex];
	} else {
		shape = mapMgr->loadPlatshape(MapParts::getShapeFile(mShapeIndex - numShapes));
		if (!shape) {
			PRINT("failed to load %s\n", MapParts::getShapeFile(mShapeIndex - numShapes));
			ERROR("sorry");
		}
	}

	switch (mPartKind) {
	case 0: // Slider
		ent                                = new MapSlider((Shape*)shape, _18(), _28(), _38(), _48(), _58(), 0);
		((MapSlider*)ent)->mSliderPosition = info.mPosition;
		((MapSlider*)ent)->mFaceDirection  = info.mRotation.y;
		break;
	case 1: // Entity
		ent            = new MapEntity((Shape*)shape);
		ent->mPosition = info.mPosition;
		ent->mRotation = info.mRotation;
		break;
	case 2: // Dynamic
		return nullptr;
	}

	PRINT("CREATING MAP PARTS #### mp = %x\n", ent);

	if (ent) {
		if (mUseStartOffset == 1) {
			MapPartsPart* part   = new MapPartsPart(); // this is wrong
			part->mStartPosition = mStartPosition + info.mPosition;
			part->mEndPosition   = _84 + info.mPosition;
			PRINT("start(%.1f %.1f %.1f)\n", part->mStartPosition.x, part->mStartPosition.y, part->mStartPosition.z);
			PRINT("start (%.1f %.1f %.1f) + info(%.1f %.1f %.1f)\n", mStartPosition.x, mStartPosition.y, mStartPosition.z, info.mPosition.x,
			      info.mPosition.y, info.mPosition.z);
			ent->mCurrentPart = part;
		}
		ent->init();
		mapMgr->mCollShape->add(ent);
	}

	return nullptr;
}
