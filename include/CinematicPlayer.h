#ifndef _CINEMATICPLAYER_H
#define _CINEMATICPLAYER_H

#include "Animator.h"
#include "Camera.h"
#include "CoreNode.h"
#include "EffectMgr.h"
#include "Light.h"
#include "Shape.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>

#define ADD_ACTOR_PIKMIN_TYPE(flags, color) (flags) |= 1 << ((color) + 12)

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
BEGIN_ENUM_TYPE(CinePlayerFlags)
enum {
	Localized      = 1 << 0,  // 0x1
	Unknown        = 1 << 1,  // 0x2
	HideNavi       = 1 << 2,  // 0x4
	HideBluePiki   = 1 << 3,  // 0x8
	HideRedPiki    = 1 << 4,  // 0x10
	HideYellowPiki = 1 << 5,  // 0x20
	NaviNoAI       = 1 << 6,  // 0x40
	UseLights      = 1 << 7,  // 0x80, originally called "NonGameMovie"
	Concurrent     = 1 << 8,  // 0x100, use special takeoff cutscene logic
	CameraBlend    = 1 << 9,  // 0x200, fade in from black when starting a scene
	ShowTekis      = 1 << 10, // 0x400
	ShowFreePiki   = 1 << 11, // 0x800
	UpdateFreePiki = 1 << 12, // 0x1000
	ShowFormPiki   = 1 << 13, // 0x2000
	UpdateFormPiki = 1 << 14, // 0x4000
	ShowWorkPiki   = 1 << 15, // 0x8000
	UpdateWorkPiki = 1 << 16, // 0x10000
	ObjWatching    = 1 << 17, // 0x20000, static camera
	ShowPellets    = 1 << 18, // 0x40000
	PauseAll       = 1 << 19, // 0x80000
	HideRedCont    = 1 << 20, // 0x100000
	PikiNearUfo    = 1 << 21, // 0x200000
	CameraReturn   = 1 << 22, // 0x400000

	UseNaviView = 1 << 31, // 0x80000000

} END_ENUM_TYPE;

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

#ifdef WIN32
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
 * @brief Enum for actor's flags during a cutscene.
 */
enum CineActorFlags {
	CAF_MoveAiNavi     = 1 << 0,  ///< 0x1, used during player movement cutscenes
	CAF_ColourAnims    = 1 << 1,  ///< 0x2, never used (unknown)
	CAF_FixedBlu       = 1 << 2,  ///< 0x4, force blue Pikmin colour
	CAF_FixedRed       = 1 << 3,  ///< 0x8, force red Pikmin colour
	CAF_FixedYel       = 1 << 4,  ///< 0x10, force yellow Pikmin colour
	CAF_MoveDayEndNavi = 1 << 5,  ///< 0x20, used for player movement during sunset sequence
	CAF_MoveAiUfo      = 1 << 6,  ///< 0x40, used with ship cutscenes
	CAF_MoveAiPiki     = 1 << 7,  ///< 0x80, used with Pikmin cutscenes
	CAF_NoSync         = 1 << 8,  ///< 0x100, animation runs independently of the scene
	CAF_MoveAiOnion    = 1 << 9,  ///< 0x200, used by onion cutscenes
	CAF_DummyUfo       = 1 << 10, ///< 0x400
	CAF_ObjMask1       = 1 << 11, ///< 0x800, visibility group 1
	CAF_ObjMask2       = 1 << 12, ///< 0x1000, visibility group 2
	CAF_ObjMask3       = 1 << 13, ///< 0x2000, visibility group 3
	CAF_ObjMask4       = 1 << 14, ///< 0x4000, visibility group 4
	CAF_ObjMask5       = 1 << 15, ///< 0x8000, visibility group 5
	CAF_MoveFaller     = 1 << 16, ///< 0x10000, object falls with gravity
	CAF_NoXluSort      = 1 << 17, ///< 0x20000, skip transparency sorting
	CAF_MultiColour    = 1 << 18, ///< 0x40000, for cycling through colour variants

	CAF_AllObjMasks = CAF_ObjMask1 | CAF_ObjMask2 | CAF_ObjMask3 | CAF_ObjMask4 | CAF_ObjMask5, ///< 0xF800

	// Object masks for day end cutscenes
	CAF_DayEndRedPikmin    = CAF_ObjMask2, ///< 0x1000
	CAF_DayEndYellowPikmin = CAF_ObjMask3, ///< 0x2000
	CAF_DayEndBluePikmin   = CAF_ObjMask4, ///< 0x4000

