#ifndef _ROUTE_H
#define _ROUTE_H

#include "Colour.h"
#include "Node.h"
#include "Vector.h"
#include "types.h"

struct Creature;
struct CmdStream;
struct DataMsg;
struct Graphics;
struct MapMgr;
struct Plane;
struct BaseShape;
struct PathFinder;
struct Texture;
struct TexAttr;
struct RoutePoint;

/**
 * @brief Base node class for editable nodes in the route editor
 */
struct EditNode : public CoreNode {
	EditNode(char* name)
	    : CoreNode(name)
	{
	}

	virtual void msgCommand(DataMsg& msg) { }                 // _10 (weak)
	virtual void render2d(Graphics& gfx, int& textHeight) { } // _14 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
};

/**
 * @brief Link between route points in the navigation graph
 */
struct RouteLink : public CoreNode {
	RouteLink()
	    : CoreNode("rp")
	{
		mPoint = nullptr;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	RoutePoint* mPoint; //< _14, target route point
};

/**
 * @brief Navigation waypoint in the route system
 */
struct RoutePoint : public CoreNode {
	RoutePoint();

	void loadini(CmdStream* stream);

	// unused/inlined:
	void refresh(Graphics& gfx);

	// _00     = VTBL
	// _00-_14 = CoreNode
	f32 mScreenX;       ///< _14
	f32 mScreenY;       ///< _18
	f32 mScreenDepth;   ///< _1C
	f32 _20;            ///< _20
	f32 mRadius;        ///< _24, Radius of waypoint influence
	Vector3f mPosition; ///< _28
	int mIsOpen;        ///< _34
	int mIndex;         ///< _38
	RouteLink mLink;    ///< _3C, links to other route points
};

/**
 * @brief Container for a group of route points
 * @note Size: 0xC0.
 */
struct RouteGroup : public EditNode {
	RouteGroup();

	virtual void render2d(Graphics& gfx, int& textHeight); // _14

	void refresh(Graphics& gfx, EditNode* node);
	void loadini(CmdStream* stream);

	/**
	 * @brief Set the group ID from a 32-bit integer
	 * @param id The ID to set
	 */
	inline void setID(u32 id)
	{
		mIntID = id;

		for (int i = 0; i < 4; i++) {
			mStringID[i] = reinterpret_cast<char*>(&mIntID)[i];
		}

		mStringID[4] = '\0';
	}

	/**
	 * @brief Update the integer ID from the string representation
	 */
	inline void updateID()
	{
		char* str = reinterpret_cast<char*>(&mIntID);
		for (int i = 0; i < 4; i++) {
			str[i] = mStringID[i];
		}
	}

	// unused/inlined:
	void saveini(char* filename, RandomAccessStream& stream);

	// _00     = VTBL
	// _00-_14 = EditNode
	Colour mColour;                 ///< _14
	char mRouteName[0x40];          ///< _18
	u32 mIntID;                     ///< _58, not an ID32
	char mStringID[8];              ///< _5C
	BaseShape* mParentShape;        ///< _64
	RoutePoint mPointListRoot;      ///< _68
	Texture* mDebugWaypointTexture; ///< _BC
};

/**
 * @brief Waypoint flags for pathfinding
 */
DEFINE_ENUM_TYPE(WayPointFlags,
                 InWater     = 1, // Waypoint is in water
                 Pebble      = 2, // Waypoint has pebble obstacle
                 Destination = 4  // Either the start or destination waypoint in a pathfinding request
);

/**
 * @brief Runtime waypoint used for pathfinding
 * @note Size: 0xC4.
 */
struct WayPoint {

	/**
	 * @brief Stores pathfinding costs to each goal type (onions/UFO)
	 * @note This is completely stripped in retail and is only exposed in the DLL.
	 */
	struct LinkInfo {
		/**
		 * @brief Get pathfinding cost for a specific goal
		 * @param linkIdx Goal index (0-2: onions, 3: UFO)
		 * @return Cost value or -2 if unreachable
		 */
		int getInfo(int linkIdx) { return mValues[linkIdx]; }

		/**
		 * @brief Set pathfinding cost for a specific goal
		 * @param linkIdx Goal index (0-2: onions, 3: UFO)
		 * @param value Cost value or -2 if unreachable
		 */
		void setInfo(int linkIdx, int value) { mValues[linkIdx] = value; }

