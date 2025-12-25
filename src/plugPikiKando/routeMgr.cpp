#include "Colour.h"
#include "DebugLog.h"
#include "Font.h"
#include "GoalItem.h"
#include "Graphics.h"
#include "ItemMgr.h"
#include "MapCode.h"
#include "MapMgr.h"
#include "Route.h"
#include "UfoItem.h"
#include "UtilityKando.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(16)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("routeMgr")

u16 PathFinder::mode;
int PathFinder::avoidWayPointIndex = -1;

RouteMgr* routeMgr;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000048
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

/**
 * @TODO: Documentation
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
	client->mStartWpIdx           = a;
	client->mDestWpIdx            = b;
	client->mIncludeBlockedPaths  = flag;
	client->mMode                 = mode;
	client->mHandle               = handle;
	client->mCurrentBufIdx        = 0;
	client->mStatus               = PathStatus::Searching;
	client->mIsBacktracking       = false;
	client->mBuffer->mWayPointIdx = a;
	if (a == b) {
		client->mStatus     = PathStatus::Success;
		client->mPathLength = 1;
		return handle;
	}
	return handle;
}

/**
 * @TODO: Documentation
 */
int PathFinder::checkASync(u32 handle)
{
	int idx = handle2idx(handle);

	if (idx == -1) {
		return -3;
	}

	Client* client = &mClient[idx];
	if (client->mStatus == PathStatus::Failed) {
		PRINT("FAIL WHY ? \n");
		return -2;
	}

	if (client->mStatus == PathStatus::Success) {
		PRINT("SUCCESS\n");
		return client->mPathLength;
	}

	return -1;
}

/**
 * @TODO: Documentation
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

		a.mBuffer              = b.mBuffer;
		a.mStartWpIdx          = b.mStartWpIdx;
		a.mDestWpIdx           = b.mDestWpIdx;
		a.mIncludeBlockedPaths = b.mIncludeBlockedPaths;
		a.mHandle              = b.mHandle;
		a.mMode                = b.mMode;
		a.mCurrentBufIdx       = b.mCurrentBufIdx;
		a.mStatus              = b.mStatus;
		a.mIsBacktracking      = b.mIsBacktracking;
		a.mPathLength          = b.mPathLength;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
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

/**
 * @TODO: Documentation
 */