	CAF_DayEndEnemyAttack   = CAF_ObjMask1, ///< 0x800
	CAF_DayEndEnemyNoDeaths = CAF_ObjMask5, ///< 0x8000

	// object masks for bad ending cutscenes
	CAF_BadEndingRedPikmin    = CAF_ObjMask2, ///< 0x1000
	CAF_BadEndingYellowPikmin = CAF_ObjMask3, ///< 0x2000
	CAF_BadEndingBluePikmin   = CAF_ObjMask4, ///< 0x4000

	CAF_BadEndingExtraRed1 = CAF_ObjMask1, ///< 0x800
	CAF_BadEndingExtraRed2 = CAF_ObjMask5, ///< 0x8000

	// default visibility, no groupings
	CAF_AllVisibleMask = 0xFFFFFFFF, ///< 0xFFFFFFFF
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
		mActiveActor         = 0;
		mDefaultActor        = 0;
		mParentFirstChild    = 0;
		mAnimator.mMgr       = 0;
		_19E                 = false;
		mMeteorFlag          = false;
		mUsingRocketLightPos = false;
		_19C                 = false;
		_6C                  = 0;
		mAnimPlayState       = 1;
		mColourAnimIndex     = -1;
		mColourValue         = 0.0f;
		mFlags               = CAF_ColourAnims;
		mIsLeaf              = FALSE;
	}

	void exitInstance();
	void initInstance();
	void checkEventKeys(f32, f32, Vector3f&);
	void refresh(immut Matrix4f&, Graphics&, f32*);

	// unused/inlined:
	void onceInit();

#ifdef WIN32
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
	CineShapeObject* mParentFirstChild;        ///< _64
	u32 mFlags;                                ///< _68, uses the CAF_* flags enum.
	int _6C;                                   ///< _6C
	int mAnimPlayState;                        ///< _70
	int mColourAnimIndex;                      ///< _74
	BOOL mIsLeaf;                              ///< _78
	CinematicPlayer* mParentPlayer;            ///< _7C
	f32 mColourValue;                          ///< _80
	Vector3f mCenterPosition;                  ///< _84
	Vector3f mActorWorldDir;                   ///< _90
	Vector3f mJointPositions[9];               ///< _9C
	Vector3f mRocketLightPosList[4];           ///< _108
	zen::particleGenerator* mEffectList[9];    ///< _138
	zen::particleGenerator* mEffectGrid[4][4]; ///< _15C
	bool _19C;                                 ///< _19C
	bool mMeteorFlag;                          ///< _19D
	bool _19E;                                 ///< _19E
	bool mUsingRocketLightPos;                 ///< _19F
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

	ActorInstance* addInstance(immut char*);

#ifdef WIN32
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
	void init(immut char* modelPath, immut char* animPath, immut char* bundlePath);

#ifdef WIN32
	virtual void genAge(AgeServer&);
#endif

	// _00     = VTBL
	// _00-_14 = CoreNode
	Shape* mModel;               ///< _14, parent model.
	immut char* mAnimFilePath;   ///< _18, path to animations file.
	immut char* mBundleFilePath; ///< _1C, path to bundle file.
	AnimContext mContext;        ///< _20, context for animations.
	AnimMgr* mMgr;               ///< _30, animation manager.
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
	CinematicPlayer(immut char* cinFilePath);

	/// Initialises player, loads given cutscene file, and initialises current scene.
	void init(immut char* cinFilePath);

	/// Loads cutscene from given file path, including unpacking all command information.
	void loadCin(immut char* cinFilePath);

	/// Reads in scene data from file and sets as current scene.
	void addScene(SceneData* scene);

	/// Creates new scene cut with given scene ID, adds to cut list, and adds corresponding scene data.
	SceneCut* addCut(int sceneID, int startFrame, int endFrame);

	/// Initialises given actor using the actor's stored information.
	void addActor(CineShapeObject* actor);

	/// Sets up a new actor with given file paths, adds to actor list, and initialises.
	void addActor(immut char* modelFilePath, immut char* animFilePath, immut char* bundleFilePath);

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
	SceneData* addScene(immut char* dskFilePath);

#if defined(WIN32)
	// DLL exclusive functions (use -DWIN32)
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
	void saveCin(immut char*);
	static void truncateName(char*);
#endif

	/// Retrieves actor information from overall actor list based on .mod file path.
	CineShapeObject* findActor(immut char* modFilePath)
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
