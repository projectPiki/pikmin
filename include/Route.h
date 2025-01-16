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
struct RoutePoint;

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
		mPoint = 0;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	RoutePoint* mPoint; // _14
};

/**
 * @brief TODO
 */
struct RoutePoint : public CoreNode {
	RoutePoint()
	    : CoreNode("rp")
	{
		mLink.initCore("");
		_20    = 8.0f;
		mIndex = 0;
		mState = 1;
		mWidth = 10.0f;
	}

	void loadini(CmdStream*);

	// unused/inlined:
	void refresh(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	f32 mScreenX;       // _14
	f32 mScreenY;       // _18
	f32 mScreenDepth;   // _1C
	f32 _20;            // _20
	f32 mWidth;         // _24
	Vector3f mPosition; // _28
	u32 mState;         // _34
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
	u32 _BC;                   // _BC
};

/**
 * @brief TODO
 */
struct WayPoint {

	/**
	 * @brief TODO
	 */
	struct LinkInfo {
		// COMPLETELY stripped, exposed in the DLL

		int getInfo(int);
		void setInfo(int, int);

		// TODO: members
	};

	WayPoint();

	void setFlag(bool);
	void refresh(Graphics&);
	void resetLinkInfos();
	void initLinkInfos();

	// unused/inlined:
	int getLinkIndex(int);

	// DLL inlines:
	bool inWater();

	Vector3f mPosition;  // _00, probably
	f32 mRadius;         // _0C
	int mIndex;          // _10
	u8 _14[0x38 - 0x14]; // _14, unknown
	bool mIsOpen;        // _38
	                     // TODO: members
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
		int getNumPoints();

		// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct PathFinder {
	struct Buffer {
		Buffer();

		// DLL inlines to make:
		bool check(int);
		void resetFlag(int);
		void setFlag(int);

		int mWayPointIdx; // _00
		u8 _04;           // _04
	};

	struct Client {
		// TODO: members
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

	// TODO: members
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

			// TODO: members
		};

		Context();

		void makeContext(RouteTracer*);
		void setTarget(RouteTracer*);
		int recognise(RouteTracer*);

		// TODO: members
	};

	RouteTracer();

	// unused/inlined:
	void render(Graphics&);
	bool noLink();
	void startConsult(Creature*, PathFinder*, PathFinder::Buffer*, int, Vector3f&);
	void updateState();
	Vector3f getTarget();

	// TODO: members
};

extern RouteMgr* routeMgr;

#endif
