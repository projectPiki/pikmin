#include "CinematicPlayer.h"
#include "Creature.h"
#include "Vector.h"
#include "Graphics.h"
#include "sysNew.h"
#include "UfoItem.h"
#include "EffectMgr.h"
#include "NaviMgr.h"
#include "Interface.h"
#include "ItemMgr.h"
#include "gameflow.h"
#include "zen/Math.h"
#include "MoviePlayer.h"
#include "Demo.h"
#include "DebugLog.h"

/**
 * @brief Error function for cinePlayer.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/**
 * @brief Print function for cinePlayer.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("CinePlayer")

/// Pointer buffer for storing backup animations during cutscenes (max 256).
static AnimContext* bcs[0x100];

/**
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void CineShapeObject::init(char* modelPath, char* animPath, char* bundlePath)
{
	mModel = gameflow.loadShape(modelPath, true);
	if (animPath) {
		mMgr        = new AnimMgr(mModel, animPath, ANIMMGR_LOAD_BUNDLE, bundlePath);
		mMgr->mName = animPath;
	}
}

/**
 * --INFO--
 * Address:	8006FA1C
 * Size:	0001BC
 */
void CinematicPlayer::init(char* cinFilePath)
{
	// reset cutscene-specific things
	mTotalDuration       = 0;
	mCurrentData         = nullptr;
	mCurrentPlaybackTime = 0.0f;
	mPlaybackSpeed       = 30.0f;
	mDataList.initCore("");
	mActorList.initCore("");
	mSceneList.initCore("");

	// load in our cutscene
	if (cinFilePath) {
		loadCin(cinFilePath);
		calcMaxFrames();
	}

	// if we have a scene, setup the cameras and lights
	if (mCurrentData) {
		int i;
		for (i = 0; i < mCurrentData->mNumCameras; i++) {
			mCurrentData->mCameraData[i].mBlendRatio = 0.0f;
			mCurrentData->mCameraData[i].update(0.0f, Matrix4f::ident);
		}

		for (i = 0; i < mCurrentData->mNumLights; i++) {
			mCurrentData->mLightData[i].update(0.0f);
		}
	}
}

/**
 * --INFO--
 * Address:	8006FBD8
 * Size:	0001B0
 */
CinematicPlayer::CinematicPlayer(char* cinFilePath)
{
	// reset essential things
	mFlags              = 0;
	mType               = 0;
	mTarget             = nullptr;
	mCurrentScene       = nullptr;
	mPreviousScene      = nullptr;
	mPreviousSceneFrame = -1.0f;
	mUseStaticCamera    = false;

	// setup given cutscene + current scene (if any)
	init(cinFilePath);
	mSceneSkipFlag = SCENESKIP_NULL;
}

/**
 * --INFO--
 * Address:	8006FEB8
 * Size:	000720
 */