void PathFinder::updateClient(Client& client, int loops)
{
	while (client.mStatus == PathStatus::Searching && loops > 0) {
		loops--;

		// Safety check: ensure current buffer index is within allocated buffer size
		if (mBufferSize < client.mCurrentBufIdx) {
			ERROR("buffer full\n");
		}

		WayPoint* wp = getWayPoint(client.mBuffer[client.mCurrentBufIdx].mWayPointIdx);

		// If not backtracking, initialize flags for each of the up to 8 links
		if (!client.mIsBacktracking) {
			for (int i = 0; i < 8; i++) {
				if (wp->mLinkIndices[i] == -1) {
					// No link in the slot, clear the flag
					client.mBuffer[client.mCurrentBufIdx].resetFlag(i);
				} else {
					// Link exists, set flag to allow consideration
					client.mBuffer[client.mCurrentBufIdx].setFlag(i);
				}
			}
		}

		int handle = selectWay(client.mBuffer[client.mCurrentBufIdx], client.mDestWpIdx, client.mBuffer, client.mCurrentBufIdx,
		                       client.mIncludeBlockedPaths);

		if (handle != -1) {
			// Found a valid next link to follow
			int linkIdx = wp->mLinkIndices[handle];

			// Check if this link reaches the destination
			if (linkIdx == client.mDestWpIdx) {
				// Record destination waypoint in buffer
				client.mBuffer[++client.mCurrentBufIdx].mWayPointIdx = client.mDestWpIdx;

				if (mBufferSize < client.mCurrentBufIdx) {
					ERROR("mem access\n");
				}

				// Mark pathfinding success and record path length
				PRINT("OK FOUND!\n");
				client.mStatus     = PathStatus::Success;
				client.mPathLength = client.mCurrentBufIdx + 1;
				return;
			}

			// If destination not reached, mark this direction as tried
			client.mBuffer[client.mCurrentBufIdx].resetFlag(handle);
			client.mCurrentBufIdx++;

			if (client.mCurrentBufIdx >= mBufferSize) {
				// Ran out of buffer slots: cannot go deeper, backtrack instead
				client.mCurrentBufIdx--;
				client.mIsBacktracking = true;
			} else {
				client.mBuffer[client.mCurrentBufIdx].mWayPointIdx = linkIdx;
				client.mIsBacktracking                             = false;
			}
		} else {
			// No valid direction found: enter backtracking
			client.mIsBacktracking                             = true;
			client.mBuffer[client.mCurrentBufIdx].mWayPointIdx = -1;
			client.mCurrentBufIdx--; // Step back!

			if (client.mCurrentBufIdx < 0) {
				// Stepped back past root: no path found
				PRINT("GIVE UP\n");
				client.mStatus     = PathStatus::Failed;
				client.mPathLength = -2;
				return;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
int PathFinder::findSync(WayPoint** pathWayPoints, int numWPsToFind, int startWPIdx, int destWPIdx, bool includeBlockedPaths)
{
	int res = findSync(mBuffer, startWPIdx, destWPIdx, includeBlockedPaths);
	if (res > 0) {
		for (int i = 0; i < numWPsToFind; i++) {
			pathWayPoints[i] = getWayPoint(mBuffer[i].mWayPointIdx);
		}
	}

	return res;
}

/**
 * @TODO: Documentation
 */
int PathFinder::findSync(PathFinder::Buffer* bufferList, int startWPIdx, int destWPIdx, bool includeBlockedPaths)
{
	if (checkMode(PathFinderMode::AvoidWater)) {
		PRINT("*** AVOID_WATER ROUTE FINDING START (%d - %d)\n", destWPIdx, startWPIdx);
	}

	Buffer* buf;
	int wpCount = 0;

	// We start at the start... (and exit early if we're here)
	bufferList[0].mWayPointIdx = startWPIdx;
	if (startWPIdx == destWPIdx) {
		return 1;
	}

	PathStatus::Type stat = PathStatus::Searching;
	bool tryNewPath       = false;

	while (stat == PathStatus::Searching) {
		if (wpCount >= mBufferSize) {
			ERROR("mem access !\n");
		}

		buf          = &bufferList[wpCount];
		WayPoint* wp = getWayPoint(buf->mWayPointIdx);

		// If not currently retrying/backtracking, reset flags for available links
		if (!tryNewPath) {
			for (int i = 0; i < 8; i++) {
				if (wp->mLinkIndices[i] == -1) {
					buf->resetFlag(i);
				} else {
					buf->setFlag(i);
				}
			}
		}

		// Select next direction/link to explore
		int way = selectWay(*buf, destWPIdx, bufferList, wpCount, includeBlockedPaths);
		if (way != -1) {
			// Valid next link found
			int linkWPIdx = wp->mLinkIndices[way];

			// Check if this link reaches the destination
			if (linkWPIdx == destWPIdx) {
				wpCount++;
				bufferList[wpCount].mWayPointIdx = destWPIdx;

				if (wpCount >= mBufferSize) {
					ERROR("mem access\n");
				}

				stat = PathStatus::Success;
				break;
			}

			// Mark this direction tried and advance deeper
			buf->resetFlag(way);
			wpCount++;

			if (wpCount >= mBufferSize) {
				// Buffer exhausted: backtrack/retry
				PRINT("@@ backtrack (full buffer ptr=%d buffSize=%d)\n", wpCount, mBufferSize);
				tryNewPath = true;
				wpCount--; // Step back!

			} else {
				// Continue forward along the chosen link
				bufferList[wpCount].mWayPointIdx = linkWPIdx;
				tryNewPath                       = false;
			}

		} else {
			// No valid links: backtrack
			buf->mWayPointIdx = -1;
			tryNewPath        = true;
			wpCount--;

			// Nothing left, we failed...
			if (wpCount < 0) {
				stat = PathStatus::Failed;
			}
		}
	}

	if (stat == PathStatus::Success) {
		// Path length + 1 because we include the destination waypoint
		return wpCount + 1;
	} else {
		// No path found
		return 0;
	}

	STACK_PAD_VAR(6);
}

/**
 * @TODO: Documentation
 */
WayPoint* PathFinder::getWayPoint(int wpIdx)
{
	return &mGroup->mWayPoints[wpIdx];
}

/**
 * @TODO: Documentation
 */
int PathFinder::selectWay(PathFinder::Buffer& buf, int destWPIdx, PathFinder::Buffer* bufferList, int wpCount, bool includeBlockedPaths)
{
	// Return value: index of chosen direction (0-7), or -1 if no valid path
	int chosenDir      = -1;
	int validLinkCount = 0; // number of valid candidate directions

	// Store candidate direction indices and their squared distances to destination
	f32 distToDestSq[8];
	int dirIndices[8];

	// Current and destination positions (XZ plane)
	Vector3f currPos = getWayPoint(buf.mWayPointIdx)->mPosition;
	Vector3f destPos = getWayPoint(destWPIdx)->mPosition;

	for (int dir = 0; dir < 8; dir++) {
		// Skip if this direction is not available
		if (!buf.check(dir)) {
			continue;
		}

		WayPoint* wp = getWayPoint(buf.mWayPointIdx);
		if (!wp) {
			PRINT_GLOBAL("buffer.idx=%d", buf.mWayPointIdx);
			ERROR("wp is null!");
		}

		// Exclude waypoints based on mode flags (e.g., avoid a specific index or water)
		if ((checkMode(PathFinderMode::Unk2) && avoidWayPointIndex != -1 && wp->mIndex == avoidWayPointIndex)
		    || (checkMode(PathFinderMode::AvoidWater) && wp->inWater())) {
			continue;
		}

		// Skip self-links
		int neighborIdx = wp->mLinkIndices[dir];
		if (neighborIdx == buf.mWayPointIdx) {
			continue;
		}

		// Invalid link index: clear flag and skip
		if (neighborIdx == -1) {
			buf.resetFlag(dir);
			continue;
		}

		// Ensure waypoint exists
		if (!getWayPoint(neighborIdx)) {
			PRINT_GLOBAL("idx=%d", neighborIdx);
			ERROR("no getwaypoint!");
		}

		// Exclude closed/blocked paths if not allowed
		if (!includeBlockedPaths && !getWayPoint(neighborIdx)->mIsOpen) {
			buf.resetFlag(dir);
			continue;
		}

		// Avoid revisiting waypoints already in current path buffer
		bool alreadyVisited = false;
		for (int j = 0; j < wpCount; j++) {
			if (bufferList[j].mWayPointIdx == neighborIdx) {
				alreadyVisited = true;
				break;
			}
		}

		if (alreadyVisited) {
			continue;
		}

		// Record this direction as a candidate
		dirIndices[validLinkCount] = dir;

		// If this neighbor is the destination, return immediately
		if (neighborIdx == destWPIdx) {
			return dir;
		}

		// Squared horizontal distance to destination
		Vector3f linkPos             = getWayPoint(neighborIdx)->mPosition;
		distToDestSq[validLinkCount] = qdist2(linkPos.x, linkPos.z, destPos.x, destPos.z);

		// Sanity check: no more than 8 candidates
		if (++validLinkCount > 7) {
			PRINT_GLOBAL("numWays=%d", validLinkCount);
			ERROR("numWays>=8");
		}
	}

	// Choose the candidate with minimum squared distance to destination
	f32 bestDist = 128000.0f;
	for (int i = 0; i < validLinkCount; i++) {
		if (distToDestSq[i] < bestDist) {
			bestDist  = distToDestSq[i];
			chosenDir = dirIndices[i];
		}
	}

	return chosenDir;

	// Reserve stack space (unused placeholder)
	STACK_PAD_VAR(3);
}

/**
 * @TODO: Documentation
 */
PathFinder* RouteMgr::getPathFinder(u32 handle)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		return mPathFinders[idx];
	} else {
		return nullptr;
	}
}

/**
 * @TODO: Documentation
 */
void RouteMgr::update()
{
	PathFinder* path = getPathFinder('test');
	if (path) {
		path->updateASync();
	}
}

/**
 * @TODO: Documentation
 */
int RouteMgr::getNumWayPoints(u32 handle)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		return mGroupList[idx].mNumPoints;
	} else {
		return -1;
	}
}

