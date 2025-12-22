#include "PlantMgr.h"
#include "Age.h"
#include "CreatureProp.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Generator.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "sysNew.h"

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
DEFINE_PRINT("plantMgr");

PlantMgr* plantMgr;

Plant::Plant()
    : AICreature(nullptr)
{
	mObjType   = OBJTYPE_Plant;
	mPlantType = PLANT_NULL;
	mCollInfo  = new CollInfo(8);
	mSearchBuffer.init(mPlantSearchData, 3);
}

void Plant::startMotion(int motionID)
{
	mPlantAnimator.startMotion(PaniMotionInfo(motionID, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void Plant::reset(int plantType)
{
	_394                    = true;
	mObjType                = OBJTYPE_Plant;
	mPlantType              = plantType;
	PlantShapeObject* shape = plantMgr->mPlantShapes[plantType];
	mPlantAnimator.init(&shape->mAnimContext, shape->mAnimMgr, plantMgr->mMotionTable);
	mMotionSpeed = 0.0f;
	mCollInfo->initInfo(shape->mShape, nullptr, nullptr);
	mStateMachine = plantMgr->mAI;
}

void Plant::startAI(int)
{
	mIsCulled = false;
	mapMgr    = plantMgr->mMapMgr;
	mProps    = plantMgr->mPlantProps;
	startMotion(PlantMotion::Touch);
	mMotionSpeed = 0.0f;
	mPlantAnimator.startMotion(PaniMotionInfo(PlantMotion::Touch));
	mSRT.t.y = mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true);
	plantMgr->mAI->start(this, PlantAI::STATE_Wait);
	if (mPlantType == PLANT_Mizukusa) {
		mMotionSpeed = 30.0f;
	}
}

void Plant::doAnimation()
{
	mPlantAnimator.animate(mMotionSpeed);
}

void Plant::update()
{
	if (mIsCulled) {
		return;
	}

	mGrid.updateGrid(mSRT.t);
	mGrid.updateAIGrid(mSRT.t, false);
	if (mPlantType == PLANT_Hae || mPlantType == PLANT_Mizukusa || !mGrid.aiCulling()) {
		doAnimation();
		plantMgr->mAI->exec(this);
	}
}

void Plant::refresh(Graphics& gfx)
{
	PlantShapeObject* shape = plantMgr->mPlantShapes[mPlantType];
	if (!mPlantAnimator.mAnimInfo) {
		return;
	}

	if (mCollInfo->hasInfo()) {

		f32 rad = 2.0f * getBoundingSphereRadius();
		if (rad > 0.0f) {
			BoundBox box(Vector3f(mSRT.t.x - rad, mSRT.t.y, mSRT.t.z - rad),
			             Vector3f(mSRT.t.x + rad, mSRT.t.y + 2.0f * rad, mSRT.t.z + rad));

			if (!gfx.mCamera->isBoundVisible(box, 0x8000 | 0x20 | 0x10 | 0x1 | 0x2 | 0x4 | 0x8) && !_394) {
				C_SAI(this)->start(this, PlantAI::STATE_Wait);
				mIsCulled = true;
				return;
			}
		}
	}

	mIsCulled = false;
	_394      = false;
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);

	mPlantAnimator.updateContext();
	shape->mShape->updateAnim(gfx, mtx, nullptr);

	gfx.useMatrix(Matrix4f::ident, 0);
	shape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

void Plant::doKill()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
PlantAI::PlantAI()
{
	OpponentMove* oppMove = new OpponentMove();
	create(STATE_COUNT);
	addState(STATE_Wait, PANI_NO_MOTION, new WaitInit());
	addState(STATE_Touch, PANI_NO_MOTION, new TouchInit());
	addArrow(STATE_Wait, saiCollideEvent, STATE_Touch)->addCondition(oppMove);
	addArrow(STATE_Touch, saiMotionDoneEvent, STATE_Wait);
}

bool PlantAI::OpponentMove::satisfy(AICreature* plant)
{
	Creature* collider = plant->mCollidingCreature;
	f32 dist           = collider->mVelocity.length();
	if (dist > 40.0f) {
		return true;
	}

	return false;
}

void PlantAI::WaitInit::act(AICreature* plant)
{
	STACK_PAD_VAR(1);

	if (static_cast<Plant*>(plant)->mPlantType == PLANT_Mizukusa) {
		plant->startMotion(PlantMotion::Touch);
		plant->setMotionSpeed(30.0f);
	} else {
		plant->startMotion(PlantMotion::Touch);
		plant->stopMotion();
	}
}

void PlantAI::TouchInit::act(AICreature* plant)
{
	STACK_PAD_VAR(1);
	if (static_cast<Plant*>(plant)->mPlantType != PLANT_Mizukusa) {
		if (plant->mCollidingCreature->mObjType == OBJTYPE_Navi) {
			SeSystem::playPlayerSe(SE_ORIMA_TOUCHPLANTS);
		}

		plant->setMotionSpeed(30.0f);
	}
}

PlantMgr::PlantMgr(MapMgr* mgr)
{
	mMapMgr = mgr;
	gameflow.addGenNode("plantMgr", this);
	mMotionTable = PaniPlantAnimator::createMotionTable();
	mPlantShapes = new PlantShapeObject*[PLANT_COUNT];
	for (int i = PLANT_START; i < PLANT_COUNT; i++) {
		mPlantShapes[i] = nullptr;
	}

	mAI         = new PlantAI();
	mPlantProps = new CreatureProp();

	mAnimFrameCacher = new AnimFrameCacher(1000);
}

// see PlantTypes enum for more info on what these are
static immut char* plantNames[PLANT_COUNT] = {
	"clover",   // 0
	"chidome",  // 1
	"hutaba",   // 2
	"ine",      // 3
	"tanpopo",  // 4
	"ooinu_l",  // 5
	"ooinu_s",  // 6
	"mizukusa", // 7
	"wakame_l", // 8
	"wakame_s", // 9
	"kinokolt", // 10
	"hae",      // 11
};

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
immut char* PlantMgr::getPlantName(int plantType)
{
	return plantNames[plantType];
}

void PlantMgr::initialise()
{
	for (int i = PLANT_START; i < PLANT_COUNT; i++) {
		if (!usePlantType(i)) {
			continue;
		}

		immut char* name = plantNames[i];
		char shapeFile[256];
		sprintf(shapeFile, "objects/plants/%s.mod", name);

		char unused[256];
		sprintf(unused, "%s", name);

		char plantFileName[256];
		sprintf(plantFileName, "%s.bin", name);

		mPlantShapes[i] = new PlantShapeObject(gameflow.loadShape(shapeFile, true), plantNames[i], plantFileName);
	}
}

Creature* PlantMgr::createObject()
{
	return new Plant();
}

bool PlantMgr::usePlantType(int type)
{
	FOREACH_NODE(UseNode, mRootUseNode.mChild, node)
	{
		if (node->mPlantType == type) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void PlantMgr::addUseList(int plantType)
{
	if (!usePlantType(plantType)) {
		UseNode* node    = new UseNode();
		node->mPlantType = plantType;
		mRootUseNode.add(node);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
Creature* PlantMgr::birth()
{
	CreatureNode* cnode = new CreatureNode();
	cnode->mCreature    = new Plant();
	mRootNode.add(cnode);
	return static_cast<Plant*>(cnode->mCreature);
	// UNUSED FUNCTION
}

PlantShapeObject::PlantShapeObject(Shape* shape, immut char* plantName, immut char* fileName)
{
	mShape               = shape;
	mShape->mFrameCacher = plantMgr->mAnimFrameCacher;
	if (plantName) {
		char buf[128];
		sprintf(buf, "objects/plants/%s", fileName);
		mAnimMgr        = new AnimMgr(shape, buf, ANIMMGR_LOAD_BUNDLE, nullptr);
		mAnimMgr->mName = plantName;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, ANIMMGR_LOAD_NOSKIP, nullptr);
	}

	mShape->overrideAnim(0, &mAnimContext);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
GenObjectPlant::GenObjectPlant()
    : GenObject('plnt', "create Plant")
{
	mPlantType = PLANT_Clover;
}

static GenObject* makeObjectPlant()
{
	return new GenObjectPlant();
}

void GenObjectPlant::initialise()
{
	GenObjectFactory::factory->registerMember('plnt', &makeObjectPlant, "Generate PLANT", 'v0.0');
}

void GenObjectPlant::doRead(RandomAccessStream& input)
{
	mPlantType = input.readInt();
}

void GenObjectPlant::updateUseList(Generator* gen, int)
{
	plantMgr->addUseList(mPlantType);
}

Creature* GenObjectPlant::birth(BirthInfo& info)
{
	Creature* plant = plantMgr->birth();
	if (plant) {
		plant->init(info.mPosition);
		plant->mSRT.r         = info.mRotation;
		plant->mFaceDirection = plant->mSRT.r.y;

		Plant* pPlant = static_cast<Plant*>(plant);
		pPlant->reset(mPlantType);

		plant->mGenerator = info.mGenerator;
		plant->mHealth    = 1.0f;
		plant->mMaxHealth = plant->mHealth;
		plant->startAI(PlantAI::STATE_Wait);
	}

	return plant;
}

void GenObjectPlant::render(Graphics&, Generator*)
{
	plantMgr->usePlantType(mPlantType);
}

#ifdef WIN32

void GenObjectPlant::doGenAge(AgeServer& server)
{
	server.StartOptionBox("草のタイプ", &mPlantType, 252);
	for (int i = 0; i < PLANT_COUNT; i++) {
		server.NewOption(plantMgr->getPlantName(i), i);
	}
	server.EndOptionBox();
}

#endif
