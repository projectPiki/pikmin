#ifndef _SOUNDMGR_H
#define _SOUNDMGR_H

#include "Ayu.h"
#include "Controller.h"
#include "Node.h"
#include "Parameters.h"
#include "SoundID.h"
#include "Win.h"
#include "jaudio/pikiinter.h"
#include "types.h"

#define MAX_SOUND_EFFECTS (128)
#define MAX_SOUND_EVENTS  (16)

struct Creature;

/**
 * @brief Quick enum-name connection object for player-related sound effects.
 *
 * @note Size: 0x8.
 */
struct SeInfo {
	int mJacPlayerSeID; ///< _00, see JacOrimaSoundID enum.
	char* mSeName;      ///< _04, name of sound effect.
};

/**
 * @brief Object for storing sound effect related constants.
 *
 * @note Size: 0x54.
 */
struct SeConstant : public Node {

	/**
	 * @brief Parameters loaded from file.
	 *
	 * @note Offsets are relative to SeConstant for convenience.
	 */
	struct Parms : public Parameters {

		/// Constructor with default values (overwritten by file load).
		Parms()
		    : mSECutoffDist(this, 700.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mBossBGMStartDist(this, 400.0f, 0.0f, 0.0f, "p01", nullptr)
		    , mBossBGMEndDist(this, 800.0f, 0.0f, 0.0f, "p02", nullptr)
		{
		}

		// _20-_24 = Parameters
		Parm<f32> mSECutoffDist;     ///< _24, p00 - radius that sound effects are audible within.
		Parm<f32> mBossBGMStartDist; ///< _34, p01 - radius that boss background music begins within.
		Parm<f32> mBossBGMEndDist;   ///< _44, p02 - radius at which boss background music ends.
	};

	/// Constructor (just loads the parameters file).
	SeConstant();

	/// Reads in the parameters from (streamed) file.
	virtual void read(RandomAccessStream& input) // _0C (weak)
	{
		mParms.read(input);
	}

	// _00     = VTBL
	// _00-_20 = Node
	Parms mParms; ///< _20, sound effect parameters.
};

/**
 * @brief Object for individual sound effects.
 *
 * Mostly shuttles information from game code to jaudio.
 * Collectively managed by SeMgr.
 *
 * @note Size: 0x28.
 */
struct SeContext {
	friend struct SeSystem;

public:
	/// Default constructor, has no emitting creature and defaults to system event type.
	SeContext();

	/// Constructor for assigning both an emitting creature and event type.
	SeContext(Creature* obj, int eventType);

	/// Releases the attached handle, assigns a new object and type, and resets.
	void setContext(Creature* obj, int eventType);

	/// Assigns a new event handle and plays the given sound (by game sound ID).
	void playSound(int soundID);

	/// Stops given sound (by game sound ID) if it has an active event handle.
	void stopSound(int soundID);

	/// If sound is active, updates the camera and object positions.
	void update();

	/// If sound is active, releases the handle - true if handle was active, false if not.
	bool releaseEvent();

	/// STRIPPED - gets position of emitter object if assigned, or stored position if not.
	Vector3f getPos();

	/// STRIPPED - gets ObjType of assigned object.
	int getObjType();

	/// STRIPPED - prints debug information about current context.
	void dump();

	/// Sets current emitter position.
	void setPosition(immut Vector3f& pos) { mSourcePosition = pos; }

protected:
	/// STRIPPED - initialises new event of given type with updated position and event handle.
	void createEvent(int eventType);

	u32 mClock;                     ///< _00, never updated, seems to be an unimplemented timer.
	Creature* mGameObj;             ///< _04, game object emitting the sound effect.
	int mEventHandle;               ///< _08, jaudio handle for active sound effect (-1 if inactive).
	u16 mEventType;                 ///< _0C, jaudio event type - see JacEventType enum.
	Vector3f mSourceListenerOffset; ///< _10, direction from listener to source, scaled by cutoff distance.
	Vector3f mSourcePosition;       ///< _1C, current position of sound emitter.
};

/**
 * @brief Managing object for sound effects.
 *
 * @note Size: 0x30.
 */
struct SeMgr : public Node {
public:
	/// Constructor, sets up SeInfos for some pikmin and player sounds.
	SeMgr();

	/// Trivial updater.
	virtual void update(); // _10

	/// Starts c-sticking "formation" sound based on c-stick magnitude/direction.
	void playNaviSound(s32 stickX, s32 stickY);

	/// Increments the battle tracker.
	void joinBattle();

	/// Decrements the battle tracker with a floor of 0.
	void leaveBattle();

	/// Passes pikmin count to jaudio to process for 'gaya' sounds.
	void setPikiNum(int pikiNum);

	/// STRIPPED - trivial.
	void playBGM(u32);

	/// STRIPPED - trivial.
	void stopBGM();

	/// STRIPPED - !! UNIMPLEMENTED !!.
	void stopSoundAll();

	/// Trivial.
	static void play(u32);

	/// Stops sound effect based on Jac player sound ID.
	static void stop(u32 jacSeID);

	/// Gets current sound effect count.
	int getSENum() { return mSENum; }

	/// Gets pointer to SeInfo based on array index (rather than sound ID).
	SeInfo* getIndexInfo(int idx) { return &mSeInfos[idx]; }

protected:
	/// STRIPPED - gets pointer to SeInfo based on Jac player sound ID.
	SeInfo* findInfo(int jacSeID);

	/// Adds a new info to the list with given Jac player sound ID and name (unless maxed out).
	void addInfo(int jacSeID, char* seName);