		int mValues[4]; ///< _00, blue/red/yellow onyons + ufo/ship
	};

	WayPoint() { }

	void setFlag(bool isOpen);
	void refresh(Graphics& gfx);
	void resetLinkInfos();
	void initLinkInfos();

	// unused/inlined:
	int getLinkIndex(int targetWpIdx);

	// DLL inlines:
	bool inWater() { return mFlags & WayPointFlags::InWater; }

	Vector3f mPosition;      ///< _00
	f32 mRadius;             ///< _0C
	int mIndex;              ///< _10, index in waypoint array
	int mLinkIndices[8];     ///< _14, indices of connected waypoints (-1 if none)
	int mLinkCount;          ///< _34
	bool mIsOpen;            ///< _38, whether the waypoint is traversable
	RoutePoint* mRoutePoint; ///< _3C
	u8 mFlags;               ///< _40, see WayPointFlags enum
	LinkInfo mLinkInfos[8];  ///< _44, Pathfinding info for each link
};

/**
 * @brief Manages all routing and pathfinding functionality
 */
struct RouteMgr : public Node {

	/**
	 * @brief Container for a group of waypoints
	 */
	struct Group {
		int getNumPoints() { return mNumPoints; }

		WayPoint* mWayPoints; ///< _00
		int mNumPoints;       ///< _04
	};

	RouteMgr();

	virtual void update(); // _10

	PathFinder* getPathFinder(u32 handle);
	int getNumWayPoints(u32 handle);
	Vector3f getSafePosition(u32 handle, Vector3f& pos);
	void findNearestEdge(WayPoint** outNearestStart, WayPoint** outNearestEnd, u32 handle, Vector3f& pos, bool allowWater, bool requireOpen,
	                     bool avoidDestination);
	void findNearestEdgeAvoidOff(WayPoint** outNearestStart, WayPoint** outNearestEnd, u32 handle, Vector3f& pos, bool allowWater,
	                             bool requireOpen, bool avoidDestination);
	WayPoint* findNearestWayPoint(u32 handle, Vector3f& pos, bool excludeWater);
	WayPoint* findNearestOffWayPoint(u32 handle, Vector3f& pos, bool excludeWater);
	void createOffPlane(u32 handle, Plane& plane, WayPoint* wp);
	WayPoint* findNearestWayPointAll(u32 handle, Vector3f& pos);
	WayPoint* getWayPoint(u32 handle, int wpIdx);
	void construct(MapMgr* map);
	void initLinks();
	int id2idx(u32 id);
	int getColinIndex(RouteGroup* group, RoutePoint* point);
	void refresh(Graphics& gfx);

	// unused/inlined:
	void dump(u32 handle);
	u32 idx2id(int idx);

	// _00     = VTBL
	// _00-_20 = Node
	Group* mGroupList;         ///< _20
	PathFinder** mPathFinders; ///< _24
	int mRouteCount;           ///< _28
	u32* mRouteGroupIDs;       ///< _2C
};

/**
 * @brief Pathfinding mode flags
 */
DEFINE_ENUM_TYPE(PathFinderMode,
                 None       = 0, // No special pathfinding mode
                 AvoidWater = 1, // Avoid water waypoints when pathfinding
                 Unk2       = 2  // Avoid specific waypoint index
);

/**
 * @brief Implements pathfinding algorithms for route navigation
 */
struct PathFinder {

	/**
	 * @brief Stores waypoint visit information during pathfinding
	 */
	struct Buffer {
		Buffer()
		{
			mDirection   = 0xFF;
			mWayPointIdx = -1;
		}

		// DLL inlines to make:
		bool check(int flag) { return mDirection & 1 << flag; }
		void resetFlag(int flag) { mDirection ^= (1 << flag); }
		void setFlag(int flag) { mDirection |= (1 << flag); }

		int mWayPointIdx; ///< _00
		u8 mDirection;    ///< _04, bitfield of available directions
	};

	/**
	 * @brief Status of pathfinding client request
	 */
	DEFINE_ENUM_TYPE(PathStatus,
	                 Searching = 0, // Currently searching for path
	                 Success   = 1, // Path found successfully
	                 Failed    = 2, // No path exists to destination
	);