/**
 * @TODO: Documentation
 */
Vector3f RouteMgr::getSafePosition(u32, Vector3f& pos)
{
	// Determine if current position is in water
	CollTriInfo* tri = mapMgr->getCurrTri(pos.x, pos.z, true);
	bool inWater     = false;
	if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
		f32 maxY = mapMgr->getMaxY(pos.x, pos.z, false);
		f32 minY = mapMgr->getMinY(pos.x, pos.z, true);
		if (maxY <= minY && pos.y <= minY) {
			PRINT("minY = %.1f < %.1f < %.1f = maxY\n", minY, pos.y, maxY);
			inWater = true;
		}
	}

	// Find nearest safe edge avoiding off-mesh areas, considering water state
	WayPoint* wp;
	WayPoint* wp2;
	findNearestEdgeAvoidOff(&wp, &wp2, 'test', pos, false, true, inWater);

	// Ensure two valid waypoints were found
	if (!wp || !wp2) {
		PRINT_GLOBAL("from=%x to=%x pos(%.1f %.1f %.1f)\n", wp, wp2, pos.x, pos.y, pos.z);
		ERROR("getSafePos (%.1f %.1f %.1f)", pos.x, pos.y, pos.z);
	}

	PRINT("getSafePos (%d-%d)\n", wp->mIndex, wp2->mIndex);

	// Compute directional vector and normalized distance between waypoints
	Vector3f edge = wp2->mPosition - wp->mPosition;
	Vector3f dir  = edge;
	f32 edgeLen   = dir.normalise();
	f32 t         = dir.DP(pos - wp->mPosition) / edgeLen;

	// Interpolate radius at projection point
	f32 radiusAtT = (1.0f - t) * wp->mRadius + t * wp2->mRadius;

	// Compute offset vector from pos to projected point on edge
	Vector3f offset;
	offset   = (t * edgeLen) * dir + wp->mPosition; // Projected point on edge
	offset   = offset - pos;                        // Offset vector from pos to projected point
	offset.y = 0.0f;                                // Ignore vertical component

	f32 offsetLen = offset.length() - radiusAtT;

	// If outside safe corridor, clamp t and adjust position to edge
	if (offsetLen > 0.0f || t < 0.0f || t > 1.0f) {
		if (t < 0.0f) {
			t = 0.0f;
		} else if (t > 1.0f) {
			t = 1.0f;
		}

		pos   = wp->mPosition + t * edge;
		pos.y = mapMgr->getMinY(pos.x, pos.z, true);
	}

	return pos;
}

/**
 * @TODO: Documentation
 */
void RouteMgr::findNearestEdge(WayPoint** outNearestStart, WayPoint** outNearestEnd, u32 handle, immut Vector3f& pos, bool allowWater,
                               bool requireOpen, bool avoidDestination)
{
	// Convert handle to index in group list
	int idx = id2idx(handle);
	if (idx == -1) {
		*outNearestStart = nullptr;
		*outNearestEnd   = nullptr;
		return;
	}

	WayPoint* bestStart = nullptr;
	WayPoint* bestEnd   = nullptr;
	f32 closestDist     = 128000.0f;

	for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
		WayPoint* startWp = &mGroupList[idx].mWayPoints[i];

		if ((allowWater || !avoidDestination || startWp->inWater()) && (avoidDestination || !allowWater || !startWp->inWater())
		    && (!requireOpen || startWp->mIsOpen) && (!avoidDestination || !(startWp->mFlags & WayPointFlags::Destination))) {

			for (int j = 0; j < 8; j++) {
				if (startWp->mLinkIndices[j] == -1) {
					continue;
				}

				WayPoint* wpLink = &mGroupList[idx].mWayPoints[startWp->mLinkIndices[j]];
				if ((!allowWater || !avoidDestination || wpLink->inWater()) && (avoidDestination || !allowWater || !wpLink->inWater())
				    && (!requireOpen || wpLink->mIsOpen)) {

					// Compute edge vector and direction
					Vector3f edgeVector = wpLink->mPosition - startWp->mPosition;
					Vector3f direction  = edgeVector;
					f32 edgeLength      = direction.normalise();

					// Project the target position onto the edge
					f32 projection = direction.DP(pos - startWp->mPosition) / edgeLength;

					f32 distanceToEdge;
					if (projection < 0.0f || projection > 1.0f) {
						// Target is outside the segment - use closest endpoint
						Vector3f diffVec = startWp->mPosition - pos;
						f32 distToStart  = diffVec.length();

						diffVec       = wpLink->mPosition - pos;
						f32 distToEnd = diffVec.length();

						if (distToEnd < distToStart) {
							distanceToEdge = distToEnd;
						} else {
							distanceToEdge = distToStart;
						}
					} else {
						Vector3f offset;

						// Target projects onto the segment
						offset = (projection * edgeLength) * direction + startWp->mPosition;
						offset = offset - pos;

						// Interpolate waypoint radius to get edge thickness
						f32 blendedRadius = (1.0f - projection) * startWp->mRadius + projection * wpLink->mRadius;
						distanceToEdge    = offset.normalise() - blendedRadius;
					}

					// Keep closest edge
					if (closestDist > distanceToEdge) {
						bestStart   = startWp;
						bestEnd     = wpLink;
						closestDist = distanceToEdge;
					}
				}
			}
		}
	}

	*outNearestStart = bestStart;
	*outNearestEnd   = bestEnd;
}

