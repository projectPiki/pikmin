#include "Route.h"
#include "Colour.h"
#include "MapMgr.h"
#include "MapCode.h"
#include "ItemMgr.h"
#include "GoalItem.h"
#include "UfoItem.h"
#include "Graphics.h"
#include "Font.h"
#include "UtilityKando.h"
#include "sysNew.h"
#include "DebugLog.h"

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

u16 PathFinder::mode;
int PathFinder::avoidWayPointIndex = -1;

RouteMgr* routeMgr;

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
	mRouteCount = map->mMapShape->mRouteGroup.getChildCount();
	if (!mRouteCount) {
		PRINT("no routes set\n");
		return;
	}

	mRouteGroupIDs         = new u32[mRouteCount];
	mGroupList             = new RouteMgr::Group[mRouteCount];
	mPathFinders           = new PathFinder*[mRouteCount];
	RouteGroup* routeGroup = static_cast<RouteGroup*>(map->mMapShape->mRouteGroup.mChild);
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
	bool check           = gsys->mPrevAllocType;
	gsys->mPrevAllocType = 0;

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
	gsys->mPrevAllocType = check;
	gsys->mRetraceCount  = 0;
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

	for (int i = 0; i < 8; i++) {
		LinkInfo* info = &mLinkInfos[i];
		if (mLinkIndices[i] == -1) {
			PRINT("nolink wp %d : link%d set deadend\n", mIndex, i);
			for (int j = 0; j < 4; j++) {
				info->setInfo(j, -2);
			}
		} else {
			for (int j = 0; j < 4; j++) {
				int wpIdx = -1;
				switch (j) {
				case 0:
				case 1:
				case 2:
					GoalItem* onyon = itemMgr->getContainer(j);
					if (onyon) {
						wpIdx = onyon->mWaypointIdx;
					}
					break;
				case 3:
					UfoItem* ufo = itemMgr->getUfo();
					if (ufo) {
						wpIdx = ufo->mWaypointID;
					}
					break;
				}

				if (wpIdx != -1) {
					int linkIdx      = mLinkIndices[i];
					PathFinder* path = routeMgr->getPathFinder('test');
					PRINT("** (%d to %d)\n", linkIdx, wpIdx);
					int syncRes = path->findSync(path->mBuffer, linkIdx, wpIdx, true);
					if (syncRes == 0) {
						info->setInfo(j, -2);
						PRINT("noway wp %d : link%d set deadend\n", mIndex, i);
					} else {
						int k;
						int value = 0;
						for (k = syncRes - 1; k >= 0; k--) {
							int thisIdx = path->mBuffer[k].mWayPointIdx;
							int prevIdx;
							if (k == 0) {
								prevIdx = mIndex;
							} else {
								prevIdx = path->mBuffer[k - 1].mWayPointIdx;
							}

							WayPoint* prevWP = routeMgr->getWayPoint('test', prevIdx);
							WayPoint* thisWP = routeMgr->getWayPoint('test', thisIdx);
							int thisLinkIdx  = prevWP->getLinkIndex(thisIdx);
							Vector3f dir     = prevWP->mPosition - thisWP->mPosition;
							value += int(dir.length());
							if (prevWP->mLinkInfos[thisLinkIdx].getInfo(j) >= 0 && prevWP->mLinkInfos[thisLinkIdx].getInfo(j) <= value) {
								continue;
							}
							prevWP->mLinkInfos[thisLinkIdx].setInfo(j, value);
						}
					}

				} else {
					info->setInfo(j, -2);
					PRINT("(goal%d) wp %d : link%d set deadend\n", j, mIndex, i);
				}
			}
		}
	}

	PathFinder::clearMode();
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
int PathFinder::findSyncOnyon(Vector3f& p1, PathFinder::Buffer* bufferList, int startWPIdx, int goalType, bool p5)
{
	int destWPIdx = -1;
	switch (goalType) {
	case 0:
	case 1:
	case 2:
		GoalItem* onyon = itemMgr->getContainer(goalType);
		if (onyon) {
			destWPIdx = onyon->mWaypointIdx;
		}
		break;
	case 3:
		UfoItem* ufo = itemMgr->getUfo();
		if (ufo) {
			destWPIdx = ufo->mWaypointID;
		}
	}

	if (destWPIdx == -1) {
		return 0;
	}

	if (PathFinder::checkMode(PFMODE_AvoidWater)) {
		PRINT("*** AVOID_WATER ROUTE FINDING START (%d - %d)\n", startWPIdx, destWPIdx);
	}

	int bufIdx                 = 0;
	bufferList[0].mWayPointIdx = startWPIdx;
	if (startWPIdx == destWPIdx) {
		return bufIdx + 1;
	}

	int a       = 0;
	int b       = 1000;
	bool check1 = false;
	int c       = 0;
	bool check2 = false;
	int d;
	int secondBestRes = selectSecondBestWayOnyon(p1, d, goalType, bufferList[bufIdx], destWPIdx, bufferList, bufIdx, p5);
	if (secondBestRes != -1) {
		PRINT("******** SECOND BEST = %d (dist =%d)\n", getWayPoint(getWayPoint(startWPIdx)->mLinkIndices[secondBestRes])->mIndex, d);
		check2 = true;
	}

	check2 = false;
	while (a == 0) {
		if (bufIdx >= mBufferSize) {
			ERROR("mem access !\n");
		}

		WayPoint* wp = getWayPoint(bufferList[bufIdx].mWayPointIdx);
		if (!check1) {
			for (int i = 0; i < 8; i++) {
				if (wp->mLinkIndices[i] == -1) {
					bufferList[bufIdx].resetFlag(i);
				} else {
					bufferList[bufIdx].setFlag(i);
				}
			}
		}

		int bestRes = selectWayOnyon(c, goalType, bufferList[bufIdx], destWPIdx, bufferList, bufIdx, p5);
		if (check2 && c > d) {
			PRINT("---- second best wo sirabe mashou!\n"); // 'let's check second best'
			for (int j = bufIdx; j > 0; j--) {
				for (int k = 0; k < 8; k++) {
					bufferList[j].setFlag(k);
				}
			}

			wp      = getWayPoint(bufferList[0].mWayPointIdx);
			bufIdx  = 0;
			bestRes = secondBestRes;
			check2  = false;
			PRINT("second best route:%d", getWayPoint(getWayPoint(startWPIdx)->mLinkIndices[secondBestRes])->mIndex);
			bufferList[0].resetFlag(bestRes);
		}

		if (bestRes != -1) {
			Vector3f dir = wp->mPosition - getWayPoint(wp->mLinkIndices[bestRes])->mPosition;
			c += int(dir.length());
			int linkIdx = wp->mLinkIndices[bestRes];
			if (linkIdx == destWPIdx) {
				bufferList[++bufIdx].mWayPointIdx = destWPIdx;
				if (bufIdx >= mBufferSize) {
					ERROR("mem access\n");
				}
				a = 1;
				break;
			}
			bufferList[bufIdx].resetFlag(bestRes);
			bufIdx++;
			if (bufIdx >= mBufferSize) {
				PRINT("@@ backtrack (full buffer ptr=%d buffSize=%d)\n", bufIdx, mBufferSize);
				bufIdx--;
				check1 = true;
			} else {
				bufferList[bufIdx].mWayPointIdx = linkIdx;
				check1                          = false;
			}
		} else {
			check1 = true;
			if (bufIdx >= 1) {
				Vector3f dir
				    = getWayPoint(bufferList[bufIdx].mWayPointIdx)->mPosition - getWayPoint(bufferList[bufIdx - 1].mWayPointIdx)->mPosition;
				c -= int(dir.length());
			}

			bufferList[bufIdx].mWayPointIdx = -1;
			bufIdx--;
			if (bufIdx < 0) {
				a = 2;
			}
		}
	}

	if (a == 1) {
		PRINT("<onyon> find route ### result {\n");
		for (int i = 0; i <= bufIdx; i++) {
			PRINT("  %d -> ::: (%s) : %s\n", bufferList[i].mWayPointIdx,
			      getWayPoint(bufferList[i].mWayPointIdx)->mIsOpen ? "[on]" : "*** off ***",
			      (getWayPoint(bufferList[i].mWayPointIdx)->_40 & 2) ? "pebble" : "-");
		}
		PRINT("}\n");
		return bufIdx + 1;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	800A2580
 * Size:	000264
 */
int PathFinder::selectWayOnyon(int p1, int goalType, PathFinder::Buffer& buf, int destWPIdx, PathFinder::Buffer* bufferList, int bufIdx,
                               bool p7)
{
	int vals2[8];
	int vals1[8];
	int wayIdx   = -1;
	int valCount = 0;

	// straight up never used lol.
	Vector3f wpPos   = getWayPoint(buf.mWayPointIdx)->mPosition;
	Vector3f destPos = getWayPoint(destWPIdx)->mPosition;

	for (int i = 0; i < 8; i++) {
		if (!buf.check(i)) {
			continue;
		}

		WayPoint* currWP = getWayPoint(buf.mWayPointIdx);
		if (!PathFinder::checkMode(PFMODE_AvoidWater) || !currWP->inWater()) {
			int linkIdx = currWP->mLinkIndices[i];
			if (linkIdx == buf.mWayPointIdx) {
				continue;
			}

			if (linkIdx == -1) {
				buf.resetFlag(i);
				continue;
			}
			if (!p7 && !getWayPoint(linkIdx)->mIsOpen) {
				buf.resetFlag(i);
				continue;
			}
			bool check = false;
			for (int j = 0; j < bufIdx; j++) {
				if (bufferList[j].mWayPointIdx == linkIdx) {
					check = true;
					break;
				}
			}

			if (currWP->mLinkInfos[i].getInfo(goalType) != -2 && !check) {
				vals1[valCount] = i;
				if (linkIdx == destWPIdx) {
					return i;
				}

				vals2[valCount] = currWP->mLinkInfos[i].getInfo(goalType);
				valCount++;
			}
		}
	}

	int minDist = 128000;
	for (int i = 0; i < valCount; i++) {
		if (vals2[i] < minDist) {
			minDist = vals2[i];
			wayIdx  = vals1[i];
		}
	}

	if (wayIdx != -1) {
		WayPoint* wp     = getWayPoint(buf.mWayPointIdx);
		WayPoint* linkWP = getWayPoint(wp->mLinkIndices[wayIdx]);
		Vector3f dir     = linkWP->mPosition - wp->mPosition;
		f32 dist         = dir.length();
		int iDist        = (int)dist + p1;
		// end ternaries in this are fake for stack fixing, just FYI.
		PRINT("\t way %d: next %d: sum is %d\n", wayIdx, linkWP->mIndex, iDist, iDist ? "yes" : "no", linkWP ? "yes" : "no");
	}

	u32 badCompiler[4];

	return wayIdx;
}

/*
 * --INFO--
 * Address:	800A27E4
 * Size:	00052C
 */
int PathFinder::selectSecondBestWayOnyon(Vector3f& p1, int& p2, int goalType, PathFinder::Buffer& buf, int destWPIdx,
                                         PathFinder::Buffer* bufferList, int bufIdx, bool p8)
{
	int vals2[8];
	int vals1[8];
	u32 badCompiler;
	int bestWayIdx   = -1;
	int valCount     = 0;
	Vector3f wpPos   = getWayPoint(buf.mWayPointIdx)->mPosition;
	Vector3f destPos = getWayPoint(destWPIdx)->mPosition;

	for (int i = 0; i < 8; i++) {
		if (!buf.check(i)) {
			continue;
		}

		WayPoint* currWP = getWayPoint(buf.mWayPointIdx);
		if (!PathFinder::checkMode(PFMODE_AvoidWater) || !currWP->inWater()) {
			int linkIdx = currWP->mLinkIndices[i];
			if (linkIdx == buf.mWayPointIdx) {
				continue;
			}

			if (linkIdx == -1) {
				buf.resetFlag(i);
				continue;
			}
			if (!p8 && !getWayPoint(linkIdx)->mIsOpen) {
				buf.resetFlag(i);
				continue;
			}
			bool check = false;
			for (int j = 0; j < bufIdx; j++) {
				if (bufferList[j].mWayPointIdx == linkIdx) {
					check = true;
					break;
				}
			}

			if (currWP->mLinkInfos[i].getInfo(goalType) != -2 && !check) {
				vals1[valCount] = i;
				if (linkIdx == destWPIdx) {
					return i;
				}

				vals2[valCount] = currWP->mLinkInfos[i].getInfo(goalType);
				valCount++;
			}
		}
	}

	int minDist = 128000;
	for (int i = 0; i < valCount; i++) {
		if (vals2[i] < minDist) {
			minDist    = vals2[i];
			bestWayIdx = vals1[i];
		}
	}

	int i;
	int secondBestWayIdx = -1;

	p2 = 128000;

	for (i = 0; i < valCount; i++) {
		if (i != bestWayIdx && vals2[i] < p2) {
			WayPoint* wp     = getWayPoint(buf.mWayPointIdx);
			WayPoint* linkWP = getWayPoint(wp->mLinkIndices[vals1[i]]);
			bool check       = true;

			PRINT("wp(%d) = %s wp2(%d) = %s\n", wp->mIndex, wp->mIsOpen ? "on" : "off", linkWP->mIndex, linkWP->mIsOpen ? "on" : "off");

			if (!wp->mIsOpen) {
				Plane plane;
				Vector3f dir = linkWP->mPosition - wp->mPosition;
				dir.normalise();
				plane.mNormal    = dir;
				plane.mOffset    = dir.DP(wp->mPosition);
				bool isAbove     = plane.dist(p1);
				bool isLinkAbove = plane.dist(linkWP->mPosition);

				if (isAbove != isLinkAbove) {
					check = false;
					PRINT("another side !\n");
				}
			} else if (!linkWP->mIsOpen) {
				Plane plane;
				Vector3f dir = linkWP->mPosition - wp->mPosition;
				dir.normalise();
				plane.mNormal  = dir;
				plane.mOffset  = dir.DP(linkWP->mPosition);
				bool isAbove   = plane.dist(p1);
				bool isWPAbove = plane.dist(wp->mPosition);
				if (isAbove != isWPAbove) {
					check = false;
					PRINT("another side !\n");
				}
			}

			if (check) {
				secondBestWayIdx = i;
				p2               = vals2[i];
			}
		}
	}

	u32 badCompiler2[6];

	PRINT("BEST IS %d : SECOND BEST IS %d\n", bestWayIdx, secondBestWayIdx);
	return secondBestWayIdx;
}

/*
 * --INFO--
 * Address:	800A2D10
 * Size:	000134
 */
void RouteMgr::refresh(Graphics& gfx)
{
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setLighting(false, nullptr);
	gfx.useTexture(nullptr, 0);
	for (int i = 0; i < getNumWayPoints('test'); i++) {
		WayPoint* wp = getWayPoint('test', i);
		if (gfx.mCamera->isPointVisible(wp->mPosition, 200.0f)) {
			wp->refresh(gfx);
		}
	}
}

/*
 * --INFO--
 * Address:	800A2E44
 * Size:	000224
 */
static void drawBattenPoleSpec(Graphics& gfx, Vector3f& pos, f32 height, char* labelText, Colour& labelColor)
{
	Vector3f bottom(pos);
	bottom.y = mapMgr->getMinY(bottom.x, bottom.z, true);

	Vector3f top(bottom);
	top.y += height;

	gfx.setColour(Colour(255, 0, 0, 255), true);
	drawBatten(gfx, bottom, 8.0f);

	gfx.setColour(Colour(255, 255, 0, 255), true);
	drawBatten(gfx, top, 8.0f);

	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.setColour(Colour(0, 255, 0, 255), true);
	gfx.drawLine(bottom, top);

	if (labelText) {
		gfx.useMatrix(Matrix4f::ident, 0);
		gfx.setColour(labelColor, true);
		top.y += 10.0f;
		top.multMatrix(gfx.mCamera->mLookAtMtx);
		int width = -gsys->mConsFont->stringWidth(labelText) / 2;
		gfx.perspPrintf(gsys->mConsFont, top, width, 0, labelText);
	}
}

/*
 * --INFO--
 * Address:	800A3068
 * Size:	0003C0
 */
void WayPoint::refresh(Graphics& gfx)
{
	char buf[64];
	sprintf(buf, "%d", mIndex);
	gfx.useMatrix(Matrix4f::ident, 0);
	Colour col;
	if (mIsOpen) {
		col.set(255, 255, 255, 255);
	} else {
		col.set(128, 128, 128, 255);
	}

	drawBattenPoleSpec(gfx, mPosition, 75.0f, buf, col);

	for (int i = 0; i < 8; i++) {
		Vector3f pos(mPosition);
		pos.y += 30.0f;
		int info = mLinkInfos[i].getInfo(2);

		if (info <= 0) {
			continue;
		}

		gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
		gfx.setColour(Colour(155, 255, 255, 255), true);
		WayPoint* wp     = routeMgr->getWayPoint('test', mLinkIndices[i]);
		Vector3f linkPos = wp->mPosition;
		linkPos.y += 30.0f;
		gfx.drawLine(pos, linkPos);

		Vector3f dir   = linkPos - pos;
		f32 dist       = dir.normalise();
		Vector3f shift = pos + dir * (dist * 0.2f);
		shift.y += 7.0f;
		gfx.setColour(Colour(100, 230, 140, 255), true);
		gfx.useMatrix(Matrix4f::ident, 0);

		shift.multMatrix(gfx.mCamera->mLookAtMtx);
		sprintf(buf, "%d:%d", mLinkIndices[i], info);

		gfx.perspPrintf(gsys->mConsFont, shift, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
	}
}