void CinematicPlayer::loadCin(char* cinFilePath)
{
	mCurrentData = nullptr;
	Stream* file = gsys->openFile(cinFilePath, true, true);
	if (!file) {
		return;
	}

	CmdStream* cmd = new CmdStream(file);
	if (cmd) {
		while (!cmd->endOfCmds() && !cmd->endOfSection()) {
			cmd->getToken(true);

			//// "Movie flags" section in .cin file ////
			if (cmd->isToken("type")) { // this is completely unused.
				sscanf(cmd->getToken(true), "%d", &mType);
				continue;
			}

			if (cmd->isToken("flags")) { // see CinematicPlayerFlags enum
				sscanf(cmd->getToken(true), "%d", &mFlags);
				continue;
			}

			//// "Scene files" section in .cin file ////
			if (cmd->isToken("addScene")) {
				cmd->getToken(true);
				while (!cmd->endOfCmds() && !cmd->endOfSection()) {
					cmd->getToken(true);
					if (cmd->isToken("scene")) {
						SceneData* data = new SceneData;
						// copy dsk file path as name
						data->mName = StdSystem::stringDup(cmd->getToken(true));
						mDataList.add(data);
					}
				}

				if (!cmd->endOfCmds()) {
					cmd->getToken(true);
				}
				continue;
			}

			//// "Actor files" section in .cin file ////
			if (cmd->isToken("addActor")) {
				cmd->getToken(true);
				CineShapeObject* actor = nullptr;
				while (!cmd->endOfCmds() && !cmd->endOfSection()) {
					cmd->getToken(true);
					if (cmd->isToken("shape")) {
						// create new actor with .mod file path as name
						actor        = new CineShapeObject;
						actor->mName = StdSystem::stringDup(cmd->getToken(true));
						mActorList.add(actor);

					} else if (cmd->isToken("bundle")) {
						// add .anm filename
						actor->mBundleFilePath = StdSystem::stringDup(cmd->getToken(true));

					} else if (cmd->isToken("anims")) {
						// add .bin filename
						actor->mAnimFilePath = StdSystem::stringDup(cmd->getToken(true));
					}
				}

				if (!cmd->endOfCmds()) {
					cmd->getToken(true);
				}
				continue;
			}

			//// "Scene cuts" section in .cin file ////
			if (cmd->isToken("addCut")) {
				cmd->getToken(true);
				SceneCut* scene      = nullptr;
				ActorInstance* actor = nullptr;
				while (!cmd->endOfCmds() && !cmd->endOfSection()) {
					cmd->getToken(true);

					if (cmd->isToken("cut")) {
						// setup basic scene info
						int sceneID;
						sscanf(cmd->getToken(true), "%d", &sceneID);
						int startFrame;
						sscanf(cmd->getToken(true), "%d", &startFrame);
						int endFrame;
						sscanf(cmd->getToken(true), "%d", &endFrame);
						scene = addCut(sceneID, startFrame, endFrame);
						actor = nullptr;
						continue;
					}

					if (cmd->isToken("flags")) {
						// set scene flags
						sscanf(cmd->getToken(true), "%d", &scene->mFlags);
						continue;
					}

					if (cmd->isToken("actor")) {
						// set actor model file
						actor = scene->addInstance(cmd->getToken(true));
						continue;
					}

					if (cmd->isToken("acflags")) {
						// set actor flags
						sscanf(cmd->getToken(true), "%d", &actor->mFlags);
						continue;
					}

					if (cmd->isToken("anim")) {
						// set anim info
						sscanf(cmd->getToken(true), "%d", &actor->mAnimPlayState);
						sscanf(cmd->getToken(true), "%d", &actor->mColourAnimIndex);
						continue;
					}

					if (cmd->isToken("keys")) {
						// set up any keyframe events
						int max;
						sscanf(cmd->getToken(true), "%d", &max);
						AnimKey* keys = new AnimKey[max];
						cmd->getToken(true);
						for (int i = 0; i < max; i++) {
							int eventType;
							sscanf(cmd->getToken(true), "%d", &eventType);
							int eventID;
							sscanf(cmd->getToken(true), "%d", &eventID);
							int value;
							sscanf(cmd->getToken(true), "%d", &value);
							int frameIdx;
							sscanf(cmd->getToken(true), "%d", &frameIdx);

							keys[i].mEventType  = eventType;
							keys[i].mEventCmdID = eventID;
							keys[i].mKeyType    = value;
							keys[i].mFrameIndex = frameIdx;
							scene->mKey.mPrev->insertAfter(&keys[i]);
						}
						cmd->getToken(true);
						continue;
					}
				}
				if (!cmd->endOfCmds()) {
					cmd->getToken(true);
				}
			}
		}
	}

	file->close();
	// set up any scenes we've loaded
	for (SceneData* data = (SceneData*)mDataList.mChild; data; data = (SceneData*)data->mNext) {
		addScene(data);
	}

	// set up any actors we've loaded
	for (CineShapeObject* actor = (CineShapeObject*)mActorList.mChild; actor; actor = (CineShapeObject*)actor->mNext) {
		addActor(actor);
	}

	STACK_PAD_VAR(1);
}

/**
 * --INFO--
 * Address:	800705D8
 * Size:	0000B4
 */