/**
 * @TODO: Documentation
 */
void RouteMgr::findNearestEdgeAvoidOff(WayPoint** outNearestStart, WayPoint** outNearestEnd, u32 handle, immut Vector3f& pos,
                                       bool allowWater, bool requireOpen, bool avoidDestination)
{
	int idx = id2idx(handle);
	if (idx == -1) {
		*outNearestStart = nullptr;
		*outNearestEnd   = nullptr;
		return;
	}

	// Try to find a special "off" waypoint near the target position
	WayPoint* wpOff = findNearestOffWayPoint(handle, pos, allowWater);
	if (!wpOff) {
		// Fallback to the regular nearest edge search
		findNearestEdge(outNearestStart, outNearestEnd, handle, pos, allowWater, requireOpen, avoidDestination);
		return;
	}

	// Construct a plane for filtering based on the off waypoint
	Plane offPlane;
	createOffPlane(handle, offPlane, wpOff);

	bool isTargetAbovePlane = offPlane.dist(pos) >= 0.0f ? TRUE : FALSE; // utterly ridiculous

	WayPoint* bestStart = nullptr;
	WayPoint* bestEnd   = nullptr;
	f32 closestDist     = 128000.0f;

	for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
		WayPoint* startWP = &mGroupList[idx].mWayPoints[i];

		if ((allowWater || !avoidDestination || startWP->inWater()) && (avoidDestination || !allowWater || !startWP->inWater())
		    && (!avoidDestination || !(startWP->mFlags & WayPointFlags::Destination)) && (!requireOpen || startWP->mIsOpen)) {

			for (int j = 0; j < 8; j++) {
				if (startWP->mLinkIndices[j] == -1) {
					continue;
				}

				WayPoint* endWP = &mGroupList[idx].mWayPoints[startWP->mLinkIndices[j]];
				if ((!allowWater || !avoidDestination || endWP->inWater()) && (avoidDestination || !allowWater || !endWP->inWater())
				    && (!requireOpen || endWP->mIsOpen)) {

					// Check if both waypoints are on the same side of the plane as the target
					bool startAbovePlane = offPlane.dist(startWP->mPosition) >= 0.0f ? TRUE : FALSE;
					bool endAbovePlane   = offPlane.dist(endWP->mPosition) >= 0.0f ? TRUE : FALSE;

					// Check if either waypoint links to the off waypoint
					bool startLinksToOff = false;
					bool endLinksToOff   = false;
					for (int k = 0; k < 8; k++) {
						if (startWP->mLinkIndices[k] == wpOff->mIndex) {
							startLinksToOff = true;
						}

						if (endWP->mLinkIndices[k] == wpOff->mIndex) {
							endLinksToOff = true;
						}
					}

					// Skip edges that cross the plane improperly
					if ((!startLinksToOff || startAbovePlane == isTargetAbovePlane)
					    && (!endLinksToOff || endAbovePlane == isTargetAbovePlane)) {

						// Project the target onto the edge between startWP and endWP
						Vector3f edgeVec = endWP->mPosition - startWP->mPosition;
						Vector3f dir     = edgeVec;
						f32 edgeLength   = dir.normalise();

						f32 projection = dir.DP(pos - startWP->mPosition) / edgeLength;
						f32 distance;

						if (projection < 0.0f || projection > 1.0f) {
							// Target projects outside the segment - use endpoint distances
							Vector3f diffVec = startWP->mPosition - pos;
							f32 distToStart  = diffVec.length();

							diffVec       = endWP->mPosition - pos;
							f32 distToEnd = diffVec.length();
							if (distToEnd < distToStart) {
								distance = distToEnd;
							} else {
								distance = distToStart;
							}
						} else {
							// Target projects onto the segment
							Vector3f offset;
							offset = (projection * edgeLength) * dir + startWP->mPosition; // Projected point on edge
							offset = offset - pos;                                         // Offset vector from pos to projected point

							f32 radius = (1.0f - projection) * startWP->mRadius + projection * endWP->mRadius;
							distance   = offset.normalise() - radius;
						}

						// Store the closest valid edge
						if (closestDist > distance) {
							bestStart   = startWP;
							bestEnd     = endWP;
							closestDist = distance;
						}
					}
				}
			}
		}
	}

	*outNearestStart = bestStart;
	*outNearestEnd   = bestEnd;
}

/**
 * @TODO: Documentation
 */
WayPoint* RouteMgr::findNearestWayPoint(u32 handle, immut Vector3f& pos, bool excludeWater)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		f32 closestDist = 128000.0f;
		int nearestIdx  = -1;

		for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
			WayPoint* waypoint = &mGroupList[idx].mWayPoints[i];

			// Skip waypoints that are closed or in water if water is excluded
			if ((excludeWater && waypoint->inWater()) || !mGroupList[idx].mWayPoints[i].mIsOpen) {
				continue;
			}

			Vector3f offset(mGroupList[idx].mWayPoints[i].mPosition); // Get waypoint position
			offset       = offset - pos;                              // Calculate offset vector from target position to waypoint
			f32 distance = offset.length();                           // Calculate distance to waypoint

			// Keep the closest
			if (closestDist > distance) {
				closestDist = distance;
				nearestIdx  = i;
			}
		}

		return &mGroupList[idx].mWayPoints[nearestIdx];
	}

	return nullptr;
}

/**
 * @TODO: Documentation
 */
