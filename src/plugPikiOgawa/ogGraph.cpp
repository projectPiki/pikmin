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
static s16 ogawa_per_line[15]     = { 1, 1, 2, 3, 10, 12, 12, 13, 13, 14, 19, 20, 22 };
static u32 og_piki_lines_color[3] = { 0x00C0FFFF, 0xFF0000FF, 0xFFFF00FF };

/*
 * --INFO--
 * Address:	80197F28
 * Size:	0000C4
 */
ogGraphMgr::ogGraphMgr(P2DScreen* screen)
{
	mPane = screen->search('g_sp', true);
	_0C   = GameStat::containerPikis[Red] + GameStat::formationPikis[Red];
	if (playerState == nullptr) {
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

	s16 width  = mPane->getWidth() / 12;
	s16 x      = mPane->getPosH();
	s16 y      = mPane->getPosV();
	s16 height = mPane->getHeight();
	s16* dummy = LinePointR;
	for (int i = 0; i <= 13; i++) {
		int a    = 100 - ogawa_per_line[i];
		s16 pt1  = y + a * height / 100;
		dummy[0] = x + i * width;
		dummy[1] = pt1;
		dummy += 2;
	}
}

/*
 * --INFO--
 * Address:	801982F0
 * Size:	000320
 */
void ogGraphMgr::MakeData()
{
	u32 badCompiler;
	s16* line;
	if (playerState == nullptr) {
		SetDummyLineData();
		mMaxPikis = _0C;
		mMinPikis = 0;
		return;
	}

	if (playerState->isTutorial()) {
		SetDummyLineData();
		mMaxPikis = _0C;
		mMinPikis = 0;
		return;
	}

	int maxPikis = 0;
	int minPikis = 10000;
	int hour;
	int color;
	int start = playerState->getStartHour();
	int end   = playerState->getEndHour();
	int count;
	PRINT("hour (%d --> %d)\n", start, end);
	for (color = 0; color < 3; color++) {
		if (mHasColor[color]) {
			for (hour = start; hour <= end; hour++) {
				count = playerState->getPikiHourCount(hour, color);
				PRINT("p(%d) h[%d] num %d\n", color, hour, count);
				if (count >= 0) {
					if (count > maxPikis) {
						maxPikis = count;
					}
					if (count < minPikis) {
						minPikis = count;
					}
				}
			}
		}
	}

	PRINT("piki Max = %d  Min = %d\n", maxPikis, minPikis);

	mMaxPikis = (s16)maxPikis;
	mMinPikis = (s16)minPikis;

	int x      = mPane->getPosH();
	int y      = mPane->getPosV();
	int width  = mPane->getWidth() / 12;
	int height = mPane->getHeight();

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
					count = playerState->getPikiHourCount(hour, color);
					s16 a = -10;
					if (count >= 0) {
						a = 100 * (count - minPikis) / (maxPikis - minPikis);
					}

					line[0] = x + (hour - 7) * width;
					line[1] = y + (100 - a) * height / 100;
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
					count = playerState->getPikiHourCount(hour, color);
					s16 a = -10;
					if (count >= 0) {
						a = 100 * (count - minPikis) / 100;
					}

					line[0] = x + (hour - 7) * width;
					line[1] = y + (100 - a) * height / 100;
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
static void setGraphGX(void* data, int color, u8 alpha)
{
	u32 graphColor = og_piki_lines_color[color];
	int hours;
	graphColor &= 0xFFFFFF00; // mask out alpha
	graphColor |= alpha;      // replace alpha
	int startHour, endHour;
	if (!playerState) {
		startHour = 7;
		endHour   = 19;
	} else {
		startHour = playerState->getStartHour();
		endHour   = playerState->getEndHour();
	}
	hours = (endHour - startHour) + 1;

	int i;
	if (!playerState || playerState->isTutorial()) {
		hours = 13;
	} else {
		// segments = hours;
		for (i = 0; i < hours; i++) {
			int count = playerState->getPikiHourCount(startHour + i, color);
			if (count < 0) {
				hours = i;
				break;
			}
		}
	}

	if (hours >= 2) {
		GXClearVtxDesc();
		GXSetAlphaUpdate(1);
		GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_RGBA4, 0);
		GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_POS_XYZ, GX_RGBA8, 0);
		GXSetArray(GX_VA_POS, data, sizeof(u32));
		GXSetArray(GX_VA_CLR0, &og_piki_lines_color, 4);
		GXSetLineWidth(0x12, GX_TO_ZERO);
		GXBegin(GX_LINESTRIP, GX_VTXFMT0, hours);

		for (i = 0; i < hours; i++) {
			s16 x = ((s16*)data)[2 * i];
			s16 y = ((s16*)data)[2 * i + 1];
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
