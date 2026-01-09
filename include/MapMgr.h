#ifndef _MAPMGR_H
#define _MAPMGR_H

#include "Graphics.h"
#include "Material.h"
#include "ShadowCaster.h"
#include "Shape.h"
#include "types.h"

struct Controller;
struct CreatureCollPart;
struct DayMgr;
struct DynSimulator;
struct MapLightMgr;

/// How many cells to divide the map into, both horizontally and vertically (4096 total).
#define MAP_GRID_SIZE (64)

/// Types of "shape" objects stored in MapMgr, "used" in genMapParts.cpp. Never properly instantiated.
enum MapShapeTypes {
	MAPSHAPE_Box = 0, ///< 0, never instantiated, just taken from name array in genMapParts.cpp.
	MAPSHAPE_1   = 1, ///< 1, never instantiated, just taken from name array in genMapParts.cpp.
	MAPSHAPE_2   = 2, ///< 2, never instantiated, just taken from name array in genMapParts.cpp.
	MAPSHAPE_3   = 3, ///< 3, never instantiated, just taken from name array in genMapParts.cpp.
	MAPSHAPE_Log = 4, ///< 4, never instantiated, just taken from name array in genMapParts.cpp.
	MAPSHAPE_Count,   ///< 5, total number of shape types.
};

/**
 * @brief Holds information for simulating object movement for the next step, to resolve collisions and physics.
 *
 * Setting to ignore dynamic collision is only ever true for sprouts.
 *
 * @note Size: 0x28.
 */
struct MoveTrace {

	/**
	 * @brief Constructs a new trace with key physical information, but no parent object.
	 * @param position Current position of the object to be traced.
	 * @param velocity Current velocity of the object to be traced.
	 * @param radius Radius of the collision sphere to trace.
	 * @param ignoreDynColl Whether to ignore dynamic collision when tracing (i.e. just resolve static map collision).
	 */
	MoveTrace(immut Vector3f& position, immut Vector3f& velocity, f32 radius, bool ignoreDynColl)
	{
		mIgnoreDynamicCollision = ignoreDynColl;
		mPosition               = position;
		mVelocity               = velocity;
		mRadius                 = radius;
		mObject                 = nullptr;
		mStepFraction           = 1.0f;
	}

	Vector3f mPosition;           ///< _00, position of the object; begins as current position, ends up as target position.
	Vector3f mVelocity;           ///< _0C, velocity of the object; begins as current velocity, ends up as target velocity.
	f32 mRadius;                  ///< _18, radius to test for collision in.
	f32 mStepFraction;            ///< _1C, fraction of total movement to perform in each substep.
	bool mIgnoreDynamicCollision; ///< _20, whether to just resolve static (map) collision, or include dynamic collision.
	Creature* mObject;            ///< _24, the object whose movement is being traced.
};

/**
 * @brief Material handler for setting up shadow light cameras.
 *
 * @note Size: 0xC.
 */
struct MapShadMatHandler : public MaterialHandler {

	/// Constructs a new material handler and basic plain white material.
	MapShadMatHandler()
	{
		// set up a new white material - will be made opaque before use
		mShadowLightMat = new Material();
		mShadowLightMat->getColour().set(255, 255, 255, 255); // white
	}

	/// Sets the current graphics pipeline material to the stored one.
	virtual void setMaterial(Material*) // _08
	{
		mGfx->setMaterial(mShadowLightMat, true);
	}

	// _00     = VTBL
	// _00-_08 = MaterialHandler
	Material* mShadowLightMat; ///< _08, material to use when setting up each shadow's light camera.
};

/**
 * @brief Material handler for projecting models and rendering shadows.
 *
 * @note Size: 0x10.
 */
struct MapProjMatHandler : public MaterialHandler {

	/**
	 * @brief Constructs a new material handler for projecting a supplied texture.
	 * @param tex
	 */
	MapProjMatHandler(Texture* tex)
	{
		mProjectionCamera  = nullptr;
		mProjMat           = new Material();
		mProjMat->mTexture = tex;
		mProjMat->getColour().set(128, 128, 128, 32); // very light grey
	}