WayPoint* RouteMgr::findNearestOffWayPoint(u32 handle, immut Vector3f& pos, bool excludeWater)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		f32 closestDist = 128000.0f;
		int nearestIdx  = -1;

		for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
			WayPoint* waypoint = &mGroupList[idx].mWayPoints[i];

			// Skip waypoints that are open or in water if water is excluded
			if ((excludeWater && waypoint->inWater()) || waypoint->mIsOpen) {
				continue;
			}

			Vector3f offset(waypoint->mPosition); // Waypoint position
			offset       = offset - pos;          // Offset vector to target position
			f32 distance = offset.length();       // Euclidean distance

			if (closestDist > distance) {
				closestDist = distance;
				nearestIdx  = i;
			}
		}

		return &mGroupList[idx].mWayPoints[nearestIdx];
	}

	return nullptr;
}

/**
 * @TODO: Documentation
 */
void RouteMgr::createOffPlane(u32 handle, Plane& plane, WayPoint* wp)
{
	int groupIdx = id2idx(handle);
	if (groupIdx == -1) {
		return;
	}

	// No links available, cannot create a plane
	if (wp->mLinkCount <= 0) {
		return;
	}

	// Find the first valid link index (i.e., a connected waypoint)
	int linkedIdx = -1;
	for (int i = 0; i < 8; i++) {
		if (wp->mLinkIndices[i] != -1) {
			linkedIdx = wp->mLinkIndices[i];
			break;
		}
	}

	if (linkedIdx == -1) {
		return;
	}

	// Compute plane normal as direction from this waypoint to the linked one
	Vector3f direction = mGroupList[groupIdx].mWayPoints[linkedIdx].mPosition - wp->mPosition;
	direction.normalise();

	plane.mNormal = direction;
	plane.mOffset = direction.DP(wp->mPosition); // Dot product gives offset from origin
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
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

/**
 * @TODO: Documentation
 */
WayPoint* RouteMgr::findNearestWayPointAll(u32 handle, immut Vector3f& pos)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		f32 closestDist = 128000.0f;
		int nearestIdx  = -1;

		for (int i = 0; i < mGroupList[idx].mNumPoints; i++) {
			Vector3f offset(mGroupList[idx].mWayPoints[i].mPosition);
			offset       = offset - pos;
			f32 distance = offset.length();

			if (closestDist > distance) {
				closestDist = distance;
				nearestIdx  = i;
			}
		}

		return &mGroupList[idx].mWayPoints[nearestIdx];
	}

	return nullptr;
}

/**
 * @TODO: Documentation
 */
WayPoint* RouteMgr::getWayPoint(u32 handle, int wpIdx)
{
	int idx = id2idx(handle);
	if (idx != -1) {
		return &mGroupList[idx].mWayPoints[wpIdx];
	} else {
		return nullptr;
	}
}

/**
 * @TODO: Documentation
 */
RouteMgr::RouteMgr()
{
	mRouteCount    = 0;
	mGroupList     = nullptr;
	mPathFinders   = nullptr;
	mRouteGroupIDs = 0;
}

/**
 * @TODO: Documentation
 */
void WayPoint::setFlag(bool flag)
{
	mIsOpen              = flag;
	mRoutePoint->mIsOpen = flag;
}

/**
 * @TODO: Documentation
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
			WayPoint* wp  = &group.mWayPoints[j];
			wp->mIsOpen   = true;
			wp->mIndex    = j;
			wp->mPosition = point->mPosition;
			wp->mFlags    = 0;

			CollTriInfo* tri = map->getCurrTri(wp->mPosition.x, wp->mPosition.z, true);
			if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
				wp->mFlags |= WayPointFlags::InWater;
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

/**
 * @TODO: Documentation
 */