	/**
	 * @brief Asynchronous pathfinding client
	 * @note Size: 0x28.
	 */
	struct Client {
		Buffer* mBuffer;           ///< _00, Path buffer
		int mStartWpIdx;           ///< _04, Starting waypoint index
		int mDestWpIdx;            ///< _08, Destination waypoint index
		bool mIncludeBlockedPaths; ///< _0C, Include closed waypoints
		int mHandle;               ///< _10, Unique request handle
		u16 mMode;                 ///< _14, PathFinderMode flags
		int mCurrentBufIdx;        ///< _18, Current position in buffer
		PathStatus::Type mStatus;  ///< _1C, Current search status
		bool mIsBacktracking;      ///< _20, Currently backtracking
		int mPathLength;           ///< _24, Final path length
	};

	PathFinder(RouteMgr::Group& group);

	u32 findASync(Buffer* buf, int startWPIdx, int destWPIdx, bool includeBlockedPaths);
	int checkASync(u32 handle);
	void releaseHandle(u32 handle);
	void updateClient(Client& client, int loops);
	int findSync(WayPoint** pathWayPoints, int numWPsToFind, int startWPIdx, int destWPIdx, bool includeBlockedPaths);
	int findSync(Buffer* bufferList, int startWPIdx, int destWPIdx, bool includeBlockedPaths);
	WayPoint* getWayPoint(int wpIdx);
	int selectWay(Buffer& buf, int destWPIdx, Buffer* bufferList, int wpCount, bool includeBlockedPaths);
	int findSyncOnyon(Vector3f& startPos, Buffer* bufferList, int startWPIdx, int goalType, bool ignoreClosedWaypoints);
	int selectWayOnyon(int additionalCost, int goalType, Buffer& buf, int destWPIdx, Buffer* bufferList, int visitedBufferCount,
	                   bool ignoreClosedWaypoints);
	int selectSecondBestWayOnyon(Vector3f& curPos, int& secondBestCost, int goalType, Buffer& buf, int destWPIdx, Buffer* bufferList,
	                             int bufIdx, bool ignoreClosedWaypoints);

	// unused/inlined:
	int handle2idx(u32 handle);
	void updateASync();
	int findFirstStepOnyon(int startWPIdx, int goalType, Buffer* bufferList);

	// DLL inlines:
	static bool checkMode(int flag) { return mode & flag; }
	static void clearMode() { mode = 0; }
	static void setMode(int flag) { mode |= flag; }

	static f32 limitDistance;
	static int avoidWayPointIndex; // Waypoint to avoid when Unk2 mode is set
	static u16 mode;               // Current PathFinderMode

	RouteMgr::Group* mGroup; ///< _00, Waypoint group
	int mBufferSize;         ///< _04, Max waypoints in path
	Buffer* mBuffer;         ///< _08, Path buffer
	int mHandleCount;        ///< _0C, Handle counter
	int mClientCount;        ///< _10, Active clients
	int mMaxClients;         ///< _14, Max concurrent clients
	Client* mClient;         ///< _18, Client array
};

/**
 * @brief Follows routes for creatures (mostly stripped)
 */
struct RouteTracer {

	/**
	 * @brief Context for route tracing (mostly stripped)
	 */
	struct Context {

		/**
		 * @brief Point information for route tracing
		 */
		struct PointInfo {
			PointInfo();

			Vector3f _00; ///< _00
			f32 _0C;      ///< _0C
		};

		void makeContext(RouteTracer* tracer);
		void setTarget(RouteTracer* tracer);
		int recognise(RouteTracer* tracer);

		PointInfo _00[3]; ///< _00
	};

	RouteTracer();

	// unused/inlined:
	void render(Graphics& gfx);
	bool noLink();
	void startConsult(Creature* creature, PathFinder* pathfinder, PathFinder::Buffer* buffer, int wpCount, Vector3f& pos);
	void updateState();
	Vector3f getTarget();

	// TODO: members
	Context mContext;    ///< _00
	u8 _30[0x44 - 0x30]; ///< _30, unknown, might be part of Context?
	Vector3f _44;        ///< _44
	Vector3f _50;        ///< _50
	Creature* _5C;       ///< _5C
	Vector3f _60;        ///< _60
	Vector3f _6C;        ///< _6C
	Vector3f _78;        ///< _78
};

extern RouteMgr* routeMgr;

#endif
