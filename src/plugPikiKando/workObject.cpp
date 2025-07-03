#include "WorkObject.h"
#include "Generator.h"
#include "Interactions.h"
#include "DynColl.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "gameflow.h"
#include "DebugLog.h"
#include "MapMgr.h"
#include "Graphics.h"
#include "Age.h"
#include "NaviMgr.h"
#include "FlowController.h"
#include "PlayerState.h"
#include "RumbleMgr.h"

WorkObjectMgr* workObjectMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(15)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("workObject");

f32 bridgeFirstPos[5] = { 42.5f, 12.5f, 12.5f, 0.0f, 42.5f };
f32 bridgeFirstY[5]   = { 10.0f, 0.0f, 0.0f, 0.0f, 10.0f };
f32 bridgeGrad[5]     = { 0.0f, 8.0f, -8.0f, 0.0f, 0.0f };

struct GenObjInfo {
	s32 mType;
	char* mName;
};

GenObjInfo info[] = {
	{ 0, "bridge test" },
	{ 1, "move stone" },
	{ 2, "..." },
};

GenObjInfo shpInfo[] = {
	{ 0, "bridge 4" }, { 1, "slope up 4" }, { 2, "slope down 4" }, { 3, "stone 10" }, { 4, "bridge 13" }, { 5, "meck" },
};

char* files[] = { "objects/bridge/brd_test.mod", "objects/bridge/slp_u_4.mod", "objects/bridge/slp_d_4.mod",
	              "objects/hinderrock/cube10.mod", "objects/bridge/brd_long.mod" };

/*
 * --INFO--
 * Address:	8009B104
 * Size:	000010
 */
void HinderRock::beginPush()
{
	mPushingPikmin++;
}

/*
 * --INFO--
 * Address:	8009B114
 * Size:	000018
 */
void HinderRock::endPush()
{
	if (mPushingPikmin) {
		mPushingPikmin--;
	}
}

/*
 * --INFO--
 * Address:	8009B12C
 * Size:	00010C
 */
