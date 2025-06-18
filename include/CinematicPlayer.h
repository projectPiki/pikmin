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
 * @brief Enum for cinematic player flags.
 */
enum CinematicPlayerFlags {
	CINFLAG_Unk0               = 1 << 0,  ///< 0x1, weird mix of use cases - fixed target camera?
	CINFLAG_Unk1               = 1 << 1,  ///< 0x2, only used by day end cave/yakushima/last?
	CINFLAG_Unk2               = 1 << 2,  ///< 0x4, weird mix of use cases, used by half?
	CINFLAG_Unk3               = 1 << 3,  ///< 0x8, 3-5 only used by meet pikmin cutscenes (incl. bombs)
	CINFLAG_Unk4               = 1 << 4,  ///< 0x10,
	CINFLAG_Unk5               = 1 << 5,  ///< 0x20,
	CINFLAG_Unk6               = 1 << 6,  ///< 0x40, weird mix of use cases, but used by most
	CINFLAG_UseLights          = 1 << 7,  ///< 0x80, use scene light data from file - mainly for space/atmosphere cutscenes.
	CINFLAG_TakeOff            = 1 << 8,  ///< 0x100, use special takeoff cutscene logic when deciding when to play.
	CINFLAG_FadeIn             = 1 << 9,  ///< 0x200, fade in from black - only used by landing in area cutscenes.
	CINFLAG_Unk10              = 1 << 10, ///< 0x400, used by onyon cutscenes?
	CINFLAG_Unk11              = 1 << 11, ///< 0x800, 11-16 are usually used together (day end don't use 11 or 12)
	CINFLAG_Unk12              = 1 << 12, ///< 0x1000,
	CINFLAG_Unk13              = 1 << 13, ///< 0x2000,
	CINFLAG_Unk14              = 1 << 14, ///< 0x4000,
	CINFLAG_Unk15              = 1 << 15, ///< 0x8000,
	CINFLAG_Unk16              = 1 << 16, ///< 0x10000,
	CINFLAG_UseStaticCamera    = 1 << 17, ///< 0x20000, only used by Demo12.
	CINFLAG_Unk18              = 1 << 18, ///< 0x40000, used by discover main engine + discover onyons?
	CINFLAG_Unk19              = 1 << 19, ///< 0x80000, only used by Demo12?
	CINFLAG_Unk20              = 1 << 20, ///< 0x100000, only used by olimin cutscene?
	CINFLAG_Unk21              = 1 << 21, ///< 0x200000, used by parts and upgrades cutscenes?
	CINFLAG_DoCameraTransition = 1 << 22, ///< 0x400000, never used by a demo.
};

/**
 * @brief Enum for cutscene skipping flags.
 */
enum SceneSkipFlags {
	SCENESKIP_NULL    = 0, ///< 0, no skipping indicated.
	SCENESKIP_Invalid = 1, ///< 1, invalid cutscene ID.
	SCENESKIP_Skip    = 2, ///< 2, skip scene.
	SCENESKIP_SkipAll = 3, ///< 3, skip all.
};

/**
 * @brief Enum for scene control flags.
 */
enum SceneFlags {
	SCENEFLAG_Unk1 = 0x1, ///< 0x1, unknown/unused.
	SCENEFLAG_2    = 0x2, ///< 0x2, base for playback mode selection.
	SCENEFLAG_4    = 0x4, ///< 0x4, base for playback mode selection.
	SCENEFLAG_8    = 0x8, ///< 0x8, base for playback mode selection.

	// based on how the code works, combos of the above flags will give different modes (up to 7) - only ModeLoop is actually used.
	SCENEFLAG_ModeNormal = SCENEFLAG_2,
	SCENEFLAG_ModeLoop   = SCENEFLAG_4,
};

/**
 * @brief Enum for scene control flags.
 */
enum CinPlayBackMode {
	CINMODE_Play      = 0x1, ///< 0x1, play normally.
	CINMODE_LoopScene = 0x2, ///< 0x2, loop current scene.
};

/**
 * @brief Object for storing scene data.
 *
 * Loads/stores overall information for a given SceneCut.
 *
 * @note Size: 0x30.
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

#ifdef DEVELOP
	virtual void genAge(AgeServer&);
#endif

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
 * @brief Managing object for a given scene actor.
 *
 * Tracks information about a given scene actor as it animates in a scene.
 *
 * @note Size: 0x1A0.
 */
struct ActorInstance : public CoreNode {
	ActorInstance()
	    : CoreNode("")
	{
		mActiveActor     = 0;
		mDefaultActor    = 0;
		_64              = 0;
		mAnimator.mMgr   = 0;
		_19E             = 0;
		mMeteorFlag      = 0;
		_19F             = 0;
		_19C             = 0;
		_6C              = 0;
		mAnimPlayState   = 1;
		mColourAnimIndex = -1;
		mColourValue     = 0.0f;
		mFlags           = 2;
		mIsLeaf          = 0;
	}