	/// Sets the current graphics pipeline material to the stored one.
	virtual void setMaterial(Material*) // _08
	{
		mGfx->setMaterial(mProjMat, true);
	}

	/**
	 * @brief Constructs and sets the GX tex matrix by projecting using the stored camera.
	 * @param enableProj Whether to construct the matrix via projection.
	 */
	virtual void setTexMatrix(bool enableProj) // _0C
	{
		mGfx->initProjTex(enableProj, mProjectionCamera);
	}

	// _00     = VTBL
	// _00-_08 = MaterialHandler
	Material* mProjMat;             ///< _08, material to use when projecting shadows.
	LightCamera* mProjectionCamera; ///< _0C, camera to use when projecting shadows.
};

/**
 * @brief Completely unused structure, only used to set up an array in MapMgr and generate a ctor.
 *
 * No additional code associated with it in the DLL thus far, either.
 *
 * @note Size: 0xC.
 */
struct MapRoom {

	/// Constructs an unused map room with some unknown default values.
	MapRoom()
	{
		_08 = 0;
		_04 = 1.0f;
		_00 = 1.0f;
	}

	f32 _00; ///< _00, unknown/unused.
	f32 _04; ///< _04, unknown/unused.
	u32 _08; ///< _08, unknown/unused.
};

/**
 * @brief Stores information for rendering a debug collision triangle.
 *
 * @note Fabricated name. Has to be this structure, but no idea what it was called. Has no ctor.
 * @note Size: 0xC.
 */
struct MapColls {
	CollGroup* mParentCollGroup; ///< _00, collision group this triangle is a part of.
	CollTriInfo* mTriangle;      ///< _04, collision triangle to render.
	int mColorCategory;          ///< _08, colour to draw triangle borders with - see `MapMgr::DebugColourTypes` enum.
};

/**
 * @brief Manager for a course/area map, handling collision, drawing, and some shadows.
 *
 * @note Size: 0x4D4.
 */
struct MapMgr {

	/// Colour types used to render debug collision triangles.
	enum DebugColourTypes {
		DCLR_Yellow = 0, ///< 0, colour for close (not far-culled) triangles. Also default colour.
		DCLR_Red    = 1, ///< 1, colour for far-culled triangles with >= 16 distance.
		DCLR_Blue   = 2, ///< 2, colour for far-culled triangles with < 16 distance.
		DCLR_COUNT,      ///< 3, number of debug triangle colours.
	};

	MapMgr(Controller* controller);

	void initEffects();
	void initShape();
	void createLights();
	void updateSimulation();
	void update();
	void preRender(Graphics& gfx);
	void drawShadowCasters(Graphics& gfx);
	void refresh(Graphics& gfx);
	void showCollisions(immut Vector3f& focusPos);
	void drawXLU(Graphics& gfx);
	void postrefresh(Graphics& gfx);
	void updatePos(f32 x, f32 z);
	f32 getLight(f32, f32);
	CollGroup* getCollGroupList(f32 x, f32 z, bool includePlatColl);
	f32 getMinY(f32 x, f32 z, bool includePlatColl);
	f32 getMaxY(f32 x, f32 z, bool includePlatColl);
	CollTriInfo* getCurrTri(f32 x, f32 z, bool includePlatColl);
	f32 findEdgePenetration(CollTriInfo& tri, immut Vector3f* vertexList, immut Vector3f& sphereCenter, f32 sphereRadius,
	                        Vector3f& outNormal);
	void recTraceMove(CollGroup* collGroupList, MoveTrace& trace, f32 timeStep);
	void traceMove(Creature* creature, MoveTrace& trace, f32 timeStep);
	Shape* loadPlatshape(immut char* modelFilePath);
	CreatureCollPart* requestCollPart(ObjCollInfo* info, Creature* obj);

	// unused/inlined:

	bool closeCollTri(CollGroup* collGroup, CollTriInfo* tri);

