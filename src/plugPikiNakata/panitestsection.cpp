#include "PaniTestSection.h"
#include "AIConstant.h"
#include "sysNew.h"
#include "MemStat.h"
#include "SoundMgr.h"
#include "Dolphin/os.h"
#include "CodeInitializer.h"
#include "GlobalShape.h"
#include "Piki.h"
#include "FlowController.h"
#include "MapMgr.h"
#include "Route.h"
#include "EffectMgr.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "gameflow.h"
#include "teki.h"
#include "Collision.h"
#include "Font.h"
#include "TekiPersonality.h"
#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"
#include "Graphics.h"
#include "DebugLog.h"

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
DEFINE_PRINT("panitestsection")

/*
 * --INFO--
 * Address:	8011FEF8
 * Size:	000554
 */
PaniTestNode::PaniTestNode()
{
	setName("PaniTestNode");
	AIConstant::createInstance();
	memStat     = new MemStat();
	mController = new Controller(1);
	seSystem    = new SeSystem();
	NakataCodeInitializer::init();
	mShadowTexture = gsys->loadTexture("effects/shadow.txe", true);
	GlobalShape::init();
	PikiShapeObject::init();
	sprintf(flowCont.mAnimationTestPath, "courses/test/animtest.mod");
	mapMgr = new MapMgr(mController);
	mapMgr->initShape();
	routeMgr  = nullptr;
	effectMgr = nullptr;
	pelletMgr = new PelletMgr(mapMgr);
	mMainLight.mPosition.set(0.0f, 500.0f, 0.0f);
	mMainLight.mDistancedRange = 500.0f;
	mMainLight.update();
	pikiMgr = new PikiMgr(nullptr);
	pikiMgr->init();
	pikiMgr->mMapMgr = mapMgr;
	FastGrid::initAIGrid(9);
	_674 = 300.0f;

	mTestPikiCount = 1;
	pikiMgr->create(mTestPikiCount);
	mTestPikiList = new Piki*[mTestPikiCount];

	int i;
	for (i = 0; i < mTestPikiCount; i++) {
		mTestPikiList[i] = static_cast<ViewPiki*>(pikiMgr->birth());
		mTestPikiList[i]->init(nullptr);
		mTestPikiList[i]->mScale.set(1.0f, 1.0f, 1.0f);
		mTestPikiList[i]->mRotation.set(0.0f, 0.0f, 0.0f);
		mTestPikiList[i]->mPosition.set(0.0f, 0.0f, 0.0f);
		mTestPikiList[i]->initColor(Blue);
	}

	gameflow.addGenNode("pikiMgr", pikiMgr);

	tekiMgr = new TekiMgr();
	gameflow.addGenNode("tekiMgr", tekiMgr);

	tekiMgr->create(TEKI_TypeCount);
	mTestTekiList = new Teki*[TEKI_TypeCount];
	tekiMgr->setUsingTypeTable(true);
	tekiMgr->mUsingType[TEKI_Frog]    = true;
	tekiMgr->mUsingType[TEKI_Swallob] = true;
	tekiMgr->mUsingType[TEKI_Chappb]  = true;
	tekiMgr->mUsingType[TEKI_Frow]    = true;

	for (i = 0; i < TEKI_TypeCount; i++) {
		if (tekiMgr->hasType(i)) {
			mTestTekiList[i]             = tekiMgr->newTeki(i);
			TekiPersonality* personality = mTestTekiList[i]->mPersonality;
			personality->mPosition.input(Vector3f(0.0f, 0.0f, 0.0f));
			personality->mNestPosition.input(Vector3f(0.0f, 0.0f, 0.0f));
			personality->mFaceDirection = 0.0f;
			mTestTekiList[i]->reset();
		} else {
			mTestTekiList[i] = nullptr;
		}
	}

	mFocusTekiType = TEKI_Napkid;
	tekiMgr->startStage();

	mFadeState = 0;

	Texture* fontTex = gsys->loadTexture("consFont.bti", true);
	mConsFont        = new Font();
	mConsFont->setTexture(fontTex, 16, 8);

	gsys->setFade(1.0f, 3.0f);
	mCamMgr         = new PcamCameraManager(&mActiveCamera, mController);
	mAnimationSpeed = 30.0f;
	_68C            = 0;

	setTestMode(PANITEST_Teki);
}

