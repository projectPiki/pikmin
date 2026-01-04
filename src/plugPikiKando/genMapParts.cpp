#include "Age.h"
#include "DebugLog.h"
#include "Generator.h"
#include "GlobalShape.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(9)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("genMapParts")

MapMgr* GenObjectMapParts::mapMgr;
int numShapes = 5;

static char* shapeNames[] = { "box", "1", "2", "3", "log" };

#ifdef WIN32
int numKinds             = 3;
static char* partNames[] = { "mapparts/cone.mod", "mapparts/cylinder.mod", "mapparts/cube.mod", "mapparts/board.mod" };
int numParts             = 4;
#endif
static char* kindNames[] = { "slider", "entity", "dynamic" };

/**
 * @todo: Documentation
 */
static GenObject* makeObjectMapParts()
{
	return new GenObjectMapParts;
}

/**
 * @todo: Documentation
 */
void GenObjectMapParts::initialise(MapMgr* mgr)
{
	mapMgr = mgr;
	GenObjectFactory::factory->registerMember('mpar', makeObjectMapParts, "マップパーツを発生", 'v0.0');
}

/**
 * @todo: Documentation
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

		mEndPosition.x = input.readFloat();
		mEndPosition.y = input.readFloat();
		mEndPosition.z = input.readFloat();
	}
}

/**
 * @todo: Documentation
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
		shape = mapMgr->mPartShapes[mShapeIndex];
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

	globalPos = mEndPosition + gen->getPos();
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
	Vector3f globalPos2 = mEndPosition + gen->getPos();
	mtx0.makeSRT(scale, Vector3f(0.0f, 0.0f, 0.0f), globalPos2);
	gfx.calcViewMatrix(mtx0, mtx4);
	gfx.useMatrix(mtx4, 0);

	color1.set(0, 0, 255, 255);
	GlobalShape::markerShape->mMaterialList->Colour() = color1;
	GlobalShape::markerShape->drawshape(gfx, *gfx.mCamera, nullptr);

	bool light = gfx.setLighting(false, nullptr);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(COLOUR_WHITE, true);
	gfx.setAuxColour(COLOUR_WHITE);
	gfx.drawLine(pos3, globalPos2);
	gfx.setLighting(light, nullptr);
}

/**
 * @todo: Documentation
 */
Creature* GenObjectMapParts::birth(BirthInfo& info)
{
	MapParts* ent = nullptr;
	PRINT("kind is %d\n", mPartKind);
	BaseShape* shape;
	if (mShapeIndex < numShapes) {
		shape = mapMgr->mPartShapes[mShapeIndex];
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
			LinePath* path       = new LinePath();
			path->mStartPosition = mStartPosition + info.mPosition;
			path->mEndPosition   = mEndPosition + info.mPosition;
			PRINT("start(%.1f %.1f %.1f)\n", path->mStartPosition.x, path->mStartPosition.y, path->mStartPosition.z);
			PRINT("start (%.1f %.1f %.1f) + info(%.1f %.1f %.1f)\n", mStartPosition.x, mStartPosition.y, mStartPosition.z, info.mPosition.x,
			      info.mPosition.y, info.mPosition.z);
			ent->mLinePath = path;
		}
		ent->init();
		mapMgr->mCollShape->add(ent);
	}

	return nullptr;
}

#ifdef WIN32
void GenObjectMapParts::doGenAge(AgeServer& server)
{
	server.StartOptionBox("マップパーツ", &mPartKind, 252); // Map Parts
	for (int i = 0; i < numKinds; i++) {
		server.NewOption(kindNames[i], i);
	}
	server.EndOptionBox();

	server.StartOptionBox("シェイプ", &mShapeIndex, 252);
	for (int i = 0; i < numShapes; i++) {
		server.NewOption(shapeNames[i], i);
	}
	for (int i = 0; i < numParts; i++) {
		server.NewOption(partNames[i], i + numShapes);
	}
	server.EndOptionBox();

	server.setOnChange(new Delegate1<GenObjectMapParts, AgeServer&>(this, refreshSection));
	server.StartOptionBox("移動形態", &mUseStartOffset, 252); // "movement type"
	server.NewOption("固定", 0);                              // "Fixed"
	server.NewOption("ライン", 1);                            // "Line"
	server.EndOptionBox();
	server.setOnChange((IDelegate*)nullptr);

	if (mUseStartOffset == 1) {
		server.NewLabel("始点オフセット"); // "Starting point offset"
		server.NewEditor("x", &mStartPosition.x, -1000.0f, 1000.0f, 320);
		server.NewEditor("y", &mStartPosition.y, -1000.0f, 1000.0f, 320);
		server.NewEditor("z", &mStartPosition.z, -1000.0f, 1000.0f, 320);
		server.NewLabel("終点オフセット"); // "End point offset"
		server.NewEditor("x", &mEndPosition.x, -1000.0f, 1000.0f, 320);
		server.NewEditor("y", &mEndPosition.y, -1000.0f, 1000.0f, 320);
		server.NewEditor("z", &mEndPosition.z, -1000.0f, 1000.0f, 320);
	}
}

void GenObjectMapParts::refreshSection(AgeServer& server)
{
	server.RefreshSection();
}

#endif
