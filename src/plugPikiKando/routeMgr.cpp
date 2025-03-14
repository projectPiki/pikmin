#include "Route.h"
#include "Colour.h"
#include "MapMgr.h"
#include "MapCode.h"
#include "sysNew.h"
#include "DebugLog.h"

u16 PathFinder::mode;
int PathFinder::avoidWayPointIndex = -1;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("routeMgr")

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
PathFinder::PathFinder(RouteMgr::Group& group)
{
	mGroup      = &group;
	mBufferSize = mGroup->getNumPoints();
	PRINT("buffersize = %d\n", mBufferSize);
	mBuffer = new Buffer[mBufferSize];
	clearMode();
	mHandleCount = 1;
	mClientCount = 0;
	mMaxClients  = 100;
	mClient      = new Client[mMaxClients];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
int PathFinder::handle2idx(u32 handle)
{
	for (int i = 0; i < mClientCount; i++) {
		if (mClient[i].mHandle == handle) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	8009F5F8
 * Size:	0000B4
 */
u32 PathFinder::findASync(PathFinder::Buffer* buf, int a, int b, bool flag)
{
	if (mClientCount >= mMaxClients) {
		return 0;
	}
	int handle = mHandleCount++;
	if (mHandleCount >= 200000) {
		mHandleCount = 1;
	}

	Client* client                = &mClient[mClientCount++];
	client->mBuffer               = buf;
	client->_04                   = a;
	client->_08                   = b;
	client->_0C                   = flag;
	client->mMode                 = mode;
	client->mHandle               = handle;
	client->_18                   = 0;
	client->_1C                   = 0;
	client->_20                   = 0;
	client->mBuffer->mWayPointIdx = a;
	if (a == b) {
		client->_1C = 1;
		client->_24 = 1;
		return handle;
	}
	return handle;
}

/*
 * --INFO--
 * Address:	8009F6AC
 * Size:	000088
 */
int PathFinder::checkASync(u32 handle)
{
	int idx = handle2idx(handle);

	if (idx == -1) {
		return -3;
	}

	Client* client = &mClient[idx];
	if (client->_1C == 2) {
		PRINT("FAIL WHY ? \n");
		return -2;
	}

	if (client->_1C == 1) {
		PRINT("SUCCESS\n");
		return client->_24;
	}

	return -1;
}

/*
 * --INFO--
 * Address:	8009F734
 * Size:	0000D8
 */
void PathFinder::releaseHandle(u32 handle)
{
	int idx = handle2idx(handle);
	if (idx == -1) {
		return;
	}
	mClientCount--;

	// No idea why we couldnt just use a normal mClient[i] = mClient[i+1] but ok
	for (int i = idx; i < mClientCount; i++) {
		Client& a = mClient[i];
		Client& b = mClient[i + 1];

		a.mBuffer = b.mBuffer;
		a._04     = b._04;
		a._08     = b._08;
		a._0C     = b._0C;
		a.mHandle = b.mHandle;
		a.mMode   = b.mMode;
		a._18     = b._18;
		a._1C     = b._1C;
		a._20     = b._20;
		a._24     = b._24;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void PathFinder::updateASync()
{
	if (mClientCount) {
		int loops = 256 / mClientCount;
		for (int i = 0; i < mClientCount; i++) {
			Client& client = mClient[i];
			int tmpMode    = mode;
			mode           = client.mMode;
			updateClient(client, loops);
			mode = tmpMode;
		}
	}
}

/*
 * --INFO--
 * Address:	8009F80C
 * Size:	000340
 */
void PathFinder::updateClient(Client& client, int loops)
{
	while (client._1C == 0 && loops > 0) {
		loops--;
		if (mBufferSize < client._18) {
			ERROR("buffer full\n");
		}
		WayPoint* wp = getWayPoint(client.mBuffer[client._18].mWayPointIdx);
		if (client._20 == 0) {
			for (int i = 0; i < 8; i++) {
				if (wp->mLinkIndices[i] == -1) {
					client.mBuffer[client._18].resetFlag(i);
				} else {
					client.mBuffer[client._18].setFlag(i);
				}
			}
		}

		int handle = selectWay(client.mBuffer[client._18], client._08, client.mBuffer, client._18, client._0C);
		if (handle != -1) {
			int linkIdx = wp->mLinkIndices[handle];
			if (linkIdx == client._08) {
				client.mBuffer[++client._18].mWayPointIdx = client._08;

				if (mBufferSize < client._18) {
					ERROR("mem access\n");
				}

				PRINT("OK FOUND!\n");
				client._1C = 1;
				client._24 = client._18 + 1;
				return;
			}

			client.mBuffer[client._18].resetFlag(handle);
			client._18++;
			if (client._18 >= mBufferSize) {
				client._18--;
				client._20 = 1;
			} else {
				client.mBuffer[client._18].mWayPointIdx = linkIdx;
				client._20                              = false;
			}
		} else {
			client._20                              = 1;
			client.mBuffer[client._18].mWayPointIdx = -1;
			client._18--;
			if (client._18 < 0) {
				PRINT("GIVE UP\n");
				client._1C = 2;
				client._24 = -2;
				return;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8009FB4C
 * Size:	000084
 */
int PathFinder::findSync(WayPoint** pathWayPoints, int numWPsToFind, int startWPIdx, int destWPIdx, bool flag)
{
	int res = findSync(mBuffer, startWPIdx, destWPIdx, flag);
	if (res > 0) {
		for (int i = 0; i < numWPsToFind; i++) {
			pathWayPoints[i] = getWayPoint(mBuffer[i].mWayPointIdx);
		}
	}
	return res;
}

/*
 * --INFO--
 * Address:	8009FBD0
 * Size:	000230
 */
int PathFinder::findSync(PathFinder::Buffer* bufferList, int startWPIdx, int destWPIdx, bool flag)
{
	if (checkMode(PFMODE_AvoidWater)) {
		PRINT("*** AVOID_WATER ROUTE FINDING START (%d - %d)\n", destWPIdx, startWPIdx);
	}

	Buffer* buf;
	int wpCount = 0;

	bufferList[0].mWayPointIdx = startWPIdx;
	if (startWPIdx == destWPIdx) {
		return 1;
	}

	int stat        = 0;
	bool tryNewPath = false;
	while (stat == 0) {
		buf = &bufferList[wpCount];
		if (mBufferSize < wpCount) {
			ERROR("buffer full\n");
		}
		WayPoint* wp = getWayPoint(buf->mWayPointIdx);
		if (!tryNewPath) {
			for (int i = 0; i < 8; i++) {
				if (wp->mLinkIndices[i] == -1) {
					buf->resetFlag(i);
				} else {
					buf->setFlag(i);
				}
			}
		}
		int way = selectWay(*buf, destWPIdx, bufferList, wpCount, flag);
		if (way != -1) {
			int linkWPIdx = wp->mLinkIndices[way];
			if (linkWPIdx == destWPIdx) {
				wpCount++;
				bufferList[wpCount].mWayPointIdx = destWPIdx;

				if (mBufferSize < wpCount) {
					ERROR("mem access\n");
				}
				stat = 1;
				break;
			}

			// we didn't make it to the destination (yet)
			buf->resetFlag(way);

			wpCount++;
			if (wpCount >= mBufferSize) {
				PRINT("@@ backtrack (full buffer ptr=%d buffSize=%d)\n", wpCount, mBufferSize);
				tryNewPath = true;
				wpCount--;

			} else {
				bufferList[wpCount].mWayPointIdx = linkWPIdx;
				tryNewPath                       = false;
			}

		} else {
			buf->mWayPointIdx = -1;
			tryNewPath        = true;
			wpCount--;
			if (wpCount < 0) {
				stat = 2;
			}
		}
	}

	if (stat == 1) {
		return wpCount + 1;
	}
	return 0;

	u32 badCompiler[6];
}

/*
 * --INFO--
 * Address:	8009FE00
 * Size:	000014
 */
WayPoint* PathFinder::getWayPoint(int wpIdx)
{
	return &mGroup->mWayPoints[wpIdx];
}

/*
 * --INFO--
 * Address:	8009FE14
 * Size:	0001FC
 */
int PathFinder::selectWay(PathFinder::Buffer& buffer, int destWPIdx, PathFinder::Buffer* bufferList, int wpCount, bool includeBlockedPaths)
{
	int res     = -1;
	int numWays = 0;
	f32 distances[8];
	int ids[8];

	Vector3f currPos = getWayPoint(buffer.mWayPointIdx)->mPosition;
	Vector3f destPos = getWayPoint(destWPIdx)->mPosition;
	for (int i = 0; i < 8; i++) {
		if (!buffer.check(i)) {
			continue;
		}

		WayPoint* wp = getWayPoint(buffer.mWayPointIdx);
		if (!wp) {
			PRINT("buffer.idx=%d", buffer.mWayPointIdx);
			ERROR("wp is null!");
		}

		if ((!checkMode(PFMODE_Unk2) || avoidWayPointIndex == -1 || wp->mIndex != avoidWayPointIndex)
		    && (!checkMode(PFMODE_AvoidWater) || !wp->inWater())) {
			int linkIdx = wp->mLinkIndices[i];
			if (linkIdx != buffer.mWayPointIdx) {

				if (linkIdx == -1) {
					// can't use this path, invalid waypoint idx
					buffer.resetFlag(i);
					continue;
				}

				if (!getWayPoint(linkIdx)) {
					PRINT("idx=%d", linkIdx);
					ERROR("no getwaypoint!");
				}

				if (!includeBlockedPaths && !getWayPoint(linkIdx)->mIsOpen) {
					buffer.resetFlag(i);
					continue;
				}

				bool found = false;
				for (int j = 0; j < wpCount; j++) {
					if (linkIdx == bufferList[j].mWayPointIdx) {
						found = true;
						break;
					}
				}

				if (!found) {
					if (numWays > 7) {
						PRINT("numWays=%d", numWays);
						ERROR("numWays>=8");
					}
					ids[numWays] = i;
					if (linkIdx == destWPIdx) {
						return i;
					}
					Vector3f linkPos   = getWayPoint(linkIdx)->mPosition;
					distances[numWays] = qdist2(linkPos.x, linkPos.z, destPos.x, destPos.z);
					numWays++;
				}
			}
		}
	}

	// find id physically closest to destination
	f32 minDist = 128000.0f;
	for (int i = 0; i < numWays; i++) {
		if (distances[i] < minDist) {
			minDist = distances[i];
			res     = ids[i];
		}
	}

	return res;

	f32 badcompiler[3];
}

/*
 * --INFO--
 * Address:	800A0010
 * Size:	000048
 */
PathFinder* RouteMgr::getPathFinder(u32 handle)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		return mPathFinders[idx];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	800A0058
 * Size:	0000B0
 */
void RouteMgr::update()
{
	PathFinder* path = getPathFinder('test');
	if (path) {
		path->updateASync();
	}
}

/*
 * --INFO--
 * Address:	800A0108
 * Size:	00004C
 */
int RouteMgr::getNumWayPoints(u32 handle)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		return mGroupList[idx].mNumPoints;
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800A0154
 * Size:	0003B8
 */
Vector3f RouteMgr::getSafePosition(u32, Vector3f& pos)
{
	CollTriInfo* tri = mapMgr->getCurrTri(pos.x, pos.z, true);
	bool water       = false;
	if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
		f32 max = mapMgr->getMaxY(pos.x, pos.z, false);
		f32 min = mapMgr->getMinY(pos.x, pos.z, true);
		if (max <= min && pos.y <= min) {
			PRINT("minY = %.1f < %.1f < %.1f = maxY\n", min, pos.y, max);
			water = true;
		}
	}

	WayPoint* wp;
	WayPoint* wp2;
	findNearestEdgeAvoidOff(&wp, &wp2, 'test', pos, false, true, water);

	if (!wp || !wp2) {
		PRINT("from=%x to=%x pos(%.1f %.1f %.1f)\n", wp, wp2, pos.x, pos.y, pos.z);
		ERROR("getSafePos (%.1f %.1f %.1f)", pos.x, pos.y, pos.z);
	}

	PRINT("getSafePos (%d-%d)\n", wp->mIndex, wp2->mIndex);

	Vector3f sep = wp2->mPosition - wp->mPosition;
	Vector3f dir = sep;
	f32 nrm      = dir.normalise();
	f32 dp       = dir.DP(pos - wp->mPosition) / nrm;
	f32 a        = (1.0f - dp) * wp->mRadius + dp * wp2->mRadius;
	Vector3f mod;
	mod     = (dp * nrm) * dir + wp->mPosition;
	mod     = mod - pos;
	mod.y   = 0.0f;
	f32 len = mod.length() - a;

	if (len > 0.0f || dp < 0.0f || dp > 1.0f) {
		if (dp < 0.0f) {
			dp = 0.0f;
		} else if (dp > 1.0f) {
			dp = 1.0f;
		}
		pos   = wp->mPosition + dp * sep;
		pos.y = mapMgr->getMinY(pos.x, pos.z, true);
	}

	return pos;
}

/*
 * --INFO--
 * Address:	800A050C
 * Size:	000474
 */
void RouteMgr::findNearestEdge(WayPoint** outWP1, WayPoint** outWP2, u32 handle, Vector3f& pos, bool p5, bool p6, bool p7)
{
	int idx = id2idx(handle);
	if (idx == -1) {
		*outWP1 = nullptr;
		*outWP2 = nullptr;
		return;
	}

	WayPoint* wp1 = nullptr;
	WayPoint* wp2 = nullptr;
	f32 minDist   = 128000.0f;

	for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
		WayPoint* wp = &mGroupList[idx].mWayPoints[i];
		if ((p5 || !p7 || wp->inWater()) && (p7 || !p5 || !wp->inWater()) && (!p6 || wp->mIsOpen) && (!p7 || !(wp->_40 & 4))) {
			for (int j = 0; j < 8; j++) {
				if (wp->mLinkIndices[j] == -1) {
					continue;
				}
				WayPoint* wpLink = &mGroupList[idx].mWayPoints[wp->mLinkIndices[j]];
				if ((!p5 || !p7 || wpLink->inWater()) && (p7 || !p5 || !wpLink->inWater()) && (!p6 || wpLink->mIsOpen)) {
					Vector3f sep = wpLink->mPosition - wp->mPosition;
					Vector3f dir = sep;
					f32 nrm      = dir.normalise();
					f32 a        = dir.DP(pos - wp->mPosition) / nrm;
					f32 dist;
					if (a < 0.0f || a > 1.0f) {
						Vector3f newDir = wp->mPosition - pos;
						f32 distWP      = newDir.length();
						newDir          = wpLink->mPosition - pos;
						f32 distLink    = newDir.length();
						if (distLink < distWP) {
							dist = distLink;
						} else {
							dist = distWP;
						}
					} else {
						Vector3f newDir;
						newDir = (a * nrm) * dir + wp->mPosition;
						newDir = newDir - pos;
						f32 b  = (1.0f - a) * wp->mRadius + a * wpLink->mRadius;
						dist   = newDir.normalise() - b;
					}

					if (minDist > dist) {
						wp1     = wp;
						wp2     = wpLink;
						minDist = dist;
					}
				}
			}
		}
	}

	*outWP1 = wp1;
	*outWP2 = wp2;
}

/*
 * --INFO--
 * Address:	800A0980
 * Size:	000768
 */
void RouteMgr::findNearestEdgeAvoidOff(WayPoint** outWP1, WayPoint** outWP2, u32 handle, Vector3f& pos, bool p5, bool p6, bool p7)
{
	int idx = id2idx(handle);
	if (idx == -1) {
		*outWP1 = nullptr;
		*outWP2 = nullptr;
		return;
	}

	WayPoint* wpOff = findNearestOffWayPoint(handle, pos, p5);
	if (!wpOff) {
		findNearestEdge(outWP1, outWP2, handle, pos, p5, p6, p7);
		return;
	}

	Plane offPlane;
	createOffPlane(handle, offPlane, wpOff);
	bool isPosAbovePlane = !!(offPlane.dist(pos) >= 0.0f ? 1 : 0); // utterly ridiculous

	WayPoint* wp1 = nullptr;
	WayPoint* wp2 = nullptr;
	f32 minDist   = 128000.0f;

	for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
		WayPoint* wp = &mGroupList[idx].mWayPoints[i];
		if ((p5 || !p7 || wp->inWater()) && (p7 || !p5 || !wp->inWater()) && (!p7 || !(wp->_40 & 4)) && (!p6 || wp->mIsOpen)) {
			for (int j = 0; j < 8; j++) {
				if (wp->mLinkIndices[j] == -1) {
					continue;
				}

				WayPoint* wpLink = &mGroupList[idx].mWayPoints[wp->mLinkIndices[j]];
				if ((!p5 || !p7 || wpLink->inWater()) && (p7 || !p5 || !wpLink->inWater()) && (!p6 || wpLink->mIsOpen)) {

					bool isWPAbovePlane   = !!(offPlane.dist(wp->mPosition) >= 0.0f ? 1 : 0);
					bool isLinkAbovePlane = !!(offPlane.dist(wpLink->mPosition) >= 0.0f ? 1 : 0);
					bool isOffInWPLinks   = false;
					bool isOffInLinkLinks = false;
					for (int k = 0; k < 8; k++) {
						if (wp->mLinkIndices[k] == wpOff->mIndex) {
							isOffInWPLinks = true;
						}
						if (wpLink->mLinkIndices[k] == wpOff->mIndex) {
							isOffInLinkLinks = true;
						}
					}

					if ((!isOffInWPLinks || isWPAbovePlane == isPosAbovePlane)
					    && (!isOffInLinkLinks || isLinkAbovePlane == isPosAbovePlane)) {
						Vector3f sep = wpLink->mPosition - wp->mPosition;
						Vector3f dir = sep;
						f32 nrm      = dir.normalise();
						f32 a        = dir.DP(pos - wp->mPosition) / nrm;
						f32 dist;
						if (a < 0.0f || a > 1.0f) {
							Vector3f newDir = wp->mPosition - pos;
							f32 distWP      = newDir.length();
							newDir          = wpLink->mPosition - pos;
							f32 distLink    = newDir.length();
							if (distLink < distWP) {
								dist = distLink;
							} else {
								dist = distWP;
							}
						} else {
							Vector3f newDir;
							newDir = (a * nrm) * dir + wp->mPosition;
							newDir = newDir - pos;
							f32 b  = (1.0f - a) * wp->mRadius + a * wpLink->mRadius;
							dist   = newDir.normalise() - b;
						}

						if (minDist > dist) {
							wp1     = wp;
							wp2     = wpLink;
							minDist = dist;
						}
					}
				}
			}
		}
	}

	*outWP1 = wp1;
	*outWP2 = wp2;
}

/*
 * --INFO--
 * Address:	800A10E8
 * Size:	00016C
 */
WayPoint* RouteMgr::findNearestWayPoint(u32 handle, Vector3f& pos, bool p3)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		f32 minDist = 128000.0f;
		int wpIdx   = -1;
		for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
			WayPoint* wp = &mGroupList[idx].mWayPoints[i];
			if ((!p3 || !wp->inWater()) && mGroupList[idx].mWayPoints[i].mIsOpen) {
				Vector3f dir(mGroupList[idx].mWayPoints[i].mPosition);
				dir      = dir - pos;
				f32 dist = dir.length();
				if (minDist > dist) {
					minDist = dist;
					wpIdx   = i;
				}
			}
		}

		return &mGroupList[idx].mWayPoints[wpIdx];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	800A1254
 * Size:	00016C
 */
WayPoint* RouteMgr::findNearestOffWayPoint(u32 handle, Vector3f& pos, bool p3)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		f32 minDist = 128000.0f;
		int wpIdx   = -1;
		for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
			WayPoint* wp = &mGroupList[idx].mWayPoints[i];
			if ((!p3 || !wp->inWater()) && !mGroupList[idx].mWayPoints[i].mIsOpen) {
				Vector3f dir(mGroupList[idx].mWayPoints[i].mPosition);
				dir      = dir - pos;
				f32 dist = dir.length();
				if (minDist > dist) {
					minDist = dist;
					wpIdx   = i;
				}
			}
		}

		return &mGroupList[idx].mWayPoints[wpIdx];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	800A13C0
 * Size:	00017C
 */
void RouteMgr::createOffPlane(u32 handle, Plane& plane, WayPoint* wp)
{
	int idx = id2idx(handle);
	if (idx != -1 && wp->mLinkCount > 0) {
		int otherIdx = -1;
		for (int i = 0; i < 8; i++) {
			if (wp->mLinkIndices[i] != -1) {
				otherIdx = wp->mLinkIndices[i];
				break;
			}
		}

		if (otherIdx != -1) {
			Vector3f normal = mGroupList[idx].mWayPoints[otherIdx].mPosition - wp->mPosition;
			normal.normalise();
			plane.mNormal = normal;
			plane.mOffset = normal.DP(wp->mPosition);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void RouteMgr::dump(u32 handle)
{
	int idx = id2idx(handle);
	int num = mGroupList[idx].mNumPoints;
	ID32 id(handle);
	PRINT("--------- route info (%s) ---------\n", id.mStringID);
	for (int i = 0; i < num; i++) {
		PRINT("\t%d : %s\n", i, mGroupList[idx].mWayPoints[i].mIsOpen ? "o" : "x");
	}
	PRINT("----------------------------------------\n");
}

/*
 * --INFO--
 * Address:	800A153C
 * Size:	00013C
 */
WayPoint* RouteMgr::findNearestWayPointAll(u32 handle, Vector3f& pos)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		f32 minDist = 128000.0f;
		int wpIdx   = -1;
		for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
			Vector3f dir(mGroupList[idx].mWayPoints[i].mPosition);
			dir      = dir - pos;
			f32 dist = dir.length();
			if (minDist > dist) {
				minDist = dist;
				wpIdx   = i;
			}
		}

		return &mGroupList[idx].mWayPoints[wpIdx];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	800A1678
 * Size:	00005C
 */
WayPoint* RouteMgr::getWayPoint(u32 handle, int wpIdx)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		return &mGroupList[idx].mWayPoints[wpIdx];
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	800A16D4
 * Size:	00009C
 */
RouteMgr::RouteMgr()
{
	mRouteCount    = 0;
	mGroupList     = nullptr;
	mPathFinders   = nullptr;
	mRouteGroupIDs = 0;
}

/*
 * --INFO--
 * Address:	800A1770
 * Size:	000014
 */
void WayPoint::setFlag(bool flag)
{
	mIsOpen             = flag;
	mRoutePoint->mState = flag;
}

/*
 * --INFO--
 * Address:	800A1784
 * Size:	000274
 */
void RouteMgr::construct(MapMgr* map)
{
	mRouteCount = map->_60->mRouteGroup.getChildCount();
	if (!mRouteCount) {
		PRINT("no routes set\n");
		return;
	}

	mRouteGroupIDs         = new u32[mRouteCount];
	mGroupList             = new RouteMgr::Group[mRouteCount];
	mPathFinders           = new PathFinder*[mRouteCount];
	RouteGroup* routeGroup = static_cast<RouteGroup*>(map->_60->mRouteGroup.mChild);
	for (int i = 0; i < mRouteCount; i++) {
		Group& group      = mGroupList[i];
		mRouteGroupIDs[i] = routeGroup->mIntID;
		group.mNumPoints  = routeGroup->mPointListRoot.getChildCount();
		group.mWayPoints  = new WayPoint[group.mNumPoints];

		RoutePoint* point = static_cast<RoutePoint*>(routeGroup->mPointListRoot.mChild);
		mPathFinders[i]   = new PathFinder(group);

		for (int j = 0; j < group.mNumPoints; j++) {
			WayPoint* wp     = &group.mWayPoints[j];
			wp->mIsOpen      = true;
			wp->mIndex       = j;
			wp->mPosition    = point->mPosition;
			wp->_40          = 0;
			CollTriInfo* tri = map->getCurrTri(wp->mPosition.x, wp->mPosition.z, true);
			if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
				wp->_40 |= 1;
			}
			wp->mRadius     = point->mRadius;
			wp->mRoutePoint = point;
			int linkCount   = point->mLink.getChildCount();
			if (linkCount > 8) {
				PRINT("too may links !\n");
				ERROR("mail to colin@nintendo.co.jp\n");
			}

			wp->mLinkCount  = linkCount;
			RouteLink* link = static_cast<RouteLink*>(point->mLink.mChild);
			for (int k = 0; k < 8; k++) {
				if (linkCount <= k) {
					wp->mLinkIndices[k] = -1;
				} else {
					wp->mLinkIndices[k] = getColinIndex(routeGroup, link->mPoint);
					link                = static_cast<RouteLink*>(link->mNext);
				}
			}

			point = static_cast<RoutePoint*>(point->mNext);
		}
		routeGroup = static_cast<RouteGroup*>(routeGroup->mNext);
	}
}

/*
 * --INFO--
 * Address:	800A1A0C
 * Size:	000134
 */
void RouteMgr::initLinks()
{
	// this gsys stuff isn't in the DLL
	bool check = gsys->_2A4;
	gsys->_2A4 = 0;

	int numWPs = getNumWayPoints('test');
	PRINT("total %d links\n", numWPs);
	int i;
	for (i = 0; i < numWPs; i++) {
		WayPoint* wp = getWayPoint('test', i);
		wp->resetLinkInfos();
	}

	for (i = 0; i < numWPs; i++) {
		WayPoint* wp = getWayPoint('test', i);
		wp->initLinkInfos();
	}

	// same with this stuff
	gsys->_2A4 = check;
	gsys->_2A0 = 0;
}

/*
 * --INFO--
 * Address:	800A1B40
 * Size:	000048
 */
int RouteMgr::id2idx(u32 id)
{
	if (!mRouteGroupIDs) {
		return -1;
	}

	for (int i = 0; i < mRouteCount; i++) {
		if (mRouteGroupIDs[i] == id) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
u32 RouteMgr::idx2id(int idx)
{
	return mRouteGroupIDs[idx];
}

/*
 * --INFO--
 * Address:	800A1B88
 * Size:	00002C
 */
int RouteMgr::getColinIndex(RouteGroup* group, RoutePoint* point)
{
	int idx               = 0;
	RoutePoint* currPoint = static_cast<RoutePoint*>(group->mPointListRoot.mChild);
	while (currPoint) {
		if (currPoint == point) {
			return idx;
		}

		currPoint = static_cast<RoutePoint*>(currPoint->mNext);
		idx++;
	}

	return -1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
RouteTracer::RouteTracer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
RouteTracer::Context::PointInfo::PointInfo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000764
 */
void RouteTracer::render(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000278
 */
void RouteTracer::Context::makeContext(RouteTracer*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002EC
 */
void RouteTracer::Context::setTarget(RouteTracer*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000224
 */
int RouteTracer::Context::recognise(RouteTracer*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
bool RouteTracer::noLink()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void RouteTracer::startConsult(Creature*, PathFinder*, PathFinder::Buffer*, int, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000364
 */
void RouteTracer::updateState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
Vector3f RouteTracer::getTarget()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
int WayPoint::getLinkIndex(int idx)
{
	for (int i = 0; i < 8; i++) {
		if (mLinkIndices[i] == idx) {
			return i;
		}
	}
	return -1;
}

/*
 * --INFO--
 * Address:	800A1BB4
 * Size:	000090
 */
void WayPoint::resetLinkInfos()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			LinkInfo* info = &mLinkInfos[i];
			info->setInfo(j, -2);
		}
	}
}

/*
 * --INFO--
 * Address:	800A1C44
 * Size:	0003BC
 */
void WayPoint::initLinkInfos()
{
	PathFinder::setMode(PFMODE_Unk2);
	PathFinder::avoidWayPointIndex = mIndex;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stfd      f29, 0xC8(r1)
	  stmw      r17, 0x8C(r1)
	  mr        r18, r3
	  addi      r25, r18, 0
	  mr        r24, r18
	  li        r23, 0
	  lis       r31, 0x7465
	  lhz       r0, 0x3028(r13)
	  lfs       f29, -0x72CC(r2)
	  ori       r0, r0, 0x2
	  lfd       f30, -0x72C0(r2)
	  sth       r0, 0x3028(r13)
	  lfd       f31, -0x72B8(r2)
	  lwz       r0, 0x10(r3)
	  stw       r0, -0x53C8(r13)

	.loc_0x50:
	  lwz       r0, 0x14(r24)
	  addi      r3, r25, 0x44
	  cmpwi     r0, -0x1
	  bne-      .loc_0x78
	  li        r0, -0x2
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)
	  b         .loc_0x380

	.loc_0x78:
	  addi      r27, r3, 0
	  li        r22, 0
	  li        r26, 0

	.loc_0x84:
	  cmpwi     r22, 0x3
	  li        r17, -0x1
	  beq-      .loc_0xBC
	  bge-      .loc_0xD0
	  cmpwi     r22, 0
	  bge-      .loc_0xA0
	  b         .loc_0xD0

	.loc_0xA0:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r22
	  bl        0x50CCC
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  lha       r17, 0x42A(r3)
	  b         .loc_0xD0

	.loc_0xBC:
	  lwz       r3, 0x30AC(r13)
	  bl        0x50F34
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  lwz       r17, 0x558(r3)

	.loc_0xD0:
	  cmpwi     r17, -0x1
	  beq-      .loc_0x364
	  lwz       r19, 0x302C(r13)
	  addi      r4, r31, 0x7374
	  lwz       r20, 0x14(r24)
	  mr        r3, r19
	  bl        -0x1EC
	  cmpwi     r3, -0x1
	  beq-      .loc_0x104
	  lwz       r4, 0x24(r19)
	  rlwinm    r0,r3,2,0,29
	  lwzx      r30, r4, r0
	  b         .loc_0x108

	.loc_0x104:
	  li        r30, 0

	.loc_0x108:
	  lwz       r4, 0x8(r30)
	  mr        r3, r30
	  addi      r5, r20, 0
	  addi      r6, r17, 0
	  li        r7, 0x1
	  bl        -0x2190
	  cmpwi     r3, 0
	  bne-      .loc_0x134
	  li        r0, -0x2
	  stw       r0, 0x0(r27)
	  b         .loc_0x36C

	.loc_0x134:
	  subi      r21, r3, 0x1
	  rlwinm    r28,r21,3,0,28
	  li        r20, 0
	  b         .loc_0x358

	.loc_0x144:
	  lwz       r0, 0x8(r30)
	  cmpwi     r21, 0
	  add       r3, r0, r28
	  lwz       r19, 0x0(r3)
	  bne-      .loc_0x160
	  lwz       r17, 0x10(r18)
	  b         .loc_0x164

	.loc_0x160:
	  lwz       r17, -0x8(r3)

	.loc_0x164:
	  lwz       r29, 0x302C(r13)
	  addi      r4, r31, 0x7374
	  addi      r3, r29, 0
	  bl        -0x274
	  cmpwi     r3, -0x1
	  beq-      .loc_0x194
	  lwz       r4, 0x20(r29)
	  rlwinm    r3,r3,3,0,28
	  mulli     r0, r17, 0xC4
	  lwzx      r3, r4, r3
	  add       r29, r3, r0
	  b         .loc_0x198

	.loc_0x194:
	  li        r29, 0

	.loc_0x198:
	  lwz       r17, 0x302C(r13)
	  addi      r4, r31, 0x7374
	  addi      r3, r17, 0
	  bl        -0x2A8
	  cmpwi     r3, -0x1
	  beq-      .loc_0x1C8
	  lwz       r4, 0x20(r17)
	  rlwinm    r3,r3,3,0,28
	  mulli     r0, r19, 0xC4
	  lwzx      r3, r4, r3
	  add       r3, r3, r0
	  b         .loc_0x1CC

	.loc_0x1C8:
	  li        r3, 0

	.loc_0x1CC:
	  lwz       r0, 0x14(r29)
	  cmpw      r0, r19
	  bne-      .loc_0x1E0
	  li        r0, 0
	  b         .loc_0x288

	.loc_0x1E0:
	  addi      r4, r29, 0x4
	  lwz       r0, 0x18(r29)
	  cmpw      r0, r19
	  bne-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x288

	.loc_0x1F8:
	  lwz       r0, 0x18(r4)
	  addi      r4, r4, 0x4
	  cmpw      r0, r19
	  bne-      .loc_0x210
	  li        r0, 0x2
	  b         .loc_0x288

	.loc_0x210:
	  lwz       r0, 0x18(r4)
	  addi      r4, r4, 0x4
	  cmpw      r0, r19
	  bne-      .loc_0x228
	  li        r0, 0x3
	  b         .loc_0x288

	.loc_0x228:
	  lwz       r0, 0x18(r4)
	  addi      r4, r4, 0x4
	  cmpw      r0, r19
	  bne-      .loc_0x240
	  li        r0, 0x4
	  b         .loc_0x288

	.loc_0x240:
	  lwz       r0, 0x18(r4)
	  addi      r4, r4, 0x4
	  cmpw      r0, r19
	  bne-      .loc_0x258
	  li        r0, 0x5
	  b         .loc_0x288

	.loc_0x258:
	  lwz       r0, 0x18(r4)
	  addi      r4, r4, 0x4
	  cmpw      r0, r19
	  bne-      .loc_0x270
	  li        r0, 0x6
	  b         .loc_0x288

	.loc_0x270:
	  lwz       r0, 0x18(r4)
	  cmpw      r0, r19
	  bne-      .loc_0x284
	  li        r0, 0x7
	  b         .loc_0x288

	.loc_0x284:
	  li        r0, -0x1

	.loc_0x288:
	  lfs       f3, 0x4(r29)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r3)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x8(r29)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x8(r3)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x318
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f2, 0x3C(r1)

	.loc_0x318:
	  rlwinm    r0,r0,4,0,27
	  fctiwz    f0, f2
	  add       r3, r29, r0
	  addi      r4, r3, 0x44
	  add       r4, r26, r4
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x84(r1)
	  cmpwi     r3, 0
	  add       r20, r20, r0
	  blt-      .loc_0x34C
	  cmpw      r3, r20
	  ble-      .loc_0x350

	.loc_0x34C:
	  stw       r20, 0x0(r4)

	.loc_0x350:
	  subi      r28, r28, 0x8
	  subi      r21, r21, 0x1

	.loc_0x358:
	  cmpwi     r21, 0
	  bge+      .loc_0x144
	  b         .loc_0x36C

	.loc_0x364:
	  li        r0, -0x2
	  stw       r0, 0x0(r27)

	.loc_0x36C:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x4
	  blt+      .loc_0x84

	.loc_0x380:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x8
	  addi      r25, r25, 0x10
	  addi      r24, r24, 0x4
	  blt+      .loc_0x50
	  li        r0, 0
	  sth       r0, 0x3028(r13)
	  lmw       r17, 0x8C(r1)
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
int PathFinder::findFirstStepOnyon(int, int, PathFinder::Buffer*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A2000
 * Size:	000580
 */
int PathFinder::findSyncOnyon(Vector3f&, PathFinder::Buffer*, int, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x198(r1)
	  stfd      f31, 0x190(r1)
	  stfd      f30, 0x188(r1)
	  stfd      f29, 0x180(r1)
	  stmw      r18, 0x148(r1)
	  addi      r28, r7, 0
	  cmpwi     r28, 0x3
	  addi      r26, r3, 0
	  addi      r19, r4, 0
	  addi      r27, r5, 0
	  addi      r18, r6, 0
	  addi      r29, r8, 0
	  li        r22, -0x1
	  beq-      .loc_0x6C
	  bge-      .loc_0x80
	  cmpwi     r28, 0
	  bge-      .loc_0x50
	  b         .loc_0x80

	.loc_0x50:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r28
	  bl        0x50960
	  cmplwi    r3, 0
	  beq-      .loc_0x80
	  lha       r22, 0x42A(r3)
	  b         .loc_0x80

	.loc_0x6C:
	  lwz       r3, 0x30AC(r13)
	  bl        0x50BC8
	  cmplwi    r3, 0
	  beq-      .loc_0x80
	  lwz       r22, 0x558(r3)

	.loc_0x80:
	  cmpwi     r22, -0x1
	  bne-      .loc_0x90
	  li        r3, 0
	  b         .loc_0x560

	.loc_0x90:
	  cmpw      r18, r22
	  stw       r18, 0x0(r27)
	  li        r21, 0
	  bne-      .loc_0xA8
	  li        r3, 0x1
	  b         .loc_0x560

	.loc_0xA8:
	  rlwinm    r0,r21,3,0,28
	  stw       r29, 0x8(r1)
	  addi      r3, r26, 0
	  addi      r4, r19, 0
	  addi      r6, r28, 0
	  addi      r8, r22, 0
	  addi      r9, r27, 0
	  addi      r5, r1, 0x134
	  add       r7, r27, r0
	  li        r20, 0
	  li        r19, 0
	  li        r31, 0
	  li        r10, 0
	  bl        0x708
	  addi      r30, r3, 0
	  cmpwi     r30, -0x1
	  li        r0, 0x1
	  lfs       f29, -0x72CC(r2)
	  lfd       f30, -0x72C0(r2)
	  slw       r24, r0, r30
	  lfd       f31, -0x72B8(r2)
	  li        r18, 0
	  b         .loc_0x518

	.loc_0x104:
	  rlwinm    r0,r21,3,0,28
	  lwz       r4, 0x0(r26)
	  add       r23, r27, r0
	  lwz       r3, 0x0(r23)
	  rlwinm.   r0,r19,0,24,31
	  lwz       r4, 0x0(r4)
	  mulli     r0, r3, 0xC4
	  add       r5, r4, r0
	  addi      r19, r5, 0
	  bne-      .loc_0x220
	  li        r0, 0x2
	  mtctr     r0
	  li        r6, 0
	  li        r4, 0x1

	.loc_0x13C:
	  lwz       r0, 0x14(r5)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x15C
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  xor       r0, r3, r0
	  stb       r0, 0x4(r23)
	  b         .loc_0x16C

	.loc_0x15C:
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  or        r0, r3, r0
	  stb       r0, 0x4(r23)

	.loc_0x16C:
	  lwz       r0, 0x18(r5)
	  addi      r5, r5, 0x4
	  addi      r6, r6, 0x1
	  cmpwi     r0, -0x1
	  bne-      .loc_0x194
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  xor       r0, r3, r0
	  stb       r0, 0x4(r23)
	  b         .loc_0x1A4

	.loc_0x194:
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  or        r0, r3, r0
	  stb       r0, 0x4(r23)

	.loc_0x1A4:
	  lwz       r0, 0x18(r5)
	  addi      r5, r5, 0x4
	  addi      r6, r6, 0x1
	  cmpwi     r0, -0x1
	  bne-      .loc_0x1CC
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  xor       r0, r3, r0
	  stb       r0, 0x4(r23)
	  b         .loc_0x1DC

	.loc_0x1CC:
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  or        r0, r3, r0
	  stb       r0, 0x4(r23)

	.loc_0x1DC:
	  lwz       r0, 0x18(r5)
	  addi      r5, r5, 0x4
	  addi      r6, r6, 0x1
	  cmpwi     r0, -0x1
	  bne-      .loc_0x204
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  xor       r0, r3, r0
	  stb       r0, 0x4(r23)
	  b         .loc_0x214

	.loc_0x204:
	  lbz       r3, 0x4(r23)
	  slw       r0, r4, r6
	  or        r0, r3, r0
	  stb       r0, 0x4(r23)

	.loc_0x214:
	  addi      r5, r5, 0x4
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x13C

	.loc_0x220:
	  addi      r3, r26, 0
	  addi      r4, r31, 0
	  addi      r5, r28, 0
	  addi      r6, r23, 0
	  addi      r7, r22, 0
	  addi      r8, r27, 0
	  addi      r9, r21, 0
	  addi      r10, r29, 0
	  bl        .loc_0x580
	  rlwinm.   r0,r18,0,24,31
	  beq-      .loc_0x2FC
	  lwz       r0, 0x134(r1)
	  cmpw      r31, r0
	  ble-      .loc_0x2FC
	  cmpwi     r21, 0
	  mtctr     r21
	  ble-      .loc_0x2CC

	.loc_0x264:
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x1
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x2
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x4
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x8
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x10
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x20
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x40
	  stb       r0, 0x4(r23)
	  lbz       r0, 0x4(r23)
	  ori       r0, r0, 0x80
	  stb       r0, 0x4(r23)
	  subi      r23, r23, 0x8
	  bdnz+     .loc_0x264

	.loc_0x2CC:
	  lwz       r4, 0x0(r26)
	  mr        r3, r30
	  lwz       r0, 0x0(r27)
	  li        r21, 0
	  lwz       r5, 0x0(r4)
	  mulli     r4, r0, 0xC4
	  lbz       r0, 0x4(r27)
	  xor       r0, r0, r24
	  add       r4, r5, r4
	  stb       r0, 0x4(r27)
	  addi      r19, r4, 0
	  li        r18, 0

	.loc_0x2FC:
	  cmpwi     r3, -0x1
	  beq-      .loc_0x42C
	  rlwinm    r4,r3,2,0,29
	  lwz       r5, 0x0(r26)
	  addi      r6, r4, 0x14
	  lfs       f3, 0x4(r19)
	  add       r6, r19, r6
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x0(r6)
	  lfs       f1, 0x0(r19)
	  mulli     r0, r0, 0xC4
	  lfs       f4, 0x8(r19)
	  add       r4, r4, r0
	  lfs       f2, 0x4(r4)
	  lfs       f0, 0x0(r4)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x8(r4)
	  fsubs     f1, f1, f0
	  fsubs     f2, f4, f2
	  fmuls     f0, f3, f3
	  fmuls     f1, f1, f1
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x3B4
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0xCC(r1)
	  lfs       f2, 0xCC(r1)

	.loc_0x3B4:
	  fctiwz    f0, f2
	  lwz       r6, 0x0(r6)
	  cmpw      r6, r22
	  stfd      f0, 0x140(r1)
	  lwz       r0, 0x144(r1)
	  add       r31, r31, r0
	  bne-      .loc_0x3E4
	  addi      r21, r21, 0x1
	  rlwinm    r0,r21,3,0,28
	  stwx      r22, r27, r0
	  li        r20, 0x1
	  b         .loc_0x520

	.loc_0x3E4:
	  rlwinm    r4,r21,3,0,28
	  addi      r5, r4, 0x4
	  li        r0, 0x1
	  lbzx      r4, r27, r5
	  slw       r0, r0, r3
	  xor       r0, r4, r0
	  stbx      r0, r27, r5
	  addi      r21, r21, 0x1
	  lwz       r0, 0x4(r26)
	  cmpw      r21, r0
	  blt-      .loc_0x41C
	  li        r19, 0x1
	  subi      r21, r21, 0x1
	  b         .loc_0x518

	.loc_0x41C:
	  rlwinm    r0,r21,3,0,28
	  stwx      r6, r27, r0
	  li        r19, 0
	  b         .loc_0x518

	.loc_0x42C:
	  cmpwi     r21, 0x1
	  li        r19, 0x1
	  blt-      .loc_0x500
	  rlwinm    r0,r21,3,0,28
	  lwz       r4, 0x0(r26)
	  add       r5, r27, r0
	  lwz       r3, -0x8(r5)
	  lwz       r0, 0x0(r5)
	  mulli     r3, r3, 0xC4
	  lwz       r4, 0x0(r4)
	  add       r3, r4, r3
	  mulli     r0, r0, 0xC4
	  lfs       f2, 0x4(r3)
	  lfs       f0, 0x0(r3)
	  lfs       f4, 0x8(r3)
	  add       r3, r4, r0
	  lfs       f3, 0x4(r3)
	  lfs       f1, 0x0(r3)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f1, f1, f0
	  fsubs     f2, f2, f4
	  fmuls     f0, f3, f3
	  fmuls     f1, f1, f1
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x4F0
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f2, 0xC0(r1)

	.loc_0x4F0:
	  fctiwz    f0, f2
	  stfd      f0, 0x140(r1)
	  lwz       r0, 0x144(r1)
	  sub       r31, r31, r0

	.loc_0x500:
	  rlwinm    r0,r21,3,0,28
	  li        r3, -0x1
	  subic.    r21, r21, 0x1
	  stwx      r3, r27, r0
	  bge-      .loc_0x518
	  li        r20, 0x2

	.loc_0x518:
	  cmpwi     r20, 0
	  beq+      .loc_0x104

	.loc_0x520:
	  cmpwi     r20, 0x1
	  bne-      .loc_0x55C
	  cmpwi     r21, 0
	  addi      r3, r21, 0x1
	  blt-      .loc_0x554
	  rlwinm.   r0,r3,29,3,31
	  mtctr     r0
	  beq-      .loc_0x54C

	.loc_0x540:
	  bdnz-     .loc_0x540
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x554

	.loc_0x54C:
	  mtctr     r3

	.loc_0x550:
	  bdnz-     .loc_0x550

	.loc_0x554:
	  addi      r3, r21, 0x1
	  b         .loc_0x560

	.loc_0x55C:
	  li        r3, 0

	.loc_0x560:
	  lmw       r18, 0x148(r1)
	  lwz       r0, 0x19C(r1)
	  lfd       f31, 0x190(r1)
	  lfd       f30, 0x188(r1)
	  lfd       f29, 0x180(r1)
	  addi      r1, r1, 0x198
	  mtlr      r0
	  blr

	.loc_0x580:
	*/
}

/*
 * --INFO--
 * Address:	800A2580
 * Size:	000264
 */
int PathFinder::selectWayOnyon(int, int, PathFinder::Buffer&, int, PathFinder::Buffer*, int, bool)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x168(r1)
	  li        r11, 0
	  addi      r12, r11, 0
	  stmw      r22, 0x140(r1)
	  addi      r25, r1, 0x100
	  addi      r26, r1, 0x120
	  addi      r31, r25, 0
	  addi      r30, r26, 0
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r10,0,24,31
	  li        r24, -0x1
	  li        r23, 0
	  li        r22, 0

	.loc_0x34:
	  li        r4, 0x1
	  lbz       r10, 0x4(r6)
	  slw       r28, r4, r22
	  and.      r4, r10, r28
	  beq-      .loc_0x140
	  lwz       r10, 0x0(r6)
	  lhz       r4, 0x3028(r13)
	  lwz       r27, 0x0(r3)
	  mulli     r29, r10, 0xC4
	  lwz       r27, 0x0(r27)
	  rlwinm.   r4,r4,0,31,31
	  add       r4, r27, r29
	  beq-      .loc_0x74
	  lbz       r29, 0x40(r4)
	  rlwinm.   r29,r29,0,31,31
	  bne-      .loc_0x140

	.loc_0x74:
	  addi      r29, r11, 0x14
	  lwzx      r29, r4, r29
	  cmpw      r29, r10
	  beq-      .loc_0x140
	  cmpwi     r29, -0x1
	  bne-      .loc_0x9C
	  lbz       r4, 0x4(r6)
	  xor       r4, r4, r28
	  stb       r4, 0x4(r6)
	  b         .loc_0x140

	.loc_0x9C:
	  cmplwi    r0, 0
	  bne-      .loc_0xC8
	  mulli     r10, r29, 0xC4
	  addi      r10, r10, 0x38
	  lbzx      r10, r27, r10
	  cmplwi    r10, 0
	  bne-      .loc_0xC8
	  lbz       r4, 0x4(r6)
	  xor       r4, r4, r28
	  stb       r4, 0x4(r6)
	  b         .loc_0x140

	.loc_0xC8:
	  cmpwi     r9, 0
	  mtctr     r9
	  addi      r27, r8, 0
	  li        r28, 0
	  ble-      .loc_0xF8

	.loc_0xDC:
	  lwz       r10, 0x0(r27)
	  cmpw      r29, r10
	  bne-      .loc_0xF0
	  li        r28, 0x1
	  b         .loc_0xF8

	.loc_0xF0:
	  addi      r27, r27, 0x8
	  bdnz+     .loc_0xDC

	.loc_0xF8:
	  add       r4, r4, r12
	  addi      r10, r4, 0x44
	  add       r10, r5, r10
	  lwz       r4, 0x0(r10)
	  cmpwi     r4, -0x2
	  beq-      .loc_0x140
	  rlwinm.   r4,r28,0,24,31
	  bne-      .loc_0x140
	  cmpw      r29, r7
	  stw       r22, 0x0(r31)
	  bne-      .loc_0x12C
	  mr        r3, r22
	  b         .loc_0x258

	.loc_0x12C:
	  lwz       r4, 0x0(r10)
	  addi      r31, r31, 0x4
	  addi      r23, r23, 0x1
	  stw       r4, 0x0(r30)
	  addi      r30, r30, 0x4

	.loc_0x140:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x8
	  addi      r11, r11, 0x4
	  addi      r12, r12, 0x10
	  blt+      .loc_0x34
	  cmpwi     r23, 0
	  mtctr     r23
	  lis       r4, 0x2
	  subi      r4, r4, 0xC00
	  ble-      .loc_0x188

	.loc_0x168:
	  lwz       r0, 0x0(r26)
	  cmpw      r0, r4
	  bge-      .loc_0x17C
	  mr        r4, r0
	  lwz       r24, 0x0(r25)

	.loc_0x17C:
	  addi      r26, r26, 0x4
	  addi      r25, r25, 0x4
	  bdnz+     .loc_0x168

	.loc_0x188:
	  cmpwi     r24, -0x1
	  beq-      .loc_0x254
	  lwz       r4, 0x0(r6)
	  rlwinm    r0,r24,2,0,29
	  lwz       r5, 0x0(r3)
	  mulli     r3, r4, 0xC4
	  lfs       f0, -0x72CC(r2)
	  lwz       r5, 0x0(r5)
	  add       r4, r5, r3
	  add       r3, r4, r0
	  lfs       f3, 0x4(r4)
	  lwz       r0, 0x14(r3)
	  lfs       f1, 0x0(r4)
	  mulli     r0, r0, 0xC4
	  lfs       f5, 0x8(r4)
	  add       r3, r5, r0
	  lfs       f4, 0x4(r3)
	  lfs       f2, 0x0(r3)
	  fsubs     f4, f4, f3
	  lfs       f3, 0x8(r3)
	  fsubs     f2, f2, f1
	  fsubs     f3, f3, f5
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x254
	  fsqrte    f1, f4
	  lfd       f3, -0x72C0(r2)
	  lfd       f2, -0x72B8(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x8C(r1)

	.loc_0x254:
	  mr        r3, r24

	.loc_0x258:
	  lmw       r22, 0x140(r1)
	  addi      r1, r1, 0x168
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A27E4
 * Size:	00052C
 */
int PathFinder::selectSecondBestWayOnyon(Vector3f&, int&, int, PathFinder::Buffer&, int, PathFinder::Buffer*, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r11, 0
	  stw       r0, 0x4(r1)
	  rlwinm    r6,r6,2,0,29
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  lbz       r0, 0x203(r1)
	  stmw      r19, 0x1BC(r1)
	  addi      r31, r1, 0x198
	  addi      r24, r3, 0
	  addi      r26, r5, 0
	  addi      r30, r1, 0x178
	  addi      r27, r7, 0
	  addi      r25, r4, 0
	  addi      r5, r11, 0
	  addi      r7, r30, 0
	  addi      r12, r31, 0
	  li        r29, -0x1
	  li        r28, 0
	  li        r3, 0

	.loc_0x50:
	  li        r4, 0x1
	  lbz       r19, 0x4(r27)
	  slw       r21, r4, r3
	  and.      r4, r19, r21
	  beq-      .loc_0x158
	  lwz       r22, 0x0(r27)
	  lhz       r4, 0x3028(r13)
	  lwz       r20, 0x0(r24)
	  mulli     r19, r22, 0xC4
	  lwz       r20, 0x0(r20)
	  rlwinm.   r4,r4,0,31,31
	  add       r4, r20, r19
	  beq-      .loc_0x90
	  lbz       r19, 0x40(r4)
	  rlwinm.   r19,r19,0,31,31
	  bne-      .loc_0x158

	.loc_0x90:
	  addi      r19, r11, 0x14
	  lwzx      r23, r4, r19
	  cmpw      r23, r22
	  beq-      .loc_0x158
	  cmpwi     r23, -0x1
	  bne-      .loc_0xB8
	  lbz       r4, 0x4(r27)
	  xor       r4, r4, r21
	  stb       r4, 0x4(r27)
	  b         .loc_0x158

	.loc_0xB8:
	  cmplwi    r0, 0
	  bne-      .loc_0xE4
	  mulli     r19, r23, 0xC4
	  addi      r19, r19, 0x38
	  lbzx      r19, r20, r19
	  cmplwi    r19, 0
	  bne-      .loc_0xE4
	  lbz       r4, 0x4(r27)
	  xor       r4, r4, r21
	  stb       r4, 0x4(r27)
	  b         .loc_0x158

	.loc_0xE4:
	  cmpwi     r10, 0
	  mtctr     r10
	  addi      r20, r9, 0
	  li        r21, 0
	  ble-      .loc_0x114

	.loc_0xF8:
	  lwz       r19, 0x0(r20)
	  cmpw      r23, r19
	  bne-      .loc_0x10C
	  li        r21, 0x1
	  b         .loc_0x114

	.loc_0x10C:
	  addi      r20, r20, 0x8
	  bdnz+     .loc_0xF8

	.loc_0x114:
	  add       r4, r4, r5
	  addi      r19, r4, 0x44
	  add       r19, r6, r19
	  lwz       r4, 0x0(r19)
	  cmpwi     r4, -0x2
	  beq-      .loc_0x158
	  rlwinm.   r4,r21,0,24,31
	  bne-      .loc_0x158
	  cmpw      r23, r8
	  stw       r3, 0x0(r7)
	  bne-      .loc_0x144
	  b         .loc_0x514

	.loc_0x144:
	  lwz       r4, 0x0(r19)
	  addi      r7, r7, 0x4
	  addi      r28, r28, 0x1
	  stw       r4, 0x0(r12)
	  addi      r12, r12, 0x4

	.loc_0x158:
	  addi      r3, r3, 0x1
	  cmpwi     r3, 0x8
	  addi      r11, r11, 0x4
	  addi      r5, r5, 0x10
	  blt+      .loc_0x50
	  cmpwi     r28, 0
	  mtctr     r28
	  lis       r3, 0x2
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  subi      r3, r3, 0xC00
	  ble-      .loc_0x1A8

	.loc_0x188:
	  lwz       r0, 0x0(r4)
	  cmpw      r0, r3
	  bge-      .loc_0x19C
	  mr        r3, r0
	  lwz       r29, 0x0(r5)

	.loc_0x19C:
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x188

	.loc_0x1A8:
	  lis       r3, 0x2
	  subi      r0, r3, 0xC00
	  stw       r0, 0x0(r26)
	  li        r21, -0x1
	  li        r20, 0
	  lfs       f31, -0x72CC(r2)
	  b         .loc_0x508

	.loc_0x1C4:
	  cmpw      r20, r29
	  beq-      .loc_0x4FC
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x0(r26)
	  cmpw      r3, r0
	  bge-      .loc_0x4FC
	  lwz       r3, 0x0(r27)
	  li        r19, 0x1
	  lwz       r5, 0x0(r24)
	  lwz       r0, 0x0(r30)
	  mulli     r4, r3, 0xC4
	  lwz       r5, 0x0(r5)
	  rlwinm    r3,r0,2,0,29
	  add       r23, r5, r4
	  addi      r0, r3, 0x14
	  lbz       r3, 0x38(r23)
	  lwzx      r0, r23, r0
	  cmplwi    r3, 0
	  mulli     r0, r0, 0xC4
	  add       r22, r5, r0
	  lbz       r0, 0x38(r22)
	  bne-      .loc_0x380
	  stfs      f31, 0x148(r1)
	  stfs      f31, 0x144(r1)
	  stfs      f31, 0x140(r1)
	  lfs       f1, 0x0(r22)
	  lfs       f0, 0x0(r23)
	  lfs       f3, 0x4(r22)
	  lfs       f2, 0x4(r23)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r22)
	  lfs       f1, 0x8(r23)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x134(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x138(r1)
	  stfs      f0, 0x13C(r1)
	  lfs       f1, 0x134(r1)
	  lfs       f0, 0x138(r1)
	  lfs       f2, 0x13C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x94E1C
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x2A8
	  lfs       f0, 0x134(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x134(r1)
	  lfs       f0, 0x138(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x138(r1)
	  lfs       f0, 0x13C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x13C(r1)

	.loc_0x2A8:
	  lwz       r0, 0x134(r1)
	  lwz       r3, 0x138(r1)
	  stw       r0, 0x140(r1)
	  lwz       r0, 0x13C(r1)
	  stw       r3, 0x144(r1)
	  lfs       f3, 0x134(r1)
	  stw       r0, 0x148(r1)
	  lfs       f2, 0x0(r23)
	  lfs       f1, 0x138(r1)
	  lfs       f0, 0x4(r23)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x13C(r1)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r23)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14C(r1)
	  lfs       f6, 0x144(r1)
	  lfs       f0, 0x4(r25)
	  lfs       f8, 0x140(r1)
	  lfs       f2, 0x0(r25)
	  fmuls     f3, f6, f0
	  lfs       f1, 0x0(r22)
	  fmuls     f4, f8, f2
	  lfs       f0, 0x4(r22)
	  lfs       f7, 0x148(r1)
	  lfs       f5, 0x8(r25)
	  fmuls     f1, f8, f1
	  fmuls     f0, f6, f0
	  lfs       f2, 0x8(r22)
	  fmuls     f5, f7, f5
	  lfs       f6, 0x14C(r1)
	  fadds     f3, f4, f3
	  fmuls     f2, f7, f2
	  fadds     f3, f5, f3
	  fadds     f0, f1, f0
	  fsubs     f1, f3, f6
	  fadds     f0, f2, f0
	  fcmpu     cr0, f1, f31
	  fsubs     f0, f0, f6
	  mfcr      r0
	  fcmpu     cr0, f0, f31
	  rlwinm    r0,r0,3,31,31
	  xori      r0, r0, 0x1
	  rlwinm    r3,r0,0,24,31
	  mfcr      r0
	  rlwinm    r0,r0,3,31,31
	  xori      r0, r0, 0x1
	  rlwinm    r0,r0,0,24,31
	  cmplw     r3, r0
	  beq-      .loc_0x4E8
	  li        r19, 0
	  b         .loc_0x4E8

	.loc_0x380:
	  cmplwi    r0, 0
	  bne-      .loc_0x4E8
	  stfs      f31, 0x128(r1)
	  stfs      f31, 0x124(r1)
	  stfs      f31, 0x120(r1)
	  lfs       f1, 0x0(r22)
	  lfs       f0, 0x0(r23)
	  lfs       f3, 0x4(r22)
	  lfs       f2, 0x4(r23)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r22)
	  lfs       f1, 0x8(r23)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x114(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x118(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f1, 0x114(r1)
	  lfs       f0, 0x118(r1)
	  lfs       f2, 0x11C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x94F88
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x414
	  lfs       f0, 0x114(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x118(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x11C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x11C(r1)

	.loc_0x414:
	  lwz       r0, 0x114(r1)
	  lwz       r3, 0x118(r1)
	  stw       r0, 0x120(r1)
	  lwz       r0, 0x11C(r1)
	  stw       r3, 0x124(r1)
	  lfs       f3, 0x114(r1)
	  stw       r0, 0x128(r1)
	  lfs       f2, 0x0(r22)
	  lfs       f1, 0x118(r1)
	  lfs       f0, 0x4(r22)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x11C(r1)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r22)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x12C(r1)
	  lfs       f6, 0x124(r1)
	  lfs       f0, 0x4(r25)
	  lfs       f8, 0x120(r1)
	  lfs       f2, 0x0(r25)
	  fmuls     f3, f6, f0
	  lfs       f1, 0x0(r23)
	  fmuls     f4, f8, f2
	  lfs       f0, 0x4(r23)
	  lfs       f7, 0x128(r1)
	  lfs       f5, 0x8(r25)
	  fmuls     f1, f8, f1
	  fmuls     f0, f6, f0
	  lfs       f2, 0x8(r23)
	  fmuls     f5, f7, f5
	  lfs       f6, 0x12C(r1)
	  fadds     f3, f4, f3
	  fmuls     f2, f7, f2
	  fadds     f3, f5, f3
	  fadds     f0, f1, f0
	  fsubs     f1, f3, f6
	  fadds     f0, f2, f0
	  fcmpu     cr0, f1, f31
	  fsubs     f0, f0, f6
	  mfcr      r0
	  fcmpu     cr0, f0, f31
	  rlwinm    r0,r0,3,31,31
	  xori      r0, r0, 0x1
	  rlwinm    r3,r0,0,24,31
	  mfcr      r0
	  rlwinm    r0,r0,3,31,31
	  xori      r0, r0, 0x1
	  rlwinm    r0,r0,0,24,31
	  cmplw     r3, r0
	  beq-      .loc_0x4E8
	  li        r19, 0

	.loc_0x4E8:
	  rlwinm.   r0,r19,0,24,31
	  beq-      .loc_0x4FC
	  lwz       r0, 0x0(r31)
	  mr        r21, r20
	  stw       r0, 0x0(r26)

	.loc_0x4FC:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x4
	  addi      r20, r20, 0x1

	.loc_0x508:
	  cmpw      r20, r28
	  blt+      .loc_0x1C4
	  mr        r3, r21

	.loc_0x514:
	  lmw       r19, 0x1BC(r1)
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A2D10
 * Size:	000134
 */
void RouteMgr::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0xFF
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  addi      r27, r4, 0
	  addi      r26, r3, 0
	  addi      r4, r1, 0x10
	  addi      r3, r27, 0
	  stb       r0, 0x10(r1)
	  stb       r0, 0x11(r1)
	  stb       r0, 0x12(r1)
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r29, 0
	  li        r30, 0
	  lis       r31, 0x7465
	  b         .loc_0xEC

	.loc_0x90:
	  addi      r3, r26, 0
	  addi      r4, r31, 0x7374
	  bl        -0x1268
	  cmpwi     r3, -0x1
	  beq-      .loc_0xB8
	  lwz       r4, 0x20(r26)
	  rlwinm    r0,r3,3,0,28
	  lwzx      r0, r4, r0
	  add       r0, r0, r30
	  b         .loc_0xBC

	.loc_0xB8:
	  li        r0, 0

	.loc_0xBC:
	  mr        r28, r0
	  lwz       r3, 0x2E4(r27)
	  lfs       f1, -0x72B0(r2)
	  mr        r4, r28
	  bl        -0x61858
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE4
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        0x278

	.loc_0xE4:
	  addi      r30, r30, 0xC4
	  addi      r29, r29, 0x1

	.loc_0xEC:
	  addi      r3, r26, 0
	  addi      r4, r31, 0x7374
	  bl        -0x12C4
	  cmpwi     r3, -0x1
	  beq-      .loc_0x114
	  rlwinm    r3,r3,3,0,28
	  lwz       r4, 0x20(r26)
	  addi      r0, r3, 0x4
	  lwzx      r0, r4, r0
	  b         .loc_0x118

	.loc_0x114:
	  li        r0, -0x1

	.loc_0x118:
	  cmpw      r29, r0
	  blt+      .loc_0x90
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A2E44
 * Size:	000224
 */
void drawBattenPoleSpec(Graphics&, Vector3f&, f32, char*, Colour&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  fmr       f31, f1
	  stmw      r27, 0x44(r1)
	  mr        r27, r3
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x8(r4)
	  li        r4, 0x1
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x3C(r1)
	  bl        -0x3AF8C
	  stfs      f1, 0x38(r1)
	  li        r30, 0xFF
	  li        r31, 0
	  lfs       f0, 0x34(r1)
	  addi      r4, r1, 0x24
	  addi      r3, r27, 0
	  stfs      f0, 0x28(r1)
	  li        r5, 0x1
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x2C(r1)
	  fadds     f0, f0, f31
	  stfs      f0, 0x2C(r1)
	  stb       r30, 0x24(r1)
	  stb       r31, 0x25(r1)
	  stb       r31, 0x26(r1)
	  stb       r30, 0x27(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x72AC(r2)
	  addi      r3, r27, 0
	  addi      r4, r1, 0x34
	  bl        0x73524
	  stb       r30, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r27, 0
	  stb       r30, 0x21(r1)
	  li        r5, 0x1
	  stb       r31, 0x22(r1)
	  stb       r30, 0x23(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x72AC(r2)
	  addi      r3, r27, 0
	  addi      r4, r1, 0x28
	  bl        0x734E8
	  mr        r3, r27
	  lwz       r4, 0x2E4(r27)
	  lwz       r12, 0x3B4(r27)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x1C(r1)
	  addi      r4, r1, 0x1C
	  addi      r3, r27, 0
	  stb       r30, 0x1D(r1)
	  li        r5, 0x1
	  stb       r31, 0x1E(r1)
	  stb       r30, 0x1F(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r1, 0x34
	  addi      r5, r1, 0x28
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r28, 0
	  beq-      .loc_0x20C
	  lwz       r12, 0x3B4(r27)
	  lis       r4, 0x803A
	  mr        r3, r27
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r29, 0
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x2C(r1)
	  addi      r3, r1, 0x28
	  lfs       f0, -0x72A8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  lwz       r4, 0x2E4(r27)
	  addi      r4, r4, 0x1E0
	  bl        -0x6B8B8
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r28
	  lwz       r3, 0x10(r3)
	  bl        -0x7AEE0
	  lwz       r12, 0x3B4(r27)
	  neg       r0, r3
	  lwz       r4, 0x2DEC(r13)
	  srawi     r6, r0, 0x1
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r27, 0
	  mtlr      r12
	  addze     r6, r6
	  addi      r8, r28, 0
	  crclr     6, 0x6
	  addi      r5, r1, 0x28
	  li        r7, 0
	  blrl

	.loc_0x20C:
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3068
 * Size:	0003C0
 */
void WayPoint::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  crclr     6, 0x6
	  stwu      r1, -0x170(r1)
	  stfd      f31, 0x168(r1)
	  stfd      f30, 0x160(r1)
	  stfd      f29, 0x158(r1)
	  stfd      f28, 0x150(r1)
	  stfd      f27, 0x148(r1)
	  stfd      f26, 0x140(r1)
	  stfd      f25, 0x138(r1)
	  stmw      r17, 0xFC(r1)
	  addi      r20, r4, 0
	  addi      r19, r3, 0
	  subi      r4, r13, 0x53BC
	  lwz       r5, 0x10(r3)
	  addi      r3, r1, 0xB8
	  bl        0x1734EC
	  lwz       r12, 0x3B4(r20)
	  lis       r4, 0x803A
	  mr        r3, r20
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lbz       r0, 0x38(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  li        r0, 0xFF
	  stb       r0, 0xB4(r1)
	  stb       r0, 0xB5(r1)
	  stb       r0, 0xB6(r1)
	  stb       r0, 0xB7(r1)
	  b         .loc_0xA4

	.loc_0x8C:
	  li        r3, 0x80
	  stb       r3, 0xB4(r1)
	  li        r0, 0xFF
	  stb       r3, 0xB5(r1)
	  stb       r3, 0xB6(r1)
	  stb       r0, 0xB7(r1)

	.loc_0xA4:
	  lfs       f1, -0x72A4(r2)
	  addi      r3, r20, 0
	  addi      r4, r19, 0
	  addi      r5, r1, 0xB8
	  addi      r6, r1, 0xB4
	  bl        -0x2DC
	  lis       r3, 0x803A
	  lfs       f31, -0x72A0(r2)
	  lfs       f28, -0x72CC(r2)
	  mr        r24, r19
	  lfs       f29, -0x729C(r2)
	  mr        r23, r19
	  lfs       f30, -0x7298(r2)
	  addi      r29, r1, 0x78
	  addi      r28, r1, 0x30
	  addi      r27, r1, 0x2C
	  addi      r26, r1, 0x28
	  addi      r25, r1, 0x50
	  subi      r31, r3, 0x77C0
	  li        r22, 0
	  lis       r30, 0x7465

	.loc_0xF8:
	  lfs       f0, 0x0(r19)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0x4(r19)
	  stfs      f0, 0xAC(r1)
	  lfs       f0, 0x8(r19)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f0, f31
	  stfs      f0, 0xAC(r1)
	  lwz       r0, 0x4C(r24)
	  cmpwi     r0, 0
	  mr        r21, r0
	  ble-      .loc_0x37C
	  mr        r3, r20
	  lwz       r4, 0x2E4(r20)
	  lwz       r12, 0x3B4(r20)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x9B
	  stb       r0, 0x78(r1)
	  li        r0, 0xFF
	  addi      r3, r20, 0
	  stb       r0, 0x79(r1)
	  addi      r4, r29, 0
	  li        r5, 0x1
	  stb       r0, 0x7A(r1)
	  stb       r0, 0x7B(r1)
	  lwz       r12, 0x3B4(r20)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lwz       r18, 0x302C(r13)
	  addi      r4, r30, 0x7374
	  lwz       r17, 0x14(r23)
	  mr        r3, r18
	  bl        -0x16B8
	  cmpwi     r3, -0x1
	  beq-      .loc_0x1B4
	  lwz       r4, 0x20(r18)
	  rlwinm    r3,r3,3,0,28
	  mulli     r0, r17, 0xC4
	  lwzx      r3, r4, r3
	  add       r6, r3, r0
	  b         .loc_0x1B8

	.loc_0x1B4:
	  li        r6, 0

	.loc_0x1B8:
	  lfs       f0, 0x0(r6)
	  addi      r3, r20, 0
	  addi      r4, r1, 0xA8
	  stfs      f0, 0x98(r1)
	  addi      r5, r1, 0x98
	  lfs       f0, 0x4(r6)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0x8(r6)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0x9C(r1)
	  fadds     f0, f0, f31
	  stfs      f0, 0x9C(r1)
	  lwz       r12, 0x3B4(r20)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x98(r1)
	  lfs       f2, 0xA8(r1)
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0xAC(r1)
	  fsubs     f27, f3, f2
	  lfs       f2, 0xA0(r1)
	  fsubs     f26, f1, f0
	  lfs       f0, 0xB0(r1)
	  fmuls     f1, f27, f27
	  fsubs     f25, f2, f0
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x95658
	  fcmpu     cr0, f28, f1
	  beq-      .loc_0x248
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x248:
	  fmuls     f0, f29, f1
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  addi      r6, r28, 0
	  fmuls     f2, f25, f0
	  fmuls     f1, f26, f0
	  addi      r3, r1, 0x54
	  fmuls     f0, f27, f0
	  stfs      f2, 0x30(r1)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  bl        -0x6C1C0
	  lfs       f1, 0xA8(r1)
	  li        r8, 0x64
	  lfs       f0, 0x54(r1)
	  li        r7, 0xE6
	  lfs       f3, 0xAC(r1)
	  lfs       f2, 0x58(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0xB0(r1)
	  li        r6, 0x8C
	  lfs       f1, 0x5C(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x7C(r1)
	  fadds     f0, f4, f1
	  li        r0, 0xFF
	  stfs      f2, 0x80(r1)
	  mr        r3, r20
	  stfs      f0, 0x84(r1)
	  addi      r4, r25, 0
	  li        r5, 0x1
	  lfs       f0, 0x80(r1)
	  fadds     f0, f0, f30
	  stfs      f0, 0x80(r1)
	  stb       r8, 0x50(r1)
	  stb       r7, 0x51(r1)
	  stb       r6, 0x52(r1)
	  stb       r0, 0x53(r1)
	  lwz       r12, 0x3B4(r20)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x3B4(r20)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2E4(r20)
	  addi      r3, r1, 0x7C
	  addi      r4, r4, 0x1E0
	  bl        -0x6BC34
	  lwz       r5, 0x14(r23)
	  addi      r6, r21, 0
	  addi      r3, r1, 0xB8
	  crclr     6, 0x6
	  subi      r4, r13, 0x53B8
	  bl        0x173200
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0xB8
	  lwz       r3, 0x10(r3)
	  bl        -0x7B274
	  lwz       r12, 0x3B4(r20)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r20, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x7C
	  crclr     6, 0x6
	  addi      r8, r1, 0xB8
	  li        r7, 0
	  blrl

	.loc_0x37C:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x8
	  addi      r24, r24, 0x10
	  addi      r23, r23, 0x4
	  blt+      .loc_0xF8
	  lmw       r17, 0xFC(r1)
	  lwz       r0, 0x174(r1)
	  lfd       f31, 0x168(r1)
	  lfd       f30, 0x160(r1)
	  lfd       f29, 0x158(r1)
	  lfd       f28, 0x150(r1)
	  lfd       f27, 0x148(r1)
	  lfd       f26, 0x140(r1)
	  lfd       f25, 0x138(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
}