void CinematicPlayer::addScene(SceneData* scene)
{
	Stream* data = gsys->openFile(scene->mName, true, true);
	if (data) {
		CmdStream* cmd = new CmdStream(data);
		if (cmd) {
			scene->parse(cmd);
		}
		data->close();
	}
	mCurrentData = scene;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000124
 */
SceneData* CinematicPlayer::addScene(char* dskFilePath)
{
	SceneData* data = new SceneData;
	data->mName     = dskFilePath;
	mDataList.add(data);
	addScene(data);
	return data;
}

/**
 * --INFO--
 * Address:	8007068C
 * Size:	000090
 */
SceneCut* CinematicPlayer::addCut(int sceneID, int startFrame, int endFrame)
{
	// grab a new scene cut
	SceneCut* scene = addSceneCut();

	scene->mSceneID    = sceneID;
	scene->mSceneData  = findScene(scene->mSceneID);
	scene->mStartFrame = startFrame;
	scene->mEndFrame   = endFrame;
}

/**
 * --INFO--
 * Address:	8007071C
 * Size:	0000A0
 */
void CinematicPlayer::addActor(CineShapeObject* actor)
{
	actor->init(actor->mName, actor->mAnimFilePath, actor->mBundleFilePath);
}

/**
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void CinematicPlayer::addActor(char* modelFilePath, char* animFilePath, char* bundleFilePath)
{
	CineShapeObject* actor = new CineShapeObject;
	actor->mName           = modelFilePath;
	actor->mAnimFilePath   = animFilePath;
	actor->mBundleFilePath = bundleFilePath;
	mActorList.add(actor);
	addActor(actor);
}

/**
 * --INFO--
 * Address:	800707BC
 * Size:	000138
 */
SceneCut* CinematicPlayer::addSceneCut()
{
	SceneCut* cut      = new SceneCut;
	cut->mParentPlayer = this;
	cut->mSceneData    = findScene(cut->mSceneID);
	cut->mEndFrame     = cut->mSceneData->mNumFrames;
	mSceneList.add(cut);
	return cut;
}

/**
 * --INFO--
 * Address:	800708F4
 * Size:	000084
 */
void CinematicPlayer::skipScene(int sceneSkipFlag)
{
	if (mCurrentScene) {
		PRINT("skipping scene!\n");
		// skip time ahead as if scene had finished playing
		mCurrentPlaybackTime   = mCurrentSceneStartTime + abs(mCurrentScene->mEndFrame - mCurrentScene->mStartFrame);
		mCurrentSceneStartTime = mCurrentPlaybackTime;

		// update skipping flag
		mSceneSkipFlag = sceneSkipFlag;
	}
}

/**
 * --INFO--
 * Address:	80070978
 * Size:	000574
 */
BOOL CinematicPlayer::update()
{
	BOOL isFinished = FALSE;
	if (mCurrentScene && mIsPlaying && mSceneSkipFlag == SCENESKIP_NULL && mPlaybackMode == CINMODE_LoopScene) {
		// loop scene!
		if (mCurrentPlaybackTime >= (f32)abs(mCurrentScene->mEndFrame - mCurrentScene->mStartFrame) + mCurrentSceneStartTime) {
			// we're at the end of a loop, so go back to the start of the scene
			mCurrentPlaybackTime -= (f32)abs(mCurrentScene->mEndFrame - mCurrentScene->mStartFrame);
			mPreviousScene = nullptr; // triggers the scene actors to be re-setup
		}
	}

	if (mSceneSkipFlag == SCENESKIP_Skip || (int)mCurrentPlaybackTime >= mTotalDuration) {
		// either we skipped the cutscene, or it's finished playing
		isFinished           = TRUE;
		mCurrentPlaybackTime = (f32)mTotalDuration;
		mPlaybackSpeed       = 0.0f;
	}

	mSceneSkipFlag        = SCENESKIP_NULL;
	bool foundActiveScene = false;
	mTotalDuration        = 0;
	mCurrentScene         = nullptr;

	// every frame, we loop through all the scenes of this cutscene and calculate what should be playing
	for (SceneCut* scene = (SceneCut*)mSceneList.mChild; scene; scene = (SceneCut*)scene->mNext) {
		int sceneStartTime = mTotalDuration;
		mTotalDuration += abs(scene->mEndFrame - scene->mStartFrame);
		if (mCurrentPlaybackTime >= (f32)sceneStartTime && mCurrentPlaybackTime < (f32)mTotalDuration) {
			// this is the scene that should be active based on playback time, make sure info's set up correctly
			mCurrentScene          = scene;
			mCurrentData           = mCurrentScene->mSceneData;
			mPlaybackMode          = (mCurrentScene->mFlags >> 1) & 7; // 0x2 | 0x4 | 0x8
			mCurrentSceneStartTime = sceneStartTime;
			// calc how far through the scene we are
			f32 ratio          = ((mCurrentPlaybackTime - sceneStartTime) / absF(f32(scene->mEndFrame) - f32(scene->mStartFrame)));
			mCurrentSceneFrame = scene->mStartFrame + (f32(scene->mEndFrame) - f32(scene->mStartFrame)) * ratio;
			foundActiveScene   = true;
		}
	}

	if (mCurrentScene != mPreviousScene) {
		// we just transitioned to a new scene, clean up old scene
		if (mPreviousScene) {
			for (ActorInstance* actor = (ActorInstance*)mPreviousScene->mActorList.mChild; actor; actor = (ActorInstance*)actor->mNext) {
				actor->exitInstance();
			}
		}

		if (mCurrentScene) {
			mPreviousSceneFrame = -1.0f;
			for (ActorInstance* actor = (ActorInstance*)mCurrentScene->mActorList.mChild; actor; actor = (ActorInstance*)actor->mNext) {
				actor->initInstance();
			}
		}

		// make sure we don't do this every frame unless we transition
		mPreviousScene = mCurrentScene;
	}

	// round the current scene frame up for the global tracker (we increment the local one at the end)
	gameflow.mMoviePlayer->mCurrentFrame = mCurrentSceneFrame + 0.5f;

	if (mCurrentScene) {
		// check for keyframe events
		for (AnimKey* key = mCurrentScene->mKey.mNext; key != &mCurrentScene->mKey; key = key->mNext) {
			// if we've just passed a key frame, trigger event
			if ((f32)key->mFrameIndex >= mPreviousSceneFrame && (f32)key->mFrameIndex < mCurrentSceneFrame) {

				// event!
				PRINT("(%.3f : %.3f) got event at frame %d : %d, %d, %d\n", mPreviousSceneFrame, mCurrentSceneFrame, key->mFrameIndex,
				      key->mEventType, key->mEventCmdID, key->mKeyType);
				if (mIsPlaying && gameflow.mGameInterface && key->mEventType == ANIMEVENT_Notify) {
					gameflow.mGameInterface->message(key->mEventCmdID, key->mKeyType);

				} else if (key->mEventType == ANIMEVENT_Action && demoEventMgr) {
					demoEventMgr->act(key->mEventCmdID, key->mKeyType);
				}
			}
		}
		mPreviousSceneFrame = mCurrentSceneFrame;
	}

	if (!foundActiveScene) {
		mCurrentSceneFrame = 0.0f;
	}

	if (mCurrentData) {
		int i;
		// update camera and lights
		for (i = 0; i < mCurrentData->mNumCameras; i++) {
			mCurrentData->mCameraData[i].mBlendRatio      = mCameraBlendRatio;
			mCurrentData->mCameraData[i].mTargetFov       = mCameraTargetFov;
			mCurrentData->mCameraData[i].mCameraPosition  = mCameraPosition;
			mCurrentData->mCameraData[i].mCameraLookAt    = mCameraLookAt;
			mCurrentData->mCameraData[i].mUseStaticCamera = mUseStaticCamera;
			mCurrentData->mCameraData[i].mStaticLookAt    = mStaticLookAt;
			mCurrentData->mCameraData[i].update(mCurrentSceneFrame, mWorldMtx);
		}
		for (i = 0; i < mCurrentData->mNumLights; i++) {
			mCurrentData->mLightData[i].update(mCurrentSceneFrame);
		}
	}

	mCurrentPlaybackTime += 1.0f;

	if (isFinished) {
		mPreviousScene = nullptr;
	}
	return isFinished;
}

/**
 * --INFO--
 * Address:	80070EEC
 * Size:	0000C4
 */
void CinematicPlayer::addLights(Graphics& gfx)
{
	if (!mCurrentData) {
		return;
	}

	gfx.useMatrix(Matrix4f::ident, 0);
	for (int i = 0; i < mCurrentData->mNumLights; i++) {
		if (mCurrentData->mLightData[i].mIsActive) {
			gfx.addLight(&mCurrentData->mLightData[i].mLight);
		}
	}
}

/**
 * --INFO--
 * Address:	80070FB0
 * Size:	0000A8
 */
void CinematicPlayer::refresh(Graphics& gfx)
{
	Matrix4f mtx;
	STACK_PAD_VAR(1);
	gfx.calcViewMatrix(mWorldMtx, mtx);
	gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);

	if (mCurrentScene) {
		for (ActorInstance* actor = (ActorInstance*)mCurrentScene->mActorList.mChild; actor; actor = (ActorInstance*)actor->mNext) {
			actor->refresh(mtx, gfx, !(actor->mFlags & 0x100) ? &mCurrentSceneFrame : nullptr);
		}
	}
}

