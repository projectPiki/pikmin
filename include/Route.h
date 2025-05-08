#ifndef _ROUTE_H
#define _ROUTE_H

#include "types.h"
#include "Vector.h"
#include "Node.h"
#include "Colour.h"

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
 * @brief TODO
 */
enum PathFinderMode {
	PFMODE_Unk0       = 0,
	PFMODE_AvoidWater = 1,
	PFMODE_Unk2       = 2,
};

/**
 * @brief TODO
 */
struct EditNode : public CoreNode {
	EditNode(char* name)
	    : CoreNode(name)
	{
	}

	virtual void msgCommand(DataMsg&) { }      // _10 (weak)
	virtual void render2d(Graphics&, int&) {}; // _14 (weak)

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct RouteLink : public CoreNode {
	RouteLink()
	    : CoreNode("rp")
	{
		mPoint = nullptr;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	RoutePoint* mPoint; // _14
};

/**
 * @brief TODO
 */
struct RoutePoint : public CoreNode {
	RoutePoint();

	void loadini(CmdStream*);

	// unused/inlined:
	void refresh(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	f32 mScreenX;       // _14
	f32 mScreenY;       // _18
	f32 mScreenDepth;   // _1C
	f32 _20;            // _20
	f32 mRadius;        // _24
	Vector3f mPosition; // _28
	int mState;         // _34
	int mIndex;         // _38
	RouteLink mLink;    // _3C
};

/**
 * @brief TODO
 * @note Size: 0xC0.
 */
struct RouteGroup : public EditNode {
	RouteGroup();

	virtual void render2d(Graphics&, int&); // _14

	void refresh(Graphics&, EditNode*);
	void loadini(CmdStream*);

	inline void setID(u32 id)
	{
		mIntID = id;

		for (int i = 0; i < 4; i++) {
			mStringID[i] = reinterpret_cast<char*>(&mIntID)[i];
		}

		mStringID[4] = '\0';
	}

	inline void updateID()
	{
		char* str = reinterpret_cast<char*>(&mIntID);
		for (int i = 0; i < 4; i++) {
			str[i] = mStringID[i];
		}
	}

	// unused/inlined:
	void saveini(char*, RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = EditNode?
	Colour mColour;            // _14
	char mRouteName[0x40];     // _18
	u32 mIntID;                // _58, yep, this isn't an ID32...
	char mStringID[8];         // _5C
	BaseShape* mParentShape;   // _64
	RoutePoint mPointListRoot; // _68
	Texture* _BC;              // _BC
};

/**
 * @brief TODO
 *
 * @note Size: 0xC4.
 */
struct WayPoint {

	/**
	 * @brief TODO
	 */
	struct LinkInfo {
		// COMPLETELY stripped, exposed in the DLL

		int getInfo(int linkIdx) { return mValues[linkIdx]; }
		void setInfo(int linkIdx, int value) { mValues[linkIdx] = value; }

		int mValues[4]; // _00, blue/red/yellow onyons + ufo/ship
	};

	WayPoint() { }

	void setFlag(bool);
	void refresh(Graphics&);
	void resetLinkInfos();
	void initLinkInfos();

	// unused/inlined:
	int getLinkIndex(int);

	// DLL inlines:
	bool inWater() { return _40 & 1; }

	Vector3f mPosition;      // _00, probably
	f32 mRadius;             // _0C
	int mIndex;              // _10
	int mLinkIndices[8];     // _14
	int mLinkCount;          // _34
	bool mIsOpen;            // _38
	RoutePoint* mRoutePoint; // _3C
	u8 _40;                  // _40, flag?
	LinkInfo mLinkInfos[8];  // _44
};

/**
 * @brief TODO
 */
struct RouteMgr : public Node {

	/**
	 * @brief TODO
	 */
	struct Group {
		// DLL inline to do
		int getNumPoints() { return mNumPoints; }

		WayPoint* mWayPoints; // _00
		int mNumPoints;       // _04
	};

	RouteMgr();

	virtual void update(); // _10

	PathFinder* getPathFinder(u32);
	int getNumWayPoints(u32);
	Vector3f getSafePosition(u32, Vector3f&);
	void findNearestEdge(WayPoint**, WayPoint**, u32, Vector3f&, bool, bool, bool);
	void findNearestEdgeAvoidOff(WayPoint**, WayPoint**, u32, Vector3f&, bool, bool, bool);
	WayPoint* findNearestWayPoint(u32, Vector3f&, bool);
	WayPoint* findNearestOffWayPoint(u32, Vector3f&, bool);
	void createOffPlane(u32, Plane&, WayPoint*);
	WayPoint* findNearestWayPointAll(u32, Vector3f&);
	WayPoint* getWayPoint(u32, int);
	void construct(MapMgr*);
	void initLinks();
	int id2idx(u32);
	int getColinIndex(RouteGroup*, RoutePoint*);
	void refresh(Graphics&);

	// unused/inlined:
	void dump(u32);
	u32 idx2id(int);

	// _00     = VTBL
	// _00-_20 = Node
	Group* mGroupList;         // _20
	PathFinder** mPathFinders; // _24
	int mRouteCount;           // _28
	u32* mRouteGroupIDs;       // _2C
};

/**
 * @brief TODO
 */
struct PathFinder {

	/**
	 * @brief TODO
	 */
	struct Buffer {
		Buffer()
		{
			mFlag        = 0xFF;
			mWayPointIdx = -1;
		}

		// DLL inlines to make:
		bool check(int flag) { return mFlag & 1 << flag; }
		void resetFlag(int flag) { mFlag ^= (1 << flag); }
		void setFlag(int flag) { mFlag |= (1 << flag); }

		int mWayPointIdx; // _00
		u8 mFlag;         // _04
	};

	/**
	 * @brief TODO
	 *
	 * @note Size: 0x28.
	 */
	struct Client {
		// NO ctor or ANY functions for this struct

		Buffer* mBuffer; // _00
		int _04;         // _04
		int _08;         // _08
		bool _0C;        // _0C
		int mHandle;     // _10
		u16 mMode;       // _14
		int _18;         // _18
		int _1C;         // _1C
		u8 _20;          // _20
		int _24;         // _24
	};

	PathFinder(RouteMgr::Group&);

	u32 findASync(Buffer*, int, int, bool);
	int checkASync(u32);
	void releaseHandle(u32);
	void updateClient(Client&, int);
	int findSync(WayPoint**, int, int, int, bool);
	int findSync(Buffer*, int, int, bool);
	WayPoint* getWayPoint(int);
	int selectWay(Buffer&, int, Buffer*, int, bool);
	int findSyncOnyon(Vector3f&, Buffer*, int, int, bool);
	int selectWayOnyon(int, int, Buffer&, int, Buffer*, int, bool);
	int selectSecondBestWayOnyon(Vector3f&, int&, int, Buffer&, int, Buffer*, int, bool);

	// unused/inlined:
	int handle2idx(u32);
	void updateASync();
	int findFirstStepOnyon(int, int, Buffer*);

	// DLL inlines:
	static bool checkMode(int flag) { return mode & flag; }
	static void clearMode() { mode = 0; }
	static void setMode(int flag) { mode |= flag; }

	static f32 limitDistance;
	static int avoidWayPointIndex;
	static u16 mode;

	RouteMgr::Group* mGroup; // _00
	int mBufferSize;         // _04, number of points in group
	Buffer* mBuffer;         // _08
	int mHandleCount;        // _0C
	int mClientCount;        // _10
	int mMaxClients;         // _14
	Client* mClient;         // _18
};

/**
 * @brief Mostly stripped struct (and substructs).
 */
struct RouteTracer {
	/**
	 * @brief Mostly stripped struct (and substructs).
	 */
	struct Context {
		/**
		 * @brief Mostly stripped struct.
		 */
		struct PointInfo {
			PointInfo();

			Vector3f _00; // _00
			f32 _0C;      // _0C
		};

		Context();

		void makeContext(RouteTracer*);
		void setTarget(RouteTracer*);
		int recognise(RouteTracer*);

		PointInfo _00[3]; // _00
	};

	RouteTracer();

	// unused/inlined:
	void render(Graphics&);
	bool noLink();
	void startConsult(Creature*, PathFinder*, PathFinder::Buffer*, int, Vector3f&);
	void updateState();
	Vector3f getTarget();

	// TODO: members
	Context mContext;    // _00
	u8 _30[0x44 - 0x30]; // _30, unknown, might be part of Context?
	Vector3f _44;        // _44
	Vector3f _50;        // _50
	Creature* _5C;       // _5C
	Vector3f _60;        // _60
	Vector3f _6C;        // _6C
	Vector3f _78;        // _78
};

extern RouteMgr* routeMgr;

#endif