	void exitInstance();
	void initInstance();
	void checkEventKeys(f32, f32, Vector3f&);
	void refresh(Matrix4f&, Graphics&, f32*);

	// unused/inlined:
	void onceInit();

#ifdef DEVELOP
	virtual void genAge(AgeServer&);
#endif

	void ageChangeAttach(AgeServer&);
	void ageChangeObject(AgeServer&);
	void ageDelInstance(AgeServer&);
	void genSection(AgeServer&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	Animator mAnimator;                        ///< _14
	ShapeDynMaterials mDynMats;                ///< _48
	Shape* mLeafModel;                         ///< _58
	CineShapeObject* mActiveActor;             ///< _5C, animating actor information.
	CineShapeObject* mDefaultActor;            ///< _60, default actor information.
	CineShapeObject* _64;                      ///< _64
	u32 mFlags;                                ///< _68
	int _6C;                                   ///< _6C
	int mAnimPlayState;                        ///< _70
	int mColourAnimIndex;                      ///< _74
	int mIsLeaf;                               ///< _78
	CinematicPlayer* mParentPlayer;            ///< _7C
	f32 mColourValue;                          ///< _80
	Vector3f mCenterPosition;                  ///< _84
	Vector3f _90;                              ///< _90
	Vector3f mJointPositions[9];               ///< _9C
	Vector3f _108[4];                          ///< _108
	zen::particleGenerator* mEffectList[9];    ///< _138
	zen::particleGenerator* mEffectGrid[4][4]; ///< _15C
	u8 _19C;                                   ///< _19C
	u8 mMeteorFlag;                            ///< _19D
	u8 _19E;                                   ///< _19E
	u8 _19F;                                   ///< _19F
};

/**
 * @brief Scene object.
 *
 * Active object for a given scene section, pulling in data from SceneData.
 *
 * @note Size: 0x1DC.
 */
struct SceneCut : public CoreNode {

	/// Default constructor.
	SceneCut()
	    : CoreNode("")
	{
		mStartFrame = 0;
		mEndFrame   = 0;
		mActorList.initCore("");
		mFlags     = SCENEFLAG_Unk1 | SCENEFLAG_ModeNormal;
		mSceneID   = 0;
		mSceneData = nullptr;
		mKey.mPrev = mKey.mNext = &mKey;
	}

	ActorInstance* addInstance(char*);

#ifdef DEVELOP
	virtual void genAge(AgeServer&);
#endif

	void ageAddEffectKey(AgeServer&);
	void ageAddInstance(AgeServer&);
	void ageChangeScene(AgeServer&);
	void ageDeleteCut(AgeServer&);
	void ageRefresh(AgeServer&);
	void genCutSection(AgeServer&);

	// unused/inlined:
	int countEKeys();

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFlags;                     ///< _14, scene flags - see SceneFlags enum.
	int mStartFrame;                ///< _18, scene start frame.
	int mEndFrame;                  ///< _1C, scene end frame.
	int mSceneID;                   ///< _20, ID for the scene to be cut to.
	SceneData* mSceneData;          ///< _24, data for the scene to be cut to.
	ActorInstance mActorList;       ///< _28, list of actors in scene.
	AnimKey mKey;                   ///< _1C8
	CinematicPlayer* mParentPlayer; ///< _1D8
};

/**
 * @brief Actor object for use in cutscenes.
 *
 * Stores basic model and animation information for a given cutscene actor.
 *
 * @note Size: 0x34.
 */
struct CineShapeObject : public CoreNode {

	/// Default constructor.
	CineShapeObject()
	    : CoreNode("")
	{
		mMgr          = nullptr;
		mAnimFilePath = mBundleFilePath = nullptr;
	}

	/// STRIPPED - initialises model and animation manager.
	void init(char* modelPath, char* animPath, char* bundlePath);

#ifdef DEVELOP
	virtual void genAge(AgeServer&);
#endif

	// _00     = VTBL
	// _00-_14 = CoreNode
	Shape* mModel;         ///< _14, parent model.
	char* mAnimFilePath;   ///< _18, path to animations file.
	char* mBundleFilePath; ///< _1C, path to bundle file.
	AnimContext mContext;  ///< _20, context for animations.
	AnimMgr* mMgr;         ///< _30, animation manager.
};

/**
 * @brief Cutscene manager.
 *
 * Manages current cutscenes including actors, cameras, and scenes.
 *
 * @note Size: 0x2E8.
 */
struct CinematicPlayer {

	/// Constructor - initialises given cutscene file.
	CinematicPlayer(char* cinFilePath);

	/// Initialises player, loads given cutscene file, and initialises current scene.
	void init(char* cinFilePath);

	/// Loads cutscene from given file path, including unpacking all command information.
	void loadCin(char* cinFilePath);

