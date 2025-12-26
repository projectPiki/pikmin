#include "Age.h"
#include "DebugLog.h"
#include "Pellet.h"
#include "PelletAnimator.h"
#include "gameflow.h"
#include "sysNew.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("animPellet");

/**
 * @todo: Documentation
 */
PelletAnimInfo::PelletAnimInfo()
    : mFolderPath(this, String("pellets", 0), String("", 0), String("", 0), "x00", "dirName")
    , mFileName(this, String("noname", 0), String("", 0), String("", 0), "x01", "theName")
{
	mID.setID('none');
	mCreationType  = PCT_Resident;
	mTekiType      = -1;
	mOverrideJoint = -1;

	initCore("pelletAnimInfo");
	mPelletShapeObject = nullptr;
}

/**
 * @todo: Documentation
 */
PelletShapeObject* PelletAnimInfo::createShapeObject()
{
	char path[PATH_MAX];
	char path2[PATH_MAX];

	sprintf(path, "objects/%s/%s.mod", mFolderPath().mString, mFileName().mString);
	Shape* shape = gameflow.loadShape(path, true);

	if (shape) {
		sprintf(path2, "%s.bin", mFileName().mString);
		mPelletShapeObject = new PelletShapeObject(mID.mStringID, shape, mFolderPath().mString, path2, mOverrideJoint);
	} else {
		mPelletShapeObject = nullptr;
	}

	return mPelletShapeObject;
}

/**
 * @todo: Documentation
 */
void PelletAnimInfo::read(RandomAccessStream& stream)
{
	mID.read(stream);
	mCreationType  = stream.readInt();
	mTekiType      = stream.readInt();
	mOverrideJoint = stream.readInt();
	Parameters::read(stream);
}

/**
 * @todo: Documentation
 */
PelletShapeObject::PelletShapeObject(immut char* str1, Shape* shape, immut char* str2, immut char* str3, int overrideJoint)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;

	if (str2) {
		char path[128];
		sprintf(path, "objects/%s/%s", str2, str3);
		mAnimMgr        = new AnimMgr(shape, path, ANIMMGR_LOAD_BUNDLE, nullptr);
		mAnimMgr->mName = str1;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, ANIMMGR_LOAD_NOSKIP, nullptr);
	}

	mShape->overrideAnim(0, &mAnimatorA);
	mMotionFlag = PelletMotionFlags::Unknown;

	if (overrideJoint != -1) {
		mShape->overrideAnim(overrideJoint, &mAnimatorB);
		setMotionFlag(PelletMotionFlags::UsePiston);
	}
}

immut char* PaniPelletAnimator::motionLabels[PelletMotion::COUNT] = { "Carry", "Appear", "3", "4", "5", "6", "7" };

/**
 * @todo: Documentation
 */
PelletAnimator::PelletAnimator()
{
}

/**
 * @todo: Documentation
 */