	Controller* mController;                  ///< _000, active player controller.
	DayMgr* mDayMgr;                          ///< _004, day manager for handling time-based lighting.
	Vector3f _08;                             ///< _008, unknown/unused - set by day manager then never used.
	MapRoom* mMapRooms;                       ///< _014, completely unused array of 256 MapRooms.
	int mMinMaxYQueryCount;                   ///< _018, number of getMinY and getMaxY calls performed in a given frame - never used.
	int mCurrTriQueryCount;                   ///< _01C, number of getCurrTri calls performed in a given frame - never used.
	u8 _20[0x60 - 0x20];                      ///< _020, unknown/unused.
	Shape* mMapModel;                         ///< _060, model for the current map.
	ShapeDynMaterials mAnimatedMaterials;     ///< _064, container for instances of all animated materials used by the map model.
	BaseShape* mMapShapes[MAPSHAPE_Count];    ///< _074, unused map shapes - see `MapShapeTypes` enum. Also see genMapParts.cpp.
	DynCollShape* mCollShapeList;             ///< _088, parent of list of all active dynamic collision models on the map.
	MapLightMgr* mSoftLightMgr;               ///< _08C, unused manager for (also unused) interactable soft lights.
	BoundBox mMapBounds;                      ///< _090, bounding box for map model.
	int mDebugCollCount;                      ///< _0A8, how many debug collision triangles to show this frame.
	int mActiveTriCount;                      ///< _0AC, number of collision triangles that are not far-culled this frame.
	int mMaxDebugColls;                       ///< _0B0, maximum number of debug triangles to show per frame (default: 300).
	Vector3f mDebugFocusPosition;             ///< _0B4, position to render any debug collision around - only ever set as navi position.
	BoundBox mOuterCollRenderBounds;          ///< _0C0, bounding box for drawing the outer (cyan) debug collision column.
	BoundBox mActiveCollisionBounds;          ///< _0D8, bounding box for drawing the inner (magenta) debug collision column.
	MapColls* mDebugCollisions;               ///< _0F0, array of render information for debug triangles.
	f32 mLastPhysicsTime;                     ///< _0F4, last time (counting secs from init) that the world's physics was updated.
	f32 mAccumPhysicsTime;                    ///< _0F8, total time (counting secs from init) that the world's physics has been running.
	f32 mPhysicsStepInterval;                 ///< _0FC, interval (in secs) between physics simulation steps - 1/60 by default.
	f32 mPhysicsSubStepInterval;              ///< _100, interval (in secs) to run integration sub-steps - 1/80 by default.
	bool mSimulationResetPending;             ///< _104, whether game world simulation needs to be reset.
	DynSimulator* mWorldSimulator;            ///< _108, physics manager for simulating game world dynamics.
	int mCurrTraceTick;                       ///< _10C, counter for how many traceMoves have been run, to prevent double-up collisions.
	int mShadowDelayCounter;                  ///< _110, frame delay to prevent shadows rendering too early - 3 frames by default.
	ShadowCaster mGlobalShadowList;           ///< _114, list of all shadow casters that need to move with the sun (large objects).
	MapShadMatHandler* mShadowCamMatHandler;  ///< _4AC, material handler for setting up each shadow's light camera.
	MapProjMatHandler* mShadowProjMatHandler; ///< _4B0, material handler for actually projecting/drawing each shadow.
	Texture* mBlurSourceTexture;              ///< _4B4, texture with the current frame's (pre-blur) rendering as pixel data.
	Texture* mBlurResultTexture;              ///< _4B8, texture from current frame's blur (multi-tex of last blur + current non-blur).
	int mBlur;                                ///< _4BC, unused value - adjusted by DayMgr's "blur" debug menu option but does nothing.
	f32 mCurrDesaturationLevel;               ///< _4C0, current desaturation (greyed blur) level - 0=no desaturation, 1=fully grey.
	f32 mCurrFadeLevel;                       ///< _4C4, current fade level - 0=no fade, 1=blacked out.
	f32 mTargetDesaturationLevel;             ///< _4C8, target desaturation level to transit to - 0=no desaturation, 1=fully grey.
	f32 mTargetFadeLevel;                     ///< _4CC, target fade level to transit to - 0=no fade, 1=blacked out.
	CreatureCollPart* mCollParts;             ///< _4D0, unused - object is created but never properly initialised or used again.
};

extern MapMgr* mapMgr;

#endif