	// _00     = VTBL
	// _00-_20 = Node
	// _00-_30 = SeMgr
	int mBattleCount; ///< _20, counter to track if we're still in combat or not.
	int mSENum;       ///< _24, current number of managed sound effects.
	int mMaxInfos;    ///< _28, max number of manageable sound effects (128 by default).
	SeInfo* mSeInfos; ///< _2C, info for managed sound effects.
};

/**
 * @brief Unused SE Test window.
 *
 * @note Size: 0x64.
 */
struct SeWin : public GmWin {
public:
	/// Starts window open sequence.
	virtual void open(); // _10

	/// Begins window close sequence.
	virtual void close(); // _14

	/// Updates window based on controller input and state.
	virtual void update(); // _18

	/// Prints current sound effect information to screen.
	virtual void doRender(Graphics& gfx); // _1C

protected:
	// _00     = VTBL
	// _00-_14 = CoreNode
	// _00-_48 = GmWin
	Controller* mController;  ///< _48, active controller.
	int mCurrSeIndex;         ///< _4C, currently selected sound effect index.
	int mCurrJacSoundID;      ///< _50, Jac player sound ID of currently selected sound effect.
	int mAnimFramesRemaining; ///< _54, fade in/out timer.
	int mUp;                  ///< _58, amount of indices to scroll up/down on update.
	f32 mScrollTime;          ///< _5C, time that stick has been pressed.
	bool mStickWasPushed;     ///< _60, has control stick been pushed (sufficiently) up or down?
};

/**
 * @brief Overall sound effect coordination object.
 *
 * @note Size: 0x78.
 */
struct SeSystem {
	friend struct SeContext;

public:
	/**
	 * @brief Quick storage object for active sound effect events.
	 *
	 * @note Size: 0x8.
	 */
	struct Event {

		/// Constructor - null context and inactive.
		Event()
		{
			mHandle  = -1;
			mContext = nullptr;
		}

		int mHandle;         ///< _00, handle for sound effect (-1 if inactive).
		SeContext* mContext; ///< _04, sound effect context (info).
	};

	/// Constructor - resets everything, max 16 events by default.
	SeSystem();

	/// Re-initialises + resets all events.
	void resetSystem();

	/// Plays sound of given (game) ID at given position, with Piki event type.
	void playPikiSound(int soundID, immut Vector3f& sourcePos);

	/// Plays sound of given type, (game) ID at given position by reusing an existing context.
	void playSoundDirect(int eventType, int soundID, immut Vector3f& sourcePos);

	/// Renders "SE [index]" above each current active sound event.
	void draw3d(Graphics& gfx);

	/// Renders a flat list of all active event information to the screen.
	void draw2d(Graphics& gfx);

	/// Prints all event and associated context information.
	void dumpEvents();

	/// Sets listener position, updates all events, and checks for boss background music.
	void update(Graphics& gfx, immut Vector3f& listenerPos);

	/// Calculates the offset/direction(!) from the listener to the given sound position, scaled by cutoff distance.
	void calcCameraPos(immut Vector3f& soundPos, Vector3f& normalisedOffsetDir);

	/// Converts given (game) sound ID to jaudio sound ID using the soundTable.
	int getJacID(int soundID);

	/// Resets and closes system, and prints debug information.
	void exitCourse();

	/// STRIPPED - gets name of sound based on input (game) sound ID.
	char* getSoundName(int soundID);

	/// STRIPPED - gets event type of sound based on input (game) sound ID.
	int getEventType(int soundID);

	/// STRIPPED - checks loop type of sound based on input (game) sound ID.
	bool isLoopType(int soundID);

	/// STATIC - plays given system (game) sound ID.
	static void playSysSe(int soundID);

	/// STATIC - stops given system (game) sound ID.
	static void stopSysSe(int soundID);

	/// STATIC - plays given player (game) sound ID.
	static void playPlayerSe(int soundID);

	/// STATIC - stops given player (game) sound ID.
	static void stopPlayerSe(int soundID);

protected:
	/// Initialises system and resets all events to inactive.
	void initEvent();

	/// Creates new sound event with given context, event type and offset, and returns event handle.
	int createEvent(SeContext* context, int eventType, SVector_* soundOffset);

	/// Destroys an event with given context and handle - returns true if successful, false if not.
	bool destroyEvent(SeContext* context, s32 handle);

	/// STRIPPED - gets event index of given handle.
	int getEvent(s32 handle);

	/// Gets event index of given context.
	int getEvent(SeContext* context);

	int mMaxSoundID;            ///< _00, initialised to number of total game sound IDs, used to check indices.
	Matrix4f mCameraMtx;        ///< _04, matrix to do camera transformations for positions.
	f32 mUnusedDistance;        ///< _44, unused - set to 700.0f and never checked/updated.
	Vector3f mListenerPosition; ///< _48, position of listener (either captain or cutscene target).
	int mCurrentContextCount;   ///< _54, count of current active sound effects.
	int mMaxContextCount;       ///< _58, max amount of active sound effects.
	SeContext* mContexts;       ///< _5C, list of active sound effects.
	SeConstant* mSoundParams;   ///< _60, fixed sound constants/parameters read from file.
	u32 mClock;                 ///< _64, unused clock/timer - set to 0 but only updated in demo versions.
	int mCurrentEventCount;     ///< _68, count of current active sound events.
	int mMaxEventCount;         ///< _6C, max amount of active sound events.
	Event* mEvents;             ///< _70, list of active sound events.
	bool mIsBossBGMActive;      ///< _74, is boss background music currently playing?
	bool mIsClosed;             ///< _75, is the system inactive? if true, does not accept new sounds to play.
};

extern SeSystem* seSystem;
extern SeMgr* seMgr;

#endif
