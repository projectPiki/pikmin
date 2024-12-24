#ifndef _CINEMATICPLAYER_H
#define _CINEMATICPLAYER_H

#include "types.h"
#include "CoreNode.h"
#include "Animator.h"
#include "Camera.h"
#include "Light.h"

struct CmdStream;
struct Graphics;
struct Matrix4f;
struct Vector3f;

/**
 * @brief TODO
 */
struct SceneData : public CoreNode {
	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	DataChunk* mCameraAnimations; // _14
	DataChunk* mLightAnimations;  // _18
	CamDataInfo* mCameraData;     // _1C
	LightDataInfo* mLightData;    // _20
	u32 mNumFrames;               // _24
	u32 mNumCameras;              // _28
	u32 mNumLights;               // _2C
};

/**
 * @brief TODO
 */
struct SceneCut : public CoreNode {
	void addInstance(char*);

	// unused/inlined:
	void countEKeys();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct ActorInstance : public CoreNode {
	ActorInstance();

	void exitInstance();
	void initInstance();
	void checkEventKeys(f32, f32, Vector3f&);
	void refresh(Matrix4f&, Graphics&, f32*);

	// unused/inlined:
	void onceInit();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct CineShapeObject : public CoreNode {

	// unused/inlined:
	void init(char*, char*, char*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct CinematicPlayer {
	CinematicPlayer(char*);

	void init(char*);
	void loadCin(char*);
	void addScene(SceneData*);
	void addCut(int, int, int);
	void addActor(CineShapeObject*);
	void addActor(char*, char*, char*);
	void addSceneCut();
	void skipScene(int);
	void update();
	void addLights(Graphics&);
	void refresh(Graphics&);

	// unused/inlined:
	void addScene(char*);

	// TODO: members
};

#endif
