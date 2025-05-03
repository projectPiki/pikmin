#ifndef _CINEMATICPLAYER_H
#define _CINEMATICPLAYER_H

#include "types.h"
#include "CoreNode.h"
#include "Animator.h"
#include "Camera.h"
#include "Light.h"
#include "Dolphin/arith.h"
#include "stl/string.h"
#include "EffectMgr.h"
#include "Shape.h"

struct AgeServer;
struct CmdStream;
struct Graphics;
struct Matrix4f;
struct Vector3f;
struct CinematicPlayer;
struct CineShapeObject;
struct ActorInstance;

/**
 * @brief TODO
 */
struct SceneData : public CoreNode {
	SceneData()
	    : CoreNode("")
	{
		mNumFrames  = 0;
		mNumCameras = 0;
		mNumLights  = 0;
	}

	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	DataChunk* mCameraAnimations; // _14
	DataChunk* mLightAnimations;  // _18
	CamDataInfo* mCameraData;     // _1C
	LightDataInfo* mLightData;    // _20
	u32 mNumFrames;               // _24
	int mNumCameras;              // _28
	int mNumLights;               // _2C
};

/**
 * @brief TODO
 */
struct ActorInstance : public CoreNode {
	ActorInstance()
	    : CoreNode("")
	{
		mAnimInstance  = 0;
		mModelInstance = 0;
		_64            = 0;
		mAnim.mMgr     = 0;
		_19E           = 0;
		mMeteorFlag    = 0;
		_19F           = 0;
		_19C           = 0;
		_6C            = 0;
		mAnimationId   = 1;
		mColourIndex   = -1;
		mColourValue   = 0.0f;
		mFlags         = 2;
		mIsLeaf        = 0;
	}

	void exitInstance();
	void initInstance();
	void checkEventKeys(f32, f32, Vector3f&);
	void refresh(Matrix4f&, Graphics&, f32*);

	// unused/inlined:
	void onceInit();

	// _00     = VTBL
	// _00-_14 = CoreNode
	Animator mAnim;                            // _14
	ShapeDynMaterials mDynMat;                 // _48
	Shape* mLeafModel;                         // _58
	CineShapeObject* mAnimInstance;            // _5C
	CineShapeObject* mModelInstance;           // _60
	int _64;                                   // _64
	int mFlags;                                // _68
	int _6C;                                   // _6C
	int mAnimationId;                          // _70
	int mColourIndex;                          // _74
	int mIsLeaf;                               // _78
	CinematicPlayer* mParentPlayer;            // _7C
	f32 mColourValue;                          // _80
	Vector3f mCenterPosition;                  // _84
	Vector3f _90;                              // _90
	Vector3f mJointPositions[9];               // _9C
	Vector3f _108[4];                          // _108
	zen::particleGenerator* mEffectList[9];    // _138
	zen::particleGenerator* mEffectGrid[4][4]; // _15C
	u8 _19C;                                   // _19C
	u8 mMeteorFlag;                            // _19D
	u8 _19E;                                   // _19E
	u8 _19F;                                   // _19F
};

/**
 * @brief TODO
 */
struct SceneCut : public CoreNode {
	SceneCut()
	    : CoreNode("")
	{
		mStartFrame = 0;
		mEndFrame   = 0;
		mActor.initCore("");
		mFlags     = 0x1 | 0x2;
		mSceneId   = 0;
		mSceneData = nullptr;
		mKey.mPrev = mKey.mNext = &mKey;
	}

	ActorInstance* addInstance(char*);

	// unused/inlined:
	int countEKeys();

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFlags;                     // _14
	int mStartFrame;                // _18
	int mEndFrame;                  // _1C
	int mSceneId;                   // _20
	SceneData* mSceneData;          // _24
	ActorInstance mActor;           // _28
	AnimKey mKey;                   // _1C8
	CinematicPlayer* mParentPlayer; // _1D8
};

/**
 * @brief TODO
 */
struct CineShapeObject : public CoreNode {
	CineShapeObject()
	    : CoreNode("")
	{
		mMgr          = nullptr;
		mAnimFileName = mBundleFileName = nullptr;
	}

	// unused/inlined:
	void init(char*, char*, char*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	Shape* mShape;         // _14
	char* mAnimFileName;   // _18
	char* mBundleFileName; // _1C
	AnimContext mContext;  // _20
	AnimMgr* mMgr;         // _30
};

struct CinematicPlayer {
	CinematicPlayer(char*);

	void init(char*);
	void loadCin(char*);
	void addScene(SceneData*);
	SceneCut* addCut(int, int, int);
	void addActor(CineShapeObject*);
	void addActor(char*, char*, char*);
	SceneCut* addSceneCut();
	void skipScene(int);
	int update();
	void addLights(Graphics&);
	void refresh(Graphics&);

	// unused/inlined:
	SceneData* addScene(char*);

	// DLL inlines
	CineShapeObject* findActor(char* name)
	{
		for (CineShapeObject* actor = (CineShapeObject*)mActorList.mChild; actor; actor = (CineShapeObject*)actor->mNext) {
			if (!strcmp(actor->mName, name)) {
				return actor;
			}
		}
		return nullptr;
	}

	SceneData* findScene(int id)
	{
		int i = 0;
		for (SceneData* scene = (SceneData*)mSceneList.mChild; scene; scene = (SceneData*)scene->mNext) {
			if (i == id) {
				return scene;
			}
			i++;
		}
		return nullptr;
	}
	void ageAddActor(AgeServer&);
	void ageAddCut(AgeServer&);
	void ageAddScene(AgeServer&);
	void ageLoad(AgeServer&);
	void ageNew(AgeServer&);
	void agePlayAnim(AgeServer&);
	void ageRefreshSection(AgeServer&);
	void ageSave(AgeServer&);
	void calcMaxFrames()
	{
		mTotalSceneDuration = 0;
		for (CineShapeObject* shape = (CineShapeObject*)mCutList.mChild; shape; shape = (CineShapeObject*)shape->mNext) {
			mTotalSceneDuration += abs(shape->mBundleFileName - shape->mAnimFileName);
		}

		if (mCurrentPlaybackTime >= (f32)mTotalSceneDuration) {
			mCurrentPlaybackTime = (f32)mTotalSceneDuration - 1.0f;
		}
	}
	void genAge(AgeServer&);
	void genSection(AgeServer&);
	void saveCin(char*);
	void truncateName(char*);

	u32 mFlags;                 // _00
	int mType;                  // _04
	Matrix4f mMtx;              // _08
	Creature* mTarget;          // _48
	SceneData mSceneList;       // _4C
	SceneData* mCurrentScene;   // _7C
	CineShapeObject mActorList; // _80
	SceneCut mCutList;          // _B4
	SceneCut* mCurrentCut;      // _290
	SceneCut* mPreviousCut;     // _294
	int mPlaybackMode;          // _298
	f32 mCurrentCutStartTime;   // _29C
	f32 mPlaybackSpeed;         // _2A0
	f32 mCurrentPlaybackTime;   // _2A4
	f32 mCurrentFramePosition;  // _2A8
	f32 mPreviousFramePosition; // _2AC
	int mTotalSceneDuration;    // _2B0
	int mCutTransitionFlag;     // _2B4
	Vector3f mCameraPosition;   // _2B8
	Vector3f mCameraLookAt;     // _2CC
	Vector3f _2D0;              // _2D0
	f32 mCameraTargetFov;       // _2DC
	f32 mCameraBlendRatio;      // _2E0
	bool _2E4;                  // _2E4
	bool mIsPlaying;            // _2E5
};

#endif