/**
 * --INFO--
 * Address:	80071058
 * Size:	000190
 */
ActorInstance* SceneCut::addInstance(char* modelFilePath)
{
	ActorInstance* actor = new ActorInstance;
	actor->mParentPlayer = mParentPlayer;
	if (modelFilePath) {
		CineShapeObject* shape = mParentPlayer->findActor(modelFilePath);
		actor->mActiveActor    = shape;
		actor->mDefaultActor   = shape;
	}
	mActorList.add(actor);
	return actor;
}

/**
 * --INFO--
 * Address:	........
 * Size:	000024
 */
int SceneCut::countEKeys()
{
	int i = 0;
	for (AnimKey* key = mKey.mNext; key != &mKey; key = key->mNext) {
		i++;
	}
	return i;
}

/**
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void ActorInstance::onceInit()
{
	mLeafModel = gameflow.loadShape("pikis/happas/leaf.mod", true);
	mDefaultActor->mModel->makeInstance(mDynMats, 0);
	// UNUSED FUNCTION
}

/**
 * --INFO--
 * Address:	800711E8
 * Size:	0000C4
 */
void ActorInstance::exitInstance()
{
	if (effectMgr) {
		for (int i = 0; i < 9; i++) {
			if (mEffectList[i]) {
				effectMgr->kill(mEffectList[i], false);
				mEffectList[i] = nullptr;
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				if (mEffectGrid[j][i]) {
					effectMgr->kill(mEffectGrid[j][i], false);
					mEffectGrid[j][i] = nullptr;
				}
			}
		}
	}
}

/**
 * --INFO--
 * Address:	800712AC
 * Size:	0001BC
 */
void ActorInstance::initInstance()
{
	mActiveActor = mDefaultActor;

	mEffectList[8] = nullptr;
	mEffectList[7] = nullptr;
	mEffectList[6] = nullptr;
	mEffectList[5] = nullptr;
	mEffectList[4] = nullptr;
	mEffectList[3] = nullptr;
	mEffectList[2] = nullptr;
	mEffectList[1] = nullptr;
	mEffectList[0] = nullptr;

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			mEffectGrid[j][i] = nullptr;
		}
	}

	if (mFlags & 0x200) {
		if (mFlags & 0x40000) {
			PRINT("setting onion with multi colour %d\n", mColourAnimIndex);
			static f32 onionColours[] = { 10.0f, 9.0f, 8.0, 13.0, 11.0, 12.0, 7.0, 10.0, 9.0, 8.0, 11.0, 8.0, 9.0, 10.0 };
			mColourValue              = onionColours[mColourAnimIndex - 1];
		}
		if (effectMgr) {
			PRINT("init effect instance!\n");
			mEffectList[0] = effectMgr->create(EffectMgr::EFF_Kafun_NG, mJointPositions[0], nullptr, nullptr);
			mEffectList[0]->setEmitPosPtr(mJointPositions);
		}
	}

	if (mFlags & 0x20 && naviMgr && naviMgr->getNavi()) {
		naviMgr->getNavi()->startDayEnd();
	}

	if (!mIsLeaf) {
		mIsLeaf = 1;
		onceInit();
	}

	if (mActiveActor->mMgr && mColourAnimIndex >= 0) {
		mAnimator.init(&mActiveActor->mContext, mActiveActor->mMgr);
		mAnimator.startAnim(mAnimPlayState, mColourAnimIndex, 0, 8);
	}
}