void WorkObjectMgr::finalSetup()
{
	Iterator iter(this);
	CI_LOOP(iter)
	{
		static_cast<WorkObject*>(*iter)->finalSetup();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
WorkObject::WorkObject()
    : ItemCreature(OBJTYPE_WorkObject, nullptr, nullptr)
{
	mObjType   = OBJTYPE_WorkObject;
	mSeContext = new SeContext();
	mSeContext->setContext(this, 4);
}

/*
 * --INFO--
 * Address:	8009B23C
 * Size:	000024
 */
void WorkObject::doKill()
{
	mLifeGauge.countOff();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
int WorkObjectMgr::getNameIndex(char* name)
{
	// mType == 2 is the end
	for (GenObjInfo* i = info; i->mType != 2; i++) {
		if (!strcmp(i->mName, name)) {
			return i->mType;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
char* WorkObjectMgr::getName(int type)
{
	// mType == 2 is the end
	for (GenObjInfo* i = info; i->mType != 2; i++) {
		if (i->mType == type) {
			return i->mName;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
int WorkObjectMgr::getShapeNameIndex(char* name)
{
	// mType == 5 is the end
	for (GenObjInfo* i = shpInfo; i->mType != 5; i++) {
		if (!strcmp(i->mName, name)) {
			return i->mType;
		}
	}

	return -1;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
char* WorkObjectMgr::getShapeName(int type)
{
	// mType == 5 is the end
	for (GenObjInfo* i = shpInfo; i->mType != 5; i++) {
		if (i->mType == type) {
			return i->mName;
		}
	}

	return nullptr;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009B260
 * Size:	000110
 */
WorkObjectMgr::WorkObjectMgr()
{
	mItemShapes          = new Shape*[5];
	mShouldThisShapeLoad = new u8[5];

	for (int i = 0; i < 5; i++) {
		mShouldThisShapeLoad[i] = 0;
	}
}

/*
 * --INFO--
 * Address:	8009B3C4
 * Size:	000094
 */
void WorkObjectMgr::loadShapes()
{
	for (int i = 0; i < 5; i++) {
		if (mShouldThisShapeLoad[i]) {
			PRINT("LOADING SHAPE FOR %d\n", i);
			mItemShapes[i] = gameflow.loadShape(files[i], true);
		} else {
			PRINT("SHAPE NOT REQUIRED %d\n", i);
			mItemShapes[i] = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void WorkObjectMgr::addUseList(int index)
{
	mShouldThisShapeLoad[index] = true;
}

/*
 * --INFO--
 * Address:	8009B458
 * Size:	00012C
 */
Creature* WorkObjectMgr::birth(int wObjType, int p2)
{
	WorkObject* object = nullptr;
	Shape* shape       = mItemShapes[p2];

	switch (wObjType) {
	case 0:
		object                             = new Bridge(shape, true);
		static_cast<Bridge*>(object)->_400 = p2;
		if (p2 == 4) {
			object->mGrid.setNeighbourSize(3);
		} else {
			object->mGrid.setNeighbourSize(1);
		}
		break;
	case 1:
		object = new HinderRock(shape);
		object->mGrid.setNeighbourSize(1);
		break;
	}

	if (!object) {
		ERROR("DAME DAME\n");
	}

	WorkObjectNode* node = new WorkObjectNode(object);
	mRootNode.add(node);
	return object;
}

/*
 * --INFO--
 * Address:	8009B584
 * Size:	000088
 */
Creature* WorkObjectMgr::getCreature(int index)
{
	WorkObjectNode* node = (WorkObjectNode*)mRootNode.mChild;
	for (int i = 0; i < index; i++) {
		node = (WorkObjectNode*)node->mNext;
	}

	if (!node)
		return nullptr;

	return node->mObject;
}

/*
 * --INFO--
 * Address:	8009B60C
 * Size:	000008
 */
int WorkObjectMgr::getFirst()
{
	return 0;
}

/*
 * --INFO--
 * Address:	8009B614
 * Size:	000008
 */
int WorkObjectMgr::getNext(int idx)
{
	return idx + 1;
}

/*
 * --INFO--
 * Address:	8009B61C
 * Size:	000044
 */
bool WorkObjectMgr::isDone(int id)
{
	if (id >= mRootNode.getChildCount()) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	8009B660
 * Size:	000024
 */
int WorkObjectMgr::getSize()
{
	return mRootNode.getChildCount();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
GenObjectWorkObject::GenObjectWorkObject()
    : GenObject('work', "仕事オブジェクト")
    , mDay(this, 0, 0, MAX_DAYS, "p00", "day")
    , mHour(this, 0, 0, 24, "p01", "hour")
    , _38(this, 10, 0, 100, "p02", "動かすのに必要なピキ数") // "Number of pikis required to move"
    , _48(this, 30.0f, 0.0f, 400.0f, "p03", "移動速度")      // "movement speed"

{
	mObjectType = 0;
	mShapeType  = 0;
	mHinderRockPosition.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8009B684
 * Size:	0000A0
 */
void GenObjectWorkObject::ramSaveParameters(RandomAccessStream& data)
{
	data.writeByte(mDay());
	data.writeByte(mHour());
	data.writeByte(_38());
	data.writeFloat(_48());
}

/*
 * --INFO--
 * Address:	8009B724
 * Size:	0000A0
 */
void GenObjectWorkObject::ramLoadParameters(RandomAccessStream& data)
{
	mDay()  = data.readByte();
	mHour() = data.readByte();
	_38()   = data.readByte();
	_48()   = data.readFloat();
}

/*
 * --INFO--
 * Address:	8009B7C4
 * Size:	00016C
 */
static GenObject* makeObjectWorkObject()
{
	return new GenObjectWorkObject;
}

/*
 * --INFO--
 * Address:	8009B930
 * Size:	00008C
 */
void GenObjectWorkObject::initialise()
{
	GenObjectFactory::factory->registerMember('work', makeObjectWorkObject, "仕事オブジェクトを発生", 'v0.3');
}

/*
 * --INFO--
 * Address:	8009B9BC
 * Size:	00020C
 */
void GenObjectWorkObject::doRead(RandomAccessStream& stream)
{
	if (Generator::ramMode) {
		mObjectType = stream.readShort();
		mShapeType  = stream.readShort();

		// MOVE STONE (hinderrock)
		if (mObjectType == 1) {
			mHinderRockPosition.x = stream.readFloat();
			mHinderRockPosition.y = stream.readFloat();
			mHinderRockPosition.z = stream.readFloat();
		}

		return;
	}

	char name[256];
	stream.readString(name, sizeof(name));
	mObjectType = WorkObjectMgr::getNameIndex(name);

	if (mObjectType == -1) {
		PRINT("ItemGenerator * %s is not item\n", name);
		ERROR("HENDANA\n");
	}

	if (mVersion == 'v0.2' || mVersion == 'v0.3') {
		stream.readString(name, sizeof(name));
		mShapeType = WorkObjectMgr::getShapeNameIndex(name);

		if (mShapeType == -1) {
			PRINT("SHAPE NOT FOUND * %s \n", name);
			ERROR("HENDANA\n");
		}
	}

	// MOVE STONE (hinderrock)
	if (mVersion == 'v0.3' && mObjectType == 1) {
		PRINT("READING HINDERROCK !!!!!!!!!!!!!!!!!!!!!!!!!! *******\n");
		mHinderRockPosition.x = stream.readFloat();
		mHinderRockPosition.y = stream.readFloat();
		mHinderRockPosition.z = stream.readFloat();
		PRINT("POS (%.1f %.1f %.1f)\n", mHinderRockPosition.x, mHinderRockPosition.y, mHinderRockPosition.z);
	}
}

/*
 * --INFO--
 * Address:	8009BBC8
 * Size:	0001B4
 */
void GenObjectWorkObject::doWrite(RandomAccessStream& stream)
{
	if (Generator::ramMode) {
		stream.writeShort(mObjectType);
		stream.writeShort(mShapeType);

		// MOVE STONE (hinderrock)
		if (mObjectType == 1) {
			stream.writeFloat(mHinderRockPosition.x);
			stream.writeFloat(mHinderRockPosition.y);
			stream.writeFloat(mHinderRockPosition.z);
		}

		return;
	}

	stream.writeString(WorkObjectMgr::getName(mObjectType));
	stream.writeString(WorkObjectMgr::getShapeName(mShapeType));

	// MOVE STONE (hinderrock)
	if (mObjectType == 1) {
		PRINT("WRITING HINDERROCK !!!!!!!!!!!!!!!!!!!!!!!!!! *******\n");

		stream.writeFloat(mHinderRockPosition.x);
		stream.writeFloat(mHinderRockPosition.y);
		stream.writeFloat(mHinderRockPosition.z);
	}
}

/*
 * --INFO--
 * Address:	8009BD7C
 * Size:	000020
 */
void GenObjectWorkObject::updateUseList(Generator*, int i)
{
	if (mShapeType != -1) {
		workObjectMgr->addUseList(mShapeType);
	}
}

/*
 * --INFO--
 * Address:	8009BD9C
 * Size:	000180
 */
Creature* GenObjectWorkObject::birth(BirthInfo& info)
{
	if (mObjectType == -1) {
		return nullptr;
	}

	Creature* obj = workObjectMgr->birth(mObjectType, mShapeType);
	if (obj) {
		info.mPosition.y = mapMgr->getMinY(info.mPosition.x, info.mPosition.z, true);
		obj->init(info.mPosition);
		obj->mRotation      = info.mRotation;
		obj->mFaceDirection = obj->mRotation.y;
		obj->mGenerator     = info.mGenerator;

		if (mObjectType == 1) {
			HinderRock* box            = (HinderRock*)obj;
			box->mDestinationPosition  = mHinderRockPosition;
			box->mAmountPushersToStart = _38();
			box->mPushSpeed            = _48();
		}

		obj->mHealth    = mDay() * (int)gameflow.mWorldClock.mHoursInDay + mHour();
		obj->mMaxHealth = obj->mHealth;
		obj->startAI(0);
		if (info.mGenerator->mGenType->mAdjustFaceDirection()) {
			obj->enableFaceDirAdjust();
		}
	}
	return obj;

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	8009BF1C
 * Size:	000178
 */
HinderRock::HinderRock(Shape* shape)
{
	mBoxShape = shape;
	mBoxShape->mSystemFlags |= ShapeFlags::IsPlatform;
	mBuildShape            = new DynBuildShape(shape);
	mBuildShape->mCreature = this;
	mCollInfo              = new CollInfo(20);
	mEfxA                  = 0;
	mEfxC                  = 0;
	mEfxB                  = 0;
}

/*
 * --INFO--
 * Address:	8009C094
 * Size:	000074
 */
bool HinderRock::insideSafeArea(Vector3f& pos)
{
	Vector3f pos2 = mPosition;
	Cylinder cyl(pos2, mDestinationPosition, 1.0f);
	if (cyl.get2dDist(pos) < 120.0f) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	8009C108
 * Size:	000164
 */
void HinderRock::doLoad(RandomAccessStream& stream)
{
	mState             = stream.readByte();
	mTotalPushStrength = 0;
	mPushingPikmin     = 0;

	mPushMoveTimer = 0.0f;

	if (mState == 2) {
		mPosition   = mDestinationPosition;
		mPosition.y = mapMgr->getMinY(mPosition.x, mPosition.z, false);
		for (int i = 0; i < 10; i++) {
			PRINT("goal Y = %f\n", mDestinationPosition.y);
		}

		mWayPoint->setFlag(true);
		PRINT("********* ROCK WAYPOINT(%d) ON\n", mWayPoint->mIndex);
	}

	;
	mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), mRotation, mPosition);

	mBuildShape->mTransformMtx = mWorldMtx;
}

/*
 * --INFO--
 * Address:	8009C26C
 * Size:	000040
 */
void HinderRock::doSave(RandomAccessStream& stream)
{
	stream.writeByte(mState);
	PRINT("\tdoSave ******** STATE = %d WIDX = %d\n", mState, mWayPoint->mIndex);
}

/*
 * --INFO--
 * Address:	8009C2AC
 * Size:	000008
 */
f32 HinderRock::getCentreSize()
{
	return mCentreSize;
}

/*
 * --INFO--
 * Address:	8009C2B4
 * Size:	000014
 */
bool HinderRock::isFinished()
{
	return mState == 2;
}

/*
 * --INFO--
 * Address:	8009C2C8
 * Size:	0000C8
 */
Vector3f HinderRock::getZVector()
{
	Vector3f v1 = getVertex(0);
	Vector3f v2 = getVertex(3);

	Vector3f diff = v2 - v1;
	diff.normalise();
	return diff;
}

/*
 * --INFO--
 * Address:	8009C390
 * Size:	0000C8
 */
Vector3f HinderRock::getXVector()
{
	Vector3f v1 = getVertex(0);
	Vector3f v2 = getVertex(1);

	Vector3f diff = v2 - v1;
	diff.normalise();
	return diff;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
int HinderRock::getPlaneIndex(Vector3f& pos)
{
	if (mPlanes[0].dist(pos) < 0.0f) {
		return 0;
	}
	if (mPlanes[1].dist(pos) < 0.0f) {
		return 1;
	}
	if (mPlanes[2].dist(pos) < 0.0f) {
		return 2;
	}
	return 3;
}

/*
 * --INFO--
 * Address:	8009C458
 * Size:	0000F8
 */
u8 HinderRock::getPlaneFlag(Vector3f& pos)
{
	u8 res = 0;
	if (mPlanes[0].dist(pos) > 0.0f) {
		res = 1;
	}
	if (mPlanes[2].dist(pos) > 0.0f) {
		res = 4;
	}
	if (mPlanes[1].dist(pos) > 0.0f) {
		res |= 2;
	}
	if (mPlanes[3].dist(pos) > 0.0f) {
		res |= 8;
	}
	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
Vector3f HinderRock::getTangentPos(f32 mod)
{
	Vector3f v1 = getVertex(2);
	Vector3f v2 = getVertex(3);

	Vector3f diff = v2 - v1;
	diff          = diff * mod + v1;
	diff.normalise();
	return diff;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009C550
 * Size:	0003A8
 */
void HinderRock::updatePlanes()
{
	Vector3f v0 = getVertex(0);
	Vector3f v2 = getVertex(2);
	Vector3f v3 = getVertex(3);

	mPlanes[0].mNormal = v0 - v3;
	_42C               = mPlanes->mNormal.normalise();
	mPlanes[2].mNormal = mPlanes[0].mNormal * -1.0f;

	mPlanes[1].mNormal = v2 - v3;
	mCentreSize        = mPlanes[1].mNormal.normalise();
	mPlanes[3].mNormal = mPlanes[1].mNormal * -1.0f;

	mPlanes[0].mOffset = mPlanes[0].mNormal.DP(v0);
	mPlanes[1].mOffset = mPlanes[1].mNormal.DP(v2);
	mPlanes[2].mOffset = mPlanes[2].mNormal.DP(v3);
	mPlanes[3].mOffset = mPlanes[3].mNormal.DP(v3);

	mMoveFrontEfxPos   = 0.5f * (v2 + v3);
	mMoveSideEfxPos[0] = v0;
	mMoveSideEfxPos[1] = getVertex(1);
}

/*
 * --INFO--
 * Address:	8009C8F8
 * Size:	0000A0
 */
Vector3f HinderRock::getVertex(int vtx)
{
	u32 id;
	switch (vtx) {
	case 0:
		id = 'vtx0';
		break;
	case 1:
		id = 'vtx1';
		break;
	case 2:
		id = 'vtx2';
		break;
	case 3:
		id = 'vtx3';
	default:
		break;
	}

	CollPart* part = mCollInfo->getSphere(id);
	if (!part) {
		ERROR("no vtx%d collpart !\n", vtx);
	}

	return part->mCentre;
}

/*
 * --INFO--
 * Address:	8009C998
 * Size:	000074
 */
bool HinderRock::stimulate(Interaction& act)
{
	if (!act.actCommon(this)) {
		return false;
	}

	return act.actHinderRock(this);
}

/*
 * --INFO--
 * Address:	8009CA0C
 * Size:	000018
 */
bool InteractPush::actHinderRock(HinderRock* obj)
{
	Vector3f unused(0.0f, 110.0f, 0.0f);
	obj->mTotalPushStrength += mStrength;
	return true;
}

/*
 * --INFO--
 * Address:	8009CA24
 * Size:	0000C0
 */
void HinderRock::refresh(Graphics& gfx)
{
	Matrix4f mtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);
	mBoxShape->updateAnim(gfx, mtx, nullptr);
	mBuildShape->mTransformMtx.inverse(&mBuildShape->mInverseMatrix);
	gfx.useMatrix(Matrix4f::ident, 0);
	mBuildShape->updateContext();
	mBoxShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
	updatePlanes();
}

/*
 * --INFO--
 * Address:	8009CAE4
 * Size:	00011C
 */
bool HinderRock::workable(Vector3f& pos)
{
	u8 flag = getPlaneFlag(pos);
	if (flag != 6 && flag != 4 && flag != 12) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	8009CC00
 * Size:	000830
 */
void HinderRock::update()
{
	if (mSeContext) {
		mSeContext->update();
	}
	mLifeGauge.mPosition = mPosition;
	mLifeGauge.mPosition.y += 40.0f;
	mIsMoving = false;
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);

	if (mPushingPikmin) {
		mLifeGauge.countOn(mLifeGauge.mPosition, mPushingPikmin, mAmountPushersToStart);
	}

	if (mPushingPikmin == 0) {
		if (++mFxCooldownTimer > 10) {
			mFxCooldownTimer = 10;
			mLifeGauge.countOff();
			if (mEfxA) {
				mEfxA->stopGen();
			}
			if (mEfxB) {
				mEfxB->stopGen();
			}
			if (mEfxC) {
				mEfxC->stopGen();
			}
		}
	} else {
		mFxCooldownTimer = 0;
	}

	if (mState == 0 && mPushingPikmin >= mAmountPushersToStart) {

		if (mEfxA == nullptr) {
			mEfxA = effectMgr->create(EffectMgr::EFF_HinderRock_MoveFront, mMoveFrontEfxPos, nullptr, nullptr);
			if (mEfxA) {
				mEfxA->setEmitPosPtr(&mMoveFrontEfxPos);
				mEfxA->setEmitDir(getXVector());
				STACK_PAD_STRUCT(6);
			}
		} else {
			mEfxA->startGen();
		}

		if (mEfxB == nullptr) {
			mEfxB = effectMgr->create(EffectMgr::EFF_HinderRock_MoveSides, mMoveSideEfxPos[0], nullptr, nullptr);
			if (mEfxB) {
				mEfxB->setEmitPosPtr(&mMoveSideEfxPos[0]);
				Vector3f gravityPos = mPlanes[3].mNormal * 0.096f;
				mEfxB->setGravityField(gravityPos, true);
			}
		} else {
			mEfxB->startGen();
		}

		if (mEfxC == nullptr) {
			mEfxC = effectMgr->create(EffectMgr::EFF_HinderRock_MoveSides, mMoveSideEfxPos[1], nullptr, nullptr);
			if (mEfxC) {
				mEfxC->setEmitPosPtr(&mMoveSideEfxPos[1]);
				Vector3f test = mPlanes[1].mNormal * 0.096f;
				mEfxC->setGravityField(test, true);
			}
		} else {
			mEfxC->startGen();
		}

		if (flowCont.mCurrentStage->mStageID == STAGE_Practice && !playerState->mDemoFlags.isFlag(DEMOFLAG_StartBoxPush)) {
			playerState->mDemoFlags.setFlag(DEMOFLAG_StartBoxPush, nullptr);
		}

		mIsMoving = true;
		mVelocity = mDestinationPosition - mPosition;
		if (std::sqrtf(mVelocity.x * mVelocity.x + mVelocity.z * mVelocity.z) < 4.0f) {
			mPosition = mDestinationPosition;
			mState    = 2;
			mWayPoint->setFlag(true);
			seSystem->playSysSe(SYSSE_WORK_FINISH);
			PRINT("つきざました！\n"); // 'it's here!'
			if (!playerState->mDemoFlags.isFlag(DEMOFLAG_FinishBoxPush)) {
				PRINT("************ MOVEROCK END *************\n");
				playerState->mDemoFlags.setFlag(DEMOFLAG_FinishBoxPush, nullptr);
			}
			if (mEfxA) {
				effectMgr->kill(mEfxA, false);
				mEfxA = nullptr;
			}
			if (mEfxB) {
				effectMgr->kill(mEfxB, false);
				mEfxB = nullptr;
			}
			if (mEfxC) {
				effectMgr->kill(mEfxC, false);
				mEfxC = nullptr;
			}
			return;
		}
		mVelocity.normalise();
		mVelocity.multiply(mPushSpeed * 0.5f);
		moveNew(gsys->getFrameTime());
		mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), mRotation, mPosition);
		mBuildShape->mTransformMtx = mWorldMtx;
		mPushMoveTimer += gsys->getFrameTime();
		if (!mIsSoundPlaying) {
			mSeContext->playSound(SEB_BOXMOVE);
			mIsSoundPlaying = true;
		}
		if (mPushMoveTimer > 1.0f) {
			mState         = 1;
			mPushMoveTimer = gsys->getRand(1.0f) * 0.1f + 0.2f;
		}
	} else if (mState == 1) {
		mIsSoundPlaying = false;
		mIsMoving       = true;
		mPushMoveTimer -= gsys->getFrameTime();
		if (mPushMoveTimer <= 0.0f) {
			mState         = 0;
			mPushMoveTimer = 0.0f;
		}
		mLifeGauge.countOn(mLifeGauge.mPosition, mPushingPikmin, mAmountPushersToStart);
	} else if ((mVelocity.x * mVelocity.x + mVelocity.z * mVelocity.z) < 1.0f) {
		if (mEfxA) {
			mEfxA->stopGen();
		}
		if (mEfxB) {
			mEfxB->stopGen();
		}
		if (mEfxC) {
			mEfxC->stopGen();
		}
	}
	mTotalPushStrength = 0;

	STACK_PAD_TERNARY(mState, 5);
	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	8009D430
 * Size:	000198
 */
void HinderRock::startAI(int)
{
	mPushingPikmin   = 0;
	mFxCooldownTimer = false;
	_428             = false;
	mCollInfo->initInfo(mBoxShape, nullptr, nullptr);
	Vector3f dist  = mDestinationPosition - mPosition;
	f32 y          = atan2f(dist.x, dist.z);
	mFaceDirection = y;
	mRotation.set(0.0f, y, 0.0f);
	mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), mRotation, mPosition);
	mBuildShape->mTransformMtx = mWorldMtx;
	mapMgr->mCollShape->add(mBuildShape);
	mTotalPushStrength = 0;
	mState             = 0;
	mPushMoveTimer     = 0.0f;
	mWayPoint          = routeMgr->findNearestWayPointAll('test', mPosition);
	mWayPoint->setFlag(false);
	PRINT("********* ROCK WAYPOINT(%d) OFF\n", mWayPoint->mIsOpen);
	mIsSoundPlaying = false;
	mPosition.y     = mapMgr->getMinY(mPosition.x, mPosition.z, false);
}

/*
 * --INFO--
 * Address:	8009D5C8
 * Size:	000154
 */
bool Bridge::workable(Vector3f& pos)
{
	f32 x, z;
	getBridgePos(pos, x, z);
	int stage = getFirstUnfinishedStage();
	if (stage == -1) {
		PRINT("workable: fst = -1 failed\n");
		return false;
	}

	f32 stageZ = getStageZ(stage);
	z          = z - 10.0f;
	if (z > stageZ + 10.0f) {
		PRINT("endZ is %.1f z is %.1f\n", stageZ, z);
		return false;
	}

	if (z >= 0.0f && z <= stageZ) {
		if (absF(x) >= getStageWidth() * 0.5f) {
			PRINT("haba dame %.1f\n", x);
			return false;
		}

		if (mapMgr->getMinY(pos.x, pos.z, true) - 10.0f >= pos.y) {
			PRINT("lower (max=%.1f srt.t.y=%.1f)\n", x, pos.y);
			return false;
		}
	} else if (z < -100.0f) {
		return false;
	}

	if (absF(x) >= getStageWidth() * 0.7f) {
		PRINT("haba dame 2 %.1f\n", x);
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8009D71C
 * Size:	0002C4
 */
Bridge::Bridge(Shape* shape, bool a3)
{
	mDoUseJointSegments = a3;
	mBridgeShape        = shape;

	mBridgeShape->mSystemFlags |= ShapeFlags::IsPlatform;
	mBridgeShape->mSystemFlags |= ShapeFlags::AlwaysRedraw;

	mBuildShape            = new DynBuildShape(shape);
	mBuildShape->mCreature = this;

	if (mDoUseJointSegments) {
		mStageCount  = shape->mJointList->getChildCount() / 2;
		mStageJoints = new Joint*[mStageCount * 2];

		Joint* currentJoint = (Joint*)shape->mJointList->mChild;
		for (int i = 2 * mStageCount - 1; i >= 0; i--) {
			mStageJoints[i] = (Joint*)currentJoint->mChild;
			currentJoint    = (Joint*)currentJoint->mNext;
		}

		PRINT("numStages = %d\n", mStageCount);
	} else {
		mCollInfo = new CollInfo(20);
		mCollInfo->initInfo(shape, 0, 0);
		_410        = mCollInfo->getSphere('refs');
		mStageCount = _410->getChildCount();
	}

	PRINT("numStages = %d\n", mStageCount);
	if (!mStageCount) {
		ERROR("numStage is 0 \n");
	}

	mStageProgressList = new f32[mStageCount];
}

/*
 * --INFO--
 * Address:	8009D9E0
 * Size:	000074
 */
bool Bridge::stimulate(Interaction& i)
{
	if (!i.actCommon(this)) {
		return false;
	}

	return i.actBridge(this);
}

/*
 * --INFO--
 * Address:	8009DA54
 * Size:	0000E4
 */
void Bridge::refresh(Graphics& gfx)
{
	Matrix4f animMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, animMtx);
	mBridgeShape->updateAnim(gfx, animMtx, nullptr);
	mBuildShape->mTransformMtx.inverse(&mBuildShape->mInverseMatrix);
	mDynMaterial.animate(nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	mBuildShape->updateContext();
	mBridgeShape->drawshape(gfx, *gfx.mCamera, &mDynMaterial);

	if (!mDoUseJointSegments) {
		mCollInfo->updateInfo(gfx, false);
	}

	if (_424) {
		_424--;
	}
}

/*
 * --INFO--
 * Address:	8009DB38
 * Size:	0000E0
 */
void Bridge::update()
{
	if (mSeContext) {
		mSeContext->update();
	}
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);

	if (_3CC == 0) {
		return;
	}
	_3CC--;
	if (_3CC > 30) {
		return;
	}

	if (_3CA != -1) {
		setStageFinished(_3CA, true);
		_3CA = -1;
		if (isFinished()) {
			mStartWaypoint->setFlag(true);
			mEndWaypoint->setFlag(true);
			seSystem->playSysSe(SYSSE_WORK_FINISH);
			PRINT("橋：完成しました\n"); // 'bridge: completed'
			playerState->mResultFlags.setOn(RESFLAG_BrokenBridge);
		}
	}
}

/*
 * --INFO--
 * Address:	8009DC18
 * Size:	000300
 */
void Bridge::startAI(int)
{
	_424 = 3;
	if (!mDoUseJointSegments) {
		mCollInfo->initInfo(mBridgeShape, nullptr, nullptr);
	}
	mBridgeShape->makeInstance(mDynMaterial, 0);
	mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), mRotation, mPosition);
	mBuildShape->mTransformMtx = mWorldMtx;
	mapMgr->mCollShape->add(mBuildShape);

	if (mDoUseJointSegments) {
		for (int i = 0; i < mStageCount; i++) {
			mStageProgressList[i] = 0.0f;
		}
		for (int i = 0; i < mStageCount * 2; i++) {
			mBuildShape->jointVisible(mStageJoints[i]->mIndex, false);
		}
		mBuildShape->jointVisible(mStageJoints[0]->mIndex, true);
	} else {
		for (int i = 0; i < mStageCount; i++) {
			mStageProgressList[i] = 0.0f;
			setStageFinished(i, false);
		}
	}

	mStartWaypoint = routeMgr->findNearestWayPointAll('test', mPosition);
	mStartWaypoint->mFlags |= WayPointFlags::Destination;
	mStartWaypoint->mPosition = getStartPos();
	mStartWaypoint->setFlag(false);

	Vector3f pos = getStagePos(mStageCount - 1);
	mEndWaypoint = routeMgr->findNearestWayPointAll('test', pos);
	mEndWaypoint->mFlags |= WayPointFlags::Destination;
	mEndWaypoint->mPosition = pos;
	mEndWaypoint->setFlag(false);

	_3CA = -1;
	_3CC = false;
}

/*
 * --INFO--
 * Address:	8009DF18
 * Size:	00018C
 */
void Bridge::doLoad(RandomAccessStream& data)
{
	bool finished = true;

	PRINT("___________ LOADING BRIDGE !\n");
	for (int i = 0; i < mStageCount; i++) {
		mStageProgressList[i] = data.readFloat();
		if (mStageProgressList[i] >= mMaxHealth) {
			setStageFinished(i, true);
			PRINT("\tStage %d is FINISHED\n", i);
		} else {
			setStageFinished(i, false);
			PRINT("\tStage %d is NOT FINISHED\n", i);
			finished = false;
		}
	}

	flatten();

	if (finished) {
		mStartWaypoint->setFlag(true);
		mEndWaypoint->setFlag(true);
	}

	int stage = getFirstUnfinishedStage();
	if (stage != -1) {
		Vector3f pos              = getStagePos(stage) - (5.0f * getBridgeZVec());
		mStartWaypoint->mPosition = pos;
	}

	PRINT("_______________________________\n");
}

/*
 * --INFO--
 * Address:	8009E0A4
 * Size:	000080
 */
void Bridge::doSave(RandomAccessStream& data)
{
	for (int i = 0; i < mStageCount; i++) {
		data.writeFloat(mStageProgressList[i]);
	}
}

/*
 * --INFO--
 * Address:	8009E124
 * Size:	0000B0
 */
bool Bridge::insideSafeArea(Vector3f& pos)
{
	Vector3f bridgePos = mPosition;
	Vector3f stage     = getStagePos(mStageCount - 1);
	Cylinder cyl(bridgePos, stage);
	if (cyl.get2dDist(pos) < 120.0f) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	8009E1D4
 * Size:	000068
 */
bool Bridge::isFinished()
{
	for (int i = 0; i < mStageCount; i++) {
		if (!isStageFinished(i)) {
			return false;
		}
	}
	return true;
}

/*
 * --INFO--
 * Address:	8009E23C
 * Size:	000068
 */
int Bridge::getFirstUnfinishedStage()
{
	for (int i = 0; i < mStageCount; i++) {
		if (!isStageFinished(i)) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	8009E2A4
 * Size:	000068
 */
int Bridge::getFirstFinishedStage()
{
	for (int i = 0; i < mStageCount; i++) {
		if (isStageFinished(i)) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	8009E30C
 * Size:	000040
 */
int Bridge::getJointIndex(int id)
{
	if (id < 0 || id > mStageCount) {
		ERROR(" illegal stage %d\n", id);
	}

	if (mDoUseJointSegments) {
		return 0;
	}
	return _410->getChildAt(id)->mCollInfo->mJointIndex;
}

/*
 * --INFO--
 * Address:	8009E34C
 * Size:	00009C
 */
bool Bridge::isStageFinished(int id)
{
	if (mDoUseJointSegments) {
		if (id < 0 || id >= mStageCount) {
			return true;
		}
		return mBuildShape->mVisibleList[mStageJoints[id * 2 + 1]->mIndex];
	}
	int jointIdx = getJointIndex(id);
	return mBuildShape->mVisibleList[jointIdx];
}

/*
 * --INFO--
 * Address:	8009E3E8
 * Size:	0000A4
 */
void Bridge::flatten()
{
	for (int i = 0; i < mStageCount; i++) {
		int index = mStageJoints[i * 2]->mIndex;
		if (mBuildShape->mVisibleList[mStageJoints[i * 2 + 1]->mIndex] && mBuildShape->mVisibleList[index]) {
			mBuildShape->jointVisible(index, false);
			PRINT("flatten bridge");
		}
	}
}

/*
 * --INFO--
 * Address:	8009E48C
 * Size:	000128
 */
void Bridge::dump()
{
	for (int i = 0; i < mStageCount; i++) {
		char a, b;
		if (mBuildShape->mVisibleList[mStageJoints[i * 2 + 1]->mIndex]) {
			a = '|';
		} else {
			a = 'x';
		}

		if (mBuildShape->mVisibleList[mStageJoints[i * 2]->mIndex]) {
			b = '|';
		} else {
			b = 'x';
		}
		f32 test = mStageProgressList[i] / mMaxHealth * 100.0f;
		PRINT("brd %d : %d%%(w%s:p%s)\n", i, (int)test, &a, &b);
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	8009E5B4
 * Size:	000394
 */
void Bridge::setStageFinished(int stageIndex, bool isFinished)
{
	if (mDoUseJointSegments) {

		int pIdx    = mStageJoints[2 * stageIndex + 1]->mIndex;
		int wIdx    = mStageJoints[2 * stageIndex]->mIndex;
		int nextIdx = -1;
		if (stageIndex < mStageCount - 1) {
			nextIdx = mStageJoints[2 * stageIndex + 2]->mIndex;
		}

		int prevID = 2 * stageIndex - 1;
		if (isFinished) {
			mBuildShape->jointVisible(wIdx, 0);
			mBuildShape->jointVisible(pIdx, 1);
			if (nextIdx != -1) {
				mBuildShape->jointVisible(nextIdx, 1);
			}
		} else {
			if (prevID > 0) {
				if (mBuildShape->mVisibleList[mStageJoints[prevID]->mIndex]) {
					mBuildShape->jointVisible(wIdx, 1);
				} else {
					mBuildShape->jointVisible(wIdx, 0);
				}
			} else {
				mBuildShape->jointVisible(wIdx, 1);
			}
			mBuildShape->jointVisible(pIdx, 0);
			if (nextIdx != -1) {
				mBuildShape->jointVisible(nextIdx, 0);
			}
		}

		flatten();
		int firstUnfinished = getFirstUnfinishedStage();
		if (firstUnfinished != -1) {
			Vector3f wpPos            = getStagePos(firstUnfinished) - 5.0f * getBridgeZVec();
			mStartWaypoint->mPosition = wpPos;
		}

		STACK_PAD_STRUCT(2);
	} else {
		mBuildShape->jointVisible(getJointIndex(stageIndex), isFinished);
	}
}

/*
 * --INFO--
 * Address:	8009E948
 * Size:	0000C8
 */
Vector3f Bridge::getStagePos(int stage)
{
	if (mDoUseJointSegments) {
		Vector3f pos;
		f32 z = getStageZ(stage);
		pos   = mPosition + getBridgeZVec() * z;
		return pos;
	}

	return _410->getChildAt(stage)->mCentre;
}

/*
 * --INFO--
 * Address:	8009EA10
 * Size:	000064
 */
f32 Bridge::getStageZ(int stage)
{
	f32 z = -20.0f;
	if (stage > 0) {
		z = (f32)(stage - 1) * 20.0f + bridgeFirstPos[_400];
	}
	return z - 10.0f;
}

/*
 * --INFO--
 * Address:	8009EA74
 * Size:	0000E8
 */
void Bridge::getBridgePos(Vector3f& origin, f32& xProjection, f32& zProjection)
{
	Vector3f diff = origin - getStartPos();
	diff.y        = 0.0f;

	xProjection = diff.dot(getBridgeXVec());
	zProjection = diff.dot(getBridgeZVec());
}

/*
 * --INFO--
 * Address:	8009EB5C
 * Size:	000060
 */
Vector3f Bridge::getBridgeZVec()
{
	f32 yRot = mRotation.y;
	Vector3f zvec(sinf(yRot), 0.0f, cosf(yRot));
	return zvec;
}

/*
 * --INFO--
 * Address:	8009EBBC
 * Size:	000060
 */
Vector3f Bridge::getBridgeXVec()
{
	f32 yRot = mRotation.y;
	Vector3f xvec(cosf(yRot), 0.0f, -sinf(yRot));
	return xvec;
}

/*
 * --INFO--
 * Address:	8009EC1C
 * Size:	0000FC
 */
Vector3f Bridge::getStartPos()
{
	Vector3f pos = mPosition;
	pos          = pos - 20.0f * getBridgeZVec();
	return pos;
}

/*
 * --INFO--
 * Address:	8009ED18
 * Size:	000008
 */
f32 Bridge::getStageDepth()
{
	return 20.0f;
}

/*
 * --INFO--
 * Address:	8009ED20
 * Size:	000008
 */
f32 Bridge::getStageWidth()
{
	return 150.0f;
}

/*
 * --INFO--
 * Address:	8009ED28
 * Size:	000424
 */
void Bridge::startStageFinished(int stageIndex, bool isFinished)
{
	FORCE_DONT_INLINE;

	if (isFinished) {
		if (_3CA != -1) {
			PRINT("abunai!"); // 'dangerous!'
		}
		rumbleMgr->start(RUMBLE_Unk7, 0, mPosition);

		f32 z = 0.0f;
		if (stageIndex <= 0) {
			z = -20.0f;
		} else {
			z = (f32)(stageIndex - 1) * 20.0f + bridgeFirstPos[_400];
		}
		Vector3f pos(mPosition);
		pos = pos + getBridgeZVec() * z;
		if (stageIndex == 1) {
			pos.y += bridgeFirstY[_400];
			if (_400 == 1) {
				pos.y -= 10.0f;
			}
		} else {
			pos.y += bridgeFirstY[_400] + f32(stageIndex - 1) * bridgeGrad[_400];
			if (_400 == 1) {
				pos.y -= 10.0f;
			}
		}

		Vector3f pos2(pos);
		pos2 = pos + 20.0f * getBridgeZVec();

		if (stageIndex > 0) {
			pos.y += f32(stageIndex) * bridgeGrad[_400];
			if (_400 == 1) {
				pos.y -= 10.0f;
			}
		}

		PRINT("bridge effect start!\n");
		zen::particleGenerator* efx1 = effectMgr->create(EffectMgr::EFF_Bridge_FinishStage, pos, nullptr, nullptr);
		zen::particleGenerator* efx2 = effectMgr->create(EffectMgr::EFF_Bridge_FinishStage, pos2, nullptr, nullptr);

		if (efx1) {
			efx1->setEmitDir(getBridgeXVec());
		}

		if (efx2) {
			efx2->setEmitDir(getBridgeXVec());
		}

		_3CC = 60;
		_3CA = stageIndex;
		playEventSound(this, SEB_BRIDGE_EXTEND);

	} else {
		setStageFinished(stageIndex, isFinished);
		_3CC = 0;
	}
}

/*
 * --INFO--
 * Address:	8009F14C
 * Size:	0000A0
 */
bool InteractBuild::actBridge(Bridge* bridge)
{
	f32& buildProgress = bridge->mStageProgressList[mCurrentStage];
	bridge->playEventSound(bridge, SEB_CONSTRUCTION);

	buildProgress += mProgressRate;
	if (buildProgress >= bridge->mMaxHealth) {
		buildProgress = bridge->mMaxHealth;
		if (!bridge->_3CC) {
			bridge->startStageFinished(mCurrentStage, true);
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	8009F1EC
 * Size:	0002E8
 */
bool InteractBreak::actBridge(Bridge* bridge)
{
	f32* progress = &bridge->mStageProgressList[mStageIndex];
	*progress -= _0C;
	if (*progress <= 0.0f) {
		*progress = 0.0f;
		for (int i = mStageIndex; i < bridge->getStage(); i++) {
			bridge->setStageFinished(i, false);
			bridge->mStageProgressList[i] = 0.0f;
		}

		PRINT("こわした！ by やましたさん\n"); // 'I broke it! by Yamashita-san'

		bridge->mStartWaypoint->setFlag(false);
		bridge->mEndWaypoint->setFlag(false);
		int firstUnfinished = bridge->getFirstUnfinishedStage();
		if (firstUnfinished != -1) {
			Vector3f wpPos                    = bridge->getStagePos(firstUnfinished) - bridge->getBridgeZVec() * 5.0f;
			bridge->mStartWaypoint->mPosition = wpPos;
		}
	}

	STACK_PAD_STRUCT(1);
	return true;
}

#ifdef DEVELOP

void GenObjectWorkObject::changeNaviPos()
{
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		mHinderRockPosition = navi->mPosition;
	}
}

void GenObjectWorkObject::setNaviPos()
{
	Navi* navi = naviMgr->getNavi();
	if (navi) {
		navi->mPosition     = mHinderRockPosition;
		navi->mLastPosition = mHinderRockPosition;
	}
}

void GenObjectWorkObject::doGenAge(AgeServer& server)
{
	server.StartOptionBox("仕事オブジェクト", (int*)&mObjectType, 252);
	for (int i = 0; i < 2; i++) {
		server.NewOption(workObjectMgr->getName(i), i);
	}
	server.EndOptionBox();

	server.StartOptionBox("シェイプ", &mShapeType, 252);
	for (int i = 0; i < 5; i++) {
		server.NewOption(workObjectMgr->getShapeName(i), i);
	}
	server.EndOptionBox();

	server.NewButton("move to navi pos", new Delegate<GenObjectWorkObject>(this, setNaviPos), 221);
	server.NewButton("move navi to this pos", new Delegate<GenObjectWorkObject>(this, changeNaviPos), 221);
	server.NewEditor("pos x", &mHinderRockPosition.x, -8000.0f, 8000.0f, 320);
	server.NewEditor("pos y", &mHinderRockPosition.y, -8000.0f, 8000.0f, 320);
	server.NewEditor("pos z", &mHinderRockPosition.z, -8000.0f, 8000.0f, 320);
}

#endif