void PelletAnimator::init(AnimContext* context1, AnimContext* context2, AnimMgr* mgr, PaniMotionTable* motionTable)
{
	mLowerAnimator.init(context1, mgr, motionTable);
	mUpperAnimator.init(context2, mgr, motionTable);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
void PelletAnimator::startMotion(immut PaniMotionInfo* lowerMotionInfo, immut PaniMotionInfo* upperMotionInfo)
{
	if (lowerMotionInfo) {
		mLowerAnimator.startMotion(*lowerMotionInfo);
	}
	if (upperMotionInfo) {
		mUpperAnimator.startMotion(*upperMotionInfo);
	}
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void PelletAnimator::finishMotion(immut PaniMotionInfo* lowerMotionInfo, immut PaniMotionInfo* upperMotionInfo)
{
	if (lowerMotionInfo) {
		mLowerAnimator.finishMotion(*lowerMotionInfo);
	}
	if (upperMotionInfo) {
		mUpperAnimator.finishMotion(*upperMotionInfo);
	}
}

/**
 * @todo: Documentation
 */
void PelletAnimator::startMotion(immut PaniMotionInfo& lowerMotionInfo, immut PaniMotionInfo& upperMotionInfo)
{
	startMotion(&lowerMotionInfo, &upperMotionInfo);
}

/**
 * @todo: Documentation
 */
void PelletAnimator::startMotion(immut PaniMotionInfo& motionInfo)
{
	startMotion(&motionInfo, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084
 */
void PelletAnimator::finishMotion(immut PaniAnimKeyListener*)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void PelletAnimator::updateAnimation(f32 lowerAnimSpeed, f32 upperAnimSpeed)
{
	mLowerAnimator.animate(lowerAnimSpeed);
	mUpperAnimator.animate(upperAnimSpeed);
}

/**
 * @todo: Documentation
 */
void PelletAnimator::updateContext()
{
	mLowerAnimator.updateContext();
	mUpperAnimator.updateContext();
}

/**
 * @todo: Documentation
 */
PaniMotionTable* PaniPelletAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(PelletMotion::COUNT);
	table->setMotion(PelletMotion::Carry, new PaniMotion(PelletMotion::Carry));
	table->setMotion(PelletMotion::Appear, new PaniMotion(PelletMotion::Appear));
	table->setMotion(PelletMotion::After, new PaniMotion(PelletMotion::After));
	table->setMotion(PelletMotion::Piston, new PaniMotion(PelletMotion::Piston));
	table->setMotion(PelletMotion::Special, new PaniMotion(PelletMotion::Special));
	table->setMotion(PelletMotion::Unused5, new PaniMotion(PelletMotion::Unused5));
	table->setMotion(PelletMotion::Unused6, new PaniMotion(PelletMotion::Unused6));
	return table;
}

/**
 * @todo: Documentation
 */
PaniPelletAnimator::PaniPelletAnimator()
{
}

#ifdef WIN32

void PelletAnimInfo::write(RandomAccessStream& output)
{
	mID.write(output);
	output.writeInt(mCreationType);
	output.writeInt(mTekiType);
	output.writeInt(mOverrideJoint);
	Parameters::write(output);
}

void PelletAnimInfo::genAge(AgeServer& server)
{
	server.StartGroup("operation");
	server.NewButton("delete", new Delegate1<PelletAnimInfo, AgeServer&>(this, removeSelf), 221);
	mID.genAge(server, "id");
	if (mPelletShapeObject == nullptr) {
		server.NewButton("new ShapeObject", new Delegate1<PelletAnimInfo, AgeServer&>(this, newShapeObject), 221);
	}
	server.EndGroup();

	server.StartGroup("type");
	server.setOnChange(new Delegate1<PelletAnimInfo, AgeServer&>(this, changeType));
	server.StartOptionBox("type", &mCreationType, 272);
	server.NewOption("常駐", PCT_Resident);
	server.NewOption("あればロード", PCT_LoadIfExists);
	server.NewOption("TEKI 次第でロード", PCT_LoadOnTeki);
	server.NewOption("BOSS 次第でロード", PCT_LoadOnBoss);
	server.EndOptionBox();

	if (mCreationType == PCT_LoadOnTeki) {
		server.StartOptionBox("TEKI", &mTekiType, 252);
		for (int i = 0; i < TEKI_TypeCount; i++) {
			server.NewOption(tekiMgr->getTypeName(i), i);
		}
		server.EndOptionBox();
	}

	server.setOnChange((IDelegate*)nullptr);
	server.EndGroup();

	if (mPelletShapeObject) {
		server.StartGroup("joint");
		server.StartOptionBox("ジョイント", &mOverrideJoint, 252);
		server.NewOption("なし", -1);
		for (int i = 0; i < mPelletShapeObject->mShape->mJointCount; i++) {
			if (mPelletShapeObject->mShape->mJointList[i].mName) {
				server.NewOption(mPelletShapeObject->mShape->mJointList[i].mName, i);
			} else {
				char buf[PATH_MAX];
				sprintf(buf, "joint %d", i);
				server.NewOption(buf, i);
			}
		}
		server.EndOptionBox();
		server.EndGroup();
	}
	genAgeParms(server, 10);
}

void PelletAnimInfo::changeType(AgeServer& server)
{
	server.RefreshSection();
}

void PelletAnimInfo::newShapeObject(AgeServer& server)
{
	if (createShapeObject()) {
		server.RefreshNode();
	}
}

void PelletAnimInfo::removeSelf(AgeServer& server)
{
	pelletMgr->removeAnimInfo(server, this);
}

void PelletShapeObject::genAge(AgeServer& server)
{
	mAnimMgr->genAge(server);
}

#endif