	/// Reads in scene data from file and sets as current scene.
	void addScene(SceneData* scene);

	/// Creates new scene cut with given scene ID, adds to cut list, and adds corresponding scene data.
	SceneCut* addCut(int sceneID, int startFrame, int endFrame);

	/// Initialises given actor using the actor's stored information.
	void addActor(CineShapeObject* actor);

	/// Sets up a new actor with given file paths, adds to actor list, and initialises.
	void addActor(char* modelFilePath, char* animFilePath, char* bundleFilePath);

	/// Creates new scene cut with first data from scene list, and adds to scene cut list.
	SceneCut* addSceneCut();

	/// Updates playback time to end of current scene, and updates scene skipping flag (see SceneSkipFlag enum).
	void skipScene(int sceneSkipFlag);

	/// Updates and transitions scenes, handles actor spawning/despawning, and triggers events - returns TRUE if playback is finished.
	BOOL update();

	/// Adds any active lights to the graphics manager to track and draw.
	void addLights(Graphics& gfx);

	/// Refreshes graphics of all actors in active scene using custom world matrix.
	void refresh(Graphics& gfx);

	/// STRIPPED - sets up new scene with given .dsk file path, reads in data, and sets as current scene.
	SceneData* addScene(char* dskFilePath);

	// DLL exclusive functions (use -DEVELOP)
	void genAge(AgeServer&);
	void ageAddActor(AgeServer&);
	void ageAddCut(AgeServer&);
	void ageAddScene(AgeServer&);
	void ageLoad(AgeServer&);
	void ageNew(AgeServer&);
	void agePlayAnim(AgeServer&);
	void ageRefreshSection(AgeServer&);
	void ageSave(AgeServer&);
	void genSection(AgeServer&);
	void saveCin(char*);
	static void truncateName(char*);

	/// Retrieves actor information from overall actor list based on .mod file path.
	CineShapeObject* findActor(char* modFilePath)
	{
		for (CineShapeObject* actor = (CineShapeObject*)mActorList.mChild; actor; actor = (CineShapeObject*)actor->mNext) {
			if (!strcmp(actor->mName, modFilePath)) {
				return actor;
			}
		}
		return nullptr;
	}

	/// Retrieves scene data based on data list index.
	SceneData* findScene(int sceneID)
	{
		int i = 0;
		for (SceneData* scene = (SceneData*)mDataList.mChild; scene; scene = (SceneData*)scene->mNext) {
			if (i == sceneID) {
				return scene;
			}
			i++;
		}
		return nullptr;
	}

	void calcMaxFrames()
	{
		mTotalDuration = 0;
		for (SceneCut* shape = (SceneCut*)mSceneList.mChild; shape; shape = (SceneCut*)shape->mNext) {
			mTotalDuration += abs(shape->mEndFrame - shape->mStartFrame);
		}

		if (mCurrentPlaybackTime >= (f32)mTotalDuration) {
			mCurrentPlaybackTime = (f32)mTotalDuration - 1.0f;
		}
	}

	u32 mFlags;                 ///< _00, flags for cutscene options - see CinematicPlayerFlags enum.
	u32 mType;                  ///< _04, unused "type" information.
	Matrix4f mWorldMtx;         ///< _08, world matrix to be used for camera transformations.
	Creature* mTarget;          ///< _48, target object of cutscene.
	SceneData mDataList;        ///< _4C, list of all loaded scene data.
	SceneData* mCurrentData;    ///< _7C, data corresponding to current scene.
	CineShapeObject mActorList; ///< _80, list of all loaded actors.
	SceneCut mSceneList;        ///< _B4, list of all loaded scenes.
	SceneCut* mCurrentScene;    ///< _290, currently playing scene.
	SceneCut* mPreviousScene;   ///< _294, scene playing in previous frame.
	int mPlaybackMode;          ///< _298
	f32 mCurrentSceneStartTime; ///< _29C, time current scene started, relative to cutscene start.
	f32 mPlaybackSpeed;         ///< _2A0
	f32 mCurrentPlaybackTime;   ///< _2A4, overall cutscene timer.
	f32 mCurrentSceneFrame;     ///< _2A8, frame counter for active scene.
	f32 mPreviousSceneFrame;    ///< _2AC, frame counter value on previous frame.
	int mTotalDuration;         ///< _2B0, total length of all scenes (in frames).
	int mSceneSkipFlag;         ///< _2B4, flag for skipping cutscene - see SceneSkipFlag enum.
	Vector3f mCameraPosition;   ///< _2B8
	Vector3f mCameraLookAt;     ///< _2CC
	Vector3f mStaticLookAt;     ///< _2D0
	f32 mCameraTargetFov;       ///< _2DC
	f32 mCameraBlendRatio;      ///< _2E0
	bool mUseStaticCamera;      ///< _2E4
	bool mIsPlaying;            ///< _2E5
};

#endif
