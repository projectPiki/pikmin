#include "zen/ogGraph.h"
#include "PlayerState.h"
#include "P2D/Screen.h"
#include "P2D/Graph.h"
#include "GameStat.h"
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
DEFINE_PRINT("OgResultSection")

namespace zen {

static s16 LinePointB[32] ATTRIBUTE_ALIGN(32) = { 0 };
static s16 LinePointR[32]                     = { 0 };
static s16 LinePointY[32]                     = { 0 };

// day 1 graph points
static s16 ogawa_per_line[]                                        = { 1, 1, 2, 3, 10, 12, 12, 13, 13, 14, 19, 20, 22 };
static u32 og_piki_lines_color[PikiColorCount] ATTRIBUTE_ALIGN(32) = { 0x00C0FFFF, 0xFF0000FF, 0xFFFF00FF };

/*
 * --INFO--
 * Address:	80197F28
 * Size:	0000C4
 */
ogGraphMgr::ogGraphMgr(P2DScreen* screen)
{
	mParent           = screen->search('g_sp', true);
	mDefaultMaxPikmin = GameStat::containerPikis[Red] + GameStat::formationPikis[Red];

	if (!playerState) {
		mHasColor[Blue]   = true;
		mHasColor[Red]    = true;
		mHasColor[Yellow] = true;
	} else {
		mHasColor[Blue]   = playerState->displayPikiCount(Blue);
		mHasColor[Red]    = playerState->displayPikiCount(Red);
		mHasColor[Yellow] = playerState->displayPikiCount(Yellow);
	}

	MakeData();
}

/*
 * --INFO--
 * Address:	80197FEC
 * Size:	000304
 */
void ogGraphMgr::SetDummyLineData()
{
	for (int i = 0; i < 32; i++) {
		LinePointB[i] = 0;
		LinePointR[i] = 0;
		LinePointY[i] = 0;
	}

	s16 paneSegmentWidth = mParent->getWidth() / 12;
	s16 x                = mParent->getPosH();
	s16 y                = mParent->getPosV();
	s16 paneFullHeight   = mParent->getHeight();

	// Iterate through the 14 points (13 segments) for the line
	s16* pointArray = LinePointR;
	for (int i = 0; i <= 13; i++) {
		int yPercentFromTop = 100 - ogawa_per_line[i];
		s16 pointY          = y + yPercentFromTop * paneFullHeight / 100;
		pointArray[0]       = x + i * paneSegmentWidth;
		pointArray[1]       = pointY;
		pointArray += 2;
	}
}

/*
 * --INFO--
 * Address:	801982F0
 * Size:	000320
 */
void ogGraphMgr::MakeData()
{
	STACK_PAD_VAR(1);

	s16* line;
	if (!playerState) {
		SetDummyLineData();
		mMaxPikis = mDefaultMaxPikmin;
		mMinPikis = 0;
		return;
	}

	if (playerState->isTutorial()) {
		SetDummyLineData();
		mMaxPikis = mDefaultMaxPikmin;
		mMinPikis = 0;
		return;
	}

	int maxPikis = 0;
	int minPikis = 10000;

	int hour;
	int color;
	int start = playerState->getStartHour();
	int end   = playerState->getEndHour();
	int countAtHour;
	PRINT("hour (%d --> %d)\n", start, end);
	for (color = 0; color < PikiColorCount; color++) {
		// If the color is not displayed, skip it
		if (!mHasColor[color]) {
			continue;
		}

		// Get the data at each hour and find the max/min
		for (hour = start; hour <= end; hour++) {
			countAtHour = playerState->getPikiHourCount(hour, color);
			PRINT("p(%d) h[%d] num %d\n", color, hour, countAtHour);
			if (countAtHour < 0) {
				continue;
			}

			if (countAtHour > maxPikis) {
				maxPikis = countAtHour;
			}

			if (countAtHour < minPikis) {
				minPikis = countAtHour;
			}
		}
	}

	PRINT("piki Max = %d  Min = %d\n", maxPikis, minPikis);

	mMaxPikis = (s16)maxPikis;
	mMinPikis = (s16)minPikis;

	int graphOriginX = mParent->getPosH();
	int graphOriginY = mParent->getPosV();
	int width        = mParent->getWidth() / 12; // Assuming 12 segments (e.g., hours 7 to 19 is 13 points, 12 segments)
	int height       = mParent->getHeight();

	// If the range of Pikmin counts is too small, use a different scaling to avoid division by zero or flat lines
	if (maxPikis - minPikis >= 100) {
		for (color = 0; color < PikiColorCount; color++) {
			if (mHasColor[color]) {
				switch (color) {
				case Blue:
					line = LinePointB;
					break;

				case Red:
					line = LinePointR;
					break;

				case Yellow:
					line = LinePointY;
					break;
				}

				for (hour = start; hour <= end; hour++) {
					countAtHour    = playerState->getPikiHourCount(hour, color);
					s16 yPosScalar = -10;
					if (countAtHour >= 0) {
						// Normalize count to a 0 - 100 scale, assuming minPikis is the baseline
						// The divisor 100 here means each Pikmin count difference from minPikis contributes 1% to the y-scale.
						yPosScalar = 100 * (countAtHour - minPikis) / (maxPikis - minPikis);
					}

					line[0] = graphOriginX + (hour - 7) * width;
					line[1] = graphOriginY + (100 - yPosScalar) * height / 100;
					line += 2;
				}
			}
		}
	} else {
		for (color = 0; color < PikiColorCount; color++) {
			if (mHasColor[color]) {
				switch (color) {
				case Blue:
					line = LinePointB;
					break;

				case Red:
					line = LinePointR;
					break;

				case Yellow:
					line = LinePointY;
					break;
				}

				for (hour = start; hour <= end; hour++) {
					countAtHour    = playerState->getPikiHourCount(hour, color);
					s16 yPosScalar = -10;
					if (countAtHour >= 0) {
						// Normalize count to a 0-100 scale, assuming minPikis is the baseline
						// The divisor 100 here means each Pikmin count difference from minPikis contributes 1% to the y-scale.
						yPosScalar = 100 * (countAtHour - minPikis) / 100;
					}

					line[0] = graphOriginX + (hour - 7) * width;
					line[1] = graphOriginY + (100 - yPosScalar) * height / 100;
					line += 2;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80198610
 * Size:	00029C
 */
static void setGraphGX(void* vertexData, int pikminColor, u8 alpha)
{
	u32 graphColor = og_piki_lines_color[pikminColor];

	// Mask out existing alpha and replace it
	graphColor &= 0xFFFFFF00;
	graphColor |= alpha;

	int startHour, endHour;
	if (!playerState) {
		startHour = 7;  // Default start hour
		endHour   = 19; // Default end hour
	} else {
		startHour = playerState->getStartHour();
		endHour   = playerState->getEndHour();
	}

	// Calculate the number of hours to display
	// The +1 is to include the end hour in the count
	int hours = (endHour - startHour) + 1;

	int i;
	if (!playerState || playerState->isTutorial()) {
		// Fixed point for tutorial / no state
		hours = 13;
	} else {
		for (i = 0; i < hours; i++) {
			int count = playerState->getPikiHourCount(startHour + i, pikminColor);

			// If the count is negative, we stop drawing at this hour
			// This is to avoid drawing lines for hours with no data
			if (count < 0) {
				hours = i;
				break;
			}
		}
	}

	// Need at least 2 points to draw a line segment
	if (hours >= 2) {
		GXClearVtxDesc();
		GXSetAlphaUpdate(1);
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_RGBA4, 0);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_POS_XYZ, GX_RGBA8, 0);
		GXSetArray(GX_VA_POS, vertexData, sizeof(u32));
		GXSetArray(GX_VA_CLR0, &og_piki_lines_color, 4);
		GXSetLineWidth(0x12, GX_TO_ZERO);
		GXBegin(GX_LINESTRIP, GX_VTXFMT0, hours);

		for (i = 0; i < hours; i++) {
			s16 x = ((s16*)vertexData)[2 * i];
			s16 y = ((s16*)vertexData)[2 * i + 1];
			GXPosition2s16(x, y);
			GXColor1u32(graphColor);
		}
	}
}

/*
 * --INFO--
 * Address:	801988AC
 * Size:	0000DC
 */
void ogGraphMgr::draw(u8 a)
{
	//! TODO: Refactor all instances of 640 and 480 to use the screen width and height
	//!       Values should be defined in a header, to be more portable.
	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();

	if (mHasColor[Blue]) {
		setGraphGX(LinePointB, Blue, a);
	}

	if (mHasColor[Red]) {
		setGraphGX(LinePointR, Red, a);
	}

	if (mHasColor[Yellow]) {
		setGraphGX(LinePointY, Yellow, a);
	}
}
} // namespace zen