/**
 * --INFO--
 * Address:	80071468
 * Size:	000DCC
 */
void ActorInstance::checkEventKeys(f32 curTime, f32 prevTime, Vector3f& pos)
{
	for (int i = 0; i < mAnimator.mAnimInfo->countEKeys(); i++) {
		AnimKey* key = mAnimator.mAnimInfo->getEventKey(i);
		f32 keyFrame = key->mFrameIndex;

		if (curTime <= keyFrame && keyFrame < prevTime) {
			if (key->mEventType == ANIMEVENT_Notify) {
				continue;
			}
			if (key->mEventType == ANIMEVENT_Action) {
				u8 id = key->mKeyType;
				switch (id) {
				case 0:
					if (mapMgr) {
						pos.y = mapMgr->getMinY(pos.x, pos.z, true);
					}
					effectMgr->create(EffectMgr::EFF_SmokeRing_S, pos, nullptr, nullptr);
					break;
				case 1:
					if (mapMgr) {
						pos.y = mapMgr->getMinY(pos.x, pos.z, true);
					}
					effectMgr->create(EffectMgr::EFF_SmokeRing_M, pos, nullptr, nullptr);
					break;
				case 2:
					effectMgr->create(EffectMgr::EFF_Rocket_Sparkles1, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
					break;
				case 3:
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomC, pos, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomW, pos, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomH, pos, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomP, pos, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomK, pos, nullptr, nullptr);
					break;
				case 4:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_Tbc1, mJointPositions[0], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[0]);
					mEffectList[1] = effectMgr->create(EffectMgr::EFF_Rocket_Tbf1, mJointPositions[0], nullptr, nullptr);
					mEffectList[1]->setEmitPosPtr(&mJointPositions[0]);
					mEffectList[2] = effectMgr->create(EffectMgr::EFF_Rocket_Tbf2, mJointPositions[0], nullptr, nullptr);
					mEffectList[2]->setEmitPosPtr(&mJointPositions[0]);
					break;
				case 5:
					mEffectList[3] = effectMgr->create(EffectMgr::EFF_Rocket_Tbc1, mJointPositions[1], nullptr, nullptr);
					mEffectList[3]->setEmitPosPtr(&mJointPositions[1]);
					mEffectList[4] = effectMgr->create(EffectMgr::EFF_Rocket_Tbf1, mJointPositions[1], nullptr, nullptr);
					mEffectList[4]->setEmitPosPtr(&mJointPositions[1]);
					mEffectList[5] = effectMgr->create(EffectMgr::EFF_Rocket_Tbf2, mJointPositions[1], nullptr, nullptr);
					mEffectList[5]->setEmitPosPtr(&mJointPositions[1]);
					break;
				case 6:
					for (int i = 0; i < 6; i++) {
						if (mEffectList[i]) {
							effectMgr->kill(mEffectList[i], false);
							mEffectList[i] = nullptr;
						}
					}
					if (itemMgr && itemMgr->getUfo()) {
						itemMgr->getUfo()->setJetEffect(0, false);
					}
					break;
				case 7:
					Vector3f pos7(64.0f, 44.0f, 1913.0f);
					effectMgr->create(EffectMgr::EFF_Rocket_WakeK1, pos7, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_WakeK2, pos7, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_WakeP1, pos7, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_WakeP2, pos7, nullptr, nullptr);
					break;
				case 8:
					Vector3f pos8(53.0f, 1164.0f, 848.0f);
					effectMgr->create(EffectMgr::EFF_MC_Bang, pos8, nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_MC_Debris, pos8, nullptr, nullptr);
					break;
				case 9:
					mMeteorFlag = 0;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (mEffectGrid[i][j]) {
								effectMgr->kill(mEffectGrid[i][j], false);
								mEffectGrid[i][j] = nullptr;
							}
						}
					}
					for (int i = 0; i < 7; i++) {
						if (mEffectList[i]) {
							effectMgr->kill(mEffectList[i], false);
							mEffectList[i] = nullptr;
						}
					}
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_7Meteor2, mCenterPosition, nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mCenterPosition);
					mEffectList[1] = effectMgr->create(EffectMgr::EFF_Rocket_7Meteor, mCenterPosition, nullptr, nullptr);
					mEffectList[1]->setEmitPosPtr(&mCenterPosition);
					mEffectList[2] = effectMgr->create(EffectMgr::EFF_Rocket_6Meteor, mCenterPosition, nullptr, nullptr);
					mEffectList[2]->setEmitPosPtr(&mCenterPosition);
					mEffectList[3] = effectMgr->create(EffectMgr::EFF_Rocket_5Meteor, mCenterPosition, nullptr, nullptr);
					mEffectList[3]->setEmitPosPtr(&mCenterPosition);
					mEffectList[4] = effectMgr->create(EffectMgr::EFF_Rocket_4Meteor, mCenterPosition, nullptr, nullptr);
					mEffectList[4]->setEmitPosPtr(&mCenterPosition);
					mEffectList[5] = effectMgr->create(EffectMgr::EFF_Rocket_3Meteor, mCenterPosition, nullptr, nullptr);
					mEffectList[5]->setEmitPosPtr(&mCenterPosition);
					mEffectList[6] = effectMgr->create(EffectMgr::EFF_Rocket_1Meteor, mCenterPosition, nullptr, nullptr);
					mEffectList[6]->setEmitPosPtr(&mCenterPosition);
					_19C = 1;
					break;
				case 10:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01, mJointPositions[0], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[0]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02, mJointPositions[0], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[0]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03, mJointPositions[0], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[0]);
					break;
				case 11:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01C, mJointPositions[1], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[1]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02C, mJointPositions[1], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[1]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01CC, mJointPositions[1], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[1]);
					break;
				case 12:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03C, mJointPositions[2], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[2]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02CC, mJointPositions[2], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[2]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03CC, mJointPositions[2], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[2]);
					break;
				case 13:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01C, mJointPositions[3], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[3]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02C, mJointPositions[3], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[3]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01CC, mJointPositions[3], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[3]);
					break;
				case 14:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03C, mJointPositions[4], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[4]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02CC, mJointPositions[4], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[4]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03CC, mJointPositions[4], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[4]);
					break;
				case 15:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03C, mJointPositions[5], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[5]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02CC, mJointPositions[5], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[5]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03CC, mJointPositions[5], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[5]);
					break;
				case 16:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01C, mJointPositions[6], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[6]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02C, mJointPositions[6], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[6]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT01CC, mJointPositions[6], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[6]);
					break;
				case 17:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03C, mJointPositions[7], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[7]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02CC, mJointPositions[7], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[7]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03CC, mJointPositions[7], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[7]);
					break;
				case 18:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03C, mJointPositions[8], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[8]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT02CC, mJointPositions[8], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[8]);
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_Rocket_SCT03CC, mJointPositions[8], nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mJointPositions[8]);
					break;
				case 19:
					mJointPositions[0].set(-25000.0f, -25000.0f, -25000.0f);
					mEffectList[1] = effectMgr->create(EffectMgr::EFF_Rocket_Bst1fb, mJointPositions[0], nullptr, nullptr);
					mEffectList[1]->setEmitPosPtr(&mJointPositions[0]);
					mEffectList[2] = effectMgr->create(EffectMgr::EFF_Rocket_Bst1fa, mJointPositions[0], nullptr, nullptr);
					mEffectList[2]->setEmitPosPtr(&mJointPositions[0]);
					mEffectList[2]->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
					mJointPositions[1].set(-25000.0f, -25000.0f, -25000.0f);
					mJointPositions[2].set(-25000.0f, -25000.0f, -25000.0f);
					mJointPositions[3].set(-25000.0f, -25000.0f, -25000.0f);
					mJointPositions[4].set(-25000.0f, -25000.0f, -25000.0f);
					for (int i = 0; i < 4; i++) {
						mEffectGrid[i][0] = effectMgr->create(EffectMgr::EFF_Rocket_NJ3FB2, mJointPositions[i + 1], nullptr, nullptr);
						mEffectGrid[i][0]->setEmitPosPtr(&mJointPositions[i + 1]);

						mEffectGrid[i][1] = effectMgr->create(EffectMgr::EFF_Rocket_NJ3FA, mJointPositions[i + 1], nullptr, nullptr);
						mEffectGrid[i][1]->setEmitPosPtr(&mJointPositions[i + 1]);
						mEffectGrid[i][1]->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
					}
					mMeteorFlag = 1;
					break;
				case 20:
					mEffectList[0] = effectMgr->create(EffectMgr::EFF_MTotl01, mCenterPosition, nullptr, nullptr);
					mEffectList[0]->setEmitPosPtr(&mCenterPosition);
					mEffectList[1] = effectMgr->create(EffectMgr::EFF_MTotl03, mCenterPosition, nullptr, nullptr);
					mEffectList[1]->setEmitPosPtr(&mCenterPosition);
					_19E = 1;
					break;
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:
				case 26:
				case 27:
				case 28:
					effectMgr->create(EffectMgr::EFF_Rocket_SCT00N, mJointPositions[id - 21], nullptr, nullptr);
					break;
				case 29:
					_108[0].set(-25000.0f, -25000.0f, -25000.0f);
					_108[1].set(-25000.0f, -25000.0f, -25000.0f);
					_108[2].set(-25000.0f, -25000.0f, -25000.0f);
					_108[3].set(-25000.0f, -25000.0f, -25000.0f);
					effectMgr->create(EffectMgr::EFF_Rocket_SSLight, _108[0], nullptr, nullptr)->setEmitPosPtr(&_108[0]);
					effectMgr->create(EffectMgr::EFF_Rocket_SSLight, _108[1], nullptr, nullptr)->setEmitPosPtr(&_108[1]);
					effectMgr->create(EffectMgr::EFF_Rocket_SSLight, _108[2], nullptr, nullptr)->setEmitPosPtr(&_108[2]);
					effectMgr->create(EffectMgr::EFF_Rocket_SSLight, _108[3], nullptr, nullptr)->setEmitPosPtr(&_108[3]);
					_19F = 1;
					break;
				case 30:
					effectMgr->create(EffectMgr::EFF_Rocket_Opa1, mCenterPosition, nullptr, nullptr);
					break;
				case 31:
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomC, mJointPositions[0], nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomW, mJointPositions[0], nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomH, mJointPositions[0], nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomP, mJointPositions[0], nullptr, nullptr);
					effectMgr->create(EffectMgr::EFF_Rocket_BeBomK, mJointPositions[0], nullptr, nullptr);
					break;
				}
			}
		}
	}

	STACK_PAD_VAR(4);
}