/*
 * --INFO--
 * Address:	8012044C
 * Size:	000084
 */
void PaniTestNode::setTestMode(int mode)
{
	mTestMode           = mode;
	Creature* camTarget = nullptr;
	switch (mTestMode) {
	case PANITEST_Piki:
		camTarget = mTestPikiList[0];
		break;
	case PANITEST_Teki:
		camTarget = mTestTekiList[mFocusTekiType];
		break;
	}

	mCamMgr->mCamera->startCamera(camTarget, 1, 0);
	mMotionId = 0;
}

/*
 * --INFO--
 * Address:	801204D0
 * Size:	00048C
 */
void PaniTestNode::update()
{
	mController->update();

	Controller* ctrl = mController;
	f32 subY         = 0.0f;
	if (ctrl->keyDown(KBBTN_X)) {
		subY = ctrl->getSubStickY();
	}

	PcamControlInfo camInfo;
	camInfo.init(true, ctrl->keyDown(KBBTN_L), false, ctrl->keyClick(KBBTN_R), false, false, ctrl->keyDown(KBBTN_X), ctrl->getMainStickX(),
	             subY, ctrl->getSubStickY());

	mCamMgr->mCamera->control(camInfo);

	mCamMgr->mCamera->update();

	if (mController->keyDown(KBBTN_L) && mController->keyUnClick(KBBTN_A)) {
		if (mTestMode == PANITEST_Teki) {
			setTestMode(PANITEST_Piki);
		} else {
			setTestMode(mTestMode + 1);
		}
	}

	if (mController->keyDown(KBBTN_L) && mController->keyUnClick(KBBTN_CSTICK_RIGHT)) {
		do {
			mFocusTekiType++;
			if (mFocusTekiType == TEKI_TypeCount) {
				mFocusTekiType = TEKI_START;
			}
		} while (!tekiMgr->hasType(mFocusTekiType));
	}

	if (mController->keyDown(KBBTN_L) && mController->keyUnClick(KBBTN_CSTICK_LEFT)) {
		do {
			mFocusTekiType--;
			if (mFocusTekiType == -1) {
				mFocusTekiType = TEKI_TypeCount - 1;
			}
		} while (!tekiMgr->hasType(mFocusTekiType));
	}

	if (mController->keyUnClick(KBBTN_B)) {
		_68C = !_68C;
	}

	mAnimationEvent = -1;

	switch (mTestMode) {
	case PANITEST_Piki:
		updatePikis();
		break;
	case PANITEST_Teki:
		updateTekis();
		break;
	}

	if (mController->keyDown(KBBTN_CSTICK_UP)) {
		mAnimationSpeed += 0.2f;
		if (mAnimationSpeed > 60.0f) {
			mAnimationSpeed = 60.0f;
		}
	}

	if (mController->keyDown(KBBTN_CSTICK_DOWN)) {
		mAnimationSpeed -= 0.2f;
		if (mAnimationSpeed < 0.0f) {
			mAnimationSpeed = 0.0f;
		}
	}

	int amt = 0;
	switch (mTestMode) {
	case PANITEST_Piki:
		amt = 90;
		break;
	case PANITEST_Teki:
		amt = 15;
		break;
	}

	if (!mController->keyDown(KBBTN_L) && mController->keyUnClick(KBBTN_CSTICK_LEFT)) {
		mMotionId--;
		if (mMotionId < 0) {
			mMotionId = amt - 1;
		}
	}

	if (!mController->keyDown(KBBTN_L) && mController->keyUnClick(KBBTN_CSTICK_RIGHT)) {
		mMotionId++;
		if (mMotionId > amt - 1) {
			mMotionId = 0;
		}
	}

	if (mFadeState == 0) {
		if (mController->keyUnClick(KBBTN_START)) {
			mFadeState = 1;
			gsys->setFade(0.0f, 3.0f);
		}
		Node::update();
	} else if (mFadeState == 1) {
		if (gsys->getFade() == 0.0f) {
			gameflow.mGameSectionID = SECTION_Titles;
			gsys->softReset();
		}
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	8012095C
 * Size:	0002B4
 */
void PaniTestNode::updatePikis()
{
	int i;
	for (i = 0; i < mTestPikiCount; i++) {
		// can you tell how much i dont wanna change the Creature scale/rot/pos definition to an SRT?
		SRT* srt = (SRT*)&mTestPikiList[i]->mScale;
		mTestPikiList[i]->mWorldMtx.makeSRT_(*srt);
	}

	if (_68C) {
		if (mController->keyUnClick(KBBTN_A)) {
			for (i = 0; i < mTestPikiCount; i++) {
				for (int j = 0; j < 10; j++) {
					mTestPikiList[i]->mPikiAnimMgr.updateAnimation(mAnimationSpeed);
				}
			}
		}
		return;
	}

	for (i = 0; i < mTestPikiCount; i++) {
		mTestPikiList[i]->mPikiAnimMgr.updateAnimation(mAnimationSpeed);
	}

	if (mController->keyUnClick(KBBTN_A)) {
		mTestPikiList[0]->mPikiAnimMgr.startMotion(&PaniMotionInfo(mMotionId, this), &PaniMotionInfo(mMotionId));

		for (i = 1; i < mTestPikiCount; i++) {
			mTestPikiList[i]->mPikiAnimMgr.startMotion(&PaniMotionInfo(mMotionId, nullptr), &PaniMotionInfo(mMotionId));
		}
	}

	if (mController->keyUnClick(KBBTN_X)) {
		mTestPikiList[0]->mPikiAnimMgr.finishMotion(&PaniMotionInfo(-1, this), &PaniMotionInfo(-1));

		for (i = 1; i < mTestPikiCount; i++) {
			mTestPikiList[i]->mPikiAnimMgr.finishMotion(&PaniMotionInfo(-1, nullptr), &PaniMotionInfo(-1));
		}
	}
}

/*
 * --INFO--
 * Address:	80120C10
 * Size:	0001BC
 */
void PaniTestNode::updateTekis()
{
	// can you tell how much i dont wanna change the Creature scale/rot/pos definition to an SRT?
	SRT* srt = (SRT*)&mTestTekiList[mFocusTekiType]->mScale;
	mTestTekiList[mFocusTekiType]->mWorldMtx.makeSRT_(*srt);

	if (_68C) {
		if (mController->keyUnClick(KBBTN_A)) {
			for (int i = 0; i < 10; i++) {
				mTestTekiList[mFocusTekiType]->mTekiAnimator->animate(mAnimationSpeed);
			}
		}
		return;
	}

	mTestTekiList[mFocusTekiType]->mTekiAnimator->animate(mAnimationSpeed);

	if (mController->keyUnClick(KBBTN_A)) {
		mTestTekiList[mFocusTekiType]->mTekiAnimator->startMotion(PaniMotionInfo(mMotionId, this));
	}

	if (mController->keyUnClick(KBBTN_X)) {
		mTestTekiList[mFocusTekiType]->mTekiAnimator->finishMotion(PaniMotionInfo(-1, this));
	}
}

/*
 * --INFO--
 * Address:	80120DCC
 * Size:	00006C
 */
void PaniTestNode::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	mAnimationEvent = event.mEventType;
	if (mTestMode == PANITEST_Piki) {
		mTestPikiList[0]->animationKeyUpdated(event);
	} else { // mTestMode == PANITEST_Teki
		mTestTekiList[mFocusTekiType]->animationKeyUpdated(event);
	}
}

/*
 * --INFO--
 * Address:	80120E38
 * Size:	000684
 */
void PaniTestNode::draw(Graphics& gfx)
{
	mapMgr->preRender(gfx);

	gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setClearColour(Colour(96, 128, 255, 0));
	gfx.clearBuffer(3, false);

	Matrix4f mtx1;
	gfx.setOrthogonal(mtx1.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	mActiveCamera.update(f32(gfx.mScreenWidth) / f32(gfx.mScreenHeight), mActiveCamera.mFov, 1.0f, 1000.0f);
	gfx.setCamera(&mActiveCamera);
	gfx.addLight(&mMainLight);
	gfx.calcLighting(1.0f);

	Matrix4f mtx2;
	gfx.calcViewMatrix(Matrix4f::ident, mtx2);
	gfx.setPerspective(mActiveCamera.mPerspectiveMatrix.mMtx, mActiveCamera.mFov, mActiveCamera.mAspectRatio, mActiveCamera.mNear,
	                   mActiveCamera.mFar, 1.0f);
	gfx.setLighting(true, nullptr);
	gfx.setFog(true, mFogColour, 1.0f, 750.0f, mActiveCamera.mFar);
	switch (mTestMode) {
	case PANITEST_Piki:
		for (int i = 0; i < mTestPikiCount; i++) {
			drawPiki((ViewPiki*)mTestPikiList[i], gfx);
		}
		pikiMgr->drawShadow(gfx, mShadowTexture);
		break;
	case PANITEST_Teki:
		drawTeki(mTestTekiList[mFocusTekiType], gfx);
		tekiMgr->drawShadow(gfx, mShadowTexture);
		break;
	}

	mapMgr->refresh(gfx);
	seSystem->update(gfx, Vector3f(0.0f, 0.0f, 0.0f));

	Matrix4f mtx3;
	gfx.calcViewMatrix(Matrix4f::ident, mtx3);
	gfx.useMatrix(mtx3, 0);

	int blend = gfx.setCBlending(2);
	gfx.setDepth(0);
	gfx.setLighting(false, nullptr);
	gfx.useTexture(mShadowTexture, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setCBlending(blend);
	gfx.setDepth(1);

	Matrix4f mtx4;
	gfx.setOrthogonal(mtx4.mMtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	Node::draw(gfx);

	gfx.texturePrintf(gsys->mConsFont, 0, 440, "VerticalDegree:%d", int(NMathF::r2d(mCamMgr->mCamera->getPolar().mInclination)));
	gfx.texturePrintf(gsys->mConsFont, 0, 430, "Speed:%3.1f", mAnimationSpeed);

	char* motionLabel = nullptr;
	switch (mTestMode) {
	case PANITEST_Piki:
		motionLabel = PaniPikiAnimator::motionLabels[mMotionId];
		break;
	case PANITEST_Teki:
		motionLabel = PaniTekiAnimator::motionLabels[mMotionId];
		break;
	}
	gfx.texturePrintf(gsys->mConsFont, 0, 420, "Motion:%d:%s", mMotionId, motionLabel);

	f32 animCounter = 0.0f;
	int frameCount  = 0;
	switch (mTestMode) {
	case PANITEST_Piki:
		animCounter = mTestPikiList[0]->mPikiAnimMgr.getUpperAnimator().mAnimationCounter;
		frameCount  = mTestPikiList[0]->mPikiAnimMgr.getUpperAnimator().getFrameCount();
		break;

	case PANITEST_Teki:
		animCounter = mTestTekiList[mFocusTekiType]->mTekiAnimator->mAnimationCounter;
		frameCount  = mTestTekiList[mFocusTekiType]->mTekiAnimator->getFrameCount();
		break;
	}

	gfx.texturePrintf(gsys->mConsFont, 0, 410, "Counter:%4.1f/%d", animCounter, frameCount);
	gfx.texturePrintf(gsys->mConsFont, 0, 400, "Name:%s", TekiMgr::getTypeName(mFocusTekiType));
}

/*
 * --INFO--
 * Address:	801214BC
 * Size:	000034
 */
void PaniTestNode::drawPiki(ViewPiki* piki, Graphics& gfx)
{
	piki->refresh(gfx);
}

/*
 * --INFO--
 * Address:	801214F0
 * Size:	000034
 */
void PaniTestNode::drawTeki(Teki* teki, Graphics& gfx)
{
	teki->refresh(gfx);
}

/*
 * --INFO--
 * Address:	80121524
 * Size:	000078
 */
void PaniTestSection::init()
{
	Node::init("<PaniTestSection>");
	switch (gameflow.mNextOnePlayerSectionID) {
	case ONEPLAYER_GameSetup:
		add(new PaniTestNode);
		break;
	}
}