void RouteMgr::initLinks()
{
	// this gsys stuff isn't in the DLL
	bool check           = gsys->mPrevAllocType;
	gsys->mPrevAllocType = FALSE;

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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
u32 RouteMgr::idx2id(int idx)
{
	return mRouteGroupIDs[idx];
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000080
 */
RouteTracer::RouteTracer()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
RouteTracer::Context::PointInfo::PointInfo()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000764
 */
void RouteTracer::render(Graphics&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000278
 */
void RouteTracer::Context::makeContext(RouteTracer*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002EC
 */
void RouteTracer::Context::setTarget(RouteTracer*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000224
 */
int RouteTracer::Context::recognise(RouteTracer*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
bool RouteTracer::noLink()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B0
 */
void RouteTracer::startConsult(Creature*, PathFinder*, PathFinder::Buffer*, int, Vector3f&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000364
 */
void RouteTracer::updateState()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000054
 */
Vector3f RouteTracer::getTarget()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C0
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void WayPoint::initLinkInfos()
{
	PathFinder::setMode(PathFinderMode::Unk2);
	PathFinder::avoidWayPointIndex = mIndex;

	for (int i = 0; i < 8; i++) {
		LinkInfo* info = &mLinkInfos[i];

		// If no link exists in this slot, mark all info entries as dead ends (-2)
		if (mLinkIndices[i] == -1) {
			PRINT_KANDO("nolink wp %d : link%d set deadend\n", mIndex, i);
			for (int j = 0; j < 4; j++) {
				info->setInfo(j, -2);
			}

			continue;
		}

		// For each "goal" type (3 containers and 1 UFO)
		for (int goalIdx = 0; goalIdx < 4; goalIdx++) {
			int wpIdx = -1;

			switch (goalIdx) {
			case 0: // Red onion
			case 1: // Blue onion
			case 2: // Yellow onion
				GoalItem* container = itemMgr->getContainer(goalIdx);
				if (container) {
					wpIdx = container->mWaypointIdx;
				}
				break;
			case 3: // Ship
				UfoItem* ufo = itemMgr->getUfo();
				if (ufo) {
					wpIdx = ufo->mWaypointID;
				}
				break;
			}

			if (wpIdx != -1) {

				int linkWaypointIdx    = mLinkIndices[i];
				PathFinder* pathfinder = routeMgr->getPathFinder('test');

				PRINT_KANDO("** (%d to %d)\n", linkWaypointIdx, wpIdx);

				int pathLength = pathfinder->findSync(pathfinder->mBuffer, linkWaypointIdx, wpIdx, true);

				// If no path is found, mark dead end
				if (pathLength == 0) {
					info->setInfo(goalIdx, -2);
					PRINT_KANDO("noway wp %d : link%d set deadend\n", mIndex, i);
					continue;
				}

				int step;
				int accumCost = 0;

				// Walk backward along the found path to update link info costs
				for (step = pathLength - 1; step >= 0; step--) {
					int currentWPIdx = pathfinder->mBuffer[step].mWayPointIdx;
					int prevWPIdx    = (step == 0) ? mIndex : pathfinder->mBuffer[step - 1].mWayPointIdx;

					WayPoint* prevWP         = routeMgr->getWayPoint('test', prevWPIdx);
					WayPoint* currentWP      = routeMgr->getWayPoint('test', currentWPIdx);
					int prevToCurrentLinkIdx = prevWP->getLinkIndex(currentWPIdx);

					Vector3f diff = prevWP->mPosition - currentWP->mPosition;
					accumCost += int(diff.length());

					// Update if no cost exists or new cost is lower
					if (prevWP->mLinkInfos[prevToCurrentLinkIdx].getInfo(goalIdx) >= 0
					    && prevWP->mLinkInfos[prevToCurrentLinkIdx].getInfo(goalIdx) <= accumCost) {
						continue;
					}

					prevWP->mLinkInfos[prevToCurrentLinkIdx].setInfo(goalIdx, accumCost);
				}

			} else {
				// If no valid target waypoint, mark as dead end for this goal
				info->setInfo(goalIdx, -2);
				PRINT_KANDO("(goal%d) wp %d : link%d set deadend\n", goalIdx, mIndex, i);
			}
		}
	}

	PathFinder::clearMode();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
int PathFinder::findFirstStepOnyon(int, int, PathFinder::Buffer*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
int PathFinder::findSyncOnyon(immut Vector3f& startPos, PathFinder::Buffer* bufferList, int startWPIdx, int goalType,
                              bool ignoreClosedWaypoints)
{
	int destWPIdx = -1;

	// Determine the destination waypoint index based on goalType
	switch (goalType) {
	case 0: // Red onion
	case 1: // Blue onion
	case 2: // Yellow onion
		GoalItem* container = itemMgr->getContainer(goalType);
		if (container) {
			destWPIdx = container->mWaypointIdx;
		}
		break;
	case 3: // UFO
		UfoItem* ufo = itemMgr->getUfo();
		if (ufo) {
			destWPIdx = ufo->mWaypointID;
		}
	}

	// If no valid destination found, return 0 (no path)
	if (destWPIdx == -1) {
		return 0;
	}

	if (PathFinder::checkMode(PathFinderMode::AvoidWater)) {
		PRINT("*** AVOID_WATER ROUTE FINDING START (%d - %d)\n", startWPIdx, destWPIdx);
	}

	int bufIdx                 = 0;
	bufferList[0].mWayPointIdx = startWPIdx;

	// If start equals destination, path length is 1
	if (startWPIdx == destWPIdx) {
		return bufIdx + 1;
	}

	PathStatus::Type status = PathStatus::Searching;
	int UNUSED              = 1000;
	bool isBacktracking     = false;
	int currentCost         = 0;
	bool secondBestFlag     = false;

	// Attempt to find second best initial step, if any
	int secondBestWayCost;
	int secondBestRes = selectSecondBestWayOnyon(startPos, secondBestWayCost, goalType, bufferList[bufIdx], destWPIdx, bufferList, bufIdx,
	                                             ignoreClosedWaypoints);
	if (secondBestRes != -1) {
		PRINT("******** SECOND BEST = %d (dist =%d)\n", getWayPoint(getWayPoint(startWPIdx)->mLinkIndices[secondBestRes])->mIndex,
		      secondBestWayCost);
		secondBestFlag = true;
	}

	secondBestFlag = false;

	// Main pathfinding loop
	while (status == PathStatus::Searching) {
		if (bufIdx >= mBufferSize) {
			ERROR("mem access !\n");
		}

		WayPoint* wp = getWayPoint(bufferList[bufIdx].mWayPointIdx);

		// If not in backtracking mode, initialize flags for current waypoint links
		if (!isBacktracking) {
			for (int i = 0; i < 8; i++) {
				if (wp->mLinkIndices[i] == -1) {
					bufferList[bufIdx].resetFlag(i);
				} else {
					bufferList[bufIdx].setFlag(i);
				}
			}
		}

		// Select the best next step based on pathfinding heuristics
		int bestStep = selectWayOnyon(currentCost, goalType, bufferList[bufIdx], destWPIdx, bufferList, bufIdx, ignoreClosedWaypoints);

		// If we're considering the second best route and current cost exceeds it, try switching
		if (secondBestFlag && currentCost > secondBestWayCost) {
			PRINT("---- second best wo sirabe mashou!\n"); // 'let's check second best'

			// Reset flags to allow alternative paths on all buffered waypoints
			for (int j = bufIdx; j > 0; j--) {
				for (int k = 0; k < 8; k++) {
					bufferList[j].setFlag(k);
				}
			}

			wp             = getWayPoint(bufferList[0].mWayPointIdx);
			bufIdx         = 0;
			bestStep       = secondBestRes;
			secondBestFlag = false;
			PRINT_GLOBAL("second best route:%d", getWayPoint(getWayPoint(startWPIdx)->mLinkIndices[secondBestRes])->mIndex);
			bufferList[0].resetFlag(bestStep);
		}

		if (bestStep != -1) {
			// Calculate cost for the step
			Vector3f dir = wp->mPosition - getWayPoint(wp->mLinkIndices[bestStep])->mPosition;
			currentCost += int(dir.length());

			int nextWpIdx = wp->mLinkIndices[bestStep];

			// Check if reached destination
			if (nextWpIdx == destWPIdx) {
				bufferList[++bufIdx].mWayPointIdx = destWPIdx;

				if (bufIdx >= mBufferSize) {
					ERROR("mem access\n");
				}

				// Path found successfully WOO HOO!
				status = PathStatus::Success;
				break;
			}

			// Mark this link as used to avoid revisiting
			bufferList[bufIdx].resetFlag(bestStep);
			bufIdx++;

			// If buffer full, trigger backtracking
			if (bufIdx >= mBufferSize) {
				PRINT("@@ backtrack (full buffer ptr=%d buffSize=%d)\n", bufIdx, mBufferSize);
				bufIdx--;
				isBacktracking = true;
			} else {
				// Continue forward!
				bufferList[bufIdx].mWayPointIdx = nextWpIdx;
				isBacktracking                  = false;
			}
		} else {
			// No next step available: backtrack
			isBacktracking = true;
			if (bufIdx >= 1) {
				Vector3f lastStepDir
				    = getWayPoint(bufferList[bufIdx].mWayPointIdx)->mPosition - getWayPoint(bufferList[bufIdx - 1].mWayPointIdx)->mPosition;
				currentCost -= int(lastStepDir.length());
			}

			bufferList[bufIdx].mWayPointIdx = -1;
			bufIdx--;

			// No path found
			if (bufIdx < 0) {
				status = PathStatus::Failed;
			}
		}
	}

	// If we exit the loop normally, we found a path
	if (status == PathStatus::Success) {
		PRINT("<onyon> find route ### result {\n");
		for (int i = 0; i <= bufIdx; i++) {
			PRINT("  %d -> ::: (%s) : %s\n", bufferList[i].mWayPointIdx,
			      getWayPoint(bufferList[i].mWayPointIdx)->mIsOpen ? "[on]" : "*** off ***",
			      (getWayPoint(bufferList[i].mWayPointIdx)->mFlags & WayPointFlags::Pebble) ? "pebble" : "-");
		}
		PRINT("}\n");
		return bufIdx + 1; // Return the number of waypoints in the path + 1 for destination
	}

	return 0;
}

/**
 * @TODO: Documentation
 */
int PathFinder::selectWayOnyon(int additionalCost, int goalType, PathFinder::Buffer& buf, int destWPIdx, PathFinder::Buffer* bufferList,
                               int visitedBufferCount, bool ignoreClosedWaypoints)
{
	int pathCosts[8];        // Cost values for each valid link
	int validLinkIndices[8]; // Direction indices for valid links

	int bestLinkIndex  = -1; // Index of the best (lowest cost) link direction
	int validLinkCount = 0;  // Number of valid links found

	// NEVER USED, FOR WHATEVER REASON /////////////////////////
	Vector3f wpPos   = getWayPoint(buf.mWayPointIdx)->mPosition;
	Vector3f destPos = getWayPoint(destWPIdx)->mPosition;
	////////////////////////////////////////////////////////////

	for (int dir = 0; dir < 8; dir++) {
		// Skip if this direction is not available
		if (!buf.check(dir)) {
			continue;
		}

		WayPoint* wp = getWayPoint(buf.mWayPointIdx);
		if (!PathFinder::checkMode(PathFinderMode::AvoidWater) || !wp->inWater()) {
			int neighborIdx = wp->mLinkIndices[dir];

			// Skip self-referencing links
			if (neighborIdx == buf.mWayPointIdx) {
				continue;
			}

			// Handle invalid links by resetting the flag
			if (neighborIdx == -1) {
				buf.resetFlag(dir);
				continue;
			}

			// Check if connected waypoint is closed (and we're not ignoring closed waypoints)
			if (!ignoreClosedWaypoints && !getWayPoint(neighborIdx)->mIsOpen) {
				buf.resetFlag(dir);
				continue;
			}

			// Check if this waypoint has already been visited to avoid cycles
			bool isAlreadyVisited = false;
			for (int j = 0; j < visitedBufferCount; j++) {
				if (bufferList[j].mWayPointIdx == neighborIdx) {
					isAlreadyVisited = true;
					break;
				}
			}

			// Add to valid links if it has valid pathfinding info and hasn't been visited
			if (wp->mLinkInfos[dir].getInfo(goalType) != -2 && !isAlreadyVisited) {
				validLinkIndices[validLinkCount] = dir;

				// If this link leads directly to destination, return immediately (optimal path found)
				if (neighborIdx == destWPIdx) {
					return dir;
				}

				// Store the pathfinding cost for this link
				pathCosts[validLinkCount] = wp->mLinkInfos[dir].getInfo(goalType);
				validLinkCount++;
			}
		}
	}

	// Phase 2: Find the best (lowest cost) option among all valid links
	int lowestCost = 128000;
	for (int i = 0; i < validLinkCount; i++) {
		if (pathCosts[i] < lowestCost) {
			lowestCost    = pathCosts[i];
			bestLinkIndex = validLinkIndices[i];
		}
	}

	// Debug output: Print information about the selected path
	if (bestLinkIndex != -1) {
		WayPoint* sourceWaypoint = getWayPoint(buf.mWayPointIdx);
		WayPoint* targetWaypoint = getWayPoint(sourceWaypoint->mLinkIndices[bestLinkIndex]);

		// Calculate actual distance between waypoints
		Vector3f directionVector = targetWaypoint->mPosition - sourceWaypoint->mPosition;
		f32 actualDistance       = directionVector.length();

		// Add any additional cost penalty/bonus to the distance
		int totalDistanceCost = (int)actualDistance + additionalCost;
		PRINT("\t way %d: next %d: sum is %d\n", bestLinkIndex, targetWaypoint->mIndex, totalDistanceCost);

		STACK_PAD_TERNARY(totalDistanceCost, 1);
		STACK_PAD_TERNARY(targetWaypoint, 1);
	}

	STACK_PAD_VAR(4);

	return bestLinkIndex;
}

/**
 * @TODO: Documentation
 */
int PathFinder::selectSecondBestWayOnyon(immut Vector3f& curPos, int& secondBestCost, int goalType, PathFinder::Buffer& buf, int destWPIdx,
                                         PathFinder::Buffer* bufferList, int bufIdx, bool ignoreClosedWaypoints)
{
	int pathCosts[8];        // Cost values for each valid link
	int validLinkIndices[8]; // Direction indices forvalid links

	STACK_PAD_VAR(1);

	int bestLinkIndex  = -1; // Index of the best (lowest cost) link
	int validLinkCount = 0;  // Number of valid links found

	Vector3f wpPos   = getWayPoint(buf.mWayPointIdx)->mPosition;
	Vector3f destPos = getWayPoint(destWPIdx)->mPosition;

	for (int dir = 0; dir < 8; dir++) {
		// Skip if this direction is not available
		if (!buf.check(dir)) {
			continue;
		}

		WayPoint* currWP = getWayPoint(buf.mWayPointIdx);
		if (!PathFinder::checkMode(PathFinderMode::AvoidWater) || !currWP->inWater()) {
			int neighborIdx = currWP->mLinkIndices[dir];

			// Skip self-referencing links
			if (neighborIdx == buf.mWayPointIdx) {
				continue;
			}

			// Handle invalid links by resetting the flag
			if (neighborIdx == -1) {
				buf.resetFlag(dir);
				continue;
			}

			// Check if connected waypoint is closed (and we're not ignoring closed waypoints)
			if (!ignoreClosedWaypoints && !getWayPoint(neighborIdx)->mIsOpen) {
				buf.resetFlag(dir);
				continue;
			}

			// Check if this waypoint has already been visited to avoid cycles
			bool isAlreadyVisited = false;
			for (int j = 0; j < bufIdx; j++) {
				if (bufferList[j].mWayPointIdx == neighborIdx) {
					isAlreadyVisited = true;
					break;
				}
			}

			// Add to valid links if it has valid pathfinding info and hasn't been visited
			if (currWP->mLinkInfos[dir].getInfo(goalType) != -2 && !isAlreadyVisited) {
				validLinkIndices[validLinkCount] = dir;

				// If this link leads directly to destination, return immediately
				if (neighborIdx == destWPIdx) {
					return dir;
				}

				// Store the pathfinding cost for this link
				pathCosts[validLinkCount] = currWP->mLinkInfos[dir].getInfo(goalType);
				validLinkCount++;
			}
		}
	}

	// Phase 2: Find the best (lowest cost) option
	int lowestCost = 128000;
	for (int i = 0; i < validLinkCount; i++) {
		if (pathCosts[i] < lowestCost) {
			lowestCost    = pathCosts[i];
			bestLinkIndex = validLinkIndices[i];
		}
	}

	// Phase 3: Find the second-best option with geometric validation
	int i;
	int secondBestLinkIndex = -1;
	secondBestCost          = 128000;

	for (i = 0; i < validLinkCount; i++) {
		// Skip the best option and only consider better costs than current second-best
		if (i != bestLinkIndex && pathCosts[i] < secondBestCost) {
			WayPoint* wp1 = getWayPoint(buf.mWayPointIdx);                       // Source waypoint
			WayPoint* wp2 = getWayPoint(wp1->mLinkIndices[validLinkIndices[i]]); // Destination waypoint

			bool geometricallyValid = true;

			PRINT("wp(%d) = %s wp2(%d) = %s\n", wp1->mIndex, wp1->mIsOpen ? "on" : "off", wp2->mIndex, wp2->mIsOpen ? "on" : "off");

			if (!wp1->mIsOpen) {
				// If source waypoint is closed, create plane at source facing target
				Plane seperatingPlane;
				Vector3f directionToTarget = wp2->mPosition - wp1->mPosition;
				directionToTarget.normalise();
				seperatingPlane.mNormal = directionToTarget;
				seperatingPlane.mOffset = directionToTarget.DP(wp1->mPosition);

				// Check if current position and target are on same side of plane
				bool isAbove     = seperatingPlane.dist(curPos);
				bool isLinkAbove = seperatingPlane.dist(wp2->mPosition);

				if (isAbove != isLinkAbove) {
					geometricallyValid = false;
					PRINT("another side !\n");
				}
			} else if (!wp2->mIsOpen) {
				// If target waypoint is closed, create plane at target facing source
				Plane separatingPlane;
				Vector3f directionToTarget = wp2->mPosition - wp1->mPosition;
				directionToTarget.normalise();
				separatingPlane.mNormal = directionToTarget;
				separatingPlane.mOffset = directionToTarget.DP(wp2->mPosition);

				// Check if current position and source are on same side of plane
				bool isAbove   = separatingPlane.dist(curPos);
				bool isWPAbove = separatingPlane.dist(wp1->mPosition);

				if (isAbove != isWPAbove) {
					geometricallyValid = false;
					PRINT("another side !\n");
				}
			}

			// Update second-best if this option passes geometric validation
			if (geometricallyValid) {
				secondBestLinkIndex = i;
				secondBestCost      = pathCosts[i];
			}
		}
	}

	STACK_PAD_VAR(6);

	PRINT("BEST IS %d : SECOND BEST IS %d\n", bestLinkIndex, secondBestLinkIndex);
	return secondBestLinkIndex;
}

/**
 * @TODO: Documentation
 */
void RouteMgr::refresh(Graphics& gfx)
{
	gfx.setColour(COLOUR_WHITE, true);
	gfx.setLighting(false, nullptr);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	for (int i = 0; i < getNumWayPoints('test'); i++) {
		WayPoint* wp = getWayPoint('test', i);
		if (gfx.mCamera->isPointVisible(wp->mPosition, 200.0f)) {
			wp->refresh(gfx);
		}
	}
}

/**
 * @TODO: Documentation
 */
static void drawBattenPoleSpec(Graphics& gfx, immut Vector3f& pos, f32 height, immut char* labelText, immut Colour& labelColor)
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

/**
 * @TODO: Documentation
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
