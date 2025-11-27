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

/*
 * --INFO--
 * Address:	80119D3C
 * Size:	0000C8
 */
Plant::Plant()
    : AICreature(nullptr)
{
	mObjType   = OBJTYPE_Plant;
	mPlantType = PLANT_NULL;
	mCollInfo  = new CollInfo(8);
	mSearchBuffer.init(mPlantSearchData, 3);
}

/*
 * --INFO--
 * Address:	80119E04
 * Size:	000048
 */
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

/*
 * --INFO--
 * Address:	80119E4C
 * Size:	0000B8
 */
void Plant::startAI(int)
{
	mIsCulled = false;
	mapMgr    = plantMgr->mMapMgr;
	mProps    = plantMgr->mPlantProps;
	startMotion(0);
	mMotionSpeed = 0.0f;
	mPlantAnimator.startMotion(PaniMotionInfo(0));
	mPosition.y = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	plantMgr->mAI->start(this, PlantAI::STATE_Wait);
	if (mPlantType == PLANT_Mizukusa) {
		mMotionSpeed = 30.0f;
	}
}

/*
 * --INFO--
 * Address:	80119F04
 * Size:	000038
 */
void Plant::doAnimation()
{
	mPlantAnimator.animate(mMotionSpeed);
}

/*
 * --INFO--
 * Address:	80119F3C
 * Size:	0000A4
 */
void Plant::update()
{
	if (mIsCulled) {
		return;
	}

	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
	if (mPlantType == PLANT_Hae || mPlantType == PLANT_Mizukusa || !mGrid.aiCulling()) {
		doAnimation();
		plantMgr->mAI->exec(this);
	}
}

/*
 * --INFO--
 * Address:	80119FE0
 * Size:	0003C0
 */
void Plant::refresh(Graphics& gfx)
{
	PlantShapeObject* shape = plantMgr->mPlantShapes[mPlantType];
	if (!mPlantAnimator.mAnimInfo) {
		return;
	}

	if (mCollInfo->hasInfo()) {

		f32 rad = 2.0f * getBoundingSphereRadius();
		if (rad > 0.0f) {
			BoundBox box(Vector3f(mPosition.x - rad, mPosition.y, mPosition.z - rad),
			             Vector3f(mPosition.x + rad, mPosition.y + 2.0f * rad, mPosition.z + rad));

			if (!gfx.mCamera->isBoundVisible(box, 0x8000 | 0x20 | 0x10 | 0x1 | 0x2 | 0x4 | 0x8) && !_394) {
				C_SAI(this)->start(this, PlantAI::STATE_Wait);
				mIsCulled = true;
				return;
			}
		}
	}

	mIsCulled = false;
	_394      = false;
	mWorldMtx.makeSRT(mScale, mRotation, mPosition);
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);

	mPlantAnimator.updateContext();
	shape->mShape->updateAnim(gfx, mtx, nullptr);

	gfx.useMatrix(Matrix4f::ident, 0);
	shape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	8011A3A0
 * Size:	000004
 */
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

/*
 * --INFO--
 * Address:	8011A3A4
 * Size:	0000AC
 */
bool PlantAI::OpponentMove::satisfy(AICreature* plant)
{
	Creature* collider = plant->mCollidingCreature;
	f32 dist           = collider->mVelocity.length();
	if (dist > 40.0f) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8011A450
 * Size:	000094
 */
void PlantAI::WaitInit::act(AICreature* plant)
{
	STACK_PAD_VAR(1);

	if (static_cast<Plant*>(plant)->mPlantType == PLANT_Mizukusa) {
		plant->startMotion(0);
		plant->setMotionSpeed(30.0f);
	} else {
		plant->startMotion(0);
		plant->stopMotion();
	}
}

/*
 * --INFO--
 * Address:	8011A4E4
 * Size:	000064
 */
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

/*
 * --INFO--
 * Address:	8011A548
 * Size:	000478
 */
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
static char* plantNames[PLANT_COUNT] = {
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
char* PlantMgr::getPlantName(int plantType)
{
	return plantNames[plantType];
}

/*
 * --INFO--
 * Address:	8011A9C0
 * Size:	0000EC
 */
void PlantMgr::initialise()
{
	for (int i = PLANT_START; i < PLANT_COUNT; i++) {
		if (!usePlantType(i)) {
			continue;
		}

		char* name = plantNames[i];
		char shapeFile[256];
		sprintf(shapeFile, "objects/plants/%s.mod", name);

		char unused[256];
		sprintf(unused, "%s", name);

		char plantFileName[256];
		sprintf(plantFileName, "%s.bin", name);

		mPlantShapes[i] = new PlantShapeObject(gameflow.loadShape(shapeFile, true), plantNames[i], plantFileName);
	}
}

/*
 * --INFO--
 * Address:	8011AAAC
 * Size:	0000D8
 */
Creature* PlantMgr::createObject()
{
	return new Plant();
}

/*
 * --INFO--
 * Address:	8011AB84
 * Size:	000030
 */
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

/*
 * --INFO--
 * Address:	8011ABB4
 * Size:	000118
 */
PlantShapeObject::PlantShapeObject(Shape* shape, char* plantName, char* fileName)
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

/*
 * --INFO--
 * Address:	8011ACCC
 * Size:	000078
 */
static GenObject* makeObjectPlant()
{
	return new GenObjectPlant();
}

/*
 * --INFO--
 * Address:	8011AD44
 * Size:	00008C
 */
void GenObjectPlant::initialise()
{
	GenObjectFactory::factory->registerMember('plnt', &makeObjectPlant, "Generate PLANT", 'v0.0');
}

/*
 * --INFO--
 * Address:	8011ADD0
 * Size:	000040
 */
void GenObjectPlant::doRead(RandomAccessStream& input)
{
	mPlantType = input.readInt();
}

/*
 * --INFO--
 * Address:	8011AE10
 * Size:	0000CC
 */
void GenObjectPlant::updateUseList(Generator* gen, int)
{
	plantMgr->addUseList(mPlantType);
}

/*
 * --INFO--
 * Address:	8011AEDC
 * Size:	000190
 */
Creature* GenObjectPlant::birth(BirthInfo& info)
{
	Creature* plant = plantMgr->birth();
	if (plant) {
		plant->init(info.mPosition);
		plant->mRotation      = info.mRotation;
		plant->mFaceDirection = plant->mRotation.y;

		Plant* pPlant = static_cast<Plant*>(plant);
		pPlant->reset(mPlantType);

		plant->mGenerator = info.mGenerator;
		plant->mHealth    = 1.0f;
		plant->mMaxHealth = plant->mHealth;
		plant->startAI(PlantAI::STATE_Wait);
	}

	return plant;
}

/*
 * --INFO--
 * Address:	8011B06C
 * Size:	00002C
 */
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
