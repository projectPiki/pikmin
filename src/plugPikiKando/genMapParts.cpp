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

char* shapeNames[] = { "box", "1", "2", "3", "log" };
char* kindNames[]  = { "slider", "entity", "dynamic" };

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
	_6C = input.readInt();
	_70 = input.readInt();
	_74 = input.readInt();
	if (_74 == 1) {
		_78.x = input.readFloat();
		_78.y = input.readFloat();
		_78.z = input.readFloat();

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
	if (_70 < numShapes) {
		shape = mapMgr->_74[_70];
	} else {
		shape = mapMgr->loadPlatshape(MapParts::getShapeFile(_70 - numShapes));
	}
	Matrix4f mtx;
	Vector3f globalPos = _78 + gen->getPos();
	static bool first  = true;
	if (first) {
		PRINT("render :: start (%.1f %.1f %.1f)\n", globalPos.x, globalPos.y, globalPos.z);
		PRINT(" start (%.1f %.1f %.1f) gen(%.1f %.1f %.1f)\n", _78.x, _78.y, _78.z, gen->getPos().x, gen->getPos().y, gen->getPos().z);
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

	if (_74 != 1) {
		return;
	}

	Vector3f pos3 = _78 + gen->getPos();
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
	PRINT("kind is %d\n", _6C);
	BaseShape* shape;
	if (_70 < numShapes) {
		shape = mapMgr->_74[_70];
	} else {
		shape = mapMgr->loadPlatshape(MapParts::getShapeFile(_70 - numShapes));
		if (!shape) {
			PRINT("failed to load %s\n", MapParts::getShapeFile(_70 - numShapes));
			ERROR("sorry");
		}
	}

	switch (_6C) {
	case 0:
		ent                     = new MapSlider((Shape*)shape, _18(), _28(), _38(), _48(), _58(), 0);
		((MapSlider*)ent)->_150 = info.mPosition;
		((MapSlider*)ent)->_15C = info.mRotation.y;
		break;
	case 1:
		ent       = new MapEntity((Shape*)shape);
		ent->_134 = info.mPosition;
		ent->_128 = info.mRotation;
		break;
	case 2:
		return nullptr;
	}

	PRINT("CREATING MAP PARTS #### mp = %x\n", ent);

	if (ent) {
		if (_74 == 1) {
			MapPartsPart* part = new MapPartsPart(); // this is wrong
			part->_00          = _78 + info.mPosition;
			part->_0C          = _84 + info.mPosition;
			PRINT("start(%.1f %.1f %.1f)\n", part->_00.x, part->_00.y, part->_00.z);
			PRINT("start (%.1f %.1f %.1f) + info(%.1f %.1f %.1f)\n", _78.x, _78.y, _78.z, info.mPosition.x, info.mPosition.y,
			      info.mPosition.z);
			ent->_140 = part;
		}
		ent->init();
		mapMgr->mCollShape->add(ent);
	}

	return nullptr;
}