/**
 * --INFO--
 * Address:	80072234
 * Size:	000F10
 */
void ActorInstance::refresh(Matrix4f& mtx, Graphics& gfx, f32* p3)
{
	// feels like a typo.
	if ((mFlags & 0xf800) && !(gameflow.mMoviePlayer->mMaskFlags & (mFlags & 0xF800))) {
		return;
	}

	if (!mActiveActor) {
		return;
	}

	f32 a       = 0.0f;
	f32 b       = 0.0f;
	bool check1 = false;
	f32 c       = 0.0f;
	f32* d      = nullptr;
	if (mAnimator.mMgr) {
		a = mAnimator.mAnimationCounter;
		if (p3) {
			mAnimator.mAnimationCounter = *p3;
		} else {
			mAnimator.animate(30.0f);
		}
		mAnimator.updateContext();
		b      = mAnimator.mAnimationCounter;
		check1 = true;
		d      = &mAnimator.mAnimationCounter;
	} else if (p3 && mActiveActor->mModel->mCurrentAnimation->mData->mTotalFrameCount) {
		c = std::fmodf(*p3, f32(mActiveActor->mModel->mCurrentAnimation->mData->mTotalFrameCount));
		d = &c;
	}

	gfx.useMatrix(Matrix4f::ident, 0);
	bool check2 = true;

	if (mFlags & 0x440) {
		mActiveActor->mModel->backupAnimOverrides(bcs);
		if (!(mFlags & 0x400)) {
			check2 = false;
		}

		if (mAnimator.mMgr) {
			mActiveActor->mModel->overrideAnim(0, &mActiveActor->mContext);
		}

		AnimFrameCacher* prevCacher        = mActiveActor->mModel->mFrameCacher;
		mActiveActor->mModel->mFrameCacher = nullptr;
		mActiveActor->mModel->updateAnim(gfx, mtx, d);
		mActiveActor->mModel->mFrameCacher = prevCacher;

		mJointPositions[0].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[0]);
		mJointPositions[1].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[1]);

		if (check1) {
			Vector3f pos(0.0f, 0.0f, 0.0f);
			mActiveActor->mModel->calcJointWorldPos(gfx, 0, pos);
			checkEventKeys(a, b, pos);
		}

		Matrix4f animMtx = mActiveActor->mModel->getAnimMatrix(0);
		mActiveActor->mModel->restoreAnimOverrides();

		if (itemMgr && itemMgr->getUfo()) {
			if (mFlags & 0x400) {
				gfx.mRenderState = 0;
			}

			gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
			itemMgr->getUfo()->demoDraw(gfx, &animMtx);
			gfx.mRenderState = (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk3);
		}
	} else if (mFlags & 0x80) {
		check2 = false;
		mActiveActor->mModel->backupAnimOverrides(bcs);
		if (mAnimator.mMgr) {
			mActiveActor->mModel->overrideAnim(0, &mActiveActor->mContext);
		}

		AnimFrameCacher* prevCacher        = mActiveActor->mModel->mFrameCacher;
		mActiveActor->mModel->mFrameCacher = nullptr;
		mActiveActor->mModel->updateAnim(gfx, mtx, d);
		mActiveActor->mModel->mFrameCacher = prevCacher;
		if (mParentPlayer->mTarget) {
			mParentPlayer->mTarget->demoDraw(gfx, nullptr);
		}
		mActiveActor->mModel->restoreAnimOverrides();
	}

	if (!check2) {
		return;
	}

	mActiveActor->mModel->backupAnimOverrides(bcs);
	if (mAnimator.mMgr) {
		mActiveActor->mModel->overrideAnim(0, &mActiveActor->mContext);
	}

	int modelType = 0;
	if (strcmp(mActiveActor->mModel->mName, "pikis/bluModel.mod") == 0) {
		modelType = 1;
		mActiveActor->mModel->mMaterialList[0].setColour(Colour(0, 50, 255, 255));
		mDynMats.animate(nullptr);

	} else if (strcmp(mActiveActor->mModel->mName, "pikis/redModel.mod") == 0) {
		modelType = 1;
		mActiveActor->mModel->mMaterialList[0].setColour(Colour(255, 30, 0, 255));
		mDynMats.animate(nullptr);

	} else if (strcmp(mActiveActor->mModel->mName, "pikis/yelModel.mod") == 0) {
		modelType = 1;
		mActiveActor->mModel->mMaterialList[0].setColour(Colour(255, 210, 0, 255));
		mDynMats.animate(nullptr);

	} else if (strcmp(mActiveActor->mModel->mName, "objects/pikihead/navihead.mod") == 0) {
		modelType = 2;
		mDynMats.animate(nullptr);
	}

	if (modelType == 0) {
		if (mFlags & 0x40000) {
			mDynMats.animate(&mColourValue);
		} else {
			int v = (mFlags >> 1) & 0xF;
			if (v != 1) {
				if (v == 2) {
					mColourValue = 0.0f;
				} else if (v == 4) {
					mColourValue = 2.0f;
				} else if (v == 8) {
					mColourValue = 4.0f;
				}

				mDynMats.animate(&mColourValue);
			} else {
				mDynMats.animate(nullptr);
			}
		}
	}

	AnimFrameCacher* prevCacher        = mActiveActor->mModel->mFrameCacher;
	mActiveActor->mModel->mFrameCacher = nullptr;
	mActiveActor->mModel->updateAnim(gfx, mtx, d);
	mActiveActor->mModel->mFrameCacher = prevCacher;

	mCenterPosition.set(0.0f, 0.0f, 0.0f);
	mActiveActor->mModel->calcJointWorldPos(gfx, 0, mCenterPosition);

	_90.set(0.0f, 1.0f, 0.0f);
	mActiveActor->mModel->calcJointWorldDir(gfx, 0, _90);

	if (_19F) {
		_108[0].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 69, _108[0]);
		_108[1].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 68, _108[1]);
		_108[2].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 67, _108[2]);
		_108[3].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 66, _108[3]);
	}

	if (!mMeteorFlag) {
		for (int i = 0; i < 9; i++) {
			if (mEffectList[i]) {
				if (_19C) {
					mCenterPosition.set(0.0f, 134.0f, 0.0f);
					mActiveActor->mModel->calcJointWorldPos(gfx, 0, mCenterPosition);
					Vector3f dir(_90);
					mEffectList[i]->setEmitDir(dir);

					if (i >= 3) {
						Vector3f otherDir = -dir;
						mEffectList[i]->setAirField(otherDir * mEffectList[i]->getAirField().length(), true);
					}
				} else {
					mEffectList[i]->setEmitDir(_90);
				}
			}
		}

	} else {
		mJointPositions[0].set(0.0f, 7.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[0]);
		mJointPositions[1].set(-14.4f, 14.9f, 14.4f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[1]);
		mJointPositions[2].set(-14.4f, 14.9f, -14.4f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[2]);
		mJointPositions[3].set(14.4f, 14.9f, 14.4f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[3]);
		mJointPositions[4].set(14.4f, 14.9f, -14.4f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, mJointPositions[4]);

		for (int i = 0; i < 7; i++) {
			if (mEffectList[i]) {
				mEffectList[i]->setEmitDir(-_90);
			}
		}
	}

	if (mFlags & 0x200) {
		mJointPositions[0].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 3, mJointPositions[0]);
		mJointPositions[1].set(0.0f, -28.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 1, mJointPositions[1]);
	}

	if (mFlags & 0x10000) {
		mJointPositions[0].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 9, mJointPositions[0]);
		mJointPositions[1].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 8, mJointPositions[1]);
		mJointPositions[2].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 7, mJointPositions[2]);
		mJointPositions[3].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 6, mJointPositions[3]);
		mJointPositions[4].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 5, mJointPositions[4]);
		mJointPositions[5].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 4, mJointPositions[5]);
		mJointPositions[6].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 3, mJointPositions[6]);
		mJointPositions[7].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 2, mJointPositions[7]);
		mJointPositions[8].set(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 1, mJointPositions[8]);
	}

	if (check1) {
		Vector3f pos(0.0f, 0.0f, 0.0f);
		mActiveActor->mModel->calcJointWorldPos(gfx, 0, pos);
		checkEventKeys(a, b, pos);
	}

	if (mFlags & 0x21) {
		if (naviMgr && naviMgr->getNavi()) {
			Vector3f pos(0.0f, 0.0f, 0.0f);
			pos.multMatrix(mActiveActor->mModel->getAnimMatrix(0));
			pos.multMatrix(gfx.mCamera->mInverseLookAtMtx);
			naviMgr->getNavi()->updateDayEnd(pos);
			naviMgr->getNavi()->demoDraw(gfx, nullptr);
		}
	} else {
		u32 flags = mActiveActor->mModel->mSystemFlags;
		if (mFlags & 0x20000) {
			mActiveActor->mModel->mSystemFlags |= ShapeFlags::AlwaysRedraw;
		}
		mActiveActor->mModel->drawshape(gfx, *gfx.mCamera, &mDynMats);
		mActiveActor->mModel->mSystemFlags = flags;
	}

	if (modelType == 1) {
		gfx.useMatrix(mActiveActor->mModel->getAnimMatrix(6), 0);
		mLeafModel->drawshape(gfx, *gfx.mCamera, nullptr);
	} else if (modelType == 2) {
		gfx.useMatrix(mActiveActor->mModel->getAnimMatrix(3), 0);
		mLeafModel->drawshape(gfx, *gfx.mCamera, nullptr);
	}

	mActiveActor->mModel->restoreAnimOverrides();
}
